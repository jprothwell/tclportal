#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#
# *************************************************************************
#
#        MediaTek Inc GSM/GPRS Wireless Communicatin Project
#              Build/Make Development Tools
#
#                 Copyright (C) 2002
#
#        Author         Date        Description
#        Rex Luo  2002/06/07     Create version 1.0
#
# *************************************************************************
#  MTK_GPRS.BLD  - Build option script
#
#  DISCUSSION:
#  USAGE:
#  IMPORTANT NOTES:
# *************************************************************************
#
#  Copyright Statement:
#  --------------------
#     This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2002
#
# *************************************************************************

# *************************************************************************
# Feature Options (TRUE or FALSE)
# *************************************************************************

COMPILER          =  ADS       # RVCT or ADS

RVCT_MULTI_FILE   =  NONE      # NONE for ADS compiler
                               # NONE or MULTI_FILE for RVCT compiler

RTOS              =  NUCLEUS   # NUCLEUS or THREADX

L1_CATCHER        =  TRUE        # L1 Catcher Support

MTK_SLEEP_ENABLE  =  TRUE       # Sleep Mode Support


RTOS_DEBUG        =  TRUE        # RTOS Debug Support

RF_MODULE         =  AMBER38_DEMO_MT6140D    # SKY74045, AERO, FOUNTAIN2, SPRING, 
                                 # MT6129D, AERO1PLUS

L1_GPRS           =  TRUE        # L1 GPRS Funtion, Notice: MT6205 don't support that

L1_EGPRS          =  TRUE        # L1 EGPRS Funtion, Notice: MT6205 don't support that

L1_EPSK_TX        =  TRUE        # EDGE TX

MTK_DSP_DEBUG     =  FALSE       # DSP Debugging Feature

CSD_SUPPORT       =  TRUE       # CSD Feature

PMIC              =  MT6238PMU       # Charge Function, NONE, MT6305 or MT6318

PLATFORM          =  MT6238      # Hardware Platform, MT6208, FPGA, MT6218, MT6218B, MT6219, MT6226, MT6227, MT6228, MT6229 ...etc.

CHIP_VER          =  S00         # Chip version code of Platform MT6218B, SHOULD BE ONE OF THE FOLLOWINGS
                                 # BN, CN, DN, EN, FN
                                 # S00 for MT6228

CHIP_VERSION_CHECK    = TRUE       #  TRUE, FALSE
                                   # TURE: enable HW ID check
                                   # FALSE: disable HW ID check

MCUROM_SUPPORT    =  FALSE       # Only works for MT6226 and MT6227

UID_SUPPORT       =  FALSE       # TRUE or FALSE
                                 # For MT6226M, MT6226-9. FALSE for basic/evb/l1s

BOARD_VER         =  AMBER38_DEMO_BB # Baseband main board description, SHOULD BE ONE OF THE FOLLOWINGS
                                 # MT6208_EVB, MT6208_CEVB, MT6205_CEVB, ORDNANCE, KLM2003_BB, CHICAGO2003_BB,
                                 # MT6218_MW001, CANNON, MT6218B_EVB, JUPITER_EVB, MT6219_EVB,
                                 # MT6226_EVB, MT6227_EVB, MT6228_EVB, MT6229_EVB

SUB_BOARD_VER     =  PCB01       # MT6218_MW001 Baseband main board subversion, SHOULD BE ONE OF THE FOLLOWINGS
                                 # PCB01

LCD_MODULE        =  AMBER38_DEMO_LCM  # Based on the LCM solutions (even multiple LCM modules for this project)
											# SHOULD BE ONE OF THE FOLLOWINGS, based on the LCM
											# MTKLCM				-	Mono, 	102x64
											# MTKLCM_COLOR		-	Color, 	120x160, for MT6218_MW001 or MT6205_CEVB
											# ORDNANCELCM		-	Mono, 	112x64
											# KLMLCM				-	Color,	128x128
											# INFOLCM			-	Color,	128x128
											# TOPPOLY_LCM     -  Color,   128x160, for MT6218B_EVB
											# SONY_LCM        -  Color,   176x220, for JUPITER_EVB

MCU_CLOCK			=	MCU_208M		# MCU clock setting, MCU_13M, MCU_26M, MCU_39M, MCU_52M, MCU_104M

MCU_DCM           =  DCM_ENABLE  # DCM_ENABLE when MAUI.W07.45 # DCM_ENABLE, DCM_DISABLE                                  # Dynamic Clock Management
                                  # Available BB chip: MT6217, MT6226, MT6226M, MT6227, MT6228, MT6229...etc.

EXT_CLOCK			=	EXT_26M		# External clock source setting, EXT_13M, EXT_26M

CUSTOM_CFLAGS     =  #-g -gtp          # custom flag

MMI_BASE  =  PLUTO_MMI    # PLUTO_MMI, NEPTUNE_MMI

MMI_VERSION 		= 	PLUTO_MMI  	# FCB_MMI, PLUTO_MMI, BW_MMI, EMPTY_MMI, CHICAGO_MMI, KLM_MMI

EMPTY_RESOURCE    =  FALSE       #

SPLIT_SYSTEM      =  FALSE       # Split system feature

MCD_SUPPORT       =  TRUE       # MCD support feature

TST_SUPPORT			=	TRUE			# TST task Support

TST_WRITE_TO_FILE  =  FALSE

TCPIP_SUPPORT     =  UDP_TCP    # UDP_TCP, UDP, TCP, or NONE

TELECA_FEATURE    =  WAP2_SEC    # Teleca WAP support feature:
                                # WAP, WAP2, WAP_SEC WAP2_SEC or NONE

IRDA_SUPPORT      =  FALSE       # IRDA support feature

INPUT_METHOD 		= 	MMI_ZI_V7        	# Input methods: NONE, MMI_T9, or MMI_ZI

HAND_WRITING = MMI_DECUMA  # NONE, MMI_HANWANG, MMI_PENPOWER, MMI_PENPOWER_DEMO, MMI_HANWANG_DEMO, MMI_DECUMA, MMI_DECUMA_DEMO



DICT_SUPPORT		=	MMI_GV			# Dictionary library: NONE, MMI_GV, MMI_MOTECH, MMI_TRILOGY

AFC_VCXO_TYPE     = VCXO		  # VCTCXO     : VCTCXO
                                # VCXO       : VCXO
                                # VCXO_SC    : VCXO with 7 area slope control
                                # VCXO_TC    : VCXO with temperature compensation
                                # VCXO_SC_TC : VCXO with 7 area slope control & temperature compensation


EXT_CAM_MODULE   = NONE  			# AIT102N, AIT103, NONE
                                 # Chip above MT6218B  support camera interface

CAMERA_MODULE_WITH_LCD = FALSE	# TRUE or FALSE

HORIZONTAL_CAMERA = TRUE       # FALSE, TRUE
                                # To enable horizontal camera feature. 
                                # Add HORIZONTAL_CAMERA to global compile option when the value is TRUE.


MELODY_VER	     = 	DSP_WT_SYN  	# NONE, SW_SYN_8K, SW_SYN_16K, DSP_WT_SYN, EXT_AUDIO_CHIP
				  							# SW_SYN_8K supported since MT6205B, that means it is not valid on MT6208, MT6205
				  							# DSP_WT_SYN supported since MT6218B, that means it is not valid on MT6208, MT6205, MT6205B and MT6218

WAVETABLE_VER     = WT600K         # Wavetable version, Please choose one among:
					                  #  WT600K or WT150K for SW_SYN_16K and SW_SYN_8K
					                  #  WT600K,WT300K,WT150K,WT100K,WT70K and WT20K for DSP_WT_SYN

MELODY_CHIP       =   NONE       # YAMAHA_MA3, ROHM_8788, NONE


DEDI_AMR_REC      =  TRUE      # AMR recording in GSM traffic mode. This function requires more than 50%MCU computing power.
				# For running smoothly, the system needs to be equipped with good flash/SRAM that have short
				# access time and page mode been enabled.

VR_ENGINE         =   VR_CYBERON       #  NONE, VR_CYBERON, VR_ITRI

VRSI_LANGUAGE     =  CYBERON_TWBI     # VRSI language, 
                              # CYBERON_TWBI, CYBERON_CNBI, NONE

SW_CHANGE_BLOCKING  = FALSE             # TRUE is used to enforce backup on s set of important data items.

BAND_SUPPORT	    =  QUAD	# support of designated band: PGSM900, EGSM900, RGSM900, DCS1800, PCS1900, GSM850, GSM450, GSM480, DUAL900, TRIPLE, QUAD, DUAL850

MSDC_CARD_SUPPORT_TYPE = MSDC_SD_MMC      #  MSDC_SD_MMC      for SD/MMC card support
                                          #  MSDC_MS 	      for MS card support
                                          #  MSDC_MSPRO       for MS-PRO card support
                                          #  NONE
                                          #  MT6218B, MT6217, MT6219 support MSDC
                                          #  MT6218, MT6205B, MT6208 don't support MSDC

FM_RADIO_CHIP     = MT6188A1       #  NONE, MT6188A1, MT6189A1, AR1000
NAND_SUPPORT     =  TRUE      # TRUE when MAUI.W07.46 # NAND SUPPORT

SYSTEM_DRIVE_ON_NAND = FALSE   #TRUE when MAUI.W07.46 # FALSE : System Drive on NOR flash
                 	                              # TRUE : System Drive on NAND flash

APP_STORAGE_IN_SYS_DRV = FALSE   # To put Email and MMS message to NOR or NAND flash

USB_SUPPORT      =  TRUE       # MT6218B and MT6219 chip support USB

USB_IN_NORMAL_MODE_SUPPORT =  TRUE  # TRUE,FALSE
                                     # To enable USB mass storage support in normal mode

USB_DOWNLOAD         =  NONE    # NONE, NORMAL, SECURE
                                # To enable Factory Download/Connection via USB cable

SSS_SUPPORT      = SSS_LIB     # SSS_LIB, SSS_SOURCE


OTG_SUPPORT      = TRUE       #  TRUE, FALSE
                              #  To enable OTG suuport  feature

OTG_DETECT_ID_PIN_WITH_EINT  =  TRUE  #  TRUE when W08.08 # FALSE, TRUE
                                      # TRUE is used to detect OTG A cable ID pin by external interrupt

J2ME_SUPPORT       = IJET # NONE, IJET, JBLENDIA, JBED

J2ME_VM = HI_VM		# J2ME VM:  NONE, KVM, KVM_SOURCE, HI_VM, HI_VM_SOURCE, JAZELLE

J2ME_FEATURE_SET   = JTWI		# J2ME_FEATURE_SET: NONE, BASIC, JTWI
           
J2ME_SHARE_MED_EXT_MEM = FALSE    # TRUE, FALSE

SUPPORT_JAVA_NOKIA_UI = TRUE  # TRUE, FALSE

SUPPORT_JSR_75_PIM  = TRUE

SUPPORT_JSR_184     = FALSE

SUPPORT_JSR_205     = TRUE

SUPPORT_JSR_82 = FALSE  # TRUE, FALSE

SUPPORT_INFUSIO     = FALSE

SUPPORT_SURFKITCHEN = FALSE

DRM_SUPPORT = MTK #DRM VENDOR: NONE, MTK, BSCI

DRM_VERSION = NONE # DRM VERSION: NONE, V01, V02, ALL

AMRWB_DECODE 		= TRUE		# TRUE/FALSE

AMRWB_ENCODE 		= TRUE		# TRUE/FALSE
					            # MT6219 DSP cannot support AMRWB_ENCODE when GPRS connection

JPG_DECODE 			= JPG_HW		# NONE, JPG_SW, JPG_HW

JPG_ENCODE 			= JPG_HW # JPG_HW	when W08.08	# NONE, JPG_SW, JPG_HW

GIF_DECODE 			= FALSE		# TRUE, FALSE

PNG_DECODE 			= PNG_HW  	# NONE, PNG_HW, PNG_SW

MUSICAM_DECODE  = TRUE   # TRUE, FALSE

DAF_DECODE 			= TRUE		# TRUE/FALSE

MJPG_SUPPORT		= FALSE		# TRUE/FALSE

MP4_DECODE = MP4_HW    # NONE, MP4_HW, MP4_SW
          
MP4_ENCODE = MP4_HW    # NONE, MP4_HW, MP4_SW

AAC_DECODE 			= TRUE		# TRUE/FALSE

ISP_SUPPORT 		= TRUE		# TRUE when W08.08 # TRUE/FALSE

CMOS_SENSOR 		= MT9T012    # MT9T012	when W08.08 # MT9T012 
                              # 6229 uses 2M sensor - MT9D011
                              # Amber38 use MT9T012

SENSOR_ROTATE           = SENSOR_ROTATE_0    # SENSOR_ROTATE_0, SENSOR_ROTATE_90, SENSOR_ROTATE_180, SENSOR_ROTATE_270

SENSOR_LOCATION         = SENSOR_ON_BODY     # SENSOR_ON_BODY, SENSOR_ON_CLAM


PHB_SIM_ENTRY	=	100	# Phonebook Entry Number in SIM: 100, 200

PHB_PHONE_ENTRY	=	100	# Phonebook Entry Number in NVRAM: 100, 200

PHB_LN_ENTRY	=	20	# Call log; Last Number Entry Number: 10, 20, 50

EMAIL_SUPPORT           =  ALL   # NONE or  SMTP_POP3 or ALL

FS_SORT_SUPPORT		=  TRUE	  # Both file system and file manager will support sort function

FS_SORT_MAX_ENTRY = 20000

FS_MOVE_SUPPORT		=  TRUE	  # Both file system and file manager will support move/copy function

FS_CHECKDRIVE_SUPPORT	= FALSE	  # Both file system and file manager will support check drive function
                                   # Drive more than 128MB should turn off this feature.

FS_QM_SUPPORT		=  TRUE	  # File system will support quota management mechanism

FS_TRACE_SUPPORT	=  TRUE  # File System will support trace function only if TST is supported


AEC_ENABLE              =  TRUE  # Acoustic Echo Cancellation (AEC)
                                  # TRUE, FALSE

EES_ENABLE              =  TRUE  # Enhanced Echo Suppression (EES)
                                  # TRUE, FALSE

BT_SEQ_SUPPORT = TRUE  # TRUE, FALSE
                       # TRUE: BT sequence number mechanism is supported
                       # FALSE: BT sequence number mechanism is NOT supported

BLUETOOTH_SUPPORT       = BTMTK_MT6611    # NONE, BTVCSR_HP, BTVCSR_HCI_BCHS, BTMTK or BTMTK_MT6601

BLUETOOTH_VERSION  = BT_VER_PRE21 # NONE, 
                                  # BT_VER_PRE21 - BT 1.2 and BT 2.0
                                  # BT_VER_21 - BT 2.1

CMUX_SUPPORT	        = FALSE   #

DIGIT_TONE_SUPPORT      = FALSE   # TRUE or FALSE

TTS                     = SIMPLE_TTS    # SIMPLE_TTS, CYBERON_DIC_TTS or IFLY_TTS or SINOVOICE_TTS or NONE
					
CUST_KEYPAD_TONE_SUPPORT = FALSE  # TRUE or FALSE

MED_PROFILE             = MED_HIGH  # MED_LOW, MED_NORMAL, MED_HIGH, MED_MODEM

XML_SUPPORT             = TRUE    # TRUE or FALSE

AMR_LINK_SUPPORT        = TRUE    # TRUE or FALSE

IMPS_SUPPORT            =  FALSE  # TRUE or FALSE, IMPS Feature Support


TOUCH_PANEL_SUPPORT     = TP_INTERNAL   #  NONE, MT6301, MT6301B, TP_INTERNAL
                                 # touch panel feature  
DEMO_PROJECT		= TRUE   # TRUE, FALSE. TRUE for internal demo project.

GPRS_MAX_PDP_SUPPORT    = 2      # 2, 3, 4, 5, 6 or 7  Maximum simultaneous PDP contexts (2~7)

BT_CONNECT_TO_UART2   = FALSE      # TRUE, FALSE
                                   # TRUE: BT module is connected to UART2
                                   # FALSE: BT module is connected to UART3, this is general case for most projects

UART3_SUPPORT		= TRUE   # TRUE or FALSE,  SUPPORT UART 3

DMA_UART_VIRTUAL_FIFO   = TRUE   # TRUE or FALSE

SIP_SUPPORT 	        = TRUE        # TRUE or FALSE

SDP_SUPPORT 	        = TRUE        # TRUE or FALSE

# Vogins Start
VRE_SUPPORT = VRE_V30     # NONE, VRE_V20, VRE_V21, VRE_V30

VRE_MEMORY_SOURCE = ASM  # ASM, MED

VRE_MEMORY_SIZE = 3072  # 600, 800, 1536, 2048, 3072

VRE_DEFAULT_GAME = FALSE # TRUE, FALSE

VRE_MTK_BRANCH = MTK_08A

VRE_LOG_ENABLE = FALSE

VRE_CIPHER_UA = TRUE

VRE_USER_AGENT_COMPANY = NONE

VRE_USER_AGENT_PROJECT = NONE

VRE_OVERSEA_VERSION = FALSE
# Vogins End

POC_SUPPORT 	        = NONE       # NONE, V01 or ALL 

XDM_SUPPORT             = TRUE          # TRUE or FALSE

VOIP_SUPPORT            = FALSE     # TRUE, FALSE

PHONE_TYPE 		=  BAR      # BAR, CLAMSHELL, SLIDE  
                           #  Default is BAR

SWDBG_SUPPORT        = FALSE     # MT6228 support software debug 

NAND_FLASH_BOOTING   = FALSE    # MT6228 support NAND FLASH BOOTING

WMA_DECODE = TRUE              # MT6228 and MT6229 support WMA DECODE

LOW_COST_SUPPORT  =  NONE  #  NONE, COMMON, ULC
                            #  compile option for low cost features in order to meet smaller memory size


SUB_LCD_SIZE = NONE # NONE, 48X64BW, 64X96, 96X64BW, 96X64, 128X128

MAIN_LCD_SIZE = 240X400                              # To distinguish the main lcd size. 
                                                                        # We can use it to copy the matching resources, such themecomponents.h, Fontres.c, L_xxx.h, etc, to PLUTO_MMI folder

MMI_MAIN_LCD_DEFAULT_FORMAT   = DEFAULT      # DEFAULT, 16, 24, 32

MMI_SUB_LCD_DEFAULT_FORMAT    = DEFAULT      # DEFAULT, 16, 24, 32


SUBLCD_DEDICATED_KEYS_SUPPORT = FALSE     # TRUE/FALSE
                                          # FALSE: No dedicated keys for subLCD operation
                                          # TRUE:  Have dedicated keys for subLCD when clam close, 
                                          # ex. KEY_MP3_PLAY_STOP, KEY_MP3_FWD, KEY_MP3_BACK

SINGLE_BANK_NOR_FLASH_SUPPORT   =  FALSE  # For low-cost (Flash size targetted at 16Mbits) single-bank NOR-flash solution, where partial of NVRAM is shadowed at RAM.

ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT = FALSE # TRUE, FALSE  
                                               # For single-bank NOR-flash solution without shadowed NVRAM requirement.
                                               
AAC_PLUS_DECODE      =  TRUE		# TRUE/FALSE

EMS_SUPPORT          = EMS_50   # EMS_40 support only EMS 4.0
                                # EMS_50 support EMS 5.0 
                                # EMS_NONE support only pure text content.

WEBCAM_SUPPORT       = TRUE      # TRUE, FALSE for WEB CAMERA support 


R4_SUPPORT      = FALSE   # Release 4 support

R5_SUPPORT      = FALSE   # Release 5 support

R99_SUPPORT	    		= TRUE	  # Release 99 support

EDGE_SUPPORT			= TRUE	  # EDGE support
CHE_SUPPORT          = FALSE    # CHE support

TV_OUT_SUPPORT 		= TRUE		# TRUE, FALSE  only MT6228 and MT6229 support TV OUT

BACKGROUND_SOUND	   = TRUE	  # TRUE/FALSE

AUDIO_3D_SURROUND     = MODE_EARP      # NONE, MODE_LSPK, MODE_EARP, MODE_BOTH
                                  # to enable 3D surround

AUDIO_POST_PROCESS   = ALL_EFFECT	  # NONE, ALL_EFFECT, REVERB_ONLY, TIME_STRETCH_ONLY

MOTION_SENSOR_SUPPORT = MXC6202_I2C  # NONE or KXP84_SPI or KXP84_I2C or KXP74_SPI or MXC6202_I2C
                                     # For motion sensor function support or not. 

LENS_MODULE 	     =   FOXLINK_FM30AF-13-L1             # FOXLINK_FM30AF-13-L1 when W08.08      # NONE, FOXLINK_FM30AF-13-L1

AF_SUPPORT           = TRUE    # TRUE	when W08.08  # TRUE/FALSE

DT_SUPPORT           = TRUE      # TRUE, FALSE

CTM_SUPPORT          = FALSE     # TRUE, FALSE 


M3D_MMI_SUPPORT      = TRUE     # TRUE, FALSE

LCM_ROTATE_SUPPORT   = TRUE     # TRUE, FALSE

BT_SIM_PROFILE       = TRUE      # TRUE, FALSE

BT_HIDD_PROFILE      = TRUE      # TRUE, FALSE       
                                  # Turn on or turn off bluetooth HID profile feature

BT_HFG_PROFILE       = TRUE     # TRUE, FALSE

BT_FTS_PROFILE       = TRUE      # TRUE, FALSE

BT_FTC_PROFILE       = TRUE      # TRUE, FALSE

BT_OPP_PROFILE       = TRUE      # TRUE, FALSE

BT_DUN_PROFILE       = TRUE      # TRUE, FALSE


BT_SPP_SERVER        = BT_SPP_SRV_NO_SCO       # NONE, BT_SPP_SRV_NO_SCO or BT_SPP_SRV_WITH_SCO (default:BT_SPP_SRV_NO_SCO)

                                  # This is only used in BLUETOOTH_SUPPORT = BTMTK_MT6601
                                  # If BLUETOOTH_SUPPORT is not BTMTK_MT6601, its value must be NONE

BT_SPP_CLIENT        = BT_SPP_CLI_WITH_SCO       # NONE, BT_SPP_CLI_NO_SCO or BT_SPP_CLI_WITH_SCO (default: NONE)
                                  # This is only used in BLUETOOTH_SUPPORT = BTMTK_MT6601
                                  # If BLUETOOTH_SUPPORT is not BTMTK_MT6601, its value must be NONE


BT_SPP_PROFILE       = TRUE      # TRUE, FALSE

BT_A2DP_PROFILE       = TRUE      # TRUE, FALSE

BT_AVRCP_PROFILE     = TRUE      # TRUE, FALSE 
                                  # Turn on or off AVRCP profile feature

BT_AUDIO_VIA_SCO     = TRUE     # TRUE, FALSE 
                                 # Support Audio being passed by BT SCO Link. 

BT_FM_RADIO_VIA_SCO  = TRUE     # TRUE, FALSE
                                 # Support FM Radio being passed by BT SCO Link

SVG_SUPPORT = MTK_SVG  # NONE, MTK_SVG, IKIVO_DEMO, IKIVO_SVG12, IKIVO_SVG12_WITH_SCRIPT_ENGINE
                       # support SVG image format

WIFI_SUPPORT = MT5911   # NONE or MT5911

IPERF_SUPPORT        = DUAL  	 #  SINGLE, DUAL, TRIPLE, QUAD, NONE

TFTP_SUPPORT         = TRUE  	 #  TRUE, FALSE

OPENGL               = COMMON_LITE     # COMMON_LITE, NONE
                                 # This compile option is defined for 3D graphics engine.
                                 # Only MT6228 and MT6229 support OPENGL.

USB_MULTI_CHARGE_CURRENT_SUPPORT = TRUE  # TRUE, FALSE 
                                          # Turn On or Off USB multiple charging-current support

RC5_SUPPORT          = TRUE      # TRUE or FALSE, RC5 feature support

GAME_ENGINE          = NONE      # NONE, GE_BROGENT
                                 # to add game engine 


EXT_DAC_SUPPORT      = FALSE     # TRUE, FALSE
                                 # To enable the interface between AFE control and EXT_DAC control.

UNIFIED_MESSAGE_SUPPORT  = TRUE # TRUE or FALSE, unified message support
                                 # GSM project can NOT support UNIFIED_MESSAGE

DRV_CUSTOM_TOOL_SUPPORT  = TRUE # TRUE or FALSE, To enable using driver customization tool for GPIO/EINT/ADC/UEM/Keypad setting.


WAP_SUPPORT          = OBIGO_Q03C   # NONE, OBIGO_Q03C, OBIGO_Q05A


					
DSPIRDBG             = FALSE      # IRDBG interface for dsp debugging
                                 # only support in 6229 E2

BARCODE_DECODER     = SCANBUY_QRDM       #  NONE, SCANBUY_QRDM, SCANBUY_DM, GMEDIA_QRDM, GMEDIA_DM, MMI_ONLY
					
SECURE_SUPPORT      = FALSE       #

SECURE_VERSION      = 1          #

SECURE_JTAG_ENABLE  = FALSE       #

SECURE_CUSTOM_NAME  = MTK        # MTK (6227C/6225 EVB) or JRD (JRD_06A) 

SECURE_RO_ENABLE    = FALSE       # TRUE, FALSE

SECURE_PORT_SUPPORT = FALSE       # TRUE, FALSE

DISPLAY_TYPE        = COLOR      # BW, COLOR

OTP_SUPPORT         = FALSE      # TRUE, FALSE

SW_FLASH           = NEOMTEL    # NONE, CHAOTEX

SYNCML_SUPPORT                   = FALSE        # TRUE or FALSE

UNIFIED_MESSAGE_ADVANCE_FEATURE = NONE  	# Unified message advance feture:
                                                       # NONE, COMPOSER, LISTOPTION, ARCHIVE, 
                                                       # COMPOSER_LISTOPTION, COMPOSER_ARCHIVE, LISTOPTION_ARCHIVE, COMPOSER_LISTOPTION_ARCHIVE
                                                       # Only support when unified message feature is turned on.

STREAM_SUPPORT   =   FALSE   # TRUE or FALSE

PGDL_SUPPORT  =  FALSE          # TRUE or FALSE

RTSP_SUPPORT = TRUE            # TRUE or FALSE

FOTA_ENABLE = NONE   # FOTA_DM, NONE

SYNC_LCM_SUPPORT = TRUE         # TRUE or FALSE 
                                 # TRUE if Sync mode LCM is applied and FALSE if Sync mode LCM is applied.
                           
FEATURE_OVERLOAD = FALSE         # TRUE or FALSE  
                                 # TRUE : turn on bypassing 
                                 # FLASE : turn off bypassing
                         
AAC_PLUS_PS_DECODE = TRUE       # TRUE, FALSE                                                    

VDOEDT_SUPPORT     = TRUE       # TRUE, FALSE    

OPTR_SPEC               = NONE   # CMCC_0202_SEGA, CMCC_0202_SEGB, CMCC_0202_SEGC,
                                 # CMCC_0202_SEGA_TECH, CMCC_0202_SEGB_TECH, CMCC_0202_SEGC_TECH, 
                                 # ORANGE_0605_CAM240 ,INDIA_0100_SEGB, VODAFONE_R12_LIVE, NONE

SYNCML_DM_SUPPORT       = FALSE  # TRUE or FALSE

VIRTUAL_PORTS_NUM       = 5      # default is 5, maximum is 9

SPATIAL_DITHERING       = TRUE   # TRUE or FALSE
                                 # support by MT6225, MT6228, MT6229 and MT6230

PICTBRIDGE_SUPPORT      = TRUE  # TRUE or FALSE, IMPS Feature Support
					
TDMB_SUPPORT            = NONE       # NONE, TELECHIP_TDMB, FRONTIER_TDMB       

WBXML_SUPPORT   = TRUE            # TRUE or FALSE
					
ISO_PRIORITY_MODE_SUPPORT = TRUE   # FALSE, TRUE
					
KEYPAD_TYPE             = NORMAL_KEYPAD  # NORMAL_KEYPAD, REDUCED_KEYPAD					

FLASHLIGHT_TYPE         = XENON_FLASHLIGHT_ANTI_RED_EYE            # NONE, LED_ONOFF_SUPPORT, LED_FLASHLIGHT_SUPPORT

FLASHLIGHT_MODULE       = IMCR3603_S010AO     #NONE,IMCR3603_S010AO

UCM_SUPPORT             = TRUE          # TRUE or FALSE
                                         # to enable unified call management feature


TOUCH_PANEL_SHORTCUT_SUPPORT   = FALSE         # FALSE, TRUE
                                               # TRUE for  touch panel size need to be larger than LCD size
                                               # Support touch panel shortcut functionality 

LANGLN_ENGINE           =  NONE         # NONE, LANGLN_DIGIDEA
                                               # Add compile option for language learning application

GIS_SUPPORT             =  NONE         # NONE, SUNAVI, MAPBAR_NAVI, MAPBAR_BUS


                                               # Add compile option for GIS application


SSL_SUPPORT = SSL_CIC_LIB   # NONE, SSL_CIC_LIB, MTK_SSL_CIC

SOCKET_SSL_SUPPORT = TRUE  # TRUE, FALSE

SYSGEN_ENABLE           = TRUE         # FALSE, TRUE
                                   
BACKGROUND_SMS_SUPPORT  = FALSE		     # TRUE or FALSE                                    

PURE_AUDIO_SUPPORT      = TRUE         # TRUE or FALSE 
                                       # Support pure audio 3GP/MP4 file in audio player
					
FLC_VER                = FLC2         # FLC2 or FLC1

FONT_RESOURCE         = DEMO   # DEMO, OFFICIAL

AUDIO_EQ_ENABLE           = TRUE # TRUE, FALSE

AUDIO_COMPENSATION_ENABLE = TRUE  # TRUE, FALSE

BSAC_DECODE =  TRUE  # TRUE, FALSE

INTERNAL_ANTENNAL_SUPPORT = FALSE  # TRUE, FALSE

GPS_SUPPORT           = NONE       # NONE, MT3316, MT3326                                   # NONE: Don't support GPS module on board
                                   # MT3318: Use MT3318 GPS module on board
                                   
BT_GPS_SUPPORT = FALSE  # TRUE, FALSE
                        # FALSE:  Don't support the phone connect GPS via bluetooth
                        # TRUE: Support the phone connect GPS via bluetooth

EMLPP_SUPPORT = FALSE  # TRUE, FALSE
                       # TRUE: CC EMLPP  feature is supported
                       # FALSE: CC EMLPP  feature is NOT supported

	
UUS_SUPPORT = FALSE  # TRUE, FALSE
                     # TRUE: CC User-User Service feature is supported
                     # FALSE: CC User-User Service feature is NOT supported

H264_DECODE = H264_HW
# NONE, H264_HW, H264_SW
					
DVBH_SUPPORT = NONE   # NONE

DCD_SUPPORT = NONE    # INFRAWARE, NONE

SENSOR_TYPE = RAW    # RAW, YUV, DIRECT, NONE

FM_RADIO_HW_SEARCH = FALSE    # TRUE, FALSE

BT_FAX_PROFILE = FALSE  # TRUE, FALSE

IC_TEST_TYPE = NONE  # NONE, IC_MODULE_TEST, IC_BURNIN_TEST
                                
MMI_FEATURES_SWITCH = FALSE  # TRUE, FALSE
                                
FAX_SUPPORT = FALSE  # TRUE, FALSE
                                
RSAT_SUPPORT = NONE  # NONE, MODEM_WITH_RSAT, MMI_WITH_RSAT


CAMCORDER_SUPPORT = TRUE  # TRUE or FALSE, only can be turned on in MT6238 series platform

AUD_RECORD = TRUE          # TRUE, FALSE : Turn on audio record feature, olny set to FALSE for very low cost project

AIFF_DECODE = FALSE  # TRUE, FALSE
                                
AU_DECODE = FALSE  # TRUE, FALSE
                                
BT_BIP_PROFILE = TRUE  # TRUE, FALSE
                                
BT_BPP_PROFILE = TRUE  # TRUE, FALSE
                                
DOWNLOADABLE_THEME = FALSE  # TRUE, FALSE
                                
EXIF_SUPPORT = TRUE  # TRUE, FALSE
                                
FM_RADIO_RECORD = FALSE  # TRUE, FALSE
                                
JTONE_SUPPORT = TRUE  # TRUE, FALSE
                                
UNIFIED_MESSAGE_SIMBOX_SUPPORT = FALSE  # TRUE, FALSE
                                
DLT_ALWAYS_LOAD_BUFFER_SIZE = 0
                                
DLT_LOAD_ON_DEMAND_BUFFER_SIZE = 0
                                
SMS_PHONE_ENTRY = 200  # SMS Entry Number in NVRAM: 200

SMS_TOTAL_ENTRY = 200  # SMS Entry Number in NVRAM and SIM: 200 (>=SMS_PHONE_ENTRY)

PRODUCTION_RELEASE	= FALSE	  # Production release feature includs autoreset when system hang

CBM_ALWAYS_ASK_SUPPORT = TRUE # TRUE or FALSE

CBM_CONNECTION_MANAGER_SUPPORT = TRUE # TRUE or FALSE

CBM_BEARER_FALLBACK_SUPPORT = TRUE # TRUE or FALSE

DCD_INTERNAL_TEST = FALSE   # FALSE:using normal DCD Server
					                  # TRUE:using testing DCD Server
					                            
MULTIPLE_BINARY_FILES = FALSE   # TRUE or FALSE
					                            
BT_PBAP_PROFILE		 = FALSE # TRUE or FALSE ,only can be turned on phonebook access profile feature on.
AGPS_SUPPORT = NONE  #NONE, USER_PLANE, CONTROL_PLANE. Only can be turned when GPS feature is turned on.
OMA_ULP_SUPPORT = NONE # NONE, V1, V1.5 or V2

DISABLE_A5_2 = TRUE    # TURE : disable A5/2 ciphering mode (default value)
                       # FALSE : enable A5/2 ciphering mode
                       
NDIS_SUPPORT   =  FALSE  # TRUE or FALSE, NDIS Feature Support (require CMUX_SUPPORT = TRUE )
                          # TRUE : Support NDIS feature
                          # FALSE: Do not support NDIS feature
                          
CAMCORDER_FACE_DETECTION_MODE_SUPPORT = FALSE  # TRUE, FALSE

REDUCE_PLUTO_HEADER_DEPTH = TRUE # TRUE or FALSE

MSG_SMS_EMAIL_SUPPORT = FALSE  # TRUE, FALSE,
                               # only can be turned on if unified message feature and UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT are turned on.

UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT = FALSE   # TRUE, FALSE,
                                   		    # only can be turned on if unified message feature is turned on.

WAV_CODEC         =   TRUE       #  TRUE,FALSE. The capability of file/stream PCM/WAV playback and record.

AMR_CODEC         =   TRUE       #  TRUE, FALSE.

CCBS_SUPPORT         =   TRUE       #  TRUE, FALSE.

CNAP_SUPPORT         =   TRUE       #  TRUE, FALSE.

EXT_MODEM_SUPPORT = FALSE  # TRUE, FALSE

MMS_SUPPORT =  OBIGO_Q03C_MMS_V01  # OBIGO_Q05A, OBIGO_Q03C_MMS_V01, OBIGO_Q03C_MMS_V02, NONE

LQT_SUPPORT =  TRUE  # TRUE, FALSE

BIP_SCWS_SUPPORT = TRUE # TRUE, FALSE


# below macro definition is for dual mode
DUAL_MODE_SUPPORT = NONE # MASTER, SLAVE, NONE, 
                           # GEMINI: Single chip dual card solution


SENDKEY_MODE = SINGLE_KEY_SELECT_MENU # SINGLE_KEY_SELECT_MENU   SENDKEY2_SUPPORT
                                      # SINGLE_KEY_SELECT_MENU only one sendkey will popup a menu to select dail card1 or card2
                                      # SENDKEY2_SUPPORT  two sendkeys the one is for card1 and the other is for card2

MERCURY_SLAVE_BT_SUPPORT = FALSE # TRUE or FALSE

GEMINI = FALSE

SINGLE_SIM_MMI_ONLY = FALSE # SINGLE_SIM_MMI_ONLY = TRUE/FALSE
                            # SINGLE_SIM_MMI_ONLY = TRUE : Use single SIM MMI
                            # SINGLE_SIM_MMI_ONLY = FALSE : Use dual SIM MMI


FLAVOR = NONE  # FLAVOR = NONE/$(FLAVOR)
               # FLAVOR = NONE: No flavor name was used and a compile option __FLAVOR_NOT_PRESENT__ was defined.
               # FLAVOR = $(FALVOR): A flavor name $(FLAVOR) was used and a compile option __FLAVOR_$(FLAVOR)__ was defined.
               # __FLAVOR_$(FLAVOR)__  or __FLAVOR_NOT_PRESENT__ will be used in MMI feature files.

# *************************************************************************
# Release Setting Section
# *************************************************************************
RELEASE_PACKAGE		= REL_CR_MMI_VOGINS_$(strip $(PROJECT))	# REL_CR_MMI_GPRS, REL_CR_MMI_GSM, REL_CR_PROTOCOL_GPRS, REL_CR_PROTOCOL_GSM, REL_CR_L4_GPRS, REL_CR_L4_GSM
RELEASE_WAE		= SRC		# MTK/SRC, only works when TELECA_FEATURES works
RELEASE_WAP		= MTK		# MTK/SRC, only works when TELECA_FEATURES works
RELEASE_BCHS		= MTK		# MTK/SRC, only works when BLUETOOTH_SUPPORT=BTVCSR_HCI_BCHS
RELEASE_$(strip $(INPUT_METHOD)) = SRC	# MTK/SRC, only works when INPUT_METHOD is turning on
RELEASE_INPUT_METHODS_SRC =		# MMI_ZI, MMI_T9, MMI_ITAP,

# *************************************************************************
# Consistent Feature Options
# *************************************************************************
COM_DEFS_FOR_AMBER38_DEMO_LCM = S6D0170 COLOR_LCD AMBER38_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_AMBER38_DEMO_MT6140D       = MT6140D_RF AMBER38_DEMO_MT6140D

# *************************************************************************
# Include MODEM.mak
# *************************************************************************
include make\MODEM.mak

# *************************************************************************
# Project specified preprocessor definitions
# *************************************************************************
CUSTOM_OPTION     += __IP_NUMBER__ __PHB_0x81_SUPPORT__ \
                     __KBD_2STEP_KEY_SUPPORT__

CUSTOM_OPTION     +=  __MSDC_NOT_SUPPORT_HOT_PLUG__ __MSDC_NO_WRITE_PROTECT__

CUSTOM_OPTION     +=  __CHARGER_USB_DETECT_WIHT_ONE_EINT__

CUSTOM_OPTION     += BIDI_SUPPORT __ENS__

CUSTOM_OPTION     +=  __EM_MODE__

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
     CUSTOM_OPTION    += __IMAP_REMOTE_FOLDER__
  endif
endif

# *************************************************************************
# Custom Release Component Configuration
# *************************************************************************
include make\$(strip $(RELEASE_PACKAGE)).mak

# ************************************************************************* 
# Component trace definition header files for custom release only 
# ************************************************************************* 
# Following trace headers are already existed in custom release 
# You can add new traces with kal_trace() in the following trace headers 
EXISTED_CUS_REL_TRACE_DEFS = 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_inet_app_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_conn_app_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_common_app_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_media_app_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += plutommi\mmi\inc\mmi_fw_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += j2me\interface\j2me_trace.h 
EXISTED_CUS_REL_TRACE_DEFS += drm\include\drm_trace.h 
EXISTED_CUS_REL_TRACE_DEFS += wifi\wndrv\include\os\wndrv_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += drv\include\drv_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += usb\include\usb_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\sim\include\sim_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += bmt\bmt_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += l1audio\l1sp_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += nvram\include\nvram_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\include\l4_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\phb\include\phb_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\uem\include\uem_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += media\common\include\med_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\dt\include\dt_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += vendor\wap\obigo_q03c\adaptation\integration\include\wap_trc.h 
 
# Customer can add new trace headers here for new modules 
NEW_CUS_REL_TRACE_DEFS = 
