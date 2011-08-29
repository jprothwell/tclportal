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
 *  MMI_fw_trc.h
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
 * -------
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
 * removed!
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_FW_TRC_H_
#define _MMI_FW_TRC_H_

/* for generate PS trace definition */
#include "kal_trace.h"


#define MMI_FW_TRC_FUNC           TRACE_FUNC
#define MMI_FW_TRC_STATE          TRACE_STATE
#define MMI_FW_TRC_INFO           TRACE_INFO
#define MMI_FW_TRC_WARNING        TRACE_WARNING
#define MMI_FW_TRC_ERROR          TRACE_ERROR

#define MMI_FW_TRC_G1_FRM         TRACE_GROUP_1
#define MMI_FW_TRC_G2_GUI         TRACE_GROUP_2
#define MMI_FW_TRC_G3_CAT         TRACE_GROUP_3
#define MMI_FW_TRC_G4_EDITOR      TRACE_GROUP_4
#define MMI_FW_TRC_G5_IME         TRACE_GROUP_5
#define MMI_FW_TRC_G6_FRM_DETAIL  TRACE_GROUP_6
/* MTI IRE TRACE UPDATION START */
#define MMI_FW_TRC_G7_IRE	      TRACE_GROUP_7
/* MTI IRE TRACE UPDATION END */
#define MMI_FW_TRC_G8_RESERVED    TRACE_GROUP_8
#define MMI_FW_TRC_G9_FE    TRACE_GROUP_9
#define MMI_FW_TRC_G10_GDI        TRACE_GROUP_10
#define MAX_FW_TRACE_LOG_TYPE     (MMI_FW_TRC_G10_GDI+1)



/* For MOD_MMI_FW */
BEGIN_TRACE_MAP(MOD_MMI_FW)

    /*****************************************************************************************************************
     * MMI Framework events trace
     *****************************************************************************************************************/
    //Event.c, Init related
    TRC_MSG(TRC_MMI_FRM_EVENT_INIT_BEGIN, "[MMI_FRM][Events] InitEvents <Begin> <Initialize events module>")
    TRC_MSG(TRC_MMI_FRM_EVENT_INIT_END, "[MMI_FRM][Events] InitEvents <End>")
    TRC_MSG(TRC_MMI_FRM_EVENT_DEINIT_KEY_EVENT_BEGIN,"[MMI_FRM][Key] DeInitFramework_KeyAndEventHandler <Begin> <DeInit key and event handler>")
    TRC_MSG(TRC_MMI_FRM_EVENT_DEINIT_KEY_EVENT_END,"[MMI_FRM][Key] DeInitFramework_KeyAndEventHandler <End>")
    TRC_MSG(TRC_MMI_FRM_EVENT_DEINIT_HISTORY_BEGIN,"[MMI_FRM][History] DeInitFramework_History <Begin> <DeInit framework history module>")
    TRC_MSG(TRC_MMI_FRM_EVENT_DEINIT_HISTORY_END,"[MMI_FRM][History] DeInitFramework_History <End>")
    TRC_MSG(TRC_MMI_FRM_EVENT_DEINIT_BEGIN,"[MMI_FRM] DeInitFramework <Begin> <DeInit framework key&event&history>")
    TRC_MSG(TRC_MMI_FRM_EVENT_DEINIT_END,"[MMI_FRM] DeInitFramework <End>")
    //Event.c, Exec Protocol related
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURKEY_HDLR,"[Key] [Keypad Lock] ExecuteCurrKeyHandler: Timer %d start")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURKEY_KEYCODE_HDLR,"[Key] ExecuteCurrKeyHandler: <keyHandler 0x%x, keyCode %Mmmi_keypads_enum, keyType %Mmmi_key_types_enum>   ")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURPTO_INTP_HDLR, "[MMI_FRM][Protocol] mmi_frm_execute_current_protocol_handler <Execute interrupt event handler <hdlr = 0x%x, id = %Mmsg_type>")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURPTO_HDLR, "[MMI_FRM][Protocol] mmi_frm_execute_current_protocol_handler <Execute protocol event handler> <event_type = %Mmmi_frm_event_table_enum, (MASTER:0, SLAVE:1), id = %Mmsg_type, hdlr = 0x%x, isMulti = %d)>")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURPTO_NO_HDLR, "[MMI_FRM][Protocol] mmi_frm_execute_current_protocol_handler <Message is not process> <event_type = %Mmmi_frm_event_table_enum, (MASTER:0, SLAVE:1), id = %Mmsg_type, hdlr = 0x%x)>")
    //Event.c, Hilite related
    TRC_MSG(TRC_MMI_FRM_EVENT_EXECURHILIHTE_HDLR, "[MMI_FRM][Menu] ExecuteCurrHiliteHandler <Execute hilited menu item's handler> <hiliteid =%d>")
    TRC_MSG(TRC_MMI_FRM_EVENT_EXECURHILIHTE_HDLR_ERROR, "[MMI_FRM][Menu] ExecuteCurrHiliteHandler <Error> <The parent is zero>")
    TRC_MSG(TRC_MMI_FRM_EVENT_SETCURHILIHTE_HDLR, "[MMI_FRM][Menu] SetHiliteHandler <Set hilite menu item handler> <id = %MGLOBALMENUITEMSID, funcPtr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_EVENT_CLRCURHILIHTE_HDLR, "[MMI_FRM][Menu] ClearHiliteHandler <Clear hilite menu item handler> <id = %MGLOBALMENUITEMSID>")
    //Event.c, Hint related
    TRC_MSG(TRC_MMI_FRM_EVENT_SETHINT_HDLR, "[MMI_FRM][Menu] SetHintHandler <Set hint item handler> <id = %MGLOBALMENUITEMSID, funcPtr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_EVENT_CLRHINT_HDLR, "[MMI_FRM][Menu] ClearHintHandler <Clear hint item handler> <id = %MGLOBALMENUITEMSID>")
    //Menu list related
    TRC_MSG(TRC_MMI_FRM_EVENT_SETPARENT_HDLR, "[MMI_FRM][Menu] SetParentHandler <Set current parent item id> <id = %MGLOBALMENUITEMSID>")
    //Event.c, Key related
    TRC_MSG(MMI_FRM_INFO_EVENT_SETKEY_HDLR, "[MMI_FRM][Key] SetKeyHandler: <register key handler; keyCode %Mmmi_keypads_enum, keyType %Mmmi_key_types_enum, funcPtr 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_SETGROUPKEY_HDLR, "[MMI_FRM][Key] SetGroupKeyHandler: < Group size %d, keyType %Mmmi_key_types_enum, funcPtr 0x%x >")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRKEY_HDLR, "[MMI_FRM][Key] ClearKeyHandler: <clear key handler <keyCode %Mmmi_keypads_enum, keyType %Mmmi_key_types_enum>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRALLKEY_HDLR, "[MMI_FRM][Key] ClearAllKeyHandler: <clear all key handlers>")
    //Event.c, Protocol related
    TRC_MSG(TRC_MMI_FRM_EVENT_SETPTO_HDLR, "[MMI_FRM][Protocol] mmi_frm_set_protocol_event_handler <Set protocol event handler> <event = %Mmsg_type, handler = 0x%x, isMulti = %d)>")
    TRC_MSG(TRC_MMI_FRM_EVENT_SETPTO_HDLR_DETAIL, "[MMI_FRM][Protocol] mmi_frm_set_protocol_event_handler <table_type = %Mmmi_frm_event_table_enum, used_events = %d, max_events = %d>")
    TRC_MSG(TRC_MMI_FRM_EVENT_CLRPTO_HDLR, "[MMI_FRM][Protocol] mmi_frm_clear_protocol_event_handler <Clear protocol event handler> <table_type = %Mmmi_frm_event_table_enum, event = %Mmsg_type, handler = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_EVENT_CLRALLPTO_HDLR, "[MMI_FRM][Protocol] mmi_frm_clear_all_protocol_event_handler <clear all handler> <table_type = %Mmmi_frm_event_table_enum>")
    //Event.c, Entry funtcion related
    TRC_MSG(TRC_MMI_FRM_EVENT_ENTRYNEWSCR_BEGIN, "[MMI_FRM][Screen] mmi_frm_entry_new_screen(EntryNewScreen) <Begin> <Enter the new screen ID=%Mmmi_screen_id_cgen_enum, ExitFuncPtr = 0x%x, EntryFuncPtr = 0x%x, scrn_type = %Mmmi_frm_scrn_type_enum>")
    TRC_MSG(TRC_MMI_FRM_EVENT_ENTRYNEWSCR_EXIT_HDLR, "[MMI_FRM][Screen] mmi_frm_entry_new_screen <Execute exit handler>")
    TRC_MSG(TRC_MMI_FRM_EVENT_ENTRYNEWSCR_END, "[MMI_FRM][Screen] mmi_frm_entry_new_screen(EntryNewScreen) <End>")
    TRC_MSG(TRC_MMI_FRM_EVENT_CLEARINPUTEVENTHDLR, "[MMI_FRM][Screen] ClearInputEventHandler <type=%Mmmi_frm_device_type_emun>")
    TRC_MSG(TRC_MMI_FRM_EVENT_ENTRYNEWSCR_EXT_BEGIN, "[MMI_FRM][Screen] mmi_frm_entry_new_screen_ext <Begin> <Enter the new screen ID=%Mmmi_screen_id_cgen_enum, ExitFuncPtr = 0x%x, EntryFuncPtr = 0x%x, flag = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_EVENT_ENTRYNEWSCR_EXT_END, "[MMI_FRM][Screen] mmi_frm_entry_new_screen_ext <End>")
    TRC_MSG(MMI_FRM_INFO_EVENT_SETENTRY_HDLR, "[MMI_FRM][Screen] SetEntryHandler <Set current screen ID=%Mmmi_screen_id_cgen_enum, entry handler FuncPtr = 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_SETEXIT_HDLR, "[MMI_FRM][Screen] SetExitHandler <Sets current screen ID=%Mmmi_screen_id_cgen_enum, exit handler FuncPtr = 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRENTRY_HDLR, "[MMI_FRM][Screen] ClearEntryHandler <Clear current screen entry handler>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLREXIT_HDLR, "[MMI_FRM][Screen] ClearExitHandler <Clear current screen exit handler>")
    //Event.c, Generic function related
    TRC_MSG(TRC_MMI_FRM_EVENT_SETGEN_EXIT_HDLR, "[MMI_FRM][Screen] SetGenericExitHandler <Sets generic screen handler> <ID = %Mmmi_screen_id_cgen_enum, exit_func_p = 0x%x entry_func_p = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_EVENT_GENEXITSCRN_ADD_HISTORY, "[MMI_FRM][Screen] mmi_frm_generic_exit_scrn <Add history> <scrn_id = %Mmmi_screen_id_cgen_enum, entry_func_ptr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_EVENT_GETGEN_EXIT_HDLR, "[MMI_FRM][Screen] GetExitScrnID <Get the exit screen> <ID = %Mmmi_screen_id_cgen_enum>>")
    //Event.c, Interrupt funtcion related
    TRC_MSG(TRC_MMI_FRM_EVENT_SETINTP_HDLR, "[MMI_FRM][Event handler] SetInterruptEventHandler: <Set interrupt event handler %Mmsg_type>")
    TRC_MSG(TRC_MMI_FRM_EVENT_SETGRPINTP_HDLR, "[MMI_FRM][Event handler] SetGroupInterruptEventHandler: <Set group interruptEvent handler %Mmsg_type>")
    TRC_MSG(TRC_MMI_FRM_EVENT_CLRINTP_HDLR, "[MMI_FRM][Event handler] ClearInterruptEventHandler: <Clears interrupt event handler %Mmsg_type>")
    TRC_MSG(TRC_MMI_FRM_EVENT_CLRALLINTP_HDLR, "[MMI_FRM][Event handler] ClearAllInterruptEventHandler: <Clears all the interrupt event handler>")
    //event_handler.c New interrup function related
    TRC_MSG(TRC_MMI_FRM_EVENT_BLOCK_INT_HDLR, "[MMI_FRM][Event handler] mmi_frm_block_interrupt_event_handler: <block interrupt event %d>")
    TRC_MSG(TRC_MMI_FRM_EVENT_BLOCK_GEN_INT_HDLR, "[MMI_FRM][Event handler] mmi_frm_block_general_interrupt_event: <block interrupt event %d>")
    //event_handler.c, Notification Service related
    TRC_MSG(MMI_FRM_INFO_EVENT_SET_SCENARIO, "[MMI_FRM][Event NS] set scenario %Mmmi_frm_scenario_enum [1]")
    TRC_MSG(MMI_FRM_INFO_EVENT_RESET_SCENARIO, "[MMI_FRM][Event NS] reset scenario %Mmmi_frm_scenario_enum [0]")
    TRC_MSG(MMI_FRM_INFO_EVENT_UPDATE_CONCURRENT_SCENARIO, "[MMI_FRM][Event NS] update scenario %Mmmi_frm_scenario_enum [%d]")
    TRC_MSG(MMI_FRM_INFO_EVENT_ALL_SCENARIO_STATUS, "[MMI_FRM][Event NS] scenario status [%s]")
    TRC_MSG(MMI_FRM_INFO_EVENT_QUERY_BEHAVIOR, "[MMI_FRM][Event NS] scenario[%Mmmi_frm_scenario_enum] int[%Mmmi_frm_int_enum] behavior[%Mmmi_frm_behavior_enum,%Mmmi_frm_behavior_enum,%Mmmi_frm_behavior_enum,%Mmmi_frm_behavior_enum,%Mmmi_frm_behavior_enum]")
    TRC_MSG(MMI_FRM_INFO_EVENT_REGISTER_DEFER, "[MMI_FRM][Event NS] defer added: res_id[%d] cb[0x%X] int[%Mmmi_frm_int_enum] arg[%d]")
    TRC_MSG(MMI_FRM_INFO_EVENT_DEREGISTER_DEFER, "[MMI_FRM][Event NS] defer removed: res_id[%d]")
    TRC_MSG(MMI_FRM_INFO_EVENT_DEFER_INVOKED, "[MMI_FRM][Event NS] defer invoked: res_id[%d] cb[0x%X] int[%Mmmi_frm_int_enum] arg[%d]")
    //event_handler.c
    TRC_MSG(MMI_EVENT_TRC_EXE_CURR_PROTOCOL_HDLR, "[MMI_FRM][EVENT] ExecuteCurrProtocolHandler count = %d")
    TRC_MSG(MMI_EVENT_TRC_EVENT_PROFILING_COUNT, "[MMI_FRM][EVENT] ExecuteCurrProtocolHandler accu_count = %d")
    TRC_MSG(MMI_EVENT_TRC_EVENT_PROFILING_TICKS, "[MMI_FRM][EVENT] ExecuteCurrProtocolHandler accu_ticks = %d")
    TRC_MSG(MMI_EVENT_TRC_EVENT_PROFILING_MAX, "[MMI_FRM][EVENT] ExecuteCurrProtocolHandler maxProtocolEvent = %d")
    TRC_MSG(MMI_EVENT_TRC_SET_PROTOCOL_EVENT_HDLR_MAX_1, "[MMI_FRM][EVENT] SetProtocolEventHandler old maxUsedInHistory = %d")
    TRC_MSG(MMI_EVENT_TRC_SET_PROTOCOL_EVENT_HDLR_MAX_2, "[MMI_FRM][EVENT] SetProtocolEventHandler maxUsedInHistory = %d")

    /*****************************************************************************************************************
     * MMI Framework history trace
     *****************************************************************************************************************/

    /* Group 1 trace - MMI_FW_TRC_G1_FRM */
    TRC_MSG(TRC_MMI_FRM_HIST_ADD_HISTORY, "[MMI_FRM][History] mmi_frm_add_history <scrn_id = %Mmmi_screen_id_cgen_enum, add result = %Mkal_bool>")
    TRC_MSG(TRC_MMI_FRM_HIST_EXE_DESTROY_HDLR, "[MMI_FRM][History] mmi_frm_exec_scrn_destroy_hdlr <execute destroy handler> <scrn_id=%Mmmi_screen_id_cgen_enum,func_ptr=0x%xarg_p=0x%x>")
    TRC_MSG(MMI_FRM_INFO_HIST_ADD_HISTREFMEMREC_HDLR, "[MMI_FRM][History] AddHistoryReferenceMemoryRecord <exe(bool) = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_ADD_HISTREF_HDLR, "[MMI_FRM][History] AddHistoryReference <exe(bool) = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_ADD_NHIST_HDLR, "[MMI_FRM][History] AddNHistory <size =%d, exe(bool) =%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GO_BACK_HIST_HDLR, "[MMI_FRM][History] GoBackHistory")
    TRC_MSG(TRC_MMI_FRM_HIST_GO_BACK_TO_HIST_HDLR, "[MMI_FRM][History] GoBackToHistory <screen ID = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GO_BACK_NHIST_HDLR, "[MMI_FRM][History] GoBacknHistory <nHistory = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GOBACKTOHIST_BEGIN, "[MMI_FRM][History] mmi_frm_go_back_to_history_int <Begin> <goto_scrnid = %Mmmi_screen_id_cgen_enum, top_scrnid = %Mmmi_screen_id_cgen_enum, exit_scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_EXETOPDELET_HDLR, "[MMI_FRM][History] Invoke delete callback hdlr of current active scrn<del_cb = 0x%x, could delete = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GOBACKTOHIST_ENTRY, "[MMI_FRM][History] Go back to screen entry <screen ID = %Mmmi_screen_id_cgen_enum, entry = 0x%x, arg = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_HIST_GOBACKTOHIST_REMOVE, "[MMI_FRM][History] Remove gobacking history node <screen ID=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GOBACKTOHIST_END, "[MMI_FRM][History] mmi_frm_go_back_to_history_int <End>")
    TRC_MSG(TRC_MMI_FRM_HIST_REMOVE_HIST_NODE, "[MMI_FRM][History] Remove history node <status=%M, remove_index=%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_EXE_SMALL_SCREEN_BEGIN, "[MMI_FRM][History][Small Screen] <Begin> <target small-scrn idx=%d, full-scrn idx=%d> ")
    TRC_MSG(TRC_MMI_FRM_HIST_EXE_SMALL_SCREEN_BKGD, "[MMI_FRM][History][Small Screen] <background scrn><ScrnId = %Mmmi_screen_id_cgen_enum, entryFuncPtr=0x%x, arg=0x%x>")
    TRC_MSG(TRC_MMI_FRM_HIST_EXE_SMALL_SCREEN_END, "[MMI_FRM][History] [Small Screen] <End> then active screen <ScrnId = %Mmmi_screen_id_cgen_enum, entryFuncPtr = %x>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_HISTORY_HDLR, "[MMI_FRM][History] DeleteHistoryInt <start_scrn_id=%Mmmi_screen_id_cgen_enum, if include start_scrn_id=%d, expected delete count=%d, end_scrn_id=%Mmmi_screen_id_cgen_enum, if include end_scrn_id=%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_HISTORY_INDEX_HDLR, "[MMI_FRM][History] DeleteHistory <currHistoryIndex=%d, start_hist_idx=%d, end_hist_idx=%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_HISTORY_INDEX, "[MMI_FRM][History] DeleteHistory <Delete history node> <scrn_id=%Mmmi_screen_id_cgen_enum, del_hist_idx=%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_HISTORY_STOP_DELETING, "[MMI_FRM][History] DeleteHistory <Forbid deleting history node> <scrn_id=%Mmmi_screen_id_cgen_enum, del_hist_idx=%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_SCR_IF_PRESENT_RETURN, "[MMI_FRM][History] DeleteScreenIfPresent <Fail to delete in small screen process> <ScrId = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_SCR_IF_PRESENT_HDLR, "[MMI_FRM][History] DeleteScreenIfPresent <Succeed to delete> <ScrId = %Mmmi_screen_id_cgen_enum, delete_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_SCR_IF_PRESENT_HDLR_ERROR, "[MMI_FRM][History] DeleteScreenIfPresent <Fail to delete since can't find the ScrId> <ScrId = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_DEL_SCRS_HDLR, "[MMI_FRM][History] DeleteScreens: <startScrId=%Mmmi_screen_id_cgen_enum, EndScrId=%Mmmi_screen_id_cgen_enum, del_cnt = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_DEL_BEYOND_SCR_TILL_SCR_HDLR, "[MMI_FRM][History] DeleteBeyondScrTillScr: <beyondScrnid=%Mmmi_screen_id_cgen_enum, tillScrnid=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_DEL_BETWEEN_SCR_HDLR, "[MMI_FRM][History] DeleteBetweenScreen: <StartScrId=%Mmmi_screen_id_cgen_enum, EndScrId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_DEL_SCR_FROM_TO_N_NODE_HDLR, "[MMI_FRM][History] DeleteScreenFromToNnodes: <ScrId=%Mmmi_screen_id_cgen_enum, DeleteCount = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_DEL_FROM_SCR_UPTO_SCR_HDLR, "[MMI_FRM][History] DeleteFromScrUptoScr: <FromScrId=%Mmmi_screen_id_cgen_enum, UptoScrId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_INSERT_HIST_BEFORE_SCREEN_HDLR, "[MMI_FRM][History] InsertHistoryBeforeThisScrnReference: <ScrId=%Mmmi_screen_id_cgen_enum>")   
    TRC_MSG(TRC_MMI_FRM_HIST_INSERT_HIST_AFTER_SCREEN_HDLR, "[MMI_FRM][History] InsertHistoryAfterThisScrnReference: <ScrId=%Mmmi_screen_id_cgen_enum>")   
    TRC_MSG(MMI_FRM_INFO_HIST_GET_CUR_INPUT_BUF_HDLR, "[MMI_FRM][History] GetCurrInputBuffer: <ScrId = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_CUR_NINPUT_BUF_HDLR, "[MMI_FRM][History] GetCurrNInputBuffer: <ScrId = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_CUR_GUI_BUF_HDLR, "[MMI_FRM][History] GetCurrGuiBuffer: <ScrId = %Mmmi_screen_id_cgen_enum, cur History idx = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_DUMP_HDLR, "[MMI_FRM][History] HistoryDump <Dump history stack info> <index = %d, scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_REPLACE_HDLR, "[MMI_FRM][History] HistoryReplace: <History Replace><dst_id = %Mmmi_screen_id_cgen_enum, scr_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_EXEC_CURR_HIST_HDLR, "[MMI_FRM][History] ExecutecurrHisIndEntryFunc")
    TRC_MSG(MMI_FRM_INFO_DEL_NHIST_HDLR, "[MMI_FRM][History] DeleteNHistory: <DeleteCount = %d>")
    TRC_MSG(MMI_FRM_INFO_DEL_UPTO_SCRID_HDLR, "[MMI_FRM][History] DeleteUptoScrID: <scrnid = %Mmmi_screen_id_cgen_enum, cur History idx=%d>")
    TRC_MSG(MMI_FRM_INFO_GO_BEYOND_MARKER_SCR_HDLR, "[MMI_FRM][History] GoBeyondMarkerScr: <scrnid = %Mmmi_screen_id_cgen_enum, cur History idx = %d>")
    TRC_MSG(MMI_FRM_INFO_DEL_NSCRID_HDLR, "[MMI_FRM][History] DeleteNScrId: <scrnid = %Mmmi_screen_id_cgen_enum, cur History idx = %d>")
    TRC_MSG(MMI_FRM_INFO_IS_SCR_PRESENT_HDLR, "[MMI_FRM][History] IsScreenPresent <scrnid = %Mmmi_screen_id_cgen_enum, present = %Mkal_bool>")
    TRC_MSG(MMI_FRM_INFO_GET_PREVIOUS_SCR_IDOF_HDLR, "[MMI_FRM][History] GetPreviousScrnIdOf <scrnid = %Mmmi_screen_id_cgen_enum, previousScrnId = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_GET_PREVIOUS_SCR_IDOF_2_HDLR, "[MMI_FRM][History] GetPreviousScrnIdOf <NO previousScrnId> <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_IS_CUR_MARKER_SCR_HDLR, "[MMI_FRM][History] IsCurrMarkerScreen: <scrnid = %Mmmi_screen_id_cgen_enum, historyData[currHistoryIndex].scrnID = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_EXEC_ROOT_HIST_HDLR, "[MMI_FRM][History] ExecuteRootMainHistoryScreen: <currHistoryIndex=%d, Status=%d>")
    TRC_MSG(MMI_FRM_INFO_SET_SCREEN_ID_CB_HDLR, "[MMI_FRM][History] SetDelScrnIDCallbackHandler: <ScrnID=%Mmmi_screen_id_cgen_enum, funcPtr=%x>")
    TRC_MSG(MMI_FRM_INFO_CLR_SCREEN_ID_CB_HDLR, "[MMI_FRM][History] ClearDelScrnIDCallbackHandler: <ScrnID=%Mmmi_screen_id_cgen_enum, funcPtr=%x>")
    TRC_MSG(MMI_FRM_INFO_SRCH_DEL_SCRN_CB_HDLR, "[MMI_FRM][History] SearchDelScrnIDCallbackHandler: <ScrnID=%Mmmi_screen_id_cgen_enum is found in history_idx=%d>")
    TRC_MSG(MMI_FRM_INFO_DEL_HISTORY_END, "[MMI_FRM][History] DeleteHistory end <delCount %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_INSERT_HIST_BY_IDX, "[MMI_FRM][History] insert_history_by_idx <insert_idx = %d, scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_INSERT_SCRN, "[MMI_FRM][History] mmi_frm_insert_screen <insert_idx = %d, scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_INSERT_INSERT_SCRN_ERROR, "[MMI_FRM][History] mmi_frm_insert_screen <target_scrn = %Mmmi_screen_id_cgen_enum, insert_scrn_id = %Mmmi_screen_id_cgen_enum, insert_type = %Mmmi_frm_insert_scrn_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_INIT_SCRN_STRUCT, "[MMI_FRM][History] mmi_frm_init_screen_struct <scrn = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_REPLACE_SCREEN, "[MMI_FRM][History] mmi_frm_replace_screen <out_scrn_id = %Mmmi_screen_id_cgen_enum, replace_scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_REPLACE_SCREEN_ERROR, "[MMI_FRM][History] mmi_frm_replace_screen <Fail to find out_scrn_id> <out_scrn_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_REPLACE, "[MMI_FRM][History] mmi_frm_history_replace <out_scrn_id = %Mmmi_screen_id_cgen_enum, in_scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_REPLACE_ERROR, "[MMI_FRM][History] mmi_frm_history_replace <Fail to find out_scrn_id> <out_scrn_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_EXECUTEROOTMAINHISTSCRN, "[MMI_FRM][History] ExecuteRootMainHistoryScreen <Enter the root history node> <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_DESTROY_SCRN_CB, "[MMI_FRM][History] mmi_frm_set_destroy_scrn_callback <scrn_id = %Mmmi_screen_id_cgen_enum, hdlr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_HIST_CLEAR_DESTROY_SCRN_CB, "[MMI_FRM][History] mmi_frm_clear_destroy_scrn_callback <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_SRCH_DEL_SCRN_CB_HDLR, "[MMI_FRM][History] mmi_frm_search_destroy_scrn_callback <scrn_id = %Mmmi_screen_id_cgen_enum, scrn_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_HIST, "[MMI_FRM][History] mmi_frm_add_tab_history <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_N_HIST, "[MMI_FRM][History] mmi_frm_add_tab_n_history <scrn_id = %Mmmi_screen_id_cgen_enum, size = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_CUR_SEL_PAGE, "[MMI_FRM][History] mmi_frm_set_cur_sel_page <index = %d, tab_page_count = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_FIRST_SEL_PAGE, "[MMI_FRM][History] mmi_frm_set_first_sel_page <index = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_SEL_PAGE, "[MMI_FRM][History] mmi_frm_get_cur_sel_page <cur_sel_index = %d>")

    /* Group 6 trace - MMI_FW_TRC_G6_FRM_DETAIL */
    TRC_MSG(TRC_MMI_FRM_HIST_INIT_HIST_BEGIN, "[MMI_FRM][History] InitHistory <Begin>")
    TRC_MSG(TRC_MMI_FRM_HIST_INIT_HIST_END, "[MMI_FRM][History] InitHistory <End>")
    TRC_MSG(TRC_MMI_FRM_HIST_DINIT_HIST_BEGIN, "[MMI_FRM][History] DinitHistory <Begin>")
    TRC_MSG(TRC_MMI_FRM_HIST_DINIT_HIST_END, "[MMI_FRM][History] DinitHistory <End>")
    TRC_MSG(MMI_FRM_INFO_EXEC_HIST_SCRN_CB_STRAT, "[MMI_FRM][History] ExecHistoryScrnCallBackHandle Start <ScrnID=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_EXEC_HIST_SCRN_CB_END, "[MMI_FRM][History] ExecHistoryScrnCallBackHandle End <ScrnID=%Mmmi_screen_id_cgen_enum><is_stop_allow=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_HIST_HDLR, "[MMI_FRM][History] GetHistory <screen ID =%Mmmi_screen_id_cgen_enum, history index=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_NHIST_HDLR, "[MMI_FRM][History] GetNHistory <screen ID = %Mmmi_screen_id_cgen_enum, history index = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_HIST_SCRID_HDLR, "[MMI_FRM][History] GetHistoryScrID <screen ID =%Mmmi_screen_id_cgen_enum, history index=%d>")
    TRC_MSG(TRC_MMI_FRM_HIST_INC_HIST, "[MMI_FRM][History] increment <curr_hist_idx = %d, top_hist_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_ADD_SCRN_BEGIN, "[MMI_FRM][History] mmi_frm_add_screen <Begin> <scrn_id = %Mmmi_screen_id_cgen_enum, funcPtr=%x>")
    TRC_MSG(TRC_MMI_FRM_HIST_ADD_SCRN_END, "[MMI_FRM][History] mmi_frm_add_screen <End>")
    TRC_MSG(TRC_MMI_FRM_HIST_DECREMENT_CURRHIST_IDX, "[MMI_FRM][History] decrement_current_history_index <curr_hist_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_HISTO_STATUS, "[MMI_FRM][History] mmi_frm_set_history_node_status <set non-gobacking status> <idx = %d, status: %Mmmi_history_node_status_enum => %Mmmi_history_node_status_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_HISTO_STATUS_GB, "[MMI_FRM][History] mmi_frm_set_history_node_status <set gobacking status> <idx = %d, status: %Mmmi_history_node_status_enum => %Mmmi_history_node_status_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_HISTO_STATUS_GB_RET, "[MMI_FRM][History] mmi_frm_set_history_node_status <return gobacking status> <idx = %d, status: %Mmmi_history_node_status_enum => %Mmmi_history_node_status_enum, reentry = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_HISTO_STATUS_RET, "[MMI_FRM][History] mmi_frm_set_history_node_status <return non-gobacking status> <status = %Mmmi_history_node_status_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_EXE_WAIT_TO_DESTROY_HDLR, "[MMI_FRM][History] mmi_frm_exec_scrn_wait_to_destroy_hdlr <status = %Mmmi_history_node_status_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_NEXT_SCR_ID, "[MMI_FRM][History] GetNextScrnIdOf <scrn_id = %Mmmi_screen_id_cgen_enum, next_scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_SCR_IDX, "[MMI_FRM][History] mmi_frm_get_screen_index <scrn_id = %Mmmi_screen_id_cgen_enum, idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR1, "[MMI_FRM][History] get_range_index <Error: startScrId == 0 && endScrId == 0>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR2, "[MMI_FRM][History] get_range_index <Error: scr not present in history>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR3, "[MMI_FRM][History] get_range_index <Error: endIdxTmp is invalid>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR4, "[MMI_FRM][History] get_range_index <Error: count exists, no startIdx/endIdx>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_ERR5, "[MMI_FRM][History] get_range_index <Error: startIdx < 0 || endIdx < 0>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_RANGE_IDX_SUCCESS, "[MMI_FRM][History] get_range_index <Success> <startIdx = %d, endIdx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_SMALL_SCRN, "[MMI_FRM][History] set_small_screen <Success>")
    TRC_MSG(TRC_MMI_FRM_HIST_SET_SMALL_SCRN_ERR, "[MMI_FRM][History] set_small_screen <Fail since no small scrn>")
    TRC_MSG(TRC_MMI_FRM_HIST_IS_REDRAW_BK, "[MMI_FRM][History] mmi_is_redrawing_bk_screens <sm_scrn_state = %Mmmi_hist_smallscreen_state_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_RESET_TAB, "[MMI_FRM][History] mmi_frm_reset_tab <tab_info_p = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_FIRST_ENTRY, "[MMI_FRM][History] mmi_frm_general_tab_entry_int <First entry time> <func = 0x%x, tab_page_cnt = %d, sel_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_OTHER_ENTRY, "[MMI_FRM][History] mmi_frm_general_tab_entry_int <Other entry time> <scrn_id = %Mmmi_screen_id_cgen_enum, func = 0x%x, tab_page_cnt = %d, sel_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_EXIT_HDLR, "[MMI_FRM][History] mmi_frm_general_tab_exit")
    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_DELETE_HDLR, "[MMI_FRM][History] mmi_frm_general_tab_delete_hdlr <arg_p = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_HIST_RELEASE_TAB_GROUP, "[MMI_FRM][History] mmi_frm_release_tab_group <tab_page_count = %d, tab_history_p = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_HIST_FIND_TAB_HIST, "[MMI_FRM][History] mmi_frm_find_tab_history <scrn_id = %Mmmi_screen_id_cgen_enum, tab_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_HIST_ERR1, "[MMI_FRM][History] mmi_frm_add_tab_history <Fail - gobacking>")
    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_HIST_ERR2, "[MMI_FRM][History] mmi_frm_add_tab_history <Fail - can't find tab history>")
    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_N_HIST_ERR1, "[MMI_FRM][History] mmi_frm_add_tab_n_history <Fail - gobacking>")
    TRC_MSG(TRC_MMI_FRM_HIST_ADD_TAB_N_HIST_ERR2, "[MMI_FRM][History] mmi_frm_add_tab_n_history <Fail - can't find tab history>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_GUIBUF, "[MMI_FRM][History] mmi_frm_get_cur_tab_gui_buffer <Success>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_GUIBUF_ERR, "[MMI_FRM][History] mmi_frm_get_cur_tab_gui_buffer <NULL pointer>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_INPUTBUF, "[MMI_FRM][History] mmi_frm_get_cur_tab_input_buffer <Success>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_INPUTBUF_ERR, "[MMI_FRM][History] mmi_frm_get_cur_tab_input_buffer <NULL pointer>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_N_INPUTBUF, "[MMI_FRM][History] mmi_frm_get_cur_tab_n_input_buffer <Success>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_N_INPUTBUF_ERR1, "[MMI_FRM][History] mmi_frm_get_cur_tab_n_input_buffer <Fail - can't find tab history>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_CUR_TAB_N_INPUTBUF_ERR2, "[MMI_FRM][History] mmi_frm_get_cur_tab_n_input_buffer <Fail - NULL input buffer pointer>")
    TRC_MSG(TRC_MMI_FRM_HIST_TAB_L_ARROW_KEY_HDLR, "[MMI_FRM][History] mmi_frm_general_tab_l_arrow_key_hdlr")
    TRC_MSG(TRC_MMI_FRM_HIST_TAB_R_ARROW_KEY_HDLR, "[MMI_FRM][History] mmi_frm_general_tab_r_arrow_key_hdlr")
    TRC_MSG(TRC_MMI_FRM_HIST_FREE_TAB_BAR_ITEMS, "[MMI_FRM][History] mmi_frm_free_tab_bar_items")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_TAB_BAR_ITEMS, "[MMI_FRM][History] mmi_frm_get_tab_bar_items")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_TAB_BAR_ITEMS_ERR, "[MMI_FRM][History] mmi_frm_get_tab_bar_items <Fail - tab_bar_num = 0>")
    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_ENTRY_CHANGE_PAGE_IDX, "[MMI_FRM][History] mmi_frm_general_tab_entry_change_page_index")
    TRC_MSG(TRC_MMI_FRM_HIST_GEN_TAB_ENTRY_CHANGE_PAGE_IDX_ERR, "[MMI_FRM][History] mmi_frm_general_tab_entry_change_page_index <Fail>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_ARG_WITH_SCRN_EXIT, "[MMI_FRM][History] mmi_frm_get_argument_with_screen <Exit screen's arg> <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_ARG_WITH_SCRN_HIST, "[MMI_FRM][History] mmi_frm_get_argument_with_screen <scrn_id = %Mmmi_screen_id_cgen_enum, hist_idx = %d>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_ARG_WITH_SCRN_NULL, "[MMI_FRM][History] mmi_frm_get_argument_with_screen <NULL arg> <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_SCRN_INFO, "[MMI_FRM][History] mmi_frm_get_screen_info <scrn_id = %Mmmi_screen_id_cgen_enum, state = %Mmmi_frm_screen_state_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_GET_SCRN_INFO_ERR, "[MMI_FRM][History] mmi_frm_get_screen_info <Fail> <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_HOLD_HIST_BUFF, "[MMI_FRM][History] mmi_frm_hold_history_buffer <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_HOLD_HIST_BUFF_ERR, "[MMI_FRM][History] mmi_frm_hold_history_buffer <Fail> <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_FREE_HIST_BUFF, "[MMI_FRM][History] mmi_frm_free_history_buffer <scrn_id = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(TRC_MMI_FRM_HIST_FREE_HIST_BUFF_ERR, "[MMI_FRM][History] mmi_frm_free_history_buffer <Fail> <scrn_id = %Mmmi_screen_id_cgen_enum>")
    //SublcdHistory.c, 
    TRC_MSG(MMI_FRM_INFO_SUBHIST_EXE_SUBLCD_CUR_EXIT_HDLR, "[MMI_FRM][Sub-History] ExecSubLCDCurrExitHandler")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_HIST_HDLR, "[MMI_FRM][Sub-History] AddSubLCDHistory")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_HIST_WITHSCRID_HDLR, "[MMI_FRM][Sub-History] AddSubLCDHistoryWithScrID: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_EXIT_HDLR, "[MMI_FRM][Sub-History] SetSubLCDExitHandler: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_ENTRY_HDLR, "[MMI_FRM][Sub-History] SetSubLCDEntryHandler: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_INIT, "[MMI_FRM][Sub-History] InitSubLCDHistory: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEINIT, "[MMI_FRM][Sub-History] DinitSubLCDHistory")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_SHOW_SUBLCD_HDLR, "[MMI_FRM][Sub-History] ShowSubLCDScreen: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_FORCE_SUBLCD_HDLR, "[MMI_FRM][Sub-History] ForceSubLCDScreen: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DISPLAY_SUBLCD_HDLR, "[MMI_FRM][Sub-History] DisplaySubLCDScreen: %x, <scrnid = %Mmmi_screen_id_cgen_enum>, <force_display = %d>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_GO_BACK_SUBLCD_HDLR, "[MMI_FRM][Sub-History] GoBackSubLCDHistory")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_GO_BACK_N_SUBLCD_HDLR, "[MMI_FRM][Sub-History] GoBacknSubLCDHistory: %d")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_GO_BACK_TO_SUBLCD_HDLR, "[MMI_FRM][Sub-History] GoBackToSubLCDHistory: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_GO_BEYOND_SUBLCD_HDLR, "[MMI_FRM][Sub-History] GoBeyondSubLCDMarkerScr: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_BACK_BOTHLCD_HIST_HDLR, "[MMI_FRM][Sub-History] GoBackBothLCDHistory")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_SUBLCD_IDLE_SCRN_HDLR, "[MMI_FRM][Sub-History] SubLCDIdleScreen")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_UPTO_SUBLCD_SCR_HDLR, "[MMI_FRM][Sub-History] DeleteUptoSubLCDScrID: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_N_SUBLCD_SCR_HDLR, "[MMI_FRM][Sub-History] DeleteNSubLCDScrId: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_SUBLCD_SCR_HDLR, "[MMI_FRM][Sub-History] DeleteSubLCDScreen: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_SUBLCD_SCR_NUM, "[MMI_FRM][Sub-History] DeleteNSubLCDHistory: %d")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_BEYOND_TILL_SUBLCD_SCR_HDLR, "[MMI_FRM][Sub-History] DeleteBeyondSubLCDScrTillScr: <Beyond scrnid = %Mmmi_screen_id_cgen_enum>, <Till scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_BETWEEN_SUBLCD_SCR_HDLR, "[MMI_FRM][Sub-History] DeleteBetweenSubLCDScreen: <scrnid = %Mmmi_screen_id_cgen_enum> to <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_REPLACE_SUBLCD_SCR_HDLR, "[MMI_FRM][Sub-History] SubLCDHistoryReplace: <out_scrn_id = %Mmmi_screen_id_cgen_enum> <in_scrn_id = %Mmmi_screen_id_cgen_enum, in_src_func = %x>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DUMP_HDLR, "[MMI_FRM][Sub-History] SubLCDHistoryDump: <SubLCDHistory Dump> index,<SCRN_ID>,(entryFuncPtr) = %d,[%Mmmi_screen_id_cgen_enum],(%d)")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DUMP_ROOTHDLR, "[MMI_FRM][Sub-History] SubLCDHistoryDump: <SubLCDHistory Dump> index = -1,[0],(RootSubLcdHistoryScreenPtr)")
    TRC_MSG(MMI_FRM_SUBHIST_SWITCH_MODE_S2M, "[MMI_FRM][Sub-History] SwitchSubLCDHistory (S2M)")
    TRC_MSG(MMI_FRM_SUBHIST_SWITCH_MODE_M2S, "[MMI_FRM][Sub-History] SwitchSubLCDHistory (M2S)")
    TRC_MSG(MMI_FRM_SUBHIST_CLEAR_MASTER_HIST, "[MMI_FRM][Sub-History] ClearSubLCDMasterHistory")
    TRC_MSG(MMI_FRM_SUBHIST_FORCE_EXIT_CURR_SCR, "[MMI_FRM][Sub-History] ForceExitCurrScr")
    TRC_MSG(MMI_FRM_SUBHIST_MASTER_GOBACK_HIST, "[MMI_FRM][Sub-History] SubLCDMasterGoBackHistory")
    // sublcd_master
    TRC_MSG(MMI_FRM_ENTRY_SUBLCDMASTER_FROM_IDLE, "[MMI_FRM][Sub-Master] EntrySubLCDMasterFromIdle")
    TRC_MSG(MMI_FRM_FORCE_ENTRY_SUBLCD_MASTER, "[MMI_FRM][Sub-Master] ForceEntrySubLCDMaster")
    TRC_MSG(MMI_FRM_FORCE_ENTRY_SUBLCD_SLAVE, "[MMI_FRM][Sub-Master] ForceEntrySubLCDSlave")
    TRC_MSG(MMI_FRM_EXIT_MAINLCD_DUMMY_SCRN_TIMEOUT, "[MMI_FRM][Sub-Master] ExitMainLCDDummyScreenTimeOut")
    TRC_MSG(MMI_FRM_ENTRY_MAINLCD_DUMMY_SCRN, "[MMI_FRM][Sub-Master] EntryMainLCDDummyScreen")
    TRC_MSG(MMI_FRM_SET_SUBLCD_IN_MASTER_MODE, "[MMI_FRM][Sub-Master] SetSubLCDInMasterMode")
    TRC_MSG(MMI_FRM_SET_SUBLCD_IN_SLAVE_MODE, "[MMI_FRM][Sub-Master] SetSubLCDInSlaveMode")
    TRC_MSG(MMI_FRM_MASTER_MODE_CLAM_OPEN, "[MMI_FRM][Sub-Master] SubLCDMasterModeClamOpen")
    TRC_MSG(MMI_FRM_MASTER_MODE_CLAM_CLOSED, "[MMI_FRM][Sub-Master] SubLCDMasterModeClamclosed")

    /*****************************************************************************************************************
     * MMI Framework key trace
     *****************************************************************************************************************/

    /* key group 1 trace */ 
    TRC_MSG(TRC_MMI_FRM_KEY_HANDLE_BEGIN, "[MMI_FRM][Key] mmi_frm_key_handle <Begin> <begin to handle key events>")
    TRC_MSG(TRC_MMI_FRM_KEY_HANDLE_END, "[MMI_FRM][Key] mmi_frm_key_handle <End>")
    TRC_MSG(TRC_MMI_FRM_KEY_HANDLE_SUSPEND, "[MMI_FRM][Key] mmi_frm_key_handle <suspend>")
    TRC_MSG(TRC_MMI_FRM_KEY_CLEAR_KEY_EVENTS_BEGIN, "[MMI_FRM][Key] ClearKeyEvents <Begin>")
    TRC_MSG(TRC_MMI_FRM_KEY_CLEAR_KEY_EVENTS_END, "[MMI_FRM][Key] ClearKeyEvents <End>")
    TRC_MSG(TRC_MMI_FRM_KEY_KEY_EVENT_CLEARING, "[MMI_FRM][Key] <clear key event> <keycode = %Mmmi_keypads_enum, key type = %Mmmi_key_types_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_DISABLE_ACTION_BY_PEN_OR_BACKLIGHT, "[MMI_FRM][Key] <disable key action by pen or backlight>")
    TRC_MSG(TRC_MMI_FRM_KEY_CONVERT_KEY_CODE, "[MMI_FRM][Key] <convert %Mmmi_keypads_enum to %Mmmi_keypads_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_KEY_EVENT_INFO, "[MMI_FRM][Key] <key event will be handled> <keycode = %Mmmi_keypads_enum, key type = %Mmmi_key_types_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_DISABLE_KEY_ACTION_BY_UNPAIR, "[MMI_FRM][Key] <unpaired key event> <keycode = %Mmmi_keypads_enum, key type = %Mmmi_key_types_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_EXECUTE_PRE_KEY_HANDLER, "[MMI_FRM][Key] Execute pre key handler, <func_ptr = 0x%x>.")
    TRC_MSG(TRC_MMI_FRM_KEY_DISABLE_KEY_ACTION_BY_PRE_KEY_HDLR, "[MMI_FRM][Key] Disable key action by pre key handler. <key code = %Mmmi_keypads_enum, key type = %Mmmi_key_types_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_EXECUTE_POST_KEY_HANDLER, "[MMI_FRM][Key] Execute post key handler, <func_ptr = 0x%x>.")
    TRC_MSG(TRC_MMI_FRM_KEY_EXECUTE_KEY_HANDLER, "[MMI_FRM][Key] Execute key handler, <key code = %Mmmi_keypads_enum, key type = %Mmmi_key_types_enum, funcptr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_KEY_SUSPEND_KEY_FLOW, "[MMI_FRM][Key] mmi_suspend_handle_key_process <suspend key flow>")
    TRC_MSG(TRC_MMI_FRM_KEY_RESUME_KEY_FLOW, "[MMI_FRM][Key] mmi_suspend_handle_key_process <resume key flow>")

    /* key group 6 trace */
    TRC_MSG(TRC_MMI_FRM_KEY_MMI_KEY_CODE_SUPPORTED, "[MMI_FRM][Key] mmi_frm_kbd_is_key_supported <keycode = %Mmmi_keypads_enum, is_support = %d>")
    TRC_MSG(TRC_MMI_FRM_KEY_END_FULL_CTRL_BY_APP, "[MMI_FRM][Key] <END key full control by app>")
    TRC_MSG(TRC_MMI_FRM_KEY_VOL_FULL_CTRL_BY_APP, "[MMI_FRM][Key] <Vol key full control by app>")
    TRC_MSG(TRC_MMI_FRM_KEY_ANY_KEY_REPEAT_TO_DOWN, "[MMI_FRM][Key] <get any key down handler for repeat> <key code = %Mmmi_keypads_enum, key type = %Mmmi_key_types_enum, func_ptr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_KEY_GET_ANY_KEY_HDLR, "[MMI_FRM][Key] <get any key handler> <key code = %Mmmi_keypads_enum, key type = %Mmmi_key_types_enum, func_ptr = %x>")
    TRC_MSG(TRC_MMI_FRM_KEY_ENTER_TO_LSK, "[MMI_FRM][Key] <enter to lsk> <%Mmmi_key_types_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_REPEAT_TO_DOWN, "[MMI_FRM][Key] <get down handler for repeat event>")
    TRC_MSG(TRC_MMI_FRM_KEY_TAB_BAR_HDLR, "[MMI_FRM][Key] <get tab bar key handler>")
    TRC_MSG(TRC_MMI_FRM_KEY_CAMERA_SNAP, "[MMI_FRM][Key] <get camear snap key handler>")
    TRC_MSG(TRC_MMI_FRM_KEY_SEND_KEY_HDLR, "[MMI_FRM][Key] <get send key handler>")
    TRC_MSG(TRC_MMI_FRM_KEY_INT_CNTX, "[MMI_FRM][Key] <internal cntx> <press_key = %d, uprepeatkey = %d>")
    TRC_MSG(TRC_MMI_FRM_KEY_DEVICE_KEY_INFO, "[MMI_FRM][Key] device_key_code = %d, device_key_type = %Mkbd_event")
    TRC_MSG(TRC_MMI_FRM_KEY_DISABLE_ACTION_BY_BACKLIGTH, "[MMI_FRM][Key] <disable key action(backlight off)>")
    TRC_MSG(TRC_MMI_FRM_KEY_DISABLE_ACTION_BY_PEN, "[MMI_FRM][Key] <disable key action(pen down)>")
    TRC_MSG(TRC_MMI_FRM_KEY_PRESSING_BUF, "[MMI_FRM][Key] <active key buffer> <%d, %Mmmi_keypads_enum>")
    TRC_MSG(TRC_MMI_FRM_ERR_MMI_KEY_INFO, "[MMI_FRM][Key] <Error> <%Mmmi_keypads_enum, %Mmmi_key_types_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_UP_SUPPLEMENT, "[MMI_FRM][Key][%Mmmi_keypads_enum]up supplement")
    TRC_MSG(TRC_MMI_FRM_KEY_KEYPAD_MODE, "[MMI_FRM][Key] mmi_frm_set_keypad_mode <%Mmmi_frm_keypad_mode_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_PLAY_KEY_TONE, "[MMI_FRM][Key] <play key tone> <%Mmmi_keypads_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_STOP_KEY_TONE, "[MMI_FRM][Key] <stop key tone> <%Mmmi_keypads_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_REVERSE_CODE, "[MMI_FRM][Key] mmi_kbd_reverse_code: <mmi_key_code = %Mmmi_keypads_enum, device_key_code = %d>")
    TRC_MSG(TRC_MMI_FRM_KEY_TONE_MODE, "[MMI_FRM][Key]<num key tone mode><%Mmmi_frm_num_key_tone_mode_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_PTR_CHANGE_SUCCESS, "[MMI_FRM][Key] <keypad ptr changed successfully> <dir = %d>")
    TRC_MSG(TRC_MMI_FRM_KEY_EVENT_IS_FITERED, "[MMI_FRM][Key] <key event is fitered> <%Mmmi_keypads_enum, %Mmmi_key_types_enum>")
    TRC_MSG(TRC_MMI_FRM_KEY_EMERGENCE_CALL, "[MMI_FRM][Key] <emergency call>")
    TRC_MSG(TRC_MMI_FRM_KEY_CLRALLKEY_HDLR, "[MMI_FRM][Key] ClearAllKeyHandler")
    TRC_MSG(TRC_MMI_FRM_KEY_SET_KEY_HDLR, "[MMI_FRM][Key] <set key hdlr> <%Mmmi_keypads_enum, %Mmmi_key_types_enum, ptr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_KEY_EXECUTE_TRANS_KEY_HDLR, "[MMI_FRM][Key] Execute translate key handler, <level = %Mmmi_frm_trans_key_handle_enum, functpr = 0x%x, key code = %Mmmi_keypads_enum, key type = %Mmmi_key_types_enum, ucs2 = 0x%x, special key flag = 0x%x")
    
    /*****************************************************************************************************************
     * MMI Framework queue trace
     *****************************************************************************************************************/

    /* Queue group 6 trace */
    TRC_MSG(TRC_MMI_FRM_QUEUE_WRITE_CQ, "[MMI_FRM][QUEUE] OslWriteCircularQ <msg_num_before_write = %d, curr_msg = %Mmsg_type>")
    TRC_MSG(TRC_MMI_FRM_QUEUE_READ_CQ, "[MMI_FRM][QUEUE] OslReadCircularQ <msg_num_befeore_read = %d>")

    /*****************************************************************************************************************
     * MMI Framework timer trace
     *****************************************************************************************************************/

    /* Timer group1 trace */
    TRC_MSG(TRC_MMI_FRM_TIMER_START_ALIGN_TIMER, "[MMI_FRM][Timer] StartTimer <align timer(coarse)> - <timer id = %MMMI_TIMER_IDS, duration = %d milliseconds, call back = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_TIMER_START_ALIGN_TIMER_EX, "[MMI_FRM][Timer] StartTimerEx <align timer(coarse)> - <timer id = %MMMI_TIMER_IDS, duration = %d milliseconds, call back = 0x%x, arg = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_TIMER_START_NON_ALIGN_TIMER, "[MMI_FRM][Timer] StartNonAlignTimer <non-align timer(precise)> - <timer id = %MMMI_TIMER_IDS, duration = %d milliseconds, call back = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_TIMER_START_NON_ALIGN_TIMER_EX, "[MMI_FRM][Timer] StartNonAlignTimerEx <non-align timer(precise)> - <timer id = %MMMI_TIMER_IDS, duration = %d milliseconds, call back = 0x%x, arg = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_TIMER_STOP_TIMER, "[MMI_FRM][Timer] StopTimer <timer id = %MMMI_TIMER_IDS>")
    TRC_MSG(TRC_MMI_FRM_TIMER_SUSPEND_TIMER, "[MMI_FRM][Timer] mmi_frm_suspend_timers <type = %Mmmi_timer_type_enum>")
    TRC_MSG(TRC_MMI_FRM_TIMER_RESUME_TIMER, "[MMI_FRM][Timer] mmi_frm_resume_timers <type = %Mmmi_timer_type_enum>")
    TRC_MSG(TRC_MMI_FRM_TIMER_EXECUTE_TIMER_CALL_BACK, "[MMI_FRM][Timer] <Execute timer call back> <timer id = %MMMI_TIMER_IDS, call back = 0x%x, para = 0x%x>")

    /* Timer group6 trace */
    TRC_MSG(TRC_MMI_FRM_TIMER_INVALID_TIMER_MSG, "[MMI_FRM][Timer] <invalid timer message>")

    /*****************************************************************************************************************
     * MMI Framework NVRAM trace
     *****************************************************************************************************************/
    /* NVRAM group 1 trace */
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_CORE_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadRecord <Begin> <lid = %Mnvram_lid_core_enum, record id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_COMAPP_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadRecord <Begin> <lid = %Mnvram_lid_commapp_enum, record id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_CUST_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadRecord <Begin> <lid = %Mnvram_lid_cust_enum, record id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_RECORD_END, "[MMI_FRM][NVRAM] ReadRecord <End> <result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_MULTI_CORE_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadMultiRecord <Begin> <lid = %Mnvram_lid_core_enum, record id = %d, rec_amount = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_MULTI_COMAPP_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadMultiRecord <Begin> <lid = %Mnvram_lid_commapp_enum, record id = %d, rec_amount = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_MULTI_CUST_RECORD_BEGIN, "[MMI_FRM][NVRAM] ReadMultiRecord <Begin> <lid = %Mnvram_lid_cust_enum, record id = %d, rec_amount = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_MULTI_RECORD_END, "[MMI_FRM][NVRAM] ReadMultiRecord <End> <result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_CORE_RECORD_BEGIN, "[MMI_FRM][NVRAM] WriteRecord <Begin> <lid = %Mnvram_lid_core_enum, record_id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_COMAPP_RECORD_BEGIN, "[MMI_FRM][NVRAM] WriteRecord <Begin> <lid = %Mnvram_lid_commapp_enum, record_id = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_CUST_RECORD_BEGIN, "[MMI_FRM][NVRAM] WriteRecord <Begin> <lid = %Mnvram_lid_cust_enum, record_id = %d>") 
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_RECORD_END, "[MMI_FRM][NVRAM] WriteRecord <End> <result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_BYTE_VALUE, "[MMI_FRM][NVRAM] ReadValue <type = DS_BYTE, value id = %MBYTEDATA, result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_SHORT_VALUE, "[MMI_FRM][NVRAM] ReadValue <type = DS_SHORT, value id = %MSHORTDATA, result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_READ_DOUBLE_VALUE, "[MMI_FRM][NVRAM] ReadValue <type = DS_DOUBLE, value id = %MDOUBLEDATA, result = %MMMINVRAMERRORSENUM>")    
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_BYTE_VALUE, "[MMI_FRM][NVRAM] WriteValue <type = DS_BYTE, value id = %MBYTEDATA, result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_SHORT_VALUE, "[MMI_FRM][NVRAM] WriteValue <type = DS_SHORT, value id = %MSHORTDATA, result = %MMMINVRAMERRORSENUM>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_DOUBLE_VALUE, "[MMI_FRM][NVRAM] WriteValue <type = DS_DOUBLE, value id = %MDOUBLEDATA, result = %MMMINVRAMERRORSENUM>")    
    TRC_MSG(TRC_MMI_FRM_NVRAM_FLUSH_CACHE_DATA, "[MMI_FRM][NVRAM] <Flush cache data> <type = %MDATASIZE, flag = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_SET_FLUSH_CACHE_FLAG, "[MMI_FRM][NVRAM] <set flush cache flag> <type = %MDATASIZE, value = %d>")
    /* NVRAM group 6 trace */
    TRC_MSG(TRC_MMI_FRM_NVRAM_JUDGE_IS_PROCEDURE, "[MMI_FRM][NVRAM] IsInNVRAMProcedure <recursive_num = %d>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_SEND_WRITE_REQ, "[MMI_FRM][NVRAM] SendNVRAMWriteReq")
    TRC_MSG(TRC_MMI_FRM_NVRAM_SEND_READ_REQ, "[MMI_FRM][NVRAM] SendNVRAMReadReq")
    TRC_MSG(TRC_MMI_FRM_NVRAM_FS_SANITY_CHECK_PROCESSING, "[MMI_FRM][NVRAM] <FS sanity check processing>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_WRITE_CACHE_BY_LID, "[MMI_FRM][NVRAM] <direct write cache by lid><lid = %Mnvram_lid_cust_enum>")
    TRC_MSG(TRC_MMI_FRM_NVRAM_CHECK_CQ, "[MMI_FRM][NVRAM] <check circular q> <result = %McircularQ_check_enum>")

    /*****************************************************************************************************************
     * MMI Framework Memory trace
     *****************************************************************************************************************/
    TRC_MSG(TRC_MMI_FRM_MEM_APP_ASM_ALLOC, "[MMI_FRM][MEM] <APP_ASM alloc> <app_id = %Mapplib_mem_ap_id_enum, size = %d, line = %d, ptr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_MEM_APP_ASM_FREE, "[MMI_FRM][MEM] <APP_ASM free> <ptr = 0x%x, line = %d>")
    TRC_MSG(TRC_MMI_FRM_MEM_SCR_ASM_ALLOC, "[MMI_FRM][MEM] <SCR_ASM alloc> <scr_id = %Mmmi_screen_id_cgen_enum, size = %d, line = %d, ptr = 0x%x>")
    TRC_MSG(TRC_MMI_FRM_MEM_SCR_ASM_FREE, "[MMI_FRM][MEM] <SCR_ASM free> <ptr = 0x%x, line = %d>")

    // Memory Manager, App-based ASM
    // AppMemMgr.c
    TRC_MSG(MMI_FRM_ASM_ENTRY_PROGRESSING_SCREEN, "[MMI_FRM][ASM] entry progressing screen: [%Mkal_bool]")
    TRC_MSG(MMI_FRM_ASM_STOP_CONFIRM_YES, "[MMI_FRM][ASM] yes to stop confirm screen: app[%Mapplib_mem_ap_id_enum] StopState[%Mmmi_frm_appmem_stop_state_enum]")
    TRC_MSG(MMI_FRM_ASM_ENTRY_PROMPT_SCREEN, "[MMI_FRM][ASM] entry prompt screen: [%Mkal_bool]")
    TRC_MSG(MMI_FRM_ASM_INVOKE_SUCCESS_CB, "[MMI_FRM][ASM] invoke success cb: app[%Mapplib_mem_ap_id_enum] cb[0x%x]")
    TRC_MSG(MMI_FRM_ASM_STOP_FINISHED_HANDLER, "[MMI_FRM][ASM] stop finished handler: msg[%MSTRINGID_LIST_COMMON_SCREENS] cb[0x%x]")
    TRC_MSG(MMI_FRM_ASM_PROMPT_TO_RELEASE_MEM, "[MMI_FRM][ASM] prompt to release mem: app[%Mapplib_mem_ap_id_enum] size[%d]")
    TRC_MSG(MMI_FRM_ASM_PROMPT_TO_RELEASE_FULL_POOL, "[MMI_FRM][ASM] prompt to release full pool: app[%Mapplib_mem_ap_id_enum]")
    //ResMemMgr.c
    TRC_MSG(TRC_MMI_RESMEM_MEMORY_POOL_INFO,"[MMI_FRM][RESMEM] ALWAYS pool size : %d LOD pool size : %d String pool size : %d")
    TRC_MSG(TRC_MMI_RESMEM_MEMORY_ALLOCFAIL_INFO,"[MMI_FRM][RESMEM] Pool type : %M The maximal left memory size : %d, allocated memory size : %d, need to add pool size : %d!")
    TRC_MSG(TRC_MMI_RESMEM_MEMORY_STRING_POOL_INFO,"[MMI_FRM][RESMEM] The string content memory size : %d, string map size : %d, total string pool size : %d")
    //TouchScreen.c, 
    /* Group 1 trace - MMI_FW_TRC_G1_FRM */
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT,"[MMI_FRM][Pen] mmi_pen_check_tp_shortcut (%d, %d), event:%d")
    TRC_MSG(MMI_PEN_TRC_DROP_LOOKAHEAD_BUF, "[MMI_FRM][Pen] Drop lookahead buffer (%d - %d)")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_AREA, "[MMI_FRM][Pen] mmi_pen_check_tp_shortcut <in touch panel shortcut area (%d)>")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_DOWN, "[MMI_FRM][Pen] mmi_pen_check_tp_shortcut index:%d down")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_UP, "[MMI_FRM][Pen] mmi_pen_check_tp_shortcut index:%d up")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_MOVE, "[MMI_FRM][Pen] mmi_pen_check_tp_shortcut index:%d move")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_LONGTAP, "[MMI_FRM][Pen] mmi_pen_check_tp_shortcut index:%d longtap")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_REPEAT, "[MMI_FRM][Pen] mmi_pen_check_tp_shortcut index:%d repeat")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_ABORT, "[MMI_FRM][Pen] mmi_pen_check_tp_shortcut index:%d abort")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_DEFAULT, "[MMI_FRM][Pen] mmi_pen_check_tp_shortcut index:%d default")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR, "[MMI_FRM][Pen] mmi_pen_poll_hdlr - %d %d")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_NO_BL, "[MMI_FRM][Pen] mmi_pen_poll_hdlr - no backlight")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_DOWN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr - PEN_DOWN <x = %d, y = %d, time: %d>")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_MOVE, "[MMI_FRM][Pen] mmi_pen_poll_hdlr - PEN_MOVE <x = %d, y = %d>")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_UP, "[MMI_FRM][Pen] mmi_pen_poll_hdlr - PEN_UP <x = %d, y = %d, time: %d>")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_LONGTAP, "[MMI_FRM][Pen] mmi_pen_poll_hdlr - PEN_LONGTAP <x = %d, y = %d>")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_REPEAT, "[MMI_FRM][Pen] mmi_pen_poll_hdlr - PEN_REPEAT <x = %d, y = %d>")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_ABORT, "[MMI_FRM][Pen] mmi_pen_poll_hdlr - PEN_ABORT <x = %d, y = %d>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_STROKE_DOWN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <STROKE_DOWN> <x = %d, y = %d, time: %d>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_STROKE_LONGTAP, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <STROKE_LONGTAP> <x = %d, y = %d>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_STROKE_MOVE, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <STROKE_MOVE> <x = %d, y = %d>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_STROKE_UP, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <STROKE_UP> <x = %d, y = %d, time: %d>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_UNKNOWN_EVENT, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Unknow event> <x = %d, y = %d>")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_DELAY_POLLING_TIMER, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <delay polling timer>")
    TRC_MSG(MMI_PEN_TRC_TOUCH_PANEL_EVENT_IND, "[MMI_FRM][Pen] mmi_pen_touch_panel_event_in - %d, %d")
    TRC_MSG(MMI_PEN_TRC_ENABLE, "[MMI_FRM][Pen] mmi_pen_enable()")
    TRC_MSG(MMI_PEN_TRC_DISABLE, "[MMI_FRM][Pen] mmi_pen_disable()")
    TRC_MSG(MMI_PEN_TRC_RESET, "[MMI_FRM][Pen] mmi_pen_reset()")
    TRC_MSG(MMI_PEN_TRC_FLUSH_QUEUE, "[MMI_FRM][Pen] mmi_frm_pen_flush_queue()")
    TRC_MSG(MMI_PEN_TRC_RESET_CONTEXT_FOR_NEW_SCREEN, "[MMI_FRM][Pen] mmi_frm_pen_reset_context_for_new_screen()")
    TRC_MSG(MMI_PEN_TRC_CALIBRATION, "[MMI_FRM][Pen] mmi_pen_start_calibration()")
    TRC_MSG(MMI_PEN_TRC_START_CAPTURE_STROKES, "[MMI_FRM][Pen] mmi_pen_start_capture_strokes()")
    TRC_MSG(MMI_PEN_TRC_CHANGE_HANDWRITING_AREA, "[MMI_FRM][Pen] mmi_pen_change_handwriting_area()")
    TRC_MSG(MMI_PEN_TRC_STOP_CAPTURE_STROKES, "[MMI_FRM][Pen] mmi_pen_stop_capture_strokes()")
    TRC_MSG(MMI_PEN_TRC_PEEK_STROKE_STATE, "[MMI_FRM][Pen] mmi_pen_peek_stroke_state() - %d")
    TRC_MSG(MMI_PEN_TRC_BEGIN_STROKES_OF_CHAR, "[MMI_FRM][Pen] mmi_pen_begin_strokes_of_character()")
    TRC_MSG(MMI_PEN_TRC_END_STROKES_OF_CHAR, "[MMI_FRM][Pen] mmi_pen_end_strokes_of_character()")
    TRC_MSG(MMI_PEN_TRC_PEN_DOWN_HDLR, "[MMI_FRM][Pen] mmi_general_pen_down_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_UP_HDLR, "[MMI_FRM][Pen] mmi_general_pen_up_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_LONG_TAP_HDLR, "[MMI_FRM][Pen] mmi_general_pen_long_tap_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_REPEAT_HDLR, "[MMI_FRM][Pen] mmi_general_pen_repeat_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_MOVE_HDLR, "[MMI_FRM][Pen] mmi_general_pen_move_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_ABORT_HDLR, "[MMI_FRM][Pen] mmi_general_pen_abort_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_SET_DEFAULT_HDLR, "[MMI_FRM][Pen] mmi_frm_setup_default_pen_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_SET_EVENT_HDLR_CB, "[MMI_FRM][Pen] mmi_pen_set_callback: pre:%x, post:%x")
    TRC_MSG(MMI_PEN_TRC_RESET_EVENT_HDLR_CB, "[MMI_FRM][Pen] mmi_pen_set_callback: pre:%x, post:%x")
    TRC_MSG(MMI_PEN_TRC_CHECK_INSIDE_POLYGON, "[MMI_FRM][Pen] <%d,%d> check_inside_polygon: (%d, %d) (%d, %d) (%d, %d) (%d, %d); result:%d")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_DOWN_HDLR, "[MMI_FRM][Pen] Register pen down handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_UP_HDLR, "[MMI_FRM][Pen]Register pen up handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_LONG_TAP_HDLR, "[MMI_FRM][Pen] Register pen longtap handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_DOUBLE_CLICK_HDLR, "[MMI_FRM][Pen] Register pen double click handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_MOVE_HDLR, "[MMI_FRM][Pen] register pen move handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_REPEAT_HDLR, "[MMI_FRM][Pen] Register pen repeat handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_ABORT_HDLR, "[MMI_FRM][Pen] Register pen abort handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_STROKE_DOWN_HDLR, "[MMI_FRM][Pen] Register stroke down handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_STROKE_UP_HDLR, "[MMI_FRM][Pen] Register stroke up handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_STROKE_LONGTAP_HDLR, "[MMI_FRM][Pen] Register stroke longtap handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_STROKE_MOVE_HDLR, "[MMI_FRM][Pen] Register stroke move handler 0x%X")
    TRC_MSG(TRC_MMI_PEN_INIT_BEGIN, "[MMI_FRM][Pen] mmi_pen_init <Begin>")
    TRC_MSG(TRC_MMI_PEN_INIT_END, "[MMI_FRM][Pen] mmi_pen_init <End>")
    TRC_MSG(TRC_MMI_PEN_BLOCK, "[MMI_FRM][Pen] mmi_pen_block")
    TRC_MSG(TRC_MMI_PEN_UNBLOCK, "[MMI_FRM][Pen] mmi_pen_unblock")
    TRC_MSG(MMI_PEN_TRC_RESET_ERR, "[MMI_FRM][Pen] mmi_pen_reset, <Error> <init = %Mkal_bool, is_blocked = %d, is_enabled = %d>")
    TRC_MSG(TRC_MMI_PEN_GET_STATE, "[MMI_FRM][Pen] mmi_pen_get_state, <is_enabled = %Mkal_bool, is_pen_down = %Mkal_bool>")
    TRC_MSG(TRC_MMI_PEN_GET_INFO, "[MMI_FRM][Pen] mmi_pen_get_info, <pen_type = %Mmmi_pen_event_type_enum, stroke_type = %Mmmi_pen_stroke_type_enum>")
    TRC_MSG(TRC_MMI_PEN_SET_CALIBRATION_DATA, "[MMI_FRM][Pen] mmi_pen_set_calibration_data")
    TRC_MSG(TRC_MMI_PEN_READ_CALIBRATION_DATA, "[MMI_FRM][Pen] mmi_pen_set_calibration_data")

    /* Group 6 trace - MMI_FW_TRC_G6_FRM_DETAIL */
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PRE_CB, "[MMI_FRM][Pen] MMI_PEN_EXECUTE_PRE_CALLBACK_FUNC <event = %Mmmi_pen_event_type_enum>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_POST_CB, "[MMI_FRM][Pen] MMI_PEN_EXECUTE_POST_CALLBACK_FUNC <event = %Mmmi_pen_event_type_enum>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_DOUBLE_CLICK_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen double click begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_DOUBLE_CLICK_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen double click end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_DOWN_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr  <Process pen down begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_DOWN_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen down end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_UP_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen up begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_UP_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen up end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_MOVE_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen move begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_MOVE_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen move end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_LONGTAP_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen longtap begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_LONGTAP_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen longtap end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_REPEAT_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen repeat begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_PEN_REPEAT_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process pen repeat end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_MOVE_GEN_ABORT_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke move generate pen abort begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_MOVE_GEN_ABORT_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke move generate pen abort end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_MOVE_GEN_DOWN_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke move generate stroke down begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_MOVE_GEN_DOWN_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke move generate stroke down end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_MOVE_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke move begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_MOVE_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke move end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_DOWN_GEN_PEN_DOWN_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke down generate pen down begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_DOWN_GEN_PEN_DOWN_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke down generate pen down end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_DOWN_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke down begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_DOWN_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke down end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_UP_GEN_PEN_UP_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke up generate pen up begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_UP_GEN_PEN_UP_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke up generate pen up end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_UP_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke up begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_UP_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke up end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_LONGTAP_BEGIN, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke longtap begin>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_PROCESS_STROKE_LONGTAP_END, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Process stroke longtap end>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_BREAK_SINCE_MSG, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <Break process flow since msg of cir_q is out of threshold>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_START_TIME_FOR_UNNORMAL_BREAK, "[MMI_FRM][Pen] mmi_pen_poll_hdlr <is_pen_down = %d, pen_abort_happen = %Mkal_bool>")
    TRC_MSG(TRC_MMI_PEN_POLL_HDLR_GEN_PEN_ABORT, "[MMI_FRM][Pen] generate_pen_abort_event <Generate pen abort event>")

    /*****************************************************************************************************************
     * MMI Framework task trace
     *****************************************************************************************************************/
    /* Task group1 trace*/
    TRC_MSG(TRC_MMI_FRM_TASK_MSG_HANDLE_BEGIN, "[MMI_FRM][Task] MMI_task <Begin> <Message handling> <msgid = %Mmsg_type, scr_mod = %Mmodule_type, dst_mod = %Mmodule_type>.")
    TRC_MSG(TRC_MMI_FRM_TASK_MSG_HANDLE_END, "[MMI_FRM][Task] MMI_task <End> <Message handling> <msgid = %Mmsg_type, scr_mod = %Mmodule_type, dst_mod = %Mmodule_type>.")
    TRC_MSG(TRC_MMI_FRM_TASK_POWER_PROC_BEGIN, "[MMI_FRM][Task] MMI_task <Begin> <Power on proc> <power on mode = %Mpower_on_status_enum>")
    TRC_MSG(TRC_MMI_FRM_TASK_POWER_PROC_END, "[MMI_FRM][Task] MMI_task <End> <Power on proc> <power on mode = %Mpower_on_status_enum>")
    TRC_MSG(TRC_MMI_FRM_TASK_IN_NVRAM_PROCEDURE, "[MMI_FRM][Task] AccessRecordInt <in NVRAM procedure> <nest level = %d>")
    TRC_MSG(TRC_MMI_FRM_TASK_IN_NVRAM_PROCEDURE_HANDLE_TIMER_MSG, "[MMI_FRM][Task] AccessRecordInt <handle timer message in NVRAM while loop>")

    /* task group6 trace */
    TRC_MSG(TRC_MMI_FRM_TASK_SUSPEND_EXTERNAL_Q, "[MMI_FRM][Task] MMI task suspends at external queue.")
    TRC_MSG(TRC_MMI_FRM_TASK_COPY_EXTERNAL_Q_TO_CIRCULAR_Q, "[MMI_FRM][Task] mmi_frm_fetch_msg_from_extQ_to_circularQ <num = %d>")

    /*****************************************************************************************************************
     * MMI Framework theme trace
     *****************************************************************************************************************/
    //ThemeManager.c 
    TRC_MSG(MMI_TM_TRC_ADD_IMG_ID_TO_CACHE_HDLR, "[MMI_FRM][THEME] mmi_tm_add_img_id_to_cache: img_list_index =%d, image_offset = %d type = %d")
    TRC_MSG(MMI_TM_TRC_CREATE_NON_IMAGEID_IMAGE_HDLR, "[MMI_FRM][THEME] mmi_tm_create_non_imageid_image: image_offset =%d, type = %d")
    TRC_MSG(MMI_TM_TRC_ACTIVATE_DEFAULT_THEME_HDLR, "[MMI_FRM][THEME] mmi_tm_activate_default_theme")
    TRC_MSG(MMI_TM_TRC_SET_IMAGEID_HDLR, "[MMI_FRM][THEME] mmi_tm_set_imageid: image_id =%d has type = %d")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_DOWNLOADED_THEME, "[MMI_FRM][THEME] mmi_tm_activate_downloaded_theme()")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_THEME_FROM_FMGR, "[MMI_FRM][THEME] mmi_tm_activate_theme_from_fmgr()")
    TRC_MSG(TRC_MMI_TM_DELETE_THEME, "[MMI_FRM][THEME] mmi_tm_delete_theme(), theme id: %d")
    TRC_MSG(TRC_MMI_TM_DELETE_THEME_FROM_FMGR, "[MMI_FRM][THEME] mmi_tm_delete_theme_from_fmgr(), theme type: %M")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_THEME, "[MMI_FRM][THEME] mmi_tm_activate_theme(), theme id: %d")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_THEME_AT_BOOTUP, "[MMI_FRM][THEME] mmi_tm_activate_theme_at_bootup()")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_SYSTEM_THEME, "[MMI_FRM][THEME] mmi_tm_activate_system_theme(), theme id: %d")

    /* GDI */
    TRC_MSG(GDI_TRC_1,"******* gdi_image_codec_draw PRE type=%d src=%d size=%d x=%d y=%d w=%d h=%d flag=%x frame_pos=%d")
    TRC_MSG(GDI_TRC_2,"gdi_image_codec_draw image type=%d src=%d size=%d x=%d y=%d w=%d h=%d flag=%x frame_pos=%d")
    TRC_MSG(GDI_TRC_3,"------- decode time=%d delay time=%d ret=%d")
    TRC_MSG(GDI_TRC_5,"gdi_image_gif_draw(hw) src=%x,size=%d,x=%d,y=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_6,"gdi_image_gif_draw(sw) src=%x,size=%d,x=%d,y=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_7,"gdi_image_gif_draw_resized(hw) src=%x,size=%d,x=%d,y=%d,rw=%d,rh=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_8,"gdi_image_gif_draw_resized(sw) src=%x,size=%d,x=%d,y=%d,rw=%d,rh=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_9,"gdi_image_gif_draw_with_background_color(hw) src=%x,size=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_10,"gdi_image_gif_draw_with_background_color(sw) src=%x,size=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_11,"gdi_image_gif_draw_file(hw) id=%x,x=%d,y=%d,frame_number=%d cached_by_hw=%d ret=%d")
    TRC_MSG(GDI_TRC_12,"gdi_image_gif_draw_file(sw) id=%x,x=%d,y=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_13,"gdi_image_gif_draw_resized_file(sw) id=%x,x=%d,y=%d,rw=%d,rh=%d,frame_number=%d ret=%d")
    TRC_MSG(GDI_TRC_14,"sw disposal method: restore background(%d,%d)-(%d,%d) clip=(%d,%d)-(%d,%d) color=%x")
    TRC_MSG(GDI_TRC_15,"GDI_HW_JPG set_ext_memory size=%d")
    TRC_MSG(GDI_TRC_16,"GDI_HW_JPG set_source_image file mem_size=%d")
    TRC_MSG(GDI_TRC_17,"try gdi_image_hwjpeg_enlarge_file_buffer ")
    TRC_MSG(GDI_TRC_18,"gdi_image_hwjpeg_enlarge_file_buffer size=%d")
    TRC_MSG(GDI_TRC_19,"---- GDI_HW_JPG INIT BEGIN----")
    TRC_MSG(GDI_TRC_20,"---- GDI_HW_JPG INIT END ret=%d----")
    TRC_MSG(GDI_TRC_21,"gdi_image_hwjpeg_msg_handler cause=%d")
    TRC_MSG(GDI_TRC_22,"---- GDI_HW_JPG decode BEGIN ----")
    TRC_MSG(GDI_TRC_23,"jpeg_decode_process cause=%d")
    TRC_MSG(GDI_TRC_24,"---- GDI_HW_JPG decode END ----")
    TRC_MSG(GDI_TRC_25,"[%d] LAYER[%x] %x cf=%x (%d,%d) wh(%d,%d) size=%d ptr=%x ptr1=%x R%d")
    TRC_MSG(GDI_TRC_26,"-- GDI free lazy layer --")
    TRC_MSG(GDI_TRC_27,"gdi_layer_create cf=%x (%d,%d) wh(%d,%d) is_double(%d) size=%d ptr=%x ptr1=%x")
    TRC_MSG(GDI_TRC_28,"gdi_layer_free [%d] %x")
    TRC_MSG(GDI_TRC_29,"gdi_layer_lazy_free [%d] %x")
    TRC_MSG(GDI_TRC_30,"GDI_RAISE gdi_bytestream_get_byte_mem %d/%d")
    TRC_MSG(GDI_TRC_31,"GDI_RAISE gdi_bytestream_peek_byte_mem %d/%d")
    TRC_MSG(GDI_TRC_32,"GDI_RAISE gdi_bytestream_peek_byte_n_mem %d/%d")
    TRC_MSG(GDI_TRC_33,"GDI_RAISE gdi_bytestream_get_word_mem %d/%d")
    TRC_MSG(GDI_TRC_34,"GDI_RAISE gdi_bytestream_get_3bytes_mem %d/%d")
    TRC_MSG(GDI_TRC_35,"GDI_RAISE gdi_bytestream_get_dword_mem %d/%d")
    TRC_MSG(GDI_TRC_36,"GDI_RAISE gdi_bytestream_get_array_mem %d/%d")
    TRC_MSG(GDI_TRC_37,"GDI_RAISE gdi_bytestream_flush_mem %d/%d")
    TRC_MSG(GDI_TRC_38,"GDI_RAISE gdi_bytestream_seek_mem %d/%d")
    TRC_MSG(GDI_TRC_39,"GDI_RAISE gdi_bytestream_buffer_load_file %d/%d")
    TRC_MSG(GDI_TRC_40,"GDI_RAISE gdi_bytestream_seek_file %d/%d")
    TRC_MSG(GDI_TRC_41,"GDI_BMP_EXCEPTION_ESCAPE_MODE_END_OF_BITMAP")
    TRC_MSG(GDI_TRC_42,"GDI_RAISE GDI_IMAGE_GIF_CODEC %d")
    TRC_MSG(GDI_TRC_43,"GDI_RAISE gdi_image_gif_progress_callback")
    TRC_MSG(GDI_TRC_44,"GDI_RAISE y <= src_clipy2")
    TRC_MSG(GDI_TRC_45,"GIF(sw) hit cache fn=%d, lcd=%d, frame_count = %d, offset = %d")
    TRC_MSG(GDI_TRC_46,"GIF(sw) NOT hit cache background color (%d,%d) =%x")
    TRC_MSG(GDI_TRC_47,"resized width x height = %dx %d")
    TRC_MSG(GDI_TRC_48,"jpeg spatial dithering buffer size = %d")
    TRC_MSG(GDI_TRC_49,"jpeg spatial dithering enable")
    TRC_MSG(GDI_TRC_50,"jpeg spatial dithering disable")
    TRC_MSG(GDI_TRC_51,"jpeg spatial_dithering888_565 [%x -> %x] , (%d,%d)  (%d x %d)")
    TRC_MSG(GDI_TRC_52,"FORCE ABORT!!")
    TRC_MSG(GDI_TRC_53,"gdi_image_codec set timeout = %d seconds")
    TRC_MSG(GDI_TRC_54,"gdi_image_codec clean timeout")
    TRC_MSG(GDI_TRC_55,"FORCE ABORT SUCCEED")
    TRC_MSG(GDI_TRC_56,"gdi_image_set_update_area %d %d %d %d")

    /* GDI-SVG */
    TRC_MSG(GDI_SVG_TRC_SVG_RAISE_ERROR,"[SVG] SVG_RAISE Error %d")
    TRC_MSG(GDI_SVG_TRC_PARSER_ELEMENT,"[SVG] Parser : Valid SVG_PARSER_TABLE element index = %d")
    TRC_MSG(GDI_SVG_TRC_PARSER_ELEMENT_UNKNOWN,"[SVG] Parser : Unknown SVG_PARSER_TABLE element")
    TRC_MSG(GDI_SVG_TRC_PARSER_ELEMENT_UNKNOWN_INDEX,"[SVG] Parser : Unknown SVG_PARSER_TABLE element index = %d")
    TRC_MSG(GDI_SVG_TRC_STACK_OVERFLOW,"[SVG] Stack will overflow.")
    

    TRC_MSG(MMI_FW_BUFFER_TRACE, " *** Get data in [lower Panel] ***")

    /* Drawmanager & Categories */
    TRC_MSG(MMI_WGUI_TRC_DM_REDRAW, "[DMGR] Redraw DM_Main_Status = [%d], CatID = [%MMMI_CATEGORY_ID_LIST]")
    TRC_MSG(MMI_WGUI_TRC_DM_SUB_STATUS, "[DMGR] Redraw DM_SUB_Status = [%d]")
    TRC_MSG(MMI_WGUI_TRC_DM_MULTITAP_DEF, "[DMGR] dm_update_multitap_coordinates: Control should never come here.")
    TRC_MSG(MMI_WGUI_TRC_CAT280_TEXT_INPUT_CALLBACK_EDITOR, "[CAT280] Text input callback: editor event = %d, code = %d")
    TRC_MSG(MMI_WGUI_TRC_CAT280_TEXT_INFO_ORIGINAL, "[CAT280] Text original: char_count=%d, uft8_msg_len=%d, extension=%d, UCS2_count=%d")
    TRC_MSG(MMI_WGUI_TRC_CAT280_TEXT_INFO_NEW, "[CAT280] Text new: char_count=%d, uft8_msg_len=%d, extension=%d, UCS2_count=%d")
    TRC_MSG(MMI_WGUI_TRC_CAT280_TEXT_INFO_APP, "[CAT280] Text app: return = %d, char_count=%d, uft8_msg_len=%d, extension=%d, UCS2_count=%d")
    TRC_MSG(MMI_WGUI_TRC_CAT280_TEXT_INFO_FINAL, "[CAT280] Text final: char_count=%d, uft8_msg_len=%d, extension=%d, UCS2_count=%d")
    TRC_MSG(MMI_WGUI_TRC_CAT6001_CONTROL_AREA, "[CAT] Controlled area: Y=[%d], H=[%d].")
    TRC_MSG(MMI_WGUI_TRC_CAT6001_PEN_POINT, "[CAT] Pen event point: X=[%d], Y=[%d].")
    
    /* Resgen */
    TRC_MSG(MMI_RESGEN_ALL_MENU_HIDE, "[RESGEN] All children of parent_item_id=[%d] are hidden")
    TRC_MSG(MMI_RESGEN_ZIP_TIME_CHECK, "[RESGEN] UNZIP time step[%d] tick=[%d] time=[%d]")
    

    /* Editor */
    TRC_MSG(MMI_GUI_EDITOR_ML_ENTER_SHOWN, "[EDITOR] Enter ML shown function in non-cache mode")
    TRC_MSG(MMI_GUI_EDITOR_ML_ENTER_SHOWN_WITH_CACHE, "[EDITOR] Enter ML shown function in cache mode")
    TRC_MSG(MMI_GUI_EDITOR_ML_LEAVE_SHOWN, "[EDITOR] LEAVE ML shown function for %d times, spent %d(ms)")
    TRC_MSG(MMI_GUI_EDITOR_ML_PAGING_REQUEST_NEXT_DATA, "[EDITOR] Paging request the next page data, page id = %d")
    TRC_MSG(MMI_GUI_EDITOR_ML_PAGING_REQUEST_PRE_DATA, "[EDITOR] Paging request the previouse page data, page id = %d")
    TRC_MSG(MMI_GUI_EDITOR_CACHE_FORCED_FREE, "[EDITOR] CACHE is forced free")
    TRC_MSG(MMI_GUI_EDITOR_CACHE_REALLOC_ALL_LINE, "[EDITOR] Realloc cache for all line 0x%x")
    TRC_MSG(MMI_GUI_EDITOR_CACHE_ALLOC_MEMORY_FOR_VISIBLE, "[EDITOR] Malloc cache for visible line, memeory size = 0x%x")
    TRC_MSG(MMI_GUI_EDITOR_CACHE_ALLOC_MEMORY_FOR_ALL_LINES, "[EDITOR] Malloc cache for all line, memeory size = 0x%x")
    TRC_MSG(MMI_GUI_EDITOR_CACHE_ALLOC_FAIL, "[EDITOR] Malloc Failed")
    TRC_MSG(MMI_GUI_EDITOR_CACHE_ALLOC_SUCCESS, "[EDITOR] Malloc Success")
    TRC_MSG(MMI_GUI_EDITOR_EMS_LEAVE_SHOWN, "[EDITOR] LEAVE EMS shown function for %d times, spent %d(ms)")
    TRC_MSG(MMI_GUI_EDITOR_EMS_ENTER_SHOWN, "[EDITOR] Enter EMS shown function in non-cache mode")
    TRC_MSG(MMI_GUI_EDITOR_EMS_ENTER_SHOWN_WITH_CACHE, "[EDITOR] Enter EMS shown function in cache mode")

    /* EMS 7BIT conversion */
    TRC_MSG(MMI_GUI_GSM_7BIT_LANGUAGE_SET, "[EMS 7Bit] National Language is set to %d")
    TRC_MSG(MMI_GUI_GSM_7BIT_TABLE_SET, "[EMS 7Bit] LOCKING TABLE is set to 0x%x, Single Table is set to 0x%x")
    TRC_MSG(MMI_GUI_GSM_7BIT_MECHANISM_SET, "[EMS 7Bit] TABLE Mechanism is set to %d")
    TRC_MSG(MMI_GUI_GSM_7BIT_TRUNCATE_UCS2, "[EMS 7Bit] 0x%x is truncated")

    /* CTK */
    TRC_MSG(MMI_CTK_SCREEN_GENERAL_ENTRY_FUNC, "[CTK] ctk_screen_general_entry_function() - enter")
    TRC_MSG(MMI_CTK_SCREEN_GENERAL_ENTRY_FUNC_END, "[CTK] ctk_screen_general_entry_function() - end")
    TRC_MSG(MMI_CTK_SCREEN_GENERAL_EXIT_HDLR, "[CTK] ctk_screen_general_exit_handler() - enter")
    TRC_MSG(MMI_CTK_SCREEN_GENERAL_EXIT_HDLR_END, "[CTK] ctk_screen_general_exit_handler() - end")
    TRC_MSG(MMI_CTK_SCREEN_GENERAL_KEY_HDLR, "[CTK] ctk_screen_general_key_handler() - enter")
    TRC_MSG(MMI_CTK_SCREEN_ADD_HIST, "[CTK] ctk_screen_add_history()")
    TRC_MSG(MMI_CTK_SCREEN_CLOSE, "[CTK] ctk_screen_close()")
    TRC_MSG(MMI_CTK_SCREEN_INVOKE_ON_ENTER, "[CTK] ctk_screen_invoke_on_enter()")
    TRC_MSG(MMI_CTK_SCREEN_INVOKE_ON_EXIT, "[CTK] ctk_screen_invoke_on_exit()")
    TRC_MSG(MMI_CTK_SCREEN_INVOKE_REDRAW, "[CTK] ctk_screen_invoke_redraw()")
    TRC_MSG(MMI_CTK_SCREEN_INVOKE_REDRAW_NOT_ACTIVE, "[CTK] ctk_screen_invoke_redraw() - screen not active")
    TRC_MSG(MMI_CTK_SCREEN_ENTER, "[CTK] ctk_screen_enter() - enter")
    TRC_MSG(MMI_CTK_SCREEN_ENTER_END, "[CTK] ctk_screen_enter() - end")
    TRC_MSG(MMI_CTK_SCREEN_REDRAW, "[CTK] ctk_screen_redraw() - enter")
    TRC_MSG(MMI_CTK_SCREEN_REDRAW_NOT_ACTIVE, "[CTK] ctk_screen_redraw() - end - screen not active")
    TRC_MSG(MMI_CTK_SCREEN_REDRAW_END, "[CTK] ctk_screen_redraw() - end - finished")
    TRC_MSG(MMI_CTK_SCREEN_EXIT, "[CTK] ctk_screen_exit() - enter")
    TRC_MSG(MMI_CTK_SCREEN_EXIT_ADD_HIST, "[CTK] ctk_screen_exit() - backup history data and add history")
    TRC_MSG(MMI_CTK_SCREEN_EXIT_NO_IN_HIST, "[CTK] ctk_screen_exit() - backup history data")
    TRC_MSG(MMI_CTK_SCREEN_EXIT_END, "[CTK] ctk_screen_exit() - exit")
    TRC_MSG(MMI_CTK_INLINE_GENERAL_HILITE_HDLR, "[CTK] ctk_inline_general_highlight_handler()")
    TRC_MSG(MMI_CTK_INLINE_GENERAL_CANCEL_HDLR, "[CTK] ctk_inline_general_cancel_handler()")
    TRC_MSG(MMI_CTK_INLINE_SHOW, "[CTK] ctk_inline_show()")
    TRC_MSG(MMI_CTK_INLINE_CLOSE_DISPLAY, "[CTK] ctk_inline_close_display()")
    TRC_MSG(MMI_CTK_PCATEGORY_GENERAL_HILITE_HDLR, "[CTK] ctk_pcategory_general_highlight_handler()")
    TRC_MSG(MMI_CTK_PCATEGORY_SHOW, "[CTK] ctk_pcategory_show(%x)")
    TRC_MSG(MMI_CTK_PCATEGORY_CLOSE_DISPLAY, "[CTK] ctk_pcategory_close_display()")
    
    


    /* Q03C - Widget */
    TRC_MSG(MMI_WIDGET_RELEASE_VIDEO_RAWFILE_ID, "[Widget] widget_image_release() - release video rawfile id")
    TRC_MSG(MMI_WIDGET_WIDGET_VIDEO_NONE, "[Widget] current_video_state is WIDGET_VIDEO_NONE")
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING, "[Widget] HDIa_widgetExtImageResizing() - enter")
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING_TOO_LARGE, "[Widget] HDIa_widgetExtImageResizing() - the original image is too large")
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING_END, "[Widget] HDIa_widgetExtImageResizing() - end : %d")
    TRC_MSG(MMI_WIDGET_OPEN_VIDEO_FILE_DONE_HDLR_FAILED, "[Widget] widget_MMI_open_video_file_done_hdlr() - returns: Failed")
    TRC_MSG(MMI_WIDGET_OPEN_VIDEO_FILE_DONE_HDLR_SUCCEED, "widget_MMI_open_video_file_done_hdlr() - end: Succeeds")
    TRC_MSG(MMI_WIDGET_VIDEO_CREATE_RESOURCE ,"[Widget] HDIa_widgetExtVideoCreateResource()")
    TRC_MSG(MMI_WIDGET_PLAY_VIDEO, "[Widget] HDIa_widgetExtPlayVideo()")
    TRC_MSG(MMI_WIDGET_STOP_VIDEO, "[Widget] HDIa_widgetExtStopVideo()")
    TRC_MSG(MMI_WIDGET_CLOSE_VIDEO_WHEN_FILE_IS_OPENED, "[Widget] HDIa_widgetExtCloseVideo() in video file is opened")
    TRC_MSG(MMI_WIDGET_DISABLE_VIDEO_PLAY, "[Widget] HDIa_widgetExtDisableVideoPlay()")
    TRC_MSG(MMI_WIDGET_ENABLE_VIDEO_PLAY, "[Widget] HDIa_widgetExtEnableVideoPlay()")
    TRC_MSG(MMI_WIDGET_ON_WINDOW_FOCUS_CHANGED, "[Widget] widget_on_window_focus_changed()")
    TRC_MSG(MMI_WIDGET_ON_WINDOW_FOCUS_CHANGED_END, "[Widget] widget_on_window_focus_changed() - end")
    TRC_MSG(MMI_WIDGET_SET_IN_FOCUS_TRUE, "[Widget] HDIa_widgetSetInFocus(1) handle:%x, a:%x")
    TRC_MSG(MMI_WIDGET_SET_POSITION, "[Widget] HDIa_widgetSetPosition() for gadgets of sliding SMIL")
    TRC_MSG(MMI_WIDGET_SET_SIZE, "[Widget] HDIa_widgetSetSize() for gadgets of sliding SMIL")
    TRC_MSG(MMI_WIDGET_WAP_INTERNET_KEY_HDLR, "[Widget] wap_internet_key_hdlr()")
    TRC_MSG(MMI_WIDGET_GOTO_MOBILE_SUITE_SCREEN, "[Widget] goto_mobile_suite_screen()")
    TRC_MSG(MMI_WIDGET_IN_USB_MODE_AND_EXIT, "[Widget] In USB mode - exit")
    TRC_MSG(MMI_WIDGET_GOTO_MMS_SCREEN, "[Widget] goto_mms_screen() - enter")
    TRC_MSG(MMI_WIDGET_GOTO_MMS_SCREEN_AND_MEA_RUNNING, "[Widget] goto_mms_screen() - MEA already running")
    TRC_MSG(MMI_WIDGET_GOTO_MMS_SCREEN_AND_MEA_NOT_RUNNING, "[Widget] goto_mms_screen() - MEA already not running")
    TRC_MSG(MMI_WIDGET_MMS_TEXT_INSERT_HDLR, "[Widget] mms_text_insert_hdlr()")
    TRC_MSG(MMI_WIDGET_MMS_CONTENT_INSERT_HDLR, "[Widget] mms_content_insert_hdlr()")
    TRC_MSG(MMI_WIDGET_MMS_CONTENT_INSERT_HDLR_WITH_CALLBACK, "[Widget] mms_content_insert_hdlr_with_callback()")
    TRC_MSG(MMI_WIDGET_MMS_ADDRESS_INSERT_HDLR, "[Widget] mms_address_insert_hdlr()")
    TRC_MSG(MMI_WIDGET_FORM_UPDATE_FOR_SLIDING_SMIL, "[Widget] widget_form_update_for_sliding_SMIL() - incorrect number of image gadgets")
    TRC_MSG(MMI_WIDGET_HOLD_DRAW_PAINTBOX, "[Widget] HDIa_widgetHoldDraw() - paintbox")
    TRC_MSG(MMI_WIDGET_HOLD_DRAW_IMAGE, "[Widget] HDIa_widgetHoldDraw() - image")
    TRC_MSG(MMI_WIDGET_HOLD_DRAW_UNSUPPORTED, "[Widget] HDIa_widgetHoldDraw() - Unsupported Type")
    TRC_MSG(MMI_WIDGET_PERFORM_DRAW_PAINTBOX, "[Widget] HDIa_widgetPerformDraw() - paintbox ")
    TRC_MSG(MMI_WIDGET_PERFORM_DRAW_IMAGE, "[Widget] HDIa_widgetPerformDraw() - image")
    TRC_MSG(MMI_WIDGET_PERFORM_DRAW_UNSUPPORTED, "[Widget] HDIa_widgetPerformDraw() - Unsupported Type")
    TRC_MSG(MMI_WIDGET_MMI_DRAW_IMAGE_OP, "[Widget] widget_MMI_draw_image() - image containing drawing op")
    TRC_MSG(MMI_WIDGET_MMI_DRAW_IMAGE_IN_PAINTBOX, "[Widget] widget_MMI_draw_image() - simple image drawn in paintbox")
    TRC_MSG(MMI_WIDGET_MMI_DRAW_IMAGE_IN_MSFIMAGE, "[Widget] widget_MMI_draw_image() - simple image drawn in MsfImage")
    TRC_MSG(MMI_WIDGET_DRAW_IMAGE, "[Widget] HDIa_widgetDrawImage()")
    TRC_MSG(MMI_WIDGET_MMI_CTK_LEAVE_SCREEN_IF_PRESENT, "[Widget] widget_MMI_ctk_leave_screen_if_present()")
    TRC_MSG(MMI_WIDGET_MMI_CTK_LEAVE_SCREEN_IF_PRESENT_END, "[Widget] widget_MMI_ctk_leave_screen_if_present() - end")
    TRC_MSG(MMI_WIDGET_MMI_CTK_LEAVE_SCREEN_IF_PRESENT_ENTERED, "[Widget] widget_MMI_ctk_leave_screen_if_present() - WIDGET_CTK_STATE_ENTERED")
    TRC_MSG(MMI_WIDGET_MMI_CTK_LEAVE_SCREEN_IF_PRESENT_PAUSED, "[Widget] widget_MMI_ctk_leave_screen_if_present() - WIDGET_CTK_STATE_PAUSED")
    TRC_MSG(MMI_WIDGET_CTK_LEAVE_IF_PRESENT, "[Widget] widget_ctk_leave_screen_if_present() %d, %d")
    TRC_MSG(MMI_WIDGET_CTK_LEAVE_IF_PRESENT_RETURN_TO_IDLE, "[Widget] widget_ctk_leave_screen_if_present() - returns to idle screen")
    TRC_MSG(MMI_WIDGET_CTK_ON_EXIT, "[Widget] widget_ctk_on_exit()")
    TRC_MSG(MMI_WIDGET_CTK_ON_EXIT_FREE_SCRMEM, "[Widget] mmi_frm_scrmem_free() when leaving SMIL editor screen")
    TRC_MSG(MMI_WIDGET_CTK_ON_EXIT_BACK_TO_WIDGET_SCREEN, "[Widget] widget_ctk_on_exit() - back to widget screen")
    TRC_MSG(MMI_WIDGET_CTK_ON_EXIT_INTERRUPT, "[Widget] widget_ctk_on_exit() - interrupted by MMI")
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_TAKE_WAP_Q_LOCK, "[Widget] widget_ctk_dynamic_list_menu_take_WAP_extq_lock()") 
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_TAKE_WAP_Q_LOCK_END, "[Widget] widget_ctk_dynamic_list_menu_get_WAP_extq_lock() - end")
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GIVE_WAP_Q_LOCK, "[Widget] widget_ctk_dynamic_list_menu_give_WAP_extq_lock() - release mutex")
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_ITEM_HDLR, "[Widget] widget_ctk_dynamic_list_menu_get_item_hdlr()")
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_ITEM_HDLR_INDEX_ERROR, "[Widget] widget_ctk_dynamic_list_menu_get_item_hdlr index<%d, %d> (return 0 directly)")
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_ITEM_HDLR_SHOW_ERROR, "[Widget] widget_ctk_dynamic_list_menu_get_item_hdlr is_shown:%d (return 0 directly)")
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_HINT_HDLR, "[Widget] widget_ctk_dynamic_list_menu_get_hint_hdlr()")
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_HINT_HDLR_INDEX_ERROR, "[Widget] widget_ctk_dynamic_list_menu_get_hint_hdlr index<%d, %d> (return 0 directly)")
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU_GET_HINT_HDLR_STR_ERROR, "[Widget] widget_ctk_dynamic_list_menu_get_hint_hdlr hint is NULL (return 0 directly)")
    TRC_MSG(MMI_WIDGET_CTK_DYNAMIC_LIST_MENU, "[Widget] widget_ctk_show_dynamic_list_menu()")
    TRC_MSG(MMI_WIDGET_UPDATE_LIST_MENU_CALLBACK, "[Widget] HDIa_widgetExtUpdateListMenuByCallback()")
    TRC_MSG(MMI_WIDGET_CTK_SMIL_IMAGE_NB_DRAW_DONE_CALLBACK, "[Widget] widget_ctk_smil_image_nb_draw_done_callback() result:%d")
    TRC_MSG(MMI_WIDGET_CTK_SMIL_IMAGE_NB_DRAW_DONE_CALLBACK_END, "[Widget] widget_ctk_smil_image_nb_draw_done_callback() - end")
    TRC_MSG(MMI_WIDGET_CTK_SHOW_SMIL_EDITOR_SCRMEM_ALLOC, "[Widget] mmi_frm_scrmem_alloc in widget_ctk_show_smil_editor")
    TRC_MSG(MMI_WIDGET_GIVE_CONTROL_TO_MMI, "[Widget] HDIa_widgetExtGiveControlToMMI()")
    TRC_MSG(MMI_WIDGET_MMI_KEY_HANDLER, "[Widget] widget_MMI_key_handler() - enter")
    TRC_MSG(MMI_WIDGET_MMI_KEY_HANDLER_END_WAP_NOT_RUNNING, "[Widget] widget_MMI_key_handler() - end - WAP not running")
    TRC_MSG(MMI_WIDGET_ENQUEUE_KEYPAD_EVENT_END_DROP_KEYEVENT, "[Widget] widget_enqueue_keypad_event() - end - drop key event")
    TRC_MSG(MMI_WIDGET_ENQUEUE_KEYPAD_EVENT_END_TIME_TOO_LONG, "[Widget] widget_enqueue_keypad_event() - end - last keypad takes too much time")
    TRC_MSG(MMI_WIDGET_WAP_MMI_KEY_IND, "[Widget] widget_wap_mmi_key_ind() - enter")
    TRC_MSG(MMI_WIDGET_WAP_MMI_KEY_IND_END_DISCARD_KEY, "[Widget] widget_wap_mmi_key_ind() - discard key !!!")
    TRC_MSG(MMI_WIDGET_WAP_MMI_KEY_IND_PUT_IN_Q, "[Widget] widget_wap_mmi_key_ind() - put indication")
    TRC_MSG(MMI_WIDGET_WAP_MMI_KEY_IND_END_TIME_TOO_LONG, "[Widget] widget_wap_mmi_key_ind() - end - last keypad takes too much time")
    TRC_MSG(MMI_WIDGET_WAP_MMI_KEY_IND_END_Q_EMPTY, "[Widget] widget_wap_mmi_key_ind() - end - queue empty")
    TRC_MSG(MMI_WIDGET_WAP_READY_TO_LEAVE_SCREEN, "[Widget] widget_ready_to_leave_screen() - enter")
    TRC_MSG(MMI_WIDGET_WAP_READY_TO_LEAVE_SCREEN_TRUE, "[Widget] widget_ready_to_leave_screen returns: TRUE")    
    TRC_MSG(MMI_WIDGET_MMI_LEAVE_SCREEN_GOBACK, "[Widget] widget_MMI_leave_screen_goback() - enter")
    TRC_MSG(MMI_WIDGET_MMI_LEAVE_SCREEN_GOBACK_WINDOW_LEFT, "[Widget] widget_MMI_leave_screen_goback() still window left")
    TRC_MSG(MMI_WIDGET_LEAVE_SCREEN_HDLR_WITH_WINDOW, "[Widget] widget_leave_screen_hdlr() but window left")
    TRC_MSG(MMI_WIDGET_LEAVE_SCREEN_HDLR_NOT_IN_WIDGET_SCREEN, "[Widget] widget_leave_screen_hdlr() not in widget screen")
    TRC_MSG(MMI_WIDGET_LEAVE_SCREEN_HDLR, "[Widget] widget_leave_screen_hdlr() start to leave screen")
    TRC_MSG(MMI_WIDGET_PREPARE_TO_LEAVE_SCREEN, "[Widget] widget_prepare_to_leave_screen()")
    TRC_MSG(MMI_WIDGET_MMI_SHUTDOWN_WAP_UI, "[Widget] widget_MMI_shutdown_WAP_UI() - enter")
    TRC_MSG(MMI_WIDGET_MMI_SHUTDOWN_WAP_UI_END, "[Widget] widget_MMI_shutdown_WAP_UI() - end")
    TRC_MSG(MMI_WIDGET_MMI_SHUTDOWN_WAP_WIDGET_UI, "[Widget] widget_MMI_shutdown_WAP_Widget_UI() - enter")
    TRC_MSG(MMI_WIDGET_MMI_SHUTDOWN_WAP_WIDGET_UI_END, "[Widget] widget_MMI_shutdown_WAP_Widget_UI() - end")
    TRC_MSG(MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN, "[Widget] wap_exit_widget_screen() - enter")
    TRC_MSG(MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN_END, "[Widget] wap_exit_widget_screen() - end")
    TRC_MSG(MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN_IN_WIDGET_SCREEN, "[Widget] wap_exit_widget_screen() - WGUI_CTX->is_widget_screen")
    TRC_MSG(MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN_END_TO_LEAVE, "[Widget] wap_exit_widget_screen() - end - ready to leave")
    TRC_MSG(MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN_END_IN_HIST, "[Widget] wap_exit_widget_screen() - end - put into history")
    TRC_MSG(MMI_WIDGET_DEL_WIDGET_SCREEN_IF_PRESENT, "[Widget] HDIa_widgetExtDeleteWidgetScreenIfPresent()")
    TRC_MSG(MMI_WIDGET_REG_SWITCH_WIDGET_SCREEN_CB, "[Widget] HDIa_widgetExtRegisterSwitchWidgetScreenCallback()")
    TRC_MSG(MMI_WAP_DELETE_WIDGET_SCREEN_CB, "[Widget] wap_delete_widget_screen_cb()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN, "[Widget] wap_entry_widget_screen() - enter")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_END_WAP_NOT_RUNNING, "[Widget] wap_entry_widget_screen() - end - WAP not running")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_NO_MSFWINDOW, "[Widget] wap_entry_widget_screen() - no window left")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_NO_MSFWINDOW_2, "[Widget] wap_entry_widget_screen() - no window - previous exit handler executed")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_PREVIOUS_EXIT_HDLE_DONE, "[Widget] wap_entry_widget_screen() - previous exit handler executed")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_WIDGET_SCREEN_END, "[Widget] wap_entry_widget_screen() - end - normal")
    TRC_MSG(MMI_WIDGET_ALLOW_CREATE_NEW_MMI_SCREEN_FAILED_BY_SHUTDOWN, "[Widget] widget_allow_create_new_MMI_screen() - FALSE is shutdown UI ")
    TRC_MSG(MMI_WIDGET_ALLOW_CREATE_NEW_MMI_SCREEN_FAILED_BY_GOTO_IDLE_SCREEN, "[Widget] widget_allow_create_new_MMI_screen() -FALSE in idle screen")
    TRC_MSG(MMI_WIDGET_MMI_GOBACK_TO_WIDGET_SCREEN, "[Widget] widget_MMI_goback_to_widget_screen()")
    TRC_MSG(MMI_WIDGET_GOBACK_TO_WIDGET_SCREEN, "[Widget] widget_goback_to_widget_screen()")
    TRC_MSG(MMI_WIDGET_MMI_GOBACK_TO_WAP_SCREEN_CTK, "[Widget] widget_MMI_goback_to_WAP_screens() - to CTK")
    TRC_MSG(MMI_WIDGET_MMI_GOBACK_TO_WAP_SCREEN_WIDGET, "[Widget] widget_MMI_goback_to_WAP_screens() - to widget")
    TRC_MSG(MMI_WIDGET_MMI_GOBACK_TO_WAP_SCREEN_OTHERS, "[Widget] widget_MMI_goback_to_WAP_screens() - No Window to go")
    TRC_MSG(MMI_WIDGET_GOBACK_TO_WAP_SCREEN, "[Widget] widget_goback_to_WAP_screens()")
    TRC_MSG(MMI_WIDGET_MMI_NOT_READY_GOBACK_HDLR, "[Widget] widget_MMI_not_ready_goback_hdlr()")
    TRC_MSG(MMI_WIDGET_WAP_EXIT_WIDGET_NOT_READY, "[Widget] wap_exit_widget_not_ready()")
    TRC_MSG(MMI_WAP_ENTRY_IMAGE_PRECACHE, "[Widget] wap_entry_image_precache()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_WIDGET_NOT_READY, "[Widget] wap_entry_widget_not_ready()")
    TRC_MSG(MMI_WIDGET_DISPLAY_TRANSITION_ANIMATION_NOT_ALLOW, "[Widget] HDIa_widgetExtDisplayTransitionAnimation() - not allowed")
    TRC_MSG(MMI_WIDGET_DISPLAY_TRANSITION_ANIMATION_ALREADY_EXIST, "[Widget] HDIa_widgetExtDisplayTransitionAnimation() - already exist")
    TRC_MSG(MMI_WIDGET_DISPLAY_TRANSITION_ANIMATION, "[Widget] HDIa_widgetExtDisplayTransitionAnimation()")
    TRC_MSG(MMI_WIDGET_MMI_CLOSE_TRANSITION_ANIMATION, "[Widget] widget_MMI_close_transition_animation()")
    TRC_MSG(MMI_WIDGET_MMI_ON_ENTER_IDLE_SCREEN, "[Widget] widget_MMI_on_enter_idle_screen()")
    TRC_MSG(MMI_WAP_ENTRY_BUSY_PROCESSING_SCREEN, "[Widget] wap_entry_busy_progressing_screen_in_idle()")
    TRC_MSG(MMI_WIDGET_GOTO_IDLE_SCREEN, "[Widget] widget_goto_idlescreen()!!!!")
    TRC_MSG(MMI_WIDGET_GOTO_IDLE_SCREEN_END, "[Widget] widget_goto_idlescreen()!!!! (end)")
    TRC_MSG(MMI_WIDGET_MMS_CONTENT_INSERT_HDLR_WITH_MEA_RUNNING, "[Widget] mms_content_insert_hdlr() - MEA already running")
    TRC_MSG(MMI_WIDGET_MMI_DISPLAY_POPUP, "[Widget] widget_MMI_display_popup() - enter")
    TRC_MSG(MMI_WIDGET_MMI_DISPLAY_POPUP_GOTO_IDLE_SCREEN, "[Widget] widget_MMI_display_popup() - go to idle screen")
    TRC_MSG(MMI_WIDGET_MMI_DISPLAY_POPUP_DIRECTLY, "[Widget] widget_MMI_display_popup() - display popup; flag=%d")
    TRC_MSG(MMI_WIDGET_SHOW_POPUP_EXT_NOT_ALLOW, "[Widget] HDIa_widgetExtShowPopupExt() - cannot create new popup")
    TRC_MSG(MMI_WIDGET_SHOW_POPUP_EXT, "[Widget] HDIa_widgetExtShowPopupExt()")
    TRC_MSG(MMI_WIDGET_SHOW_POPUP, "[Widget] HDIa_widgetExtForcePopup()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_DELETE_ALL_SCREEN, "[Widget] wap_entry_delete_all_screen()")
    TRC_MSG(MMI_WIDGET_LEAVE_DELETE_ALL_SCREEN, "[Widget] widget_leave_delete_all_screen()")
    TRC_MSG(MMI_WIDGET_CONFIG_MMS_ICON, "[Widget] widget_config_mms_icon() statusType:%d, sim_status:%d, setting_mode:%d")
    TRC_MSG(MMI_WIDGET_MMS_SET_INDICATOR_DIRECTLY, "[Widget] mms_set_indicator (directly)")
    TRC_MSG(MMI_WIDGET_MMS_SET_INDICATOR_DIRECTLY_END, "[Widget] mms_set_indicator (directly) (end)")
    TRC_MSG(MMI_WIDGET_MMS_SET_INDICATOR, "[Widget] mms_set_indicator (mmiapi) scrnID:%d, WGUI_CTX->is_painted_after_first_focus_changed:%d")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_FULLSCREEN_EDITOR_OPTION, "[Widget] wap_entry_fullscreen_editor_option()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_WCSS_EDITOR, "[Widget] wap_entry_WCSS_editor()")
    TRC_MSG(MMI_WIDGET_EXIT_FULLSCREEN_EDITOR, "[Widget] widget_exit_fullscreen_editor()")
    TRC_MSG(MMI_WIDGET_MMI_GOBACK_FULLSCREEN_EDITOR, "[Widget] widget_MMI_goback_fullscreen_editor()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_FULLSCREEN_EDITOR, "[Widget] wap_entry_fullscreen_editor()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_FULLSCREEN_RADIO_MENU, "[Widget] wap_entry_fullscreen_radio_menu()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_FULLSCREEN_CHECKBOX_MENU, "[Widget] wap_entry_fullscreen_checkbox_menu()")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_ENTER_MEDIA_INPUT, "[Widget] widget_MMI_fmgr_enter_media_input()")
    TRC_MSG(MMI_WIDGET_FMGR_MEDIA_INPUT_NOT_ALLOW, "[Widget] HDIa_widgetExtFmgrMediaInput() - cannot create new window")
    TRC_MSG(MMI_WIDGET_FMGR_MEDIA_INPUT, "[Widget] HDIa_widgetExtFmgrMediaInput()")
    TRC_MSG(MMI_WIDGET_FMGR_MEDIA_INPUT_ABORT, "[Widget] HDIa_widgetExtFmgrMediaInputAbort()")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_MEDIA_INPUT_DONE_HDLR, "[Widget] widget_MMI_fmgr_media_input_done_hdlr()")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_MEDIA_INPUT_DONE_HDLR_GOBACK_TO_WIDGET_SCREEN, "[Widget] Go back to widget screen from FMGR done hdlr")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_MEDIA_INPUT_DONE_HDLR_GOBACK_HIST, "[Widget] GoBackHistory from FMGR done hdlr")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME, "[Widget] HDIa_widgetExtFmgrGetSaveFileName() - enter")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME_NOT_ALLOW, "[Widget] HDIa_widgetExtFmgrGetSaveFileName() - cannot create new window")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME_DRM, "[Widget] HDIa_widgetExtFmgrGetSaveFileName() - DRM object")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME_END, "[Widget] HDIa_widgetExtFmgrGetSaveFileName() - end")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_GET_SAVE_FILE_NAME_ABORT, "[Widget] HDIa_widgetExtFmgrSaveFileNameAbort()")
    TRC_MSG(MMI_WIDGET_FMGR_CLOSE_GET_SAVE_PATH, "[Widget] widget_fmgr_close_get_save_path()")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_CLOSE_GET_SAVE_FILE_NAME, "[Widget] widget_MMI_fmgr_get_save_filename()")
    TRC_MSG(MMI_WIDGET_FMGR_GET_SAVE_PATH_CALLBACK, "[Widget] widget_fmgr_get_save_path_callback()")
    TRC_MSG(MMI_WIDGET_MMI_FMGR_GET_SAVE_PATH_DONE_HDLR, "[Widget] widget_MMI_fmgr_get_save_path_done_hdlr()")
    TRC_MSG(MMI_WIDGET_MMI_SAVE_NAME_CANCEL, "[Widget] widget_MMI_savename_cancel()")
    TRC_MSG(MMI_WIDGET_MMI_SAVE_NAME_EDITOR_DONE, "[Widget] widget_MMI_savename_editor_done()")
    TRC_MSG(MMI_WIDGET_MMI_SAVE_NAME_EDITOR_DONE_WITH_NULL_FOLDER, "[Widget] filename_folder==NULL in widget_MMI_savename_editor_done")
    TRC_MSG(MMI_WIDGET_MMI_SAVE_NAME_EDITOR_DONE_WITH_INVALID_FOLDER, "[Widget] filename_folder not existed in widget_MMI_savename_editor_done")
    TRC_MSG(MMI_WIDGET_MMI_SAVE_NAME_EDITOR_DONE_WITH_REMOVE_FILE, "[Widget] widget_MMI_savename_editor_done() - remove file")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_SAVE_FILE_NAME_EDITOR_OPTION, "[Widget] wap_entry_save_filename_editor_option()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_SAVE_FILE_NAME_EDITOR, "[Widget] wap_entry_save_filename_editor()")
    TRC_MSG(MMI_WIDGET_MMIAPI_REMOTE_PROC_CALL_REQ, "[Widget] widget_mmiapi_remote_proc_call_req()")
    TRC_MSG(MMI_WIDGET_UNLOCK_MMI_LOCK, "[Widget] To unlock MMI lock")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI, "[Widget] widget_execute_MMI(%x, %d)")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_IN_MMI_TASK, "[Widget] widget_execute_MMI() in MMI task")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_WAIT_WAP_TASK, "[Widget] widget_execute_MMI() - MMI is already waiting WAP")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_UNLOCK_Q_MUTEX, "[Widget] widget_execute_MMI() - unlock extq mutex before send wait event group")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_WAP_BLOCKED, "[Widget] widget_execute_MMI() - WAP blocked for MMI")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_ASYNC, "[Widget] widget_execute_MMI() - async")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP, "[Widget] widget_execute_WAP(%x, %d)")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP_IN_WAP_TASK, "[Widget] widget_execute_WAP() in WAP task")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP_WAIT_MMI_TASK, "[Widget] widget_execute_WAP() - WAP is already waiting MMI")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP_MMI_BLOCKED, "[Widget] widget_execute_WAP() - MMI blocked for WAP")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP_ASYNC, "[Widget] widget_execute_WAP() - async")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_I, "[Widget] widget_execute_MMI_i(%x, %d, %d)")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_I_IN_MMI_TASK, "[Widget] widget_execute_MMI_i() in MMI task")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_I_WAIT_WAP_TASK, "[Widget] widget_execute_MMI_i() - MMI is already waiting WAP")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_I_UNLOCK_Q_MUTEX, "[Widget] widget_execute_MMI_i() - unlock extq mutex before send wait event group")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_I_WAP_BLOCKED, "[Widget] widget_execute_MMI_i() - WAP blocked for MMI")
    TRC_MSG(MMI_WIDGET_EXECUTE_MMI_I_ASYNC, "[Widget] widget_execute_MMI_i() - async")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP_I, "[Widget] [Widget] widget_execute_WAP_i(%x, %d, %d)")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP_I_IN_WAP_TASK, "[Widget] widget_execute_WAP_i() in WAP task")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP_I_WAIT_MMI_TASK, "[Widget] widget_execute_WAP_i() - WAP is already waiting MMI")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP_I_MMI_BLOCKED, "[Widget] widget_execute_WAP_i() - MMI blocked for WAP")
    TRC_MSG(MMI_WIDGET_EXECUTE_WAP_I_ASYNC, "[Widget] widget_execute_WAP_i() - async")
    TRC_MSG(MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE_IN_CALL, "[Widget] widget_play_msg_arrival_tone (SMS_IN_CALL_TONE)")
    TRC_MSG(MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE_DRM_RIGHT_MSG, "[Widget] widget_play_msg_arrival_tone (drm_right)")
    TRC_MSG(MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE_MMS_SIM2, "[Widget] widget_play_msg_arrival_tone (mms sim2)")
    TRC_MSG(MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE_PROV_SIM2, "[Widget] widget_play_msg_arrival_tone (prov sim2)")
    TRC_MSG(MMI_WIDGET_PLAY_MSG_ARRIVAL_TONE, "[Widget] widget_play_msg_arrival_tone (MESSAGE_TONE) mms:%d, text:%d")
    TRC_MSG(MMI_WIDGET_EXIT_WIDGET_MSG_NOTIFICATION_POPUP, "[Widget] exit_widget_msg_notification_popup()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_MSG_NOTIFICATION_POPUP, "[Widget] wap_entry_msg_notification_popup()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_MSG_NOTIFICATION_POPUP_END, "[Widget] wap_entry_msg_notification_popup (end) text:%d")
    TRC_MSG(MMI_WIDGET_MSG_NOTIFY_PUSH, "[Widget] widget_msg_notifiy_push()")
    TRC_MSG(MMI_WIDGET_MSG_NOTIFY_URGENT_SERVICE_LOADING, "[Widget] widget_msg_notifiy_urgent_service_loading()")
    TRC_MSG(MMI_WIDGET_MSG_NOTIFY_URGENT_SERVICE_INDICATION, "[Widget] widget_msg_notifiy_urgent_service_indication()")
    TRC_MSG(MMI_WIDGET_MSG_NOTIFY_PROVISION, "[Widget] widget_msg_notifiy_provision()")
    TRC_MSG(MMI_WIDGET_MSG_NOTIFY_DRM_RIGHT, "[Widget] widget_msg_notifiy_DRM_right()")
    TRC_MSG(MMI_WIDGET_MSG_DISPLAY_OTA_SETTING, "[Widget] widget_msg_display_OTA_setting_msg()")
    TRC_MSG(MMI_WIDGET_MSG_NOTIFY_MMS, "[Widget] widget_msg_notifiy_MMS()")
    TRC_MSG(MMI_WIDGET_MMI_REGISTER_NEW_MSG, "[Widget] widget_MMI_register_new_msg() - enter (%d)")
    TRC_MSG(MMI_WIDGET_MMI_REGISTER_NEW_MSG_GOTO_IDLE_SCREEN, "[Widget] widget_MMI_register_new_msg() - go to idle screen")
    TRC_MSG(MMI_WIDGET_MMI_REGISTER_NEW_MSG_IN_CALL, "[Widget] widget_MMI_register_new_msg() - in call ")
    TRC_MSG(MMI_WIDGET_MMI_REGISTER_NEW_MSG_POPUP_DIRECTLY, "[Widget] widget_MMI_register_new_msg() - display popup ")
    TRC_MSG(MMI_WIDGET_REGISTER_SYSTEM_MSG, "[Widget] HDIa_widgetExtRegisterSystemMsg()- discard the action")
    TRC_MSG(MMI_WIDGET_REGISTER_SYSTEM_MSG_EX, "[Widget] HDIa_widgetExtRegisterSystemMsgEx()- mod:%d, type(org):%d, type(in):%d, cb:0x%x")
    TRC_MSG(MMI_WIDGET_CLEAR_SYSTEM_MSG_EX, "[Widget] HDIa_widgetExtClearSystemMsgEx()- type:%d")
    TRC_MSG(MMI_WIDGET_REGISTER_NEW_PUSH, "[Widget] HDIa_widgetExtRegisterNewPush()")
    TRC_MSG(MMI_WIDGET_REGISTER_URGENT_SERVICE_LOADING, "[Widget] HDIa_widgetExtRegisterUrgentServiceLoading()")
    TRC_MSG(MMI_WIDGET_REGISTER_URGENT_SERVICE_INDICATION, "[Widget] HDIa_widgetExtRegisterUrgentServiceIndication()")
    TRC_MSG(MMI_WIDGET_REGISTER_NEW_PROVISION, "[Widget] HDIa_widgetExtRegisterNewProvision()")
    TRC_MSG(MMI_WIDGET_REGISTER_DRM_RIGHT, "[Widget] HDIa_widgetExtRegisterDRMRightNotification()")
    TRC_MSG(MMI_WIDGET_REGISTER_OTA_SETTING, "[Widget] HDIa_widgetExtRegisterOTASettingMsg()")
    TRC_MSG(MMI_WIDGET_REGISTER_NEW_MMS, "[Widget] HDIa_widgetExtRegisterNewMMS(%d, %d, %d)")
    TRC_MSG(MMI_WIDGET_CLEAR_MMS, "[Widget] HDIa_widgetExtClearMMS()")
    TRC_MSG(MMI_WIDGET_MMI_ON_EXIT_CM, "[Widget] widget_MMI_on_exit_CM() - with pending message")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_WHEN_KEYPAD_LOCK, "[Widget] widget_MMI_check_and_display_new_msg_when_keypad_lock() - enter")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_WHEN_KEYPAD_LOCK_WITH_MSG, "[Widget] widget_MMI_check_and_display_new_msg_when_keypad_lock() - with message")
    TRC_MSG(MMI_WIDGET_ENTRY_DISPLAY_SYSTEM_MSG, "[Widget] wap_entry_display_system_msg ")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_MSG, "[Widget] widget_MMI_check_and_display_new_msg() - ret=%d")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_MSG_NOT_IN_WIDGET_SCREEN, "[Widget] widget_MMI_check_and_display_new_msg() - not in widget screen. return true")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_MSG_REQUEST_TO_DISPLAY_WIDGET_SCREEN, "[Widget] widget_MMI_check_and_display_new_msg() - WAP request MMI to display widget screen")

    TRC_MSG(MMI_WIDGET_PAINT_ACTION_IN_CTK, "[Widget] MsfAction in CTK window")
    TRC_MSG(MMI_WIDGET_STRING_NOT_FOUND, "[Widget] String not found!")
    TRC_MSG(MMI_WIDGET_MMI_PAINT_BLINKING_HDLR, "[Widget] widget_MMI_paint_blinking_hdlr()")
    TRC_MSG(MMI_WIDGET_GENEREAL_KEYBOARD_HANDLER_DROP_KEY, "[Widget] widget_general_keyboard_handler() - Drop key in menu item index selection process")
    TRC_MSG(MMI_WIDGET_FORM_SCROLL_UP_SLIDING_SMIL, "[Widget] widget_form_scroll_up_sliding_SMIL() - incorrect number of gadgets")
    TRC_MSG(MMI_WIDGET_FORM_SCROLL_DOWN_SLIDING_SMIL, "[Widget] widget_form_scroll_down_sliding_SMIL() - incorrect number of gadgets")
    TRC_MSG(MMI_WIDGET_SET_CURRENT_FOCUS_IN_NON_WIDGET_SCREEN, "[Widget] widget_set_current_focus type:%d, level=%d, present=%d, status=%d, shutdown=%d, poweroff=%d")
    TRC_MSG(MMI_WIDGET_PAINT_OBJECT, "[Widget] widget_paint_object()")
    TRC_MSG(MMI_WIDGET_PAINT_OBJECT_PAINTBOX, "[Widget] widget_paint_object() - paintbox")
    TRC_MSG(MMI_WIDGET_PAINT_OBJECT_FORM, "[Widget] widget_paint_object() - form")
    TRC_MSG(MMI_WIDGET_PAINT_OBJECT_EDITOR, "[Widget] widget_paint_object() - editor")
    TRC_MSG(MMI_WIDGET_PAINT_OBJECT_DIALOG, "[Widget] widget_paint_object() - dialog")
    TRC_MSG(MMI_WIDGET_PAINT_OBJECT_MENU, "[Widget] widget_paint_object() - menu")
    TRC_MSG(MMI_WIDGET_PAINT_OBJECT_CTK, "[Widget] widget_paint_object() - CTK")
    TRC_MSG(MMI_WIDGET_PAINT_OUTSIDE_LOOK, "[Widget] widget_paint_outside_look()")
    TRC_MSG(MMI_WIDGET_CLEAR_ALL_HANDLER, "[Widget] widget_clear_all_handler() - enter")
    TRC_MSG(MMI_WIDGET_CLEAR_ALL_HANDLER_END, "[Widget] widget_clear_all_handler() - end")
    TRC_MSG(MMI_WIDGET_PAINT_HDLR, "[Widget] widget_paint_hdlr()")
    TRC_MSG(MMI_WIDGET_PAINTBOX_REDRAW, "[Widget] widget_paintbox_redraw()")
    TRC_MSG(MMI_WIDGET_PAINT, "[Widget] widget_paint()")
    TRC_MSG(MMI_WIDGET_MMI_PAINT_COMMAND_HDLR, "[Widget] widget_MMI_paint_command_hdlr()")
    TRC_MSG(MMI_WIDGET_PAINT_COMMAND_HDLR, "[Widget] widget_paint_command_hdlr()")
    TRC_MSG(MMI_WIDGET_PAINT_SCROLLBAR_IND_HDLR, "[Widget] widget_paint_scrollbar_ind_hdlr()")
    TRC_MSG(MMI_WIDGET_PROCESS_PENDING_PEN_EVENT_H_BAR, "[Widget] widget_process_pending_pen_event() h_bar")
    TRC_MSG(MMI_WIDGET_PROCESS_PENDING_PEN_EVENT_V_BAR, "[Widget] widget_process_pending_pen_event() v_bar")
    TRC_MSG(MMI_WIDGET_MMI_SOUND_PLAY_CALLBACK, "[Widget] widget_MMI_sound_play_callback(%d) %x")
    TRC_MSG(MMI_WIDGET_PLAY_SOUND_FILE, "[Widget] widget_play_sound_file(%x) success")
    TRC_MSG(MMI_WIDGET_PLAY_SOUND_FILE_FAIL, "[Widget] widget_play_sound_file(%x) failed")
    TRC_MSG(MMI_WIDGET_STOP_SOUND_FILE_IF_PRESENT, "[Widget] widget_stop_sound_file_if_present(%x)")
    TRC_MSG(MMI_WIDGET_MMI_SOUND_PAUSE_CALLBACK, "[Widget] widget_MMI_sound_pause_callback(%d) %x")
    TRC_MSG(MMI_WIDGET_PAUSE_SOUND_FILE_IF_PRESENT, "[Widget] widget_pause_sound_file_if_present(%x)")
    TRC_MSG(MMI_WIDGET_RESUME_SOUND_FILE, "[Widget] widget_resume_sound_file(%x)")
    TRC_MSG(MMI_WIDGET_SOUND_PLAY, "[Widget] HDIa_widgetSoundPlay(%x)")
    TRC_MSG(MMI_WIDGET_SOUND_PLAY_IN_WIDGET_SCREEN, "[Widget] HDIa_widgetSoundPlay() in widget_screen (%x, %x)")
    TRC_MSG(MMI_WIDGET_SOUND_PLAY_IN_PENDING_FOR_PLAYING, "[Widget] WSND_CTX->state:WIDGET_SOUND_PENDING_FOR_PLAYING (%x, %x)")
    TRC_MSG(MMI_WIDGET_SOUND_PLAY_IN_PENDING_ON_DISPLAYED, "[Widget] WSND_CTX->state:WIDGET_SOUND_PENDING_ON_DISPLAYED (%x, %x)")
    TRC_MSG(MMI_WIDGET_MMI_SOUND_STOP, "[Widget] widget_MMI_sound_stop(%x)")
    TRC_MSG(MMI_WIDGET_SOUND_STOP, "[Widget] HDIa_widgetSoundStop(%x)")
    TRC_MSG(MMI_WIDGET_RESUME_PENDING_SOUND_ON_DISPLAYED, "[Widget] widget_resume_pending_sound_on_displayed (curr_sound:%x, curr_wnd:%x, state:%d, owner:%x)")
    TRC_MSG(MMI_WIDGET_MMI_SOUND_GET_DURATION_NO_BUFFER, "[Widget] widget_MMI_sound_get_duration() - can't get buffer")
    TRC_MSG(MMI_WIDGET_MMI_SOUND_GET_DURATION, "[Widget] widget_MMI_sound_get_duration(%d)")
    TRC_MSG(MMI_WIDGET_MMI_IMAGE_NB_DRAW_DONE_CALLBACK, "[Widget] widget_MMI_image_nb_draw_done_callback() result:%d")
    TRC_MSG(MMI_WIDGET_STOP_IMAGE_NB_DRAW, "[Widget] widget_stop_image_nb_draw() image:%x")
    TRC_MSG(MMI_WIDGET_MMI_IMAGE_DRAW_FILE, "[Widget] widget_MMI_image_draw_file() is_resized:%d, ret:%d")
    TRC_MSG(MMI_WIDGET_MMI_IMAGE_DRAW, "[Widget] widget_MMI_image_draw() is_resized:%d, ret:%d")
    TRC_MSG(MMI_WIDGET_MMI_PAINT_GIF_ANOMATION_HDLR_END_WRONG_SCREEN, "[Widget] widget_MMI_paint_GIF_animation_hdlr() - !WGUI_CTX->is_widget_screen")
    TRC_MSG(MMI_WIDGET_MMI_PAINT_GIF_ANOMATION_HDLR_END_NO_IMAGE, "[Widget] widget_MMI_paint_GIF_animation_hdlr() - no image to display")
    TRC_MSG(MMI_WIDGET_MMI_PAINT_GIF_ANOMATION_HDLR_END_WRONG_STATE, "[Widget] widget_MMI_paint_GIF_animation_hdlr() - !WGUI_CTX->is_painted")
    TRC_MSG(MMI_WIDGET_MMI_PAINT_GIF_ANOMATION_HDLR, "[Widget] widget_MMI_paint_GIF_animation_hdlr() - start to animate")
    TRC_MSG(MMI_WIDGET_PAINT_GIF_ANOMATION_HDLR_END_WRONG_SCREEN, "[Widget] widget_paint_GIF_animation_hdlr() - !WGUI_CTX->is_widget_screen")
    TRC_MSG(MMI_WIDGET_PAINT_GIF_ANOMATION_HDLR_END_NO_IMAGE, "[Widget] widget_paint_GIF_animation_hdlr() - no image to display")
    TRC_MSG(MMI_WIDGET_GET_TOP_GDI_LAYER, "[Widget] widget_get_video_gdi_layer() - top gdi layer")
    TRC_MSG(MMI_WIDGET_GET_VIDEO_GDI_LAYER, "[Widget] widget_get_video_gdi_layer() - video gdi layer")
    TRC_MSG(MMI_WIDGET_FREE_VIDEO_GDI_LAYER, "[Widget] widget_free_video_gdi_layer()")
    TRC_MSG(MMI_WIDGET_MMI_PREPARE_PLAY_VIDEO_GADGET_FIRST_OPEN, "[Widget] widget_MMI_prepare_play_vido_gadget() - open file first")
    TRC_MSG(MMI_WIDGET_MMI_PREPARE_PLAY_VIDEO_GADGET_DIRECTLY, "[Widget] widget_MMI_prepare_play_vido_gadget() - play directly")
    TRC_MSG(MMI_WIDGET_MMI_PLAY_VIDEO_GADGET, "[Widget] widget_MMI_play_vido_gadget() - enter")
    TRC_MSG(MMI_WIDGET_MMI_SHOW_VIDEO_GADGET_PREVIEW, "[Widget] widget_MMI_show_vido_gadget_preview() - enter")
    TRC_MSG(MMI_WIDGET_PAINT_VIDEO_GADGET_IN_PREVIEW, "[Widget] widget_paint_gadget_image() - video_in_preview")
    TRC_MSG(MMI_WIDGET_PAINT_VIDEO_GADGET_PLAY_VIDEO, "[Widget] widget_paint_gadget_image() - play video")
    TRC_MSG(MMI_WIDGET_MMI_PAINT_MARQUEE_OBJECT, "[Widget] widget_MMI_paint_marquee_object - %d")
    TRC_MSG(MMI_WIDGET_MMI_PAINT_MARQUEE_HDLR, "[Widget] widget_MMI_paint_marquee_hdlr")
    TRC_MSG(MMI_WIDGET_EXT_CACHE_NONBLOCKING_IMAGE, "[Widget] HDIa_widgetExtCacheNonBlockingImage cb:%x")
    TRC_MSG(MMI_WIDGET_EXT_CACHE_NONBLOCKING_IMAGE_RESULT, "[Widget] HDIa_widgetExtCacheNonBlockingImage result:%d")
    TRC_MSG(MMI_WIDGET_CTK_SMIL_FREE_SCRMEM, "[Widget] mmi_frm_scrmem_free when leaving SMIL editor screen")
    TRC_MSG(MMI_WIDGET_CTK_SMIL_ALLOC_SCRMEM, "[Widget] mmi_frm_scrmem_alloc in widget_ctk_show_smil_editor")
    TRC_MSG(MMI_WIDGET_INIT_CTK, "[Widget] widget_init_ctk() widget_ctk_appid:0x%x")
    TRC_MSG(MMI_WIDGET_DEINIT_CTK, "[Widget] widget_deinit_ctk() widget_ctk_appid:0x%x")
    TRC_MSG(MMI_WIDGET_PAINT_CTK, "[Widget] widget_paint_ctk widget_current_ctk:0x%x (End)")
    TRC_MSG(MMI_WIDGET_CTK_SMIL_EDITOR_CACHE_IMAGE, "[Widget] widget_ctk_smil_editor_cache_image()")
    TRC_MSG(MMI_WIDGET_CTK_SMIL_EDITOR_CACHE_IMAGE_FREE_LAYER, "[Widget] Free g_widget_ctk_se_image_cache_layer (is_nb_drawing == FALSE)")
    TRC_MSG(MMI_WIDGET_EXT_SMIL_EDITOR_CACHE_NONBLOCKING_IMAGE, "[Widget] HDIa_widgetExtSmilEditorCacheNonBlockingImage()")
    TRC_MSG(MMI_WIDGET_EXT_SMIL_EDITOR_CACHE_NONBLOCKING_IMAGE_RETURN, "[Widget] HDIa_widgetExtSmilEditorCacheNonBlockingImage() state:%d")

    
   
   
    /* Catcher logs activity by ankit */
    TRC_MSG(MMI_WIDGET_MMI_PLAY_VIDEO_GADGET_FINISH_HDLR, "[Widget] widget_MMI_play_video_gadget - enter: %d") 
    TRC_MSG(MMI_WIDGET_MDI_RESULT, "[Widget] MDI API result : %d")
    TRC_MSG(MMI_WIDGET_MMI_PREPARE_PLAY_VIDEO_GADGET, "[Widget] widget_MMI_prepare_play_vido_gadget() - enter")
    TRC_MSG(MMI_WIDGET_MMI_PREPARE_PLAY_VIDEO_GADGET_END, "[Widget] widget_MMI_prepare_play_vido_gadget() - end")
    TRC_MSG(MMI_WIDGET_VIDEO_STATE_READY_TO_PLAY, "[Widget] WGUI_CTX->current_video_state == WIDGET_VIDEO_READY_TO_PLAY")    
    TRC_MSG(MMI_WIDGET_VIDEO_STATE_PLAYING, "[Widget] WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING")    
    TRC_MSG(MMI_WIDGET_VIDEO_STATE_OPENED_WAIT_PLAY, "[Widget] WGUI_CTX->current_video_state == WIDGET_VIDEO_OPENED_WAIT_PLAY")    
    TRC_MSG(MMI_WIDGET_VIDEO_STATE_PLAYING_OUT_OF_LCD, "[Widget] WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD")
    TRC_MSG(MMI_WIDGET_MDI_VIDEO_PLAY_SUCCEED, "[Widget] mdi_video_ply_open_clip_file succeeds in playing video")    
    TRC_MSG(MMI_WIDGET_CHECK_IN_PLAYING_VIDEO_TRUE, "[Widget] widget_check_in_playing_video returns true")
    TRC_MSG(MMI_WIDGET_CHECK_IN_PLAYING_VIDEO_FALSE, "[Widget] widget_check_in_playing_video returns false")    
    TRC_MSG(MMI_WIDGET_PAINT_GADGET_IMAGE, "[Widget] widget_paint_gadget_image() - enter")
    TRC_MSG(MMI_WIDGET_PAINT_GADGET_IMAGE_END, "[Widget] widget_paint_gadget_image() - end")        
    TRC_MSG(MMI_WIDGET_PAINT_GADGET_IMAGE_RETURNS_SIZE, "[Widget] widget_paint_gadget_image returns: error in size")    
    TRC_MSG(MMI_WIDGET_GADGET_IMAGE_IS_VIDEO, "[Widget] Image gadget is video")    
    TRC_MSG(MMI_WIDGET_VIDEO_COORDINATE_CHANGED, "[Widget] video coordinate changed: operate the video")      
    TRC_MSG(MMI_WIDGET_ENQUEUE_MARQUEE, "[Widget] widget_enqueue_marquee() - enter")   
    TRC_MSG(MMI_WIDGET_ENQUEUE_MARQUEE_FALSE, "[Widget] widget_enqueue_marquee returns: false")
    TRC_MSG(MMI_WIDGET_DEQUEUE_MARQUEE, "[Widget] widget_dequeue_marquee() - enter")    
    TRC_MSG(MMI_WIDGET_DEQUEUE_MARQUEE_FALSE, "[Widget] widget_dequeue_marquee returns: false")    
    TRC_MSG(MMI_WIDGET_HAS_MARQUEE_DISPLAYED, "[Widget] widget_has_marquee_displayed() - enter")
    TRC_MSG(MMI_WIDGET_HAS_MARQUEE_DISPLAYED_FALSE, "[Widget] widget_has_marquee_displayed returns: false")
    TRC_MSG(MMI_WIDGET_PAINT_MARQUEE_OBJECT, "[Widget] widget_MMI_paint_marquee_object() - enter")
    TRC_MSG(MMI_WIDGET_PAINT_MARQUEE_OBJECT_RETURNS, "[Widget] widget_MMI_paint_marquee_object returns")
    TRC_MSG(MMI_WIDGET_PAINT_MARQUEE_OBJECT_END, "[Widget] widget_MMI_paint_marquee_object() - end")
    TRC_MSG(MMI_WIDGET_MMI_PAINT_MARQUEE_HDLR_RETURNS, "[Widget] widget_MMI_paint_marquee_hdlr returns")     
    TRC_MSG(MMI_WIDGET_MMI_PAINT_MARQUEE_HDLR_END, "[Widget] widget_MMI_paint_marquee_hdlr() - end")
    TRC_MSG(MMI_WIDGET_PAINT_MARQUEE_HDLR, "[Widget] widget_paint_marquee_hdlr() - enter")
    TRC_MSG(MMI_WIDGET_PAINT_MARQUEE_HDLR_END, "[Widget] widget_paint_marquee_hdlr() - end")
    TRC_MSG(MMI_WIDGET_PAINT_MARQUEE_HDLR_RETURNS, "[Widget] widget_paint_marquee_hdlr returns")
    TRC_MSG(MMI_WIDGET_START_MARQUEE_ANIMATION, "[Widget] widget_start_marquee_animation() - enter")
    TRC_MSG(MMI_WIDGET_STOP_MARQUEE_ANIMATION, "[Widget] widget_stop_marquee_animation()")
    TRC_MSG(MMI_WIDGET_SETUP_MARQUEE, "[Widget] widget_setup_marquee()")
    TRC_MSG(MMI_WIDGET_FREE_MARQUEE_ELEMENTS, "[Widget] HDIa_widgetExtFreeMarqueeElements()")
    TRC_MSG(MMI_WIDGET_STOP_ALL_MARQUEE, "[Widget] widget_stop_all_marquee()")
    TRC_MSG(MMI_WIDGET_REMOVE_MARQUEE, "[Widget] widget_remove_marquee()")
    TRC_MSG(MMI_WIDGET_HDIA_SET_MARQUEE, "[Widget] HDIa_widgetSetMarquee() - enter")
    TRC_MSG(MMI_WIDGET_HDIA_SET_MARQUEE_END, "[Widget] HDIa_widgetSetMarquee() - end")
    TRC_MSG(MMI_WIDGET_PRECACHE_IMAGE_RESET_IMAGE_DATA, "[Widget] widget_precache_image_reset_image_data()")
    TRC_MSG(MMI_WIDGET_PRECACHE_IMAGE_RESET_LAYER_DATA, "[Widget] widget_precache_image_reset_layer_data()")    
    TRC_MSG(MMI_WIDGET_INIT_PRECACHE_IMAGE, "[Widget] widget_init_precache_image()")
    TRC_MSG(MMI_WIDGET_DEINIT_PRECACHE_IMAGE, "[Widget] widget_deinit_precache_image()")
    TRC_MSG(MMI_WIDGET_FREE_PRECACHE_IMAGE_IF_ANY, "[Widget] widget_MMI_free_precached_image_if_any()")
    TRC_MSG(MMI_WIDGET_PRECACHE_IMAGE_RESET_ALL, "[Widget] widget_precache_image_reset_all()")
    TRC_MSG(MMI_WIDGET_RESET_PRECACHE_IMAGE_BY_IMAGE, "[Widget] widget_reset_precached_image_by_image()")
    TRC_MSG(MMI_WIDGET_PRECACHE_NB_IMAGE_STATE_NONE, "[Widget] WGUI_CTX->precache_nb_image_state = WIDGET_PRECACHE_NB_IMAEG_NONE")
    TRC_MSG(MMI_WIDGET_PREPARE_PRECACHE_IMAGE, "[Widget] widget_MMI_prepare_precache_image() - enter")
    TRC_MSG(MMI_WIDGET_PREPARE_PRECACHE_IMAGE_END, "[Widget] widget_MMI_prepare_precache_image() - end")
    TRC_MSG(MMI_WIDGET_FINISH_PRECACHE_IMAGE, "[Widget] widget_MMI_finish_precache_image() - enter")
    TRC_MSG(MMI_WIDGET_FINISH_PRECACHE_IMAGE_END, "[Widget] widget_MMI_finish_precache_image() - end")
    TRC_MSG(MMI_WIDGET_IS_IMAGE_PRECACHED, "[Widget] widget_image_is_precached() - enter")
    TRC_MSG(MMI_WIDGET_IS_IMAGE_PRECACHED_END, "[Widget] widget_image_is_precached() - end")
    TRC_MSG(MMI_WIDGET_SHOW_PRECACHED_IMAGE, "[Widget] widget_MMI_show_precached_image() - enter")
    
    /* General Return Traces */
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN, "[Widget] Function returns")
    TRC_MSG(MMI_WIDGET_GENERAL_DEFAULT_CASE, "[Widget] Function: Control goes into default case")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_VALUE, "[Widget] Function returns: %d")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_0, "[Widget] Function returns 0")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_1, "[Widget] Function returns 1")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_MINUS1, "[Widget] Function returns -1")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_ERROR, "[Widget] Function returns error")
    TRC_MSG(MMI_WIDGET_GENERAL_ERROR_OCCURED, "[Widget] Some Error occured")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_EMPTY, "[Widget] Function returns: empty")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_FULL, "[Widget] Function returns: full")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_BROKEN, "[Widget] Function returns: broken")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_SIZE, "[Widget] Function returns due to error in size")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_STATE, "[Widget] Function returns due to error in state")
    TRC_MSG(MMI_WIDGET_GENERAL_RETURN_IMAGE_LARGE, "[Widget] Function returns due to large image")
    TRC_MSG(MMI_WIDGET_GENERAL_IN_CHECK1, "[Widget] Control goes inside check 1")
    TRC_MSG(MMI_WIDGET_NOT_WIDGET_SCREEN, "[Widget] Function returns: !WGUI_CTX->is_widget_screen") 
    TRC_MSG(MMI_WIDGET_IS_ENETRING_WIDGET_SCREEN, "[Widget] Function returns: WGUI_CTX->is_entering_widget_screen") 
    TRC_MSG(MMI_WIDGET_GENERAL_IMAGE_OUT_OF_REGION, "[Widget] Image out of region => returns") 
    TRC_MSG(MMI_WIDGET_WIDGET_CALLS_GOBACKHISTORY, "[Widget] Widget calls GoBackHistory()")
    TRC_MSG(MMI_WIDGET_WIDGET_CALLS_GOBACKNHISTORY, "[Widget] Widget calls GoBacknHistory()")
    TRC_MSG(MMI_WIDGET_WIDGET_CALLS_DELETE_SCREEN_IF_PRESENT, "[Widget] Widget calls DeleteScreenIfPresent(): %d")
    TRC_MSG(MMI_WIDGET_RETURNS_IN_WAP_CALL, "[Widget] Function returns: In WAP call") 
    TRC_MSG(MMI_WIDGET_RETURNS_WAP_NOT_RUNNING, "[Widget] Function returns: !WIDGET_IS_WAP_RUNNING")
    TRC_MSG(MMI_WIDGET_RETURNS_POWER_OFF_PERIOD, "[Widget] Function returns: mmi_shutdown_is_in_power_off_period returns true")
    TRC_MSG(MMI_WIDGET_RETURN_EMPTY_INBOX, "[Widget] Function returns: Inbox empty")
    TRC_MSG(MMI_WIDGET_CHECK_IF_CONDITION, "[Widget] IF Condtion : TRUE")
    TRC_MSG(MMI_WIDGET_RETURNS_WAP_NOT_READY, "[Widget] Function returns: WAP not ready") 
    TRC_MSG(MMI_WIDGET_GDI_ERROR, "[Widget] Error: GDI - %d")
    TRC_MSG(MMI_WIDGET_MDI_ERROR, "[Widget] Error: MDI - %d")
    TRC_MSG(MMI_WIDGET_DIMENSION_ERROR, "[Widget] Error: Dimension - width = %d, height = %d")
    TRC_MSG(MMI_WIDGET_UNKNOWN_ERROR, "[Widget] Error: Unknown")
    TRC_MSG(MMI_WIDGET_RETURN_NO_SUPPORT, "[Widget] Function returns: No support")
    TRC_MSG(MMI_WIDGET_INFO_DO_NOTHING, "[Widget] Info: Do nothing")
    
    
    /* File */
    TRC_MSG(MMI_WIDGET_WRITE_CONTENT_IN_FILE_FAILED, "[Widget] Failed: To write content in file")
    TRC_MSG(MMI_WIDGET_ERROR_READ_FILE, "[Widget] Error: Reading a file")
    TRC_MSG(MMI_WIDGET_ERROR_OPEN_FILE, "[Widget] Error: Opening a file")
    TRC_MSG(MMI_WIDGET_ERROR_END_OF_FILE, "[Widget] Error: End of file")
    TRC_MSG(MMI_WIDGET_ERROR_INVALID_FILE, "[Widget] Function returns error: Invalid File")
    TRC_MSG(MMI_WIDGET_HDIA_FILE_READ, "[Widget] HDIa_fileRead() returns %x")   
    TRC_MSG(MMI_WIDGET_HDIA_FILE_CLOSE, "[Widget] HDIa_fileClose()")
    TRC_MSG(MMI_WIDGET_HDIA_FILE_READ_ERROR_DELAYED, "[Widget] HDIa_fileRead() returns HDI_FILE_ERROR_DELAYED")
    TRC_MSG(MMI_WIDGET_RETURN_WIDGET_WAIT_SELECT, "[Widget] Function returns: WIDGET_WAIT_SELECT")
    TRC_MSG(MMI_WIDGET_RETURN_WIDGET_READ_ERROR, "[Widget] Function returns: returns WIDGET_READ_ERROR")
    TRC_MSG(MMI_WIDGET_RETURN_WIDGET_READ_FINISH, "[Widget] Function returns: returns WIDGET_READ_FINISH")
    

    /* Pipe */
    
    TRC_MSG(MMI_WIDGET_WRITE_CONTENT_IN_PIPE_FAILED, "[Widget] Failed: To write content in Pipe")
    
   

    /* Info */
    TRC_MSG(MMI_WIDGET_INFO_OPEN_FILE_SUCCESS, "[Widget] Info: Opening file success")
    TRC_MSG(MMI_WIDGET_INFO_SOURCE_IS_DRM, "[Widget] Info: Source is DRM")
    TRC_MSG(MMI_WIDGET_INFO_SOURCE_IS_PIPE, "[Widget] Info: Source is MsfResourcePipe")
    TRC_MSG(MMI_WIDGET_INFO_SOURCE_IS_FILE, "[Widget] Info: Source is MsfResourceFile")
    TRC_MSG(MMI_WIDGET_INFO_SOURCE_IS_BUFFER, "[Widget] Info: Source is MsfResourceBuffer")
    TRC_MSG(MMI_WIDGET_INFO_SOURCE_IS_PARTIALFILE, "[Widget] Info: Source is MsfResourcePartialFile")
    TRC_MSG(MMI_WIDGET_INFO_SOURCE_IS_VIDEO, "[Widget] Info: Source is VIDEO")
    TRC_MSG(MMI_WIDGET_INFO_SOURCE_IS_IMAGE, "[Widget] Info: Source is IMAGE")   
    
    TRC_MSG(MMI_WIDGET_TRY_TO_CREATE_1VIDEO_RESOURCE, "[Widget] Info: Try to create 1st video resource")
    TRC_MSG(MMI_WIDGET_TRY_TO_CREATE_2VIDEO_RESOURCE, "[Widget] Info: Try to create 2nd video resource")
  

    /*mobile_suite_app.c*/
    TRC_MSG(MMI_WIDGET_INIT_KEY_QUEUE, "[Widget] widget_init_key_queue()")
    TRC_MSG(MMI_WIDGET_INSERT_KEY_QUEUE, "[Widget] widget_insert_key_queue(): %d")
    TRC_MSG(MMI_WIDGET_KEY_DROPPED_QUEUE_FULL, "[Widget] Key dropped : queue full returns false")
    TRC_MSG(MMI_WIDGET_GET_KEY_QUEUE, "[Widget] widget_get_key_queue returns: %d")
    TRC_MSG(MMI_WIDGET_PUT_KEY_IND_IN_EXT_QUEUE, "[Widget] widget_put_key_indication_in_ext_q()")
    TRC_MSG(MMI_WIDGET_PUT_KEY_UP_EVENT_IN_EXT_QUEUE, "[Widget] widget_put_key_up_event_in_ext_q() : %d")
    TRC_MSG(MMI_WIDGET_ENQUEUE_KEYPAD_EVENT, "[Widget] widget_enqueue_keypad_event() : %d %d")
    TRC_MSG(MMI_WIDGET_KEY_EVENT_DOWN_NOT_PROCESSED, "[Widget] Function returns: KEY_EVENT_DOWN is not processed")
    TRC_MSG(MMI_WIDGET_RETURN_KEY_OTHER_THAN_REPEAT_LONG_PRESS_NAVIGATION, "[Widget] Function returns: For navigation keys: only repeat and long press ")
    TRC_MSG(MMI_WIDGET_RETURN_KEY_FREQUENCY_MORE, "[Widget] Function returns: Key dropped due to high frequency")
    TRC_MSG(MMI_WIDGET_RETURN_KEY_DROPPED_REPEAT_EVENT, "[Widget] Function returns: key dropped due to repeat event")
    TRC_MSG(MMI_WIDGET_HDIA_SIMULATE_END, "[Widget] HDIa_widgetExtSimulateSEND()")    
    TRC_MSG(MMI_WIDGET_NOTIFY_SHUTDOWN_UI_FINISHED, "[Widget] widget_notify_shutdown_UI_finished()")
    TRC_MSG(MMI_WIDGET_EXIT_DUMMY_WIDGET_SCREEN, "[Widget] wap_exit_dummy_widget_screen()")
    TRC_MSG(MMI_WIDGET_ENTRY_NEW_SCREEN_WITH_CHECK, "[Widget] widget_MMI_entry_new_screen_with_check()")
    TRC_MSG(MMI_WIDGET_DELETE_WIDGET_SCREEN_CB, "[Widget] wap_delete_widget_screen_cb()")
    TRC_MSG(MMI_WIDGET_SEND_BROWSER_SHUTDOWN_REQ, "[Widget] Widget sends ILM: MSG_ID_WAP_BROWSER_SHUTDOWN_REQ")
    TRC_MSG(MMI_WIDGET_ALLOW_CREATE_NEW_MMI_SCREEN_TRUE, "[Widget] widget_allow_create_new_MMI_screen() returns: TRUE")
    TRC_MSG(MMI_WIDGET_MMI_GOBACK_TO_WAP_SCREEN, "[Widget] widget_MMI_goback_to_WAP_screens()")
    TRC_MSG(MMI_WIDGET_HDIA_DELETE_EDITOR_SCREENS, "[Widget] HDIa_widgetExtWAPDeleteEditorScreens()")
    TRC_MSG(MMI_WIDGET_HDIA_STOP_DIALOG_TONE, "[Widget] HDIa_widgetExtStopDialogTone()")
    TRC_MSG(MMI_WIDGET_HDIA_MMI_DELETE_EDITOR_SCREENS, "[Widget] widget_MMI_delete_editor_screens()")
    TRC_MSG(MMI_WIDGET_MMI_STOP_DIALOG_TONE, "[Widget] widget_MMI_stop_dialog_tone_if_present()")
    TRC_MSG(MMI_WIDGET_MMI_REFRESH_SCREEN, "[Widget] widget_MMI_refresh_screen()")
    TRC_MSG(MMI_WIDGET_MMI_UCM_CALL_STATUS_CB, "[Widget] mmi_widget_ucm_call_status_cb()")
    TRC_MSG(MMI_WIDGET_MMI_UCM_CALLBACK, "[Widget] mmi_widget_ucm_call_back()")
    TRC_MSG(MMI_WIDGET_MMI_NMGR_NOTIFY, "[Widget] mmi_nmgr_notify() returns: %d")
    TRC_MSG(MMI_WIDGET_NEW_MMS_HANDLE_NOTIFICATION, "[Widget] mmi_widget_new_mms_handle_notification()")
    TRC_MSG(MMI_WIDGET_NMGR_MMS_CANCEL, "[Widget] mmi_nmgr_widget_mms_cancel()")
    TRC_MSG(MMI_WIDGET_NMGR_MMS_QUERY, "[Widget] mmi_nmgr_widget_mms_query()")
    TRC_MSG(MMI_WIDGET_NMGR_WAP_MMS_GET_INFO_RSP, "[Widget] mmi_nmgr_wap_mms_get_info_rsp()")
    TRC_MSG(MMI_WIDGET_HDIA_DISPLAY_WAP_TRANSITION_ANIM, "[Widget] HDIa_widgetExtDisplayWAPTransitionAnimation()")
    TRC_MSG(MMI_WIDGET_HDIA_CLOSE_WAP_TRANSITION_ANIM, "[Widget] HDIa_widgetExtCloseWAPTransitionAnimation()")
    TRC_MSG(MMI_WIDGET_MMI_CLOSE_WAP_TRANSITION_ANIM, "[Widget] widget_MMI_close_wap_transition_animation()")
    TRC_MSG(MMI_WIDGET_WAP_ENTRY_WAP_TRANSITION_ANIM, "[Widget] wap_entry_wap_transition_animation()")    
    TRC_MSG(MMI_WIDGET_IS_PAINTBOX_ON_TOP_TRUE, "[Widget] widget_is_paintbox_on_top() retuens: TRUE")
    TRC_MSG(MMI_WIDGET_IS_PAINTBOX_ON_TOP_FALSE, "[Widget] widget_is_paintbox_on_top( returns: FALSE)")
    TRC_MSG(MMI_WIDGET_DEREGISTER_PAINTBOX_ON_TOP, "[Widget] widget_deregister_paintbox_on_top_callback()")
    TRC_MSG(MMI_WIDGET_REGISTER_PAINTBOX_ON_TOP_CB	, "[Widget] widget_register_paintbox_on_top_callback()")
    TRC_MSG(MMI_WIDGET_ASM_WAP_DEINIT, "[Widget] widget_asm_wap_deinit()")
    TRC_MSG(MMI_WIDGET_HDIA_ASM_INIT, "[Widget] HDIa_widgetExtASMInit()")
    TRC_MSG(MMI_WIDGET_DEREGISTER_ASM_CALLBACK, "[Widget] widget_deregister_callback() : ASM")
    TRC_MSG(MMI_WIDGET_REGISTER_ASM_CALLBACK, "[Widget] widget_internal_success_callback() : register ASM callback")
    TRC_MSG(MMI_WIDGET_ASM_POOL_INIT_HANDLER, "[Widget] widget_wap_asm_pool_init_handler()")
    TRC_MSG(MMI_WIDGET_IS_PAINTBOX_FOCUSSED_TRUE, "[Widget] widget_is_paintbox_focused() returns: TRUE")
    TRC_MSG(MMI_WIDGET_IS_PAINTBOX_FOCUSSED_FALSE, "[Widget] widget_is_paintbox_focused() returns: FALSE")
    TRC_MSG(MMI_WIDGET_HDIA_SUSPEND_PROCESS_KEY, "[Widget] HDIa_widgetExtSuspendProcessKey()")
    TRC_MSG(MMI_WIDGET_WAIT_MSG_NOTIF_IN_IDLE_SCREEN_TRUE, "[Widget] HDIa_widgetExtIsWaitingMessageNotificationInIdleScreen() returns: TRUE")
    TRC_MSG(MMI_WIDGET_WAIT_MSG_NOTIF_IN_IDLE_SCREEN_FALSE, "[Widget] HDIa_widgetExtIsWaitingMessageNotificationInIdleScreen() returns: FALSE")
    TRC_MSG(MMI_WIDGET_CHECK_MSG_IN_IDLE_SCREEN, "[Widget] widget_check_msg_in_idle_screen()")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG, "[Widget] widget_MMI_check_and_display_new_msg() - enter")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_RETURNS, "[Widget] widget_MMI_check_and_display_new_msg() returns")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_END, "[Widget] widget_MMI_check_and_display_new_msg() - end")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_RETURNS_HAS_SYSTEM_MSG, "[Widget] widget_MMI_check_and_display_new_msg() returns: has system msg")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_RETURNS_HAS_PUSH, "[Widget] widget_MMI_check_and_display_new_msg() returns: has Push")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_RETURNS_HAS_MMS, "[Widget] widget_MMI_check_and_display_new_msg() returns: has MMS")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_HAS_SL_HIGH, "[Widget] widget_MMI_check_and_display_new_msg() - has SL High")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_HAS_SI_HIGH, "[Widget] widget_MMI_check_and_display_new_msg() - has SI High")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_RETURNS_HAS_DRM_RIGHT, "[Widget] widget_MMI_check_and_display_new_msg() returns: has DRM Right")
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_HAS_PROVISION, "[Widget] widget_MMI_check_and_display_new_msg() - has Provision")
    TRC_MSG(MMI_WIDGET_END_KEY_FROM_SYSTEM_MSG, "[Widget] widget_end_key_from_system_msg() affects WNOTI_CTX & calls DisplayIdleScreen")
    TRC_MSG(MMI_WIDGET_GO_BACK_FROM_SYSTEM_MSG, "[Widget] widget_go_back_from_system_msg() affects WNOTI_CTX and calls GoBackHistory")
    TRC_MSG(MMI_WIDGET_HDIA_GET_MMS_ID, "[Widget] HDIa_widgetExtGetMMSMessageID()")
    TRC_MSG(MMI_WIDGET_HDIA_CLEAR_DRM_NOTIF, "[Widget] HDIa_widgetExtClearDRMRightNotification()")
    TRC_MSG(MMI_WIDGET_HDIA_CLEAR_PROVISION, "[Widget] HDIa_widgetExtClearProvision()")
    TRC_MSG(MMI_WIDGET_HDIA_CLEAR_PUSH, "[Widget] HDIa_widgetExtClearPush()")
    TRC_MSG(MMI_WIDGET_CLEAR_SERVICE_INDICATION, "[Widget] HDIa_widgetExtClearUrgentServiceIndication()")
    TRC_MSG(MMI_WIDGET_CLEAR_SERVICE_LOADING, "[Widget] HDIa_widgetExtClearUrgentServiceLoading()")
    
    /*widget_image */
    
    
    TRC_MSG(WIDGET_IMAGE_GET_PICTOGRAM_HANDLE, "[Widget] widget_image_get_pictogram_handle()")
    TRC_MSG(WIDGET_HDIA_MSF_TO_MMI_IMAGE_FORMAT, "[Widget] HDIa_widgetExtMsfToMMIImageFormat()")
    TRC_MSG(WIDGET_INIT_RAWFILE, "[Widget] widget_init_rawfile()")
    TRC_MSG(WIDGET_DEINIT_RAWFILE, "[Widget] widget_deinit_rawfile()")
    TRC_MSG(WIDGET_RAWFILE_ALLOW_TO_CREATE_IMAGE, "[Widget] widget_rawfile_allow_to_create_image()")
    TRC_MSG(WIDGET_RAWFILE_ALLOW_TO_CREATE_SOUND, "[Widget] widget_rawfile_allow_to_create_sound()")
    TRC_MSG(WIDGET_RAWFILE_GEN_VIRTUAL_FILE, "[Widget] widget_rawfile_gen_virtual_file()")
    TRC_MSG(WIDGET_OPEN_CHECK_ORIG_FILE_FOR_VIRTUAL_FILE, "[Widget] widget_open_check_original_file_for_virtual_file()")
    TRC_MSG(MMI_WIDGET_RAWFILE_REGISTER, "[Widget] widget_rawfile_register()")
    TRC_MSG(MMI_WIDGET_RAWFILE_DEREGISTER, "[Widget] widget_rawfile_deregister()")
    TRC_MSG(MMI_WIDGET_RAWFILE_GETNAME, "[Widget] widget_rawfile_getname()")
    TRC_MSG(WIDGET_RAWFILE_WRITE_FAILED, "[Widget] widget_rawfile_write_failed()")
    TRC_MSG(WIDGET_RAWFILE_WRITE, "[Widget] widget_rawfile_write()")
    TRC_MSG(MMI_WIDGET_RAWFILE_CONFIGURE_FORMAT, "[Widget] widget_rawfile_configure_format()")
    TRC_MSG(MMI_WIDGET_GET_PREIMAGE_DATA, "[Widget] widget_get_pre_image_data()")
    TRC_MSG(MMI_WIDGET_IMAGE_FORMAT, "[Widget] widget_image_format()")
    TRC_MSG(MMI_WIDGET_IS_IMAGE_READY, "[Widget] widget_image_is_ready()")
    TRC_MSG(MMI_WIDGET_IMAGE_RESID, "[Widget] widget_image_resid()")
    TRC_MSG(MMI_WIDGET_IMAGE_WIDTH, "[Widget] widget_image_width()")
    TRC_MSG(MMI_WIDGET_IMAGE_HEIGHT, "[Widget] widget_image_heigth()")   
    TRC_MSG(MMI_WIDGET_IMAGE_CONTENT, "[Widget] widget_image_content()")
    TRC_MSG(MMI_WIDGET_IMAGE_DIMENSION, "[Widget] widget_image_dimension()")
    TRC_MSG(MMI_WIDGET_IMAGE_CONTENT_FILE, "[Widget] widget_image_content_file()")
    TRC_MSG(MMI_WIDGET_IMAGE_LENGTH, "[Widget] widget_image_length()")
    TRC_MSG(MMI_WIDGET_IMAGE_FRAME_COUNT, "[Widget] widget_image_frame_count()")
    TRC_MSG(MMI_WIDGET_IMAGE_CHECK_FORMAT, "[Widget] widget_image_check_format()")
    TRC_MSG(MMI_WIDGET_IMAGE_AUTO_DETECT_FORMAT, "[Widget] widget_image_auto_detect_format()")
    TRC_MSG(MMI_WIDGET_IMAGE_SET_DONE, "[Widget] widget_image_set_done()")    
    TRC_MSG(MMI_WIDGET_IMAGE_IS_VALID_DIMENSION, "[Widget] widget_image_set_done(): is_valid_dimension = %d")
    TRC_MSG(MMI_WIDGET_IMAGE_FMGR_CHECK, "[Widget] widget_image_set_done(): FMGR check failed")
    TRC_MSG(MMI_WIDGET_IMAGE_SET_DONE_RETURNS, "[Widget] widget_image_set_done(): returns %d")
    TRC_MSG(MMI_WIDGET_IMAGE_RELEASE, "[Widget] widget_image_release() - enter")
    TRC_MSG(MMI_WIDGET_OUTPUT_IMAGE_FILE, "[Widget] widget_output_image_file() - enter")
    TRC_MSG(MMI_WIDGET_HDIA_WIDGET_IMAGECREATE, "[Widget] HDIa_widgetImageCreate() - enter")
    TRC_MSG(MMI_WIDGET_HDIA_WIDGET_IMAGECREATE_END, "[Widget] HDIa_widgetImageCreate() - end")
    TRC_MSG(MMI_WIDGET_HDIA_WIDGET_IMAGE_NEXT_PART, "[Widget] HDIa_widgetImageNextPart() - enter")
    TRC_MSG(MMI_WIDGET_HDIA_WIDGET_IMAGE_NEXT_PART_END, "[Widget] HDIa_widgetImageNextPart() - end")
    TRC_MSG(MMI_WIDGET_WRITE_CONTENT_IN_MEMORY, "[Widget] Function: Write content in memory")
    TRC_MSG(MMI_WIDGET_WRITE_CONTENT_IN_FILE, "[Widget] Function: Write content in file")
    TRC_MSG(MMI_WIDGET_HDIA_WIDGET_IMAGE_NEXT_PART_RETURNS, "[Widget] HDIa_widgetImageNextPart(): Returns")
    TRC_MSG(MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE, "[Widget] Widget sends widget_send_notification_load_resource() - enter")
    TRC_MSG(MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE_LOADED, "[Widget] Widget sends MsfNotifyResourceLoaded")
    TRC_MSG(MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE_FAILED, "[Widget] Widget sends MsfNotifyResourceFailed")
    TRC_MSG(MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE_FAILED_RESOLUTION, "[Widget] Widget sends MsfNotifyFailedResolution")
    TRC_MSG(MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE_FAILED_FS_FULL, "[Widget] Widget sends MsfNotifyFailedFSFull")
    TRC_MSG(MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE_FAILED_NO_RESOURCE, "[Widget] Widget sends MsfNotifyFailedNoResource")
    TRC_MSG(MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE_FAILED_CORRUPT, "[Widget] Widget sends MsfNotifyFailedCorrupt")    
    TRC_MSG(WIDGET_RAWFILE_IS_VIRTUAL_FILE, "[Widget] widget_rawfile_is_virtual_file()")
    TRC_MSG(MMI_WIDGET_RAWFILE_GETSIZE, "[Widget] widget_rawfile_getsize()")
    TRC_MSG(MMI_WIDGET_CREATE_IMAGE_RESOURCE, "[Widget] widget_create_image_resource() - enter")
    TRC_MSG(MMI_WIDGET_CREATE_IMAGE_RESOURCE_END, "[Widget] widget_create_image_resource() - end")
    TRC_MSG(MMI_WIDGET_READ_IMAGE_FROM_FILE_TO_RAW_DATA, "[Widget] widget_read_image_from_file_to_raw_data() - enter")
    TRC_MSG(MMI_WIDGET_READ_IMAGE_FROM_FILE_TO_RAW_DATA_END, "[Widget] widget_read_image_from_file_to_raw_data() - end")
    TRC_MSG(MMI_WIDGET_READ_IMAGE_FROM_FILE_TO_RAW_FILE, "[Widget] widget_read_image_from_file_to_raw_file() - enter")
    TRC_MSG(MMI_WIDGET_READ_IMAGE_FROM_FILE_TO_RAW_FILE_END, "[Widget] widget_read_image_from_file_to_raw_file() - end")
    TRC_MSG(MMI_WIDGET_WAIT_IF_INCOMING_CALL, "[Widget] Don't access file since incoming call()")
    TRC_MSG(MMI_WIDGET_IMAGE_RAW_FILE_CHECK_TIME_HDLR, "[Widget] widget_image_raw_file_check_time_hdlr() - enter")
    TRC_MSG(MMI_WIDGET_IMAGE_RAW_FILE_CHECK_TIME_HDLR_END, "[Widget] widget_image_raw_file_check_time_hdlr() - end")
    TRC_MSG(MMI_WIDGET_READ_IMAGE_FROM_FILE, "[Widget] widget_read_image_from_file() - enter")
    TRC_MSG(MMI_WIDGET_READ_IMAGE_FROM_FILE_END, "[Widget] widget_read_image_from_file() - end")
    TRC_MSG(MMI_WIDGET_READ_IMAGE_FROM_PIPE, "[Widget] widget_read_image_from_pipe() - enter")
    TRC_MSG(MMI_WIDGET_READ_IMAGE_FROM_PIPE_END, "[Widget] widget_read_image_from_pipe() - end")
    TRC_MSG(MMI_WIDGET_NOTHING_LEFT_TO_READ, "[Widget] size is 0: nothing left to read")
    TRC_MSG(MMI_WIDGET_PEER_HAS_CLOSED_THE_PIPE, "[Widget] The peer writer has closed the pipe()")    
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING_RETURNS_NO_QUOTA, "[Widget] HDIa_widgetExtImageResizing() returns: MSF_WIDGET_EXT_RESIZING_FAILED_IN_NO_QUOTA")
    TRC_MSG(MMI_WIDGET_GDI_GET_IMAGE_DIMENSION, "[Widget] GDI returns width = %d height = %d")
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING_RETURNS_RESIZING_FAILED_IN_GDI, "[Widget] HDIa_widgetExtImageResizing() returns: MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_FAILED")
    TRC_MSG(MMI_WIDGET_INFO_IMAGE_CALCULTING_DIMENSION_OF_RESIZE_JPEG, "[Widget] Info: calculate the dimension of the resize JPEG")
    TRC_MSG(MMI_WIDGET_INFO_IMAGE_NEED_TO_RESIZE, "[Widget] Info: need to resize")
    TRC_MSG(MMI_WIDGET_ERROR_MEDIA_GET_BUFFER, "[Widget] media_get_ext_buffer() can't get buffer")
    TRC_MSG(MMI_WIDGET_GDI_IMAGE_ENCODE_FILE_TO_JPEG, "[Widget] gdi_image_encode_file_to_jpeg() returned %d")
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING_RETURNS_RESIZING_SUCCEED, "[Widget] HDIa_widgetExtImageResizing() returns: MSF_WIDGET_EXT_RESIZING_SUCCEED")
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING_RETURNS_GDI_ERR_NO_BUFFER, "[Widget] HDIa_widgetExtImageResizing() returns: buf_size is not greater than 0 - ret = MSF_WIDGET_EXT_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF")
    TRC_MSG(MMI_WIDGET_INFO_IMAGE_RESIZING_RETURNS_UNCHANGED, "[Widget] Info: don't need resizing - ret = MSF_WIDGET_EXT_RESIZING_SUCCEED_WITH_UNCHANGED")
    TRC_MSG(MMI_WIDGET_ERR_IMAGE_RESIZING_UNKNOWN_DIMENSION, "[Widget] Info: can't get the image dimension - ret = MSF_WIDGET_EXT_RESIZING_FAILED_IN_UNKNOWN_DIMENSION")
    TRC_MSG(MMI_WIDGET_OPEN_VIDEO_FILE_DONE_HDLR, "[Widget] widget_MMI_open_video_file_done_hdlr() - enter")
    TRC_MSG(MMI_WIDGET_MMI_CREATE_VIDEO_RESOURCE, "[Widget] widget_MMI_create_video_resource() - enter")
    TRC_MSG(MMI_WIDGET_MMI_CREATE_VIDEO_RESOURCE_END, "[Widget] widget_MMI_create_video_resource() - end")
    TRC_MSG(MMI_WIDGET_INFO_CREATE_SECOND_VIDEO, "[Widget] Info: Application tries to create the 2nd video resource: Close 1st resource")
    TRC_MSG(MMI_WIDGET_CREATE_VIDEO_RESOURCE, "[Widget] widget_create_video_resource() - enter")
    TRC_MSG(MMI_WIDGET_CREATE_VIDEO_RESOURCE_END, "[Widget] widget_create_video_resource() - end")
    TRC_MSG(MMI_WIDGET_INFO_TRY_TO_CREATE_1VIDEO_RESOURCE, "[Widget] Info: Try to create first video resource")
    TRC_MSG(MMI_WIDGET_INFO_TRY_TO_CREATE_2VIDEO_RESOURCE, "[Widget] Info: Try to create second video resource")
    TRC_MSG(MMI_WIDGET_HDIA_WIDGET_IMAGE_CREATE_RESOURCE, "[Widget] HDIa_widgetImageCreateResource() - enter")
    TRC_MSG(MMI_WIDGET_HDIA_WIDGET_IMAGE_CREATE_RESOURCE_END, "[Widget] HDIa_widgetImageCreateResource() - end")
    /*
    TRC_MSG(MMI_WIDGET_PRECACHE_IMAGE_RESET_ALL, "[Widget] widget_precache_image_reset_all()")
    TRC_MSG(MMI_WIDGET_PRECACHE_IMAGE_RESET_ALL, "[Widget] widget_precache_image_reset_all()")
    TRC_MSG(MMI_WIDGET_PRECACHE_IMAGE_RESET_ALL, "[Widget] widget_precache_image_reset_all()")
    TRC_MSG(MMI_WIDGET_PRECACHE_IMAGE_RESET_ALL, "[Widget] widget_precache_image_reset_all()")
    TRC_MSG(MMI_WIDGET_PRECACHE_IMAGE_RESET_ALL, "[Widget] widget_precache_image_reset_all()")
    TRC_MSG(MMI_WIDGET_PRECACHE_IMAGE_RESET_ALL, "[Widget] widget_precache_image_reset_all()")
    */


    /* External APIs being called from widget */
    TRC_MSG(MMI_WIDGET_HDIA_PIPE_READ, "[Widget] Widget calls HDIa_pipeRead() returns %x")
    TRC_MSG(MMI_WIDGET_HDIA_DELETE_PIPE_BY_HANDLE, "[Widget] Widget calls HDIa_pipeDeleteByHandle()")
    TRC_MSG(MMI_WIDGET_CALLS_MDI_VIDEO_PLY_STOP, "[Widget] Widget calls mdi_video_ply_stop() - returns %d")
    TRC_MSG(MMI_WIDGET_CALLS_MDI_VIDEO_PLY_CLOSE_CLIP_FILE, "[Widget] Widget calls mdi_video_ply_close_clip_file() - returns %d")
    TRC_MSG(MMI_WIDGET_CALLS_MDI_VIDEO_PLY_OPEN_CLIP_FILE, "[Widget] Widget calls mdi_video_ply_open_clip_file() - returns %d")
    TRC_MSG(MMI_WIDGET_CALLS_HDIA_FILE_OPEN, "[Widget] Widget calls HDIa_fileOpen() - returns %d")
    TRC_MSG(MMI_WIDGET_CALLS_HDIA_FILE_CLOSE, "[Widget] Widget calls HDIa_fileClose() - returns %d")
    TRC_MSG(MMI_WIDGET_CALLS_HDIA_PIPE_OPEN, "[Widget] Widget calls HDIa_pipeOpen() - returns %d")
    TRC_MSG(MMI_WIDGET_CALLS_DRM_OPEN_FILE, "[Widget] Widget calls DRM_open_file() - returns %d")
    TRC_MSG(MMI_WIDGET_CALLS_DRM_CLOSE_FILE, "[Widget] Widget calls DRM_open_file()")
     
   
    
    
    
    
    
    
    
    
		/* Catcher logs activity by ankit -- ends here*/
    
    TRC_MSG(MMI_WAP_UM_ENTRY_WRITE_MMS, "wap_um_entry_write_mms() : cannot enter during USB mode")
    TRC_MSG(MMI_WAP_UM_ENTRY_MSG_MMS, "wap_um_entry_msg_mms() : cannot enter during USB mode")
    TRC_MSG(MMI_WAP_UM_ENTRY_TEMPLATE_MMS, "wap_um_entry_template_mms() : cannot enter during USB mode")
    TRC_MSG(MMI_WAP_UM_ENTRY_SETTING_MMS, "wap_um_entry_setting_mms() : cannot enter during USB mode")
    
        TRC_MSG(MMI_UT_TRC_ABORTING_DUE_TO_ERROR, "[MMI_UT] Error: %Mmmi_ut_error_code_enum!")
    TRC_MSG(MMI_UT_TRC_INITIALIZE, "[MMI_UT]Initialize")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_NOMEMORY, "[MMI_UT] Memory allocation failed.")
    TRC_MSG(MMI_UT_TRC_ERROR_FAILURE_REC_OVERFLOW, "[MMI_UT] The number of failure record has got max.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_REGISTRY_OVERFLOW, "[MMI_UT] The number of registry has got max.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_NO_REGISTRYNAME, "[MMI_UT] Registry name cannot be NULL.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_DUP_REGISTRY, "[MMI_UT] Registry having name already registered.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_NOREGISTRY, "[MMI_UT] Test registry does not exist.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_REGISTRY_PRE_FUNC_FAILED, "[MMI_UT] Registry pre-function failed.")   
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_REGISTRY_POST_FUNC_FAILED, "[MMI_UT] Registry post-function failed.")  
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_NOSUITE, "[MMI_UT] NULL suite not allowed.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_NO_SUITENAME, "[MMI_UT] Suite name cannot be NULL.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_SUITE_PRE_FUNC_FAILED, "[MMI_UT] Suite pre-function failed.")   
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_SUITE_POST_FUNC_FAILED, "[MMI_UT] Suite post-function failed.")           
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_DUP_SUITE, "[MMI_UT] Suite having name already registered.") 
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_SUITE_OVERFLOW, "[MMI_UT] The number of suites has alreay surpassed the maximum which can be displayed.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_NOTEST, "[MMI_UT] NULL test not allowed.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_NO_TESTNAME, "[MMI_UT] Test name cannot be NULL.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_TEST_PRE_FUNC_FAILED, "[MMI_UT] Test pre-function failed.")   
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_TEST_POST_FUNC_FAILED, "[MMI_UT] Test post-function failed.")                
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_DUP_TEST, "[MMI_UT] Test having this name already in suite.")  
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_TEST_OVERFLOW, "[MMI_UT] The number of test has alreay surpassed the maximum which can be displayed.")
    TRC_MSG(MMI_UT_TRC_ERROR_CODE_TEST_NOT_IN_SUITE, "[MMI_UT] Test not registered in specified suite.") 
    TRC_MSG(MMI_UT_TRC_RUN_SUMMARY, "[MMI_UT] Run Summary:")
    TRC_MSG(MMI_UT_TRC_SUITES_SUMMARY, "[MMI_UT] [Suites] Total:%8u Ran:%8u Failed:%8u")
    TRC_MSG(MMI_UT_TRC_CASES_SUMMARY,  "[MMI_UT] [Cases] Total:%8u Ran:%8u Passed:%8u Failed:%8u")
    TRC_MSG(MMI_UT_TRC_CHECKS_SUMMARY, "[MMI_UT] [Checks] Total:%8u Ran:%8u Passed:%8u Failed:%8u")
    TRC_MSG(MMI_UT_TRC_PASSED, "[MMI_UT] Passed")
    TRC_MSG(MMI_UT_TRC_FAILED, "[MMI_UT] Failed")
	
	/* MTI IRE TRACE UPDATION START */
	/* Indic rule engine*/
	TRC_MSG(TRC_IRE_GET_CURRENT_CLUSTER, "[IRE] ire_get_current_cluster()")
	TRC_MSG(TRC_IRE_GET_NEXT_CLUSTER_P, "[IRE] ire_get_next_cluster_p()")
	TRC_MSG(TRC_IRE_GET_NEXT_CLUSTER_P_WITH_SIZE, "[IRE] ire_get_next_cluster_p_with_size()")
	TRC_MSG(TRC_IRE_GET_PREV_CLUSTER_P, "[IRE] ire_get_prev_cluster_p()")
	TRC_MSG(TRC_IRE_SIZE_OF_CURRENT_CLUSTER, "[IRE] ire_size_of_current_cluster()")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_HINDI_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_HINDI unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_GUJARATI_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_GUJARATI unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_BENGALI_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_BENGALI unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_ASSAMESE_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_ASSAMESE unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_PUNJABI_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_PUNJABI unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_KANNADA_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_KANNADA unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_MALAYALAM_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_MALAYALAM unicode value")
    TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_SINHALA_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_SINHALA unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_TELUGU_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_TELUGU unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_ORIYA_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_ORIYA unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_TAMIL_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_TAMIL unicode value")
	TRC_MSG(TRC_IRE_GET_CHARACTER_LANG_ID_INVALID_UNICODE_VALUE, "[IRE] ire_get_character_lang_id(), IRE_LANGUAGE_ID_INVALID unicode value")
	TRC_MSG(TRC_IRE_GET_CLUSTER, "[IRE] ire_get_cluster()")
	TRC_MSG(TRC_IRE_GET_CLUSTER_NON_INDIC_CHARACTER, "[IRE] ire_get_cluster(), non indic character")
	TRC_MSG(TRC_IRE_GET_CLUSTER_INDIC_CHARACTER_TYPE_CONSONANT, "[IRE] ire_get_cluster(), indic character type consonant")
	TRC_MSG(TRC_IRE_GET_CLUSTER_INDIC_CHARACTER_TYPE_HALANT_SIGN, "[IRE] ire_get_cluster(), indic character type halant sign")
	TRC_MSG(TRC_IRE_GET_CLUSTER_INDIC_CHARACTER_TYPE_TAMIL_HALANT_SIGN, "[IRE] ire_get_cluster(), indic character type tamil halant sign")
	TRC_MSG(TRC_IRE_GET_MULTITAP_TEXT_X, "[IRE] ire_get_multitap_text_x()")
	TRC_MSG(TRC_IRE_GET_TEXT_X, "[IRE] ire_get_text_x()")
	TRC_MSG(TRC_IRE_GET_BORDERED_TEXT_X, "[IRE] ire_get_bordered_text_x()")
	TRC_MSG(TRC_INDIC_WHETHER_CONJUNCT, "[IRE] indic_whether_conjunct()")
	TRC_MSG(TRC_IRE_LANGUAGE_RULES, "[IRE] ire_language_rules()")
	TRC_MSG(TRC_IRE_LANGUAGE_RULES_NOUTGLYPH, "[IRE] ire_language_rules(), noutglyph-%d")
	TRC_MSG(TRC_IRE_GET_INDIC_RULES_FOR_WHOLE_STRING, "[IRE] ire_get_indic_rules_for_whole_string()")
	TRC_MSG(TRC_IRE_GET_STRING_WIDTH_HEIGHT, "[IRE] ire_get_string_width_height()")
	TRC_MSG(TRC_IRE_IDENTIFY_CHARACTER_TYPE, "[IRE] ire_identify_character_type()")
	TRC_MSG(TRC_IRE_IDENTIFY_CHARACTER_TYPE_CONSONANT, "[IRE] ire_identify_character_type(), char type-%d")
	TRC_MSG(TRC_IRE_IDENTIFY_CHARACTER_TYPE_INDEPVOWEL, "[IRE] ire_identify_character_type(), char type-%d")
	TRC_MSG(TRC_IRE_IDENTIFY_CHARACTER_TYPE_DEPVOWEL, "[IRE] ire_identify_character_type(), char type-%d")
	TRC_MSG(TRC_IRE_IDENTIFY_CHARACTER_TYPE_SIGN, "[IRE] ire_identify_character_type(), char type-%d")
	TRC_MSG(TRC_IRE_IDENTIFY_CHARACTER_TYPE_HALANT, "[IRE] ire_identify_character_type(), char type-%d")
	TRC_MSG(TRC_IRE_IDENTIFY_CHARACTER_TYPE_LIGATURE, "[IRE] ire_identify_character_type(), char type-%d")
	TRC_MSG(TRC_IRE_IDENTIFY_CHARACTER_TYPE_DIGIT, "[IRE] ire_identify_character_type(), char type-%d")
	TRC_MSG(TRC_IRE_IDENTIFY_CHARACTER_TYPE_INVALID, "[IRE] ire_identify_character_type(), char type-%d")
	TRC_MSG(TRC_IRE_IDENTIFY_SIGN_RANGE, "[IRE] ire_identify_sign_range()")
	TRC_MSG(TRC_IRE_IDENTIFY_CHAR_POSITION, "[IRE] ire_identify_char_position()")
    TRC_MSG(TRC_IRE_SMALL_CON_RENDERING_CORRECTION, "[IRE] ire_small_con_rendering_correction()")
	/* MTI IRE TRACE UPDATION END */

    TRC_MSG(MMI_GUI_SCREEN_SWITCH_EFFECT_PERFORMANCE, "[SSE] effect %d index %d time %d ms")

    /* MMIAPI */
    TRC_MSG(MMI_RPC_REQ_MESSAGE, "[RPC] mmiapi_remote_proc_call_req() %x")
    TRC_MSG(MMI_RPC_REQ_MESSAGE_CANCELED, "[RPC] mmiapi_remote_proc_call_req() canceled")
    TRC_MSG(MMI_RPC_REQ_MESSAGE_END, "[RPC] mmiapi_remote_proc_call_req() %x - finished")
    TRC_MSG(MMI_TEXTBOX_SHOW, "[MMI][TEXTBOX] show textbox,isActiveScreen=%d")
    TRC_MSG(MMI_TEXTBOX_HIDE, "[MMI][TEXTBOX] hide textbox")
    TRC_MSG(MMI_TEXTBOX_UPDATE_TITLE, "[MMI][TEXTBOX] update title")
    TRC_MSG(MMI_TEXTBOX_UPDATE_TICKER, "[MMI][TEXTBOX] update ticker")
    TRC_MSG(MMI_TEXTBOX_UPDATE_COMMAND, "[MMI][TEXTBOX] update command")
    TRC_MSG(MMI_TEXTBOX_UPDATE_DATA, "[MMI][TEXTBOX] update data")
    
    /* Gesture */
    TRC_MSG(MMI_FRM_TRC_GESTURE_INFO, "[GESTURE] Stroke %d: %Mmmi_frm_strokes_enum (%d, %d)")
    TRC_MSG(MMI_FRM_TRC_GESTURE_ACCEPT, "[GESTURE] The gesture is recognised as %Mmmi_frm_gesture_event_enum ")
    TRC_MSG(MMI_FRM_TRC_GESTURE_REJECT, "[GESTURE] The gesture can not be recognised")

    /* Clipboard */
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_MEMORY_BEGIN, "[CLIPBOARD] mmi_clipboard_get_memory() Begin mem_size=%d type=%M")
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_MEMORY_WRONG_ARG, "[CLIPBOARD] mmi_clipboard_get_memory() Wrong argument type=%M")
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_MEMORY_NO_MEMORY, "[CLIPBOARD] mmi_clipboard_get_memory() Memory is not enough mem_size=%d max_alloc_size=%M")
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_MEMORY_END, "[CLIPBOARD] mmi_clipboard_get_memory() End mem_ptr=%x")

    TRC_MSG(TRC_MMI_CLIPBOARD_SET_DATA_BEGIN, "[CLIPBOARD] mmi_clipboard_set_data() Begin type=%M data=%x")
    TRC_MSG(TRC_MMI_CLIPBOARD_SET_DATA_WRONG_ARG, "[CLIPBOARD] mmi_clipboard_set_data() Wrong argument type=%M data=%x")
    TRC_MSG(TRC_MMI_CLIPBOARD_SET_DATA_MEM_POOL_FAIL, "[CLIPBOARD] mmi_clipboard_set_data() Fail to construct memory pool!")
    TRC_MSG(TRC_MMI_CLIPBOARD_SET_DATA_EMPTY_FAIL, "[CLIPBOARD] mmi_clipboard_set_data() Fail to empty clipboard memory, type=%M")
    TRC_MSG(TRC_MMI_CLIPBOARD_SET_DATA_END, "[CLIPBOARD] mmi_clipboard_set_data() End cpbd_hdl=%x")

    TRC_MSG(TRC_MMI_CLIPBOARD_GET_DATA_BY_TYPE_BEGIN, "[CLIPBOARD] mmi_clipboard_get_data_by_type() Begin type=%M")
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_DATA_BY_TYPE_WRONG_ARG, "[CLIPBOARD] mmi_clipboard_get_data_by_type() Wrong argument type=%M")
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_DATA_BY_TYPE_END, "[CLIPBOARD] mmi_clipboard_get_data_by_type() End type=%d")
    
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_DATA_BY_HANDLE_BEGIN, "[CLIPBOARD] mmi_clipboard_get_data_by_handle() Begin handle=%x")
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_DATA_BY_HANDLE_END, "[CLIPBOARD] mmi_clipboard_get_data_by_handle() End handle=%x")
    
    TRC_MSG(TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_BEGIN, "[CLIPBOARD] mmi_clipboard_empty_data_by_type() Begin type=%M")
    TRC_MSG(TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_WRONG_ARG, "[CLIPBOARD] mmi_clipboard_empty_data_by_type() Wrong argument type=%M")
    TRC_MSG(TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_NULL_HDL, "[CLIPBOARD] mmi_clipboard_empty_data_by_type() Null handler")
    TRC_MSG(TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_PATTERN_FAIL, "[CLIPBOARD] mmi_clipboard_empty_data_by_type() Pattern corrupt!")
    TRC_MSG(TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_END, "[CLIPBOARD] mmi_clipboard_empty_data_by_type() End")

    TRC_MSG(TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_HANDLE_BEGIN, "[CLIPBOARD] mmi_clipboard_empty_data_by_handle() Begin handle=%x")
    TRC_MSG(TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_HANDLE_WRONG_ARG, "[CLIPBOARD] mmi_clipboard_empty_data_by_handle() Wrong argument handle=%x")
    TRC_MSG(TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_HANDLE_GET_TYPE_FAIL, "[CLIPBOARD] mmi_clipboard_empty_data_by_handle() Fail to get type from handle!, type=%M")
    TRC_MSG(TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_HANDLE_END, "[CLIPBOARD] mmi_clipboard_empty_data_by_handle() End, result=%d")

    TRC_MSG(TRC_MMI_CLIPBOARD_GET_TYPE_FROM_HANDLE_BEGIN, "[CLIPBOARD] mmi_clipboard_get_type_from_handle() Begin handle=%x")
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_TYPE_FROM_HANDLE_FAIL, "[CLIPBOARD] mmi_clipboard_get_type_from_handle() Fail")
    TRC_MSG(TRC_MMI_CLIPBOARD_GET_TYPE_FROM_HANDLE_END, "[CLIPBOARD] mmi_clipboard_get_type_from_handle() End type=%M")

    TRC_MSG(TRC_MMI_CLIPBOARD_REGISTER_NEW_CONTENT_BEGIN, "[CLIPBOARD] mmi_clipboard_get_type_from_handle() Begin type=%M set_cb=%x")
    TRC_MSG(TRC_MMI_CLIPBOARD_REGISTER_NEW_CONTENT_WRONG_ARG, "[CLIPBOARD] mmi_clipboard_get_type_from_handle() Wrong argument type=%M set_cb=%x")
    TRC_MSG(TRC_MMI_CLIPBOARD_REGISTER_NEW_CONTENT_END, "[CLIPBOARD] mmi_clipboard_get_type_from_handle() End")

    TRC_MSG(TRC_MMI_CLIPBOARD_CCP_ENTER_LOCATE_START_CURSOR_STATE, "[CLIPBOARD_CCP] mmi_imc_clipboard_enter_locate_start_cursor_state()")
    TRC_MSG(TRC_MMI_CLIPBOARD_CCP_ENTER_MARK_TEXT_STATE, "[CLIPBOARD_CCP] mmi_imc_clipboard_enter_mark_text_state()")
    TRC_MSG(TRC_MMI_CLIPBOARD_CCP_GOBACK_INITIAL_STATE, "[CLIPBOARD_CCP] mmi_imc_clipboard_go_back_to_initial() Begin, g_imc_clipboard_data.is_saved=%d")
    TRC_MSG(TRC_MMI_CLIPBOARD_CCP_OPTION_HANDLE_END, "[CLIPBOARD_CCP] mmi_imc_clipboard_option_handle() End, ret=%d")
    TRC_MSG(TRC_MMI_CLIPBOARD_CCP_COPY, "[CLIPBOARD_CCP] mmi_imc_clipboard_copy() Begin, Free_space=%d Text_length=%d")
    TRC_MSG(TRC_MMI_CLIPBOARD_CCP_COPY_ALL, "[CLIPBOARD_CCP] mmi_imc_clipboard_copy_all() Begin, Free_space=%d Text_length=%d")
    TRC_MSG(TRC_MMI_CLIPBOARD_CCP_PASTE_BEGIN, "[CLIPBOARD_CCP] mmi_imc_clipboard_paste() Begin")
    TRC_MSG(TRC_MMI_CLIPBOARD_CCP_PASTE_END, "[CLIPBOARD_CCP] mmi_imc_clipboard_paste() End")
    /* Handwriting */
    TRC_MSG(TRC_MMI_FW_HW_CANDIDATES_RECONGNITION_TIME, "[Hand Writing] Handwriting recongnition time: %d ms")
    TRC_MSG(TRC_MMI_FW_IME_INSERT_CHARACTER_TO_EDITOR, "[IME] 0x%x is inserted to editor")
    /* Font engine */
    TRC_MSG(TRC_MMI_FE_INVALID_CHARACTER, "[FONT_ENGINE] ch == %x is invalid")
    TRC_MSG(TRC_MMI_FE_LOAD_FONT_RESOURCE_FROM_ENFB, "[FONT_ENGINE] retval = %d (load font %d from ENFB)")
    TRC_MSG(TRC_MMI_FE_LOAD_FONT_RESOURCE_FROM_MEM, "[FONT_ENGINE] retval = %d ( load font %d from MEMORY)")
    /* Font engine - monotype */
    TRC_MSG(TRC_MMI_FE_MONO_INIT_SUCCESS, "[MONOTYPE] monotype engine initialize success")
    TRC_MSG(TRC_MMI_FE_MONO_INIT_FAIL, "[MONOTYPE] monotype engine initialize success")
    TRC_MSG(TRC_MMI_FE_MONO_INIT_VALUE, "[MONOTYPE] monotype engine initialize ret value = %x")
    TRC_MSG(TRC_MMI_FE_MONO_ADD_FONT_RESOURCE, "[MONOTYPE] monotype FS_add_font(%d) = %x")
    TRC_MSG(TRC_MMI_FE_MONO_SET_FONT, "[MONOTYPE] monotype FS_set_font(%d) = %x")
    TRC_MSG(TRC_MMI_FE_MONO_SET_CMAP, "[MONOTYPE] monotype FS_set_cmap() = %x")
    TRC_MSG(TRC_MMI_FE_MONO_ENGINE_RESTART, "[MONOTYPE] engine restart")
    /* Font engine - freetype */
    TRC_MSG(TRC_MMI_FE_FREE_LOAD_GDEF_TABLE_ERROR, "[FREETYPE] load GDEF table error = %d")
    TRC_MSG(TRC_MMI_FE_FREE_LOAD_GSUB_TABLE_ERROR, "[FREETYPE] load GSUB table error = %d")
    TRC_MSG(TRC_MMI_FE_FREE_LOAD_GPOS_TABLE_ERROR, "[FREETYPE] load GPOS table error = %d")
    TRC_MSG(TRC_MMI_FE_FREE_MEMORY_USAGE, "[FREETYPE] Freetype have %d bytes pool")
    TRC_MSG(TRC_MMI_FE_FREE_MEMORY_USAGE_LOWER_BOUND, "[FREETYPE] FREETYPE_ENGINE_INIT_SIZE should > %d")
    TRC_MSG(TRC_MMI_FE_FREE_MEMORY_USAGE_TRY_INITIAL_SIZE, "[FREETYPE] Try font engine initialize size %d")
    TRC_MSG(TRC_MMI_FE_FREE_MEMORY_REMINDING, "[FREETYPE] Freetype still have %d bytes")

/* Vogins Start */
    /* VRE use temporaty */
    TRC_MSG(TRC_MMI_AM_SET_AS_SHORTCUT, "[VRE] mmi_am_set_as_shortcut()")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_ICON_SIZE_FAIL, "[VRE] MMI_AM_SHORTCUT_ICON_SIZE_FAIL") 
    TRC_MSG(TRC_MMI_AM_SHORTCUT_DUPLICATE_ID, "[VRE] MMI_AM_SHORTCUT_DUPLICATE_ID")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_VERIFY_FAIL, "[VRE] VRE Verify fail=%d")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_STRUCTURE_FAIL, "[VRE] MMI_AM_SHORTCUT_STRUCTURE_FAIL,i=%d")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_FILE_FAIL, "[VRE] MMI_AM_SHORTCUT_FILE_FAIL")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_INFO, "[VRE] id=%d,is_used=%d,number=%d,i=%d")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_NUMBER, "[VRE] shortcut_number =%d")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_ICON, "[VRE] mmi_am_get_shortcut_icon()")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_ICON_ID, "[VRE] icon_id =%d")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_CANCEL, "[VRE] mmi_am_cancel_shortcut()")
    TRC_MSG(TRC_MMI_AM_SHORTCUT_LAUNCH, "[VRE] mmi_am_launch_shortcut:id=%d")

    TRC_MSG(TRC_MMI_AM_START_S, "[VRE] mmi_am_start --S-- <is_quick_start:%d, dyn_mem_pool:%d, adm_pool_id:%d, is_vre_init:%d>")
    TRC_MSG(TRC_MMI_AM_START_E, "[VRE] mmi_am_start --E-- <is_quick_start:%d, dyn_mem_pool:%d, adm_pool_id:%d, is_vre_init:%d>")
    TRC_MSG(TRC_MMI_AM_START_INT_S, "[VRE] mmi_am_start_int --S--")
    TRC_MSG(TRC_MMI_AM_VRE_LOAD_RESULT, "[VRE] mmi_am_start_int <load_vre_core_ret:%d>")
    TRC_MSG(TRC_MMI_AM_DYN_MEM_POOL, "[VRE] mmi_am_start_int <dyn_mem_pool:%d>")
    TRC_MSG(TRC_MMI_AM_ALLOCATE_MEM_FAIL, "[VRE] mmi_am_start_int <allocate memory fail>")    
    TRC_MSG(TRC_MMI_AM_START_INT_E, "[VRE] mmi_am_start_int --E--")    
    TRC_MSG(TRC_MMI_AM_PRE_START_CHECK_S, "[VRE] mmi_am_pre_start_check --S--")
    TRC_MSG(TRC_MMI_AM_PRE_START_CHECK_E1, "[VRE] mmi_am_pre_start_check --E1-- <too many files>")
    TRC_MSG(TRC_MMI_AM_PRE_START_CHECK_E2, "[VRE] mmi_am_pre_start_check --E2-- <mass storage mode>")
    TRC_MSG(TRC_MMI_AM_PRE_START_CHECK_E3, "[VRE] mmi_am_pre_start_check --E3--")
    TRC_MSG(TRC_MMI_AM_VRE_CB_S, "[VRE] mmi_am_vre_cb --S-- <evt:%d, is_quick_start:%d, is_app_update:%d, dyn_mem_pool:%d>")
    TRC_MSG(TRC_MMI_AM_VRE_CB_E, "[VRE] mmi_am_vre_cb --E--")    
    TRC_MSG(TRC_MMI_AM_ALLOC_MEM_CB_S, "[VRE] mmi_am_alloc_mem_cb --S-- <is_quick_start:%d, is_app_update:%d, dyn_mem_pool:%d>")
    TRC_MSG(TRC_MMI_AM_ALLOC_MEM_CB_E, "[VRE] mmi_am_alloc_mem_cb --E-- <dyn_mem_pool:%d>")    
    TRC_MSG(TRC_MMI_AM_START_FROM_FM_S, "[VRE] mmi_am_start_from_fm --S--")
    TRC_MSG(TRC_MMI_AM_START_FROM_FM_E, "[VRE] mmi_am_start_from_fm --E--")
    TRC_MSG(TRC_MMI_AM_START_FROM_HS_S, "[VRE] mmi_am_start_from_hs --S--")
    TRC_MSG(TRC_MMI_AM_START_FROM_HS_E, "[VRE] mmi_am_start_from_hs --E--")
    TRC_MSG(TRC_MMI_AM_START_FROM_MM_S, "[VRE] mmi_am_start_from_mm --S-- <appid:%d>")
    TRC_MSG(TRC_MMI_AM_START_FROM_MM_E1, "[VRE] mmi_am_start_from_mm --E1--")    
    TRC_MSG(TRC_MMI_AM_START_FROM_MM_E2, "[VRE] mmi_am_start_from_mm --E2--")    
    TRC_MSG(TRC_MMI_AM_START_FROM_MM_E3, "[VRE] mmi_am_start_from_mm --E3-- <is_quick_start:%d, is_download:%d>")    
    TRC_MSG(TRC_MMI_AM_GROUP_PROC_EVT_S, "[VRE] mmi_am_grp_proc --S-- <evt_id:%d, is_quick_start:%d, is_download:%d>")
    TRC_MSG(TRC_MMI_AM_GROUP_PROC_EVT_E, "[VRE] mmi_am_grp_proc --E--")
    TRC_MSG(TRC_MMI_AM_ASM_STOP_CB_S, "[VRE] mmi_am_asm_stop_cb --S--")
    TRC_MSG(TRC_MMI_AM_ASM_STOP_CB_E, "[VRE] mmi_am_asm_stop_cb --E--")    
    TRC_MSG(TRC_MMI_AM_APP_INIT_S, "[VRE] mmi_am_app_init --S-- <dyn_mem_pool:%d, is_quick_start:%d, is_app_update:%d>")
    TRC_MSG(TRC_MMI_AM_APP_INIT_E1, "[VRE] mmi_am_app_init --E")
    TRC_MSG(TRC_MMI_AM_APP_INIT_E2, "[VRE] mmi_am_app_init --E2-- <adm_pool_id:%d, is_quick_start:%d, is_app_update:%d, shortcut_app_num:%d, rom_app_num:%d, has_small_font:%d, sim_settings:%d, conn_settings:%d>")    
    TRC_MSG(TRC_MMI_AM_SEARCH_S, "[VRE] mmi_am_search --S--")
    TRC_MSG(TRC_MMI_AM_SEARCH_E, "[VRE] mmi_am_search --E--")
    TRC_MSG(TRC_MMI_AM_DEINIT_S, "[VRE] mmi_am_grp_deinit --S--<search_hdl:%d, card_vre_folder_hdl:%d, phone_vre_folder_hdl:%d, adm_pool_id:%d, dyn_mem_pool:%d, is_vre_init:%d>")
    TRC_MSG(TRC_MMI_AM_DEINIT_E, "[VRE] mmi_am_grp_deinit --E--<search_hdl:%d, card_vre_folder_hdl:%d, phone_vre_folder_hdl:%d, adm_pool_id:%d, dyn_mem_pool:%d, is_vre_init:%d>")    
    TRC_MSG(TRC_MMI_AM_ENTRY_LOADING_SCRN_S, "[VRE] mmi_am_entry_loading_scrn --S-- <is_quick_start:%d, is_download:%d, adm_pool_id:%d, start_state:%d, is_card_plug_in:%d, is_card_plug_out:%d, is_launch_vas:%d>")    
    TRC_MSG(TRC_MMI_AM_ENTRY_LOADING_SCRN_E1, "[VRE] mmi_am_entry_loading_scrn --E1--")
    TRC_MSG(TRC_MMI_AM_ENTRY_LOADING_SCRN_E2, "[VRE] mmi_am_entry_loading_scrn --E2--")
    TRC_MSG(TRC_MMI_AM_ENTRY_LOADING_SCRN_E3, "[VRE] mmi_am_entry_loading_scrn --E3--")
    TRC_MSG(TRC_MMI_AM_ENTRY_LOADING_SCRN_E4, "[VRE] mmi_am_entry_loading_scrn --E4--")
    TRC_MSG(TRC_MMI_AM_ENTRY_LOADING_SCRN_E5, "[VRE] mmi_am_entry_loading_scrn --E5--")
    TRC_MSG(TRC_MMI_AM_ENTRY_LOADING_SCRN_E6, "[VRE] mmi_am_entry_loading_scrn --E6--")
    TRC_MSG(TRC_MMI_AM_ENTRY_LOADING_SCRN_E7, "[VRE] mmi_am_entry_loading_scrn --E7--")
    TRC_MSG(TRC_MMI_AM_ENTRY_LOADING_SCRN_E8, "[VRE] mmi_am_entry_loading_scrn --E8--")
    TRC_MSG(TRC_MMI_AM_LS_APP_LAUNCH_S, "[VRE] mmi_am_ls_app_launch --S-- <hl_idx:%d>")      
    TRC_MSG(TRC_MMI_AM_LS_APP_LAUNCH_AS, "[VRE] Launch appstore")        
    TRC_MSG(TRC_MMI_AM_LS_APP_LAUNCH_OTHER_APP, "[VRE] Launch other app")    
    TRC_MSG(TRC_MMI_AM_LS_APP_LAUNCH_E1, "[VRE] mmi_am_ls_app_launch --E1")    
    TRC_MSG(TRC_MMI_AM_LS_APP_LAUNCH_E2, "[VRE] mmi_am_ls_app_launch --E2")    
    TRC_MSG(TRC_MMI_AM_LS_APP_LAUNCH_E3, "[VRE] mmi_am_ls_app_launch --E3-- <hl_idx:%d>")    
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_FILES_S, "[VRE] mmi_am_search_vxp_files --S-- <is_card_plug_in:%d, is_card_plug_out:%d>")         
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_FILES_DONE, "[VRE] mmi_am_search_vxp_files <Search done>")   
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_FILES_E, "[VRE] mmi_am_search_vxp_files --E-- <search_state:%d>")      
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_CB_S, "[VRE] mmi_am_search_vxp_cb --S-- <is_card_plug_in:%d, is_card_plug_out:%d, search_hdl:%d, search_state:%d, cur_driver:%d>")         
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_CB_FINDNEXT, "[VRE] mmi_am_search_vxp_cb <FS_FindNext::cur_driver:%d>")   
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_CB_FINDFIRST_IN_PHONE, "[VRE] mmi_am_search_vxp_cb <FS_FindFirst in phone::cur_driver:%d>")   
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_CB_DONE_IN_PHONE, "[VRE] mmi_am_search_vxp_cb <no vxp file in phone>")   
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_CB_FINDFIRST_PLUG_IN_CARD, "[VRE] mmi_am_search_vxp_cb <FS_FindFirst in phone::cur_driver:%d>")   
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_CB_DONE_PLUG_IN_CARD, "[VRE] mmi_am_search_vxp_cb <no vxp file in memory card>")   
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_CB_DONE, "[VRE] mmi_am_search_vxp_cb <Search done>")      
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_CB_CONTINUE, "[VRE] mmi_am_search_vxp_cb <Start a timer continue to search>")      
    TRC_MSG(TRC_MMI_AM_SEARCH_VXP_CB_E, "[VRE] mmi_am_search_vxp_cb --E--")     
    TRC_MSG(TRC_MMI_AM_APP_LAUNCH_CB_S, "[VRE] mmi_am_app_launch_cb --S-- <is_quick_start:%d>")         
    TRC_MSG(TRC_MMI_AM_APP_LAUNCH_CB_E, "[VRE] mmi_am_app_launch_cb --E-- <is_launch_vas:%d>")            
    TRC_MSG(TRC_MMI_AM_APP_LAUNCH_RESULT, "[VRE] mmi_am_app_launch_int-result:%d")
    TRC_MSG(TRC_MMI_AM_PLUG_IN_S, "[VRE] mmi_am_card_plug_in_hdlr --S-- <adm_pool_id:%d, start_state:%d, is_card_plug_out:%d, search_state:%d, is_download:%d>")
    TRC_MSG(TRC_MMI_AM_PLUG_IN_SCRN_ID, "[VRE] mmi_am_card_plug_in_hdlr <scrn_id:%d>")
    TRC_MSG(TRC_MMI_AM_PLUG_IN_E, "[VRE] mmi_am_card_plug_in_hdlr --E--")    
    TRC_MSG(TRC_MMI_AM_PLUG_OUT_S, "[VRE] mmi_am_card_plug_out_hdlr --S-- <adm_pool_id:%d, start_state:%d, is_card_plug_in:%d, hl_idx:%d, is_app_in_card:%d, is_download:%d>")
    TRC_MSG(TRC_MMI_AM_PLUG_OUT_PATH, "[VRE] mmi_am_card_plug_out_hdlr <path diver:%d>")
    TRC_MSG(TRC_MMI_AM_PLUG_OUT_IN_MEMORY_CARD, "[VRE] mmi_am_card_plug_out_hdlr <in memory card>")
    TRC_MSG(TRC_MMI_AM_PLUG_OUT_E, "[VRE] mmi_am_card_plug_out_hdlr --E-- <hl_idx:%d, is_app_in_card:%d>")
    TRC_MSG(TRC_MMI_AM_RELEASE_APPSTORE, "[VRE] mmi_am_release_shortcut_list_nodes_in_memory_card <release appstore>")
    TRC_MSG(TRC_MMI_AM_RELEASE_SHORTCUT_PATH, "[VRE] mmi_am_release_shortcut_list_nodes_in_memory_card <i:%d, driver:%d>")
    TRC_MSG(TRC_MMI_AM_RELEASE_SHORTCUT, "[VRE] mmi_am_release_shortcut_list_nodes_in_memory_card <release shortcut i:%d>")
    TRC_MSG(TRC_MMI_AM_RELEASE_VXP_NODE, "[VRE] mmi_am_release_vxp_list_nodes_in_memory_card <release vxp list node>")
    TRC_MSG(TRC_MMI_AM_RELEASE_APP_LIST_NODE, "[VRE] mmi_am_ms_release_app_list_nodes_in_memory_card <release app list node hl_idx:%d>")
    TRC_MSG(TRC_MMI_AM_ENTER_USB_MODE_S, "[VRE] mmi_am_enter_usb_mode --S-- <adm_pool_id:%d>")
    TRC_MSG(TRC_MMI_AM_ENTER_USB_MODE_CLOSE_AM, "[VRE] mmi_am_enter_usb_mode <close AM>")
    TRC_MSG(TRC_MMI_AM_ENTER_USB_MODE_E, "[VRE] mmi_am_enter_usb_mode --E--")
    TRC_MSG(TRC_MMI_AM_CHECK_FILE_NUMBER, "[VRE] mmi_am_is_too_many_files_in_vre_folder <vxp_num:%d>")
    TRC_MSG(TRC_MMI_AM_ENTRY_MAIN_SCRN_S, "[VRE] mmi_am_entry_main_scrn --S--")
    TRC_MSG(TRC_MMI_AM_MS_ENTRY_SCREEN, "[VRE] mmi_am_entry_main_scrn <num_of_items:%d>")
    TRC_MSG(TRC_MMI_AM_MS_ENTRY_SCREEN_CDR, "[VRE] mmi_am_entry_main_scrn <is_prompt_update_cdr:%d>")
    TRC_MSG(TRC_MMI_AM_ENTRY_MAIN_SCRN_E, "[VRE] mmi_am_entry_main_scrn --E--")
    TRC_MSG(TRC_MMI_AM_MS_LEAVE_SCREEN, "[VRE] mmi_am_leave_main_scrn <evt_id:%d>")    
    TRC_MSG(TRC_MMI_AM_MS_DRAW_CB_S, "[VRE] mmi_am_ms_draw_cb --S--")
    TRC_MSG(TRC_MMI_AM_MS_DRAW_CB, "[VRE] mmi_am_ms_draw_cb <idx:%d, page_start_idx:%d, page_end_idx:%d, is_hilighted:%d>")
    TRC_MSG(TRC_MMI_AM_MS_DRAW_CB_POS, "[VRE] mmi_am_ms_draw_cb <x1:%d, y1:%d, x2:%d, y2:%d>")
    TRC_MSG(TRC_MMI_AM_MS_DRAW_CB_APP_NUM, "[VRE] mmi_am_ms_draw_cb <sc_app_num:%d, rom_app_num:%d>")
    TRC_MSG(TRC_MMI_AM_MS_DRAW_CB_E, "[VRE] mmi_am_ms_draw_cb --E--")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_S, "[VRE] mmi_am_ms_update_app_list --S--")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_1, "[VRE] mmi_am_ms_update_app_list <first_idx:%d, is_first_idx_exist:%d>")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_2, "[VRE] mmi_am_ms_update_app_list <remove from applist[1]--p->idx:%d>")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_3, "[VRE] mmi_am_ms_update_app_list <remove a node from applist[2] -- no:%d>")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_4, "[VRE] mmi_am_ms_update_app_list <get a node from vxplist[1] -- i:%d, no:%d>")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_5, "[VRE] mmi_am_ms_update_app_list <get a node from vxplist[1] -- i:%d, no:%d>")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_6, "[VRE] mmi_am_ms_update_app_list <remove from applist[3]--p->idx:%d>")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_7, "[VRE] mmi_am_ms_update_app_list <remove from applist[4] -- p->idx:%d, no:%d>")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_8, "[VRE] mmi_am_ms_update_app_list <remove from applist[1]--p->idx:%d>")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_E1, "[VRE] mmi_am_ms_update_app_list --E1--")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_E2, "[VRE] mmi_am_ms_update_app_list --E2--")
    TRC_MSG(TRC_MMI_AM_MS_UPDATE_APP_LIST_E3, "[VRE] mmi_am_ms_update_app_list --E3--")    
    TRC_MSG(TRC_MMI_AM_ENTRY_DOWNLOADING_SCRN_S, "[VRE] mmi_am_entry_downloading_scrn --S-- <is_start_download:%d, download_progress:%d>")
    TRC_MSG(TRC_MMI_AM_ENTRY_DOWNLOADING_SCRN_E1, "[VRE] mmi_am_entry_downloading_scrn --E1--")
    TRC_MSG(TRC_MMI_AM_ENTRY_DOWNLOADING_SCRN_E2, "[VRE] mmi_am_entry_downloading_scrn --E2--")
    TRC_MSG(TRC_MMI_AM_PROXY_CANCEL_DOWNLOAD, "[VRE] mmi_am_vre_cancel_download <total left size:%d>")
    TRC_MSG(TRC_MMI_AM_PROXY_PRE_DOWNLOAD, "[VRE] mmi_am_vre_pre_download_app <total left size:%d>")
    TRC_MSG(TRC_MMI_AM_PROXY_DOWNLOAD_APP, "[VRE] mmi_am_vre_download_app <ret:%d>")
    TRC_MSG(TRC_MMI_AM_SCREENS_SET_SHORTCUT, "[VRE] mmi_am_os_create_hs_shortcut <ret:%d>")
    TRC_MSG(TRC_MMI_AM_SCREENS_DOWNLOAD_CB, "[VRE] mmi_am_download_app_cb <nResult:%d, nPercent:%d, is_start_download:%d>")         
    TRC_MSG(TRC_MMI_AM_LS_DESTROY_S, "[VRE] mmi_am_destroy_loading_scrn --S--")
    TRC_MSG(TRC_MMI_AM_LS_DESTROY_E, "[VRE] mmi_am_destroy_loading_scrn --E--")
    TRC_MSG(TRC_MMI_AM_MS_DESTROY_S, "[VRE] mmi_am_destroy_main_scrn --S--")
    TRC_MSG(TRC_MMI_AM_MS_DESTROY_E, "[VRE] mmi_am_destroy_main_scrn --E--")
    TRC_MSG(TRC_MMI_AM_DETAILS_SCRN_ENTRY_S, "[VRE] mmi_am_entry_details_scrn --S-- <g_ds_str_buf:%d>")
    TRC_MSG(TRC_MMI_AM_DETAILS_SCRN_ENTRY_E, "[VRE] mmi_am_entry_details_scrn --E--")
    TRC_MSG(TRC_MMI_AM_DETAILS_SCRN_DESTROY_S, "[VRE] mmi_am_destroy_details_scrn --S--")
    TRC_MSG(TRC_MMI_AM_DETAILS_SCRN_DESTROY_E, "[VRE] mmi_am_destroy_details_scrn --E--")
    TRC_MSG(TRC_MMI_AM_DOWNLOADING_SCRN_DESTROY_S, "[VRE] mmi_am_destroy_downloading_scrn --S--")
    TRC_MSG(TRC_MMI_AM_DOWNLOADING_SCRN_DESTROY_E, "[VRE] mmi_am_destroy_downloading_scrn --E--")
    TRC_MSG(TRC_MMI_AM_UPDATE_CDR_STATE, "[VRE] mmi_am_ms_update_cdr <state:%d>")
    TRC_MSG(TRC_MMI_AM_UPDATE_CDR_BALANCE, "[VRE] mmi_am_ms_update_cdr <balance:%d>")
    TRC_MSG(TRC_MMI_AM_UPDATE_CDR_CB, "[VRE] mmi_am_cdr_update_cb <nResult:%d>")
    TRC_MSG(TRC_MMI_AM_HOLD_VRE_FOLDER_S, "[VRE] mmi_am_hold_vre_folder --S-- <card_vre_folder_hdl:%d, phone_vre_folder_hdl:%d>")
    TRC_MSG(TRC_MMI_AM_HOLD_VRE_FOLDER_E, "[VRE] mmi_am_hold_vre_folder --E-- <card_vre_folder_hdl:%d, phone_vre_folder_hdl:%d>")
    TRC_MSG(TRC_MMI_AM_SEARCH_SHORTCUT_APPS_S, "[VRE] mmi_am_search_shortcut_apps --S--")
    TRC_MSG(TRC_MMI_AM_SEARCH_SHORTCUT_APPS_E, "[VRE] mmi_am_search_shortcut_apps --E--")
    TRC_MSG(TRC_MMI_AM_SEARCH_APPSTORE_S, "[VRE] mmi_am_search_appstore --S--")
    TRC_MSG(TRC_MMI_AM_SEARCH_APPSTORE_E1, "[VRE] mmi_am_search_appstore --E1-- <appstore in memory card>")
    TRC_MSG(TRC_MMI_AM_SEARCH_APPSTORE_E2, "[VRE] mmi_am_search_appstore --E2-- <appstore in phone>")
    TRC_MSG(TRC_MMI_AM_SEARCH_APPSTORE_E3, "[VRE] mmi_am_search_appstore --E1-- <appstore is not in memory card and phone>")
    TRC_MSG(TRC_MMI_AM_SEARCH_APPSTORE_IN_ROM, "[VRE] mmi_am_search_appstore_in_rom <appstore in rom>")
    TRC_MSG(TRC_MMI_AM_SEARCH_ROM_APPS_S, "[VRE] mmi_am_search_rom_apps --S--")
    TRC_MSG(TRC_MMI_AM_SEARCH_ROM_APPS_E, "[VRE] mmi_am_search_rom_apps --E--")
    TRC_MSG(TRC_MMI_AM_ADD_VXP_FILE_LIST_POSTION, "[VRE] mmi_am_add_vxp_file_list <position:%d>")
    TRC_MSG(TRC_MMI_AM_CHECK_DL_BY_AS_S, "[VRE] mmi_am_check_downloaded_app_by_as --S-- <is_card_plug_in:%d>")
    TRC_MSG(TRC_MMI_AM_CHECK_DL_BY_AS_PLUG_IN_1, "[VRE] mmi_am_check_downloaded_app_by_as <list does not in memory card>")
    TRC_MSG(TRC_MMI_AM_CHECK_DL_BY_AS_PLUG_IN_2, "[VRE] mmi_am_check_downloaded_app_by_as <list does not in phone>")
    TRC_MSG(TRC_MMI_AM_CHECK_DL_BY_AS_LIST_NUM, "[VRE] mmi_am_check_downloaded_app_by_as <num_of_list:%d>")
    TRC_MSG(TRC_MMI_AM_CHECK_DL_BY_AS_E1, "[VRE] mmi_am_check_downloaded_app_by_as --E1--")
    TRC_MSG(TRC_MMI_AM_CHECK_DL_BY_AS_E2, "[VRE] mmi_am_check_downloaded_app_by_as --E2--")
    TRC_MSG(TRC_MMI_AM_DL_FROM_MM_ENTRY_ASK_SCRN_S, "[VRE] mmi_am_download_from_mm_entry_ask_scrn --S--")
    TRC_MSG(TRC_MMI_AM_DL_FROM_MM_ENTRY_ASK_SCRN_E, "[VRE] mmi_am_download_from_mm_entry_ask_scrn --E--")
    TRC_MSG(TRC_MMI_AM_DL_APP_FROM_MM_S, "[VRE] mmi_am_download_app_from_mm --S--")
    TRC_MSG(TRC_MMI_AM_DL_APP_FROM_MM_E1, "[VRE] mmi_am_download_app_from_mm --E1--")
    TRC_MSG(TRC_MMI_AM_DL_APP_FROM_MM, "[VRE] mmi_am_download_app_from_mm <ret:%d, dl_app_id:%d>")
    TRC_MSG(TRC_MMI_AM_DL_APP_FROM_MM_E2, "[VRE] mmi_am_download_app_from_mm --E2--")
    TRC_MSG(TRC_MMI_AM_DL_APP_FROM_MM_DEINIT_S, "[VRE] mmi_am_download_app_from_mm_deinit --S-- <adm_pool_id:%d, dyn_mem_pool:%d, is_quick_start:%d, is_download:%d, quick_start_flag:%d, is_vre_init:%d>")
    TRC_MSG(TRC_MMI_AM_DL_APP_FROM_MM_DEINIT_E, "[VRE] mmi_am_download_app_from_mm_deinit --E--")
    TRC_MSG(TRC_MMI_AM_DEL_DL_FROM_MM_ASK_SCRN_S, "[VRE] mmi_am_del_download_from_mm_ask_scrn --S-- <is_download:%d>")
    TRC_MSG(TRC_MMI_AM_DEL_DL_FROM_MM_ASK_SCRN_E, "[VRE] mmi_am_del_download_from_mm_ask_scrn --E-- <is_download:%d>")
    TRC_MSG(TRC_MMI_AM_LEAVE_DL_FROM_MM_ASK_SCRN_S, "[VRE] mmi_am_leave_download_from_mm_ask_scrn --S-- <is_download:%d>")
    TRC_MSG(TRC_MMI_AM_LEAVE_DL_FROM_MM_ASK_SCRN_E, "[VRE] mmi_am_leave_download_from_mm_ask_scrn --E-- <is_download:%d>")
    TRC_MSG(TRC_MMI_AM_DOWNLOAD_APP_DONE_S, "[VRE] mmi_am_download_app_done --S-- <is_quick_start:%d>")
    TRC_MSG(TRC_MMI_AM_DOWNLOAD_APP_DONE_E, "[VRE] mmi_am_download_app_done --E--")
    TRC_MSG(TRC_MMI_AM_DOWNLOAD_FROM_MM_ENTRY_CONFIRM_SCRN_S, "[VRE] mmi_am_download_from_mm_entry_confirm_scrn --S--")
    TRC_MSG(TRC_MMI_AM_DOWNLOAD_FROM_MM_ENTRY_CONFIRM_SCRN_E, "[VRE] mmi_am_download_from_mm_entry_confirm_scrn --E--")
/* Vogins End */

END_TRACE_MAP(MOD_MMI_FW)

#endif /* _MMI_FW_TRC_H_ */


