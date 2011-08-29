/*****************************************************************************
* Copyright (c) 2009 Vogins Network Technology (China). All rights reserved.
*
* Filename:
* ---------
*   amnet.c
*
* Project:
* --------
*   AppStore 3.0
*
* Description:
* ------------
*   网络模块接口实现 2009.11.10
*
* Author:
*   David Liu 2009.11.10
* -------
* -------
*
****************************************************************************/
#ifdef __VRE30_AM__
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "vmsys.h"
#include "vmstdlib.h"
#include "vmio.h"
#include "vmchset.h"
#include "vmgraph.h"
#include "vmxml.h"
#include "vmlog.h"

//#include "logic_public.h"
#include "liblist.h"

#include "AMnet.h"
#include "vmnvramadapter.h"
#include "vmvip.h"

typedef struct NetManager 
{
    VMINT nPhoneId;
    VMINT nUserId;
    void (*get_single_app_info_cb)(VMINT nResult, AppInfo_t *pAppInfo);//获取应用详细信息
    sml_list_t * DataStack;
    sml_list_t * ElmtStack;
    VMCHAR szResPath[250];
    VMINT nXmlPasRlt;//0 no error
    VMINT nmfcount;
}NetManager_t;
NetManager_t g_AMNetManager;


AMAppInfXmlPser_t g_AMAppInfPasManager;//applist xml解析器

#define  SAFE_FREE(p) if(p){ vm_free(p); (p) = NULL; }
/*
*	系统配置数据类型
*/
typedef enum 
{
    VRE_SYSTEM_TIME = 1,
    VRE_PUBLIC_KEY,
    VRE_PERMISSION_BLACK_LIST,
    VRE_APPLICATION_BLACK_LIST,
    VRE_PAYMENT_CHANNEL,
    VRE_APPSTORE_VERSION
}E_SysCfgCnt_t;

#ifndef _DEBUG
VMINT am_vm_chset_convert (vm_chset_enum src_type, vm_chset_enum dest_type, 
                           VMCHAR* src, VMCHAR* dest, VMINT dest_size)
{
    return VM_CHSET_CONVERT_SUCCESS;
}

VMINT am_UTF8toUCS2Code(VMUINT8* utf8_code, VMUINT16* ucs2_code){        
    VMUINT16 temp1, temp2;
    VMINT is_unrecognized = FALSE ;
    VMUINT step = 1,counter = 0, end = strlen((char *)utf8_code);
    VMUINT8* utf8string = utf8_code;

    if (!utf8_code || !ucs2_code)
    {
        return 0;
    }

    while (counter < end + 1)
    {
        if (0x00 == (*utf8string & 0x80))
        {
            /* 1 byte UTF-8 Charater.*/
            temp1 = *((VMUINT8 *)(utf8string));
            wstrcpy((VMWCHAR *)ucs2_code++, (VMWCHAR *)&temp1);
            step = 1;
            counter += step;
            utf8string += step;
            is_unrecognized = TRUE;
        }
        else if (0xc0 == (*utf8string & 0xe0) &&
                 0x80 == (*(utf8string + 1) & 0xc0)
                )
        {
            /* 2 bytes UTF-8 Charater.*/ 
            temp1 = (VMUINT16)(*utf8string & 0x1f);
            temp1 <<= 6;
            temp1 |= (VMUINT16)(*(utf8string + 1) & 0x3f);
            step = 2;
            counter += step;
            utf8string += step;
            wstrcpy((VMWCHAR *)ucs2_code++, (VMWCHAR *)(&temp1));
            is_unrecognized = TRUE;
        }
        else if ( 0xe0 == (*utf8string & 0xf0) &&
                  0x80 == (*(utf8string +1) & 0xc0) &&
                  0x80 == (*(utf8string + 2) & 0xc0)
                )
        {
            /* 3bytes UTF-8 Charater.*/
            temp1 = (VMUINT16)(*utf8string &0x0f);
            temp1 <<= 12;
            temp2 = (VMUINT16)(*(utf8string+1) & 0x3F);
            temp2 <<= 6;
            temp1 = temp1 | temp2 | (VMUINT16)(*(utf8string+2) & 0x3F);
            step = 3;
            counter += step;
            utf8string += step;
            wstrcpy((VMWCHAR *)ucs2_code++, (VMWCHAR *)(&temp1));
            is_unrecognized = TRUE;
        }
        else
        {
            temp1 = *((VMUINT8 *)(utf8string));
            wstrcpy((VMWCHAR *)ucs2_code++, (VMWCHAR *)&temp1);
            is_unrecognized = TRUE;
            utf8string ++;
            counter ++;
        }
    }
    return is_unrecognized;
}
#endif 

sml_list_t * am_net_xml_stack_create()
{
    return sml_list_new();
}

VMINT am_net_xml_stack_clear(sml_list_t * Stack)
{
    VMINT nSize = 0;
    VMCHAR * pData;

    nSize = sml_list_size((const sml_list_t *)Stack);
    while (nSize > 0)
    {
        pData = (VMCHAR *)sml_list_get(Stack,nSize - 1);
        vm_free(pData);
#ifdef LOG_NET
        vm_log_debug("[NET] free,net_xml_stack_clear,pData=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
#endif

        sml_list_remove(Stack,nSize - 1);
        nSize --;
    }

    return AM_NET_OK;
}

void am_net_xml_stack_destroy(sml_list_t * Stack)
{
    am_net_xml_stack_clear(Stack);
    sml_list_free(Stack);
}

void am_net_xml_stack_push(sml_list_t * Stack,void * Data)
{
    sml_list_add(Stack,Data,0);//stack push总是把元素放在list的第一个
}

void * am_net_xml_stack_pop(sml_list_t * Stack)
{
// 	VMBYTE * pPopValue = NULL;
    VMBYTE * pData;

    pData = sml_list_get(Stack,0);
    if (pData)
    {
        sml_list_remove(Stack,0);
        return pData;
    }
    else
        return NULL;
}

void * am_net_xml_stack_get(sml_list_t * Stack)//获取栈顶元素，但是不出栈
{
    return sml_list_get(Stack,0);
}

VMINT am_ph_dm_byte_switch(char * src_data, VMUINT32 *data, VMUINT16 *data1)
{
    if (data)
    {
        VMCHAR str_data[5];
        VMUINT32 temp_data;
        memset(str_data, 0, sizeof(str_data));

        str_data[0] = src_data[3];
        str_data[1] = src_data[2];
        str_data[2] = src_data[1];
        str_data[3] = src_data[0];
        memcpy(&temp_data, str_data, 4);

        memcpy(data, str_data, 4);
    }
    else if (data1)
    {
        VMCHAR str_data[3];

        memset(str_data, 0, sizeof(str_data));

        str_data[0] = src_data[1];
        str_data[1] = src_data[0];

        memcpy(data1, str_data, 2);
    }

    return TRUE;
}

void am_ph_dm_string_byte_switch(VMWCHAR * dst_data, VMWCHAR * src_data)
{
    VMINT i;

    for (i = 0 ; i < vm_wstrlen(src_data) ; i ++)
    {
        dst_data[i] = (src_data[i] >> 8) | (src_data[i] << 8);
    }
}


void am_net_xml_appinfo_start_elem_hdlr(void *data,const VMCHAR *el,const VMCHAR **attr,VMINT error)
{
    VMCHAR * pElmt = NULL;

    if (error == VM_XML_NO_ERROR && g_AMNetManager.nXmlPasRlt == AM_NET_OK)
    {
        pElmt = (VMCHAR *)vm_malloc(sizeof(VMBYTE) * (strlen(el) + 1));
//#ifdef LOG_NET
        kal_prompt_trace(MOD_MMI,"[NET] malloc,net_xml_appinfo_start_elem,pElmt=%p,mfcount=%d",pElmt,++g_AMNetManager.nmfcount);
//#endif
        if (pElmt)
        {
            memset(pElmt,0,sizeof(VMBYTE) * (strlen(el) + 1));
            strcpy(pElmt,el);
            am_net_xml_stack_push(g_AMNetManager.ElmtStack,pElmt);
            if (!strcmp(el,"app"))//进入appinfo的结构内，开始解析
            {
                g_AMAppInfPasManager.pAppInfo = (AppInfo_t *)vm_malloc(sizeof(AppInfo_t));
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] malloc,net_xml_appinfo_start_elem,pAppInfo=%p,mfcount=%d",g_AMAppInfPasManager.pAppInfo,g_AMNetManager.nmfcount);
//#endif
                memset(g_AMAppInfPasManager.pAppInfo,0,sizeof(AppInfo_t));
                g_AMAppInfPasManager.pAppInfo->ContentInfo.nFlag = 1;//为app
            }
        }
    }
    else if (g_AMNetManager.nXmlPasRlt == AM_NET_OK)//错误第一次出现
    {
//#ifdef LOG_NET
        kal_prompt_trace(MOD_MMI, "[NET] net_xml_appinfo_start_elem,parse error");
//#endif
        g_AMNetManager.nXmlPasRlt = AM_NET_ERR;
        if (g_AMAppInfPasManager.pAppInfo)
        {
            if (g_AMAppInfPasManager.pAppInfo->ContentInfo.imageIcon)
            {
                vm_graphic_release_canvas(g_AMAppInfPasManager.pAppInfo->ContentInfo.imageIcon);
            }
            vm_free(g_AMAppInfPasManager.pAppInfo);
            g_AMAppInfPasManager.pAppInfo = NULL;
        }
        if (g_AMAppInfPasManager.pIconData)
        {
            vm_free(g_AMAppInfPasManager.pIconData);
            g_AMAppInfPasManager.pIconData = NULL;
        }
    }
}

void am_net_xml_appinfo_end_elem_hdlr(void *data,const VMCHAR *el, VMINT error)
{
    VMCHAR * pElmt = NULL;
    VMCHAR * pData = NULL;
//#ifdef LOG_NET
    kal_prompt_trace(MOD_MMI, "[NET]net_xml_appinfo_end_elem_hdlr,el=%s",el);
//#endif

    if (error == VM_XML_NO_ERROR  && g_AMNetManager.nXmlPasRlt == AM_NET_OK)
    {
        pElmt = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.ElmtStack);
        if (!strcmp(pElmt,el))//匹配成功
        {
            kal_prompt_trace(MOD_MMI, "[NET]net_xml_appinfo_end_elem_hdlr,22222el=%s",el);
            if (!strcmp(el,"result"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                g_AMAppInfPasManager.nResult = atoi((const VMSTR)pData);
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"md5"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"appid"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                g_AMAppInfPasManager.pAppInfo->ContentInfo.nContentID = atoi((const VMSTR)pData);
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"cpname"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                if (pData)
                {
#ifndef _DEBUG 
//#ifdef LOG_NET
                    kal_prompt_trace(MOD_MMI, "[NET] net_xml_appinfo_end_elem_hdlr,pdata1=%p",pData);
//#endif
                    am_vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,pData,(VMSTR)g_AMAppInfPasManager.pAppInfo->szCPName,
                                        sizeof(g_AMAppInfPasManager.pAppInfo->szCPName));
//#ifdef LOG_NET
                    kal_prompt_trace(MOD_MMI, "[NET] net_xml_appinfo_end_elem_hdlr,pdata2=%p",pData);
//#endif

#else
                    vm_gb2312_to_ucs2(g_AMAppInfPasManager.pAppInfo->szCPName,
                                      sizeof(g_AMAppInfPasManager.pAppInfo->szCPName),pData);
#endif

// 					memcpy(g_AMAppInfPasManager.pAppInfo->szCPName,vm_ucs2_string(pData),strlen(pData) * 2);
                    vm_free(pData);
//#ifdef LOG_NET
                    kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
                }
            }
            else if (!strcmp(el,"appname"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                if (pData)
                {
#ifndef _DEBUG 
                    am_vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,pData,(VMSTR)g_AMAppInfPasManager.pAppInfo->ContentInfo.szName,
                                        sizeof(g_AMAppInfPasManager.pAppInfo->ContentInfo.szName));
#else
                    vm_gb2312_to_ucs2(g_AMAppInfPasManager.pAppInfo->ContentInfo.szName,
                                      sizeof(g_AMAppInfPasManager.pAppInfo->ContentInfo.szName),pData);
#endif
// 					memcpy(g_AMAppInfPasManager.pAppInfo->ContentInfo.szName,vm_ucs2_string(pData),strlen(pData) * 2);
                    vm_free(pData);
//#ifdef LOG_NET
                    kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
                }
            }
            else if (!strcmp(el,"appdesc"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                if (pData)
                {
#ifndef _DEBUG 
                    am_vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,pData,(VMSTR)g_AMAppInfPasManager.pAppInfo->szIntro,
                                        sizeof(g_AMAppInfPasManager.pAppInfo->szIntro));
#else
                    vm_gb2312_to_ucs2(g_AMAppInfPasManager.pAppInfo->szIntro,
                                      sizeof(g_AMAppInfPasManager.pAppInfo->szIntro),pData);
#endif
// 					memcpy(g_AMAppInfPasManager.pAppInfo->szIntro,vm_ucs2_string(pData),strlen(pData) * 2);
                    vm_free(pData);
//#ifdef LOG_NET
                    kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
                }
            }
            else if (!strcmp(el,"verid"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                if (pData)
                {
#ifndef _DEBUG 
                    am_vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,pData,(VMSTR)g_AMAppInfPasManager.pAppInfo->szVersionID,
                                        sizeof(g_AMAppInfPasManager.pAppInfo->szVersionID));
#else
                    vm_gb2312_to_ucs2(g_AMAppInfPasManager.pAppInfo->szVersionID,
                                      sizeof(g_AMAppInfPasManager.pAppInfo->szVersionID),pData);
#endif
// 					memcpy(g_AMAppInfPasManager.pAppInfo->szVersionID,vm_ucs2_string(pData),strlen(pData) * 2);
                    vm_free(pData);
//#ifdef LOG_NET
                    kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
                }
            }
            else if (!strcmp(el,"filename"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                if (pData)
                {
#ifndef _DEBUG 
                    am_vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,pData,(VMSTR)g_AMAppInfPasManager.pAppInfo->szFileName,
                                        sizeof(g_AMAppInfPasManager.pAppInfo->szFileName));
#else
                    vm_gb2312_to_ucs2(g_AMAppInfPasManager.pAppInfo->szFileName,
                                      sizeof(g_AMAppInfPasManager.pAppInfo->szFileName),pData);
#endif
// 					memcpy(g_AMAppInfPasManager.pAppInfo->szFileName,vm_ucs2_string(pData),strlen(pData) * 2);
                    vm_free(pData);
//#ifdef LOG_NET
                    kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
                }
            }
            else if (!strcmp(el,"rank"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                g_AMAppInfPasManager.pAppInfo->nOrder = atoi((const VMSTR)pData);
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"appversion"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                if (pData)
                {
#ifndef _DEBUG 
                    am_vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,pData,(VMSTR)g_AMAppInfPasManager.pAppInfo->szVersion,
                                        sizeof(g_AMAppInfPasManager.pAppInfo->szVersion));
#else
                    vm_gb2312_to_ucs2(g_AMAppInfPasManager.pAppInfo->szVersion,
                                      sizeof(g_AMAppInfPasManager.pAppInfo->szVersion),pData);
#endif
// 					memcpy(g_AMAppInfPasManager.pAppInfo->szVersion,vm_ucs2_string(pData),strlen(pData) * 2);
                    vm_free(pData);
//#ifdef LOG_NET
                    kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
                }
            }
            else if (!strcmp(el,"filesize"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                g_AMAppInfPasManager.pAppInfo->nSize = atoi((const VMSTR)pData);
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%s,mfcount=%d",g_AMAppInfPasManager.pAppInfo->nSize,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"dldcount"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                g_AMAppInfPasManager.pAppInfo->nDownloadedTime = atoi((const VMSTR)pData);
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"addtime"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                if (pData)
                {
#ifndef _DEBUG 
                    am_vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,pData,(VMSTR)g_AMAppInfPasManager.pAppInfo->szUploadTime,
                                        sizeof(g_AMAppInfPasManager.pAppInfo->szUploadTime));
#else
                    vm_gb2312_to_ucs2(g_AMAppInfPasManager.pAppInfo->szUploadTime,
                                      sizeof(g_AMAppInfPasManager.pAppInfo->szUploadTime),pData);
#endif
// 					memcpy(g_AMAppInfPasManager.pAppInfo->szUploadTime,vm_ucs2_string(pData),strlen(pData) * 2);
                    vm_free(pData);
//#ifdef LOG_NET
                    kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
                }
            }
            else if (!strcmp(el,"iconname"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"iconsize"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                g_AMAppInfPasManager.nIconSize = atoi((const VMSTR)pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "nIconSize=%d",g_AMAppInfPasManager.nIconSize);
//#endif
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"partcount"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"length"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);
                g_AMAppInfPasManager.nPartSize = atoi((const VMSTR)pData) / 2;
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "length=%d",g_AMAppInfPasManager.nIconSize);
//#endif
                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"icondata"))
            {
                pData = (VMCHAR *)am_net_xml_stack_pop(g_AMNetManager.DataStack);

                vm_free(pData);
//#ifdef LOG_NET
                kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pdata=%p,mfcount=%d",pData,--g_AMNetManager.nmfcount);
//#endif
            }
            else if (!strcmp(el,"icondatas"))//appinfo的ICON数据读完,解码
            {
                g_AMAppInfPasManager.pIconData = NULL;
                g_AMAppInfPasManager.nIconOffset = 0;
                g_AMAppInfPasManager.nPartSize = 0;
                g_AMAppInfPasManager.nIconSize = 0;
            }
        }
        vm_free(pElmt);
//#ifdef LOG_NET
        kal_prompt_trace(MOD_MMI, "[NET] free,net_xml_appinfo_end_elem_hdlr,pelmt=%p,mfcount=%d",pElmt,--g_AMNetManager.nmfcount);
//#endif
    }
    else if (g_AMNetManager.nXmlPasRlt == AM_NET_OK)//错误第一次出现
    {
//#ifdef LOG_NET
        kal_prompt_trace(MOD_MMI, "[NET] net_xml_appinfo_start_elem,parse error");
//#endif
        g_AMNetManager.nXmlPasRlt = AM_NET_ERR;
        if (g_AMAppInfPasManager.pAppInfo)
        {
            if (g_AMAppInfPasManager.pAppInfo->ContentInfo.imageIcon)
            {
                vm_graphic_release_canvas(g_AMAppInfPasManager.pAppInfo->ContentInfo.imageIcon);
            }
            vm_free(g_AMAppInfPasManager.pAppInfo);
            g_AMAppInfPasManager.pAppInfo = NULL;
        }
        if (g_AMAppInfPasManager.pIconData)
        {
            vm_free(g_AMAppInfPasManager.pIconData);
            g_AMAppInfPasManager.pIconData = NULL;
        }
    }

}

void am_net_xml_appinfo_data_hdlr(void *resv,const VMCHAR *el,const VMCHAR *data,VMINT len,VMINT error)
{
    VMCHAR * pElmt = NULL;

    if (error == VM_XML_NO_ERROR)
    {
        pElmt = (VMCHAR *)vm_malloc(sizeof(VMBYTE) * (len + 1));
//#ifdef LOG_NET
        kal_prompt_trace(MOD_MMI, "[NET] malloc,net_xml_appinfo_data,pElmt=%p,mfcount=%d",pElmt,++g_AMNetManager.nmfcount);
//#endif
        if (pElmt)
        {
            memset(pElmt,0,sizeof(VMBYTE) * (len + 1));
            memcpy(pElmt,data,len);
            am_net_xml_stack_push(g_AMNetManager.DataStack,pElmt);
        }
//#ifdef LOG_NET
        kal_prompt_trace(MOD_MMI, "[NET] net_xml_appinfo_data,memset done");
//#endif

    }
    else if (g_AMNetManager.nXmlPasRlt == AM_NET_OK)//错误第一次出现
    {
//#ifdef LOG_NET
        kal_prompt_trace(MOD_MMI, "[NET] net_xml_appinfo_start_elem,parse error");
//#endif
        g_AMNetManager.nXmlPasRlt = AM_NET_ERR;
        if (g_AMAppInfPasManager.pAppInfo)
        {
            if (g_AMAppInfPasManager.pAppInfo->ContentInfo.imageIcon)
            {
                vm_graphic_release_canvas(g_AMAppInfPasManager.pAppInfo->ContentInfo.imageIcon);
            }
            vm_free(g_AMAppInfPasManager.pAppInfo);
            g_AMAppInfPasManager.pAppInfo = NULL;
        }
        if (g_AMAppInfPasManager.pIconData)
        {
            vm_free(g_AMAppInfPasManager.pIconData);
            g_AMAppInfPasManager.pIconData = NULL;
        }
    }

}

VMINT am_net_xml_appinfo_parse(VMCHAR * pXmlSource, VMUINT32 unXmlSrcLen)
{
    VM_XML_PARSER_STRUCT XmlParser;
    VMINT nResult;
#ifdef LOG_NET
    {
        VMCHAR szPath[20] = {0};
        VMFILE nHdl = 0;
        VMUINT nWrite;

        memset(szPath,0,20);
        sprintf(szPath,"%c:\\vre\\app_info.dat",public_get_valid_driver());
        nHdl = vm_file_open(vm_ucs2_string(szPath),MODE_CREATE_ALWAYS_WRITE,TRUE);
        vm_log_debug("gif path=%s,hdl=%d",szPath,nHdl);
        vm_file_write(nHdl,pXmlSource,unXmlSrcLen,&nWrite);
        vm_file_close(nHdl);
    }
#endif
    vm_xml_new_parser(&XmlParser);

    vm_xml_set_element_handlers(&XmlParser,am_net_xml_appinfo_start_elem_hdlr,am_net_xml_appinfo_end_elem_hdlr);
    vm_xml_set_data_handler(&XmlParser,am_net_xml_appinfo_data_hdlr);
    nResult = vm_xml_parse(&XmlParser,pXmlSource,unXmlSrcLen);

    if (nResult == VM_XML_RESULT_OK)
        return AM_NET_OK;
    else
        return AM_NET_ERR;
}

void am_net_vip_appinfo_callback(VMINT uid, VMINT mpi, VMINT vip_response_type, 
                                 const void* vip_response, VMUINT response_size)
{
    VMINT nResult;
#ifdef LOG_NET
    vm_log_debug("[NET] net_vip_appinfo_callback,uid=%d,mpi=%d,vip_response_type=%d",uid,mpi,vip_response_type);
#endif
    if (vip_response_type == RES_RESCONTENT_CMD)
    {
        vm_save_mobile_phone_id_record(mpi);
        vm_save_user_id_record(uid);
        //vip_update_mpuid(mpi,uid);


        nResult = am_net_xml_appinfo_parse((VMCHAR *)vip_response, response_size);

        if (nResult == AM_NET_ERR)
        {
            am_net_xml_stack_clear(g_AMNetManager.DataStack);
            am_net_xml_stack_clear(g_AMNetManager.ElmtStack);
#ifdef LOG_NET
            vm_log_debug("[NET] net_vip_appinfo_callback,appInfo parse error");
#endif
            SAFE_FREE(g_AMAppInfPasManager.pAppInfo);
        }
        else if (g_AMAppInfPasManager.nResult == 3)//服务器返回无适配版本
        {
            nResult = AM_NET_ERR2;
#ifdef LOG_NET
            vm_log_debug("[NET] net_vip_appinfo_callback,app version dosent match.");
#endif
        }
        else if (g_AMAppInfPasManager.nResult == 2)//服务器返回合法报文中错误码
        {
            nResult = AM_NET_ERR2;
#ifdef LOG_NET
            vm_log_debug("[NET] net_vip_appinfo_callback,app info get error.");
#endif
        }
    }
    else
        nResult = AM_NET_ERR;

#ifdef LOG_NET
    vm_log_debug("[NET] net_vip_appinfo_callback,nresult=%d",nResult);
#endif
    if (g_AMNetManager.get_single_app_info_cb)
        g_AMNetManager.get_single_app_info_cb(nResult,g_AMAppInfPasManager.pAppInfo);

    g_AMAppInfPasManager.pAppInfo = NULL;
}

VMINT am_net_init(void)
{
    if (vm_load_mobile_phone_id_record(&g_AMNetManager.nPhoneId) != VM_ADAPTER_NVRAM_SUCCESS)
        g_AMNetManager.nPhoneId = 0;
    if (vm_load_user_id_record(&g_AMNetManager.nUserId) != VM_ADAPTER_NVRAM_SUCCESS)
        g_AMNetManager.nUserId = 0;
#ifdef LOG_NET
    vm_log_debug("[NET] net_init,uid=%d,mpi=%d",g_AMNetManager.nUserId,g_AMNetManager.nPhoneId);
#endif	
    if (!vip_init_ext(g_AMNetManager.nPhoneId, g_AMNetManager.nUserId, VIP_APP_HANDLE))
    {
#ifdef LOG_NET
        vm_log_fatal("[AMNET] vip_init done.");
#endif
        kal_prompt_trace(MOD_MMI, "[AMNET] vip_init_ext ok");
        memset(&g_AMNetManager,0,sizeof(g_AMNetManager));
        g_AMNetManager.ElmtStack = am_net_xml_stack_create();
        g_AMNetManager.DataStack = am_net_xml_stack_create();

        memset(&g_AMAppInfPasManager,0,sizeof(g_AMAppInfPasManager));
        return AM_NET_OK;
    }
    else
    {
#ifdef LOG_NET
        vm_log_fatal("[AMNET] vip_init_ext error.");
#endif
        kal_prompt_trace(MOD_MMI, "[AMNET] vip_init_ext error");
        return AM_NET_ERR;
    }
}


#define UPDATE_CONFIG_PATH "/update/config.txt?timezonzeid=China&permission=%s&cert=%s&appblalst=%s&channel=%s&appstore=%s"
#define APPLIST_PATH "/shell/app_list.txt?folderid=%d&start=%d&end=%d"//更多分类
#define TOP_DOWNLOAD_PATH "/shell/down_top.txt?folderid=%d&start=%d&end=%d"//热门下载
#define NEW_PRODUCT_PATH "/shell/new_top.txt? folderid=%d&start=%d&end=%d"//最新上架
#define RECOMMEND_PATH "/shell/recommend.txt? folderid=%d&start=%d&end=%d"//精品推荐
#define DOWNLOAD_ICON "/shell/download_icon.txt?type=%d&folderid=%s&appid=%s"//图标下载
#define DOWNLOAD_APP "/shell/download_app.txt?appid=%d&range=%d-%d&md5=%s"
#define RANK_APP "/shell/rank_app.txt?verid=%s&version=%s&rank=%d"
#define MSG_LIST "/shell/msg_list.txt"
#define APP_DETAIL "/shell/app_detail.txt?appid=%d"
#define WAP_LIST "/shell/wap_list.txt"



VMINT am_net_get_single_app_info(void(*get_single_app_info)(VMINT nResult, AppInfo_t *pAppInfo), VMINT nAppID)
{

    memset(g_AMNetManager.szResPath,0,sizeof(g_AMNetManager.szResPath));

    g_AMNetManager.get_single_app_info_cb = get_single_app_info;

    sprintf(g_AMNetManager.szResPath,APP_DETAIL,nAppID);

    vip_cancel_request_handle(VIP_APP_HANDLE);
    register_vip_callback_for_app(am_net_vip_appinfo_callback);

    if (vip_read_resource(g_AMNetManager.szResPath) == 0)//发起成功，等待回调
    {
#ifdef LOG_NET
        vm_log_debug("[NET] net_get_single_app_info,send vip read resource ok");
#endif
        return AM_NET_OK;
    }
    else
    {
#ifdef LOG_NET
        vm_log_debug("[NET] net_get_single_app_info,send vip read resource error");
#endif
        return AM_NET_ERR;
    }
}


void am_net_release(void)
{
    vip_cancel_request_handle(VIP_APP_HANDLE);
    //vip_cancel_request_and_finalize();
    am_net_xml_stack_destroy(g_AMNetManager.DataStack);
    g_AMNetManager.DataStack = NULL;
    am_net_xml_stack_destroy(g_AMNetManager.ElmtStack);
    g_AMNetManager.ElmtStack = NULL;
}
#endif

