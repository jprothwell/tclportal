/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   AMUtil.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   AM Utility Src
 *
 * Author:
 * -------
 *  Keith Chen
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __VRE30_AM__

/***************************************************************************** 
* Include header files
*****************************************************************************/
#ifdef __VRE_AM_08AB__
#include "MMI_include.h"
#else
#include "MMI_frm_gprot.h"
#endif
#include "Conversions.h"
#include "gdi_include.h"
#ifndef __VRE_AM_08AB__
#include "SimDetectionStruct.h"
#endif
#include "CommonScreens.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_if.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif

#include "AMResDef.h"   /* Add AM head file */
#include "AMDef.h"      /* Add AM head file */
#include "AMGprot.h"    /* Add AM head file */
#include "AMprot.h"     /* Add AM head file */
#include "AMConfig.h"
#include "AMUtil.h"

/*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/
const static U8 bits[] = {0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1};
extern mmi_am_cntx_struct g_am_cntx;

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern pBOOL mmi_bootup_get_active_flight_mode(void);
//extern void mmi_idle_get_dual_sim_status(U8 *sim_status, U8 *mode_status);


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_removeable_driver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 mmi_am_get_removeable_driver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM) ==
        FS_NO_ERROR)
    {
        drive = (S8) FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if ((drive >= 'A') && (drive <= 'Z'))
        {
            return drive;
        }
    }
    return (S8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_system_driver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 mmi_am_get_system_driver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive = (S8) FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    if ((drive >= 'A') && (drive <= 'Z'))
    {
        return drive;
    }

    return (S8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_home_driver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 mmi_am_get_home_driver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int driver;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    driver = mmi_am_get_removeable_driver();
    if (driver == 0)
    {
        driver = mmi_am_get_system_driver();
    }

    return (S8) driver;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_scrmem_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void *mmi_am_scrmem_malloc(int size)
{
	mmi_frm_scrmem_alloc(size);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_scrmem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_am_scrmem_free(void *point)
{
	mmi_frm_scrmem_free(point);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_am_malloc(int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.adm_pool_id)
    {
    #ifdef WIN32
        return kal_adm_alloc(g_am_cntx.adm_pool_id, size);
    #else 
#ifdef __VRE_AM_08AB__
        return kal_adm_alloc(g_am_cntx.adm_pool_id, size);
#else
        return MMI_FRM_ADM_ALLOC_FRAMEBUFFER(g_am_cntx.adm_pool_id, size);
#endif
    #endif 
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_calloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_am_calloc(int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p = mmi_am_malloc(size);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p != NULL)
        memset(p, 0, size);

    return p;
}

#if 0
void *mmi_am_realloc(void *p, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(size == 0)
    {
        if(p) mmi_am_free(p);
        return NULL;
    }
    
    p1 = mmi_am_calloc(size);
    
    if (p && p1)
    {
        memcpy(p1, p, size);
        mmi_am_free(p);
    }
    
    return p1;
}
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.adm_pool_id && (ptr != NULL))
    {
        kal_adm_free(g_am_cntx.adm_pool_id, ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_total_left_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_am_get_total_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.adm_pool_id)
    {
        return kal_adm_get_total_left_size(g_am_cntx.adm_pool_id);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_font_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_am_get_font_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_w[10];
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_AM_ONLY_USE_ZIMO
    height = 0;
#else /* MMI_AM_ONLY_USE_ZIMO */ 
    memset(str_w, 0, sizeof(str_w));
    mmi_chset_convert(MMI_CHSET_GB2312, MMI_CHSET_UCS2, (S8*) MMI_AM_TEST_STRING, (S8*) str_w, sizeof(str_w));

    gui_set_font(&MMI_small_font);
    gui_measure_string((UI_string_type) str_w, &width, &height);
    gui_set_font(&MMI_medium_font);
#endif /* MMI_AM_ONLY_USE_ZIMO */ 

    return height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_app_is_bg_running
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_app_is_bg_running(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path)
    {
        return mmi_am_vre_app_is_running((PU16) path);
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_app_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_path       [IN]        
 *  version         [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_get_app_version(U16 *full_path, S32 *version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (full_path == NULL || version == NULL)
    {
        return MMI_FALSE;
    }

    return mmi_am_vre_get_app_version(full_path, version);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_rom_app_array
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_array_ptr           [IN]        
 *  app_array_len_ptr       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_get_rom_app_array(S32 **app_array_ptr, S32 *app_array_len_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_vre_get_buildin_app_array(app_array_ptr, app_array_len_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_gif_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source          [IN]        
 *  p_gif           [OUT]       
 *  icon_size       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_get_gif_data(U8 *source, U8 **p_gif, U32 *icon_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8 *temp_ptr = NULL;
    U8 *dest = NULL;
    S32 data_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (source == 0)
    {
        return MMI_FALSE;
    }

    /* the icon buffer has been allocated */
    if (*p_gif != NULL)
    {
        return MMI_TRUE;
    }

    ret = mmi_am_vre_get_gif_data((PS8) source, &temp_ptr, &data_len);
    if (ret == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    /* allocate memory */
    dest = mmi_am_calloc(data_len);
    if (dest == NULL)
    {
        return MMI_FALSE;
    }

    memcpy(dest, temp_ptr, data_len);
    *p_gif = dest;
    *icon_size = data_len;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_zimo_string_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source          [IN]        
 *  p_str           [OUT]       
 *  name_len        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_get_zimo_string_data(U8 *source, U8 **p_str, S32 *name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8 *temp_ptr = NULL;
    U8 *dest = NULL;
    S32 data_size, temp_name_len;
    S32 font_size;
    U8 *lang = NULL;
    MMI_AM_LANGUAGE_TYPE language = MMI_AM_ENG;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (source == 0)
    {
        return MMI_FALSE;
    }

    /* the zimo buffer has been allocated */
    if (*p_str != NULL)
    {
				if(g_am_cntx.is_card_plug_in || g_am_cntx.is_card_plug_out)
				{
					mmi_am_free(*p_str);
				}
       else
		   	{
		   		return MMI_TRUE;
		   	}
    }

    lang = Get_Current_Lang_CountryCode();
    if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
    {
        language = MMI_AM_ENG;
    }
    else if (strcmp((PS8) lang, "zh-CN") == 0)
    {
        language = MMI_AM_CHS;
    }
    else if (strcmp((PS8) lang, "zh-TW") == 0)
    {
        language = MMI_AM_CHT;
    }

    ret = mmi_am_vre_get_string_data((PS8) source, &temp_ptr, language, &temp_name_len, &font_size, &data_size);
    if (ret == MMI_FALSE)   /* && (temp_ptr != NULL)) */
    {
        language = (language == MMI_AM_ENG) ? MMI_AM_CHS : MMI_AM_ENG;
        ret = mmi_am_vre_get_string_data((PS8) source, &temp_ptr, language, &temp_name_len, &font_size, &data_size);
        if (ret == MMI_FALSE)
        {
            return MMI_FALSE;
        }
    }

    /* allocate memory */
    dest = mmi_am_calloc(data_size);
    if (dest == NULL)
    {
        return MMI_FALSE;
    }

    memcpy(dest, temp_ptr, data_size);
    *p_str = dest;
    *name_len = temp_name_len;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_app_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 *  icon_src        [IN]        
 *  des_buf         [OUT]       
 *  name_len        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_get_app_name(U16 *file_path, U8 *icon_src, void **des_buf, U32 *name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL gettag_ret, ret = MMI_TRUE;
    S32 result;
    S32 size;
    S8 *temp_buf;
    U8 *lang = NULL;
    MMI_AM_LANGUAGE_TYPE language = MMI_AM_CHS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the name buffer has been allocated */
    if (*des_buf != NULL)
    {
        return MMI_TRUE;
    }

    lang = Get_Current_Lang_CountryCode();
    if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
    {
        language = MMI_AM_ENG;
    }
    else if (strcmp((PS8) lang, "zh-CN") == 0)
    {
        language = MMI_AM_CHS;
    }
    else if (strcmp((PS8) lang, "zh-TW") == 0)
    {
        language = MMI_AM_CHT;
    }

    /* support small font */
    if (g_am_cntx.has_small_font)
    {
        /* get name buffer size */
        gettag_ret = mmi_am_vre_get_vm_tag_by_lang(file_path, INFO_NAME, NULL, &size, language);
        if (!gettag_ret)
        {
            gettag_ret = mmi_am_vre_get_vm_tag(file_path, INFO_NAME, NULL, &size);
        }

        if (gettag_ret)
        {
            *des_buf = mmi_am_calloc((size + 1) << 1);
            if (!(*des_buf))
            {
                return MMI_FALSE;
            }

            temp_buf = mmi_am_calloc(size + 1);
            if (!temp_buf)
            {
                mmi_am_free(*des_buf);
                return MMI_FALSE;
            }

            /* get name */
            gettag_ret = mmi_am_vre_get_vm_tag_by_lang(file_path, INFO_NAME, temp_buf, &size, language);
            if (!gettag_ret)
            {
                gettag_ret = mmi_am_vre_get_vm_tag(file_path, INFO_NAME, temp_buf, &size);
                language = MMI_AM_CHS;
            }

            if (!gettag_ret)
            {
                ret = MMI_FALSE;
            }
            strcat((PS8) temp_buf, "\0");

            /* convert char-set */
            if (language == MMI_AM_CHT)
            {
                result = mmi_chset_convert(
                            MMI_CHSET_BIG5,
                            MMI_CHSET_UCS2,
                            (S8*) temp_buf,
                            (S8*) * des_buf,
                            (size + 1) << 1);
            }
            else
            {
                result = mmi_chset_convert(
                            MMI_CHSET_GB2312,
                            MMI_CHSET_UCS2,
                            (S8*) temp_buf,
                            (S8*) * des_buf,
                            (size + 1) << 1);
            }
            if (result <= 0)
            {
                ret = MMI_FALSE;
            }

            mmi_wcscat((PU16) * des_buf, L"\0");
            *name_len = (U32) size;

            mmi_am_free(temp_buf);
        }
        else
        {
            ret = MMI_FALSE;
        }
    }
    /* dont support small font */
    else
    {
        result = mmi_am_get_zimo_string_data(icon_src, (U8 **) des_buf, (S32*) name_len);
        if (!result)
        {
            return MMI_FALSE;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_info_by_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 *  tag             [IN]        
 *  des_buf         [IN]        
 *  des_size        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_get_info_by_tag(U16 *file_path, MMI_AM_INFO_TYPE tag, void **des_buf, U32 *des_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL gettag_ret, ret = MMI_TRUE;
    S32 result;
    S32 size;
    S8 *temp_buf;
    U8 *lang = NULL;
    MMI_AM_LANGUAGE_TYPE language = MMI_AM_CHS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lang = Get_Current_Lang_CountryCode();
    if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
    {
        language = MMI_AM_ENG;
    }
    else if (strcmp((PS8) lang, "zh-CN") == 0)
    {
        language = MMI_AM_CHS;
    }
    else if (strcmp((PS8) lang, "zh-TW") == 0)
    {
        language = MMI_AM_CHT;
    }

    /* get app info size */
    gettag_ret = mmi_am_vre_get_vm_tag_by_lang(file_path, tag, NULL, &size, language);
    if (!gettag_ret)
    {
        gettag_ret = mmi_am_vre_get_vm_tag(file_path, tag, NULL, &size);
    }

    if (gettag_ret)
    {
        *des_buf = mmi_am_calloc((size + 1) << 1);
        if (!(*des_buf))
        {
            return MMI_FALSE;
        }

        temp_buf = mmi_am_calloc(size + 1);
        if (!temp_buf)
        {
            mmi_am_free(*des_buf);
            return MMI_FALSE;
        }

        gettag_ret = mmi_am_vre_get_vm_tag_by_lang(file_path, tag, temp_buf, &size, language);
        if (!gettag_ret)
        {
            gettag_ret = mmi_am_vre_get_vm_tag(file_path, tag, temp_buf, &size);
            language = MMI_AM_CHS;
        }

        if (!gettag_ret)
        {
            ret = MMI_FALSE;
        }
        strcat((PS8) temp_buf, "\0");

        /* convert char-set */
        if (language == MMI_AM_CHT)
        {
            result = mmi_chset_convert(MMI_CHSET_BIG5, MMI_CHSET_UCS2, (S8*) temp_buf, (S8*) * des_buf, (size + 1) << 1);
        }
        else
        {
            result = mmi_chset_convert(MMI_CHSET_GB2312, MMI_CHSET_UCS2, (S8*) temp_buf, (S8*) * des_buf, (size + 1) << 1);
        }
        if (result <= 0)
        {
            ret = MMI_FALSE;
        }

        mmi_wcscat((PU16) * des_buf, L"\0");
        *des_size = (U32) result;

        mmi_am_free(temp_buf);
    }
    else
    {
        ret = MMI_FALSE;
    }

    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_measure_zimo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  zimo_buf        [IN]        
 *  str_len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_am_measure_zimo(U8 *zimo_buf, S32 str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_am_vre_measure_zimo_string((PS8) zimo_buf, str_len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_draw_asc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  font_size       [IN]        
 *  font_data       [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_draw_asc(S32 x, S32 y, S32 font_size, const U8 *font_data, gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < font_size; i++)
    {
        for (j = 0; j < font_size / 2; j++)
        {
            if (font_data[i * ((font_size / 2 + 7) / 8) + (j / 8)] & bits[j % 8])
            {
                if ((x + j > 0) && (x + j < GDI_LCD_WIDTH) && (y + i) > 0 && (y + i < GDI_LCD_HEIGHT))
                    gdi_draw_point(x + j, y + i, color);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_draw_hz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  font_size       [IN]        
 *  font_data       [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_draw_hz(S32 x, S32 y, S32 font_size, const U8 *font_data, gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < font_size; i++)
    {
        for (j = 0; j < font_size; j++)
        {
            if (font_data[i * ((font_size + 7) / 8) + (j / 8)] & bits[j % 8])
            {
                if ((x + j > 0) && (x + j < GDI_LCD_WIDTH) && (y + i) > 0 && (y + i < GDI_LCD_HEIGHT))
                    gdi_draw_point(x + j, y + i, color);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_draw_zimo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  start_idx       [IN]        
 *  out_str_len     [IN]        
 *  src_buf         [IN]        
 *  str_len         [IN]        
 *  font            [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_draw_zimo(
        S32 x,
        S32 y,
        S32 start_idx,
        S32 out_str_len,
        U8 *src_buf,
        S32 str_len,
        S32 font,
        gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count, flag, offset, offset_out, offset_ch;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src_buf || (str_len <= 0) || (start_idx >= str_len) || ((font != 12) && (font != 14) && (font != 16)))
        return;

    count = (start_idx + out_str_len < str_len) ? out_str_len : (str_len - start_idx);
    offset = 0;

    for (i = 0; i < start_idx; i++)
    {
        offset += *(src_buf + offset + 1) + 2;
    }

    for (i = 0, offset_out = 0; i < count; i++)
    {
        flag = *(src_buf + offset);
        offset_ch = *(src_buf + offset + 1);

        if (flag == 2)
        {
            mmi_am_draw_asc(x + offset_out, y, font, (src_buf + offset + 2), color);
            offset_out += font / 2;
        }
        else
        {
            mmi_am_draw_hz(x + offset_out, y, font, (src_buf + offset + 2), color);
            offset_out += font;
        }
        offset += offset_ch + 2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_support_wifi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_is_support_wifi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else /* __MMI_WLAN_FEATURES__ */ 
    return MMI_FALSE;
#endif /* __MMI_WLAN_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_sim_card_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_am_get_sim_card_num(void)
{
    #if 0
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_status, mode_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_get_active_flight_mode())
    {
        return 0;
    }

    mmi_idle_get_dual_sim_status(&sim_status, &mode_status);

    if ((sim_status == MMI_SIM_ID_SIM1 && mode_status == MMI_SIM_ID_SIM1)
        || (sim_status == MMI_SIM_ID_DUAL_SIM && mode_status == MMI_SIM_ID_SIM1)
        || (sim_status == MMI_SIM_ID_DUAL_SIM && mode_status == MMI_SIM_ID_SIM2)
        || (sim_status == MMI_SIM_ID_SIM2 && mode_status == MMI_SIM_ID_SIM2)
        || (sim_status == MMI_SIM_ID_SIM1 && mode_status == MMI_SIM_ID_DUAL_SIM)
        || (sim_status == MMI_SIM_ID_SIM2 && mode_status == MMI_SIM_ID_DUAL_SIM))
    {
        return 1;
    }
    else if ((sim_status == MMI_SIM_ID_DUAL_SIM) && (mode_status == MMI_SIM_ID_DUAL_SIM))
    {
        return 2;
    }

    return 0;
    #else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_am_is_network_service_available())
    {
        return 0;
    }

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
    {
        return 0;
    }
#endif /* __MMI_WLAN_FEATURES__ */ 

#ifndef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim_valid())
    {
        return 1;
    }
#else
    if (MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)
    {
        return 2;
    }
    else if (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE ||
        MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE)
    {
        return 1;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    return 0;
    
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_sim_card
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_index       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_get_sim_card(mmi_am_sim_settings_enum *sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 sim_settings;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_am_vre_get_sim_card(&sim_settings);

    if (ret)
    {
        *sim_index = (mmi_am_sim_settings_enum) sim_settings;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_net_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  net_type        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_get_net_type(mmi_am_conn_settings_enum *net_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 net_settings;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_am_vre_get_net_type(&net_settings);

    if (ret)
    {
        *net_type = (mmi_am_conn_settings_enum) net_settings;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_set_sim_card
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choose_index        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_set_sim_card(S32 choose_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_am_vre_set_sim_card(choose_index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_set_net_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  net_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_set_net_type(S32 net_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_am_vre_set_net_type(net_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_app_type_by_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_AM_VRE_APP_TYPE mmi_am_get_app_type_by_path(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buf = -1;
    S32 buf_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_vre_get_vm_tag(app_path, INFO_BG_RUN, &buf, &buf_size) || buf_size == 4)
    {
        return VRE30_APP;
    }
    else if (mmi_am_vre_get_vm_tag(app_path, INFO_NAME, &buf, &buf_size))
    {
        return VRE20_APP;
    }

    return ILLEGAL_APP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_appstore_in_rom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_is_appstore_in_rom(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf = 0;
    S32 buf_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_vre_get_vm_tag(app_path, INFO_APP_ID, &buf, &buf_size) || buf_size == 4)
    {
        if ((buf >= 0x00010000) && (buf <= 0x00010100))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_runing_app_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 *  icon_src        [IN]        
 *  des_buf         [OUT]       
 *  name_len        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_get_runing_app_name(U16 *file_path, U8 *icon_src, void **des_buf, U32 *name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL gettag_ret, ret = MMI_TRUE;
    S32 result;
    S32 size;
    S8 *temp_buf;
    U8 *lang = NULL;
    MMI_AM_LANGUAGE_TYPE language = MMI_AM_CHS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the name buffer has been allocated */
    if (*des_buf != NULL)
    {
        return MMI_TRUE;
    }

    lang = Get_Current_Lang_CountryCode();
    if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
    {
        language = MMI_AM_ENG;
    }
    else if (strcmp((PS8) lang, "zh-CN") == 0)
    {
        language = MMI_AM_CHS;
    }
    else if (strcmp((PS8) lang, "zh-TW") == 0)
    {
        language = MMI_AM_CHT;
    }

    /* get name buffer size */
    gettag_ret = mmi_am_vre_get_vm_tag_by_lang(file_path, INFO_NAME, NULL, &size, language);
    if (!gettag_ret)
    {
        gettag_ret = mmi_am_vre_get_vm_tag(file_path, INFO_NAME, NULL, &size);
    }

    if (gettag_ret)
    {
        *des_buf = mmi_am_calloc((size + 1) << 1);
        if (!(*des_buf))
        {
            return MMI_FALSE;
        }

        temp_buf = mmi_am_calloc(size + 1);
        if (!temp_buf)
        {
            mmi_am_free(*des_buf);
            return MMI_FALSE;
        }

        /* get name */
        gettag_ret = mmi_am_vre_get_vm_tag_by_lang(file_path, INFO_NAME, temp_buf, &size, language);
        if (!gettag_ret)
        {
            gettag_ret = mmi_am_vre_get_vm_tag(file_path, INFO_NAME, temp_buf, &size);
            language = MMI_AM_CHS;
        }

        if (!gettag_ret)
        {
            ret = MMI_FALSE;
        }
        strcat((PS8) temp_buf, "\0");

        /* convert char-set */
        if (language == MMI_AM_CHT)
        {
            result = mmi_chset_convert(
                        MMI_CHSET_BIG5,
                        MMI_CHSET_UCS2,
                            (S8*) temp_buf,
                            (S8*) * des_buf,
                            (size + 1) << 1);
        }
        else
        {
            result = mmi_chset_convert(
                        MMI_CHSET_GB2312,
                        MMI_CHSET_UCS2,
                        (S8*) temp_buf,
                        (S8*) * des_buf,
                        (size + 1) << 1);
        }
        if (result <= 0)
        {
            ret = MMI_FALSE;
        }

        mmi_wcscat((PU16) * des_buf, L"\0");
        *name_len = (U32) size;

        mmi_am_free(temp_buf);
     }
     else
     {
        ret = MMI_FALSE;
     }

     return ret;
}
#endif /* __VRE30_AM__ */ 

