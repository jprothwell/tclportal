/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * nvram_common_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for MTK to config the NVRAM settings.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MAUI_BASIC__
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif


#include "kal_release.h"

#include "nvram_defs.h"
#include "nvram_user_defs.h"
#include "nvram_editor_data_item.h"
#include "nvram_default_audio.h"
#include "custom_hw_default.h"
#include "custom_mmi_default_value.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "drv_features.h" 
#include "camera_para.h"
#include "nvram_lid_statistics.h"
/* add head file for restore factory */
#include "custom_nvram_config.h"
#include "custom_nvram_restore.h"
#ifndef __OPTR_NONE__
#include "op_nvram_common_config.h"
#endif

//#include "adc.h"

#if(defined(ISP_SUPPORT))
#include "camera_tuning_para.h"
#endif

#ifdef __PS_SERVICE__
#include "custom_gprs_pdp_default_qos_config.h"
#endif // ~ #ifdef __PS_SERVICE__
/* Vogins Start */
#ifdef __VRE_V2X__
extern kal_uint8 const NVRAM_VER_PKEY_DEFAULT[];
extern nvram_vm_permission_list_t const NVRAM_VER_SYM_ENTRY_DEFAULT[];
extern nvram_vm_paychannel_t const NVRAM_VER_PAY_CHANNEL_DEFAULT[];
extern nvram_vm_paychannel_t const NVRAM_VER_PAY_CHANNEL_DEFAULT2[];
extern nvram_vm_paychannel_t const NVRAM_VER_PAY_CHANNEL_DEFAULT3[];
extern nvram_vm_paychannel_t const NVRAM_VER_PAY_CHANNEL_DEFAULT4[];
#endif
/* Vogins End */
/* Vogins Start */
#ifdef __VRE_V30__
extern kal_uint8 const  NVRAM_VER_PKEY_EXT_DEFAULT[];
extern kal_uint8 const  NVRAM_VER_SYM_ENTRY_EXT_DEFAULT[];
extern kal_uint8 const  NVRAM_VER_PAY_CHANNEL_EXT_DEFAULT[];
extern kal_uint8 const  NVRAM_VER_PAY_CHANNEL_A_EXT_DEFAULT[];
//extern kal_uint8 const  NVRAM_VER_PAY_CHANNEL_EXT_DEFAULT2[];
//extern kal_uint8 const  NVRAM_VER_PAY_CHANNEL_EXT_DEFAULT3[];
//extern kal_uint8 const  NVRAM_VER_PAY_CHANNEL_EXT_DEFAULT4[];
extern kal_uint8 const  NVRAM_VER_OPERATOR_CODE_EXT_DEFAULT[];
extern kal_uint8 const  NVRAM_VER_OPERATOR_CODE_234_EXT_DEFAULT[];
extern kal_uint8 const  NVRAM_VER_PAY_CONFIG_EXT_DEFAULT[];
extern kal_uint8 const  NVRAM_VER_PAY_CONFIG_EXT_EXT_DEFAULT[];
#endif
/* Vogins End */

/* Defaults */
#ifdef __MOD_SMSAL__
#if (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI))
#ifdef LOW_COST_SUPPORT
static kal_uint8 const NVRAM_SMS_CB_SMS_INFO_DEFAULT[]=
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF
};
#else /* LOW_COST_SUPPORT */
static kal_uint8 const NVRAM_SMS_CB_SMS_INFO_DEFAULT[]=
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};
#endif /* LOW_COST_SUPPORT */
#endif /* (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)) */
#endif /* __MOD_SMSAL__*/

#ifdef __MMI_MESSAGES_CLUB__
static kal_uint8 const NVRAM_MSG_CLUB_DEFAULT [NVRAM_MSG_CLUB_RECORD_SIZE]=
{
	0x41, 0x54, 0x43, 0x4C, 0x00, 0x00, 0x00, 0x00, 
	0x42, 0x54, 0x43, 0x4C, 0x4C, 0x00, 0x00, 0x00  
};

static kal_uint8 const NVRAM_MSG_CLUB_NUM_DEFAULT [NVRAM_MSG_CLUB_NUM_RECORD_SIZE]=
{
	0x31, 0x30, 0x00, 0x00,
	0x30, 0x30, 0x32, 0x00
};
#endif /* __MMI_MESSAGES_CLUB__*/

#ifdef __CMCC_0202_SEGC_TECH__
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_CUSTOMER_SERVICE__*/
#else /*__CMCC_0202_SEGC_TECH__*/
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_CUSTOMER_SERVICE__*/
#endif /*__CMCC_0202_SEGC_TECH__*/


#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#ifdef __IP_NUMBER__
static kal_uint8 const NVRAM_IP_NUMBER_DEFAULT[NVRAM_IP_NUMBER_SIZE]={

	/* first set */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	/* second set */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	/* third set */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
#endif /*__IP_NUMBER__*/
#endif

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
static PROFILE const NVRAM_PROFILES_DEFAULT [MAX_ELEMENTS] =
{
#ifdef CUSTOM_USER_PROFILE_CONTENT_DEFAULT
    CUSTOM_USER_PROFILE_CONTENT_DEFAULT
#else
	{
		LEVEL4, LEVEL2, LEVEL4, MMI_RING, {COLOR_PATTERN1, 1, 15}, 2, REPEAT,{151,152,206,207,208,209,202,201,203,204,205,201,202,203,204,KEYPAD_TONE,153,151,205},
		{1, 0, 1}, THEME_DEFAULT, {0}, {1, 0, 1, 1}
	},
	{
		LEVEL4, LEVEL1, LEVEL4, MMI_VIBRATION_ONLY, {COLOR_PATTERN1, 1, 15}, 3, SINGLE,{151,152,0,0,0,0,0, 0, 0, 0, 0,0,0,0,0,0,153,151,0},
		{1, 0, 1}, THEME_DEFAULT, {0}, {0, 0, 0, 0}
	},
	{
		LEVEL7, LEVEL7, LEVEL4, MMI_VIBRATION_AND_RING, {COLOR_PATTERN1, 1, 15}, 2, REPEAT,{151,152,206,207,208,209,202,201,203,204,205,201,202,203,204,KEYPAD_TONE,153,151,205},
		{1, 0, 1}, THEME_DEFAULT, {0}, {1, 0, 1, 1}
	},
	{
		LEVEL3, LEVEL1, LEVEL4, MMI_RING, {COLOR_PATTERN1, 1, 15}, 2, REPEAT,{151,152,206,207,208,209,202,201,203,204,205,201,202,203,204,KEYPAD_TONE,153,151,205},
		{1, 1, 1}, THEME_DEFAULT, {0}, {1, 0, 1, 1}
	},
	{
		LEVEL4, LEVEL2, LEVEL4, MMI_RING, {COLOR_PATTERN1, 1, 15}, 2, REPEAT,{151,152,206,207,208,209,202,201,203,204,205,201,202,203,204,KEYPAD_TONE,153,151,205},
		{1, 0, 1}, THEME_DEFAULT, {0}, {1, 0, 1, 1}
	},
	{
		LEVEL3, LEVEL1, LEVEL4, MMI_SILENT, {COLOR_PATTERN1, 1, 15}, 2, REPEAT,{151,152,0,0,0,0,0,0,0,0,0,0,0,0,0,0,153,151,0},
		{1, 1, 1}, THEME_DEFAULT, {0}, {0, 0, 0, 0}
	},
	{
		LEVEL3, LEVEL5, LEVEL4, MMI_RING, {COLOR_PATTERN1, 1, 15}, 2, REPEAT,{151,152,206,207,208,209,202,201,203,204,205,201,202,203,204,KEYPAD_TONE,153,151,205},
		{1, 1, 1}, THEME_DEFAULT, {0}, {1, 0, 1, 1}
	}
#endif /*CUSTOM_USER_PROFILE_CONTENT_DEFAULT*/
};
#endif /*!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)*/

#ifdef __MMI_FM_RADIO_SCHEDULER__
static char NVRAM_FMRDO_SCHEDULER_DEFAULT[NVRAM_EF_FMRDO_SCHEDULER_SIZE] = 
{
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
	0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
    0, 0xff
};
#endif /* __MMI_FM_RADIO_SCHEDULER__ */ 

#ifdef __MMI_THEMES_APPLICATION__
#ifdef __MMI_THEMES_V2_SUPPORT__
static kal_uint8 const NVRAM_THEMES_VALUES_DEFAULT [NVRAM_THEMES_VALUES_SIZE] =
{
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00
};
#else /* __MMI_THEMES_V2_SUPPORT__*/
static kal_uint8 const NVRAM_THEMES_VALUES_DEFAULT [NVRAM_THEMES_VALUES_SIZE] =
{
   0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00
};
#endif /* __MMI_THEMES_V2_SUPPORT__*/
#endif /* __MMI_THEMES_APPLICATION__*/

static kal_uint8 const NVRAM_EF_IMEI_IMEISV_DEFAULT[] = 
{
#ifndef __MTK_TARGET__
    0x53, 0x68, 0x88, 0x00, 0x00, 0x00, 0x51, 0x08, /*The IMEI is 15 digit */
    0x87,       /* Software version number */
    0x01        /* Padding */
#else
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, /*The IMEI is 15 digit */
    0x00,       /* Software version number */
    0x00        /* Padding */
#endif
};
/*
static kal_int32 const NVRAM_EF_ADC_DEFAULT[] = { 
#if defined(DRV_ADC_MAX_CH_1)
   5369,
   60428
#elif defined(DRV_ADC_MAX_CH_5)
   5369,  5369, 5369, 5369, 5369,
   60428, 60428, 60428, 60428, 60428
#elif defined(DRV_ADC_MAX_CH_6)
   5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_7)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_8)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_9)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_10)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_11)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_12)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_13)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_14)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_15)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_16)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_17)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_18)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_19)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_20)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#endif // #if defined(DRV_ADC_MAX_CH_5)

};
*/
static kal_uint8 const NVRAM_EF_BARCODE_NUM_DEFAULT[]={
                  'M', 'T', '0', '1', '2', '3', '4', '5', '6', '7',
                  '8', '9', '0', '1', '2', '3', '4', '5', '6', '7',
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00
};

static kal_uint8 const NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT[] = {
                   'M',  'T',  'K',  '1', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#ifdef __DM_MO_SUPPORT__                  
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#else
                   'M',  'T',  'K',  '2', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif  
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                   'M',  'T',  'K',  '4', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                   'M',  'T',  'K',  '5', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                   'M',  'T',  'K',  '6', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                   'M',  'T',  'K',  '7', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                  };

static kal_uint8 const NVRAM_EF_UEM_RMI_DATA_DEFAULT[] = {
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 'e' , 'n' , 0x01, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                  };


static kal_uint8 const NVRAM_EF_SMSAL_SMS_DEFAULT[] = {
                  0xfe,                            /* status */
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
                  0xFF, 0xFF, 0xFF, 0xFF
                  };

#ifdef __PS_SERVICE__
static kal_uint8 const NVRAM_EF_TCM_PDP_PROFILE_DEFAULT[] = {
                  0x00, 0x00, 0x21, 0x01, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  
                  //0x10, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // req qos
                  PS_QOS_PROFILE_DEFAULT_REQ_LENGTH,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_1,
                  PS_QOS_PROFILE_DEFAULT_REQ_DELAY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_RELIABILITY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_PEAK_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_2,
                  PS_QOS_PROFILE_DEFAULT_REQ_PRECEDENCE_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_3,
                  PS_QOS_PROFILE_DEFAULT_REQ_MEAN_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_ORDER,
                  PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_OF_ERR_SDU,
                  PS_QOS_PROFILE_DEFAULT_REQ_MAX_SDU_SIZE,
                  PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_RESIDUAL_BIT_ERROR_RATE,
                  PS_QOS_PROFILE_DEFAULT_REQ_SDU_ERROR_RATIO,
                  PS_QOS_PROFILE_DEFAULT_REQ_TRANSFER_DELAY,
                  PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_HNDL_PRIORITY,
                  PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_4,
                  PS_QOS_PROFILE_DEFAULT_REQ_SIGNALING_INDICATION,
                  PS_QOS_PROFILE_DEFAULT_REQ_SOURCE_STAT_DESCPTOR,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_UP_LINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_UP_LINK,
              
                  //0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // min qos
                  PS_QOS_PROFILE_DEFAULT_MIN_LENGTH,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_1,
                  PS_QOS_PROFILE_DEFAULT_MIN_DELAY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_RELIABILITY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_PEAK_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_2,
                  PS_QOS_PROFILE_DEFAULT_MIN_PRECEDENCE_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_3,
                  PS_QOS_PROFILE_DEFAULT_MIN_MEAN_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_ORDER,
                  PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_OF_ERR_SDU,
                  PS_QOS_PROFILE_DEFAULT_MIN_MAX_SDU_SIZE,
                  PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_RESIDUAL_BIT_ERROR_RATE,
                  PS_QOS_PROFILE_DEFAULT_MIN_SDU_ERROR_RATIO,
                  PS_QOS_PROFILE_DEFAULT_MIN_TRANSFER_DELAY,
                  PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_HNDL_PRIORITY,
                  PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_4,
                  PS_QOS_PROFILE_DEFAULT_MIN_SIGNALING_INDICATION,
                  PS_QOS_PROFILE_DEFAULT_MIN_SOURCE_STAT_DESCPTOR,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_UP_LINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_UP_LINK,

                  0x08, 
                  
                  0x69, 0x6E, 0x74, 0x65, 0x72, 0x6E, 0x65, 0x74, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x02, 0x02, 0x00, 0x00, 0x01, 
                  0xAC, 0x15, 0x78, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 
                  0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0xFF, // 228
                  0x00, 0x00 // N201U value 1520=(0xF0, 0x05) //erica 20070112
};
#endif /* __PS_SERVICE__*/


#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
static kal_uint8 const NVRAM_EF_AUTOTEST_DEFAULT[NVRAM_EF_AUTOTEST_SIZE] = 
{
       /* [count, test0, test1, test2 ....... test229] */
	15,         0,     1,     2,      3,     4,     5,     6,     7,      8,     9,   10,    11,    12,   13,    14, /* 16 */ 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00,0x00,0x00,                                                                                 /* 230 */
	
       /* Entry test time */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
	0x00,0x00,0x00,0x00                                                                                                  /* 250 */
};
#endif

static port_setting_struct const NVRAM_EF_PORT_SETTING_DEFAULT[]=
{
    {
    #if defined(__ONLY_ONE_UART__) || defined(__MMI_DUAL_SIM__)
        99,   /* tst-ps uses uart_null(value is 99 (0x63)) */
        0,   /* APP uses uart_port1 (value is 0) */
    #elif defined (WISDOM_MMI)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
        1,   /* tst-ps uses uart_port2(value is 1) */
        0,   /* APP uses uart_port1 (value is 0) */
    #endif

#if defined(EMPTY_MMI)
        921600, /* tst default baud rate for project without MMI */
#elif defined (WISDOM_MMI)
/* under construction !*/
#else
        115200, /* tst default baud rate base = 115200 = 0x0001C200 */
#endif
    
    #if defined (__PS_SERVICE__)                  
        115200, /* ps default baud rate base = 115200 = 0x0001C200 */
    #else
        57600, /* ps default baud rate base =   57600 = 0x0000E100 */
    #endif                  
    
        0,                           /* High SpeedSIM */
        0,                           /* SWDBG */  
    #if defined(__ONLY_ONE_UART__)
        1,                           /* uart power setting (0x03) */
    #else
        3,
    #endif
    
        99,                          /* CTI uart port: uart_null (value is 0x63 (99) */
        0,                           /* CTI baud rate: auto*/
    
    #if defined(__ONLY_ONE_UART__) || defined(__MMI_DUAL_SIM__)
        99,                          /* tst-l1 uart port, same as tst-ps*/
    #elif defined (WISDOM_MMI)
/* under construction !*/
    #else
        1,                           /* tst-l1 uart port, same as tst-ps*/
    #endif
    
    #if defined (WISDOM_MMI)
/* under construction !*/
    #else
        115200,                      /* tst-l1 baud rate, same as tst-ps, 115200 = 0x0001C200 */
    #endif

        0,                           /* tst output mode*/
#if !defined( __UL1_STANDALONE__ )
        0                            /* USB logging mode */
#else
    #if defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__)
/* under construction !*/
    #else
        1
    #endif /* defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__) */
#endif /*  __UL1_STANDALONE__  */
    },
};



#ifdef JATAAYU_SUPPORT
nvram_wap_profile_content_struct const  NVRAM_EF_WAP_PROFILE_CONTENT_DEFAULT[NVRAM_WAP_PROFILE_MAX]=
{
#ifdef CUSTOM_WAP_PROFILE_CONTENT_DEFAULT
    CUSTOM_WAP_PROFILE_CONTENT_DEFAULT
#else    
  { /* wap profile 1 - FET */
      1,0,80,"http://mobile.fetnet.net",10,1,210,241,199,199,"",""
   },      
   { /* wap profile 2 - CHT */
      1,0,8080,"http://wap.emome.net",11,1,10,1,1,1,"",""
   },      
   { /* wap profile 3 - Taiwan mobile */
      1,0,80,"http://ewap",12,1,10,1,1,1,"",""
   },      
	{ /* wap profile 4 - TransAsia */
      1,0,8080,"http://www.hank.net.tw",13,1,211,78,224,100,"",""
   },      
   { /* wap profile 5 - CHINA MOBILE */
      1,0,80,"http://wap.monternet.com",14,1,10,0,0,172,"",""
   },    
	{ /* wap profile 6 - KGT */
      1,0,9201,"http://mobile1.fetnet.net",10,1,210,241,199,199,"",""
   },      
   { /* wap profile 7 - Mobitai */
      1,0,8080,"http://www.mobeelife.net",15,1,192,168,77,5,"",""
   },         
   { /* wap profile 8 - Empty */
      1,1,0,"http://",10,2,0,0,0,0,"",""
   },      
   { /* wap profile 9 - Empty */
      1,1,0,"http://",10,2,0,0,0,0,"",""
   },         
   { /* wap profile 10 - Empty */
      1,1,0,"http://",10,2,0,0,0,0,"",""
   }
#endif /*CUSTOM_WAP_PROFILE_CONTENT_DEFAULT*/
};


nvram_mms_profile_content_struct const NVRAM_EF_MMS_PROFILE_CONTENT_DEFAULT[NVRAM_MMS_PROFILE_MAX] =
{
#ifdef CUSTOM_MMS_PROFILE_CONTENT_DEFAULT
    CUSTOM_MMS_PROFILE_CONTENT_DEFAULT
#else
  { /* mms profile 1 - FET */
      1,0,9201,"http://mms",10,1,210,241,199,199,"",""
   },      
   { /* mms profile 2 - CHT */
      1,0,8080,"http://mms.emome.net:8002",11,1,10,1,1,1,"",""
   },      
   { /* mms profile 3 - TCC */
      1,0,80,"http://mms",12,1,10,1,1,1,"",""
   },      
   { /* mms profile 4 - TransAsia */	
      1,0,8080,"http://mms",13,1,211,78,224,100,"",""
   },      
   { /* mms profile 5 - CHINA MOBILE */
      1,0,80,"http://mmsc.monternet.com",14,1,10,0,0,172,"",""
   },         
   { /* mms profile 6 - KGT */
      1,0,8080,"http://mms.kgtmms.net.tw/mms/wapenc",16,1,172,28,33,5,"",""
   },      
   { /* mms profile 7 - Mobitai */
      1,0,8080,"http://mms.mobeelife.net/mms/wapenc",15,1,192,168,77,5,"",""
   },         
   { /* mms profile 8 - Empty */
      1,1,0,"http://",10,2,0,0,0,0,"",""
   },      
   { /* mms profile 9 - Empty */
      1,1,0,"http://",10,2,0,0,0,0,"","" 
   },         
   { /* mms profile 10 - Empty */
      1,1,0,"http://",10,2,0,0,0,0,"",""   
   }
#endif /*CUSTOM_MMS_PROFILE_CONTENT_DEFAULT*/
 };

nvram_wap_profile_name_struct const NVRAM_EF_WAP_PROFILE_NAMES_DEFAULT[NVRAM_WAP_PROFILE_MAX]=
{
#ifdef CUSTOM_WAP_PROFILE_NAMES_DEFAULT
    CUSTOM_WAP_PROFILE_NAMES_DEFAULT
#else /*CUSTOM_WAP_PROFILE_NAMES_DEFAULT*/
	{2,0x00,"FET",},
	{2,0x00,"CHT",},
	{2,0x00,"Taiwan Mobile",},
	{2,0x00,"TransAsia",},
	{2,0x00,"China Mobile",},
	{2,0x00,"KGT",},
	{2,0x00,"Mobitai",},
	{2,0x00,"Profile8",},
	{2,0x00,"Profile9",},
	{2,0x00,"Profile10",},
#endif /*CUSTOM_WAP_PROFILE_NAMES_DEFAULT*/
};

nvram_mms_profile_name_struct const NVRAM_EF_MMS_PROFILE_NAMES_DEFAULT[NVRAM_MMS_PROFILE_MAX]=
{
#ifdef CUSTOM_MMS_PROFILE_NAMES_DEFAULT
    CUSTOM_MMS_PROFILE_NAMES_DEFAULT
#else /*CUSTOM_MMS_PROFILE_NAMES_DEFAULT*/	
	{2,0x00,"FET MMS",},
	{2,0x00,"CHT MMS",},
	{2,0x00,"Taiwan Mobile MMS",},
	{2,0x00,"TransAsia MMS",},
	{2,0x00,"China Mobile MMS",},
	{2,0x00,"KGT MMS",},
	{2,0x00,"Mobitai MMS",},
	{2,0x00,"Profile8",},
	{2,0x00,"Profile9",},
	{2,0x00,"Profile10",},
#endif /*CUSTOM_MMS_PROFILE_NAMES_DEFAULT*/	
};

/* Bookmark */
nvram_brw_bkm_title_struct const NVRAM_EF_BRW_BOOKMARK_TITLE_DEFAULT[NVRAM_BRW_MAX_BOOKMARKS]=
{
#ifdef CUSTOM_BRW_BOOKMARK_TITLE_DEFAULT
    CUSTOM_BRW_BOOKMARK_TITLE_DEFAULT
#else /*CUSTOM_BRW_BOOKMARK_TITLE_DEFAULT*/
	{0x00,"YAHOO"},
	{0x00,"OBIGO"},
	{0x00,"GOOGLE"},
	{0x00,"VSWAP2"},
#endif /*CUSTOM_BRW_BOOKMARK_TITLE_DEFAULT*/
};

nvram_brw_bkm_url_struct const NVRAM_EF_BRW_BOOKMARK_URL_DEFAULT[NVRAM_BRW_MAX_BOOKMARKS]=
{
#ifdef CUSTOM_BRW_BOOKMARK_URL_DEFAULT
    CUSTOM_BRW_BOOKMARK_URL_DEFAULT
#else /*CUSTOM_BRW_BOOKMARK_URL_DEFAULT*/
	{"http://wap.yahoo.com"},
	{"http://wap.obigo.com"},
	{"http://www.google.com"},
	{"http://wap1.mtk.com.tw/vswap2"},
#endif /*CUSTOM_BRW_BOOKMARK_URL_DEFAULT*/
};

#endif /* JATAAYU_SUPPORT */

#ifdef __MMI_EBOOK_READER__ 
static kal_uint8 const NVRAM_EF_EBOOK_DEFAULT_VALUE [NVRAM_EF_EBOOK_SETTING_SIZE] =
{
   0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x00,0x01
};
#endif /* __MMI_EBOOK_READER__ */

#ifdef __MMI_ECOMPASS__
static kal_int32 const NVRAM_EF_ECOMPASS_DEFAULT[NVRAM_EF_ECOMPASS_SIZE * NVRAM_EF_ECOMPASS_TOTAL] = 
{
	-2,  /*Ghazni  */
	-3,  /*Herat  */
	-3,  /*Jalalabad  */
	-3,  /*Kabul  */
	-3,  /*Mazar-i-Sharif  */
	-2,  /*Qandahar  */
	-3,  /*Durres  */
	-3,  /*Shkoder  */
	-3,  /*Tirane  */
	-3,  /*Vlore  */
	0,  /*Algiers  */
	-1,  /*Annaba  */
	0,  /*Bejaia  */
	0,  /*Blida  */
	-1,  /*Constantine  */
	1,  /*Oran  */
	-1,  /*Setif  */
	-1,  /*Skikda  */
	1,  /*Tlemcen  */
	7,  /*Benguela  */
	8,  /*Huambo  */
	7,  /*Lobito  */
	5,  /*Luanda  */
	20,  /*Casey  */
	0,  /*South Pole  */
	15,  /*Codrington  */
	15,  /*Saint John  */
	7,  /*Buenos Aires  */
	4,  /*Cordoba  */
	8,  /*La Plata  */
	-1,  /*Mendoza  */
	6,  /*Salta  */
	-8,  /*Adelaide  */
	-11,  /*Brisbane  */
	-12,  /*Canberra  */
	-12,  /*Geelong  */
	-15,  /*Hobart  */
	-12,  /*Melbourne  */
	-12,  /*Newcastle  */
	2,  /*Perth  */
	-13,  /*Sydney  */
	-13,  /*Wollongong  */
	-3,  /*Linz  */
	-3,  /*Vienna  */
	-2,  /*Villach  */
	7,  /*Freeport  */
	7,  /*Nassau  */
	-2,  /*Al Manamah  */
	-2,  /*Muharraq  */
	1,  /*Barisal  */
	1,  /*Chittagong  */
	1,  /*Comilla  */
	1,  /*Dhaka  */
	1,  /*Khulna  */
	15,  /*Bridgetown  */
	15,  /*Oistins  */
	0,  /*Brussels  */
	0,  /*Gent  */
	0,  /*Liege  */
	0,  /*Namur  */
	15,  /*Hamilton  */
	0,  /*Paro  */
	0,  /*Punakha  */
	0,  /*Thimphu  */
	6,  /*La Paz  */
	7,  /*Oruro  */
	7,  /*Potosi  */
	11,  /*Santa Cruz  */
	8,  /*Sucre  */
	-3,  /*Mostar  */
	-3,  /*Sarajevo  */
	-3,  /*Tuzla  */
	21,  /*Brasilia  */
	18,  /*Curitiba  */
	23,  /*Salvador  */
	20,  /*Sao Paulo  */
	0,  /*Bandar Seri Begawan  */
	0,  /*Kuala Belait  */
	-5,  /*Burgas  */
	-4,  /*Pernik  */
	-4,  /*Ruse  */
	-5,  /*Shumen  */
	-4,  /*Sofia  */
	-5,  /*Varna  */
	1,  /*Akyab  */
	1,  /*Bassein  */
	1,  /*Mandalay  */
	1,  /*Rangoon  */
	1,  /*Batdambang  */
	1,  /*Kampong Cham  */
	0,  /*Phnom Penh  */
	2,  /*Bamenda  */
	2,  /*Douala  */
	2,  /*Yaounde  */
	-16,  /*Edmonton  */
	10,  /*Hamilton  */
	15,  /*Montreal  */
	14,  /*Ottawa  */
	17,  /*Quebec  */
	11,  /*Toronto  */
	-18,  /*Vancouver  */
	-4,  /*Winnipeg  */
	-1,  /*Abeche  */
	0,  /*Doba  */
	0,  /*Kelo  */
	0,  /*Koumra  */
	0,  /*Lai  */
	0,  /*Moundou  */
	4,  /*Arica  */
	-6,  /*Chillan  */
	-3,  /*Santiago  */
	7,  /*Beijing  */
	2,  /*Chengdu  */
	10,  /*Haerbin  */
	5,  /*Nanjing  */
	5,  /*Shanghai  */
	9,  /*Shenyang  */
	7,  /*Barranquilla  */
	6,  /*Bogota D.E.  */
	8,  /*Cucuta  */
	5,  /*Ibague  */
	5,  /*Pereira  */
	3,  /*Brazzaville  */
	4,  /*Loubomo  */
	4,  /*Quimpanza  */
	1,  /*Cartago  */
	1,  /*Heredia  */
	0,  /*Limon  */
	-3,  /*Osijek  */
	-3,  /*Rijeka  */
	-3,  /*Split  */
	-3,  /*Zagreb  */
	6,  /*Camaguey  */
	8,  /*Guantanamo  */
	4,  /*Havana  */
	8,  /*Holguin  */
	4,  /*Matanzas  */
	-4,  /*Nicosia  */
	-3,  /*Brno  */
	-4,  /*Ostrava  */
	-2,  /*Plzen  */
	-3,  /*Prague  */
	-2,  /*Copenhagen  */
	11,  /*La Romana  */
	10,  /*Santiago  */
	10,  /*Santo Domingo  */
	-2,  /*Bacau  */
	-2,  /*Dili  */
	2,  /*Ambato  */
	1,  /*Cuenca  */
	1,  /*Esmeraldas  */
	1,  /*Guayaquil  */
	0,  /*Machala  */
	0,  /*Manta  */
	0,  /*Portoviejo  */
	0,  /*Quito  */
	-4,  /*Alexandria  */
	-3,  /*Asyut  */
	-4,  /*Cairo  */
	-4,  /*Damanhour  */
	-4,  /*Giza  */
	-4,  /*Port Said  */
	-4,  /*Suez  */
	-4,  /*Tanta  */
	-4,  /*Zagazig  */
	-2,  /*San Miguel  */
	-2,  /*Santa Ana  */
	-9,  /*Narva  */
	-7,  /*Pamu  */
	-7,  /*Tallinn  */
	-7,  /*Tartu  */
	-2,  /*Addis Ababa  */
	-2,  /*Dessye  */
	-1,  /*Dire Dawa  */
	-2,  /*Gondar  */
	-1,  /*Harar  */
	-2,  /*Jimma  */
	-12,  /*Suva  */
	-7,  /*Espoo  */
	-7,  /*Helsinki  */
	-7,  /*Turku  */
	-7,  /*Vantaa  */
	0,  /*Lyon  */
	0,  /*Marseille  */
	0,  /*Montpellier  */
	-1,  /*Nice  */
	0,  /*Paris  */
	8,  /*Banjul  */
	8,  /*Farafenni  */
	8,  /*Georgetown  */
	8,  /*Gunjur  */
	-6,  /*Sokhumi  */
	-6,  /*Tbilisi  */
	-3,  /*Berlin  */
	-1,  /*Bonn  */
	-1,  /*Frankfurt  */
	-1,  /*Hamburg  */
	4,  /*Accra  */
	4,  /*Kumasi  */
	4,  /*Tema  */
	2,  /*Gibraltar  */
	-4,  /*Athens  */
	-4,  /*Larissa  */
	-4,  /*Patras  */
	-4,  /*Volos  */
	24,  /*Kap Farvel  */
	14,  /*Grenville  */
	-3,  /*Barrios  */
	-3,  /*Guatemala City  */
	16,  /*Georgetown  */
	16,  /*Linden  */
	-1,  /*Agat  */
	-1,  /*Yigo  */
	10,  /*Cap-Haitien  */
	10,  /*Les Cayes  */
	2,  /*Kowloon  */
	-4,  /*Kecskemet  */
	-4,  /*Szeged  */
	15,  /*Akureyri  */
	15,  /*Reykjavik  */
	15,  /*Vatnajokull  */
	0,  /*Ahmedabad  */
	2,  /*Bengaluru  */
	1,  /*Mumbai  */
	2,  /*Chennai  */
	1,  /*Nagpur  */
	-1,  /*New Delhi  */
	-1,  /*Pune  */
	-1,  /*Qadian  */
	-1,  /*Bandung  */
	0,  /*Battam  */
	-1,  /*Jakarta  */
	-1,  /*Malang  */
	-1,  /*Palembang  */
	-3,  /*Abadan  */
	-3,  /*Ahwaz  */
	-4,  /*Bakhtaran  */
	-4,  /*Esfahan  */
	-3,  /*Karaj  */
	-3,  /*Mashad  */
	-3,  /*Qom  */
	-3,  /*Shiraz  */
	-5,  /*Tabriz  */
	-3,  /*Tehran  */
	-4,  /*An Najaf  */
	-4,  /*Baghdad  */
	-4,  /*Basra  */
	-4,  /*Ibril  */
	-4,  /*Kirkuk  */
	-4,  /*Kufa  */
	-5,  /*Mosul  */
	5,  /*Dublin  */
	-3,  /*Bari  */
	-2,  /*Florence  */
	-2,  /*Milan  */
	-2,  /*Naples  */
	-2,  /*Rome  */
	-2,  /*Venice  */
	6,  /*Kingston  */
	6,  /*Mandeville  */
	6,  /*Montego Bay  */
	6,  /*Old Harbour  */
	7,  /*Fukuoka  */
	7,  /*Hiroshima  */
	7,  /*Kawasaki  */
	7,  /*Kyoto  */
	7,  /*Tokyo  */
	-4,  /*Amman  */
	-4,  /*Irbid  */
	-4,  /*Madaba  */
	-9,  /*Akmola  */
	-9,  /*Aktau  */
	-5,  /*Almaty  */
	-1,  /*Kisumu  */
	1,  /*Malindi  */
	1,  /*Mombasa  */
	0,  /*Nairobi  */
	0,  /*Nakuru  */
	-3,  /*Al Jahara  */
	-3,  /*Hawalli  */
	-3,  /*Kuwait  */
	-3,  /*Salmiya  */
	-5,  /*Bishkek  */
	-5,  /*Osh  */
	-5,  /*Liepaja  */
	-6,  /*Riga  */
	-4,  /*Akka  */
	-4,  /*Baalbek  */
	-4,  /*Beirut  */
	-4,  /*Sidon  */
	-4,  /*Tripoli  */
	-4,  /*Tyre  */
	-4,  /*Zahle  */
	8,  /*Buchanan  */
	8,  /*Harbel  */
	7,  /*Harper  */
	8,  /*Monrovia  */
	-3,  /*Agedabia  */
	-3,  /*Benghazi  */
	-2,  /*Misurata  */
	-1,  /*Sebha  */
	-2,  /*Tripoli  */
	-3,  /*Tubruq  */
	2,  /*Macau  */
	12,  /*Majunga  */
	12,  /*Toamasina  */
	0,  /*Alor Star  */
	0,  /*Ipoh  */
	0,  /*Kota Bharu  */
	0,  /*Kuala Lumpur  */
	0,  /*Kuantan  */
	0,  /*Kuching  */
	0,  /*Malacca  */
	0,  /*Seremban  */
	4,  /*Male  */
	5,  /*Bamako  */
	5,  /*Gao  */
	5,  /*Mopti  */
	19,  /*Port Louis  */
	19,  /*Triolet  */
	-6,  /*Acapulco  */
	-9,  /*Chihuahua  */
	-8,  /*Ciudad Juarez  */
	-7,  /*Guadalajara  */
	-11,  /*Leon  */
	-12,  /*Mexicali  */
	-6,  /*Mexico  */
	5,  /*Darhan  */
	5,  /*Ulan Bator  */
	4,  /*Agadir  */
	3,  /*Casablanca  */
	2,  /*Fez  */
	3,  /*Kenitra  */
	3,  /*Marrakech  */
	2,  /*Meknes  */
	1,  /*Oujda  */
	3,  /*Rabat  */
	3,  /*Safi  */
	2,  /*Tangier  */
	12,  /*Beira  */
	12,  /*Chibuto  */
	8,  /*Mandie  */
	18,  /*Luderitz  */
	18,  /*Tsumeb  */
	18,  /*Windhoek  */
	0,  /*Jumla  */
	-1,  /*Kathmandu  */
	-1,  /*Lalitpur  */
	-1,  /*Pyuthan  */
	0,  /*Amsterdam  */
	-19,  /*Auckland  */
	-19,  /*Dunedin  */
	-19,  /*Hamilton  */
	-19,  /*Wellington  */
	0,  /*Agadez  */
	1,  /*Maradi  */
	1,  /*Niamey  */
	3,  /*Ibadan  */
	3,  /*Ilesha  */
	3,  /*Ilorin  */
	1,  /*Kano  */
	9,  /*Hamhung  */
	9,  /*Hungnam  */
	9,  /*Kaesong  */
	9,  /*Pyongyang  */
	8,  /*Sinuiju  */
	8,  /*Wonsan  */
	-2,  /*Oslo  */
	-3,  /*Arabian Gulf  */
	1,  /*Arabian Sea  */
	-5,  /*Black Sea  */
	-10,  /*Gulf of California  */
	-2,  /*Gulf of Mexico  */
	-1,  /*Gulf of Oman  */
	-1,  /*Muscat  */
	-1,  /*Salalah  */
	-2,  /*Faisalabad  */
	-1,  /*Hyderabad  */
	-2,  /*Islamabad  */
	-1,  /*Karachi  */
	-2,  /*Lahore  */
	-2,  /*Multan  */
	-2,  /*Peshawar  */
	-2,  /*Rawalpindi  */
	-2,  /*Sargodha  */
	-2,  /*Sialkot  */
	-4,  /*Beersheba  */
	-4,  /*Elat  */
	-4,  /*Gaza  */
	-4,  /*Haifa  */
	-4,  /*Holon  */
	-4,  /*Jerusalen Region  */
	-4,  /*Tel Aviv  */
	0,  /*Chiclayo  */
	-1,  /*Lima  */
	1,  /*Manila  */
	-5,  /*Bialystok  */
	-4,  /*Gdansk  */
	-4,  /*Warsaw  */
	4,  /*Almada  */
	4,  /*Braga  */
	4,  /*Lisbon  */
	-2,  /*Doha  */
	-5,  /*Bucharest  */
	-5,  /*Constanta  */
	-12,  /*Gorky  */
	-12,  /*Kazan  */
	-7,  /*Leningrad  */
	-7,  /*Moscow  */
	0,  /*Kigali  */
	-2,  /*Abha  */
	-3,  /*Buraidah  */
	-2,  /*Dammam  */
	-2,  /*Dhahran  */
	-3,  /*Jeddah  */
	-3,  /*Madina  */
	-2,  /*Makkah  */
	-3,  /*Riyadh  */
	-4,  /*Tabouk  */
	-3,  /*Taif  */
	8,  /*Dakar  */
	8,  /*Makeni  */
	0,  /*Jurong  */
	0,  /*Serangoon  */
	0,  /*Singapore City  */
	-3,  /*Bratislava  */
	-1,  /*Berbera  */
	1,  /*Chisimayu  */
	-1,  /*Mogadishu  */
	24,  /*Cape Town  */
	24,  /*Durban  */
	24,  /*Johannesburg  */
	24,  /*Pretoria  */
	7,  /*Busan  */
	7,  /*Seoul  */
	7,  /*Ulsan  */
	0,  /*Barcelona  */
	2,  /*Madrid  */
	2,  /*Seville  */
	1,  /*Valencia  */
	3,  /*Colombo  */
	3,  /*Galle  */
	3,  /*Jaffna  */
	3,  /*Kandy  */
	-3,  /*Atbara  */
	-3,  /*Kassala  */
	-2,  /*Kosti  */
	-3,  /*Port Sudan  */
	-5,  /*Stockholm  */
	-1,  /*Bern  */
	-1,  /*Geneva  */
	-4,  /*Damascus  */
	-4,  /*Halab  */
	-4,  /*Homs  */
	-4,  /*Rakka  */
	4,  /*Taipei  */
	-4,  /*Dushanbe  */
	-4,  /*Kulob  */
	2,  /*Dar-es-Salaam  */
	2,  /*Mwanza  */
	1,  /*Bangkok  */
	-5,  /*Ankara  */
	-5,  /*Diyarbakir  */
	-5,  /*Istanbul  */
	-4,  /*Mersin  */
	-6,  /*Kiev  */
	-2,  /*Abu Dhabi  */
	-2,  /*Dubai  */
	-2,  /*Sharjah  */
	-2,  /*Ras al Khaimah  */
	-2,  /*Birmingham  */
	-2,  /*Liverpool  */
	-2,  /*London  */
	-2,  /*Manchester  */
	-2,  /*Sheffield  */
	4,  /*Atlanta  */
	3,  /*Chicago  */
	-4,  /*Dallas  */
	-9,  /*Denver  */
	7,  /*Detroit  */
	-4,  /*Houston  */
	-13,  /*Los Angeles  */
	13,  /*New York  */
	-12,  /*San Diego  */
	11,  /*Washington  */
	-5,  /*Tashkent  */
	-2,  /*Vatican City  */
	0,  /*Barcelona  */
	11,  /*Caracas  */
	11,  /*Valencia  */
	1,  /*Hanoi  */
	-1,  /*Aden  */
	-1,  /*Ibb  */
	-1,  /*Mukalla  */
	-1,  /*Sanaa  */
	-4,  /*Belgrade  */
	-4,  /*Kosovo  */
	6,  /*Lusaka  */
	11,  /*Bulawayo  */
	9  /*Harare  */
};
#endif /* __MMI_ECOMPASS__ */ 

#ifdef __SYNCML_SUPPORT__

#ifdef CUSTOM_SYNCML_ACCOUNT_DEFAULT
nvram_ef_syncml_account_struct const NVRAM_EF_SYNCML_ACCOUNT_DEFAULT[NVRAM_EF_SYNCML_ACCOUNT_TOTAL] = 
{
    CUSTOM_SYNCML_ACCOUNT_DEFAULT
};
#endif /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */
    
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
nvram_ef_syncml_account_struct const NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_PC_SYNC[NVRAM_EF_SYNCML_ACCOUNT_TOTAL] = 
{
	{                               /* default profile 1 */ 
     0xFF,                          /* Account ID */            
     "",                            /* Account Name */   
     "http://",                     /* Server Address */        
     "",                            /* User Name */             
     "",                            /* Password */              
     "./",                          /* Contact Address */     
     "",                            /* User Name */             
     "",                            /* Password */              
     "./",                          /* Calendar Address */    
     "",                            /* User Name */             
     "",                            /* Password */              
     "./",                          /* Task Address */        
     "",                            /* User Name */             
     "",                            /* Password */    
     "./",                          /* Note Address */        
     "",                            /* User Name */             
     "",                            /* Password */       
     "./",                          /* bookmark Address */      
     "",                            /* User Name */             
     "",                            /* Password */              
     "./",                          /* email Address */         
     "",                            /* User Name */             
     "",                            /* Password */             
     0x8000,                        /* Validation:valid data account*/            
     CUSTOM_DEFAULT_SYNCML_DTCNT_ID,                             /* Network ID */          
     0,                             /* Use Proxy -- No 0, Yes 1 */ 
     {0, 0, 0, 0},                  /* IP */                  
     0,                             /* Port */                
     "",                            /* User Name */            
     "",                            /* Password */             
     "",                            /* Nap hash*/             
     "",                            /* Proxy hash*/              
     "",                            /* Provurl hash*/             
     0,                             /* Type */               
     0,                             /* Read only*/                  
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */          
     0,                             /* sync type - two-way sync*/
     0,                             /* sas 0: off , 1: on */  
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */  
     0,                             /* sync report 0:off 1:on */   
     0,                             /* last_phb_anchor */   
     0,                             /* last_cal_anchor */     
     0,                             /* last_task_anchor */  
     0,                             /* last_note_anchor */  
     0,                             /* last_email_anchor */   
     0,                             /* last_bkm_anchor */      
     },                                                       
    {                               /* operator default Account 2 */  
     0xFF,                             /* Account ID */         
     "",                            /* Account Name */   
     "http://",                     /* Server Address */        
     "",                            /* User Name */             
     "",                            /* Password */              
     "./",                            /* Contact Address */     
     "",                            /* User Name */             
     "",                            /* Password */              
     "./",                            /* Calendar Address */    
     "",                            /* User Name */             
     "",                            /* Password */              
     "./",                            /* Task Address */        
     "",                            /* User Name */             
     "",                            /* Password */   
     "./",                            /* Note Address */        
     "",                            /* User Name */             
     "",                            /* Password */
     "./",                          /* bookmark Address */      
     "",                            /* User Name */             
     "",                            /* Password */              
     "./",                          /* email Address */         
     "",                            /* User Name */             
     "",                            /* Password */             
     0x8000,                          /* Validation */            
     CUSTOM_DEFAULT_SYNCML_DTCNT_ID,                             /* Network ID */          
     0,                             /* Use Proxy -- No 0, Yes 1 */ 
     {0, 0, 0, 0},                  /* IP */                  
     0,                             /* Port */                
     "",                            /* User Name */            
     "",                            /* Password */             
     "",                            /* Nap hash*/             
     "",                            /* Proxy */              
     "",                            /* Provurl*/             
     0,                             /* Type */               
     0,                             /* Read only*/                  
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */          
     0,                             /* sync type - two-way sync*/
     0,                             /* sas 0: off , 1: on */  
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */  
     0,                             /* sync report 0:off 1:on */   
     0,                             /* last_phb_anchor */   
     0,                             /* last_cal_anchor */     
     0,                             /* last_task_anchor */   
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */   
     0,                             /* last_bkm_anchor */          
     },                                                         
    {                               /* operator default profile 3 */    
     3,                             /* Account ID */            
     {'M', 0x00,'T', 0x00,'K', 0x00,' ', 0x00,'P', 0x00, 'C', 0x00, ' ', 0x00, 'S', 0x00, 'Y', 0x00, 'N', 0x00, 'C', 0x00, 0x00, 0x00},  /* bt Account Name */   
     "MTK SYNC TOOL",                /* Server Address */        
     "",                            /* User Name */             
     "",                            /* Password */              
     "./Contacts",                          /* Contact Address */       
     "",                            /* User Name */             
     "",                            /* Password */              
     "./Calendar",                          /* Calendar Address */      
     "",                            /* User Name */             
     "",                            /* Password */              
     "./Tasks",                          /* Task Address */          
     "",                            /* User Name */             
     "",                            /* Password */  
     "./Notes",                          /* Note Address */          
     "",                            /* User Name */             
     "",                            /* Password */  
     "./",                          /* bookmark Address */      
     "",                            /* User Name */             
     "",                            /* Password */              
     "./",                          /* email Address */         
     "",                            /* User Name */             
     "",                            /* Password */              
     0x0001 | 0x0002 | 0x0004 | 0x0008 | 0x0010 | 0x0020 | 0x8000,   /* Validation */        
     CUSTOM_DEFAULT_SYNCML_DTCNT_ID,                                 /* Network ID */        
     0,                             /* Use Proxy -- No 0, Yes 1 */  
     {0, 0, 0, 0},                  /* IP */                    
     0,                            /* Port */                   
     "",                            /* User Name */             
     "",                            /* Password */              
     "",                            /* Nap hash */              
     "",                            /* Proxy hash */            
     "",                            /* Provurl hash */          
     0,                             /* Profile Type */          
     0,                             /* Read only */             
     2,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */  
     0x01,                          /* App to sync only phonebook*/           
     0,                             /* sync type - two-way sync*/   
     0,                             /* sas 0: off , 1: on */    
     0,                             /* regular sync - 0:none */ 
     0,                             /* regular sync notify */   
     1,                             /* sync report 0:off 1:on */    
     0,                             /* last_phb_anchor */       
     0,                             /* last_cal_anchor */       
     0,                             /* last_task_anchor */  
     0,                             /* last_note_anchor */ 
     0,                             /* last_email_anchor */     
     0,                             /* last_bkm_anchor */       
     },
};
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

#endif /* __SYNCML_SUPPORT__ */

#if defined(__MMI_FWU_VIA_TFTP__)
static nvram_ef_dm_fwu_tftp_setting_struct const NVRAM_EF_DM_FWU_TFTP_SETTING_DEFAULT[]=
{
    {"172.22.216.28", 0, 
    {'S', 0, 'U', 0, 'P', 0, 'E', 0, 'R', 0, 'M', 0, 'A', 0, 'N', 0, '2', 0, '9', 0, '_', 0, 'M', 0, 'A', 0, 'U', 0, 'I', 0, '_', 0, 'W', 0, '0', 0, '6', 0, '_', 0, '4', 0, '4', 0, '.', 0, 'c', 0, 'p', 0, 'r', 0}, 0,},
};
#endif /* #if defined(__MMI_FWU_VIA_TFTP__) */


#if defined(__MMI_FWU_VIA_HTTP__)
static nvram_ef_dm_fwu_http_setting_struct const NVRAM_EF_DM_FWU_HTTP_SETTING_DEFAULT[]=
{
	{"http://wap1.mtk.com.tw/",0},
};
#endif  /* #if defined(__MMI_FWU_VIA_HTTP__) */

/*Rahul*/
#if defined(OBIGO_Q03C_MMS_V01)
nvram_mmsv01_compose_settings_struct const NVRAM_EF_MMSV01_COMPOSE_SETTING_CONTENT_DEFAULT[]=
{
/*#ifdef CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
#else /*CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT*/
  { 
      0,1,0,0,""
   }, 

};

nvram_mmsv01_sending_settings_struct const NVRAM_EF_MMSV01_SENDING_SETTING_CONTENT_DEFAULT[]=
{
/*#ifdef CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
#else /*CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT*/
  { 
      5,0,0,1,0,0,5
   }, 
};
#endif

#ifdef __MMI_MMS_2__
nvram_umms_compose_settings_struct const NVRAM_EF_MMS_COMPOSE_SETTING_CONTENT_DEFAULT[]=
{
#ifdef CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
#else /*CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT*/
  { 
      0,0,255,1,20,0,0,"","","","",5
   }, 
#endif
};

nvram_umms_sending_settings_struct const NVRAM_EF_MMS_SENDING_SETTING_CONTENT_DEFAULT[]=
{
#ifdef CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
#else /*CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT*/
  { 
      0,0,0,1,0,0,0,0,0,0,1
   }, 
#endif
};

#ifndef __MMI_WAP_PROF__
nvram_profile_content_struct const  NVRAM_EF_WAP_PROFILE_CONTENT_DEFAULT[NVRAM_PROFILE_MAX]=
{
#ifdef CUSTOM_WAP_PROFILE_CONTENT_DEFAULT
    CUSTOM_WAP_PROFILE_CONTENT_DEFAULT
#else
   { /* wap profile 1 - FET */
      1,0,80,"http://mobile.fetnet.net",10,-1,1,210,241,199,199,"",""
		  ,0
   },      
   { /* wap profile 2 - CHT */
      1,0,8080,"http://wap.emome.net",11,-1,1,10,1,1,1,"",""
		  ,0
   },      
   { /* wap profile 3 - Taiwan mobile */
      2,0,80,"http://ewap",12,-1,1,10,1,1,1,"",""
		  ,0
   },      
   { /* wap profile 4 - CHINA MOBILE */
      1,0,80,"http://wap.monternet.com",14,-1,1,10,0,0,172,"",""
		  ,0
   },      
   { /* wap profile 5 - Unicom */
      2,0,80,"http://wap.uni-info.com.cn",15,-1,1,10,0,0,172,"",""
		  ,0
   },    
   { /* wap profile 6 - AIRTEL INDIA */
      1,0,8080,"http://www.google.com",17,-1,1,202,56,231,117,"",""
		  ,0
   },      
	{ /* wap profile 7 - HUTCH INDIA */
      1,0,9401,"http://www.hutchworld.co.in",19,-1,1,10,10,1,100,"",""
		  ,0
   },         
   { /* wap profile 8 - KGT */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },      
   { /* wap profile 9 - Mobitai */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },         
   { /* wap profile 10 - Empty */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   }
#endif /*CUSTOM_WAP_PROFILE_CONTENT_DEFAULT*/
};

nvram_profile_content_struct const NVRAM_EF_MMS_PROFILE_CONTENT_DEFAULT[NVRAM_PROFILE_MAX] =
{
#ifdef CUSTOM_MMS_PROFILE_CONTENT_DEFAULT
    CUSTOM_MMS_PROFILE_CONTENT_DEFAULT
#else /*CUSTOM_MMS_PROFILE_CONTENT_DEFAULT*/
  { /* mms profile 1 - FET */
      1,0,80,"http://mms",10,-1,1,210,241,199,199,"",""
		  ,0
   },      
   { /* mms profile 2 - CHT */
      1,0,8080,"http://mms.emome.net:8002",11,-1,1,10,1,1,1,"",""
		  ,0
   },      
   { /* mms profile 3 - Taiwan mobile */
      1,0,80,"http://mms",12,-1,1,10,1,1,1,"",""
		  ,0
   },      
   { /* mms profile 4 - CHINA MOBILE */
      1,0,80,"http://mmsc.monternet.com",14,-1,1,10,0,0,172,"",""
		  ,0
   },      
   { /* mms profile 5 - Unicom */
      2,0,80,"http://mmsc.myuni.com.cn",15,-1,1,10,0,0,172,"",""
		  ,0
   }, 
   { /* mms profile 6 - AIRTEL INDIA */
      1,0,8080,"http://100.1.201.171:10021/mmsc",18,-1,1,100,1,201,172,"",""
		  ,0
   },    
   { /* mms profile 7 - HUTCH INDIA */
      1,0,9401,"http://mms1.hutchworld.co.in/mms/",19,-1,1,10,10,1,100,"",""
		  ,0
   },      
	{ /* mms profile 8 - KGT */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },         
   { /* mms profile 9 - Mobitai */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },      
   { /* mms profile 10 - Empty */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   }
#endif /*CUSTOM_MMS_PROFILE_CONTENT_DEFAULT*/
 };

nvram_profile_name_array_struct const NVRAM_EF_WAP_PROFILE_NAMES_DEFAULT[NVRAM_PROFILE_MAX]=
{
#ifdef CUSTOM_WAP_PROFILE_NAMES_DEFAULT
    CUSTOM_WAP_PROFILE_NAMES_DEFAULT
#else
	2,0x00,1,0,{"FET"},
	2,0x00,1,1,{"CHT"},
	2,0x00,2,2,{"Taiwan Mobile"},
	2,0x00,1,3,{"China Mobile"},
	2,0x00,2,4,{"China Unicom"},
	2,0x00,1,5,{"Airtel"},
	2,0x00,1,6,{"Hutch"},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""}
#endif /*CUSTOM_WAP_PROFILE_NAMES_DEFAULT*/
};

nvram_profile_name_array_struct const NVRAM_EF_MMS_PROFILE_NAMES_DEFAULT[NVRAM_PROFILE_MAX]=
{
#ifdef CUSTOM_MMS_PROFILE_NAMES_DEFAULT
    CUSTOM_MMS_PROFILE_NAMES_DEFAULT
#else /*CUSTOM_MMS_PROFILE_NAMES_DEFAULT*/
	2,0x00,1,0,{"FET MMS"},
	2,0x00,1,1,{"CHT MMS"},
	2,0x00,1,2,{"Taiwan Mobile MMS"},
	2,0x00,1,3,{"China Mobile MMS"},
	2,0x00,2,4,{"China Unicom MMS"},
	2,0x00,1,5,{"Airtel MMS"},
	2,0x00,1,6,{"Hutch MMS"},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""}
#endif /*CUSTOM_MMS_PROFILE_NAMES_DEFAULT*/
};

#endif /* __MMI_WAP_PROF__ */
#endif /* __MMI_MMS_2__ */

#ifdef WAP_SUPPORT
nvram_push_general_setting_struct const NVRAM_EF_PUSH_GEN_SETTING_DEFAULT[]=
{
#ifdef CUSTOM_WAP_PUSH_GEN_SET
	CUSTOM_WAP_PUSH_GEN_SET
#else
	2,0

#ifdef __MMI_WAP_PUSH_WHITE_LIST__ 
    ,1
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    ,1
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
#endif /* CUSTOM_WAP_PUSH_GEN_SET */
};
#endif /* WAP SUPPORT*/

#ifdef WAP_SUPPORT
#ifdef __MMI_OP12_BRW_SEARCH_MENU__
kal_uint8 const WAP_CUSTOM_CFG_SEARCH_WEB_URL[] = {'h', 't', 't', 'p', ':', '/', '/', 
'l', 'i', 'v', 'e', '.', 'v', 'o', 'd', 'a', 'f', 'o', 'n','e', '.', 'c', 'o', 'm', '\0'};
#endif /* __MMI_OP12_BRW_SEARCH_MENU__ */
#endif /* OBIGO_Q05A */

#if defined(__MMI_VIDEO_STREAM__)
/* 5 predefined URL */
/* "URL", "SERVER NAME" - in unicode */
static nvram_ef_video_predefined_url_struct const NVRAM_EF_VIDEO_PREDEFINED_URL_DEFAULT[NVRAM_EF_VIDEO_PREDEFINED_URL_COUNT]=
{
	{
        {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'm', 0, '.', 0, 'y', 0, 'o', 0, 
         'u', 0, 't', 0, 'u', 0, 'b', 0, 'e', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '/', 0}, /* url 1 */
        {'Y', 0, 'o', 0, 'u', 0, 'T', 0, 'u', 0, 'b', 0, 'e', 0}   /* name 1 */
    }
#ifdef DEMO_PROJECT    
    /* MTK internal test server */
	,{
	    {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'w', 0, 'a', 0, 'p', 0, '1', 0, 
         '.', 0, 'm', 0, 't', 0, 'k', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '.', 0, 't', 0, 'w', 0, 
         '/', 0}, /* url 2 */
        {'M', 0, 'T', 0, 'K', 0}   /* name 2 */
    }
#endif /* DEMO_PROJECT */
};

static nvram_ef_video_network_profile_struct const NVRAM_EF_VIDEO_NETWORK_PROFILE_DEFAULT[NVRAM_EF_VIDEO_NETWORK_PROFILE_TOTAL] =
{
    /* profile 1 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '1', 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },
    
    /* profile 2 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '2', 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 3 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '3', 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 4 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '4', 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 5 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '5', 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    }
};

#endif  /* defined(__MMI_VIDEO_STREAM__) */

#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_SUPPORT__) 
static nvram_ef_medply_settings_profile_struct const NVRAM_EF_MEDPLY_NETWORK_PROFILE_DEFAULT[NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL] =
{
    /* profile 1 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },
    
    /* profile 2 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 3 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 4 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 5 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0}, /* profile_name */
        CUSTOM_DEFAULT_STREAM_DTCNT_ID, /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    }
};
#endif /* __MMI_MEDIA_PLAYER_STREAM__ __MMI_KURO_SUPPORT__*/ 

#ifdef __MMI_MEDIA_PLAYER_STREAM__
static nvram_ef_medply_video_predefined_url_struct const NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_DEFAULT[NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_COUNT]=
{
	{
        {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'm', 0, '.', 0, 'y', 0, 'o', 0, 
         'u', 0, 't', 0, 'u', 0, 'b', 0, 'e', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '/', 0}, /* url 1 */
        {'Y', 0, 'o', 0, 'u', 0, 'T', 0, 'u', 0, 'b', 0, 'e', 0}   /* name 1 */
    }
#ifdef DEMO_PROJECT    
    /* MTK internal test server */
	,{
	    {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'w', 0, 'a', 0, 'p', 0, '1', 0, 
         '.', 0, 'm', 0, 't', 0, 'k', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '.', 0, 't', 0, 'w', 0, 
         '/', 0}, /* url 2 */
        {'M', 0, 'T', 0, 'K', 0}   /* name 2 */
    }
#endif /* DEMO_PROJECT */
};
#endif

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
static kal_uint8 const NVRAM_EF_DM_SR_NUMBER_DEFAULT[NVRAM_EF_DM_SR_NUMBER_SIZE] = 
{
	'1', '0', '6', '5', '4', '0', '4', '0', '\0'
};
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */


#ifdef __BIP_PULL_SUPPORT__
static kal_uint8 const NVRAM_EF_BT_BIP_SETTING_DEFAULT[NVRAM_EF_BT_BIP_SETTING_SIZE] = 
{
	0, 0, 0, 0, 0, 0
};
#endif /* __MMI_BIP_SUPPORT__ */

#ifdef __MMI_IPSEC__
nvram_ef_ipsec_policy_struct const NVRAM_EF_IPSEC_POLICY_DEFAULT[] = 
{
    0, {0, 0, 0, 0}, 0, {0, 0, 0, 0}, 1, 0, {0, 0, 0, 0}, 0, 2, 2
};
nvram_ef_ipsec_ike_struct const NVRAM_EF_IPSEC_IKE_DEFAULT[] = 
{
    "", 0, 0, 0
};
#endif /* __MMI_IPSEC__ */

#if defined (__MMI_DUAL_SIM_MASTER__)
#ifdef LOW_COST_SUPPORT
static kal_uint8 const NVRAM_CARD2_CB_SMS_INFO_DEFAULT[]=
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF
};
#else /* LOW_COST_SUPPORT */
static kal_uint8 const NVRAM_CARD2_CB_SMS_INFO_DEFAULT[]=
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};
#endif /* LOW_COST_SUPPORT */
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_OP01_DCD__
static kal_uint8 const NVRAM_EF_DCD_SETTING_DATA_DEFAULT[NVRAM_EF_DCD_SETTING_DATA_SIZE] = 
{
    0x01, 0x00, 0x00, 0x00, 0xFF, 0x01 
};
#endif /* __MMI_OP01_DCD__ */

#ifdef __MMI_EM_MISC_DCD__
static kal_uint8 const NVRAM_EF_DCD_EM_PARAM_DATA_DEFAULT[NVRAM_EF_DCD_EM_PARAM_DATA_SIZE] = 
{
     'c',  'm',  'w',  'a',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* APN: 12B */
     'C',  'h',  'i',  'n',  'a',  ' ',  'M',  'o',  'b',  'i',  'l',  'e', /* APN name: 24B */
	 ' ',  'G',  'P',  'R',  'S', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 '0',  '1',  '0',  '.',  '0',  '0',  '0',  '.',  '0',  '0',  '0',  '.', /* gate way: 20B*/
	 '1',  '7',  '2', 0x00, 0x00, 0x00, 0x00, 0x00,
	 '8',  '0', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                        /* port: 8B */

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't', 'e', /* add channel: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  's',  'e',  'r',  'v',  'i',  'c', 'e',
     '/',  'a',  'd',  'd',  'c',  'h',  'a',  'n',  'n',  'e',  'l', 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't',  'e', /* delete channel: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  's',  'e',  'r',  'v',  'i',  'c',  'e',
     '/',  'd',  'e',  'l',  'e',  't',  'e',  'c',  'h',  'a',  'n',  'n',  'e',  'l', 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't',  'e',/* refresh: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  'c',  'o',  'n',  't',  'e',  'n',  't',
     '/',  'r',  'e',  'f',  'r',  'e',  's',  'h', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't', 'e',/* help: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  's',  'e',  'r',  'v',  'i',  'c', 'e',
     '/',  'h',  'e',  'l',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};
#endif /* __MMI_EM_MISC_DCD__ */

#if defined(__AGPS_USER_PLANE__)
static nvram_ef_agps_profile_struct const NVRAM_EF_AGPS_PROFILE_DEFAULT[NVRAM_EF_AGPS_PROFILE_TOTAL] =
{
    /* Profile 1 */
    /* name */
    {
    /* CMCC */
    /*{0x0043, 0x004D, 0x0043, 0x0043, 0x0000},  */
    /* China Mobile AGPS server */
    {0x0043, 0x0068, 0x0069, 0x006E, 0x0061, 0x0020, 0x004D, 0x006F, 0x0062, 0x0069, 0x006C, 0x0065, 0x0020, 0x0041, 
     0x0047, 0x0050, 0x0053, 0x0020, 0x0073, 0x0065, 0x0072, 0x0076, 0x0065, 0x0072, 0x0000}, 
    /* addr */
    {0x0032, 0x0032, 0x0031, 0x002E, 0x0031, 0x0037, 0x0036, 0x002E, 0x0030, 0x002E, 0x0035, 0x0035, 0x0000}, 
    /* port */
    {0x00001c6b},
    /* data_account */
    {0x0000000e},
    /* sms_number */
    {0x0039, 0x0030, 0x0030, 0x0032, 0x0031, 0x0030, 0x0031, 0x0030, 0x0031, 0x0000}, 
    /* name_can_modify */
    0x00,    
    /* addr_can_modify */
    0x00,   
    /* port_can_modify */
    0x00,    
    /* data_account_can_modify*/ 
    0x01,
    /* is_modified */
    0x01
#ifdef    __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* nap_id */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    /* provurl */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#endif
    },
    

    /* Profile 2 */
    /* name */
    {{0x0050, 0x0072, 0x006F, 0x0066, 0x0069, 0x006C, 0x0065, 0x0020, 0x0032, 0x0000}, 
    /* addr */
    {0x0000}, 
    /* port */
    {0x00000000},
    /* data_account */
    {0xffffffff},
    /* sms_number */
    {0x0000}, 
    /* name_can_modify */
    0x01,    
    /* addr_can_modify */
    0x01,   
    /* port_can_modify */
    0x01,   
    /* data_account_can_modify*/ 
    0x01,
    /* is_modified */
    0x00
#ifdef    __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* nap_id */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    /* provurl */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#endif
    },
    

    /* Profile 3 */
    /* name */
    {{0x0050, 0x0072, 0x006F, 0x0066, 0x0069, 0x006C, 0x0065, 0x0020, 0x0033, 0x0000}, 
    /* addr */
    {0x0000}, 
    /* port */
    {0x00000000},
    /* data_account */
    {0xffffffff},
    /* sms_number */
    {0x0000}, 
    /* name_can_modify */
    0x01,    
    /* addr_can_modify */
    0x01,   
    /* port_can_modify */
    0x01,   
    /* data_account_can_modify*/ 
    0x01,
    /* is_modified */
    0x00
#ifdef    __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* nap_id */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    /* provurl */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#endif
    },


    /* Profile 4 */
    /* name */
    {{0x0050, 0x0072, 0x006F, 0x0066, 0x0069, 0x006C, 0x0065, 0x0020, 0x0034, 0x0000}, 
    /* addr */
    {0x0000}, 
    /* port */
    {0x00000000},
    /* data_account */
    {0xffffffff},
    /* sms_number */
    {0x0000}, 
    /* name_can_modify */
    0x01,    
    /* addr_can_modify */
    0x01,   
    /* port_can_modify */
    0x01,   
    /* data_account_can_modify*/ 
    0x01,
    /* is_modified */
    0x00
#ifdef    __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* nap_id */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    /* provurl */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#endif
    },

    /* Profile 5 */
    /* name */
    {{0x0050, 0x0072, 0x006F, 0x0066, 0x0069, 0x006C, 0x0065, 0x0020, 0x0035, 0x0000}, 
    /* addr */
    {0x0000}, 
    /* port */
    {0x00000000},
    /* data_account */
    {0xffffffff},
    /* sms_number */
    {0x0000}, 
    /* name_can_modify */
    0x01,    
    /* addr_can_modify */
    0x01,   
    /* port_can_modify */
    0x01,   
    /* data_account_can_modify*/ 
    0x01,
    /* is_modified */
    0x00
#ifdef    __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    /* nap_id */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    /* provurl */
    ,{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#endif
    },
};
#endif /* __AGPS_USER_PLANE__ */

#if defined(__GPS_SUPPORT__) && defined(__MNL_SUPPORT__)
static kal_uint8 const NVRAM_EF_MNL_SETTING_DATA_DEFAULT[] = {
/* Internal LNA Enable          ,  1  */ 0x00,
/* TCXO Frequency Drift         ,  1  */ 0x01,
/* SBAS Mode                    ,  1  */ 0x00,
/* Clock Type                   ,  1  */ 0x00,
/* Frequency Error for XTAL     ,  1  */ 0x00,
/* Frame Sync Enable            ,  1  */ 0x00,
/* Reserved                     ,  10 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#endif /* __GPS_SUPPORT__ & __MNL_SUPPORT__ */


#ifdef __MMI_VUI_MAINMENU__
static kal_uint8 const NVRAM_EF_VENUS_MM_DEFAULT [NVRAM_EF_VENUS_MM_SIZE] =
{
   0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B
};
#endif /*__MMI_VUI_MAINMENU__*/

#ifdef __MMI_AZAAN_ALARM__
static mmi_hijri_azaan_nvram_struct const NVRAM_EF_AZAAN_ALARM_DEFAULT[NVRAM_AZAAN_ALARM_SIZE] =
{
    /* For Fajr */
    0x05, 0X21, 0x00, 
    152,
    0x00,
    /* For Zuhr */
    0x0C, 0x23, 0x00,
    152,
    0x00,
    /* For Asr */
    0x10, 0x2D, 0x00,
    152,
    0x00,
    /* For Magrib */
    0x12, 0x19, 0x00,
    152,
    0x00,
    /* For Isha */
    0x13, 0x24, 0x00,
    152,
    0x00,
};
#endif /* __MMI_AZAAN_ALARM__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
static kal_uint8 const NVRAM_EF_SRV_SMS_PDU_DEFAULT[] = {
                        /* status, 1 byte, unused flag */ 
                        0x00,
                        /* Reminder, 175 byte */
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                        0x00, 0x00, 0x00, 0x00, 0x00, 
                        /* timestamp, 4 byte */
                        0x00, 0x00, 0x00, 0x00
                    #ifdef __SRV_SMS_MULTI_SIM__
                        /* sim id, 2 byte */
                        , 0x01, 0x01
                    #endif
                  };
#endif

#if defined (__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
static kal_uint32 const NVRAM_EF_BWCS_SETTING_DATA_DEFAULT[] =
{
    /* Real Time RSSI Threshold : BT / WIFI1 / WIFI2 */
    73, 73, 73,
    /* Non Real Time RSSI Threshold : BT / WIFI1 / WIFI2 */
    73, 73, 73,
    /* Antenna path compensation */
    10,
    /* antenna path switch protection period, Unit is frames (4.615us) */
    2000,
    /* TX Flow control : medium time / period time */
    0x0E00, 0x01,
    /* BT RX Range : Low / High */
    0xC4, 0xE2,
    /* BT TX power : WIFI OFF / WIFI SCO / WIFI ACL */
    0x07, 0x03, 0x02,
    /* Reserved                     ,  5 */
    0x00, 0x00, 0x00, 0x00, 0x00
};
#endif /* __WIFI_BT_SINGLE_ANTENNA_SUPPORT__ */

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
static nvram_ef_op11_hs32_hist_struct const NVRAM_EF_OP11_HS32_HIST_DEFAULT[NVRAM_EF_OP11_HS32_HIST_TOTAL] = 
{
	{
		{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* sidebar items */
		{
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Call  0*/
			{0x00, 0x02, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Contacts (PHB) 1*/
#ifdef __MMI_UNIFIED_COMPOSER__
			{0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Message  2*/
#else
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Message  2*/
#endif
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Email  3*/
			{0x00, 0x01, 0x02, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Orange Messenger  4*/
			{0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0xff, 0xff, 0xff, 0xff}, /* Orange World (WAP)  5*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Profile  6*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Alarms  7*/
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Calendar  8*/
			{0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Music  9*/
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Photography  10*/
			{0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Connections (BT, Flight Mode)  11*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Device Status  12*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* SIM Toolkit  13*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Take Photo 14 */
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* VIP Contacts 15 */
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* AP reserved (PHB for example) 16 */
			{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff} /* */
		}
	}
};
#endif /*defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)*/

/**
 * Steps of defining logical data item:
 * 1> Define LID of new logical data item into `nvram_LID_cust_enum' in 
 *    nvram_user_defs.h
 * 2> Define two constants: SIZE and TOTAL, in nvram_user_defs.h
 * 3> Define default value of that new logical data item in nvram_user_config.c
 * 4> Define attributes of that new logical data item into 
 *    `logical_data_item_table_cust'
 * 5> Bypass.
 * 6> Change version number CODED_DATA_VERSION in nvram_user_config.c
 */
/**
 * The logical data item table.
 * Note:
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 */
 /**
 * The rule for data item changes:
 * 1. To add a new data item, its name must be the next of the current last LID, for example, 
 *     the last LID in the CT reign now is CT20, the new one must be CT21. 
 * 2. Version must be increased if 
 *    (a) Size is changed, or 
 *    (b) Number of sections is changed, or 
 *    (c) Attribute is changed, or 
 *    (d) data structure is changed.
 */
ltable_entry_struct logical_data_item_table_comm_app[] = 
{
#ifdef __NVRAM_UNIT_TEST__
    {
        NVRAM_EF_NVRAM_UNIT_TEST_LID,
        NVRAM_EF_NVRAM_UNIT_TEST_SIZE,
        NVRAM_EF_NVRAM_UNIT_TEST_TOTAL,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "NV00",
        VER(NVRAM_EF_NVRAM_UNIT_TEST_LID),
        "NVRAM UNIT TEST",
        NVRAM_APP_RESERVED
    },
#endif
/*
    {
        NVRAM_EF_ADC_LID,
        NVRAM_EF_ADC_SIZE,
        NVRAM_EF_ADC_TOTAL,
        NVRAM_NORMAL((kal_uint8 const *)NVRAM_EF_ADC_DEFAULT),
        NVRAM_ATTR_MULTIPLE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        "MP00",
        VER(NVRAM_EF_ADC_LID),
        "ADC",
        NVRAM_APP_RESERVED
    }
    ,*/
    {
        NVRAM_EF_CUST_HW_LEVEL_TBL_LID,
        NVRAM_EF_CUST_HW_LEVEL_TBL_SIZE,
        NVRAM_EF_CUST_HW_LEVEL_TBL_TOTAL,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_CUST_HW_LEVEL_TBL_DEFAULT),
        NVRAM_ATTR_SW_VERNO_RESET,
        NVRAM_CATEGORY_USER,
        "MP01",
        VER(NVRAM_EF_CUST_HW_LEVEL_TBL_LID),
        "HW Level",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_UEM_MANUFACTURE_DATA_LID,
        NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE,
        NVRAM_EF_UEM_MANUFACTURE_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP02",
        VER(NVRAM_EF_UEM_MANUFACTURE_DATA_LID),
        "UEM Manufact",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_UEM_RMI_DATA_LID,
        NVRAM_EF_UEM_RMI_DATA_SIZE,
        NVRAM_EF_UEM_RMI_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_UEM_RMI_DATA_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP04",
        VER(NVRAM_EF_UEM_RMI_DATA_LID),
        "UEM RMI",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CUST_ACOUSTIC_DATA_LID,
        NVRAM_EF_CUST_ACOUSTIC_DATA_SIZE,
        NVRAM_EF_CUST_ACOUSTIC_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_CUST_ACOUSTIC_DATA_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP05",
        VER(NVRAM_EF_CUST_ACOUSTIC_DATA_LID),
        "Accoustic",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_AUDIO_PARAM_LID,
        NVRAM_EF_AUDIO_PARAM_SIZE,
        NVRAM_EF_AUDIO_PARAM_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_MULTIPLE,
        NVRAM_CATEGORY_USER,
        "MP06",
        VER(NVRAM_EF_AUDIO_PARAM_LID),
        "Audio Parameter",
        NVRAM_APP_RESERVED
    }

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_AUTOTEST_LID,
        NVRAM_EF_AUTOTEST_SIZE ,
        NVRAM_EF_AUTOTEST_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_AUTOTEST_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP07",
        VER(NVRAM_EF_AUTOTEST_LID),
        "AutoTest",
        NVRAM_APP_RESERVED
    }
#endif
    ,{
        NVRAM_EF_PORT_SETTING_LID,
        NVRAM_EF_PORT_SETTING_SIZE,
        NVRAM_EF_PORT_SETTING_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_PORT_SETTING_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP08",
        VER(NVRAM_EF_PORT_SETTING_LID),
        "Port Settings",
        NVRAM_APP_RESERVED
    }
    ,{                                                                   
        NVRAM_EF_BARCODE_NUM_LID,
        NVRAM_EF_BARCODE_NUM_SIZE,
        NVRAM_EF_BARCODE_NUM_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_BARCODE_NUM_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        "MP09",
        VER(NVRAM_EF_BARCODE_NUM_LID),
        "BARCODE",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_SYS_CACHE_OCTET_LID,
        NVRAM_EF_SYS_CACHE_OCTET_SIZE,
        NVRAM_EF_SYS_CACHE_OCTET_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_SYS_CACHE_OCTET_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MP0A",
        VER(NVRAM_EF_SYS_CACHE_OCTET_LID),
        "SYS_CACHE_OCTET",
        NVRAM_APP_RESERVED
    }
#if defined(PLUTO_MMI) || defined(NEPTUNE_MMI)
    ,{
        NVRAM_EF_CACHE_BYTE_LID,
        NVRAM_CACHE_SIZE,
        NVRAM_CACHE_TOTAL,
        NVRAM_CUSTPACK(NVRAM_CACHE_BYTE_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MM00",
        VER(NVRAM_EF_CACHE_BYTE_LID),
        "1-byte Setting",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CACHE_SHORT_LID,
        NVRAM_CACHE_SIZE,
        NVRAM_CACHE_TOTAL,
        NVRAM_CUSTPACK(NVRAM_CACHE_SHORT_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MM01",
        VER(NVRAM_EF_CACHE_SHORT_LID),
        "2-byte Setting",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CACHE_DOUBLE_LID,
        NVRAM_CACHE_SIZE,
        NVRAM_CACHE_TOTAL,
        NVRAM_CUSTPACK(NVRAM_CACHE_DOUBLE_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MM02",
        VER(NVRAM_EF_CACHE_DOUBLE_LID),
        "8-byte Setting",
        NVRAM_APP_RESERVED
    }
#endif
    ,{
        NVRAM_EF_IMEI_IMEISV_LID,
        NVRAM_EF_IMEI_IMEISV_SIZE,
        NVRAM_EF_IMEI_IMEISV_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_IMEI_IMEISV_DEFAULT),
    #ifndef __SECURITY_OTP__
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL,
    #else
        NVRAM_ATTR_AVERAGE,
    #endif

    #ifndef __SECURITY_OTP__
        NVRAM_CATEGORY_IMPORTANT,
    #else
        NVRAM_CATEGORY_OTP,
    #endif
        "MP0B",
        VER(NVRAM_EF_IMEI_IMEISV_LID),
        "IMEI IMEISV",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_PHB_LID,
        NVRAM_EF_PHB_SIZE,
        NVRAM_EF_PHB_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_PHB_DEFAULT),
        NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MP0C",
        VER(NVRAM_EF_PHB_LID),
        "Phone Book",
        NVRAM_APP_RESERVED
    }
#if !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__)
    ,{
        NVRAM_EF_PHB_LN_ENTRY_LID,
        NVRAM_EF_PHB_LN_ENTRY_SIZE,
        NVRAM_EF_PHB_LN_ENTRY_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0D",
        VER(NVRAM_EF_PHB_LN_ENTRY_LID),
        "Last Dial Num",
        NVRAM_APP_RESERVED
    }
#endif /* !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__) */
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)    
    ,{
        NVRAM_EF_PHB_SOS_LID,
        NVRAM_EF_PHB_SOS_SIZE,
        NVRAM_EF_PHB_SOS_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PHB_SOS_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MP0E",
        VER(NVRAM_EF_PHB_SOS_LID),
        "Phonebook SOS",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_PHB_SPEEDDIAL_LID,
        NVRAM_EF_PHB_SPEEDDIAL_SIZE,
        NVRAM_EF_PHB_SPEEDDIAL_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0F",
        VER(NVRAM_EF_PHB_SPEEDDIAL_LID),
        "Phonebook SpeedDial",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_PHB_RES_LID,
        NVRAM_EF_PHB_RES_SIZE,
        NVRAM_EF_PHB_RES_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MP0G",
        VER(NVRAM_EF_PHB_RES_LID),
        "Phonebook IDs",
        NVRAM_APP_RESERVED
    }
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    ,{
        NVRAM_EF_PHB_FIELDS_LID,
        NVRAM_EF_PHB_FIELDS_SIZE,
        NVRAM_EF_PHB_FIELDS_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MP0H",
        VER(NVRAM_EF_PHB_FIELDS_LID),
        "Phonebook Fields",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_PHB_NO_OPTIONAL_FIELD__ */
    ,{
        NVRAM_EF_PHB_FIELDS_MASK_LID,
        NVRAM_EF_PHB_FIELDS_MASK_SIZE,
        NVRAM_EF_PHB_FIELDS_MASK_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0I",
        VER(NVRAM_EF_PHB_FIELDS_MASK_LID),
        "Phonebook Settings",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_PHB_GROUP_INFO_LID,
        NVRAM_EF_PHB_GROUP_INFO_SIZE,
        NVRAM_EF_PHB_GROUP_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0J",
        VER(NVRAM_EF_PHB_GROUP_INFO_LID),
        "PHB Caller Group",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_PHB_MY_NUMBER_LID,
        NVRAM_EF_PHB_MY_NUMBER_SIZE,
        NVRAM_EF_PHB_MY_NUMBER_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0K",
        VER(NVRAM_EF_PHB_MY_NUMBER_LID),
        "PHB my number",
        NVRAM_APP_RESERVED
    }   
#if defined(__MMI_PHB_EMAIL_SORT__)
    ,{
        NVRAM_EF_PHB_EMAIL_SORT_LID,
        NVRAM_EF_PHB_EMAIL_SORT_SIZE,
        NVRAM_EF_PHB_EMAIL_SORT_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0L",
        VER(NVRAM_EF_PHB_EMAIL_SORT_LID),
        "Email sorting",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_PHB_EMAIL_SORT__ */
    ,{
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        NVRAM_EF_PHB_GROUP_FIELD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0M",
        VER(NVRAM_EF_PHB_GROUP_FIELD_LID),
        "PHB Group ID",
        NVRAM_APP_RESERVED
    }
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    ,{
        NVRAM_EF_PHB_BIRTHDAY_LID,
        NVRAM_EF_PHB_BIRTHDAY_SIZE,
        NVRAM_EF_PHB_BIRTHDAY_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0P",
        VER(NVRAM_EF_PHB_BIRTHDAY_LID),
        "PHB Birthday",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_PHB_BIRTHDAY_FIELD__ */
#if defined(__MMI_PHB_INFO_FIELD__)
    ,{
        NVRAM_EF_PHB_INFO_LID,
        NVRAM_EF_PHB_INFO_SIZE,
        NVRAM_EF_PHB_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0Q",
        VER(NVRAM_EF_PHB_INFO_LID),
        "PHB Personal Information",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_PHB_INFO_FIELD__ */
#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/* __MMI_IMPS__ */
#if defined(__MMI_PHB_POC_FIELD__)
    ,{
        NVRAM_EF_PHB_POC_LID,
        NVRAM_EF_PHB_POC_SIZE,
        NVRAM_EF_PHB_POC_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0T",
        VER(NVRAM_EF_PHB_POC_LID),
        "PHB PoC Field ",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_PHB_POC_FIELD__ */
#if defined(__MMI_VOIP__)
    ,{
        NVRAM_EF_PHB_VOIP_LID,
        NVRAM_EF_PHB_VOIP_SIZE,
        NVRAM_EF_PHB_VOIP_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0U",
        VER(NVRAM_EF_PHB_VOIP_LID),
        "PHB VoIP Field ",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_VOIP__ */
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */
#if !defined(__PHB_NO_CALL_LOG__)
    ,{
        NVRAM_EF_PHB_LN_TYPE_SEQ_LID,
        NVRAM_EF_PHB_LN_TYPE_SEQ_SIZE,
        NVRAM_EF_PHB_LN_TYPE_SEQ_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0N",
        VER(NVRAM_EF_PHB_LN_TYPE_SEQ_LID),
        "PHB LN Type Seq",
        NVRAM_APP_RESERVED
    }
#endif /* !defined(__PHB_NO_CALL_LOG__) */
#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    ,{
        NVRAM_EF_SMS_LID,
        NVRAM_SMS_TEMPL_RECORD_SIZE,
        NVRAM_SMS_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0V",
        VER(NVRAM_EF_SMS_LID),
        "SMS",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_MESSAGES_PREDEFINED_TEMPLATE__*/
#ifdef __MOD_SMSAL__
#if (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI))
    ,{
        NVRAM_EF_SMS_CB_CHNL_LID,
        NVRAM_SMS_CB_CHNL_RECORD_SIZE,
        NVRAM_SMS_CB_CHNL_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0W",
        VER(NVRAM_EF_SMS_CB_CHNL_LID),
        "SMS CB Channel",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_SMS_CB_SMS_LID,
        NVRAM_SMS_CB_SMS_PAGE_SIZE,
        NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP0X",
        VER(NVRAM_EF_SMS_CB_SMS_LID),
        "SMS CB SMS",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_SMS_CB_SMS_INFO_LID,
        NVRAM_SMS_CB_SMS_INFO_SIZE,
        NVRAM_SMS_CB_SMS_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_SMS_CB_SMS_INFO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP0Y",
        VER(NVRAM_EF_SMS_CB_SMS_INFO_LID),
        "SMS CB SMS INFO",
        NVRAM_APP_RESERVED
    }
#endif /* (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)) */
#endif/*__MOD_SMSAL__*/	
#ifdef __DOWNLOAD__
    ,{
        NVRAM_EF_EMS_MY_PICTURE_NAME_LID,
        NVRAM_EMS_MY_PICTURE_NAME_RECORD_SIZE,
        NVRAM_EMS_MY_PICTURE_NAME_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP0Z",
        VER(NVRAM_EF_EMS_MY_PICTURE_NAME_LID),
        "EMS Picture",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_EMS_MY_ANIMATION_NAME_LID,
        NVRAM_EMS_MY_ANIMATION_NAME_RECORD_SIZE,
        NVRAM_EMS_MY_ANIMATION_NAME_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP10",
        VER(NVRAM_EF_EMS_MY_ANIMATION_NAME_LID),
        "EMS Animation",
        NVRAM_APP_RESERVED
    }
#ifdef __MMI_IMELODY_SUPPORT__
    ,{
        NVRAM_EF_EMS_MY_MELODY_NAME_LID,
        NVRAM_EMS_MY_MELODY_NAME_RECORD_SIZE,
        NVRAM_EMS_MY_MELODY_NAME_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP11",
        VER(NVRAM_EF_EMS_MY_MELODY_NAME_LID),
        "EMS Melody",
        NVRAM_APP_RESERVED
    }
#endif
#endif/*__DOWNLOAD__*/	

#if !defined(__SMS_STORAGE_BY_MMI__)
    ,{
        NVRAM_EF_SMSAL_SMS_LID,
        NVRAM_EF_SMSAL_SMS_SIZE,
        NVRAM_EF_SMSAL_SMS_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_SMSAL_SMS_DEFAULT),
        NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MP12",
        VER(NVRAM_EF_SMSAL_SMS_LID),
        "SMSAL SMS",
        NVRAM_APP_RESERVED
    }
#endif

#if !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_SMSAL_MAILBOX_ADDR_LID,
        NVRAM_EF_SMSAL_MAILBOX_ADDR_SIZE,
        NVRAM_EF_SMSAL_MAILBOX_ADDR_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MP13",
        VER(NVRAM_EF_SMSAL_MAILBOX_ADDR_LID), 
        "SMSAL MAILBOX",
        NVRAM_APP_RESERVED
    }
#endif

    ,{
        NVRAM_EF_SMSAL_COMMON_PARAM_LID,
        NVRAM_EF_SMSAL_COMMON_PARAM_SIZE,
        NVRAM_EF_SMSAL_COMMON_PARAM_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MP14",
        VER(NVRAM_EF_SMSAL_COMMON_PARAM_LID),
        "SMSAL COMMON",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CB_DEFAULT_CH_LID,
        NVRAM_EF_CB_DEFAULT_CH_SIZE,
        NVRAM_EF_CB_DEFAULT_CH_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MP15",
        VER(NVRAM_EF_CB_DEFAULT_CH_LID),
        "CB Default CH",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_SMSAL_SMSP_LID,
        NVRAM_EF_SMSAL_SMSP_SIZE,
        NVRAM_EF_SMSAL_SMSP_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MP16", 
        VER(NVRAM_EF_SMSAL_SMSP_LID), 
        "SMSAL SMSP",
        NVRAM_APP_RESERVED
    }
#ifdef __MMI_MESSAGES_CLUB__
    ,{
        NVRAM_EF_MSG_CLUB_LID,
        NVRAM_MSG_CLUB_RECORD_SIZE,
        NVRAM_MSG_CLUB_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_MSG_CLUB_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP17",
        VER(NVRAM_EF_MSG_CLUB_LID),
        "Msg Club",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_MSG_CLUB_NUM_LID,
        NVRAM_MSG_CLUB_NUM_RECORD_SIZE,
        NVRAM_MSG_CLUB_NUM_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_MSG_CLUB_NUM_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP18",
        VER(NVRAM_EF_MSG_CLUB_NUM_LID),
        "Msg Club Number",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_MESSAGES_CLUB__*/
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_CALL_TIME_LID,
        NVRAM_CALL_TIME_RECORD_SIZE ,
        NVRAM_CALL_TIME_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1A",
        VER(NVRAM_EF_CALL_TIME_LID),
        "Call Time",
        NVRAM_APP_RESERVED
    }
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    ,{
        NVRAM_EF_CAMERA_SETTING_LID,
        NVRAM_EF_CAMERA_SETTING_SIZE,
        NVRAM_EF_CAMERA_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP1B",
        VER(NVRAM_EF_CAMERA_SETTING_LID),
        "CAMERA SETTING",
        NVRAM_APP_CAMERAPP
    }
#endif/* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */
#if defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
    ,{
        NVRAM_EF_VIDEO_SETTING_LID,
        NVRAM_EF_VIDEO_SETTING_SIZE,
        NVRAM_EF_VIDEO_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP1C",
        VER(NVRAM_EF_VIDEO_SETTING_LID),
        "VIDEO SETTING",
        NVRAM_APP_RESERVED
    }
#endif/* defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__) */
#if (defined(ISP_SUPPORT) && (!defined(DRV_ISP_6238_SERIES)) && (!defined(BACKUP_SENSOR_SUPPORT)))
    ,{
        NVRAM_EF_CAMERA_PARA_LID,
        NVRAM_EF_CAMERA_PARA_SIZE,
        NVRAM_EF_CAMERA_PARA_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_PARA_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1D",
        VER(NVRAM_EF_CAMERA_PARA_LID),
        "Camera Para",
        NVRAM_APP_RESERVED
    }
#endif/* (defined(ISP_SUPPORT) && (!defined(DRV_ISP_6238_SERIES)) && (!defined(BACKUP_SENSOR_SUPPORT))) */
#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES))
    ,{
        NVRAM_EF_CAMERA_GAMMA_LID,
        NVRAM_EF_CAMERA_GAMMA_SIZE,
        NVRAM_EF_CAMERA_GAMMA_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_GAMMA_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1E",
        VER(NVRAM_EF_CAMERA_GAMMA_LID),
        "Camera Gamma",
        NVRAM_APP_RESERVED
    }
#endif/*defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES))*/	
#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))	
    ,{
        NVRAM_EF_CAMERA_DEFECT_LID,
        NVRAM_EF_CAMERA_DEFECT_SIZE,
        NVRAM_EF_CAMERA_DEFECT_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1F",
        VER(NVRAM_EF_CAMERA_DEFECT_LID),
        "Camera Defect",
        NVRAM_APP_RESERVED
    }
#endif /*defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))*/
#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))
    ,{
        NVRAM_EF_CAMERA_LENS_LID,
        NVRAM_EF_CAMERA_LENS_SIZE,
        NVRAM_EF_CAMERA_LENS_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_LENS_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1G",
        VER(NVRAM_EF_CAMERA_LENS_LID),
        "Camera Lens",
        NVRAM_APP_RESERVED
    }
#endif/*defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))*/

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#ifdef __IP_NUMBER__
    ,{
        NVRAM_EF_IP_NUMBER_LID,
        NVRAM_IP_NUMBER_SIZE,
        NVRAM_IP_NUMBER_TOTAL,
        NVRAM_NORMAL(NVRAM_IP_NUMBER_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1H",
        VER(NVRAM_EF_IP_NUMBER_LID),
        "IP Number",
        NVRAM_APP_RESERVED
    }
#endif/*__IP_NUMBER__*/
#endif

#ifdef __TCPIP_OVER_CSD__
    ,{
        NVRAM_EF_CSD_PROFILE_LID,
        NVRAM_EF_CSD_PROFILE_SIZE,
        NVRAM_EF_CSD_PROFILE_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_CSD_PROFILE_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_CUSTPACK,
        "MP1I",
        VER(NVRAM_EF_CSD_PROFILE_LID),
        "CSD Profile",
        NVRAM_APP_RESERVED
    }
#endif
#ifdef __PS_SERVICE__
    ,{
        NVRAM_EF_ABM_GPRS_PROFILE_LID,
        NVRAM_EF_ABM_GPRS_PROFILE_SIZE,
        NVRAM_EF_ABM_GPRS_PROFILE_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_ABM_PS_PROFILE_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_CUSTPACK,
        "MP1J",
        VER(NVRAM_EF_ABM_GPRS_PROFILE_LID),
        "ABM GPRS PROFILE",
        NVRAM_APP_RESERVED
    }
#endif/*__PS_SERVICE__*/
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_EXT_MELODY_INFO_LID,
        NVRAM_EF_EXT_MELODY_INFO_SIZE,
        NVRAM_EF_EXT_MELODY_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1K",
        VER(NVRAM_EF_EXT_MELODY_INFO_LID),
        "External Melody",
        NVRAM_APP_RESERVED
    }
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_ALM_QUEUE_LID,
        NVRAM_ALM_QUEUE_SIZE ,
        NVRAM_ALM_QUEUE_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_SW_VERNO_RESET,
        NVRAM_CATEGORY_USER ,
        "MP1L",
        VER(NVRAM_EF_ALM_QUEUE_LID),
        "Alarm queue",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_ALM_SPOF_DATA_LID,
        NVRAM_ALM_SPOF_DATA_SIZE ,
        NVRAM_ALM_SPOF_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_SW_VERNO_RESET,
        NVRAM_CATEGORY_USER,
        "MP1M", 
        VER(NVRAM_EF_ALM_SPOF_DATA_LID), 
        "Alarm SPOF data",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_ALM_ALARM_DATA_LID,
        NVRAM_ALM_ALARM_DATA_SIZE ,
        NVRAM_ALM_ALARM_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_SW_VERNO_RESET,
        NVRAM_CATEGORY_USER,
        "MP1N",
        VER(NVRAM_EF_ALM_ALARM_DATA_LID),
        "Alarm data",
        NVRAM_APP_RESERVED
    }
#endif /* #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */
#ifdef __MMI_TODOLIST__
    ,{
        NVRAM_EF_TODO_LIST_LID,
        NVRAM_TODO_LIST_RECORD_SIZE,
        NVRAM_TODO_LIST_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MP1O",
        VER(NVRAM_EF_TODO_LIST_LID),
        "Todo List",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_TODOLIST__ */
#if defined (__PS_SERVICE__) && defined (__MOD_TCM__)
    ,{
        NVRAM_EF_TCM_PDP_PROFILE_LID,
        NVRAM_EF_TCM_PDP_PROFILE_SIZE,
        NVRAM_EF_TCM_PDP_PROFILE_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_TCM_PDP_PROFILE_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1P",
        VER(NVRAM_EF_TCM_PDP_PROFILE_LID),
        "TCM PDP Profile",
        NVRAM_APP_RESERVED
    }
#endif // ~ #if defined (__PS_SERVICE__) && defined (__MOD_TCM__)
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_SETTING_LID,
        NVRAM_SETTING_SIZE,
        NVRAM_SETTING_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SETTING_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MP1Q", 
        VER(NVRAM_EF_SETTING_LID), 
        "Greeting Txt",
        NVRAM_APP_RESERVED
    }
#endif /* #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_GROUPLIST_LID,
        NVRAM_MAX_GROUP_NAME_SIZE,
        NVRAM_MAX_GROUP_NAME_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1R",
        VER(NVRAM_EF_GROUPLIST_LID),
        "Group Lists",
        NVRAM_APP_RESERVED
    }
#endif

#ifdef __MMI_FILE_MANAGER__
    ,{
        NVRAM_EF_WPSS_FILENAME_LID,
        NVRAM_EF_WPSS_FILENAME_SIZE,
        NVRAM_EF_WPSS_FILENAME_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP1S",
        VER(NVRAM_EF_WPSS_FILENAME_LID),
        "Dispchar path",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_FILE_MANAGER__ */
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_SHORTCUTS_LID,
        NVRAM_SHORTCUTS_SIZE,
        NVRAM_SHORTCUTS_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP1T",
        VER(NVRAM_EF_SHORTCUTS_LID),
        "Shortcuts",
        NVRAM_APP_RESERVED
    }
#endif
#ifdef __MMI_CALORIE__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CALORIE__ */
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_PROFILES_LID,
        NVRAM_PROFILES_RECORD_SIZE,
        NVRAM_PROFILES_RECORD_TOTAL,
        NVRAM_NORMAL((kal_uint8 const *)NVRAM_PROFILES_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP1V",
        VER(NVRAM_EF_PROFILES_LID),
        "Profiles",
        NVRAM_APP_RESERVED
    }
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */
#ifdef __MMI_STOPWATCH__
    ,{
        NVRAM_EF_STOPWATCH_LID,
        NVRAM_EF_STOPWATCH_RECORD_SIZE,
        NVRAM_EF_STOPWATCH_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1W",
        VER(NVRAM_EF_STOPWATCH_LID),
        "Stopwatch",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_STOPWATCH__*/
#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
    ,{
        NVRAM_PICTURE_EDITOR_LID,
        NVRAM_PICTURE_EDITOR_SIZE,
        NVRAM_PICTURE_EDITOR_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP1X",
        VER(NVRAM_PICTURE_EDITOR_LID),
        "Pic Editor",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_PICTURE_EDITOR_SUPPORT__*/
#ifdef __MMI_PHOTOEDITOR__
    ,{
        NVRAM_EF_PHOTO_EDITOR_SETTING_LID,
        NVRAM_EF_PHOTO_EDITOR_SETTING_SIZE,
        NVRAM_EF_PHOTO_EDITOR_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP1Y",
        VER(NVRAM_EF_PHOTO_EDITOR_SETTING_LID),
        "Photo Editor",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_PHOTOEDITOR__*/
#ifdef __MMI_FM_RADIO__
    ,{
        NVRAM_EF_FM_RADIO_LID,
        NVRAM_EF_FM_RADIO_SIZE,
        NVRAM_EF_FM_RADIO_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
#ifdef __MMI_FM_RADIO_SCHEDULER__
        NVRAM_CATEGORY_USER,
#else         
        NVRAM_CATEGORY_USER,
#endif 
        "MP1Z",
        VER(NVRAM_EF_FM_RADIO_LID),
        "FM Radio",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_FM_RADIO__*/
#ifdef __MMI_FM_RADIO_SCHEDULE_REC__    
    ,{
        NVRAM_EF_FMSR_SETTING_LID,
        NVRAM_EF_FMSR_SETTING_SIZE,
        NVRAM_EF_FMSR_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP20",
        VER(NVRAM_EF_FMSR_SETTING_LID),
        "Schedule FM Radio Record",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_FM_RADIO_SCHEDULE_REC__*/
#ifdef __MMI_VRSD__
    ,{
        NVRAM_EF_VRSD_TAG_LID,
        NVRAM_EF_VRSD_TAG_SIZE,
        NVRAM_EF_VRSD_TAG_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        NVRAM_CATEGORY_USER,
        "MP21",
        VER(NVRAM_EF_VRSD_TAG_LID),
        "VRSD Tag",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_VRSD__*/
#ifdef __MMI_VRSI__
    ,{
        NVRAM_EF_VRSI_TAG_LID,
        NVRAM_EF_VRSI_TAG_SIZE,
        NVRAM_EF_VRSI_TAG_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        NVRAM_CATEGORY_USER,
        "MP22",
        VER(NVRAM_EF_VRSI_TAG_LID),
        "VRSI TAG",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_VRSI__*/
#if NVRAM_EF_FMGR_FILEPATH_COUNT  /* not 0 */
    ,{
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_LID,
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_SIZE,
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP23",
        VER(NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_LID),
        "Fmgr Path Pool Head",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_LID,
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_SIZE,
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP24",
        VER(NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_LID),
        "Fmgr Path Pool Tail",
        NVRAM_APP_RESERVED
    }
#endif /* NVRAM_EF_FILEPATH_COUNT */
#ifdef __BT_SUPPORT__
    ,{
        NVRAM_EF_BT_INFO_LID,
        NVRAM_EF_BT_INFO_SIZE,
        NVRAM_EF_BT_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP25",
        VER(NVRAM_EF_BT_INFO_LID),
        "Bluetooth info",
        NVRAM_APP_RESERVED
    }

    ,{
        NVRAM_EF_BT_SYS_INFO_LID,
        NVRAM_EF_BT_SYS_INFO_SIZE,
        NVRAM_EF_BT_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP29",
        VER(NVRAM_EF_BT_SYS_INFO_LID),
        "Bluetooth system settng info",
        NVRAM_APP_RESERVED
    }

#endif/*__BT_SUPPORT__*/    
#ifdef __MMI_CM_BLACK_LIST__
    ,{
        NVRAM_EF_BLACK_LIST_LID,
        NVRAM_EF_BLACK_LIST_SIZE,
        NVRAM_EF_BLACK_LIST_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2A",
        VER(NVRAM_EF_BLACK_LIST_LID),
        "Black List",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_CM_BLACK_LIST__*/
#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/* __MMI_IMPS__ */
#ifdef __MMI_AUDIO_EQUALIZER__
    ,{
        NVRAM_EF_AUDIO_EQUALIZER_LID,
        NVRAM_EF_AUDIO_EQUALIZER_SIZE,
        NVRAM_EF_AUDIO_EQUALIZER_TOTAL,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_AUDIO_EQUALIZER_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP2C",
        VER(NVRAM_EF_AUDIO_EQUALIZER_LID),
        "Audio EQ",
        NVRAM_APP_EDITABLE_EQ
    }
#endif/*__MMI_AUDIO_EQUALIZER__*/
#ifdef __MMI_POC__
    ,{
        NVRAM_EF_POC_PROFILE_LID,
        NVRAM_MAX_POC_PROFILE_SIZE,
        NVRAM_MAX_POC_PROFILE_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2D",
        VER(NVRAM_EF_POC_PROFILE_LID),
        "PoC Contact",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_POC_HISTORY_LID,
        NVRAM_MAX_POC_HISTORY_SIZE,
        NVRAM_MAX_POC_HISTORY_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2E",
        VER(NVRAM_EF_POC_HISTORY_LID),
        "PoC History",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_POC_PRIVACY_LID,
        NVRAM_MAX_POC_PRIVACY_SIZE,
        NVRAM_MAX_POC_PRIVACY_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2F",
        VER(NVRAM_EF_POC_PRIVACY_LID),
        "PoC Privacy",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_POC__*/
#ifdef __MMI_THEMES_APPLICATION__
    ,{
        NVRAM_EF_THEMES_VALUES,
        NVRAM_THEMES_VALUES_SIZE,
        NVRAM_THEMES_VALUES_RECORDS,
        NVRAM_NORMAL(NVRAM_THEMES_VALUES_DEFAULT),
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP2G",
        VER(NVRAM_EF_THEMES_VALUES),
        "Theme Values",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_THEMES_APPLICATION__*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    ,{
        NVRAM_EF_THEME_MANAGER_LID,
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        NVRAM_EF_THEME_MANAGER_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2H",
        VER(NVRAM_EF_THEME_MANAGER_LID),
        "Theme Manager",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
        NVRAM_THEMES_DOWNLOAD_SIZE,
        NVRAM_THEMES_DOWNLOAD_RECORDS,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2I",
        VER(NVRAM_EF_THEME_DOWNLOAD_LIST_LID),
        "down load list ",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */	
#ifdef __MMI_MOTION_APP__
    ,{
        NVRAM_EF_MOTION_DICE_LID,
        NVRAM_EF_MOTION_DICE_SIZE,
        NVRAM_EF_MOTION_DICE_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP2J",
        VER(NVRAM_EF_MOTION_DICE_LID),
        "Motion Dice",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_MOTION_DJ_LID,
        NVRAM_EF_MOTION_DJ_SIZE,
        NVRAM_EF_MOTION_DJ_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP2K",
        VER(NVRAM_EF_MOTION_DJ_LID),
        "Motion DJ",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_MOTION_APP__ */
#if defined(__MMI_EONS_SUPPORT__)
    ,{
        NVRAM_EF_EONS_INFO_LID,
        NVRAM_EF_EONS_INFO_SIZE,
        NVRAM_EF_EONS_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2L",
        VER(NVRAM_EF_EONS_INFO_LID),
        "EONS Info",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_EONS_SUPPORT__ */
#ifdef __MMI_BG_SOUND_EFFECT__
    ,{
        NVRAM_EF_BGSND_SETTING_LID,
        NVRAM_EF_BGSND_SETTING_SIZE,
        NVRAM_EF_BGSND_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP2M",
        VER(NVRAM_EF_BGSND_SETTING_LID),
        "Background Sound Setting",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_BGSND_FILEPATH_LID,
        NVRAM_EF_BGSND_FILEPATH_SIZE,
        NVRAM_EF_BGSND_FILEPATH_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2N",
        VER(NVRAM_EF_BGSND_FILEPATH_LID),
        "Background Sound Filepath",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_BG_SOUND_EFFECT__ */	
#ifdef JATAAYU_SUPPORT
    ,{
        NVRAM_EF_BRW_BOOKMARK_TITLE_LID,
        NVRAM_EF_BRW_BOOKMARK_RECORD_TITLE_SIZE,
        NVRAM_EF_BRW_BOOKMARK_TITLE_RECORDS,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_BRW_BOOKMARK_TITLE_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET
        NVRAM_CATEGORY_USER,
        "MP2O",
        VER(NVRAM_EF_BRW_BOOKMARK_TITLE_LID), 
        "Bookmark Title",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_BRW_BOOKMARK_URL_LID,
        NVRAM_EF_BRW_BOOKMARK_RECORD_URL_SIZE,
        NVRAM_EF_BRW_BOOKMARK_URL_RECORDS,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_BRW_BOOKMARK_URL_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MP2P", 
        VER(NVRAM_EF_BRW_BOOKMARK_URL_LID), 
        "Bookmark URL",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
        NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_TITLE_SIZE,
        NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_RECORDS,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2Q", 
        VER(NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID), 
        "History Title",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
        NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_URL_SIZE,
        NVRAM_EF_BRW_ADDRESS_HISTORY_URL_RECORDS,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2R",
        VER(NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID),
        "History URL",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_JMMS_COMPOSE_SETTINGS_LID,
        NVRAM_JMMS_COMPOSE_SETTINGS_SIZE,
        NVRAM_JMMS_COMPOSE_SETTINGS_RECORDS,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2S", 
        VER(NVRAM_EF_JMMS_COMPOSE_SETTINGS_LID), 
        "jmms compose settings",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_JMMS_SENDING_SETTINGS_LID,
        NVRAM_JMMS_SENDING_SETTINGS_SIZE,
        NVRAM_JMMS_SENDING_SETTINGS_RECORDS,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2T", 
        VER(NVRAM_EF_JMMS_SENDING_SETTINGS_LID), 
        "jmms sending settings",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_WAP_PROFILE_CONTENT_LID,
        NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
        NVRAM_EF_WAP_PROFILE_CONTENT_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_WAP_PROFILE_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MP2U",
        VER(NVRAM_EF_WAP_PROFILE_CONTENT_LID), 
        "wap profile",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_MMS_PROFILE_CONTENT_LID,
        NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
        NVRAM_EF_MMS_PROFILE_CONTENT_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MMS_PROFILE_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MP2V",
        VER(NVRAM_EF_MMS_PROFILE_CONTENT_LID),
        "mms profile",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_WAP_PROFILE_NAMES_LID,
        NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
        NVRAM_EF_WAP_PROFILE_NAMES_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_WAP_PROFILE_NAMES_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2W",
        VER(NVRAM_EF_WAP_PROFILE_NAMES_LID),
        "wap profile name",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_MMS_PROFILE_NAMES_LID,
        NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
        NVRAM_EF_MMS_PROFILE_NAMES_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MMS_PROFILE_NAMES_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2X", 
        VER(NVRAM_EF_MMS_PROFILE_NAMES_LID), 
        "mms profile name",
        NVRAM_APP_RESERVED
        }
    ,{
        NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID,
        NVRAM_MAX_READ_UNREAD_STATUS_BYTES,
        NVRAM_JMMS_INBOX_READ_STATUS_RECORDS,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2Y", 
        VER(NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID), 
        "jmms inbox status",
        NVRAM_APP_RESERVED
    }
#endif/* JATAAYU_SUPPORT */
#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
    ,{
        NVRAM_EF_USER_CTRL_PLMN_LID,
        NVRAM_EF_USER_CTRL_PLMN_SIZE,
        NVRAM_EF_USER_CTRL_PLMN_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP2Z",
        VER(NVRAM_EF_USER_CTRL_PLMN_LID),
        "User Control PLMN Info",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_USER_CTRL_PLMN_SUPPORT__ */
#ifdef __MMI_EBOOK_READER__ 
    ,{
        NVRAM_EF_EBOOK_SETTINGS_LID,
        NVRAM_EF_EBOOK_SETTING_SIZE,
        NVRAM_EF_EBOOK_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_EBOOK_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP30",
        VER(NVRAM_EF_EBOOK_SETTINGS_LID),
        "Ebook Settings",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_EBOOK_READER__ */
#ifdef __MMI_BARCODEREADER__
    , {
        NVRAM_EF_BARCODEREADER_SETTING_LID,
        NVRAM_EF_BARCODEREADER_SETTING_SIZE,
        NVRAM_EF_BARCODEREADER_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP32",
        VER(NVRAM_EF_BARCODEREADER_SETTING_LID),
        "BARCODEREADER SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_BARCODEREADER__ */
    ,{
        NVRAM_EF_SML_LID,
        NVRAM_EF_SML_SIZE,
        NVRAM_EF_SML_TOTAL,
        NVRAM_SECUPACK(&NVRAM_EF_SML_DEFAULT),
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        #ifdef __SMART_PHONE_MODEM__
        NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT_L4,
        #else
        NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT,
        #endif
        "MP33",
        VER(NVRAM_EF_SML_LID),
        "SIM-ME Lock",
        NVRAM_APP_RESERVED
    }
#if defined(__MMI_A2DP_SUPPORT__)
    ,{
        NVRAM_EF_A2DP_SETTINGS_LID,
        sizeof(nvram_ef_a2dp_settings_struct),
        1,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP36",
        VER(NVRAM_EF_A2DP_SETTINGS_LID),
        "BT A2DP SETTINGS",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_A2DP_SUPPORT__*/
#ifdef __MMI_VOIP__
    ,{
        NVRAM_EF_VOIP_PROF_LID,
        NVRAM_EF_VOIP_PROF_SIZE,
        NVRAM_EF_VOIP_PROF_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP37",
        VER(NVRAM_EF_VOIP_PROF_LID),
        "VoIP Profile Setting",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_VOIP_SETTING_LID,
        NVRAM_EF_VOIP_SETTING_SIZE,
        NVRAM_EF_VOIP_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP38",
        VER(NVRAM_EF_VOIP_SETTING_LID),
        "VoIP Call Setting",
        NVRAM_APP_RESERVED
    }    
#endif /* __MMI_VOIP__*/
#ifdef __WIFI_SUPPORT__
    ,{
        NVRAM_EF_WLAN_SETTING_LID,
        NVRAM_MAX_WLAN_SETTING_SIZE,
        NVRAM_MAX_WLAN_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP39",
        VER(NVRAM_EF_WLAN_SETTING_LID),
        "WLAN Settings",
        NVRAM_APP_RESERVED
    },
    {
        NVRAM_EF_WLAN_PROFILE_LID,
        NVRAM_MAX_WLAN_PROFILE_SIZE,
        NVRAM_MAX_WLAN_PROFILE_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP40",
        VER(NVRAM_EF_WLAN_PROFILE_LID),
        "WLAN Profile",
        NVRAM_APP_RESERVED
    }
#endif /* __WIFI_SUPPORT__*/
#if defined(__EM_MODE__) && defined(__MMI_ENGINEER_MODE__)
    ,{
        NVRAM_EF_EM_NW_EVENT_RINGS_LID,
        NVRAM_EF_EM_NW_EVENT_RINGS_SIZE,
        NVRAM_EF_EM_NW_EVENT_RINGS_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MT36",
        VER(NVRAM_EF_EM_NW_EVENT_RINGS_LID),
        "EM NW Event Rings",
        NVRAM_APP_RESERVED
    }
#endif /* defined(__EM_MODE__) && defined(__MMI_ENGINEER_MODE__) */
#ifdef __MMI_NITZ__

    ,{
        NVRAM_EF_NITZ_NW_NAME_LID,
        NVRAM_NITZ_NW_NAME_SIZE ,
        NVRAM_NITZ_NW_NAME_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP42",
        VER(NVRAM_EF_NITZ_NW_NAME_LID),
        "NITZ PLMN",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_NITZ__ */
#if defined(__MMI_FWU_VIA_TFTP__)
    ,{
        NVRAM_EF_DM_FWU_TFTP_SETTING_LID,
        NVRAM_EF_DM_FWU_TFTP_SETTING_SIZE,
        NVRAM_EF_DM_FWU_TFTP_SETTING_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_DM_FWU_TFTP_SETTING_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP43",
        VER(NVRAM_EF_DM_FWU_TFTP_SETTING_LID),
        "DM FWU TFTP Setting",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_FWU_VIA_TFTP__ */
#if defined(__MMI_FWU_VIA_HTTP__)
    ,{
        NVRAM_EF_DM_FWU_HTTP_SETTING_LID,
        NVRAM_EF_DM_FWU_HTTP_SETTING_SIZE,
        NVRAM_EF_DM_FWU_HTTP_SETTING_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_DM_FWU_HTTP_SETTING_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP44",
        VER(NVRAM_EF_DM_FWU_HTTP_SETTING_LID),
        "DM FWU HTTP Setting",
        NVRAM_APP_RESERVED
    }
#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */
    ,{
        NVRAM_EF_MS_SECURITY_LID,
        NVRAM_EF_MS_SECURITY_SIZE,
        NVRAM_EF_MS_SECURITY_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MS_SECURITY_DEFAULT),
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MP45",
        VER(NVRAM_EF_MS_SECURITY_LID), 
        "MS SECURITY",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_RAC_PREFERENCE_LID,
        NVRAM_EF_RAC_PREFERENCE_SIZE,
        NVRAM_EF_RAC_PREFERENCE_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MP46",
        VER(NVRAM_EF_RAC_PREFERENCE_LID),
        "RAC Preference",
        NVRAM_APP_RESERVED
    }
#ifdef __MMI_AVATAR__
    , {
        NVRAM_EF_AVATAR_SETTING_LID,
        NVRAM_EF_AVATAR_SETTING_SIZE,
        NVRAM_EF_AVATAR_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP47",
        VER(NVRAM_EF_AVATAR_SETTING_LID),
        "AVATAR SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_AVATAR__ */
#ifdef WAP_SUPPORT
    ,{
        NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
        NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_TITLE_SIZE,
        NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_RECORDS,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP48", 
        VER(NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID), 
        "History Title",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
        NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_URL_SIZE,
        NVRAM_EF_BRW_ADDRESS_HISTORY_URL_RECORDS,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP49",
        VER(NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID),
        "History URL",
        NVRAM_APP_RESERVED
    }
#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    ,{
        NVRAM_EF_BRW_LAST_WEB_ADDR_LID,
        NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE,
        NVRAM_EF_BRW_LAST_WEB_ADDR_RECORDS,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP4A",
        VER(NVRAM_EF_BRW_LAST_WEB_ADDR_LID), 
        "Last Web Address",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__  */
#ifndef __MMI_WAP_PROF__
    ,{
        NVRAM_EF_WAP_PROFILE_CONTENT_LID,
        NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
        NVRAM_EF_WAP_PROFILE_CONTENT_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_WAP_PROFILE_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MP4D",
        VER(NVRAM_EF_WAP_PROFILE_CONTENT_LID), 
        "wap profile",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_WAP_PROFILE_NAMES_LID,
        NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
        NVRAM_EF_WAP_PROFILE_NAMES_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_WAP_PROFILE_NAMES_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4E",
        VER(NVRAM_EF_WAP_PROFILE_NAMES_LID),
        "wap profile name",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_MMS_PROFILE_CONTENT_LID,
        NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
        NVRAM_EF_MMS_PROFILE_CONTENT_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MMS_PROFILE_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MP4F",
        VER(NVRAM_EF_MMS_PROFILE_CONTENT_LID),
        "mms profile",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_MMS_PROFILE_NAMES_LID,
        NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
        NVRAM_EF_MMS_PROFILE_NAMES_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MMS_PROFILE_NAMES_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4G",
        VER(NVRAM_EF_MMS_PROFILE_NAMES_LID), 
        "mms profile name",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_WAP_PROF__ */
#endif /* OBIGO_Q05A */
#ifdef __MMI_CSB_BROWSER__
    ,{
        NVRAM_EF_CSB_SETTINGS_LID,
        NVRAM_CSB_SETTINGS_SIZE,
        NVRAM_CSB_SETTINGS_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP4H",
        VER(NVRAM_EF_CSB_SETTINGS_LID),
        "CSB Settings",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_CSB_BROWSER__ */    
#ifdef __MMI_VIDEO_STREAM__
    ,{
        NVRAM_EF_VIDEO_PREDEFINED_URL_LID,
        NVRAM_EF_VIDEO_PREDEFINED_URL_SIZE,
        NVRAM_EF_VIDEO_PREDEFINED_URL_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_VIDEO_PREDEFINED_URL_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP4I",
        VER(NVRAM_EF_VIDEO_PREDEFINED_URL_LID),
        "VIDEO PREDEFINED URL",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_VIDEO_STREAM__*/
#ifdef __MMI_VIDEO_STREAM__
    ,{
        NVRAM_EF_VIDEO_HISTORY_URL_LID,
        NVRAM_EF_VIDEO_HISTORY_URL_SIZE,
        NVRAM_EF_VIDEO_HISTORY_URL_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP4J",
        VER(NVRAM_EF_VIDEO_HISTORY_URL_LID),
        "VIDEO HISTORY URL",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_VIDEO_STREAM__*/
#ifdef __DRM_V02__
    ,{
        NVRAM_EF_DRM_SETTING_LID, 
        NVRAM_EF_DRM_SETTING_SIZE,
        NVRAM_EF_DRM_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL,
        NVRAM_CATEGORY_USER,
        "DRM1",
        VER(NVRAM_EF_DRM_SETTING_LID),
        "DRM Service Setting",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_DRM_STIME_LID, 
        NVRAM_EF_DRM_STIME_SIZE,
        NVRAM_EF_DRM_STIME_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_CONFIDENTIAL,
        NVRAM_CATEGORY_USER,
        "DRM2",
        VER(NVRAM_EF_DRM_STIME_LID),
        "DRM Secure Time",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_DRM_CERPATH_LID, 
        NVRAM_EF_DRM_CERPATH_SIZE,
        NVRAM_EF_DRM_CERPATH_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "DRM3",
        VER(NVRAM_EF_DRM_CERPATH_LID),
        "DRM Certificate",
        NVRAM_APP_RESERVED
    }

#endif /* __DRM_V02__ */

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
    ,{
        NVRAM_EF_DM_SR_NUMBER_LID,
        NVRAM_EF_DM_SR_NUMBER_SIZE,
        NVRAM_EF_DM_SR_NUMBER_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_DM_SR_NUMBER_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP4K",
        VER(NVRAM_EF_DM_SR_NUMBER_LID),
        "DM Self-Register Number",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */

#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CUSTOMER_SERVICE__ */

#if defined (__MMI_MMS_2__)	
    ,{
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        NVRAM_UMMS_COMPOSE_SETTINGS_RECORDS,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MMS_COMPOSE_SETTING_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4N",
        VER(NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID), 
        "mms compose settings",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
        NVRAM_UMMS_SENDING_SETTINGS_SIZE,
        NVRAM_UMMS_SENDING_SETTINGS_RECORDS,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MMS_SENDING_SETTING_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4O",
        VER(NVRAM_EF_UMMS_SENDING_SETTINGS_LID), 
        "mms sending settings",
        NVRAM_APP_RESERVED
    }
#endif


#if defined (OBIGO_Q03C_MMS_V01)	
    ,{
        NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
        NVRAM_MMSV01_COMPOSE_SETTINGS_SIZE,
        NVRAM_MMSV01_COMPOSE_SETTINGS_RECORDS,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MMSV01_COMPOSE_SETTING_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4N",
        VER(NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID),
        "mms compose settings",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_MMSV01_SENDING_SETTINGS_LID,
        NVRAM_MMSV01_SENDING_SETTINGS_SIZE,
        NVRAM_MMSV01_SENDING_SETTINGS_RECORDS,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MMSV01_SENDING_SETTING_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4O",
        VER(NVRAM_EF_MMSV01_SENDING_SETTINGS_LID), 
        "mms sending settings",
        NVRAM_APP_RESERVED
    }
#endif

#ifdef __MMI_EMAIL_TEMPLATE__
    ,{
        NVRAM_EF_EMAIL_TEMPLATE_LID,
        NVRAM_EMAIL_TEMPL_RECORD_SIZE,
        NVRAM_EMAIL_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP4P",
        VER(NVRAM_EF_EMAIL_TEMPLATE_LID),
        "EMAIL TEMPLATE",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_EMAIL_TEMPLATE__*/

#ifdef __MMI_LANGLN_LK__
    ,{
        NVRAM_EF_LANGLN_LK_SETTING_LID,
        NVRAM_EF_LANGLN_LK_SETTING_SIZE,
        NVRAM_EF_LANGLN_LK_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP4Q",
        VER(NVRAM_EF_LANGLN_LK_SETTING_LID),
        "LANGLN_LK SETTING",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_LANGLN_LK__*/

#ifdef __MMI_LANGLN__
    ,{
        NVRAM_EF_LANGLN_PRESEL_INFO_LID,
        NVRAM_EF_LANGLN_PRESEL_INFO_SIZE,
        NVRAM_EF_LANGLN_PRESEL_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4R",
        VER(NVRAM_EF_LANGLN_PRESEL_INFO_LID),
        "LANGLN preselect info",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_LANGLN__*/

#ifdef __MMI_MOBILE_TV_PLAYER__
    , {
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE,
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4S",
        VER(NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID),
        "MOBILE TV PLAYER SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_MOBILE_TV_PLAYER__ */

#if defined(__MMI_LANGLN_SK__) || defined(__MMI_LANGLN_BK__)
    , {
        NVRAM_EF_LANGLN_BSK_SETTING_LID,
        NVRAM_EF_LANGLN_BSK_SETTING_SIZE,
        NVRAM_EF_LANGLN_BSK_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4T",
        VER(NVRAM_EF_LANGLN_BSK_SETTING_LID),
        "LANGLN SK SETTING",
        NVRAM_APP_RESERVED
    }
#endif /*__MMI_LANGLN_SK__*/

#ifdef __MMI_SLIDESHOW__
    ,{  
        NVRAM_EF_SLIDE_SHOW_SETTING_LID,
        NVRAM_EF_SLIDE_SHOW_SETTING_SIZE,
        NVRAM_EF_SLIDE_SHOW_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4U",
        VER(NVRAM_EF_SLIDE_SHOW_SETTING_LID),
        "Slide Show",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_SLIDESHOW__*/

#ifdef __MMI_VIDEO_TELEPHONY__
    , {
        NVRAM_EF_VT_SETTING_LID,
        NVRAM_EF_VT_SETTING_SIZE,
        NVRAM_EF_VT_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4V",
        VER(NVRAM_EF_VT_SETTING_LID),
        "VT SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __BIP_PULL_SUPPORT__
    ,{
        NVRAM_EF_BT_BIP_SETTING_LID,
        NVRAM_EF_BT_BIP_SETTING_SIZE,
        NVRAM_EF_BT_BIP_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_BT_BIP_SETTING_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4X",
        VER(NVRAM_EF_BT_BIP_SETTING_LID),
        "BT_BIP_SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_BIP_SUPPORT__ */

#if defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)
    , {
        NVRAM_EF_GIS_GPS_SETTING_DATA_LID,
        NVRAM_EF_GIS_GPS_SETTING_DATA_SIZE,
        NVRAM_EF_GIS_GPS_SETTING_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4Y",
        VER(NVRAM_EF_GIS_GPS_SETTING_DATA_LID),
        "MMI GPS SETTING",
        NVRAM_APP_RESERVED
    }
    , {
        NVRAM_EF_TIME_SYNC_SETTING_LID,
        NVRAM_EF_TIME_SYNC_SETTING_SIZE,
        NVRAM_EF_TIME_SYNC_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP4Z",
        VER(NVRAM_EF_TIME_SYNC_SETTING_LID),
        "TIME SYNC SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__) */

#ifdef __MMI_BARCODEREADER__
#if defined(__MMI_OP11_BARCODEREADER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef __GPS_SUPPORT__
    , {
        NVRAM_EF_GPS_SETTING_DATA_LID,
        NVRAM_EF_GPS_SETTING_DATA_SIZE,
        NVRAM_EF_GPS_SETTING_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP51",
        VER(NVRAM_EF_GPS_SETTING_DATA_LID),
        "GPS SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* __GPS_SUPPORT__ */
#if defined (__MMI_DUAL_SIM_MASTER__)
    ,{
        NVRAM_EF_CARD2_CB_CHNL_LID,
        NVRAM_SMS_CB_CHNL_RECORD_SIZE,
        NVRAM_SMS_CB_CHNL_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP52",
        VER(NVRAM_EF_CARD2_CB_CHNL_LID),
        "SMS CB Channel",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CARD2_CB_SMS_LID,
        NVRAM_SMS_CB_SMS_PAGE_SIZE,
        NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP53",
        VER(NVRAM_EF_CARD2_CB_SMS_LID),
        "SMS CB SMS",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CARD2_CB_SMS_INFO_LID,
        NVRAM_SMS_CB_SMS_INFO_SIZE,
        NVRAM_SMS_CB_SMS_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_CARD2_CB_SMS_INFO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP54",
        VER(NVRAM_EF_CARD2_CB_SMS_INFO_LID),
        "SMS CB SMS INFO",
        NVRAM_APP_RESERVED
    }
#endif /*__MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_VIDEO_STREAM__
    ,{
        NVRAM_EF_VIDEO_NETWORK_PROFILE_LID,
        NVRAM_EF_VIDEO_NETWORK_PROFILE_SIZE,
        NVRAM_EF_VIDEO_NETWORK_PROFILE_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_VIDEO_NETWORK_PROFILE_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MP55",
        VER(NVRAM_EF_VIDEO_NETWORK_PROFILE_LID),
        "VIDEO NETWORK PROFILE",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_VIDEO_STREAM__*/

#ifdef __MMI_OP01_DCD__
    , {
        NVRAM_EF_DCD_SETTING_DATA_LID,
        NVRAM_EF_DCD_SETTING_DATA_SIZE,
        NVRAM_EF_DCD_SETTING_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_DCD_SETTING_DATA_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP56",
        VER(NVRAM_EF_DCD_SETTING_DATA_LID),
        "DCD SETTING",
        NVRAM_APP_RESERVED
    }
#endif

#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))
  #if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))

    ,{
        NVRAM_EF_CAMERA_PARA1_LID,
        NVRAM_EF_CAMERA_PARA1_SIZE,
        NVRAM_EF_CAMERA_PARA1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_PARA_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP57",
        VER(NVRAM_EF_CAMERA_PARA1_LID),
        "Camera Para",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_PARA2_LID,
        NVRAM_EF_CAMERA_PARA2_SIZE,
        NVRAM_EF_CAMERA_PARA2_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_3A_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP58",
        VER(NVRAM_EF_CAMERA_PARA2_LID),
        "Camera 3a",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT1_LID,
        NVRAM_EF_CAMERA_DEFECT1_SIZE,
        NVRAM_EF_CAMERA_DEFECT1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP59",
        VER(NVRAM_EF_CAMERA_DEFECT1_LID),
        "Camera Defect1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT2_LID,
        NVRAM_EF_CAMERA_DEFECT2_SIZE,
        NVRAM_EF_CAMERA_DEFECT2_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT2_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5A",
        VER(NVRAM_EF_CAMERA_DEFECT2_LID),
        "Camera Defect2",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_SHADING1_LID,
        NVRAM_EF_CAMERA_SHADING1_SIZE,
        NVRAM_EF_CAMERA_SHADING1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5B",
        VER(NVRAM_EF_CAMERA_SHADING1_LID),
        "Camera Shading1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_SHADING2_LID,
        NVRAM_EF_CAMERA_SHADING2_SIZE,
        NVRAM_EF_CAMERA_SHADING2_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING2_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5C",
        VER(NVRAM_EF_CAMERA_SHADING2_LID),
        "Camera Shading2",
        NVRAM_APP_RESERVED
    }
 #endif  //  #if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT))) 
#endif/*defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES) */	

#ifdef __MMI_CAMCORDER__
    ,{
        NVRAM_EF_CAMCO_MAIN_SETTING_LID,
        NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
        NVRAM_EF_CAMCO_MAIN_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP5D",
        VER(NVRAM_EF_CAMCO_MAIN_SETTING_LID),
        "CAMCO MAIN SETTING",
        NVRAM_APP_CAMCODER
    }

    ,{
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_LID,
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_SIZE,
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP5E",
        VER(NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_LID),
        "CAMCO MAIN SCENE SEL SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_CAMCORDER__ */

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    , {
        NVRAM_EF_AGPS_SETTING_LID,
        NVRAM_EF_AGPS_SETTING_SIZE,
        NVRAM_EF_AGPS_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP5F",
        VER(NVRAM_EF_AGPS_SETTING_LID),
        "AGPS SETTING",
        NVRAM_APP_RESERVED
    }

    , {
        NVRAM_EF_EM_GPS_POS_TYPE_LID,
        NVRAM_EF_EM_GPS_POS_TYPE_SIZE,
        NVRAM_EF_EM_GPS_POS_TYPE_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP5G",
        VER(NVRAM_EF_EM_GPS_POS_TYPE_LID),
        "EM GPS POS TYPE",
        NVRAM_APP_RESERVED
    }
#endif

#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    ,{
        NVRAM_EF_AUDPLY_LAST_PLAYLIST_PATH_LID,
        NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_SIZE,
        NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP5K",
        VER(NVRAM_EF_AUDPLY_LAST_PLAYLIST_PATH_LID),
        "AUDPLY LAST PLAYLIST PATH",
        NVRAM_APP_RESERVED
    }
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

    /* phonebook vip contact */
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
    , {
        NVRAM_EF_PHB_VIP_CONTACT_LID,
        NVRAM_EF_PHB_VIP_CONTACT_SIZE,
        NVRAM_EF_PHB_VIP_CONTACT_TOTAL,
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PHB_VIP_CONTACT_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
    #endif
        NVRAM_ATTR_AVERAGE,
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
    #else
        NVRAM_CATEGORY_USER /* | NVRAM_CATEGORY_FACTORY */,
    #endif
        "MP5L",
        VER(NVRAM_EF_PHB_VIP_CONTACT_LID),
        "PHB Vip Contact",
        NVRAM_APP_RESERVED
    }
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) */
    /* phonebook vip contact */

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    ,{
        NVRAM_EF_SMS_EMAIL_LID,
        NVRAM_SMS_EMAIL_RECORD_SIZE,
        NVRAM_SMS_EMAIL_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5M",
        VER(NVRAM_EF_SMS_EMAIL_LID),
        "SMSEMAIL",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_MESSAGES_SMS_EMAIL__*/
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#ifdef __MMI_WAP_PROF__
    ,{
        NVRAM_EF_WAP_PROF_WAP_PROFILE_CONTENT_LID,
        NVRAM_EF_WAP_PROF_WAP_PROFILE_CONTENT_SIZE,
        NVRAM_EF_WAP_PROF_WAP_PROFILE_CONTENT_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_PROF_WAP_PROFILE_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_CUSTPACK,
        "MP5O", 
        VER(NVRAM_EF_WAP_PROF_WAP_PROFILE_CONTENT_LID), 
        "wap profile",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_WAP_PROF_MMS_PROFILE_CONTENT_LID,
        NVRAM_EF_WAP_PROF_MMS_PROFILE_CONTENT_SIZE,
        NVRAM_EF_WAP_PROF_MMS_PROFILE_CONTENT_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_PROF_MMS_PROFILE_CONTENT_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_CUSTPACK,
        "MP5Q",
        VER(NVRAM_EF_WAP_PROF_MMS_PROFILE_CONTENT_LID),
        "mms profile",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_WAP_PROF__ */
#if defined(__MMI_BT_AUTO_PROMPT_SWITCH__)
    ,{
        NVRAM_EF_BT_DEFDEVICE_LID,
        NVRAM_EF_BT_DEFDEVICE_SIZE,
        NVRAM_EF_BT_DEFDEVICE_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5S",
        VER(NVRAM_EF_BT_DEFDEVICE_LID),
        "Bluetooth default device",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_BT_AUTO_PROMPT_SWITCH__ */

#if defined(__MMI_TODOLIST__) && defined(__MMI_BIRTHDAY_REMINDER__)
    ,{
        NVRAM_EF_TDL_BR_LID,
        NVRAM_EF_TDL_BR_SIZE,
        NVRAM_EF_TDL_BR_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MP5T",
        VER(NVRAM_EF_TDL_BR_LID),
        "Birth day",
        NVRAM_APP_RESERVED
    }
#endif

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    ,{
        NVRAM_EF_SMS_RECENT_EVENT_BITMAP_LID,
        NVRAM_EF_SMS_RECENT_EVENT_BITMAP_SIZE,
        NVRAM_EF_SMS_RECENT_EVENT_BITMAP_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5U",
        VER(NVRAM_EF_SMS_RECENT_EVENT_BITMAP_LID),
        "SMS Recent Event bitmap",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_OP11_HOMESCREEN__ || __MMI_VUI_HOMESCREEN__ */
#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__)
    ,{
        NVRAM_EF_SMS_VOICEMAIL_TIME_LID,
        NVRAM_EF_SMS_VOICEMAIL_TIME_SIZE,
        NVRAM_EF_SMS_VOICEMAIL_TIME_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5V",
        VER(NVRAM_EF_SMS_VOICEMAIL_TIME_LID),
        "SMS Voicemail Time",
        NVRAM_APP_RESERVED
    }
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__) */

#if defined(__GPS_SUPPORT__) && defined(__MNL_SUPPORT__)
    , {
        NVRAM_EF_MNL_SETTING_DATA_LID,
        NVRAM_EF_MNL_SETTING_DATA_SIZE,
        NVRAM_EF_MNL_SETTING_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_MNL_SETTING_DATA_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5W",
        VER(NVRAM_EF_MNL_SETTING_DATA_LID),
        "MNL SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* __GPS_SUPPORT__ & __MNL_SUPPORT__ */

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__) || defined(__MMI_VUI_HOMESCREEN__)
    ,{
        NVRAM_EF_CHIST_MISS_ACCUM_TIMES_LID,
        NVRAM_EF_CHIST_MISS_ACCUM_TIMES_SIZE,
        NVRAM_EF_CHIST_MISS_ACCUM_TIMES_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5X",
        VER(NVRAM_EF_CHIST_MISS_ACCUM_TIMES_LID),
        "CHIST Missed Call Accu Times ",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CHIST_MISS_EVENT_CHECK_LID,
        NVRAM_EF_CHIST_MISS_EVENT_CHECK_SIZE,
        NVRAM_EF_CHIST_MISS_EVENT_CHECK_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP5Y",
        VER(NVRAM_EF_CHIST_MISS_EVENT_CHECK_LID),
        "CHIST Missed Call Recent Event Check ",
        NVRAM_APP_RESERVED
    }
#endif/* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__) || defined(__MMI_VUI_HOMESCREEN__) */

#ifdef __FLAVOR_VENDOR_SDK__
    ,{
		NVRAM_EF_VS_SETTING_LID,
		NVRAM_EF_VS_SETTING_SIZE,
		NVRAM_EF_VS_SETTING_TOTAL,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER,
		"MP5Z",
		VER(NVRAM_EF_VS_SETTING_LID),
		"Vendor use",
		NVRAM_APP_RESERVED
	}
#endif

#ifdef __MMI_IPSEC__
    , {
       NVRAM_EF_IPSEC_POLICY_LID,
       NVRAM_EF_IPSEC_POLICY_SIZE,
       NVRAM_EF_IPSEC_POLICY_TOTAL,
       NVRAM_NORMAL((kal_uint8*)NVRAM_EF_IPSEC_POLICY_DEFAULT),
       NVRAM_ATTR_AVERAGE,
       NVRAM_CATEGORY_USER,
       "MP60",
       VER(NVRAM_EF_IPSEC_POLICY_LID),
       "IPSec MMI Policy Settings",
       NVRAM_APP_RESERVED
       }
    , {
       NVRAM_EF_IPSEC_IKE_LID,
       NVRAM_EF_IPSEC_IKE_SIZE,
       NVRAM_EF_IPSEC_IKE_TOTAL,
       NVRAM_NORMAL((kal_uint8*)NVRAM_EF_IPSEC_IKE_DEFAULT),
       NVRAM_ATTR_AVERAGE,
       NVRAM_CATEGORY_USER,
       "MP61",
       VER(NVRAM_EF_IPSEC_IKE_LID),
       "IPSec MMI Ike Settings",
       NVRAM_APP_RESERVED
       }
#endif /* __MMI_IPSEC__ */
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    , {
       NVRAM_EF_PHB_DEFAULT_NUMBER_LID,
       NVRAM_EF_PHB_DEFAULT_NUMBER_SIZE,
       NVRAM_EF_PHB_DEFAULT_NUMBER_TOTAL,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT), /* need to reset it when add an new contact */
       NVRAM_ATTR_AVERAGE,
       NVRAM_CATEGORY_USER,
       "MP62",
       VER(NVRAM_EF_PHB_DEFAULT_NUMBER_LID),
       "PHB default number",
       NVRAM_APP_RESERVED
      }
#endif /* __MMI_PHB_DEFAULT_NUMBER__ */

#ifdef __MMI_PHB_ICE_CONTACT__
    ,{
        NVRAM_EF_PHB_ICE_CONTACT_LID,
        NVRAM_EF_PHB_ICE_CONTACT_SIZE,
        NVRAM_EF_PHB_ICE_CONTACT_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP63",
        VER(NVRAM_EF_PHB_ICE_CONTACT_LID),
        "PHB ICE contact",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_PHB_ICE_CONTACT__ */

#ifdef __MMI_WAP_PROF__
    ,{
        NVRAM_EF_WAP_PROF_WAP_SIM1_PROFILE_NAMES_LID,
        NVRAM_EF_WAP_PROF_WAP_PROFILE_NAMES_SIZE,
        NVRAM_EF_WAP_PROF_WAP_PROFILE_NAMES_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_PROF_WAP_SIM1_PROFILE_NAMES_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MP64",
        VER(NVRAM_EF_WAP_PROF_WAP_SIM1_PROFILE_NAMES_LID),
        "wap SIM1 profile name",
        NVRAM_APP_RESERVED
    }

    ,{
        NVRAM_EF_WAP_PROF_MMS_SIM1_PROFILE_NAMES_LID,
        NVRAM_EF_WAP_PROF_MMS_PROFILE_NAMES_SIZE,
        NVRAM_EF_WAP_PROF_MMS_PROFILE_NAMES_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_PROF_MMS_SIM1_PROFILE_NAMES_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
		"MP65", 
		VER(NVRAM_EF_WAP_PROF_MMS_SIM1_PROFILE_NAMES_LID), 
		"mms SIM1 profile name",
        NVRAM_APP_RESERVED
    }
#ifdef __MMI_WAP_DUAL_SIM__
	,{
        NVRAM_EF_WAP_PROF_WAP_SIM2_PROFILE_NAMES_LID,
		NVRAM_EF_WAP_PROF_WAP_PROFILE_NAMES_SIZE,
		NVRAM_EF_WAP_PROF_WAP_PROFILE_NAMES_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_PROF_WAP_SIM2_PROFILE_NAMES_DEFAULT),
		NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
		"MP66",
		VER(NVRAM_EF_WAP_PROF_WAP_SIM2_PROFILE_NAMES_LID),
		"wap SIM2 profile name",
		NVRAM_APP_RESERVED
    }
	,{
        NVRAM_EF_WAP_PROF_MMS_SIM2_PROFILE_NAMES_LID,
		NVRAM_EF_WAP_PROF_MMS_PROFILE_NAMES_SIZE,
		NVRAM_EF_WAP_PROF_MMS_PROFILE_NAMES_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_PROF_MMS_SIM2_PROFILE_NAMES_DEFAULT),
		NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
		"MP67", 
		VER(NVRAM_EF_WAP_PROF_MMS_SIM2_PROFILE_NAMES_LID), 
		"mms SIM2 profile name",
		NVRAM_APP_RESERVED
    }
#endif /* __MMI_WAP_DUAL_SIM__ */

#endif /* __MMI_WAP_PROF__ */

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    ,{
        NVRAM_EF_SMS_UD_TMEP_LID,
        NVRAM_SMS_UD_TEMPL_RECORD_SIZE,
        NVRAM_SMS_UD_RECORD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
            NVRAM_CATEGORY_USER,
        "MP68",
        VER(NVRAM_EF_SMS_UD_TMEP_LID),
        "SMS UD TEMP",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_MESSAGES_USERDEFINED_TEMPLATE__*/

#if defined(__SYNCML_SUPPORT__) && defined(__MMI_SYNCML_VIEW_LOG_SUPPORT__)
	,{
	    NVRAM_EF_SYNCML_VIEW_LOG_LID,
	    NVRAM_EF_SYNCML_VIEW_LOG_SIZE,
	    NVRAM_EF_SYNCML_VIEW_LOG_TOTAL,
	    NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
#ifdef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
	    NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
#else
        NVRAM_ATTR_AVERAGE,
#endif /* __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__ */
        NVRAM_CATEGORY_USER,
	    "MP69",
	    VER(NVRAM_EF_SYNCML_VIEW_LOG_LID),
	    "SyncML View Log",
	    NVRAM_APP_RESERVED
	}
#endif /* __MMI_SYNCML_VIEW_LOG_SUPPORT__ */

#ifdef __MMI_BCR__
    , {
       NVRAM_EF_BCR_SETTING_LID,
       NVRAM_EF_BCR_SETTING_SIZE,
       NVRAM_EF_BCR_SETTING_TOTAL,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       NVRAM_CATEGORY_USER,
       "MP6A",
       VER(NVRAM_EF_BCR_SETTING_LID),
       "BCR SETTING",
       NVRAM_APP_RESERVED
       }
#endif /* __MMI_BCR__ */

#ifdef __MMI_AUTO_ANSWER_MACHINE__    
	,{
		NVRAM_EF_ANSWER_MACHINE_SETTING_LID,
		NVRAM_EF_ANSWER_MACHINE_SETTING_SIZE,
		NVRAM_EF_ANSWER_MACHINE_SETTING_TOTAL,
		NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		NVRAM_CATEGORY_USER,
		"MP6B",
		VER(NVRAM_EF_ANSWER_MACHINE_SETTING_LID),
		"Answer Machine",
		NVRAM_APP_RESERVED
	}
#endif/*__MMI_AUTO_ANSWER_MACHINE__*/

#ifdef __MMI_OP12_TOOLBAR__
    ,{
        NVRAM_EF_TOOLBAR_CNTX_LID,
        NVRAM_EF_TOOLBAR_CNTX_SIZE,
        NVRAM_EF_TOOLBAR_CNTX_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP6C",
        VER(NVRAM_EF_TOOLBAR_CNTX_LID),
        "Idle toolbar settings",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_OP12_TOOLBAR__ */
#ifdef __MMI_MEDIA_PLAYER__
	,{
	  NVRAM_EF_MEDPLY_SETTINGS_LID,
	  NVRAM_EF_MEDPLY_SETTINGS_SIZE,
	  NVRAM_EF_MEDPLY_SETTINGS_TOTAL,
	  NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
	  NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
	  NVRAM_CATEGORY_USER,
	  "MP6D",
	  VER(NVRAM_EF_MEDPLY_SETTINGS_LID),
	  "MEDIA SETTINGS ",
	  NVRAM_APP_RESERVED
	 }
#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_SUPPORT__)
	,{
	  NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID,
	  NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_SIZE,
	  NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL,
	  NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MEDPLY_NETWORK_PROFILE_DEFAULT),
	  NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
      NVRAM_CATEGORY_USER,
      "MP6E",
      VER(NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID),
      "MEDIA NETWORK PROFILE",
      NVRAM_APP_RESERVED
     }
#endif /* (__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_SUPPORT__)*/
#if defined(__MMI_MEDIA_PLAYER_STREAM__)
#ifdef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__
	,{
	  NVRAM_EF_MEDPLY_HISTORY_URL_LID,
	  NVRAM_EF_MEDPLY_HISTORY_URL_SIZE,
	  NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL,
	  NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
	  NVRAM_ATTR_AVERAGE,
      NVRAM_CATEGORY_USER,
      "MP6F",
      VER(NVRAM_EF_MEDPLY_HISTORY_URL_LID),
      "MEDIA PLAYER HISTORY",
      NVRAM_APP_RESERVED
     }
#endif  /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__ */
#endif
    ,{
       NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID,
       NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_SIZE,
       NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_TOTAL,
       NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       NVRAM_CATEGORY_USER,
       "MP6G",
       VER(NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID),
       "MEDPLY LAST PLAYLIST PATH",
       NVRAM_APP_RESERVED
     }
#endif

#ifdef WAP_SUPPORT
	,{
        NVRAM_EF_PUSH_GEN_SETTING_LID,
		NVRAM_EF_PUSH_GEN_SETTING_SIZE,
		NVRAM_EF_PUSH_GEN_SETTING_TOTAL,
		NVRAM_NORMAL((kal_uint8*)NVRAM_EF_PUSH_GEN_SETTING_DEFAULT),
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		NVRAM_CATEGORY_USER,
		"MP6I", 
		VER(NVRAM_EF_PUSH_GEN_SETTING_LID), 
		"wap push gen settings",
		NVRAM_APP_Q05A_BROWSER
    }
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
	,{
        NVRAM_EF_PUSH_BLACK_LIST_LID,
		NVRAM_EF_PUSH_BLACK_LIST_SIZE,
		NVRAM_EF_PUSH_BLACK_LIST_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PUSH_BLACK_LIST_DEFAULT),
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_CUSTPACK,
		"MP6J",
		VER(NVRAM_EF_PUSH_BLACK_LIST_LID), 
		"wap push black list",
		NVRAM_APP_RESERVED
    }
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

#ifdef __MMI_WAP_PUSH_WHITE_LIST__

	,{
        NVRAM_EF_PUSH_WHITE_LIST_LID,
		NVRAM_EF_PUSH_WHITE_LIST_SIZE,
		NVRAM_EF_PUSH_WHITE_LIST_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PUSH_WHITE_LIST_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_CUSTPACK,
		"MP6K",
		VER(NVRAM_EF_PUSH_WHITE_LIST_LID), 
		"wap push white list",
		NVRAM_APP_RESERVED
    }
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
#endif /* WAP_SUPPORT */

#if defined(PLUTO_MMI) && !defined(__MMI_EM_INET_APP_SLIM__)
    /* Internet Application */
    ,{
        NVRAM_EF_INET_CUSTPACK_LID,
        NVRAM_EF_INET_CUSTPACK_SIZE,
        NVRAM_EF_INET_CUSTPACK_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_INET_CUSTPACK_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        "MP6L",
        VER(NVRAM_EF_INET_CUSTPACK_LID),
        "user agent custpack",
        NVRAM_APP_RESERVED
     }
#endif

#ifdef __MMI_IPSEC__
    , {
       NVRAM_EF_IPSEC_PROFILE_NAME_LID,
       NVRAM_EF_IPSEC_PROFILE_NAME_SIZE,
       NVRAM_EF_IPSEC_PROFILE_NAME_TOTAL,
       NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
       NVRAM_ATTR_AVERAGE,
       NVRAM_CATEGORY_USER,
       "MP6M",
       VER(NVRAM_EF_IPSEC_PROFILE_NAME_LID),
       "IPSec Profile name",
       NVRAM_APP_RESERVED
       }
#endif /* __MMI_IPSEC__ */
    
#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    ,{
        NVRAM_EF_PICTBRIDGE_LID,
        NVRAM_EF_PICTBRIDGE_SIZE,
        NVRAM_EF_PICTBRIDGE_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP6N",
        VER(NVRAM_EF_PICTBRIDGE_LID),
        "pictbridge print setting",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_PICT_BRIDGE_SUPPORT__*/
#ifdef __MMI_SYNCML_DEVICE_SYNC__ 
	,{
		NVRAM_EF_SYNCML_DEV_SETTING_LID,
		NVRAM_EF_SYNCML_DEV_SETTING_SIZE,
		NVRAM_EF_SYNCML_DEV_SETTING_TOTAL,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER,
		"MP6O",
		VER(NVRAM_EF_SYNCML_DEV_SETTING_LID),
		"SyncML Dev Setting",
		NVRAM_APP_RESERVED
	}
	,{
		NVRAM_EF_SYNCML_DEV_ACCOUNT_LID,
		NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE,
		NVRAM_EF_SYNCML_DEV_ACCOUNT_TOTAL,
		NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER,
		"MP6P",
		VER(NVRAM_EF_SYNCML_DEV_ACCOUNT_LID),
		"SyncML Dev account ",
		NVRAM_APP_RESERVED
	}
#ifdef __MMI_SYNCML_VIEW_LOG_SUPPORT__
	,{
	    NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID,
	    NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE,
	    NVRAM_EF_SYNCML_DEV_SYNC_LOG_TOTAL,
	    NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
	    NVRAM_ATTR_AVERAGE,
	    NVRAM_CATEGORY_USER,
	    "MP6Q",
	    VER(NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID),
	    "SyncML dev View Log",
	    NVRAM_APP_RESERVED
	}
#endif /* __MMI_SYNCML_VIEW_LOG_SUPPORT__ */
#endif/* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef WAP_SUPPORT
    ,{
        NVRAM_EF_WAP_BOOKMARK_LIST_LID,
        NVRAM_EF_WAP_BOOKMARK_LIST_SIZE,
        NVRAM_EF_WAP_BOOKMARK_LIST_TOTAL_RECORDS,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_BOOKMARK_LIST_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_CUSTPACK,
        "MP6R",
        VER(NVRAM_EF_WAP_BOOKMARK_LIST_LID), 
        "wap bookmarks list",
        NVRAM_APP_RESERVED
    }
#endif /* WAP_SUPPORT */

#ifdef __MMI_CM_WHITE_LIST__
    ,{
        NVRAM_EF_WHITE_LIST_LID,
        NVRAM_EF_WHITE_LIST_SIZE,
        NVRAM_EF_WHITE_LIST_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP6S",
        VER(NVRAM_EF_WHITE_LIST_LID),
        "White List",
        NVRAM_APP_RESERVED
    }
#endif/*__MMI_CM_WHITE_LIST__*/
#ifdef __SMART_PHONE_MODEM__
    ,{
        NVRAM_EF_SIM_LOCK_LID,
        NVRAM_EF_SIM_LOCK_SIZE,
        NVRAM_EF_SIM_LOCK_TOTAL,
        NVRAM_SECUPACK(&NVRAM_EF_SML_DEFAULT),
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        NVRAM_CATEGORY_SECUPACK | NVRAM_CATEGORY_IMPORTANT,
        "MP6T",
        VER(NVRAM_EF_SIM_LOCK_LID),
        "SIM Lock for smartphone",
        NVRAM_APP_RESERVED
    }
#endif

#ifdef __MMI_FM_RADIO_SCHEDULER__
    ,{
        NVRAM_EF_FMRDO_SCHEDULER_LID,
        NVRAM_EF_FMRDO_SCHEDULER_SIZE,
        NVRAM_EF_FMRDO_SCHEDULER_TOTAL,
        NVRAM_NORMAL((kal_uint8 const *)NVRAM_FMRDO_SCHEDULER_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP6U",
        VER(NVRAM_EF_FMRDO_SCHEDULER_LID),
        "FM Scheduler",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_FM_RADIO_SCHEDULER__ */

#ifdef __MMI_BCR__
    , {
       NVRAM_EF_BCR_FIELD_SET_LID,
       NVRAM_EF_BCR_FIELD_SET_SIZE,
       NVRAM_EF_BCR_FIELD_SET_TOTAL,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       NVRAM_CATEGORY_USER,
       "MP6V",
       VER(NVRAM_EF_BCR_FIELD_SET_LID),
       "BCR SETTING",
       NVRAM_APP_RESERVED
       }
#endif /* __MMI_BCR__ */

#ifdef __BIP_PULL_SUPPORT__
    ,{
        NVRAM_EF_BT_BIP_SET_FOLDER_LID,
        NVRAM_EF_BT_BIP_SETTING_SIZE,
        NVRAM_EF_BT_BIP_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_BT_BIP_SETTING_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP6W",
        VER(NVRAM_EF_BT_BIP_SET_FOLDER_LID),
        "BT_BIP_SET_FOLDER",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_BIP_SUPPORT__ */

#if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__TCM_EXT_CALL_HISTORY_SUPPORT__)
    ,{
        NVRAM_EF_TCM_EXT_CALL_HISTORY_LID,
        NVRAM_EF_TCM_EXT_CALL_HISTORY_SIZE,
        NVRAM_EF_TCM_EXT_CALL_HISTORY_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
    	NVRAM_CATEGORY_USER,
        "MP6X",
        VER(NVRAM_EF_TCM_EXT_CALL_HISTORY_LID),
        "TCM External PS Call History",
        NVRAM_APP_RESERVED
    }
#endif // ~ #if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__TCM_EXT_CALL_HISTORY_SUPPORT__)
#ifdef __MMI_MEDIA_PLAYER_STREAM__
    ,{
        NVRAM_EF_MEDPLY_PREDEFINED_URL_LID,
        NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_SIZE,
        NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP6Y",
        VER(NVRAM_EF_MEDPLY_PREDEFINED_URL_LID),
        "MEDIA PLAYER VIDEO PREDEFINED URL",
        NVRAM_APP_RESERVED
    }
#endif

#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))
#if (defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT))
    ,{
        NVRAM_EF_CAMERA_PARA1_MAIN_LID,
        NVRAM_EF_CAMERA_PARA1_MAIN_SIZE,
        NVRAM_EF_CAMERA_PARA1_MAIN_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_PARA_MAIN_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP70",
        VER(NVRAM_EF_CAMERA_PARA1_MAIN_LID),
        "Camera Para main",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_PARA2_MAIN_LID,
        NVRAM_EF_CAMERA_PARA2_MAIN_SIZE,
        NVRAM_EF_CAMERA_PARA2_MAIN_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_3A_MAIN_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP71",
        VER(NVRAM_EF_CAMERA_PARA2_MAIN_LID),
        "Camera 3a main",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT1_MAIN_LID,
        NVRAM_EF_CAMERA_DEFECT1_MAIN_SIZE,
        NVRAM_EF_CAMERA_DEFECT1_MAIN_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT1_MAIN_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP72",
        VER(NVRAM_EF_CAMERA_DEFECT1_MAIN_LID),
        "Camera Defect1 main",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT2_MAIN_LID,
        NVRAM_EF_CAMERA_DEFECT2_MAIN_SIZE,
        NVRAM_EF_CAMERA_DEFECT2_MAIN_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT2_MAIN_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP73",
        VER(NVRAM_EF_CAMERA_DEFECT2_MAIN_LID),
        "Camera Defect2 main",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_SHADING1_MAIN_LID,
        NVRAM_EF_CAMERA_SHADING1_MAIN_SIZE,
        NVRAM_EF_CAMERA_SHADING1_MAIN_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING1_MAIN_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP74",
        VER(NVRAM_EF_CAMERA_SHADING1_MAIN_LID),
        "Camera Shading1 main",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_SHADING2_MAIN_LID,
        NVRAM_EF_CAMERA_SHADING2_MAIN_SIZE,
        NVRAM_EF_CAMERA_SHADING2_MAIN_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING2_MAIN_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP75",
        VER(NVRAM_EF_CAMERA_SHADING2_MAIN_LID),
        "Camera Shading2 main",
        NVRAM_APP_RESERVED
    }

#if (defined(CMOS_SENSOR_SUB)) /*keep this sequence*/
    ,{
        NVRAM_EF_CAMERA_PARA1_SUB_LID,
        NVRAM_EF_CAMERA_PARA1_SUB_SIZE,
        NVRAM_EF_CAMERA_PARA1_SUB_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_PARA_SUB_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP76",
        VER(NVRAM_EF_CAMERA_PARA1_SUB_LID),
        "Camera Para sub",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_PARA2_SUB_LID,
        NVRAM_EF_CAMERA_PARA2_SUB_SIZE,
        NVRAM_EF_CAMERA_PARA2_SUB_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_3A_SUB_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP77",
        VER(NVRAM_EF_CAMERA_PARA2_SUB_LID),
        "Camera 3a sub",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT1_SUB_LID,
        NVRAM_EF_CAMERA_DEFECT1_SUB_SIZE,
        NVRAM_EF_CAMERA_DEFECT1_SUB_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT1_SUB_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP78",
        VER(NVRAM_EF_CAMERA_DEFECT1_SUB_LID),
        "Camera Defect1 sub",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT2_SUB_LID,
        NVRAM_EF_CAMERA_DEFECT2_SUB_SIZE,
        NVRAM_EF_CAMERA_DEFECT2_SUB_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT2_SUB_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP79",
        VER(NVRAM_EF_CAMERA_DEFECT2_SUB_LID),
        "Camera Defect2 sub",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_SHADING1_SUB_LID,
        NVRAM_EF_CAMERA_SHADING1_SUB_SIZE,
        NVRAM_EF_CAMERA_SHADING1_SUB_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING1_SUB_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7A",
        VER(NVRAM_EF_CAMERA_SHADING1_SUB_LID),
        "Camera Shading1 sub",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_SHADING2_SUB_LID,
        NVRAM_EF_CAMERA_SHADING2_SUB_SIZE,
        NVRAM_EF_CAMERA_SHADING2_SUB_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING2_SUB_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7B",
        VER(NVRAM_EF_CAMERA_SHADING2_SUB_LID),
        "Camera Shading2 sub",
        NVRAM_APP_RESERVED
    }
#endif

#if (defined(CMOS_SENSOR_BAK1)) /*keep this sequence*/
    ,{
        NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_SIZE,
        NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_PARA_MAIN_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7C",
        VER(NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID),
        "Camera Para bak1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_SIZE,
        NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_3A_MAIN_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7D",
        VER(NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID),
        "Camera 3a bak1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_SIZE,
        NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT1_MAIN_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7E",
        VER(NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID),
        "Camera Defect1 bak1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_SIZE,
        NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT2_MAIN_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7F",
        VER(NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID),
        "Camera Defect2 bak1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_SIZE,
        NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING1_MAIN_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7G",
        VER(NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID),
        "Camera Shading1 bak1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_SIZE,
        NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING2_MAIN_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7H",
        VER(NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID),
        "Camera Shading2 bak1",
        NVRAM_APP_RESERVED
    }
#endif

#if (defined(CMOS_SENSOR_SUB_BAK1)) /*keep this sequence*/
    ,{
        NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_PARA1_SUB_BAK1_SIZE,
        NVRAM_EF_CAMERA_PARA1_SUB_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_PARA_SUB_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7I",
        VER(NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID),
        "Camera Para sub bak1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_PARA2_SUB_BAK1_SIZE,
        NVRAM_EF_CAMERA_PARA2_SUB_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_3A_SUB_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7J",
        VER(NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID),
        "Camera 3a sub bak1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_SIZE,
        NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT1_SUB_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7K",
        VER(NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID),
        "Camera Defect1 sub bak1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_SIZE,
        NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_DEFECT2_SUB_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7L",
        VER(NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID),
        "Camera Defect2 sub bak1",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_SIZE,
        NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING1_SUB_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7M",
        VER(NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID),
        "Camera Shading1 sub bak1",
        NVRAM_APP_RESERVED
    }

#endif    
#endif/* defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT) */ 
#endif/* defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES) */

#if defined (ISP_SUPPORT)
    ,{
        NVRAM_EF_CAMERA_MAIN_SENSOR_ID_LID,
        NVRAM_EF_CAMERA_MAIN_SENSOR_ID_SIZE,
        NVRAM_EF_CAMERA_MAIN_SENSOR_ID_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP7N",
        VER(NVRAM_EF_CAMERA_MAIN_SENSOR_ID_LID),
        "Camera Main sensor id",
        NVRAM_APP_RESERVED
    }
#if defined(DUAL_CAMERA_SUPPORT)
    ,{
        NVRAM_EF_CAMERA_SUB_SENSOR_ID_LID,
        NVRAM_EF_CAMERA_SUB_SENSOR_ID_SIZE,
        NVRAM_EF_CAMERA_SUB_SENSOR_ID_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP7O",
        VER(NVRAM_EF_CAMERA_SUB_SENSOR_ID_LID),
        "Camera Sub sensor id",
        NVRAM_APP_RESERVED
    }
#endif /* defined(DUAL_CAMERA_SUPPORT) */
#endif /* defined (ISP_SUPPORT) */

#ifdef __MMI_CAMCORDER__
    ,{
        NVRAM_EF_CAMCO_APP_INFO_LID,
        NVRAM_EF_CAMCO_APP_INFO_SIZE,
        NVRAM_EF_CAMCO_APP_INFO_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP7P",
        VER(NVRAM_EF_CAMCO_APP_INFO_LID),
        "CAMCO APP INFO",
        NVRAM_APP_RESERVED
    }
#ifdef DUAL_CAMERA_SUPPORT
    ,{
        NVRAM_EF_CAMCO_SUB_SETTING_LID,
        NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
        NVRAM_EF_CAMCO_SUB_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP7Q",
        VER(NVRAM_EF_CAMCO_SUB_SETTING_LID),
        "CAMCO SUB SETTING",
        NVRAM_APP_CAMCODER
    }
    ,{
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_LID,
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_SIZE,
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP7R",
        VER(NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_LID),
        "CAMCO SUB SCENE SEL SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* DUAL_CAMERA_SUPPORT */
#endif /* __MMI_CAMCORDER__ */
#ifdef __EMAIL__
    /* Email Data Account */
    ,{
        NVRAM_EF_EMAIL_DATA_ACCOUNT_LID,
        NVRAM_EF_EMAIL_DATA_ACCOUNT_SIZE,
        NVRAM_EF_EMAIL_DATA_ACCOUNT_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MP7S",
        VER(NVRAM_EF_EMAIL_DATA_ACCOUNT_LID),
        "Email Data Account",
        NVRAM_APP_RESERVED
    }
#endif /* __EMAIL__ */
#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6235_SERIES) && defined(BACKUP_SENSOR_SUPPORT))
    ,{
        NVRAM_EF_CAMERA_PARA_MAIN_LID,
        NVRAM_EF_CAMERA_PARA_MAIN_SIZE,
        NVRAM_EF_CAMERA_PARA_MAIN_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_PARA_MAIN_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7T",
        VER(NVRAM_EF_CAMERA_PARA_MAIN_LID),
        "Camera Para 6235 main",
        NVRAM_APP_RESERVED
    }
    ,{
        NVRAM_EF_CAMERA_PARA_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_PARA_MAIN_BAK1_SIZE,
        NVRAM_EF_CAMERA_PARA_MAIN_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_PARA_MAIN_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7U",
        VER(NVRAM_EF_CAMERA_PARA_MAIN_BAK1_LID),
        "Camera Para 6235 main bak1 ",
        NVRAM_APP_RESERVED
    }
#endif/* defined(ISP_SUPPORT) && defined(DRV_ISP_6235_SERIES) && defined(BACKUP_SENSOR_SUPPORT) */

#ifdef __SYNCML_SUPPORT__   
    ,{
        NVRAM_EF_SYNCML_ACCOUNT_LID,
        NVRAM_EF_SYNCML_ACCOUNT_SIZE,
        NVRAM_EF_SYNCML_ACCOUNT_TOTAL,        
#ifdef CUSTOM_SYNCML_ACCOUNT_DEFAULT
        NVRAM_NORMAL((kal_uint8 *) NVRAM_EF_SYNCML_ACCOUNT_DEFAULT),
    #ifndef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_FACTORY_RESET,
    #else
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
    #endif /* __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__ */
        NVRAM_CATEGORY_USER,
#else /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */
    #ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
        NVRAM_NORMAL((kal_uint8 *) NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_PC_SYNC),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
    #else /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),        
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,  
    #endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
   
#endif /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */     
        "MP7V",
        VER(NVRAM_EF_SYNCML_ACCOUNT_LID),
        "SyncML account",
        NVRAM_APP_RESERVED
    }
#endif /* __SYNCML_SUPPORT__ */
/* Vogins Start */
#ifdef __VRE_V2X__
    ,{
    	NVRAM_EF_VRE_APP_BAN_LIST_LID,
    	NVRAM_EF_VRE_APP_BAN_LIST_SIZE,
    	NVRAM_EF_VRE_APP_BAN_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7W", 
        VER(NVRAM_EF_VRE_APP_BAN_LIST_LID), 
        "VRE BAN",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_PKEY_LIST_LID,
    	NVRAM_EF_VRE_PKEY_LIST_SIZE,
    	NVRAM_EF_VRE_PKEY_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PKEY_DEFAULT),
    	NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MP7X",
        VER(NVRAM_EF_VRE_PKEY_LIST_LID), 
        "VRE PKEY",
        NVRAM_APP_RESERVED 
    }
    ,{
    	NVRAM_EF_VRE_SYM_ENTRY_LIST_LID,
    	NVRAM_EF_VRE_SYM_ENTRY_LIST_SIZE,
    	NVRAM_EF_VRE_SYM_ENTRY_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_SYM_ENTRY_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7Y", 
        VER(NVRAM_EF_VRE_SYM_ENTRY_LIST_LID), 
        "VRE SYMENTRY",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_SYM_CONF_LIST_LID,
    	NVRAM_EF_VRE_SYM_CONF_LIST_SIZE,
    	NVRAM_EF_VRE_SYM_CONF_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP7Z", 
        VER(NVRAM_EF_VRE_SYM_CONF_LIST_LID), 
        "VRE SYSCONF",
        NVRAM_APP_RESERVED 
    }
    ,{
    	NVRAM_EF_VRE_PAY_CHANNEL_ORG_LIST_LID,
    	NVRAM_EF_VRE_PAY_CHANNEL_ORG_LIST_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_ORG_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP80", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_ORG_LIST_LID), 
        "VRE PAYORG",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_LID,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PAY_CHANNEL_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP81", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_LIST_LID), 
        "VRE PAYCHAN",
        NVRAM_APP_RESERVED
    }

    ,{
    	NVRAM_EF_VRE_APP_STATE_LIST_LID,
    	NVRAM_EF_VRE_APP_STATE_LIST_SIZE,
    	NVRAM_EF_VRE_APP_STATE_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER, 
        "MP82", 
        VER(NVRAM_EF_VRE_APP_STATE_LIST_LID), 
        "VRE APP",
        NVRAM_APP_RESERVED
    }
#endif
/* Vogins End */

     #ifdef __MMI_ECOMPASS__
    , {
       NVRAM_EF_ECOMPASS_LID,
       NVRAM_EF_ECOMPASS_SIZE,
       NVRAM_EF_ECOMPASS_TOTAL,
       NVRAM_NORMAL((kal_uint8 const *)NVRAM_EF_ECOMPASS_DEFAULT),
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
       NVRAM_CATEGORY_USER,
       "MP83",
       VER(NVRAM_EF_ECOMPASS_LID),
       "Ecompass",
        NVRAM_APP_RESERVED
    }
   #endif /* __MMI_ECOMPASS__ */ 

#ifdef __MMI_NOTE_APP__
    , {
		NVRAM_EF_NOTE_APP_LID,
		NVRAM_EF_NOTE_NODE_STRUCT_SIZE,
		NVRAM_EF_NOTE_LIST_TOTAL,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER,
		"MP84",
		VER(NVRAM_EF_NOTE_APP_LID),
		"Note Application",
		NVRAM_APP_RESERVED
	}
#endif /* __MMI_NOTE_APP__ */

#ifdef __MMI_SEARCH_WEB__
    ,{
        NVRAM_EF_SEARCH_WEB_HISTORY_LID,
        NVRAM_EF_SEARCH_WEB_HISTORY_SIZE,
        NVRAM_EF_SEARCH_WEB_HISTORY_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP85",
        VER(NVRAM_EF_SEARCH_WEB_HISTORY_LID),
        "MMI Search history",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_SEARCH_WEB__ */

#ifdef __MMI_SEARCH_WEB_BAIDU__
    ,{
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID,
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_SIZE,
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_CALIBRAT, /* Keep even SW version changes */
        "MP86",
        VER(NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID),
        "Baidu UID",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_SEARCH_WEB__ */

#ifdef __MMI_VUI_HOMESCREEN__
    ,{
        NVRAM_EF_VENUS_HS_CNTX_LID,
        NVRAM_EF_VENUS_HS_CNTX_SIZE,
        NVRAM_EF_VENUS_HS_CNTX_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP87",
        VER(NVRAM_EF_VENUS_HS_CNTX_LID),
        "Venus home screen settings",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_VUI_HOMESCREEN__ */

#ifdef __MMI_VUI_HOMESCREEN_MEMO__
    ,{
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_LID,
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_SIZE,
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP88",
        VER(NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_LID),
        "Venus home screen Memo widget data",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_VUI_HOMESCREEN_MEMO__ */

#ifdef __MMI_VUI_MAINMENU__
    ,{
        NVRAM_EF_VENUS_MM_LID,
        NVRAM_EF_VENUS_MM_SIZE,
        NVRAM_EF_VENUS_MM_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_VENUS_MM_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP89",
        VER(NVRAM_EF_VENUS_MM_LID),
        "Venus main menu settings",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_VUI_MAINMENU__*/

#ifdef __MMI_VUI_HOMESCREEN_PHOTO__
    ,{
        NVRAM_EF_VENUS_PHOTO_FILEPATH_LID,
        NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE,
        NVRAM_EF_VENUS_PHOTO_FILEPATH_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP8A",
        VER(NVRAM_EF_VENUS_PHOTO_FILEPATH_LID),
        "Venus Photo file path",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_VUI_HOMESCREEN_PHOTO__*/

#ifdef __MMI_ZAKAT_CALCULATOR__
    ,{
        NVRAM_EF_ZAKAT_CALCULATOR_LID,
        NVRAM_EF_ZAKAT_CALCULATOR_SIZE,
        NVRAM_EF_ZAKAT_CALCULATOR_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP8B",
        VER(NVRAM_EF_ZAKAT_CALCULATOR_LID),
        "zakat calculator\0",
        NVRAM_RESERVED_VALUE
    }
#endif /* __MMI_ZAKAT_CALCULATOR__*/
/* Vogins Start */
#ifdef __VRE_V2X__
	  ,{
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST2_LID,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PAY_CHANNEL_DEFAULT2),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP8C", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_LIST2_LID), 
        "VRE PAYCHAN2",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST3_LID,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PAY_CHANNEL_DEFAULT3),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP8D", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_LIST3_LID), 
        "VRE PAYCHAN3",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST4_LID, 
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PAY_CHANNEL_DEFAULT4),	
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER, 
        "MP8E", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_LIST4_LID), 
        "VRE PAYCHAN4",
        NVRAM_APP_RESERVED 
    } 
    ,{
    	NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_LID,
    	NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_SZIE,
    	NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP8F", 
        VER(NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_LID), 
        "VRE APP",
        NVRAM_APP_RESERVED
    }
#endif
/* Vogins End */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#ifdef __TCPIP__
    , {
		NVRAM_EF_CBM_CALL_HISTORY_LID,
		NVRAM_EF_TCP_LAST_TOTAL_SIZE,
		NVRAM_EF_TCP_LAST_TOTAL_TOTAL,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER,
		"MP90",
		VER(NVRAM_EF_CBM_CALL_HISTORY_LID),
		"CBM call history",
		NVRAM_APP_RESERVED
	}
#endif /* __TCPIP__ */
#endif

#ifdef __MMI_EM_MISC_DCD__
    , {
        NVRAM_EF_DCD_EM_PARAM_DATA_LID,
        NVRAM_EF_DCD_EM_PARAM_DATA_SIZE,
        NVRAM_EF_DCD_EM_PARAM_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_DCD_EM_PARAM_DATA_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP91",
        VER(NVRAM_EF_DCD_EM_PARAM_DATA_LID),
        "DCD EM Param",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_EM_MISC_DCD__ */

#ifdef __APP_STATIC_QOS_PROFILE_SUPPORT__
    ,{
        NVRAM_EF_ABM_PS_QOS_PROFILE_LID,
        NVRAM_EF_ABM_PS_QOS_PROFILE_SIZE,
        NVRAM_EF_ABM_PS_QOS_PROFILE_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_ABM_PS_QOS_PROFILE_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_CUSTPACK,
        "MP93",
        VER(NVRAM_EF_ABM_PS_QOS_PROFILE_LID),
        "ABM PS QOS PROFILE\0",
        NVRAM_APP_RESERVED
    }
#endif/*__APP_STATIC_QOS_PROFILE_SUPPORT__ */

#ifdef __MMI_AZAAN_ALARM__
    ,{
        NVRAM_EF_AZAAN_ALARM_LID,
        NVRAM_AZAAN_ALARM_SIZE,
        NVRAM_AZAAN_ALARM_TOTAL,
        NVRAM_NORMAL((kal_uint8 const *)NVRAM_EF_AZAAN_ALARM_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP94",
        VER(NVRAM_EF_AZAAN_ALARM_LID),
        "Azaan alarm data",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_AZAAN_ALARM__ */

#ifdef __AGPS_CONTROL_PLANE__
    , {
       NVRAM_EF_AGPS_MTLR_LID,
       NVRAM_EF_AGPS_MTLR_SIZE,
       NVRAM_EF_AGPS_MTLR_TOTAL,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       NVRAM_CATEGORY_USER,
       "MP95",
       VER(NVRAM_EF_AGPS_MTLR_LID),
       "AGPS MTLR",
       NVRAM_APP_RESERVED
       }

    , {
       NVRAM_EF_AGPS_SEND_LOCATION_LID,
       NVRAM_EF_AGPS_SEND_LOCATION_SIZE,
       NVRAM_EF_AGPS_SEND_LOCATION_TOTAL,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
       "MP96",
       VER(NVRAM_EF_AGPS_SEND_LOCATION_LID),
       "AGPS SEND LOCATION",
       NVRAM_APP_RESERVED
       }
    
    , {
       NVRAM_EF_AGPS_CP_CONFIG_LID,
       NVRAM_EF_AGPS_CP_CONFIG_SIZE,
       NVRAM_EF_AGPS_CP_CONFIG_TOTAL,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
       "MP97",
       VER(NVRAM_EF_AGPS_CP_CONFIG_LID),
       "AGPS CP CONFIG",
       NVRAM_APP_RESERVED
       }
#endif

#if defined(__AGPS_USER_PLANE__)
    , {
        NVRAM_EF_AGPS_CURRENT_PROFILE_LID,
        NVRAM_EF_AGPS_CURRENT_PROFILE_SIZE,
        NVRAM_EF_AGPS_CURRENT_PROFILE_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP98",
        VER(NVRAM_EF_AGPS_CURRENT_PROFILE_LID),
        "AGPS CURRENT PROFILE\0",
        NVRAM_RESERVED_VALUE
    }

    , {
        NVRAM_EF_AGPS_EM_SETTING_LID,
        NVRAM_EF_AGPS_EM_SETTING_SIZE,
        NVRAM_EF_AGPS_EM_SETTING_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP99",
        VER(NVRAM_EF_AGPS_EM_SETTING_LID),
        "AGPS ENGINEER MODE SETTING",
        NVRAM_APP_RESERVED
    }

    , {
        NVRAM_EF_AGPS_PROFILE_LID,
        NVRAM_EF_AGPS_PROFILE_SIZE,
        NVRAM_EF_AGPS_PROFILE_TOTAL,
        NVRAM_NORMAL((kal_uint8*)NVRAM_EF_AGPS_PROFILE_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MP9A",
        VER(NVRAM_EF_AGPS_PROFILE_LID),
        "AGPS PROFILE",
        NVRAM_APP_RESERVED
    }

    , {
        NVRAM_EF_AGPS_EM_STATUS_LID,
        NVRAM_EF_AGPS_EM_STATUS_SIZE,
        NVRAM_EF_AGPS_EM_STATUS_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP9B",
        VER(NVRAM_EF_AGPS_EM_STATUS_LID),
        "AGPS ENGINEER MODE STATUS",
        NVRAM_APP_RESERVED
    }
#endif /* __AGPS_USER_PLANE__ */

    
#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES)) /*Number Confliction and Remove here*/
#if (defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT))
#if (defined(CMOS_SENSOR_SUB_BAK1))
    ,{
        NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_SIZE,
        NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_TOTAL,
        NVRAM_NORMAL((void*)&CAMERA_SHADING2_SUB_BAK1_DEFAULT_VALUE),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MP9C",
        VER(NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID),
        "Camera Shading2 sub bak1",
        NVRAM_APP_RESERVED
    }
#endif    
#endif/* defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT) */ 
#endif/* defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES) */  

#ifdef __MMI_IMAGE_VIEWER_EX__
    ,{
        NVRAM_EF_IVEX_SETTINGS_LID,
        NVRAM_EF_IVEX_SETTINGS_SIZE,
        NVRAM_EF_IVEX_SETTINGS_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MP9D",
        VER(NVRAM_EF_IVEX_SETTINGS_LID),
        "ImageViewerEX Setting",
        NVRAM_APP_RESERVED
    }
#endif/* __MMI_IMAGE_VIEWER_EX__ */	

#ifdef   __MMI_WAP_PROF__ 
#if defined(__MMI_WAP_DUAL_SIM__ ) && defined(__MMI_WLAN_FEATURES__)
    ,{
        NVRAM_EF_WAP_PROF_WAP_WLAN_PROFILE_NAMES_LID,
		NVRAM_EF_WAP_PROF_WAP_PROFILE_NAMES_SIZE,
		NVRAM_EF_WAP_PROF_WAP_PROFILE_NAMES_TOTAL,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_PROF_WAP_WLAN_PROFILE_NAMES_DEFAULT),
		NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
		"MP9E",
		VER(NVRAM_EF_WAP_PROF_WAP_WLAN_PROFILE_NAMES_LID),
		"wap WLAN profile name",
		NVRAM_APP_RESERVED
    }
#endif /* (__MMI_WAP_DUAL_SIM__ ) && defined(__MMI_WLAN_FEATURES__)*/
#endif  /* __MMI_WAP_PROF__ */

#ifdef __MMI_TODOLIST__
     ,{
        NVRAM_EF_TDL_EVENT_LID,
        NVRAM_EF_TDL_EVENT_SIZE,
        NVRAM_EF_TDL_EVENT_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MP9F",
        VER(NVRAM_EF_TDL_EVENT_LID),
        "Event in calendar",
        NVRAM_APP_RESERVED
     }
     ,{
        NVRAM_EF_TDL_TASK_LID,
        NVRAM_EF_TDL_TASK_SIZE,
        NVRAM_EF_TDL_TASK_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MPA0",
        VER(NVRAM_EF_TDL_TASK_LID),
        "Task in todolist",
        NVRAM_APP_RESERVED 
     }
#endif /* __MMI_TODOLIST__ */

#ifdef __DM_SCOMO_SUPPORT__
,{
    NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
    NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_SIZE,
    NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_TOTAL,
    NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    NVRAM_ATTR_AVERAGE,
    NVRAM_CATEGORY_USER,
    "MPA1",
    VER(NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID),
    "DM app SCOMO report info",
    NVRAM_APP_RESERVED
}
#endif /* __DM_SCOMO_SUPPORT__ */
   ,{
        NVRAM_EF_CAL_FLAG_LID,
        NVRAM_EF_CAL_FLAG_SIZE,
        NVRAM_EF_CAL_FLAG_TOTAL,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_MULTIPLE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        "MPA2",
        VER(NVRAM_EF_CAL_FLAG_LID),
        "Calibration Flag\0",
        NVRAM_RESERVED_VALUE
    }

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    ,{
        NVRAM_EF_SRV_SMS_PDU_LID,
        NVRAM_EF_SRV_SMS_PDU_SIZE,
        NVRAM_EF_SRV_SMS_PDU_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_SRV_SMS_PDU_DEFAULT),
        NVRAM_ATTR_MULTIREC_READ,
        NVRAM_CATEGORY_USER,
        "MPA3",
        VER(NVRAM_EF_SRV_SMS_PDU_LID),
        "SRV SMS PDU",
        NVRAM_APP_RESERVED
    }
#ifdef __SRV_SMS_RECENT_EVENT__
    ,{
        NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID,
        NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_SIZE,
        NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPA4",
        VER(NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID),
        "SMS Service Recent Event bitmap",
        NVRAM_APP_RESERVED
    }
#endif /* __SRV_SMS_RECENT_EVENT__ */
#endif
#if defined(__AGPS_USER_PLANE__)
    , {
        NVRAM_EF_AGPS_PAYLOAD_LID,
        NVRAM_EF_AGPS_PAYLOAD_SIZE,
        NVRAM_EF_AGPS_PAYLOAD_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MPA5",
        VER(NVRAM_EF_AGPS_PAYLOAD_LID),
        "AGPS ENGINEER MODE PAYLOAD",
        NVRAM_APP_RESERVED
    }
#endif /* __AGPS_USER_PLANE__ */
#ifdef __OCSP_SUPPORT__
    ,{
      NVRAM_EF_CERTMAN_OCSP_URL_LID,
      NVRAM_EF_CERTMAN_OCSP_URL_SIZE,
      NVRAM_EF_CERTMAN_OCSP_URL_TOTAL,
      NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
      NVRAM_ATTR_AVERAGE,
      NVRAM_CATEGORY_USER,
      "MPA6",
      VER(NVRAM_EF_CERTMAN_OCSP_URL_LID),
      "certificate status server\0",
      NVRAM_APP_RESERVED
    }
#endif /*__OCSP_SUPPORT__*/

#if defined(__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
    , {
        NVRAM_EF_BWCS_SETTING_DATA_LID,
        NVRAM_EF_BWCS_SETTING_DATA_SIZE,
        NVRAM_EF_BWCS_SETTING_DATA_TOTAL,
        NVRAM_NORMAL((kal_uint8 const *)NVRAM_EF_BWCS_SETTING_DATA_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPA7",
        VER(NVRAM_EF_BWCS_SETTING_DATA_LID),
        "BWCS SETTING",
        NVRAM_APP_RESERVED
    }
#endif /* __WIFI_BT_SINGLE_ANTENNA_SUPPORT__ */
    ,{
        NVRAM_EF_CAL_DATA_CHECK_LID,
        NVRAM_EF_CAL_DATA_CHECK_SIZE,
        NVRAM_EF_CAL_DATA_CHECK_TOTAL,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_MULTIPLE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CALIBRAT,
        "MPA8",
        VER(NVRAM_EF_CAL_DATA_CHECK_LID),
        "Calibration Data Check\0",
        NVRAM_RESERVED_VALUE
    }
/* Vogins Start */
#ifdef __VRE_V30__
	,{
    	NVRAM_EF_VRE_APP_BAN_LIST_EXT_LID,
    	NVRAM_EF_VRE_APP_BAN_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_APP_BAN_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPA9", 
        VER(NVRAM_EF_VRE_APP_BAN_LIST_EXT_LID), 
        "VRE3 BAN",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_PKEY_LIST_EXT_LID,
    	NVRAM_EF_VRE_PKEY_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_PKEY_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PKEY_EXT_DEFAULT),
    	NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MPAA",
        VER(NVRAM_EF_VRE_PKEY_LIST_EXT_LID), 
        "VRE3 PKEY",
        NVRAM_APP_RESERVED 
    }
    ,{
    	NVRAM_EF_VRE_SYM_ENTRY_LIST_EXT_LID,
    	NVRAM_EF_VRE_SYM_ENTRY_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_SYM_ENTRY_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_SYM_ENTRY_EXT_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPAB", 
        VER(NVRAM_EF_VRE_SYM_ENTRY_LIST_EXT_LID), 
        "VRE3 SYMENTRY",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_SYM_CONF_LIST_EXT_LID,
    	NVRAM_EF_VRE_SYM_CONF_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_SYM_CONF_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPAC", 
        VER(NVRAM_EF_VRE_SYM_CONF_LIST_EXT_LID), 
        "VRE3 SYSCONF",
        NVRAM_APP_RESERVED 
    }
    ,{
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_LID,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PAY_CHANNEL_EXT_DEFAULT),
    	NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MPAD", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_LID), 
        "VRE3 PAYCHAN",
        NVRAM_APP_RESERVED
    }

    ,{
    	NVRAM_EF_VRE_APP_STATE_LIST_EXT_LID,
    	NVRAM_EF_VRE_APP_STATE_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_APP_STATE_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER, 
        "MPAE", 
        VER(NVRAM_EF_VRE_APP_STATE_LIST_EXT_LID), 
        "VRE3 APP",
        NVRAM_APP_RESERVED
    }
,{
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST2_EXT_LID,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPAF", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_LIST2_EXT_LID), 
        "VRE3 PAYCHAN2",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST3_EXT_LID,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPB0", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_LIST3_EXT_LID), 
        "VRE3 PAYCHAN3",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST4_EXT_LID, 
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),	
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER, 
        "MPB1", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_LIST4_EXT_LID), 
        "VRE3 PAYCHAN4",
        NVRAM_APP_RESERVED 
    } 
    
    ,{
    	NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_EXT_LID,
    	NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPB2", 
        VER(NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_EXT_LID), 
        "VRE3 APP",
        NVRAM_APP_RESERVED
    }
    ,{
    	NVRAM_EF_VRE_APPSTORE3_CONFIG_LIST_EXT_LID,
    	NVRAM_EF_VRE_APPSTORE3_CONFIG_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_APPSTORE3_CONFIG_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPB3", 
        VER(NVRAM_EF_VRE_APPSTORE3_CONFIG_LIST_EXT_LID), 
        "VRE3 APP3",
        NVRAM_APP_RESERVED
    }	
	,{
    	NVRAM_EF_VRE_FIRST_RUNNING_LID,
    	NVRAM_EF_VRE_FIRST_RUNNING_SIZE,
    	NVRAM_EF_VRE_FIRST_RUNNING_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_FF_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPB4", 
        VER(NVRAM_EF_VRE_FIRST_RUNNING_LID), 
        "VRE3 FIRSTRUNNING",
        NVRAM_APP_RESERVED
    }
	,{
    	NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_LID,
    	NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPBC", 
        VER(NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_LID), 
        "VRE3 CHARGEDETAIL",
        NVRAM_APP_RESERVED
    }
	,{
    	NVRAM_EF_VRE_CHARGE_SMS_DETAIL_LIST_EXT_LID,
    	NVRAM_EF_VRE_CHARGE_SMS_DETAIL_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_CHARGE_SMS_DETAIL_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPBD", 
        VER(NVRAM_EF_VRE_CHARGE_SMS_DETAIL_LIST_EXT_LID), 
        "VRE3 CHARGESMSDETAIL",
        NVRAM_APP_RESERVED
    }
	,{
    	NVRAM_EF_VRE_PAY_CONFIG_EXT_LID,
    	NVRAM_EF_VRE_PAY_CONFIG_EXT_SIZE,
    	NVRAM_EF_VRE_PAY_CONFIG_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PAY_CONFIG_EXT_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPBE", 
        VER(NVRAM_EF_VRE_PAY_CONFIG_EXT_LID), 
        "VRE3 PAYCONFIG",
        NVRAM_APP_RESERVED
    }
	,{
    	NVRAM_EF_VRE_OPERATOR_CODE_EXT_LID,
    	NVRAM_EF_VRE_OPERATOR_CODE_EXT_SIZE,
    	NVRAM_EF_VRE_OPERATOR_CODE_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_OPERATOR_CODE_EXT_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPBF", 
        VER(NVRAM_EF_VRE_OPERATOR_CODE_EXT_LID), 
        "VRE3 OPERATECODE",
        NVRAM_APP_RESERVED
    }
	,{
    	NVRAM_EF_VRE_LOCAL_APN_INFO_EXT_LID,
    	NVRAM_EF_VRE_LOCAL_APN_INFO_EXT_SIZE,
    	NVRAM_EF_VRE_LOCAL_APN_INFO_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPC1", 
        VER(NVRAM_EF_VRE_LOCAL_APN_INFO_EXT_LID), 
        "VRE3 LOCALAPNINFO",
        NVRAM_APP_RESERVED
    }
	,{
    	NVRAM_EF_VRE_PAY_NOTIFICATION_EXT_LID,
    	NVRAM_EF_VRE_PAY_NOTIFICATION_EXT_SIZE,
    	NVRAM_EF_VRE_PAY_NOTIFICATION_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPC2", 
        VER(NVRAM_EF_VRE_PAY_NOTIFICATION_EXT_LID), 
        "VRE3 PAYNOTIFICATION",
        NVRAM_APP_RESERVED
    }
	,{
    	NVRAM_EF_VRE_PAY_CHANNEL_A_LIST_EXT_LID,
    	NVRAM_EF_VRE_PAY_CHANNEL_A_LIST_EXT_SIZE,
    	NVRAM_EF_VRE_PAY_CHANNEL_A_LIST_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PAY_CHANNEL_A_EXT_DEFAULT),
    	NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        NVRAM_CATEGORY_USER,
        "MPC3", 
        VER(NVRAM_EF_VRE_PAY_CHANNEL_A_LIST_EXT_LID), 
        "VRE3 PAYCHANACT",
        NVRAM_APP_RESERVED
    }	

	,{
    	NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_LID,
    	NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_SIZE,
    	NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_OPERATOR_CODE_234_EXT_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPC4", 
        VER(NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_LID), 
        "VRE3 OPERATECODE234",
        NVRAM_APP_RESERVED
    }
	,{
    	NVRAM_EF_VRE_PAYCHANNEL_USAGE_EXT_LID,
    	NVRAM_EF_VRE_PAYCHANNEL_USAGE_EXT_SZIE,
    	NVRAM_EF_VRE_PAYCHANNEL_USAGE_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPC5", 
        VER(NVRAM_EF_VRE_PAYCHANNEL_USAGE_EXT_LID), 
        "VRE3 PAYCHANNELSAGE",
        NVRAM_APP_RESERVED
    }

   ,{
    	NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_EXT_LID,
    	NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_EXT_SIZE,
    	NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPC6", 
        VER(NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_EXT_LID), 
        "VRE3 CHARGEDETAILEXT",
        NVRAM_APP_RESERVED
    }

   ,{
    	NVRAM_EF_VRE_PAY_CONFIG_EXT_EXT_LID,
    	NVRAM_EF_VRE_PAY_CONFIG_EXT_EXT_SIZE,
    	NVRAM_EF_VRE_PAY_CONFIG_EXT_EXT_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_VER_PAY_CONFIG_EXT_EXT_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPC7", 
        VER(NVRAM_EF_VRE_PAY_CONFIG_EXT_EXT_LID), 
        "VRE3 PAYCONFIGEXT",
        NVRAM_APP_RESERVED
    }
#endif
#ifdef __VRE30_AM__
/*vogins_20100625_start*/
	,{
        NVRAM_EF_AM_PROMPT_LID,                     /* LID */                                            
        NVRAM_EF_AM_PROMPT_SIZE,                    /* Size */                                           
        NVRAM_EF_AM_PROMPT_TOTAL,                   /* Total */                                          
        NVRAM_NORMAL(( kal_uint8 *)&NVRAM_EF_ZERO_DEFAULT),     /* Default value */
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,             /* Category */                                       
        "MPC5", 
        VER(NVRAM_EF_AM_PROMPT_LID), 
        "AM Profile Setting",
        NVRAM_APP_RESERVED
    }	
    /*vogins_20100625_end*/
#endif
#ifdef __VRE_V30__
/*vogins_20100630_start_by_waternie*/
   ,{
    	NVRAM_EF_VRE_USER_APN_INFO_LID,
    	NVRAM_EF_VRE_USER_APN_INFO_SIZE,
    	NVRAM_EF_VRE_USER_APN_INFO_TOTAL,
    	NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
    	NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPC6", 
        VER(NVRAM_EF_VRE_USER_APN_INFO_LID), 
        "VRE3 USERAPNINFO",
        NVRAM_APP_RESERVED
    } 
/*vogins_20100630_end_by_waternie*/
#endif

#ifdef __VRE30_AM__
    ,{
		NVRAM_EF_AM_HS_SHORTCUT_LIST_LID,
		NVRAM_EF_AM_HS_SHORTCUT_LIST_SIZE,
		NVRAM_EF_AM_HS_SHORTCUT_LIST_TOTAL,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER,
		"MPB5",
		VER(NVRAM_EF_AM_HS_SHORTCUT_LIST_LID),
		"hs shortcut use",
		NVRAM_APP_RESERVED
	}
#endif
/* Vogins End */

#ifdef __MMI_VUI_HOMESCREEN_CLOCK__
    ,{
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_LID,
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_SIZE,
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPB6",
        VER(NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_LID),
        "Venus home screen clock widget data",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_VUI_HOMESCREEN_CLOCK__ */

#ifdef __MMI_VUI_3D_CUBE_APP__
    ,{
        NVRAM_EF_CUBE_VIP_CONTS_LID,
        NVRAM_EF_CUBE_VIP_CONTS_SIZE,
        NVRAM_EF_CUBE_VIP_CONTS_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPB7",
        VER(NVRAM_EF_CUBE_VIP_CONTS_LID),
        "Cube vip contact arrays",
        NVRAM_APP_RESERVED
    }
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    ,{
		NVRAM_EF_OP11_HS32_HIST_LID,
		NVRAM_EF_OP11_HS32_HIST_SIZE,
		NVRAM_EF_OP11_HS32_HIST_TOTAL,
		NVRAM_NORMAL(NVRAM_EF_OP11_HS32_HIST_DEFAULT),
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER,
		"MPB8",
		VER(NVRAM_EF_OP11_HS32_HIST_LID),
		"hs history",
		NVRAM_APP_RESERVED
	}
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __MMI_VUI_HOMESCREEN__
    ,{
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_LID,
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_SIZE,
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        NVRAM_CATEGORY_USER,
        "MPB9",
        VER(NVRAM_EF_VENUS_HS_SHORTCUT_MGR_LID),
        "Venus home screen shortcut manager settings",
        NVRAM_APP_RESERVED
    }
#endif /* __MMI_VUI_HOMESCREEN__ */

#if (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) && defined(__SRV_SMS_SIM_CUST_DATA__))
    ,{
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_LID,
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_SIZE,
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MPBA",
        VER(NVRAM_EF_SRV_SMS_SIM_CUST_DATA_LID),
        "SMS SIM Card Customization Data",
        NVRAM_APP_RESERVED
    }
#endif /* (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) && defined(__SRV_SMS_SIM_CUST_DATA__)) */
/**************************************************************************
 *   Add new entry in the tail with its compile optoin                    *
 *   Add new entry in the tail with its compile optoin                    *
 *   Add new entry in the tail with its compile optoin                    *
 **************************************************************************/
    ,{ NVRAM_EF_RESERVED_LID }
};

/* Configure NVRAM_EF_SYS_CACHE_OCTET_LID begin */
#ifdef NVRAM_AUTO_GEN
nvram_sys_cache_entry nvram_sys_cache[] =
{
    SYS_CACHE_ENTRY(NVRAM_SYS_CACHE_BEGIN,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_FALSE,
                    "Record system cache will be restore or not",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#ifdef __GEMINI__
    SYS_CACHE_ENTRY(NVRAM_SYS_FLIGHTMODE_STATE,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_FLIGHTMODE_STATE",
                    0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00),
#else
    SYS_CACHE_ENTRY(NVRAM_SYS_FLIGHTMODE_STATE,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_FLIGHTMODE_STATE",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#endif
    SYS_CACHE_ENTRY(NVRAM_SYS_DSP_PATCH,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_DSP_PATCH",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_SIM_PLUS_SETTING,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_SIM_PLUS_SETTING",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_FIXED_GAIN_MECH_FOR_HELIOS2,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_FIXED_GAIN_MECH_FOR_HELIOS2",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_FACTORY_FLAG,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_FACTORY_FLAG",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_LAST_FAT_STATUS,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_LAST_FAT_STATUS",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_INFO,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_INFO",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_PHB_COMPARE_DIGIT,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_PHB_COMPARE_DIGIT",
                    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_SVN,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_SVN",
                    0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_USB_BOOT_MODE,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_USB_BOOT_MODE\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),

    /* !!Add a entry above this line by using SYS_CACHE_ENTRY macro */
    SYS_CACHE_ENTRY(NVRAM_SYS_CACHE_MAX,
                    NVRAM_APP_PHNSET,
                    NVRAM_CACHE_ID_RESERVED,
                    KAL_FALSE,
                    "The last record of system cache",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
};
#endif
/* Configure NVRAM_EF_SYS_CACHE_OCTET_LID end */

#endif /*!__MAUI_BASIC__*/


