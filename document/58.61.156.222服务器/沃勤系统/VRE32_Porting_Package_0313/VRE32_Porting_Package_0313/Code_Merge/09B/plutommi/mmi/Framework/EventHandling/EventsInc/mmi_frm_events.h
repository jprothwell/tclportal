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
 * mmi_frm_events.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Events.
 *
 * Author:
 * -------
 *  Xiaodong Wang
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * Feb 5 2010 mtk02739
 * [MAUI_02144917] [SMS] CSK don't show
 * 
 *
 * Jan 14 2010 mtk80499
 * [MAUI_02130853] [FRM] Framework DOM SAP
 * 
 *
 * Apr 3 2009 mtk80019
 * [MAUI_01410404] [Slide show]The RSK will always stay in press state if click it after "Invalid forma
 * Remove extern g_has_switch_screen
 *
 * Apr 1 2009 mtk01184
 * [MAUI_01659017] [Global Resource] Add global image for CSK icon
 * Revise framework header files
 *
 * Mar 31 2009 mtk01184
 * [MAUI_01645545] Add new API mmi_frm_check_wait_to_run to query MMI task status
 * Revise Plutommi header files
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MMI_FRM_EVENTS_H
#define MMI_FRM_EVENTS_H

typedef struct
{
    mmi_event_struct *evt_p;
    mmi_proc_func proc;
} mmi_post_event_proc_struct;


typedef struct
{
    mmi_event_struct *evt_p;
    mmi_proc_func proc;
    mmi_post_event_result_proc_func result_cb;
    void *result_cb_user_data;
} mmi_post_event_proc_ex_struct;




/***************************************************************************** 
* Define
*****************************************************************************/
/*----------------------------------------------------------------*
  Interrupt Mechanism
 *----------------------------------------------------------------*/
#if !defined(LOW_COST_SUPPORT)
    #define MAX_INTERRUPT_EVENT	30       /* max number of interrupt events (protocol, timer & hardware) */
#else
    #define MAX_INTERRUPT_EVENT	20       /* max number of interrupt events (protocol, timer & hardware) */
#endif

#define MMI_INT_EVENT_GROUP_MASK (0x8000)



/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* Async PRT event information struct */
typedef struct _PseventInfo
{
    PsFuncPtr entryFuncPtr;
    U16 eventID;    /* for timer & hardware events      */
    U8 flagMulti;   /* is multi-handler or not */
/* vogins Start */
#ifdef __VRE_V30__
	U8 isMismatch;
#endif
/* vogins End */
} PseventInfo;

typedef struct _PIntseventInfo
{
    U16 eventID;    /* for timer & hardware events      */
    PsIntFuncPtr entryIntFuncPtr;
    PsIntFuncPtr postIntFuncPtr;
} PsInteventInfo;

/* enum event table */
typedef enum {
    EVENT_TABLE_MASTER,     /* main table */
#ifdef __MMI_DUAL_SIM__
    EVENT_TABLE_SLAVE,      /* table for dual sim */
#endif
    EVENT_TABLE_END
} mmi_frm_event_table_enum;

/* static info of event table (may declared as const) */
typedef struct {
    PseventInfo *table;     /* pointer to event table */
    U16 num_of_events;      /* number of events (table size) */
} mmi_frm_event_static_info_struct;

/* runtime info of event table */
typedef struct {
    U16 max_events;     /* max. count of events used*/
    U16 used_events;    /* count of currently used events */
} mmi_frm_event_runtime_info_struct;


typedef struct
{
    U32 key;
    U32 data;
}mmi_frm_pair_data_struct;

typedef struct
{
    U32     menu_id;
    FuncPtr hilite_hdlr;
}mmi_frm_hilite_hdlr_struct;

typedef struct
{
    U32          menu_id;
    FuncPtrShort hint_hdlr;
}mmi_frm_hint_hdlr_struct;

typedef struct
{
#if 0
    FuncPtr         curr_tab_exit_func_ptr;
    FuncPtr         curr_tab_entry_func_ptr;
    U16             curr_tab_scrn_id;   
    MMI_BOOL        is_in_exit_handler_proc;
    U16             currMaxHiliteInfo;               /* currently max hilite info */
    U16             currParentID;                    /* current parent item id */
    U16             currHiliteID;
    U16             currTopScrnID;   /* curr exit func ptr with scrn id */
    MMI_BOOL        mmu_frm_execute_scrn_exit_handler;
#endif

    U16             currExitScrnID;
    exit_func_ptr   curr_exit_handler; 
    entry_func_ptr  curr_entry_handler;
    void            *curr_exit_scrn_arg_p;
    void            *curr_entry_scrn_arg_p;
}history_ctxt_struct;

/*----------------------------------------------------------------*
  Interrupt Mechanism
 *----------------------------------------------------------------*/
/*
 * If we want to add the new interrupt event group,
 * define the new interrupt event group id here.
 */
typedef enum
{
    MMI_SMS_INT_EVENT_GROUP = MMI_INT_EVENT_GROUP_MASK,
    MMI_CARD_PLUG_EVENT_GROUP
} interrtupGroupEventId;



/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/* Event handler global data */
extern U16 maxProtocolEvent;
extern U16 usedProtocolEvent;

#ifdef __MMI_DUAL_SIM__
    extern U16 maxSlaveProtocolEvent;
    extern U16 usedSlaveProtocolEvent;
#endif /* __MMI_DUAL_SIM__ */


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void InitEvents(void);                           /* initilize events func */
extern void ExecuteCurrExitHandler_Ext(void);

extern void SetEntryHandler(U16 scrnID, FuncPtr entryFuncPtr);  /* entry function handler */
extern void ClearEntryHandler(void);
extern void ClearAllHiliteHandler(void);

extern void DeInitFramework_KeyAndEventHandler(void);
extern void DeInitFramework_History(void);
extern void DeInitFramework(void);

extern U16 GetExitScrnID_r(void);
extern FuncPtrShort mmi_frm_get_hint_hdlr(U16 menu_id);
extern MMI_BOOL mmi_frm_binary_search(U32 key, mmi_frm_pair_data_struct* search_table, U32 table_size, U32* index);

extern void wap_suppress_popup(kal_bool is_true);
extern void mmi_frm_notification_service_init(void);

extern MMI_BOOL mmi_check_in_scrn_exit_func_procedure(void);

extern void mmi_frm_tab_save_history(U16 scrnID, FuncPtr entryFuncPtr);

/* event handler */
extern void mmi_proc_inject_string(void * in);


#endif /* MMI_FRM_EVENTS_H */ 



