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

# *************************************************************************
# Include GNU Make Standard Library (GMSL)
# *************************************************************************
-include tools\GMSL\gmsl
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))
# *************************************************************************
# Dependency Check error message Interfaces
# *************************************************************************
# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB)
#						$(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB1/ValB2/.../ValBn)
#						$(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,non ValB)
# Output:		PLEASE set OptA as ValA or set OptB as ValB
#						PLEASE set OptA as ValA or set OptB as ValB1/ValB2/.../ValBn
#						PLEASE set OptA as ValA or set OptB as non ValB
#
# Example:	$(call DEP_ERR_SETA_OR_SETB,WAP_SUPPORT,OBIGO_Q05A,UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT,non OBIGO_Q05A)
#						PLEASE set WAP_SUPPORT as OBIGO_Q05A or set UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT as non OBIGO_Q05A
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_SETB = $(error PLEASE set $1 as $2 or set $3 as $4)

# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_ONA_OR_OFFB,OptA,OptB)
# Output:		PLEASE turn on OptA or turn off OptB
#
# Example:	$(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
#						PLEASE turn on NAND_SUPPORT or turn off NAND_FLASH_BOOTING
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_OFFB = $(error PLEASE turn on $1 or turn off $2)

# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_SETA_OR_OFFB,OptA,ValA,OptB)
#						$(call DEP_ERR_SETA_OR_OFFB,OptA,ValA1/ValA2/.../ValAn,OptB)
#						$(call DEP_ERR_SETA_OR_OFFB,OptA,non ValA,OptB)
# Output:		PLEASE set OptA as ValA or turn off OptB
#						PLEASE set OptA as ValA1/ValA2/.../ValAn or turn off OptB
#						PLEASE set OptA as non ValA or turn off OptB
#
# Example:	$(call DEP_ERR_SETA_OR_OFFB,MELODY_VER,DSP_WT_SYN,J2ME_SUPPORT)
#						PLEASE set MELODY_VER as DSP_WT_SYN or turn off J2ME_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_OFFB = $(error PLEASE set $1 as $2 or turn off $3)

# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_SETA_OR_ONB,OptA,ValA,OptB)
#						$(call DEP_ERR_SETA_OR_ONB,OptA,ValA1/ValA2/.../ValAn,OptB)
#						$(call DEP_ERR_SETA_OR_ONB,OptA,non ValA,OptB)
# Output:		PLEASE set OptA as ValA or turn on OptB
#						PLEASE set OptA as ValA1/ValA2/.../ValAn or turn on OptB
#						PLEASE set OptA as non ValA or turn on OptB
#
# Example:	$(call DEP_ERR_SETA_OR_ONB,MMS_SUPPORT,non OBIGO_Q05A,UNIFIED_MESSAGE_SUPPORT)
#						PLEASE set MMS_SUPPORT as non OBIGO_Q05A or turn on UNIFIED_MESSAGE_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_ONB = $(error PLEASE set $1 as $2 or turn on $3)

# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_OFFA_OR_OFFB,OptA,OptB)
# Output:		PLEASE turn off OptA or turn off OptB
#
# Example:	$(call DEP_ERR_OFFA_OR_OFFB,CMUX_SUPPORT,BLUETOOTH_SUPPORT)
#						PLEASE turn off CMUX_SUPPORT or turn off BLUETOOTH_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_OFFA_OR_OFFB = $(error PLEASE turn off $1 or turn off $2)

# ------------------------------------------------------------------------
# Usage: 		$(call DEP_ERR_ONA_OR_ONB,OptA,OptB)
# Output:		PLEASE turn on OptA or turn on OptB
#
# Example:	$(call DEP_ERR_ONA_OR_ONB,UCM_SUPPORT,VOIP_SUPPORT)
#						PLEASE turn on UCM_SUPPORT or turn on VOIP_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_ONB = $(error PLEASE turn on $1 or turn on $2)

# *************************************************************************
# Set defaul value to eliminate "option not define" warning
# *************************************************************************
BM_NEW         =  FALSE
RUN_RESGEN      =  FALSE

# *************************************************************************
# Include temporary build script
# *************************************************************************
# Get $(PROJECT) Definition
-include make\~buildinfo.tmp

# Custom specific build script
-include make\Custom.bld         # Custom release build
ifndef CUSTOM_RELEASE
CUSTOM_RELEASE  =  FALSE         # Default custom release
endif

ifndef MTK_SUBSIDIARY
  MTK_SUBSIDIARY = FALSE
endif

ifeq ($(strip $(call Upper,$(CUSTOMER))),MTK)

 ifneq ($(strip $(call Upper,$(APLAT))),NONE)
include make\$(strip $(APLAT))_$(strip $(PROJECT)).mak
THE_MF = make\$(strip $(APLAT))_$(strip $(PROJECT)).mak
 else
include make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
THE_MF = make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
 endif

else
include make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
THE_MF = make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
endif

-include make\USER_SPECIFIC.mak
ifndef DEBUG_MODULES
  DEBUG_MODULES =
endif

ifndef NON_DEBUG_MODULES
  NON_DEBUG_MODULES =
endif

# *************************************************************************
# Include checkvalue.mak to check invalid feature values.
# *************************************************************************
-include make\checkvalue.mak

# *************************************************************************
# Environment and Tools
# *************************************************************************
COMPILE_MODE   =  INST16                           # 16bits instruction set

# default is ADS compiler
ifndef COMPILER
   VIA = -via
   MD = -MD
   COMPILER = ADS
else
   ifeq ($(strip $(COMPILER)),RVCT)
      VIA = --via
      MD = --md
   endif
   ifeq ($(strip $(COMPILER)),ADS)
      VIA = -via
      MD = -MD
   endif
endif

ifdef RVCT_VERSION
    ifneq ($(strip $(RVCT_VERSION)),NONE)
        ifneq ($(strip $(COMPILER)),RVCT)
            $(call DEP_ERR_SETA_OR_OFFB,COMPILER,RVCT,RVCT_VERSION)
        endif
    endif
endif

ifeq ($(strip $(COMPILER)),RVCT)
  ifndef RVCT_VERSION
      $(call DEP_ERR_SETA_OR_ONB,COMPILER,non RVCT,RVCT_VERSION)  
  endif 
  ifeq ($(strip $(RVCT_VERSION)),NONE)
      $(call DEP_ERR_SETA_OR_ONB,COMPILER,non RVCT,RVCT_VERSION)
  endif
  DIR_ARM        =  C:\Progra~1\ARM\RVCT
  DIR_ARM := $(strip $(DIR_ARM))
  ifeq ($(strip $(RVCT_VERSION)),V22)
      DIR_TOOL       =  $(DIR_ARM)\Programs\2.2\349\win_32-pentium
      DIR_ARMLIB     =  $(DIR_ARM)\Data\2.2\349\lib
      DIR_ARMINC     =  $(DIR_ARM)\Data\2.2\349\include\windows
  endif
  ifeq ($(strip $(RVCT_VERSION)),V31)
        DIR_TOOL       =  $(DIR_ARM)\Programs\3.1\569\win_32-pentium
        DIR_ARMLIB     =  $(DIR_ARM)\Data\3.1\569\lib
        DIR_ARMINC     =  $(DIR_ARM)\Data\3.1\569\include\windows
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  DIR_ARM        =  c:\progra~1\arm\adsv1_2
  DIR_ARM := $(strip $(DIR_ARM))
  DIR_TOOL       =  $(DIR_ARM)\bin
  DIR_ARMLIB     =  $(DIR_ARM)\lib
  DIR_ARMINC     =  $(DIR_ARM)\include
endif

ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
  DIR_BF        =  C:\PROGRA~1\ANALOG~1\VISUAL~1.0
  DIR_TOOL       =  $(DIR_BF)
  DIR_BFLIB     =  $(DIR_BF)\Blackfin\lib
  DIR_BFINC     =  $(DIR_BF)\Blackfin\include
endif


ifeq ($(strip $(call Upper,$(COMPILER))),ADS)
  DIR_TOOL := $(strip $(DIR_TOOL))
  LINK           =  $(DIR_TOOL)\armlink.exe          # Linker
  ASM            =  $(DIR_TOOL)\armasm.exe           # ARM assembler
  LIB            =  $(DIR_TOOL)\armar.exe            # Library tool
  BIN_CREATE     =  $(DIR_TOOL)\fromelf.exe          # Binary tool
endif

ifeq ($(strip $(call Upper,$(COMPILER))),RVCT)
  DIR_TOOL := $(strip $(DIR_TOOL))
  LINK           =  $(DIR_TOOL)\armlink.exe          # Linker
  ASM            =  $(DIR_TOOL)\armasm.exe           # ARM assembler
  LIB            =  $(DIR_TOOL)\armar.exe            # Library tool
  BIN_CREATE     =  $(DIR_TOOL)\fromelf.exe          # Binary tool
endif

ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
  DIR_TOOL := $(strip $(DIR_TOOL))
  LINK           =  $(DIR_TOOL)\linker.exe           # Linker, generating dxe file
  ASM            =  $(DIR_TOOL)\easmBLKFN.exe        # ARM assembler
  LIB            =  $(DIR_TOOL)\elfar.exe            # Library tool
  BIN_CREATE     =  $(DIR_TOOL)\elfloader.exe        # Binary tool, generating ldr file
endif
  

ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     CC          =  $(DIR_TOOL)\armcc.exe --thumb    # Thumb Mode(16bits), use tcc
     CC32        =  $(DIR_TOOL)\armcc.exe --arm      # ARM Mode(32bits), use armcc
  else
     ifeq ($(strip $(COMPILE_MODE)),INST32)
        CC          =  $(DIR_TOOL)\armcc.exe --arm   # ARM Mode(32bits), use armcc
     else
        CC          =  $(DIR_TOOL)\armcc.exe --thumb # Default tcc
        CC32        =  $(DIR_TOOL)\armcc.exe --arm   # ARM Mode(32bits), use armcc
     endif
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     CC          =  $(DIR_TOOL)\tcc.exe              # Thumb Mode(16bits), use tcc
     CC32        =  $(DIR_TOOL)\armcc.exe            # ARM Mode(32bits), use armcc
     CPPC        =  $(DIR_TOOL)\tcpp.exe              # Thumb Mode(16bits), use tcc
     CPPC32      =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
  else
     ifeq ($(strip $(COMPILE_MODE)),INST32)
        CC          =  $(DIR_TOOL)\armcc.exe            # ARM Mode(32bits), use armcc
        CPPC        =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
     else
        CC          =  $(DIR_TOOL)\tcc.exe              # Default tcc
        CC32        =  $(DIR_TOOL)\armcc.exe            # ARM Mode(32bits), use armcc
        CPPC        =  $(DIR_TOOL)\tcpp.exe              # Thumb Mode(16bits), use tcc
        CPPC32      =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
     endif
  endif
endif


ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
  CC          =  $(DIR_TOOL)\ccblkfn.exe            # 16bits Mode, use ccblkfn.exe
  CC32        =  $(DIR_TOOL)\ccblkfn.exe            # 32bits Mode, use ccblkfn.exe
  CPPC        =  $(DIR_TOOL)\ccblkfn.exe            # 16bits Mode, use ccblkfn.exe
  CPPC32      =  $(DIR_TOOL)\ccblkfn.exe            # 32bits Mode, use ccblkfn.exe
endif



# *************************************************************************
# Build Options
# *************************************************************************

# -----------------------------
# CODEGEN option
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
   CGENFLAG = -D__RVCT__
endif

ifeq ($(strip $(COMPILER)),ADS)
   CGENFLAG =
endif

ifeq ($(strip $(COMPILER)),BLACKFIN)
   CGENFLAG = -D__BLACKFIN__
endif

# -----------------------------
# Interwork option
# -----------------------------
APCSINT     =
ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     APCSINT  +=  --apcs /inter/noswst
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     APCSINT  +=  -apcs /interwork
  endif
endif

# -----------------------------
# C options COPTION16 for thumb mode and COPTION32 for arm mode
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  CPLUSFLAGS = --cpp --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  CFLAGS     = --cpu ARM7EJ-S --littleend -O3 -D__RVCT__  -J$(DIR_ARMINC) 
  ifeq ($(strip $(PLATFORM)),MT6218B)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6217)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6219)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6226M)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6229)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6268T)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6268H)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6268A)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6268)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6230)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6228)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6227)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6227D)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6226)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6226D)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6208)
     CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6205B)
     CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6205C)
     CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6225)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6253T)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6253)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6223)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6223P)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6238)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6239)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6235)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6235B)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
  endif

  ifeq ($(strip $(PLATFORM)),MT6516)
    ifdef SMART_PHONE_CORE
      ifeq ($(strip $(SMART_PHONE_CORE)),AP)
        CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
      else
        CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
      endif
    else
      CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 -D__RVCT__ -J$(DIR_ARMINC) 
    endif
  endif

endif

ifeq ($(strip $(COMPILER)),ADS)
  CFLAGS     =   -cpu ARM7EJ-S -littleend -O2 -zo -Ono_peephole -fa

  ifeq ($(strip $(PLATFORM)),MT6218B)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6217)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6219)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226M)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6229)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268T)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268H)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268A)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6268)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6230)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6228)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6227)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6227D)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226D)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6208)
      CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6205B)
      CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6205C)
      CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6225)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6253T)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6253)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6223)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6223P)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6238)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6239)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6235)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6235B)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6516)
    ifdef SMART_PHONE_CORE
      ifeq ($(strip $(SMART_PHONE_CORE)),AP)
        CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
      else
        CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
      endif
    else
      CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
    endif
  endif

endif

ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
     CFLAGS     := -proc ADSP-BF535  -no-extra-keywords  -Ov0 -si-revision none -ipa -c
endif



CFLAGS     +=  $(CUSTOM_CFLAGS)

ifeq ($(strip $(COMPILER)),RVCT)
   CPLUSFLAGS +=  $(CUSTOM_CFLAGS)

# move to Comp.mak 
# begin
#   CFLAGS += --bss_threshold=0
#   CPLUSFLAGS += --bss_threshold=0
# end

endif


# -----------------------------
# assembly option AOPTION16 for Thumb mode and AOPTION32 for Arm mode
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  BL_AFLAGS  = --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  AFLAGS     = --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  ifeq ($(strip $(PLATFORM)),MT6218B)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6219)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6217)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6226M)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6226)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6226D)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6227)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6227D)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6228)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268T)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268H)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268A)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6268)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253T)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6253)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM9EJ-S --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6516)
    BL_AFLAGS  :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
    AFLAGS     :=   --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  BL_AFLAGS  = -g -littleend -cpu ARM7TDMI
  AFLAGS     = -g -littleend -cpu ARM7TDMI
  ifeq ($(strip $(PLATFORM)),MT6218B)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6219)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6217)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226M)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226D)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6227)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6227D)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6228)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268T)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268H)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268A)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6268)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253T)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6253)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    BL_AFLAGS  :=   -g -littleend -cpu ARM9EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6516)
    BL_AFLAGS  :=   -g -littleend -cpu ARM7EJ-S
    AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
endif

ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
     AFLAGS     := -proc ADSP-BF535 -si-revision none -g 
endif


ifeq ($(strip $(COMPILE_MODE)),INST16)
  BL_AFLAGS += -16
  AFLAGS +=  -16
endif

# -----------------------------
# Library option LIBOPT for generating libraries
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  LIBOPT      =  --create
endif
ifeq ($(strip $(COMPILER)),ADS)
  LIBOPT      =  -create
endif

# -----------------------------
# Linker options
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  LNKOPT      =  --map --info sizes,totals --symbols --feedback lnkfeedback.txt --xref --remove --pad 0xFF
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
        LNKOPT      +=  --first LARGEPOOL_FIRST_ZI
    endif
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE) 
    LNKOPT      =  -map -info sizes,totals -symbols -xref -remove -verbose
  else
    LNKOPT      =  -map -info sizes,totals -symbols -xref -remove
  endif
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
      ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
        LNKOPT      +=  -first LARGEPOOL_FIRST_ZI
      endif
    endif
  endif
endif


ifeq ($(strip $(call Upper,$(COMPILER))),BLACKFIN)
    LNKOPT      =  -proc ADSP-BF535 -si-revision none -verbose -map -xref -e 
endif


# -----------------------------
# Binary tool options
# -----------------------------
BIN_FORMAT  =  -bin

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    ifneq ($(findstring TECH,$(strip $(subst _, ,$(OPTR_SPEC)))),)
       OPTR_SPEC  := $(strip $(subst _TECH, ,$(OPTR_SPEC)))
       OPTR_DEFS   +=  __OP_TECH_REL__
       OPTR_DEFS   +=  __$(strip $(OPTR_SPEC))_TECH__
       ifdef OPTR_CODE
          OPTR_DEFS   +=  __$(strip $(OPTR_CODE))_$(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))_$(word 3,$(subst _, ,$(OPTR_SPEC))))_TECH__
       endif
    endif
    ifdef OPTR_CODE
       OPTR_DEFS   +=  __$(strip $(OPTR_CODE))__
       OPTR_DEFS   +=  __$(strip $(OPTR_CODE))_$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))__
       OPTR_DEFS   +=  __$(strip $(OPTR_CODE))_$(strip $(word 2,$(subst _, ,$(OPTR_SPEC)))_$(word 3,$(subst _, ,$(OPTR_SPEC))))__
    endif
  endif
endif

# -----------------------------
# custom release library path
# -----------------------------
ifdef OPTR_SPEC
  ifeq ($(strip $(OPTR_SPEC)),NONE)
    ifdef SWITCHABLE_FEATURE
      ifneq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        ifdef SWITCHABLE_FEATURE_2ND
          ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
            CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))
          else
            CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
          endif
        else
          CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
        endif
      else
        CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))
      endif      
    else
      CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))
    endif
  else
    ifdef SWITCHABLE_FEATURE
      ifneq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        ifdef SWITCHABLE_FEATURE_2ND
          ifneq ($(strip $(SWITCHABLE_FEATURE)),NONE)
            CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))\$(strip $(SWITCHABLE_FEATURE_2ND))\$(strip $($(strip $(SWITCHABLE_FEATURE_2ND))))
          else
            CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
          endif
        else
          CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
        endif
      else
        CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))
      endif      
    else
      CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))
    endif
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6226)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226,6226M,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226,6226M,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6226,6227,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226,6227,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6227)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6227,6226M,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227,6226M,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6227,6226,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227,6226,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6226M)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226M,6226,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226M,6226,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6226M,6227,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226M,6227,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6229)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6229,6230,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6229,6230,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6230)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6230,6229,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6230,6229,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6226D)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226D,6227D,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226D,6227D,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6227D)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6227D,6226D,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227D,6226D,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6223)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6223,6223P,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6223,6223P,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6223P)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6223P,6223,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6223P,6223,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6238)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6238,6239,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6238,6239,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6239)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6239,6238,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6239,6238,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6235)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6235,6235B,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6235,6235B,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6235B)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6235B,6235,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6235B,6235,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif

# *************************************************************************
# Common include file and output directory path
# *************************************************************************
ifndef RTOS
   RTOS = NUCLEUS
endif

ifndef RTOS_DEBUG
   RTOS_DEBUG = TRUE
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
COMMINCDIRS    =  nucleus\inc \
                  kal\include kal\common\include \
                  kal\nucleus\include
endif

ifeq ($(strip $(RTOS)),THREADX)
COMMINCDIRS    =  threadx\inc \
                  kal\include kal\common\include \
                  kal\threadx\include
endif


ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
COMMINCDIRS   +=  tst\database\gv \
                  tst\database\unionTag
endif

ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
COMMINCDIRS   +=  tst\database\gv \
                  tst\database\unionTag
endif

ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
COMMINCDIRS   +=  tst\database\gv \
                  tst\database\unionTag
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
COMMINCDIRS   +=  tst\database\gv \
                  tst\database\unionTag
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
COMMINCDIRS   +=  tst\database_classb\gv \
                  tst\database_classb\unionTag

endif

ifeq ($(strip $(call Upper,$(PROJECT))),UMTS)
COMMINCDIRS   +=  tst\database_classb_umts\gv \
                  tst\database_classb_umts\unionTag
endif

COMMINCDIRS   +=  custom\system\$(strip $(BOARD_VER))

COMMINCDIRS   +=  interface\wap \
                  wapadp\include 

COMMINCDIRS   +=  drm\include

COMMINCDIRS   +=  ps\email\inc \
                  ps\email\pop3\inc \
                  ps\email\smtp\inc \
                  ps\email\imap\inc

COMMINCDIRS   +=  ps\ems\include ps\cc-ss\ss\include
COMMINCDIRS   +=  ps\l4\smu\include ps\l4\rac\include
COMMINCDIRS   +=  ps\interfaces\local_inc
COMMINCDIRS   +=  applib\asn1\include

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COMMINCDIRS   +=  plutommi\mtkapp\EngineerMode\EngineerModeApp\EngineerModeAppInc \
                    plutommi\mtkapp\EngineerMode\EngineerModeEngine\EngineerModeEngineInc \
                    plutommi\mtkapp\FactoryMode\FactoryModeInc
endif

#for GEMINI
ifdef GEMINI
  ifeq ($(strip $(GEMINI)),TRUE)
    COMMINCDIRS   +=  SIM2\ps\l4\smu\include SIM2\ps\cc-ss\ss\include SIM2\ps\l4\rac\include
  endif  
endif

ifeq ($(strip $(call Upper,$(PROJECT))),UMTS)
  COMMINCDIRS   +=  ps\mcddll\include ps\rr2\asn\include
else
  COMMINCDIRS   +=  ps\mcddll\include ps\rr\asn\include
endif

COMMINCDIRS   += interface\bt
COMMINCDIRS   += ps\dt\include

# dependency rule for KAL,BUFFER & ITC debug compile options
DEP_DEBUG_COMPILE_OPTION = DEBUG_KAL DEBUG_BUF DEBUG_BUF2 DEBUG_ITC
ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),)
  ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(sort $(strip $(DEP_DEBUG_COMPILE_OPTION))))
    DISABLED_DEBUG_COMPILE_OPTION = $(filter-out $(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(strip $(DEP_DEBUG_COMPILE_OPTION)))
    $(error PLEASE turn on $(DISABLED_DEBUG_COMPILE_OPTION) or turn off $(ENABLED_DEBUG_COMPILE_OPTION))
  endif
endif
# end

ifdef MSDC_CARD_SUPPORT_TYPE
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
     ifneq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
        $(error Please remove FMT_NOT_PRESENT from CUSTOM_OPTION when MSDC_CARD_SUPPORT_TYPE is set as MSDC_SD_MMC!)     
     endif              
  endif
endif

ifneq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
  ifneq ($(filter fmt,$(COMPLIST)),)
    $(error Please remove FMT_NOT_PRESENT from CUSTOM_OPTION when fmt module is defined in COMPLIST)
  endif
endif

ifneq ($(filter MULTIPLE_BINARY_FILES,$(CUSTOM_OPTION)),)
  $(error Please remove invalid compile optoin MULTIPLE_BINARY_FILES from CUSTOM_OPTION and set feature option MULTIPLE_BINARY_FILES as TRUE!)
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
    COMMINCDIRS   += applib\inet\engine\include
    COMMINCDIRS   += applib\inet\app\include
  endif
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
       COMMINCDIRS  +=	ps\xdm\include
  endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
       COMMINCDIRS  +=	ps\voip\include
       COMMINCDIRS  +=	ps\saf\include
  endif
endif

COMMINCDIRS += custom\common\$(strip $(MMI_BASE))
CUS_REL_BASE_COMP += custom\common\$(strip $(MMI_BASE))

COMMINCDIRS	+= interface\wifi


ifdef UNIFIED_MESSAGE_SUPPORT
   ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),FALSE)
      COMMINCDIRS	+= plutommi\MMI\UnifiedMessage\UnifiedMessageInc
   endif
endif

COMMINCDIRS	  += plutommi\MtkApp\DLAgent\DLAgentInc

ISP_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B
ifdef ISP_SUPPORT
  ifeq ($(strip $(ISP_SUPPORT)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(ISP_NOT_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does NOT support ISP)
    endif
  endif
endif

MP4_CODEC_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B

ifdef MP4_ENCODE
  ifneq ($(strip $(MP4_ENCODE)),NONE)
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_CODEC_NOT_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(MP4_ENCODE)))
    endif
  endif
endif

ifdef MP4_DECODE
  ifneq ($(strip $(MP4_DECODE)),NONE)
    ifneq ($(filter $(strip $(PLATFORM)),$(MP4_CODEC_NOT_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(MP4_DECODE)))
    endif
  endif
endif

ifdef MP4_ENCODE
  ifneq ($(strip $(MP4_ENCODE)),NONE)
    ifdef ISP_SUPPORT
      ifeq ($(strip $(ISP_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,MP4_ENCODE)
      endif
    endif
  endif # ifneq ($(strip $(MP4_ENCODE)),NONE)
endif # ifdef MP4_ENCODE

ifdef MP4_DECODE
  ifneq ($(strip $(MP4_DECODE)),NONE)
    ifdef ISP_SUPPORT
      ifeq ($(strip $(ISP_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,MP4_DECODE)
      endif
    endif
  endif # ifneq ($(strip $(MP4_DECODE)),NONE)
endif # ifdef MP4_DECODE

RAW_SENSOR_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B MT6225 MT6235 MT6235B
YUV_SENSOR_NOT_SUPPORT_PLATFORM = MT6223 MT6223P MT6205B

ifdef ISP_SUPPORT
  ifeq ($(strip $(ISP_SUPPORT)),TRUE)
    ifeq ($(strip $(SENSOR_TYPE)),RAW)
      ifeq ($(filter $(strip $(PLATFORM)),$(RAW_SENSOR_NOT_SUPPORT_PLATFORM)),)
        ifdef MP4_ENCODE
          ifeq ($(strip $(MP4_ENCODE)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,MP4_ENCODE,ISP_SUPPORT)
          endif # ifeq ($(strip $(MP4_ENCODE)),NONE)
        endif
        ifdef MP4_DECODE
          ifeq ($(strip $(MP4_DECODE)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,ISP_SUPPORT)
          endif # ifeq ($(strip $(MP4_DECODE)),NONE)
        endif
      endif
    endif # ifeq ($(strip $(SENSOR_TYPE)),RAW)
  endif # ifeq ($(strip $(ISP_SUPPORT)),TRUE)
endif # ifdef ISP_SUPPORT

ifneq ($(strip $(SENSOR_TYPE)),RAW)
  ifeq ($(strip $(AF_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,RAW,AF_SUPPORT)
  endif
endif

ifdef SENSOR_TYPE
  ifneq ($(strip $(SENSOR_TYPE)),NONE)
    ifeq ($(strip $(PLATFORM)),MT6223P)
      ifneq ($(strip $(SENSOR_TYPE)),DIRECT)
        $(error MT6223P only supports SENSOR_TYPE=DIRECT, please change SENSOR_TYPE value)
      endif
    endif
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
         $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,SENSOR_TYPE)
    endif

    ifeq ($(strip $(SENSOR_TYPE)),RAW)
      ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,SENSOR_TYPE,non RAW,ISP_SUPPORT)
      else
        ifneq ($(filter $(strip $(PLATFORM)),$(RAW_SENSOR_NOT_SUPPORT_PLATFORM)),)
          $(error PLATFORM $(strip $(PLATFORM)) does NOT support SENSOR_TYPE=$(strip $(SENSOR_TYPE)))
        endif
      endif
    endif # ifeq ($(strip $(SENSOR_TYPE)),RAW)
    ifeq ($(strip $(SENSOR_TYPE)),YUV)
      ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,SENSOR_TYPE,non YUV,ISP_SUPPORT)
      else
        ifneq ($(filter $(strip $(PLATFORM)),$(YUV_SENSOR_NOT_SUPPORT_PLATFORM)),)
          $(error PLATFORM $(strip $(PLATFORM)) does NOT support SENSOR_TYPE=$(strip $(SENSOR_TYPE)))
        endif
      endif
    endif #ifeq ($(strip $(SENSOR_TYPE)),YUV)

    ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
      ifneq ($(strip $(ISP_SUPPORT)),FALSE)
         $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,non DIRECT,ISP_SUPPORT)
      endif
      ifneq ($(strip $(PLATFORM)),MT6223P)
         $(error Only MT6223P supports SENSOR_TYPE = DIRECT)
      endif
      6223_SUPPORT_LCD_SIZE = 176X220 128X160 128X128 
      ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))) ,$(6223_SUPPORT_LCD_SIZE)),)
        $(error $(strip $(PLATFORM)) only supports $(6223_SUPPORT_LCD_SIZE) when CMOS_SENSOR is enabled)
      endif
    endif #ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
  else
    ifneq ($(strip $(CMOS_SENSOR)),NONE)
         $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,CMOS_SENSOR)
    endif
    ifneq ($(strip $(ISP_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,ISP_SUPPORT)
    endif
  endif # ifneq ($(strip $(SENSOR_TYPE)),NONE)
endif# ifdef SENSOR_TYPE

COMMINCDIRS	  += interface\drv_def

ifdef RTSP_SUPPORT
  ifneq ($(strip $(RTSP_SUPPORT)),FALSE)
       COMMINCDIRS  +=	ps\rtsp\include
  endif
endif


ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
   CUSTOM_COMMINC +=  lcmmi\mmi\Inc
   CUSTOM_COMMINC += lcmmi\mmi\Inc\MenuID
else
   CUSTOM_COMMINC   +=  plutommi\mmi\Inc
   CUSTOM_COMMINC   +=  plutommi\MMI\Inc\MenuID
   CUSTOM_COMMINC   +=  plutommi\mmi\framework\commonfiles\commoninc
   CUSTOM_COMMINC   +=  plutommi\mmi\framework\commonfiles\commoninc\depreciation
   CUSTOM_COMMINC   +=  applib\mem\include
endif


ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\plutommi
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi\$(strip $(word 3,$(subst _, ,$(OPTR_SPEC))))
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi\$(strip $(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\app
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi\$(strip $(word 3,$(subst _, ,$(OPTR_SPEC))))\custom\common
  endif
endif

# ifdef SYNCML_DM_SUPPORT
#  ifneq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
#       COMMINCDIRS  +=  dm\task\inc 
#       COMMINCDIRS  +=  dm\wrapper\inc 
#  endif
# endif

ifdef SYNCML_DM_SUPPORT
  ifneq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
       COMMINCDIRS  +=	vendor\dm\bitfone\adaptation\task\inc
       COMMINCDIRS  +=	vendor\dm\bitfone\adaptation\wrapper\inc
       COMP_TRACE_DEFS   += vendor\dm\bitfone\adaptation\task\inc\dm_trc.h
  endif
endif


ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    COMMINCDIRS    +=	custom\drv\misc_drv\$(strip $(BOARD_VER))
    COMMINCDIRS    +=	custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen
  endif
endif

COMMINCDIRS	+= interface\GIS

COMMINCDIRS += interface\GPS

ifdef GPS_SUPPORT
  ifneq ($(strip $(GPS_SUPPORT)),NONE)
     COMP_TRACE_DEFS += gps\inc\gps_trc.h
  endif
endif

ifdef BT_GPS_SUPPORT
  ifneq ($(strip $(BT_GPS_SUPPORT)),FALSE)
     COMP_TRACE_DEFS += gps\inc\gps_trc.h
  endif
endif

ifeq ($(strip $(MP4_DECODE)),MP4_SW)
  COMP_TRACE_DEFS += media\vcodec\include\vcodec_trc.h
else
  ifeq ($(strip $(MP4_ENCODE)),MP4_SW)
    COMP_TRACE_DEFS += media\vcodec\include\vcodec_trc.h
  else
    ifeq ($(strip $(H264_DECODE)),H264_SW)
      COMP_TRACE_DEFS += media\vcodec\include\vcodec_trc.h
    else
      ifeq ($(strip $(H264_ENCODE)),H264_SW)
        COMP_TRACE_DEFS += media\vcodec\include\vcodec_trc.h
      endif
    endif
  endif
endif


COMMINCDIRS	+= ps\interfaces\asn\rr\include 

COMMINCDIRS  +=  drv\display\include
COMMINCDIRS  +=  drv\graphics\include
COMMINCDIRS  +=  drv\graphics\jpeg_codec\inc
COMMINCDIRS  +=  drv\idp\include
COMMINCDIRS  +=  image_codec\common\include
COMMINCDIRS  +=  image_codec\sw_jpeg_core\inc

ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)), NONE)
    COMMINCDIRS     +=  interface\security
    COMMINCDIRS     +=  applib\misc\include
    COMMINCDIRS     +=  security\certman\include
    COMMINCDIRS     +=  plutommi\mmi\CertificateManager\CertificateManagerMMIInc
    COMP_TRACE_DEFS += security\certman\include\certman_trc.h
  endif
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)), TRUE)
    COMMINCDIRS     += interface\security
    COMP_TRACE_DEFS += security\tls\include\tls_trc.h
  endif
endif

ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  COMP_TRACE_DEFS += drv\include\drv_trc.h
endif

ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
  COMP_TRACE_DEFS += drv\include\drv_trc.h
endif

#end of commincdirs

# -----------------------------
# Custom Options
# -----------------------------
CUSTOM_COMMINC += ul1\ul1d
CUSTOM_COMMINC += media\camera_v2\include
COMMINCDIRS    += $(DIR_ARMINC) $(CUSTOM_COMMINC)

# *************************************************************************
# Component Compile Options
# *************************************************************************
# -----------------------------
# Common Options
# -----------------------------
CUSTOM_OPTION := $(filter-out $(REMOVE_CUSTOM_OPTION),$(CUSTOM_OPTION))

COM_DEFS    = $(CUSTOM_OPTION)

ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    COM_DEFS    += $(OPTR_DEFS)
  endif
endif

ifndef FLAVOR
   COM_DEFS    += __FLAVOR_NOT_PRESENT__
endif

ifdef FLAVOR
  ifneq ($(strip $(FLAVOR)),NONE)
    COM_DEFS    += __FLAVOR_$(strip $(FLAVOR))__
  else
    COM_DEFS    += __FLAVOR_NOT_PRESENT__
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  COM_DEFS += KAL_ON_NUCLEUS
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += NU_DEBUG
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(RTOS)),THREADX)
  COM_DEFS += KAL_ON_THREADX
  COM_DEFS += TX_ENABLE_IRQ_NESTING TX_DISABLE_NOTIFY_CALLBACKS \
              TX_DISABLE_PREEMPTION_THRESHOLD TX_DISABLE_STACK_FILLING TX_REACTIVE_INLINE
  ifneq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += TX_DISABLE_ERROR_CHECKING
  endif
endif

COM_DEFS    += __BLIND_HANDOVER__

COM_DEFS    +=  IDLE_TASK _DEBUG MTK_KAL  __MTK_TARGET__ IDMA_DOWNLOAD

COM_DEFS    +=  SME_NOT_PRESENT SME_READER_NOT_PRESENT STDC_HEADERS TARGET_BUILD

COM_DEFS    += DEBUG_LEVEL=0

COM_DEFS    += __SATC3__

COM_DEFS    += __MSLT__

ifeq ($(strip $(COMPILER)),RVCT)
  COM_DEFS += __RVCT__
endif

ifeq ($(strip $(COMPILER)),ADS)
  COM_DEFS += __ADS__
endif

ifdef OPTR_SPEC
    ifeq ($(strip $(OPTR_SPEC)),NONE)
       COM_DEFS += __OPTR_NONE__
    endif
endif


ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  EMPTY_MMI
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  EMPTY_MMI
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    COM_DEFS +=  EMPTY_MMI
  endif
endif

ifdef DEMO_PROJECT
   ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      COM_DEFS   += DEMO_PROJECT
      COM_DEFS   += MTK_INTERNAL_MMI_FEATURES
      COM_DEFS   += __MTK_INTERNAL__
      
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
         COM_DEFS += WIFI_BLACKLIST 
      endif
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
           COM_DEFS += WIFI_PORT_TIMER 
      endif
   endif
endif

MMI_SWITCH = $(shell dir .\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h /b 2>nul)
ifdef DEMO_PROJECT
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    ifdef MMI_FEATURES_SWITCH
      ifeq ($(strip $(MMI_FEATURES_SWITCH)),FALSE)
        COM_DEFS   += USE_COMMON_MMI_FEATURES_SWITCH
      else
        ifeq ($(words $(strip $(MMI_SWITCH))),0)
          ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
            $(error .\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h shoule exist when MMI_FEATURES_SWITCH is TRUE)
          endif
        endif
      endif
    else
      COM_DEFS   += USE_COMMON_MMI_FEATURES_SWITCH
    endif
  endif
endif

ifdef EMPTY_RESOURCE
  ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
    COM_DEFS += __BT_MP_RELEASE__
  endif
endif

ifdef GPS_SUPPORT
  ifneq ($(strip $(GPS_SUPPORT)),NONE)
    COM_DEFS    += __GPS_SUPPORT__
    COM_DEFS    += __GPS_USE_UART2__
    COM_DEFS    += __ONLY_ONE_UART__
    COMPLIST    += gps
    ifeq ($(strip $(GPS_SUPPORT)),MT3316)
       COM_DEFS    += __GPS_MT3316__
    endif
    ifeq ($(strip $(GPS_SUPPORT)),MT3326)
       COM_DEFS    += __GPS_MT3326__ __MNL_SUPPORT__
       COMPLIST    += mnl    
       COMPOBJS    += gps\mnl\lib\MTKNav.lib
       CUS_REL_OBJ_LIST += gps\mnl\lib\MTKNav.lib
       CUS_REL_FILES_LIST += gps\mnl\lib\MTKNav_WIN32.lib
    endif
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      CUS_REL_BASE_COMP += gps\mnl make\mnl
    endif
  endif
endif

ifdef BT_GPS_SUPPORT
  ifneq ($(strip $(BT_GPS_SUPPORT)),FALSE)
    COM_DEFS    += __BT_GPS_SUPPORT__
    COMPLIST    += gps
  endif
endif

ifdef WAP_SUPPORT
  ifneq ($(strip $(WAP_SUPPORT)),NONE)
    ifneq ($(strip $(WBXML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,WBXML_SUPPORT,WAP_SUPPORT)
    else
      COM_DEFS    += __PROVISIONING_SERVICE_SUPPORT__
      COM_DEFS    += __CCA_SUPPORT__
      ifdef SIM_PROVISIONING
        ifneq ($(strip $(SIM_PROVISIONING)),NONE)
          COM_DEFS    += __SPA_SUPPORT__
          COM_DEFS    += __DTCNT_SIM_PROFILES_SUPPORT__
        endif
        ifeq ($(strip $(SIM_PROVISIONING)),MMSICP)
          COM_DEFS    += __MMSICP_SUPPORT__
        endif
      endif
    endif
  endif
endif


ifdef RSAT_SUPPORT
  ifeq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
    ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,EMPTY_MMI,RSAT_SUPPORT)
    else
      COM_DEFS    += __RSAT__
    endif
  endif
  ifeq ($(strip $(RSAT_SUPPORT)),MMI_WITH_RSAT)
    COM_DEFS    += __RSAT__
  endif
endif

ifdef UL1D_COSIM
    ifeq ($(strip $(UL1D_COSIM)),TRUE)
        ifeq ($(strip $(UL1D_LOOPBACK)),0)
            $(call DEP_ERR_SETA_OR_OFFB,UL1D_LOOPBACK,non 0,UL1D_COSIM)
        endif
    endif
endif

ifdef IC_TEST_TYPE
  ifneq ($(strip $(IC_TEST_TYPE)),NONE)
    CUS_REL_MTK_COMP += btmt
  endif
endif

# remove COM_DEFS   += __SIM_PLUS__

# *************************************************************************
# Include Java compile settings.
# *************************************************************************
-include make\JAVA_DEF.mak

# *************************************************************************
# Components
# *************************************************************************
# -----------------------------
# Common Components
# -----------------------------



# *************************************************************************
# Component trace definition header files
# *************************************************************************
# -----------------------------
# Common trace
# -----------------------------

ifdef MMI_VERSION

   ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_conn_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_common_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_inet_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_media_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_fw_trc.h
   endif
   ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_common_app_trc.h 
      COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_media_app_trc.h 
      COMP_TRACE_DEFS += lcmmi\mmi\inc\mmi_fw_trc.h 
   endif

endif


ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
     COMP_TRACE_DEFS += ps\email\inc\email_trace.h
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
     COMP_TRACE_DEFS	+= ps\cmux\include\cmux_trc.h
  endif
endif

ifdef POC_SUPPORT
  ifneq ($(strip $(POC_SUPPORT)),NONE)
     COMP_TRACE_DEFS	+= ps\poc\include\poc_trc.h
  endif
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\sip\include\sip_trc.h
  endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\voip\include\voip_trc.h
     COMP_TRACE_DEFS	+= ps\saf\include\saf_trc.h
  endif
endif

ifdef DT_SUPPORT
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
      ifneq ($(strip $(DT_SUPPORT)),FALSE)
        COMP_TRACE_DEFS	+= ps\dt\include\dt_trc.h
      endif
    endif
  endif
endif
endif

ifndef SMART_PHONE_CORE
  COMP_TRACE_DEFS	+= l1audio\inc\l1sp_trc.h
else
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    COMP_TRACE_DEFS	+= l1audio_sp\l1sp_trc.h
  else
    COMP_TRACE_DEFS	+= l1audio\inc\l1sp_trc.h
  endif
endif

COMP_TRACE_DEFS += dp_engine\dp_engine_trc.h

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\xdm\include\xdm_trc.h
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    COMP_TRACE_DEFS	+= j2me\interface\j2me_trace.h
  endif
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    ifeq ($(strip $(WIFI_SUPPORT)),MT5911)
      COMP_TRACE_DEFS	+= wifi\wndrv\include\os\wndrv_trc.h
    endif
    ifeq ($(strip $(WIFI_SUPPORT)),MT5921)
      COMP_TRACE_DEFS	+= wifi\wndrv\MT5921\include\os\wndrv_trc.h
    endif
    COMP_TRACE_DEFS	+= wifi\dummy_supc\include\supc_trc.h
    COMP_TRACE_DEFS	+= ps\dhcp\include\dhcp_trc.h
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     COMP_TRACE_DEFS	+= ps\iperf\include\iperf_trc.h
  endif
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
  COMP_TRACE_DEFS += btadp\include\bluetooth_trc.h
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
  COMP_TRACE_DEFS += btadp\include\bluetooth_trc.h
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
  COMP_TRACE_DEFS += btadp\include\bluetooth_trc.h
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612)
  COMP_TRACE_DEFS += btadp\include\bluetooth_trc.h
endif

#ifdef JATAAYU_FEATURE
#  ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
#     COMP_TRACE_DEFS	+= vendor\wap\jataayu4\adaptation\include\wap_trc.h
#     COMP_TRACE_DEFS	+= vendor\wap\jataayu4\adaptation\include\wps_trc.h
#  endif
#endif


ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
      COMP_TRACE_DEFS   += ps\ems\include\ems_trc.h
    endif
  endif
endif

ifdef RTSP_SUPPORT
  ifneq ($(strip $(RTSP_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\rtsp\include\rtsp_trc.h
  endif
endif

ifdef WAP_SUPPORT
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
     COMP_TRACE_DEFS  += vendor\wap\obigo_q05a\adaptation\integration\include\wap_trc.h
  endif
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)
     COMP_TRACE_DEFS  += vendor\wap\obigo_Q03C\adaptation\integration\include\wap_trc.h
  endif
endif


ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
     COMP_TRACE_DEFS += vendor_sec\security\certicom\adaptation\ssl\include\sslplus5_trc.h
  endif

  ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
     COMP_TRACE_DEFS += vendor_sec\security\certicom\adaptation\ssl\include\sslplus5_trc.h
  endif

  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
     COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_ssl_trc.h
     COMP_TRACE_DEFS += security\openssl\adaptation\ssl\include\ossl_ssladp_trc.h     
  endif

  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
     COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_ssl_trc.h
     COMP_TRACE_DEFS += security\openssl\adaptation\ssl\include\ossl_ssladp_trc.h     
  endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
      ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
        COMP_TRACE_DEFS   +=    ps\rr2\mpal\include\mpal_trace.h
      else
        ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
          COMP_TRACE_DEFS   +=    ps\rr\mpal\include\mpal_trace.h
        endif
        ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
          COMP_TRACE_DEFS   +=    ps\rr\mpal\include\mpal_trace.h
        endif
      endif
    endif
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
  ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
    L1_TMD_FILES   +=    l1_dm\common\l1D_EDGE_trace.tmd
  else
    L1_TMD_FILES   +=    l1\common\l1D_EDGE_trace.tmd
  endif
endif

ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
  L1_TMD_FILES   +=   l1_dm\common\L1D3_Trace.tmd \
                      l1_dm\common\l1c3_Trace.tmd \
                      l1_dm\common\l1c4_Trace.tmd
else
  ifeq ($(call Upper,$(strip $(L1_WCDMA))),TRUE)
    L1_TMD_FILES   +=   l1_dm\common\L1D3_Trace.tmd \
                        l1_dm\common\l1c3_Trace.tmd \
                        l1_dm\common\l1c4_Trace.tmd 
  else
    L1_TMD_FILES   +=   l1\common\L1D3_Trace.tmd \
                        l1\common\l1c3_Trace.tmd \
                        l1\common\l1c4_Trace.tmd
  endif
endif

# ---------------------------------------------------------------
# The followings are global options from $(Customer)_$(Project).bld
# ---------------------------------------------------------------
# Platform Options
COM_DEFS_FOR_MT6208  = MT6208
COM_DEFS_FOR_MT6205  = MT6205 __HW_DIVIDER__
COM_DEFS_FOR_MT6205B = MT6205B __HW_DIVIDER__
COM_DEFS_FOR_FPGA    = FPGA
COM_DEFS_FOR_MT6218  = MT6218  __HW_DIVIDER__
COM_DEFS_FOR_MT6218B = MT6218B __HW_DIVIDER__ MT6218B_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6217  = MT6217 __HW_DIVIDER__ MT6217_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6219  = MT6219 __HW_DIVIDER__ MT6219_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6228  = MT6228 __HW_DIVIDER__ MT6228_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6229  = MT6229 __HW_DIVIDER__ MT6229_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6235  = MT6235 __HW_DIVIDER__ MT6235_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6235B  = MT6235B __HW_DIVIDER__ MT6235B_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6238  = MT6238 __HW_DIVIDER__ MT6238_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6239  = MT6239 __HW_DIVIDER__ MT6239_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6230  = MT6230 __HW_DIVIDER__ MT6230_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6227  = MT6227 __HW_DIVIDER__ MT6227_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6227D = MT6227D __HW_DIVIDER__ MT6227D_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226  = MT6226 __HW_DIVIDER__ MT6226_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226D = MT6226D __HW_DIVIDER__ MT6226D_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226M = MT6226M __HW_DIVIDER__ MT6226M_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6225  = MT6225 __HW_DIVIDER__ MT6225_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6223  = MT6223 __HW_DIVIDER__ MT6223_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6223P  = MT6223P __HW_DIVIDER__ MT6223P_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268T = MT6268T __HW_DIVIDER__ MT6268T_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268H = MT6268H __HW_DIVIDER__ MT6268H_$(strip $(CHIP_VER))
COM_DEFS_FOR_TK6516  = TK6516 __HW_DIVIDER__ TK6516_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6516  = MT6516 __HW_DIVIDER__ MT6516_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6516AP  = MT6516AP __HW_DIVIDER__ MT6516AP_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268A = MT6268A __HW_DIVIDER__ MT6268A_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6268  = MT6268 __HW_DIVIDER__ MT6268_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253T = MT6253T __HW_DIVIDER__ MT6253T_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6253 = MT6253 __HW_DIVIDER__ MT6253_$(strip $(CHIP_VER))

COM_DEFS_FOR_PLATFORM =  COM_DEFS_FOR_$(strip $(PLATFORM))
ifdef $(COM_DEFS_FOR_PLATFORM)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(PLATFORM)))
else
   $(error [COM_DEFS_FOR_$(strip $(PLATFORM))] was not defined)
endif

# RF Module Options
# Move to project.mak except EVB
COM_DEFS_FOR_BRIGHT4                  = BRIGHT4_RF BRIGHT4_EVB
COM_DEFS_FOR_EUROPA                   = MT6129C_RF EUROPA_EVB
COM_DEFS_FOR_FOUNTAIN2                = MT6119C_RF FOUNTAIN2_EVB  FOUNTAIN2_RF
COM_DEFS_FOR_MT6129C                  = MT6129C_RF MT6129C_EVB
COM_DEFS_FOR_MT6129D                  = MT6129D_RF MT6129D_EVB
COM_DEFS_FOR_MT6139B                  = MT6139B_RF MT6139B_EVB
COM_DEFS_FOR_MT6139C                  = MT6139C_RF MT6139C_EVB
COM_DEFS_FOR_MT6139E                  = MT6139E_RF MT6139E_EVB
COM_DEFS_FOR_MT6140A                  = MT6140A_RF MT6140A_EVB
COM_DEFS_FOR_MT6140C                  = MT6140C_RF MT6140C_EVB
COM_DEFS_FOR_MT6140D                  = MT6140D_RF MT6140D_EVB
COM_DEFS_FOR_SKY74117                 = SKY74117_RF SKY74117_EVB
COM_DEFS_FOR_SKY74137                 = SKY74137_RF SKY74137_EVB
COM_DEFS_FOR_SKY74045                 = SKY74045_RF SKY74045_EVB
COM_DEFS_FOR_BRIGHT5P                 = BRIGHT5P_RF BRIGHT5P_EVB
COM_DEFS_FOR_AERO2                    = AERO2_RF   AERO2_EVB
COM_DEFS_FOR_SONY_CXA3359             = SONY_CXA3359_RF SONY_CXA3359_EVB
COM_DEFS_FOR_SMARTI3G                 = SMARTI3G_RF SMARTI3G_EVB
COM_DEFS_FOR_MTKSOC1                  = MTKSOC1_RF MTKSOC1_EVB
COM_DEFS_FOR_MT6160                   = MT6160_RF MT6160_EVB
COM_DEFS_FOR_AD6546                   = AD6546_RF AD6546_EVB
COM_DEFS_FOR_TECHFAITH68_DEMO_MT6160   = MT6160_RF TECHFAITH68_DEMO_MT6160
COM_DEFS_FOR_TECHFAITH68_DEMO_AD6546   = AD6546_RF TECHFAITH68_DEMO_AD6546

# For Customer projects.
COM_DEFS_FOR_MT6140_CUSTOM = MT6140D_RF MT6140_CUSTOM
COM_DEFS_FOR_MT6139_CUSTOM = MT6139E_RF MT6139_CUSTOM
COM_DEFS_FOR_MT6129_CUSTOM = MT6129D_RF MT6129_CUSTOM
COM_DEFS_FOR_AD6548_CUSTOM = AD6548_RF AD6548_CUSTOM
COM_DEFS_FOR_AD6546_CUSTOM = AD6546_RF AD6546_CUSTOM
COM_DEFS_FOR_SKY74137_CUSTOM = SKY74137_RF SKY74137_CUSTOM
COM_DEFS_FOR_UNICORN53_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V2_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V2_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V3_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V3_DEMO_MTKSOC1

CUS_REL_BASE_COMP += custom\l1_rf\MT6140_CUSTOM custom\l1_rf\MT6139_CUSTOM \
                     custom\l1_rf\MT6129_CUSTOM custom\l1_rf\SKY74137_CUSTOM \
                     custom\l1_rf\AD6548_CUSTOM custom\l1_rf\AD6546_CUSTOM

COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(RF_MODULE))
ifdef $(COM_DEFS_FOR_RF_MODULE)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(RF_MODULE)))
else
   $(error [COM_DEFS_FOR_$(strip $(RF_MODULE))] was not defined)
endif

ifdef UMTS_RF_MODULE
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE)))
  else
    $(error [COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))] was not defined)
  endif
endif

# check AFC_VCXO_TYPE matches RF_MODULE
ifdef AFC_VCXO_TYPE
  ifdef RF_MODULE
    VCXO_PLATFORM = MT6140C MT6140D MT6139B MT6139C MT6139E
    ifneq ($(filter $(strip $(RF_MODULE)),$(VCXO_PLATFORM)),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        ifneq ($(strip $(PLATFORM)),MT6268A)
          ifneq ($(strip $(PLATFORM)),MT6268)
            $(error MT6139/MT6140 series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
          endif
        endif
      endif
    endif
        
    ifneq ($(findstring MT6129D,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6129D series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring MT6129,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(error MT6129 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring MT6119,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6119 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring BRIGHT4,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING BRIGHT4 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring MT6140A,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6140A series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring SKY74117,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING SKY74117 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring SKY74045,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING SKY74045 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring BRIGHT5P,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING  BRIGHT5P series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring FOUNTAIN,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING FOUNTAIN series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif

    ifneq ($(findstring AERO,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        $(warning WARNING AERO series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
      endif
    endif
    ifneq ($(findstring MT6139,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        $(warning WARNING MT6139 series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
      endif
    endif
    ifneq ($(findstring MT6140D,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        ifneq ($(strip $(PLATFORM)),MT6268A)
          ifneq ($(strip $(PLATFORM)),MT6268)
            $(error MT6140D series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
          endif
        endif
      endif
    endif
  endif
endif

# Board Options
ifneq ($(strip $(BOARD_VER)),)
   COM_DEFS    += $(BOARD_VER)
endif

# Board Subversion
ifneq ($(strip $(SUB_BOARD_VER)),)
   COM_DEFS    += $(SUB_BOARD_VER)
endif


# LCD Module Options
# Move to project.mak except EVB
COM_DEFS_FOR_KLMLCM            = PCF8833 COLOR_LCD S6B1713 KLMLCM
COM_DEFS_FOR_MTKLCM_COLOR      = S1D15G00 COLOR_LCD MTKLCM_COLOR
COM_DEFS_FOR_NEPTUNE_LCM       = S6B33B1X COLOR_LCD NEPTUNE_LCM STN_MAINLCD
COM_DEFS_FOR_POWERTIP_LCM      = S6B33B1X COLOR_LCD POWERTIP_LCM STN_MAINLCD
COM_DEFS_FOR_SONY_LCM          = SONY_LCM TFT_MAINLCD
COM_DEFS_FOR_TOPPOLY_LCM       = TOPPOLY_LCM TFT_MAINLCD
COM_DEFS_FOR_RENESAS_LCM       = HD66781 COLOR_LCD HD66791 COLOR_SUBLCD DUAL_LCD RENESAS_LCM TFT_MAINLCD
COM_DEFS_FOR_TAURUS_LCM        = S6B33B2A COLOR_LCD S6B0756 TAURUS_LCM
COM_DEFS_FOR_PHOENIX29_LCM     = PHOENIX29_LCM TFT_MAINLCD
COM_DEFS_FOR_FIREFLY_LCM       = WSX6396A COLOR_LCD SSD1773 COLOR_SUBLCD FIREFLY_LCM TFT_MAINLCD STN_SUBLCD
COM_DEFS_FOR_MTK6225_LCM       = MTK6225_LCM TFT_MAINLCD
COM_DEFS_FOR_TOP_6227_LCM      = TOP_6227_LCM TFT_MAINLCD
COM_DEFS_FOR_LIBRA35_LCM       = LIBRA35_LCM TFT_MAINLCD
COM_DEFS_FOR_WISTRON_2P8_WQVGA_LCM = S6D0170 COLOR_LCD WISTRON_2P8_WQVGA_LCM TFT_MAINLCD
COM_DEFS_FOR_AUO_VGA_LCM = SSD1961 COLOR_LCD AUO_VGA_LCM TFT_MAINLCD
COM_DEFS_FOR_TRULY_HVGA_LCM = TA7601 COLOR_LCD TRULY_HVGA_LCM TFT_MAINLCD
COM_DEFS_FOR_UNICORN53_DEMO_LCM = ILI9325DS COLOR_LCD UNICORN53_DEMO_LCM TFT_MAINLCD

COM_DEFS_FOR_LCD_MODULE =  COM_DEFS_FOR_$(strip $(LCD_MODULE))
ifdef $(COM_DEFS_FOR_LCD_MODULE)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(LCD_MODULE)))
else
   $(error No COM_DEFS for LCD_MODULE = $(strip $(LCD_MODULE))!)
endif

# BAND_SUPPORT Options
COM_DEFS_FOR_PGSM900   = __PGSM900__
COM_DEFS_FOR_EGSM900   = __EGSM900__
COM_DEFS_FOR_RGSM900   = __RGSM900__
COM_DEFS_FOR_DCS1800   = __DCS1800__
COM_DEFS_FOR_PCS1900   = __PCS1900__
COM_DEFS_FOR_GSM850    = __GSM850__
COM_DEFS_FOR_GSM450    = __GSM450__
COM_DEFS_FOR_DUAL900   = __EGSM900__ __DCS1800__
COM_DEFS_FOR_TRIPLE    = __EGSM900__ __DCS1800__ __PCS1900__
COM_DEFS_FOR_QUAD      = __EGSM900__ __DCS1800__ __PCS1900__  __GSM850__
COM_DEFS_FOR_DUAL850   = __GSM850__ __PCS1900__
COM_DEFS_FOR_TRIPLE850 = __GSM850__ __DCS1800__ __PCS1900__  TRIPLE850

COM_DEFS_FOR_BAND_SUPPORT =  COM_DEFS_FOR_$(strip $(BAND_SUPPORT))
ifdef $(COM_DEFS_FOR_BAND_SUPPORT)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(BAND_SUPPORT)))
else
   COM_DEFS		+= __EGSM900__ __DCS1800__   # the same as DUAL900
endif



# UMTS_BAND_SUPPORT Options 
ifdef UMTS_BAND_I
    ifeq ($(strip $(UMTS_BAND_I)),TRUE)     
        COM_DEFS           += __UMTS_BAND_I__
    endif
endif
ifdef UMTS_BAND_II
    ifeq ($(strip $(UMTS_BAND_II)),TRUE)     
        COM_DEFS           += __UMTS_BAND_II__
    endif
endif
ifdef UMTS_BAND_III
    ifeq ($(strip $(UMTS_BAND_III)),TRUE)     
        COM_DEFS           += __UMTS_BAND_III__
    endif
endif
ifdef UMTS_BAND_IV
    ifeq ($(strip $(UMTS_BAND_IV)),TRUE)     
        COM_DEFS           += __UMTS_BAND_IV__
    endif
endif
ifdef UMTS_BAND_V
    ifeq ($(strip $(UMTS_BAND_V)),TRUE)     
        COM_DEFS           += __UMTS_BAND_V__
    endif
endif
ifdef UMTS_BAND_VI
    ifeq ($(strip $(UMTS_BAND_VI)),TRUE)     
        COM_DEFS           += __UMTS_BAND_VI__
    endif
endif
ifdef UMTS_BAND_VII
    ifeq ($(strip $(UMTS_BAND_VII)),TRUE)     
        COM_DEFS           += __UMTS_BAND_VII__
    endif
endif
ifdef UMTS_BAND_VIII
    ifeq ($(strip $(UMTS_BAND_VIII)),TRUE)     
        COM_DEFS           += __UMTS_BAND_VIII__
    endif
endif
ifdef UMTS_BAND_IX
    ifeq ($(strip $(UMTS_BAND_IX)),TRUE)     
        COM_DEFS           += __UMTS_BAND_IX__
    endif
endif
ifdef UMTS_BAND_X
    ifeq ($(strip $(UMTS_BAND_X)),TRUE)     
        COM_DEFS           += __UMTS_BAND_X__
    endif
endif


# AFC_VCXO_TYPE Options
COM_DEFS_FOR_VCXO   		= AFC_VCXO
COM_DEFS_FOR_VCXO_SC   	= AFC_VCXO AFC_SC
COM_DEFS_FOR_VCXO_TC   	= AFC_VCXO AFC_TC
COM_DEFS_FOR_VCXO_SC_TC = AFC_VCXO AFC_SC AFC_TC

COM_DEFS_FOR_AFC_VCXO_TYPE =  COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE))
ifdef $(COM_DEFS_FOR_AFC_VCXO_TYPE)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE)))
endif

#
# Check the dependency of each options
#
ifneq ($(strip $(WAP_SUPPORT)),NONE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,WAP_SUPPORT)
  endif
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
    ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),FALSE)
      $(call DEP_ERR_SETA_OR_ONB,WAP_SUPPORT,non OBIGO_Q05A,UNIFIED_MESSAGE_SUPPORT)
    endif
  endif
endif

ifdef WAP_SUPPORT
  ifeq ($(strip $(WAP_SUPPORT)),NONE)
#    ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
#       $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,JATAAYU_FEATURE)
#    endif    
    ifneq ($(strip $(TELECA_FEATURE)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,TELECA_FEATURE)
    endif    
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifeq ($(strip $(WAP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,J2ME_SUPPORT)
    endif
    ifneq ($(strip $(MELODY_VER)),DSP_WT_SYN)
      $(call DEP_ERR_SETA_OR_OFFB,MELODY_VER,DSP_WT_SYN,J2ME_SUPPORT)
    endif
    ifdef PLATFORM
      ifeq ($(strip $(PLATFORM)),MT6223)
        ifneq ($(strip $(J2ME_SUPPORT)),NONE)
          $(error MT6223 does not support J2ME_SUPPORT yet)
        endif
      endif
    endif
  endif
endif

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
  ifeq ($(strip $(WAP_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,IMPS_SUPPORT)
  endif
  ifneq ($(strip $(XML_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,IMPS_SUPPORT)
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
    ifeq ($(strip $(WAP_SUPPORT)),NONE)     
      $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,DRM_SUPPORT)
    endif
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
     ifeq ($(filter FMT_NOT_PRESENT,$(COM_DEFS)),FMT_NOT_PRESENT)
        $(error Please turn off DRM_SUPPORT when FMT_NOT_PRESENT!)     
     endif              
  endif
endif

ifdef  NAND_SUPPORT
ifdef  SYSTEM_DRIVE_ON_NAND
   ifeq ($(strip $(NAND_SUPPORT)),FALSE)
     ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,SYSTEM_DRIVE_ON_NAND)
     endif
   endif
endif
endif

ifdef EMAIL_SUPPORT
ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
    $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,TCP/UDP_TCP,EMAIL_SUPPORT)
  endif
  ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
    $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,TCP/UDP_TCP,EMAIL_SUPPORT)
  endif
endif
endif

ifdef POC_SUPPORT
ifneq ($(strip $(POC_SUPPORT)),NONE)
  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      $(error GSM project does not support POC!)
  endif
  ifeq ($(strip $(SIP_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SIP_SUPPORT,POC_SUPPORT)
  endif
  ifeq ($(strip $(SDP_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SDP_SUPPORT,POC_SUPPORT)
  endif
  ifeq ($(strip $(XDM_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,XDM_SUPPORT,POC_SUPPORT)
  endif
endif
endif

ifdef VOIP_SUPPORT
ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      $(error GSM project does not support VoIP!)
  endif
  ifneq ($(strip $(SIP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SIP_SUPPORT,VOIP_SUPPORT)
  endif
  ifneq ($(strip $(SDP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SDP_SUPPORT,VOIP_SUPPORT)
  endif
  ifneq ($(strip $(L1_WCDMA)),TRUE)
    ifndef WIFI_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,VOIP_SUPPORT)
    endif
    ifeq ($(strip $(WIFI_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,VOIP_SUPPORT)
    endif
  endif
endif
endif

ifdef SIP_SUPPORT
ifneq ($(strip $(SIP_SUPPORT)),FALSE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,SIP_SUPPORT)
  endif
endif
endif


# WIFI_BB_MODULE Options
COM_DEFS_FOR_MT5911       = WIFI_BB_MT5911
COM_DEFS_FOR_MT5921       = WIFI_BB_MT5921
COM_DEFS_FOR_NONE         = WIFI_BB_NONE
COM_DEFS_FOR_None         = WIFI_BB_None

ifdef WIFI_SUPPORT
    COM_DEFS_FOR_WIFI_BB_MODULE =  COM_DEFS_FOR_$(strip $(WIFI_SUPPORT))
    ifdef $(COM_DEFS_FOR_WIFI_BB_MODULE)
        COM_DEFS	+=  $(COM_DEFS_FOR_$(strip $(WIFI_SUPPORT)))
    else
        $(error WIFI_BB_MODULE = $(strip $(WIFI_SUPPORT)) is not defined!)
    endif
endif

# WIFI_RF_MODULE Options
COM_DEFS_FOR_AL2236      = WIFI_RF_AL2236
COM_DEFS_FOR_NONE        = WIFI_RF_NONE
COM_DEFS_FOR_None        = WIFI_RF_None

ifdef WIFI_SUPPORT
  ifeq ($(strip $(WIFI_SUPPORT)),none)
     COM_DEFS	+=  $(COM_DEFS_FOR_None)
  endif
  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
     COM_DEFS	+=  $(COM_DEFS_FOR_NONE)
  endif
  ifeq ($(strip $(WIFI_SUPPORT)),MT5911)
     COM_DEFS	+=  $(COM_DEFS_FOR_AL2236)
  endif
endif

ifdef STREAM_SUPPORT
  ifneq ($(strip $(STREAM_SUPPORT)),FALSE)
    STREAM_NOT_SUPPORT_PLATFORM = MT6205% MT6217 MT6218% MT6219 MT6223% MT6225 MT6226% MT6227% MT6228
    ifneq ($(filter $(strip $(STREAM_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM))),)
      $(error $(strip $(PLATFORM)) does NOT support STREAM_SUPPORT)
    endif
    ifeq ($(strip $(SDP_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,SDP_SUPPORT,STREAM_SUPPORT)
    endif
    ifeq ($(strip $(RTSP_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,RTSP_SUPPORT,STREAM_SUPPORT)
    endif
    ifeq ($(strip $(AAC_DECODE)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,STREAM_SUPPORT)
    endif
    ifndef MP4_DECODE
       $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,STREAM_SUPPORT)
    endif
    ifeq ($(strip $(MP4_DECODE)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,STREAM_SUPPORT)
    endif
    ifeq ($(strip $(WAP_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,STREAM_SUPPORT)
    endif
  endif
endif

ifdef 3G_VIDEO_CALL
  ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
    COMPLIST        += 3g324m
    CUS_REL_MTK_COMP += 3g324m
    COMP_TRACE_DEFS += 3g324m\appl\inc\vt_trc.h
    COM_DEFS   += __CC_VIDEO_CALL__  __3G_VIDEO_CALL__
  endif
endif

ifdef UUS_SUPPORT
  ifeq ($(strip $(UUS_SUPPORT)),TRUE)
     COM_DEFS    += __UUS_SUPPORT__
  endif   
endif

ifdef EMLPP_SUPPORT
  ifeq ($(strip $(EMLPP_SUPPORT)),TRUE)
     COM_DEFS    += __EMLPP_SUPPORT__
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
  COMPLIST += mtv
  COM_DEFS += __MTV_SUPPORT__
  CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\pc\SDL.dll
  CUS_REL_FILES_LIST += MoDIS\MoDIS\Debug\SDL.dll \
                        MoDIS\MoDIS\Release\SDL.dll \
                        media\mtv\src\cmmb_ca_mmc.h
endif

ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
      FLC_LIB_INCLUDE_CONDITION = FALSE
      ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
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
          COMPLIST += flc2
          COMP_TRACE_DEFS += ps\flc2\include\flc_trc.h         
          CUSTOM_COMMINC += ps\flc2\include  
          COM_DEFS += __FLC2__ __FLC_SUPPORT__
      endif
    endif
  endif
endif

ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  COM_DEFS    += __PHB_0x81_SUPPORT__
endif

ifdef SYNCML_DM_SUPPORT
  ifeq ($(strip $(SYNCML_DM_SUPPORT)),TRUE)
    ifndef WAP_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,SYNCML_DM_SUPPORT)
    endif
    ifdef WAP_SUPPORT
      ifeq ($(strip $(WAP_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,SYNCML_DM_SUPPORT)
      endif
    endif
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,SYNCML_DM_SUPPORT)
    endif
  endif
endif


ifdef EMPTY_RESOURCE
  ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
    ifdef MMI_FEATURES_SWITCH
      ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,MMI_FEATURES_SWITCH,EMPTY_RESOURCE)
      endif
    endif
  endif
endif
# Disabled definitions
# COM_DEFS  += MTK_PCM MTK_SLEEP_ENABLE MT6205_SIM GSI_SUPPORT MTK_GSM_ENABLE

# -----------------------------
# Custom Options
# -----------------------------
ifeq ($(call Upper,$(strip $(PROJECT))),UMTS)
   COM_DEFS += __MTK_3G_MRAT_ARCH__
endif

ifeq ($(strip $(PLATFORM)),MT6225)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6253T)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6253)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6223)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6223P)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6235)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__
endif

ifeq ($(strip $(PLATFORM)),MT6235B)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__
endif

ifeq ($(strip $(PLATFORM)),MT6238)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__
endif

ifeq ($(strip $(PLATFORM)),MT6239)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__
endif

ifeq ($(strip $(PLATFORM)),MT6268A)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__
endif

ifeq ($(strip $(PLATFORM)),MT6268)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__ __ARM9_DCACHEABLE__
endif

ifeq ($(strip $(PLATFORM)),MT6268A)
   COM_DEFS    += __3G_AUTO_BAND_MECHANISM__
endif

ifeq ($(strip $(PLATFORM)),MT6268)
   COM_DEFS    += __3G_AUTO_BAND_MECHANISM__
endif

ifeq ($(strip $(L1_CATCHER)),TRUE)
   ifeq ($(strip $(TST_SUPPORT)),TRUE)
      COM_DEFS    += L1_CATCHER
   endif
endif

ifeq ($(strip $(MTK_SLEEP_ENABLE)),TRUE)
   COM_DEFS    += MTK_SLEEP_ENABLE
endif

ifeq ($(strip $(MTK_DSP_DEBUG)),TRUE)
   COM_DEFS    += MTK_DSP_DEBUG
endif

ifeq ($(strip $(FAX_SUPPORT)),TRUE)
  ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
    $(error FAX_SUPPORT cannot be turned on in L1S projects.)
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    $(error FAX_SUPPORT cannot be turned on in BASIC projects.)
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
    $(error FAX_SUPPORT cannot be turned on in MEUT projects.)
  endif
endif

ifdef CSD_SUPPORT
  ifneq ($(strip $(CSD_SUPPORT)),NONE)
    ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
      $(error Please turn off CSD_SUPPORT in $(strip $(call Upper,$(PROJECT))) project)
    endif
    # Support CSD
    COM_DEFS    += CSD_SUPPORT 

    ifeq ($(strip $(CSD_SUPPORT)),T_NT)
      COM_DEFS    += __CSD_NT__ __CSD_T__
    else
      ifeq ($(strip $(CSD_SUPPORT)),NT_ONLY)
        COM_DEFS    += __CSD_NT__ 
      else
        $(error CSD_SUPPORT setting is wrong)
      endif
    endif

    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += __CSD_FAX__
    endif
  else
    # FAX only, Not support CSD
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += CSD_SUPPORT __CSD_FAX__
    endif
  endif
endif

ifndef CSD_SUPPORT
   # FAX only, Not support CSD
   ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += CSD_SUPPORT __CSD_FAX__
   endif
endif

ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
  COM_DEFS += KAL_ENH_MUTEX
else
  ifneq ($(filter __CS_SERVICE__,$(COM_DEFS)),)
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      COM_DEFS    += KAL_ENH_MUTEX
    endif
  endif
endif
   
ifdef PMIC_PRESENT
  ifeq ($(strip $(PMIC_PRESENT)),TRUE)
   	COM_DEFS    += PMIC_PRESENT
  endif
endif

ifdef PMIC
  ifneq ($(strip $(PMIC)),NONE)
     COM_DEFS    += PMIC_PRESENT
  endif
  ifeq ($(strip $(PLATFORM)),MT6205)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6205 only supports MT6305 PMIC, and does not support $(strip $(PMIC)))
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6205B)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6205B only supports MT6305 PMIC, and does not support $(strip $(PMIC)))
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6205C)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6205C only supports MT6305 PMIC, and does not support $(strip $(PMIC)))
      endif
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6235PMU)
    ifneq ($(strip $(PLATFORM)),MT6235)
      ifneq ($(strip $(PLATFORM)),MT6235B)
        $(error $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6235 & MT6235B series chips support $(strip $(PMIC)) PMIC)
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
    ifneq ($(strip $(PMIC)),MT6235PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6235 only supports MT6235PMU PMIC, and does not support $(strip $(PMIC)))
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    ifneq ($(strip $(PMIC)),MT6235PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6235B only supports MT6235PMU PMIC, and does not support $(strip $(PMIC)))
      endif
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6238PMU)
    ifneq ($(strip $(PLATFORM)),MT6238)
      ifneq ($(strip $(PLATFORM)),MT6239)
        $(error $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6238 & MT6239 series chips support $(strip $(PMIC)) PMIC)
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    ifneq ($(strip $(PMIC)),MT6238PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6238 only supports MT6238PMU PMIC, and does not support $(strip $(PMIC)))
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    ifneq ($(strip $(PMIC)),MT6238PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6239 only supports MT6238PMU PMIC, and does not support $(strip $(PMIC)))
      endif
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6223PMU)
    ifneq ($(strip $(PLATFORM)),MT6223)
      ifneq ($(strip $(PLATFORM)),MT6223P)
        $(error $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6223 series chips support $(strip $(PMIC)) PMIC)
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
    ifneq ($(strip $(PMIC)),MT6223PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6223 only supports MT6223PMU PMIC, and does not support $(strip $(PMIC)))
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    ifneq ($(strip $(PMIC)),MT6223PMU)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6223P only supports MT6223PMU PMIC, and does not support $(strip $(PMIC)))
      endif
    endif
  endif
  PMIC_MT6326_SUPPORT_PLATFORM = MT6268A MT6268 
  ifeq ($(strip $(PMIC)),MT6326)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6326_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6253PMU)
    ifneq ($(strip $(PLATFORM)),MT6253T)
      ifneq ($(strip $(PLATFORM)),MT6253)
        $(error $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6253 series chips support $(strip $(PMIC)) PMIC)
      endif
    endif
  endif
endif

ifeq ($(strip $(PMIC)),MT6223PMU)
   COM_DEFS    += MT6223PMU
endif

ifeq ($(strip $(PMIC)),MT6238PMU)
   COM_DEFS    += MT6238PMU
endif

ifeq ($(strip $(PMIC)),MT6235PMU)
   COM_DEFS    += MT6235PMU
endif

ifeq ($(strip $(PMIC)),MT6305)
     COM_DEFS    += MT6305
endif

ifeq ($(strip $(PMIC)),MT6318)
   COM_DEFS    += MT6318
endif

ifeq ($(strip $(PMIC)),MT6326)
   COM_DEFS    += MT6326
endif

ifeq ($(strip $(PMIC)),MT6253PMU)
   COM_DEFS    += MT6253PMU
endif

ifeq ($(strip $(PMIC)),MT6326_CCCI)
   COM_DEFS    += MT6326_CCCI
endif

ifeq ($(strip $(TELECA_FEATURE)),WAP)
   COM_DEFS    += WAP_SUPPORT
else
  ifeq ($(strip $(TELECA_FEATURE)),WAP2)
    COM_DEFS    += WAP_SUPPORT  WAP2
  else
    ifeq ($(strip $(TELECA_FEATURE)),WAP_SEC)
      COM_DEFS    += WAP_SUPPORT  WAP_SEC_SUPPORT
    else
      ifeq ($(strip $(TELECA_FEATURE)),WAP2_SEC)
        COM_DEFS    += WAP_SUPPORT  WAP2  WAP_SEC_SUPPORT
      endif
      ifeq ($(strip $(TELECA_FEATURE)),NONE)
        COM_DEFS    += WAP_NOT_PRESENT
      endif
    endif
  endif
endif

#ifneq ($(strip $(TELECA_FEATURE)),NONE)
#   COM_DEFS    += OBIGO_SUPPORT
#endif


ifdef DRM_SUPPORT
  COMPLIST    += drm
  COMMINCDIRS     +=  applib\misc\include
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
    COMP_TRACE_DEFS += drm\include\drm_trace.h
    ifneq ($(findstring BSCI,$(strip $(DRM_SUPPORT))),)
      BSCI_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6223 MT6223P MT6225 
      ifneq ($(filter $(strip $(PLATFORM)),$(BSCI_NOT_SUPPORT_PLATFORM)),)
        $(error Please set DRM_SUPPORT=MTK and DRM_VESION=V01 for PLATFORM $(strip $(PLATFORM)))
      endif
      COM_DEFS    += __DRM_SUPPORT__ __DRM_BSCI__  __DRM_V01__ __DRM_V02__
      ifneq ($(strip $(PLATFORM)),MT6238)
        ifneq ($(strip $(PLATFORM)),MT6239)
          ifdef STREAM_SUPPORT
            ifdef PURE_AUDIO_SUPPORT
              ifeq ($(strip $(PURE_AUDIO_SUPPORT)),TRUE)
                $(error Please set PURE_AUDIO_SUPPORT as FALSE)
              endif
            endif
            ifeq ($(strip $(STREAM_SUPPORT)),TRUE)
              COM_DEFS   += __DRM_PDCF__
            endif
          endif
        endif
      endif
      ifeq ($(strip $(DRM_SUPPORT)),BSCI)
        COMPLIST    += drmadp_bsci
        CUS_REL_SRC_COMP += drmadp_bsci
        COMPOBJS         += vendor\drm\bsci\bsci.lib
        CUS_REL_OBJ_LIST += vendor\drm\bsci\bsci.lib
        CUS_REL_BASE_COMP += vendor\drm\bsci\inc
        CUS_REL_BASE_COMP += vendor\drm\bsci\src\drmagent-v2\inc
        COMMINCDIRS   +=  vendor\drm\$(strip $(DRM_SUPPORT))\adp\include
      else
        ifeq ($(strip $(DRM_SUPPORT)),BSCI_SRC)
          COMPLIST    += bsci
          CUS_REL_MTK_COMP += bsci
          COMMINCDIRS   +=  vendor\drm\bsci\adp\include
        endif
      endif
    else
      COM_DEFS    += __DRM_SUPPORT__ __DRM_MTK__ __DRM_V01__
      COMPLIST    += drmadp_mtk
      CUS_REL_SRC_COMP += drmadp_mtk
      COMMINCDIRS   +=  vendor\drm\MTK\adp\include
    endif
  endif
endif


ifeq ($(strip $(DRM_VERSION)),V02)
 ifeq ($(strip $(DRM_SUPPORT)),MTK)
   $(error DRM_SUPPORT as MTK does not support DRM_VERSION as V02)
 endif    
endif

ifeq ($(strip $(DRM_VERSION)),ALL)
 ifeq ($(strip $(DRM_SUPPORT)),MTK)
   $(error DRM_SUPPORT as MTK does not support DRM_VERSION as ALL)
 endif    
endif

ifeq ($(strip $(FAST_UART)),TRUE)
	COM_DEFS    += __FAST_UART__
endif



# We can define __TWO_KEY_DETECTION_SWITCHABLE__  when __KBD_JOYSTICK_SUPPORT__ is not defined.
ifeq ($(filter __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
   ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__TWO_KEY_DETECTION_SWITCHABLE__)
      $(call DEP_ERR_OFFA_OR_OFFB,__TWO_KEY_DETECTION_SWITCHABLE__,__KBD_JOYSTICK_SUPPORT__)
  endif
endif

ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    COM_DEFS    += NAND_SUPPORT
  endif
endif

ifdef BOOT_FAT_RESET
  ifeq ($(strip $(BOOT_FAT_RESET)),TRUE)
    COM_DEFS    += __BOOT_FAT_RESET__
  endif
endif

ifdef NAND_SUPPORT
ifdef SYSTEM_DRIVE_ON_NAND
  ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
    SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6217 MT6218B MT6219 MT6227 MT6226 MT6226M MT6225 MT6253T MT6253 MT6223 MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H MT6268A MT6268 
    ifeq ($(filter $(strip $(PLATFORM)) ,$(SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM)),)
           $(error PLATFORM $(strip $(PLATFORM)) does not support SYSTEM_DRIVE_ON_NAND.)
    else
      ifeq ($(strip $(NAND_SUPPORT)),TRUE)
          COM_DEFS    += __FS_SYSDRV_ON_NAND__
      endif
    endif
  endif
endif
endif


ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(error The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.)
    endif
    ifeq ($(strip $(PLATFORM)),MT6205)
      $(error The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.)
    endif
    ifeq ($(strip $(PLATFORM)),MT6208)
      $(error The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.)
    endif
    ifeq ($(strip $(PLATFORM)),MT6223)
      $(error The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.)
    endif
    ifeq ($(strip $(PLATFORM)),MT6223P)
      $(error The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.)
    endif
  endif
endif


ifdef APP_STORAGE_IN_SYS_DRV
  ifeq ($(strip $(APP_STORAGE_IN_SYS_DRV)),FALSE)
     ifdef MMS_SUPPORT
         COM_DEFS    += MMS_IN_LARGE_STORAGE
     endif
     ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
       COM_DEFS   += IMPS_IN_LARGE_STORAGE
     endif
  else
      COM_DEFS    += APP_STORAGE_IN_SYS_DRV
  endif
endif

ifeq ($(strip $(SW_CHANGE_BLOCKING)),TRUE)
   COM_DEFS    += SW_CHANGE_BLOCKING
endif

ifdef FM_RADIO_CHIP
  ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
    COM_DEFS	+= $(FM_RADIO_CHIP)
    COM_DEFS	+= FM_RADIO_ENABLE
    ifdef FM_RADIO_RECORD
      ifeq ($(strip $(FM_RADIO_RECORD)),TRUE)
        COM_DEFS  += FM_RADIO_RECORD
      endif
    endif
    COMPLIST         += fm_drv
    CUS_REL_SRC_COMP += fm_drv
  endif
endif

ifdef MSDC_CARD_SUPPORT_TYPE
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
      MSDC_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6253T MT6253 MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H MT6268A MT6268 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(MSDC_SUPPORT_PLATFORM)),)
          $(error PLATFORM $(strip $(PLATFORM)) does NOT support MSDC_CARD_SUPPORT_TYPE)
      else
           COM_DEFS	+= __FS_CARD_SUPPORT__
         ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_MMC)
           COM_DEFS	+= __MSDC_SD_MMC__
         endif
         ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MS)
           COM_DEFS	+= __MSDC_MS__
         endif
         ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MSPRO)
           COM_DEFS	+= __MSDC_MSPRO__
         endif
      endif
  endif
endif

ifneq ($(strip $(USB_SUPPORT)),TRUE)
    ifneq ($(filter __CHARGER_USB_DETECT_WIHT_ONE_EINT__ ,$(CUSTOM_OPTION)),)
        $(error Please remove __CHARGER_USB_DETECT_WIHT_ONE_EINT__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!)
    endif
    ifneq ($(filter __USB_AND_UART_WITH_ONE_GPIO__ ,$(CUSTOM_OPTION)),)
        $(error Please remove __USB_AND_UART_WITH_ONE_GPIO__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!)
    endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  USB_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6228 MT6229 MT6230 MT6227 MT6226 MT6226M MT6225 MT6253T MT6253 MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H MT6268A MT6268 MT6516 
  ifeq ($(filter $(strip $(PLATFORM)) ,$(USB_SUPPORT_PLATFORM)),)
     $(error PLATFORM $(strip $(PLATFORM)) does not support USB.)
  else
  ifeq ($(strip $(USB_SUPPORT)),TRUE)
     COM_DEFS    += __USB_ENABLE__  __NVRAM_IN_USB_MS__
     ifeq ($(strip $(BOARD_VER)),MT6228_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
     endif
     ifeq ($(strip $(BOARD_VER)),MT6229_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
     endif
     ifeq ($(strip $(BOARD_VER)),MT6229_MGM_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
     endif
     ifeq ($(strip $(BOARD_VER)),MT6230_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
     endif
     ifeq ($(strip $(PLATFORM)),MT6235) 
       COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
     endif
     ifeq ($(strip $(PLATFORM)),MT6235B) 
       COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
     endif
     ifeq ($(strip $(PLATFORM)),MT6238)
       COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
     endif
     ifeq ($(strip $(PLATFORM)),MT6239)
       COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
     endif
     ifeq ($(strip $(PLATFORM)),MT6268A) 
       COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
     endif
     ifeq ($(strip $(PLATFORM)),MT6268) 
       COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
     endif
     ifeq ($(strip $(PLATFORM)),MT6253T) 
       COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
     endif
     ifeq ($(strip $(PLATFORM)),MT6253) 
       COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__ 
     endif
   endif
  endif
endif

WT100K_ROM_SUPPORT_PLATFORM = MT6253 MT6253T 
ifdef WAVETABLE_VER
    ifeq ($(strip $(WAVETABLE_VER)),WT100K_ROM)
        ifeq ($(filter $(strip $(PLATFORM)),$(WT100K_ROM_SUPPORT_PLATFORM)),)
            $(error PLATFORM $(strip $(PLATFORM)) does not support WAVETABLE_VER=WT100K_ROM)
        endif
    endif
endif

ifdef MELODY_VER
  ifeq ($(strip $(MELODY_VER)),NONE)
    ifneq ($(strip $(MED_PROFILE)),MED_MODEM)
      $(error Please do not set MELODY_VER to be NONE or set MED_PROFILE to be MED_MODEM)
    endif
  endif
endif

ifeq ($(strip $(MELODY_VER)),SW_SYN_8K)
   ifneq ($(strip $(PLATFORM)),MT6205B)
     $(error $(strip $(PLATFORM)) does not support MELODY_VER=$(strip $(MELODY_VER)))
   endif
   COM_DEFS	+= $(strip $(WAVETABLE_VER))
endif

ifeq ($(strip $(MELODY_VER)),SW_SYN_16K)
   ifneq ($(strip $(PLATFORM)),MT6205B)
     $(error $(strip $(PLATFORM)) does not support MELODY_VER=$(strip $(MELODY_VER)))
   endif
   COM_DEFS	+= $(strip $(WAVETABLE_VER))
endif

ifeq ($(strip $(MELODY_VER)),EXT_AUDIO_CHIP)
   ifneq ($(strip $(PLATFORM)),MT6205B)
     $(error $(strip $(PLATFORM)) does not support MELODY_VER=$(strip $(MELODY_VER)))
   endif
endif

ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
#  DSP_WT_SYN_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
#  ifneq ($(filter $(strip $(PLATFORM)),$(DSP_WT_SYN_NOT_SUPPORT_PLATFORM)),)
#     $(error Chip version $(strip $(PLATFORM)) does not support MELODY_VER=DSP_WT_SYN)
#  endif
   ifeq ($(strip $(PLATFORM)),MT6205B)
     $(error $(strip $(PLATFORM)) does not support MELODY_VER=$(strip $(MELODY_VER)))
  endif
   COM_DEFS	+= $(strip $(WAVETABLE_VER))
endif


ifdef DEDI_AMR_REC
  DEDI_AMR_REC_NOT_SUPPORT_PLATFORM = MT6205B MT6223 MT6223P
  ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(DEDI_AMR_REC_NOT_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support DEDI_AMR_REC=TRUE)
    endif
    ifndef AMR_CODEC
      $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,DEDI_AMR_REC)
    else
      ifneq ($(strip $(AMR_CODEC)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,DEDI_AMR_REC)
      endif
    endif
    COM_DEFS	+= DEDI_AMR_REC
  endif
endif

ifdef VR_ENGINE
  ifneq ($(strip $(VR_ENGINE)),NONE)
    COM_DEFS	+= $(VR_ENGINE)
  endif

  ifeq ($(strip $(VR_ENGINE)),VR_CYBERON)
     COMPOBJS    += l1audio\obj\BSR_Shell.lib
     CUS_REL_OBJ_LIST += l1audio\obj\BSR_Shell.lib
     COM_DEFS	+= VR_ENABLE
  endif


  ifeq ($(strip $(VR_ENGINE)),VRSI_CYBERON)
    COM_DEFS += VRSI_ENABLE
    ifeq ($(strip $(VRSI_LANGUAGE)),CYBERON_CNBI)
      COMPOBJS    += l1audio\obj\BSR_SI_Shell_CNBI.lib
      CUS_REL_OBJ_LIST += l1audio\obj\BSR_SI_Shell_CNBI.lib
      COM_DEFS += CYBERON_CNBI
    else
      COMPOBJS    += l1audio\obj\BSR_SI_Shell_TWBI.lib
      CUS_REL_OBJ_LIST    += l1audio\obj\BSR_SI_Shell_TWBI.lib
      COM_DEFS += CYBERON_TWBI
    endif
  endif
endif

ifdef PROJECT
  ifdef TCPIP_SUPPORT
    ifeq ($(strip $(TCPIP_SUPPORT)),TCP)
      COM_DEFS   += TCP_SUPPORT
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
      COM_DEFS   += UDP_SUPPORT
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
      COM_DEFS   += UDP_SUPPORT TCP_SUPPORT
    endif
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      COM_DEFS   += __TCPIP__
      ifneq ($(strip $(TCPIP_LOOP_SUPPORT)),FALSE)
        COM_DEFS += __TCPIP_LOOP_BACK__
      endif
    endif
    ifeq ($(call Upper,$(strip $(PROJECT))),UMTS)
      ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
        COMPLIST    += abm soc tcpip applib_inet
      else
        COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
      endif
    endif
    ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
      ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
        COMPLIST    += abm soc tcpip applib_inet
      else
        COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
      endif
    endif
    ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
        COMPLIST    += abm soc tcpip ppp applib_inet
      else
        COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT PPP_NOT_PRESENT
      endif
    endif
  endif
else
  $(error PROJECT is not defined!)
endif

ifndef FS_SORT_MAX_ENTRY
  FS_SORT_MAX_ENTRY = 256
endif

ifdef FS_SORT_MAX_ENTRY
  FS_SORT_MAX_ENTRY_PLATFORM = MT6228 MT6229 MT6230 MT6235 MT6235B MT6238 MT6239 MT6253 MT6268
  ifneq ($(filter $(strip $(PLATFORM)),$(FS_SORT_MAX_ENTRY_PLATFORM)),)
    ifeq ($(call gt,$(strip $(FS_SORT_MAX_ENTRY)),20000),T)
      $(error FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be larger than 20000)
    endif
    ifeq ($(call lt,$(strip $(FS_SORT_MAX_ENTRY)),64),T)
      $(error FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be less than 64)
    endif
  else
    ifeq ($(call gt,$(strip $(FS_SORT_MAX_ENTRY)),256),T)
      $(error FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be larger than 256)
    endif
    ifeq ($(call lt,$(strip $(FS_SORT_MAX_ENTRY)),64),T)
      $(error FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be less than 64)
    endif
  endif
endif

ifdef FS_SORT_SUPPORT
  ifeq ($(strip $(FS_SORT_SUPPORT)),TRUE)
    COM_DEFS   += __FS_SORT_SUPPORT__ FS_SORT_MAX_ENTRY=$(strip $(FS_SORT_MAX_ENTRY))
  endif
endif

ifdef FS_CHECKDRIVE_SUPPORT
  ifeq ($(strip $(FS_CHECKDRIVE_SUPPORT)),TRUE)
    COM_DEFS   += __FS_CHECKDRIVE_SUPPORT__
  else
    ifeq ($(strip $(NAND_SUPPORT)), TRUE)
      $(warning WARNING recommend set FS_CHECKDRIVE_SUPPORT=TRUE when NAND_SUPPORT=TRUE)
    else
      ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)), NONE)
        $(warning WARNING recommend set FS_CHECKDRIVE_SUPPORT=TRUE when MSDC_CARD_SUPPORT_TYPE!=NONE)
      endif
    endif
  endif
endif

ifdef FS_QM_SUPPORT
  ifeq ($(strip $(FS_QM_SUPPORT)),TRUE)
    COM_DEFS   += __FS_QM_SUPPORT__
  endif
endif

ifdef TST_SUPPORT
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      $(error TST_SUPPORT should be FALSE in BASIC project)
    endif
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      $(error TST_SUPPORT should be FALSE in MEUT project)
    endif
  endif
endif
  
ifdef FS_TRACE_SUPPORT
  ifdef TST_SUPPORT
    ifdef PRODUCTION_RELEASE
      ifeq ($(strip $(FS_TRACE_SUPPORT)),TRUE)
        ifeq ($(strip $(TST_SUPPORT)),TRUE)
          ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
             COM_DEFS   += __FS_TRACE_SUPPORT__
          else
            $(call DEP_ERR_OFFA_OR_OFFB,PRODUCTION_RELEASE,FS_TRACE_SUPPORT)
          endif
        else
          $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,FS_TRACE_SUPPORT)
        endif
      endif
    endif
  endif
endif

ifdef AMRWB_ENCODE
  ifeq ($(strip $(AMRWB_ENCODE)),TRUE)
    AMRWB_ENCODE_NOT_SUPPORT_PLATFORM = MT6205B MT6218 MT6208 MT6218B MT6217 MT6219 MT6223 MT6223P
    ifneq ($(filter $(strip $(PLATFORM)),$(AMRWB_ENCODE_NOT_SUPPORT_PLATFORM)),)
      $(error Platform $(strip $(PLATFORM)) not support AMRWB_ENCODE!)
    endif
    COM_DEFS   += AMRWB_ENCODE
  endif
endif

ifdef AMRWB_DECODE
  ifeq ($(strip $(AMRWB_DECODE)),TRUE)
    AMRWB_DECODE_NOT_SUPPORT_PLATFORM = MT6205B MT6218 MT6208 MT6218B MT6217 MT6223 MT6223P
    ifneq ($(filter $(strip $(PLATFORM)),$(AMRWB_DECODE_NOT_SUPPORT_PLATFORM)),)
      $(error Platform $(strip $(PLATFORM)) not support AMRWB_DECODE!)
    endif
    COM_DEFS   += AMRWB_DECODE
  endif
endif

ifdef EES_ENABLE
  ifeq ($(strip $(EES_ENABLE)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(error Platform $(strip $(PLATFORM)) does not support EES_ENABLE!)
    endif
    COM_DEFS    += EES_ENABLE
  else
    ifneq ($(strip $(PLATFORM)),MT6205B)
      $(error EES_ENABLE is a mandatory feature. Please turn on EES_ENABLE!)
    endif
  endif
endif

ifdef AEC_ENABLE
  ifeq ($(strip $(AEC_ENABLE)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(error Platform $(strip $(PLATFORM)) does not support AEC_ENABLE!)
    endif
    COM_DEFS    += AEC_ENABLE
  else
    ifneq ($(strip $(PLATFORM)),MT6205B)
      $(error AEC_ENABLE is a mandatory feature. Please turn on AEC_ENABLE!)
    endif
  endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
     COM_DEFS    += __EMAIL__  __EMAIL_AUTO_CHECK__ __POP3_LEAVE_COPY_ON_SERVER__
     COM_DEFS    += __EMAIL_DOWNLOAD_OPTION__  EMAIL_BCC  __EMAIL_USE_ASM_ADM__

     ifeq ($(strip $(EMAIL_SUPPORT)),SMTP_POP3)
        COM_DEFS    += __NO_IMAP__
     endif
  endif
endif



#BT_A2DP_PROFILE was not supported on MT6205/6217/6218/6219/6223 platforms
ifdef BT_A2DP_PROFILE
  ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
    BT_A2DP_PROFILE_NOT_SUPPORT_PLATFORM = MT6205 MT6217 MT6218 MT6219 MT6223 MT6223P 
    ifneq ($(filter $(strip $(PLATFORM)),$(BT_A2DP_PROFILE_NOT_SUPPORT_PLATFORM)),)
      $(error Platform $(strip $(PLATFORM)) does not support BT_A2DP_PROFILE!)
    endif
  endif
endif

#BT_AVRCP_PROFILE was not supported on MT6205/6217/6218/6219/6223 platforms
ifdef BT_AVRCP_PROFILE
  ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      BT_AVRCP_PROFILE_NOT_SUPPORT_PLATFORM = MT6205 MT6217 MT6218 MT6219 MT6223 MT6223P 
      ifneq ($(filter $(strip $(PLATFORM)),$(BT_AVRCP_PROFILE_NOT_SUPPORT_PLATFORM)),)
          $(error Platform $(strip $(PLATFORM)) does not support BT_AVRCP_PROFILE!)
      endif
  endif
endif

ifdef MERCURY_SLAVE_BT_SUPPORT
  ifeq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),TRUE)
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,MERCURY_SLAVE_BT_SUPPORT)
    endif
  endif
endif  

ifeq ($(strip $(BT_SEQ_SUPPORT)),TRUE)
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SEQ_SUPPORT)
    endif
    ifndef BLUETOOTH_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SEQ_SUPPORT)
    endif
    COM_DEFS    +=  __BT_SEQ_SUPPORT__
endif

BLUETOOTH_SUPPORT_CHIP = BTMTK_MT6601 BTMTK_MT6611 BTMTK_MT6612
# NONE, BTMTK, BTMTK_MT6601, BTMTK_MT6612
ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    COM_DEFS    +=  __BT_SUPPORT__ __NEW_BT_PATCH__
    ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DMA_UART_VIRTUAL_FIFO,BLUETOOTH_SUPPORT)
    endif
    ifdef CMUX_SUPPORT
      ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,CMUX_SUPPORT,BLUETOOTH_SUPPORT)
      endif
    endif
    ifneq ($(strip $(UART3_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,UART3_SUPPORT,BLUETOOTH_SUPPORT)
    endif

    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_RFMD3500__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6601__
    endif    
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6611__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612)
      COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6612__
    endif
    ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_HFG_PROFILE__ __BT_SPK_VOL_CONTROL__
      ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
        COM_DEFS    +=  __HF_V15__
      endif
      ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
        COM_DEFS    +=  __HF_V15__
      endif
    endif
    ifeq ($(strip $(BT_AUDIO_VIA_SCO)),TRUE)
      BT_AUDIO_VIA_SCO_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 MT6516 
      ifneq ($(filter $(strip $(PLATFORM)),$(BT_AUDIO_VIA_SCO_NOT_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support BT_AUDIO_VIA_SCO)
      endif
      COM_DEFS    +=  __BT_AUDIO_VIA_SCO__
      COM_DEFS    +=  __BT_INBAND_RING__
    endif
    ifeq ($(strip $(BT_FM_RADIO_VIA_SCO)),TRUE)
      ifdef FM_RADIO_CHIP
        ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
          COM_DEFS    +=  __BT_FM_VIA_SCO__
        endif
      endif
    endif
    ifeq ($(strip $(BT_FTS_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_FTS_PROFILE__
    endif
    ifeq ($(strip $(BT_FTC_PROFILE)),TRUE)
      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,BT_FTC_PROFILE)
      endif
      COM_DEFS    +=  __BT_FTC_PROFILE__
    endif
    ifeq ($(strip $(BT_OPP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_OPP_PROFILE__
    endif
    ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_DUN_PROFILE__
    endif

    ifeq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
      ifneq ($(strip $(BT_SPP_SERVER)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,BLUETOOTH_SUPPORT,BTMTK_MT6601/BTMTK_MT6611/BTMTK_MT6612,BT_SPP_SERVER)
      endif
      ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
       $(call DEP_ERR_SETA_OR_OFFB,BLUETOOTH_SUPPORT,BTMTK_MT6601/BTMTK_MT6611/BTMTK_MT6612,BT_SPP_CLIENT)
      endif
    endif
    
    ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
      ifeq ($(strip $(BT_SPP_SERVER)),NONE)
        ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
          ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
            $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_SERVER & BT_SPP_CLIENT,BT_SPP_PROFILE)
          endif
        endif
      endif
      ifneq ($(strip $(BT_SPP_SERVER)),NONE)
        ifeq ($(strip $(BT_SPP_PROFILE)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_SPP_SERVER)
        endif
      endif
      ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
        ifeq ($(strip $(BT_SPP_PROFILE)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_SPP_CLIENT)
        endif
      endif
    endif
          
    ifneq ($(filter $(strip $(BLUETOOTH_SUPPORT)),$(BLUETOOTH_SUPPORT_CHIP)),)
      ifeq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_NO_SCO)
        COM_DEFS    +=  __BT_SPP_SRV_NO_SCO__
      endif
      ifeq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_WITH_SCO)
        COM_DEFS    +=  __BT_SPP_SRV_WITH_SCO__
      endif
      ifeq ($(strip $(BT_SPP_CLIENT)),BT_SPP_CLI_NO_SCO)
        COM_DEFS    +=  __BT_SPP_CLI_NO_SCO__
      endif
      ifeq ($(strip $(BT_SPP_CLIENT)),BT_SPP_CLI_WITH_SCO)
        COM_DEFS    +=  __BT_SPP_CLI_WITH_SCO__
      endif
    endif

    ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_SPP_PROFILE__
    endif
    ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_A2DP_PROFILE__ __BT_A2DP_SUPPORT__
    endif
    ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_AVRCP_PROFILE__
    endif
    ifeq ($(strip $(BT_SIM_PROFILE)),TRUE)
      ifeq ($(strip $(R5_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,BT_SIM_PROFILE,R5_SUPPORT)
      endif
      COM_DEFS    +=  __BT_SIM_PROFILE__
    endif
    ifeq ($(strip $(BT_HIDD_PROFILE)),TRUE)
      COM_DEFS    +=  __BT_HIDD_PROFILE__
    endif
    ifeq ($(strip $(BT_BPP_PROFILE)),TRUE)
      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,BT_BPP_PROFILE)
      endif
      COM_DEFS    +=  __BT_BPP_PROFILE__
    endif
    ifeq ($(strip $(BT_BIP_PROFILE)),TRUE)
      ifneq ($(strip $(XML_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,BT_BIP_PROFILE)
      endif
      ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128)
        $(call DEP_ERR_SETA_OR_OFFB,MAIN_LCD_SIZE,non 128X128,BT_BIP_PROFILE)
      endif
      COM_DEFS    +=  __BT_BIP_PROFILE__
    endif
  else
    ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_HFG_PROFILE)
    endif
    ifeq ($(strip $(BT_FTS_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_FTS_PROFILE)
    endif
    ifeq ($(strip $(BT_FTC_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_FTC_PROFILE)
    endif
    ifeq ($(strip $(BT_OPP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_OPP_PROFILE)
    endif
    ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_DUN_PROFILE)
    endif
    ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_A2DP_PROFILE)
    endif
    ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_AVRCP_PROFILE)
    endif
    ifneq ($(strip $(BT_SPP_SERVER)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPP_SERVER)
    endif
    ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPP_CLIENT)
    endif
    ifeq ($(strip $(BT_BIP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_BIP_PROFILE)
    endif
    ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_SPP_PROFILE)
    endif
    ifeq ($(strip $(BT_FM_RADIO_VIA_SCO)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_FM_RADIO_VIA_SCO)
    endif
    ifeq ($(strip $(BT_HIDD_PROFILE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_HIDD_PROFILE)
    endif
  endif
endif

ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_HFG_PROFILE)
  endif
  ifneq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_NO_SCO)
    $(call DEP_ERR_SETA_OR_OFFB,BT_SPP_SERVER,BT_SPP_SRV_NO_SCO,BT_HFG_PROFILE)
  endif  
endif

ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_DUN_PROFILE)
  endif
  ifeq ($(strip $(BT_SPP_SERVER)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_SERVER,BT_DUN_PROFILE)
  endif  
endif

ifeq ($(strip $(BT_FAX_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_PROFILE,BT_FAX_PROFILE)
  endif
  ifeq ($(strip $(BT_SPP_SERVER)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_SERVER,BT_FAX_PROFILE)
  endif  
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(BLUETOOTH_VERSION)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_VERSION,BLUETOOTH_SUPPORT)
    endif
  endif
endif

ifdef BLUETOOTH_VERSION
  ifneq ($(strip $(BLUETOOTH_VERSION)),NONE)
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BLUETOOTH_VERSION)
    endif
    ifeq ($(strip $(BLUETOOTH_VERSION)),BT_VER_21)
      COM_DEFS    +=  __BT_VER_21__
    endif
  endif
endif

ifdef JPG_DECODE
  ifneq ($(strip $(JPG_DECODE)),NONE)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(error NEPTUNE_MMI does not support JPG_DECODE, please set JPG_DECODE=NONE)
    endif
    COM_DEFS    += JPG_DECODE
  endif
endif

# only MT6238 supports PNG_HW
PNG_DECODE_HW_PLATFORM = MT6238 MT6239 MT6268A MT6268 
ifdef PNG_DECODE
  ifeq ($(filter $(strip $(PLATFORM)) ,$(PNG_DECODE_HW_PLATFORM)),)
    ifeq ($(strip $(PNG_DECODE)),PNG_HW)
      $(error $(strip $(PLATFORM)) does not support PNG_HW)
    endif
  endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
  PNG_DECODE_HW_NOT_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6235 MT6235B MT6225 MT6253T MT6253 MT6223 MT6223P
  ifeq ($(strip $(PNG_DECODE)),PNG_HW)
    ifneq ($(filter $(strip $(PLATFORM)),$(strip $(PNG_DECODE_HW_NOT_SUPPORT_PLATFORM))),)
      $(error $(strip $(PLATFORM)) does NOT support PNG_DECODE=$(strip $(PNG_DECODE)))
    endif
  endif

  JPG_CODEC_HW_NOT_SUPPORT_PLATFORM = MT6225 MT6253T MT6253 MT6223 MT6223P
  ifeq ($(strip $(JPG_DECODE)),JPG_HW)
    ifneq ($(filter $(strip $(PLATFORM)),$(strip $(JPG_CODEC_HW_NOT_SUPPORT_PLATFORM))),)
      $(error $(strip $(PLATFORM)) does NOT support JPG_DECODE=$(strip $(JPG_DECODE)))
    endif
  endif
  ifeq ($(strip $(JPG_ENCODE)),JPG_HW)
    ifneq ($(filter $(strip $(PLATFORM)),$(strip $(JPG_CODEC_HW_NOT_SUPPORT_PLATFORM))),)
      $(error $(strip $(PLATFORM)) does NOT support JPG_ENCODE=$(strip $(JPG_ENCODE)))
    endif
  endif
endif


ifdef GIF_DECODE
  ifeq ($(strip $(GIF_DECODE)),TRUE)
    COM_DEFS    += GIF_DECODE
  endif
  ifdef PLATFORM
    GIF_DECODE_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6223 MT6223P MT6225 MT6235 MT6235B MT6238 MT6239
    ifeq ($(strip $(GIF_DECODE)),TRUE)
      ifneq ($(filter $(strip $(PLATFORM)),$(GIF_DECODE_NOT_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support hardware GIF decoder, please set GIF_DECODE to FALSE)
      endif
      ifeq ($(strip $(PLATFORM)),MT6219)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif    
      ifeq ($(strip $(PLATFORM)),MT6226)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6226M)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6226D)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6227)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6227D)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V1
      endif
      ifeq ($(strip $(PLATFORM)),MT6228)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6229)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6230)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6268T)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6268H)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V2
      endif
      ifeq ($(strip $(PLATFORM)),MT6268A)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V3
      endif
      ifeq ($(strip $(PLATFORM)),MT6268)
        COM_DEFS    +=   USE_HW_GIF_DECODER_V3
      endif
    endif
  endif
endif


ifdef PNG_DECODE
  ifneq ($(strip $(PNG_DECODE)),NONE)
    PNG_HW_DECODE_SUPPORT_PLATFORM = MT6238 MT6239 MT6268 MT6268A 
    ifeq ($(strip $(PNG_DECODE)),PNG_HW)
      ifeq ($(filter $(strip $(PLATFORM)),$(PNG_HW_DECODE_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support PNG_DECODE)
      else
        COM_DEFS    += USE_HW_PNG_DECODER
      endif
    else
      ifeq ($(strip $(PNG_DECODE)),PNG_SW)
        COM_DEFS    += USE_SW_PNG_DECODER
      endif
    endif
  endif
endif


# sw_jpeg_code only release OBJ!! 
##  CUS_REL_BASE_COMP   +=  image_codec\sw_jpeg_codec 
##  CUS_REL_BASE_COMP   +=  image_codec\common 

ifeq ($(strip $(JPG_DECODE)),JPG_SW)
#  COMPLIST    += sw_jpeg_codec
#  CUS_REL_MTK_COMP  += sw_jpeg_codec
  COM_DEFS    += __SW_JPEG_CODEC_SUPPORT__
  COMMINCDIRS   +=  image_codec\sw_jpeg_codec\include
else
  ifeq ($(strip $(JPG_ENCODE)),JPG_SW)
#    COMPLIST    += sw_jpeg_codec
#    CUS_REL_MTK_COMP  += sw_jpeg_codec
    COM_DEFS    += __SW_JPEG_CODEC_SUPPORT__
    COMMINCDIRS   +=  image_codec\sw_jpeg_codec\include
  endif
endif


ifeq ($(strip $(DAF_DECODE)),TRUE)
   DAF_DECODE_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6226M MT6228 MT6229 MT6230 MT6226 MT6227 MT6225 MT6253T MT6253 MT6223 MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H MT6268A MT6268 
  ifeq ($(filter $(strip $(PLATFORM)) ,$(DAF_DECODE_SUPPORT_PLATFORM)),)
    $(error PLATFORM $(strip $(PLATFORM)) does not support DAF_DECODE.)
  endif
  ifeq ($(strip $(COMPILER)),ADS)
    COMPOBJS         += l1audio\mp3frmlen\mp3frmlen.a
    CUS_REL_OBJ_LIST += l1audio\mp3frmlen\mp3frmlen.a
  endif
  ifeq ($(strip $(COMPILER)),RVCT)
    COMPOBJS         += l1audio\mp3frmlen\mp3frmlen_rvct.a
    CUS_REL_OBJ_LIST += l1audio\mp3frmlen\mp3frmlen_rvct.a
  endif  
  COM_DEFS += DAF_DECODE
endif


## MT6217, 6219, 6227_S00 and 6228_S00, 6228_S01 and 6229_S00, 6223 not support MUSICAM_DECODE
ifdef MUSICAM_DECODE
  MUSICAM_DECODE_NOT_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6223
  ifeq ($(strip $(MUSICAM_DECODE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(MUSICAM_DECODE_NOT_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) not support MUSICAM_DECODE.)
    endif  
    ifeq ($(strip $(PLATFORM)),MT6227)
      ifeq ($(strip $(CHIP_VER)),S00)  
        $(error platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)  
      endif      
    endif
    ifeq ($(strip $(PLATFORM)),MT6228)
      ifeq ($(strip $(CHIP_VER)),S00)  
        $(error platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)  
      endif      
      ifeq ($(strip $(CHIP_VER)),S01)  
        $(error platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)  
      endif          
    endif
    ifeq ($(strip $(PLATFORM)),MT6229)
      ifeq ($(strip $(CHIP_VER)),S00)  
        $(error platform $(strip $(PLATFORM)) with chip version $(CHIP_VER) not support MUSICAM_DECODE.)  
      endif      
    endif

    ifeq ($(strip $(DAF_DECODE)),TRUE)
      COM_DEFS    += MUSICAM_DECODE
    else
      $(call DEP_ERR_ONA_OR_OFFB,DAF_DECODE,MUSICAM_DECODE)
    endif
  endif
endif


ifneq ($(strip $(JPG_ENCODE)),NONE)
  COM_DEFS    += JPG_ENCODE
endif

ifeq ($(strip $(AAC_DECODE)),TRUE)
   AAC_DECODE_SUPPORT_PLATFORM = MT6219 MT6226M MT6228 MT6229 MT6230 MT6226 MT6227 MT6225 MT6253T MT6253 MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H MT6268A MT6268 
   ifeq ($(filter $(strip $(PLATFORM)) ,$(AAC_DECODE_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) not support AAC_DECODE.)
   endif
   COM_DEFS    += AAC_DECODE
endif

ifeq ($(strip $(ISP_SUPPORT)),TRUE)
  COM_DEFS    += ISP_SUPPORT
endif

ifdef SENSOR_TYPE
  ifneq ($(strip $(SENSOR_TYPE)),NONE)
    ifdef CMOS_SENSOR   
      ifneq ($(strip $(CMOS_SENSOR)),NONE)
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          COM_DEFS += RAW_MAIN_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          COM_DEFS += YUV_MAIN_CAMERA
        endif
      endif
    endif    
    ifdef CMOS_SENSOR_BAK1   
      ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          COM_DEFS += RAW_BAK1_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          COM_DEFS += YUV_BAK1_CAMERA
        endif
      endif
    endif  
  endif
endif

ifdef SENSOR_TYPE_SUB
  ifneq ($(strip $(SENSOR_TYPE_SUB)),NONE)
    ifdef CMOS_SENSOR_SUB
      ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COM_DEFS += RAW_SUB_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COM_DEFS += YUV_SUB_CAMERA
        endif
      endif
    endif  
    ifdef CMOS_SENSOR_SUB_BAK1 
      ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COM_DEFS += RAW_SUB_BAK1_CAMERA
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COM_DEFS += YUV_SUB_BAK1_CAMERA
        endif
      endif
    endif  
  endif
endif

ifdef CMOS_SENSOR
  ifneq ($(strip $(CMOS_SENSOR)),NONE)
    COM_DEFS += CMOS_SENSOR_MAIN $(strip $(CMOS_SENSOR))_$(strip $(SENSOR_TYPE)) $(strip $(CMOS_SENSOR))_$(strip $(SENSOR_TYPE))_MAIN
  endif
  ifeq ($(strip $(CMOS_SENSOR)),NONE)
    ifdef ISP_SUPPORT
      ifeq ($(strip $(ISP_SUPPORT)),TRUE)
        $(error Please set ISP_SUPPORT = FALSE when CMOS_SENSOR = NONE )
      endif
    endif
  endif
endif

ifdef LENS_MODULE
  ifneq ($(strip $(LENS_MODULE)),NONE)
    ifndef AF_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,LENS_MODULE)
    endif
    ifeq ($(strip $(AF_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,LENS_MODULE)
    endif
    ifndef CMOS_SENSOR
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,LENS_MODULE)
    endif
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,LENS_MODULE)
    endif
    COMMINCDIRS    +=	custom\drv\lens_module\$(strip $(LENS_MODULE))
    COM_DEFS += $(strip $(LENS_MODULE)) 
  endif
endif

ifdef LENS_MODULE_BAK1
  ifneq ($(strip $(LENS_MODULE_BAK1)),NONE)
    ifndef CMOS_SENSOR_BAK1
      $(error Please define CMOS_SENSOR_BAK1 when LENS_MODULE_BAK1 is defined)
    endif
    ifeq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1,LENS_MODULE_BAK1)
    endif
    COMMINCDIRS    +=	custom\drv\lens_module\$(strip $(LENS_MODULE_BAK1))
    COM_DEFS += $(strip $(LENS_MODULE_BAK1)) 
  endif
endif

ifdef CMOS_SENSOR_SUB
  ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
    ifeq ($(strip $(DUAL_CAMERA_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,DUAL_CAMERA_SUPPORT,CMOS_SENSOR_SUB)
    endif
    ifndef SENSOR_TYPE_SUB
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB)
    else
      ifeq ($(strip $(SENSOR_TYPE_SUB)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB)
      else
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COMMINCDIRS += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB))
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COMMINCDIRS  +=	custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB))
        endif
      endif
    endif
    COM_DEFS += CMOS_SENSOR_SUB $(strip $(CMOS_SENSOR_SUB))_$(strip $(SENSOR_TYPE_SUB)) $(strip $(CMOS_SENSOR_SUB))_$(strip $(SENSOR_TYPE_SUB))_SUB
  endif
endif

ifdef CMOS_SENSOR_BAK1
  ifndef LENS_MODULE_BAK1
    $(error Please define LENS_MODULE_BAK1 when CMOS_SENSOR_BAK1 is defined)
  endif
  ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
    ifndef BACKUP_SENSOR_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_BAK1)
    else
      ifeq ($(strip $(BACKUP_SENSOR_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_BAK1)
      endif
    endif
    ifndef SENSOR_TYPE
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,CMOS_SENSOR_BAK1)
    else
      ifeq ($(strip $(SENSOR_TYPE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE,CMOS_SENSOR_BAK1)
      else
        ifeq ($(strip $(SENSOR_TYPE)),RAW)
          COMMINCDIRS += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_BAK1))
        endif
        ifeq ($(strip $(SENSOR_TYPE)),YUV)
          COMMINCDIRS  +=	custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_BAK1))
        endif
      endif
    endif    
    COM_DEFS += CMOS_SENSOR_BAK1 $(strip $(CMOS_SENSOR_BAK1))_$(strip $(SENSOR_TYPE)) $(strip $(CMOS_SENSOR_BAK1))_$(strip $(SENSOR_TYPE))_BAK1
  endif
endif

ifdef CMOS_SENSOR_SUB_BAK1
  ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
    ifndef BACKUP_SENSOR_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_SUB_BAK1)
    else
      ifeq ($(strip $(BACKUP_SENSOR_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_SUB_BAK1)
      endif
    endif
    ifndef SENSOR_TYPE_SUB
      $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB_BAK1)
    else
      ifeq ($(strip $(SENSOR_TYPE_SUB)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SENSOR_TYPE_SUB,CMOS_SENSOR_SUB_BAK1)
      else
        ifeq ($(strip $(SENSOR_TYPE_SUB)),RAW)
          COMMINCDIRS += custom\drv\image_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
        endif
        ifeq ($(strip $(SENSOR_TYPE_SUB)),YUV)
          COMMINCDIRS  +=	custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR_SUB_BAK1))
        endif
      endif
    endif    
    COM_DEFS += CMOS_SENSOR_SUB_BAK1 $(strip $(CMOS_SENSOR_SUB_BAK1))_$(strip $(SENSOR_TYPE_SUB)) $(strip $(CMOS_SENSOR_SUB_BAK1))_$(strip $(SENSOR_TYPE_SUB))_SUB_BAK1
  endif
endif

ifdef DUAL_CAMERA_SUPPORT
  ifeq ($(strip $(DUAL_CAMERA_SUPPORT)),TRUE)
    ifndef CMOS_SENSOR_SUB
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_SUB,DUAL_CAMERA_SUPPORT)
    else
      ifeq ($(strip $(CMOS_SENSOR_SUB)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_SUB,DUAL_CAMERA_SUPPORT)
      endif
    endif
    COM_DEFS += DUAL_CAMERA_SUPPORT
  else
    ifneq ($(strip $(CMOS_SENSOR_SUB)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,DUAL_CAMERA_SUPPORT,CMOS_SENSOR_SUB)
    endif
  endif
endif

ifdef BACKUP_SENSOR_SUPPORT
  ifeq ($(strip $(BACKUP_SENSOR_SUPPORT)),TRUE)
    ifndef CMOS_SENSOR_BAK1
      ifndef CMOS_SENSOR_SUB_BAK1
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
      else
        ifeq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
        endif
      endif      
    else
      ifeq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        ifndef CMOS_SENSOR_SUB_BAK1
          $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
        else
          ifeq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR_BAK1/CMOS_SENSOR_SUB_BAK1,BACKUP_SENSOR_SUPPORT)
          endif
        endif
      endif
    endif
    COM_DEFS += BACKUP_SENSOR_SUPPORT
  else
    ifdef CMOS_SENSOR_BAK1
      ifneq ($(strip $(CMOS_SENSOR_BAK1)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_BAK1)
      endif
    endif
    ifdef CMOS_SENSOR_SUB_BAK1
      ifneq ($(strip $(CMOS_SENSOR_SUB_BAK1)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,CMOS_SENSOR_SUB_BAK1)
      endif
    endif
    ifdef LENS_MODULE_BAK1
      ifneq ($(strip $(LENS_MODULE_BAK1)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,BACKUP_SENSOR_SUPPORT,LENS_MODULE_BAK1)
      endif
    endif
  endif
endif

ifdef CMOS_SENSOR
  ifneq ($(strip $(CMOS_SENSOR)),NONE)
    ifneq ($(strip $(ISP_SUPPORT)),FALSE)
      COMMINCDIRS    += custom\drv\Camera_common
    endif
    COMMINCDIRS    += custom\drv\camera\$(strip $(BOARD_VER))
    ifeq ($(strip $(SENSOR_TYPE)),RAW)
      COMMINCDIRS    +=	custom\drv\image_sensor\$(strip $(CMOS_SENSOR))
    endif
    ifeq ($(strip $(SENSOR_TYPE)),YUV)
      COMMINCDIRS    +=	custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR))
      COM_DEFS += YUV_SENSOR_SUPPORT
    endif
    ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
      COMMINCDIRS    += custom\drv\direct_sensor \
                        drv\drv_sec\include
      COM_DEFS       += __DIRECT_SENSOR_SUPPORT__ __$(strip $(CMOS_SENSOR))__
      COMPLIST       += image_sensor_sec
      CUS_REL_MTK_COMP += image_sensor_sec
    endif
    ifdef SENSOR_TYPE
      ifneq ($(strip $(SENSOR_TYPE)),NONE)    
        CUS_REL_BASE_COMP  += custom\drv\Image_sensor \
                              custom\drv\YUV_sensor \
                              custom\drv\DIRECT_sensor \
                              custom\drv\Lens_module
      endif
    endif
  endif
endif 

ifdef SENSOR_ROTATE
  ifneq ($(strip $(SENSOR_ROTATE)),NONE)
    COM_DEFS    += $(strip $(SENSOR_ROTATE))
  endif
endif

ifdef SENSOR_SUB_ROTATE
  ifneq ($(strip $(SENSOR_SUB_ROTATE)),NONE)
    COM_DEFS    += SUB_$(strip $(SENSOR_SUB_ROTATE))
  endif
endif

ifdef SENSOR_LOCATION
  ifneq ($(strip $(SENSOR_LOCATION)),NONE)
    COM_DEFS    += $(strip $(SENSOR_LOCATION))
  endif
endif

ifdef MOTION_SENSOR_SUPPORT
  ifneq ($(strip $(MOTION_SENSOR_SUPPORT)),NONE)
    COM_DEFS    += $(strip $(MOTION_SENSOR_SUPPORT))
    COM_DEFS    += MOTION_SENSOR_SUPPORT
    COMMINCDIRS += custom\drv\motion_sensor\$(strip $(MOTION_SENSOR_SUPPORT))
    CUS_REL_BASE_COMP += custom\drv\motion_sensor
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
    COM_DEFS     += __CMUX_SUPPORT__
  endif
endif

ifdef DIGIT_TONE_SUPPORT
  ifeq ($(strip $(DIGIT_TONE_SUPPORT)),TRUE)
    COM_DEFS    +=  DIGIT_TONE_SUPPORT
  endif
endif

ifdef TTS
  ifneq ($(strip $(TTS)),NONE)
    COM_DEFS    +=  $(strip $(TTS))
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      CUS_REL_OBJ_LIST += l1audio\obj\TDic_Shell.lib \
                          l1audio\obj\InterSound4.a \
                          l1audio\obj\eJTTS.a
      CUS_REL_BASE_COMP += l1audio\Tts
    endif
  endif
  ifeq ($(strip $(TTS)),CYBERON_DIC_TTS)
    COMPOBJS    += l1audio\obj\TDic_Shell.lib
    CUS_REL_OBJ_LIST += l1audio\obj\TDic_Shell.lib
    COM_DEFS += __GENERAL_TTS__
  endif
  ifeq ($(strip $(TTS)),IFLY_TTS)
    COMPOBJS    += l1audio\obj\InterSound4.a
    CUS_REL_OBJ_LIST += l1audio\obj\InterSound4.a
    COM_DEFS	+= __GENERAL_TTS__
  endif
  ifeq ($(strip $(TTS)),SINOVOICE_TTS)
    COMPOBJS    += l1audio\obj\ejTTS.a
    CUS_REL_OBJ_LIST += l1audio\obj\eJTTS.a
    COM_DEFS	+= __GENERAL_TTS__
  endif
endif

ifdef CUST_KEYPAD_TONE_SUPPORT
  ifeq ($(strip $(CUST_KEYPAD_TONE_SUPPORT)),TRUE)
    COM_DEFS    +=  CUST_KEYPAD_TONE_SUPPORT
  endif
endif

HORIZONTAL_CAMERA_SUPPORT_SIZE = 176X220 240X320 240X400 320X480 
ifdef HORIZONTAL_CAMERA
  ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),$(HORIZONTAL_CAMERA_SUPPORT_SIZE)),)
       $(error $(MAIN_LCD_SIZE) does not support HORIZONTAL_CAMERA. Please disable HORIZONTAL_CAMERA)
    else
      COM_DEFS    += HORIZONTAL_CAMERA
    endif
  endif
endif

MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM = MT6217 MT6218B MT6225 MT6253T MT6253 MT6235 MT6235B MT6223P 
ifneq ($(filter $(strip $(PLATFORM)) ,$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
  ifeq ($(strip $(PLATFORM)),MT6223P)
    ifneq ($(strip $(SENSOR_TYPE)),DIRECT)
      ifeq ($(strip $(MJPG_SUPPORT)),TRUE)
#        $(error For MT6223P, please set SENSOR_TYPE=DIRECT or turn off MJPG_SUPPORT)
        $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,DIRECT,MJPG_SUPPORT)
      endif
    endif
  endif
endif


ifdef MJPG_SUPPORT
  ifeq ($(strip $(MJPG_SUPPORT)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support MJPG_SUPPORT)
    endif
    ifdef MP4_DECODE
      ifneq ($(strip $(MP4_DECODE)),NONE)
        $(call DEP_ERR_OFFA_OR_OFFB,MP4_DECODE,MJPG_SUPPORT)
      endif
    endif
    ifdef MP4_ENCODE
      ifneq ($(strip $(MP4_ENCODE)),NONE)
        $(call DEP_ERR_OFFA_OR_OFFB,MP4_ENCODE,MJPG_SUPPORT)
      endif
    endif
    ifeq ($(strip $(CMOS_SENSOR)),PO4010K)
      $(error $(strip $(CMOS_SENSOR)) does not support MJPG_SUPPORT)
    endif
    ifeq ($(strip $(CMOS_SENSOR)),SIA100A)
      $(error $(strip $(CMOS_SENSOR)) does not support MJPG_SUPPORT)
    endif
    COM_DEFS += MJPG_SUPPORT
  endif
endif



ifdef MED_PROFILE
  COM_DEFS    += $(strip $(MED_PROFILE))
endif


ifdef XML_SUPPORT
  ifeq ($(strip $(XML_SUPPORT)),TRUE)
    ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      $(error GSM project does not support XML_SUPPORT)
    endif
    COM_DEFS   += __XML_SUPPORT__
  endif
endif

ifdef AMR_LINK_SUPPORT
  ifeq ($(strip $(AMR_LINK_SUPPORT)),TRUE)
    COM_DEFS   += __AMR_SUPPORT__
  endif
endif

ifdef IMPS_SUPPORT
  ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
    COM_DEFS    += __IMPS__
  endif
endif

TP_INTERNAL_SUPPORT_PLATFORM = MT6235 MT6235B MT6238 MT6239 MT6268 MT6268A MT6268 MT6516 MT6253 MT6253T 
ifdef TOUCH_PANEL_SUPPORT
  ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
    ifdef HAND_WRITING
      ifeq ($(strip $(HAND_WRITING)),NONE)
        COM_DEFS += __NO_HANDWRITING__
      endif
    else
      COM_DEFS += __NO_HANDWRITING__
    endif
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(error TOUCH_PANEL does not support NEPTUNE_MMI)
    endif
  endif
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),MT6301)
     COM_DEFS    += TOUCH_PANEL_SUPPORT
  endif
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),MT6301B)
     COM_DEFS    += TOUCH_PANEL_SUPPORT
     COM_DEFS    += TOUCH_PANEL_PRESSURE
  endif
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),TP_INTERNAL)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(TP_INTERNAL_SUPPORT_PLATFORM)),)
      $(error $(PLATFORM) does not support TOUCH_PANEL_SUPPORT = TP_INTERNAL)
    endif
    COM_DEFS    += TOUCH_PANEL_SUPPORT
    COM_DEFS    += TOUCH_PANEL_PRESSURE
    COM_DEFS    += TOUCH_PANEL_INTERNAL
  endif  
endif


ifdef TOUCH_PANEL_SUPPORT
   ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      ifeq ($(strip $(TOUCH_PANEL_SHORTCUT_SUPPORT)),TRUE)  
          $(call DEP_ERR_OFFA_OR_OFFB,TOUCH_PANEL_SUPPORT,TOUCH_PANEL_SHORTCUT_SUPPORT)
      endif
   else 
      ifeq ($(strip $(TOUCH_PANEL_SHORTCUT_SUPPORT)),TRUE)
         COM_DEFS    += TOUCH_PANEL_SHORTCUT_SUPPORT
      endif
   endif     
endif

ifdef TOUCH_PAD_SUPPORT
   ifeq ($(strip $(TOUCH_PAD_SUPPORT)),TRUE)
     ifneq ($(strip $(DEMO_PROJECT)),TRUE)
       $(error TOUCH_PAD_SUPPORT can be turned on only in the internal project)
     endif
     COM_DEFS  += TOUCH_PAD_SUPPORT
   endif
endif

ifndef GPRS_MAX_PDP_SUPPORT
     GPRS_MAX_PDP_SUPPORT = 2
endif

ifdef GPRS_MAX_PDP_SUPPORT
     COM_DEFS    += GPRS_MAX_PDP_SUPPORT=$(strip $(GPRS_MAX_PDP_SUPPORT))
endif

ifdef UART3_SUPPORT
  ifeq ($(strip $(UART3_SUPPORT)),TRUE)
    UART3_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
    ifneq ($(filter $(strip $(PLATFORM)),$(UART3_NOT_SUPPORT_PLATFORM)),)
       $(error PLATFORM $(strip $(PLATFORM)) not support UART3_SUPPORT.)
    endif
    COM_DEFS    +=	__UART3_SUPPORT__
    UART_PORT_FREE_COUNT = 1
  else
    UART_PORT_FREE_COUNT = 0
  endif
else
    UART_PORT_FREE_COUNT = 0
endif

ifdef BLUETOOTH_SUPPORT
   ifeq ($(strip $(BLUETOOTH_SUPPORT)), NONE)
      ifdef TOUCH_PAD_SUPPORT
        ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
          UART_PORT_USED_COUNT = 1
        else
          UART_PORT_USED_COUNT = 0
        endif
     else
      UART_PORT_USED_COUNT = 0
     endif
   else
     ifdef TOUCH_PAD_SUPPORT
        ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
           UART_PORT_USED_COUNT = 2
        else
           UART_PORT_USED_COUNT = 1
        endif
      else
        UART_PORT_USED_COUNT = 1
      endif
   endif
else
  ifdef TOUCH_PAD_SUPPORT
    ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
      UART_PORT_USED_COUNT = 1
    else
      UART_PORT_USED_COUNT = 0
    endif
  else
    UART_PORT_USED_COUNT = 0
  endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),1)
   ifeq ($(strip $(UART_PORT_USED_COUNT)),2)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),0)
  ifneq ($(strip $(UART_PORT_USED_COUNT)),0)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif



ifdef DMA_UART_VIRTUAL_FIFO
  VFIFO_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
  ifneq ($(filter $(strip $(PLATFORM)),$(VFIFO_NOT_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(error PLATFORM $(strip $(PLATFORM)) dose NOT support DMA_UART_VIRTUAL_FIFO.)
    endif
  else
    ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(error DMA_UART_VIRTUAL_FIFO is a mandatory feature on PLATFORM $(strip $(PLATFORM)))
    endif
  endif
  ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
    COM_DEFS    +=	__DMA_UART_VIRTUAL_FIFO__
  endif
endif

ifdef DMA_UART_VFIFO_TUNNEL_SUPPORT
    ifeq ($(strip $(DMA_UART_VFIFO_TUNNEL_SUPPORT)),TRUE)
        ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,DMA_UART_VIRTUAL_FIFO,DMA_UART_VFIFO_TUNNEL_SUPPORT)
        endif
        COM_DEFS    +=	__DMA_UART_VFIFO_SINGLE_TUNNEL__
    endif
endif

ifdef POC_SUPPORT
  ifneq ($(strip $(POC_SUPPORT)),NONE)
     COM_DEFS    += __POC__  __POC_NON_RLS__
  endif
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
     COM_DEFS    +=  __SIP__
  endif
endif

ifdef SDP_SUPPORT
  ifneq ($(strip $(SDP_SUPPORT)),FALSE)
     COM_DEFS    +=  __SDP__
     COMP_TRACE_DEFS	  += ps\sdp\include\sdp_trc.h
  endif
endif

ifdef WIFI_SUPPORT
  ifeq ($(strip $(WIFI_SUPPORT)),WIFI_LIB)
#     COMPOBJS         += wifi\sslplus.lib
#     CUS_REL_OBJ_LIST += wifi\sslplus.lib
#     COMPOBJS         += wifi\sb.lib
#     CUS_REL_OBJ_LIST += wifi\sb.lib
  endif
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
     COM_DEFS    +=  __WIFI_SUPPORT__
     COM_DEFS    +=  __WIFI_CHIP_VERIFY__
     COM_DEFS    += __WIFI_WIZARD_SUPPORT__
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
        $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,IPERF_SUPPORT)
     endif
  endif

  ifeq ($(strip $(IPERF_SUPPORT)),QUAD)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
     COM_DEFS    += __IPERF3__
     COM_DEFS    += __IPERF4__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),TRIPLE)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
     COM_DEFS    += __IPERF3__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),DUAL)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),SINGLE)
     COM_DEFS    += __IPERF__
  endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
     COM_DEFS    += __VOIP__  __SAF__
  endif
endif

ifndef PHB_SIM_ENTRY
     PHB_SIM_ENTRY = 250
endif

ifdef PHB_SIM_ENTRY
     COM_DEFS    += MAX_PHB_SIM_ENTRY=$(strip $(PHB_SIM_ENTRY))
endif

ifndef PHB_PHONE_ENTRY
     PHB_PHONE_ENTRY = 200
endif

ifdef PHB_PHONE_ENTRY
     COM_DEFS    += MAX_PHB_PHONE_ENTRY=$(strip $(PHB_PHONE_ENTRY))
endif

ifndef PHB_LN_ENTRY
     PHB_LN_ENTRY = 20
endif

ifdef PHB_LN_ENTRY
     COM_DEFS    += MAX_PHB_LN_ENTRY=$(strip $(PHB_LN_ENTRY))
endif

ifndef PHONE_TYPE
  PHONE_TYPE = BAR
endif

ifdef PHONE_TYPE
  COM_DEFS    += __PHONE_$(strip $(PHONE_TYPE))__
  ifeq ($(strip $(PHONE_TYPE)),CLAMSHELL)
    COM_DEFS  +=  CLAM_SUPPORT
  endif
endif

ifdef SUBLCD_DEDICATED_KEYS_SUPPORT
  ifeq ($(strip $(SUBLCD_DEDICATED_KEYS_SUPPORT)),TRUE)
    ifeq ($(strip $(PHONE_TYPE)),CLAMSHELL)
        COM_DEFS    +=  __SUBLCD_DEDICATED_KEYS_SUPPORT__
    else
        $(call DEP_ERR_SETA_OR_OFFB,PHONE_TYPE,CLAMSHELL,SUBLCD_DEDICATED_KEYS_SUPPORT)
    endif
  endif
endif



ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
  IRDA_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
  ifneq ($(filter $(strip $(PLATFORM)),$(IRDA_NOT_SUPPORT_PLATFORM)),)
    $(error PLATFORM $(strip $(PLATFORM)) not support IRDA_SUPPORT.)
  endif
  IRDA_FULL_COMPILE_OPTION_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H 
  ifneq ($(filter $(strip $(PLATFORM)) ,$(IRDA_FULL_COMPILE_OPTION_PLATFORM)),)
    COM_DEFS    += __IRDA_SUPPORT__ __IRDA_MIR_SUPPORT__ __IRDA_FIR_SUPPORT__
  else
    COM_DEFS    += __IRDA_SUPPORT__
  endif
endif

ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    NAND_FLASH_BOOTING_SUPPORT_PLATFORM = MT6228 MT6229 MT6225 MT6230 MT6238 MT6239 MT6235 MT6235B MT6268A MT6268 
    NFB_ONDEMAND_SUPPORT_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6268A MT6268 
    ifeq ($(strip $(SMART_PHONE_CORE)),AP)
      NAND_FLASH_BOOTING_SUPPORT_PLATFORM += MT6516 
      NFB_ONDEMAND_SUPPORT_PLATFORM += MT6516 
    endif
    ifeq ($(filter $(strip $(PLATFORM)) ,$(NAND_FLASH_BOOTING_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING)
    endif
    ifdef NAND_SUPPORT
      ifeq ($(strip $(NAND_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
      endif
    endif
    COM_DEFS    += _NAND_FLASH_BOOTING_
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ENFB)
      ifneq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) should use NAND_FLASH_BOOTING = ONDEMAND / MIXED instead of ENFB)
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = ONDEMAND)
      endif
      COM_DEFS    += __NFB_ON_DEMAND_PAGE_IN__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),MIXED)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = MIXED)
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
      COM_DEFS    += __NFB_ON_DEMAND_PAGE_IN__
    endif
    CUS_REL_SRC_COMP += bootloader
  endif
  CUS_REL_BASE_COMP += bootloader make\bootloader
  CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
  CUS_REL_FILES_LIST += sss\sss.lib sss\interface\src\SSS_interface.c \
                        interface\l1interface\l1_interface.c interface\l1interface\l1_interface.h
endif

ifdef USB_DOWNLOAD
  ifeq ($(strip $(USB_DOWNLOAD)),SECURE)
    ifneq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,USB_DOWNLOAD,non SECURE,SECURE_SUPPORT)
    endif
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,USB_DOWNLOAD,non SECURE,USB_SUPPORT)
    endif
  endif
endif

ifdef USB_DOWNLOAD
  ifneq ($(strip $(USB_DOWNLOAD)),NONE)
    ifeq ($(strip $(USB_SUPPORT)),TRUE)
      USB_DOWNLOAD_SUPPORT_PLATFORM = MT6227 MT6226 MT6226M MT6227D MT6226D MT6225 MT6253T MT6253 MT6228 MT6229 MT6230 MT6235 MT6235B MT6238 MT6239 MT6268A MT6268 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(USB_DOWNLOAD_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does not support USB_DOWNLOAD.)
      endif
      COM_DEFS    += __USB_DOWNLOAD__
      COM_DEFS    += USBACM_TX_WITHOUT_DMA
      CUS_REL_SRC_COMP += bootloader
      CUS_REL_BASE_COMP += bootloader make\bootloader
      CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
      CUS_REL_FILES_LIST += sss\interface\src\SSS_interface.c
      ifeq ($(strip $(USB_DOWNLOAD)),SECURE)
        COM_DEFS  += __SECURE_USB_DOWNLOAD__
        CUS_REL_FILES_LIST += dp_engine\che\sha1.h
        CUS_REL_FILES_LIST += dp_engine\che\rc4.h
      endif
    endif
  endif
endif

ARM9_FOTA_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6268
ARM7_FOTA_PLATFORM = MT6223 MT6223P MT6229 MT6228 MT6230 MT6225 MT6226 MT6226M MT6226D MT6227 MT6227D
ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    ifeq ($(strip $(SYNCML_DM_SUPPORT)),TRUE)
      ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
        COM_DEFS += _DM_OMADL_VIA_DLAGENT_
      endif
    endif
    COM_DEFS += __$(strip $(FOTA_ENABLE))__ __FOTA_ENABLE__
    ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
      ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
          $(call DEP_ERR_SETA_OR_OFFB,FOTA_ENABLE,non FOTA_DM,SYSTEM_DRIVE_ON_NAND)
        endif
      endif
      ifeq ($(strip $(UID_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_OFFB,FOTA_ENABLE,non FOTA_DM,UID_SUPPORT)
      endif
      ifneq ($(strip $(SYNCML_DM_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,FOTA_ENABLE,non FOTA_DM,SYNCML_DM_SUPPORT)
      endif      
      COMPLIST         += ssf
      CUS_REL_MTK_COMP += ssf
      CUS_REL_SRC_COMP += bootloader
      CUS_REL_BASE_COMP += bootloader make\bootloader ssf\inc vendor\hp_fota\UA
      CUS_REL_FILES_LIST += custom\drv\common_drv\gpio_setting.c
      CUS_REL_FILES_LIST += sss\sss.lib sss\interface\src\SSS_interface.c
      CUS_REL_FILES_LIST += applib\misc\include\app_zlib.h sst\include\sst_fue_encrypt.h
      CUS_REL_FILES_LIST += dp_engine\che\sha1.h dp_engine\che\rsa.h dp_engine\che\bignum.h
    endif
    CUS_REL_FILES_LIST += init\src\emi.c
    CUS_REL_BASE_COMP += fota make\fota
    CUS_REL_SRC_COMP += fota
  endif
endif

SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORT_PLATFORM = MT6205B
ifdef SINGLE_BANK_NOR_FLASH_SUPPORT
   ifeq ($(strip $(SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
     ifeq ($(filter $(strip $(PLATFORM)),$(SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORT_PLATFORM)),)
       $(error PLATFORM $(strip $(PLATFORM)) does not support SINGLE_BANK_NOR_FLASH_SUPPORT)
     endif
     ifdef EMS_SUPPORT
       ifneq ($(strip $(EMS_SUPPORT)),EMS_NONE)
         $(call DEP_ERR_SETA_OR_OFFB,EMS_SUPPORT,EMS_NONE,SINGLE_BANK_NOR_FLASH_SUPPORT)
       endif
     endif
     ifdef FS_SORT_SUPPORT
       ifneq ($(strip $(FS_SORT_SUPPORT)),FALSE)
         $(call DEP_ERR_OFFA_OR_OFFB,FS_SORT_SUPPORT,SINGLE_BANK_NOR_FLASH_SUPPORT)
       endif
     endif
     ifdef MMI_VERSION
       ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
         $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,non PLUTO_MMI,SINGLE_BANK_NOR_FLASH_SUPPORT)
       endif
     endif
     COM_DEFS += _LOW_COST_SINGLE_BANK_FLASH_
   endif
endif

ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORTED_PLATFORM = MT6205B MT6223 MT6223P MT6225 MT6253T MT6253 MT6226 MT6226D MT6226M MT6227 MT6229 MT6230 MT6227D MT6235 MT6235B 
ifdef ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT
  ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORTED_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)
    endif
    ifneq ($(strip $(SYSGEN_ENABLE)),TRUE)
      $(error Please turn on SYSGEN_ENABLE when ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT is TRUE)
    endif
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SYSTEM_DRIVE_ON_NAND)
    endif
    ifeq ($(strip $(SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SINGLE_BANK_NOR_FLASH_SUPPORT)
    else
      COM_DEFS += __SINGLE_BANK_NOR_FLASH_SUPPORT__
    endif
  endif
endif

ifdef SWDBG_SUPPORT
   ifeq ($(strip $(SWDBG_SUPPORT)),TRUE)
      SWDBG_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6223 MT6223P MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H MT6268A MT6268 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(SWDBG_SUPPORT_PLATFORM)),)
          $(error PLATFORM $(strip $(PLATFORM)) does not support SWDBG_SUPPORT.)
      endif
      ifeq ($(strip $(NAND_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,NAND_SUPPORT,SWDBG_SUPPORT)
      endif
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
        $(call DEP_ERR_OFFA_OR_OFFB,WIFI_SUPPORT,SWDBG_SUPPORT)
      endif
      COM_DEFS    += __SWDBG_SUPPORT__
   endif
endif

ifdef UID_SUPPORT
   ifeq ($(strip $(UID_SUPPORT)),TRUE)
      UID_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6227 MT6226 MT6226M MT6225 MT6253T MT6253 MT6223 MT6227D MT6226D MT6223P MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H MT6268A MT6268 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(UID_SUPPORT_PLATFORM)),)
          $(error PLATFORM $(strip $(PLATFORM)) does not support UID_SUPPORT.)
      endif
      COM_DEFS    += UID_SUPPORT
   endif
else
UID_SUPPORT = FALSE
endif

ifdef WMA_DECODE
  ifeq ($(strip $(WMA_DECODE)),TRUE)
      WMA_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H MT6268A MT6268 MT6253T MT6253 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(WMA_DECODE_SUPPORT_PLATFORM)),)
          $(error PLATFORM $(strip $(PLATFORM)) does not support WMA_DECODE.)
      endif
      COM_DEFS    += WMA_DECODE
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    ifneq ($(strip $(LOW_COST_SUPPORT)),FALSE)
      COM_DEFS    +=  LOW_COST_SUPPORT
    endif
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)),COMMON)
    COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)),ULC)
    COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__ __LOW_COST_SUPPORT_ULC__
  endif
endif

ifdef AAC_PLUS_DECODE
   ifeq ($(strip $(AAC_PLUS_DECODE)),TRUE)
      AAC_PLUS_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6253T MT6253 MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6268T MT6268H MT6268A MT6268 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(AAC_PLUS_DECODE_SUPPORT_PLATFORM)),)
         $(error PLATFORM $(strip $(PLATFORM)) does not support AAC_PLUS_DECODE.)
      endif
      COM_DEFS    +=  AAC_PLUS_DECODE
   endif
endif


ifdef AAC_PLUS_PS_DECODE
   ifeq ($(strip $(AAC_PLUS_PS_DECODE)),TRUE)
      AAC_PLUS_PS_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6253T MT6253 MT6227D MT6226D MT6238 MT6239 MT6235 MT6235B MT6268A MT6268 
      ifeq ($(filter $(strip $(PLATFORM)) ,$(AAC_PLUS_PS_DECODE_SUPPORT_PLATFORM)),)
         $(error PLATFORM $(strip $(PLATFORM)) does not support AAC_PLUS_PS_DECODE.)
      endif
      ifeq ($(strip $(AAC_PLUS_DECODE)),FALSE)
         $(call DEP_ERR_ONA_OR_OFFB,AAC_PLUS_DECODE,AAC_PLUS_PS_DECODE)
      endif
      COM_DEFS    +=  AAC_PLUS_PS_DECODE
   endif
endif



ifdef EMS_SUPPORT
    ifeq ($(strip $(EMS_SUPPORT)),EMS_50)
      COM_DEFS    +=  __EMS_REL5__
    endif
    ifeq ($(strip $(EMS_SUPPORT)),EMS_40)
       # do nothing
    endif
    ifeq ($(strip $(EMS_SUPPORT)),EMS_NONE)
      COM_DEFS    +=  __SLIM_EMS__
    endif
endif

ifdef EDGE_SUPPORT
   ifeq ($(strip $(EDGE_SUPPORT)),TRUE)
     EDGE_SUPPORT_PLATFORM = MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6268 TK6516 MT6516 MT6268T MT6268H MT6268A MT6268 
     ifeq ($(filter $(strip $(PLATFORM)) ,$(EDGE_SUPPORT_PLATFORM)),)
       $(error PLATFORM $(strip $(PLATFORM)) does not support EGPRS.)
     endif
     ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
       $(error GSM project does not support EDGE_SUPPORT)
     endif
     ifneq ($(strip $(R99_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,EDGE_SUPPORT)
     endif
     ifneq ($(strip $(L1_EGPRS)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,L1_EGPRS,EDGE_SUPPORT)
     endif
      
     COM_DEFS    += __EGPRS_MODE__
      
     ifeq ($(strip $(L1_EPSK_TX)),TRUE)
       ifeq ($(filter MT6140D_RF,$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
         ifeq ($(filter AD6546_RF,$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
           ifeq ($(filter SKY74137_RF,$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
             ifeq ($(filter SKY74045_RF,$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
               $(error RF_MODULE $(strip $(RF_MODULE)) does not support L1_EPSK_TX.)
             endif
           endif
         endif
       endif
       COM_DEFS    +=  __EPSK_TX__
     endif
   else
     ifdef L1_EGPRS
       ifeq ($(strip $(L1_EGPRS)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,EDGE_SUPPORT,L1_EGPRS)
       endif
     endif
     ifdef L1_EPSK_TX
       ifeq ($(strip $(L1_EPSK_TX)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,EDGE_SUPPORT,L1_EPSK_TX)
       endif
     endif
   endif
endif

ifdef XDM_SUPPORT
ifneq ($(strip $(XDM_SUPPORT)),FALSE)
  # XDM_SUPPORT should be based on TELECA_FEATURE (WAP2 and SEC)
  ifdef TELECA_FEATURE
    ifneq ($(strip $(TELECA_FEATURE)),NONE)
      ifneq ($(strip $(TELECA_FEATURE)),WAP2_SEC)
        $(call DEP_ERR_SETA_OR_OFFB,TELECA_FEATURE,WAP2_SEC,XDM_SUPPORT)
      endif
    else
      $(call DEP_ERR_SETA_OR_OFFB,TELECA_FEATURE,WAP2_SEC,XDM_SUPPORT)
    endif
  else
    $(call DEP_ERR_SETA_OR_OFFB,TELECA_FEATURE,WAP2_SEC,XDM_SUPPORT)
  endif
  # XDM_SUPPORT should be based on XML_SUPPORT
  ifdef XML_SUPPORT
    ifeq ($(strip $(XML_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,XDM_SUPPORT)
    endif
  endif
endif
endif

ifdef POC_SUPPORT
  ifneq ($(strip $(POC_SUPPORT)),NONE)
    ifeq ($(strip $(SIP_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,SIP_SUPPORT,POC_SUPPORT)
    endif
    ifeq ($(strip $(XDM_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,XDM_SUPPORT,POC_SUPPORT)
    endif
  endif
endif

ifdef R99_SUPPORT
  ifeq ($(strip $(R99_SUPPORT)),TRUE)
      COM_DEFS    +=   __R99__
  endif
endif

ifdef R4_SUPPORT
  R4_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(strip $(R4_SUPPORT)),TRUE)
    ifneq ($(strip $(R99_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,R4_SUPPORT)
    endif
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
        $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,non NEPTUNE_MMI,R4_SUPPORT)
    endif    
    ifeq ($(filter $(strip $(PLATFORM)),$(R4_NOT_SUPPORT_PLATFORM)),)
      COM_DEFS    +=   __REL4__
    else
       $(error PLATFORM $(strip $(PLATFORM)) not support R4_SUPPORT.)
    endif
  endif
endif

ifdef R5_SUPPORT
  R5_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219 
  ifeq ($(strip $(R5_SUPPORT)),TRUE)
    ifneq ($(strip $(R4_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R4_SUPPORT,R5_SUPPORT)
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(R5_NOT_SUPPORT_PLATFORM)),)
          $(error PLATFORM $(strip $(PLATFORM)) does not support R5_SUPPORT.)
    endif
    ifneq ($(strip $(PLATFORM)),MT6516)
          COM_DEFS    +=   __REL5__  __USIM_SUPPORT__ __ACL_SUPPORT__
    else
          COM_DEFS    +=   __REL5__    
    endif
  endif
endif

ifdef CHE_SUPPORT
  ifeq ($(strip $(PLATFORM)),MT6228)
    ifeq ($(strip $(CHE_SUPPORT)),TRUE)
       COM_DEFS    +=  __HW_CHE__
    endif
  endif
endif

ifdef TV_OUT_SUPPORT
  ifeq ($(strip $(CAMCORDER_SUPPORT)),NONE)
    ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
      ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
        ifeq ($(strip $(LCM_ROTATE_SUPPORT)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,LCM_ROTATE_SUPPORT,HORIZONTAL_CAMERA/TV_OUT_SUPPORT)
        endif
      endif
    endif
  endif
  TV_OUT_SUPPORT_PLATFORM = MT6228 MT6229 MT6268T MT6268H MT6238 MT6239 MT6235 MT6235B MT6230 MT6268A MT6268 
  ifneq ($(filter $(strip $(PLATFORM)) ,$(TV_OUT_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
      COM_DEFS    +=  TV_OUT_SUPPORT
    endif
  endif
endif

ifndef MAIN_LCD_SIZE
   MAIN_LCD_SIZE = 0X0
endif

ifdef MAIN_LCD_SIZE
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),120X160)
      # spacial case for MTKLCM_COLOR in MT6208 EVB
      MAIN_LCD_SIZE := 128X160
   endif

   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128)
     ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
       $(error MAIN_LCD_SIZE 128X128 does not support TOUCH_PANEL)
     endif
   endif
   COM_DEFS    += __MMI_MAINLCD_$(call Upper,$(strip $(MAIN_LCD_SIZE)))__
endif

ifndef SUB_LCD_SIZE
    SUB_LCD_SIZE = NONE
endif

ifdef SUB_LCD_SIZE
    COM_DEFS += __MMI_SUBLCD_$(call Upper,$(strip $(SUB_LCD_SIZE)))__
endif

ifeq ($(strip $(MMI_MAIN_LCD_DEFAULT_FORMAT)),16)
    COM_DEFS    +=  MMI_MAIN_LCD_DEFAULT_FORMAT=16
endif
ifeq ($(strip $(MMI_MAIN_LCD_DEFAULT_FORMAT)),24)
    COM_DEFS    +=  MMI_MAIN_LCD_DEFAULT_FORMAT=24
endif
ifeq ($(strip $(MMI_MAIN_LCD_DEFAULT_FORMAT)),32)
    COM_DEFS    +=  MMI_MAIN_LCD_DEFAULT_FORMAT=32
endif
ifeq ($(strip $(MMI_SUB_LCD_DEFAULT_FORMAT)),16)
    COM_DEFS    +=  MMI_SUB_LCD_DEFAULT_FORMAT=16
endif
ifeq ($(strip $(MMI_SUB_LCD_DEFAULT_FORMAT)),24)
    COM_DEFS    +=  MMI_SUB_LCD_DEFAULT_FORMAT=24
endif
ifeq ($(strip $(MMI_SUB_LCD_DEFAULT_FORMAT)),32)
    COM_DEFS    +=  MMI_SUB_LCD_DEFAULT_FORMAT=32
endif

BACKGROUND_SOUND_NOT_SUPPORT_PLATFORM = MT6226 MT6226M MT6227
ifdef BACKGROUND_SOUND
  ifeq ($(strip $(BACKGROUND_SOUND)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(BACKGROUND_SOUND_NOT_SUPPORT_PLATFORM)),)
      $(error $(strip $(PLATFORM)) does not support BACKGROUND_SOUND)
    endif
    COM_DEFS	+= BGSND_ENABLE
  endif
endif

ifdef WEBCAM_SUPPORT
  ifeq ($(strip $(WEBCAM_SUPPORT)),TRUE)
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,WEBCAM_SUPPORT)
    endif
    ifndef CMOS_SENSOR
        $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,WEBCAM_SUPPORT)
    endif
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,WEBCAM_SUPPORT)
    endif
    WEBCAM_SUPPORT_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B
    ifneq ($(filter $(strip $(PLATFORM)),$(WEBCAM_SUPPORT_NOT_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) not support WEBCAM_SUPPORT.)
    else
      ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,WEBCAM_SUPPORT)
      else
        COM_DEFS += WEBCAM_SUPPORT      
      endif
    endif
  endif
  ifeq ($(strip $(VENDOR)),NONE)
    CUS_REL_BASE_COMP += media\camera\include \
                         media\camera_v2\include
  endif
endif

# AUDIO_POST_PROCESS for 6228/6229/6230/6238 only
AUDIO_POST_PROCESS_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6268A MT6268 
ifdef AUDIO_POST_PROCESS
  ifneq ($(strip $(AUDIO_POST_PROCESS)),NONE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(AUDIO_POST_PROCESS_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support AUDIO_POST_PROCESS.)
    endif
  endif

  ifeq ($(strip $(AUDIO_POST_PROCESS)),ALL_EFFECT)
    COM_DEFS	+= AUD_REVERB
    COM_DEFS	+= AUD_TIME_STRETCH
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
    ifeq ($(strip $(COMPILER)),ADS)
      COMPOBJS    += dp_engine\BesSound\BesLive_arm.a
      CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLive_arm.a
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += dp_engine\BesSound\BesLive_arm_rvct.a
      CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLive_arm_rvct.a
    endif
  else
    ifeq ($(strip $(AUDIO_POST_PROCESS)),REVERB_ONLY)
      COM_DEFS	+= AUD_REVERB
      CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += dp_engine\BesSound\BesLive_arm.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLive_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += dp_engine\BesSound\BesLive_arm_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLive_arm_rvct.a
      endif
    else
      ifeq ($(strip $(AUDIO_POST_PROCESS)),TIME_STRETCH_ONLY)
        COM_DEFS	+= AUD_TIME_STRETCH
      endif
    endif
  endif
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COM_DEFS    +=  __DT_SUPPORT__
     COMPLIST    +=  dt
  endif
endif

ifeq ($(strip $(AU_DECODE)),TRUE)
   AU_DECODE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208
   ifeq ($(filter $(strip $(PLATFORM)),$(AU_DECODE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(error PLATFORM $(strip $(PLATFORM)) not support AU_DECODE.)
   endif
   COM_DEFS    += AU_DECODE
endif


ifeq ($(strip $(AIFF_DECODE)),TRUE)
   AIFF_DECODE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208 
   ifeq ($(filter $(strip $(PLATFORM)),$(AIFF_DECODE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(error PLATFORM $(strip $(PLATFORM)) not support AIFF_DECODE.)
   endif
   COM_DEFS    += AIFF_DECODE
endif

ifeq ($(strip $(JTONE_SUPPORT)),TRUE)
   JTONE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208
   ifeq ($(filter $(strip $(PLATFORM)),$(JTONE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(error PLATFORM $(strip $(PLATFORM)) not support JTONE_SUPPORT.)
   endif
   COM_DEFS    += JTONE_SUPPORT
endif

ifneq ($(strip $(J2ME_SUPPORT)),NONE)
  ifneq ($(strip $(JTONE_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,JTONE_SUPPORT,J2ME_SUPPORT)
  endif
endif

ifdef AF_SUPPORT
  ifneq ($(strip $(AF_SUPPORT)),FALSE)
    ifndef LENS_MODULE
  		$(call DEP_ERR_ONA_OR_OFFB,LENS_MODULE,AF_SUPPORT)
    endif
    ifeq ($(strip $(LENS_MODULE)),NONE)
  		$(call DEP_ERR_ONA_OR_OFFB,LENS_MODULE,AF_SUPPORT)
    endif
      COM_DEFS    +=  AF_SUPPORT
  endif
endif


ifdef CTM_SUPPORT
  ifneq ($(strip $(CTM_SUPPORT)),FALSE)
     COM_DEFS    +=  __CTM_SUPPORT__
  endif
endif

ifdef XDM_SUPPORT
  ifeq ($(strip $(XDM_SUPPORT)),TRUE)
     COM_DEFS    += __XDM__
  endif
endif

#
#ifdef BT_HFG_PROFILE
#  ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
#    COM_DEFS    +=  __BT_HFG_PROFILE__
#  else
#    COM_DEFS    += EXCLUDE_HFG_MODULE
#  endif
#endif
#

# JSR184
ifndef SUPPORT_JSR_184
   SUPPORT_JSR_184 = FALSE
endif

ifdef SUPPORT_JSR_184
  ifneq ($(strip $(SUPPORT_JSR_184)),FALSE)
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),96X64 128X128 128X160 176X220 240X320 320X240 ),)
      $(call DEP_ERR_SETA_OR_OFFB,MAIN_LCD_SIZE,non $(strip $(MAIN_LCD_SIZE)),SUPPORT_JSR_184)
    endif  
    ifeq ($(strip $(OPENGL)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,OPENGL,SUPPORT_JSR_184)
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
        $(call DEP_ERR_SETA_OR_OFFB,J2ME_SUPPORT,non JBLENDIA,SUPPORT_JSR_184)
    endif
    # We can turn on SUPPORT_JSR_184  when HI_VM/HI_VM_SOURCE is defined in J2ME_VM.
    ifeq ($(findstring HI_VM,$(J2ME_VM)),)
      $(call DEP_ERR_SETA_OR_OFFB,J2ME_VM,HI_VM/HI_VM_SOURCE,SUPPORT_JSR_184)
    endif
    ifdef OPENGL
      ifneq ($(strip $(OPENGL)),NONE)
        COM_DEFS += M3D_SUPPORT
      endif
    endif
  endif
endif


ifndef M3D_MMI_SUPPORT
   M3D_MMI_SUPPORT = FALSE
endif

ifdef M3D_MMI_SUPPORT
  ifneq ($(strip $(M3D_MMI_SUPPORT)),FALSE)
    ifeq ($(strip $(OPENGL)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,OPENGL,M3D_MMI_SUPPORT)
    else
       # We can turn on M3D_MMI_SUPPORT when HI_VM/HI_VM_SOURCE is defined in J2ME_VM.
       ifeq ($(strip $(SUPPORT_JSR_184)),FALSE)
          COM_DEFS += M3D_MMI_SUPPORT M3D_SUPPORT
       else
          COM_DEFS += M3D_MMI_SUPPORT
       endif
    endif
  endif
endif





ifdef LCM_ROTATE_SUPPORT
  ifeq ($(strip $(LCM_ROTATE_SUPPORT)),TRUE)
      COM_DEFS += LCM_ROTATE_SUPPORT
  endif
endif

ifdef EXIF_SUPPORT
  ifeq ($(strip $(EXIF_SUPPORT)),TRUE)
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,EXIF_SUPPORT)
    endif
      COM_DEFS += EXIF_SUPPORT
  endif
endif

ifdef SVG_SUPPORT
  ifeq ($(strip $(SVG_SUPPORT)),TRUE) # For backward compatible
    COM_DEFS += SVG_SUPPORT MTK_SVG
  else
    ifeq ($(strip $(SVG_SUPPORT)),MTK_SVG)
        ifneq ($(strip $(XML_SUPPORT)),TRUE)
            $(call DEP_ERR_SETA_OR_ONB,SVG_SUPPORT,non MTK_SVG,XML_SUPPORT)
        endif
       COM_DEFS += SVG_SUPPORT MTK_SVG
    else
      ifneq ($(strip $(SVG_SUPPORT)),FALSE) # For backward compatible
        ifeq ($(strip $(SVG_SUPPORT)),IKIVO_DEMO) # For demo project use
          CUS_REL_BASE_COMP += vendor\svg\ikivo\adaptation
          CUS_REL_BASE_COMP += make\ikivo_svg
        else
          ifneq ($(strip $(SVG_SUPPORT)),NONE)
            ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
              ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
                ifneq ($(strip $(SVG_SUPPORT)),IKIVO_DEMO)
                  ifneq ($(strip $(SVG_SUPPORT)),MTK_SVG)
                    $(error Please set SVG_SUPPORT to be IKIVO_DEMO or MTK_SVG in customer projects)
                  endif
                endif
              endif
            endif
            COM_DEFS += SVG_SUPPORT
            COM_DEFS += $(SVG_SUPPORT)
          endif
        endif
      endif
    endif
  endif

  ifeq ($(strip $(SVG_SUPPORT)),IKIVO_SVG12)
    COM_DEFS   += IKIVO_SVG SVG12_SUPPORT
    COMPLIST    += ikivo_svg 
    COMPOBJS  	+= vendor\svg\ikivo\engine_v1\ikivo_svglib.lib
    CUS_REL_OBJ_LIST += vendor\svg\ikivo\engine_v1\ikivo_svglib.lib
    CUS_REL_FILES_LIST += vendor\svg\ikivo\engine_v1\ikivo_svglib_modis.lib
  endif

  ifeq ($(strip $(SVG_SUPPORT)),IKIVO_SVG12_WITH_SCRIPT_ENGINE)
    COM_DEFS += IKIVO_SVG SVG12_SUPPORT IKIVO_SVG_SCRIPT_ENGINE
    COMPLIST    += ikivo_svg
    COMPOBJS  	+= vendor\svg\ikivo\engine_v1\ikivo_svglib.lib
    COMPOBJS  	+= vendor\svg\ikivo\engine_v1\ikivo_script_engine.lib
    CUS_REL_OBJ_LIST += vendor\svg\ikivo\engine_v1\ikivo_svglib.lib
    CUS_REL_OBJ_LIST += vendor\svg\ikivo\engine_v1\ikivo_script_engine.lib
    CUS_REL_FILES_LIST += vendor\svg\ikivo\engine_v1\ikivo_svglib_modis.lib
    CUS_REL_FILES_LIST += vendor\svg\ikivo\engine_v1\ikivo_script_engine_modis.lib
  endif
endif

#ifdef USB_IN_NORMAL_MODE_SUPPORT
#  ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
#	COM_DEFS += __USB_IN_NORMAL_MODE__
#	ifeq ($(strip $(BOARD_VER)),DRAGONFLY_BB)
#	   COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
#        endif
#	ifeq ($(strip $(BOARD_VER)),SAPPHIRE28_BB)
#	   COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
#        endif
#  endif
#endif

ifdef USB_IN_NORMAL_MODE_SUPPORT
  ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_IN_NORMAL_MODE_SUPPORT)
     else
	      COM_DEFS += __USB_IN_NORMAL_MODE__
	      COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
     endif
  endif
endif


ifneq ($(strip $(PLATFORM)),MT6205B)
   ifneq ($(strip $(PLATFORM)),MT6208)
     ifneq ($(strip $(PLATFORM)),MT6218B)
       ifneq ($(strip $(PLATFORM)),MT6217)
         COM_DEFS +=  __USIM_DRV__
       endif
     endif
   endif
endif

ifdef OTG_SUPPORT
  ifeq ($(strip $(OTG_SUPPORT)),TRUE)
  OTG_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238 MT6239 MT6268T MT6268H MT6268
    ifeq ($(filter $(strip $(PLATFORM)),$(OTG_SUPPORT_PLATFORM)),)
     $(error PLATFORM $(strip $(PLATFORM)) does not support OTG.)
    else
      ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_IN_NORMAL_MODE_SUPPORT,OTG_SUPPORT)
      else
        ifeq ($(strip $(USB_SUPPORT)),FALSE)
          $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,OTG_SUPPORT)
        else
          ifeq ($(strip $(USB_MULTI_CHARGE_CURRENT_SUPPORT)),FALSE)
            $(call DEP_ERR_ONA_OR_OFFB,USB_MULTI_CHARGE_CURRENT_SUPPORT,OTG_SUPPORT)
          else
            ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
              COM_DEFS	+= __OTG_ENABLE__
            endif
          endif
        endif
      endif
    endif
  endif
endif

ifdef OTG_DETECT_ID_PIN_WITH_EINT
  ifeq ($(strip $(OTG_DETECT_ID_PIN_WITH_EINT)),TRUE)
    ifeq ($(strip $(OTG_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,OTG_SUPPORT,OTG_DETECT_ID_PIN_WITH_EINT)
    else
	    COM_DEFS += __OTG_DETECT_IDPIN_WITH_EINT__
    endif
  endif
endif



ifdef OPENGL
  ifneq ($(strip $(OPENGL)),NONE)
     COM_DEFS +=  __OPENGL_SUPPORT__
     COMPLIST         += opengl opengl16 opengl_custom
     CUS_REL_MTK_COMP    += opengl opengl16
     CUS_REL_SRC_COMP    += opengl_custom
  endif
  ifeq ($(strip $(OPENGL)),COMMON_LITE)
     COM_DEFS +=  __COMMON_LITE__     
     OPENGL_OBJ_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6235 MT6235B MT6238 MT6239 
     ifneq ($(filter $(strip $(PLATFORM)) ,$(OPENGL_OBJ_SUPPORT_PLATFORM)),)
       COMPOBJS    += dp_engine\opengl\swrast\affine_span_sfo.obj
       COMPOBJS    += dp_engine\opengl\swrast\fast_persp_span_sfo.obj
       COMPOBJS    += dp_engine\opengl\swrast\s_span_arm_sfo_flat.obj
       COMPOBJS    += dp_engine\opengl\swrast\s_span_arm_sfo_smooth.obj
     endif
     CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\affine_span_sfo.obj
     CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\fast_persp_span_sfo.obj
     CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\s_span_arm_sfo_flat.obj
     CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\s_span_arm_sfo_smooth.obj
  endif
endif


ifneq ($(filter __DISABLE_SMS_CONTROLLED_BY_SIM__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __SAT__,$(strip $(COM_DEFS))),)
    $(error Please define __SAT__ or do not define __DISABLE_SMS_CONTROLLED_BY_SIM__)
  endif
endif

ifdef USB_MULTI_CHARGE_CURRENT_SUPPORT
  ifeq ($(strip $(USB_MULTI_CHARGE_CURRENT_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MULTI_CHARGE_CURRENT_SUPPORT)
     else
        COM_DEFS +=  __USB_MULTI_CHARGE_CURRENT__
     endif
  endif
endif

ifdef RC5_SUPPORT
  ifeq ($(strip $(RC5_SUPPORT)),TRUE)
    ifeq ($(findstring SEC,$(strip $(TELECA_FEATURE))),SEC)
      COM_DEFS    += RC5_SUPPORT
    endif
  endif
endif


ifdef GAME_ENGINE
  ifneq ($(strip $(GAME_ENGINE)),NONE)
     ifeq ($(strip $(OPENGL)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OPENGL,GAME_ENGINE)
     else
        COM_DEFS +=  $(strip $(GAME_ENGINE))
     endif
  endif
endif

ifdef YUV_SENSOR_SUPPORT
  ifneq ($(strip $(YUV_SENSOR_SUPPORT)),FALSE)
     ifeq ($(strip $(ISP_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,YUV_SENSOR_SUPPORT)
     else
        COM_DEFS += YUV_SENSOR_SUPPORT
     endif
  endif
endif

ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6225)
    ifdef ISP_SUPPORT
      ifneq ($(strip $(ISP_SUPPORT)),FALSE)
        ifdef YUV_SENSOR_SUPPORT
          ifeq ($(strip $(YUV_SENSOR_SUPPORT)),FALSE)
            $(call DEP_ERR_ONA_OR_OFFB,YUV_SENSOR_SUPPORT,ISP_SUPPORT)
          endif
        endif
      endif
    endif
  endif
endif

ifdef EXT_DAC_SUPPORT
  ifeq ($(strip $(EXT_DAC_SUPPORT)),TRUE)
     COM_DEFS    +=  EXT_DAC_SUPPORT
  endif
endif

ifdef UNIFIED_MESSAGE_SUPPORT
   ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
      ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        $(error $(MMI_VERSION) does not support UNIFIED_MESSAGE )
      endif
   endif
endif

ifdef UNIFIED_MESSAGE_SUPPORT
  ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
    ifneq ($(strip $(TELECA_FEATURE)),NONE)
      ifeq ($(findstring WAP,$(strip $(TELECA_FEATURE))),)
        $(call DEP_ERR_SETA_OR_OFFB,TELECA_FEATURE,WAP,UNIFIED_MESSAGE_SUPPORT)
      else
        ifeq ($(strip $(MMS_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,UNIFIED_MESSAGE_SUPPORT)
        else
          COM_DEFS    +=  __UNIFIED_MSG_SUPPORT__
        endif
      endif
    else
      $(call DEP_ERR_SETA_OR_OFFB,TELECA_FEATURE,WAP,UNIFIED_MESSAGE_SUPPORT)
    endif
  endif
endif

DRV_CUSTOM_TOOL_SUPPORT_PLATFORM = MT6253 MT6268 MT6236  
ifneq ($(filter $(call Upper,$(strip $(PLATFORM))) ,$(DRV_CUSTOM_TOOL_SUPPORT_PLATFORM)),)
    ifneq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
        $(error DRV_CUSTOM_TOOL_SUPPORT must be turned on when PLATFORM = $(strip $(PLATFORM)))
    endif
endif

ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
     COM_DEFS    +=  __CUST_NEW__
  endif
endif


ifdef WAP_SUPPORT
  ifdef TELECA_FEATURE
    ifneq ($(strip $(WAP_SUPPORT)),NONE)
      ifeq ($(strip $(TELECA_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,TELECA_FEATURE,WAP_SUPPORT)
      endif
    endif
    ifeq ($(strip $(WAP_SUPPORT)),NONE)
      ifneq ($(strip $(TELECA_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,TELECA_FEATURE)
      endif
    endif
  endif
endif


ifdef WAP_SUPPORT
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)
    COM_DEFS    +=   OBIGO_Q03C
  endif
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
    COM_DEFS    +=  OBIGO_Q05A
  endif
endif

ifneq ($(findstring MMS,$(strip $(TELECA_FEATURE))),)
    $(error $(strip $(TELECA_FEATURE)) is not a valid option of TELECA_FEATURE! Please modify it and set MMS_SUPPORT properly. )
endif

ifdef MMS_SUPPORT
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
      ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,MMS_SUPPORT,non OBIGO_Q03C_MMS_V02,UNIFIED_MESSAGE_SUPPORT)
      endif
      ifeq ($(findstring COMPOSER,$(UNIFIED_MESSAGE_ADVANCE_FEATURE)),)
        COM_DEFS    +=  __MMS_STANDALONE_COMPOSER_SUPPORT__
      endif
    endif
endif

ifeq ($(strip $(TELECA_FEATURE)),NONE)
  COM_DEFS    += WAP_NOT_PRESENT
  COM_DEFS    += WPS_NOT_PRESENT
else
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
    COM_DEFS    += WAP_NOT_PRESENT
  endif
endif


ifdef DSPIRDBG
   ifeq ($(strip $(DSPIRDBG)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,DSPIRDBG)
     endif
      COM_DEFS    += __DSPIRDBG__
      COM_DEFS    += __USB_LOGGING__
   endif
endif

ifndef ISP_SUPPORT
   COM_DEFS    += MED_C_NOT_PRESENT
endif

ifdef ISP_SUPPORT
   ifeq ($(strip $(ISP_SUPPORT)),FALSE)
      COM_DEFS    += MED_C_NOT_PRESENT
   endif
endif

ifdef PROJECT
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
      ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
        COM_DEFS    += __MANUAL_MODE_NW_SEL__  __NORMAL_NW_SEARCH__
      endif
    endif
  endif
endif

ifdef CUST_PARA_SUPPORT
   ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
     ifneq ($(strip $(SECURE_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,CUST_PARA_SUPPORT)
     endif
     COM_DEFS += __CUST_PARA_SUPPORT__
   endif
endif

ifdef DISPLAY_TYPE
  COM_DEFS    += __MMI_DISPLAY_TYPE_$(call Upper,$(strip $(DISPLAY_TYPE)))__
  ifeq ($(strip $(DISPLAY_TYPE)),BW)
    ifdef SENSOR_TYPE
      ifeq ($(strip $(SENSOR_TYPE)),DIRECT)
        $(error DISPLAY_TYPE = $(strip $(DISPLAY_TYPE)) does not support SENSOR_TYPE = $(strip $(SENSOR_TYPE)))
      endif
    endif
  endif
endif

ifdef OTP_SUPPORT
   ifeq ($(strip $(OTP_SUPPORT)),TRUE)
      COM_DEFS    += __SECURITY_OTP__
   endif
endif

#6226C (S02), 6229E4, and 6225 and newer chip related project only.
SECURE_SUPPORT_NOT_SUPPORT_PLATFORM = MT6205B MT6208 MT6217 MT6218B MT6219 MT6226 MT6226M MT6227 MT6228 MT6229
SECURE_SUPPORT_NOT_SUPPORT_PARTIAL_PLATFORM = MT6226 MT6226M MT6227 MT6229
SECURE_SUPPORT_NOT_SUPPORT_CHIPVER = S00 S01
# For 6226, 6226M, 6227, 6229: only 6226C (S02), 6226M (S02), 6227 (S02), 6229E4 (S02) and later chip version support SECURE PLATFORM

SECURE_SUPPORT_NOT_SUPPORT_NFB_PLATFORM = MT6226 MT6229 MT6225 MT6253T MT6253 MT6223 MT6227 MT6230 MT6226M MT6223P
SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM = MT6226 MT6229 MT6227 MT6226M
SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER = S00 S01 S02
# For 6229 (S00, S01, S02), 6226 (S00, S01, S02), 6227 (S00, S01, S02), 6226M (S00, S01, S02): do not support SECURE PLATFORM when NFB is on

ifdef SECURE_SUPPORT
  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_RO_ENABLE,SECURE_SUPPORT)
    endif
    # Platforms which do not support secure platform
    ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_PLATFORM)),)
      ifneq ($(filter $(strip $(PLATFORM)), $(SECURE_SUPPORT_NOT_SUPPORT_PARTIAL_PLATFORM)),)
        # Platforms which do not support secure platform
        ifneq ($(filter $(strip $(CHIP_VER)), $(SECURE_SUPPORT_NOT_SUPPORT_CHIPVER)),)
          $(error $(strip $(PLATFORM)) $(strip $(CHIP_VER)) does not support SECURE_SUPPORT.)
        # Platforms which partially support secure platform (new chip version)
        else
          ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM)),)
            ifneq ($(filter $(strip $(CHIP_VER)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER)),)
              ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
                COM_DEFS    += __MTK_SECURE_PLATFORM__
              else
                $(error $(strip $(PLATFORM)) $(strip $(CHIP_VER)) does not support SECURE_SUPPORT when NAND_FLASH_BOOTING is not NONE.)
              endif
            # new chip version of partial NFB support platform
            else
              COM_DEFS    += __MTK_SECURE_PLATFORM__
            endif
          endif
        endif
      # Platforms which do not support secure platform
      else
        $(error $(strip $(PLATFORM)) not support SECURE_SUPPORT.)
      endif
    # Platforms which support secure platform
    else
      ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PLATFORM)),)
        ifneq ($(filter $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM)),)
          ifneq ($(filter $(strip $(CHIP_VER)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER)),)
            ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
              COM_DEFS    += __MTK_SECURE_PLATFORM__
            else
              $(error $(strip $(PLATFORM)) $(strip $(CHIP_VER)) not support SECURE_SUPPORT when NAND_FLASH_BOOTING is not NONE.)
            endif
          endif
        #  NFB support platform
        else
          ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
            COM_DEFS    += __MTK_SECURE_PLATFORM__
          else
            $(error $(strip $(PLATFORM)) not support SECURE_SUPPORT when NAND_FLASH_BOOTING is not NONE.)
          endif
        endif
      # other support platforms
      else
        COM_DEFS    += __MTK_SECURE_PLATFORM__
      endif
    endif
  endif
endif

ifdef SECURE_RO_ENABLE
  ifeq ($(strip $(SECURE_RO_ENABLE)),TRUE)
    ifeq ($(strip $(SECURE_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,SECURE_RO_ENABLE)
    else
      COM_DEFS    += __SECURE_RO_ENABLE__
    endif
  endif
endif

ifdef DOWNLOADABLE_THEME
   ifeq ($(strip $(DOWNLOADABLE_THEME)),TRUE)
      ifdef XML_SUPPORT
        ifneq ($(strip $(XML_SUPPORT)),TRUE)
           $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,DOWNLOADABLE_THEME)
        endif
      endif
      ifeq ($(strip $(WAP_SUPPORT)),NONE)
         $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,DOWNLOADABLE_THEME)
      endif
      COM_DEFS    += __DOWNLOADABLE_THEME__
   endif
endif

ifndef DLT_ALWAYS_LOAD_BUFFER_SIZE
   DLT_ALWAYS_LOAD_BUFFER_SIZE = 0
endif

ifdef DLT_ALWAYS_LOAD_BUFFER_SIZE
   COM_DEFS    += __DLT_ALWAYS_LOAD_BUFFER_SIZE__=$(strip $(DLT_ALWAYS_LOAD_BUFFER_SIZE))
endif

ifndef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
   DLT_LOAD_ON_DEMAND_BUFFER_SIZE = 0
endif

ifdef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
   COM_DEFS    += __DLT_LOAD_ON_DEMAND_BUFFER_SIZE__=$(strip $(DLT_LOAD_ON_DEMAND_BUFFER_SIZE))
endif

TEARING_REDUCTION_FB_PLATFORM = MT6227 MT6227D MT6226 MT6226M MT6226D 
ifneq ($(filter $(strip $(PLATFORM)),$(TEARING_REDUCTION_FB_PLATFORM)),)
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),240X320)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),320X240)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),400X240)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),400X240)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
endif

ifdef STREAM_SUPPORT
  ifeq ($(strip $(STREAM_SUPPORT)),TRUE)
     COM_DEFS    += STREAM_SUPPORT
  endif
endif

ifdef PGDL_SUPPORT
  ifeq ($(strip $(PGDL_SUPPORT)),TRUE)
    PGDL_NOT_SUPPORT_PLATFORM = MT6205% MT6217 MT6218% MT6219 MT6223% MT6225 MT6226% MT6227% MT6228
    ifneq ($(filter $(strip $(PGDL_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM))),)
      $(error $(strip $(PLATFORM)) does NOT support PGDL_SUPPORT)
    endif
     ifneq ($(strip $(STREAM_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,STREAM_SUPPORT,PGDL_SUPPORT)
     endif
     COM_DEFS    += PGDL_SUPPORT
  endif
endif

ifndef VIRTUAL_PORTS_NUM
     VIRTUAL_PORTS_NUM = 5
endif

ifdef VIRTUAL_PORTS_NUM
     COM_DEFS    += VIRTUAL_PORTS_NUM=$(strip $(VIRTUAL_PORTS_NUM))
endif

ifdef SYNCML_DM_SUPPORT
  ifeq ($(strip $(SYNCML_DM_SUPPORT)),TRUE)
    COM_DEFS    += SYNCML_DM_SUPPORT
    COMPLIST    += dm
    #### CUS_REL_SRC_COMP    += dm
    COMPLIST    += dmsdk
    #### CUS_REL_SRC_COMP    += dmsdk    
  endif
endif

ifeq ($(strip $(SPATIAL_DITHERING)),TRUE)
     COM_DEFS += __SPATIAL_DITHERING__
endif

ifeq ($(strip $(PICTBRIDGE_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,PICTBRIDGE_SUPPORT)
     endif
     ifeq ($(strip $(XML_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,PICTBRIDGE_SUPPORT)
     endif
     COM_DEFS +=  PICTBRIDGE_SUPPORT
     COM_DEFS +=  __USB_IMAGE_CLASS__
endif

ifdef UNIFIED_MESSAGE_SUPPORT
   ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),FALSE)
      ifeq ($(strip $(UNIFIED_MESSAGE_SIMBOX_SUPPORT)),TRUE)   
         $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_SUPPORT,UNIFIED_MESSAGE_SIMBOX_SUPPORT)
      endif   
   else
      ifeq ($(strip $(UNIFIED_MESSAGE_SIMBOX_SUPPORT)),TRUE)
         COM_DEFS	+= __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
      endif
   endif
endif

ifdef TDMB_SUPPORT
  ifneq ($(strip $(TDMB_SUPPORT)),NONE)
    COMPLIST += cyberlink
    COM_DEFS += __TDMB_SUPPORT__
    COMPOBJS += vendor\tdmb\cyberlink\lib\arm\LibDemuxInterface.a
    COMPOBJS += vendor\tdmb\cyberlink\lib\arm\LibDLSParser.a
    COMPOBJS += vendor\tdmb\cyberlink\lib\arm\LibPADParser.a
    CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\arm\LibDemuxInterface.a
    CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\arm\LibDLSParser.a
    CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\arm\LibPADParser.a	
    CUS_REL_BASE_COMP += vendor\tdmb\cyberlink\lib
  endif
  ifeq ($(strip $(TDMB_SUPPORT)),TELECHIP_TDMB)
    COMPLIST += tdmb
    COM_DEFS    += TELECHIP_TDMB
    COMPOBJS    += tdmb\tc3100\lib\ops.a tdmb\tc3100\lib\opi.a
    COMPOBJS    += tdmb\tc3100\OSSDK\lib\ads_arm7tdmi\CommonAPI.a
    COMPOBJS    += tdmb\tc3100\OSSDK\lib\ads_arm7tdmi\FICParser.a
    CUS_REL_OBJ_LIST += tdmb\tc3100\lib\ops.a tdmb\tc3100\lib\opi.a
    CUS_REL_OBJ_LIST += tdmb\tc3100\OSSDK\lib\ads_arm7tdmi\CommonAPI.a
    CUS_REL_OBJ_LIST += tdmb\tc3100\OSSDK\lib\ads_arm7tdmi\FICParser.a
  endif 
  ifeq ($(strip $(TDMB_SUPPORT)),FRONTIER_TDMB)
    COMPLIST += tdmb
    COM_DEFS    += FRONTIER_TDMB
    COMPOBJS    += tdmb\Frontier\deniro.lib
    COMPOBJS    += tdmb\Frontier\fs_fig.lib
    CUS_REL_OBJ_LIST += tdmb\Frontier\deniro.lib
    CUS_REL_OBJ_LIST += tdmb\Frontier\fs_fig.lib
  endif
endif


ifneq ($(strip $(OPTR_SPEC)), VODAFONE_R12_LIVE)
   COM_DEFS    += __IP_NUMBER__
endif


ifdef ISO_PRIORITY_MODE_SUPPORT
   ifeq ($(strip $(ISO_PRIORITY_MODE_SUPPORT)),TRUE)
      COM_DEFS    += ISO_PRIORITY_SUPPORT 
   endif       
endif 


ifdef KEYPAD_TYPE
   ifeq ($(strip $(KEYPAD_TYPE)),NORMAL_KEYPAD)
      COM_DEFS    += NORMAL_KEYPAD 
   endif       
   ifeq ($(strip $(KEYPAD_TYPE)),REDUCED_KEYPAD)
      COM_DEFS    += REDUCED_KEYPAD 
   endif          
   ifeq ($(strip $(KEYPAD_TYPE)),QWERTY_KEYPAD)
      COM_DEFS    += QWERTY_KEYPAD 
   endif
endif

ifdef KEYPAD_TYPE
  ifeq ($(strip $(KEYPAD_TYPE)), REDUCED_KEYPAD)
    ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      $(call DEP_ERR_SETA_OR_ONB,KEYPAD_TYPE,non $(KEYPAD_TYPE),TOUCH_PANEL_SUPPORT)
    endif
  endif
  ifeq ($(strip $(KEYPAD_TYPE)), QWERTY_KEYPAD)
    ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),)
      $(call DEP_ERR_SETA_OR_ONB,KEYPAD_TYPE,non $(KEYPAD_TYPE),__TWO_KEY_DETECTION_SWITCHABLE__)
    endif
  endif
endif

ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    ifeq ($(strip $(APP_STORAGE_IN_SYS_DRV)),TRUE) 
      $(call DEP_ERR_OFFA_OR_OFFB,APP_STORAGE_IN_SYS_DRV,NAND_SUPPORT)
    endif
  endif
endif

ifdef FLASHLIGHT_TYPE
  ifneq ($(strip $(FLASHLIGHT_TYPE)),NONE)
    ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_ONOFF_SUPPORT)
       COM_DEFS    += LED_ONOFF_SUPPORT 
    endif          
    ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_FLASHLIGHT_SUPPORT)
       COM_DEFS    += LED_FLASHLIGHT_SUPPORT 
    endif          
    ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT)
       COM_DEFS    += XENON_FLASHLIGHT 
    endif          
    ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT_ANTI_RED_EYE)
       COM_DEFS    += XENON_FLASHLIGHT_ANTI_RED_EYE 
    endif            
  endif
endif

XENON_FLASHLIGHT_SUPPORT_PLATFORM = MT6238 MT6239
ifdef FLASHLIGHT_TYPE
  ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT)
    ifeq ($(filter $(strip $(PLATFORM)),$(XENON_FLASHLIGHT_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(FLASHLIGHT_TYPE)))
    endif
    ifdef FLASHLIGHT_MODULE
      ifeq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_SETA_OR_ONB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
      endif
    else
        $(call DEP_ERR_SETA_OR_ONB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
    endif
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT_ANTI_RED_EYE)
    ifeq ($(filter $(strip $(PLATFORM)),$(XENON_FLASHLIGHT_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does NOT support $(strip $(FLASHLIGHT_TYPE)))
    endif
    ifdef FLASHLIGHT_MODULE
      ifeq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_SETA_OR_ONB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
      endif
    else
        $(call DEP_ERR_SETA_OR_ONB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
    endif
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_ONOFF_SUPPORT)
    ifdef FLASHLIGHT_MODULE
      ifneq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
      endif
    endif 
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_FLASHLIGHT_SUPPORT)
    ifdef FLASHLIGHT_MODULE
      ifneq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_SETA_OR_OFFB,FLASHLIGHT_TYPE,non $(strip $(FLASHLIGHT_TYPE)),FLASHLIGHT_MODULE)
      endif
    endif 
  endif
  ifeq ($(strip $(FLASHLIGHT_TYPE)),NONE)
    ifdef FLASHLIGHT_MODULE
      ifneq ($(strip $(FLASHLIGHT_MODULE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,FLASHLIGHT_TYPE,FLASHLIGHT_MODULE)
      endif
    endif
  endif
endif

ifdef FLASHLIGHT_TYPE
  ifneq ($(strip $(FLASHLIGHT_TYPE)),NONE)
    ifneq ($(filter $(strip $(PLATFORM)),$(XENON_FLASHLIGHT_SUPPORT_PLATFORM)),)
      CUS_REL_BASE_COMP += custom\drv\Flashlight_module\IMCR3603_S010AO \
                           media\camera_v2\include
    endif
  endif
endif

#ifdef LANGLN_ENGINE
#   ifeq ($(strip $(LANGLN_ENGINE)),LANGLN_DIGIDEA)   
#      COM_DEFS    += LANGLN_DIGIDEA         
#   endif
#endif

ifeq ($(strip $(call Upper,$(MAIN_LCD_SIZE))),320X480)
    ifndef TOUCH_PANEL_SUPPORT
      $(call DEP_ERR_SETA_OR_ONB,MAIN_LCD_SIZE,non $(strip $(call Upper,$(MAIN_LCD_SIZE))),TOUCH_PANEL_SUPPORT)
    endif
    ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      $(call DEP_ERR_SETA_OR_ONB,MAIN_LCD_SIZE,non $(strip $(call Upper,$(MAIN_LCD_SIZE))),TOUCH_PANEL_SUPPORT)
    endif
endif

ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6238)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__
  endif
  ifeq ($(strip $(PLATFORM)),MT6235)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__
  endif
  ifeq ($(strip $(PLATFORM)),MT6268A)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__
  endif
  ifeq ($(strip $(PLATFORM)),MT6268)
      COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__
  endif

endif


ifdef GIS_SUPPORT
  ifneq ($(strip $(GIS_SUPPORT)),NONE)
    ifneq ($(strip $(BT_GPS_SUPPORT)),TRUE)
        ifndef GPS_SUPPORT
            $(call DEP_ERR_ONA_OR_OFFB,BT_GPS_SUPPORT/GPS_SUPPORT,GIS_SUPPORT)
        endif
        ifeq ($(strip $(GPS_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,BT_GPS_SUPPORT/GPS_SUPPORT,GIS_SUPPORT)
        endif
    endif
    ifneq ($(strip $(call Upper,$(MAIN_LCD_SIZE))),240X320)
      $(call DEP_ERR_SETA_OR_OFFB,MAIN_LCD_SIZE,240X320,GIS_SUPPORT)
    endif
    ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,GIS_SUPPORT)
    endif
    COMPLIST    += gis
    COM_DEFS    += GIS_SUPPORT

    ifeq ($(strip $(GIS_SUPPORT)),SUNAVI)
       COM_DEFS    += GIS_SUNAVI
       COMPOBJS    += vendor\gis\sunavi\v1_demo\arm\sunavi_target.lib
    endif
    
    ifeq ($(strip $(GIS_SUPPORT)),MAPBAR_NAVI)
       COM_DEFS    += GIS_MAPBAR_NAVI
       COMPOBJS    += vendor\gis\mapbar\v1_demo\arm\mapbar_navi.a
    endif 
    
    ifeq ($(strip $(GIS_SUPPORT)),MAPBAR_BUS)
       COM_DEFS    += GIS_MAPBAR_BUS
       COMPOBJS    += vendor\gis\mapbar\v1_demo\arm\mapbar_bus.a
    endif
    
    ifeq ($(strip $(GIS_SUPPORT)),MIGO)
       COM_DEFS    += GIS_MIGO
       COMPOBJS    += vendor\gis\migo\lib\migo_gis_engine.lib
       COMPOBJS    += vendor\gis\migo\lib\migo_ui_framework.lib
    endif
       
  endif
endif

ifdef BT_GPS_SUPPORT
  ifneq ($(strip $(BT_GPS_SUPPORT)),FALSE)
    ifndef BT_SPP_CLIENT
      $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_CLIENT,BT_GPS_SUPPORT)
    endif
    ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,BT_SPP_CLIENT,BT_GPS_SUPPORT)
    endif
    COM_DEFS  += __BT_GPS_SUPPORT__  
    COMPLIST += gps
  endif
endif

ifdef LANGLN_ENGINE
  ifneq ($(strip $(LANGLN_ENGINE)),NONE)
    COM_DEFS += $(LANGLN_ENGINE)
    COM_DEFS += LANGLN_ENABLE
    COMPLIST += langln
    CUS_REL_SRC_COMP += langln
    
    ifeq ($(strip $(LANGLN_ENGINE)),LANGLN_DIGIDEA)
      COMPOBJS            += vendor\langlearn\digidea\engine_01\dzdarm.a
      CUS_REL_OBJ_LIST    += vendor\langlearn\digidea\engine_01\dzdarm.a
      CUS_REL_OBJ_LIST    += vendor\langlearn\digidea\engine_01\dzdpc.lib
      COMMINCDIRS         += vendor\langlearn\digidea\adaptation\inc
      CUSTOM_COMMINC      += vendor\langlearn\digidea\adaptation\inc
      CUS_REL_BASE_COMP   += vendor\langlearn\Courseware\Demo_Version
    endif
  endif
endif


ifdef TCPIP_SUPPORT
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(error $(MMI_VERSION) does not support TCPIP_SUPPORT)
    endif
    TCPIP_SUPPORT_ON_CONDITION = FALSE
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      TCPIP_SUPPORT_ON_CONDITION = TRUE
    endif  
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      TCPIP_SUPPORT_ON_CONDITION = TRUE
    endif
    ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      TCPIP_SUPPORT_ON_CONDITION = TRUE
    endif
    ifeq ($(strip $(TCPIP_SUPPORT_ON_CONDITION)),FALSE)
      $(error Please add __PS_SERVICE__ to CUSTOM_OPTION or turn on CSD_SUPPORT or turn on WIFI_SUPPORT when TCPIP_SUPPORT is turned on!)
    endif
  endif
endif


ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    ifneq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
      ifneq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
        $(call DEP_ERR_SETA_OR_OFFB,SSL_SUPPORT,SSL_CIC_LIB,WIFI_SUPPORT)
      endif
    endif
    ifneq ($(strip $(SECLIB_SUPPORT)),BASIC)
        $(call DEP_ERR_SETA_OR_OFFB,SECLIB_SUPPORT,BASIC,WIFI_SUPPORT)
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,WIFI_SUPPORT)
    endif
  endif
endif


ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)), NONE)
    COM_DEFS            += __CERTMAN_SUPPORT__
    COMPLIST            += certman sec_store
    CUS_REL_BASE_COMP   += security\certman\presetdata
  endif
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)), TRUE)
    COM_DEFS            += __SSL_SUPPORT__
    COMPLIST            += tls
  endif
endif

ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)),NONE)
    ifeq ($(strip $(WIFI_SUPPORT)),NONE)
      ifneq ($(strip $(SSL_SUPPORT)),OPENSSL)
        ifneq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
          $(call DEP_ERR_SETA_OR_ONB,SSL_SUPPORT,OPENSSL or OPENSSL_MTK,WIFI_SUPPORT)
        endif
      endif
    endif 
    ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
      ifneq ($(strip $(SECLIB_SUPPORT)), PKI)    	
      	$(error Please set SSL_SUPPORT as NONE or set SECLIB_SUPPORT as PKI!)
      endif
    endif
  	ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
      ifneq ($(strip $(SECLIB_SUPPORT)), PKI)    	
      	$(error Please set SSL_SUPPORT as NONE or set SECLIB_SUPPORT as PKI!)
      endif
    endif
    ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
      ifeq ($(strip $(SECLIB_SUPPORT)), NONE)
         $(error Please set SSL_SUPPORT as NONE or set SECLIB_SUPPORT as BASIC!)
      endif
      ifeq ($(strip $(SECLIB_SUPPORT)), PKI)
         $(warning WARNING Duplicate PKI library from Certicom SSL and OpenSSL!)
         $(error Please set SSL_SUPPORT as OPENSSL_SRC or set SECLIB_SUPPORT as BASIC.)
      endif
    endif
    ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
      ifeq ($(strip $(SECLIB_SUPPORT)), NONE)
         $(error Please set SSL_SUPPORT as NONE or set SECLIB_SUPPORT as BASIC!)
      endif
      ifeq ($(strip $(SECLIB_SUPPORT)), PKI)
         $(warning WARNING Duplicate PKI library from Certicom SSL and OpenSSL!)
         $(error Please set SSL_SUPPORT as OPENSSL_SRC or set SECLIB_SUPPORT as BASIC.)
      endif
    endif  
  endif
endif

ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
     COMPLIST         += sb51 sbpki2 sslplus5 sslplus5adp sbpki2adp
     COM_DEFS         += __SSL_CIC__
  endif   
  
  ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
     COMPOBJS         += vendor_sec\security\certicom\v1_official\sslplus5.lib
     CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sslplus5.lib
     COMPOBJS         += vendor_sec\security\certicom\v1_official\sb51.lib
     CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sb51.lib
     COMPOBJS         += vendor_sec\security\certicom\v1_official\sbpki2.lib
     CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sbpki2.lib
     COMPLIST         += sslplus5adp sbpki2adp
     COM_DEFS         += __SSL_CIC__
  endif
  
  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL)
     COMPLIST         += ossl_ssl ossl_ssladp
     COM_DEFS         += __OPENSSL__
  endif   
  ifeq ($(strip $(SSL_SUPPORT)),OPENSSL_MTK)
     COMPLIST         += ossl_ssl ossl_ssladp
     COM_DEFS         += __OPENSSL__
     COM_DEFS         += __OPENSSL_CHE_PORTING__
  endif   
endif

ifdef SOCKET_SSL_SUPPORT
  ifeq ($(strip $(SOCKET_SSL_SUPPORT)),TRUE)
    ifndef SSL_SUPPORT
     $(error Please define SSL_SUPPORT!)
    endif
    ifeq ($(strip $(SSL_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,SOCKET_SSL_SUPPORT)
    endif
  endif
endif

ifdef WIFI_SUPPORT
   ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      COM_DEFS += __WIFI_CHIP_DYM_POWERON__
      ifneq ($(strip $(GEMINI)),TRUE)
        COM_DEFS += EAP_SIM
      endif
   endif
endif

ifdef CHIP_VERSION_CHECK
   ifeq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
      COM_DEFS += __CHIP_VERSION_CHECK__
   endif
else
   $(error The feature CHIP_VERSION_CHECK should be defined as TRUE or FALSE)
endif

ifdef PURE_AUDIO_SUPPORT
   ifeq ($(strip $(PURE_AUDIO_SUPPORT)),TRUE)
      ifeq ($(strip $(AAC_DECODE)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,PURE_AUDIO_SUPPORT)
      endif
      COM_DEFS    += PURE_AUDIO_SUPPORT
   endif
endif

ifdef BACKGROUND_SMS_SUPPORT
  ifeq ($(strip $(BACKGROUND_SMS_SUPPORT)),TRUE)
    ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_SUPPORT,BACKGROUND_SMS_SUPPORT)
    endif
    COM_DEFS    +=  __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
  endif
endif 

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
   COM_DEFS    +=  __GSM_RAT__ 
endif

AUDIO_3D_SURROUND_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6235 MT6235B MT6238 MT6239 MT6268T MT6268H MT6268 MT6268A MT6268 
ifdef AUDIO_3D_SURROUND
  ifneq ($(strip $(AUDIO_3D_SURROUND)),NONE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(AUDIO_3D_SURROUND_SUPPORT_PLATFORM)),)
      $(error $(strip $(PLATFORM)) does not support AUDIO_3D_SURROUND)
    endif
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
    ifeq ($(strip $(AUDIO_3D_SURROUND)),MODE_LSPK)
      COM_DEFS += AUD_3D_SURROUND_LSPK
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += dp_engine\BesSound\BesSurround_arm.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesSurround_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += dp_engine\BesSound\BesSurround_arm_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesSurround_arm_rvct.a
      endif
    endif
    ifeq ($(strip $(AUDIO_3D_SURROUND)),MODE_EARP)
      COM_DEFS += AUD_3D_SURROUND_EARP
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += dp_engine\BesSound\BesHeadPhone_arm.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesHeadPhone_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += dp_engine\BesSound\BesHeadPhone_arm_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesHeadPhone_arm_rvct.a
      endif
    endif
    ifeq ($(strip $(AUDIO_3D_SURROUND)),MODE_BOTH)
      COM_DEFS += AUD_3D_SURROUND_LSPK AUD_3D_SURROUND_EARP
      ifeq ($(strip $(COMPILER)),ADS)
        COMPOBJS    += dp_engine\BesSound\BesSurround_arm.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesSurround_arm.a
        COMPOBJS    += dp_engine\BesSound\BesHeadPhone_arm.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesHeadPhone_arm.a
      endif
      ifeq ($(strip $(COMPILER)),RVCT)
        COMPOBJS    += dp_engine\BesSound\BesSurround_arm_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesSurround_arm_rvct.a
        COMPOBJS    += dp_engine\BesSound\BesHeadPhone_arm_rvct.a
        CUS_REL_OBJ_LIST += dp_engine\BesSound\BesHeadPhone_arm_rvct.a
      endif
    endif
  endif
endif

#ifdef WBXML_SUPPORT
#  ifeq ($(strip $(WBXML_SUPPORT)),TRUE)
#	  ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
#      COM_DEFS    += WBXML_SUPPORT
#      COMPLIST    += wbxmlp
#      CUS_REL_SRC_COMP    += wbxmlp
#	  endif
#	  ifeq ($(strip $(call Upper,$(PROJECT))),UMTS)
#      COM_DEFS    += WBXML_SUPPORT
#      COMPLIST    += wbxmlp
#      CUS_REL_SRC_COMP    += wbxmlp
#	  endif  
#  endif
#endif

ifdef WBXML_SUPPORT
  ifeq ($(strip $(WBXML_SUPPORT)),TRUE)
    COM_DEFS    += __WBXML_SUPPORT__
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      COMPLIST    += xmlp
    endif
  endif
endif 

# Check if BT is connected to UART2 or NOT
ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)              # BT is supported
    ifdef BT_CONNECT_TO_UART2
      ifeq ($(strip $(BT_CONNECT_TO_UART2)),TRUE)        # BT module is connected to UART2
        COM_DEFS += __BT_USE_UART2__
      endif
    endif
  endif 
endif

# When BT is connected to UART2, we will only allow one uart be configured in engineer mode
ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)              # BT is supported
    ifdef BT_CONNECT_TO_UART2
      ifeq ($(strip $(BT_CONNECT_TO_UART2)),TRUE)        # BT module is connected to UART2
        COM_DEFS += __ONLY_ONE_UART__
      endif
    endif
  endif 
endif 

ifdef AUDIO_EQ_ENABLE
  ifeq ($(strip $(AUDIO_EQ_ENABLE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),MT6205 MT6205B ),)
      $(error AUDIO_EQ_ENABLE is not supported on $(PLATFORM)!)
    endif
    COM_DEFS += AUDIO_EQ_ENABLE
    COM_DEFS += AUDIO_EQUALIZER_ENABLE
    CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
    ifeq ($(strip $(COMPILER)),ADS)
      COMPOBJS    += dp_engine\BesSound\BesEQ_arm.a
      CUS_REL_OBJ_LIST += dp_engine\BesSound\BesEQ_arm.a
    endif
    ifeq ($(strip $(COMPILER)),RVCT)
      COMPOBJS    += dp_engine\BesSound\BesEQ_arm_rvct.a
      CUS_REL_OBJ_LIST += dp_engine\BesSound\BesEQ_arm_rvct.a
    endif
  endif
endif

ifdef AUDIO_LOUDNESS
   ifneq ($(strip $(AUDIO_LOUDNESS)),NONE)
      AUDIO_LOUDNESS_SUPPORT_PLATFORM = MT6225 MT6228 MT6229 MT6230 MT6238 MT6239 MT6235 MT6235B MT6268A MT6268 MT6268T MT6268H MT6268 MT6253T MT6253 
      ifeq ($(strip $(AUDIO_LOUDNESS)),LOUDSPEAKER)
         COM_DEFS += AUD_LOUDNESS_ON_LOUDSPEAKER
         COM_DEFS += AUD_LOUDNESS_ENABLE
      endif
      ifeq ($(strip $(AUDIO_LOUDNESS)),LOUDSPEAKER_RINGTONE)
         COM_DEFS += AUD_LOUDNESS_ON_LOUDSPEAKER_RINGTONE
         COM_DEFS += AUD_LOUDNESS_ENABLE
      endif
      ifneq ($(filter $(strip $(PLATFORM)) ,$(AUDIO_LOUDNESS_SUPPORT_PLATFORM)),)
        CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
        ifeq ($(strip $(COMPILER)),ADS)
          COMPOBJS    += dp_engine\BesSound\BesLoudness_arm.a
          CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLoudness_arm.a
        endif
        ifeq ($(strip $(COMPILER)),RVCT)
          COMPOBJS    += dp_engine\BesSound\BesLoudness_arm_rvct.a
          CUS_REL_OBJ_LIST += dp_engine\BesSound\BesLoudness_arm_rvct.a
        endif
      else
        $(error $(strip $(PLATFORM)) does not support AUDIO_LOUDNESS)
      endif
   endif
endif

ifdef AUDIO_COMPENSATION_ENABLE
  AUDIO_EQ_ENABLE_AUDIO_COMPENSATION_ENABLE_EXCLUSIVE_PLATFORM = MT6219 MT6223 MT6225 MT6226 MT6226D MT6226M MT6227D MT6227 
  ifeq ($(strip $(AUDIO_COMPENSATION_ENABLE)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),MT6205 MT6205B ),)
      $(error AUDIO_COMPENSATION_ENABLE is not supported on $(PLATFORM)!)
    endif
    COM_DEFS += AUDIO_COMPENSATION_ENABLE
    ifeq ($(strip $(AUDIO_EQ_ENABLE)),TRUE)
      ifneq ($(filter $(strip $(PLATFORM)),$(AUDIO_EQ_ENABLE_AUDIO_COMPENSATION_ENABLE_EXCLUSIVE_PLATFORM)),)
        $(error AUDIO_EQ_ENABLE and AUDIO_COMPENSATION_ENABLE must be exclusive in $(PLATFORM)!)
      endif
    endif
  else
    ifneq ($(filter $(strip $(PLATFORM)) ,MT6228 MT6229 MT6235 MT6235B MT6238 MT6239 ),)
      $(error AUDIO_COMPENSATION_ENABLE must turn on in $(PLATFORM)!)
    endif
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6238)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6239)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6235)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6235B)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6253T)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6253)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),TK6516)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6516)
   COM_DEFS += __NFI_VERSION3__
endif

ifeq ($(strip $(PLATFORM)),MT6268A)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6268)
   COM_DEFS += __NFI_VERSION2__ __NAND_FDM_50__
endif

SAIC_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 
ifeq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __SAIC__
endif
ifneq ($(filter __SAIC__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
    $(error __SAIC__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
  endif
endif

REPEATED_ACCH_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6223 MT6223P MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 MT6235 MT6235B MT6238 MT6239 MT6268T MT6268H 
ifeq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __REPEATED_ACCH__
endif
ifneq ($(filter __REPEATED_ACCH__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
    $(error __REPEATED_ACCH__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
  endif
endif

ifdef BSAC_DECODE
  BSAC_DECODE_PLATFORM_CHIP_VER = $(strip $(PLATFORM))_$(strip $(CHIP_VER))
  ifeq ($(strip $(BSAC_DECODE)),TRUE)
    ifneq ($(strip $(BSAC_DECODE_PLATFORM_CHIP_VER)),MT6228_S02)
      ifneq ($(strip $(BSAC_DECODE_PLATFORM_CHIP_VER)),MT6229_S02)
        ifneq ($(strip $(BSAC_DECODE_PLATFORM_CHIP_VER)),MT6230_S02)
          ifneq ($(strip $(PLATFORM)),MT6238)
            ifneq ($(strip $(PLATFORM)),MT6239)
              ifneq ($(strip $(PLATFORM)),MT6268A)
                ifneq ($(strip $(PLATFORM)),MT6268)
                  $(error BSAC_DECODE only support on MT6228_S02, MT6229_S02, MT6230_S02, MT6238, MT6239, MT6268A, MT6268 !!)
                endif
              endif
            endif
          endif
        endif
      endif
    endif
    ifneq ($(strip $(AAC_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,BSAC_DECODE)
    endif
    
    COM_DEFS += BSAC_DECODE
  endif
endif

ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
       COM_DEFS   += IMPS_WV13_ENHANCEMENT
     endif

ifeq ($(strip $(INTERNAL_ANTENNAL_SUPPORT)),TRUE)
   COM_DEFS    += INTERNAL_ANTENNAL_SUPPORT
endif

ifeq ($(strip $(TST_WRITE_TO_FILE)),TRUE)
   ifeq ($(strip $(TST_SUPPORT)),TRUE)
      COM_DEFS    += __TST_WRITE_TO_FILE__
   endif
endif

ifdef MP4_ENCODE
  ifneq ($(strip $(MP4_ENCODE)),NONE)
    ifeq ($(strip $(MP4_DECODE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,MP4_ENCODE)
    endif
  endif
endif

ifeq ($(strip $(MP4_DECODE)),MP4_HW)
  COM_DEFS    += MP4_DECODE
  COM_DEFS    += __MP4_DEC_HW_SUPPORT__
endif

ifeq ($(strip $(MP4_DECODE)),MP4_SW)
  COM_DEFS    += MP4_DECODE
  COM_DEFS    += __MP4_DEC_SW_SUPPORT__
endif

ifeq ($(strip $(MP4_ENCODE)),MP4_HW)
  COM_DEFS    += MP4_ENCODE
  COM_DEFS    += __MP4_ENC_HW_SUPPORT__
endif

ifeq ($(strip $(MP4_ENCODE)),MP4_SW)
  COM_DEFS    += MP4_ENCODE
  COM_DEFS    += __MP4_ENC_SW_SUPPORT__
endif

ifeq ($(strip $(H264_DECODE)),H264_SW)
  ifneq ($(strip $(MP4_DECODE)),MP4_SW)
    $(call DEP_ERR_SETA_OR_ONB,H264_DECODE,non H264_SW,MP4_DECODE)
  else
    COM_DEFS    += __H264_DEC_SW_SUPPORT__
  endif
endif

ifeq ($(strip $(H264_DECODE)),H264_HW)
  ifneq ($(strip $(MP4_DECODE)),MP4_HW)
    $(call DEP_ERR_SETA_OR_ONB,H264_DECODE,non H264_SW,MP4_DECODE)
  else
    COM_DEFS    += __H264_DEC_HW_SUPPORT__
  endif
endif

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  COM_DEFS += __GIS_INTERNAL__
endif

ifdef DCD_SUPPORT
  ifneq ($(strip $(DCD_SUPPORT)), NONE)
    ifeq ($(strip $(WAP_SUPPORT)), NONE)
      $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,DCD_SUPPORT)
    endif
    COM_DEFS    += __DCD_SUPPORT__
  endif
  ifeq ($(strip $(DCD_SUPPORT)),INFRAWARE)    
    DCD_LIB_TARGET   = vendor\dcd\v1_official\Thumb\BrowserApplication.a\
                       vendor\dcd\v1_official\Thumb\EFCInterface.a\
                       vendor\dcd\v1_official\Thumb\NetworkComponent.a\
                       vendor\dcd\v1_official\Thumb\PALComponent.a\
                       vendor\dcd\v1_official\Thumb\StorageComponent.a\
                       vendor\dcd\v1_official\Thumb\XMLParsingComponent.a\
                       vendor\dcd\v1_official\Thumb\DCDAgentComponent.a
    DCD_LIB_WIN32 = vendor\dcd\v1_official\Win32\BrowserApplication.lib\
                    vendor\dcd\v1_official\Win32\EFCInterface.lib\
                    vendor\dcd\v1_official\Win32\NetworkComponent.lib\
                    vendor\dcd\v1_official\Win32\PALComponent.lib\
                    vendor\dcd\v1_official\Win32\StorageComponent.lib\
                    vendor\dcd\v1_official\Win32\XMLParsingComponent.lib\
                    vendor\dcd\v1_official\Win32\DCDAgentComponent.lib
    COMPOBJS    += $(DCD_LIB_TARGET)
    COM_DEFS    += DCD_$(strip $(DCD_SUPPORT))
    COMPLIST += dcd
    CUS_REL_OBJ_LIST += $(DCD_LIB_TARGET)
    CUS_REL_OBJ_LIST += $(DCD_LIB_WIN32)
    CUS_REL_BASE_COMP   +=  vendor\dcd
  endif
endif

ifeq ($(strip $(FM_RADIO_CHIP)),AR1000)
  ifneq ($(strip $(FM_RADIO_HW_SEARCH)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FM_RADIO_CHIP,non AR1000,FM_RADIO_HW_SEARCH)
  else
    COM_DEFS  += FM_RADIO_HW_SEARCH
  endif
endif

ifdef RFC2507_SUPPORT
  ifeq ($(strip $(RFC2507_SUPPORT)),TRUE)
     COMPLIST          += rfc2507
     COMP_TRACE_DEFS   += uas\l2\rfc2507\include\rfc2507_lib_trc.h
     CUSTOM_COMMINC    += uas\l2\rfc2507\include
     COM_DEFS          += __RFC2507_SUPPORT__
     CUS_REL_MTK_COMP += rfc2507
  endif   
endif

ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  ifeq ($(strip $(USB_SUPPORT)),TRUE)
    ifneq ($(filter __EDGE_MODEM_CARD__,$(COM_DEFS)),)
      COM_DEFS += __USB_MODEM_CARD_SUPPORT__
    endif
  endif
  ifneq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
    $(call DEP_ERR_SETA_OR_OFFB,RSAT_SUPPORT,MODEM_WITH_RSAT,EMPTY_MMI)
  endif
endif

CAMCORDER_SUPPORT_PLATFORM = MT6238 MT6239 MT6268 MT6268A MT6268 
ifdef CAMCORDER_SUPPORT
  ifneq ($(strip $(CAMCORDER_SUPPORT)),NONE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support CAMCORDER_SUPPORT)
    endif
    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,CAMCORDER_SUPPORT)
    endif
    ifndef MP4_ENCODE
      $(call DEP_ERR_ONA_OR_OFFB,MP4_ENCODE,CAMCORDER_SUPPORT)
    endif
    ifeq ($(strip $(MP4_ENCODE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,MP4_ENCODE,CAMCORDER_SUPPORT)
    endif
    ifndef MP4_DECODE
      $(call DEP_ERR_ONA_OR_OFFB,MP4_DNCODE,CAMCORDER_SUPPORT)
    endif
    ifeq ($(strip $(MP4_DECODE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,CAMCORDER_SUPPORT)
    else
      COM_DEFS += __CAMCORDER_SUPPORT__
      COM_DEFS += __CAMCORDER_PACKAGE_$(strip $(CAMCORDER_SUPPORT))__
    endif
  else
    ifneq ($(filter $(strip $(PLATFORM)) ,$(CAMCORDER_SUPPORT_PLATFORM)),)
      ifdef ISP_SUPPORT
        ifeq ($(strip $(ISP_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,CAMCORDER_SUPPORT,ISP_SUPPORT)
        endif
      endif
    endif
  endif
endif

ifdef AUD_RECORD
  ifneq ($(strip $(AUD_RECORD)),FALSE)
    COM_DEFS    += AUD_REC_ENABLE
  else
    ifdef DEDI_AMR_REC
      ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AUD_RECORD,DEDI_AMR_REC)
      endif
    endif
    ifdef FM_RADIO_RECORD
      ifeq ($(strip $(FM_RADIO_RECORD)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AUD_RECORD,FM_RADIO_RECORD)
      endif
    endif
  endif
else
    COM_DEFS    += AUD_REC_ENABLE
endif

ifeq ($(strip $(CBM_ALWAYS_ASK_SUPPORT)),TRUE)
    COM_DEFS    +=  __CBM_ALWAYS_ASK__
endif

ifeq ($(strip $(CBM_CONNECTION_MANAGER_SUPPORT)),TRUE)
    COM_DEFS    +=  __CBM_CONNECTION_MANAGER__ 
    ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        COM_DEFS    +=  __TCM_EXT_CALL_HISTORY_SUPPORT__
    endif
endif

ifeq ($(strip $(CBM_BEARER_FALLBACK_SUPPORT)),TRUE)
  COM_DEFS    +=  __CBM_BEARER_FALLBACK__
endif

ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
        $(call DEP_ERR_SETA_OR_OFFB,NAND_FLASH_BOOTING,non ONDEMAND,MULTIPLE_BINARY_FILES)
    endif
    COM_DEFS    +=  __MULTIPLE_BINARY_FILES__
endif

ifeq ($(strip $(BT_PBAP_PROFILE)),TRUE)  
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,BT_PBAP_PROFILE)
  endif
  ifeq ($(strip $(BT_AUDIO_VIA_SCO)),TRUE)
    $(call DEP_ERR_OFFA_OR_OFFB,BT_PBAP_PROFILE,BT_AUDIO_VIA_SCO)
  endif
    COM_DEFS    +=  __BT_PBAP_PROFILE__
endif

ifneq ($(strip $(CHE_INPUT_FROM_FSAL)),FALSE)
  COM_DEFS    +=  __CHE_INPUT_FROM_FSAL__
endif

ifdef AGPS_SUPPORT
  ifneq ($(strip $(AGPS_SUPPORT)), NONE)
    ifeq ($(strip $(GPS_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,GPS_SUPPORT,AGPS_SUPPORT)
    endif
    ifeq ($(strip $(OMA_ULP_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,OMA_ULP_SUPPORT,AGPS_SUPPORT)
    endif
    ifeq ($(strip $(SSL_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,AGPS_SUPPORT)
    endif
    ifeq ($(strip $(SOCKET_SSL_SUPPORT)), FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,SOCKET_SSL_SUPPORT,AGPS_SUPPORT)
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
        COMMINCDIRS     += ps\supl\include
        COMMINCDIRS     += ps\rrlp\include
        COM_DEFS += __AGPS_SUPPORT__ __SUPL_SUPPORT__ __RRLP_SUPPORT__ __AGPS_USER_PLANE__ __NBR_CELL_INFO__
        COMPLIST        += supl rrlp
        COMP_TRACE_DEFS += ps\supl\include\supl_trc.h
        COMP_TRACE_DEFS += ps\rrlp\include\rrlp_trc.h
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
        COMMINCDIRS     += ps\rrlp\include
        COM_DEFS += __AGPS_SUPPORT__ __RRLP_SUPPORT__ __AGPS_CONTROL_PLANE__
        COMPLIST        += rrlp
        COMP_TRACE_DEFS += ps\rrlp\include\rrlp_trc.h
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
        COMMINCDIRS     += ps\supl\include
        COMMINCDIRS     += ps\rrlp\include
        COM_DEFS += __AGPS_SUPPORT__ __SUPL_SUPPORT__ __RRLP_SUPPORT__ __AGPS_USER_PLANE__ __AGPS_CONTROL_PLANE__ __NBR_CELL_INFO__
        COMPLIST        += supl rrlp
        COMP_TRACE_DEFS += ps\supl\include\supl_trc.h
        COMP_TRACE_DEFS += ps\rrlp\include\rrlp_trc.h
    endif
  endif
endif

ifdef OMA_ULP_SUPPORT
    ifeq ($(strip $(OMA_ULP_SUPPORT)), V1)
        COM_DEFS += __ULP_VER_1__
    endif
    ifeq ($(strip $(OMA_ULP_SUPPORT)), V1.5)
        COM_DEFS += __ULP_VER_1__
        COM_DEFS += __ULP_VER_1_5__
    endif
    ifeq ($(strip $(OMA_ULP_SUPPORT)), V2)
        COM_DEFS += __ULP_VER_1__
        COM_DEFS += __ULP_VER_1_5__
        COM_DEFS += __ULP_VER_2__
    endif
endif

ifeq ($(strip $(NDIS_SUPPORT)),TRUE)
  ifneq ($(strip $(CMUX_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,CMUX_SUPPORT,NDIS_SUPPORT)
  endif
  COM_DEFS    += __NDIS_SUPPORT__
endif

ifeq ($(strip $(DISABLE_A5_2)),TRUE)
    COM_DEFS += __DISABLE_A5_2__
endif

ifneq ($(filter MT6223%,$(PLATFORM)),)
   COM_DEFS    += __DRV_SIM_CLK_DUTY_NOT_ENOUGH__
endif

ifeq ($(strip $(CAMCORDER_FACE_DETECTION_MODE_SUPPORT)),TRUE)
  ifneq ($(strip $(AF_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,CAMCORDER_FACE_DETECTION_MODE_SUPPORT)
  endif
  ifneq ($(strip $(SENSOR_TYPE)),RAW)
    $(call DEP_ERR_SETA_OR_OFFB,SENSOR_TYPE,RAW,CAMCORDER_FACE_DETECTION_MODE_SUPPORT)
  endif
  ifeq ($(strip $(CAMCORDER_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,CAMCORDER_SUPPORT,CAMCORDER_FACE_DETECTION_MODE_SUPPORT)
  endif
  ifneq ($(strip $(ISP_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,CAMCORDER_FACE_DETECTION_MODE_SUPPORT)
  endif
  COM_DEFS += __FACE_DETECTION_SUPPORT__
endif

ifeq ($(strip $(UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)),TRUE)
  ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_SUPPORT,UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)
  endif
  COM_DEFS		 += __UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT__
endif

ifeq ($(strip $(MSG_SMS_EMAIL_SUPPORT)),TRUE)
  ifneq ($(strip $(OPTR_SPEC)),ORANGE_0605_CAM240)
    $(error MSG_SMS_EMAIL_SUPPORT is not supported on NON-ORANGE project yet)
  endif
  ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_SUPPORT,MSG_SMS_EMAIL_SUPPORT)
  endif
  ifneq ($(strip $(UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)),TRUE)   
    $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT,MSG_SMS_EMAIL_SUPPORT)
  endif
  ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
    $(call DEP_ERR_SETA_OR_OFFB,UNIFIED_MESSAGE_ADVANCE_FEATURE,non $(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE)),MSG_SMS_EMAIL_SUPPORT)
  endif
  COM_DEFS  += __MSG_SMS_EMAIL_SUPPORT__
endif

ifdef WAV_CODEC
    ifeq ($(strip $(WAV_CODEC)),TRUE)
        COM_DEFS    += WAV_CODEC
    else
        ifeq ($(strip $(AIFF_DECODE)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,WAV_CODEC,AIFF_DECODE)
        endif
        ifeq ($(strip $(AU_DECODE)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,WAV_CODEC,AU_DECODE)
        endif
    endif
endif

ifdef AMR_CODEC
    ifeq ($(strip $(AMR_CODEC)),TRUE)
        COM_DEFS    += AMR_CODEC
    else
        ifeq ($(strip $(DEDI_AMR_REC)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,DEDI_AMR_REC)
        endif
        ifeq ($(strip $(AMRWB_ENCODE)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,AMRWB_ENCODE)
        endif
        ifeq ($(strip $(AMRWB_DECODE)),TRUE)   
            $(call DEP_ERR_ONA_OR_OFFB,AMR_CODEC,AMRWB_DECODE)
        endif
    endif
endif

ifdef CCBS_SUPPORT
  ifeq ($(strip $(CCBS_SUPPORT)),TRUE)
     COM_DEFS    += __CCBS_SUPPORT__
  endif
endif

ifdef CNAP_SUPPORT
  ifeq ($(strip $(CNAP_SUPPORT)),TRUE)
     COM_DEFS    += __CNAP_SUPPORT__
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
  ifdef L1_GPRS
    ifeq ($(strip $(L1_GPRS)),TRUE)
      $(error GSM project does not support L1_GPRS. Please turn off L1_GPRS)
    endif
  endif
  ifdef L1_EGPRS
    ifeq ($(strip $(L1_EGPRS)),TRUE)
      $(error GSM project does not support L1_EGPRS. Please turn off L1_EGPRS)
    endif
  endif
  ifdef L1_EPSK_TX
    ifeq ($(strip $(L1_EPSK_TX)),TRUE)
      $(error GSM project does not support L1_EPSK_TX. Please turn off L1_EPSK_TX)
    endif
  endif
endif

ifeq ($(strip $(TST_LOGACC_SUPPORT)),TRUE)
   ifneq ($(strip $(TST_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_LOGACC_SUPPORT)
   else
      COM_DEFS    += __LOGACC_ENABLE__
   endif
endif

ifdef SWITCHABLE_FEATURE_2ND
  ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
    ifndef SWITCHABLE_FEATURE
      $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
    else
      ifeq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
      endif
    endif
  endif
endif

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    ifeq ($(strip $(CCBS_SUPPORT)),TRUE)
        $(error Please turn off CCBS_SUPPORT in NEPTUNE project!) 
    endif
    ifeq ($(strip $(CNAP_SUPPORT)),TRUE)
        $(error Please turn off CNAP_SUPPORT in NEPTUNE project!) 
    endif
endif

ifdef MODEM_3G_LOGGING
   ifeq ($(strip $(MODEM_3G_LOGGING)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,MODEM_3G_LOGGING)
     endif
      COM_DEFS    += __MODEM_3G_LOGGING__
      COM_DEFS    += __USB_LOGGING__
   endif
endif

ifdef EXT_MODEM_SUPPORT
  ifeq ($(strip $(EXT_MODEM_SUPPORT)), TRUE)
    ifndef TCPIP_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,EXT_MODEM_SUPPORT)
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPOR,EXT_MODEM_SUPPORT)
    endif
    COMPLIST          += ext_modem
    COMP_TRACE_DEFS   += ps\ext_modem\include\ext_modem_trc.h
    CUSTOM_COMMINC    += ps\ext_modem\include
    COM_DEFS += __EXT_MODEM__
  endif
endif

ifdef MMS_SUPPORT
  ifneq ($(strip $(MMS_SUPPORT)),NONE)
    ifeq ($(strip $(WAP_SUPPORT)),NONE)     
      $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,MMS_SUPPORT)
    endif
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V01)     
      ifneq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)     
        $(call DEP_ERR_SETA_OR_SETB,MMS_SUPPORT,non OBIGO_Q03C_MMS_V01,WAP_SUPPORT,OBIGO_Q03C)
      endif
      ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)     
        $(call DEP_ERR_SETA_OR_OFFB,MMS_SUPPORT,OBIGO_Q03C_MMS_V02,UNIFIED_MESSAGE_SUPPORT)
      endif
      COM_DEFS    += MMS_SUPPORT OBIGO_Q03C_MMS_V01
    endif
    ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V02)
      ifeq ($(strip $(WAP_SUPPORT)),NONE)     
        $(call DEP_ERR_SETA_OR_ONB,MMS_SUPPORT,non OBIGO_Q03C_MMS_V02,WAP_SUPPORT)
      endif
      COM_DEFS    += MMS_SUPPORT OBIGO_Q03C_MMS_V02
      COMP_TRACE_DEFS += vendor\mms\obigo_q03c\adaptation\integration\include\mms_trc.h
      COMPLIST    += obigo03cmmsadp obigo03cmmslib mmsapp
    endif     
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    ifeq ($(strip $(call Upper,$(SUPPORT_JSR_205))),TRUE)
      ifeq ($(filter MMS_SUPPORT,$(COM_DEFS)),)
        $(error MMS_SUPPORT must be added to COM_DEFS when SUPPORT_JSR_205 is TRUE)
      endif
    endif
  endif
endif

ifdef BACKGROUND_SMS_SUPPORT
  ifeq ($(strip $(BACKGROUND_SMS_SUPPORT)),TRUE)
      ifneq ($(filter __EMS_NON_STD_7BIT_CHAR__,$(COM_DEFS)),)
        $(error Please turn off BACKGROUND_SMS_SUPPORT when __EMS_NON_STD_7BIT_CHAR__ is defined! )
      endif
  endif
endif
    
ifdef LQT_SUPPORT
  ifeq ($(strip $(LQT_SUPPORT)),TRUE)
    COM_DEFS += LQT_SUPPORT
    COMPLIST += lqt
    COMMINCDIRS += lqt\include
  endif
endif

ifndef SMS_PHONE_ENTRY
     $(error Please define SMS_PHONE_ENTRY in project makefile.)
endif

ifndef SMS_TOTAL_ENTRY
     $(error Please define SMS_TOTAL_ENTRY in project makefile.)
endif

ifdef SMS_PHONE_ENTRY
     COM_DEFS    += SMS_PHONE_ENTRY=$(strip $(SMS_PHONE_ENTRY))
endif

ifdef SMS_TOTAL_ENTRY
     COM_DEFS    += SMS_TOTAL_ENTRY=$(strip $(SMS_TOTAL_ENTRY))
endif

ifdef SECURE_PORT_SUPPORT
  ifeq ($(strip $(SECURE_PORT_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_RO_ENABLE,SECURE_PORT_SUPPORT)
    else
      COM_DEFS    += __SECURE_PORT_SUPPORT__
    endif
  endif
endif

ifdef BIP_SCWS_SUPPORT
  ifeq ($(strip $(BIP_SCWS_SUPPORT)),TRUE)
    ifneq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)
      $(call DEP_ERR_SETA_OR_OFFB,WAP_SUPPORT,OBIGO_Q03C,BIP_SCWS_SUPPORT)
    endif
    ifndef TCPIP_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,BIP_SCWS_SUPPORT)
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,BIP_SCWS_SUPPORT)
    endif
    ifeq ($(filter __SAT__,$(COM_DEFS)),)
        $(error __SAT__ must be defined when BIP_SCWS_SUPPORT is turned on.) 
    endif   
    COM_DEFS    += __SATCE__
  endif
endif

ifdef IPSEC_SUPPORT
  ifneq ($(strip $(IPSEC_SUPPORT)),FALSE)
    ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
      $(call DEP_ERR_SETA_OR_OFFB,TCPIP_SUPPORT,UDP_TCP,IPSEC_SUPPORT)
    endif
    COM_DEFS    += __IPSEC__
    COMP_TRACE_DEFS += security\ike\include\ike_trc.h
    COMMINCDIRS     +=  interface\security
    COMPLIST    += ipsec netkey ike
  endif
endif

ifdef FONT_ENGINE
  ifneq ($(strip $(FONT_ENGINE)),NONE)
    VECTORFONT_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6223 MT6223P MT6226 MT6227 MT6226M MT6226D
    ifneq ($(filter $(strip $(PLATFORM)),$(VECTORFONT_NOT_SUPPORT_PLATFORM)),)
       $(error Vector font (FONT_ENGINE) is not supported for PLATFORM $(strip $(PLATFORM)))
    endif
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),240X320 320X240 240X400 320X480),)
      $(error FONT_ENGINE only supports 240X320, 320X240, 240X400 and 320X480 MAIN_LCD_SIZE)
    endif
     COM_DEFS += FONT_ENGINE_SUPPORT __MMI_VECTOR_FONT_SUPPORT__
     COM_DEFS += $(strip $(FONT_ENGINE))
  endif
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
      ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE)
        $(error For customer project, please set FONT_ENGINE = FONT_ENGINE_MONOTYPE_DEMO, not set FONT_ENGINE = FONT_ENGINE_MONOTYPE)
      endif
      ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE)
        $(error For customer project, please set FONT_ENGINE = FONT_ENGINE_FREETYPE_DEMO, not set FONT_ENGINE = FONT_ENGINE_FREETYPE)
      endif
      ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_WTLE)
        $(error For customer project, please set FONT_ENGINE = FONT_ENGINE_MONOTYPE_DEMO because there is no wtle demo resource)
      endif
    endif
  endif
endif

ifdef FONT_ENGINE
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE)
    COMPLIST    += vectorfont_monotype
    CUS_REL_SRC_COMP += vectorfont_monotype
    COMPOBJS    += vendor\vectorfont\monotype\official\engine_v1\monotype_engine.a
    CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_v1\monotype_engine.a 
    CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_v1\monotype_engine.lib
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_MONOTYPE_DEMO)
    COMPLIST    += vectorfont_monotype
    CUS_REL_SRC_COMP += vectorfont_monotype
    COMPOBJS  	+= vendor\vectorfont\monotype\demo\engine_v1\monotype_engine.a
    CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\demo\engine_v1\monotype_engine.a 
    CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\demo\engine_v1\monotype_engine.lib
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE)
    COMPLIST    += vectorfont_freetype
    CUS_REL_SRC_COMP += vectorfont_freetype
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_FREETYPE_DEMO)
    COMPLIST    += vectorfont_freetype
    CUS_REL_SRC_COMP += vectorfont_freetype
    CUS_REL_BASE_COMP += plutommi\Customer\Fonts\Android \
                         plutommi\Customer\Fonts\MTK \
                         plutommi\Customer\Fonts\Arphic_demo \
                         vendor\vectorfont\freetype
  endif
  ifeq ($(strip $(FONT_ENGINE)),FONT_ENGINE_WTLE)
    COMPLIST    += vectorfont_wtle
    CUS_REL_SRC_COMP += vectorfont_wtle
    COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\itype_engine.a
    COMPOBJS    += vendor\vectorfont\monotype\official\engine_wtle\wtle_engine.a
    CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\itype_engine.a 
    CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\itype_engine.lib
    CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\wtle_engine.a 
    CUS_REL_OBJ_LIST  	+= vendor\vectorfont\monotype\official\engine_wtle\wtle_engine.lib
  endif
endif

ifdef CMMB_SUPPORT
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SQLITE3_SUPPORT,CMMB_SUPPORT)
    endif
    ifneq ($(strip $(DRA_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DRA_DECODE,CMMB_SUPPORT)
    endif
    COM_DEFS += __CMMB_SUPPORT__
    CUS_REL_OBJ_LIST +=  vendor\tdmb\cyberlink\lib\pc\LibCodecInterface.lib \
                         vendor\tdmb\cyberlink\lib\pc\SDL.lib
  endif
  ifneq ($(strip $(CMMB_SUPPORT)),NONE)
    COMPLIST += cmmb
    COM_DEFS += __$(strip $(CMMB_SUPPORT))__
    COMMINCDIRS += custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Adaption\inc \
                   custom\drv\CMMB_Demod\$(strip $(CMMB_SUPPORT))\Demod\inc
  endif
endif

ifdef SQLITE3_SUPPORT
    ifeq ($(strip $(SQLITE3_SUPPORT)),TRUE)
       COMPLIST    += applib_sqlite3
       COM_DEFS    += __SQLITE3_SUPPORT__
       COMP_TRACE_DEFS += applib\sqlite3\inc\sqlite3_trc.h
       CUS_REL_BASE_COMP += applib\sqlite3\inc
    endif
endif

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    COM_DEFS += __SAT_LOWCOST_UI_DISABLE__ __SAT_LOWCOST_NW_DISABLE__
endif

ifndef VENDOR
  VENDOR = NONE
endif

ifdef PRODUCTION_RELEASE
  ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
    ifeq ($(strip $(VENDOR)),NONE)
      ifneq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,DEMO_PROJECT)
        endif
      endif
      ifneq ($(strip $(EMPTY_RESOURCE)),FALSE)
        ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_OFFB,PRODUCTION_RELEASE,EMPTY_RESOURCE)
        endif
      endif
      ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
        ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,MTK_SUBSIDIARY)
        endif
      endif
      ifeq ($(strip $(DEMO_PROJECT)),TRUE)
        ifneq ($(filter __MOD_SMU__,$(COM_DEFS)),)
          ifneq ($(filter __MOD_SMS__,$(COM_DEFS)),)
            COM_DEFS    += __SMS_DEPERSONALIZATION__
          endif
        endif
      endif
    else
      ifeq ($(strip $(DEMO_PROJECT)),TRUE)
        ifneq ($(strip $(EMPTY_RESOURCE)),TRUE)
          $(error PLEASE turn on EMPTY_RESOURCE for vendor projects)
        endif
      endif
    endif
  else
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,DEMO_PROJECT,PRODUCTION_RELEASE)
    endif
  endif
endif

ifneq ($(filter __SMS_DEPERSONALIZATION__,$(COM_DEFS)),)
  ifeq ($(filter __MOD_SMU__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMU__,__SMS_DEPERSONALIZATION__)
  endif
  ifeq ($(filter __MOD_SMS__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMS__,__SMS_DEPERSONALIZATION__)
  endif
endif

ifneq ($(strip $(DEMO_PROJECT)),TRUE)
    ifeq ($(strip $(FRM_BKWD_COMP_SUPPORT)),TRUE)
        COM_DEFS += __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
    endif
endif

ifdef GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO)), TRUE)
    COM_DEFS += __GPRS_DIALUP_ESCAPE_ATO_SUPPORT__
  endif
endif

ifneq ($(filter GSM,$(call Upper,$(PROJECT))),)
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO)), TRUE)
    $(error PLEASE turn off GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO in $(PROJECT) project)
  endif
endif

ifdef GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND 
  ifeq ($(strip $(GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND)), TRUE)
    COM_DEFS += __PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND__
  endif
endif

ifneq ($(filter GSM,$(call Upper,$(PROJECT))),)
  ifeq ($(strip $(GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND)), TRUE)
    $(error PLEASE turn off GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND in $(PROJECT) project)
  endif
endif

ifdef MULTIPLE_PPP_DIALUP_SUPPORT
  ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
       $(error MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),3),T)
       $(error MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than 3)
     endif
     ifeq ($(call lt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),2),T)
       $(error MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be less than 2)
     endif
     COM_DEFS          += __MULTIPLE_PPP_DIALUP_SUPPORT__
     COM_DEFS          += __MAX_NUM_OF_PPP_DIALUP_SUPPORT__=$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT))
  endif
endif

ifneq ($(filter __REL5__,$(COM_DEFS)),)
    COM_DEFS  +=  __REMOVE_FA__ 
endif

ifdef BCR_SUPPORT
  ifneq ($(strip $(BCR_SUPPORT)),NONE)

    ifneq ($(strip $(ISP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,BCR_SUPPORT)
    endif
  
    BCR_SUPPORT_PLATFORM = MT6238 MT6239 
    ifeq ($(filter $(strip $(PLATFORM)) ,$(BCR_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support BCR_SUPPORT)
    endif

    BCR_SUPPORT_MAIN_LCD_SIZE = 176X220 240X320 320X240 240X400 320X480 
    ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(BCR_SUPPORT_MAIN_LCD_SIZE)),)
      $(error BCR_SUPPORT do not support MAIN_LCD_SIZE = $(MAIN_LCD_SIZE) !)
    endif

    COMPOBJS += vendor\bcr\$(strip $(BCR_SUPPORT))\lib\arm\ChinOcr.a
    COMPOBJS += vendor\bcr\$(strip $(BCR_SUPPORT))\lib\arm\OcrEngine.a
    COMPOBJS += vendor\bcr\$(strip $(BCR_SUPPORT))\lib\arm\RTKCtl.a
    CUS_REL_OBJ_LIST += vendor\bcr\$(strip $(BCR_SUPPORT))\lib\arm\ChinOcr.a
    CUS_REL_OBJ_LIST += vendor\bcr\$(strip $(BCR_SUPPORT))\lib\arm\OcrEngine.a
    CUS_REL_OBJ_LIST += vendor\bcr\$(strip $(BCR_SUPPORT))\lib\arm\RTKCtl.a
    CUS_REL_OBJ_LIST += vendor\bcr\$(strip $(BCR_SUPPORT))\inc\MTKOcrSDK.H
    COMMINCDIRS += vendor\bcr\$(strip $(BCR_SUPPORT))\inc
    COM_DEFS += BCR_SUPPORT_$(strip $(BCR_SUPPORT))
    COM_DEFS += BCR_SUPPORT
        
  endif
endif

MEDIA_PLAYER_VER_MAIN_LCD_SIZE = 176X220 240X320 240X400 320X480 
ifdef MEDIA_PLAYER_VER
  ifeq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED_DB)
    ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,MEDIA_PLAYER_VER,non INTEGRATED_DB,SQLITE3_SUPPORT)
    endif
    ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(MEDIA_PLAYER_VER_MAIN_LCD_SIZE)),)
      $(error MAIN_LCD_SIZE = $(MAIN_LCD_SIZE) is not supported when MEDIA_PLAYER_VER = INTEGRATED_DB!)
    endif
    COM_DEFS += __INTEGRATED_PLAYER_DB__
  endif 
  ifeq ($(strip $(MEDIA_PLAYER_VER)),INTEGRATED)
    ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(MEDIA_PLAYER_VER_MAIN_LCD_SIZE)),)
      $(error MAIN_LCD_SIZE = $(MAIN_LCD_SIZE) is not supported when MEDIA_PLAYER_VER = INTEGRATED!)
    endif
    COM_DEFS += __INTEGRATED_PLAYER__
  endif       
endif

ifdef DRM_SUPPORT
    ifneq ($(strip $(DRM_SUPPORT)),NONE)  
        ifdef DRM_SUPPORT_SCAN_DISK
            ifeq ($(strip $(DRM_SUPPORT_SCAN_DISK)),TRUE)
                COM_DEFS += __DRM_SUPPORT_SCAN_DISK__
            endif
        endif        
        ifdef DRM_SUPPORT_DB_SIZE
            ifeq ($(strip $(DRM_SUPPORT_DB_SIZE)),NONE)
                COM_DEFS   += MAX_DRM_DB_SIZE=(0)
            endif
            ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),NONE)
                ifeq ($(strip $(DRM_SUPPORT_DB_SIZE)),DEFAULT)
                    ifeq ($(strip $(DRM_SUPPORT)),BSCI)
                        COM_DEFS   += MAX_DRM_DB_SIZE=(64)
                    else
                        COM_DEFS   += MAX_DRM_DB_SIZE=(1024)
                    endif
                else  
                    ifeq ($(strip $(DRM_SUPPORT)),BSCI)
                        ifeq ($(call gt, $(strip $(DRM_SUPPORT_DB_SIZE)),64), T)
                            $(error DRM_SUPPORT_DB_SIZE value is incorrect!)
                        endif
                        COM_DEFS   += MAX_DRM_DB_SIZE=(64)
                    else
                        ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),256)
                            ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),512)
                                ifneq ($(strip $(DRM_SUPPORT_DB_SIZE)),1024)
                                    $(error DRM_SUPPORT_DB_SIZE value is incorrect!)
                                endif 
                            endif
                        endif   
                        COM_DEFS   += MAX_DRM_DB_SIZE=($(strip $(DRM_SUPPORT_DB_SIZE)))
                    endif    
                endif
            endif
        endif
    endif
endif

ifdef BACKGROUND_CALL_SUPPORT
    ifeq ($(strip $(BACKGROUND_CALL_SUPPORT)),TRUE)
      ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
        $(error BACKGROUND_CALL_SUPPORT can not be TRUE when MMI_BASE is NEPTUNE_MMI)
      endif 
      COM_DEFS    +=  __BACKGROUND_CALL_SUPPORT__
    endif
endif

ifneq ($(filter __EDGE_MODEM_CARD__,$(COM_DEFS)),)
    COM_DEFS += __DISABLE_MODEM_AUTO_POWER_OFF__
    COM_DEFS += __DISABLE_MODEM_AUTO_STARTUP__
endif

ifdef MULTIPLE_NDIS_SUPPORT
  ifeq ($(strip $(MULTIPLE_NDIS_SUPPORT)),TRUE)
     ifneq ($(strip $(NDIS_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,NDIS_SUPPORT,MULTIPLE_NDIS_SUPPORT)
     endif
     ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
       $(call DEP_ERR_OFFA_OR_OFFB,MULTIPLE_NDIS_SUPPORT,MULTIPLE_PPP_DIALUP_SUPPORT)
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
       $(error MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),3),T)
       $(error MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than 3)
     endif
     ifeq ($(call lt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),2),T)
       $(error MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be less than 2)
     endif
     COM_DEFS          += __MULTIPLE_NDIS_SUPPORT__
     COM_DEFS          += __MAX_NUM_OF_NDIS_SUPPORT__=$(strip $(MAX_NUM_OF_NDIS_SUPPORT))
  endif
endif

ifeq ($(strip $(AF_AUXI_LED_SUPPORT)),TRUE)
    ifneq ($(strip $(AF_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,AF_SUPPORT,AF_AUXI_LED_SUPPORT)
    endif
    COM_DEFS += __AF_AUXI_LED_SUPPORT__
endif

ifndef NVRAM_NOT_PRESENT
  ifdef NVRAM_PSEUDO_MERGE
    ifeq ($(strip $(NVRAM_PSEUDO_MERGE)),ON)
      ifdef MMI_VERSION
        ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
          $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,non PLUTO_MMI,NVRAM_PSEUDO_MERGE)
        endif
      endif
      COM_DEFS +=  __NVRAM_PSEUDO_MERGE__
    endif
  endif
endif

ifdef UDX_SUPPORT
  ifeq ($(strip $(UDX_SUPPORT)),TRUE)
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,UDX_SUPPORT)
    endif
    COM_DEFS    += __UDX_SUPPORT__
    COMPLIST    += udx
  endif
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  COM_DEFS    += __UCM_SUPPORT__
  COM_DEFS    += __AUTO_CALL_REJECTION__
endif

ifdef DRA_DECODE
  ifeq ($(strip $(DRA_DECODE)),TRUE)
    DRA_DECODE_SUPPORT_PLATFORM = MT6235 MT6235B MT6238 MT6239 MT6268T MT6268H MT6268A MT6268 
    ifeq ($(filter $(strip $(PLATFORM)),$(DRA_DECODE_SUPPORT_PLATFORM)),)
          $(error PLATFORM $(strip $(PLATFORM)) does not support DRA_DECODE.)
    endif
    COM_DEFS    += __DRA_DECODE_SUPPORT__
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      COMPOBJS    += l1audio\obj\ArmDraDecLib.a
      CUS_REL_OBJ_LIST += l1audio\obj\ArmDraDecLib.a
    else
      COMPOBJS    += l1audio\obj\ArmDraDecLib_Trial.a
      CUS_REL_OBJ_LIST += l1audio\obj\ArmDraDecLib_Trial.a
    endif
  endif
endif

ifeq ($(strip $(SMS_R8_NATION_LANGUAGE)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    ifeq ($(strip $(EMS_SUPPORT)),EMS_NONE)
      $(call DEP_ERR_ONA_OR_OFFB,EMS_SUPPORT,EMS_R8_NATION_LANGUAGE)
    endif
    ifndef EMS_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,EMS_SUPPORT,EMS_R8_NATION_LANGUAGE)
    endif
  endif
  COM_DEFS += __SMS_R8_NATION_LANGUAGE__
endif

ifdef UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE
    ifeq ($(strip $(UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE)), TRUE)
        ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)), TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_SUPPORT,UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE)
        endif
        ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
          $(call DEP_ERR_SETA_OR_OFFB,MMS_SUPPORT,OBIGO_Q03C_MMS_V02,UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE)
        endif
        COM_DEFS    += __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    endif
endif

ifeq ($(strip $(AUDIO_BASS_ENHANCEMENT)),TRUE)
  AUDIO_BASS_ENHANCEMENT_SUPPORT_PLATFORM = MT6235 MT6235B MT6238 MT6239 MT6268T MT6268H MT6268 MT6268A MT6268 
  ifeq ($(filter $(strip $(PLATFORM)) ,$(AUDIO_BASS_ENHANCEMENT_SUPPORT_PLATFORM)),)
    $(error PLATFORM $(strip $(PLATFORM)) does not support AUDIO_BASS_ENHANCEMENT.)
  endif
  ifneq ($(filter MED_NOT_PRESENT,$(COM_DEFS)),)
    $(error Please turn off AUDIO_BASS_ENHANCEMENT when MED_NOT_PRESENT is defined)
  endif
  ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
    $(call DEP_ERR_SETA_OR_OFFB,MED_PROFILE,non MED_MODEM,AUDIO_BASS_ENHANCEMENT)
  endif
  COM_DEFS   += AUD_BASS_ENHANCEMENT
  CONDITION_COM_DEFS_BESSOUND_SUPPORT = TRUE
  ifeq ($(strip $(COMPILER)),ADS)
    COMPOBJS   += dp_engine\BesSound\BesBass_arm.a
    CUS_REL_OBJ_LIST += dp_engine\BesSound\BesBass_arm.a
  endif
  ifeq ($(strip $(COMPILER)),RVCT)
    COMPOBJS   += dp_engine\BesSound\BesBass_arm_rvct.a
    CUS_REL_OBJ_LIST += dp_engine\BesSound\BesBass_arm_rvct.a
  endif
endif

ifdef MMS_FEATURES
    ifndef MMS_SUPPORT
        $(error Please define MMS_SUPPORT when MMS_FEATURES is defined!)
    endif
    ifeq ($(strip $(MMS_FEATURES)),NONE)
        ifneq ($(strip $(MMS_SUPPORT)),NONE)
            $(error MMS_FEATURES can NOT be NONE when MMS_SUPPORT != NONE!)
        endif
    endif
    ifneq ($(strip $(MMS_FEATURES)),NONE)
        ifeq ($(strip $(MMS_SUPPORT)),NONE)
            $(error MMS_FEATURES MUST be NONE when MMS_SUPPORT = NONE!)
        endif
        ifeq ($(strip $(MMS_FEATURES)),SLIM)
            ifeq ($(strip $(MMS_SUPPORT)),OBIGO_Q03C_MMS_V01)
                $(error MMS_FEATURES can NOT be SLIM when MMS_SUPPORT = OBIGO_Q03C_MMS_V01!)
            endif
            COM_DEFS += __SLIM_MMS__
        endif
    endif
endif

ifdef SYNCML_DEVICE_SYNC_SUPPORT
    ifeq ($(strip $(SYNCML_DEVICE_SYNC_SUPPORT)),TRUE)
        ifneq ($(strip $(SYNCML_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,SYNCML_SUPPORT,SYNCML_DEVICE_SYNC_SUPPORT)
        endif
        ifndef BLUETOOTH_SUPPORT
            $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_DEVICE_SYNC_SUPPORT)
        endif
        ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_DEVICE_SYNC_SUPPORT)
        endif
        COM_DEFS    += __SYNCML_DEVICE_SYNC__
        COM_DEFS    += __SYNCML_TRANS_BT_SUPPORT__
        COM_DEFS    += __BT_SUPPORT_SYNCML__
        COM_DEFS    += __OBEX_ADAP_SUPPORT__
        ifneq ($(strip $(EMPTY_RESOURCE)),TRUE)
            COM_DEFS    += __SYNCML_DEVICE_SYNC_INTERNAL_TEST__
        endif
    endif
endif

ifdef SYNCML_PC_SYNC_SUPPORT
    ifeq ($(strip $(SYNCML_PC_SYNC_SUPPORT)),TRUE)
        ifneq ($(strip $(SYNCML_SUPPORT)),TRUE)
            $(call DEP_ERR_ONA_OR_OFFB,SYNCML_SUPPORT,SYNCML_PC_SYNC_SUPPORT)
        endif
        ifndef BLUETOOTH_SUPPORT
            $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_PC_SYNC_SUPPORT)
        endif
        ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,SYNCML_PC_SYNC_SUPPORT)
        endif
        COM_DEFS    += __SYNCML_PC_SYNC_SUPPORT__
        COM_DEFS    += __SYNCML_TRANS_BT_SUPPORT__
        COM_DEFS    += __BT_SUPPORT_SYNCML__
        COM_DEFS    += __OBEX_ADAP_SUPPORT__
    endif
endif

ifeq ($(strip $(SYNCML_DEVICE_SYNC_SUPPORT)),TRUE)
    COMPLIST    += obex_stub
else
    ifeq ($(strip $(SYNCML_PC_SYNC_SUPPORT)),TRUE)
        COMPLIST    += obex_stub
    endif
endif

ifdef UCWEB_SUPPORT
  ifeq ($(strip $(UCWEB_SUPPORT)),UCWEB6)
    COM_DEFS += __UCWEB6__
    COMPLIST    += ucwebadp
    COMPOBJS  	+= vendor\ucweb\v1_official\arm\ucweb.lib
    CUS_REL_OBJ_LIST += vendor\ucweb\v1_official\arm\ucweb.lib
    CUS_REL_FILES_LIST += vendor\ucweb\v1_official\win32\ucweb.lib
  endif
endif

ifdef MSHUTTER_SUPPORT
  ifneq ($(strip $(MSHUTTER_SUPPORT)),FALSE)
    ifndef CMOS_SENSOR
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,MSHUTTER_SUPPORT)
    endif
    ifeq ($(strip $(CMOS_SENSOR)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,CMOS_SENSOR,MSHUTTER_SUPPORT)
    endif
    COM_DEFS    +=  MSHUTTER_SUPPORT
  endif
endif

ifdef SMS_R8_TABLE_MECHANISM
   COM_DEFS += __$(strip $(SMS_R8_TABLE_MECHANISM))__
else
   COM_DEFS += __SMS_R8_DEFAULT__
endif

ifeq ($(strip $(PANORAMA_VIEW_SUPPORT)),TRUE)
  ifneq ($(strip $(CAMCORDER_SUPPORT)),FULL)
    $(call DEP_ERR_SETA_OR_OFFB,CAMCORDER_SUPPORT,FULL,PANORAMA_VIEW_SUPPORT)
  endif
  ifneq ($(strip $(ISP_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,ISP_SUPPORT,PANORAMA_VIEW_SUPPORT)
  endif
  COM_DEFS += __PANORAMA_VIEW_SUPPORT__
endif

ifeq ($(strip $(GPS_BEE_SUPPORT)),TRUE)
    ifneq ($(strip $(GPS_SUPPORT)),MT3326)
      $(call DEP_ERR_SETA_OR_OFFB,GPS_SUPPORT,MT3326,GPS_BEE_SUPPORT)
    endif
    COM_DEFS    += __BEE_SUPPORT__ 
    COMPLIST    += bee      
    COMPOBJS    += gps\bee\lib\MTK_BEE.lib
    CUS_REL_OBJ_LIST += gps\bee\lib\MTK_BEE.lib
    CUS_REL_FILES_LIST += gps\bee\lib\MTK_BEE_WIN32.lib
endif

ifdef QQIM_SUPPORT
  # a temp solution for QQ IM switchable in customer side
  ifdef TCPIP_SUPPORT
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        COMPLIST    += qqim
        CUS_REL_OBJ_LIST += vendor\qqim\lib\qq.lib
        ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
          CUS_REL_FILES_LIST += vendor\qqim\modis_lib\qqlib.lib
        endif
      endif
    endif
  endif
  ifeq ($(strip $(QQIM_SUPPORT)),TRUE)
    ifndef TCPIP_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,QQIM_SUPPORT)
    endif
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_SUPPORT,QQIM_SUPPORT)
    endif
    COM_DEFS    += __QQIM_SUPPORT__
    COMPOBJS    += vendor\qqim\lib\qq.lib
    ifneq ($(strip $(VENDOR)),NONE)
      ifneq ($(strip $(VENDOR)),QQIM)
        $(error QQIM_SUPPORT cannot be enabled in vendor release)
      endif
    endif
  endif
endif

ifdef PMU_WITH_EXTERNL_CHARGER
  ifeq ($(strip $(PMU_WITH_EXTERNL_CHARGER)),TRUE)
    ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
      COM_DEFS    +=  __PMU_WITH_EXTERNL_CHARGER__
    endif
  endif
endif

ifeq ($(strip $(CONDITION_COM_DEFS_BESSOUND_SUPPORT)),TRUE)
    COM_DEFS   += BESSOUND_SUPPORT
endif

A8BOX_SUPPORT_PLATFORM = MT6225 MT6226M MT6226 MT6226D MT6227 MT6227D MT6228 MT6229 MT6230 MT6235 MT6235B MT6236 MT6236B MT6238 MT6239 MT6268 MT6268A MT6268T MT6268H MT6253 MT6253T
ifdef A8BOX_SUPPORT
  ifeq ($(strip $(A8BOX_SUPPORT)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(A8BOX_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) not support A8BOX.)
    endif 
    ifneq ($(strip $(BITSTREAM_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BITSTREAM_SUPPORT,A8BOX_SUPPORT)
    endif
    COM_DEFS += __A8BOX_SUPPORT__ __ELFMUSIC_SUPPORT__
    COMPLIST    += a8box
    COMPOBJS    += vendor\streaming\a8box\lib\official\a8box_arm.lib
    CUS_REL_OBJ_LIST += vendor\streaming\a8box\lib\official\a8box_arm.lib
    CUS_REL_FILES_LIST += vendor\streaming\a8box\lib\official\a8box_arm.lib
    CUS_REL_OBJ_LIST += vendor\streaming\a8box\lib\official\a8box_w32.lib
    CUS_REL_FILES_LIST += vendor\streaming\a8box\lib\official\a8box_w32.lib \
                          vendor\streaming\a8box\adaptation\Inc\elf_def.h \
                          vendor\streaming\a8box\adaptation\Inc\elf_features.h \
                          vendor\streaming\a8box\adaptation\Inc\elf_res_def.h
  endif
endif

ifdef CMMB_CAS_FULL_CARD_SUPPORT
    ifeq ($(strip $(CMMB_CAS_FULL_CARD_SUPPORT)),TRUE)
       ifeq ($(strip $(CMMB_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_FULL_CARD_SUPPORT)
       endif
       ifndef CMMB_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_FULL_CARD_SUPPORT)
       endif
       COM_DEFS    += __CMMB_CAS_FULL_CARD_SUPPORT__
       ifeq ($(filter DRV_MSDC_CLK_SEARCH,$(COM_DEFS)),)
         COM_DEFS += DRV_MSDC_CLK_SEARCH
       endif
    endif
endif

ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MASS_STORAGE_SUPPORT )
     endif
     COM_DEFS +=  __USB_MASS_STORAGE_ENABLE__
endif

ifeq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_COM_PORT_SUPPORT)
     endif
     COM_DEFS +=  __USB_COM_PORT_ENABLE__
endif

ifndef MELODY_BUFFER_LEN
ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
     MELODY_BUFFER_LEN = 512
else
    ifeq ($(strip $(MED_PROFILE)),MED_LOW)
         MELODY_BUFFER_LEN = 1300
    else
         MELODY_BUFFER_LEN = 102400
    endif
endif
endif 

ifdef OPTR_SPEC
    ifeq ($(strip $(OPTR_SPEC)), VODAFONE_R12_LIVE)
        MELODY_BUFFER_LEN = 307200
    endif
endif

ifdef MELODY_BUFFER_LEN
     COM_DEFS += MAX_MELODY_BUF_LEN=$(strip $(MELODY_BUFFER_LEN))
endif

ifdef GGLIVE_SUPPORT
  ifeq ($(strip $(GGLIVE_SUPPORT)),TRUE)
    ifneq ($(strip $(BITSTREAM_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BITSTREAM_SUPPORT,GGLIVE_SUPPORT)
    endif
    COM_DEFS += __GGLIVE_SUPPORT__
    COMPLIST    += gglive
    COMPOBJS    += vendor\streaming\gglive\lib\official\gglive.a
    CUS_REL_OBJ_LIST += vendor\streaming\gglive\lib\official\gglive.a
    CUS_REL_FILES_LIST += vendor\streaming\gglive\lib\official\gglive.a
  endif
endif

ifdef USB_HS_SUPPORT
  ifeq ($(strip $(USB_HS_SUPPORT)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_HS_SUPPORT)
     else
       USB_HS_SUPPORT_PLATFORM = MT6238 MT6239 MT6235 MT6235B MT6268A MT6268 MT6268H MT6253T MT6253 MT6516 
       ifeq ($(filter $(strip $(PLATFORM)),$(USB_HS_SUPPORT_PLATFORM)),)
         $(error PLATFORM $(strip $(PLATFORM)) does not support USB HS.)
       else
         COM_DEFS += __USB_HS_ENABLE__
       endif
     endif
   endif
endif

ifdef UNIFIED_MESSAGE_SORT_MESSAGE_LIST
    ifeq ($(strip $(UNIFIED_MESSAGE_SORT_MESSAGE_LIST)), TRUE)
        ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)), TRUE)
            $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_SUPPORT,UNIFIED_MESSAGE_SORT_MESSAGE_LIST)
        endif
        ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
            $(call DEP_ERR_SETA_OR_OFFB,MMS_SUPPORT,OBIGO_Q03C_MMS_V02,UNIFIED_MESSAGE_SORT_MESSAGE_LIST)
        endif
        ifeq ($(findstring LISTOPTION,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
            $(call DEP_ERR_SETA_OR_OFFB,UNIFIED_MESSAGE_ADVANCE_FEATURE,LISTOPTION,UNIFIED_MESSAGE_SORT_MESSAGE_LIST)
        endif
        ifeq ($(strip $(UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT)), TRUE)
            $(call DEP_ERR_OFFA_OR_OFFB,UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT,UNIFIED_MESSAGE_SORT_MESSAGE_LIST)
        endif

        COM_DEFS    += __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__

        ifeq ($(filter __UNIFIED_MESSAGE_LIST_INDEX_DATA__,$(COM_DEFS)),)
            COM_DEFS    += __UNIFIED_MESSAGE_LIST_INDEX_DATA__
        endif
    endif
endif

ifdef SECLIB_SUPPORT
  ifeq ($(strip $(SECLIB_SUPPORT)), BASIC)
      COMP_TRACE_DEFS += security\seclib\include\seclib_trc.h
	endif
	ifeq ($(strip $(SECLIB_SUPPORT)), PKI)
			COMP_TRACE_DEFS += security\seclib\include\seclib_trc.h
      COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_os_adp_trc.h
      COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_crypto_trc.h
      COMP_TRACE_DEFS += security\openssl\adaptation\system\include\ossl_pki_trc.h
      COMP_TRACE_DEFS += security\openssl\adaptation\pki\include\ossl_pki_adp_trc.h
  endif
endif

ifdef SECLIB_SUPPORT
  ifneq ($(strip $(SECLIB_SUPPORT)), NONE)
    ifndef SSL_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,SECLIB_SUPPORT)
    endif
    ifeq ($(strip $(SSL_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,SSL_SUPPORT,SECLIB_SUPPORT)
    endif
  endif 
  ifeq ($(strip $(SECLIB_SUPPORT)), BASIC)
    COMPLIST            += seclib
    COM_DEFS            += __SECLIB_SUPPORT__    
  endif
  ifeq ($(strip $(SECLIB_SUPPORT)), PKI)
    COMPLIST            += seclib ossl_osadp ossl_crypto ossl_pki ossl_pkiadp
    COM_DEFS            += __SECLIB_SUPPORT__    
  endif
endif

ifdef KURO_SUPPORT
  ifneq ($(strip $(KURO_SUPPORT)), NONE)
    ifneq ($(strip $(DAF_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DAF_DECODE,KURO_SUPPORT)
    endif
    ifneq ($(strip $(AAC_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,AAC_DECODE,KURO_SUPPORT)
    endif    
    ifneq ($(strip $(XML_SUPPORT)), TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,KURO_SUPPORT)
    endif
    ifneq ($(strip $(MEDIA_PLAYER_VER)), INTEGRATED)
        $(call DEP_ERR_SETA_OR_OFFB,MEDIA_PLAYER_VER,INTEGRATED,KURO_SUPPORT)
    endif
  endif
  ifeq ($(strip $(KURO_SUPPORT)), MTK_INTERNAL)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
      $(error KURO_SUPPORT=MTK_INTERNAL can be ONLY enabled for internal use)
    endif
    COM_DEFS += KURO_INTERNAL
  endif
  KURO_SUPPORT_OPTION = OFFICIAL MTK_INTERNAL 
  ifneq ($(filter $(strip $(KURO_SUPPORT)) ,$(KURO_SUPPORT_OPTION)),)
     COM_DEFS               += KUR_DECODE AUD_VOCAL_REMOVAL AUD_PITCH_SHIFTING
     COMPLIST               += kuro
     ifeq ($(strip $(KURO_SUPPORT)),OFFICIAL)
         COMPOBJS           += vendor\player\ipeer\lib\libkuro.lib
         COMPOBJS           += vendor\player\ipeer\lib\libkurodep.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\libkuro.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\libkurodep.lib
     else
         COMPOBJS           += vendor\player\ipeer\lib\mtk_internal\libkuro.lib
         COMPOBJS           += vendor\player\ipeer\lib\mtk_internal\libkurodep.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\mtk_internal\libkuro.lib
         CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\mtk_internal\libkurodep.lib
     endif
     CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\MODIS\libkuro.lib
     CUS_REL_OBJ_LIST += vendor\player\ipeer\lib\MODIS\libkurodep.lib
  endif
endif

ifeq ($(strip $(STREAM_REC_SUPPORT)),TRUE)
  ifneq ($(strip $(STREAM_SUPPORT)),TRUE)
     $(call DEP_ERR_ONA_OR_OFFB,STREAM_SUPPORT,STREAM_REC_SUPPORT)
  endif
  COM_DEFS += __STREAM_REC_SUPPORT__
endif

ifdef E_COMPASS_SENSOR_SUPPORT 
  ifneq ($(strip $(E_COMPASS_SENSOR_SUPPORT)),NONE) 
    COM_DEFS    += $(strip $(E_COMPASS_SENSOR_SUPPORT)) 
    COM_DEFS    += __E_COMPASS_SENSOR_SUPPORT__
    COMMINCDIRS += custom\drv\e_compass_sensor\$(strip $(E_COMPASS_SENSOR_SUPPORT))
    COMMINCDIRS += vendor\e_compass_sensor\$(strip $(E_COMPASS_SENSOR_SUPPORT)) 
    COMPLIST += ecompass
  endif 
endif

ifeq ($(strip $(MTP_SUPPORT)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,MTP_SUPPORT)
     endif
     COMPLIST    += mtp
     CUS_REL_SRC_COMP    += mtp
     COM_DEFS +=  __MTP_ENABLE__
     COM_DEFS +=  __USB_IMAGE_CLASS__
endif

ifeq ($(strip $(JOGBALL_SUPPORT)),TRUE)
    COM_DEFS    += JOGBALL_SUPPORT
endif

ifdef IMAGE_VIEWER_VER
  ifneq ($(strip $(IMAGE_VIEWER_VER)),NONE)
    IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE = 240X320 240X400 320X480 
    IMAGE_VIEWER_VER_EX_SUPPORT_PLATFORM = MT6235 MT6235B MT6238 MT6239 MT6268 MT6268A MT6268T MT6268H
    ifeq ($(strip $(IMAGE_VIEWER_VER)),STANDARD)
      COM_DEFS += __IMAGE_VIEWER_STANDARD__
    endif 
    
    ifeq ($(strip $(IMAGE_VIEWER_VER)),EX)
      ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE)),)
        $(error MAIN_LCD_SIZE = $(strip $(MAIN_LCD_SIZE)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
      endif
      ifeq ($(filter $(strip $(call Upper,$(PLATFORM))),$(IMAGE_VIEWER_VER_EX_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
      endif
      ifndef JPG_DECODE
        $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX,JPG_DECODE)
      else
          ifeq ($(strip $(JPG_DECODE)),NONE)
              $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX,JPG_DECODE)
          endif
      endif
      COM_DEFS += __IMAGE_VIEWER_EX__
    endif 
    
    ifeq ($(strip $(IMAGE_VIEWER_VER)),EX_DB)
      ifneq ($(strip $(SQLITE3_SUPPORT)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB,SQLITE3_SUPPORT)
      endif
      ifeq ($(filter $(strip $(call Upper,$(PLATFORM))),$(IMAGE_VIEWER_VER_EX_SUPPORT_PLATFORM)),)
        $(error PLATFORM $(strip $(PLATFORM)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
      endif
      ifeq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(IMAGE_VIEWER_VER_EX_SUPPORT_MAIN_LCD_SIZE)),)
        $(error MAIN_LCD_SIZE = $(strip $(MAIN_LCD_SIZE)) does NOT support IMAGE_VIEWER_VER = $(strip $(IMAGE_VIEWER_VER)))
      else
          ifeq ($(strip $(JPG_DECODE)),NONE)
              $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB,JPG_DECODE)
          endif
      endif
      ifndef JPG_DECODE
        $(call DEP_ERR_SETA_OR_ONB,IMAGE_VIEWER_VER,non EX_DB,JPG_DECODE)
      endif
      COM_DEFS += __IMAGE_VIEWER_EX_DB__
    endif 
   endif 
endif

ifeq ($(strip $(POWERONOFF_BY_POWERKEY)),TRUE)
    COM_DEFS    += __POWERONOFF_BY_POWERKEY__
endif
# Vogins Start
ifdef VRE_SUPPORT
ifneq ($(strip $(VRE_SUPPORT)),NONE)
  VRE_NOT_SUPPORT_PLATFORM = MT6205% MT6217 MT6218% MT6219
  ifneq ($(filter $(strip $(PLATFORM)),$(VRE_NOT_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support VRE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
  endif
    
  ifeq ($(strip $(VRE_MEMORY_SOURCE)),MED)
    COM_DEFS += __VRE_MEDIA_BUF__
  endif
  
  COM_DEFS += __VRE__ VRE_SYS_MEMORY_SIZE=$(strip $(VRE_MEMORY_SIZE))
  
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),176X220)
    COM_DEFS += __VRE_QCIF__
  endif
 
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),240X320)
    COM_DEFS += __VRE_QVGA__
  endif
 
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),240X400)
    COM_DEFS += __VRE_WQVGA__
  endif
 
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),320X240)
    COM_DEFS += __VRE_HQVGA__
  endif
 
  ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),320X480)
    COM_DEFS += __VRE_HVGA__
  endif
  
  ifeq ($(strip $(VRE_DEFAULT_GAME)), TRUE)
    COM_DEFS += __VRE_DEFAULT_GAME__
  endif
  
  VRE_VERSION = VRE_V20 VRE_V21
  ifneq ($(filter $(strip $(VRE_SUPPORT)),$(VRE_VERSION)),)
    ifeq ($(strip $(FINGER_TOUCH_SUPPORT)),FTE)
      $(warning ERROR: VRE_SUPPORT is VRE_V20/VRE_V21 do not support FTE)
      DEPENDENCY_CONFLICT = TRUE
    endif 
    COM_DEFS += __VRE_V2X__
    COMPLIST    += vre
    COMPOBJS    += vendor\vre\lib\vrecore.lib
    CUS_REL_OBJ_LIST += vendor\vre\lib\vrecore.lib
    CUS_REL_FILES_LIST += vendor\vre\lib\vrewin32.lib
    CUS_REL_BASE_COMP += vendor\vre\vxp
    COMMINCDIRS     += vendor\vre\include
  endif
  
  ifeq ($(strip $(VRE_SUPPORT)),VRE_V30)
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,XML_SUPPORT,VRE_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(WBXML_SUPPORT)),TRUE)
       $(call DEP_ERR_ONA_OR_OFFB,WBXML_SUPPORT,VRE_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(strip $(VRE_CIPHER_UA)),TRUE)
        COM_DEFS += __VRE_CIPHER_UA__
        ifneq ($(strip $(VRE_USER_AGENT_COMPANY)),NONE)
            $(warning ERROR: Please set VRE_USER_AGENT_COMPANY as "NONE" when VRE_CIPHER_UA = TRUE)
            DEPENDENCY_CONFLICT = TRUE
        endif
    else
        COM_DEFS += VRE_USER_AGENT_COMPANY=$(strip $(VRE_USER_AGENT_COMPANY))
        COM_DEFS += VRE_USER_AGENT_PROJECT=$(strip $(VRE_USER_AGENT_PROJECT))
    endif

    ifeq ($(strip $(VRE_OVERSEA_VERSION)),TRUE)
        COM_DEFS += __VRE_OVERSEA_VERSION__
    endif
    
    #COM_DEFS += __NBR_CELL_INFO__
    COM_DEFS += __VRE_V30__
    COMPLIST    += vre30
    ifeq ($(strip $(COMPILER)),RVCT)
      COM_DEFS   += __VRE_V30_LOG_ON__
      COMPOBJS    += vendor\vre30\lib\vrecorervct.lib
      CUS_REL_OBJ_LIST += vendor\vre30\lib\vrecorervct.lib
    else
        ifeq ($(strip $(VRE_LOG_ENABLE)),TRUE)
          COM_DEFS   += __VRE_V30_LOG_ON__
      COMPOBJS    += vendor\vre30\lib\vrecore.lib
        else
          COMPOBJS    += vendor\vre30\lib\vrecore_r.lib
        endif
    endif
    COMPOBJS    += vendor\vre30\lib\kuro_core_vre.lib
    CUS_REL_OBJ_LIST += vendor\vre30\lib\kuro_core_vre.lib
    CUS_REL_OBJ_LIST += vendor\vre30\lib\vrecore.lib
    CUS_REL_OBJ_LIST += vendor\vre30\lib\vrecore_r.lib
    CUS_REL_FILES_LIST += vendor\vre30\lib\vrewin32.lib
    CUS_REL_BASE_COMP += vendor\vre30\vxp
    COMMINCDIRS     += vendor\vre30\include
    COM_DEFS += __VRE30_AM__

    ifeq ($(strip $(VRE_MTK_BRANCH)), MTK_08A)
    	COM_DEFS += __VRE_AM_08AB__
    	COM_DEFS += __VRE_RB_08A__
    	COM_DEFS += __VRE_RB_08B__
    	COM_DEFS += __VRE_RB_09A__
    endif 
    ifeq ($(strip $(VRE_MTK_BRANCH)), MTK_08B)
    	COM_DEFS += __VRE_AM_08AB__
    	COM_DEFS += __VRE_RB_08B__
    	COM_DEFS += __VRE_RB_09A__
    endif
    ifeq ($(strip $(VRE_MTK_BRANCH)), MTK_09A)
    	COM_DEFS += __VRE_RB_09A__
    endif

  endif
endif
endif
# Vogins End

ifeq ($(strip $(3SET_F8F9_ENABLE)),TRUE)
  # can ONLY be turned on for 3G projects
  ifneq ($(strip $(L1_WCDMA)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,L1_WCDMA,3SET_F8F9_ENABLE)
  endif

  # NOT support 3G PLATFORMs
  3SET_F8F9_ENABLE_NOT_SUPPORT_3G_PLATFORM = MT6268A
  ifneq ($(filter $(strip $(PLATFORM)),$(strip $(3SET_F8F9_ENABLE_NOT_SUPPORT_3G_PLATFORM))),)
    $(error PLATFORM $(strip $(PLATFORM)) does NOT support 3SET_F8F9_ENABLE)
  endif

  COM_DEFS  += __CP_3SET_F8F9_HW_ENABLE__
endif

ifeq ($(strip $(BITSTREAM_SUPPORT)),TRUE)
   COM_DEFS    += __BITSTREAM_API_SUPPORT__
endif

ifdef GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP)),TRUE)
    COM_DEFS += __PPP_SPEED_UP_IPV4_GPRS_DIALUP__
  endif
endif

ifdef CMMB_CAS_SMD_SUPPORT
    ifeq ($(strip $(CMMB_CAS_SMD_SUPPORT)),TRUE)
       ifeq ($(strip $(CMMB_SUPPORT)),NONE)
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_SMD_SUPPORT)
       endif
       ifndef CMMB_SUPPORT
          $(call DEP_ERR_ONA_OR_OFFB,CMMB_SUPPORT,CMMB_CAS_SMD_SUPPORT)
       endif
       COM_DEFS    += __CMMB_CAS_SMD_SUPPORT__
       # CMMB Nagra KDA lib
       COMPOBJS    += vendor\cmmb\nagra\lib\kda.a
       CUS_REL_OBJ_LIST += vendor\cmmb\nagra\lib\kda.a
       CUS_REL_FILES_LIST += vendor\cmmb\nagra\lib\kda.a
    endif
endif

ifeq ($(strip $(PLATFORM)),MT6516)
   COM_DEFS += __CPI_SUPPORT__
endif

ifdef MP4_DECODE_MODE
    ifneq ($(strip $(MP4_DECODE_MODE)),NONE)
        ifndef MP4_DECODE
            $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,MP4_DECODE_MODE)
        endif
        ifeq ($(strip $(MP4_DECODE)),NONE)
            $(call DEP_ERR_ONA_OR_OFFB,MP4_DECODE,MP4_DECODE_MODE)
        endif
    endif
    ifeq ($(strip $(MP4_DECODE_MODE)),SLIM)
        MP4_DECODE_MODE_SLIM_SUPPORT_PLATFORM = MT6253T MT6253 
        ifeq ($(filter $(strip $(PLATFORM)),$(MP4_DECODE_MODE_SLIM_SUPPORT_PLATFORM)),)
            $(error PLATFORM $(strip $(PLATFORM)) does not support MP4_DECODE_MODE=$(strip $(MP4_DECODE_MODE)))
        endif  
        COM_DEFS         += __MP4_DEC_SW_SLIM__
    endif
endif

ifeq ($(strip $(FLAVOR)),NON_DEBUG)
    LNKOPT = -remove -map
endif

ifdef SW_VIDEO_RESIZER
ifneq ($(strip $(SW_VIDEO_RESIZER)),NONE)
  ifeq ($(strip $(SW_VIDEO_RESIZER)),IP)
    SW_VIDEO_RESIZER_IP_SUPPORT_PLATFORM = MT6235 MT6235B 
    ifeq ($(filter $(strip $(PLATFORM)),$(SW_VIDEO_RESIZER_IP_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support SW_VIDEO_RESIZER=$(strip $(SW_VIDEO_RESIZER)))
    else
      ifneq ($(strip $(MP4_DECODE)),MP4_SW)
        $(call DEP_ERR_SETA_OR_SETB,MP4_DECODE,MP4_SW,SW_VIDEO_RESIZER,non IP)
      endif
    endif
    COM_DEFS    += __SW_VIDEO_IP_RESIZER_SUPPORT__
  endif
  ifeq ($(strip $(SW_VIDEO_RESIZER)),DD)
    SW_VIDEO_RESIZER_DD_SUPPORT_PLATFORM = MT6225 MT6235 MT6235B 
    ifeq ($(filter $(strip $(PLATFORM)),$(SW_VIDEO_RESIZER_DD_SUPPORT_PLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support SW_VIDEO_RESIZER=$(strip $(SW_VIDEO_RESIZER)))
    else
      ifneq ($(strip $(MP4_DECODE)),MP4_SW)
        $(call DEP_ERR_SETA_OR_SETB,MP4_DECODE,MP4_SW,SW_VIDEO_RESIZER,non DD)
      endif
    endif    
  endif
endif
endif

ifeq ($(strip $(VENUS_MMI)),VENUS_LEVEL1)
    ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,PLUTO_MMI,VENUS_MMI)
    endif
    COM_DEFS         += __VENUS_UI_ENGINE__ __FANCY_PLUTO_APP_ON_VENUS_UI__
    COMPLIST         += venusmmi
    CUS_REL_SRC_COMP += venusmmi
    COMP_TRACE_DEFS  += venusmmi\pluto_adapter\interface\trc\vadp_sys_trc.h
    COMP_TRACE_DEFS  += venusmmi\pluto_adapter\interface\trc\vadp_app_trc.h
endif

ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    COMPLIST         += vrt vrt16
    CUS_REL_MTK_COMP += vrt vrt16
    CUS_REL_BASE_COMP += venusmmi\app \
                         venusmmi\framework \
                         venusmmi\pluto_adapter \
                         venusmmi\service \
                         venusmmi\test \
                         venusmmi\visual \
                         venusmmi\vrt\interface
endif

ifdef APP_SECONDARY_PDP_SUPPORT
  ifeq ($(strip $(APP_SECONDARY_PDP_SUPPORT)),TRUE)
     COM_DEFS    += __APP_SECONDARY_PDP_SUPPORT__
  endif   
endif

ifeq ($(strip $(WAP_MEM_DEBUG)),TRUE)
    COM_DEFS    +=   WAP_MEM_DEBUG
endif

ifneq ($(strip $(GEMINI)),TRUE)
    COM_DEFS += __HO_IMPROVE__
endif


# For basic project, MAUI_01717707
ifeq ($(strip $(FLASH_TEST_SELECT)),NAND_FLASH)
  ifneq ($(strip $(NAND_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FLASH_TEST_SELECT,non NAND_FLASH,NAND_SUPPORT)
  endif
    COM_DEFS    += __NAND_FLASH_HARDWARE_TEST__
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NOR_FLASH)
    COM_DEFS    += __NOR_FLASH_HARDWARE_TEST__
endif


ifdef FOTA_UPDATE_PACKAGE_ON_NAND
  ifeq ($(strip $(FOTA_UPDATE_PACKAGE_ON_NAND)),TRUE)
    ifeq ($(strip $(FOTA_ENABLE)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,FOTA_ENABLE,FOTA_UPDATE_PACKAGE_ON_NAND)
    endif
    COM_DEFS += __UP_PKG_ON_NAND__
  endif
endif

ifdef WIFI_ENHANCE_SUPPORT
	ifneq ($(strip $(WIFI_ENHANCE_SUPPORT)),FALSE)
	  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
	    $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,WIFI_WIZARD_SUPPORT)
	  endif
	  COM_DEFS    += __WIFI_ENHANCE_SUPPORT__
	endif
endif

# end of COM_DEFS

# EMI latency setting, MPLLDISABLED, MPLLXHALF, MPLLX1, MPLLX2, MPLLX3, MPLLX4
MPLL_SETTING_FOR_MT6205_EXT_13M_MCU_13M   = MPLLDISABLED
MPLL_SETTING_FOR_MT6205B_EXT_13M_MCU_13M  = MPLLDISABLED
MPLL_SETTING_FOR_MT6205B_EXT_26M_MCU_13M  = MPLLXHALF
MPLL_SETTING_FOR_MT6205B_EXT_26M_MCU_26M  = MPLLDISABLED
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_13M   = MPLLX1
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_26M   = MPLLX2
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_39M   = MPLLX3
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_52M   = MPLLX4
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_13M   = MPLLX1
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_26M   = MPLLX2
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_39M   = MPLLX3
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_52M   = MPLLX4
MPLL_SETTING_FOR_MT6218_EXT_26M_MCU_26M   = MPLLX1
MPLL_SETTING_FOR_MT6218_EXT_26M_MCU_52M   = MPLLX2
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6218B_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6218B_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6219_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6219_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6217_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6217_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268T_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268T_EXT_26M_MCU_122_88M = MPLLX4

MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268H_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268H_EXT_26M_MCU_122_88M = MPLLX4

MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268A_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_122_88M = MPLLX4
MPLL_SETTING_FOR_MT6268A_EXT_26M_MCU_245_76M = MPLLX4

MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6268_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_122_88M = MPLLX4
MPLL_SETTING_FOR_MT6268_EXT_26M_MCU_245_76M = MPLLX4

MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6239_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6239_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6235_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6235_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6235B_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6235B_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226M_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226M_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226D_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226D_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6227_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6227_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6227D_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6227D_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253T_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253T_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253T_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253T_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6253_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6253_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6253_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6253_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_TK6516_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_TK6516_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_TK6516_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_TK6516_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6516_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6516_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6516_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6516_EXT_26M_MCU_104M  = MPLLX4


MPLL_SETTING_FOR =  MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK))
ifdef $(MPLL_SETTING_FOR)
   MPLL_SETTING      =  $(MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK)))
#   $(error [$(MPLL_SETTING)])
else
  ifeq ($(strip $(PLATFORM)),MT6208)
    $(error MCU Clock and External Clock setting cannot be supported.)
  endif
endif


COM_DEFS    += $(MCU_CLOCK) $(EXT_CLOCK) $(MPLL_SETTING)

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
   COM_DEFS    += DCM_ENABLE
endif

ifdef HAND_WRITING
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
      ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
        $(error For customer project, please set HAND_WRITING = MMI_HANWANG_DEMO, not set HAND_WRITING = MMI_HANWANG)
      endif
      ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
        $(error For customer project, please set HAND_WRITING = MMI_PENPOWER_DEMO, not set HAND_WRITING = MMI_PENPOWER)
      endif
      ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA)
        $(error For customer project, please set HAND_WRITING = MMI_DECUMA_DEMO, not set HAND_WRITING = MMI_DECUMA)
      endif
    endif
  endif
  ifneq ($(strip $(HAND_WRITING)),NONE)
    ifndef TOUCH_PANEL_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,HAND_WRITING)
    endif
    ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,TOUCH_PANEL_SUPPORT,HAND_WRITING)
    endif
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
    COM_DEFS    += __MMI_HANWANG__
    COMPLIST    += hanwang
    COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw.a
    COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.a
    COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\thaihw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\HWRE_MTL_OEM.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\thaihw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\thaihw.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.dll
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hws.lib
    CUSTOM_COMMINC  +=	vendor\handwriting\hanwang\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG_DEMO)
    COM_DEFS    += __MMI_HANWANG__ __MMI_HANWANG_DEMO__
    COMPLIST    += hanwang
    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.a
    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.a
    COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\arabichw.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\HWRE_MTL_OEM.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\thaihw.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.dll
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hws.lib
    CUSTOM_COMMINC  +=	vendor\handwriting\hanwang\v1_demo\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
    COM_DEFS    += __MMI_PENPOWER__
    COMPLIST    += penpower
    COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\Thumb_MediaTek_HWRE.a
    COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhase_thumb.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\Thumb_MediaTek_HWRE.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhase_thumb.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MediaTek_HWRE.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhrase_WIN.lib
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_data_big5gb2312_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_big5tw_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_gb2312_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_russian_vc6.h
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_edit_thai_vc6.h
    CUSTOM_COMMINC  +=	vendor\handwriting\penpower\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA)
    COM_DEFS    += __MMI_DECUMA__
    COMPLIST    += decuma
    CUS_REL_SRC_COMP += decuma
    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib.a
    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib.a
    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_MODIS.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_MODIS.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltpredict_MODIS.lib
    CUSTOM_COMMINC  +=	vendor\handwriting\Zi_decuma\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA_DEMO)
    CUS_REL_BASE_COMP += vendor\handwriting\Zi_decuma\adaptation
  endif
  ifdef TOUCH_PANEL_SUPPORT
    ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER_DEMO)
        COM_DEFS    += __MMI_PENPOWER__ __MMI_PENPOWER_DEMO__
        COMPLIST         += penpower
        COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\Thumb_MediaTek_HWRE_demo.a
        CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\Thumb_MediaTek_HWRE_demo.a
        CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\MediaTek_Hwre_demo.lib
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_data_big5gb2312_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_big5tw_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_gb2312_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_russian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_thai_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_portugese_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_italian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_hungarian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_finnish_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_dutch_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_danish_norwegian_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_spanish_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_german_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_french_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_czech_vc6.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_croatian.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_romanian.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_slovak.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_slovene.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_swedish.h
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_edit_bulgarian_vc6.h
        COMMINCDIRS  += vendor\handwriting\penpower\v1_demo\inc
      endif
    endif
  endif
endif

ifdef HAND_WRITING
  ifneq ($(strip $(HAND_WRITING)),NONE)
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
        CUS_REL_BASE_COMP += make\hanwang \
                             make\penpower \
                             make\decuma \
                             vendor\handwriting\hanwang \
                             vendor\handwriting\penpower \
                             vendor\handwriting\zi_decuma
      endif
    endif
  endif
endif

ifneq ($(filter __MMS_STANDALONE_COMPOSER_SUPPORT__,$(COM_DEFS)),)
    COMMINCDIRS  +=  plutommi\MMI\UnifiedComposer\UnifiedComposerInc 
endif

ifndef MCUROM_SUPPORT
  MCUROM_SUPPORT = FALSE
endif


ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
ifeq ($(strip $(PLATFORM)),MT6226)
   ifeq ($(strip $(CHIP_VER)),S02)
      $(error platfrom $(strip $(PLATFORM))Chip version $(strip $(CHIP_VER)) not support MCUROM_SUPPORT.)
   endif

   MAUI_IN_ROM       = TRUE
   COMPLIST         += rompatch romsa
   CUS_REL_MTK_COMP += rompatch romsa
   CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
   CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
   COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
   COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
else
   ifeq ($(strip $(PLATFORM)),MT6227)
      MAUI_IN_ROM       = TRUE
      COMPLIST         += rompatch romsa
      CUS_REL_MTK_COMP += rompatch romsa
      CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
      CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
      COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
      COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
   else
      ifeq ($(strip $(PLATFORM)),MT6227D)
         MAUI_IN_ROM       = TRUE
         COMPLIST         += rompatch romsa
         CUS_REL_MTK_COMP += rompatch romsa
         CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
         CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
         COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
         COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
      else
         ifeq ($(strip $(PLATFORM)),MT6226M)
            MAUI_IN_ROM       = TRUE
            COMPLIST         += rompatch romsa
            CUS_REL_MTK_COMP += rompatch romsa
            CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
            CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
            COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
            COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
         else
            ifeq ($(strip $(PLATFORM)),MT6226D)
               MAUI_IN_ROM       = TRUE
               COMPLIST         += rompatch romsa
               CUS_REL_MTK_COMP += rompatch romsa
               CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
               CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
               COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
               COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
            else
               $(error PLATFORM $(strip $(PLATFORM)) not support MCUROM_SUPPORT.)
            endif
         endif
      endif
   endif
endif
else
   MAUI_IN_ROM       = FALSE
endif
endif
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
    COMPLIST         += xdm
  endif
endif

ifdef SUPPORT_JSR_184
   ifneq ($(strip $(SUPPORT_JSR_184)),FALSE)
      COMPLIST    += m3d m3g
      CUS_REL_MTK_COMP += m3d m3g
   endif
endif

ifdef M3D_MMI_SUPPORT
ifneq ($(strip $(M3D_MMI_SUPPORT)),FALSE)
   ifeq ($(strip $(SUPPORT_JSR_184)),FALSE)
      COMPLIST    += m3d
      CUS_REL_MTK_COMP += m3d
   endif
endif
endif

ifdef DICT_SUPPORT
  ifeq ($(strip $(DICT_SUPPORT)),MMI_GV)
    COM_DEFS    += __MMI_DICT_GV__
    COMPLIST    += dict
    COMPOBJS  	+= vendor\dict\gv\v01_demo\gvlib_targer_rom.lib
    CUS_REL_OBJ_LIST   	+= vendor\dict\gv\v01_demo\gvlib_targer_rom.lib
  endif
  ifeq ($(strip $(DICT_SUPPORT)),MMI_MOTECH)
    COM_DEFS    += __MMI_DICT_MOTECH__
    COMPLIST    += dict
    COMPOBJS  	+= vendor\dict\motech\v01_demo\tccDict.a
    CUS_REL_OBJ_LIST   	+= vendor\dict\motech\v01_demo\tccDict.a
  endif
  ifeq ($(strip $(DICT_SUPPORT)),MMI_TRILOGY)
    COM_DEFS    += __MMI_DICT_TRILOGY__
    COMPLIST    += dict
    COMPOBJS  	+= vendor\dict\trilogy\v01_demo\Dict_core.obj
    COMPOBJS  	+= vendor\dict\trilogy\v01_demo\bg5_uni.obj
    CUS_REL_OBJ_LIST   	+= vendor\dict\trilogy\v01_demo\Dict_core.obj
    CUS_REL_OBJ_LIST   	+= vendor\dict\trilogy\v01_demo\bg5_uni.obj
  endif
  ifneq ($(strip $(DICT_SUPPORT)),NONE)
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      CUS_REL_FILES_LIST += vendor\dict\gv\adaptation\inc\libdh.h \
                            vendor\dict\motech\adaptation\inc\de_api.h \
                            vendor\dict\trilogy\adaptation\inc\dict_core.h  
      CUS_REL_BASE_COMP += vendor\dict\gv\v01_demo \
                           vendor\dict\motech\v01_demo \
                           vendor\dict\trilogy\v01_demo
    endif
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,BLUETOOTH_SUPPORT,MERCURY_SLAVE_BT_SUPPORT)
    endif
  endif
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
    COMPLIST          += btadp btprofiles btstack
  endif
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
    COMPLIST          += btadp btprofiles btstack
  endif   
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612)
    COMPLIST          += btadp btprofiles btstack
  endif  
endif

ifdef SW_FLASH
  ifeq ($(strip $(SW_FLASH)),NEOMTEL)
    COMPOBJS            += vendor\swflash\$(strip $(SW_FLASH))\v1_official\VIS20_ARM12_IRAM_12K_MTK.a
    COMPOBJS            += vendor\swflash\$(strip $(SW_FLASH))\v1_official\zddlib_mtk-ADS.a
    COMMINCDIRS         += vendor\swflash\$(strip $(SW_FLASH))\adaptation\inc
    COM_DEFS         += SWFLASH_$(strip $(SW_FLASH))
    COMPLIST         += swflash
  endif
# always release sw flash libraries to customers except vendors
  ifeq ($(strip $(call Upper,$(VENDOR))),NONE)
    ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\VIS20_ARM12_IRAM_12K_MTK.a
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\VIS20_ARM12_MTK.a
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\VIS20_WIN32_MTK.lib
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\zddlib_mtk-ADS.a
      CUS_REL_OBJ_LIST   	+= vendor\swflash\neomtel\v1_official\zdd2_1_lib.lib
      CUS_REL_BASE_COMP  += vendor\swflash\neomtel\adaptation make\swflash
    endif
  endif
endif



COMPLIST += che image_codec image_codec16 dsp_ram
CUS_REL_MTK_COMP += image_codec image_codec16 dsp_ram
CUS_REL_MTK_COMP += che

#ifeq ($(strip $(PLATFORM)),MT6223P)
#   COMPLIST       +=  drv_sec
#endif

COMPLIST    += drv_display drv_idp drv_graphics drv_sec media_sec32
CUS_REL_SRC_COMP  += drv_display drv_idp drv_graphics 
CUS_REL_MTK_COMP  += drv_sec media_sec32

ifdef L1S_BASIC
  ifeq ($(strip $(L1S_BASIC)),FALSE)
    ifdef SMART_PHONE_CORE
	    ifneq ($(strip $(SMART_PHONE_CORE)),WM_MODEM)
	      CUS_REL_MTK_COMP  += media_sec
  		endif
		else
		  CUS_REL_MTK_COMP  += media_sec
		endif
  endif
endif

ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
     COMPLIST         += sss
     CUS_REL_SRC_COMP += sss
  endif   
endif

ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
     ifeq ($(strip $(COMPILER)),RVCT)
         COMPOBJS         += sss\sss_rvct.lib
         CUS_REL_OBJ_LIST += sss\sss_rvct.lib
     else
         COMPOBJS         += sss\sss.lib
         CUS_REL_OBJ_LIST += sss\sss.lib
     endif
     CUS_REL_FILES_LIST += sss\interface\src\SSS_interface.c
  endif
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
     COMPLIST     += wndrv supc dhcp
  endif   
endif

COMPLIST += camera_armcode
CUS_REL_MTK_COMP += camera_armcode

ifeq ($(strip $(GEMINI_WIFI_COEXIST)),TRUE)
  ifneq ($(strip $(GEMINI)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,GEMINI,GEMINI_WIFI_COEXIST)
  endif
  ifndef WIFI_SUPPORT
    $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,GEMINI_WIFI_COEXIST)
  endif
  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
    $(call DEP_ERR_ONA_OR_OFFB,WIFI_SUPPORT,GEMINI_WIFI_COEXIST)
  endif
endif


# GEMINI list
ifdef GEMINI
  ifeq ($(strip $(GEMINI)),TRUE)
    ifdef WIFI_SUPPORT
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
        ifneq ($(strip $(GEMINI_WIFI_COEXIST)),TRUE)
          $(call DEP_ERR_OFFA_OR_OFFB,GEMINI,WIFI_SUPPORT)
        endif
      endif
    endif
    ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      ifndef DUAL_MODE_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,DUAL_MODE_SUPPORT,GEMINI)
      endif
      ifdef DUAL_MODE_SUPPORT
        ifneq ($(strip $(DUAL_MODE_SUPPORT)),GEMINI)
          $(call DEP_ERR_SETA_OR_OFFB,DUAL_MODE_SUPPORT,GEMINI,GEMINI)
        endif
      endif
    endif
    ifndef SENDKEY_MODE
      $(call DEP_ERR_ONA_OR_OFFB,SENDKEY_MODE,GEMINI)
    endif
    ifndef MERCURY_SLAVE_BT_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,MERCURY_SLAVE_BT_SUPPORT,GEMINI)
    endif
    ifndef SINGLE_SIM_MMI_ONLY
      $(call DEP_ERR_ONA_OR_OFFB,SINGLE_SIM_MMI_ONLY,GEMINI)
    endif
    ifdef CTM_SUPPORT
      ifeq ($(strip $(CTM_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,CTM_SUPPORT,GEMINI)
      endif
    endif
    ifdef BT_SIM_PROFILE
      ifeq ($(strip $(BT_SIM_PROFILE)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,BT_SIM_PROFILE,GEMINI)
      endif 
    endif
    ifdef BACKGROUND_SMS_SUPPORT
      ifeq ($(strip $(BACKGROUND_SMS_SUPPORT)),TRUE)
        $(call DEP_ERR_OFFA_OR_OFFB,BACKGROUND_SMS_SUPPORT,GEMINI)
      endif
    endif
    ifdef UNIFIED_MESSAGE_SUPPORT
      ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
         ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
           $(call DEP_ERR_SETA_OR_OFFB,MMS_SUPPORT,OBIGO_Q03C_MMS_V02,GEMINI & UNIFIED_MESSAGE)
         endif
         ifneq ($(strip $(WAP_SUPPORT)), OBIGO_Q03C)
           $(call DEP_ERR_SETA_OR_OFFB,WAP_SUPPORT,OBIGO_Q03C,GEMINI & UNIFIED_MESSAGE)
         endif
      endif
    endif
    ifdef UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE
        ifeq ($(strip $(UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE)), TRUE)
           $(call DEP_ERR_OFFA_OR_OFFB,UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE,GEMINI)
        endif
    endif   
    ifdef PLATFORM
      ifneq ($(filter MT6223%,$(PLATFORM)),)
        ifneq ($(strip $(PLATFORM)),MT6223P)
          $(call DEP_ERR_SETA_OR_OFFB,PLATFORM,MT6223P,GEMINI)
        endif
      endif
    endif
  # For SIM2 modules.
    ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      COMPLIST      += l1_2 interface_gemini
    else
      COMPLIST      += l1_classb_2 interface_gemini
      L1_TMD_FILES  += SIM2\l1\common\l1i_ps_trace_2.tmd \
                       SIM2\l1\common\l1c2_trace_2.tmd
      L1_TMD_FILES  += SIM2\l1\common\l1c_egprs_trace_2.tmd \
                       SIM2\l1\common\l1i_egprs_trace_2.tmd
                       
    endif

    L1_TMD_FILES  += SIM2\l1\common\L1C_Trace_2.tmd \
                     SIM2\l1\common\L1SC_Trace_2.tmd \
                     SIM2\l1\common\l1i_cs_trace_2.tmd \
                     SIM2\l1\common\L1D_Trace_2.tmd \
                     SIM2\l1\common\L1C_csd_trace_2.tmd \
                     SIM2\l1\common\L1D2_Trace_2.tmd \
                     SIM2\l1\common\l1i_amr_trace_2.tmd \
                     SIM2\l1\common\l1t_amr_trace_2.tmd \
                     SIM2\l1\common\l1D_EDGE_trace_2.tmd \
                     SIM2\l1\common\l1c3_trace_2.tmd \
                     SIM2\l1\common\l1c4_trace_2.tmd

    COMP_TRACE_DEFS += SIM2\l1\common\l1a_trace.h

    COMMINCDIRS    += SIM2\l1\common \
                      SIM2\interface\l1interface

    COM_DEFS += __GEMINI__ __GEMINI_GSM__ __GSM_RAT__ DRV_MULTIPLE_SIM

    ifneq ($(filter MT6223P,$(strip $(PLATFORM))),)
      ifdef TOUCH_PANEL_SUPPORT
        ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
          COM_DEFS     += __DRV_SIM_TP_SHARE_PIN__
        endif
      endif
    endif
  endif
  ifeq ($(strip $(GEMINI)),FALSE)
    ifdef DUAL_MODE_SUPPORT
      ifneq ($(strip $(DUAL_MODE_SUPPORT)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,GEMINI,DUAL_MODE_SUPPORT)
      endif
    endif
    ifdef MERCURY_SLAVE_BT_SUPPORT
      ifneq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),FALSE)
        $(call DEP_ERR_ONA_OR_OFFB,GEMINI,MERCURY_SLAVE_BT_SUPPORT)
      endif
    endif
  endif
endif

ifdef DUAL_MODE_SUPPORT
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),GEMINI)
    ifndef GEMINI
      $(call DEP_ERR_SETA_OR_ONB,DUAL_MODE_SUPPORT,non GEMINI,GEMINI)
    endif
    ifdef GEMINI
      ifneq ($(strip $(GEMINI)),TRUE)
        $(call DEP_ERR_SETA_OR_ONB,DUAL_MODE_SUPPORT,non GEMINI,GEMINI)
      endif
    endif
  endif
endif

ifdef DUAL_MODE_SUPPORT
  ifneq ($(strip $(DUAL_MODE_SUPPORT)),NONE)
    ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      $(error Only PLUTO_MMI supports DUAL_MODE_SUPPORT)
    endif
  endif
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),MASTER)
    COMPLIST		+= mercury_master
    COM_DEFS += __MERCURY_MASTER__
  endif
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),GEMINI)
    COMPLIST    += mercury_master
    COMPLIST    += mercury_gemini
    COM_DEFS += __MERCURY_MASTER__
    COM_DEFS += __MERCURY_GEMINI__
  endif
endif

ifdef SINGLE_SIM_MMI_ONLY
  ifeq ($(strip $(SINGLE_SIM_MMI_ONLY)),TRUE)
    COM_DEFS += __SINGLE_SIM_MMI_ONLY__ 
  endif
endif

ifdef SENDKEY_MODE
  ifeq ($(strip $(SENDKEY_MODE)),SENDKEY2_SUPPORT)
    COM_DEFS  += __SENDKEY2_SUPPORT__
  endif
endif

ifdef MERCURY_SLAVE_BT_SUPPORT
  ifdef BLUETOOTH_SUPPORT
    ifeq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),TRUE)
      ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
        COM_DEFS  += __MERCURY_SLAVE_BT_MASTER_SIDE__
      endif
    endif
  endif
endif
# end of GEMINI

#COM_DEFS    += $(CUSTOM_OPTION)
# end of COMPLIST


ifndef MMI_BASE
  MMI_BASE = PLUTO_MMI
  MMIDIR   = plutommi
else
  ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
    MMIDIR         =  lcmmi
  else
    MMIDIR         =  plutommi
  endif
endif

MMI_BASE_PRJ = $(strip $(subst _MMI,,$(MMI_BASE)))

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
  ifeq ($(strip $(call Upper,$(MAIN_LCD_SIZE))),128X128)
    CUS_REL_BASE_COMP += $(strip $(MMIDIR))\Customer\Images\$(strip $(MMI_BASE_PRJ))$(strip $(DISPLAY_TYPE))$(strip $(MAIN_LCD_SIZE))_WITHOUT_ENHANCED
  endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)

INPUT_METHOD_BASE = $(strip $(MMIDIR))
ifeq ($(strip $(DEMO_PROJECT)),FALSE)
  ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
  endif
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
  endif
endif

ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  ifneq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
    INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
  endif
  endif
endif

ifndef OP_CHECK_FORCE_ERROR
OP_CHECK_FORCE_ERROR = 0
  ifdef OPTR_SPEC
    ifneq ($(strip $(OPTR_SPEC)),NONE)
      OP_CHECK_FORCE_ERROR = 1
    endif
  endif
endif

ifdef FONT_RESOURCE
  ifeq ($(strip $(FONT_RESOURCE)),OFFICIAL)
    ifneq ($(strip $(MMIDIR)),lcmmi)
      CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    else
      CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    endif
    CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))

    ifneq ($(strip $(INPUT_METHOD_BASE)),$(strip $(MMI_BASE_PRJ)))
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif
      CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(MMIDIR))
    endif

    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif
      CUS_REL_BASE_COMP += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE)) vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))
    endif
  endif
endif

ifdef FONT_RESOURCE
  ifeq ($(strip $(FONT_RESOURCE)),DEMO)
    ifeq ($(strip $(MMIDIR)),lcmmi)
     $(error DEMO font is only applied in PLUTOMMI project, please set FONT_RESOURCE=OFFICIAL)
    endif
    ifeq ($(filter $(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128 128X160 176X220 240X320 320X240 240X400 320X480),)
      $(error DEMO font only supports 128X128, 128X160, 176X220, 240X320, 320X240, 240X400 and 320X480 MAIN_LCD_SIZE, for other MAIN_LCD_SIZE, please set FONT_RESOURCE=OFFICIAL)
    endif
    ifneq ($(strip $(MMIDIR)),lcmmi)
      CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    else
      CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    endif    
    
    CUS_REL_BASE_COMP += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))

    ifneq ($(strip $(INPUT_METHOD_BASE)),$(strip $(MMI_BASE_PRJ)))
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif
      CUS_REL_BASE_COMP += vendor\font\MTK\demo\project\$(strip $(MMIDIR))
      CUS_REL_BASE_COMP += vendor\font\Dynacom\demo\project\$(strip $(MMIDIR))
      CUS_REL_BASE_COMP += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))
    endif

    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      endif
      CUS_REL_BASE_COMP += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE)) vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))
    endif
  endif
endif

ifdef FONT_RESOURCE
  ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
    CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\MTK\official\project\$(strip $(MMIDIR)) \
                         vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\MTK\demo\project\$(strip $(MMIDIR)) \
                         vendor\font\Dynacom\demo\project\$(strip $(MMIDIR)) \
                         vendor\font\Arphic\demo\project\$(strip $(MMIDIR)) \
                         vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE)) \
                         vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))
  endif
endif

endif
endif
endif

ifdef INPUT_METHOD
  ifneq ($(strip $(INPUT_METHOD)),NONE)
    ifneq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2_DEMO)
      ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
        ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
          $(error Please set INPUT_METHOD to be MMI_CSTAR_V2_DEMO or NONE in customer projects)
        endif
      endif
    endif
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V6)
    CUSTOM_COMMINC  +=	vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\inc
    COMPOBJS  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
    CUS_INPUTMETHOD_BASE = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
    CUSTOM_COMMINC  +=	vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
    COMPOBJS  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
    CUS_INPUTMETHOD_BASE 	= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
    CUSTOM_COMMINC  +=	vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
    COMPOBJS  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
    CUS_INPUTMETHOD_BASE 	= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official
  endif

# CSTAR Official version
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_official
    COMPLIST    += cstar
    COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif

# CSTAR Demo version
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2_DEMO)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_demo
    COMPLIST    += cstar
    COMPOBJS    += $(strip $(CUS_INPUTMETHOD_BASE))\lib\kmxime.a
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif

  ifneq ($(findstring MMI_ZI,$(INPUT_METHOD)),)
    COM_DEFS    += __MMI_ZI__
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_ZI_V7)
      COM_DEFS    += __MMI_ZI_V7__
    endif
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_ZI)
      COM_DEFS    += __MMI_ZI_V7__
    endif
    COMPLIST    += zi
    ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
      CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a /b 2>nul)
    else
      ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
        CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a /b 2>nul)
      else
        CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a /b 2>nul)
      endif
    endif
    ifeq ($(words $(strip $(CUS_ZI))),1)
      ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
      COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
      CUS_REL_OBJ_LIST  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
      else
        ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
          COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
          CUS_REL_OBJ_LIST  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
        else
          COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a
          CUS_REL_OBJ_LIST  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a
        endif
      endif
    endif
  endif
  ifneq ($(findstring MMI_T9,$(INPUT_METHOD)),)
    COM_DEFS    += __MMI_T9__
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_T9_V7)
       ifeq ($(strip $(MMIDIR)),plutommi)
          COM_DEFS    += __MMI_T9_V7__
       endif
    endif
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_T9)
       ifeq ($(strip $(MMIDIR)),plutommi)
          COM_DEFS    += __MMI_T9_V7__
       endif
    endif
    COMPLIST    += t9
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9)
    CUSTOM_COMMINC  +=	vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
    COMPOBJS  	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V7)
    CUSTOM_COMMINC  +=	vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
    COMPOBJS  	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V6)
    $(error INPUT_METHOD MMI_T9_V6 is phased out. Please change INPUT_METHOD value)
  endif
  CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifneq ($(strip $(INPUT_METHOD)),NONE)
      CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_ZI))),2)
        $(error $(strip $(CUS_INPUTMETHOD_BASE)) does NOT exist!)
      endif
    endif
  endif

  ifneq ($(strip $(INPUT_METHOD_BASE)),plutommi)
    ifneq ($(strip $(INPUT_METHOD_BASE)),lcmmi)
      CUS_T9 = $(shell dir vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_T9))),0)
        CUS_REL_BASE_COMP   += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE)) make\t9 vendor\InputMethod\T9\adaptation
      endif
      CUS_ZI = $(shell dir vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_ZI))),0)
        CUS_REL_BASE_COMP   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE)) make\zi vendor\InputMethod\ZI\adaptation
      endif
    endif
  endif

endif

ifdef INPUT_METHOD
  ifneq ($(strip $(INPUT_METHOD)),NONE)
    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      CUS_REL_BASE_COMP += vendor\InputMethod\ZI\project\$(MMIDIR) \
                           vendor\InputMethod\T9\project\$(MMIDIR) \
                           vendor\InputMethod\cstar\v2_official \
                           vendor\InputMethod\cstar\v2_demo
    endif
  endif
  CUS_REL_BASE_COMP += vendor\InputMethod\ZI\adaptation make\zi \
                       vendor\InputMethod\T9\adaptation make\t9 \
                       vendor\InputMethod\cstar\adaptation make\cstar
endif

ifdef GAME_ENGINE
  ifneq ($(strip $(GAME_ENGINE)),NONE)
    COMPLIST    += game_engine
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_BROGENT)
    COMPOBJS    += vendor\game_engine\brogent\engine_v1\arm\mini_bgl.lib \
                   vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\arm\bgt_ggr2_optimize.lib \
                   vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\arm\bgt_hb2_utils.lib
    CUS_REL_OBJ_LIST += vendor\game_engine\brogent\engine_v1\arm\mini_bgl.lib \
                        vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\arm\bgt_ggr2_optimize.lib \
                        vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\arm\bgt_hb2_utils.lib \
                        vendor\game_engine\brogent\engine_v1\pc\mini_bgl.lib \
                        vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\pc\bgt_ggr2_optimize.lib \
                        vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\pc\bgt_hb2_utils.lib
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_INTERGRAFX)
    #COMPOBJS  	+= vendor\game_engine\brogent\engine_v1\arm\ur_engine.lib
  endif
endif

#ifdef JATAAYU_FEATURE
#   ifeq ($(findstring WAP,$(JATAAYU_FEATURE)),WAP) # if $(JATAAYU_FEATURE) is *WAP*
#       COMPLIST    += jataayu jataayuapp jdd
#   endif
#endif

ifdef BARCODE_DECODER
  BARCODE_DECODER_SUPPORT_MAIN_LCD_SIZE = 176X220 240X320 320X240 240X400 320X480
    ifeq ($(strip $(BARCODE_DECODER)),MMI_ONLY)
        COM_DEFS += BARCODE_DECODER_$(strip $(BARCODE_DECODER))
    else
      ifneq ($(strip $(BARCODE_DECODER)),NONE)
        ifneq ($(filter $(strip $(call Upper,$(MAIN_LCD_SIZE))),$(BARCODE_DECODER_SUPPORT_MAIN_LCD_SIZE)),)
          COMPOBJS += vendor\barcode\$(strip $(BARCODE_DECODER))\lib\DecodeLib.lib
          CUS_REL_OBJ_LIST += vendor\barcode\$(strip $(BARCODE_DECODER))\lib\DecodeLib.lib
          COMMINCDIRS += vendor\barcode\$(strip $(BARCODE_DECODER))\inc
          COM_DEFS += BARCODE_DECODER_$(strip $(BARCODE_DECODER))
          COM_DEFS += BARCODE_SUPPORT
        else
          $(error BARCODE_DECODER do not support MAIN_LCD_SIZE = $(strip $(MAIN_LCD_SIZE)))
        endif
      endif
    endif
endif


ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
      CUS_REL_BASE_COMP += custom\drv\Drv_Tool
  endif
endif


ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),MEUT)
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    COMPLIST         +=  media_rtp
endif
endif
endif


ifdef WAP_SUPPORT
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)
    COMPLIST    += obigo03capp obigo03cadp obigo03clib
  endif
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
    COMPLIST    += obigo05aadp obigo05alib wapapp
  endif
endif


ifdef SYNCML_SUPPORT
  ifneq ($(strip $(SYNCML_SUPPORT)),FALSE)
    ifeq ($(strip $(WAP_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,WAP_SUPPORT,SYNCML_SUPPORT)
    endif  
  endif
  ifeq ($(strip $(SYNCML_SUPPORT)),TRUE)
    COM_DEFS    += __SYNCML_SUPPORT__
    COMPLIST    += syncml
  endif
endif

ifdef UNIFIED_MESSAGE_SUPPORT
ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
   ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),FALSE)
      ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
         COMMINCDIRS	+= plutommi\MMI\UnifiedComposer\UnifiedComposerInc
      endif
   endif
endif
endif


ifdef UNIFIED_MESSAGE_SUPPORT
ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
  ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),FALSE)
     ifneq ($(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE)),NONE)
           $(call DEP_ERR_ONA_OR_OFFB,UNIFIED_MESSAGE_SUPPORT,UNIFIED_MESSAGE_ADVANCE_FEATURE)
     endif
  else
     ifneq ($(findstring LISTOPTION,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
#       ifeq ($(strip $(WAP_SUPPORT)),JATAAYU4)
#         $(error Please turn WAP_SUPPORT to NONE or OBIGO_Q03C, or turn UNIFIED_MESSAGE_ADVANCE_FEATURE to NONE or COMPOSER)
#       endif
     endif
     ifneq ($(findstring ARCHIVE,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
#       ifeq ($(strip $(WAP_SUPPORT)),JATAAYU4)
#         $(error Please turn WAP_SUPPORT to NONE or OBIGO_Q03C, or turn UNIFIED_MESSAGE_ADVANCE_FEATURE to NONE or COMPOSER)
#       endif
     endif
     ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
         COM_DEFS    +=  __UNIFIED_COMPOSER_SUPPORT__
     endif
     ifneq ($(findstring LISTOPTION,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
         COM_DEFS    +=  __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
     endif
     ifneq ($(findstring ARCHIVE,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
         COM_DEFS    +=  __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
     endif
  endif

endif
endif


ifdef RTSP_SUPPORT
  ifeq ($(strip $(RTSP_SUPPORT)),TRUE)
    COMPLIST	+= rtsp
    COM_DEFS    += __RTSP__
  endif
endif


SYNC_LCM_SUPPORT_NOT_SUPPORT_FLATFORM = MT6205 MT6217 MT6218 MT6223 MT6223P MT6225 
SYNC_LCM_HW_SUPPORT_PLATFORM = MT6235 MT6235B MT6238 MT6239 MT6268 MT6253T MT6253 MT6516 
SYNC_LCM_SUPPORT_DISABLE_OPTION = FALSE NONE 
ifdef SYNC_LCM_SUPPORT
  ifeq ($(filter $(strip $(SYNC_LCM_SUPPORT)) ,$(SYNC_LCM_SUPPORT_DISABLE_OPTION)),)
    ifneq ($(filter $(strip $(PLATFORM)) ,$(SYNC_LCM_SUPPORT_NOT_SUPPORT_FLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support SYNC_LCM_SUPPORT)
    endif  
    ifneq ($(filter $(strip $(PLATFORM)) ,$(SYNC_LCM_HW_SUPPORT_PLATFORM)),)
      COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_HW_SUPPORT__
    else    
      COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_SW_SUPPORT__
    endif
  endif
endif


ifeq ($(strip $(call Upper,$(PLATFORM))),MT6225)
   ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
      COM_DEFS    +=  MT6225_DMA_EMI_ISSUE
   endif
endif

ifeq ($(strip $(call Upper,$(PLATFORM))),MT6235)
  ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
    $(error CHIP_VER should be larger than S00 for MT6235)
  endif
endif

ifeq ($(strip $(call Upper,$(PLATFORM))),MT6235B)
  ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
    $(error CHIP_VER should be larger than S00 for MT6235B)
  endif
endif

ifdef VDOEDT_SUPPORT
  VDOEDT_SUPPORT_NOT_SUPPORT_FLATFORM = MT6205B MT6208 MT6217 MT6218B MT6219 MT6226 MT6227 MT6227D MT6226D
  ifeq ($(strip $(VDOEDT_SUPPORT)),TRUE)
    ifneq ($(strip $(MP4_DECODE)),MP4_HW)
      $(call DEP_ERR_SETA_OR_OFFB,MP4_DECODE,MP4_HW,VDOEDT_SUPPORT)
    endif
    ifneq ($(strip $(MP4_ENCODE)),MP4_HW)
      $(call DEP_ERR_SETA_OR_OFFB,MP4_ENCODE,MP4_HW,VDOEDT_SUPPORT)
    endif
    ifneq ($(filter $(strip $(PLATFORM)),$(VDOEDT_SUPPORT_NOT_SUPPORT_FLATFORM)),)
      $(error PLATFORM $(strip $(PLATFORM)) does not support VDOEDT_SUPPORT.)
    endif
  endif
  ifeq ($(strip $(VDOEDT_SUPPORT)),TRUE)
     COM_DEFS    += VDOEDT_SUPPORT
     COM_DEFS    += __VIDEO_EDITOR__
  endif
endif

ifneq ($(filter DUAL_LCD,$(COM_DEFS)),)
  ifeq ($(strip $(SUB_LCD_SIZE)),NONE)
    ifneq ($(strip $(PLATFORM)),TK6516)
      ifneq ($(strip $(PLATFORM)),MT6516)
        $(error Please set SUB_LCD_SIZE when DUAL LCD (LCD_MODULE=$(strip $(LCD_MODULE))) is used)
      endif
    endif
  endif
endif

L1CACHEABLE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6268T MT6268H TK6516 MT6225 MT6253T MT6253 
ifneq ($(filter $(strip $(PLATFORM)) ,$(L1CACHEABLE_SUPPORT_PLATFORM)),)
  COM_DEFS += __MTK_L1CACHEABLE__
endif

L2CACHEABLE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6268T MT6268H MT6238 MT6239 
ifneq ($(filter $(strip $(PLATFORM)) ,$(L2CACHEABLE_SUPPORT_PLATFORM)),)
  COM_DEFS += __MTK_L2CACHEABLE__
endif


CUS_REL_BASE_COMP += make\theme_rom

ifeq ($(filter dp_engine,$(COMPLIST)),dp_engine)
  ifeq ($(strip $(call Upper,$(PLATFORM))),MT6205B)
    $(error MT6205B does not support dp_engine)
  endif
endif

####DPENGINE_MODULE_SUPPORT_PLATFORM = MT6218B MT6217 MT6219 MT6223 MT6225 MT6226 MT6227 MT6227D MT6226M MT6228 MT6229 MT6230
ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
  ifneq ($(call Upper,$(strip $(PROJECT))),MEUT)
    ifneq ($(strip $(PLATFORM)), MT6205B)
      CUS_REL_MTK_COMP  += dp_engine
    endif
  endif
endif

# For MoDIS AVLib release.
CUS_REL_FILES_LIST += MoDIS\MoDIS\w32_av_lib.cpp \
                      MoDIS\MoDIS\w32_av_lib.h \
                      Modis\MoDIS\w32_av_types.h \
                      MoDIS\MoDIS\AVLib\Player.h \
                      MoDIS\MoDIS\AVLib\RgbFormat.h \
                      MoDIS\MoDIS\AVLib\VideoSample.h

# For NEPTUNE voice prompt release.
ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
CUS_REL_FILES_LIST += lcmmi\Customer\VoicePrompt\VPres\VP.zip
endif

# For smart phone settings.
ifdef SMART_PHONE_CORE
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    include make\smart_phone_option.mak
  endif
endif

#####
# COMMON SECTION used by gsm2.mak and custom_release.mak
#####

DEFAULT_CUSTOMER = MTK MTK_RF PLUTO
ifneq ($(filter $(call Upper,$(strip $(CUSTOMER))),$(strip $(DEFAULT_CUSTOMER))),)
  VERNOFILE		=  make\Verno.bld

  ifdef FOTA_ENABLE
    ifneq ($(strip $(FOTA_ENABLE)),NONE)
      SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_FOTA.txt
    else
      SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM)).txt
    endif
  else
    SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM)).txt
  endif
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_FOTA.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_L1S.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_BASIC.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_MEUT.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
    VERNOFILE		:=  make\Verno_ClassB.bld
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),UMTS)
    VERNOFILE		:=  make\Verno_ClassB_UMTS.bld
  endif
else
  VERNOFILE		=  make\Verno_$(strip $(CUSTOMER)).bld

  ifdef FOTA_ENABLE
    ifneq ($(strip $(FOTA_ENABLE)),NONE)
      SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_FOTA.txt
    else
      SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER)).txt
    endif
  else
    SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER)).txt
  endif

  ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_L1S.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_BASIC.txt
  endif
  ifeq ($(strip $(call Upper,$(PROJECT))),MEUT)
    SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_MEUT.txt
  endif
endif

BL_SCATTERFILE   = custom\system\$(strip $(BOARD_VER))\scatBL_$(strip $(PLATFORM)).txt
FOTA_SCATTERFILE = custom\system\$(strip $(BOARD_VER))\scatFOTA_$(strip $(PLATFORM)).txt

include $(strip $(VERNOFILE))
SLIM_BRANCH := $(call Upper,$(strip $(BRANCH)))
BRANCH   +=   $(call Upper,$(strip $(CUSTOMER)))

# *************************************************************************
# Include extra dependency check.
# *************************************************************************
-include make\Extra_dep.mak

# *************************************************************************
# Build path, directories
# *************************************************************************
FIXPATH        =  .
TARGNAME       =  $(strip $(CUSTOMER))_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
PLATLIBROOT    =  $(strip $(FIXPATH))\lib\$(strip $(PLATFORM))
TSTDIR         =  $(strip $(FIXPATH))\tst
TST_DB         =  $(strip $(TSTDIR))\database
ifeq ($(call Upper,$(PROJECT)),GPRS)
	TST_DB         :=  $(strip $(TSTDIR))\database_classb
endif
ifeq ($(call Upper,$(PROJECT)),UMTS)
	TST_DB         :=  $(strip $(TSTDIR))\database_classb_umts
endif
BUILDDIR       =  $(strip $(FIXPATH))\build
TARGDIR        =  $(strip $(BUILDDIR))\$(strip $(CUSTOMER))
PROJDIR        =  $(strip $(TARGDIR))\$(PROJECT)
BPLGUINFOCUSTOMPREFIX = BPLGUInfoCustomApp_$(strip $(PLATFORM))_$(strip $(CHIP_VER))

OBJSDIR        =  $(strip $(PROJDIR))\$(strip $(PLATFORM))o
RULESDIR       =  $(strip $(PROJDIR))\$(strip $(PLATFORM))r
COMPLIBDIR     =  $(strip $(OBJSDIR))\lib

HEADER_TEMP    =  header_temp
CUSTPACKDIR    =  $(strip $(FIXPATH))\custpack

NOT_REMOVAL_DIR_FILE = make\NotRemovalCodeDir.def

# Move to project makefile
# Settings for operator
#ifdef MMI_BASE
#  ifeq ($(strip $(MMI_BASE)),PLUTO_MMI)
#    ifneq ($(strip $(OPTR_SPEC)),NONE)
#      OPTR_PATH = operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi
#      -include $(OPTR_PATH)\operator.mak
#    endif
#  endif
#endif

#  Settings for emigen
BB_FOLDER_PATH    = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))
FLASH_OPTIONS_HDR = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\flash_opt.h
CUSTOM_EMI_H      = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI.h
CUSTOM_EMI_C      = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI.c
CUSTOM_FLASH_C    = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_flash.c
CUSTOM_FLASH_NORFDM5_C = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_flash_norfdm5.c
MEMORY_DEVICE_HDR = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_MemoryDevice.h
MEMORY_DEVICE_LST = $(strip $(FIXPATH))\tools\MemoryDeviceList\MemoryDeviceList_Since09AW0920.xls
EMI_GENERATOR     = $(strip $(FIXPATH))\tools\emiGenV6.pl

FLASHFILE = $(strip $(FIXPATH))\~flash_cfg_tmp.c
MEMORY_CFG = $(strip $(CUSTOM_EMI_H))

# Settings for MSC
NETSIM       = $(strip $(FIXPATH))\MoDIS\NetSim\NetSim.exe
MSCWORKSPACE = $(strip $(FIXPATH))\mtk_tools\AutoTest\MSC_TestCase\target.msc
CUSTMENUTREE = $(strip $(FIXPATH))\$(strip $(MMIDIR))\Customer\CustResource\CustMenuTree_Out.c

#ifdef NAND_FLASH_BOOTING
#  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
#    ifneq (,$(filter $(strip $(PLATFORM)), $(strip $(NAND_FLASH_BOOTING_SUPPORT_PLATFORM))))
#      FLASHFILE := $(strip $(MEMORY_DEVICE_HDR))
#      MEMORY_CFG := $(strip $(CUSTOM_EMI_H))
#    endif
#  endif
#endif

# Determine if BOOTLOADER built required

  NEED_BUILD_BOOTLOADER = FALSE

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
else
  ifdef USB_DOWNLOAD
    ifneq ($(strip $(USB_DOWNLOAD)),NONE)
      NEED_BUILD_BOOTLOADER = TRUE
      BOOTLOADER_CHE = ON
    endif
  endif
  ifdef FOTA_ENABLE
    ifeq ($(strip $(FOTA_ENABLE)),FOTA_DM)
      NEED_BUILD_BOOTLOADER = TRUE
      BOOTLOADER_CHE = ON
    endif
  endif  
  
  ifeq ($(strip $(PLATFORM)),MT6235)
    NEED_BUILD_BOOTLOADER = TRUE
    BOOTLOADER_CHE = ON
  endif
  ifeq ($(strip $(PLATFORM)),MT6235B)
    NEED_BUILD_BOOTLOADER = TRUE
    BOOTLOADER_CHE = ON
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    NEED_BUILD_BOOTLOADER = TRUE
    BOOTLOADER_CHE = ON
  endif
  ifeq ($(strip $(PLATFORM)),MT6239)
    NEED_BUILD_BOOTLOADER = TRUE
    BOOTLOADER_CHE = ON
  endif  
endif

ifeq ($(strip $(PLATFORM)),MT6268T)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifeq ($(strip $(PLATFORM)),MT6268H)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifeq ($(strip $(PLATFORM)),MT6268A)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  CUS_REL_SRC_COMP += bootloader
  CUS_REL_BASE_COMP += bootloader make\bootloader
  CUS_REL_FILES_LIST += $(strip $(BL_SCATTERFILE))
endif

ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
include make\REL_CR_VENDOR.mak
endif

#########################################################
# Replace alias modules. (for build flow)
#########################################################
include make\ALIAS.mak
ifdef COMPLIST
COMPLIST_TEMP = $(foreach mod,$(call Upper,$(COMPLIST)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
COMPLIST := $(strip $(COMPLIST_TEMP))
#########################################################
# End of replacing alias modules.
#########################################################

#########################################################
# Replace alias modules. (for custom release flow)
#########################################################
ifdef CUS_REL_SRC_COMP
CUS_REL_SRC_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_SRC_COMP)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_SRC_COMP := $(CUS_REL_SRC_COMP_TEMP)

ifdef CUS_REL_PAR_SRC_COMP
CUS_REL_PAR_SRC_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_PAR_SRC_COMP)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_PAR_SRC_COMP := $(CUS_REL_PAR_SRC_COMP_TEMP)

ifdef CUS_REL_MTK_COMP
CUS_REL_MTK_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_MTK_COMP)), \
  $(if $(filter $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_MTK_COMP := $(CUS_REL_MTK_COMP_TEMP)

#########################################################
# End of replacing alias modules.
#########################################################

CLEANROOM_COMP = j2me_11 j2me_hi sb51 sbpki2 sslplus5 bsci
# consistency check for COMPLIST & CUS_REL_XXX_COMP
# check each comp in $(COMPLIST) if it has been put in $(CUS_REL_XXX_COMP)
COMPLIST_NO_REL_TYPE_COMP = $(filter-out $(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP),$(COMPLIST))
COMPLIST_NO_REL_TYPE_COMP := $(filter-out $(CLEANROOM_COMP),$(COMPLIST_NO_REL_TYPE_COMP))
ifneq ($(words $(COMPLIST_NO_REL_TYPE_COMP)),0)
  $(error $(foreach comp,$(COMPLIST_NO_REL_TYPE_COMP),"$(comp)") in COMPLIST but NOT in CUS_REL_XXX_COMP)
endif

# check each comp in $(CUS_REL_XXX_COMP) if it has been put in $(COMPLIST)
CREL_COMP_NOT_COMPLIST = $(filter-out $(COMPLIST),$(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP))
CREL_COMP_NOT_COMPLIST := $(filter-out bootloader,$(CREL_COMP_NOT_COMPLIST))
CREL_COMP_NOT_COMPLIST := $(filter-out fota,$(CREL_COMP_NOT_COMPLIST))
ifneq ($(words $(CREL_COMP_NOT_COMPLIST)),0)
  $(error $(foreach comp,$(CREL_COMP_NOT_COMPLIST),"$(comp)") in CUS_REL_XXX_COMP but NOT in COMPLIST)
endif

# COMPLIST(during CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  COMPLIST =     $(strip $(CUS_REL_SRC_COMP))
  COMPLIST +=    $(strip $(CUS_REL_PAR_SRC_COMP))
  COMPLIST := $(filter-out bootloader,$(COMPLIST))
  COMPLIST := $(filter-out fota,$(COMPLIST))

  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      COMPLIST :=  	$(filter-out plutommi,$(COMPLIST))
      COMPLIST :=  	$(filter-out mmiresource,$(COMPLIST))
      COMPLIST :=  	$(subst lc ,lcmmiresource ,$(COMPLIST))
      COMPLIST :=  	$(filter-out mtkapp,$(COMPLIST))
      COMPLIST :=  	$(subst lc ,lcmtkapp ,$(COMPLIST))
    else
      ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
        COMPLIST :=  	$(filter-out plutommi,$(COMPLIST))
        COMPLIST :=  	$(filter-out mmiresource,$(COMPLIST))
        COMPLIST :=  	$(subst lc ,lcmmiresource ,$(COMPLIST))
        COMPLIST :=  	$(filter-out mtkapp,$(COMPLIST))
        COMPLIST :=  	$(subst lc ,lcmtkapp ,$(COMPLIST))
      else
        COMPLIST :=  	$(filter-out lcmmi,$(COMPLIST))
        COMPLIST :=  	$(filter-out lcmmiresource,$(COMPLIST))
        COMPLIST :=  	$(filter-out lcmtkapp,$(COMPLIST))
      endif
    endif
  endif
endif

ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
ifdef OPTR_SPEC
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
ifneq ($(strip $(OPTR_SPEC)),NONE)
CUS_REL_BASE_COMP += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\$(strip $(MMIDIR))
CUS_REL_BASE_COMP += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\$(strip $(MMIDIR))
THE_OP_CUSTOM_LIS = $(OPTR_PATH)\op_custom.lis
OPTR_MMI = operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\$(strip $(MMIDIR))
endif
else
CUS_REL_BASE_COMP += operator
THE_OP_CUSTOM_LIS = $(OPTR_PATH)\op_custom.lis
OPTR_MMI = operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\$(strip $(MMIDIR))
endif
endif
endif

