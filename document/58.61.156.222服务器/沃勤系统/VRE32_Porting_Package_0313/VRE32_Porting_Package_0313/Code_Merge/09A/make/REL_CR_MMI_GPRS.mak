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

# *************************************************************************
# Custom Release Component Configuration
# *************************************************************************
# Be sure the following:
#    1. COMPLIST(for CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
#    2. CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP + CUS_REL_MTK_COMP = COMPLIST(CUSTOM_RELEASE = False)

CUS_REL_OPTION_FILTER   = TRUE
CUS_REL_HISTORY_FILTER  = TRUE

CUS_REL_BASE_COMP       =
CUS_REL_SRC_COMP        =
CUS_REL_PAR_SRC_COMP    =
CUS_REL_HDR_COMP        =
CUS_REL_MTK_COMP        =
CUS_REL_FILES_LIST      =
CUS_REL_OBJ_LIST        =
NON_REL_FILES_LIST      =
NON_REL_DIRS_LIST       =

# Forbidden feature
ifdef CHIP_VERSION_CHECK
  ifneq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
    $(error Please set CHIP_VERSION_CHECK as TRUE !!)
  endif
endif

# Different Release Levels for plutommi/lcmmi related components
# LEVEL1:      Customer can change ~50% image files and view on PC simulator
# LEVEL2_OBJ:  Customer can change some resources and use PC simulator and Network simulator
# LEVEL2_SRC:  Customer will have the source code of PC simulator and Network simulator

ifndef LEVEL
  LEVEL = LEVEL2_SRC
endif

ifndef MMI_BASE
  MMI_BASE = PLUTO_MMI
  MMIDIR         =  plutommi
else
  ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    MMIDIR         =  lcmmi
  else
    MMIDIR         =  plutommi
  endif
endif

MMI_PROJ = $(strip $(subst _MMI,,$(MMI_VERSION)))

ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL1)
   ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
     CUS_REL_BASE_COMP	   +=
     CUS_REL_SRC_COMP     += lcmmiresource
     CUS_REL_MTK_COMP     += lcmmi lcmtkapp
   else
     CUS_REL_BASE_COMP   += plutommi\WIN32FS
     CUS_REL_SRC_COMP    += mmiresource vendorapp gdi_arm
     CUS_REL_MTK_COMP    += plutommi
   endif
else
  ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
      ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
        CUS_REL_BASE_COMP	   += plutommi\WIN32FS
        CUS_REL_SRC_COMP     += lcmmiresource
        CUS_REL_MTK_COMP     += lcmmi lcmtkapp
      else
        CUS_REL_BASE_COMP  += plutommi\WIN32FS
        CUS_REL_SRC_COMP   += mmiresource vendorapp gdi_arm
        CUS_REL_MTK_COMP   += plutommi
      endif
  else
    ifeq ($(strip $(call Upper,$(LEVEL))),LEVEL2_SRC)
    
  ifdef SUB_LCD_SIZE
    ifneq ($(strip $(SUB_LCD_SIZE)),NONE)
      ifeq ($(strip $(call Upper,$(EMPTY_RESOURCE))),FALSE)
        ifeq ($(findstring BW,$(strip $(SUB_LCD_SIZE))),BW)
          SUB_MMI_PRJ := SubLCDBW$(strip $(subst BW,,$($(SUB_LCD_SIZE))))
          CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(SUB_MMI_PRJ))
        else
          SUB_MMI_PRJ := SubLCD$(strip $(SUB_LCD_SIZE))
          CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(SUB_MMI_PRJ))
        endif
      endif
    endif
  endif

   	   CUS_REL_BASE_COMP	   += $(strip $(MMIDIR))\mmi $(strip $(MMIDIR))\mtkapp $(strip $(MMIDIR))\tool $(MMIDIR)\WIN32FS
   	   CUS_REL_BASE_COMP	   += $(strip $(MMIDIR))\Customer\CustomerInc \
                           		$(strip $(MMIDIR))\Customer\Customize \
                           		$(strip $(MMIDIR))\Customer\CustResource\$(strip $(MMI_VERSION)) \
                           		$(strip $(MMIDIR))\Customer\debug \
                           		$(strip $(MMIDIR))\Customer\Images\GameImages \
                           		$(strip $(MMIDIR))\Customer\Images\decoder \
                           		$(strip $(MMIDIR))\Customer\Res_MMI \
                           		$(strip $(MMIDIR))\Customer\ResGenerator \
                           		$(strip $(MMIDIR))\Customer\ResourceDLL \
                           		$(strip $(MMIDIR))\Customer\Resources \
                           		$(strip $(MMIDIR))\Customer\Audio

      ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
        ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
          CUS_REL_SRC_COMP  += mmi
          CUS_REL_MTK_COMP  +=
        else  
          CUS_REL_SRC_COMP     += lcmmiresource lcmtkapp lcmmi
          CUS_REL_BASE_COMP    += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(DISPLAY_TYPE))$(strip $(MAIN_LCD_SIZE))
          CUS_REL_MTK_COMP     +=
        endif
      else
        ifeq ($(strip $(MMI_BASE)),PLUTO_MMI)
          ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
            CUS_REL_SRC_COMP  += mmi
            CUS_REL_MTK_COMP  +=
          else
            CUS_REL_SRC_COMP  += mmiresource plutommi vendorapp gdi_arm
            IMAGE_FOLDER = $(shell dir $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(MAIN_LCD_SIZE)) /b 2>nul)
            ifeq ($(words $(IMAGE_FOLDER)),0)
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))
            else
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))$(strip $(MAIN_LCD_SIZE))
            endif
            ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128)
              CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_PROJ))
            endif
            CUS_REL_MTK_COMP  +=
          endif
        endif
      endif
    endif
  endif
endif

include make\REL_COMMON.mak

ifdef RELEASE_BASE_COMP
  CUS_REL_BASE_COMP += $(RELEASE_BASE_COMP)
endif

CUS_REL_BASE_COMP +=  tools MoDIS\filesystem

CUS_REL_BASE_COMP += interface\hwdrv

CUS_REL_SRC_COMP  +=  custom drv bmt \
                      nvram l4misc \
                      fs verno

ifdef SMART_PHONE_CORE
  ifeq ($(strip $(SMART_PHONE_CORE)),WM_MODEM)
    CUS_REL_SRC_COMP  +=  l1audio_sp
  else
    CUS_REL_SRC_COMP  +=  l1audio media applib
    CUS_REL_MTK_COMP  +=  ems l1audio_secure l1audio32
  endif
else
  CUS_REL_SRC_COMP  +=  l1audio l1audio32 media applib
  CUS_REL_MTK_COMP  +=  ems l1audio_secure
endif


ifdef CUSTOM_OPTION
  ifeq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
     CUS_REL_SRC_COMP += fmt
  endif
else
  $(error Please define CUSTOM_OPTION before include release package make file in project make file )
endif

ifeq ($(strip $(MONZA2G)),TRUE)
  CUS_REL_PAR_SRC_COMP +=  l1_classb_g2
else
  CUS_REL_PAR_SRC_COMP +=  l1_classb
endif

CUS_REL_PAR_SRC_COMP +=  init kal mtkdebug

ifdef GPS_SUPPORT
  ifneq ($(strip $(GPS_SUPPORT)),NONE)
    CUS_REL_PAR_SRC_COMP +=  gps
    ifeq ($(strip $(GPS_SUPPORT)),MT3326)
      CUS_REL_SRC_COMP += mnl
    endif
  endif
endif

ifdef BT_GPS_SUPPORT
  ifneq ($(strip $(BT_GPS_SUPPORT)),FALSE)
    CUS_REL_PAR_SRC_COMP +=  gps
  endif
endif

ifdef GIS_SUPPORT
  ifneq ($(strip $(GIS_SUPPORT)),NONE)
    CUS_REL_PAR_SRC_COMP +=  gis
  endif
  ifeq ($(strip $(GIS_SUPPORT)),SUNAVI)
    CUS_REL_BASE_COMP += vendor\gis\sunavi
  endif
  ifeq ($(strip $(GIS_SUPPORT)),MAPBAR_NAVI)
    CUS_REL_BASE_COMP += vendor\gis\mapbar
  endif  
  ifeq ($(strip $(GIS_SUPPORT)),MAPBAR_BUS)
    CUS_REL_BASE_COMP += vendor\gis\mapbar
  endif
  ifeq ($(strip $(GIS_SUPPORT)),MIGO)
    CUS_REL_BASE_COMP += vendor\gis\migo
  endif
endif

ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
        CUS_REL_MTK_COMP += supl
        CUS_REL_MTK_COMP += rrlp
endif
ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
        CUS_REL_MTK_COMP += rrlp
endif
ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
        CUS_REL_MTK_COMP += supl
        CUS_REL_MTK_COMP += rrlp
endif

CUS_REL_MTKDEBUG_PAR_SRC_LIST = mtkdebug\kal_debug_sysdebug_task.c \
                                mtkdebug\mtkkal_debug.c

CUS_REL_KAL_PAR_SRC_LIST = kal\Efs\src\fs_internal.c \
                           kal\Efs\src\fs_func.c

CUS_REL_L1_CLASSB_PAR_SRC_LIST = l1\l1d\l1d_data.c \
                                 l1\l1c\idle_task.c
                                 
CUS_REL_L1_CLASSB_G2_PAR_SRC_LIST = l1_dm\l1d\l1d_data.c \
                                    l1_dm\l1c\idle_task.c

ifneq ($(strip $(PLATFORM)),MT6253)
  CUS_REL_L1_CLASSB_PAR_SRC_LIST += l1\l1d\m12190.c \
                                    l1\l1d\m12191.c \
                                    l1\l1d\m12192.c \
                                    l1\l1d\m12194.c \
                                    l1\l1d\m12195.c \
                                    l1\l1d\m12196.c
  CUS_REL_L1_CLASSB_G2_PAR_SRC_LIST += l1_dm\l1d\m12190.c \
                                       l1_dm\l1d\m12191.c \
                                       l1_dm\l1d\m12192.c \
                                       l1_dm\l1d\m12194.c \
                                       l1_dm\l1d\m12195.c \
                                       l1_dm\l1d\m12196.c
endif

CUS_REL_INIT_PAR_SRC_LIST = init\src\init.c \
                          init\src\bootarm.s \
                          init\src\cp15.s \
                          init\src\emi.c \
                          init\src\mmu.c \
                          init\src\Eint.c \
                          init\src\init_memory_stack.c \
                          init\src\intrCtrl.c \
                          init\src\pdn.c \
                          init\src\regioninit_ads.s \
                          init\src\cache.c init\src\nfb_loader.c init\src\dcmgr.c \
                          init\src\fault.c \
                          init\src\isrentry.c

CUS_REL_GPS_PAR_SRC_LIST = gps\src\gps_init.c \
                          gps\src\gps_inject_msg.c \
                          gps\src\gps_main.c \
                          gps\src\gps_sm.c \
                          gps\src\gps_uart.c
                          
CUS_REL_GIS_PAR_SRC_LIST = gis\src\gis_main.c \
                           vendor\gis\mapbar\adaptation\src\MB_MMIAdp.c \
                           vendor\gis\mapbar\adaptation\src\MB_EngAdp.c \
                           vendor\gis\mapbar\mmi\src\MB_GISFrm.c \
                           vendor\gis\mapbar\mmi\src\MB_GISTaskAgent.c \
                           vendor\gis\mapbar\task\src\MB_GISTask.c \
                           vendor\gis\mapbar\adaptation\src\MapbarGisAdp.c \
                           vendor\gis\mapbar\adaptation\src\MapbarSndAdp.c \
                           vendor\gis\mapbar\adaptation\src\MB_MMISOC.c \
                           vendor\gis\sunavi\adaptation\src\SN_MMIAdp.c \
                           vendor\gis\sunavi\adaptation\src\SN_EngAdp.c \
                           vendor\gis\sunavi\mmi\src\SN_GISFrm.c \
                           vendor\gis\sunavi\mmi\src\SN_GISTaskAgent.c \
                           vendor\gis\sunavi\task\src\SN_GISTask.c

ifdef QQIM_SUPPORT
  ifdef TCPIP_SUPPORT
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        CUS_REL_PAR_SRC_COMP += qqim
        CUS_REL_QQIM_PAR_SRC_LIST += vendor\qqim\adaptation\src\TencentQQ_vm.c \
                                     vendor\qqim\adaptation\src\TencentQQ_adp_other.c
        CUS_REL_FILES_LIST += vendor\qqim\adaptation\inc\TencentQQ_resource_enum.h
      endif
    endif
  endif
endif

CUS_REL_MTK_COMP  +=   fdm  \
                       cc ciss data llc \
                       l4_classb sndcp sim sm sms \
                       sst ft \
                       adaptation config interface_classb stacklib \
                       ppp dsp_ram

CUS_REL_MTK_COMP  +=  nvram_sec

ifeq ($(strip $(MONZA2G)),TRUE)
  CUS_REL_MTK_COMP += mm_classb2 rr_classb2 scsi ratcm ratdm asn1_re
else
  CUS_REL_MTK_COMP += mm_classb rr_classb
endif

ifdef GEMINI
ifeq ($(strip $(GEMINI)),TRUE)
  CUS_REL_MTK_COMP += l1_classb_2 interface_gemini
endif
endif

ifdef DUAL_MODE_SUPPORT
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),MASTER)
  	CUS_REL_MTK_COMP += mercury_master
  endif
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),GEMINI)
    CUS_REL_SRC_COMP += mercury_master mercury_gemini
  endif
endif

ifdef MMI_VERSION
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    CUS_REL_SRC_COMP += mmi
  endif
endif

ifdef SYNCML_SUPPORT
  ifeq ($(strip $(SYNCML_SUPPORT)),TRUE)
    CUS_REL_MTK_COMP    += syncml    
  endif
endif

ifeq ($(strip $(MCD_SUPPORT)),TRUE)
   CUS_REL_MTK_COMP  += mcd
else
   CUS_REL_MTK_COMP  += peer_classb
endif

ifeq ($(strip $(TST_SUPPORT)),TRUE)
      CUS_REL_MTK_COMP    += tst
endif

ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
   CUS_REL_MTK_COMP  += abm soc tcpip applib_inet
   CUS_REL_FILES_LIST += ps\interfaces\local_inc\tcpip2abm_struct.h \
                         ps\interfaces\local_inc\soc2mmi_struct.h \
                         ps\soc\include\soc_feature.h \
                         ps\soc\include\soc_defs.h \
                         ps\soc\include\soc_enum.h \
                         ps\soc\include\soc_dns.h \
                         ps\soc\include\soc_struct.h \
                         ps\soc\include\soc_abm.h \
                         ps\soc\include\soc_app.h \
                         ps\interfaces\local_inc\soc2tcpip_struct.h
endif

ifdef USB_SUPPORT
ifeq ($(strip $(USB_SUPPORT)),TRUE)
   CUS_REL_SRC_COMP  += usb
endif
endif

ifdef DRM_SUPPORT
  CUS_REL_SRC_COMP    	+= drm
endif

ifdef VR_ENGINE
  ifeq ($(strip $(VR_ENGINE)),VR_CYBERON)
   	CUS_REL_OBJ_LIST    += l1audio\obj\BSR_Shell.lib
  endif
endif


ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
     CUS_REL_MTK_COMP        += cmux
  endif
endif

ifeq ($(strip $(XML_SUPPORT)),TRUE)
	CUS_REL_SRC_COMP    += xmlp
endif

ifdef WBXML_SUPPORT
  ifeq ($(strip $(WBXML_SUPPORT)),TRUE)
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      CUS_REL_SRC_COMP  += xmlp
    endif
  endif
endif 

ifdef IMPS_SUPPORT
  ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
       CUS_REL_MTK_COMP    += imps
  endif
endif

ifdef POC_SUPPORT
  ifneq ($(strip $(POC_SUPPORT)),NONE)
     CUS_REL_MTK_COMP    	+= poc
  endif   
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
     CUS_REL_MTK_COMP    	+= sip
  endif   
endif

ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    CUS_REL_SRC_COMP         +=  media_rtp
endif
endif

ifdef SDP_SUPPORT
  ifneq ($(strip $(SDP_SUPPORT)),FALSE)
     CUS_REL_MTK_COMP    	+= sdp
  endif   
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
     CUS_REL_MTK_COMP    	+= voip saf
  endif   
endif

ifdef DT_SUPPORT
ifneq ($(strip $(DT_SUPPORT)),FALSE)
  CUS_REL_SRC_COMP    	+= dt
endif
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
     CUS_REL_MTK_COMP    	+= wndrv supc  dhcp
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     CUS_REL_MTK_COMP    	+= iperf
  endif   
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
    CUS_REL_MTK_COMP         += xdm
  endif
endif

ifdef SW_FLASH
  ifneq ($(strip $(SW_FLASH)),NONE)
    CUS_REL_SRC_COMP += swflash
  endif
endif


ifdef DICT_SUPPORT
  ifeq ($(strip $(DICT_SUPPORT)),MMI_GV)
    CUS_REL_SRC_COMP += dict
  endif
  ifeq ($(strip $(DICT_SUPPORT)),MMI_MOTECH)
    CUS_REL_SRC_COMP += dict
  endif
  ifeq ($(strip $(DICT_SUPPORT)),MMI_TRILOGY)
    CUS_REL_SRC_COMP += dict
  endif
endif


ifdef GAME_ENGINE
  ifneq ($(strip $(GAME_ENGINE)),NONE)
    CUS_REL_SRC_COMP += game_engine
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_BROGENT)
    CUS_REL_BASE_COMP += vendor\game_engine\brogent
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_INTERGRAFX)
    CUS_REL_BASE_COMP += vendor\game_engine\intergrafx
  endif
endif

ifdef SYNCML_DM_SUPPORT
  ifeq ($(strip $(SYNCML_DM_SUPPORT)),TRUE)
     CUS_REL_MTK_COMP    += dmsdk
     CUS_REL_SRC_COMP    += dm
  endif
endif

ifeq ($(strip $(RTSP_SUPPORT)),TRUE)
    CUS_REL_MTK_COMP += rtsp
endif

ifdef TDMB_SUPPORT
  ifneq ($(strip $(TDMB_SUPPORT)),NONE)
    CUS_REL_MTK_COMP += cyberlink
  endif
  ifeq ($(strip $(TDMB_SUPPORT)),FRONTIER_TDMB)
    CUS_REL_MTK_COMP += tdmb
    CUS_REL_FILES_LIST += tdmb\EtiParser\inc\eti.h \
                          tdmb\EtiParser\inc\EtiParser.h \
                          tdmb\EtiParser\inc\interleaving.h \
                          tdmb\rscode\inc\rs.h \
                          tdmb\rscode\inc\crc.h \
                          tdmb\rscode\inc\random.h
  else
    ifeq ($(strip $(TDMB_SUPPORT)),TELECHIP_TDMB)
      CUS_REL_MTK_COMP += tdmb
    endif
  endif
endif

ifdef SECLIB_SUPPORT
  ifeq ($(strip $(SECLIB_SUPPORT)), BASIC)
    CUS_REL_MTK_COMP    += seclib   
  endif
  ifeq ($(strip $(SECLIB_SUPPORT)), PKI)
    CUS_REL_MTK_COMP    += seclib ossl_osadp ossl_crypto ossl_pki ossl_pkiadp
  endif
endif

ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)), NONE)
    CUS_REL_MTK_COMP    += certman
  endif
  ifneq ($(strip $(SSL_SUPPORT)), NONE)
    CUS_REL_MTK_COMP    += sec_store
  endif
  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
    CUS_REL_MTK_COMP    += ossl_ssl ossl_ssladp
  endif   
  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
    CUS_REL_MTK_COMP    += ossl_ssl ossl_ssladp
  endif   
  ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
     CUS_REL_MTK_COMP += sslplus5adp sbpki2adp
  endif   
  ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
     CUS_REL_MTK_COMP += sslplus5adp sbpki2adp
  endif
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
    CUS_REL_MTK_COMP            += tls
  endif
endif

ifdef MMS_SUPPORT
  ifneq ($(strip $(MMS_SUPPORT)),NONE)
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
      CUS_REL_SRC_COMP += mmsapp obigo03cmmsadp
      ifdef RELEASE_$(strip $(MMS_SUPPORT))
        CUS_REL_$(strip $(RELEASE_$(strip $(MMS_SUPPORT))))_COMP += obigo03cmmslib
      else
        CUS_REL_MTK_COMP += obigo03cmmslib
      endif
    endif
  endif
endif

ifdef LQT_SUPPORT
  ifeq ($(strip $(LQT_SUPPORT)),TRUE)
    CUS_REL_MTK_COMP += lqt
  endif
endif

ifdef SQLITE3_SUPPORT
    ifeq ($(strip $(SQLITE3_SUPPORT)),TRUE)
       CUS_REL_MTK_COMP    += applib_sqlite3
    endif
endif

ifdef CMMB_SUPPORT
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    CUS_REL_MTK_COMP += cmmb
  endif
endif

ifdef FONT_ENGINE
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE_DEMO)
    CUS_REL_BASE_COMP += plutommi\Customer\Fonts\Monotype_demo \
                         plutommi\Customer\Fonts\MTK \
                         vendor\vectorfont\monotype\adaptation \
                         vendor\vectorfont\monotype\demo
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE)
    CUS_REL_BASE_COMP += plutommi\Customer\Fonts\MTK \
                         vendor\vectorfont\freetype
  endif
endif

ifdef UDX_SUPPORT
  ifeq ($(strip $(UDX_SUPPORT)),TRUE)
    CUS_REL_SRC_COMP    += udx
  endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    FLC_LIB_INCLUDE_CONDITION = FALSE
    ifneq ($(filter __PS_SERVICE__,$(CUSTOM_OPTION)),)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif  
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif
    ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif
    ifeq ($(strip $(FLC_LIB_INCLUDE_CONDITION)),TRUE)
      CUS_REL_MTK_COMP += flc2
    endif
  endif
endif

ifdef EXT_MODEM_SUPPORT
  ifeq ($(strip $(EXT_MODEM_SUPPORT)), TRUE)
    CUS_REL_SRC_COMP  += ext_modem
  endif
endif

ifdef UCWEB_SUPPORT
  ifeq ($(strip $(UCWEB_SUPPORT)),UCWEB6)
    CUS_REL_SRC_COMP    += ucwebadp
  endif
  CUS_REL_BASE_COMP += vendor\ucweb make\ucwebadp
endif

ifeq ($(strip $(SYNCML_DEVICE_SYNC_SUPPORT)),TRUE)
    CUS_REL_MTK_COMP += obex_stub
else
    ifeq ($(strip $(SYNCML_PC_SYNC_SUPPORT)),TRUE)
        CUS_REL_MTK_COMP   += obex_stub
    endif
endif

ifeq ($(strip $(GPS_BEE_SUPPORT)),TRUE)
    CUS_REL_SRC_COMP    += bee      
endif

ifdef A8BOX_SUPPORT
  ifeq ($(strip $(A8BOX_SUPPORT)),TRUE)
    CUS_REL_MTK_COMP += a8box
  endif
endif

ifdef GGLIVE_SUPPORT
  ifeq ($(strip $(GGLIVE_SUPPORT)),TRUE)
    CUS_REL_SRC_COMP += gglive
  endif
endif
MTV_SUPPORT_ADD_CONDITION = FALSE
ifdef TDMB_SUPPORT
  ifneq ($(strip $(TDMB_SUPPORT)),NONE)
    MTV_SUPPORT_ADD_CONDITION = TRUE
  endif
endif

ifdef CMMB_SUPPORT
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    MTV_SUPPORT_ADD_CONDITION = TRUE
  endif
endif
ifeq ($(strip $(MTV_SUPPORT_ADD_CONDITION)),TRUE)
  CUS_REL_MTK_COMP += mtv
endif

ifdef E_COMPASS_SENSOR_SUPPORT 
  ifneq ($(strip $(E_COMPASS_SENSOR_SUPPORT)),NONE) 
    CUS_REL_MTK_COMP += ecompass
  endif 
endif

ifdef KURO_SUPPORT
  KURO_SUPPORT_OPTION = OFFICIAL MTK_INTERNAL 
  ifneq ($(filter $(strip $(KURO_SUPPORT)) ,$(KURO_SUPPORT_OPTION)),)
     CUS_REL_MTK_COMP       += kuro
  endif
endif

ifdef IPSEC_SUPPORT
  ifneq ($(strip $(IPSEC_SUPPORT)),FALSE)
    CUS_REL_MTK_COMP    += ipsec netkey ike
  endif
endif

CUS_REL_MTK_COMP += event_info
CUS_REL_MTK_COMP  +=   cct
# Vogins Start
ifdef VRE_SUPPORT
  ifeq ($(strip $(VRE_SUPPORT)),VRE_V20)
    CUS_REL_SRC_COMP += vre
  endif
  ifeq ($(strip $(VRE_SUPPORT)),VRE_V21)
    CUS_REL_SRC_COMP += vre
  endif  
  ifeq ($(strip $(VRE_SUPPORT)),VRE_V30)
    CUS_REL_SRC_COMP += vre30
  endif   
endif
# Vogins End

# *************************************************************
# Beginning of block for Change as SW_PM's request
# *************************************************************

ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
   CUS_REL_SRC_COMP  += irda ircomm obex 
endif

ifdef EMAIL_SUPPORT
ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
   CUS_REL_MTK_COMP  +=	email
endif
endif


ifeq ($(strip $(RTOS)),NUCLEUS)
  CUS_REL_MTK_COMP  += nucleus nucleus_int nucleus_ctrl_code nucleus_critical_data
endif

ifeq ($(strip $(RTOS)),THREADX)
  CUS_REL_MTK_COMP  +=  threadx threadx_ctrl_code threadx_ctrl_data
endif

ifeq ($(strip $(RTOS_DEBUG)),TRUE)
  ifeq ($(strip $(RTOS)),NUCLEUS)
    CUS_REL_MTK_COMP    += nucleus_debug
  else
    CUS_REL_MTK_COMP    += threadx_debug
  endif
endif

CUS_REL_FILES_LIST      +=  interface\wap\wap_ps\struct.h \
media\audio\include\aud_dec_imdct_s.dat \
media\audio\include\aud_dec_qc_table.dat \
media\audio\include\aud_dec_rq_table.dat \
media\audio\include\aud_dec_sf_table.dat \
media\audio\include\aud_id3_genre.dat

CUS_REL_FILES_LIST   += media\audio\include\aud_mad_tagger.h 


# **************************************************************
# End of Block for Change as SW_PM's request 
# **************************************************************
CUS_REL_BASE_COMP += MoDIS\NetSim
CUS_REL_FILES_LIST += MoDIS\NetSimScript.msc
CUS_REL_FILES_LIST += interface\ps\abm_api.h
CUS_REL_FILES_LIST += ps\abm\include\abm_main.h
CUS_REL_FILES_LIST += ps\abm\include\abm_util.h
CUS_REL_FILES_LIST += ps\interfaces\enum\mmi_sm_enums.h \
                      ps\interfaces\local_inc\abm2soc_struct.h \
                      ps\interfaces\local_inc\soc2abm_struct.h \
                      ps\interfaces\local_inc\l4c2abm_struct.h \
                      ps\interfaces\local_inc\abm2l4c_struct.h \
                      interface\ps\cbm_api.h \
                      ps\interfaces\local_inc\mmi2abm_struct.h \
                      ps\abm\include\abm_def.h \
                      ps\interfaces\local_inc\app2cbm_struct.h \
                      ps\interfaces\enum\dhcp_abm_enums.h \
                      ps\interfaces\local_inc\dhcp2abm_struct.h \
                      drv\idp\include\legacy\img_comm.h \
                      interface\ps\dhcp_consts.h
ifeq ($(strip $(MMI_BASE)),PLUTO_MMI)
CUS_REL_FILES_LIST += plutommi\MMI\MTE\MTEInc\mteGprot.h \
                      plutommi\MMI\MTE\MTEInc\mte.h \
                      plutommi\MMI\MTE\MTEInc\mte_data.h \
                      plutommi\Customer\CustResource\mte_img_resource.h
endif

CUS_REL_FILES_LIST   +=  tst\database\msglog_db\custom_parse_db.c
CUS_REL_FILES_LIST += drv\graphics\include\jpeg_ext_legacy.h
####CUS_REL_FILES_LIST      += ps\interfaces\local_inc\wap_ps_struct.h 

ifeq ($(call Upper,$(PROJECT)),GPRS)
  CUS_REL_FILES_LIST += tst\database_classb\MCDDLL.dll
else
  ifeq ($(call Upper,$(PROJECT)),UMTS)
    CUS_REL_FILES_LIST += tst\database_classb_umts\MCDDLL.dll
  else
    CUS_REL_FILES_LIST += tst\database\MCDDLL.dll
  endif
endif

########################################################################################
# Custimization part
########################################################################################
ifeq ($(findstring MMI_ZI,$(RELEASE_INPUT_METHODS_SRC)),MMI_ZI)
       CUS_REL_BASE_COMP    += vendor\InputMethod\ZI\adaptation make\zi
endif

ifeq ($(findstring MMI_T9,$(RELEASE_INPUT_METHODS_SRC)),MMI_T9)
       CUS_REL_BASE_COMP    += vendor\InputMethod\T9\adaptation make\t9
endif

ifeq ($(findstring MMI_KA,$(RELEASE_INPUT_METHODS_SRC)),MMI_KA)
       CUS_REL_BASE_COMP    += vendor\InputMethod\KA\adaptation make\ka
endif

ifeq ($(findstring MMI_ITAP,$(RELEASE_INPUT_METHODS_SRC)),MMI_ITAP)
       CUS_REL_BASE_COMP    += vendor\InputMethod\ITAP\adaptation make\itap
endif

ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),KVM)
    CUS_REL_OBJ_LIST  +=   j2me\vm\IJET\j2me_11.lib
  endif
  ifeq ($(strip $(J2ME_VM)),HI_VM)
    CUS_REL_OBJ_LIST  +=   j2me\vm\IJET\j2me_hi.lib
  endif
  ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
    CUS_REL_SRC_COMP  +=   j2me_11
  endif
  ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
    CUS_REL_SRC_COMP  +=   j2me_hi
  endif
endif


ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C) 
       CUS_REL_SRC_COMP    += obigo03cadp
       CUS_REL_$(strip $(RELEASE_WAE))_COMP    += obigo03capp
       CUS_REL_$(strip $(RELEASE_WAP))_COMP    += obigo03clib
endif

ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
       CUS_REL_SRC_COMP    += obigo05aadp wapapp
       CUS_REL_MTK_COMP    += obigo05alib
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
   CUS_REL_MTK_COMP          += btadp btprofiles btstack 
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
   CUS_REL_MTK_COMP          += btadp btprofiles btstack 
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
   CUS_REL_MTK_COMP          += btadp btprofiles btstack 
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612)
   CUS_REL_MTK_COMP          += btadp btprofiles btstack 
endif

ifdef DCD_SUPPORT
  ifneq ($(strip $(DCD_SUPPORT)),NONE)
    CUS_REL_SRC_COMP += dcd    
  endif
endif

ifdef NAND_FLASH_BOOTING
ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
CUS_REL_FILES_LIST += custom\system\$(strip $(BOARD_VER))\custom_emi.c \
                      custom\system\$(strip $(BOARD_VER))\custom_blconfig.c \
                      custom\drv\misc_drv\$(strip $(BOARD_VER))\gpio_drv.c \
                      custom\drv\misc_drv\$(strip $(BOARD_VER))\keypad_def.c \
                      custom\drv\common_drv\gpio_setting.c \
                      drv\src\gpio.c \
                      custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\gpio_var.c \
                      sss\interface\src\SSS_interface.c
endif
endif

ifdef USB_DOWNLOAD
ifneq ($(strip $(USB_DOWNLOAD)),NONE)
CUS_REL_FILES_LIST += custom\system\$(strip $(BOARD_VER))\custom_emi.c \
                      custom\system\$(strip $(BOARD_VER))\custom_blconfig.c \
                      custom\drv\misc_drv\$(strip $(BOARD_VER))\gpio_drv.c \
                      custom\drv\misc_drv\$(strip $(BOARD_VER))\keypad_def.c \
                      custom\drv\common_drv\gpio_setting.c \
                      drv\src\gpio.c \
                      custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\gpio_var.c \
                      sss\interface\src\SSS_interface.c
endif
endif

ifdef INPUT_METHOD
  ifneq ($(findstring MMI_ZI,$(INPUT_METHOD)),)
    CUS_REL_$(strip $(RELEASE_$(strip $(INPUT_METHOD))))_COMP += zi
  endif
  ifneq ($(findstring MMI_T9,$(INPUT_METHOD)),)
    CUS_REL_$(strip $(RELEASE_$(strip $(INPUT_METHOD))))_COMP += t9
  endif
endif

ifdef HAND_WRITING
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
    CUS_REL_SRC_COMP += hanwang
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG_DEMO)
    CUS_REL_SRC_COMP += hanwang
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
    CUS_REL_SRC_COMP += penpower
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER_DEMO)
    CUS_REL_SRC_COMP += penpower
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA)
    CUS_REL_SRC_COMP += decuma
  endif
endif

