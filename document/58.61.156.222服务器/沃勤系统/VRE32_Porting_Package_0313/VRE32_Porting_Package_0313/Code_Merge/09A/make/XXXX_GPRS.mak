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
                               # ADS : ADS v1.2 , standard release
                               # RVCT : RVCT v3.1 , MediaTek internal use


RVCT_VERSION      =  NONE      # NONE, V22, V31

RVCT_MULTI_FILE   =  NONE      # NONE for ADS compiler
                               # NONE or MULTI_FILE for RVCT compiler

RTOS              =  NUCLEUS   # NUCLEUS or THREADX

L1_CATCHER        =  TRUE        # L1 Catcher Support

MTK_SLEEP_ENABLE  =  TRUE       # Sleep Mode Support


RTOS_DEBUG        =  TRUE        # RTOS Debug Support

RF_MODULE         =  AD6548_CUSTOM    # SKY74045, AERO, FOUNTAIN2, SPRING, 
                                 # MT6129D, AERO1PLUS

L1_GPRS           =  TRUE        # L1 GPRS Funtion, Notice: MT6205 don't support that

L1_EGPRS          =  TRUE        # L1 EGPRS Funtion, Notice: MT6205 don't support that

L1_EPSK_TX = FALSE        # EDGE TX

MTK_DSP_DEBUG     =  FALSE       # DSP Debugging Feature


PMIC              =  MT6235PMU       # Charge Function, NONE, MT6305 or MT6318

PLATFORM          =  MT6235B      # Hardware Platform, MT6208, FPGA, MT6218, MT6218B, MT6219, MT6226, MT6227, MT6228, MT6229 ...etc.

CHIP_VER          =  S01         # Chip version code of Platform MT6218B, SHOULD BE ONE OF THE FOLLOWINGS
                                 # BN, CN, DN, EN, FN
                                 # S00 for MT6228

CHIP_VERSION_CHECK    = TRUE       #  TRUE, FALSE
                                   # TURE: enable HW ID check
                                   # FALSE: disable HW ID check

MCUROM_SUPPORT    =  FALSE       # Only works for MT6226 and MT6227

UID_SUPPORT       =  FALSE       # TRUE or FALSE
                                 # For MT6226M, MT6226-9. FALSE for basic/evb/l1s

BOARD_VER         = KCMSZ35_09A_GEMINI_BB # Baseband main board description, SHOULD BE ONE OF THE FOLLOWINGS
                                 # MT6208_EVB, MT6208_CEVB, MT6205_CEVB, ORDNANCE, KLM2003_BB, CHICAGO2003_BB,
                                 # MT6218_MW001, CANNON, MT6218B_EVB, JUPITER_EVB, MT6219_EVB,
                                 # MT6226_EVB, MT6227_EVB, MT6228_EVB, MT6229_EVB

SUB_BOARD_VER     =  PCB01       # MT6218_MW001 Baseband main board subversion, SHOULD BE ONE OF THE FOLLOWINGS
                                 # PCB01

LCD_MODULE        = KCMSZ35_09A_GEMINI_LCM  # Based on the LCM solutions (even multiple LCM modules for this project)
											# WISTRON_2P8_WQVGA_LCM
											# SHOULD BE ONE OF THE FOLLOWINGS, based on the LCM
											# MTKLCM				-	Mono, 	102x64
											# MTKLCM_COLOR		-	Color, 	120x160, for MT6218_MW001 or MT6205_CEVB
											# ORDNANCELCM		-	Mono, 	112x64
											# KLMLCM				-	Color,	128x128
											# INFOLCM			-	Color,	128x128
											# TOPPOLY_LCM     -  Color,   128x160, for MT6218B_EVB
											# SONY_LCM        -  Color,   176x220, for JUPITER_EVB

MCU_CLOCK			=	MCU_208M		# MCU clock setting, MCU_13M, MCU_26M, MCU_39M, MCU_52M, MCU_104M

MCU_DCM           =  DCM_ENABLE  # DCM_ENABLE, DCM_DISABLE 
                                  # Dynamic Clock Management
                                  # Available BB chip: MT6217, MT6226, MT6226M, MT6227, MT6228, MT6229...etc.

EXT_CLOCK			=	EXT_26M		# External clock source setting, EXT_13M, EXT_26M

CUSTOM_CFLAGS     = #-g -gtp          # custom flag

MMI_BASE  =  PLUTO_MMI    # PLUTO_MMI, NEPTUNE_MMI

MMI_VERSION 		= 	PLUTO_MMI  	# FCB_MMI, PLUTO_MMI, BW_MMI, EMPTY_MMI, CHICAGO_MMI, KLM_MMI


EMPTY_RESOURCE    = TRUE       #
	
MMI_FEATURES_SWITCH = FALSE       # TRUE or FALSE   It's for the internal usage only.

SPLIT_SYSTEM      =  FALSE       # Split system feature

MCD_SUPPORT       =  TRUE       # MCD support feature

TST_SUPPORT			=	TRUE			# TST task Support

TST_WRITE_TO_FILE  =  FALSE

TCPIP_SUPPORT     =  UDP_TCP    # UDP_TCP, UDP, TCP, or NONE

TELECA_FEATURE = WAP2_SEC  # WAP, WAP2, WAP_SEC, WAP2_SEC, NONE

IRDA_SUPPORT      =  FALSE       # IRDA support feature

INPUT_METHOD 		= NONE        	# Input methods: NONE, MMI_T9, or MMI_ZI

HAND_WRITING 		= MMI_PENPOWER_DEMO   	# NONE, MMI_HANWANG, MMI_PENPOWER, MMI_PENPOWER_DEMO, MMI_HANWANG_DEMO, MMI_DECUMA, MMI_DECUMA_DEMO

DICT_SUPPORT		= NONE			# NONE, MMI_MOTECH

AFC_VCXO_TYPE     = VCXO		  # VCXO     : VCTCXO
                                # VCXO       : VCXO
                                # VCXO_SC    : VCXO with 7 area slope control
                                # VCXO_TC    : VCXO with temperature compensation
                                # VCXO_SC_TC : VCXO with 7 area slope control & temperature compensation




HORIZONTAL_CAMERA = TRUE       # FALSE, TRUE
                                # To enable horizontal camera feature. 
                                # Add HORIZONTAL_CAMERA to global compile option when the value is TRUE.


MELODY_VER	     = 	DSP_WT_SYN  	# NONE, SW_SYN_8K, SW_SYN_16K, DSP_WT_SYN, EXT_AUDIO_CHIP
                                 # SIN_WAV_SYN supported since MT6208
				  							# SW_SYN_8K supported since MT6205B, that means it is not valid on MT6208, MT6205
				  							# DSP_WT_SYN supported since MT6218B, that means it is not valid on MT6208, MT6205, MT6205B and MT6218

WAVETABLE_VER     = WT600K         # Wavetable version, Please choose one among:
					                  #  WT600K or WT150K for SW_SYN_16K and SW_SYN_8K
					                  #  WT600K,WT300K,WT150K,WT100K,WT70K and WT20K for DSP_WT_SYN



DEDI_AMR_REC      =  TRUE      # AMR recording in GSM traffic mode. This function requires more than 50%MCU computing power.
				# For running smoothly, the system needs to be equipped with good flash/SRAM that have short
				# access time and page mode been enabled.

VR_ENGINE         = NONE       #  NONE, VR_CYBERON, VR_ITRI

VRSI_LANGUAGE     = NONE     # VRSI language, 
                              # CYBERON_TWBI, CYBERON_CNBI, NONE

SW_CHANGE_BLOCKING  = FALSE             # TRUE is used to enforce backup on s set of important data items.

BAND_SUPPORT	    =  QUAD	# support of designated band: PGSM900, EGSM900, RGSM900, DCS1800, PCS1900, GSM850, GSM450, GSM480, DUAL900, TRIPLE, QUAD, DUAL850

MSDC_CARD_SUPPORT_TYPE = MSDC_SD_MMC      #  MSDC_SD_MMC      for SD/MMC card support
                                          #  MSDC_MS 	      for MS card support
                                          #  MSDC_MSPRO       for MS-PRO card support
                                          #  NONE
                                          #  MT6218B, MT6217, MT6219 support MSDC
                                          #  MT6218, MT6205B, MT6208 don't support MSDC

FM_RADIO_CHIP     = MT6188A1       # NONE, MT6189A1, MT6188A1, AR1000

NAND_SUPPORT     =  TRUE      # NAND SUPPORT

SYSTEM_DRIVE_ON_NAND = TRUE   # FALSE : System Drive on NOR flash
                 	                              # TRUE : System Drive on NAND flash

APP_STORAGE_IN_SYS_DRV = FALSE   # To put Email and MMS message to NOR or NAND flash

USB_SUPPORT      =  TRUE       # MT6218B and MT6219 chip support USB

USB_HS_SUPPORT = FALSE  # TRUE, FALSE

USB_COM_PORT_SUPPORT = TRUE  # TRUE, FALSE

USB_MASS_STORAGE_SUPPORT = TRUE  # TRUE, FALSE


USB_IN_NORMAL_MODE_SUPPORT =  TRUE  # TRUE,FALSE
                                     # To enable USB mass storage support in normal mode

USB_DOWNLOAD         = NORMAL     #NONE or NORMAL or SECURE
                                # To enable Factory Download/Connection via USB cable

SSS_SUPPORT      = SSS_LIB     # SSS_LIB, SSS_SOURCE


OTG_SUPPORT      = FALSE       #  TRUE, FALSE

                               #  To enable OTG suuport  feature

OTG_DETECT_ID_PIN_WITH_EINT  =  FALSE  # FALSE, TRUE
                                       # TRUE is used to detect OTG A cable ID pin by external interrupt

J2ME_SUPPORT       = NONE # NONE, IJET, JBLENDIA, JBED, MTK_DUMMYVM

J2ME_VM			       = NONE		# J2ME VM:  NONE, KVM, KVM_SOURCE, HI_VM, HI_VM_SOURCE, JAZELLE, KVM_KDWP, KVM_KDWP_SOURCE

J2ME_FEATURE_SET   = NONE		# J2ME_FEATURE_SET: NONE, BASIC, JTWI

J2ME_SHARE_MED_EXT_MEM = FALSE    # TRUE, FALSE

SUPPORT_JAVA_NOKIA_UI = FALSE  # TRUE, FALSE

SUPPORT_JSR_75_PIM  = FALSE

SUPPORT_JSR_75_PIM_MSA = TRUE    # TRUE, FALSE

SUPPORT_JSR_184     = FALSE

SUPPORT_JSR_205     = FALSE

SUPPORT_JSR_82 = FALSE  # TRUE, FALSE

SUPPORT_BACKGROUND_JAVA = FALSE  # TRUE, FALSE


DRM_SUPPORT = NONE #DRM VENDOR: NONE, MTK, BSCI

DRM_VERSION = V01 # DRM VERSION: NONE, V01, V02, ALL

DRM_SUPPORT_SCAN_DISK = FALSE  # TRUE/FALSE (DRM supports scan disk or not)

DRM_SUPPORT_DB_SIZE = NONE  # NONE/DEFAULT/64/256/512/1024 (DRM database size cnfiguration)

AMRWB_DECODE 		= TRUE		# TRUE/FALSE

AMRWB_ENCODE 		= TRUE		# TRUE/FALSE      # MT6219 DSP cannot support AMRWB_ENCODE when GPRS connection

JPG_DECODE 			= JPG_SW		# NONE, JPG_SW, JPG_HW

JPG_ENCODE 			= JPG_SW		# NONE, JPG_SW, JPG_HW

GIF_DECODE 			= FALSE		# TRUE/FALSE

PNG_DECODE 			= PNG_SW  	# NONE, PNG_HW, PNG_SW

MUSICAM_DECODE  = TRUE   # TRUE, FALSE

DAF_DECODE 			= TRUE		# TRUE/FALSE

MJPG_SUPPORT		= FALSE		# TRUE/FALSE


AAC_DECODE 			= TRUE		# TRUE/FALSE

ISP_SUPPORT 		= TRUE		# TRUE/FALSE

BACKUP_SENSOR_SUPPORT = FALSE  # TRUE or FALSE

CMOS_SENSOR 		= OV7670	# MT9D011, 

CMOS_SENSOR_BAK1 = NONE  # NONE: not support backup sensor feature in main camera
                         # Others: sensor module name for backup sensor feature in main camera

CMOS_SENSOR_SUB_BAK1 = NONE  # NONE: not support backup sensor feature in sub camera
                             # Others: sensor module name for backup sensor feature in sub camera
                              # 6229 uses 2M sensor - MT9D011

SENSOR_ROTATE           = SENSOR_ROTATE_180    # SENSOR_ROTATE_0, SENSOR_ROTATE_90, SENSOR_ROTATE_180, SENSOR_ROTATE_270

SENSOR_SUB_ROTATE = SENSOR_ROTATE_0    # SENSOR_ROTATE_0 : sub camera not rotate
                                       # SENSOR_ROTATE_180: sub camera rotate 180 degree

SENSOR_LOCATION         = SENSOR_ON_BODY     # SENSOR_ON_BODY, SENSOR_ON_CLAM


PHB_SIM_ENTRY	=	100	# Phonebook Entry Number in SIM: 100, 200

PHB_PHONE_ENTRY	=	100	# Phonebook Entry Number in NVRAM: 100, 200

PHB_LN_ENTRY	=	20	# Call log; Last Number Entry Number: 10, 20, 50

EMAIL_SUPPORT           =  ALL   # NONE or  SMTP_POP3 or ALL

FS_SORT_SUPPORT		=  TRUE	  # Both file system and file manager will support sort function


FS_CHECKDRIVE_SUPPORT	= TRUE	  # Both file system and file manager will support check drive function
                                   # Drive more than 128MB should turn off this feature.

FS_QM_SUPPORT		=  TRUE	  # File system will support quota management mechanism

FS_TRACE_SUPPORT	=  FALSE  # File System will support trace function only if TST is supported


AEC_ENABLE              =  TRUE  # Acoustic Echo Cancellation (AEC)
                                  # TRUE, FALSE

EES_ENABLE              =  TRUE  # Enhanced Echo Suppression (EES)
                                  # TRUE, FALSE

BLUETOOTH_SUPPORT       = BTMTK_MT6612    # NONE, BTMTK, BTMTK_MT6601, BTMTK_MT6612

BLUETOOTH_VERSION       = BT_VER_21    # NONE, BT_VER_PRE21, BT_VER_21

CMUX_SUPPORT	        = FALSE   #

DIGIT_TONE_SUPPORT      = FALSE   # TRUE or FALSE

TTS                     = NONE    # SIMPLE_TTS, CYBERON_DIC_TTS, IFLY_TTS, SINOVOICE_TTS, NONE
					
CUST_KEYPAD_TONE_SUPPORT = FALSE  # TRUE or FALSE

MED_PROFILE             = MED_HIGH  # MED_LOW, MED_NORMAL, MED_HIGH, MED_MODEM

XML_SUPPORT             = TRUE    # TRUE or FALSE

AMR_LINK_SUPPORT        = TRUE    # TRUE or FALSE

IMPS_SUPPORT            =  FALSE  # TRUE or FALSE, IMPS Feature Support

TOUCH_PANEL_SUPPORT     = TP_INTERNAL   #  NONE, MT6301, MT6301B
                                 # touch panel feature  
DEMO_PROJECT		= FALSE   # TRUE, FALSE. TRUE for internal demo project.

GPRS_MAX_PDP_SUPPORT    = 2      # 2, 3, 4, 5, 6 or 7  Maximum simultaneous PDP contexts (2~7)

BT_CONNECT_TO_UART2   = FALSE      # TRUE, FALSE
                                   # TRUE: BT module is connected to UART2
                                   # FALSE: BT module is connected to UART3, this is general case for most projects

UART3_SUPPORT		= TRUE   # TRUE or FALSE,  SUPPORT UART 3

DMA_UART_VIRTUAL_FIFO   = TRUE   # TRUE or FALSE

DMA_UART_VFIFO_TUNNEL_SUPPORT = TRUE  # TRUE, FALSE

SIP_SUPPORT 	        = FALSE        # TRUE or FALSE

SDP_SUPPORT 	        = FALSE        # TRUE or FALSE

POC_SUPPORT = NONE  # NONE, V01, ALL

XDM_SUPPORT             = FALSE          # TRUE or FALSE

VOIP_SUPPORT            = FALSE     # TRUE, FALSE

PHONE_TYPE 		=  BAR      # BAR, CLAMSHELL, SLIDE  
                           #  Default is BAR

SWDBG_SUPPORT        = FALSE     # MT6228 support software debug 

NAND_FLASH_BOOTING   = ONDEMAND    # NONE, ENFB, ONDEMAND, MIXED
                                   # NONE: NORXIP Project and it's not NAND FLASH BOOTING
                                   # ENFB: MMI Images and string put on THIRD_ROM and dynmaic load into RAM by application. Default for MT6228/29/30
                                   # ONDEMAND: MMI Resource and Some Non-Real-Time App RO put on NAND and on-demand page in. 
                                   #           ARM9 MMU Required. Default for MT6235/38
                                   # MIXED: Both ENFB and On-Demand Page In mechanism enabled. ARM9 MMU Required. Pick this to support MBA Feature.

WMA_DECODE = FALSE              # MT6228 and MT6229 support WMA DECODE

LOW_COST_SUPPORT = NONE  # NONE, COMMON, ULC
                           #  Please not that a module can define its own low-cost levels, or it can just adopt this compile option.


SUB_LCD_SIZE = NONE # NONE, 48X64BW, 64X96, 96X64BW, 96X64, 128X128

MAIN_LCD_SIZE = 240X320                              # To distinguish the main lcd size. 
                                                                        # We can use it to copy the matching resources, such themecomponents.h, Fontres.c, L_xxx.h, etc, to PLUTO_MMI folder

MMI_MAIN_LCD_DEFAULT_FORMAT   = DEFAULT      # DEFAULT, 16, 24, 32

MMI_SUB_LCD_DEFAULT_FORMAT    = DEFAULT      # DEFAULT, 16, 24, 32


SUBLCD_DEDICATED_KEYS_SUPPORT = FALSE     # TRUE/FALSE
                                          # FALSE: No dedicated keys for subLCD operation
                                          # TRUE:  Have dedicated keys for subLCD when clam close, 
                                          # ex. KEY_MP3_PLAY_STOP, KEY_MP3_FWD, KEY_MP3_BACK

SINGLE_BANK_NOR_FLASH_SUPPORT   =  FALSE  # For low-cost (Flash size targetted at 16Mbits) single-bank NOR-flash solution, where partial of NVRAM is shadowed at RAM.

ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT = FALSE  # TRUE, FALSE For single-bank NOR-flash solution without shadowed NVRAM requirement.

AAC_PLUS_DECODE      = FALSE		# TRUE/FALSE

EMS_SUPPORT          = EMS_50   # EMS_40 support only EMS 4.0
                                # EMS_50 support EMS 5.0 
                                # EMS_NONE support only pure text content.

WEBCAM_SUPPORT       = TRUE      # TRUE, FALSE for WEB CAMERA support 


R4_SUPPORT      = FALSE   # Release 4 support

R5_SUPPORT      = FALSE   # Release 5 support

R99_SUPPORT	    		= TRUE	  # Release 99 support

EDGE_SUPPORT			= TRUE	  # EDGE support
 
CHE_SUPPORT          = TRUE    # CHE support

TV_OUT_SUPPORT 		= FALSE  # TRUE, FALSE  only MT6228 and MT6229 support TV OUT

BACKGROUND_SOUND	   = TRUE	  # TRUE/FALSE

AUDIO_3D_SURROUND     = MODE_EARP      # NONE, MODE_LSPK, MODE_EARP, MODE_BOTH
                                  # to enable 3D surround

AUDIO_POST_PROCESS   = ALL_EFFECT	  # NONE, ALL_EFFECT, REVERB_ONLY, TIME_STRETCH_ONLY

MOTION_SENSOR_SUPPORT = MXC6202_I2C  # NONE or KXP84_SPI or KXP84_I2C or KXP74_SPI or MXC6202_I2C
                                   # For motion sensor function support or not. 

LENS_MODULE 	     = NONE       # NONE, ABICO_VQ26A10_OV2640_AD5398, ABICO_WZ36A333_OV3640_MD118B, ACME_900_0043_00_OV3640_AD5398, 
                                                  # AOCI_BASAV0422_MT9T012_AD5398, AOCI_BTIAV0486_ET8EE6_MD115, FOXCONN_ATCM_5011_MT9P012_AD5820, 
                                                  # FOXLINK_FM30AF_13_L1_MT9T012_MD115, FOXLINK_FM50AF_04_MT9P012_MD218B, FOXLINK_FO20AF_25_OV2640_MD115, 
                                                  # FOXLINK_M30AF_26_OV3640_MD115, LITEONSEMI_DCM_300MAV_MT9T012_MD115, MCNEX_MC_20A2_05_MT9D011_ID9701, 
                                                  # MCNEX_MC300A_2IC1B0626_MT9T012_ID9701, MCNEX_MC320A_2JC1L0711_MT9T012_AD5398, NANOFOCUS_HSMW2_C04_AM7S_001_MT9D011_ID9700, 
                                                  # NANOFOCUS_NFMW3_C07_AM7M_004_MT9T012_AD5398, NANOFOCUS_NFMW3_S01_AM7M_002_MT9T012_ID9701,
                                                  # SANYO_ED_20MA_NOON200PC11_AD5398, SUNNY_8212E_OV2640_AD5398, YAHSIN_M20P1A_BGK_OV2640_MD115

LENS_MODULE_BAK1 = NONE  # NONE:  not support AF lens backup sensor feature in main camera
                         # Others: AF lens module name for backup sensor feature in main camera

AF_SUPPORT           = FALSE	  # TRUE/FALSE

DT_SUPPORT           = TRUE      # TRUE, FALSE

CTM_SUPPORT          = FALSE     # TRUE, FALSE 


M3D_MMI_SUPPORT      = FALSE     # TRUE, FALSE

LCM_ROTATE_SUPPORT   = FALSE     # TRUE, FALSE

BT_SIM_PROFILE = FALSE      # TRUE, FALSE

BT_HIDD_PROFILE      = TRUE      # TRUE, FALSE       
                                  # Turn on or turn off bluetooth HID profile feature

BT_HFG_PROFILE       = TRUE      # TRUE, FALSE

BT_FTS_PROFILE       = TRUE      # TRUE, FALSE

BT_FTC_PROFILE       = TRUE      # TRUE, FALSE

BT_OPP_PROFILE       = TRUE      # TRUE, FALSE

BT_DUN_PROFILE       = TRUE      # TRUE, FALSE


BT_SPP_SERVER        = BT_SPP_SRV_NO_SCO        # NONE, BT_SPP_SRV_NO_SCO or BT_SPP_SRV_WITH_SCO (default:BT_SPP_SRV_NO_SCO)
                                  # This is only used in BLUETOOTH_SUPPORT = BTMTK_MT6601
                                  # If BLUETOOTH_SUPPORT is not BTMTK_MT6601, its value must be NONE

BT_SPP_CLIENT        = NONE       # NONE, BT_SPP_CLI_NO_SCO or BT_SPP_CLI_WITH_SCO (default: NONE)
                                  # This is only used in BLUETOOTH_SUPPORT = BTMTK_MT6601
                                  # If BLUETOOTH_SUPPORT is not BTMTK_MT6601, its value must be NONE


BT_SPP_PROFILE       = TRUE      # TRUE, FALSE

BT_A2DP_PROFILE      = TRUE      # TRUE, FALSE

BT_AVRCP_PROFILE     = TRUE      # TRUE, FALSE 
                                  # Turn on or off AVRCP profile feature

BT_AUDIO_VIA_SCO     = TRUE     # TRUE, FALSE 
                                 # Support Audio being passed by BT SCO Link. 

BT_FM_RADIO_VIA_SCO  = TRUE     # TRUE, FALSE 
                                 # Support FM Radio being passed by BT SCO Link

SVG_SUPPORT = NONE  # NONE, MTK_SVG, IKIVO_DEMO, IKIVO_SVG12, IKIVO_SVG12_WITH_SCRIPT_ENGINE
                                 # support SVG image format

WIFI_SUPPORT = NONE  # NONE, MT5911, MT5921

WIFI_WIZARD_SUPPORT = TRUE   # TRUE or FALSE


IPERF_SUPPORT        = NONE  	 #  SINGLE, DUAL, TRIPLE, QUAD, NONE


OPENGL               = COMMON_LITE     # COMMON_LITE, NONE
                                 # This compile option is defined for 3D graphics engine.
                                 # Only MT6228 and MT6229 support OPENGL.

USB_MULTI_CHARGE_CURRENT_SUPPORT = FALSE  # TRUE, FALSE 
                                          # Turn On or Off USB multiple charging-current support

RC5_SUPPORT          = TRUE      # TRUE or FALSE, RC5 feature support

GAME_ENGINE          = NONE      # NONE, GE_BROGENT
                                 # to add game engine 


EXT_DAC_SUPPORT      = FALSE     # TRUE, FALSE
                                 # To enable the interface between AFE control and EXT_DAC control.

UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE = FALSE  # TRUE, FALSE

UNIFIED_MESSAGE_SORT_MESSAGE_LIST = FALSE	# TRUE, FALSE

UNIFIED_MESSAGE_SUPPORT  = FALSE # TRUE or FALSE, unified message support
                                 # GSM project can NOT support UNIFIED_MESSAGE

DRV_CUSTOM_TOOL_SUPPORT  = TRUE # TRUE or FALSE, To enable using driver customization tool for GPIO/EINT/ADC/UEM/Keypad setting.


WAP_SUPPORT          = OBIGO_Q03C   # NONE, OBIGO_Q03C, OBIGO_Q05A

WAP_MEM_DEBUG = TRUE  # TRUE or FALSE
					
DSPIRDBG             = FALSE      # IRDBG interface for dsp debugging
                                 # only support in 6229 E2

BARCODE_DECODER     = NONE       #  NONE, SCANBUY_QRDM, SCANBUY, GMEDIA_QRDM, MMI_ONLY
					
SECURE_SUPPORT      = FALSE       #

SECURE_VERSION      = 1          #

SECURE_JTAG_ENABLE  = FALSE       #

SECURE_CUSTOM_NAME  = MTK        # MTK (6227C/6225 EVB) or JRD (JRD_06A) 

SECURE_RO_ENABLE    = FALSE       # TRUE, FALSE

DISPLAY_TYPE        = COLOR      # BW, COLOR

OTP_SUPPORT         = FALSE      # TRUE, FALSE

SW_FLASH           = NONE    # NONE, NEOMTEL

SYNCML_SUPPORT                   = TRUE        # TRUE or FALSE

SYNCML_DEVICE_SYNC_SUPPORT = TRUE  # TRUE, FALSE

UNIFIED_MESSAGE_ADVANCE_FEATURE = NONE  	# Unified message advance feture:
                                                       # NONE, COMPOSER, LISTOPTION, ARCHIVE, 
                                                       # COMPOSER_LISTOPTION, COMPOSER_ARCHIVE, LISTOPTION_ARCHIVE, COMPOSER_LISTOPTION_ARCHIVE
                                                       # Only support when unified message feature is turned on.

STREAM_SUPPORT   =   FALSE   # TRUE or FALSE

PGDL_SUPPORT  =  FALSE          # TRUE or FALSE

RTSP_SUPPORT = FALSE            # TRUE or FALSE

FOTA_ENABLE = NONE   # FOTA_DM, NONE

FOTA_UPDATE_PACKAGE_ON_NAND = FALSE    # TRUE or FALSE

SYNC_LCM_SUPPORT = FALSE         # TRUE or FALSE 
                                 # TRUE if Sync mode LCM is applied and FALSE if Sync mode LCM is applied.
                           
FEATURE_OVERLOAD = FALSE         # TRUE or FALSE  
                                 # TRUE : turn on bypassing 
                                 # FLASE : turn off bypassing
                         
AAC_PLUS_PS_DECODE = FALSE       # TRUE, FALSE                                                    

VDOEDT_SUPPORT     = FALSE       # TRUE, FALSE    

OPTR_SPEC               = NONE   # NONE, CMCC_0202_SEGA, CMCC_0202_SEGB, CMCC_0202_SEGC, CMCC_0202_SEGA_TECH, CMCC_0202_SEGB_TECH, CMCC_0202_SEGC_TECH, ORANGE_0605_CAM240, INDIA_0100_SEGB, VODAFONE_R12_LIVE
                                 # CMCC_0203_SEGA, CMCC_0203_SEGB, CMCC_0203_SEGC, CMCC_0203_SEGD, CMCC_0203_SEGE, CMCC_0203_SEGA_TECH, CMCC_0203_SEGB_TECH, CMCC_0203_SEGC_TECH, CMCC_0203_SEGD_TECH, CMCC_0203_SEGE_TECH


SYNCML_DM_SUPPORT       = FALSE  # TRUE or FALSE

VIRTUAL_PORTS_NUM       = 5      # default is 5, maximum is 9

SPATIAL_DITHERING       = TRUE   # TRUE or FALSE
                                 # support by MT6225, MT6228, MT6229 and MT6230

PICTBRIDGE_SUPPORT      = TRUE  # TRUE or FALSE, IMPS Feature Support
					
TDMB_SUPPORT            = NONE       # NONE, TELECHIP_TDMB, FRONTIER_TDMB    

WBXML_SUPPORT   = TRUE		# TRUE or FALSE
					
ISO_PRIORITY_MODE_SUPPORT = FALSE   # FALSE, TRUE
					
KEYPAD_TYPE             = NORMAL_KEYPAD#QWERTY_KEYPAD   NORMAL_KEYPAD, REDUCED_KEYPAD					

FLASHLIGHT_TYPE         = LED_ONOFF_SUPPORT           # NONE, LED_ONOFF_SUPPORT, LED_FLASHLIGHT_SUPPORT, XENON_FLASHLIGHT, XENON_FLASHLIGHT_ANTI_RED_EYE

FLASHLIGHT_MODULE       = NONE     # NONE, IMCR3603_S010AO


TOUCH_PANEL_SHORTCUT_SUPPORT   = FALSE         # FALSE, TRUE
                                               # TRUE for  touch panel size need to be larger than LCD size
                                               # Support touch panel shortcut functionality 

LANGLN_ENGINE                  =  NONE         # NONE, LANGLN_DIGIDEA
                                               # Add compile option for language learning application

GIS_SUPPORT                    = NONE         # NONE, SUNAVI, MAPBAR_NAVI, MAPBAR_BUS
                                               # Add compile option for GIS application


SSL_SUPPORT             = NONE   # NONE, SSL_CIC_LIB, MTK_SSL_CIC, OPENSSL, OPENSSL_MTK

SOCKET_SSL_SUPPORT = FALSE  # TRUE, FALSE

SECLIB_SUPPORT = NONE # NONE, BASIC, PKI
                      # NONE: disable security library
                      # BASIC: enable security library
                      # PKI: enable OpenSSL library

SYSGEN_ENABLE         = FALSE         # FALSE, TRUE
                                   
BACKGROUND_SMS_SUPPORT = FALSE		     # TRUE or FALSE                                    

PURE_AUDIO_SUPPORT      = FALSE         # TRUE or FALSE 
                                       # Support pure audio 3GP/MP4 file in audio player
 
 
GPS_SUPPORT           = NONE       # NONE, MT3316, MT3326

CSD_SUPPORT       =  T_NT       # CSD Feature,   NONE : NOT support CSD feature
                                #                T_NT : Support both Transparent and Non-transparent mode.
                                #                NT_ONLY: Support Non-Transparent mode only.

FAX_SUPPORT           = TRUE       # TRUE, FALSE

FONT_RESOURCE         = OFFICIAL   # DEMO, OFFICIAL

 
AUDIO_EQ_ENABLE           = TRUE # TRUE, FALSE

AUDIO_COMPENSATION_ENABLE = TRUE  # TRUE, FALSE

BSAC_DECODE = FALSE # TRUE, FALSE

INTERNAL_ANTENNAL_SUPPORT = FALSE  # TRUE, FALSE

BT_GPS_SUPPORT = FALSE  # TRUE, FALSE
                        # FALSE:  Don't support the phone connect GPS via bluetooth
                        # TRUE: Support the phone connect GPS via bluetooth

EMLPP_SUPPORT = FALSE  # TRUE, FALSE
                       # TRUE: CC EMLPP  feature is supported
                       # FALSE: CC EMLPP  feature is NOT supported

	
UUS_SUPPORT = FALSE  # TRUE, FALSE
                     # TRUE: CC User-User Service feature is supported
                     # FALSE: CC User-User Service feature is NOT supported

H264_DECODE         = NONE     # NONE, H264_HW, H264_SW


DCD_SUPPORT = NONE    # INFRAWARE, NONE

SENSOR_TYPE = YUV    # RAW, YUV, DIRECT, NONE

FM_RADIO_HW_SEARCH = FALSE    # TRUE, FALSE

BT_FAX_PROFILE = TRUE  # TRUE, FALSE

IC_TEST_TYPE = NONE  # NONE, IC_MODULE_TEST, IC_BURNIN_TEST
                                
RSAT_SUPPORT = NONE  # NONE, MODEM_WITH_RSAT, MMI_WITH_RSAT


CAMCORDER_SUPPORT = NONE  # NONE, FULL, SLIM, STANDARD, CUSTOM

AUD_RECORD = TRUE          # TRUE, FALSE : Turn on audio record feature, olny set to FALSE for very low cost project

AIFF_DECODE = FALSE  # TRUE, FALSE
                                
AU_DECODE = FALSE  # TRUE, FALSE
                                
BT_BIP_PROFILE = TRUE  # TRUE, FALSE
                                
BT_BPP_PROFILE = TRUE  # TRUE, FALSE
                                
DOWNLOADABLE_THEME = FALSE  # TRUE, FALSE
                                
EXIF_SUPPORT = FALSE  # TRUE, FALSE
                                
FM_RADIO_RECORD = TRUE  # TRUE, FALSE
                                
JTONE_SUPPORT = TRUE  # TRUE, FALSE
                                
UNIFIED_MESSAGE_SIMBOX_SUPPORT = FALSE  # TRUE, FALSE
                                
DLT_ALWAYS_LOAD_BUFFER_SIZE = 0
                                
DLT_LOAD_ON_DEMAND_BUFFER_SIZE = 0
                                
CBM_ALWAYS_ASK_SUPPORT = TRUE  # TRUE or FALSE

CBM_CONNECTION_MANAGER_SUPPORT = TRUE  # TRUE or FALSE

CBM_BEARER_FALLBACK_SUPPORT = FALSE  # TRUE or FALSE


MULTIPLE_BINARY_FILES = FALSE  # FALSE, TRUE

BT_PBAP_PROFILE = FALSE  # TRUE or FALSE

AGPS_SUPPORT = NONE  # NONE, USER_PLANE, CONTROL_PLANE, BOTH

OMA_ULP_SUPPORT = V1  # NONE, V1, V1.5, V2

NDIS_SUPPORT = FALSE  # TRUE or FALSE, NDIS Feature Support

DISABLE_A5_2 = TRUE  # TRUE, FALSE

CAMCORDER_FACE_DETECTION_MODE_SUPPORT = FALSE  # TRUE, FALSE

REDUCE_PLUTO_HEADER_DEPTH = TRUE  # TRUE, FALSE

UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT = FALSE  # TRUE, FALSE

MSG_SMS_EMAIL_SUPPORT = FALSE  # TRUE, FALSE

WAV_CODEC = TRUE  # TRUE, FALSE

AMR_CODEC = TRUE  # TRUE, FALSE

CCBS_SUPPORT = TRUE  # TRUE, FALSE

CNAP_SUPPORT = TRUE  # TRUE, FALSE

TST_LOGACC_SUPPORT = FALSE  # TRUE, FALSE

MODEM_3G_LOGGING = FALSE  # TRUE, FALSE

EXT_MODEM_SUPPORT = FALSE  # TRUE, FALSE

MMS_SUPPORT = OBIGO_Q03C_MMS_V01  # OBIGO_Q03C_MMS_V01, OBIGO_Q03C_MMS_V02, NONE

MMS_FEATURES = FULL  # NONE, SLIM, FULL

SMS_PHONE_ENTRY = 200  # SMS Entry Number in NVRAM: 200

SMS_TOTAL_ENTRY = 200  # SMS Entry Number in NVRAM and SIM: 200 (>=SMS_PHONE_ENTRY)

LQT_SUPPORT = FALSE  # FALSE, TRUE


BT_SEQ_SUPPORT = TRUE  # FALSE, TRUE

MP4_DECODE = MP4_SW    # NONE, MP4_HW, MP4_SW

MP4_DECODE_MODE = NORMAL  # NORMAL, SLIM, NONE

MP4_ENCODE = MP4_SW    # NONE, MP4_HW, MP4_SW

SECURE_PORT_SUPPORT = FALSE  # TRUE, FALSE

IPSEC_SUPPORT = FALSE  # FALSE, IPSEC_IKEv1

BIP_SCWS_SUPPORT = FALSE  # TRUE, FALSE


FONT_ENGINE = FONT_ENGINE_FREETYPE_DEMO  # NONE, FONT_ENGINE_MONOTYPE, FONT_ENGINE_MONOTYPE_DEMO, FONT_ENGINE_FREETYPE, FONT_ENGINE_FREETYPE_DEMO, FONT_ENGINE_WTLE

FS_SORT_MAX_ENTRY = 20000  # 64 ~ 256 or 20000

CMMB_SUPPORT = NONE  # NONE, INNOFIDEI_IF201, TELEPATH_TP3001B, INNOFIDEI_IF202

CMMB_CAS_FULL_CARD_SUPPORT = FALSE  # TRUE, FALSE

SQLITE3_SUPPORT = TRUE  # TRUE, FALSE

MONZA2G = TRUE  # TRUE, FALSE

FRM_BKWD_COMP_SUPPORT = TRUE  # TRUE, FALSE

GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO = TRUE  # TRUE, FALSE

GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND = TRUE  # TRUE, FALSE

MULTIPLE_PPP_DIALUP_SUPPORT = FALSE  # TRUE/FALSE, Enable/Disable Multiple PPP GPRS Dialup support

MAX_NUM_OF_PPP_DIALUP_SUPPORT = 3  # 2,3 
                                   # This MAX_NUM_OF_PPP_DIALUP_SUPPORT value only works when MULTIPLE_PPP_DIALUP_SUPPORT = TRUE
                                   # valid values: 2,3
                                   # The value of MAX_NUM_OF_PPP_DAILUP_SUPPORT must <= GPRS_MAX_PDP_SUPPORT

BCR_SUPPORT = NONE  # NONE, PENPOWER

MEDIA_PLAYER_VER = SEPARATED  # SEPARATED, INTEGRATED, INTEGRATED_DB
                              # SEPARATED : Seperate audio player and video player
                              # INTEGRATED : Integrated media player
                              # INTEGRATED_DB : Integrated media player using SQL database

BACKGROUND_CALL_SUPPORT = FALSE  # TRUE, FALSE

MULTIPLE_NDIS_SUPPORT = FALSE    # TRUE/FALSE, Enable/Disable Multiple PPP GPRS Dialup support
                                 # MULTIPLE_NDIS_SUPPORT only works when NDIS_SUPPORT = TRUE

MAX_NUM_OF_NDIS_SUPPORT = 3 	 # 2,3 
                                 # This MAX_NUM_OF_NDIS_SUPPORT value only works when MULTIPLE_NDIS_SUPPORT = TRUE
                                 # valid values: 2,3
                                 # The value of MAX_NUM_OF_PPP_DAILUP_SUPPORT must <= GPRS_MAX_PDP_SUPPORT

AF_AUXI_LED_SUPPORT = FALSE    # TRUE, FALSE

NVRAM_PSEUDO_MERGE = OFF    # ON, OFF

UDX_SUPPORT = FALSE    # TRUE, FALSE

DRA_DECODE = FALSE    # TRUE, FALSE

SMS_R8_NATION_LANGUAGE = TRUE    # TRUE/FALSE, to support Turkish letter in SMS

SMS_R8_TABLE_MECHANISM = SMS_R8_AUTO   #SMS_R8_DEFAULT or SMS_R8_LOCKING or SMS_R8_SINGLE or SMS_R8_BOTH or SMS_R8_AUTO

AUDIO_LOUDNESS = LOUDSPEAKER  # NONE, LOUDSPEAKER, LOUDSPEAKER_RINGTONE

AUDIO_BASS_ENHANCEMENT = TRUE  # TRUE, FALSE

UCWEB_SUPPORT = NONE  # NONE, UCWEB6

MSHUTTER_SUPPORT = FALSE  # TRUE, FALSE

PANORAMA_VIEW_SUPPORT = FALSE  # TRUE, FALSE

GPS_BEE_SUPPORT = FALSE  # TRUE, FALSE

QQIM_SUPPORT = FALSE  # TRUE, FALSE

PMU_WITH_EXTERNL_CHARGER = FALSE  # TRUE, FALSE


A8BOX_SUPPORT = FALSE  # TRUE, FALSE

MELODY_BUFFER_LEN = 102400  # 102400, 307200, 1300, 1024, 512

GGLIVE_SUPPORT = FALSE  # TRUE, FALSE

SMART_PHONE_CORE = NONE  # NONE: feature phone
                         # MODEM: smart phone modem
                         # AP: smart phone AP
                                
DUAL_CAMERA_SUPPORT = FALSE  # TRUE: enable dual camera support
                             # FALSE: disable dual camera support

CMOS_SENSOR_SUB = NONE       # NONE: no sub camera sensor module
                             # other supported sensor module name

SENSOR_TYPE_SUB = NONE       # RAW: raw type sub camera sensor module
                             # YUV : yuv type sub camera sensor module
                             # NONE: not support sub camera
                               
SIM_PROVISIONING = MMSICP  # NONE, MMSICP

KURO_SUPPORT = NONE	# NONE, OFFICIAL, MTK_INTERNAL

STREAM_REC_SUPPORT = FALSE  # TRUE, FALSE

VENDOR = NONE  # NONE, DEFAULT, XXX(for XXX_VENDOR)
	
MTP_SUPPORT = TRUE  # TRUE, FALSE

UMTS_BAND_I    = FALSE  # TRUE, FALSE
UMTS_BAND_II   = FALSE  # TRUE, FALSE
UMTS_BAND_III  = FALSE  # TRUE, FALSE
UMTS_BAND_IV   = FALSE  # TRUE, FALSE
UMTS_BAND_V    = FALSE  # TRUE, FALSE
UMTS_BAND_VI   = FALSE  # TRUE, FALSE
UMTS_BAND_VII  = FALSE  # TRUE, FALSE
UMTS_BAND_VIII = FALSE  # TRUE, FALSE
UMTS_BAND_IX   = FALSE  # TRUE, FALSE
UMTS_BAND_X    = FALSE  # TRUE, FALSE

JOGBALL_SUPPORT = FALSE  # TRUE, FALSE

E_COMPASS_SENSOR_SUPPORT = NONE  # NONE, AMI304_I2C

SYNCML_PC_SYNC_SUPPORT = TRUE  # TRUE or FALSE

POWERONOFF_BY_POWERKEY = FALSE  # TRUE or FALSE

# Vogins Start
VRE_SUPPORT = VRE_V30     # NONE, VRE_V20, VRE_V21, VRE_V30

VRE_MEMORY_SOURCE = ASM  # ASM, MED

VRE_MEMORY_SIZE = 3072  # 600, 800, 1536, 2048, 3072

VRE_DEFAULT_GAME = FALSE # TRUE, FALSE

VRE_MTK_BRANCH = MTK_09A

VRE_LOG_ENABLE = FALSE

VRE_CIPHER_UA = TRUE

VRE_USER_AGENT_COMPANY = NONE

VRE_USER_AGENT_PROJECT = NONE

VRE_OVERSEA_VERSION = FALSE
# Vogins End

IMAGE_VIEWER_VER = EX_DB  # STANDARD, EX, EX_DB, NONE

3SET_F8F9_ENABLE = FALSE  # TRUE or FALSE

GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP = FALSE  # TRUE or FALSE

CMMB_CAS_SMD_SUPPORT = FALSE  # TRUE or FALSE

BITSTREAM_SUPPORT = TRUE  # TRUE or FALSE

SW_VIDEO_RESIZER = NONE  # NONE, IP, DD

VENUS_MMI = VENUS_LEVEL1   # NONE, VENUS_LEVEL1

PRODUCTION_RELEASE	= TRUE	  # Production release feature includs autoreset when system hang
# below macro definition is for dual mode
GEMINI_WIFI_COEXIST = FALSE

SWITCHABLE_FEATURE = GEMINI

SWITCHABLE_FEATURE_2ND = WIFI_SUPPORT

DUAL_MODE_SUPPORT = GEMINI # MASTER, SLAVE, NONE, 
                           # GEMINI: Single chip dual card solution


SENDKEY_MODE = SENDKEY2_SUPPORT # SINGLE_KEY_SELECT_MENU   SENDKEY2_SUPPORT
                                      # SINGLE_KEY_SELECT_MENU only one sendkey will popup a menu to select dail card1 or card2
                                      # SENDKEY2_SUPPORT  two sendkeys the one is for card1 and the other is for card2

MERCURY_SLAVE_BT_SUPPORT = TRUE # TRUE or FALSE

GEMINI = TRUE

SINGLE_SIM_MMI_ONLY = FALSE # SINGLE_SIM_MMI_ONLY = TRUE/FALSE
                            # SINGLE_SIM_MMI_ONLY = TRUE : Use single SIM MMI
                            # SINGLE_SIM_MMI_ONLY = FALSE : Use dual SIM MMI

FLAVOR = NONE  # FLAVOR = NONE/$(FLAVOR)
               # FLAVOR = NONE: No flavor name was used.
               # FLAVOR = $(FALVOR): A flavor name $(FLAVOR) was used and a compile option __FLAVOR_$(FLAVOR)__ was defined.
               # __FLAVOR_$(FLAVOR)__ will be used in MMI feature files.

# *************************************************************************
# Release Setting Section
# *************************************************************************
RELEASE_PACKAGE = REL_CR_MMI_gprs # REL_CR_MMI_GPRS, REL_CR_MMI_GSM, REL_CR_L4_GPRS, REL_CR_L4_GSM

RELEASE_WAE		= SRC		# MTK/SRC, only works when TELECA_FEATURES works
RELEASE_WAP		= MTK		# MTK/SRC, only works when TELECA_FEATURES works
 
RELEASE_$(strip $(INPUT_METHOD)) = SRC	# MTK/SRC, only works when INPUT_METHOD is turning on
RELEASE_INPUT_METHODS_SRC =		# MMI_ZI, MMI_T9, MMI_ITAP,

# *************************************************************************
# Consistent Feature Options
# *************************************************************************
#COM_DEFS_FOR_LIBRA35_DEMO_MT6140D = MT6140D_RF LIBRA35_DEMO_MT6140D
COM_DEFS_FOR_KCMSZ35_09A_GEMINI_LCM = KCMSZ35_09A_GEMINI_LCM TFT_MAINLCD
# *************************************************************************
# Include MODEM.mak
# *************************************************************************
include make\MODEM.mak

# *************************************************************************
# Project specified preprocessor definitions
# *************************************************************************

CUSTOM_OPTION += BIDI_SUPPORT __MSDC_NOT_SUPPORT_HOT_PLUG__ __MSDC_NO_WRITE_PROTECT__

CUSTOM_OPTION += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ __TWO_KEY_DETECTION_SWITCHABLE__
# *************************************************************************
# Custom Release Component Configuration
# *************************************************************************
include make\$(strip $(RELEASE_PACKAGE)).mak
#

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
EXISTED_CUS_REL_TRACE_DEFS += media\common\include\med_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += btadp\include\bluetooth_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += wifi\wndrv\mt5921\include\os\wndrv_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += drv\include\drv_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += usb\include\usb_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\sim\include\sim_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += bmt\bmt_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += nvram\include\nvram_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\include\l4_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\phb\include\phb_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\l4\uem\include\uem_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += l1audio\inc\l1sp_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += media\vcodec\include\vcodec_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += ps\dt\include\dt_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += vendor\wap\obigo_q03c\adaptation\integration\include\wap_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += venusmmi\pluto_adapter\interface\trc\vadp_sys_trc.h 
EXISTED_CUS_REL_TRACE_DEFS += venusmmi\pluto_adapter\interface\trc\vadp_app_trc.h 
 
# Customer can add new trace headers here for new modules 
NEW_CUS_REL_TRACE_DEFS = 
