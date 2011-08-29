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

/*******************************************************************************
 * Filename:
 * ---------
 *  CommonScreensenum.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : CommonScreensenum.h

   PURPOSE     : This file defines enum value for global resources used in Common Screens.

   REMARKS     : 

   AUTHOR      : MTK00866

   DATE     : 05-23-2005

**************************************************************/
#ifndef __COMMONSCREENS_RES_H__
#define __COMMONSCREENS_RES_H__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalDefs.h"

#define MMI_MAX_EDITOR_COMMON_SCREEN_NUM (5)
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
    typedef enum
    {
        SCR_INPUT_METHOD_LIST = COMMON_SCREENS_BASE,
        SCR_INPUT_METHOD_LIST_END =  SCR_INPUT_METHOD_LIST + 5 - 1,
        SCR_SYMBOL_PICKER_SCREEN,
        SCR_SYMBOL_PICKER_SCREEN_END = SCR_SYMBOL_PICKER_SCREEN + 5 - 1,
        SCR_INPUT_MODE_LIST,
		SCR_INPUT_MODE_LIST_END = SCR_INPUT_MODE_LIST + 5 - 1,
		SCR_EDIT_NEW_WORD,
        SCR_EDIT_NEW_WORD_END = SCR_EDIT_NEW_WORD + 5 - 1,
        SCR_ID_CLIPBOARD_EDIT_OPTION,
        SCR_ID_CLIPBOARD_EDIT_OPTION_END = SCR_ID_CLIPBOARD_EDIT_OPTION + 5 - 1,
		SCR_CONFIG_SMART_INPUT_METHOD,
        SCR_CONFIG_SMART_INPUT_METHOD_END = SCR_CONFIG_SMART_INPUT_METHOD + 5 - 1,
        SCR_INPUT_METHOD_AND_DONE,
		SCR_INPUT_METHOD_AND_DONE_END = SCR_INPUT_METHOD_AND_DONE + 5 - 1,
        SCR_POPUP_SCREEN,
        SCR_CONFIRM_SCREEN,
        SCR_CONFIRM_WINDOW_SCREEN,
        SCR_QUICK_SEARCH_INPUT_METHOD_LIST,
        SCR_IN_LINE_MULTI_LINE_INPUT_METHOD_AND_DONE,
        SCR_ID_ASM_MEM_FULL,
        SCR_AP_REQUIRED_INPUT_METHOD_LIST,
        SCR_APPMEM_STOP_PROMPT, 
        SCR_APPMEM_STOP_PROGRESSING,
        SCR_FRM_UNIT_TEST,
        SCR_ID_CASCADING_MENU_BASE,
        SCR_ID_CASCADING_MENU_CLIPBOARD,
        SCR_ID_CASCADING_MENU_END = SCR_ID_CASCADING_MENU_BASE + 7, /* reserve 8 screen IDs for cascading menu */
    /* Vogins Start */
    #if defined(__VRE30_AM__)
        SCR_MEDMEM_STOP_PROMPT, 
    #endif
    /* Vogins End */
        SCR_COMMON_SCREENS_END
    } SCREENID_LIST_COMMON_SCREENS;

    typedef enum
    {
        /* STR_INPUT_METHOD_CAPTION=COMMON_SCREENS_BASE,==> replaced by Global String */
        STR_INPUT_METHOD_MENU_INSERT_SYMBOLS = COMMON_SCREENS_BASE,
        STR_INPUT_METHOD_MENU_SELECT_SYMBOL,
        STR_INPUT_METHOD_MENU_SET_T9,
        STR_INPUT_METHOD_MENU_SET_ZI,
        STR_INPUT_METHOD_MENU_SET_CSTAR,
        STR_INPUT_METHOD_MENU_NEW_T9_WORD,
        STR_INPUT_METHOD_MENU_NEW_ZI_WORD,
        STR_INPUT_METHOD_MENU_NEW_CSTAR_WORD,
        STR_ID_APPMEM_ATTR_STOPPING,
        STR_ID_APPMEM_PROMPT_STOP_APP,
        STR_ID_APPMEM_STOP, 
        STR_ID_APPMEM_WAIT,      
        STR_ID_APPMEM_NOTIFY_STARTING_NEW,
        STR_ID_APPMEM_NOTIFY_STOPPED,
        STR_ID_APPMEM_NOTIFY_STOP_FAILED,       
    #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        STR_ID_IME_WRITING_LANGUAGE_123,
        #endif    
        STR_ID_CLIPBOARD_COPY,                /* "Copy", "Clipboard String- Copy" */
        STR_ID_CLIPBOARD_CUT,                 /* "Cut", "Clipboard String- Cut" */
        STR_ID_CLIPBOARD_PASTE,               /* "Paste", "Clipboard String- Paste" */
        STR_ID_CLIPBOARD_COPY_ALL,            /* "Copy all", "Clipboard String- Copy all" */
        STR_ID_CLIPBOARD_CUT_ALL,             /* "Cut all", "Clipboard String- Cut all" */
        STR_ID_CLIPBOARD_MARK_TEXT,           /* "Mark text", "Clipboard String- Mark text" */
        STR_ID_CLIPBOARD_EDIT_OPTION,           /* "Edit option", "Clipboard String- Edit option" */
        STR_ID_CLIPBOARD_COPY_SUCESS,           /* "Copy sucess", "Clipboard String- Copy sucess" */
        STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY,   /* "Text truncated for insufficient memory", "Clipboard String-Text truncated for insufficient memory" */
        STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT, /* "Unsupported content is cut", "Clipboard String-Unsupported content is cut" */
        STR_ID_COMMONSCREEN_STR_END
    } STRINGID_LIST_COMMON_SCREENS;
#ifdef __cplusplus
}
#endif 
#endif /* __COMMONSCREENS_RES_H__ */ 

