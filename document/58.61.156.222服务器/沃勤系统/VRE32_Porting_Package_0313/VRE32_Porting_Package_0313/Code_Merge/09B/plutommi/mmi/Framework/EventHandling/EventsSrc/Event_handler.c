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
* Event_handler.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is intends for protocol/keypad/interrupt event handler .
*
* Author:
* -------
*  Xiaodong Wang (mbj06019)
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
* $Log$
 *
 * Jan 20 2010 mtk80019
 * [MAUI_02140207] [FRM][cb mgr] Provide interface to check if event has been posted
 * Provide external api to check if event has been posted and get post event number.
 *
 * Jan 11 2010 mtk80019
 * [MAUI_02134626] [Idle]Should not show message notification in Webcam screen
 * Add interrupt event for class 0 of sms.
 *
 * Dec 25 2009 mtk80019
 * [MAUI_01914095] [SWFlash] popup "New message" when receive a message while the flash is playing
 * In mmi_frm_int_event_convert_table, revise message id since sms mech. has been changed.
 *
 * Dec 11 2009 mtk01184
 * [MAUI_02013492] Revise Screen group in W09.51 load
 * dump history in mmi_frm_invoke_post_event()
 *
 * Nov 30 2009 mtk80019
 * [MAUI_01921032] [FRM][cb mgr]Revise api naming & split event mechanism from callback manager
 * 
 *
 * Nov 26 2009 mtk80019
 * [MAUI_01919906] [FRM][events] Help provbox revise compile option __MMI_PROV_INBOX_SUPPORT__ to __MMI
 * 
 *
 * Nov 19 2009 mtk80019
 * [MAUI_01911829] [Push]Should not show the popup in the Webcam screen
 * Help revise compile option to WAP_SUPPORT in mmi_frm_int_event_convert_table.
 *
 * Nov 13 2009 mtk80019
 * [MAUI_01914056] [DM]Should not popup remind when locked by operator
 * For phone lock feature, disable all vector behavior in mmi_frm_query_interrupt_behavior to block interrupt screen.
 *
 * Oct 28 2009 mtk80019
 * [MAUI_01905563] [AGPS 2G CP] remove wap MSG
 * Revise msg id for __MMI_BROWSER_2__ in interrupt table.
 *
 * Oct 27 2009 mtk80274
 * [MAUI_01905181] [For MBJ check-in] CMCC DM LAWMO and SCOMO
 * 
 *
 * Oct 27 2009 mtk80019
 * [MAUI_01905181] [For MBJ check-in] CMCC DM LAWMO and SCOMO
 * Provide interface mmi_frm_keep_block_interrupt_event for phone lock feature.
 *
 * Oct 19 2009 mtk80019
 * [MAUI_01903335] [FRM][CB MGR] enhance trace info, add assert.
 * Add assert in mmi_post_event & mmi_post_event_ex to prevent incorrect usage by app.
 *
 * Sep 3 2009 mtk80019
 * [MAUI_01894725] [FRM] [PlutoFW2.0] Check in callback manager module
 * Add event mechanism interface.
 *
 * Jul 27 2009 mtk80250
 * [MAUI_01764722] [1]Assert Fail:0 keybrd.c 5187- MMI
 * in nvram procedure, we need to judge the current key msg's protocol event  handler to handler key events. This issue is: the protocol event handler is mmi_frm_key_handle, but in nvram procedure because the condition to do key handle for before poweron is wrong, 
 * so some key event is cleared.
 *
 * Jul 10 2009 mtk80019
 * [MAUI_01877631] [FRM] Add interrupt event for email
 * Add interrupt event for email.
 *
 * Jun 11 2009 mtk80019
 * [MAUI_01868186] [FRM][Need Patch][Build error] Patch for enhance debug info since backward compatibl
 * Remove trace in backward compatible section of mmi_frm_execute_current_protocol_handler
 *
 * Jun 5 2009 mtk80019
 * [MAUI_01866251] [FRM] Enhance debug infromation
 * 
 *
 * May 15 2009 mtk80019
 * [MAUI_01831742] Check in line-base eBook in MAUI and 09A
 * Add ebook interrupt event.
 *
 * Apr 15 2009 mtk01542
 * [MAUI_01667715] prototype change of multi protocol event handler APIs (for MBJ)
 * 
 *
 * Apr 14 2009 mtk01542
 * [MAUI_01667715] prototype change of multi protocol event handler APIs (for MBJ)
 * 
 *
 * Apr 2 2009 mtk80019
 * [MAUI_01414113] [Provisioning ProvBox]Should not display New settings on Webcom
 * Add interrupt event for prvbox new message
 *
 * Mar 31 2009 mtk01184
 * [MAUI_01645545] Add new API mmi_frm_check_wait_to_run to query MMI task status
 * Revise Plutommi header files
 *
 * Mar 18 2009 mtk80043
 * [MAUI_01410110] [Provisioning Inbox] [New feature] check in Provisioning Inbox
 * 
 *
 * Feb 23 2009 mtk80250
 * [MAUI_01394496] [FRM]modify ProtocolEventHandler the 4th para
 * 
 *
 * Jan 16 2009 mtk80019
 * [MAUI_01360287] [FOTA]Should not have this popup on Webcam
 * Add interrupt event for DM
 *
 * Nov 18 2008 mtk01542
 * [MAUI_01279090] check-in Central Control Interrupt
 * 
 *
 * Nov 5 2008 MBJ06019
 * [MAUI_01123976] [SW flash]When playing flash,should not disturb by MT MMS
 * Add mms interrupt event
 *
 * Sep 18 2008 MBJ06019
 * [MAUI_01114671] [FRM] Add interrupt event for java push install
 * 
 *
 * Sep 4 2008 MBJ06019
 * [MAUI_01110970] [FRM] Check in interrupt event for SYNCML
 * 
 *
 * Sep 3 2008 mtk01542
 * [MAUI_01232313] protocol event multi handler
 * 
 *
 * Jul 25 2008 MBJ06019
 * [MAUI_01095315] [FRM] Adjust mmi header files - stage3
 * 
 *
 * Jul 23 2008 MBJ06019
 * [MAUI_01094511] [FRM] Solve build error of event_handler.c since wap_suppress_popup
 * 
 *
 * Jul 22 2008 MBJ06019
 * [MAUI_01094178] [Build warning] event_handler.c use widget interface
 * 
 *
 * Jul 2 2008 mbj06019
 * [MAUI_01082625] [New Feature][OBIGO_Q03C_MMS_V02][FRM] Revies compile option in event_handler.c
 * 
 *
 * May 29 2008 mbj06019
 * [MAUI_01037416] [USB webcam] play  tone  is abnormal when popup ""receive vcard",
 * Add interrupt event for vcard
 *
 * May 5 2008 mbj06019
 * [MAUI_01034746] [FRM][EVENT] Add incoming call interrupt event
 * 
 *
 * Apr 16 2008 mbj06019
 * [MAUI_00103448] In call Sound recorder stops after connecting/Disconnecting USB cable.
 * Add interrupt event for usb indication
 *
 * Mar 7 2008 mtk01184
 * [MAUI_00633733] [Network setup]should not show that popup during the process of powering off
 * call mmi_frm_clear_all_slave_protocol_event_handler() in mmi_frm_clear_all_protocol_event_handler()
 *
 * Feb 22 2008 mbj06019
 * [MAUI_00629520] [FRM] [EVENT] Update event definition of interrupt mechanism and add interrupt event
 * Add certman interrupt event
 *
 * Feb 22 2008 mbj06019
 * [MAUI_00629520] [FRM] [EVENT] Update event definition of interrupt mechanism and add interrupt event
 * Add Jpush and processing low battery interrupt events
 *
 * Jan 23 2008 mbj06019
 * [MAUI_00519696] [Gemini] Merge Gemini related code back to MAUI and 07B
 * 
 *
 * Jan 9 2008 mbj06019
 * [MAUI_00515194] [Compile warning] Solve framework related compile warning
 * 
 *
 * Jan 3 2008 mbj06019
 * [MAUI_00512953] Provide framework backward compatible files
 * 
 *
 * Dec 26 2007 mbj06019
 * [MAUI_00507405] [FRM] Solve compile warning
 * Change BT header file
 *
 * Dec 10 2007 mbj06075
 * [MAUI_00502895] Divide FRM trace into different groups
 * 
 *
 * Dec 10 2007 mbj06075
 * [MAUI_00502895] Divide FRM trace into different groups
 * 
 *
 * Nov 30 2007 mbj06019
 * [MAUI_00033490] There should be no tone and popup over video recording screen.
 * Add interrupt event for wap and cca
 *
 * Nov 17 2007 mbj06019
 * [MAUI_00494183] Replace string api name and double parentheses of trace macro
 * created by clearfsimport
 *
 * Nov 3 2007 MBJ06075
 * [MAUI_00486481] MMI framework trace group adjustment
 * 
 *
 * Nov 2 2007 mbj06019
 * [MAUI_00473485] [Interrupt] during recording, should not have BT popup screen
 * Process BT interrupt event by new interface
 *
 * Oct 29 2007 MBJ06075
 * [MAUI_00486481] MMI framework trace group adjustment
 * 
 *
 * Oct 25 2007 mbj06019
 * [MAUI_00481921] [FW] Should not popup screen when receive Vcard .
 * Add interrupt event for vcard
 *
 * Oct 20 2007 mbj06019
 * [MAUI_00482146] Trace group adjustment
 * created by clearfsimport
 *
 * Sep 7 2007 mbj06019
 * [MAUI_00467176] Add trace in event_handler.c
 * Add event handler trace
 *
 * Sep 7 2007 mbj06019
 * [MAUI_00466785] Add filemanager compile option for message id
 * Add compile option for filemanage message
 *
 * Aug 28 2007 mbj06019
 * [MAUI_00461614] New interrupt mechanism
 * New file for processing event handlers
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "mmi_include.h"
#include "mmi_frm_prot.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "BTMMIScrGprots.h"
#include "Device.h"
#include "Mmi_msg_struct.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_EVENT_INVALID  0
#define INTERRUPT_EVENT_GREOUP_SIZE     (4)
#define IS_INTERRUPT_EVENT_GROUP(x)    (((x)&MMI_INT_EVENT_GROUP_MASK) == MMI_INT_EVENT_GROUP_MASK)
#define MMI_FRM_PRE_INT_HDLR    1
#define MMI_FRM_POST_INT_HDLR   2

/* notification service: definitions */

#define MMI_FRM_NOTIFY_INVOKE_TIME      (2000)  /* next notify invoke time (ms) */

#define MMI_FRM_DEFER_NOTIFICATION_NUM  (20)    /* queue size for deferring notification */

#define MMI_FRM_SCENARIO_FLAG_SET_RESET (0x01)  /* bit 0 : set/reset */

/* index of general behavior in behavior table */
#define MMI_FRM_BEHAVIOR_TABLE_IDX_GENERAL  (MMI_FRM_BEHAVIOR_TABLE_SIZE-1)


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
 #ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
 typedef struct
{
    U16 groupID;
    U16 eventID[INTERRUPT_EVENT_GREOUP_SIZE];
} InterruptGroupInfo;
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */

typedef struct _mmi_frm_int_mask_hdlr_struct
{
    mmi_frm_int_event_type event_mask;
    interrupt_event_hdlr int_func_ptr;
    interrupt_event_hdlr post_int_func_ptr;
} mmi_frm_int_mask_hdlr_struct;

typedef struct
{
    U16 event_id;
    mmi_frm_int_event_type int_event_macro;
} mmi_frm_int_event_convert_struct;

typedef enum
{
    MMI_FRM_INT_EVENT_SPECIFIC,
    MMI_FRM_INT_EVENT_GENERAL,
    MMI_FRM_INT_EVENT_TYPE_NUM
} mmi_frm_int_event_type_list_enum;


/* notification service:  */
typedef struct {
    mmi_frm_defer_cb_type callback;
    void *arg;
    U16 res_id;         /* should be unique, maybe app id, scr id */
    U16 int_type;
} mmi_frm_defer_item_struct;


/* notification service:  */
typedef struct _mmi_frm_defer_notification_struct {
    mmi_frm_defer_item_struct data[MMI_FRM_DEFER_NOTIFICATION_NUM];
    U8 used;
} mmi_frm_defer_info_struct;


/* notification service:  */
typedef struct {
    mmi_frm_defer_info_struct   defer_info;
    U8 scenario_info[MMI_FRM_SCENARIO_NUM];       /* scenario info */
} mmi_frm_notify_service_cntx_struct;

/* Post event mechanism */
typedef struct _mmi_post_evt_node_struct
{
    U8 flag;
    void *evt_p;
    struct _mmi_post_evt_node_struct *next;
} mmi_post_evt_node_struct;


/*****************************************************************************
 * Global Variable                                                             
 *****************************************************************************/
PseventInfo protocolEventHandler[MAX_PROTOCOL_EVENT];
#ifdef __MMI_DUAL_SIM__
PseventInfo SlaveProtocolEventHandler[MAX_SLAVE_PROTOCOL_EVENT];
#endif /* __MMI_DUAL_SIM__ */

/* static event table info, e.g. table pointer, num. of table items */
const mmi_frm_event_static_info_struct g_event_table_static_info[EVENT_TABLE_END] = {
    {protocolEventHandler, sizeof(protocolEventHandler)/sizeof(PseventInfo)},
#ifdef __MMI_DUAL_SIM__            
    {SlaveProtocolEventHandler, sizeof(SlaveProtocolEventHandler)/sizeof(PseventInfo)},
#endif
};

/* runtime event table info, e.g. used and max. size */
mmi_frm_event_runtime_info_struct g_event_table_runtime_info[EVENT_TABLE_END];

#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
U16 maxInterruptEvent;
PsInteventInfo interruptEventHandler[MAX_INTERRUPT_EVENT];
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */

static BOOL g_int_evt_control_by_app = MMI_FALSE;

/* Post event link list */
static mmi_post_evt_node_struct *post_evt_header = NULL;
static U8 post_evt_num = 0;

/*****************************************************************************
 * Local Variable                                                             
 *****************************************************************************/
static mmi_frm_int_mask_hdlr_struct mmi_frm_int_mask_hdlr[MMI_FRM_INT_EVENT_TYPE_NUM];

#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
static const InterruptGroupInfo interruptGroupEventTable[] = 
{
    {MMI_SMS_INT_EVENT_GROUP,
     {PRT_MSG_ID_MMI_SMS_DELIVER_MSG_IND,
      PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND,
      PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND,
      0 /* end at 0 */
      }
     }
#if defined(__MMI_FILE_MANAGER__)
    ,{MMI_CARD_PLUG_EVENT_GROUP,
     {PRT_MMI_FMGR_CARD_PLUG_IN_IND,
      PRT_MMI_FMGR_CARD_PLUG_OUT_IND,
      0 /* end at 0 */
      }
     }
#endif /* __MMI_FILE_MANAGER__ */
};
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */

static const mmi_frm_int_event_convert_struct mmi_frm_int_event_battery_table[] = 
{
    {PMIC_CHARGER_IN,           MMI_FRM_INT_CHARGER_IN},
    {PMIC_CHARGER_OUT,          MMI_FRM_INT_CHARGER_OUT},
    {PMIC_CHARGE_COMPLETE,      MMI_FRM_INT_CHARGE_COMPLETE},
    {PMIC_USB_CHARGER_IN,       MMI_FRM_INT_USB_CHARGER_IN},
    {PMIC_USB_CHARGER_OUT,      MMI_FRM_INT_USB_CHARGER_OUT},
    {PMIC_USB_NO_CHARGER_IN,    MMI_FRM_INT_USB_NO_CHARGER_IN},
    {PMIC_USB_NO_CHARGER_OUT,   MMI_FRM_INT_USB_NO_CHARGER_OUT}
};

static const mmi_frm_int_event_convert_struct mmi_frm_int_event_convert_table[] = 
{
    {PTR_MSG_ID_SRV_SMS_WRITE_ME_SMS_IND,   MMI_FRM_INT_SMS_DELIVER},
    {MSG_ID_MMI_SMU_WRITE_SIM_RSP,          MMI_FRM_INT_SMS_DELIVER},
    {PTR_MSG_ID_SRV_SMS_DELIVER_IND,        MMI_FRM_INT_SMS_DELIVER},
    {PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND,  MMI_FRM_INT_SMS_STATUS_REPORT},
    {PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND,    MMI_FRM_INT_SMS_MSG_WAITING},
    {PRT_MSG_ID_MMI_SMS_APP_DATA_IND,       MMI_FRM_INT_SMS_APP_DATA},
    {MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_RSP,MMI_FRM_INT_SMS_APP_DATA},
#if defined(__MMI_FILE_MANAGER__)
    {PRT_MMI_FMGR_CARD_PLUG_IN_IND,         MMI_FRM_INT_FMGR_CARD_PLUG_IN},
    {PRT_MMI_FMGR_CARD_PLUG_OUT_IND,        MMI_FRM_INT_FMGR_CARD_PLUG_OUT},
#endif /* __MMI_FILE_MANAGER__ */
#if defined(WAP_SUPPORT)
    {MSG_ID_WPS_PMG_NEW_MSG_IND,                MMI_FRM_INT_WAP_PMG_NEW_MSG},
    {MSG_ID_WPS_PMG_DLG_PUSH_STORAGE_FULL_IND,  MMI_FRM_INT_WAP_PMG_DLG_PUSH_STORAGE_FULL},
    {MSG_ID_WPS_PMG_REPLACE_IND,                MMI_FRM_INT_WAP_PMG_REPLACE},
    {MSG_ID_WPS_PMG_DLG_SIA_CONFIRM_REQ,        MMI_FRM_INT_WAP_PMG_DLG_SIA_CONFIRM},
    {MSG_ID_WPS_PMG_DLG_UNKNOWN_ADDR_REQ,       MMI_FRM_INT_WAP_PMG_DLG_UNKNOWN_ADDR_REQ},
#endif /* WAP_SUPPORT */
#if defined(__CCA_SUPPORT__)
    {MSG_ID_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND,  MMI_FRM_INT_CCA_SOURCE_UI_INVALID_SETTING},
    {MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND,      MMI_FRM_INT_CCA_SOURCE_UI_NEW_SETTING},
#endif /* __CCA_SUPPORT__ */
	{MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND,    MMI_FRM_INT_MMI_JAVA_TIMEALARM_PUSH},
	{MSG_ID_MMI_JAVA_PUSH_INSTALL_IND,    MMI_FRM_INT_MMI_JAVA_PUSH_INSTALL},
#ifdef __CERTMAN_SUPPORT__
	{MSG_ID_MMI_CERTMAN_INVALID_CERT_IND,        MMI_FRM_INT_CERTMAN_MMI},
	{MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND,    MMI_FRM_INT_CERTMAN_MMI},
#endif
#ifdef __MMI_USB_SUPPORT__
    {MSG_ID_MMI_EQ_USBDETECT_IND,           MMI_FRM_INT_USBDETECT},
#endif
    {MSG_ID_MMI_VOIP_CALL_RING_IND,         MMI_FRM_INT_VOIP_CALL_RING},
    {MSG_ID_MMI_CC_CALL_RING_IND,           MMI_FRM_INT_MMI_CC_CALL_RING_IND},
#ifdef __SYNCML_SUPPORT__
    {MSG_ID_MMI_SYNCML_FINISH_SYNC_IND,        MMI_FRM_INT_SYNCML_FINISH_SYNC_IND},
    {MSG_ID_MMI_SYNCML_BT_ASK_ACCEPT_CONN_IND, MMI_FRM_INT_SYNCML_DEVICE_CONN_IND},
#endif
    {MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_RSP, MMI_FRM_INT_WAP_MMA_GET_MSG},
    {MSG_ID_WAP_MMA_GET_MSG_INFO_RSP,        MMI_FRM_INT_WAP_MMA_GET_MSG},
#ifdef SYNCML_DM_SUPPORT
    {MSG_ID_DM_NOTIFICATION_INIT_SESSION_REQ_IND,   MMI_FRM_INT_DM},
    {MSG_ID_DM_GET_BOOTSTRAP_USERPIN_REQ_IND,       MMI_FRM_INT_DM},
    {MSG_ID_DM_START_DL_REQ_IND,                    MMI_FRM_INT_DM},
    {MSG_ID_DM_DL_RESUME_REQ_IND,                   MMI_FRM_INT_DM},
    {MSG_ID_DM_DL_REQ_IND,                          MMI_FRM_INT_DM},
    {MSG_ID_DM_UPDATE_REQ_IND,                      MMI_FRM_INT_DM},
    {MSG_ID_DM_ALERT_REQ_IND,                       MMI_FRM_INT_DM},
    {MSG_ID_DM_DL_PROGRESS_IND,                     MMI_FRM_INT_DM},
    {MSG_ID_DM_PS_STATUS_IND,                       MMI_FRM_INT_DM},
    {MSG_ID_DM_DA_STATE_PAUSE,                      MMI_FRM_INT_DM},
    {MSG_ID_DM_DA_STATE_ABORT,                      MMI_FRM_INT_DM},
    {MSG_ID_DM_SCOMO_INSTALL_BY_SERVER_IND,         MMI_FRM_INT_DM},
    {MSG_ID_DM_SCOMO_REMOVE_BY_SERVER_IND,          MMI_FRM_INT_DM},
#endif
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    {MSG_ID_MMI_PROVBOX_NEW_MSG_IND,    MMI_FRM_INT_PROVBOXUI_NEW_SETTING},
#endif
#ifdef __MMI_EBOOK_READER__
    {MSG_ID_MMI_EBOOK_CALLBACK_ERROR_IND, MMI_FRM_INT_EBOOK},
#endif
#ifdef __MMI_EMAIL_EMN__
    {PRT_MMI_EMAIL_EMN_FAIL_NOTIFY_IND, MMI_FRM_INT_EMN},
#endif /* __MMI_EMAIL_EMN__ */
	/* Please add interrupt event before this one */
    {PRT_L4AUD_AUDIO_PLAY_FINISH_IND,       MMI_FRM_INT_AUDIO_PLAY_FINISH}
};

static MMI_BOOL mmi_frm_process_non_mmi_task = MMI_FALSE;

/* notification service: context */
static mmi_frm_notify_service_cntx_struct g_notify_service_cntx;

/* notification service: behavior table */
#include "mmi_behavior_table.h"


/*****************************************************************************
 * Local Function                                                              
 *****************************************************************************/
/* New interrupt event internal function */
static MMI_BOOL mmi_frm_query_interrupt_event_information(mmi_frm_int_event_type frm_int_event, interrupt_event_hdlr *int_func, interrupt_event_hdlr *post_int_func);
static mmi_frm_int_event_type mmi_frm_interrupt_event_converter(U16 event_id, void *msg);

#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
static MMI_BOOL mmi_frm_query_interrupt_handler(U16 event_id, PsIntFuncPtr *func_ptr, PsIntFuncPtr *post_func_ptr);
#endif

static S16 mmi_frm_search_event(
            mmi_frm_event_table_enum tableType,
            U16 eventID, 
            PsFuncPtr* pFuncPtr,
            S16 startIdx, 
            MMI_BOOL doSwap,
            S16 *pNextIdx, 
            S16 *pFirstEmptyIdx, 
            MMI_BOOL *pIsMultiInTable);

static void mmi_frm_set_protocol_event_handler_int(
                mmi_frm_event_table_enum tableType, 
                U16 eventID, 
                PsFuncPtr funcPtr, 
                MMI_BOOL isMultiHandler);

static void mmi_frm_clear_protocol_event_handler_int(
                mmi_frm_event_table_enum tableType, 
                U16 eventID, 
                PsFuncPtr funcPtr);

/* notification service: local functions */

static void mmi_frm_process_deferred_notification(void);
__inline MMI_BOOL is_scenario_flag_set(S32 idx, U8 flag);
__inline void set_scenario_flag(S32 idx, U8 flag);
__inline void clear_scenario_flag(S32 idx, U8 flag);
__inline S32 get_defer_notification_count(void);
static void update_concurrent_scenario(void);
static mmi_frm_scenario_enum get_scenario(void);
static mmi_frm_behavior_type get_behavior(mmi_frm_scenario_enum scenario, mmi_frm_int_enum interrupt);
static mmi_frm_defer_item_struct* get_defer_notification(U16 res_id);
static void add_defer_notification(U16 res_id, mmi_frm_defer_cb_type deferred_cb, U16 interrupt, void *arg);
static void del_defer_notification(U16 res_id);


/*****************************************************************************
 * Extern data and function                                                             
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_execute_current_protocol_handler
 * DESCRIPTION
 *  This function is used for executes current protocol func handler.
 * PARAMETERS
 *  eventID         [IN]  Unique Protocol/System EventID       
 *  MsgStruct       [IN]  The pointer to the Local parameter.      
 *  mod_src         [IN]  Source module ID.     
 *  Message         [IN]  The pointer to the ILM.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_execute_current_protocol_handler(U16 eventID, void *MsgStruct, int mod_src, void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx = 0;
/* vogins Start */
#ifdef __VRE_V30__
    MMI_BOOL isMultiHandler = MMI_FALSE, isExecuted = MMI_FALSE;
#else
    MMI_BOOL isMultiHandler = MMI_FALSE, isExecuted;
#endif
/* Vogins End */

    S16 nextIdxToSearch = 0;    /* used for multi-handler to enhance search efficiency */
    PsExtPeerIntFuncPtr currFuncPtr = NULL;
    mmi_frm_event_table_enum tableType = EVENT_TABLE_MASTER;
/* vogins Start */
#ifdef __VRE_V30__
    PsExtPeerIntFuncPtr  single_func= NULL;
    MMI_BOOL isMismatch = MMI_FALSE;
#endif
/* Vogins End */

#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
    PsIntFuncPtr IntFunc = NULL, PostIntFunc = NULL;
    PsExtPeerIntFuncPtr currInterruptFuncPtr = NULL, currPostInterruptFuncPtr = NULL;
    U8 interrup_result = MMI_FALSE; /* False not handle interrupt, True will handle */
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */

    /* new interrupt event mechanism */
    MMI_BOOL query_result = MMI_FALSE, execute_result = MMI_FALSE;
    interrupt_event_hdlr int_func = NULL, post_int_func = NULL;
    mmi_frm_int_event_type current_frm_int_event;
        
#if defined (MMI_EVENT_PROFILING)
    kal_uint32 start_tick, end_tick;
    static kal_uint32 accu_ticks = 0;
    static U32 accu_count = 0;
#endif /* defined (MMI_EVENT_PROFILING) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (MMI_EVENT_PROFILING)
    kal_get_time(&start_tick);
#endif 

#ifdef __MMI_DUAL_SIM__
    if (mod_src == MOD_L4C_2)
    {
        tableType = EVENT_TABLE_SLAVE;  /* use slave event table */
    }
#endif /* __MMI_DUAL_SIM__ */
        
    /* Search events in protocol event handler table */
    idx = mmi_frm_search_event(
            tableType,
            eventID, 
            (PsFuncPtr*) &currFuncPtr,
            0, 
            MMI_TRUE, 
            &nextIdxToSearch, 
            NULL, 
            &isMultiHandler);

/* vogins Start */
#ifdef __VRE_V30__
   isMultiHandler = (g_event_table_static_info[tableType].table)[idx].flagMulti;
   isMismatch = (g_event_table_static_info[tableType].table)[idx].isMismatch;
   if (idx >= 0)
   {
       if (isMismatch && !isMultiHandler)
       {
           single_func = currFuncPtr;
       }
    }
#endif
/* Vogins End */

#if defined (MMI_EVENT_PROFILING)
    if (idx > 0)
        accu_count += idx;
#endif /* defined (MMI_EVENT_PROFILING) */ 

#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
    /* Old Search events in interrupt event handler table */
    mmi_frm_query_interrupt_handler(eventID, &IntFunc, &PostIntFunc);
    currInterruptFuncPtr = (PsExtPeerIntFuncPtr) IntFunc;
    currPostInterruptFuncPtr = (PsExtPeerIntFuncPtr) PostIntFunc;
    /* Old interruption mechanism */
    if (currInterruptFuncPtr)
    {
        interrup_result = (*currInterruptFuncPtr) (MsgStruct, mod_src, Message);
    }
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */

    /* New Search events in interrupt event handler mask table */
    current_frm_int_event = mmi_frm_interrupt_event_converter(eventID, MsgStruct);
    if (current_frm_int_event > 0)
    {
        query_result = mmi_frm_query_interrupt_event_information(current_frm_int_event, &int_func, &post_int_func);
    }
    if (query_result && int_func)
    {
        /* New interruption mechanism */
        execute_result = (*int_func)(current_frm_int_event);
    }
    
    if ((currFuncPtr) && 
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
        (!interrup_result) && 
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
        (!execute_result))
    {
        do {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXECURPTO_HDLR, tableType, eventID, currFuncPtr, isMultiHandler);
/* vogins Start */
#ifdef __VRE_V30__
            if (single_func != currFuncPtr)
#endif
/* Vogins End */
                isExecuted = (*currFuncPtr) (MsgStruct, mod_src, Message);

            currFuncPtr = NULL; /* reset handler to NULL */
/* vogins Start */
#ifdef __VRE_V30__
            if (isMismatch)
            {
                isMultiHandler = MMI_TRUE;
            }
#endif
/* Vogins End */

            /* search and execute next handler if (1) multi-handler and (2) event is not executed */
            if (isMultiHandler && !isExecuted)
            {
/* vogins Start */
#ifdef __VRE_V30__
                idx = mmi_frm_search_event(
                        tableType,
                        eventID, 
                        (PsFuncPtr*) &currFuncPtr,
                        nextIdxToSearch, 
                        MMI_TRUE, 
                        &nextIdxToSearch, 
                        NULL, 
                        &isMultiHandler);
                   if (idx>= 0 && !(g_event_table_static_info[tableType].table)[idx].flagMulti && isMismatch)
                   {
                        single_func = currFuncPtr;
                   }

#else
                idx = mmi_frm_search_event(
                        tableType,
                        eventID, 
                        (PsFuncPtr*) &currFuncPtr,
                        nextIdxToSearch, 
                        MMI_TRUE, 
                        &nextIdxToSearch, 
                        NULL, 
                        NULL);
#endif
/* Vogins End */

                if (idx < 0)
                {
/* vogins Start */
#ifdef __VRE_V30__
                    if (single_func)
                    {
                        MMI_ASSERT(isMismatch);
                        (*single_func) (MsgStruct, mod_src, Message);
                    }
#endif
/* Vogins End */
                    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_FRM_INFO_EVENT_EXECURPTO_NO_HDLR, tableType, eventID, currFuncPtr);
                }
            }
        } while (currFuncPtr);
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXECURPTO_NO_HDLR, tableType, eventID, currFuncPtr);
    }
    
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
    if (currPostInterruptFuncPtr)
    {
        (*currPostInterruptFuncPtr) (MsgStruct, mod_src, Message);
    }
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */

    /* New interruption mechanism */    
    if (query_result && post_int_func)
    {
        execute_result = (*post_int_func)(current_frm_int_event);
    }

#if defined (MMI_EVENT_PROFILING)
    kal_get_time(&end_tick);
    accu_ticks += (end_tick - start_tick);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_EVENT_PROFILING_COUNT, accu_count);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_EVENT_PROFILING_TICKS, accu_ticks);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_EVENT_PROFILING_MAX, g_event_table_runtime_info[tableType].max_events);
#endif /* defined (MMI_EVENT_PROFILING) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_protocol_event_handler
 * DESCRIPTION
 *  This function is used for register the protocol event handler. Whenever 
 *  an event is received from the protocol or system corresponding function 
 *  is executed.
 * PARAMETERS
 *  eventID         [IN] Unique Protocol/System EventID.       
 *  funcPtr         [IN] Function to be executed whenever a event is received from the protocol or system
 *  isMultiHandler  [IN] is multi-handler or not. for multi-handler, it shall return MMI_TRUE when event is handled (taken) by it.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_protocol_event_handler(U16 eventID, PsIntFuncPtr funcPtr, MMI_BOOL isMultiHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler_int(EVENT_TABLE_MASTER, eventID, (PsFuncPtr)funcPtr, isMultiHandler);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_protocol_event_handler
 * DESCRIPTION
 *  This is used to clear protocol event handler
 * PARAMETERS
 *  eventID     [IN] event ID to clear
 *  funcPtr     [IN] handler of event ID to clear for multi-handler. can just assign NULL for single-handler event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_protocol_event_handler(U16 eventID, PsIntFuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_clear_protocol_event_handler_int(EVENT_TABLE_MASTER, eventID, (PsFuncPtr)funcPtr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_protocol_event_handler
 * DESCRIPTION
 *  This is used to get protocal event handler(only support MSG_ID_MMI_EQ_KEYPAD_DETECT_IND)
 * PARAMETERS
 *  eventID     :[IN] event ID
 *  funcPtr     :[IN] protocol event handler of eventID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_get_protocol_event_handler(U16 eventID, PsFuncPtr* pFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PsFuncPtr funcPtr = NULL;
    S16 idx = -1, firstNotUsed = -1;
    MMI_BOOL isMultiInTable ;
/* vogins Start */
#ifdef __VRE_V30__
isMultiInTable = MMI_FALSE;
#endif
/* Vogins End */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eventID == MSG_ID_MMI_EQ_KEYPAD_DETECT_IND);

    idx = mmi_frm_search_event(
            EVENT_TABLE_MASTER,
            eventID, 
            &funcPtr,
            0, 
            MMI_FALSE, 
            NULL, 
            &firstNotUsed, 
            &isMultiInTable);
/* vogins Start */
#ifdef __VRE_V30__
    if (idx >= 0)
#else
    if (idx > 0)
#endif
/* Vogins End */
    {
       *pFuncPtr = funcPtr;
    }
    else
    {
       *pFuncPtr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_search_event
 * DESCRIPTION
 *  search event in eventTable.
 * PARAMETERS
 *  tableType       [IN]  type of event table to search
 *  eventID         [IN]  event ID to search
 *  pFuncPtr        [IN/OUT] [IN] handler to search, or NULL to search event ID only [OUT] handler found for given event ID
 *  startIdx        [IN]  start index
 *  doSwap          [IN]  swap found event or not (now only swap when executing event)
 *  pNextIdx        [OUT] next index to search
 *  pFirstEmptyIdx  [OUT] index of 1st empty
 *  pIsMultiInTable [OUT] is multi-handler found in event table
 * RETURNS
 *  index found or -1 (not found)
 *****************************************************************************/
static S16 mmi_frm_search_event(
            mmi_frm_event_table_enum tableType,
            U16 eventID, 
            PsFuncPtr* pFuncPtr,
            S16 startIdx, 
            MMI_BOOL doSwap,
            S16 *pNextIdx, 
            S16 *pFirstEmptyIdx, 
            MMI_BOOL *pIsMultiInTable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx = -1;
    S16 maxEvents = g_event_table_runtime_info[tableType].max_events;
    PseventInfo *eventTable = g_event_table_static_info[tableType].table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pFirstEmptyIdx)
        *pFirstEmptyIdx = -1;

    /* Search events in protocol event handler table */
    for (idx = startIdx; idx < maxEvents; idx++)
    {
        /* eventID match */
        if (eventTable[idx].eventID == eventID)
        {
            /* if handler type is diff., return type in table */
            /* search for handler or not */
/* vogins Start */
#ifdef __VRE_V30__
            //mismatch case
            if ((pIsMultiInTable) && (*pIsMultiInTable != (MMI_BOOL)eventTable[idx].flagMulti))
            {
                if (!eventTable[idx].isMismatch)
                    eventTable[idx].isMismatch = MMI_TRUE;
            }
#else
            if ((pIsMultiInTable) && (*pIsMultiInTable != (MMI_BOOL)eventTable[idx].flagMulti))
                *pIsMultiInTable = (MMI_BOOL)eventTable[idx].flagMulti;
#endif
/* Vogins End */

            /* search for handler or not */
            if (pFuncPtr)
    {
                /* match eventID only, no handler to search */
                if (*pFuncPtr == NULL)
                {
/* vogins Start */
#ifdef __VRE_V30__
                    if ((pIsMultiInTable) && ((*pIsMultiInTable == eventTable[idx].flagMulti)) || (!pFirstEmptyIdx))            
                    {
                        
                    *pFuncPtr = eventTable[idx].entryFuncPtr;
                }
                    else
                    {
                        continue;
                    }
#else
                    *pFuncPtr = eventTable[idx].entryFuncPtr;

#endif
/* Vogins End */

                }
                /* has handler to search */
                else
                {
                    /* handler not found */
                    if (*pFuncPtr != eventTable[idx].entryFuncPtr)
        {
                        continue;   /* keep searching */
                    }
                    /* else: handler found */
/* vogins Start */
#ifdef __VRE_V30__

                    else
                    {
                        *pIsMultiInTable = eventTable[idx].flagMulti;
                    }
#endif
/* Vogins End */

                }
            }

            if (pNextIdx) /* next index to search */
                *pNextIdx = idx+1;

            if (doSwap && (idx > 0))
            {   /* improve the search efficiently */
                PseventInfo tmpEvent = eventTable[idx];
                eventTable[idx]     = eventTable[idx-1];
                eventTable[idx-1]   = tmpEvent;
                idx--;
            }
         
            break;
        }
        
        /* find 1st empty at the same time */
        if (pFirstEmptyIdx && (*pFirstEmptyIdx == -1) && (eventTable[idx].eventID == MMI_EVENT_INVALID))
        {
            *pFirstEmptyIdx = idx;
        }

    }

    if (idx < maxEvents)
    {
        
        return idx;
    }
    else
        return -1;  /* not found */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_protocol_event_handler_int
 * DESCRIPTION
 *  This function is used for register the protocol event handler. Whenever 
 *  an event is received from the protocol or system corresponding function 
 *  is executed.
 * PARAMETERS
 *  tableType       [IN] event table type
 *  eventID         [IN] Unique Protocol/System EventID.       
 *  funcPtr         [IN] Function to be executed whenever a event is received from the protocol or system
 *  isMultiHandler  [IN] is multi-handler or not. for multi-handler, it shall return MMI_TRUE when event is handled (taken) by it.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_set_protocol_event_handler_int(mmi_frm_event_table_enum tableType, U16 eventID, PsFuncPtr funcPtr, MMI_BOOL isMultiHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 maxUsedInHistory[EVENT_TABLE_END] = {0};
    S16 idx = -1, firstNotUsed = -1;
    MMI_BOOL isMultiInTable = isMultiHandler;  /* initial to same as input */
    PsFuncPtr funcToSearch = NULL;
    PseventInfo *eventTable = g_event_table_static_info[tableType].table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eventID != 0);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_SETPTO_HDLR,
              eventID, funcPtr, isMultiHandler);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_EVENT_SETPTO_HDLR_DETAIL,
              tableType, g_event_table_runtime_info[tableType].used_events, g_event_table_runtime_info[tableType].max_events);

    /* serach */
    if (isMultiHandler)
    {
        funcToSearch = funcPtr;
        MMI_ASSERT(funcPtr != NULL);    /* funcPtr=NULL is only for single-handler */
   }

    idx = mmi_frm_search_event(
            tableType,
            eventID, 
            &funcToSearch,
            0, 
            MMI_FALSE, 
            NULL, 
            &firstNotUsed, 
            &isMultiInTable);
/* vogins Start */
#ifndef __VRE_V30__
    MMI_ASSERT(isMultiHandler == isMultiInTable);  /* handler type mismatch with existing in table */
#endif
/* Vogins End */
    /* found */
    if (idx >= 0)
    {
        /* single-handler */
        if (!isMultiHandler)
        {
            if (funcPtr != NULL)
            {
                /* just need to update */
                eventTable[idx].entryFuncPtr = funcPtr;
            }
            else
            {
                /* funcPtr=NULL, means clear => reset it */
                memset(&eventTable[idx], 0, sizeof(PseventInfo));
                g_event_table_runtime_info[tableType].used_events--;
            }
        }
        /* multi-handler: eventID/funcPtr already exists, do nothing */
    }
    /* not found */
    else
    {
        if (funcPtr != NULL)
        {
            /* newly set */
            if (firstNotUsed != -1)
            {
                idx = firstNotUsed;
            }
            else
            {
                /* need to enlarge current searching list */
                idx = g_event_table_runtime_info[tableType].max_events;
                g_event_table_runtime_info[tableType].max_events++;
                MMI_ASSERT(g_event_table_runtime_info[tableType].max_events < g_event_table_static_info[tableType].num_of_events);
            }
            g_event_table_runtime_info[tableType].used_events++;
            eventTable[idx].eventID       = eventID;
            eventTable[idx].entryFuncPtr  = funcPtr;
            eventTable[idx].flagMulti     = (U8)isMultiHandler;
        }
        else
        {
            /* funcPtr=NULL, means clear. but not found => do nothing */
        }
    }

    /* recycle not-used items in the tail of list. It is for searching efficency */
    for (idx = (g_event_table_runtime_info[tableType].max_events - 1); idx >= 0; idx--)
    {
        if (eventTable[idx].eventID != MMI_EVENT_INVALID)
        {
            break;
        }
    }
    g_event_table_runtime_info[tableType].max_events= idx + 1;

    /* record the max value for array size analysis */
    if (maxUsedInHistory[tableType] < g_event_table_runtime_info[tableType].max_events)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_SET_PROTOCOL_EVENT_HDLR_MAX_1, maxUsedInHistory[tableType]);
        maxUsedInHistory[tableType] = g_event_table_runtime_info[tableType].max_events;
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_EVENT_TRC_SET_PROTOCOL_EVENT_HDLR_MAX_2, maxUsedInHistory[tableType]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_protocol_event_handler_int
 * DESCRIPTION
 *  This is used to clear protocol event handler
 * PARAMETERS
 *  tableType   [IN] event table type
 *  eventID     [IN] event ID to clear
 *  funcPtr     [IN] handler of event ID to clear for multi-handler. can just assign NULL for single-handler event.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_clear_protocol_event_handler_int(mmi_frm_event_table_enum tableType, U16 eventID, PsFuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx = -1;
    MMI_BOOL isMultiInTable = MMI_FALSE;
    PsFuncPtr funcToClear = funcPtr;
    PseventInfo *eventTable = g_event_table_static_info[tableType].table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = mmi_frm_search_event(
            tableType,
            eventID, 
            &funcToClear,
            0, 
            MMI_FALSE, 
            NULL, 
            NULL, 
            &isMultiInTable);

    if (idx >= 0)  /* found */
    {
        if (isMultiInTable)
        {
            MMI_ASSERT(funcPtr);    /* can't use NULL for multi-handler */
        }

        /* shows actual (eventID, funcPtr) to clear */
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_CLRPTO_HDLR, tableType, eventID, funcToClear);

        memset(&eventTable[idx], 0, sizeof(PseventInfo));
        g_event_table_runtime_info[tableType].used_events--;

        /* recycle not-used items in the tail of list. It is for searching efficency */
        for (idx = (g_event_table_runtime_info[tableType].max_events - 1); idx >= 0; idx--)
        {
            if (eventTable[idx].eventID != MMI_EVENT_INVALID)
            {
                break;
            }
        }
        g_event_table_runtime_info[tableType].max_events= idx + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_protocol_event_handler
 * DESCRIPTION
 *  This is used to clear all the protocol event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_CLRALLPTO_HDLR, EVENT_TABLE_MASTER);

    memset(protocolEventHandler, 0, sizeof(PseventInfo)*g_event_table_runtime_info[EVENT_TABLE_MASTER].max_events); 
    memset(&g_event_table_runtime_info[EVENT_TABLE_MASTER], 0, sizeof(mmi_frm_event_runtime_info_struct));
    
    mmi_frm_set_protocol_event_handler(MSG_ID_TST_INJECT_STRING, (PsIntFuncPtr)mmi_proc_inject_string, MMI_FALSE);

#ifdef __MMI_DUAL_SIM__
    mmi_frm_clear_all_slave_protocol_event_handler();
#endif
}


#ifdef __MMI_DUAL_SIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_slave_protocol_event_handler
 * DESCRIPTION
 *  This function is used for register the protocol event handler for slave card. 
 *  Whenever an event is received from the protocol or system corresponding function 
 *  is executed.
 * PARAMETERS
 *  eventID     [IN] Unique Protocol/System EventID.       
 *  funcPtr         [IN] Function to be executed whenever a event is received from the protocol or system
 *  isMultiHandler  [IN] is multi-handler or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_slave_protocol_event_handler(U16 eventID, PsIntFuncPtr funcPtr, MMI_BOOL isMultiHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler_int(EVENT_TABLE_SLAVE, eventID, (PsFuncPtr)funcPtr, isMultiHandler);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_slave_protocol_event_handler
 * DESCRIPTION
 *  This is used to clear protocol event handler
 * PARAMETERS
 *  eventID     [IN] Clear the handler of event ID.       
 *  funcPtr     [IN] handler of event ID to clear for multi-handler. can just assign NULL for single-handler event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_slave_protocol_event_handler(U16 eventID, PsIntFuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_clear_protocol_event_handler_int(EVENT_TABLE_SLAVE, eventID, (PsFuncPtr)funcPtr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_slave_protocol_event_handler
 * DESCRIPTION
 *  This is used to clear all the protocol event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_slave_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(SlaveProtocolEventHandler, 0, sizeof(PseventInfo) * g_event_table_runtime_info[EVENT_TABLE_SLAVE].max_events); 
    memset(&g_event_table_runtime_info[EVENT_TABLE_SLAVE], 0, sizeof(mmi_frm_event_runtime_info_struct));
    
    mmi_frm_set_slave_protocol_event_handler(MSG_ID_TST_INJECT_STRING, (PsIntFuncPtr)mmi_proc_inject_string, MMI_FALSE);
}
#endif /* __MMI_DUAL_SIM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_query_interrupt_event_information
 * DESCRIPTION
 *  This function could query interrupt event information.
 * PARAMETERS
 *  eventID      [IN]        interrupt event id
 *  int_func     [OUT]       interrupt event pre handler
 *  post_int_func[OUT]       interrupt event post handler   
 * RETURNS
 *  Return MMI_TURE if find the information slot, otherwise, return MMI_FLASE
 *****************************************************************************/
static MMI_BOOL mmi_frm_query_interrupt_event_information(mmi_frm_int_event_type frm_int_event, interrupt_event_hdlr *int_func, interrupt_event_hdlr *post_int_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We set specific interrupt event as higher priority than general ones */
    for (count = MMI_FRM_INT_EVENT_SPECIFIC; count < MMI_FRM_INT_EVENT_TYPE_NUM; count++)
    {
        if (frm_int_event & mmi_frm_int_mask_hdlr[count].event_mask)
        {
            if (int_func)
            {
                *int_func = mmi_frm_int_mask_hdlr[count].int_func_ptr;
            }
            if (post_int_func)
            {
                *post_int_func = mmi_frm_int_mask_hdlr[count].post_int_func_ptr;
            }
            return MMI_TRUE;
        }
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_frm_int_event_macro
 * DESCRIPTION
 *  This function will get framework interrupt event macro from convert table
 * PARAMETERS
 *  event_id       [IN]       interrupt event id
 *  msg            [IN]       primitive's local parameter
 * RETURNS
 *  Reture framework interrupt event macro
 *****************************************************************************/
static mmi_frm_int_event_type mmi_frm_get_frm_int_event_macro(U16 int_event, const mmi_frm_int_event_convert_struct *int_event_convert_table, U8 table_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  count;
    mmi_frm_int_event_type frm_int_event_macro = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < table_size; count++)
    {
        if (int_event_convert_table[count].event_id == int_event)
        {
            frm_int_event_macro = int_event_convert_table[count].int_event_macro;
            break;
        }
    }
    return frm_int_event_macro;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_interrupt_event_converter
 * DESCRIPTION
 *  This function will convert protocol interrupt event to framework interrupt
 *  event macro.
 * PARAMETERS
 *  event_id       [IN]       interrupt event id
 *  msg            [IN]       primitive's local parameter
 * RETURNS
 *  Reture framework interrupt event macro
 *****************************************************************************/
static mmi_frm_int_event_type mmi_frm_interrupt_event_converter(U16 event_id, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_int_event_type frm_interrupt_event = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event_id)
    {
        case PRT_EQ_GPIO_DETECT_IND:
        {
            mmi_eq_gpio_detect_ind_struct *gpio_detect_ind = (mmi_eq_gpio_detect_ind_struct *)msg;
            switch (gpio_detect_ind->gpio_device)
            {
                case EXT_DEV_CLAM_CLOSE:
                {
                    frm_interrupt_event = MMI_FRM_INT_CLAM_CLOSE;
                    break;
                }
                case EXT_DEV_CLAM_OPEN:
                {
                    frm_interrupt_event = MMI_FRM_INT_CLAM_OPEN;
                    break;
                }
                case EXT_DEV_EARPHONE:
                {
                    if (gpio_detect_ind->on_off == 1)
                    {
                        frm_interrupt_event = MMI_FRM_INT_EARPHONE_PLUG_IN;
                    }
                    else
                    {
                        frm_interrupt_event = MMI_FRM_INT_EARPHONE_PLUG_OUT;
                    }
                    break;
                }
            }
            break;
        }
        case PRT_BATTERY_STATUS_IND:
        {
            mmi_eq_battery_status_ind_struct *battery_status_ind = (mmi_eq_battery_status_ind_struct*)msg;

            frm_interrupt_event = mmi_frm_get_frm_int_event_macro(
                                      battery_status_ind->battery_status,
                                      mmi_frm_int_event_battery_table,
                                      sizeof(mmi_frm_int_event_battery_table) / sizeof(mmi_frm_int_event_battery_table[0]));
            /* For low battery indication */
            if (battery_status_ind->battery_status == PMIC_VBAT_STATUS)
            {
                if (battery_status_ind->battery_voltage == BATTERY_LOW_WARNING)
                {
                    frm_interrupt_event = MMI_FRM_INT_BATTERY_LOW_WARNING;
                }
                else if (battery_status_ind->battery_voltage == BATTERY_LOW_TX_PROHIBIT)
                {
                    frm_interrupt_event = MMI_FRM_INT_BATTERY_LOW_TX_PROHIBIT;
                }
            }
            break;
        }
        case MSG_ID_TIMER_EXPIRY:
        case MSG_ID_MMI_EQ_POWER_ON_IND:
        case MSG_ID_MMI_EQ_KEYPAD_DETECT_IND:
        {
            break;
        }
        default:
        {
            frm_interrupt_event = mmi_frm_get_frm_int_event_macro(
                                      event_id, 
                                      mmi_frm_int_event_convert_table,
                                      sizeof(mmi_frm_int_event_convert_table) / sizeof(mmi_frm_int_event_convert_table[0]));
            break;
        }
    }
    return frm_interrupt_event;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_process_non_mmi_task_interrupt
 * DESCRIPTION
 *  This function is an internal one which will set interrupt event handler
 *  into interrupt information table.
 * PARAMETERS
 *  mmi_frm_int_event_type       [IN]       interrupt event
 *  is_set                       [IN]       set non-mmi task popup screen 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_process_non_mmi_task_interrupt(mmi_frm_int_event_type interrupt_event, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL mmi_arg = MMI_FALSE;
    kal_bool kal_arg = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_set)
    {
        mmi_arg = MMI_TRUE;
        kal_arg = KAL_TRUE;
    }

    #ifdef OBIGO_Q03C
        if (interrupt_event & MMI_FRM_INT_WAP_MMS)
        {
            wap_suppress_popup(kal_arg);
        }        
    #endif /* OBIGO_Q03C */
    #if defined(__MMI_BT_MTK_SUPPORT__)
        if (interrupt_event & MMI_FRM_INT_BT_TASK)
        {
            mmi_bt_suppress_popup(mmi_arg, (U32)(interrupt_event & MMI_FRM_INT_BT_TASK));
        }
    #endif /* defined(__MMI_BT_MTK_SUPPORT__) */
    mmi_frm_process_non_mmi_task = is_set;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_block_interrupt_event_int
 * DESCRIPTION
 *  This function is an internal one which will set interrupt event handler
 *  into interrupt information table.
 * PARAMETERS
 *  int_event_p           [IN]       pre interrupt event handler
 *  post_int_event_p      [IN]       post interrupt event handler
 *  interrupt_event       [IN]       framework interrupt event macro
 *  event_type            [IN]       to decide general or specific event  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_block_interrupt_event_int(mmi_frm_int_event_type interrupt_event, interrupt_event_hdlr int_event_p, interrupt_event_hdlr post_int_event_p, U8 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Non-MMI task interruption is not through the protocol event process, so it needs to set flag to 
     * stop popup screen after EntryNewScreen and reset it when exit the screen
     */
    if (interrupt_event & MMI_FRM_INT_NON_MMI_TASK_EVENTS)
    {
        if (int_event_p)
        {
            mmi_frm_process_non_mmi_task_interrupt(interrupt_event, MMI_TRUE);
        }
        else if (!int_event_p && mmi_frm_process_non_mmi_task)  /* if int_event_p is NULL which means user want to clear this handler */
        {
            mmi_frm_process_non_mmi_task_interrupt(interrupt_event, MMI_FALSE);
        }
    }

    /* This action will only register the events and handlers in the last time calling this interface */
    mmi_frm_int_mask_hdlr[event_type].event_mask = interrupt_event;
    mmi_frm_int_mask_hdlr[event_type].int_func_ptr = int_event_p;
    mmi_frm_int_mask_hdlr[event_type].post_int_func_ptr = post_int_event_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_pre_block_interrupt_event_handler
 * DESCRIPTION
 *  This function is an internal one which will block popup screen caused by
 *  interrupt event handler.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro  
 * RETURNS
 *  Return MMI_FALSE to let protocol handler be executed, otherwise, 
 *  return MMI_TRUE.
 *****************************************************************************/
static U8 mmi_frm_pre_block_interrupt_event_handler(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (interrupt_event)
    {
        /* Now the default action is just to stop popup screen for general interrupt event */
        default:
        {
            SetInterruptPopupDisplay(POPUP_ALL_OFF);
            break;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_post_block_interrupt_event_handler
 * DESCRIPTION
 *  This function is an internal one which will reset the flag of popup screen.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro  
 * RETURNS
 *  Return MMI_FALSE always (remain for expansion).
 *****************************************************************************/
static U8 mmi_frm_post_block_interrupt_event_handler(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (interrupt_event)
    {
        /* Now the default action is just to stop popup screen for general interrupt event */
        default:
        {
            SetInterruptPopupDisplay(POPUP_ALL_ON);
            break;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_block_interrupt_event_handler
 * DESCRIPTION
 *  This function will set event handler which could process what application want 
 *  when the interrupt event is blocked by mmi task.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro
 *  int_event_p           [IN]       pre interrupt event handler
 *  post_int_event_p      [IN]       post interrupt event handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_block_interrupt_event_handler(mmi_frm_int_event_type interrupt_event, interrupt_event_hdlr int_event_p, interrupt_event_hdlr post_int_event_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_BLOCK_INT_HDLR, interrupt_event);
    mmi_frm_block_interrupt_event_int(
        interrupt_event, 
        int_event_p,
        post_int_event_p,
        MMI_FRM_INT_EVENT_SPECIFIC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_block_general_interrupt_event
 * DESCRIPTION
 *  This function could block all the interruptive popup screen when the general
 *  interrupt event is blocked by mmi task.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_block_general_interrupt_event(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_BLOCK_GEN_INT_HDLR, interrupt_event);
    mmi_frm_block_interrupt_event_int(
        interrupt_event,    
        mmi_frm_pre_block_interrupt_event_handler,
        mmi_frm_post_block_interrupt_event_handler,
        MMI_FRM_INT_EVENT_GENERAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_interrupt_event_handler
 * DESCRIPTION
 *  This function could clear the designated interrupt event handler.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_interrupt_event_handler(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((interrupt_event & MMI_FRM_INT_NON_MMI_TASK_EVENTS) && mmi_frm_process_non_mmi_task)
    {
        mmi_frm_process_non_mmi_task_interrupt(interrupt_event, MMI_FALSE);
    }

    for (count = MMI_FRM_INT_EVENT_SPECIFIC; count < MMI_FRM_INT_EVENT_TYPE_NUM; count++)
    {
        if (interrupt_event & mmi_frm_int_mask_hdlr[count].event_mask)
        {
            mmi_frm_int_mask_hdlr[count].event_mask &= ~interrupt_event;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_interrupt_event_handler
 * DESCRIPTION
 *  This function could clear all the interrupt event handler.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_interrupt_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(mmi_frm_int_mask_hdlr, 0, sizeof(mmi_frm_int_mask_hdlr));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_keep_block_interrupt_event
 * DESCRIPTION
 *  Phone lock feature need to block interrupt event during its process even screen
 *  has been switched.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_keep_block_interrupt_event(MMI_BOOL flag)
{
    g_int_evt_control_by_app = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_reset_interrupt_event_context
 * DESCRIPTION
 *  This function could reset interrupt event context and clear all interrupt
 *  event handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_reset_interrupt_event_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_int_evt_control_by_app)
    {
        return ;
    }
    /* 
     * Non-MMI task interruption is not through the protocol event process, so it needs to set flag to 
     * stop popup screen after EntryNewScreen and reset it when exit the screen
     */    
    if (mmi_frm_process_non_mmi_task)
    {
    #ifdef OBIGO_Q03C
        if (mmi_frm_query_interrupt_event_information(MMI_FRM_INT_WAP_MMS, NULL, NULL))
        {
            wap_suppress_popup(KAL_FALSE);
        }
    #endif /* OBIGO_Q03C */
    #if defined(__MMI_BT_MTK_SUPPORT__)
        if (mmi_frm_query_interrupt_event_information(MMI_FRM_INT_BT_TASK, NULL, NULL))
        {
            mmi_bt_suppress_popup(MMI_FALSE, (U32)NULL);
        }
    #endif /* defined(__MMI_BT_MTK_SUPPORT__) */
        mmi_frm_process_non_mmi_task = MMI_FALSE;
    }

    mmi_frm_clear_all_interrupt_event_handler();
}


#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_interrupt_group_table
 * DESCRIPTION
 *  search interrupt group event id is in interrupt
 *  group table and get the index
 * PARAMETERS
 *  eventID     [IN]     Unique Protocol/System EventID.   
 *  index       [OUT]    The index in the interrupt group table. If not find the
 *                       index is -1.
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_is_interrupt_group_table(U16 event_id, int *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(interruptGroupEventTable) / sizeof(InterruptGroupInfo); i++)
    {
        if (interruptGroupEventTable[i].groupID == event_id)
        {
            *index = i;
            return MMI_TRUE;
        }
    }

    *index = -1;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_query_interrupt_handler
 * DESCRIPTION
 *  query interrupt event handler
 * PARAMETERS
 *  eventID         [IN]   Unique Protocol/System EventID.      
 *  funcPtr         [OUT]  Function to be executed when receiving the interrupt event.     
 *  postfuncPtr     [OUT]  Function to be executed after receiving the interrupt event       
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_query_interrupt_handler(U16 event_id, PsIntFuncPtr *func_ptr, PsIntFuncPtr *post_func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_INTERRUPT_EVENT; i++)
    {
        if (!IS_INTERRUPT_EVENT_GROUP(interruptEventHandler[i].eventID))
        {
            /* General interrupt event */
            if (interruptEventHandler[i].eventID == event_id)
            {
                goto is_found;
            }
        }
        else
        {
            if (mmi_frm_is_interrupt_group_table(interruptEventHandler[i].eventID, &index))
            {
                /* Interrupt group event */
                j = 0;
                while (interruptGroupEventTable[index].eventID[j] != 0)
                {
                    if (interruptGroupEventTable[index].eventID[j] == event_id)
                    {
                        goto is_found;
                    }
                    j++;

                    MMI_ASSERT(j < INTERRUPT_EVENT_GREOUP_SIZE);
                }
            }
        }

    }
    return MMI_FALSE;

  is_found:
    *func_ptr = (PsIntFuncPtr) interruptEventHandler[i].entryIntFuncPtr;
    *post_func_ptr = (PsIntFuncPtr) interruptEventHandler[i].postIntFuncPtr;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_interrupt_event_handler
 * DESCRIPTION
 *  This function is used for register the interrupt event handler. Whenever 
 *  an event is received from the protocol corresponding function is executed.
 *  If the interrupt event handlers are registered, MMI framework  executes 
 *  the functions as follow order: Inpterrupt Event Handler, Protocol Event 
 *  Handler, Post Interrupt Event Handler.
 * PARAMETERS
 *  funcPtr         [IN] Function to be executed when receiving the interrupt event.       
 *  postfuncPtr     [IN] Function to be executed after receiving the interrupt event.       
 *  eventID         [IN] Unique Protocol/System EventID.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_interrupt_event_handler(PsIntFuncPtr func_ptr, PsIntFuncPtr post_func_ptr, U16 event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0;
    pBOOL isNewEvent = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_SETINTP_HDLR, event_id);

    if (!IS_INTERRUPT_EVENT_GROUP(event_id))
    {
        /* General interrupt event will allocate from the begin */
        for (count = 0; count < maxInterruptEvent; count++)
        {
            if (interruptEventHandler[count].eventID == event_id)
            {
                isNewEvent = FALSE;
                break;
            }
            if (interruptEventHandler[count].eventID == 0)
            {
                break;
            }
        }
    }
    else
    {
        /* Interrupt group event will allocate from the end */
        for (count = MAX_INTERRUPT_EVENT - 1; count >= 0; count--)
        {
            if (interruptEventHandler[count].eventID == event_id)
            {
                isNewEvent = FALSE;
                break;
            }
            if (interruptEventHandler[count].eventID == 0)
            {
                break;
            }
        }
    }

    if (isNewEvent)
    {
        maxInterruptEvent++;
        MMI_ASSERT(maxInterruptEvent < MAX_INTERRUPT_EVENT);
    }

    interruptEventHandler[count].eventID = event_id;
    interruptEventHandler[count].entryIntFuncPtr = func_ptr;
    interruptEventHandler[count].postIntFuncPtr = post_func_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_group_interrupt_event_handler
 * DESCRIPTION
 *  This function is used for register the group interrupt event handlers. 
 *  If the interrupt event handlers are registered, MMI framework  executes 
 *  the functions as follow order: InpterruptFuncPtr, ProtocolFuncPtr, 
 *  InterruptPostfuncPtr.
 * PARAMETERS
 *  funcPtr         [IN] Function to be executed when receiving the interrupt event.       
 *  postfuncPtr     [IN] Function to be executed after receiving the interrupt event.       
 *  eventsID        [IN] Unique Protocol/System EventID array.       
 *  len             [IN] The EventsID array size.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_group_interrupt_event_handler(PsIntFuncPtr func_ptr, PsIntFuncPtr post_func_ptr, PU16 events_id, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < len; count++)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_SETGRPINTP_HDLR, events_id[count]);
        mmi_frm_set_interrupt_event_handler(func_ptr, post_func_ptr, events_id[count]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_interrupt_event_handler_old
 * DESCRIPTION
 *  This is used to clear interrupt event handler
 * PARAMETERS
 *  eventID     [IN] Clear the handler of event ID.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_interrupt_event_handler_old(U16 event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_CLRINTP_HDLR, event_id);
    mmi_frm_set_interrupt_event_handler(NULL, NULL, event_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_interrupt_event_handler_old
 * DESCRIPTION
 *  This is used to clear all the interrupt event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_interrupt_event_handler_old(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_EVENT_CLRALLINTP_HDLR);

    memset(interruptEventHandler, 0, sizeof(PsInteventInfo)*maxInterruptEvent);

    maxInterruptEvent = 0;
}
#endif /*__MMI_FRAMEWORK_BACKWARD_COMPATIBLE__*/


/***************************************************************************** 
* Notification Service
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_notification_service_init
 * DESCRIPTION
 *  this function is used to initialize notification service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_notification_service_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* event handler for notification service */
    SetProtocolEventHandler(mmi_frm_process_deferred_notification, MSG_ID_MMI_NOTIFICATION_SERVICE_INVOKE_IND);

    /* initialize cntx struct */
    memset(&g_notify_service_cntx, 0, sizeof(g_notify_service_cntx));

    /* make sure last one in behavior table is general behavior */
    MMI_ASSERT(behavior_table[MMI_FRM_BEHAVIOR_TABLE_IDX_GENERAL].scenario == MMI_FRM_SCENARIO_GENERAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_scenario
 * DESCRIPTION
 *  this function is used to set MMI scenario
 * PARAMETERS
 *  scenario    [IN]    scenario to set
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_scenario(mmi_frm_scenario_enum scenario)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SET_SCENARIO, scenario);
    MMI_ASSERT(scenario < MMI_FRM_SCENARIO_END);

    /* set scenario */
    set_scenario_flag(scenario, MMI_FRM_SCENARIO_FLAG_SET_RESET);
    update_concurrent_scenario();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_reset_scenario
 * DESCRIPTION
 *  this function is used to reset MMI scenario
 * PARAMETERS
 *  scenario    [IN]    scenario to reset
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_reset_scenario(mmi_frm_scenario_enum scenario)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_RESET_SCENARIO, scenario);
    MMI_ASSERT(scenario < MMI_FRM_SCENARIO_END);

    /* reset scenario */
    clear_scenario_flag(scenario, MMI_FRM_SCENARIO_FLAG_SET_RESET);
    update_concurrent_scenario();

    /* if allow-to-execute defer exists, invoke notification service */
    if (get_defer_notification(0))
    {
        /* invoke deferred notification by msg */
        msg.oslSrcId = MOD_MMI;
        msg.oslDestId = MOD_MMI;
        msg.oslMsgId = MSG_ID_MMI_NOTIFICATION_SERVICE_INVOKE_IND;
        msg.oslDataPtr = (oslParaType*) NULL;
        msg.oslPeerBuffPtr = NULL;
        
        OslMsgSendExtQueue(&msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_query_interrupt_behavior
 * DESCRIPTION
 *  this function is used to query interrupt behavior
 * PARAMETERS
 *  interrupt           [IN]  interrupt type
 *  behavior_struct_p   [OUT] pointer to store returned behavior
 * RETURNS
 *  current scenario (highest priority if more than 1 is set)
 *****************************************************************************/
mmi_frm_scenario_enum mmi_frm_query_interrupt_behavior(
                        mmi_frm_int_enum interrupt, 
                        mmi_frm_int_behavior_struct *behavior_struct_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scenario_enum scenario;
    mmi_frm_behavior_type behavior_from_table;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_ASSERT(behavior_struct_p != NULL);

    memset(behavior_struct_p, 0, sizeof(mmi_frm_int_behavior_struct));
    scenario = get_scenario();

    if (g_int_evt_control_by_app)
    {/* After memset 0, all vectors have been set to NONE. */
        return scenario;
    }

    behavior_from_table = get_behavior(scenario, interrupt);
    
    behavior_struct_p->ev_interface = behavior_from_table & MMI_FRM_BEHAVIOR_MASK_IF;  
    behavior_struct_p->sound        = behavior_from_table & MMI_FRM_BEHAVIOR_MASK_SND;
    behavior_struct_p->indicator    = behavior_from_table & MMI_FRM_BEHAVIOR_MASK_IND;
    behavior_struct_p->vibrator     = behavior_from_table & MMI_FRM_BEHAVIOR_MASK_VIB;
    behavior_struct_p->backlight    = behavior_from_table & MMI_FRM_BEHAVIOR_MASK_BL;

    MMI_TRACE(
        MMI_FW_TRC_G1_FRM, 
        MMI_FRM_INFO_EVENT_QUERY_BEHAVIOR, 
        scenario, 
        interrupt,
        behavior_struct_p->ev_interface, 
        behavior_struct_p->sound, 
        behavior_struct_p->indicator,
        behavior_struct_p->vibrator, 
        behavior_struct_p->backlight);

    return scenario;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_register_deferring_notification
 * DESCRIPTION
 *  this function is used to register deferring notification to deferring queue
 * PARAMETERS
 *  res_id      [IN] resource id, e.g. app id or scr id, which is used to identify this defer notification
 *  deferred_cb [IN] deferring callback to register
 *  interrupt   [IN] interrupt type
 *  arg         [IN] argument that will be passed to deferring callback
 * RETURNS
 *  success or not
 *****************************************************************************/
MMI_BOOL mmi_frm_register_deferring_notification(
            U16 res_id, 
            FuncPtr deferred_cb, 
            mmi_frm_int_enum interrupt, 
            void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_defer_item_struct *defer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(res_id > 0); /* should have valid res ID */
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_REGISTER_DEFER, res_id, deferred_cb, interrupt, arg);

    defer_ptr = get_defer_notification(res_id);

    if (defer_ptr != NULL)
    {
        /* defer already exists, replace it */
        defer_ptr->callback = (mmi_frm_defer_cb_type)deferred_cb;
        defer_ptr->int_type = (U16)interrupt;
        defer_ptr->arg      = arg;
    }
    else
    {
        /* new defer */
        add_defer_notification(res_id, (mmi_frm_defer_cb_type)deferred_cb, (U16)interrupt, arg);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_deregister_deferring_notification
 * DESCRIPTION
 *  this function is used to de-register deferring notification from deferring queue
 * PARAMETERS
 *  res_id  [IN] resource id to identify deferring notification
 * RETURNS
 *  success or not
 *****************************************************************************/
MMI_BOOL mmi_frm_deregister_deferring_notification(U16 res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(res_id > 0); /* should have valid res ID */

    if (get_defer_notification(res_id) != NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_DEREGISTER_DEFER, res_id);  
        del_defer_notification(res_id);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  is_scenario_flag_set
 * DESCRIPTION
 *  this function is used to check if specified flag set for given scenario index.
 * PARAMETERS
 *  idx     [IN] index for interested scenario
 *  flag    [IN] flag to check
 * RETURNS
 *  is flag set or not
 *****************************************************************************/
__inline MMI_BOOL is_scenario_flag_set(S32 idx, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((g_notify_service_cntx.scenario_info[idx] & flag) == flag);
}


/*****************************************************************************
 * FUNCTION
 *  set_scenario_flag
 * DESCRIPTION
 *  this function is used to set specified flag to given scenario
 * PARAMETERS
 *  idx     [IN] index for interested scenario
 *  flag    [IN] flag to set
 * RETURNS
 *  void
 *****************************************************************************/
__inline void set_scenario_flag(S32 idx, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_notify_service_cntx.scenario_info[idx] |= flag;
}


/*****************************************************************************
 * FUNCTION
 *  clear_scenario_flag
 * DESCRIPTION
 *  this function is used to clear specified flag for given scenario
 * PARAMETERS
 *  idx     [IN] index for interested scenario
 *  flag    [IN] flag to clear
 * RETURNS
 *  void
 *****************************************************************************/
__inline void clear_scenario_flag(S32 idx, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_notify_service_cntx.scenario_info[idx] &= ~flag;
}


/*****************************************************************************
 * FUNCTION
 *  get_defer_notification_count
 * DESCRIPTION
 *  this function is used to get deferred notification count in queue
 * PARAMETERS
 *  void
 * RETURNS
 *  notification count
 *****************************************************************************/
__inline S32 get_defer_notification_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_notify_service_cntx.defer_info.used;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_process_deferred_notification
 * DESCRIPTION
 *  this function is used to process deferred notification. 
 *  if any notification left in queue, it starts a timer to invoke next.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_process_deferred_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_defer_item_struct *defer_ptr;
    mmi_frm_defer_item_struct defer_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    StopTimer(MMI_NOTIFICATION_SERVICE_TIMER);

    defer_ptr = get_defer_notification(0);

    if (defer_ptr != NULL)  /* allow-to-execute defer exists */
    {
        defer_item = *defer_ptr;
        del_defer_notification(defer_item.res_id);

        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_DEFER_INVOKED, defer_item.res_id, defer_item.callback, defer_item.int_type, defer_item.arg);

        /* invoke callback */
        defer_item.callback(get_scenario(), (mmi_frm_int_enum) defer_item.int_type, defer_item.arg);
    }

    /* defer still exists, schedule to trigger next */
    if (get_defer_notification_count())
    {
        /* invoke deferred notification by timer */
        StartTimer(MMI_NOTIFICATION_SERVICE_TIMER, 
            MMI_FRM_NOTIFY_INVOKE_TIME, 
            (FuncPtr)mmi_frm_process_deferred_notification);
    }
}


/*****************************************************************************
 * FUNCTION
 *  update_concurrent_scenario
 * DESCRIPTION
 *  this function is used to update concurrent scenario according to concurrent scenario table.
 *  if concurrent scenario is not correct, correct it.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void update_concurrent_scenario(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL concurrent_exists;
    mmi_frm_scenario_enum scenario;
    U32 condition_count;
    S32 i;
    S8 trc_str[MMI_FRM_SCENARIO_NUM*2 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i=0; i<sizeof(mmi_concurrent_scenario); i++)
    {
        scenario = mmi_concurrent_scenario[i++];    /* get scenario name */
        MMI_ASSERT(scenario < MMI_FRM_SCENARIO_GENERAL);    /* validate scenario */

        concurrent_exists   = MMI_TRUE;
        condition_count     = 0;
        while((i < sizeof(mmi_concurrent_scenario)) && (mmi_concurrent_scenario[i] < MMI_FRM_SCENARIO_GENERAL))
        {
            if (concurrent_exists)
            {
                if (!is_scenario_flag_set(mmi_concurrent_scenario[i], MMI_FRM_SCENARIO_FLAG_SET_RESET))
                {
                    concurrent_exists = MMI_FALSE;
                }
            }
            i++;
            condition_count++;
        }

        if (condition_count)    /* conditions exists in table */
        {
            if (concurrent_exists)
            {
                set_scenario_flag(scenario, MMI_FRM_SCENARIO_FLAG_SET_RESET);
            }
            else
            {
                clear_scenario_flag(scenario, MMI_FRM_SCENARIO_FLAG_SET_RESET);
            }
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_UPDATE_CONCURRENT_SCENARIO, scenario, concurrent_exists);
        }
    }
    
    /* generate scenario status string for debug info */
    for (i=0; i<MMI_FRM_SCENARIO_NUM; i++)
    {
        sprintf(trc_str + i*2, "%1d ", is_scenario_flag_set(i, MMI_FRM_SCENARIO_FLAG_SET_RESET));
    }

    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_FRM_INFO_EVENT_ALL_SCENARIO_STATUS, trc_str);
}


/*****************************************************************************
 * FUNCTION
 *  get_scenario
 * DESCRIPTION
 *  internal function to get MMI scenario
 * PARAMETERS
 *  void
 * RETURNS
 *  current scenario (highest priority if more than 1 is set)
 *****************************************************************************/
static mmi_frm_scenario_enum get_scenario(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get scenario with highest priority, including concurrent scenario */
    for (i=0; i<MMI_FRM_SCENARIO_NUM; i++)
    {
        if (is_scenario_flag_set(i, MMI_FRM_SCENARIO_FLAG_SET_RESET))
            break;
    }
    
    return i;   /* if no scenario is set, MMI_FRM_SCENARIO_GENERAL will be used */
}


/*****************************************************************************
 * FUNCTION
 *  get_behavior
 * DESCRIPTION
 *  internal function to get behavior. 
 *  if MMI_FRM_BEHAVIOR_GENERAL got, lookup general scenario instead.
 * PARAMETERS
 *  scenario    [IN] scenario to lookup for behavior
 *  interrupt   [IN] interrupt to lookup for behavior
 * RETURNS
 *  behavior, contains all factors
 *****************************************************************************/
static mmi_frm_behavior_type get_behavior(mmi_frm_scenario_enum scenario, mmi_frm_int_enum interrupt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_frm_behavior_type behavior;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_ASSERT(interrupt < MMI_INT_END);

    for (i=0; i<MMI_FRM_BEHAVIOR_TABLE_SIZE; i++)
    {
        if (behavior_table[i].scenario == scenario)
        {
            behavior = behavior_table[i].behavior[interrupt];

            if (behavior == MMI_FRM_BEHAVIOR_GENERAL)
            {
                /* use general behavior */
                behavior = behavior_table[MMI_FRM_BEHAVIOR_TABLE_IDX_GENERAL].behavior[interrupt];
            }
            return behavior;
        }
    }

    /* not found, use general behavior */
    return behavior_table[MMI_FRM_BEHAVIOR_TABLE_IDX_GENERAL].behavior[interrupt];

}


/*****************************************************************************
 * FUNCTION
 *  is_ok_to_invoke_defer
 * DESCRIPTION
 *  allow to invoke defer notification or not.
 *  it checks from high to low priority existing scenarios to see 
 *  if all event interface behaviors are TOP for this interrupt.
 * PARAMETERS
 *  interrupt   [IN] interrupt to check for behavior
 * RETURNS
 *  ok to invoke or not
 *****************************************************************************/
static MMI_BOOL is_ok_to_invoke_defer(mmi_frm_int_enum interrupt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL any_scenario_exists = MMI_FALSE;
    MMI_BOOL allow_to_invoke = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* invoke condition: 
       #1. all MMI_FRM_BEHAVIOR_IF_TOP for existing scenarios
       #2. scenarios are all reset => MMI_FRM_BEHAVIOR_IF_TOP for general behavior
    */  

    for (i=0; i<MMI_FRM_SCENARIO_NUM ;i++)
    {
        /* check for existing scenario */
        if (is_scenario_flag_set(i, MMI_FRM_SCENARIO_FLAG_SET_RESET))
        {
            any_scenario_exists = MMI_TRUE;

            if ((get_behavior(i, interrupt) & MMI_FRM_BEHAVIOR_MASK_IF) != MMI_FRM_BEHAVIOR_IF_TOP)
                allow_to_invoke = MMI_FALSE;    /* #1 */
        }
    }

    if (any_scenario_exists == MMI_FALSE)   /* scenarios are all reset */
    {
        /* check general behavior */
        if ((get_behavior(MMI_FRM_SCENARIO_GENERAL, interrupt) & MMI_FRM_BEHAVIOR_MASK_IF) != MMI_FRM_BEHAVIOR_IF_TOP)
            allow_to_invoke = MMI_FALSE;    /* #2 */
    }

    return allow_to_invoke;
}


/*****************************************************************************
 * FUNCTION
 *  get_defer_notification
 * DESCRIPTION
 *  get defer notification with given res_id. 
 *  if res_id is 0, get most recent allow-to-execute defer notification.
 * PARAMETERS
 *  res_id      [IN] resource id to identify defer notification
 * RETURNS
 *  pointer to defer notification item
 *****************************************************************************/
static mmi_frm_defer_item_struct* get_defer_notification(U16 res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (res_id == 0)
    {
        if (g_notify_service_cntx.defer_info.used)
        {
            /* get most recent one */
            for (i=g_notify_service_cntx.defer_info.used - 1; i>=0; i--)
            {
                if (is_ok_to_invoke_defer(g_notify_service_cntx.defer_info.data[i].int_type))
                {
                    /* defer is free to run */
                    return &g_notify_service_cntx.defer_info.data[i];
                }
            }    
        }
    }
    else
    {
        /* search for corresponding defer info */
        for (i=0; i<MMI_FRM_DEFER_NOTIFICATION_NUM; i++)
        {
            if (g_notify_service_cntx.defer_info.data[i].res_id == res_id)
            {
                return &g_notify_service_cntx.defer_info.data[i];
            }
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  add_defer_notification
 * DESCRIPTION
 *  internal function to add defer notification to queue
 * PARAMETERS
 *  res_id      [IN] resource id to identify this defer notification
 *  deferred_cb [IN] deferring callback
 *  interrupt   [IN] interrupt type
 *  arg         [IN] argument
 * RETURNS
 *  void
 *****************************************************************************/
static void add_defer_notification(U16 res_id, mmi_frm_defer_cb_type deferred_cb, U16 interrupt, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx = g_notify_service_cntx.defer_info.used;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(res_id > 0);     /* validate res_id */

    /* make sure defer table is enough */
    MMI_ASSERT(idx < MMI_FRM_DEFER_NOTIFICATION_NUM);
    
    g_notify_service_cntx.defer_info.data[idx].res_id   = res_id;
    g_notify_service_cntx.defer_info.data[idx].callback = deferred_cb;
    g_notify_service_cntx.defer_info.data[idx].int_type = interrupt;
    g_notify_service_cntx.defer_info.data[idx].arg      = arg;

    g_notify_service_cntx.defer_info.used++;
}


/*****************************************************************************
 * FUNCTION
 *  del_defer_notification
 * DESCRIPTION
 *  internal function to delete defer notification in queue
 * PARAMETERS
 *  res_id      [IN] resource id to identify which defer notification to del
 * RETURNS
 *  void
 *****************************************************************************/
static void del_defer_notification(U16 res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, idx_to_clear, data_to_move;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(res_id > 0);     /* validate res_id */

    for (i=0; i<MMI_FRM_DEFER_NOTIFICATION_NUM; i++)
    {
        if (g_notify_service_cntx.defer_info.data[i].res_id == res_id)
        {
            MMI_ASSERT(g_notify_service_cntx.defer_info.used > 0);
            g_notify_service_cntx.defer_info.used--;    /* decrement used */

            data_to_move = g_notify_service_cntx.defer_info.used - i;

            /* there's data behind it */
            if (data_to_move > 0)
            {
                /* replace it with data behind */
                memmove(&g_notify_service_cntx.defer_info.data[i], 
                    &g_notify_service_cntx.defer_info.data[i+1], 
                    sizeof(mmi_frm_defer_item_struct) * data_to_move);

                idx_to_clear = g_notify_service_cntx.defer_info.used;   /* last data should be cleared */
            }
            else
            {
                /* it's last one, just remove it */
                idx_to_clear = i;
            }

            memset(&g_notify_service_cntx.defer_info.data[idx_to_clear], 0, sizeof(mmi_frm_defer_item_struct));
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_send_event
 * DESCRIPTION
 *  Send directly event to designated proc with user data.
 * PARAMETERS
 *  evt              [IN]
 *  proc             [IN]
 *  user_data        [IN]
 * RETURN VALUES
 *  MMI_RET_OK: Emit the event to the specific proc function without return value from the receiver.
 *  Others: Emit the event to the specific proc function and carry the return value from the receiver.
 *****************************************************************************/
mmi_ret mmi_frm_send_event(mmi_event_struct *evt, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt->user_data = user_data;

    return proc(evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_post_event
 * DESCRIPTION
 *  Send post event to designated proc with user data, it will be invoked after current
 *  function flow and before next input event like key, pen, timer, primitive.
 * PARAMETERS
 *  evt              [IN]   event structure pointer;
 *  proc             [IN]   process handler
 *  user_data        [IN]   user data pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_post_event(mmi_event_struct *evt, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_event_proc_struct *post_evt_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL && proc != NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_POST_EVT, evt, evt->evt_id, proc, user_data);
    /* Copy event struct and push into post evt queue */
    post_evt_p = OslMalloc(sizeof(mmi_post_event_proc_struct));
    post_evt_p->evt_p = OslMalloc(evt->size);
    memcpy(post_evt_p->evt_p, evt, evt->size);
    post_evt_p->proc = proc;
    post_evt_p->evt_p->user_data = user_data;

    enqueue_post_evt((void *)post_evt_p, POST_EVT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_post_event_ex
 * DESCRIPTION
 *  Send post event to designated proc with user data, it will be invoked after current
 *  function flow and before next input event like key, pen, timer, primitive.
 *  And result callback will be invoked with EVT_ID_POST_CB_RST and result_cb_user_data to
 *  notify sender the result.
 * PARAMETERS
 *  evt                 [IN]   event structure pointer;
 *  proc                [IN]   designated process handler;
 *  user_data           [IN]   designated user data pointer;
 *  result_cb           [IN]   result process handler;
 *  result_cb_user_data [IN]   result user data;
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_post_event_ex(mmi_event_struct *evt, mmi_proc_func proc, void *user_data, mmi_post_event_result_proc_func result_cb, void *result_cb_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_event_proc_ex_struct *post_evt_ex_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt != NULL && proc != NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_CB_POST_EVT_EX, evt, evt->evt_id, proc, user_data, result_cb, result_cb_user_data);
    /* Copy event struct and push into post evt queue */
    post_evt_ex_p = OslMalloc(sizeof(mmi_post_event_proc_ex_struct));
    post_evt_ex_p->evt_p = OslMalloc(evt->size);
    memcpy(post_evt_ex_p->evt_p, evt, evt->size);
    post_evt_ex_p->proc = proc;
    post_evt_ex_p->evt_p->user_data = user_data;
    post_evt_ex_p->result_cb = result_cb;
    post_evt_ex_p->result_cb_user_data = result_cb_user_data;

    enqueue_post_evt((void *)post_evt_ex_p, POST_EVT_EX);
}


/**************************************************************************************
 * Post event mechanism
 **************************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_event_posted
 * DESCRIPTION
 *  Check if event is in post event queue.
 * PARAMETERS
 *  evt_p :      [IN]  event structure pointer.
 * RETURNS
 *  Return MMI_TRUE if the designated post event is in queue by checking event id & user data pointer,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_is_event_posted(mmi_event_struct *check_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position;
    mmi_event_struct *post_evt_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!post_evt_header || !check_evt_p)
    {
        return MMI_FALSE;
    }
    
    for (position = post_evt_header->next; position != NULL; position = position->next)
    {/* position should point to current cell */
        post_evt_p = (mmi_event_struct *)position->evt_p;
        if (post_evt_p->evt_id == check_evt_p->evt_id && post_evt_p->user_data == check_evt_p->user_data)
        {
            return MMI_TRUE;
        }        
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_post_evt_num
 * DESCRIPTION
 *  Get event number of post queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return event number.
 *****************************************************************************/
U32 mmi_frm_get_post_evt_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position;
    U32 num = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!post_evt_header)
    {
        return 0;
    }
    for (position = post_evt_header->next; position != NULL; position = position->next)
    {
        num++;
    }
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_post_evt_queue_empty
 * DESCRIPTION
 *  Check if post event queue is empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if there is some post event in queue, 
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_is_post_evt_queue_empty(void)
{
    return (post_evt_header == NULL) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  enqueue_post_evt
 * DESCRIPTION
 *  Enqueue event into post event queue.
 * PARAMETERS
 *  evt_p             [IN]  event structure pointer;
 *  evt_flag          [IN]  post event type;
 * RETURNS
 *  Return event number.
 *****************************************************************************/
void enqueue_post_evt(void *evt_p, U8 evt_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position, *tmp_cell;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != evt_p);
    if (!post_evt_header)
    {
        post_evt_header = OslMalloc(sizeof(mmi_post_evt_node_struct));
        memset(post_evt_header, 0, sizeof(mmi_post_evt_node_struct));
    }
    for (position = post_evt_header; position->next != NULL; position = position->next)
    /* position should point to previous cell */
        ;
    tmp_cell = OslMalloc(sizeof(mmi_post_evt_node_struct));
    tmp_cell->flag = evt_flag;
    tmp_cell->evt_p = evt_p;
    tmp_cell->next = position->next;    /* NULL */
    position->next = tmp_cell;
    post_evt_num++;

    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_ENQ_POST_EVT, evt_p, evt_flag, post_evt_num);
}


/*****************************************************************************
 * FUNCTION
 *  dequeue_post_evt
 * DESCRIPTION
 *  Dequeue post event with designated event type.
 * PARAMETERS
 *  evt_flag             [IN]  post event type;
 * RETURNS
 *  void
 *****************************************************************************/
void *dequeue_post_evt(U8 *evt_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_post_evt_node_struct *position;
    void *evt_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!post_evt_header)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_DEQ_POST_EVT_NULL);
        return NULL;
}
    position = post_evt_header->next;
    if (!position)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_DEQ_POST_EVT_EMPTY);
        return NULL;
    }
    post_evt_header->next = position->next;
    evt_p = position->evt_p;
    *evt_flag = position->flag;
    OslMfree(position);
    MMI_ASSERT(NULL != evt_p);

    if (!post_evt_header->next)
    {
        OslMfree(post_evt_header);
		post_evt_header = NULL;
    }
    post_evt_num--;
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_DEQ_POST_EVT, evt_p, ((mmi_event_struct *)evt_p)->evt_id, *evt_flag, post_evt_num);

    return evt_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_invoke_post_event
 * DESCRIPTION
 *  Emit post events, the callback of this events will be invoked after current 
 *  function flow.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_RET_ERR_NO_POST_EVENT if there is no post event,
 *  Return MMI_RET_ERR_UNKNOWN_EVT_FLAG if can't find event flag,
 *  otherwise return result of callback function;
 *****************************************************************************/
S32 mmi_frm_invoke_post_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *evt_p;
    U8 evt_flag;
    S32 result = MMI_RET_ERR;
    MMI_BOOL has_evt = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (post_evt_num == 0)
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_INVOKE_POST_EVT_NULL);
        result = MMI_RET_ERR_NO_POST_EVENT;
    }
    else
    {
        has_evt = MMI_TRUE;
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_INVOKE_POST_EVT_BEGIN, post_evt_num);
    }

    if (has_evt)
    {
        while (NULL != (evt_p = dequeue_post_evt(&evt_flag)))
        {
            MMI_ASSERT(NULL != evt_p);

            if (evt_flag == POST_CB_EVT)
            {
            result = MMI_FRM_CB_EMIT_EVENT(evt_p);
                OslMfree(evt_p);
            }
            else if (evt_flag == POST_CB_EVT_EX)
            {
                mmi_post_evt_ex_struct *evt_ex_p = (mmi_post_evt_ex_struct *)evt_p;
                mmi_post_result_event_struct rst_evt;
                S32 rst;

                /* Send posted event */
            rst = MMI_FRM_CB_EMIT_EVENT(evt_ex_p->evt_p);

                /* Feedback to caller by result callback */
                rst_evt.evt_id = EVT_ID_POST_CB_RST;
                rst_evt.user_data = evt_ex_p->result_cb_user_data;
                rst_evt.result = rst;
                rst_evt.evt_p = evt_ex_p->evt_p;
                result = evt_ex_p->result_cb(&rst_evt);
            
                OslMfree(evt_ex_p->evt_p);
                OslMfree(evt_ex_p);
            }
            else if (evt_flag == POST_EVT)
            {
                mmi_post_event_proc_struct *post_evt_p = (mmi_post_event_proc_struct *)evt_p;

                result = post_evt_p->proc(post_evt_p->evt_p);
            
                OslMfree(post_evt_p->evt_p);
                OslMfree(post_evt_p);
            }
            else if (evt_flag == POST_EVT_EX)
            {
                mmi_post_event_proc_ex_struct *post_evt_ex_p = (mmi_post_event_proc_ex_struct *)evt_p;
                mmi_post_result_event_struct rst_evt;
                S32 rst;

                /* Send posted event to designated proc */
                rst = post_evt_ex_p->proc(post_evt_ex_p->evt_p);
            
                /* Feedback to caller by result callback */
                rst_evt.evt_id = EVT_ID_POST_CB_RST;
                rst_evt.user_data = post_evt_ex_p->result_cb_user_data;
                rst_evt.result = rst;
                rst_evt.evt_p = post_evt_ex_p->evt_p;
                result = post_evt_ex_p->result_cb(&rst_evt);

                OslMfree(post_evt_ex_p->evt_p);
                OslMfree(post_evt_ex_p);
            }
            else
            {
                MMI_ASSERT(0);
                result = MMI_RET_ERR_UNKNOWN_EVT_FLAG;
            }
        }
    
        MMI_ASSERT(post_evt_num == 0);
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_CB_INVOKE_POST_EVT_END);
    }

    /* After handling the post events, we check if need to dump the screen history. */
    if (mmi_frm_event_get_dump_history_flag())
    {
        HistoryDump();
        mmi_frm_event_set_dump_history_flag(MMI_FALSE);

        /* if need to dump the screen id. */
        mmi_frm_dump_screen_id();
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_evt_id
 * DESCRIPTION
 *  Get event id from event structure.
 * PARAMETERS
 *  evt :      [IN]  post event structure pointer.
 * RETURNS
 *  Return event id;
 *****************************************************************************/
U16 mmi_frm_get_evt_id(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return evt->evt_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_evt_user_data
 * DESCRIPTION
 *  Get user data from event structure.
 * PARAMETERS
 *  evt :      [IN]  post event structure pointer.
 * RETURNS
 *  Return user data;
 *****************************************************************************/
void *mmi_frm_get_evt_user_data(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return evt->user_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_post_event_number
 * DESCRIPTION
 *  Get user data from event structure.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return post event number;
 *****************************************************************************/
U8 mmi_frm_get_post_event_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return post_evt_num;
}

