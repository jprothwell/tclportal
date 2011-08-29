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
 * SSCStringHandle.C
 *
 * Project:
 * --------
 *   PlutoMMI
 *
 * Description:
 * ------------
 *   To handle the ssc string.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *============================================================================
 ****************************************************************************/

/* MTK Add Robin 1001 for saperate MMI feature by project */
#include "MMI_include.h"
/* MTK End */

#include "FontDcl.h"
#include "StatusIconRes.h"
#include "MiscFunctions.h"
#include "SimDetectionGprot.h"
#include "SettingProfile.h"
#include "PhonebookDef.h"
#include "SettingDefs.h"
#include "wgui_status_icons.h"
#include "CallManagementGprot.h"
#include "ProtocolEvents.h"
#include "SSCStringHandle.h"
#include "SettingGprots.h"
#include "SettingsGexdcl.h"
#include "SimDetectionGexdcl.h"
#include "GSM7BitDefaultAlphabet.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "SettingProt.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "CustResDef.h"
#include "ATHandlerProt.h"
#include "CommonScreens.h"
#include "CallManagementIdDef.h"
#include "ProfileGprots.h"
#include "ProfilesDefs.h"
#include "DevAppGprot.h"
#include "IdleHomescreenGProt.h"

#ifdef __FLAVOR_VENDOR_SDK__
extern void mmi_entry_avk_app_scr(void);
#endif

/* for pts V2.1.0.4 */
/* cannot update indicators to remote bluetooth headset while HFP is connected */
/* indicators shall be retrieved by remote HF AT+CIND? */
/* so for pts V2.1.0.4, host will not udpate indicators while HFP is just connected */
#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif
#ifdef __MMI_SML_MENU__
#include "PersonalizationProt.h"
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_Slave_common_def.h"
#include "MTPNP_AD_master_if.h"
#endif

/**********************************************/
/*   Local Functions                          */
/**********************************************/
void SSCHandleLngAutoMode(void);
void SSCHandleLngEnglish(void);
void SSCHandleLngChinese(void);
void SSCHandleLngSimplify(void);

#if defined(__MMI_LANG_SPANISH__)
void SSCHandleLngSpanish(void);
#endif 
#if defined(__MMI_LANG_DANISH__)
void SSCHandleLngDanish(void);
#endif 
#if defined(__MMI_LANG_POLISH__)
void SSCHandleLngPolish(void);
#endif 
#if defined(__MMI_LANG_FRENCH__)
void SSCHandleLngFrench(void);
#endif 
#if defined(__MMI_LANG_GERMAN__)
void SSCHandleLngGerman(void);
#endif 
#if defined(__MMI_LANG_ITALIAN__)
void SSCHandleLngItalian(void);
#endif 
#if defined(__MMI_LANG_THAI__)
void SSCHandleLngThai(void);
#endif 
#if defined(__MMI_LANG_RUSSIAN__)
void SSCHandleLngRussian(void);
#endif 
#if defined(__MMI_LANG_BULGARIAN__)
void SSCHandleLngBulgarian(void);
#endif 
#if defined(__MMI_LANG_UKRAINIAN__)
void SSCHandleLngUkrainian(void);
#endif 
#if defined(__MMI_LANG_PORTUGUESE__)
void SSCHandleLngPortuguese(void);
#endif 
#if defined(__MMI_LANG_TURKISH__)
void SSCHandleLngTurkish(void);
#endif 
#if defined(__MMI_LANG_VIETNAMESE__)
void SSCHandleLngVietnamese(void);
#endif 
#if defined(__MMI_LANG_INDONESIAN__)
void SSCHandleLngIndonesian(void);
#endif 
#if defined(__MMI_LANG_CZECH__)
void SSCHandleLngCzech(void);
#endif 
#if defined(__MMI_LANG_MALAY__)
void SSCHandleLngMalay(void);
#endif 
#if defined(__MMI_LANG_FINNISH__)
void SSCHandleLngFinnish(void);
#endif 
#if defined(__MMI_LANG_HUNGARIAN__)
void SSCHandleLngHungarian(void);
#endif 
#if defined(__MMI_LANG_SLOVAK__)
void SSCHandleLngSlovak(void);
#endif 
#if defined(__MMI_LANG_DUTCH__)
void SSCHandleLngDutch(void);
#endif 
#if defined(__MMI_LANG_NORWEGIAN__)
void SSCHandleLngNorwegian(void);
#endif 
#if defined(__MMI_LANG_SWEDISH__)
void SSCHandleLngSwedish(void);
#endif 
#if defined(__MMI_LANG_CROATIAN__)
void SSCHandleLngCroatian(void);
#endif 
#if defined(__MMI_LANG_ROMANIAN__)
void SSCHandleLngRomanian(void);
#endif 
#if defined(__MMI_LANG_SLOVENIAN__)
void SSCHandleLngSlovenian(void);
#endif 

#if defined(__MMI_LANG_GREEK__)
void SSCHandleLngGreek(void);
#endif 

#if defined (__MMI_LANG_HEBREW__)
void SSCHandleLngHebrew(void);
#endif /* defined (__MMI_LANG_HEBREW__) */ 

#if defined (__MMI_LANG_ARABIC__)
void SSCHandleLngArabic(void);
#endif /* defined (__MMI_LANG_ARABIC__) */ 

#if defined (__MMI_LANG_PERSIAN__)
void SSCHandleLngPersian(void);
#endif 

#if defined (__MMI_LANG_URDU__)
void SSCHandleLngUrdu(void);
#endif 

#if defined (__MMI_LANG_HINDI__)
void SSCHandleLngHindi(void);
#endif /* defined (__MMI_LANG_HINDI__) */ 

#if defined (__MMI_LANG_MARATHI__)
void SSCHandleLngMarathi(void);
#endif 
#if defined (__MMI_LANG_TAMIL__)
void SSCHandleLngTamil(void);
#endif 
#if defined (__MMI_LANG_BENGALI__)
void SSCHandleLngBengali(void);
#endif /* defined (__MMI_LANG_BENGALI__) */ 
#if defined (__MMI_LANG_ASSAMESE__)
void SSCHandleLngAssamese(void);
#endif /* defined (__MMI_LANG_ASSAMESE__) */ 
#if defined (__MMI_LANG_PUNJABI__)
void SSCHandleLngPunjabi(void);
#endif
#if defined (__MMI_LANG_TELUGU__)
void SSCHandleLngTelugu(void);
#endif
#if defined (__MMI_LANG_XHOSA__)
void SSCHandleLngXhosa(void);
#endif
#if defined (__MMI_LANG_SWAHILI__)
void SSCHandleLngSwahili(void);
#endif
#if defined (__MMI_LANG_AFRIKAANS__)
void SSCHandleLngAfrikaans(void);
#endif
#if defined (__MMI_LANG_SA_PORTUGUESE__)
void SSCHandleLngBzPortuguese(void);
#endif
#if defined (__MMI_LANG_CA_FRENCH__)
void SSCHandleLngCaFRench(void);
#endif
#if defined (__MMI_LANG_SA_SPANISH__)
void SSCHandleLngLatinAmSpanish(void);
#endif
#if defined (__MMI_LANG_HK_CHINESE__)
void SSCHandleLngCantoneseChinese(void);
#endif
#if defined (__MMI_LANG_UK_ENGLISH__)
void SSCHandleLngUKEnglish(void);
#endif
#if defined (__MMI_LANG_ICELANDIC__)
void SSCHandleLngIcelandic(void);
#endif
#if defined (__MMI_LANG_SERBIAN__)
void SSCHandleLngSerbian(void);
#endif
#if defined (__MMI_LANG_AZERBAIJANI__)
void SSCHandleLngAzerbaijani(void);
#endif
#if defined (__MMI_LANG_CATALAN__)
void SSCHandleLngCatalan(void);
#endif
#if defined (__MMI_LANG_HAUSA__)
void SSCHandleLngHausa(void);
#endif
#if defined (__MMI_LANG_GALICIAN__)
void SSCHandleLngGalician(void);
#endif
#if defined (__MMI_LANG_BASQUE__)
void SSCHandleLngBasque(void);
#endif
#if defined (__MMI_LANG_IGBO__)
void SSCHandleLngIgbo(void);
#endif
#if defined (__MMI_LANG_FILIPINO__)
void SSCHandleLngFilipino(void);
#endif
#if defined (__MMI_LANG_IRISH__)
void SSCHandleLngIrish(void);
#endif
#if defined (__MMI_LANG_KAZAKH__)
void SSCHandleLngKazakh(void);
#endif
#if defined (__MMI_LANG_MACEDONIAN__)
void SSCHandleLngMacedonian(void);
#endif
#if defined (__MMI_LANG_SESOTHO__)
void SSCHandleLngSesotho(void);
#endif
#if defined (__MMI_LANG_TAGALOG__)
void SSCHandleLngTagalog(void);
#endif
#if defined (__MMI_LANG_YORUBA__)
void SSCHandleLngYoruba(void);
#endif
#if defined (__MMI_LANG_ZULU__)
void SSCHandleLngZulu(void);
#endif
#if defined (__MMI_LANG_LITHUANIAN__)
void SSCHandleLngLithuanian(void);
#endif
#if defined (__MMI_LANG_LATVIAN__)
void SSCHandleLngLatvian(void);
#endif
#if defined (__MMI_LANG_ESTONIAN__)
void SSCHandleLngEstonian(void);
#endif
#if defined (__MMI_LANG_ALBANIAN__)
void SSCHandleLngAlbanian(void);
#endif
#if defined (__MMI_LANG_ARMENIAN__)
void SSCHandleLngArmenian(void);
#endif
#if defined (__MMI_LANG_GEORGIAN__)
void SSCHandleLngGeorgian(void);
#endif
#if defined (__MMI_LANG_MOLDOVAN__)
void SSCHandleLngMoldovan(void);
#endif
#if defined (__MMI_LANG_KANNADA__)
void SSCHandleLngKannada(void);
#endif
#if defined (__MMI_LANG_MALAYALAM__)
void SSCHandleLngMalayalam(void);
#endif
#if defined (__MMI_LANG_GUJARATI__)
void SSCHandleLngGujarati(void);
#endif
#if defined (__MMI_LANG_ORIYA__)
void SSCHandleLngOriya(void);
#endif
void SSCHandleIMEI(void);
void SSCHandleSoftwareVersion(void);

/* Lisen 0921 */
void SSCHandleSoftwareVersionSummary(void);
void SSCHandleLCDContrastSetting(void);

#ifdef __MMI_HW_VERSION__
void SSCHandleHardwareVersion(void);
#endif 
void SSCHandleEngineerMode(void);
void SSCHandleSerialNumber(void);
void SSCHandleFactoryMode(void);
void SSCHandleFactoryModeAutoTest(void);
void SendReqPIN1Status(void);
void SendReqPIN2Status(void);
void SSCChangePIN1(void *);
void SSCChangePIN2(void *);
void SSCEntryPUK1(void);
void SSCEntryPUK2(void);
void ShowIMEIScreen(void);
void SSCAbnormalReset(void);
void SSCHandleIrClose(void);
void SSCHandleIrOpen(void);
PS8 Serial_num(void);
void SSCHandleDisable(void);    /* diamond, 2005/05/13 for SSC disable */

#ifdef __MMI_A2DP_SUPPORT__
void SSCHandle_BT_A2DP_Toggle_PTS_Mode(void);
#endif /* __MMI_A2DP_SUPPORT__ */ 

#ifdef __BTMTK__
void SSCHandle_BT_POWER_ON(void);
void SSCHandle_BT_POWER_OFF(void);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
void SSCHandle_BT_PTS_SIMAP_Graceful_Disc_Type(void);
void SSCHandle_BT_PTS_SIMAP_Immediate_Disc_Type(void);
void SSCHandle_BT_PTS_SIMAP_PRS(void);
#endif /* __BTMTK__ */ 

extern void FillCountDownNumber(sim_chv_info_struct chv_info);
extern void EntryFMVersionSummaryMenu(void);
extern void EntryFMLCDContrastMenuHdlr(void);
#ifdef __DRM_V02__
extern void OSD_STime_Switch(void);
extern void OSD_PKI_Format_Switch(void);
extern void mmi_rmgr_switch_cermgr(void);
#endif
static void SSCHandleVendorApp(void);

#ifdef __FLAVOR_VENDOR_SDK__
static void SSCHandleAvkApp(void);
#endif

#ifdef __VENUS_UI_ENGINE__
static void SSCHandleVenusUITest(void);
#endif

#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
extern void em_gps_open_soc(void);
extern void em_gps_close_soc(void);
extern void em_gps_reset_data_102(void);
extern void em_gps_reset_data_103(void);
extern void em_gps_reset_data_104(void);
extern void em_gps_gps_reset_chip_on_104(void);
extern void em_gps_gps_reset_chip_off_104(void);
extern void em_gps_gps_reset_chip_on_103(void);
extern void em_gps_gps_reset_chip_off_103(void);
#endif

S8 ssc_dialpad_buffer[MAX_DIAL_PAD * ENCODING_LENGTH];
/* IMEI:135790246811220 */
/* IMEISV:00 */
#ifdef __MMI_DUAL_SIM_MASTER__
#ifdef __MMI_IMEISV_SUPPORT__
static S8 gstrIMEI[MAX_IMEISV_DISPLAY_LEN * 2 * ENCODING_LENGTH];
#else
static S8 gstrIMEI[((MAX_IMEI_LEN + 1) * 2 + 1)* ENCODING_LENGTH];
#endif
#else /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_IMEISV_SUPPORT__
static S8 gstrIMEI[MAX_IMEISV_DISPLAY_LEN * ENCODING_LENGTH];
#else
static S8 gstrIMEI[(MAX_IMEI_LEN + 1) * ENCODING_LENGTH];
#endif
#endif /* __MMI_DUAL_SIM_MASTER__ */

/* diamond, 2005/05/13 for SSC disable
   MMI_FALSE (0): ssc string unchanged
   MMI_TRUE  (1): before executing ssc, check the 'ssc_disable_ctrl' flag first
   0xFF: read NVRAM first */
extern U8 ssc_disable_flag;

typedef struct sscstringtblstruct
{
    const S8 *ssc_string;
    /* diamond, 2005/05/13 for SSC disable
       MMI_FALSE (0): ssc cannot be disabled
       MMI_TRUE  (1): ssc can be disabled */
    const U8 ssc_disable_ctrl;
    FuncPtr func_ptr;
} SSCSTRINGTBL;

typedef struct simstringtblstruct
{
    const S8 *sim_string;
    S8 sim_length;
    FuncPtr func_ptr;
} SIMSTRINGTBL;

/* micha1129 begin */

SSCSTRINGTBL ssc_table2[] = 
{
    /* diamond, 2005/05/13 for SSC disable */
    {SSC_AUTO, MMI_FALSE, SSCHandleLngAutoMode},
    {SSC_ENGLISH, MMI_FALSE, SSCHandleLngEnglish},
#if defined(__MMI_LANG_TR_CHINESE__)
    {SSC_TCHINESE, MMI_FALSE, SSCHandleLngChinese},
#endif
#if defined(__MMI_LANG_SPANISH__)
    {SSC_SPANISH, MMI_FALSE, SSCHandleLngSpanish},
#endif 
#if defined(__MMI_LANG_DANISH__)
    {SSC_DANISH, MMI_FALSE, SSCHandleLngDanish},
#endif 
#if defined(__MMI_LANG_POLISH__)
    {SSC_POLISH, MMI_FALSE, SSCHandleLngPolish},
#endif 
#if defined(__MMI_LANG_FRENCH__)
    {SSC_FRENCH, MMI_FALSE, SSCHandleLngFrench},
#endif 
#if defined(__MMI_LANG_GERMAN__)
    {SSC_GERMAN, MMI_FALSE, SSCHandleLngGerman},
#endif 
#if defined(__MMI_LANG_ITALIAN__)
    {SSC_ITALIAN, MMI_FALSE, SSCHandleLngItalian},
#endif 
#if defined(__MMI_LANG_THAI__)
    {SSC_THAI, MMI_FALSE, SSCHandleLngThai},
#endif 
#if defined(__MMI_LANG_RUSSIAN__)
    {SSC_RUSSIAN, MMI_FALSE, SSCHandleLngRussian},
#endif 
#if defined(__MMI_LANG_BULGARIAN__)
    {SSC_BULGARIAN, MMI_FALSE, SSCHandleLngBulgarian},
#endif 
#if defined(__MMI_LANG_UKRAINIAN__)
    {SSC_UKRAINIAN, MMI_FALSE, SSCHandleLngUkrainian},
#endif 
#if defined(__MMI_LANG_PORTUGUESE__)
    {SSC_PORTUGUESE, MMI_FALSE, SSCHandleLngPortuguese},
#endif 
#if defined(__MMI_LANG_TURKISH__)
    {SSC_TURKISH, MMI_FALSE, SSCHandleLngTurkish},
#endif 
#if defined(__MMI_LANG_VIETNAMESE__)
    {SSC_VIETNAMESE, MMI_FALSE, SSCHandleLngVietnamese},
#endif 
#if defined(__MMI_LANG_INDONESIAN__)
    {SSC_INDONESIAN, MMI_FALSE, SSCHandleLngIndonesian},
#endif 
#if defined(__MMI_LANG_CZECH__)
    {SSC_CZECH, MMI_FALSE, SSCHandleLngCzech},
#endif 
#if defined(__MMI_LANG_MALAY__)
    {SSC_MALAY, MMI_FALSE, SSCHandleLngMalay},
#endif 
#if defined(__MMI_LANG_FINNISH__)
    {SSC_FINNISH, MMI_FALSE, SSCHandleLngFinnish},
#endif 
#if defined(__MMI_LANG_HUNGARIAN__)
    {SSC_HUNGARIAN, MMI_FALSE, SSCHandleLngHungarian},
#endif 
#if defined(__MMI_LANG_SLOVAK__)
    {SSC_SLOVAK, MMI_FALSE, SSCHandleLngSlovak},
#endif 
#if defined(__MMI_LANG_DUTCH__)
    {SSC_DUTCH, MMI_FALSE, SSCHandleLngDutch},
#endif 
#if defined(__MMI_LANG_NORWEGIAN__)
    {SSC_NORWEGIAN, MMI_FALSE, SSCHandleLngNorwegian},
#endif 
#if defined(__MMI_LANG_SWEDISH__)
    {SSC_SWEDISH, MMI_FALSE, SSCHandleLngSwedish},
#endif 
#if defined(__MMI_LANG_CROATIAN__)
    {SSC_CROATIAN, MMI_FALSE, SSCHandleLngCroatian},
#endif 
#if defined(__MMI_LANG_ROMANIAN__)
    {SSC_ROMANIAN, MMI_FALSE, SSCHandleLngRomanian},
#endif 
#if defined(__MMI_LANG_SLOVENIAN__)
    {SSC_SLOVENIAN, MMI_FALSE, SSCHandleLngSlovenian},
#endif 
#if defined(__MMI_LANG_GREEK__)
    {SSC_GREEK, MMI_FALSE, SSCHandleLngGreek},
#endif 
#if defined (__MMI_LANG_HEBREW__)
    {SSC_HEBREW, MMI_FALSE, SSCHandleLngHebrew},
#endif /* defined (__MMI_LANG_HEBREW__) */ 
#if defined (__MMI_LANG_ARABIC__)
    {SSC_ARABIC, MMI_FALSE, SSCHandleLngArabic},
#endif /* defined (__MMI_LANG_ARABIC__) */ 
#if defined (__MMI_LANG_PERSIAN__)
    {SSC_PERSIAN, MMI_FALSE, SSCHandleLngPersian},
#endif 
#if defined (__MMI_LANG_URDU__)
    {SSC_URDU, MMI_FALSE, SSCHandleLngUrdu},
#endif
#if defined (__MMI_LANG_HINDI__)
    {SSC_HINDI, MMI_FALSE, SSCHandleLngHindi},
#endif /* defined (__MMI_LANG_HINDI__) */ 
#if defined (__MMI_LANG_MARATHI__)
    {SSC_MARATHI, MMI_FALSE, SSCHandleLngMarathi},
#endif 
#if defined (__MMI_LANG_TAMIL__)
    {SSC_TAMIL, MMI_FALSE, SSCHandleLngTamil},
#endif
#if defined (__MMI_LANG_UK_ENGLISH__)
    {SSC_UK_ENGLISH, MMI_FALSE, SSCHandleLngUKEnglish},
#endif    
#if defined (__MMI_LANG_HK_CHINESE__)
    {SSC_HK_CHINESE, MMI_FALSE, SSCHandleLngCantoneseChinese},
#endif
#if defined (__MMI_LANG_CA_FRENCH__)
    {SSC_CA_FRENCH, MMI_FALSE, SSCHandleLngCaFRench},
#endif
#if defined (__MMI_LANG_SA_SPANISH__)
    {SSC_SA_SPANISH, MMI_FALSE, SSCHandleLngLatinAmSpanish},
#endif
#if defined (__MMI_LANG_SA_PORTUGUESE__)
    {SSC_SA_PORTUGUESE, MMI_FALSE, SSCHandleLngBzPortuguese},
#endif
#if defined (__MMI_LANG_ICELANDIC__)
    {SSC_ICELANDIC, MMI_FALSE, SSCHandleLngIcelandic},
#endif
#if defined (__MMI_LANG_SERBIAN__)
    {SSC_SERBIAN, MMI_FALSE, SSCHandleLngSerbian},
#endif
#if defined (__MMI_LANG_AZERBAIJANI__)
    {SSC_AZERBAIJANI, MMI_FALSE, SSCHandleLngAzerbaijani},
#endif
#if defined (__MMI_LANG_CATALAN__)
    {SSC_CATALAN, MMI_FALSE, SSCHandleLngCatalan},
#endif
#if defined (__MMI_LANG_KAZAKH__)
    {SSC_KAZAKH, MMI_FALSE, SSCHandleLngKazakh},
#endif
#if defined (__MMI_LANG_HAUSA__)
    {SSC_HAUSA, MMI_FALSE, SSCHandleLngHausa},
#endif
#if defined (__MMI_LANG_MACEDONIAN__)
    {SSC_MACEDONIAN, MMI_FALSE, SSCHandleLngMacedonian},
#endif
#if defined (__MMI_LANG_SESOTHO__)
    {SSC_SESOTHO, MMI_FALSE, SSCHandleLngSesotho},
#endif
#if defined (__MMI_LANG_TAGALOG__)
    {SSC_TAGALOG, MMI_FALSE, SSCHandleLngTagalog},
#endif
#if defined (__MMI_LANG_YORUBA__)
    {SSC_YORUBA, MMI_FALSE, SSCHandleLngYoruba},
#endif
#if defined (__MMI_LANG_GALICIAN__)
    {SSC_GALICIAN, MMI_FALSE, SSCHandleLngGalician},
#endif
#if defined (__MMI_LANG_BASQUE__)
    {SSC_BASQUE, MMI_FALSE, SSCHandleLngBasque},
#endif
#if defined (__MMI_LANG_IGBO__)
    {SSC_IGBO, MMI_FALSE, SSCHandleLngIgbo},
#endif
#if defined (__MMI_LANG_FILIPINO__)
    {SSC_FILIPINO, MMI_FALSE, SSCHandleLngFilipino},
#endif
#if defined (__MMI_LANG_IRISH__)
    {SSC_IRISH, MMI_FALSE, SSCHandleLngIrish},
#endif


#if defined (__MMI_LANG_BENGALI__)
    {SSC_BENGALI, MMI_FALSE, SSCHandleLngBengali},
#endif /* defined (__MMI_LANG_BENGALI__) */ 
#if defined (__MMI_LANG_ASSAMESE__)
    {SSC_ASSAMESE, MMI_FALSE, SSCHandleLngAssamese},
#endif /* defined (__MMI_LANG_ASSAMESE__) */ 
#if defined (__MMI_LANG_PUNJABI__)
    {SSC_PUNJABI, MMI_FALSE, SSCHandleLngPunjabi},
#endif
#if defined (__MMI_LANG_TELUGU__)
    {SSC_TELUGU, MMI_FALSE, SSCHandleLngTelugu},
#endif
#if defined (__MMI_LANG_KANNADA__)
    {SSC_KANNADA, MMI_FALSE, SSCHandleLngKannada},
#endif
#if defined (__MMI_LANG_MALAYALAM__)
    {SSC_MALAYALAM, MMI_FALSE, SSCHandleLngMalayalam},
#endif
#if defined (__MMI_LANG_GUJARATI__)
    {SSC_GUJARATI, MMI_FALSE, SSCHandleLngGujarati},
#endif
#if defined (__MMI_LANG_ORIYA__)
    {SSC_ORIYA, MMI_FALSE, SSCHandleLngOriya},
#endif
#if defined (__MMI_LANG_XHOSA__)
    {SSC_XHOSA, MMI_FALSE, SSCHandleLngXhosa},
#endif
#if defined (__MMI_LANG_SWAHILI__)
    {SSC_SWAHILI, MMI_FALSE, SSCHandleLngSwahili},
#endif
#if defined (__MMI_LANG_AFRIKAANS__)
    {SSC_AFRIKAANS, MMI_FALSE, SSCHandleLngAfrikaans},
#endif
#if defined (__MMI_LANG_ZULU__)
    {SSC_ZULU, MMI_FALSE, SSCHandleLngZulu},
#endif
#if defined (__MMI_LANG_LITHUANIAN__)
    {SSC_LITHUANIAN, MMI_FALSE, SSCHandleLngLithuanian},
#endif
#if defined (__MMI_LANG_LATVIAN__)
    {SSC_LATVIAN, MMI_FALSE, SSCHandleLngLatvian},
#endif
#if defined (__MMI_LANG_ESTONIAN__)
    {SSC_ESTONIAN, MMI_FALSE, SSCHandleLngEstonian},
#endif
#if defined (__MMI_LANG_ALBANIAN__)
    {SSC_ALBANIAN, MMI_FALSE, SSCHandleLngAlbanian},
#endif
#if defined (__MMI_LANG_ARMENIAN__)
    {SSC_ARMENIAN, MMI_FALSE, SSCHandleLngArmenian},
#endif
#if defined (__MMI_LANG_GEORGIAN__)
    {SSC_GEORGIAN, MMI_FALSE, SSCHandleLngGeorgian},
#endif
#if defined (__MMI_LANG_MOLDOVAN__)
    {SSC_MOLDOVAN, MMI_FALSE, SSCHandleLngMoldovan},
#endif
#if defined(__MMI_LANG_SM_CHINESE__)
    {SSC_SCHINESE, MMI_FALSE, SSCHandleLngSimplify}
#endif
    /* diamond, end */
};

/* micha1129 end */

extern void ssc_show_logo_screen(void);

#ifdef __MMI_BT_PROFILE__
U8 g_ssc_bt_a2dp_mode = 0;  /* 0: INT mode, 1: ACP mode, 2: ACP mode for PTS only */
#endif 


/* Vogins Start */
#ifdef __VRE__
extern void mmi_am_show_vre_information(void);
#endif
/* Vogins End */


SSCSTRINGTBL ssc_table1[] = 
{
/* Vogins Start */
#ifdef __VRE__
    {"*#8377#", MMI_TRUE, mmi_am_show_vre_information},
#endif
/* Vogins End */
    {"*#06#", MMI_FALSE, SSCHandleIMEI},
    /* {SSC_SW_VERSION,             SSCHandleSoftwareVersion}, */
    {SSC_SW_VERSION, MMI_FALSE, SSCHandleSoftwareVersionSummary},
#ifdef __MMI_HW_VERSION__
    {SSC_HW_VERSION, MMI_FALSE, SSCHandleHardwareVersion},
#endif
    {SSC_ENGINEERING_MODE, MMI_TRUE, SSCHandleEngineerMode},
    {SSC_FACTORY_MODE, MMI_TRUE, SSCHandleFactoryMode},
    {SSC_FACTORY_MODE_AUTOTEST, MMI_TRUE, SSCHandleFactoryModeAutoTest},
    {SSC_SERIAL_NUMBER, MMI_TRUE, SSCHandleSerialNumber},
    {SSC_SET_LCD_CONTRAST, MMI_TRUE, SSCHandleLCDContrastSetting},
    {SSC_IR_OPEN, MMI_FALSE, SSCHandleIrOpen},
    {SSC_IR_CLOSE, MMI_FALSE, SSCHandleIrClose},
    {SSC_DISABLE_FOR_SHIPMENT, MMI_FALSE, SSCHandleDisable},
/* diamond, 2006/04/11 SML menu implementation */
#ifdef __MMI_SML_MENU__
#ifdef __MMI_DUAL_SIM_MASTER__
    {SSC_SML_LOCK_CODE,	MMI_FALSE, mmi_sml_entry_lock_category_sim_interface},
    {SSC_SML_UNLOCK_CODE, MMI_FALSE, mmi_sml_entry_unlock_category_sim_interface},
    {SSC_SML_ADD_CODE, MMI_FALSE, mmi_sml_entry_add_category_sim_interface},
    {SSC_SML_REMOVE_CODE, MMI_FALSE, mmi_sml_entry_remove_category_sim_interface},
    {SSC_SML_DEACTIVATE_CODE, MMI_FALSE, mmi_sml_entry_permanent_unlock_sim_interface},
#else
    {SSC_SML_LOCK_CODE,	MMI_FALSE, mmi_sml_entry_lock_category_selection},
    {SSC_SML_UNLOCK_CODE, MMI_FALSE, mmi_sml_entry_unlock_category_selection},
    {SSC_SML_ADD_CODE, MMI_FALSE, mmi_sml_entry_add_category_data},
    {SSC_SML_REMOVE_CODE, MMI_FALSE, mmi_sml_entry_remove_category_data},
    {SSC_SML_DEACTIVATE_CODE, MMI_FALSE, mmi_sml_entry_permanent_unlock_selection},
#endif
#ifdef __MMI_SML_NP_ONLY__
    {SSC_SML_UNLOCK_NP_CMD, MMI_FALSE, mmi_bootup_sim_entry_check_np_screen},
    {SSC_SML_UNLOCK_NSP_CMD, MMI_FALSE, mmi_bootup_sim_entry_check_nsp_screen},
    {SSC_SML_UNLOCK_SP_CMD, MMI_FALSE, mmi_bootup_sim_entry_check_sp_screen},
    {SSC_SML_UNLOCK_CP_CMD, MMI_FALSE, mmi_bootup_sim_entry_check_cp_screen},
    {SSC_SML_UNLOCK_SIMP_CMD, MMI_FALSE, mmi_bootup_sim_entry_check_simp_screen},
    {SSC_SML_UNLOCK_NS_SP_CMD, MMI_FALSE, mmi_bootup_sim_entry_check_nssp_screen},
    {SSC_SML_UNLOCK_SIM_C_CMD, MMI_FALSE, mmi_bootup_sim_entry_check_simcp_screen},
#endif /* __MMI_SML_NP_ONLY__ */
#endif /* __MMI_SML_MENU__ */
#ifdef __MMI_A2DP_SUPPORT__
    {SSC_BT_A2DP_TOGGLE_PTS_MODE, MMI_FALSE, SSCHandle_BT_A2DP_Toggle_PTS_Mode},
#endif /* __MMI_A2DP_SUPPORT__ */ 
#ifdef __BTMTK__
    {BT_POWER_ON, MMI_FALSE, SSCHandle_BT_POWER_ON},
    {BT_POWER_OFF, MMI_FALSE, SSCHandle_BT_POWER_OFF},
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    {BT_PTS_SIMAP_GRACEFUL_DISC_TYPE_ON, MMI_FALSE, SSCHandle_BT_PTS_SIMAP_Graceful_Disc_Type},
    {BT_PTS_SIMAP_IMMEDIATE_DISC_TYPE_ON, MMI_FALSE, SSCHandle_BT_PTS_SIMAP_Immediate_Disc_Type},    
    {BT_PTS_SIMAP_UNAVAILABLE_SIM_SEND_STATUS_IND, MMI_FALSE, SSCHandle_BT_PTS_SIMAP_PRS},    
#endif /* __BTMTK__ */ 
#ifdef __MMI_BT_SUPPORT__
    /* for pts V2.1.0.4 */
    /* cannot update indicators to remote bluetooth headset while HFP is connected */
    /* indicators shall be retrieved by remote HF AT+CIND? */
    /* so for pts V2.1.0.4, host will not udpate indicators while HFP is just connected */
    {BT_PTS_ON, MMI_FALSE, mmi_bt_enable_pts_test},
    {BT_PTS_OFF, MMI_FALSE, mmi_bt_disable_pts_test},
#endif /* __MMI_BT_SUPPORT__ */ 
#ifdef __DRM_V02__
    {"*#6221#", MMI_FALSE, OSD_STime_Switch},
    {"*#6237#", MMI_FALSE, OSD_PKI_Format_Switch},
    {"*#6248#", MMI_FALSE, mmi_rmgr_switch_cermgr},
#endif
#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
    {"*#2008#", MMI_FALSE, em_gps_open_soc},
    {"*#2009#", MMI_FALSE, em_gps_close_soc},
    {"*#1040#", MMI_FALSE, em_gps_gps_reset_chip_off_104},
    {"*#1041#", MMI_FALSE, em_gps_gps_reset_chip_on_104},
    {"*#1042#", MMI_FALSE, em_gps_reset_data_104},
    {"*#1030#", MMI_FALSE, em_gps_gps_reset_chip_off_103},
    {"*#1031#", MMI_FALSE, em_gps_gps_reset_chip_on_103},
    {"*#1032#", MMI_FALSE, em_gps_reset_data_103},
    {"*#1022#", MMI_FALSE, em_gps_reset_data_102},
#endif
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif 
#ifdef __VENUS_UI_ENGINE__
    {"*#28146#", MMI_FALSE, SSCHandleVenusUITest},
#endif // __VENUS_UI_ENGINE__
#ifdef __FLAVOR_VENDOR_SDK__
    {SSC_AVKAPP, MMI_FALSE, SSCHandleAvkApp},
#endif
    {SSC_VENDORAPP, MMI_FALSE, SSCHandleVendorApp},
    {"*#63342835#", MMI_FALSE, ssc_show_logo_screen}
};

SIMSTRINGTBL sim_table[] = 
{
#ifdef __MMI_DUAL_SIM_MASTER__
    {"**04*", 5, mmi_ssc_request_pin1_status},
    {"**042*", 6, mmi_ssc_request_pin2_status},
    {"**05*", 5, mmi_ssc_entry_puk1},
    {"**052*", 6, mmi_ssc_entry_puk2}
#else
    {"**04*", 5, SendReqPIN1Status},
    {"**042*", 6, SendReqPIN2Status},
    {"**05*", 5, SSCEntryPUK1},
    {"**052*", 6, SSCEntryPUK2}
#endif
#ifdef __MMI_SML_MENU__
#ifdef __MMI_DUAL_SIM_MASTER__
    ,{SSC_SML_LOCK_CMD, 6, mmi_sml_entry_lock_req_sim_interface}
    ,{SSC_SML_UNLOCK_CMD, 6, mmi_sml_entry_unlock_req_sim_interface}
    ,{SSC_SML_QUERY_CMD, 7, mmi_sml_entry_query_req_sim_interface}
#else
    ,{SSC_SML_LOCK_CMD, 6, mmi_sml_send_lock_req_by_ssc}
    ,{SSC_SML_UNLOCK_CMD, 6, mmi_sml_send_unlock_req_by_ssc}
    ,{SSC_SML_QUERY_CMD, 7, mmi_sml_send_query_req_by_ssc}
#endif
#endif /* __MMI_SML_MENU__ */
};

extern U16 gCurrLangIndex;
extern sLanguageDetails *gLanguageArray;
extern U8 gPLMN[];
extern void RefreshNwProviderName(U8 *UpdatePlmn);

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
extern U8 gPLMN_2[];
extern void MTPNP_PFAL_RefreshNwProviderName(U8 *UpdatePlmn);
#endif

/* extern void SendSetLanguage(U8 code); */

#ifdef __MMI_ENGINEER_MODE__    /* MTK Add Robin 1001 for saperate MMI feature by project */
extern void EntryEngineerModeMenu(void);
#endif 

#ifdef __MMI_FACTORY_MODE__     /* MTK Add Robin 1001 for saperate MMI feature by project */
/* Lisen 0630 */
extern void EntryFMMenu(void);
extern void EntryFMMenuAutoTest(void);
extern void EntryFMVersionSummaryMenu(void);
extern void EntryFMLCDContrastMenuHdlr(void);
#endif /* __MMI_FACTORY_MODE__ */ 

#ifdef __BTMTK__
extern void BTDlightTest(void);
extern void BTDlightTest1(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  SSCAbnormalReset
 * DESCRIPTION
 *  Abnormal reset testing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCAbnormalReset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngAutoMode
 * DESCRIPTION
 *  Set Auto language selction
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngAutoMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is show the SSCHandleLngAutoMode");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_DEFAULT) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_DEFAULT_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_DEFAULT), MMI_EVENT_FAILURE);
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngEnglish
 * DESCRIPTION
 *  Set English language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngEnglish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set English language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ENGLISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }
            
            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ENGLISH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_ENGLISH), MMI_EVENT_FAILURE);
}

#if defined(__MMI_LANG_TR_CHINESE__)
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngChinese
 * DESCRIPTION
 *  Set Traditional Chinese language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngChinese(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Traditional Chinese language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_TCHINESE) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 

            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_TCHINESE_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_TCHINESE), MMI_EVENT_FAILURE);
}
#endif

#if defined(__MMI_LANG_SM_CHINESE__)
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngSimplify
 * DESCRIPTION
 *  Set Simplify Chinese language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngSimplify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Simplify Chinese language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SCHINESE) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SCHINESE_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_SCHINESE), MMI_EVENT_FAILURE);
}
#endif


#if defined(__MMI_LANG_SA_PORTUGUESE__)

/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngBzPortuguese
 * DESCRIPTION
 *  Set Brazilian portuguese language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngBzPortuguese(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Brazilian portuguese language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SA_PORTUGUESE) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SA_PORTUGUESE_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_SA_PORTUGUESE), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_SA_PORTUGUESE__) */

#if defined(__MMI_LANG_CA_FRENCH__)

    
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngCaFRench
 * DESCRIPTION
 *  Set Canadian French language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngCaFRench(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting CA_FRENCH language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_CA_FRENCH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_CA_FRENCH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_CA_FRENCH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_CA_FRENCH__) */


#if defined(__MMI_LANG_HK_CHINESE__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngCantoneseChinese
 * DESCRIPTION
 *  Set CNT_CHINESE language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngCantoneseChinese(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting CNT_CHINESE language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_HK_CHINESE) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
}

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_HK_CHINESE_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_HK_CHINESE), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_HK_CHINESE__) */


#if defined(__MMI_LANG_SA_SPANISH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngLatinAmSpanish
 * DESCRIPTION
 *  Set SA_SPANISH language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngLatinAmSpanish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting SA_SPANISH language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SA_SPANISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SA_SPANISH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_SA_SPANISH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_SA_SPANISH__) */


#if defined(__MMI_LANG_UK_ENGLISH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngUKEnglish
 * DESCRIPTION
 *  Set UK_ENGLISH language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngUKEnglish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting UK_ENGLISH language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_UK_ENGLISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_UK_ENGLISH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_UK_ENGLISH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_UK_ENGLISH__) */

#if defined(__MMI_LANG_ICELANDIC__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngIcelandic
 * DESCRIPTION
 *  Set ICELANDIC language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngIcelandic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting ICELANDIC language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ICELANDIC) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ICELANDIC_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_ICELANDIC), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_ICELANDIC__) */

#if defined(__MMI_LANG_SERBIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngSerbian
 * DESCRIPTION
 *  Set SERBIAN language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngSerbian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting SERBIAN language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SERBIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
#endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SERBIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_SERBIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_SERBIAN__) */



#if defined(__MMI_LANG_AZERBAIJANI__)

/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngAzerbaijani
 * DESCRIPTION
 *  Set Azerbaijani language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngAzerbaijani(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Azerbaijani language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_AZERBAIJANI) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_AZERBAIJANI_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_AZERBAIJANI), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_AZERBAZINI__) */

#if defined(__MMI_LANG_CATALAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngCatalan
 * DESCRIPTION
 *  Set Catalan language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngCatalan(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Catalan language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_CATALAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_CATALAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_CATALAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_CATALAN__) */


#if defined(__MMI_LANG_KAZAKH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngKazakh
 * DESCRIPTION
 *  Set Kazakh language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngKazakh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Kazakh language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_KAZAKH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_KAZAKH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_KAZAKH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_KAZAKH__) */


#if defined(__MMI_LANG_HAUSA__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngHausa
 * DESCRIPTION
 *  Set Hausa language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngHausa(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Hausa language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_HAUSA) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_HAUSA_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_HAUSA), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_HAUSA__) */
#if defined(__MMI_LANG_GALICIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngGalician
 * DESCRIPTION
 *  Set Galician language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngGalician(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Galician language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_GALICIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_GALICIAN_STR_ID),
                MMI_EVENT_SUCCESS);
            return;
        }
    }
    mmi_display_popup(get_string(SSC_STR_ERR_SET_GALICIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_GALICIAN__) */
#if defined(__MMI_LANG_BASQUE__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngBasque
 * DESCRIPTION
 *  Set Basque language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngBasque(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Basque language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_BASQUE) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
}

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_BASQUE_STR_ID),
                MMI_EVENT_SUCCESS);
            return;
        }
    }
    mmi_display_popup(get_string(SSC_STR_ERR_SET_BASQUE), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_BASQUE__) */
#if defined(__MMI_LANG_IGBO__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngIgbo
 * DESCRIPTION
 *  Set Igbo language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngIgbo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Igbo language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_IGBO) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_IGBO_STR_ID),
                MMI_EVENT_SUCCESS);
            return;
        }
    }
    mmi_display_popup(get_string(SSC_STR_ERR_SET_IGBO), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_IGBO__) */
#if defined(__MMI_LANG_FILIPINO__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngFilipino
 * DESCRIPTION
 *  Set Filipino language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngFilipino(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Filipino language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_FILIPINO) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_FILIPINO_STR_ID),
                MMI_EVENT_SUCCESS);
            return;
        }
    }
    mmi_display_popup(get_string(SSC_STR_ERR_SET_FILIPINO), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_FILIPINO__) */
#if defined(__MMI_LANG_IRISH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngIrish
 * DESCRIPTION
 *  Set Irish language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngIrish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Irish language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_IRISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_IRISH_STR_ID),
                MMI_EVENT_SUCCESS);
            return;
        }
    }
    mmi_display_popup(get_string(SSC_STR_ERR_SET_IRISH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_IRISH__) */


#if defined(__MMI_LANG_MACEDONIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngMacedonian
 * DESCRIPTION
 *  Set Macedonian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngMacedonian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Macedonian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_MACEDONIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_MACEDONIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_MACEDONIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_MACEDONIAN__) */

#if defined(__MMI_LANG_SESOTHO__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngSesotho
 * DESCRIPTION
 *  Set Sesotho language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngSesotho(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Sesotho language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SESOTHO) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SESOTHO_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_SESOTHO), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_SESOTHO__) */

#if defined(__MMI_LANG_TAGALOG__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngTagalog
 * DESCRIPTION
 *  Set tagalog language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngTagalog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Tagalog language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_TAGALOG) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }
    
            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_TAGALOG_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
}
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_TAGALOG), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_TAGALOG__) */

#if defined(__MMI_LANG_YORUBA__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngYoruba
 * DESCRIPTION
 *  Set Yoruba language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngYoruba(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is setting Yoruba language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_YORUBA) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
#endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_YORUBA_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_YORUBA), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_YORUBA__) */

/* MTK Terry for Spanish French German Italian Thai Russian Portuguese Turkish Vietnamese Indonesian Malay */
#if defined(__MMI_LANG_SPANISH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngSpanish
 * DESCRIPTION
 *  Set Spanish language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngSpanish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Spanish language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SPANISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SPANISH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_SPANISH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_SPANISH__) */ 
/* PMT VIKASG START 20050729 */
#if defined(__MMI_LANG_DANISH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngDanish
 * DESCRIPTION
 *  Set Danish language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngDanish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Danish language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_DANISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_DANISH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_DANISH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_DANISH__) */ 
//PMT VIKASG END 20050729
//PMT CZ_PO_TU START 20050812
#if defined(__MMI_LANG_POLISH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngPolish
 * DESCRIPTION
 *  Set Polish language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngPolish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Polish language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_POLISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_POLISH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_POLISH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_POLISH__) */ 
/* PMT CZ_PO_TU END 20050812 */
#if defined(__MMI_LANG_FRENCH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngFrench
 * DESCRIPTION
 *  Set French language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngFrench(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set French language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_FRENCH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_FRENCH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_FRENCH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_FRENCH__) */ 
#if defined(__MMI_LANG_GERMAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngGerman
 * DESCRIPTION
 *  Set German language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngGerman(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set German language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_GERMAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_GERMAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_GERMAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_GERMAN__) */ 
#if defined(__MMI_LANG_ITALIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngItalian
 * DESCRIPTION
 *  Set Italian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngItalian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Italian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ITALIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ITALIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_ITALIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_ITALIAN__) */ 
#if defined(__MMI_LANG_THAI__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngThai
 * DESCRIPTION
 *  Set Thai language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngThai(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Thai language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_THAI) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_THAI_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_THAI), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_THAI__) */ 
#if defined(__MMI_LANG_RUSSIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngRussian
 * DESCRIPTION
 *  Set Russian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngRussian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Russian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_RUSSIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_RUSSIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_RUSSIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_RUSSIAN__) */ 
/* PMT BULGARIAN START 20051201 */
#if defined(__MMI_LANG_BULGARIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngBulgarian
 * DESCRIPTION
 *  Set Bulgarian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngBulgarian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Bulgarian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_BULGARIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_BULGARIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_BULGARIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_BULGARIAN__) */ 
#if defined(__MMI_LANG_UKRAINIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngUkrainian
 * DESCRIPTION
 *  Set Ukrainian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngUkrainian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Ukrainian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_UKRAINIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_UKRAINIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_UKRAINIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_UKRAINIAN__) */ 

#if defined(__MMI_LANG_PORTUGUESE__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngPortuguese
 * DESCRIPTION
 *  Set Portuguese language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngPortuguese(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Portuguese language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_PORTUGUESE) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_PORTUGUESE_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_PORTUGUESE), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_PORTUGUESE__) */ 
#if defined(__MMI_LANG_TURKISH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngTurkish
 * DESCRIPTION
 *  Set Turkish language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngTurkish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Turkish language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_TURKISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_TURKISH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_TURKISH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_TURKISH__) */ 
#if defined(__MMI_LANG_VIETNAMESE__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngVietnamese
 * DESCRIPTION
 *  Set Vietnamese language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngVietnamese(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Vietnamese language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_VIETNAMESE) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_VIETNAMESE_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_VIETNAMESE), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
#if defined(__MMI_LANG_INDONESIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngIndonesian
 * DESCRIPTION
 *  Set Indonesian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngIndonesian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Indonesian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_INDONESIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_INDONESIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_INDONESIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_INDONESIAN__) */ 
/* PMT CZ_PO_TU START 20050812 */
#if defined(__MMI_LANG_CZECH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngCzech
 * DESCRIPTION
 *  Set Czech language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngCzech(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Czech language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_CZECH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_CZECH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_CZECH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_CZECH__) */ 
/* PMT CZ_PO_TU END 20050812 */

#if defined(__MMI_LANG_MALAY__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngMalay
 * DESCRIPTION
 *  Set Malay language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngMalay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Malay language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_MALAY) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_MALAY_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_MALAY), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_MALAY__) */ 
/* PMT START HU_FI 20050825 */
#if defined(__MMI_LANG_FINNISH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngFinnish
 * DESCRIPTION
 *  Set Finnish language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngFinnish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to set Finnish language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_FINNISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_FINNISH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_FINNISH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_FINNISH__) */ 
#if defined(__MMI_LANG_HUNGARIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngHungarian
 * DESCRIPTION
 *  Set Hungarian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngHungarian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Hungarian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_HUNGARIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_HUNGARIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_HUNGARIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_HUNGARIAN__) */ 
//PMT END HU_FI 20050825
//PMT NO_AR_SL_DU START 20050909
#if defined(__MMI_LANG_SLOVAK__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngSlovak
 * DESCRIPTION
 *  Set SLOVAK language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngSlovak(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to set SLOVAK language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SLOVAK) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SLOVAK_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_SLOVAK), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_SLOVAK__) */ 
#if defined(__MMI_LANG_DUTCH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngDutch
 * DESCRIPTION
 *  Set Dutch language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngDutch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Dutch language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_DUTCH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_DUTCH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_DUTCH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_DUTCH__) */ 
/* Norwegian start */
#if defined(__MMI_LANG_NORWEGIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngNorwegian
 * DESCRIPTION
 *  Set Norwegian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngNorwegian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Norwegian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_NORWEGIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_NORWEGIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_NORWEGIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_NORWEGIAN__) */ 
//Norwegian end
//PMT NO_AR_SL_DU END 20050909
//PMT START SWEDISH 20050916
#if defined(__MMI_LANG_SWEDISH__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngSwedish
 * DESCRIPTION
 *  Set SWEDISH language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngSwedish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to set SWEDISH language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SWEDISH) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }
            
            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SWEDISH_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_SWEDISH), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_SWEDISH__) */ 
//PMT END SWEDISH 20050916
//PMT START CR_ROM_SLO 20050923
#if defined(__MMI_LANG_CROATIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngCroatian
 * DESCRIPTION
 *  Set CROATIAN language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngCroatian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to set CROATIAN language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_CROATIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_CROATIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_CROATIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_CROATIAN__) */ 
#if defined(__MMI_LANG_ROMANIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngRomanian
 * DESCRIPTION
 *  Set Romanian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngRomanian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Romanian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ROMANIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ROMANIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_ROMANIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_ROMANIAN__) */ 
#if defined(__MMI_LANG_SLOVENIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngSlovenian
 * DESCRIPTION
 *  Set SLOVENIAN language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngSlovenian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to set SLOVENIAN language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SLOVENIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SLOVENIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_SLOVENIAN), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_SLOVENIAN__) */ 
//PMT END CR_ROM_SLO 20050923
//PMT START GR_HE_CZ_FI_DA_HU 20051007
#if defined(__MMI_LANG_GREEK__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngGreek
 * DESCRIPTION
 *  Set GREEK language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngGreek(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to set GREEK language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_GREEK) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_GREEK_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_GREEK), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_GREEK__) */ 
/* PMT END GR_HE_CZ_FI_DA_HU 20051007 */
/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngArabic
 * DESCRIPTION
 *  Set Thai language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* PMT START 20060714 */
#if defined (__MMI_LANG_ARABIC__)
/* PMT END 20060714 */
void SSCHandleLngArabic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Arabic language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ARABIC) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ARABIC_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_ARABIC), MMI_EVENT_FAILURE);
}

/* PMT START 20060714 */
#endif /* defined (__MMI_LANG_ARABIC__) */ 
/* PMT START PERSIAN */
#if defined (__MMI_LANG_PERSIAN__)
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngPersian
 * DESCRIPTION
 *  Set Persian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngPersian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Persian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_PERSIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_PERSIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_PERSIAN), MMI_EVENT_FAILURE);
}
#endif /* defined (__MMI_LANG_PERSIAN__) */ 
/* PMT END PERSIAN */


#if defined (__MMI_LANG_HEBREW__)
/* PMT END 20060714 */
/**************************************************************
//PMT START GR_HE_CZ_FI_DA_HU 20051007
   FUNCTION NAME     : SSCHandleLngHebrew

   PURPOSE           : Set Hebrew language 

   INPUT PARAMETERS  : nil

   OUTPUT PARAMETERS : nil

   RETURNS           : void

   REMARKS           : 

**************************************************************/


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngHebrew
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngHebrew(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Hebrew language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_HEBREW) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_HEBREW_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_HEBREW), MMI_EVENT_FAILURE);
}

/* PMT START 20060714 */
#endif /* defined (__MMI_LANG_HEBREW__) */ 
//PMT START URDU 
#if defined (__MMI_LANG_URDU__)
/**************************************************************
   FUNCTION NAME		: SSCHandleLngUrdu
   PURPOSE				: Set Urdu language 
   INPUT PARAMETERS  : nil
   OUTPUT PARAMETERS : nil
   RETURNS           : void
   REMARKS           : 
**************************************************************/
void SSCHandleLngUrdu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;
   PRINT_INFORMATION("This is set Urdulanguage");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
	   if(strcmp((PS8)gLanguageArray[count].aLangSSC,SSC_URDU)==0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                       	case SUBLCD_NOT_ON_IDLE: // Lisen 0617: could switch to other screen, like receiving an SMS
                        break;
                    default:
                        ASSERT(0);
                }
#endif
            }
            
            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_URDU_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_URDU), MMI_EVENT_FAILURE);
}
#endif
//PMT END URDU
#if defined (__MMI_LANG_HINDI__)
/* PMT END 20060714 */
/**************************************************************
//PMT END GR_HE_CZ_FI_DA_HU 20051007

   FUNCTION NAME     : SSCHandleLngHindi

   PURPOSE           : Set Thai language 

   INPUT PARAMETERS  : nil

   OUTPUT PARAMETERS : nil

   RETURNS           : void

   REMARKS           : 

**************************************************************/


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngHindi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngHindi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Hindi language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_HINDI) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_HINDI_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_HINDI), MMI_EVENT_FAILURE);
}

/* PMT START 20060714 */
#endif /* defined (__MMI_LANG_HINDI__) */ 
/* PMT END 20060714 */
/* PMT RAKESH START 20061006 */
#if defined(__MMI_LANG_MARATHI__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngMarathi
 * DESCRIPTION
 *  Set Marathi language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngMarathi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Marathi language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_MARATHI) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_MARATHI_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_MARATHI), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_MARATHI__) */ 
/* PMT RAKESH END 20061006 */
/*PMT IRE START*/
#if defined(__MMI_LANG_TAMIL__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngTamil
 * DESCRIPTION
 *  Set Tamil language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngTamil(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Tamil language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_TAMIL) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_TAMIL_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_TAMIL), MMI_EVENT_FAILURE);
}

#endif /* defined(__MMI_LANG_TAMIL__) */ 
#if defined (__MMI_LANG_BENGALI__)
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngHindi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngBengali(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Bengali language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_BENGALI) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_BENGALI_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_BENGALI), MMI_EVENT_FAILURE);
}

#endif /* defined (__MMI_LANG_BENGALI__) */ 
#if defined (__MMI_LANG_ASSAMESE__)
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngAssamese
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngAssamese(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Assamese language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ASSAMESE) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ASSAMESE_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_ASSAMESE), MMI_EVENT_FAILURE);
}

#endif /* defined (__MMI_LANG_ASSAMESE__) */ 
#if defined(__MMI_LANG_PUNJABI__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngPunjabi
 * DESCRIPTION
 *  Set Punjabi language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngPunjabi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Punjabi language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_PUNJABI) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_PUNJABI_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_PUNJABI), MMI_EVENT_FAILURE);
}

#endif
#if defined(__MMI_LANG_TELUGU__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngTelugu
 * DESCRIPTION
 *  Set Telugu language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngTelugu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Telugu language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_TELUGU) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    /* Lisen 0617: could switch to other screen, like receiving an SMS */
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_TELUGU_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_TELUGU), MMI_EVENT_FAILURE);
}

#endif
#if defined(__MMI_LANG_KANNADA__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngKannada
 * DESCRIPTION
 *  Set Kannada language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngKannada(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Kannada language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_KANNADA) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_KANNADA_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_KANNADA), MMI_EVENT_FAILURE);
}

#endif /* __MMI_LANG_KANNADA__ */
#if defined(__MMI_LANG_MALAYALAM__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngMalayalam
 * DESCRIPTION
 *  Set Malayalam language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngMalayalam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Malayalam language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_MALAYALAM) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_MALAYALAM_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_MALAYALAM), MMI_EVENT_FAILURE);
}

#endif /* __MMI_LANG_MALAYALAM__ */
#if defined(__MMI_LANG_GUJARATI__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngGujarati
 * DESCRIPTION
 *  Set Gujarati language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngGujarati(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Gujarati language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_GUJARATI) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_GUJARATI_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_GUJARATI), MMI_EVENT_FAILURE);
}

#endif /* __MMI_LANG_GUJARATI__ */
#if defined(__MMI_LANG_ORIYA__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngORIYA
 * DESCRIPTION
 *  Set ORIYA language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngOriya(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set ORIYA language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ORIYA) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:    
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ORIYA_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_ORIYA), MMI_EVENT_FAILURE);
}

#endif /* __MMI_LANG_ORIYA__ */

#if defined(__MMI_LANG_XHOSA__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngXhosa
 * DESCRIPTION
 *  Set Xhosa language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngXhosa(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Xhosa language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_XHOSA) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_XHOSA_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_XHOSA), MMI_EVENT_FAILURE);
}
#endif /* defined(__MMI_LANG_XHOSA__) */ 


#if defined (__MMI_LANG_SWAHILI__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngSwahili
 * DESCRIPTION
 *  Set Swahili language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngSwahili(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Swahili language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_SWAHILI) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
        #endif

        #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
        #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_SWAHILI_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_SWAHILI), MMI_EVENT_FAILURE);
}

#endif /* defined (__MMI_LANG_SWAHILI__) */


#if defined (__MMI_LANG_AFRIKAANS__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngAfrikaans
 * DESCRIPTION
 *  Set Afrikaans language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngAfrikaans(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Afrikaans language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_AFRIKAANS) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_AFRIKAANS_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_AFRIKAANS), MMI_EVENT_FAILURE);
}

#endif  /* defined (__MMI_LANG_AFRIKAANS__) */


#if defined (__MMI_LANG_ZULU__)

/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngZulu
 * DESCRIPTION
 *  Set Zulu language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngZulu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Zulu language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ZULU) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ZULU_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_ZULU), MMI_EVENT_FAILURE);
}

#endif  /* defined (__MMI_LANG_ZULU__) */

#if defined (__MMI_LANG_LITHUANIAN__)
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngLithuanian
 * DESCRIPTION
 *  Set Lithuanian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngLithuanian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Lithuanian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_LITHUANIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif

            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_LITHUANIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_LITHUANIAN), MMI_EVENT_FAILURE);
}

#endif /* defined (__MMI_LANG_LITHUANIAN__) */

#if defined (__MMI_LANG_LATVIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngLatvian
 * DESCRIPTION
 *  Set Latvian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngLatvian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Latvian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_LATVIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif
    
            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_LATVIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }

    mmi_display_popup(get_string(SSC_STR_ERR_SET_LATVIAN), MMI_EVENT_FAILURE);
}


#endif /* defined (__MMI_LANG_LATVIAN__) */

#if defined (__MMI_LANG_ESTONIAN__)
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngEstonian
 * DESCRIPTION
 *  Set Estonian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngEstonian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Estonian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ESTONIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif
        
            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ESTONIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_ESTONIAN), MMI_EVENT_FAILURE);
}

#endif /* defined (__MMI_LANG_ESTONIAN__) */


#if defined (__MMI_LANG_ARMENIAN__)
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngArmenian
 * DESCRIPTION
 *  Set Armenian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngArmenian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Armenian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ARMENIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif
            
            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ARMENIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_ARMENIAN), MMI_EVENT_FAILURE);
}

#endif /* defined (__MMI_LANG_ARMENIAN__) */


#if defined (__MMI_LANG_ALBANIAN__)
/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngAlbanian
 * DESCRIPTION
 *  Set Albanian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngAlbanian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Albanian language set");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_ALBANIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif
            
            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_ALBANIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_ALBANIAN), MMI_EVENT_FAILURE);
}

#endif /* defined (__MMI_LANG_ALBANIAN__) */



#if defined (__MMI_LANG_GEORGIAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngGeorgian
 * DESCRIPTION
 *  Set Georgian language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngGeorgian(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Georgian language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_GEORGIAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif
                
            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_GEORGIAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_GEORGIAN), MMI_EVENT_FAILURE);
}

#endif /* defined (__MMI_LANG_GEORGIAN__) */


#if defined (__MMI_LANG_MOLDOVAN__)


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLngMoldovan
 * DESCRIPTION
 *  Set Moldovan language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLngMoldovan(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is set Moldovan language");
    DisplayIdleScreen();
    for (count = 0; count < MAX_LANGUAGES; count++)
    {
        if (strcmp((PS8) gLanguageArray[count].aLangSSC, SSC_MOLDOVAN) == 0)
        {
            if (gCurrLangIndex != count)
            {
                SetCurrentLanguage(count);
                WriteValue(NVRAM_SETTING_LANG, &count, DS_BYTE, &error);
                PhnsetSetCharsetByLang();
                RefreshNwProviderName(gPLMN);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                MTPNP_PFAL_RefreshNwProviderName(gPLMN_2);
            #endif
                
            #ifdef __MMI_SUBLCD__
                switch (g_idle_context.IsSubLcdOnIdleScreen)
                {
                    case SUBLCD_ON_IDLE_NORMAL:
                        ShowIdleAppSubLcd();
                        break;
                    case SUBLCD_ON_IDLE_INSERT_SIM:
                        ShowSubLCDSimError();
                        break;
                    case SUBLCD_ON_IDLE_SIM_BLOCKED:
                        ShowSubLCDBlockedSIM();
                        break;
                    case SUBLCD_NOT_ON_IDLE:
                        break;
                    default:
                        ASSERT(0);
                }
            #endif /* __MMI_SUBLCD__ */ 
            }

            mmi_display_popup(
                get_string(SSC_SCR_LANGUAGE_MOLDOVAN_STR_ID),
                MMI_EVENT_SUCCESS);

            return;
        }
    }
    
    mmi_display_popup(get_string(SSC_STR_ERR_SET_MOLDOVAN), MMI_EVENT_FAILURE);
}

#endif /* defined (__MMI_LANG_MOLDOVAN__) */


/*****************************************************************************
 * FUNCTION
 *  SSCHandleSoftwareVersion
 * DESCRIPTION
 *  Display sofeware version.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleSoftwareVersion(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 strSWVersionNo[(MAX_SW_VER_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(strSWVersionNo, 0, sizeof(strSWVersionNo));
#ifdef __ASCII
    strcpy(strSWVersionNo, (S8*) release_verno());
#endif 

#ifdef __UCS2_ENCODING
    mmi_asc_n_to_ucs2(strSWVersionNo, (S8*) release_verno(), MAX_SW_VER_LEN);
#endif 

    PRINT_INFORMATION("This is to show software version");

    EntryNewScreen(SCR_ENTER_SW_VERSION, NULL, SSCHandleSoftwareVersion, NULL);

    ShowCategory152Screen(SSC_SCR_SW_VERSION_CAPTION_ID, 0, STR_GLOBAL_OK, 0, 0, 0, (PU8) strSWVersionNo, NULL);

    SetLeftSoftkeyFunction(DisplayIdleScreen, KEY_EVENT_UP);
}

/* Lisen 0921 */


/*****************************************************************************
 * FUNCTION
 *  SSCHandleSoftwareVersionSummary
 * DESCRIPTION
 *  Display sofeware version.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleSoftwareVersionSummary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to show Version Summary Info");
    
#ifdef __MMI_FACTORY_MODE__ 
    EntryFMVersionSummaryMenu();
#else /* __MMI_FACTORY_MODE__ */ 
    DisplayIdleScreen();

    mmi_display_popup(
        get_string(SSC_SCR_FACTORY_MODE_STR_ID),
        MMI_EVENT_FAILURE);
#endif /* __MMI_FACTORY_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleLCDContrastSetting
 * DESCRIPTION
 *  Display LCD Contrast Setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleLCDContrastSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to show Version Summary Info");

#ifdef __MMI_FACTORY_MODE__ 
    EntryFMLCDContrastMenuHdlr();
#else /* __MMI_FACTORY_MODE__ */ 
    DisplayIdleScreen();

    mmi_display_popup(
        get_string(SSC_SCR_FACTORY_MODE_STR_ID),
        MMI_EVENT_FAILURE);
#endif /* __MMI_FACTORY_MODE__ */ 
}

#ifdef __MMI_HW_VERSION__


/*****************************************************************************
 * FUNCTION
 *  SSCHandleHardwareVersion
 * DESCRIPTION
 *  Execute the sofeware version dispaly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleHardwareVersion(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 strHWVersionNo[(MAX_SW_VER_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(strHWVersionNo, 0, sizeof(strHWVersionNo));
#ifdef __ASCII
    strcpy(strHWVersionNo, (S8*) release_hw_ver());
#endif 

#ifdef __UCS2_ENCODING
    mmi_asc_n_to_ucs2(strHWVersionNo, (S8*) release_hw_ver(), MAX_SW_VER_LEN);
#endif 

    PRINT_INFORMATION("This is to show hardware version");

    EntryNewScreen(SCR_ENTER_HW_VERSION, NULL, SSCHandleHardwareVersion, NULL);

    ShowCategory7Screen(SSC_SCR_HW_VERSION_CAPTION_ID, 0, STR_GLOBAL_OK, 0, 0, 0, (PU8) strHWVersionNo, NULL);

    SetLeftSoftkeyFunction(DisplayIdleScreen, KEY_EVENT_UP);
}

#endif /* __MMI_HW_VERSION__ */ 


/*****************************************************************************
 * FUNCTION
 *  SSCHandleEngineerMode
 * DESCRIPTION
 *  Set Engineering Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleEngineerMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to handle Engineering Mode");
    
#ifdef __MMI_ENGINEER_MODE__ 
    EntryEngineerModeMenu();
#else /* __MMI_ENGINEER_MODE__ */ 
    DisplayIdleScreen();

    mmi_display_popup(
        get_string(SSC_SCR_ENGINEER_MODE_STR_ID),
        MMI_EVENT_FAILURE);
#endif /* __MMI_ENGINEER_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleFactoryMode
 * DESCRIPTION
 *  Set Factory Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleFactoryMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("this is to handle Factory Mode");

#ifdef __MMI_FACTORY_MODE__ 
    EntryFMMenu();
#else /* __MMI_FACTORY_MODE__ */ 
    DisplayIdleScreen();

    mmi_display_popup(
        get_string(SSC_SCR_FACTORY_MODE_STR_ID),
        MMI_EVENT_FAILURE);
#endif /* __MMI_FACTORY_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleFactoryModeAutoTest
 * DESCRIPTION
 *  Set Factory Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleFactoryModeAutoTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("this is to handle Factory Mode Auto Test");

#ifdef __MMI_FACTORY_MODE__ 
    EntryFMMenuAutoTest();
#else /* __MMI_FACTORY_MODE__ */ 
    DisplayIdleScreen();

    mmi_display_popup(
        get_string(SSC_SCR_FACTORY_MODE_STR_ID),
        MMI_EVENT_FAILURE);
#endif /* __MMI_FACTORY_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleIMEI
 * DESCRIPTION
 *  Send req to get the IMEI number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleIMEI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is show the IMEI");

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */

    Message.oslMsgId = MSG_ID_MMI_NW_GET_IMEI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    OslMsgSendExtQueue(&Message);
    SetProtocolEventHandler(mmi_ssc_get_imei_rsp, MSG_ID_MMI_NW_GET_IMEI_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleSerialNumber
 * DESCRIPTION
 *  Display IMEI number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleSerialNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 strSerial_Num[(MAX_SW_VER_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("This is to show Serial number");

    memset(strSerial_Num, 0, (MAX_SW_VER_LEN + 1) * ENCODING_LENGTH);

#ifdef __ASCII
    memcpy(strSerial_Num, (S8*) Serial_num(), MAX_SW_VER_LEN);
#endif 

#ifdef __UCS2_ENCODING
    mmi_asc_n_to_ucs2(strSerial_Num, (S8*) Serial_num(), MAX_SW_VER_LEN);
#endif 

    EntryNewScreen(SCR_ENTER_SERIAL_NUMBER, NULL, SSCHandleSerialNumber, NULL);

    ShowCategory152Screen(SSC_SCR_SERIAL_NUMBER_CAPTION_ID, 0, STR_GLOBAL_OK, 0, 0, 0, (U8*) strSerial_Num, NULL);
    SetLeftSoftkeyFunction(DisplayIdleScreen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SendReqPIN1Status
 * DESCRIPTION
 *  Send request to L4 to know the status of PIN1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendReqPIN1Status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_valid())
    {
        return; /* avoid dual mode phone with SIM but enter SSC from idle */
    }

    if (IsScreenPresent(SCR_ID_SECSET_PUK1))
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC),
            MMI_EVENT_FAILURE);
    }
    else
    {
        if (mmi_bootup_is_searching_or_idle_reached()) /* if not from PUK Screen of Bootup */
        {
            MYQUEUE msgStruct;

            ret = mmi_ssc_check_diff_password("**04*");
            if (ret == 1)
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                mmi_display_popup(
                    get_string(STRING_MTPNP_CARD1_PIN_DONOT_MATCH),
                    MMI_EVENT_FAILURE);
            #else /* __MMI_DUAL_SIM_MASTER__ */
                mmi_display_popup(
                    get_string(STR_DIFF_PIN),
                    MMI_EVENT_FAILURE);
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            
                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == 2)
            {
                /* if the password is invalid display error popup */
                mmi_display_popup(
                    get_string(STR_INVALID_PINPUKPLOCK_LENGTH),
                    MMI_EVENT_FAILURE);
                
                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT),
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }

            /* send message and wait response in the same screen and no input can be accepted */
            ClearInputEventHandler(MMI_DEVICE_ALL);
            SetProtocolEventHandler(SSCChangePIN1, PRT_MMI_SMU_CHECK_PIN_STATUS_RSP);
            msgStruct.oslSrcId = MOD_MMI;
            msgStruct.oslDestId = MOD_L4C;
            msgStruct.oslMsgId = PRT_MMI_SMU_CHECK_PIN_STATUS_REQ;
            msgStruct.oslSapId = INVALID_SAP;
            msgStruct.oslDataPtr = NULL;
            msgStruct.oslPeerBuffPtr = NULL;
            OslMsgSendExtQueue(&msgStruct);
        }
        else
        {
            mmi_display_popup(
                get_string(STR_INCORRECT_SSC),
                MMI_EVENT_FAILURE);
            
            mmi_ssc_delete_sim_operation_screens();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_check_diff_password
 * DESCRIPTION
 *  check if the new and confirm pin is different
 * PARAMETERS
 *  PS8 ssc_head (ssc head string from the dial number screen)
 * RETURNS
 *  U8 (0: same, 1: different, 2: len invalid, -1:others)
 *****************************************************************************/
U8 mmi_ssc_check_diff_password(PS8 ssc_head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ansii_ssc_string[MAX_DIAL_PAD];
    U8 *ptr1, *ptr2 = NULL, *ptr3 = NULL;
    U8 i, count = 0, len;
    U8 pin_puk_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) ansii_ssc_string, g_idle_context.DialPadCallBuffer);
    pin_puk_len = (strcmp(ssc_head, "**04*") == 0 || strcmp(ssc_head, "**042*") == 0) ? MIN_PASSWORD_LENGTH : MAX_SIM_SETTING_PASSWD_LEN;

    if ((ssc_head != NULL) && (memcmp(ansii_ssc_string, ssc_head, strlen(ssc_head)) == 0))
    {
        ptr1 = ansii_ssc_string + strlen(ssc_head);
        len = strlen((S8*) ptr1);

        for (i = 0; i < len; i++)
        {
            if (*(ptr1 + i) == '*')
            {
                count++;
                *(ptr1 + i) = 0;
                if (count == 1)
                {
                    ptr2 = ptr1 + i + 1;
                }
                if (count == 2)
                {
                    ptr3 = ptr1 + i + 1;
                }
            }
            else if ((*(ptr1 + i) == '#') && (count == 2))
            {
                //*(ptr1 + i) = 0;
                break;
            }
        }

        if (*(ptr1 + i + 1) != 0)
        {
            return (U8) -1;
        }
        else
        {
            *(ptr1 + i) = 0;
        }

        if (count < 2 || count > 2)
        {
            return (U8) -1;
        }
        else
        {
            if (strlen((S8*)ptr1) > MAX_SIM_SETTING_PASSWD_LEN || strlen((S8*)ptr1) < pin_puk_len ||
                strlen((S8*)ptr2) > MAX_SIM_SETTING_PASSWD_LEN || strlen((S8*)ptr2) < MIN_PASSWORD_LENGTH ||
                strlen((S8*)ptr3) > MAX_SIM_SETTING_PASSWD_LEN || strlen((S8*)ptr3) < MIN_PASSWORD_LENGTH)
            {
                return 2;
            }

            if (strcmp((PS8)ptr2, (PS8)ptr3) == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    else
    {
        return (U8) -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SSCChangePIN1
 * DESCRIPTION
 *  Veirfy PIN1, if Ok then Change PIN1
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SSCChangePIN1(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_check_pin_status_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_check_pin_status_rsp_struct*) (info);
    FillCountDownNumber(resp->chv_info);

    if (resp->chv_status.chv1_status == CHV_RETRY_ALLOW || resp->chv_status.chv1_status == CHV_VERIFIED)
    {
        SetProtocolEventHandler(SECSETChangePasswordPIN1Rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
        mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C);
        return;
    }
    else if (resp->chv_status.chv1_status == CHV_DISABLED)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        mmi_display_popup(
            get_string(STRING_MTPNP_ENABLE_CARD1_PIN),
            MMI_EVENT_FAILURE);
    #else /* __MMI_DUAL_SIM_MASTER__ */
        mmi_display_popup(
            get_string(STR_ENABLE_PIN),
            MMI_EVENT_FAILURE);
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
    }
    else if (resp->chv_status.chv1_status == CHV_DEAD || resp->chv_status.chv1_status == CHV_INVALID_TYPE || resp->chv_status.chv1_status == CHV_BLOCKED || resp->chv_status.chv1_status == CHV_NOTINITED)      /* CHV_DEAD...display err scr-vanita */
    {
        mmi_display_popup(
            get_string(STR_ID_PIN_NOT_SUPPORT),
            MMI_EVENT_FAILURE);
    }
    mmi_ssc_delete_sim_operation_screens(); //DeleteUptoScrID(IDLE_SCREEN_ID);
}


/*****************************************************************************
 * FUNCTION
 *  SendReqPIN2Status
 * DESCRIPTION
 *  Send req to L4 to know the status of PIN2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendReqPIN2Status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_valid())
    {
        return; /* avoid dual mode phone with SIM but enter SSC from idle */
    }

    if (IsScreenPresent(SCR_ID_SECSET_PUK1))
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC),
            MMI_EVENT_FAILURE);
    }
    else
    {
        if (mmi_bootup_is_searching_or_idle_reached()) /* If not from PUK screen of Bootup */
        {
            MYQUEUE msgStruct;

            ret = mmi_ssc_check_diff_password("**042*");
            if (ret == 1)
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                mmi_display_popup(
                    get_string(STRING_MTPNP_CARD1_PIN2_DONOT_MATCH),
                    MMI_EVENT_FAILURE);
            #else /* __MMI_DUAL_SIM_MASTER__ */
                mmi_display_popup(
                    get_string(STR_DIFF_PIN2),
                    MMI_EVENT_FAILURE);
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            
                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == 2)
            {
                /* if the password is invalid display error popup */
                mmi_display_popup(
                    get_string(STR_INVALID_PINPUKPLOCK_LENGTH),
                    MMI_EVENT_FAILURE);
                
                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT),
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            
            /* send message and wait response in the same screen and no input can be accepted */
            ClearInputEventHandler(MMI_DEVICE_ALL);
            SetProtocolEventHandler(SSCChangePIN2, PRT_MMI_SMU_CHECK_PIN_STATUS_RSP);
            msgStruct.oslSrcId = MOD_MMI;
            msgStruct.oslDestId = MOD_L4C;
            msgStruct.oslMsgId = PRT_MMI_SMU_CHECK_PIN_STATUS_REQ;
            msgStruct.oslSapId = INVALID_SAP;
            msgStruct.oslDataPtr = NULL;
            msgStruct.oslPeerBuffPtr = NULL;
            OslMsgSendExtQueue(&msgStruct);

        }
        else    /* if from PUK screen then its a invalid SSC */
        {
            mmi_display_popup(
                get_string(STR_INCORRECT_SSC),
                MMI_EVENT_FAILURE);

            mmi_ssc_delete_sim_operation_screens();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SSCChangePIN2
 * DESCRIPTION
 *  verify PIN2, if Ok then change PIN2
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SSCChangePIN2(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_check_pin_status_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_check_pin_status_rsp_struct*) (info);
    FillCountDownNumber(resp->chv_info);

    if (resp->chv_status.chv2_status == CHV_RETRY_ALLOW || resp->chv_status.chv2_status == CHV_VERIFIED)
    {
        SetProtocolEventHandler(SECSETChangePasswordPIN2Rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);  /* MSG_ID_MMI_SMU_CHANGE_PASSWORD_RSP */
        mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C);
        return;
    }
    else if (resp->chv_status.chv2_status == CHV_BLOCKED)
    {
        mmi_display_popup(
            get_string(STR_SETTING_PIN2_BLOCK_TITLE),
            MMI_EVENT_FAILURE);
    }
    else if (resp->chv_status.chv2_status == CHV_DEAD || resp->chv_status.chv2_status == CHV_INVALID_TYPE || resp->chv_status.chv2_status == CHV_DISABLED || resp->chv_status.chv2_status == CHV_NOTINITED) /* CHV_DEAD...display err scr-vanita */
    {
        mmi_display_popup(
            get_string(STR_ID_PIN2_NOT_SUPPORT),
            MMI_EVENT_FAILURE);
    }
    mmi_ssc_delete_sim_operation_screens(); //DeleteUptoScrID(IDLE_SCREEN_ID);
}


/*****************************************************************************
 * FUNCTION
 *  SSCEntryPUK1Success
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCEntryPUK1Success(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSecuritySetupContext.SimLockStatus = CHV_VERIFIED;

    /* Show the popup and delete unused screens. */
    mmi_display_popup(
        get_string(STR_SETTING_CODE_VERIFIED),
        MMI_EVENT_SUCCESS);
    
    mmi_ssc_delete_sim_operation_screens();
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK1);
    DeleteScreenIfPresent(SCR_ID_SECSET_SIM_LOCK_PIN1);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
}


/*****************************************************************************
 * FUNCTION
 *  SSCEntryPUK1
 * DESCRIPTION
 *  Enter PUK1, if verify ok PIN1 is set to a new PIN1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCEntryPUK1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_valid() && !IsScreenPresent(SCR_ID_SECSET_PUK1) && !IsScreenPresent(SCR_ENTER_PUK))
    {
        return; /* avoid dual mode phone with SIM but enter SSC from idle */
    }

    ret = mmi_ssc_check_diff_password("**05*");
    if (ret == 1)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__    
        mmi_display_popup(
            get_string(STRING_MTPNP_CARD1_PIN_DONOT_MATCH),
            MMI_EVENT_FAILURE);
    #else /* __MMI_DUAL_SIM_MASTER__ */
        mmi_display_popup(
            get_string(STR_DIFF_PIN),
            MMI_EVENT_FAILURE);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    
        mmi_ssc_delete_sim_operation_screens();
        return;
    }
    else if (ret == 2)
    {
        /* if the password is invalid display error popup */
        mmi_display_popup(
            get_string(STR_INVALID_PINPUKPLOCK_LENGTH),
            MMI_EVENT_FAILURE);

        mmi_ssc_delete_sim_operation_screens();
        return;
    }
    else if (ret == (U8) -1)
    {
        mmi_display_popup(
            get_string(STR_GLOBAL_INVALID_FORMAT),
            MMI_EVENT_FAILURE);

        mmi_ssc_delete_sim_operation_screens();
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */
    if (IsScreenPresent(SCR_ID_SECSET_PUK1))
    {
        gSecuritySetupContext.VerifyPassSuccessCallBack = SSCEntryPUK1Success;
        SetProtocolEventHandler(SECSETVerifyPINRsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
        mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C);
    }
    else
    {
        if (!mmi_bootup_is_searching_or_idle_reached()) /* if from PUK screen of Bootup */
        {
            mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C);
        }
        else    /* if from Idle screen */
        {
            gSecuritySetupContext.VerifyPassSuccessCallBack = SSCEntryPUK1Success;
            SetProtocolEventHandler(SECSETVerifyPINRsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
            mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SSCEntryPUK2Success
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCEntryPUK2Success(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup(
        get_string(STR_SETTING_CODE_VERIFIED),
        MMI_EVENT_SUCCESS);

    mmi_ssc_delete_sim_operation_screens(); //DeleteUptoScrID(IDLE_SCREEN_ID);
    DeleteScreenIfPresent(SCR_ID_SECSET_PUK2);
    DeleteScreenIfPresent(SCR_ID_SECSET_PIN2);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_CFM_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_NEW_PWD);
    DeleteScreenIfPresent(SCR_ID_SECSET_CHANGEPW_OLD_PWD);
}


/*****************************************************************************
 * FUNCTION
 *  SSCEntryPUK2
 * DESCRIPTION
 *  Enter PUK2, if verify ok PIN2 is set to a new PIN2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCEntryPUK2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_valid())
    {
        return; /* avoid dual mode phone with SIM but enter SSC from idle */
    }

    if (IsScreenPresent(SCR_ID_SECSET_PUK1))
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC),
            MMI_EVENT_FAILURE);
    }
    else
    {
        if (mmi_bootup_is_searching_or_idle_reached()) /* If from idle screen */
        {
            ret = mmi_ssc_check_diff_password("**052*");
            if (ret == 1)
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                mmi_display_popup(
                    get_string(STRING_MTPNP_CARD1_PIN2_DONOT_MATCH),
                    MMI_EVENT_FAILURE);
            #else /* __MMI_DUAL_SIM_MASTER__ */
                mmi_display_popup(
                    get_string(STR_DIFF_PIN2),
                    MMI_EVENT_FAILURE);
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            
                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == 2)
            {
                /* if the password is invalid display error popup */
                mmi_display_popup(
                    get_string(STR_INVALID_PINPUKPLOCK_LENGTH),
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT),
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }

            ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */
            gSecuritySetupContext.VerifyPassSuccessCallBack = SSCEntryPUK2Success;
            SetProtocolEventHandler(SECSETVerifyPINRsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
            mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C);
            return;
        }
        else    /* If from PUK screen of Bootup then its a invalid SSC */
        {
            mmi_display_popup(
                get_string(STR_INCORRECT_SSC),
                MMI_EVENT_FAILURE);
        }
    }
}

#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 


/*****************************************************************************
 * FUNCTION
 *  SSCHandleIrOpen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleIrOpen(void)
{
#ifdef __MMI_IRDA_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_irda_force_ir_open();

    mmi_display_popup(
        get_string(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS);

    DeleteScreenIfPresent(SCR_DIAL_SOS_NUM);
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);

#endif /* __MMI_IRDA_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleIrClose
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleIrClose(void)
{
#ifdef __MMI_IRDA_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_irda_force_ir_close();

    mmi_display_popup(
        get_string(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS);

    DeleteScreenIfPresent(SCR_DIAL_SOS_NUM);
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);

#endif /* __MMI_IRDA_SUPPORT__ */ 
}


#ifdef __MMI_DUAL_SIM_MASTER__
void mmi_ssc_get_sim2_imei_rsp(void *buf)
{
    U8 tempbuf[(MAX_IMEI_LEN + 1) * ENCODING_LENGTH];
    mmi_nw_get_imei_rsp_struct *imeiresponse = (mmi_nw_get_imei_rsp_struct*) buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imeiresponse->result == 1)
    {
    #ifdef __ASCII
        if (strncmp((S8*) imeiresponse->imei, gstrIMEI + 5, MAX_IMEI_LEN) == 0)
    #endif
    #ifdef __UCS2_ENCODING
        mmi_asc_to_ucs2((S8*) tempbuf, (S8*) imeiresponse->imei);
        if (mmi_ucs2ncmp((S8*) tempbuf, gstrIMEI + 10, MAX_IMEI_LEN) == 0)
    #endif /* __UCS2_ENCODING */
        {
            ShowIMEIScreen();
            return;
        }

    #ifdef __ASCII
        memcpy(gstrIMEI, (S8*) imeiresponse->imei, MAX_IMEI_LEN);
    #endif 

    #ifdef __UCS2_ENCODING
    #ifdef __MMI_IMEISV_SUPPORT__
        mmi_asc_to_ucs2((S8*) tempbuf, "\n\nIMEI:");
        mmi_ucs2cat(gstrIMEI, (const S8*)tempbuf);
        mmi_asc_to_ucs2((S8*) tempbuf, (S8*) imeiresponse->imei);
        mmi_ucs2cat(gstrIMEI, (const S8*)tempbuf);
/*
 *      mmi_asc_to_ucs2((S8*) tempbuf, "\nIMEISV:");
 *      mmi_ucs2cat(gstrIMEI, (const S8*)tempbuf);
 *      mmi_asc_to_ucs2((S8*) tempbuf, (S8*) imeiresponse->svn);
 *      mmi_ucs2cat(gstrIMEI, (const S8*)tempbuf);
 */
    #else /* __MMI_IMEISV_SUPPORT__ */ 
        mmi_asc_to_ucs2((S8*) tempbuf, "\n\n");
        mmi_ucs2cat(gstrIMEI, (const S8*)tempbuf);
        mmi_asc_to_ucs2((S8*) tempbuf, (S8*) imeiresponse->imei);
        mmi_ucs2cat(gstrIMEI, (const S8*)tempbuf);
    #endif /* __MMI_IMEISV_SUPPORT__ */ 
    #endif /* __UCS2_ENCODING */ 
    }

    ShowIMEIScreen();
}


void mmi_ssc_get_sim2_imei_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = MSG_ID_MMI_NW_GET_IMEI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    OslMsgSendExtQueue(&Message);
    SetSlaveProtocolEventHandler(mmi_ssc_get_sim2_imei_rsp, MSG_ID_MMI_NW_GET_IMEI_RSP);
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_get_imei_rsp
 * DESCRIPTION
 *  Response handler fn of request to get IMEI number.
 * PARAMETERS
 *  buf     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_get_imei_rsp(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IMEISV_SUPPORT__
    U8 tempbuf[(MAX_IMEI_LEN + 1) * ENCODING_LENGTH];
#endif 
    mmi_nw_get_imei_rsp_struct *imeiresponse = (mmi_nw_get_imei_rsp_struct*) buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gstrIMEI, 0, MAX_IMEISV_DISPLAY_LEN * ENCODING_LENGTH);

    if (imeiresponse->result == 1)
    {
    #ifdef __ASCII
        memcpy(gstrIMEI, (S8*) imeiresponse->imei, MAX_IMEI_LEN);
    #endif 

    #ifdef __UCS2_ENCODING
    #ifdef __MMI_IMEISV_SUPPORT__
        mmi_asc_to_ucs2((S8*) tempbuf, "IMEI:");
        mmi_ucs2cpy(gstrIMEI, (const S8*)tempbuf);
        mmi_asc_to_ucs2((S8*) tempbuf, (S8*) imeiresponse->imei);
        mmi_ucs2cat(gstrIMEI, (const S8*)tempbuf);
        mmi_asc_to_ucs2((S8*) tempbuf, "\nSVN:");
        mmi_ucs2cat(gstrIMEI, (const S8*)tempbuf);
        mmi_asc_to_ucs2((S8*) tempbuf, (S8*) imeiresponse->svn);
        mmi_ucs2cat(gstrIMEI, (const S8*)tempbuf);
    #else /* __MMI_IMEISV_SUPPORT__ */ 
        mmi_asc_n_to_ucs2(gstrIMEI, (S8*) imeiresponse->imei, MAX_IMEI_LEN);
    #endif /* __MMI_IMEISV_SUPPORT__ */ 
    #endif /* __UCS2_ENCODING */ 
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_ssc_get_sim2_imei_req();
#else
    ShowIMEIScreen();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ShowIMEIScreen
 * DESCRIPTION
 *  Display IMEI Number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowIMEIScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ENTER_SSC, NULL, ShowIMEIScreen, NULL);

#ifdef __MMI_IMEISV_SUPPORT__
    ShowCategory7Screen(
        SSC_SCR_IMEI_CAPTION_ID,
        0,
        STR_GLOBAL_OK,
        0,
        0,
        0,
        (U8*) gstrIMEI,
        NULL);
#else /* __MMI_IMEISV_SUPPORT__ */ 
    ShowCategory152Screen(
        SSC_SCR_IMEI_CAPTION_ID, 
        0, 
        STR_GLOBAL_OK, 
        0, 
        0, 
        0, 
        (U8*) gstrIMEI, 
        NULL);
#endif /* __MMI_IMEISV_SUPPORT__ */ 

    /* Delete previous one because it might be shown from idle dialpad and then
       from call management dial pad. */
    DeleteScreenIfPresent(SCR_ENTER_SSC);

    /* If user press SSC to see IMEI in a call, not display dial pad again if 
       he press OK to leave IMEI screen */
    if (isInCall())
    {
        DeleteScreenIfPresent(DTMF_SCR_DISPLAY_ID);
    }

    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SSCStringParsing1
 * DESCRIPTION
 *  Check the Supplement Service Control String table 1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCStringParsing1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

#ifdef __UCS2_ENCODING
    U8 temp_str[MAX_SSC_STRING];
#endif 
    U8 *pTemp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < (sizeof(ssc_table1) / sizeof(ssc_table1[0])); index++)
    {
    #ifdef __UCS2_ENCODING
        mmi_asc_to_ucs2((S8*) temp_str, (S8*) ssc_table1[index].ssc_string);
        pTemp = (U8*) temp_str;
    #endif /* __UCS2_ENCODING */ 
    #ifdef __ASCII
        pTemp = (U8*) ssc_table1[index].ssc_string;
    #endif 

        if (mmi_ucs2cmp((S8*) pTemp, (S8*) g_idle_context.DialPadCallBuffer) == 0)
            if (ssc_table1[index].func_ptr != NULL)
            {
                if (ssc_disable_flag && ssc_table1[index].ssc_disable_ctrl)     /* diamond, 2005/05/13 for SSC disable */
                {
                    return;
                }
                mmi_idle_remove_dialer_screen_exit_handler();
            #if defined(__MMI_SML_MENU__) && !defined(__MMI_DUAL_SIM_MASTER__)
                mmi_sml_reset_menu_content();
            #endif
                ssc_table1[index].func_ptr();
                return;
            }
    }

#ifdef DEBUG_BUF
    mmi_asc_to_ucs2((S8*) temp_str, (S8*) MEM_CTRL_BUF_DBG);
    if (mmi_ucs2ncmp
        ((const S8*)temp_str, (const S8*)g_idle_context.DialPadCallBuffer,
         (U32) mmi_ucs2strlen((const S8*)temp_str)) == 0)
    {
        U8 temp_str2[100], temp_str3[100];
        U32 value;
        extern void kal_monitor_buffer(kal_uint32 index);

        memset(temp_str2, 0, sizeof(temp_str2));
        mmi_ucs2ncpy(
            (S8*) temp_str2,
            (const S8*)&g_idle_context.DialPadCallBuffer[ENCODING_LENGTH * strlen(MEM_CTRL_BUF_DBG)],
            (U32) (mmi_ucs2strlen(g_idle_context.DialPadCallBuffer) - strlen(MEM_CTRL_BUF_DBG)));
    #ifdef __UCS2_ENCODING
        mmi_ucs2_to_asc((S8*) temp_str3, (S8*) temp_str2);
        value = atoi((S8*) temp_str3);
    #else /* __UCS2_ENCODING */ 
        value = atoi((S8*) temp_str2);
    #endif /* __UCS2_ENCODING */ 
    
        mmi_display_popup((UI_string_type)temp_str2, MMI_EVENT_SUCCESS);

        kal_monitor_buffer(value);

        return;
    }
    mmi_asc_to_ucs2((S8*) temp_str, (S8*) MEM_CTRL_BUF_QRY);
    if (mmi_ucs2cmp((const S8*)temp_str, (const S8*)g_idle_context.DialPadCallBuffer) == 0)
    {
        U8 temp_str[100], temp_str2[100];
        extern kal_uint32 buff_pool_debug_mask_g[];

        sprintf((S8*) temp_str, "Ctrl Buffer=%d", buff_pool_debug_mask_g[0]);
    #ifdef __UCS2_ENCODING
        mmi_asc_to_ucs2((S8*) temp_str2, (S8*) temp_str);
        mmi_display_popup((UI_string_type)temp_str2, MMI_EVENT_SUCCESS);
    #else /* __UCS2_ENCODING */ 
        mmi_display_popup((UI_string_type)temp_str, MMI_EVENT_SUCCESS);
    #endif /* __UCS2_ENCODING */ 
        SetLeftSoftkeyFunction(DisplayIdleScreen, KEY_EVENT_UP);
        return;
    }
#endif /* DEBUG_BUF */ 

    mmi_asc_to_ucs2((S8*) temp_str, (S8*) TASK_CTRL_BUF_DBG);
    if (mmi_ucs2ncmp
        ((const S8*)temp_str, (const S8*)g_idle_context.DialPadCallBuffer,
         (U32) mmi_ucs2strlen((const S8*)temp_str)) == 0)
    {
        U8 temp_str2[100], temp_str3[100];
        U32 value;
        extern kal_uint32 task_debug_mask_g[];

        memset(temp_str2, 0, sizeof(temp_str2));
        mmi_ucs2ncpy(
            (S8*) temp_str2,
            (const S8*)&g_idle_context.DialPadCallBuffer[ENCODING_LENGTH * strlen(TASK_CTRL_BUF_DBG)],
            (U32) (mmi_ucs2strlen(g_idle_context.DialPadCallBuffer) - strlen(TASK_CTRL_BUF_DBG)));
    #ifdef __UCS2_ENCODING
        mmi_ucs2_to_asc((S8*) temp_str3, (S8*) temp_str2);
        value = atoi((S8*) temp_str3);
    #else /* __UCS2_ENCODING */ 
        value = atoi((S8*) temp_str2);
    #endif /* __UCS2_ENCODING */ 
    
        mmi_display_popup((UI_string_type)temp_str2, MMI_EVENT_SUCCESS);

        task_debug_mask_g[0] = value;

        return;
    }
    mmi_asc_to_ucs2((S8*) temp_str, (S8*) TASK_CTRL_BUF_QRY);
    if (mmi_ucs2cmp((const S8*)temp_str, (const S8*)g_idle_context.DialPadCallBuffer) == 0)
    {
        U8 temp_str[100], temp_str2[100];
        extern kal_uint32 task_debug_mask_g[];

        sprintf((S8*) temp_str, "Task dbg mask=%d", task_debug_mask_g[0]);
    #ifdef __UCS2_ENCODING
        mmi_asc_to_ucs2((S8*) temp_str2, (S8*) temp_str);
        mmi_display_popup((UI_string_type)temp_str2, MMI_EVENT_SUCCESS);
    #else /* __UCS2_ENCODING */
        mmi_display_popup((UI_string_type)temp_str, MMI_EVENT_SUCCESS);
    #endif /* __UCS2_ENCODING */ 
        SetLeftSoftkeyFunction(DisplayIdleScreen, KEY_EVENT_UP);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SSCStringParsing2
 * DESCRIPTION
 *  Check the Supplement Service Control String table 2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL SSCStringParsing2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

#ifdef __UCS2_ENCODING
    U8 temp_str[MAX_SSC_STRING];
#endif 
    U8 *pTemp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < (sizeof(ssc_table2) / sizeof(ssc_table2[0])); index++)
    {

    #ifdef __UCS2_ENCODING
        mmi_asc_to_ucs2((S8*) temp_str, (S8*) ssc_table2[index].ssc_string);
        pTemp = (U8*) temp_str;
    #endif /* __UCS2_ENCODING */ 
    #ifdef __ASCII
        pTemp = (U8*) ssc_table2[index].ssc_string;
    #endif 

        if (mmi_ucs2cmp((S8*) pTemp, (S8*) g_idle_context.DialPadCallBuffer) == 0)
        {
            if (ssc_table2[index].func_ptr != NULL)
            {
                ssc_table2[index].func_ptr();
            }
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  SSCStringParsing3
 * DESCRIPTION
 *  Chech the Supplement Service Control String table 3
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL SSCStringParsing3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

#ifdef __UCS2_ENCODING
    U8 temp_str[MAX_SSC_STRING];
#endif 
    U8 *pTemp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < (sizeof(sim_table) / sizeof(sim_table[0])); index++)
    {
    #ifdef __UCS2_ENCODING
        mmi_asc_to_ucs2((S8*) temp_str, (S8*) sim_table[index].sim_string);
        pTemp = (U8*) temp_str;
    #endif /* __UCS2_ENCODING */ 
    #ifdef __ASCII
        pTemp = (U8*) sim_table[index].sim_string;
    #endif 

        if (mmi_ucs2ncmp((S8*) pTemp, (S8*) g_idle_context.DialPadCallBuffer, sim_table[index].sim_length) == 0)
        {
            if (sim_table[index].func_ptr != NULL)
            {
                /* temporarily copy the dialed buffer to dial pad if UCM ask to check sim operation */
                if (index == 2 || index == 3)
                {
                    mmi_ucs2cpy(ssc_dialpad_buffer, (S8*) g_idle_context.DialPadCallBuffer);
                }
                mmi_idle_remove_dialer_screen_exit_handler();                
                sim_table[index].func_ptr();
            }
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;

}

/********************************Stub****************************/


/*****************************************************************************
 * FUNCTION
 *  Serial_num
 * DESCRIPTION
 *  Stub fn to return Serial Number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
PS8 Serial_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return "123456789012340";
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandleDisable
 * DESCRIPTION
 *  SSC disable for shipment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleDisable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ssc_disable_flag)
    {
        ssc_disable_flag = MMI_TRUE;
        WriteValue(NVRAM_SSC_DISABLE_FLAG, &ssc_disable_flag, DS_BYTE, &error);

        DisplayIdleScreen();
        mmi_display_popup(get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    }
}


#ifdef __MMI_A2DP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_A2DP_Toggle_PTS_Mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_A2DP_Toggle_PTS_Mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type text[2] = {L"A2DP Normal mode", L"A2DP PTS mode"};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ssc_bt_a2dp_mode)
    {
        g_ssc_bt_a2dp_mode = 0;
    }
    else
    {
        g_ssc_bt_a2dp_mode = 1;
    }

    mmi_display_popup(
        (UI_string_type)text[g_ssc_bt_a2dp_mode],
        MMI_EVENT_SUCCESS);
}
#endif /* __MMI_A2DP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  SSCHandleVendorApp
 * DESCRIPTION
 *  SSC handler for Vendor App
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SSCHandleVendorApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter testbed screen */
    mmi_entry_dev_app_scr();
}

#ifdef __FLAVOR_VENDOR_SDK__

/*****************************************************************************
 * FUNCTION
 *  SSCHandleAvkApp
 * DESCRIPTION
 *  SSC handler for Avk App
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SSCHandleAvkApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter testbed screen */
    mmi_entry_avk_app_scr();
}

#endif

#ifdef __VENUS_UI_ENGINE__
extern void vtst_rt_main_entry(void);
/*****************************************************************************
 * FUNCTION
 *  SSCHandleVenusUITest
 * DESCRIPTION
 *  SSC handler for Venus UI Test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SSCHandleVenusUITest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter Venus UI testbed screen */
    vtst_rt_main_entry();
}
#endif
#ifdef __BTMTK__
extern void BTPowerOn(void);
extern void BTPowerOff(void);

#ifdef __BT_SIM_PROFILE__
extern void SimSrvSetGracefulDiscType(void);
extern void SimSrvSetImmediateDiscType(void);
#endif

#ifdef __MMI_SIMAP_SUPPORT__
extern void mmi_bth_simap_send_status_ind_with_unavailable_req(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_POWER_ON
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_POWER_ON(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type text[2] = {L"BT Local Test", L"BT Local Test" };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BTDlightTest();
    mmi_display_popup((UI_string_type)text[0], MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_POWER_OFF
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_POWER_OFF(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type text[2] = {L"BT Local Test1", L"BT Local Test1" };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BTDlightTest1();
    mmi_display_popup((UI_string_type)text[1], MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_PTS_SIMAP_Graceful_Disc_Type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_PTS_SIMAP_Graceful_Disc_Type(void)
{
    UI_string_type text[2] = {L"BT_PTS_SIMAP_Graceful_Disc_Type", L"BT_PTS_SIMAP_Graceful_Disc_Type" };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup((UI_string_type)text[0], MMI_EVENT_SUCCESS);

#ifdef __BT_SIM_PROFILE__
    SimSrvSetGracefulDiscType();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_PTS_SIMAP_Immediate_Disc_Type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_PTS_SIMAP_Immediate_Disc_Type(void)
{
    UI_string_type text[2] = {L"BT_PTS_SIMAP_Immediate_Disc_Type", L"BT_PTS_SIMAP_Immediate_Disc_Type" };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup((UI_string_type)text[0], MMI_EVENT_SUCCESS);

#ifdef __BT_SIM_PROFILE__
    SimSrvSetImmediateDiscType();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_PTS_SIMAP_PRS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_PTS_SIMAP_PRS(void)
{
    UI_string_type text[2] = {L"BT_PTS_SIMAP_PRS", L"BT_PTS_SIMAP_PRS" };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup((UI_string_type)text[0], MMI_EVENT_SUCCESS);

#ifdef __MMI_SIMAP_SUPPORT__
    /* Send a message to BT Stack instead of calling function call directly */
    mmi_bth_simap_send_status_ind_with_unavailable_req();
#endif
}
#endif /* __BTMTK__ */ 


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_change_sim2_pin1_password_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_change_sim2_pin1_password_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_change_password_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_change_password_rsp_struct*) (info);

    if (resp->result == 1)
    {
        mmi_display_popup(
            get_string(STRING_MTPNP_CARD2_PIN_CHANGE), 
            MMI_EVENT_SUCCESS);

        mmi_secset_delete_upto_idle_screen();
    }
    else if (resp->result == 0 && resp->cause == MMI_SETTING_TYPE_UBCHV1)
    {
        MTPNP_PFAL_Entry_UnblockPIN();
    }
    else
    {
        mmi_display_popup(
            get_string(STRING_MTPNP_WRONG_CARD2_PIN), 
            MMI_EVENT_FAILURE);

        mmi_secset_delete_upto_idle_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_change_sim2_pin2_password_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_change_sim2_pin2_password_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_change_password_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_change_password_rsp_struct*) (info);

    if (resp->result == 1)
    {
        mmi_display_popup(
            get_string(STRING_MTPNP_CARD2_PIN2_CHANGE), 
            MMI_EVENT_SUCCESS);

        mmi_secset_delete_upto_idle_screen();
    }
    else if (resp->result == 0 && resp->cause == MMI_SETTING_TYPE_UBCHV2)
    {
        MTPNP_PFAL_Entry_UnblockPIN2();
    }
    else if (resp->result == 0 && resp->cause == MMI_SETTING_TYPE_UBCHV2_BLOCKED)
    {
        mmi_display_popup(
            get_string(STR_ID_PIN2_NOT_SUPPORT), 
            MMI_EVENT_FAILURE);
    }
    else
    {
        mmi_display_popup(
            get_string(STRING_MTPNP_WRONG_CARD2_PIN2), 
            MMI_EVENT_FAILURE);
        mmi_secset_delete_upto_idle_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_change_sim2_pin1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_change_sim2_pin1(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_check_pin_status_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_check_pin_status_rsp_struct*) (info);

    if (resp->chv_status.chv1_status == CHV_RETRY_ALLOW || resp->chv_status.chv1_status == CHV_VERIFIED)
    {
        SetSlaveProtocolEventHandler(mmi_ssc_change_sim2_pin1_password_rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
        mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C_2);
        return;
    }
    else if (resp->chv_status.chv1_status == CHV_DISABLED)
    {
        mmi_display_popup(
            get_string(STRING_MTPNP_ENABLE_CARD2_PIN), 
            MMI_EVENT_FAILURE);
    }
    else if (resp->chv_status.chv1_status == CHV_DEAD || resp->chv_status.chv1_status == CHV_INVALID_TYPE || resp->chv_status.chv1_status == CHV_BLOCKED || resp->chv_status.chv1_status == CHV_NOTINITED)      /* CHV_DEAD...display err scr-vanita */
    {
        mmi_display_popup(
            get_string(STR_ID_PIN_NOT_SUPPORT), 
            MMI_EVENT_FAILURE);
    }
    mmi_ssc_delete_sim_operation_screens(); //DeleteUptoScrID(IDLE_SCREEN_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_change_sim2_pin2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_change_sim2_pin2(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_check_pin_status_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_check_pin_status_rsp_struct*) (info);

    if (resp->chv_status.chv2_status == CHV_RETRY_ALLOW || resp->chv_status.chv2_status == CHV_VERIFIED)
    {
        SetSlaveProtocolEventHandler(mmi_ssc_change_sim2_pin2_password_rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
        mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C_2);
        return;
    }
    else if (resp->chv_status.chv2_status == CHV_BLOCKED)
    {
        mmi_display_popup(
            get_string(STR_SETTING_PIN2_BLOCK_TITLE), 
            MMI_EVENT_FAILURE);
    }
    else if (resp->chv_status.chv2_status == CHV_DEAD || resp->chv_status.chv2_status == CHV_INVALID_TYPE || resp->chv_status.chv2_status == CHV_DISABLED || resp->chv_status.chv2_status == CHV_NOTINITED) /* CHV_DEAD...display err scr-vanita */
    {
        mmi_display_popup(
            get_string(STR_ID_PIN2_NOT_SUPPORT), 
            MMI_EVENT_FAILURE);
    }
    mmi_ssc_delete_sim_operation_screens(); //DeleteUptoScrID(IDLE_SCREEN_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_send_req_sim2_pin1_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_send_req_sim2_pin1_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_CARD2_ENTER_PUK))
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC), 
            MMI_EVENT_FAILURE);
    }
    else
    {
        if (mmi_bootup_is_sim2_searching_or_idle_reached()) /* if not from PUK Screen of Bootup */
        {
            MYQUEUE msgStruct;

            ret = mmi_ssc_check_diff_password("**04*");
            if (ret == 1)
            {
                mmi_display_popup(
                    get_string(STRING_MTPNP_CARD2_PIN_DONOT_MATCH), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == 2)
            {
                /* if the password is invalid display error popup */
                mmi_display_popup(
                    get_string(STR_INVALID_PINPUKPLOCK_LENGTH), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            
            /* send message and wait response in the same screen and no input can be accepted */
            ClearInputEventHandler(MMI_DEVICE_ALL);
            SetSlaveProtocolEventHandler(mmi_ssc_change_sim2_pin1, PRT_MMI_SMU_CHECK_PIN_STATUS_RSP);
            msgStruct.oslSrcId = MOD_MMI;
            msgStruct.oslDestId = MOD_L4C_2;
            msgStruct.oslMsgId = PRT_MMI_SMU_CHECK_PIN_STATUS_REQ;
            msgStruct.oslSapId = INVALID_SAP;
            msgStruct.oslDataPtr = NULL;
            msgStruct.oslPeerBuffPtr = NULL;
            OslMsgSendExtQueue(&msgStruct);
        }
        else
        {
            mmi_display_popup(
                get_string(STR_INCORRECT_SSC), 
                MMI_EVENT_FAILURE);
            
            mmi_ssc_delete_sim_operation_screens(); //DeleteUptoScrID(IDLE_SCREEN_ID);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_send_req_sim2_pin2_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_send_req_sim2_pin2_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_CARD2_ENTER_PUK))
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC), 
            MMI_EVENT_FAILURE);
    }
    else
    {
        if (mmi_bootup_is_sim2_searching_or_idle_reached()) /* If not from PUK screen of Bootup */
        {
            MYQUEUE msgStruct;

            ret = mmi_ssc_check_diff_password("**042*");
            if (ret == 1)
            {
                mmi_display_popup(
                    get_string(STRING_MTPNP_CARD2_PIN2_DONOT_MATCH), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == 2)
            {
                /* if the password is invalid display error popup */
                mmi_display_popup(
                    get_string(STR_INVALID_PINPUKPLOCK_LENGTH), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            
            /* send message and wait response in the same screen and no input can be accepted */
            ClearInputEventHandler(MMI_DEVICE_ALL);
            SetSlaveProtocolEventHandler(mmi_ssc_change_sim2_pin2, PRT_MMI_SMU_CHECK_PIN_STATUS_RSP);
            msgStruct.oslSrcId = MOD_MMI;
            msgStruct.oslDestId = MOD_L4C_2;
            msgStruct.oslMsgId = PRT_MMI_SMU_CHECK_PIN_STATUS_REQ;
            msgStruct.oslSapId = INVALID_SAP;
            msgStruct.oslDataPtr = NULL;
            msgStruct.oslPeerBuffPtr = NULL;
            OslMsgSendExtQueue(&msgStruct);
        }
        else    /* if from PUK screen then its a invalid SSC */
        {
            mmi_display_popup(
                get_string(STR_INCORRECT_SSC), 
                MMI_EVENT_FAILURE);
            
            mmi_ssc_delete_sim_operation_screens();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_request_pin1_status
 * DESCRIPTION
 *  Dual SIM: SSC handler for **04*
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_request_pin1_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ENTER_PUK) ||       /* SIM1 power on PUK */
        IsScreenPresent(SCR_CARD2_ENTER_PUK) || /* SIM2 power on PUK or SIM2 security setup PUK */
        IsScreenPresent(SCR_ID_SECSET_PUK1) ||  /* SIM1 security setup PUK */
        IsScreenPresent(SCR_ID_SECSET_PUK2) ||  /* SIM1 security setup PUK2 */
        IsScreenPresent(SCR_CARD2_SECSET_PUK2)) /* SIM2 security setup PUK2 */
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC), 
            MMI_EVENT_FAILURE);

        DeleteScreenIfPresent(SCR_SSC_ENTER_PUK);
        return;
    }

    if (MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
        {
            if (mmi_ssc_check_diff_password("**04*") == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            // case 4, 8 ,12
            MTPNP_PFAL_CC_SetDial1Func(SendReqPIN1Status);
            MTPNP_PFAL_CC_SetDial2Func(mmi_ssc_send_req_sim2_pin1_status);
            MTPNP_PFAL_CC_SelectCardScreen();
        }
        else
        {
            // case 2, 6 ,10
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
            SendReqPIN1Status();
        }
    }
    else
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
        {
            // case 3, 7 ,11
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
            mmi_ssc_send_req_sim2_pin1_status();
        }
        else
        {
            // case 1, 5 ,7
            // nothing to do...
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_request_pin1_status
 * DESCRIPTION
 *  Dual SIM: SSC handler for **042*
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_request_pin2_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ENTER_PUK) ||       /* SIM1 power on PUK */
        IsScreenPresent(SCR_CARD2_ENTER_PUK) || /* SIM2 power on PUK or SIM2 security setup PUK */
        IsScreenPresent(SCR_ID_SECSET_PUK1) ||  /* SIM1 security setup PUK */
        IsScreenPresent(SCR_ID_SECSET_PUK2) ||  /* SIM1 security setup PUK2 */
        IsScreenPresent(SCR_CARD2_SECSET_PUK2)) /* SIM2 security setup PUK2 */
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC), 
            MMI_EVENT_FAILURE);

        DeleteScreenIfPresent(SCR_SSC_ENTER_PUK);
        return;
    }

    if (MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
        {
            if (mmi_ssc_check_diff_password("**042*") == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            // case 4, 8 ,12
            MTPNP_PFAL_CC_SetDial1Func(SendReqPIN2Status);
            MTPNP_PFAL_CC_SetDial2Func(mmi_ssc_send_req_sim2_pin2_status);
            MTPNP_PFAL_CC_SelectCardScreen();
        }
        else
        {
            // case 2, 6 ,10
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
            SendReqPIN2Status();
        }
    }
    else
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
        {
            // case 3, 7 ,11
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
            mmi_ssc_send_req_sim2_pin2_status();
        }
        else
        {
            // case 1, 5 ,7
            // nothing to do...
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_verify_pin_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_verify_pin_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_smu_verify_pin_rsp_struct *verify_pin_rsp = (mmi_smu_verify_pin_rsp_struct *) info;
    ST_SIM_CHV_INFO chv_info = { 0 };

    Convert_To_AD_CHV_Info(&chv_info, verify_pin_rsp->chv_info);
    MTPNP_AD_Update_CHV_Info(&chv_info);

    if (mmi_ucs2ncmp(ssc_dialpad_buffer, (S8*) L"**05*", 5) == 0)
    {
        MTPNP_AD_Set_SIM_CurrPwd(MTPNP_SIM_CHV1);
        MTPNP_AD_Set_SMU_Status(MTPNP_AD_SMU_UNBLOCK);
    }

    if (mmi_ucs2ncmp(ssc_dialpad_buffer, (S8*) L"**052*", 6) == 0)
    {
        MTPNP_AD_Set_SIM_CurrPwd(MTPNP_SIM_CHV2);
        MTPNP_AD_Set_SMU_Status(MTPNP_AD_SMU_UNBLOCK);
    }

    MTPNP_AD_CHV_Operation_Rsp((MTPNP_BOOL) verify_pin_rsp->result);

    mmi_ssc_delete_sim_operation_screens();
    memset(ssc_dialpad_buffer, 0, 2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_unblock_sim2_puk1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_unblock_sim2_puk1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_ssc_check_diff_password("**05*");
    if (ret == 1)
    {
        mmi_display_popup(
            get_string(STRING_MTPNP_CARD2_PIN_DONOT_MATCH), 
            MMI_EVENT_FAILURE);
        
        mmi_ssc_delete_sim_operation_screens();
        return;
    }
    else if (ret == 2)
    {
        /* if the password is invalid display error popup */
        mmi_display_popup(
            get_string(STR_INVALID_PINPUKPLOCK_LENGTH), 
            MMI_EVENT_FAILURE);

        mmi_ssc_delete_sim_operation_screens();
        return;
    }
    else if (ret == (U8) -1)
    {
        mmi_display_popup(
            get_string(STR_GLOBAL_INVALID_FORMAT), 
            MMI_EVENT_FAILURE);

        mmi_ssc_delete_sim_operation_screens();
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */
    if (!mmi_bootup_is_sim2_searching_or_idle_reached()) /* if from PUK screen of Bootup */
    {
        MTPNP_AD_Set_SIM_CurrPwd(MTPNP_SIM_CHV1);
        MTPNP_AD_Set_SMU_Status(MTPNP_AD_SMU_UNBLOCK);
        mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C_2);
    }
    else    /* if from Idle screen */
    {
        SetSlaveProtocolEventHandler(mmi_ssc_verify_pin_rsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
        mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C_2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_unblock_sim2_puk2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_unblock_sim2_puk2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_CARD2_ENTER_PUK))
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC), 
            MMI_EVENT_FAILURE);
    }
    else
    {
        if (mmi_bootup_is_sim2_searching_or_idle_reached()) /* If from idle screen */
        {
            ret = mmi_ssc_check_diff_password("**052*");
            if (ret == 1)
            {
                mmi_display_popup(
                    get_string(STRING_MTPNP_CARD2_PIN2_DONOT_MATCH), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == 2)
            {
                /* if the password is invalid display error popup */
                mmi_display_popup(
                    get_string(STR_INVALID_PINPUKPLOCK_LENGTH), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            else if (ret == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }

            ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */
            SetSlaveProtocolEventHandler(mmi_ssc_verify_pin_rsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
            mmi_ssc_send_ss_parsing_req(g_idle_context.DialPadCallBuffer, MOD_L4C_2);
            return;
        }
        else    /* If from PUK screen of Bootup then its a invalid SSC */
        {
            mmi_display_popup(
                get_string(STR_INCORRECT_SSC), 
                MMI_EVENT_FAILURE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_entry_puk1
 * DESCRIPTION
 *  Dual SIM: SSC handler for **05*
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_entry_puk1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_SECSET_PUK2) ||   /* SIM1 security setup PUK2 */
        IsScreenPresent(SCR_CARD2_SECSET_PUK2))  /* SIM2 security setup PUK2 */
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC), 
            MMI_EVENT_FAILURE);
        
        DeleteScreenIfPresent(SCR_SSC_ENTER_PUK);
        return;
    }

    if (IsScreenPresent(SCR_ENTER_PUK) || IsScreenPresent(SCR_ID_SECSET_PUK1))
    {
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
        SSCEntryPUK1();
        return;
    }

    if (IsScreenPresent(SCR_CARD2_ENTER_PUK))
    {
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
        mmi_ssc_unblock_sim2_puk1();
        return;
    }

    if (MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
        {
            if (mmi_ssc_check_diff_password("**05*") == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT), 
                    MMI_EVENT_FAILURE);

                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            // case 4, 8 ,12
            MTPNP_PFAL_CC_SetDial1Func(SSCEntryPUK1);
            MTPNP_PFAL_CC_SetDial2Func(mmi_ssc_unblock_sim2_puk1);
            MTPNP_PFAL_CC_SelectCardScreen();
        }
        else
        {
            // case 2, 6 ,10
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
            SSCEntryPUK1();
        }
    }
    else
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
        {
            // case 3, 7 ,11
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
            mmi_ssc_unblock_sim2_puk1();
        }
        else
        {
            // case 1, 5 ,7
            // nothing to do...
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_entry_puk2
 * DESCRIPTION
 *  Dual SIM: SSC handler for **052*
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_entry_puk2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ENTER_PUK) ||       /* SIM1 power on PUK */
        IsScreenPresent(SCR_CARD2_ENTER_PUK) || /* SIM2 power on PUK or SIM2 security setup PUK */
        IsScreenPresent(SCR_ID_SECSET_PUK1))    /* SIM1 security setup PUK */
    {
        mmi_display_popup(
            get_string(STR_INCORRECT_SSC), 
            MMI_EVENT_FAILURE);
        
        DeleteScreenIfPresent(SCR_SSC_ENTER_PUK);
        return;
    }

    if (IsScreenPresent(SCR_ID_SECSET_PUK2))
    {
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
        SSCEntryPUK2();
        return;
    }

    if (IsScreenPresent(SCR_CARD2_SECSET_PUK2))
    {
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
        mmi_ssc_unblock_sim2_puk2();
        return;
    }

    if (MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
        {
            if (mmi_ssc_check_diff_password("**052*") == (U8) -1)
            {
                mmi_display_popup(
                    get_string(STR_GLOBAL_INVALID_FORMAT), 
                    MMI_EVENT_FAILURE);
                
                mmi_ssc_delete_sim_operation_screens();
                return;
            }
            // case 4, 8 ,12
            MTPNP_PFAL_CC_SetDial1Func(SSCEntryPUK2);
            MTPNP_PFAL_CC_SetDial2Func(mmi_ssc_unblock_sim2_puk2);
            MTPNP_PFAL_CC_SelectCardScreen();
        }
        else
        {
            // case 2, 6 ,10
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
            SSCEntryPUK2();
        }
    }
    else
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT && MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_CHVBLOCKED)
        {
            // case 3, 7 ,11
            MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
            mmi_ssc_unblock_sim2_puk2();
        }
        else
        {
            // case 1, 5 ,7
            // nothing to do...
        }
    }
}

#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_sim_operation_handler
 * DESCRIPTION
 *  SIM operation handler if sim_table[].sim_string is invoked by call application
 * PARAMETERS
 *  number      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_sim_operation_handler(U8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

#ifdef __UCS2_ENCODING
    U8 temp_str[MAX_SSC_STRING];
#endif 
    U8 *pTemp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
    ClearProtocolEventHandler(PRT_MMI_SMU_VERIFY_PIN_RSP);
#ifdef __MMI_DUAL_SIM_MASTER__
    ClearSlaveProtocolEventHandler(PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
    ClearSlaveProtocolEventHandler(PRT_MMI_SMU_VERIFY_PIN_RSP);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    for (index = 0; index < (sizeof(sim_table) / sizeof(sim_table[0])); index++)
    {
    #ifdef __UCS2_ENCODING
        mmi_asc_to_ucs2((S8*) temp_str, (S8*) sim_table[index].sim_string);
        pTemp = (U8*) temp_str;
    #endif /* __UCS2_ENCODING */ 
    #ifdef __ASCII
        pTemp = (U8*) sim_table[index].sim_string;
    #endif 

        if (mmi_ucs2ncmp((S8*) pTemp, (S8*) number, sim_table[index].sim_length) == 0)
        {
            switch (index)
            {
                case 0:
                    SetProtocolEventHandler(SECSETChangePasswordPIN1Rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
                #ifdef __MMI_DUAL_SIM_MASTER__
                    SetSlaveProtocolEventHandler(mmi_ssc_change_sim2_pin1_password_rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
                #endif
                    break;

                case 1:
                    SetProtocolEventHandler(SECSETChangePasswordPIN2Rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
                #ifdef __MMI_DUAL_SIM_MASTER__
                    SetSlaveProtocolEventHandler(mmi_ssc_change_sim2_pin2_password_rsp, PRT_MMI_SMU_CHANGE_PASSWORD_RSP);
                #endif
                    break;

                case 2:
                case 3:
                    SetProtocolEventHandler(SECSETVerifyPINRsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
                #ifdef __MMI_DUAL_SIM_MASTER__
                    SetSlaveProtocolEventHandler(mmi_ssc_verify_pin_rsp, PRT_MMI_SMU_VERIFY_PIN_RSP);
                #endif
                    break;

                default:
                    break;
            }
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_is_sim_operation
 * DESCRIPTION
 *  SIM operation handler if sim_table[].sim_string is invoked by call application
 * PARAMETERS
 *  number      [IN]     
 *  dcs         [IN]       MMI_DEFAULT_DCS or MMI_UCS2_DCS
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ssc_is_sim_operation(U8 *number, U8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

#ifdef __UCS2_ENCODING
    U8 temp_str[MAX_SSC_STRING];
#endif 
    U8 *pTemp;

    S8 dialpad_buffer[MAX_DIAL_PAD * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dcs != MMI_UCS2_DCS)
    {
        mmi_asc_to_ucs2(dialpad_buffer, (S8*) number);
    }
    else
    {
        mmi_ucs2cpy(dialpad_buffer, (S8*) number);
    }

    for (index = 0; index < (sizeof(sim_table) / sizeof(sim_table[0])); index++)
    {
    #ifdef __UCS2_ENCODING
        mmi_asc_to_ucs2((S8*) temp_str, (S8*) sim_table[index].sim_string);
        pTemp = (U8*) temp_str;
    #endif /* __UCS2_ENCODING */ 
    #ifdef __ASCII
        pTemp = (U8*) sim_table[index].sim_string;
    #endif 

        if (mmi_ucs2ncmp((S8*) pTemp, dialpad_buffer, sim_table[index].sim_length) == 0)
        {
            /* temporarily copy the dialed buffer to dial pad if UCM ask to check sim operation */
            if (index == 2 || index == 3)
            {
                mmi_ucs2cpy(ssc_dialpad_buffer, dialpad_buffer);
            }
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_delete_sim_operation_screens
 * DESCRIPTION
 *  Delete sim operation related screen instead of DeleteUptoScrID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_delete_sim_operation_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID); //DeleteUptoScrID(IDLE_SCREEN_ID);
    DeleteScreenIfPresent(SCR_SSC_ENTER_PUK);
#ifdef __MMI_DUAL_SIM_MASTER__
    DeleteScreenIfPresent(SCR_MTPNP_SELECT_CARD);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_send_ss_parsing_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_send_ss_parsing_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ss_parsing_string_rsp_struct *ss_parsing_string_rsp;
    ss_parsing_string_rsp = (mmi_ss_parsing_string_rsp_struct*) info;

    /* should compare with L4C_ERROR however L4 has a special case on this */
    if (ss_parsing_string_rsp->result.flag == 0 /* L4C_ERROR */)
    {
        mmi_display_popup(
            get_string(STR_GLOBAL_INVALID_FORMAT), 
            MMI_EVENT_FAILURE);

        mmi_ssc_delete_sim_operation_screens();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_send_ss_parsing_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_send_ss_parsing_req(S8 *sim_operation_string, U8 dest_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_ss_parsing_string_req_struct *ss_parsing_string_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ss_parsing_string_req = (mmi_ss_parsing_string_req_struct*) OslConstructDataPtr(sizeof(mmi_ss_parsing_string_req_struct));
    mmi_ucs2_to_asc((S8*) ss_parsing_string_req->input, sim_operation_string);
    ss_parsing_string_req->dcs = 0x0F;
    ss_parsing_string_req->length = strlen((S8*) ss_parsing_string_req->input);
    ss_parsing_string_req->ip_string[0] = 0;
    ss_parsing_string_req->source_id = 0;
    ss_parsing_string_req->call_type = 0;
    ss_parsing_string_req->is_sim_operation = 1;

    ClearProtocolEventHandler(MSG_ID_MMI_SS_PARSING_STRING_RSP);
    if (dest_mod_id == MOD_L4C)
    {
        g_pwr_context.PasswordScreen = GetActiveScreenId();
        SetProtocolEventHandler(mmi_ssc_send_ss_parsing_rsp, MSG_ID_MMI_SS_PARSING_STRING_RSP);
    }
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    ClearSlaveProtocolEventHandler(MSG_ID_MMI_SS_PARSING_STRING_RSP);
    if (dest_mod_id == MOD_L4C_2)
    {
        g_pwr_context_2.PasswordScreen = GetActiveScreenId();
        SetSlaveProtocolEventHandler(mmi_ssc_send_ss_parsing_rsp, MSG_ID_MMI_SS_PARSING_STRING_RSP);
    }
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = dest_mod_id;
    Message.oslMsgId = MSG_ID_MMI_SS_PARSING_STRING_REQ;
    Message.oslDataPtr = (oslParaType*) ss_parsing_string_req;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

