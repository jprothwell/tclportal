/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * AMShortcut.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to complete the function HS shortcut in AM.
 *
 * Author:
 * -------
 * Lihong Li(mtk80092)
 *
*==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * Mar 26 2010 mtk80092
 * [MAUI_02168357] [AM] can not use the shortcut
 * 
 *
 * Mar 1 2010 mtk80092
 * [MAUI_02356136] [VRE3.0][AM]The default games should be create shortcut success.
 * 
 *
 * Mar 1 2010 mtk80092
 * [MAUI_02356136] [VRE3.0][AM]The default games should be create shortcut success.
 * 
 *
 * Jan 22 2010 mtk80092
 * [MAUI_02338338] [VRE3.0][AM]create shortcut will popup "File not found".
 * 
 *
 * Jan 17 2010 mtk80092
 * [MAUI_02065831] wromg popup on craeting shortcut
 * 
 *
 * Jan 15 2010 mtk80092
 * [MAUI_02137769] [AM] Behavior abnormal here
 * 
 *
 * Jan 15 2010 mtk80092
 * [MAUI_02137769] [AM] Behavior abnormal here
 * 
 *
 * Jan 5 2010 mtk80092
 * [MAUI_02134558] [AM]should popup "USB: Function not allowed" when launch the shortcut in USB status
 * 
 *
 * Dec 28 2009 mtk80092
 * [MAUI_02126624] [MMI][AM] AM check-in
 * 
 *
 * Dec 28 2009 mtk80092
 * [MAUI_02126624] [MMI][AM] AM check-in
 * 
 *
 * Dec 28 2009 mtk80092
 * [MAUI_02126624] [MMI][AM] AM check-in
 * 
 *
 * Dec 25 2009 mtk80092
 * [MAUI_02126624] [MMI][AM] AM check-in
 * 
 * * 
 * *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "mmi_include.h" 
#if defined (__MMI_VUI_HOMESCREEN__) && defined(__VRE30_AM__)

#include "mmidatatype.h"

#include "CommonScreens.h"
#include "custom_mmi_default_value.h"

#include "amGprot.h"
#include "vmsys.h"
#include "amshortcut.h"
#include "AMResDef.h"
#include "vmshortcut.h"
#include "vmcerter.h"
#include "Amdef.h"

#define VENUS_SHORTCUT_NUMBER  5        /* if modify the value, must modify NVRAM_EF_VRE_HS_SHORTCUT_LIST_TOTAL */
#define AM_SHORTCUT_FOLDER   L"Z:\\@AM\\"
#define AM_SHORTCUT_PATH     L"Z:\\@AM\\M"
#define AM_SHORTCUT_PATH_0   L"Z:\\@AM\\A"
#define AM_SHORTCUT_PATH_1   L"Z:\\@AM\\B"
#define AM_SHORTCUT_PATH_2   L"Z:\\@AM\\C"
#define AM_SHORTCUT_PATH_3   L"Z:\\@AM\\D"
#define AM_SHORTCUT_PATH_4   L"Z:\\@AM\\E"

#define AM_SHORTCUT_PATH_DEFAULT  L"Z:\\@AM\\N"

typedef struct
{
    U32 number;
    U32 id;
    U16 icon_path[MAX_ICON_FILE_NAME_SIZE];
    U16 src_path[50];
    U16 is_used;

} am_shortcut;

typedef struct
{
    U8 shortcut_num;
    U32 active_id;
} am_shortcut_context;

am_shortcut_context g_shortcut_cont;
am_shortcut shortcut_array[VENUS_SHORTCUT_NUMBER];


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_all_shortcut_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id_array        [?]         
 *  size            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_get_all_shortcut_id(U32 *id_array, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0,j=0,mark =0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(j=0;j<g_shortcut_cont.shortcut_num;j++)
	{	
		for (i = mark; i < VENUS_SHORTCUT_NUMBER; i++)
		{
			if(shortcut_array[i].is_used == MMI_TRUE)
			{
				id_array[j] = shortcut_array[i].id;
				mark =i+1;
				break;
			}
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_shortcut_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_am_get_shortcut_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_NUMBER, g_shortcut_cont.shortcut_num);

    return g_shortcut_cont.shortcut_num /* its value is set when init */ ;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_read_shorcut_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_read_shorcut_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(shortcut_array, 0, sizeof(shortcut_array));
   
    for (i = 0; i < VENUS_SHORTCUT_NUMBER; i++)
    {
        ReadRecord(
            NVRAM_EF_AM_HS_SHORTCUT_LIST_LID,
            i + 1,
            (void*)&shortcut_array[i],
            NVRAM_EF_AM_HS_SHORTCUT_LIST_SIZE,
            &error);

    }
	g_shortcut_cont.shortcut_num = shortcut_array[0].number;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_read_shorcut_record();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_write_shorcut_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_write_shorcut_record(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* WriteValue(NVRAM_AM_SHORTCUT_NUMBER, &g_shortcut_cont.shortcut_num, DS_BYTE, &error); */
    shortcut_array[0].number = g_shortcut_cont.shortcut_num;
    if(index != 0)
	{
		WriteRecord(
			NVRAM_EF_AM_HS_SHORTCUT_LIST_LID,
			1,
			(void*)&shortcut_array[0],
			NVRAM_EF_AM_HS_SHORTCUT_LIST_SIZE,
			&error);
	}

    WriteRecord(
        NVRAM_EF_AM_HS_SHORTCUT_LIST_LID,
        index + 1,
        (void*)&shortcut_array[index],
        NVRAM_EF_AM_HS_SHORTCUT_LIST_SIZE,
        &error);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_create_shortcut_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_create_shortcut_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE folder_hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_hd = FS_Open(AM_SHORTCUT_FOLDER, FS_OPEN_DIR | FS_READ_ONLY);
    if (folder_hd < FS_NO_ERROR)
    {
        folder_hd = FS_CreateDir(AM_SHORTCUT_FOLDER);
        MMI_ASSERT(folder_hd >= 0);
        g_shortcut_cont.shortcut_num = 0;
        mmi_am_write_shorcut_record(0);
    }
    else
    {
        FS_Close(folder_hd);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_shortcut_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_id         [IN]        
 *  icon_file       [?]         
 *  size            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_get_shortcut_icon(U32 icon_id, U16 *icon_file, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_ICON);
    if (g_shortcut_cont.shortcut_num != 0)
    {

        for (i = 0; i < VENUS_SHORTCUT_NUMBER; i++)
        {
            if (icon_id == shortcut_array[i].id)
            {
                 MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_ICON_ID, icon_id);
                break;
            }
        }

        if (i == VENUS_SHORTCUT_NUMBER)
        {
            icon_file = NULL;
        }
        else
        {
            mmi_wcscpy(icon_file, shortcut_array[i].icon_path);
        }
    }
    else
    {
        icon_file = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_set_as_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_path       [IN]         
 *  icon_buffer     [IN]         
 *  icon_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_am_set_as_shortcut(U16 *full_path, U8 *icon_buffer, U32 icon_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    FS_HANDLE file_hd = -1;
    FS_HANDLE fd = -1;
    U32 written_size = 0;
    VMINT ret = -1;
    U32 id = 0;
	U8 * dir = (U8 *)full_path;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SET_AS_SHORTCUT);
        
    if(*dir != MMI_AM_ROM_DIR)
    {
	    fd = FS_Open(full_path, FS_READ_ONLY);
	    if(fd < 0)
	    {
	        return MMI_AM_SHORTCUT_FILE_NOT_FOUND;
	    }
	    else
	    {
	        FS_Close(fd); 
	    }   
    }
    mmi_am_create_shortcut_folder();
    if (g_shortcut_cont.shortcut_num >= VENUS_SHORTCUT_NUMBER)
        return MMI_AM_SHORTCUT_OVER_NUMBER;

    if (icon_size == 0 || icon_buffer == NULL ||full_path == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_ICON_SIZE_FAIL);
        return MMI_AM_SHORTCUT_ICON_SIZE_FAIL;
    }


    /*check if the app-id has been set as shortcut*/
    id = vm_get_appid((VMWSTR) full_path);
    for(i=0; i< VENUS_SHORTCUT_NUMBER;i++ )
    {
        if((id == shortcut_array[i].id)&&
             (shortcut_array[i].is_used == MMI_TRUE))
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_DUPLICATE_ID);
            return MMI_AM_SHORTCUT_DUPLICATE_ID;
        }
    }

    /* vre verify api-reserved */
   ret = vm_app_is_valid((VMWSTR)full_path);
       
   if(ret != 0)
   {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_VERIFY_FAIL,ret);
        switch(ret)
        {
            case VM_CE_VERIFY_KEY_EXPIRED:return MMI_AM_SHORTCUT_CERT_EXPIRED;
            case VM_CE_VERIFY_TIMESTAMP_ERROR:return MMI_AM_SHORTCUT_WRONG_DATE;
            case VM_CE_VERIFY_IMSI_DISMATCH:return MMI_AM_SHORTCUT_IMSI_DISMATCH;
            case VM_CE_VERIFY_RESOLUTION_DISMATCH: return MMI_AM_SHORTCUT_WRONG_PLATFORM;   
            default:return MMI_AM_SHORTCUT_STRUCTURE_FAIL;
        }
   }  

    for (i = 0; i < VENUS_SHORTCUT_NUMBER; i++)
    {
        if (shortcut_array[i].is_used == MMI_FALSE)
            break;
    }

    if (i >= VENUS_SHORTCUT_NUMBER)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_STRUCTURE_FAIL,i);
        return MMI_AM_SHORTCUT_STRUCTURE_FAIL;
    }

    /* get icon info */

    /* get icon name */
    switch (i)
    {
        case 0:
            mmi_wcscpy(shortcut_array[i].icon_path, AM_SHORTCUT_PATH_0);
            break;
        case 1:
            mmi_wcscpy(shortcut_array[i].icon_path, AM_SHORTCUT_PATH_1);
            break;
        case 2:
            mmi_wcscpy(shortcut_array[i].icon_path, AM_SHORTCUT_PATH_2);
            break;
        case 3:
            mmi_wcscpy(shortcut_array[i].icon_path, AM_SHORTCUT_PATH_3);
            break;
        case 4:
            mmi_wcscpy(shortcut_array[i].icon_path, AM_SHORTCUT_PATH_4);
            break;
        default:
            mmi_wcscpy(shortcut_array[i].icon_path, AM_SHORTCUT_PATH_DEFAULT);

    }

    /* save icon info to file */
    file_hd = FS_Open(shortcut_array[i].icon_path, FS_READ_WRITE);
    if (file_hd >= 0)
    {
    	  FS_Close(file_hd);
        FS_Delete(shortcut_array[i].icon_path);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_STRUCTURE_FAIL,i);
    }
		file_hd = FS_Open(shortcut_array[i].icon_path, FS_CREATE_ALWAYS);
		FS_Write(file_hd, icon_buffer, icon_size, &written_size);
		FS_Close(file_hd);
		if (icon_size != written_size)
		{
		    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_FILE_FAIL);
		    return MMI_AM_SHORTCUT_FILE_FAIL;
		}
	    

    /* get other info */
    mmi_wcscpy(shortcut_array[i].src_path, full_path);
    shortcut_array[i].id = id;
    shortcut_array[i].is_used = MMI_TRUE;
    g_shortcut_cont.shortcut_num++;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_INFO,shortcut_array[i].id,
        shortcut_array[i].is_used,g_shortcut_cont.shortcut_num,i);
    /* save shortcut info */
    mmi_am_write_shorcut_record(i);

    return MMI_AM_SHORTCUT_SET_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_cancel_shortcut_intel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_cancel_shortcut_intel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    FS_HANDLE icon_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the shortcut */
    i = g_shortcut_cont.active_id;
    /* delete the icon file */
    icon_handle = FS_Open(shortcut_array[i].icon_path, FS_READ_WRITE);

    if (icon_handle < 0)
    {
        mmi_display_popup(get_string(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
    }
    else
    {
        FS_Close(icon_handle);
        FS_Delete(shortcut_array[i].icon_path);

        /* update shortcut info */
        shortcut_array[i].is_used = MMI_FALSE;
        g_shortcut_cont.shortcut_num--;

        /* save */
        mmi_am_write_shorcut_record(i);
        mmi_display_popup(get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_set_as_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_path       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_is_set_as_shortcut(U16 *full_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(full_path == NULL)
       
    return MMI_FALSE;
    

	if(!mmi_phnset_get_vui_homescreen_status())
	{
   		return MMI_FALSE;
	}

    
    for (; i < VENUS_SHORTCUT_NUMBER; i++)
    {
        if ((mmi_wcscmp(full_path, shortcut_array[i].src_path) == 0)
			&&(shortcut_array[i].is_used == MMI_TRUE))
            return MMI_TRUE;
    }
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_shortcut_support
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_path       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_is_shortcut_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   	if(!mmi_phnset_get_vui_homescreen_status())
	{
   		return MMI_FALSE;
	}
	else
	{
		return MMI_TRUE;
	}

}




/*****************************************************************************
 * FUNCTION
 *  mmi_am_query_cancel_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_query_cancel_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_confirm(
        get_string(STR_GLOBAL_YES),
        get_image(IMG_GLOBAL_YES),
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        get_string(STR_ID_AM_SHORTCUT_HS_DEL),
        MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_am_cancel_shortcut_intel, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_launch_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_launch_shortcut(U32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    FS_HANDLE fd;
	U8 * dir = NULL; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_LAUNCH,icon_id);
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
         /* phone drive is exported, cant use this app */
          mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
          return;
       
    }
#endif /* __USB_IN_NORMAL_MODE__ */     
    for (i = 0; i < VENUS_SHORTCUT_NUMBER; i++)
    {
        if ((shortcut_array[i].id == icon_id)&&
            (shortcut_array[i].is_used == MMI_TRUE))
            break;
    }
	dir = (U8 *)shortcut_array[i].src_path;
    if (i >= VENUS_SHORTCUT_NUMBER)
    {
        mmi_display_popup(get_string(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
	}
    else if(*dir != MMI_AM_ROM_DIR)
    {
        fd = FS_Open(shortcut_array[i].src_path, FS_OPEN_NO_DIR|FS_READ_ONLY);
        if (fd < FS_NO_ERROR)
        {
            g_shortcut_cont.active_id = i;
            mmi_am_query_cancel_shortcut();

        }
        else
        {
            FS_Close(fd);
            mmi_am_start_from_hs(shortcut_array[i].src_path);
        }
    }
	else
	{
		mmi_am_start_from_hs(shortcut_array[i].src_path);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_cancel_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  icon_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_am_cancel_shortcut(U16 * path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SHORTCUT_CANCEL);
    if(path == NULL)
        return;

    for(i=0;i < VENUS_SHORTCUT_NUMBER;i++)
    {
        if((mmi_wcscmp(path,shortcut_array[i].src_path)==0)
			&& (shortcut_array[i].is_used == MMI_TRUE))
        break;
    }
    MMI_ASSERT(i < VENUS_SHORTCUT_NUMBER);
    FS_Delete(shortcut_array[i].icon_path);
    /* update shortcut info */
    shortcut_array[i].is_used = MMI_FALSE;
    g_shortcut_cont.shortcut_num--;

    /* save */
    mmi_am_write_shorcut_record(i);
}



#endif /* defined (__VENUS_UI_ENGINE__) && defined(__VRE30_AM__) */ 

