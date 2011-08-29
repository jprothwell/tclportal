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

#ifndef GEN_FOR_PC
   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before mmi_trc.h"
   #endif
#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before mmi_trc.h"
#endif

#ifndef __GNUC__
#include "kal_release.h"        /* Target or MNT */
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
#define MMI_FW_TRC_G9_RESERVED    TRACE_GROUP_9
#define MMI_FW_TRC_G10_GDI        TRACE_GROUP_10
#define MAX_FW_TRACE_LOG_TYPE     (MMI_FW_TRC_G10_GDI+1)
#else /* __GNUC__ */ 
typedef enum
{
    MMI_FW_TRC_FUNC = 0,
    MMI_FW_TRC_STATE,
    MMI_FW_TRC_INFO,
    MMI_FW_TRC_WARNING,
    MMI_FW_TRC_ERROR,

    MMI_FW_TRC_G1_FRM,
    MMI_FW_TRC_G2_GUI,
    MMI_FW_TRC_G3_CAT,
    MMI_FW_TRC_G4_EDITOR,
    MMI_FW_TRC_G5_IME,
    MMI_FW_TRC_G6_FRM_DETAIL,
    /* MTI IRE TRACE UPDATION START */
    MMI_FW_TRC_G7_IRE,
    /* MTI IRE TRACE UPDATION END */
    MMI_FW_TRC_G8_RESERVED,
    MMI_FW_TRC_G9_RESERVED,
    MMI_FW_TRC_G10_GDI,
    MAX_FW_TRACE_LOG_TYPE
} mmi_fw_app_log_type_enum;
#endif /* __GNUC__ */ 



/* For MOD_MMI_FW */
BEGIN_TRACE_MAP(MOD_MMI_FW)

    //Framework
    //Event.c, Init related
    TRC_MSG(MMI_FRM_FUN_EVENT_INIT, "InitFramework")
    TRC_MSG(MMI_FRM_FUN_EVENT_DEINIT_KEY_EVENT,"[Key] DeInitFramework_KeyAndEventHandler")
    TRC_MSG(MMI_FRM_FUN_EVENT_DEINIT_HISTORY,"[History] DeInitFramework_History")
    TRC_MSG(MMI_FRM_FUN_EVENT_DEINIT,"DeInitFramework")
    //Event.c, Exec Protocol related
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURKEY_HDLR,"[Key] [Keypad Lock] ExecuteCurrKeyHandler: Timer %d start")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURKEY_KEYCODE_HDLR,"[Key] ExecuteCurrKeyHandler: <keyHandler 0x%x, keyCode %Mmmi_keypads_enum, keyType %Mmmi_key_types_enum>   ")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURPTO_INTP_HDLR, "[Protocol] ExecuteCurrProtocolHandler: <execute interrupt handler <id %Mmsg_type>")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURPTO_HDLR, "[Protocol] ExecuteCurrProtocolHandler: <execute protocol handler <id %Mmsg_type>")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURPTO_NO_HDLR, "[Protocol] ExecuteCurrProtocolHandler: <message is not process <id %Mmsg_type>")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXIT_HDLR, "[Screen] ExecuteCurrExitHandler_Ext: <execute exit handler>")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXIT_SUBLCD_HDLR, "[Screen] ExecuteCurrSubLcdExitHandler")
    //Event.c, Hilite related
    TRC_MSG(MMI_FRM_INFO_EVENT_EXECURHILIHTE_HDLR, "[Menu] ExecuteCurrHiliteHandler: execute hilite handler id %MGLOBALMENUITEMSID  funcPtr 0x%x>")
    TRC_MSG(MMI_FRM_ERROR_EVENT_EXECURHILIHTE_HDLR, "[Menu] ExecuteCurrHiliteHandler: In ExecuteCurrHiliteHandler but the Parent is Zero")
    TRC_MSG(MMI_FRM_INFO_EVENT_SETCURHILIHTE_HDLR, "[Menu] SetHiliteHandler: <set hilite item handler id %MGLOBALMENUITEMSID funcPtr 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRCURHILIHTE_HDLR, "[Menu] ClearHiliteHandler: <clear hilite item handler id %MGLOBALMENUITEMSID>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRALLHILIHTE_HDLR, "[Menu] ClearAllHiliteHandler: <clears hilite item handler >")
    //Event.c, Hint related
    TRC_MSG(MMI_FRM_INFO_EVENT_SETHINT_HDLR, "[Menu] SetHintHandler: <set hint item handler id %MGLOBALMENUITEMSID funcPtr 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRHINT_HDLR, "[Menu] ClearHintHandler: <clear hint item handler id %MGLOBALMENUITEMSID>")
    //Menu list related
    TRC_MSG(MMI_FRM_INFO_EVENT_SETPARENT_HDLR, "[Menu] SetParentHandler: <set parent item id %MGLOBALMENUITEMSID>")
    //Event.c, Key related
    TRC_MSG(MMI_FRM_INFO_EVENT_SETKEY_HDLR, "[Key] SetKeyHandler: <register key handler; keyCode %Mmmi_keypads_enum, keyType %Mmmi_key_types_enum, funcPtr 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_SETGROUPKEY_HDLR, "[Key] SetGroupKeyHandler: < Group size %d, keyType %Mmmi_key_types_enum, funcPtr 0x%x >")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRKEY_HDLR, "[Key] ClearKeyHandler: <clear key handler <keyCode %Mmmi_keypads_enum, keyType %Mmmi_key_types_enum>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRALLKEY_HDLR, "[Key] ClearAllKeyHandler: <clear all key handlers>")
    //Event.c, Protocol related
    TRC_MSG(MMI_FRM_INFO_EVENT_SETPTO_HDLR, "[Protocol] SetProtocolEventHandler: <event, handler>=%Mmsg_type, 0x%x;  <used/max>=%d, %d")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRPTO_HDLR, "[Protocol] ClearProtocolEventHandler: <clears protocol event handler %Mmsg_type>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRALLPTO_HDLR, "[Protocol] ClearAllProtocolEventHandler: <clears all the protocol event handler>")
    TRC_MSG(MMI_FRM_INFO_EVENT_SETSLPTO_HDLR, "[Protocol][SLAVE] SetSlaveProtocolEventHandler: <event, handler>=%Mmsg_type, 0x%x;  <used/max>=%d, %d")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRSLPTO_HDLR, "[Protocol][SLAVE] ClearSlaveProtocolEventHandler: <clears protocol event handler %Mmsg_type>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRSLALLPTO_HDLR, "[Protocol][SLAVE] ClearAllSlaveProtocolEventHandler: <clears all the protocol event handler>")
    //Event.c, Entry funtcion related
    TRC_MSG(MMI_FRM_INFO_EVENT_ENTRYSCR_HDLR, "[Screen] EntryNewScreen: <Enter the new screen ID=%Mmmi_screen_id_cgen_enum ExitFuncPtr = 0x%x EntryFuncPtr = 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_SETENTRY_HDLR, "[Screen] SetEntryHandler: <set current screen ID=%Mmmi_screen_id_cgen_enum entry handler FuncPtr = 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_SETEXIT_HDLR, "[Screen] SetExitHandler: <sets current screen ID=%Mmmi_screen_id_cgen_enum exit handler FuncPtr = 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRENTRY_HDLR, "[Screen] ClearEntryHandler: <clear current screen entry handler>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLREXIT_HDLR, "[Screen] ClearExitHandler: <clear current screen exit handler>")
    TRC_MSG(MMI_FRM_INFO_EVENT_ORDERLY_EXIT_INFO, "[Screen] Orderly exit screen")
    //Event.c, Generic function related
    TRC_MSG(MMI_FRM_INFO_EVENT_SETGEN_EXIT_HDLR, "[Screen] SetGenericExitHandler: <sets generic screen ID=%Mmmi_screen_id_cgen_enum exit handler>")
    TRC_MSG(MMI_FRM_INFO_EVENT_EXEGEN_EXIT_HDLR, "[Screen] GenericExitScreen: <exec generic screen ID=%Mmmi_screen_id_cgen_enum exit handler EntryFuncPtr = 0x%x>")
    TRC_MSG(MMI_FRM_INFO_EVENT_GETGEN_EXIT_HDLR, "[Screen] GetExitScrnID: <Get the screen ID=%Mmmi_screen_id_cgen_enum  that will be exited.>")
    //Event.c, Interrupt funtcion related
    TRC_MSG(MMI_FRM_INFO_EVENT_SETINTP_HDLR, "[Protocol] SetInterruptEventHandler: <set interrupt event handler %Mmsg_type>")
    TRC_MSG(MMI_FRM_INFO_EVENT_SETGRPINTP_HDLR, "[Protocol] SetGroupInterruptEventHandler: <set group interruptEvent handler %Mmsg_type>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRINTP_HDLR, "[Protocol] ClearInterruptEventHandler: <clears interrupt event handler %Mmsg_type>")
    TRC_MSG(MMI_FRM_INFO_EVENT_CLRALLINTP_HDLR, "[Protocol] ClearAllInterruptEventHandler: <clears all the interrupt event handler>")
    //event_handler.c New interrup function related
    TRC_MSG(MMI_FRM_INFO_EVENT_BLOCK_INT_HDLR, "[Event handler] mmi_frm_block_interrupt_event_handler: <block interrupt event %d>")
    TRC_MSG(MMI_FRM_INFO_EVENT_BLOCK_GEN_INT_HDLR, "[Event handler] mmi_frm_block_general_interrupt_event: <block interrupt event %d>")

    //History.c, 
    TRC_MSG(MMI_FRM_INFO_HIST_ADD_HISTREFMEMREC_HDLR, "[History] AddHistoryReferenceMemoryRecord: <exe(bool) = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_ADD_HISTREF_HDLR, "[History] AddHistoryReference: <exe(bool) = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_ADD_NHIST_HDLR, "[History] AddNHistory: <size =%d, exe(bool) =%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_ADD_HIST_EX_HDLR, "[History] AddHistoryEx: <exe(bool) = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_HIST_HDLR, "[History] GetHistory: <screen ID =%Mmmi_screen_id_cgen_enum, history index=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_HIST_SCRID_HDLR, "[History] GetHistoryScrID: <screen ID =%Mmmi_screen_id_cgen_enum, history index=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_NHIST_HDLR, "[History] GetNHistory: <screen ID =%Mmmi_screen_id_cgen_enum, history index=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_GO_BACK_HIST_HDLR, "[History] GoBackHistory")
    TRC_MSG(MMI_FRM_INFO_HIST_GO_BACK_TO_HIST_HDLR, "[History] GoBackToHistory: <screen ID=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_GO_BACK_NHIST_HDLR, "[History] GoBacknHistory: <nHistory ID=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_EXE_POP_HIST_HDLR, "[History] ExecutePopHistory: <top/exit scrnid = %Mmmi_screen_id_cgen_enum/%Mmmi_screen_id_cgen_enum, IsBackHistory=%d, CheckMainLCDHistoryBack=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_EXE_SMALL_SCREEN_BEGIN, "[History] [Small Screen] Begin <target idx=%d, full-screen idx=%d> ")
    TRC_MSG(MMI_FRM_INFO_HIST_EXE_SMALL_SCREEN, "[History] [Small Screen] <ScrnId = %Mmmi_screen_id_cgen_enum, entryFuncPtr = %x>")
    TRC_MSG(MMI_FRM_INFO_HIST_EXE_SMALL_SCREEN_END, "[History] [Small Screen] End, then active screen <ScrnId = %Mmmi_screen_id_cgen_enum, entryFuncPtr = %x>")
    TRC_MSG(MMI_FRM_INFO_DEL_SCRS_HDLR, "[History] DeleteScreens: <startScrId=%Mmmi_screen_id_cgen_enum, EndScrId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_DEL_BEYOND_SCR_TILL_SCR_HDLR, "[History] DeleteBeyondScrTillScr: <beyondScrnid=%Mmmi_screen_id_cgen_enum, tillScrnid=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_DEL_BETWEEN_SCR_HDLR, "[History] DeleteBetweenScreen: <StartScrId=%Mmmi_screen_id_cgen_enum, EndScrId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_DEL_SCR_IF_PRESENT_HDLR, "[History] DeleteScreenIfPresent: <ScrId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_DEL_SCR_FROM_TO_N_NODE_HDLR, "[History] DeleteScreenFromToNnodes: <ScrId=%Mmmi_screen_id_cgen_enum, DeleteCount = %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_DEL_FROM_SCR_UPTO_SCR_HDLR, "[History] DeleteFromScrUptoScr: <FromScrId=%Mmmi_screen_id_cgen_enum, UptoScrId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_INSERT_HIST_BEFORE_SCREEN_HDLR, "[History] InsertHistoryBeforeThisScrnReference: <ScrId=%Mmmi_screen_id_cgen_enum>")   
    TRC_MSG(MMI_FRM_INFO_HIST_GET_CUR_INPUT_BUF_HDLR, "[History] GetCurrInputBuffer: <ScrId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_CUR_NINPUT_BUF_HDLR, "[History] GetCurrNInputBuffer: <ScrId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_HIST_GET_CUR_GUI_BUF_HDLR, "[History] GetCurrGuiBuffer: <ScrId=%Mmmi_screen_id_cgen_enum, cur History idx=%d>")
    TRC_MSG(MMI_FRM_INFO_HIST_DUMP_HDLR, "[History] HistoryDump: <History Dump><SCRN_ID>index = %d [%Mmmi_screen_id_cgen_enum]")
    TRC_MSG(MMI_FRM_INFO_HIST_REPLACE_HDLR, "[History] HistoryReplace: <History Replace><dst_id=%Mmmi_screen_id_cgen_enum, scr_id=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_EXEC_CURR_HIST_HDLR, "[History] ExecutecurrHisIndEntryFunc")
    TRC_MSG(MMI_FRM_INFO_DEL_NHIST_HDLR, "[History] DeleteNHistory: <DeleteCount = %d>")
    TRC_MSG(MMI_FRM_INFO_DEL_UPTO_SCRID_HDLR, "[History] DeleteUptoScrID: <scrnid = %Mmmi_screen_id_cgen_enum, cur History idx=%d>")
    TRC_MSG(MMI_FRM_INFO_GO_BEYOND_MARKER_SCR_HDLR, "[History] GoBeyondMarkerScr: <scrnid = %Mmmi_screen_id_cgen_enum, cur History idx=%d>")
    TRC_MSG(MMI_FRM_INFO_DEL_NSCRID_HDLR, "[History] DeleteNScrId: <scrnid = %Mmmi_screen_id_cgen_enum, cur History idx=%d>")
    TRC_MSG(MMI_FRM_INFO_IS_SCR_PRESENT_HDLR, "[History] IsScreenPresent: <scrnid = %Mmmi_screen_id_cgen_enum, present(bool)=%d>")
    TRC_MSG(MMI_FRM_INFO_GET_PREVIOUS_SCR_IDOF_HDLR, "[History] GetPreviousScrnIdOf: <scrnid = %Mmmi_screen_id_cgen_enum, previousScrnId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_GET_PREVIOUS_SCR_IDOF_2_HDLR, "[History] GetPreviousScrnIdOf: <scrnid = %Mmmi_screen_id_cgen_enum, NO previousScrnId>")
    TRC_MSG(MMI_FRM_INFO_IS_CUR_MARKER_SCR_HDLR, "[History] IsCurrMarkerScreen: <scrnid = %Mmmi_screen_id_cgen_enum, historyData[currHistoryIndex].scrnID=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_EXEC_ROOT_HIST_HDLR, "[History] [History] ExecuteRootMainHistoryScreen: <currHistoryIndex=%d, Status=%d>")
    TRC_MSG(MMI_FRM_INFO_DINIT_HIST_HDLR, "[History] DinitHistory")
    TRC_MSG(MMI_FRM_INFO_DEL_BETWEEN_SCRS_HDLR, "[History] DeleteBetweenScreens: <StartScrId=%Mmmi_screen_id_cgen_enum, EndScrId=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SET_SCREEN_ID_CB_HDLR, "[History] SetDelScrnIDCallbackHandler: <ScrnID=%Mmmi_screen_id_cgen_enum, funcPtr=%x>")
    TRC_MSG(MMI_FRM_INFO_CLR_SCREEN_ID_CB_HDLR, "[History] ClearDelScrnIDCallbackHandler: <ScrnID=%Mmmi_screen_id_cgen_enum, funcPtr=%x>")
    TRC_MSG(MMI_FRM_INFO_EXEC_TOP_SCRN_CB_HDLR, "[History] ExecTopScrnCallbackHandler: <is_stop_delete=%d>")
    TRC_MSG(MMI_FRM_INFO_SRCH_DEL_SCRN_CB_HDLR, "[History] SearchDelScrnIDCallbackHandler: <ScrnID=%Mmmi_screen_id_cgen_enum is found in history_idx=%d>")
    TRC_MSG(MMI_FRM_INFO_DEL_HISTORY_HDLR, "[History] DeleteHistory: <startId=%Mmmi_screen_id_cgen_enum, inc=%d, count=%d, endId=%Mmmi_screen_id_cgen_enum, inc=%d>")   
    TRC_MSG(MMI_FRM_INFO_DEL_HISTORY_INDEX_HDLR, "[History] DeleteHistory: <currHistoryIndex=%d, startIdx=%d, endIdx=%d>")
    TRC_MSG(MMI_FRM_INFO_SET_ORDERLY_EXIT_SCREEN_HDLR, "[history] void mmi_set_orderly_exit_screen(void)")
    TRC_MSG(MMI_FRM_INFO_EXEC_HIST_SCRN_CB_STRAT, "[History] ExecHistoryScrnCallBackHandle Start <ScrnID=%Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_EXEC_HIST_SCRN_CB_END, "[History] ExecHistoryScrnCallBackHandle End <ScrnID=%Mmmi_screen_id_cgen_enum><is_stop_allow=%d>")
    TRC_MSG(MMI_FRM_INFO_DEL_HISTORY_END, "[History] DeleteHistory end <delCount %d>")
    TRC_MSG(MMI_FRM_INFO_HIST_EXE_POP_HIST_END, "[History] ExecutePopHistory: <END>")

    //SublcdHistory.c, 
    TRC_MSG(MMI_FRM_INFO_SUBHIST_EXE_SUBLCD_CUR_EXIT_HDLR, "[Sub-History] ExecSubLCDCurrExitHandler")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_HIST_HDLR, "[Sub-History] AddSubLCDHistory")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_HIST_WITHSCRID_HDLR, "[Sub-History] AddSubLCDHistoryWithScrID: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_EXIT_HDLR, "[Sub-History] SetSubLCDExitHandler: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_ADD_SUBLCD_ENTRY_HDLR, "[Sub-History] SetSubLCDEntryHandler: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_INIT, "[Sub-History] InitSubLCDHistory: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEINIT, "[Sub-History] DinitSubLCDHistory")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_SHOW_SUBLCD_HDLR, "[Sub-History] ShowSubLCDScreen: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_FORCE_SUBLCD_HDLR, "[Sub-History] ForceSubLCDScreen: %x")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DISPLAY_SUBLCD_HDLR, "[Sub-History] DisplaySubLCDScreen: %x, <scrnid = %Mmmi_screen_id_cgen_enum>, <force_display = %d>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_GO_BACK_SUBLCD_HDLR, "[Sub-History] GoBackSubLCDHistory")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_GO_BACK_N_SUBLCD_HDLR, "[Sub-History] GoBacknSubLCDHistory: %d")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_GO_BACK_TO_SUBLCD_HDLR, "[Sub-History] GoBackToSubLCDHistory: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_GO_BEYOND_SUBLCD_HDLR, "[Sub-History] GoBeyondSubLCDMarkerScr: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_BACK_BOTHLCD_HIST_HDLR, "[Sub-History] GoBackBothLCDHistory")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_SUBLCD_IDLE_SCRN_HDLR, "[Sub-History] SubLCDIdleScreen")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_UPTO_SUBLCD_SCR_HDLR, "[Sub-History] DeleteUptoSubLCDScrID: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_N_SUBLCD_SCR_HDLR, "[Sub-History] DeleteNSubLCDScrId: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_SUBLCD_SCR_HDLR, "[Sub-History] DeleteSubLCDScreen: <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_SUBLCD_SCR_NUM, "[Sub-History] DeleteNSubLCDHistory: %d")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_BEYOND_TILL_SUBLCD_SCR_HDLR, "[Sub-History] DeleteBeyondSubLCDScrTillScr: <Beyond scrnid = %Mmmi_screen_id_cgen_enum>, <Till scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DEL_BETWEEN_SUBLCD_SCR_HDLR, "[Sub-History] DeleteBetweenSubLCDScreen: <scrnid = %Mmmi_screen_id_cgen_enum> to <scrnid = %Mmmi_screen_id_cgen_enum>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_REPLACE_SUBLCD_SCR_HDLR, "[Sub-History] SubLCDHistoryReplace: <out_scrn_id = %Mmmi_screen_id_cgen_enum> <in_scrn_id = %Mmmi_screen_id_cgen_enum, in_src_func = %x>")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DUMP_HDLR, "[Sub-History] SubLCDHistoryDump: <SubLCDHistory Dump> index,<SCRN_ID>,(entryFuncPtr) = %d,[%Mmmi_screen_id_cgen_enum],(%d)")
    TRC_MSG(MMI_FRM_INFO_SUBHIST_DUMP_ROOTHDLR, "[Sub-History] SubLCDHistoryDump: <SubLCDHistory Dump> index = -1,[0],(RootSubLcdHistoryScreenPtr)")

    TRC_MSG(MMI_FRM_SUBHIST_SWITCH_MODE_S2M, "[Sub-History] SwitchSubLCDHistory (S2M)")
    TRC_MSG(MMI_FRM_SUBHIST_SWITCH_MODE_M2S, "[Sub-History] SwitchSubLCDHistory (M2S)")
    TRC_MSG(MMI_FRM_SUBHIST_CLEAR_MASTER_HIST, "[Sub-History] ClearSubLCDMasterHistory")
    TRC_MSG(MMI_FRM_SUBHIST_FORCE_EXIT_CURR_SCR, "[Sub-History] ForceExitCurrScr")
    TRC_MSG(MMI_FRM_SUBHIST_MASTER_GOBACK_HIST, "[Sub-History] SubLCDMasterGoBackHistory")

    // sublcd_master
    TRC_MSG(MMI_FRM_ENTRY_SUBLCDMASTER_FROM_IDLE, "[Sub-Master] EntrySubLCDMasterFromIdle")
    TRC_MSG(MMI_FRM_FORCE_ENTRY_SUBLCD_MASTER, "[Sub-Master] ForceEntrySubLCDMaster")
    TRC_MSG(MMI_FRM_FORCE_ENTRY_SUBLCD_SLAVE, "[Sub-Master] ForceEntrySubLCDSlave")
    TRC_MSG(MMI_FRM_EXIT_MAINLCD_DUMMY_SCRN_TIMEOUT, "[Sub-Master] ExitMainLCDDummyScreenTimeOut")
    TRC_MSG(MMI_FRM_ENTRY_MAINLCD_DUMMY_SCRN, "[Sub-Master] EntryMainLCDDummyScreen")
    TRC_MSG(MMI_FRM_SET_SUBLCD_IN_MASTER_MODE, "[Sub-Master] SetSubLCDInMasterMode")
    TRC_MSG(MMI_FRM_SET_SUBLCD_IN_SLAVE_MODE, "[Sub-Master] SetSubLCDInSlaveMode")
    TRC_MSG(MMI_FRM_MASTER_MODE_CLAM_OPEN, "[Sub-Master] SubLCDMasterModeClamOpen")
    TRC_MSG(MMI_FRM_MASTER_MODE_CLAM_CLOSED, "[Sub-Master] SubLCDMasterModeClamclosed")



    //KeyBrd.c, 
    TRC_MSG(MMI_FRM_INFO_PROC_KEYEVENT_HDLR, "[Key] ProcessKeyEvent: <MsgType=%Mmmi_key_types_enum, Keycode=%Mmmi_keypads_enum>")
    TRC_MSG(MMI_FRM_ERROR_PROC_KEYEVENT_HDLR, "[Key] ProcessKeyEvent not handler")
    TRC_MSG(MMI_FRM_ERROR_KEY_TIMER_EXPIRY_HDLR, "(win32) KeyTimerExpiryProc: Unknown timer id =%d")
    TRC_MSG(MMI_FRM_INFO_CLEAR_KEY_EVENTS_HDLR, "[Key] ClearKeyEvents")
    TRC_MSG(MMI_FRM_INFO_PROC_TIMER_EVENT_HDLR, "(win32) ProcessTimerEvent: <MsgType=%d, Keycode=%d>")
    TRC_MSG(MMI_FRM_KEY_CONCURRENT_MODE, "[Key] set concurrent mode to [%Mmmi_frm_concurrent_key_mode_enum]")
    TRC_MSG(MMI_FRM_KEY_REVERSE_CODE, "[Key] mmi_kbd_reverse_code: return %d")
    TRC_MSG(MMI_FRM_KEY_TONE_HDLR, "[Key] key event <<code %d, type %d>>")
    TRC_MSG(MMI_FRM_KEY_HDLR_END, "[Key] mmi_frm_key_handle end")    
    TRC_MSG(MMI_FRM_KEY_HDLR_DISABLED, "[key] [%Mmmi_keypads_enum, %Mmmi_key_types_enum] hdlr disabled by func. 0x%x")

    //Queue.c, 
    TRC_MSG(MMI_FRM_INFO_QUEUE_READ_HDLR, "[QUEUE] OslReadCircularQ: <#[%d], read:[%d], write:[%d]>")
    TRC_MSG(MMI_FRM_INFO_QUEUE_WRITE_HDLR, "[QUEUE] OslWriteCircularQ: <#[%d], read:[%d], write:[%d]>")
    TRC_MSG(MMI_FRM_INFO_QUEUE_PROCESSED_MSG, "[QUEUE] Processed a message")

    //L4Drv.c. 
    TRC_MSG(MMI_FRM_INFO_L4DRV_CBTIMER_HDLR, "[Timer] L4CallBackTimer: <expire timer id=%MMMI_TIMER_IDS, address=0x%8x>")
    TRC_MSG(MMI_FRM_INFO_L4DRV_STARTTIMER_HDLR, "[Timer] L4StartTimer: <start timer id=%MMMI_TIMER_IDS, address=0x%8x, dur=%d, ali=%d>")
    TRC_MSG(MMI_FRM_INFO_L4DRV_STOPTIMER_HDLR, "[Timer] L4StopTimer: <stop timer id=%MMMI_TIMER_IDS>")

    //NvramInterface.c 
    TRC_MSG(MMI_FRM_INFO_NVM_WRITE_HDLR, "[NVRAM] After Calling Send_ILM from SendNVRAMWriteReq!")
    TRC_MSG(TRC_SEND_NVRAM_READ_REQ, "[MMI][NVRAM] SendNVRAMReadReq(), Send Read NVRAM request to L4")
    TRC_MSG(MMI_FRM_INFO_NVM_READ_REC_INT_HDLR, "[NVRAM] Request of Reading record <from NvramID: [%d] RecID: [%d]>")
    TRC_MSG(MMI_FRM_INFO_NVM_WRITE_REC_INT_HDLR, "[NVRAM] Request of Writing record <from NvramID: [%d] RecID: [%d]>")
    TRC_MSG(MMI_FRM_INFO_NVM_DELETE_REC_INT_HDLR, "[NVRAM] Inside Delete record")
    TRC_MSG(MMI_FRM_INFO_NVM_READ_VAL_INT_HDLR, "[NVRAM] ReadValueInt: <nDataItemId: [%d] nDataType : [%d]>")
    TRC_MSG(MMI_FRM_INFO_NVM_READ_VAL_INT_INFO_HDLR, "[NVRAM] NVRAM is already read, reading DataType: [%d]")
    TRC_MSG(MMI_FRM_INFO_NVM_READ_VAL_INT_INFO2_HDLR, "[NVRAM] NVRAM record read then reading DataType: [%d]")
    TRC_MSG(MMI_FRM_ERROR_NVM_READ_VAL_INT_HDLR, "[NVRAM] ERROR in NVRAM record read")
    TRC_MSG(MMI_FRM_INFO_NVM_WRITE_VAL_INT_HDLR, "[NVRAM] WriteValueInt: <nDataItemId: [%d] nDataType : [%d]>")
    TRC_MSG(MMI_FRM_INFO_NVM_WRITE_VAL_INT_INFO_HDLR, "[NVRAM] NVRAM is already read, writing <DataType: [%d]>")
    TRC_MSG(MMI_FRM_INFO_NVM_WRITE_VAL_INT_INFO2_HDLR, "[NVRAM] NVRAM record read then writing <DataType: [%d]>")
    TRC_MSG(MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR, "[NVRAM] ERROR in NVRAM record write!")
    TRC_MSG(MMI_FRM_INFO_NVM_FLASH_CATCH_DATA_HDLR, "[NVRAM] SetFlashNVRAMCatchData: <DataType: [%d], WriteFlashFlag: [%d]>")
    TRC_MSG(MMI_FRM_INFO_NVM_FLASH_CATCH_ALL_DATA_HDLR, "[NVRAM] SetFlashAllNVRAMCatchData: <WriteFlashFlag: [%d]>")
    TRC_MSG(MMI_FRM_INFO_NVM_WRITE_NVM_CATCH_DATA_HDLR, "[NVRAM] WriteFlashNVRAMCatchData: <DataType: [%d]>")
    TRC_MSG(MMI_FRM_WARN_NVM_WRITE_HDLR, "[NVRAM] No this case!!")
    TRC_MSG(MMI_FRM_INFO_NVM_FLASH_ALL_CATCH_DATA_HDLR, "[NVRAM] WriteFlashAllNVRAMCatchData!")
    TRC_MSG(MMI_FRM_INFO_NVM_TIME_OUT_IS_NOT_VALID, "[NVRAM] Time out is not valid")
    TRC_MSG(MMI_FRM_INFO_NVM_READ_SUCCESS, "[NVRAM] NVRAM Read Success")
    TRC_MSG(MMI_FRM_INFO_NVM_READ_FAILED, "[NVRAM] NVRAM Read Failed. Cause: %d")
    TRC_MSG(MMI_FRM_INFO_NVM_EXITING_READ_REC_STATUS,"[NVRAM] Exiting Reading record status = %d")
    TRC_MSG(MMI_FRM_INFO_NVM_WRITE_SUCCESS, "[NVRAM] NVRAM Write Success")
    TRC_MSG(MMI_FRM_INFO_NVM_WRITE_FAILED, "[NVRAM] NVRAM Write Failed. Cause: %d")
    TRC_MSG(MMI_FRM_INFO_NVM_EXITING_WRITE_REC, "[NVRAM] Exiting Wriring record")
    TRC_MSG(MMI_FRM_INFO_NVM_INSIDE_OK_BLOCK, "[NVRAM] Inside MMI_OK block")
    TRC_MSG(MMI_FRM_INFO_NVM_INSIDE_ERROR_BLOCK, "[NVRAM] Inside MMI_ERROR block")
    TRC_MSG(MMI_FRM_INFO_NVM_IS_PROCEDURE, "[NVRAM] IsInNVRAMProcedure(%d)")

    // Memory Manager, App-based ASM
    // AppMemMgr.c
    TRC_MSG(MMI_FRM_ASM_ENTRY_PROGRESSING_SCREEN, "[ASM] entry progressing screen: [%Mkal_bool]")
    TRC_MSG(MMI_FRM_ASM_STOP_CONFIRM_YES, "[ASM] yes to stop confirm screen: app[%Mapplib_mem_ap_id_enum] StopState[%Mmmi_frm_appmem_stop_state_enum]")
    TRC_MSG(MMI_FRM_ASM_ENTRY_PROMPT_SCREEN, "[ASM] entry prompt screen: [%Mkal_bool]")
    TRC_MSG(MMI_FRM_ASM_INVOKE_SUCCESS_CB, "[ASM] invoke success cb: app[%Mapplib_mem_ap_id_enum] cb[0x%8x]")
    TRC_MSG(MMI_FRM_ASM_STOP_FINISHED_HANDLER, "[ASM] stop finished handler: msg[%MSTRINGID_LIST_COMMON_SCREENS] cb[0x%x]")
    TRC_MSG(MMI_FRM_ASM_PROMPT_TO_RELEASE_MEM, "[ASM] prompt to release mem: app[%Mapplib_mem_ap_id_enum] size[%d]")
    TRC_MSG(MMI_FRM_ASM_PROMPT_TO_RELEASE_FULL_POOL, "[ASM] prompt to release full pool: app[%Mapplib_mem_ap_id_enum]")
    //ResMemMgr.c
    TRC_MSG(TRC_MMI_RESMEM_MEMORY_POOL_INFO,"[RESMEM] ALWAYS pool size : %d LOD pool size : %d String pool size : %d")
    TRC_MSG(TRC_MMI_RESMEM_MEMORY_ALLOCFAIL_INFO,"[RESMEM] Pool type : %M The maximal left memory size : %d, allocated memory size : %d, need to add pool size : %d!")
    TRC_MSG(TRC_MMI_RESMEM_MEMORY_STRING_POOL_INFO,"[RESMEM] The string content memory size : %d, string map size : %d, total string pool size : %d")

    //TouchScreen.c, 
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT,"[Pen] mmi_pen_check_tp_shortcut (%d, %d), event:%d")
    TRC_MSG(MMI_PEN_TRC_DROP_LOOKAHEAD_BUF, "[Pen] Drop lookahead buffer (%d - %d)")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_AREA, "[Pen] mmi_pen_check_tp_shortcut <in touch panel shortcut area (%d)>")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_DOWN, "[Pen] mmi_pen_check_tp_shortcut index:%d down")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_UP, "[Pen] mmi_pen_check_tp_shortcut index:%d up")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_MOVE, "[Pen] mmi_pen_check_tp_shortcut index:%d move")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_LONGTAP, "[Pen] mmi_pen_check_tp_shortcut index:%d longtap")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_REPEAT, "[Pen] mmi_pen_check_tp_shortcut index:%d repeat")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_ABORT, "[Pen] mmi_pen_check_tp_shortcut index:%d abort")
    TRC_MSG(MMI_PEN_TRC_CHECK_TP_SHORTCUT_DEFAULT, "[Pen] mmi_pen_check_tp_shortcut index:%d default")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR, "[Pen] mmi_pen_poll_hdlr() - %d %d")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_NO_BL, "[Pen] mmi_pen_poll_hdlr() - no backlight")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_DOWN, "[Pen] mmi_pen_poll_hdlr() - PEN_DOWN (%d, %d) time: %d")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_MOVE, "[Pen] mmi_pen_poll_hdlr() - PEN_MOVE (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_UP, "[Pen] mmi_pen_poll_hdlr() - PEN_UP (%d, %d) time: %d")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_LONGTAP, "[Pen] mmi_pen_poll_hdlr() - PEN_LONGTAP (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_REPEAT, "[Pen] mmi_pen_poll_hdlr() - PEN_REPEAT (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_PEN_ABORT, "[Pen] mmi_pen_poll_hdlr() - PEN_ABORT (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_POLL_HDLR_DELAY_POLLING_TIMER, "[Pen] mmi_pen_poll_hdlr() - delay polling timer")
    TRC_MSG(MMI_PEN_TRC_TOUCH_PANEL_EVENT_IND, "[Pen] mmi_pen_touch_panel_event_in - %d, %d")
    TRC_MSG(MMI_PEN_TRC_ENABLE, "[Pen] mmi_pen_enable()")
    TRC_MSG(MMI_PEN_TRC_DISABLE, "[Pen] mmi_pen_disable()")
    TRC_MSG(MMI_PEN_TRC_RESET, "[Pen] mmi_pen_reset()")
    TRC_MSG(MMI_PEN_TRC_CALIBRATION, "[Pen] mmi_pen_start_calibration()")
    TRC_MSG(MMI_PEN_TRC_START_CAPTURE_STROKES, "[Pen] mmi_pen_start_capture_strokes()")
    TRC_MSG(MMI_PEN_TRC_CHANGE_HANDWRITING_AREA, "[Pen] mmi_pen_change_handwriting_area()")
    TRC_MSG(MMI_PEN_TRC_STOP_CAPTURE_STROKES, "[Pen] mmi_pen_stop_capture_strokes()")
    TRC_MSG(MMI_PEN_TRC_PEEK_STROKE_STATE, "[Pen] mmi_pen_peek_stroke_state() - %d")
    TRC_MSG(MMI_PEN_TRC_BEGIN_STROKES_OF_CHAR, "[Pen] mmi_pen_begin_strokes_of_character()")
    TRC_MSG(MMI_PEN_TRC_END_STROKES_OF_CHAR, "[Pen] mmi_pen_end_strokes_of_character()")
    TRC_MSG(MMI_PEN_TRC_PEN_DOWN_HDLR, "[Pen] mmi_general_pen_down_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_UP_HDLR, "[Pen] mmi_general_pen_up_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_LONG_TAP_HDLR, "[Pen] mmi_general_pen_long_tap_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_REPEAT_HDLR, "[Pen] mmi_general_pen_repeat_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_MOVE_HDLR, "[Pen] mmi_general_pen_move_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_PEN_ABORT_HDLR, "[Pen] mmi_general_pen_abort_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_SET_DEFAULT_HDLR, "[Pen] mmi_frm_setup_default_pen_handler (%d, %d)")
    TRC_MSG(MMI_PEN_TRC_SET_EVENT_HDLR_CB, "[Pen] mmi_pen_set_callback: pre:%x, post:%x")
    TRC_MSG(MMI_PEN_TRC_RESET_EVENT_HDLR_CB, "[Pen] mmi_pen_set_callback: pre:%x, post:%x")
    TRC_MSG(MMI_PEN_TRC_CHECK_INSIDE_POLYGON, "[Pen] <%d,%d> check_inside_polygon: (%d, %d) (%d, %d) (%d, %d) (%d, %d); result:%d")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_DOWN_HDLR, "[Pen] Register pen down handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_UP_HDLR, "[Pen]Register pen up handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_LONG_TAP_HDLR, "[Pen] Register pen longtap handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_DOUBLE_CLICK_HDLR, "[Pen] Register pen double click handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_MOVE_HDLR, "[Pen] register pen move handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_REPEAT_HDLR, "[Pen] Register pen repeat handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_EVENT_ABORT_HDLR, "[Pen] Register pen abort handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_STROKE_DOWN_HDLR, "[Pen] Register stroke down handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_STROKE_UP_HDLR, "[Pen] Register stroke up handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_STROKE_LONGTAP_HDLR, "[Pen] Register stroke longtap handler 0x%X")
    TRC_MSG(MMI_PEN_TRC_REG_PEN_STROKE_MOVE_HDLR, "[Pen] Register stroke move handler 0x%X")

    //MMITask.c    
    TRC_MSG(MMI_TASK_TRC_NORMAL_POW_ON_SUCCESS_INFO, "[MMI TASK] NORMAL POWER ON SUCCESS!")
    TRC_MSG(MMI_TASK_TRC_CHARGER_POW_ON_SUCCESS_INFO, "[MMI TASK] CHARGER POWER ON SUCCESS!")
    TRC_MSG(MMI_TASK_TRC_ALARM_POW_ON_SUCCESS_INFO, "[MMI TASK] ALARM POWER ON SUCCESS!")
    TRC_MSG(MMI_TASK_TRC_EXCEPTION_POW_ON_SUCCESS_INFO, "[MMI TASK] Exception POWER ON SUCCESS!")
    TRC_MSG(MMI_TASK_TRC_USB_POW_ON_SUCCESS_INFO, "[MMI TASK] USB POWER ON SUCCESS!")
    TRC_MSG(MMI_TASK_TRC_PROTOCOL_EVENT_INFO, "[MMI TASK] protocol event %d")

    //ThemeManager.c 
    TRC_MSG(MMI_TM_TRC_ADD_IMG_ID_TO_CACHE_HDLR, "[THEME] mmi_tm_add_img_id_to_cache: img_list_index =%d, image_offset = %d type = %d")
    TRC_MSG(MMI_TM_TRC_CREATE_NON_IMAGEID_IMAGE_HDLR, "[THEME] mmi_tm_create_non_imageid_image: image_offset =%d, type = %d")
    TRC_MSG(MMI_TM_TRC_ACTIVATE_DEFAULT_THEME_HDLR, "[THEME] mmi_tm_activate_default_theme")
    TRC_MSG(MMI_TM_TRC_SET_IMAGEID_HDLR, "[THEME] mmi_tm_set_imageid: image_id =%d has type = %d")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_DOWNLOADED_THEME, "[MMI][THEME] mmi_tm_activate_downloaded_theme()")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_THEME_FROM_FMGR, "[MMI][THEME] mmi_tm_activate_theme_from_fmgr()")
    TRC_MSG(TRC_MMI_TM_DELETE_THEME, "[MMI][THEME] mmi_tm_delete_theme(), theme id: %d")
    TRC_MSG(TRC_MMI_TM_DELETE_THEME_FROM_FMGR, "[MMI][THEME] mmi_tm_delete_theme_from_fmgr(), theme type: %M")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_THEME, "[MMI][THEME] mmi_tm_activate_theme(), theme id: %d")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_THEME_AT_BOOTUP, "[MMI][THEME] mmi_tm_activate_theme_at_bootup()")
    TRC_MSG(TRC_MMI_TM_ACTIVATE_SYSTEM_THEME, "[MMI][THEME] mmi_tm_activate_system_theme(), theme id: %d")

    //event_handler.c
    TRC_MSG(MMI_EVENT_TRC_EXE_CURR_PROTOCOL_HDLR, "[EVENT] ExecuteCurrProtocolHandler count = %d")
    TRC_MSG(MMI_EVENT_TRC_EVENT_PROFILING_COUNT, "[EVENT] ExecuteCurrProtocolHandler accu_count = %d")
    TRC_MSG(MMI_EVENT_TRC_EVENT_PROFILING_TICKS, "[EVENT] ExecuteCurrProtocolHandler accu_ticks = %d")
    TRC_MSG(MMI_EVENT_TRC_EVENT_PROFILING_MAX, "[EVENT] ExecuteCurrProtocolHandler maxProtocolEvent = %d")
    TRC_MSG(MMI_EVENT_TRC_SET_PROTOCOL_EVENT_HDLR_MAX_1, "[EVENT] SetProtocolEventHandler old maxUsedInHistory = %d")
    TRC_MSG(MMI_EVENT_TRC_SET_PROTOCOL_EVENT_HDLR_MAX_2, "[EVENT] SetProtocolEventHandler maxUsedInHistory = %d")

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

    TRC_MSG(MMI_FW_BUFFER_TRACE, " *** Get data in [lower Panel] ***")

    /* Drawmanager & Categories */
    TRC_MSG(MMI_WGUI_TRC_DM_REDRAW, "[DMGR] Redraw DM_Main_Status = [%d], CatID = [%MMMI_CATEGORY_ID_LIST]")
    TRC_MSG(MMI_WGUI_TRC_DM_SUB_STATUS, "[DMGR] Redraw DM_SUB_Status = [%d]")
    TRC_MSG(MMI_WGUI_TRC_DM_MULTITAP_DEF, "[DMGR] dm_update_multitap_coordinates: Control should never come here.")
    
    /* Resgen */
    TRC_MSG(MMI_RESGEN_ALL_MENU_HIDE, "[RESGEN] All children of parent_item_id=[%d] are hidden")
    


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
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING, "[Widget] HDIa_widgetExtImageResizing()")
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING_TOO_LARGE, "[Widget] HDIa_widgetExtImageResizing() - the original image is too large")
    TRC_MSG(MMI_WIDGET_IMAGE_RESIZING_END, "[Widget] HDIa_widgetExtImageResizing() - %d")
    TRC_MSG(MMI_WIDGET_OPEN_VIDEO_FILE_DONE_HDLR_FAILED, "[Widget] widget_MMI_open_video_file_done_hdlr() - Failed")
    TRC_MSG(MMI_WIDGET_OPEN_VIDEO_FILE_DONE_HDLR_SUCCEED, "widget_MMI_open_video_file_done_hdlr() - Succeed")
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
    TRC_MSG(MMI_WIDGET_WAP_READY_TO_LEAVE_SCREEN, "[Widget] widget_ready_to_leave_screen() - return TRUE")
    TRC_MSG(MMI_WIDGET_MMI_LEAVE_SCREEN_GOBACK, "[Widget] widget_MMI_leave_screen_goback() still window left")
    TRC_MSG(MMI_WIDGET_LEAVE_SCREEN_HDLR_WITH_WINDOW, "[Widget] widget_leave_screen_hdlr() but window left")
    TRC_MSG(MMI_WIDGET_LEAVE_SCREEN_HDLR_NOT_IN_WIDGET_SCREEN, "[Widget] widget_leave_screen_hdlr() not in widget screen")
    TRC_MSG(MMI_WIDGET_LEAVE_SCREEN_HDLR, "[Widget] widget_leave_screen_hdlr() start to leave screen")
    TRC_MSG(MMI_WIDGET_PREPARE_TO_LEAVE_SCREEN, "[Widget] widget_prepare_to_leave_screen()")
    TRC_MSG(MMI_WIDGET_MMI_SHUTDOWN_WAP_UI, "[Widget] widget_MMI_shutdown_WAP_UI() - enter")
    TRC_MSG(MMI_WIDGET_MMI_SHUTDOWN_WAP_UI_END, "[Widget] widget_MMI_shutdown_WAP_UI() - end")
    TRC_MSG(MMI_WIDGET_MMI_SHUTDOWN_WAP_WIDGET_UI, "[Widget] widget_MMI_shutdown_WAP_Widget_UI() - enter")
    TRC_MSG(MMI_WIDGET_MMI_SHUTDOWN_WAP_WIDGET_UI_END, "[Widget] widget_MMI_shutdown_WAP_Widget_UI() - end")
    TRC_MSG(MMI_WIDGET_WAP_EXIT_WIDGET_SCREEN, "[Widget] wap_exit_widget_screen() - enter")
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
    TRC_MSG(MMI_WIDGET_MMI_CHECK_AND_DISPLAY_NEW_MSG_WHEN_KEYPAD_LOCK, "[Widget] widget_MMI_check_and_display_new_msg_when_keypad_lock() - with message")
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
    TRC_MSG(MMI_WIDGET_MMI_PLAY_VIDEO_GADGET, "[Widget] widget_MMI_play_vido_gadget()")
    TRC_MSG(MMI_WIDGET_MMI_SHOW_VIDEO_GADGET_PREVIEW, "[Widget] widget_MMI_show_vido_gadget_preview()")
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
    TRC_MSG(TRC_MMI_AM_OS_DOWNLOAD_ACCEPT, "[VRE] mmi_am_os_download_accept <ret:%d, dl_app_id:%d, file_name:%s>")
    TRC_MSG(TRC_MMI_AM_APP_LAUNCH_INT_PATH, "[VRE] mmi_am_app_launch_int <app_path:%s>")
    TRC_MSG(TRC_MMI_AM_VERSION, "[VRE] AM Version: %s")
/* Vogins End */

END_TRACE_MAP(MOD_MMI_FW)

#endif /* _MMI_FW_TRC_H_ */

