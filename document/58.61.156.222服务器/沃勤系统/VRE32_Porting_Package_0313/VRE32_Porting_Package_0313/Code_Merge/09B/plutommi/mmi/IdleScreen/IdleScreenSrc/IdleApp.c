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
 *  IdleApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for The Idle screen application
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"

#include "MiscFunctions.h"
#include "DateTimeGprot.h"
#include "CommonScreens.h"      /* DisplayPopup */
#include "wgui_softkeys.h"
#include "worldclock.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "IdleHomescreen.h"
#include "IdleToolbar.h"
#include "IdleVenus.h"
#include "IdleLawmo.h"
#include "IdleNotificationManager.h"
#include "IdleDialerSearch.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "CallsGprot.h"
#include "SSCStringHandle.h"
#include "SettingGprots.h"
#include "audioinc.h"
#include "gpioInc.h"
#include "SettingProfile.h"
#include "SpeedDial.h"
#include "MessagesResourceData.h"
#include "WPSSProtos.h"
#include "PowerOnChargerProt.h"
#include "FunAndGamesDefs.h"
#include "QuickAccessMenuItemResDef.h"
#include "QuickAccessMenuItemProt.h"
#include "AlarmFrameworkProt.h"
#include "AlarmProt.h"
#include "ProfilesGexdcl.h"
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "PhoneSetupGprots.h"
#include "OrganizerGprot.h"     /* OrgDeInit */
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "FileManagerGProt.h"   /* file path / file error */
#include "FileManagerDef.h"     /* error string id */
#include "FlightModeGProt.h"
#include "VolumeHandler.h"
#include "EONSGProt.h"
#include "BrowserGprots.h"
#include "StatusIconRes.h"
#include "ConnectManageGProt.h"
#include "BootUp.h"
#include "CallManagementGprot.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "PhbCuiGprot.h"

#ifdef __MMI_VUI_3D_CUBE_APP__
#include "CubeAppGProt.h"
#include "CubeAppProt.h"
#endif /* __MMI_VUI_3D_CUBE_APP__ */

#if defined(__MMI_DATE_TIME_SETTING_REMINDER__)
#include "rtc_sw.h"
#endif 

/* JBRW Sandeep */
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "JBrowserMMIGProts.h"
#endif 

/* Manish - adding for JMMS */
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
#include "JMMSPushHandling.h"
#include "JMMSMainMMS.h"
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

/* Dara */
#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
#include "JProvProts.h"
#endif 

#include "wgui_ems.h"
#include "ShortcutsProts.h"     /* for 4-dedicated shortcuts 0101 */
#include "SATGProts.h"

#ifdef WAP_SUPPORT
#include "Wapadp.h"
#include "wap_ps_struct.h"
#endif 

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#endif 
#ifdef __J2ME__
#include "javaAgencyGprot.h"
#include "jam_internal.h"
#include "JavaAgencyGProt.h"

#endif /* __J2ME__ */ 

#ifdef __MMI_SWFLASH__
#include "SWFlashGprot.h"
#endif /* __MMI_SWFLASH__ */ 

#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 

#if defined __MMI_OPP_SUPPORT__ || defined __MMI_BIP_SUPPORT__
#include "BTMMIObexGprots.h"
#endif 

#ifdef __MOD_SMSAL__
#include "MessagesExDcl.h"
#endif /* __MOD_SMSAL__ */ 

#ifdef __MMI_AUDIO_PLAYER__
#include "AudioPlayerProt.h"
#endif /* __MMI_AUDIO_PLAYER__ */ 

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#include "lcd_if.h"     /* LCD layer enable flag */
#include "MMI_features_camera.h"
#include "mdi_datatype.h"
#include "mdi_camera.h" /* camera lib */
#include "CameraApp.h"
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
#include "mmi_features_camcorder.h"
#include "CamcorderGprot.h"
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)*/ 

#ifdef __MMI_FM_RADIO__
#include "FMRadioProt.h"
#endif /* __MMI_FM_RADIO__ */ 

#if defined(__MMI_VRSD_DIAL__)
#include "VRSDDial.h"
#endif /* __MMI_VRSD_DIAL__ */

#include "custom_util.h"

#include "NITZ.h"
#include "vObjects.h"
#include "OSThreadInterfaceGprot.h"
#include "NetworkSetupDefs.h"
#include "NetworkSetupGProt.h"

#ifdef __MMI_IMPS__
/* under construction !*/
#endif 

/* micha_POC */
#ifdef __MMI_POC__
#include "PoCGProt.h"
#endif 

#ifdef __MMI_VOIP__
#include "VoIPResDef.h"
#include "VoIPGProt.h"
#endif /* __MMI_VOIP__ */

#ifdef __MMI_AUTO_ANSWER_MACHINE__
#include "AnswerMachineGprot.h"
#endif

#ifdef __MMI_TOUCH_SCREEN__
#endif /* __MMI_TOUCH_SCREEN__ */ 

#include "UMGProt.h"

#if defined(__MMI_DOWNLOAD_AGENT__)
#include "App_mine.h"
#include "DLAgentDef.h"
#include "DLAgentGProt.h"
#endif /* defined(__MMI_DOWNLOAD_AGENT__) */ 

#ifdef __MMI_SML_MENU__
#include "PersonalizationProt.h"
#endif

#ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__
#include "MTPNP_PFAL_DM_Setup.h"
#endif

#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif

#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))
#include "SyncMLGProt.h"
#endif

#ifdef __CCA_SUPPORT__
#include "CentralConfigAgentGProt.h"
#endif

#ifdef __MMI_MMS_2__
#include "MMSAppInterfaceGprot.h"
#endif
#ifdef WAP_SUPPORT
#include "WAPPushGprots.h"
#endif

#ifdef __MMI_OP01_DCD__
#include "DCDResDef.h"
#include "DCDGprot.h"
#include "ui_dcd_porting.h"
#endif /* __MMI_OP01_DCD__ */ 

#ifdef __MMI_BG_SOUND_EFFECT__
#include "BGSoundType.h"
#endif

#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGprots.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_PFAL_Master_CallHistory.h"
#include "mtpnp_pfal_cellbroadcast.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */


#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif

#ifdef __DRM_SUPPORT__
#include "RightsMgrGProt.h"
#endif

#ifdef __MMI_MAPBAR_GIS__
#include "MB_GISGProt.h"
#endif

#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
#include "FileMgrGProt.h"
#endif

#ifdef __MMI_AUTO_ANSWER_MACHINE__
#include "AnswerMachineGprot.h"
#endif

#ifdef SYNCML_DM_SUPPORT
#include "Dmuigprot.h"
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxUIGProt.h"
#endif

#ifdef __MMI_SEARCH_WEB__
#include "SearchWebGProt.h"
#endif

#undef __NEWSIMULATOR

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#include "gui_effect_oem.h"
#endif

#ifdef __MMI_FANCY_SCREEN_LOCK__
#include "IdleFancyHandsetLock.h"
#endif

/***************************************************************************** 
* Define
*****************************************************************************/

#if defined(__MMI_WGUI_CSK_ENABLE__) && \
    defined(__MMI_TOUCH_SCREEN__) && \
    !defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
#define MMI_IDLE_DIAL_PAD_SUPPORT_CSK
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
extern void EntryDualModeSwitchProgressInIdle(void);
extern U8 DualModeIsSwitching(void);
#endif 

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* diamond, 2005/10/12 idle revise */
typedef void (*FuncPtr) (void);
typedef U8(*FuncPtrRtn) (void);

typedef struct _idle_callback_info
{
    FuncPtrRtn idle_callback_chk_f; /* callback to check if there is any pending event in idle screen */
    FuncPtr idle_callback_exe_f;    /* callback to execute the corresponding function in idle screen  */
} IDLECALLBACKINFO;

/* end, diamond */


/****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern MMI_BOOL EmergencyCallCheck(S16 keyCode, S16 keyType);
extern void MMIProcessActionMsg(void);
extern U8 *GetDeliverdReportMessage(void);
extern kal_bool INT_USBBoot(void);
extern EMSData *GetClass0MessagePtr(void);
extern U8 *GetClass0MessageHeader(void);

#ifdef __SAT__
#ifndef __SAT_LOWCOST_UI_DISABLE__
extern void SATEVDLIdleScreenAvaliable(void);
#endif
#endif
extern void mmiapi_enter_idle_screen_notify(void);

#ifdef WAP_SUPPORT
extern void wap_internet_key_hdlr(void);
#endif 

#if defined(__MMI_VRSD__)
extern void mmi_vrsd_rcg_pre_entry(void);
#endif 

#if defined(__MMI_VRSI__)
extern void mmi_vrsi_rcg_pre_entry(void);
#endif 

#ifdef __MMI_WGUI_MINI_TAB_BAR__
extern void ClndrPreEntryApp(void);
extern void mmi_fmgr_launch(void);
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 

/* diamond, 2005/07/05 Flight mode */
void EntryFlightModeIdleScreen(void);
void EntryFlightModeKeypadLockScreen(void);
void FlightModeDigitHandler(void);
/* end, diamond */

extern void InsertSimSetKeyPadLockFlag(void);

#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
extern int widget_MMI_check_and_display_new_msg_when_keypad_lock(
            U16 KeyLockLSKStringID,
            U16 KeyLockLSKIconID,
            U16 KeyLockRSKStringID,
            U16 KeyLockRSKIconID);
extern int widget_MMI_check_and_display_new_msg(void);
extern void widget_check_msg_in_idle_screen(void);
extern void widget_MMI_on_enter_idle_screen(void);
#endif

#ifdef __A8BOX_SUPPORT__
extern MMI_BOOL mmi_a8box_is_playing(void);
extern void mmi_a8box_enter_cameraapp(void);
#endif

/*****************************************************************************
* Local Function 
*****************************************************************************/
#ifdef __MMI_NITZ__
static U8 mmi_idle_pending_nitz_check(void);
#endif 
#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
static U8 mmi_idle_widget_check_and_display_new_msg(void);
#endif


/****************************************************************************
* Global Variable                                                           
*****************************************************************************/
extern U16 gCurrLangIndex;
extern U16 gMaxDeployedLangs;
extern S32 MAIN_LCD_device_width;
extern sLanguageDetails *gLanguageArray;

#ifdef __HOMEZONE_SUPPORT__
extern U8 *gHomezoneText;
#endif 

extern U16 simErrorDisplayString;


/***************************************************************************** 
* Local Variable
*****************************************************************************/
idle_context_struct g_idle_context = 
{
    0,                      /* IsOnIdleScreen */
    SUBLCD_NOT_ON_IDLE,     /* IsSubLcdOnIdleScreen */
    0,                      /* IsOnDialerScreen */
    0,                      /* IsOnSimErrorScreen */
    0,                      /* IsOnSimErrorDialerScreen */
    0,                      /* IsScrSvrSleepIn */
    0,                      /* IsRSKPressOnScreenSaver */
    0,                      /* LongPressEnable */
    0,                      /* ScreenSaverRunFlag */
    0,                      /* ToNameScrFromIdleApp */
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    0,                      /* ToMainMenuScrFromIdleApp */
#endif 
    0,                      /* RskPressedFromIdleApp */
    0,
    -1,                     /* IdleScreenDigitKeyCode */
#ifdef __MMI_SIMAP_SUPPORT__
    0,
#endif
#ifdef __OP12__
    NULL,                   /* delayed_rsk_hdlr */
#endif
#ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
    {0},                    /* icon_shortcut_hdlr */
#endif
    0,                      /* AutoLockTimeOut */
    0,                      /* cui_save_number_id */
    {0}                     /* All dialled digits from idle screen */
};

idle_keylock_struct g_keylock_context = 
{
    0,      /* gKeyPadLockFlag */
    0,
    0,      /* KeyLockLSKStringID */
    0,      /* KeyLockRSKStringID */
    0,      /* KeyLockLSKIconID */
    0,      /* KeyLockRSKIconID */
    NULL    /* diamond, 2006/03/26 Generic exit function for keypad lock callback screens */
};

#ifdef __MMI_NITZ__
static idle_nitz_struct g_nitz_display = 
{
    0,      /* opname_from_nitz */
    0,      /* country_init */
    {0},    /* plmn[] */
    {0}     /* display_name[] */
};
#ifdef __MMI_DUAL_SIM_MASTER__
idle_nitz_struct g_nitz_display_2 = 
{
    0,      /* opname_from_nitz */
    0,      /* country_init */
    {0},    /* plmn[] */
    {0}     /* display_name[] */
};
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_NITZ__ */ 

static const IDLECALLBACKINFO mmi_idle_callbacks[] = 
{
    /* How to add callbacks for idle screen/keypad lock ? */
    /* 1. Fill the callbacks into this array     */

    /* Notice that the function type !        */
    /* 1. Checking  function should be U8 XXX(void)    */
    /* 2. Execution function should be void XXX(void)  */
    
#ifdef __DM_LAWMO_SUPPORT__
    /* Do not add idle callback before this. */
    {mmi_idle_lawmo_is_locked, mmi_idle_lawmo_entry_locked_screen},
#endif /* __DM_LAWMO_SUPPORT__ */

#ifdef __MMI_FANCY_SCREEN_LOCK__
    {mmi_idle_fhl_check, mmi_idle_fhl_entry},
#endif
#ifdef __DM_FOTA_SUPPORT__
    /* Notify user that the firmware update success or not when bootup */
    {mmi_dmui_fota_entry_update_info_check, mmi_dmui_fota_entry_update_info_callback},
#endif /* __DM_FOTA_SUPPORT__ */
    {mmi_nmgr_need_notification, mmi_nmgr_direct_notify},
        
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif
#ifdef __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__
    {mmi_sat_is_pending_idle_sat_cmd, mmi_sat_execute_idle_sat_cmd},
#endif
#ifdef __J2ME__
    {mmi_java_is_launch_from_idle, mmi_java_entry_mid_launch_from_idle}, /* new Java midlet */
    {mmi_java_timealarm_islock, mmi_java_timealarm_unlock}, 
    {mmi_java_pushinstall_islock, mmi_java_pushinstall_unlock}, 
#endif 
#if defined(__J2ME__) && defined(__DM_SCOMO_SUPPORT__)
	{mmi_java_dmui_scomo_execute_cmd_check, mmi_java_dmui_scomo_execute_cmd_cb},
#endif 
    {mmi_chist_new_event_query, mmi_chist_idle_entry_notify_missed_call}, /* missed call */
    {mmi_msg_need_class0_msg_ind, mmi_msg_entry_class0_msg_ind}, /* new class 0 message */
    {mmi_um_check_new_msg, mmi_um_pre_entry_new_msg_ind}, /* new unified message */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    {mmi_msg_need_new_sim_msg_ind, mmi_msg_entry_new_sim_msg_ind}, /* new unified message */
#endif
#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__)
    {mmi_provboxui_idle_new_msg_check, mmi_provboxui_idle_new_msg_ind},
#endif
    {mmi_msg_need_mem_exceed_ind, mmi_msg_entry_mem_exceed_ind}, /* memory exceed notification */
    {mmi_msg_need_delivery_report_ind, mmi_msg_entry_deliver_report_ind}, /* deliver report */
    {mmi_msg_need_waiting_ind, mmi_msg_entry_msg_waiting_ind}, /* waiting message */
#ifdef __MMI_EMAIL__
    {mmi_email_check_show_idle_data, mmi_email_show_idle_data},
#endif
#ifdef __MMI_VOIP__
    {mmi_voip_need_msg_waiting_ind, mmi_voip_entry_msg_waiting_ind},
#endif
#ifdef __MMI_AUTO_ANSWER_MACHINE__
    {mmi_autoam_need_msg_waiting_ind, mmi_autoam_entry_msg_waiting_ind},
#endif
#ifdef __MMI_IMPS__
#ifndef __MMI_OP11_IMPS__  
/* under construction !*/
#endif 
#endif 
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    {mmi_vobj_is_pending_object, mmi_vobj_entry_recv_object}, /* unread vObjects */
#endif 
#if defined(__MMI_IRDA_SUPPORT__)
    {mmi_irda_get_recv_files_cnt, mmi_irda_entry_idle_notify_scr}, /* files from IrDA */
#endif 
#if (defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) && defined(__MMI_IRDA_SUPPORT__))
    {mmi_irda_is_any_theme_file_rcv, mmi_irda_theme_show_idle_notify_scr}, /* downloadable theme from IrDA */
#endif 
#if defined(__MMI_NITZ__)
    {mmi_idle_pending_nitz_check, EntryNitzScreen}, /* NITZ */
#endif 
    {mmi_msg_need_new_cb_ind, mmi_msg_entry_new_cb_ind}, /* new CB message */
#ifdef __MMI_DUAL_SIM_MASTER__
    {mmi_card2_msg_need_new_cb_ind, mmi_msg_entry_card2_new_cb_ind}, /* new SIM 2 CB message */
#endif /* __MMI_DUAL_SIM_MASTER__ */
#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
    {mmi_idle_widget_check_and_display_new_msg, NULL}, /* new message from widget */
#endif 
#if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)
    {mmi_phb_init_check_sim_change, NULL}, /* associate caller group in SIM card entry */
#endif 
#if defined(__MMI_VRSD_DIAL__)
    {mmi_vrsddial_check_sim_change, NULL}, /* VRSD dial */
#endif 
#if defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
    {mmi_bt_recv_files_exist, mmi_bt_entry_idle_notify_scr}, /* files from Bluetooth */
#endif
#if defined(__MMI_DOWNLOAD_AGENT__)
    {mmi_da_launch_ring_buffer_check, mmi_da_entry_new_push_ind}, /* download agent */
#endif 
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
    {mmi_jmms_need_mms_ind, mmi_jmms_entry_new_mms_ind}, /* new mms message */
#endif 
#if !defined (__MMI_PUSH_IN_UM__) && defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
    {mmi_brw_new_push_msg_ind, mmi_brw_entry_new_push_msg_ind},  /* new wap push message */
#endif 
#if !defined (__CCA_SUPPORT__) && defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))
    {mmi_prov_check_and_install_new_settings, mmi_prov_show_install_settings_dialog},
#endif 
#ifdef WAP_SUPPORT
    {srv_wap_push_check_pendig_event_on_idle, srv_wap_push_handle_pendig_event_on_idle},
    {srv_wap_push_service_dlg_idle_scr_cb, srv_wap_push_fetch_dlg_from_queue},
#endif
#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__))
    {mmi_syncml_is_sync_alarm_expired, mmi_syncml_sync_alarm_hdlr}, /* sync */
#endif
#ifdef __MMI_USER_CTRL_PLMN_SUPPORT__
    {mmi_netset_unknown_operator_check, mmi_netset_unknown_operator_query}, /* user control plmn */
#endif
#if defined(__FOTA_PROPRIETARY__)
    {mmi_dm_fwu_check_download_finish, mmi_dm_fwu_entry_download_finish_ind}, /* firmware upgrade finished */
#endif
#ifdef __CCA_SUPPORT__
    {mmi_cca_idle_check, mmi_cca_ui_entry_idle_screen},
#endif 
#ifdef __CERTMAN_SUPPORT__
	{mmi_certman_idle_check,mmi_certman_ui_entry_idle_screen},
#endif
#if defined(__DRM_SUPPORT__)
    {mmi_rmgr_space_check, mmi_rmgr_entry_db_check},
#endif
#ifdef __MMI_PHB_ICE_CONTACT__
    {mmi_phb_ice_contact_check, mmi_phb_entry_ice_contact},
#endif /* __MMI_PHB_ICE_CONTACT__ */

#if defined (__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
    {mmi_fmgr_default_storage_need_confirm, mmi_fmgr_default_storage_do_confirm},
#endif        

#ifdef __MMI_NETSET_3G_ENHANCE__
    {mmi_netset_rat_idle_notify, mmi_netset_rat_selection},
#endif /* __MMI_NETSET_3G_ENHANCE__ */

#ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__
    {mmi_dualmode_check_query_screen_from_idle, mmi_dualmode_entry_query_screen_from_idle},
#endif

#ifdef __MMI_PHB_STARTUP_COPY_SIM__
    {mmi_phb_startup_copy_sim_check, mmi_phb_startup_copy_sim_pre_entry},
#ifdef __MMI_DUAL_SIM_MASTER__
    {mmi_phb_startup_copy_sim2_check, mmi_phb_startup_copy_sim2_pre_entry},
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_PHB_STARTUP_COPY_SIM__ */

#ifdef SYNCML_DM_SUPPORT
    {mmi_dmui_start_dl_delay_to_idle_check, mmi_dmui_start_dl_delay_to_idle_callback},
#endif

    {NULL, NULL}                                            /* dummy one, please add callbacks before this entity */
};

static U16 idleRskStringID = 0; /* __MANUAL_MODE_NW_SEL__ */
static MMI_BOOL gIsIdleScreenReentry = MMI_FALSE;
extern S8 *idle_screen_wallpaper_name;


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_exe_callback
 * DESCRIPTION
 *  Execute callbacks before entry idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_idle_exe_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    pBOOL rtn = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.IsOnIdleScreen = 0; /* set not on idle first because the callback will provide a new screen */
    for (i = 0; mmi_idle_callbacks[i].idle_callback_chk_f != NULL; i++)
    {
        if ((*mmi_idle_callbacks[i].idle_callback_chk_f) ())
        {
            rtn = MMI_TRUE;
            if (mmi_idle_callbacks[i].idle_callback_exe_f != NULL)
            {
                (*mmi_idle_callbacks[i].idle_callback_exe_f) ();
            }
            break;
        }
    }

    if (!rtn)
    {
        g_idle_context.IsOnIdleScreen = 1; /* reset on idle if no callback to execute */
    }

    mmi_nmgr_reset();

    return rtn;
}


#ifdef __MMI_NITZ__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_pending_nitz_check
 * DESCRIPTION
 *  Wrapper for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_idle_pending_nitz_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8) g_nitz_cntx.IsNITZPending;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_opname_from_nitz
 * DESCRIPTION
 *  Update NITZ network name if a new message is received
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_update_opname_from_nitz(void)
{
    if (mmi_idle_is_on_idle_screen())
    {
        EntryIdleScreen(); /* IdleRefreshServiceIndicationArea(); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_nitz_content
 * DESCRIPTION
 *  Update NITZ network name from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_update_nitz_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_display_length = MAX_LENGTH_DISPLAY_NAME;
    U8 mcc_tmp_unicode[4 * ENCODING_LENGTH];
    U8 tmp_plmn[MAX_PLMN_LEN_MMI + 1];
    U8 tmp_display_name[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];
    U8 iCnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tmp_plmn, 0 , MAX_PLMN_LEN_MMI + 1);
    memset(tmp_display_name, 0, MAX_LENGTH_DISPLAY_NAME);

    mmi_nitz_get_nitz_nw_name(tmp_plmn, tmp_display_name, (U8) MAX_LENGTH_DISPLAY_NAME - 1, &g_nitz_display.country_init);

    if (strlen((S8*)tmp_plmn) != 0 && strlen((S8*)tmp_display_name) != 0)
    {
    	strcpy((S8*)g_nitz_display.plmn, (S8*)tmp_plmn);
        if (g_nitz_display.country_init)
        {
            max_display_length -= 4;    /* 1 space char and 3 mcc digits */
        }
        
        if (mmi_ucs2strlen((S8*) tmp_display_name) >= max_display_length)
        {
            mmi_ucs2ncpy((S8*) g_nitz_display.display_name, (S8*) tmp_display_name, max_display_length);
        }
        else
        {
            mmi_ucs2cpy((S8*) g_nitz_display.display_name, (S8*) tmp_display_name);
        }

        if (g_nitz_display.country_init)
        {
            memset(mcc_tmp_unicode, 0, sizeof(mcc_tmp_unicode));
            mmi_asc_n_to_ucs2((S8*) mcc_tmp_unicode, (S8*) g_nitz_display.plmn, 3);
            mmi_ucs2cat((S8*) g_nitz_display.display_name, " ");
            mmi_ucs2cat((S8*) g_nitz_display.display_name, (S8*) mcc_tmp_unicode);
        }

        g_nitz_display.opname_from_nitz = 1;
    }
    else
    {
        g_nitz_display.opname_from_nitz = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_check_nitz_display_validation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_idle_check_nitz_display_validation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EONS_SUPPORT__
    extern U8 gLAC[2];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EONS_SUPPORT__
    if (mmi_eons_check_if_plmn_present(gPLMN, gLAC) != 0)
    {
        return MMI_FALSE;
    }
#endif /* __MMI_EONS_SUPPORT__ */

    if (memcmp(g_nitz_display.plmn, gPLMN, MAX_PLMN_LEN_MMI) != 0)
    {
        g_nitz_display.opname_from_nitz = 0;
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_sim2_nitz_content
 * DESCRIPTION
 *  Update NITZ network name from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_update_sim2_nitz_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_display_length = MAX_LENGTH_DISPLAY_NAME;
    U8 mcc_tmp_unicode[4 * ENCODING_LENGTH];
    U8 tmp_plmn[MAX_PLMN_LEN_MMI + 1];
    U8 tmp_display_name[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];
    U8 iCnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tmp_plmn, 0 , MAX_PLMN_LEN_MMI + 1);
    memset(tmp_display_name, 0, MAX_LENGTH_DISPLAY_NAME);

    mmi_nitz_get_nitz_nw_name_sim2(tmp_plmn, tmp_display_name, (U8) MAX_LENGTH_DISPLAY_NAME - 1, &g_nitz_display_2.country_init);

    if (strlen((S8*)tmp_plmn) != 0 && strlen((S8*)tmp_display_name) != 0)
    {
    	strcpy((S8*)g_nitz_display_2.plmn, (S8*)tmp_plmn);
        if (g_nitz_display_2.country_init)
        {
            max_display_length -= 4;    /* 1 space char and 3 mcc digits */
        }
        
        if (mmi_ucs2strlen((S8*) tmp_display_name) >= max_display_length)
        {
            mmi_ucs2ncpy((S8*) g_nitz_display_2.display_name, (S8*) tmp_display_name, max_display_length);
        }
        else
        {
            mmi_ucs2cpy((S8*) g_nitz_display_2.display_name, (S8*) tmp_display_name);
        }

        if (g_nitz_display_2.country_init)
        {
            memset(mcc_tmp_unicode, 0, sizeof(mcc_tmp_unicode));
            mmi_asc_n_to_ucs2((S8*) mcc_tmp_unicode, (S8*) g_nitz_display_2.plmn, 3);
            mmi_ucs2cat((S8*) g_nitz_display_2.display_name, " ");
            mmi_ucs2cat((S8*) g_nitz_display_2.display_name, (S8*) mcc_tmp_unicode);
        }

        g_nitz_display_2.opname_from_nitz = 1;
    }
    else
    {
        g_nitz_display_2.opname_from_nitz = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_check_sim2_nitz_display_validation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_idle_check_sim2_nitz_display_validation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EONS_SUPPORT__
    extern U8 gLAC_2[2];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EONS_SUPPORT__
    if (mmi_eons_check_sim2_if_plmn_present(gPLMN_2, gLAC_2) != 0)
    {
        return MMI_FALSE;
    }
#endif /* __MMI_EONS_SUPPORT__ */

    if (memcmp(g_nitz_display_2.plmn, gPLMN_2, MAX_PLMN_LEN_MMI) != 0)
    {
        g_nitz_display_2.opname_from_nitz = 0;
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MMI_NITZ__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_widget_check_and_display_new_msg
 * DESCRIPTION
 *  Wrapper for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
static U8 mmi_idle_widget_check_and_display_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check WNOTI_CTX->check_msg_in_idle_screen first */
    widget_check_msg_in_idle_screen();
    if (g_keylock_context.gKeyPadLockFlag)
    {
        if (widget_MMI_check_and_display_new_msg_when_keypad_lock
            (g_keylock_context.KeyLockLSKStringID, g_keylock_context.KeyLockLSKIconID,
             g_keylock_context.KeyLockRSKStringID, g_keylock_context.KeyLockRSKIconID))
        {
            /* Check WNOTI_CTX->check_msg_in_idle_screen again */
            widget_check_msg_in_idle_screen();
            return MMI_TRUE;
        }
    }
    else
    {
        if (widget_MMI_check_and_display_new_msg())
        {
            /* Check WNOTI_CTX->check_msg_in_idle_screen again */
            widget_check_msg_in_idle_screen();
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif /* defined(OBIGO_Q03C) && defined(WAP_SUPPORT) && !defined (__UNIFIED_MSG_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_pen_block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_idle_pen_block(void)
{
#ifndef __MMI_GPIO_DISABLE_SLEEP_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_gpio_is_lcd_sleep())
#endif /* __MMI_GPIO_DISABLE_SLEEP_MODE__ */ 
        mmi_pen_block();
}
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_keypad_lock_string
 * DESCRIPTION
 *  This function is used to set keypad lock RSK string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_set_keypad_lock_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_keylock_context.KeyLockRSKStringID = 0;
    g_keylock_context.KeyLockRSKIconID = 0;
    g_keylock_context.KeyLockLSKStringID = 0;
    g_keylock_context.KeyLockLSKIconID = 0;

    if (g_idle_context.IsOnIdleScreen == 1 || g_idle_context.IsOnSimErrorScreen == 1)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_LOCK);
    #else 
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_KEYPAD_LOCK);
    #endif 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    #ifdef __MMI_TOUCH_SCREEN__
        g_keylock_context.KeyLockRSKStringID = SCREEN_LOCKED_TEXT;
    #else 
        g_keylock_context.KeyLockRSKStringID = KEYPAD_LOCKED_RSK_TEXT;
    #endif 
    #endif /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    #ifdef __MMI_TOUCH_SCREEN__
        g_keylock_context.KeyLockLSKStringID = SCREEN_LOCKED_TEXT;
    #else 
        g_keylock_context.KeyLockLSKStringID = KEYPAD_LOCKED_RSK_TEXT;
    #endif 
    #endif /* __MMI_KEYPAD_LOCK_PATTERN_2__ */ 
    }
    else
    {
        /* If active screen is not idle, pen is not blocked */
        /* Set RSK/LSK string to "unlock" because it is allowed to click the touch screen to unlock */
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
        g_keylock_context.KeyLockRSKStringID = KEYPAD_LOCKED_RSK_TEXT;
    #endif 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
        g_keylock_context.KeyLockLSKStringID = KEYPAD_LOCKED_RSK_TEXT;
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_date_time_reminder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_date_time_reminder(void)
{
#if defined(__MMI_DATE_TIME_SETTING_REMINDER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL datejust_reminder_shown = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!datejust_reminder_shown && RTC_is_MS_FirstPowerOn())
    {
        mmi_display_popup(
            get_string(STR_DATE_TIME_UPDATE_REMINDER), 
            MMI_EVENT_INFO);

        datejust_reminder_shown = MMI_TRUE;
    }
#endif /* defined(__MMI_DATE_TIME_SETTING_REMINDER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_eg_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void nor_sweep_device(void);

static void mmi_idle_set_eg_events(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL egIsSet = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!egIsSet)
    {
        nor_sweep_device();
        egIsSet = 1;
    }
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_start_keypad_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_start_keypad_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_set_eg_events();

    if (!g_keylock_context.gKeyPadLockFlag) /* keypad isn't lock now */
    {
        SETTING_AKPL_TIME GetAutoLockTimeOut = GetAutoKeypadLockTime();

        switch (GetAutoLockTimeOut)
        {
            case TIME_0:
                g_idle_context.AutoLockTimeOut = 0;
                break;
            case TIME_5:
                g_idle_context.AutoLockTimeOut = 5000;
                break;
            case TIME_30:
                g_idle_context.AutoLockTimeOut = 30000;
                break;
            case TIME_60:
                g_idle_context.AutoLockTimeOut = 60000;
                break;
            case TIME_2:
                g_idle_context.AutoLockTimeOut = 300000;
                break;
        }

        if (g_idle_context.AutoLockTimeOut != 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_KEYPAD_LOCK_START, g_idle_context.AutoLockTimeOut);
            if (mmi_idle_is_on_idle_screen())
            {
            #ifdef __MMI_FANCY_SCREEN_LOCK__
                StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, mmi_idle_fhl_entry);
            #else
                StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, IdleSetKeyPadLockFlag);
            #endif
            }
            else
            {
                StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, InsertSimSetKeyPadLockFlag);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_restart_keypad_lock_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_restart_keypad_lock_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag == 1)
    {
        return;
    }

    if (g_idle_context.AutoLockTimeOut != 0 &&
        (g_idle_context.IsOnIdleScreen == 1 || g_idle_context.IsOnSimErrorScreen == 1))
    {
        StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
        if (g_idle_context.IsOnIdleScreen == 1)
        {
        #ifdef __MMI_FANCY_SCREEN_LOCK__
            StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, mmi_idle_fhl_entry);
        #else
            StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, IdleSetKeyPadLockFlag);
        #endif
        }
        if (g_idle_context.IsOnSimErrorScreen == 1)
        {
            StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, g_idle_context.AutoLockTimeOut, InsertSimSetKeyPadLockFlag);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_start_screensaver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_start_screensaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ScreenSaverStatus, ScreenSaverWait;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetGetScrSvrSetings(&ScreenSaverStatus, &ScreenSaverWait);

    if (ScreenSaverStatus == 0xFF)
    {
        PhnsetRstScrSvrDefault();
    }

    if (ScreenSaverStatus == 1) /* Screensaver is set to on */
    {
        StartTimer(SCREENSAVER_TIMER, ScreenSaverWait * 1000, EntryIdleSetScreenSaver);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_restart_screensaver_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_restart_screensaver_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ScreenSaverStatus, ScreenSaverWait;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.ScreenSaverRunFlag == 1) /* screensaver is running */
    {
        return;
    }

    if (g_idle_context.IsOnIdleScreen == 1)
    {
        PhnsetGetScrSvrSetings(&ScreenSaverStatus, &ScreenSaverWait);
        if (ScreenSaverStatus == 0xFF)
        {
            PhnsetRstScrSvrDefault();
        }

        if (ScreenSaverStatus == 1) /* screensaver is active */
        {
            StopTimer(SCREENSAVER_TIMER);
            StartTimer(SCREENSAVER_TIMER, ScreenSaverWait * 1000, EntryIdleSetScreenSaver);
        }
    }
}


/* For the detail information, please refer to IdleAppGprot.h */
pBOOL mmi_idle_is_on_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.IsOnIdleScreen == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/* For the detail information, please refer to IdleAppGprot.h */
pBOOL mmi_idle_is_screensaver_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.ScreenSaverRunFlag == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


#ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_icon_shortcut_set_hdlr
 * DESCRIPTION
 *  This function sets the handler for the idle icon shortcuts.
 * PARAMETERS
 *  idx         : [IN]      Index of the icon shortcut
 *  hdlr        : [IN]      Handler associated with this shortcut icon
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_icon_shortcut_set_hdlr(S32 idx, FuncPtr hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(idx >= 0 && idx < MMI_IDLE_MAX_ICON_SHORTCUT);
    
    g_idle_context.icon_shortcut_hdlr[idx] = hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_icon_shortcut_exec_hdlr
 * DESCRIPTION
 *  This function executes the handler for the idle icon shortcuts.
 * PARAMETERS
 *  idx         : [IN]      Index of the shortcut to be launched
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_icon_shortcut_exec_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(idx >= 0 && idx < MMI_IDLE_MAX_ICON_SHORTCUT);

    if (g_idle_context.icon_shortcut_hdlr[idx])
    {
        g_idle_context.icon_shortcut_hdlr[idx]();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_enable_idle_icon_shortcut
 * DESCRIPTION
 *  This function enables the idle screen icon shortcuts functionality. The 
 *  parameters passed to WGUI must be static because WGUI does not internally
 *  save it.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_enable_idle_icon_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static PU8     hint[MMI_IDLE_MAX_ICON_SHORTCUT];
    static PU8     icon1[MMI_IDLE_MAX_ICON_SHORTCUT];
    static PU8     icon2[MMI_IDLE_MAX_ICON_SHORTCUT];
    S32 idx = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
     * Audio player:
     */
#ifdef __MMI_AUDIO_PLAYER__
    mmi_idle_icon_shortcut_set_hdlr(idx, mmi_audply_entry_main);
    hint[idx]  = (PU8)GetString(STR_ID_IDLE_ICON_SHORTCUT_HINT_AUDIO);
    icon1[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_AUDIO_DOWN);
    icon2[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_AUDIO_UP);
    ++idx;
#endif /* __MMI_AUDIO_PLAYER__ */

    /*
     * Browser:
     */
#ifdef WAP_SUPPORT
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE) || 
        (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE) ||
        (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE) ||
        (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY))
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_idle_icon_shortcut_set_hdlr(idx, goto_mobile_suite_screen);
        hint[idx]  = (PU8)GetString(STR_ID_IDLE_ICON_SHORTCUT_HINT_BROWSER);
        icon1[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_BROSWER_DOWN);
        icon2[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_BROSWER_UP);
        ++idx;
    }
#endif /* WAP_SUPPORT */

    /*
     * Dial pad:
     */
    mmi_idle_icon_shortcut_set_hdlr(idx, mmi_idle_entry_dialer);
    hint[idx]  = (PU8)GetString(STR_ID_IDLE_ICON_SHORTCUT_HINT_DIAL);
    icon1[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_DIAL_DOWN);
    icon2[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_DIAL_UP);
    ++idx;

    /*
     * Message:
     */
#ifdef __MOD_SMSAL__
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE) || 
        (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE) ||
        (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE) ||
        (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY))
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_idle_icon_shortcut_set_hdlr(idx, mmi_um_entry_main_message_menu);
        hint[idx]  = (PU8)GetString(STR_ID_IDLE_ICON_SHORTCUT_HINT_MG);
        icon1[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_MG_DOWN);
        icon2[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_MG_UP);
        ++idx;
    }
#endif /* __MOD_SMSAL__ */

    /*
     * Call log: 
     */
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE) || 
        (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE) ||
        (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE)
#ifdef __MMI_VOIP__
     || (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
#endif
       )
    {
        mmi_idle_icon_shortcut_set_hdlr(idx, MTPNP_PFAL_ReadDualMixedCallLog);
    #ifndef __MMI_CH_MIXED_CALL_LOG__
        hint[idx]  = (PU8)GetString(STR_GLOBAL_DIALLED_CALLS);
    #else
        hint[idx]  = (PU8)GetString(STR_ID_IDLE_ICON_SHORTCUT_HINT_ALL_CALLS);
    #endif
        icon1[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_MISSCALL_DOWN);
        icon2[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_MISSCALL_UP);
        ++idx;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
#ifndef __MMI_VOIP__
    if (mmi_bootup_is_sim_valid() &&
        mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)
#endif /* __MMI_VOIP__ */
    {
        mmi_idle_icon_shortcut_set_hdlr(idx, CHISTGetCallLogBySENDKey);
    #ifndef __MMI_CH_MIXED_CALL_LOG__
        hint[idx]  = (PU8)GetString(STR_GLOBAL_DIALLED_CALLS);
    #else
        hint[idx]  = (PU8)GetString(STR_ID_IDLE_ICON_SHORTCUT_HINT_ALL_CALLS);
    #endif
        icon1[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_MISSCALL_DOWN);
        icon2[idx] = (U8*)GetImage(IMG_ID_IDLE_ICON_SHORTCUT_MISSCALL_UP);
        ++idx;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (idx > 0)
    {
        wgui_cat033_enable_icon_shortcut_bar_display(
            idx, 
            mmi_idle_icon_shortcut_exec_hdlr, 
            hint, 
            icon1, 
            icon2);
    }
}
#endif /* __MMI_IDLE_SCREEN_ICON_SHORTCUT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_softkey_area_present
 * DESCRIPTION
 *  This function checks whether the softkey area is present on the idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_idle_is_softkey_area_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    if (mmi_idle_is_display_touch_shortcuts())
    {
        ret = MMI_FALSE;
    }
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */

#if defined(__MMI_VUI_HOMESCREEN__)
    if (mmi_vhs_is_enable())
    {
        ret = MMI_FALSE;
    }
#endif /* __MMI_VUI_HOMESCREEN__ */

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_lsk
 * DESCRIPTION
 *  Set up LSK, RSK and CSK. If the softkey area of the idle screen already
 *  has other UI component (e.g., the native idle screen with the idle 
 *  shortcut or the Venus idle screen), we cannot use 
 *  Set[Left|Right|Center]SoftKey handler. We should use SetKeyHandler.
 * PARAMETERS
 *  hdlr            : [IN]      Key handler
 *  event           : [IN]      Key event type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_lsk(FuncPtr hdlr, mmi_key_types_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_idle_is_softkey_area_present())
    {
        SetLeftSoftkeyFunction(hdlr, event);
    }
    else
    {
        SetKeyHandler(hdlr, KEY_LSK, event);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_rsk
 * DESCRIPTION
 *  Set up LSK, RSK and CSK. If the softkey area of the idle screen already
 *  has other UI component (e.g., the native idle screen with the idle 
 *  shortcut or the Venus idle screen), we cannot use 
 *  Set[Left|Right|Center]SoftKey handler. We should use SetKeyHandler.
 * PARAMETERS
 *  hdlr            : [IN]      Key handler
 *  event           : [IN]      Key event type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_rsk(FuncPtr hdlr, mmi_key_types_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_idle_is_softkey_area_present())
    {
        SetRightSoftkeyFunction(hdlr, event);
    }
    else
    {
        SetKeyHandler(hdlr, KEY_RSK, event);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_csk
 * DESCRIPTION
 *  Set up LSK, RSK and CSK. If the softkey area of the idle screen already
 *  has other UI component (e.g., the native idle screen with the idle 
 *  shortcut or the Venus idle screen), we cannot use 
 *  Set[Left|Right|Center]SoftKey handler. We should use SetKeyHandler.
 * PARAMETERS
 *  hdlr            : [IN]      Key handler
 *  event           : [IN]      Key event type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_csk(FuncPtr hdlr, mmi_key_types_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_idle_is_softkey_area_present())
    {
        SetCenterSoftkeyFunction(hdlr, event);
    }
    else
    {
        SetKeyHandler(hdlr, KEY_CSK, event);
    }
}

/* Vogins Start */
#if defined(__VRE_V30__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)
/*add by jqzhu*/
extern void vm_process_status_qqicon(void);
extern void vm_process_status_fetionicon(void);
extern void vm_process_status_msnicon(void);
extern void vm_process_status_pushmailicon(void);
extern void vm_process_status_defaulticon(void);
extern void vm_register_status_icon_pen_event(void);
#endif
/* Vogins End */
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_handler
 * DESCRIPTION
 *  This function sets the key handler for the idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_set_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)
    /* Venus home screen uses END key for manual keypad lock. */
    wgui_status_icon_bar_register_pen_event_handler(
        STATUS_ICON_KEYPAD_LOCK,
        WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
        IdleSetKeyPadLockFlag);
/* Vogins Start */
#ifdef __VRE_V30__ 
    vm_register_status_icon_pen_event();
#endif
/* Vogins End */
#endif /* defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__) */ 

    mmi_idle_set_digit_key_handler();

    /*
     * Set up LSK, RSK and CSK. If the softkey area of the idle screen already
     * has other UI component (e.g., the native idle screen with the idle 
     * shortcut or the Venus idle screen), we cannot use 
     * Set[Left|Right|Center]SoftKey handler. We should use SetKeyHandler.
     */
    IdleSetLRKey();

#if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_VUI_HOMESCREEN__)
    if (!mmi_vhs_is_enable())
#endif
    {
    #if !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && \
        !defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
        mmi_idle_set_csk(mmi_idle_entry_dialer, KEY_EVENT_UP);
    #endif

    #if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
        if (!mmi_idle_is_display_touch_shortcuts())
        {
            mmi_idle_set_csk(mmi_idle_entry_dialer, KEY_EVENT_UP);
        }
    #endif
    }
#endif /* defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__) */

    /* Voice Recognition */
#ifdef __MMI_VRSD__
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_UsableSide() >= MTPNP_AD_SIMCARD1_USABLE)
#endif
    {
        mmi_idle_set_rsk(mmi_vrsd_rcg_pre_entry, KEY_LONG_PRESS);
    }
#endif /* __MMI_VRSD__ */

#ifdef __MMI_VRSI__
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_UsableSide() >= MTPNP_AD_SIMCARD1_USABLE)
#endif
    {
        mmi_idle_set_rsk(mmi_vrsi_rcg_pre_entry, KEY_LONG_PRESS);
    }
#endif /* __MMI_VRSI__ */

    /*
     * Set up other key handlers.
     */

#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_vhs_is_enable())
    {
        SetKeyHandler(vadp_p2v_hs_rotate_desktop, KEY_ENTER, KEY_EVENT_DOWN);
    }

    /* Allow to keypad lock even if the Venus home screen is off. */
    SetKeyHandler(mmi_vhs_entry_lock_keypad_confirm, KEY_END, KEY_EVENT_UP);
#endif /* __MMI_VUI_HOMESCREEN__ */

    /* for 4-dedicated shortcuts */
#if defined(__MMI_OP01_DCD__)
    if (MMI_TRUE == mmi_dcd_is_switch_on() && MMI_TRUE == mmi_dcd_is_idle_on())
    {
        SetKeyHandler(mmi_dcd_idle_prev_channel, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dcd_idle_next_channel, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dcd_idle_prev_entry, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dcd_idle_next_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
    #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
        RegisterDedicatedKeyHandlers();
    #elif !defined(__DISABLE_SHORTCUTS_MENU__)
        SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
                
    #ifdef __MMI_SEARCH_WEB__
        if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY))
        {
            SetKeyHandler(mmi_search_web_trigger_by_down_key, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        }
    #endif /* __MMI_SEARCH_WEB__ */
        
    #endif 
    }
#elif defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    RegisterDedicatedKeyHandlers();
#elif !defined(__DISABLE_SHORTCUTS_MENU__)
    SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_SEARCH_WEB__
    if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY))
    {
        SetKeyHandler(mmi_search_web_trigger_by_down_key, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    }
    #endif /* __MMI_SEARCH_WEB__ */
#endif 

#ifdef __MMI_KLG__
    SetKeyHandler(mmi_fmgr_launch, KEY_EXTRA_1, KEY_EVENT_UP);
    SetKeyHandler(ClndrPreEntryApp, KEY_EXTRA_2, KEY_EVENT_UP);
#endif /* __MMI_KLG__ */ 

#ifdef __MMI_DUAL_SIM_MASTER__
#ifdef __SENDKEY2_SUPPORT__
    if ((MTPNP_AD_Get_UsableSide() ==MTPNP_AD_DUALSIM_USABLE) ||(MTPNP_AD_Get_UsableSide() ==MTPNP_AD_SIMCARD1_USABLE))
    {
        SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_SEND1, KEY_EVENT_DOWN);
    }
    if ((MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE) || (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE))
    {
        SetKeyHandler(MTPNP_PFAL_chist_slave_req_read_mixed_num_by_key, KEY_SEND2, KEY_EVENT_DOWN);
    }
#else /* __SENDKEY2_SUPPORT__ */
    if ((MTPNP_AD_Get_UsableSide() ==MTPNP_AD_DUALSIM_USABLE) ||(MTPNP_AD_Get_UsableSide() ==MTPNP_AD_SIMCARD1_USABLE) ||(MTPNP_AD_Get_UsableSide() ==MTPNP_AD_SIMCARD2_USABLE))
    {
        SetKeyHandler(MTPNP_PFAL_ReadDualMixedCallLog, KEY_SEND, KEY_EVENT_DOWN);  /* diamond, 2005/09/13 key event DOWN to UP */
    }
#endif /* __SENDKEY2_SUPPORT__ */
#else /* __MMI_DUAL_SIM_MASTER__ */
#ifndef __MMI_VOIP__
    if (mmi_bootup_is_sim_valid() && mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)
#endif /* __MMI_VOIP__ */
    {
        SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_SEND, KEY_EVENT_DOWN);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_OP01_DCD__)
    if (MMI_TRUE == mmi_dcd_is_switch_on() && MMI_TRUE == mmi_dcd_is_idle_on())
    {
        SetKeyHandler(mmi_dcd_idle_to_story_viewer, KEY_WAP, KEY_EVENT_UP);
    #if defined(WAP_SUPPORT) && defined(__MMI_WITH_WAP_KEY__)
    #ifdef __MMI_OP01_WITH_WAP_KEY__
/* under construction !*/
    #endif /* __MMI_OP01_WITH_WAP_KEY__ */
    #endif /*defined(WAP_SUPPORT) && defined(__MMI_WITH_WAP_KEY__)*/
    }
    else
    {
    #if defined(WAP_SUPPORT) && defined(__MMI_WITH_WAP_KEY__)
    #ifdef __MMI_OP01_WITH_WAP_KEY__
/* under construction !*/
/* under construction !*/
    #else 
        SetKeyHandler(wap_internet_key_hdlr, KEY_WAP, KEY_LONG_PRESS);
    #endif 
    #endif /* defined(WAP_SUPPORT) && defined(__MMI_WITH_WAP_KEY__) */ 
    }
#elif defined(WAP_SUPPORT) && defined(__MMI_WITH_WAP_KEY__)
#ifdef __MMI_OP01_WITH_WAP_KEY__
/* under construction !*/
#elif defined(__MMI_OP02_WITH_WAP_KEY__)
    SetKeyHandler(wap_internet_key_hdlr, KEY_WAP, KEY_EVENT_UP);
#else 
    SetKeyHandler(wap_internet_key_hdlr, KEY_WAP, KEY_LONG_PRESS);
#endif 
#endif 

    /* camera fast access key */
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
    SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
#ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose())
        SetKeyHandler(mmi_sublcd_camera_entry_option_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    else
        SetKeyHandler(mmi_camera_lauch, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
#else
    SetKeyHandler(mmi_camera_lauch, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
#endif /* __MMI_SUBLCD_CAMERA__ */
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
    SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_camco_launch, KEY_CAMERA, KEY_EVENT_DOWN);
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */

#ifdef __MMI_MAPBAR_GIS__
    SetKeyHandler(mmi_gis_enter_app_check_conform, KEY_EXTRA_2, KEY_EVENT_UP);
#endif

    /* volume key */
    SetDefaultVolumeKeyHandlers();

#ifdef __FLIGHT_MODE_SUPPORT__
    mmi_flight_mode_need_play_camp_on_tone();
#endif

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY || 
        mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
    {
        mmi_idle_set_dial_mode(DIAL_MODE_WLAN);
    }
    else
    {
        mmi_idle_set_dial_mode(DIAL_MODE_GSM);
    }
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_idle_screen
 * DESCRIPTION
 *  Idle screen with/without keypad lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if (mmi_op11_hs32_is_enable())
    {
        mmi_op11_hs32_entry_homescreen();
    }
    else
#endif            
#if defined(__MMI_VUI_HOMESCREEN__)
    if (mmi_vhs_is_enable())
    {
    #ifdef __MMI_VUI_3D_CUBE_APP__
        mmi_cube_vapp_show_homescreen();
    #else
        mmi_vhs_show_homescreen();
    #endif
    }
    else
#endif
    {
        IdleRefreshServiceIndicationArea();

    #if defined(__MMI_WGUI_CSK_ENABLE__) && \
        defined(__MMI_TOUCH_SCREEN__) && \
        !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && \
        !defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    #endif 

    #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
        if (!mmi_idle_is_display_touch_shortcuts())
        {
            EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
        }
    #endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */

    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
        if (PhnsetGetCalendarIdleScreen() != 0)
        {
            idle_screen_enable_calendar_display();
        }
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

    #ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
        mmi_idle_enable_idle_icon_shortcut();
    #endif

    #ifdef __MMI_SWFLASH__
        if (dispchar_iswp_swflash() == MMI_TRUE)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT, 
                IDLE_SCREEN_LSK_ICON, 
                idleRskStringID, 
                IDLE_SCREEN_RSK_ICON, 
                PhnsetGetCurWallPaperIdx(), 
                idle_screen_wallpaper_name, 
                NULL);
        }
        else
    #endif /* _MMI_SWFLASH__ */
    #ifdef __MMI_AVATAR__
        if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT, 
                IDLE_SCREEN_LSK_ICON, 
                idleRskStringID, 
                IDLE_SCREEN_RSK_ICON, 
                PhnsetGetCurWallPaperIdx(), 
                NULL, 
                NULL);
        }
        else
    #endif /* __MMI_AVATAR__ */
        {
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            ShowCategory33Screen(
                idleRskStringID
                IDLE_SCREEN_RSK_ICON,
                IDLE_SCREEN_LSK_TEXT,
                IDLE_SCREEN_LSK_ICON,
                NULL);
        #else 
            ShowCategory33Screen(
                IDLE_SCREEN_LSK_TEXT,
                IDLE_SCREEN_LSK_ICON,
                idleRskStringID,
                IDLE_SCREEN_RSK_ICON,
                NULL);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */
            mmi_phnset_save_wallpaper_to_speedup();
        }
    }
    g_idle_context.LongPressEnable = 0;

#ifdef __MMI_TOUCH_DIAL_SCREEN__
    memset((U8*) g_idle_context.DialPadCallBuffer, 0, sizeof((U8*) g_idle_context.DialPadCallBuffer));
#endif 

    mmi_idle_set_handler();
    ClearKeyEvents();

    ForceSubLCDScreen(ShowIdleAppSubLcd);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_searching_screen
 * DESCRIPTION
 *  Searching screen with/without keypad lock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_searching_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_keylock_context.gKeyPadLockFlag)
    {
    #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP11_HOMESCREEN__ */

    #ifdef __MMI_OP12_TOOLBAR__
        if (mmi_tb_is_enable())
        {
            mmi_tb_entry_toolbar();
            return;
        }
    #endif /* __MMI_OP12_TOOLBAR__ */
    
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        if (mmi_op11_hs32_is_enable())
        {
            mmi_op11_hs32_entry_homescreen();
        }
        else    
    #endif            
    #if defined(__MMI_VUI_HOMESCREEN__)
        if (mmi_vhs_is_enable())
        {
        #ifdef __MMI_VUI_3D_CUBE_APP__
            mmi_cube_vapp_show_homescreen();
        #else
            mmi_vhs_show_homescreen();
        #endif
        }
        else
    #endif /* __MMI_VUI_HOMESCREEN__ */
        {
            /* diamond, 2005/07/22 240x320 sync searching screen style with idle screen style */
        #ifdef __MMI_IDLE_NO_NW_SEARCHING_SCREEN__
            IdleRefreshServiceIndicationArea();

        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
            if (PhnsetGetCalendarIdleScreen() != 0)
            {
                idle_screen_enable_calendar_display();
            }
        #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

        #ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
            mmi_idle_enable_idle_icon_shortcut();
        #endif

        #ifdef __MMI_SWFLASH__
            if (dispchar_iswp_swflash() == MMI_TRUE)
            {
                ShowCategory34Screen(
                    IDLE_SCREEN_LSK_TEXT, 
                    IDLE_SCREEN_LSK_ICON, 
                    idleRskStringID, 
                    IDLE_SCREEN_RSK_ICON, 
                    PhnsetGetCurWallPaperIdx(), 
                    idle_screen_wallpaper_name, 
                    NULL);
            }
            else
        #endif /* _MMI_SWFLASH__ */
        #ifdef __MMI_AVATAR__
            if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
            {
                ShowCategory34Screen(
                    IDLE_SCREEN_LSK_TEXT, 
                    IDLE_SCREEN_LSK_ICON, 
                    idleRskStringID, 
                    IDLE_SCREEN_RSK_ICON, 
                    PhnsetGetCurWallPaperIdx(), 
                    NULL, 
                    NULL);
            }
            else
        #endif /* __MMI_AVATAR__ */
            {
            #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
                ShowCategory33Screen(
                    idleRskStringID,
                    IDLE_SCREEN_RSK_ICON,
                    IDLE_SCREEN_LSK_TEXT,
                    IDLE_SCREEN_LSK_ICON,
                    NULL);
            #else 
                ShowCategory33Screen(
                    IDLE_SCREEN_LSK_TEXT,
                    IDLE_SCREEN_LSK_ICON,
                    idleRskStringID,
                    IDLE_SCREEN_RSK_ICON,
                    NULL);
            #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */
                mmi_phnset_save_wallpaper_to_speedup();
            }
        #else /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            ShowCategory120Screen(
                idleRskStringID,
                IDLE_SCREEN_RSK_ICON,
                IDLE_SCREEN_LSK_TEXT,
                IDLE_SCREEN_LSK_ICON,
                STR_GLOBAL_SEARCHING,
                IMG_IDLE_NETWORK_SRCH_SCR,
                NULL);
        #else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
            ShowCategory120Screen(
                IDLE_SCREEN_LSK_TEXT,
                IDLE_SCREEN_LSK_ICON,
                idleRskStringID,
                IDLE_SCREEN_RSK_ICON,
                STR_GLOBAL_SEARCHING,
                IMG_IDLE_NETWORK_SRCH_SCR,
                NULL);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */ 
        #endif /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */ 
        }
        g_idle_context.LongPressEnable = 0;
        
    #ifdef __MMI_TOUCH_DIAL_SCREEN__
        memset((U8*) g_idle_context.DialPadCallBuffer, 0, sizeof((U8*) g_idle_context.DialPadCallBuffer));
    #endif 
        
        mmi_idle_set_handler();
        ClearKeyEvents();
        
        ForceSubLCDScreen(ShowIdleAppSubLcd);
    }
    else
    {
        mmi_idle_set_keypad_lock_string();

    #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP11_HOMESCREEN__ */

    #ifdef __MMI_OP12_TOOLBAR__
        if (mmi_tb_is_enable())
        {
            mmi_tb_entry_toolbar();
            mmi_idle_generic_keypad_lock_key_hdlr();
            return;
        }
    #endif /* __MMI_OP12_TOOLBAR__ */

    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        if (mmi_op11_hs32_is_enable())
        {
            mmi_op11_hs32_entry_homescreen();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
        else
    #endif            
    #ifdef __MMI_VUI_HOMESCREEN__
        if (mmi_vhs_is_enable())
        {
        #ifdef __MMI_VUI_3D_CUBE_APP__
            mmi_cube_vapp_show_homescreen();
        #else
            mmi_vhs_show_homescreen();
        #endif
        }
        else
    #endif /* __MMI_VUI_HOMESCREEN__ */
        {
        #ifdef __MMI_IDLE_NO_NW_SEARCHING_SCREEN__
            IdleRefreshServiceIndicationArea();

        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
            if (PhnsetGetCalendarIdleScreen() != 0)
            {
                idle_screen_enable_calendar_display();
            }
        #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

        #ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
            mmi_idle_enable_idle_icon_shortcut();
        #endif

        #ifdef __MMI_SWFLASH__
            if (dispchar_iswp_swflash() == MMI_TRUE)
            {
                ShowCategory34Screen(
                    g_keylock_context.KeyLockLSKStringID,
                    g_keylock_context.KeyLockLSKIconID,
                    g_keylock_context.KeyLockRSKStringID,
                    g_keylock_context.KeyLockRSKIconID,
                    PhnsetGetCurWallPaperIdx(), 
                    idle_screen_wallpaper_name, 
                    NULL);
             }
             else
        #endif /* _MMI_SWFLASH__ */        
        #ifdef __MMI_AVATAR__
            if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
            {
                ShowCategory34Screen(
                    g_keylock_context.KeyLockLSKStringID,
                    g_keylock_context.KeyLockLSKIconID,
                    g_keylock_context.KeyLockRSKStringID,
                    g_keylock_context.KeyLockRSKIconID,
                    PhnsetGetCurWallPaperIdx(), 
                    NULL, 
                    NULL);
            }
            else
        #endif /* __MMI_AVATAR__ */
            {
                ShowCategory33Screen(
                    g_keylock_context.KeyLockLSKStringID,
                    g_keylock_context.KeyLockLSKIconID,
                    g_keylock_context.KeyLockRSKStringID,
                    g_keylock_context.KeyLockRSKIconID,
                    NULL);
                mmi_phnset_save_wallpaper_to_speedup();
            }
        #else /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */ 
            ShowCategory120Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                STR_GLOBAL_SEARCHING,
                IMG_IDLE_NETWORK_SRCH_SCR,
                NULL);
        #endif /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */ 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_key_event_backlight_check
 * DESCRIPTION
 *  Check backlight when key event occurs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_key_event_backlight_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_keylock_context.gKeyPadLockFlag && (g_idle_context.IsOnIdleScreen || g_idle_context.IsOnSimErrorScreen)) ||
        (g_keylock_context.gKeyPadLockFlag && g_idle_context.ScreenSaverRunFlag))
    {
        HalfModeBacklight();
    }
    else
    {
        TurnOnBacklight(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_key_event_keypad_lock_check
 * DESCRIPTION
 *  Handle the case of keypad timer is running in idle screen but the key event is not POUND key
 * PARAMETERS
 *  eventKey                [?]         
 *  KEYBRD_MESSAGE(?)       [IN]        *eventKey
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_key_event_keypad_lock_check(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsMyTimerExist(KEYPAD_LOCK_TIMER) == MMI_TRUE)
    {
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
        if ((S16) eventKey->nKeyCode != KEY_POUND)
        {
            IdleHandleKeypadLockProcess();
        }
    #endif /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
        if ((S16) eventKey->nKeyCode != KEY_STAR)
        {
            IdleHandleKeypadLockProcess();
        }
    #endif /* __MMI_KEYPAD_LOCK_PATTERN_2__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  DeInitSpecialMode
 * DESCRIPTION
 *  DeInit Special Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if (defined(__MMI_ENGINEER_MODE__) || defined(__MMI_FACTORY_MODE__))
U8 gCurrentMode = NORMAL_MODE;
#endif 

/* Reset special function for special mode */
void DeInitSpecialMode(void)
{
#ifdef __MMI_ENGINEER_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gCurrentMode == ENGINEERING_MODE)
    {
        gCurrentMode = NORMAL_MODE;
        mdi_audio_resume_background_play();
        StartLEDPatternBackGround();
    }
#endif /* __MMI_ENGINEER_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  SearchingSrceenTimeOutHandler
 * DESCRIPTION
 *  This function is a call back for searching screen expire
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SearchingSrceenTimeOutHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (!g_pwr_context.IsCampOnTonePlayed &&
        !g_pwr_context_2.IsCampOnTonePlayed &&
         mmi_bootup_is_in_sim2_security_check())
    {
        StartTimer(SEARCHING_SCREEN_TIMER, 10000, SearchingSrceenTimeOutHandler);
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG; /* 0x01: network attachment timeout */
    g_pwr_context.IsCampOnTonePlayed = 1; /* Camp on tone will not be played after the timeout */
#ifdef __MMI_DUAL_SIM_MASTER__
    g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
    g_pwr_context_2.IsCampOnTonePlayed = 1;
#endif

    if (g_idle_context.IsOnIdleScreen)
    {
        mmi_bootup_exit_network_searching();
    }

    mmi_bootup_notify_searching_completed(SIM1);
    mmi_bootup_notify_searching_completed(SIM2);
}


/*****************************************************************************
 * FUNCTION
 *  DisplayIdleScreen
 * DESCRIPTION
 *  Shows the idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
     if (mmi_op11_hs32_is_enable())
     {
        mmi_op11_hs32_discard_history();
     }
#endif /* __MMI_OP11_HOMESCREEN_0301__ */

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#ifdef __MMI_OP12_TOOLBAR__
    if (mmi_tb_is_enable())
    {
        mmi_tb_discard_history();
    }
#endif /* __MMI_OP12_TOOLBAR__ */

    /* Execute the root history */
    ExecuteRootMainHistoryScreen(NULL);

    OrgDeInit();

#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    mmi_vobj_deinit();
#endif 

    AlmEnableSPOF();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_bootup_ready_to_certman
 * DESCRIPTION
 *  Send message to Certificate Manager for idle screen notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_bootup_ready_to_certman(void)
{
#ifdef __CERTMAN_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_CERTMAN;
    Message.oslMsgId = MSG_ID_MMI_READY_NOTIFY_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_dual_sim_status
 * DESCRIPTION
 *  Provide MMI level API for dual sim status (vendor request)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_get_dual_sim_status(U8 *sim_status, U8* mode_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim_valid())
    {
        if (mmi_bootup_is_sim2_valid())
        {
            *sim_status = MMI_SIM_ID_DUAL_SIM;
        }
        else
        {
            *sim_status = MMI_SIM_ID_SIM1;
        }
    }
    else
    {
        if (mmi_bootup_is_sim2_valid())
        {
            *sim_status = MMI_SIM_ID_SIM2;
        }
        else
        {
            *sim_status = MMI_SIM_ID_NO_SIM;
        }
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    *sim_status = mmi_bootup_is_sim_valid() ? MMI_SIM_ID_SIM1 : MMI_SIM_ID_NO_SIM;
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_MASTER__
    switch(MTPNP_AD_Get_Startup_Mode())
    {
        case MTPNP_AD_NVRAM_CARD1:
            *mode_status = MMI_SIM_ID_SIM1;
        break;

        case MTPNP_AD_NVRAM_CARD2:
            *mode_status = MMI_SIM_ID_SIM2;
        break;

        case MTPNP_AD_NVRAM_FLIGHT:
            *mode_status = MMI_SIM_ID_FLIGHT_MODE;
        break;

        case MTPNP_AD_NVRAM_DUALCARD:
        default:
            *mode_status = MMI_SIM_ID_DUAL_SIM;
        break;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    *mode_status = mmi_bootup_get_active_flight_mode() ? MMI_SIM_ID_FLIGHT_MODE: MMI_SIM_ID_SIM1;
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_dual_sim_status_to_mms
 * DESCRIPTION
 *  Send message to MMS for SIM info notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_dual_sim_status_to_mms(void)
{
#ifdef OBIGO_Q03C_MMS_V02
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mms_sim_info_notify_ind_struct *sim_info_notify_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_info_notify_ind = (mms_sim_info_notify_ind_struct *) OslConstructDataPtr(sizeof(mms_sim_info_notify_ind_struct));

#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim_valid())
    {
        if (mmi_bootup_is_sim2_valid())
        {
            sim_info_notify_ind->sim_status = MMS_SIM_ID_DUAL_SIM;
        }
        else
        {
            sim_info_notify_ind->sim_status = MMS_SIM_ID_SIM1;
        }
    }
    else
    {
        if (mmi_bootup_is_sim2_valid())
        {
            sim_info_notify_ind->sim_status = MMS_SIM_ID_SIM2;
        }
        else
        {
            sim_info_notify_ind->sim_status = MMS_SIM_ID_NO_SIM;
        }
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    sim_info_notify_ind->sim_status = mmi_bootup_is_sim_valid() ? MMS_SIM_ID_SIM1 : MMS_SIM_ID_NO_SIM;
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_MASTER__
    switch(MTPNP_AD_Get_Startup_Mode())
    {
        case MTPNP_AD_NVRAM_CARD1:
            sim_info_notify_ind->setting_mode = MMS_SIM_ID_SIM1;
        break;

        case MTPNP_AD_NVRAM_CARD2:
            sim_info_notify_ind->setting_mode = MMS_SIM_ID_SIM2;
        break;

        case MTPNP_AD_NVRAM_FLIGHT:
            sim_info_notify_ind->setting_mode = MMS_SIM_ID_FLIGHT_MODE;
        break;

        case MTPNP_AD_NVRAM_DUALCARD:
        default:
            sim_info_notify_ind->setting_mode = MMS_SIM_ID_DUAL_SIM;
        break;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    sim_info_notify_ind->setting_mode = mmi_bootup_get_active_flight_mode() ? MMS_SIM_ID_FLIGHT_MODE: MMS_SIM_ID_SIM1;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMS;
    Message.oslMsgId = MSG_ID_MMS_SIM_INFO_NOTIFY_IND;
    Message.oslDataPtr = (oslParaType*) sim_info_notify_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* OBIGO_Q03C_MMS_V02 */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_dual_sim_status_to_wap
 * DESCRIPTION
 *  Send message to WAP for SIM info notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_dual_sim_status_to_wap(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_sim_info_notify_ind_struct *sim_info_notify_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_info_notify_ind = (wap_sim_info_notify_ind_struct *) OslConstructDataPtr(sizeof(wap_sim_info_notify_ind_struct));

#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim_valid())
    {
        if (mmi_bootup_is_sim2_valid())
        {
            sim_info_notify_ind->sim_status = WAP_SIM_ID_DUAL_SIM;
        }
        else
        {
            sim_info_notify_ind->sim_status = WAP_SIM_ID_SIM1;
        }
    }
    else
    {
        if (mmi_bootup_is_sim2_valid())
        {
            sim_info_notify_ind->sim_status = WAP_SIM_ID_SIM2;
        }
        else
        {
            sim_info_notify_ind->sim_status = WAP_SIM_ID_NO_SIM;
        }
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    sim_info_notify_ind->sim_status = mmi_bootup_is_sim_valid() ? WAP_SIM_ID_SIM1 : WAP_SIM_ID_NO_SIM;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (mmi_bootup_is_sim_removed())
    {
        sim_info_notify_ind->sim1_type = WAP_SIM_TYPE_UNKNOWN;
    }
    else if (!mmi_bootup_is_sim_valid())
    {
        sim_info_notify_ind->sim1_type = WAP_SIM_TYPE_BLOCKED_SIM;
    }
    else if (!mmi_bootup_is_nw_registration_ok())
    {
        sim_info_notify_ind->sim1_type = WAP_SIM_TYPE_INVALID_SIM;
    }
    else
    {
        sim_info_notify_ind->sim1_type = WAP_SIM_TYPE_VALID_SIM;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim2_removed())
    {
        sim_info_notify_ind->sim2_type = WAP_SIM_TYPE_UNKNOWN;
    }
    else if (!mmi_bootup_is_sim2_valid())
    {
        sim_info_notify_ind->sim2_type = WAP_SIM_TYPE_BLOCKED_SIM;
    }
    else if (!mmi_bootup_is_sim2_nw_registration_ok())
    {
        sim_info_notify_ind->sim2_type = WAP_SIM_TYPE_INVALID_SIM;
    }
    else
    {
        sim_info_notify_ind->sim2_type = WAP_SIM_TYPE_VALID_SIM;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    sim_info_notify_ind->sim2_type = WAP_SIM_TYPE_UNKNOWN;
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_MASTER__
    switch(MTPNP_AD_Get_Startup_Mode())
    {
        case MTPNP_AD_NVRAM_CARD1:
            sim_info_notify_ind->setting_mode = WAP_SIM_ID_SIM1;
        break;

        case MTPNP_AD_NVRAM_CARD2:
            sim_info_notify_ind->setting_mode = WAP_SIM_ID_SIM2;
        break;

        case MTPNP_AD_NVRAM_FLIGHT:
            sim_info_notify_ind->setting_mode = WAP_SIM_ID_FLIGHT_MODE;
        break;

        case MTPNP_AD_NVRAM_DUALCARD:
        default:
            sim_info_notify_ind->setting_mode = WAP_SIM_ID_DUAL_SIM;
        break;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    sim_info_notify_ind->setting_mode = mmi_bootup_get_active_flight_mode() ? WAP_SIM_ID_FLIGHT_MODE: WAP_SIM_ID_SIM1;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_SIM_INFO_NOTIFY_IND;
    Message.oslDataPtr = (oslParaType*) sim_info_notify_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* WAP_SUPPORT */ 

    mmi_idle_notify_dual_sim_status_to_mms();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_dual_sim_status_to_spa
 * DESCRIPTION
 *  Send message to SPA application for SIM info notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_dual_sim_status_to_spa(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_sim_status_info_ind_struct *sim_info_notify_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_info_notify_ind = (mmi_sim_status_info_ind_struct *) OslConstructDataPtr(sizeof(mmi_sim_status_info_ind_struct));

    sim_info_notify_ind->sim_id = sim_source;

#ifdef __MMI_DUAL_SIM_MASTER__
    if (!mmi_bootup_is_sim_removed())
    {
        if (!mmi_bootup_is_sim2_removed())
        {
            sim_info_notify_ind->sim_inserted = MMI_SIM_ID_DUAL_SIM;
        }
        else
        {
            sim_info_notify_ind->sim_inserted = MMI_SIM_ID_SIM1;
        }
    }
    else
    {
        if (!mmi_bootup_is_sim2_removed())
        {
            sim_info_notify_ind->sim_inserted = MMI_SIM_ID_SIM2;
        }
        else
        {
            sim_info_notify_ind->sim_inserted = MMI_SIM_ID_NO_SIM;
        }
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    sim_info_notify_ind->sim_inserted = mmi_bootup_is_sim_valid() ? MMI_SIM_ID_SIM1 : MMI_SIM_ID_NO_SIM;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    sim_info_notify_ind->sim1_can_read = mmi_bootup_is_sim_valid() ? MMI_TRUE : MMI_FALSE;

#ifdef __MMI_DUAL_SIM_MASTER__
    sim_info_notify_ind->sim2_can_read = mmi_bootup_is_sim2_valid() ? MMI_TRUE : MMI_FALSE;
#else
    sim_info_notify_ind->sim2_can_read = MMI_FALSE;
#endif

    if (mmi_bootup_is_sim_removed())
    {
        sim_info_notify_ind->sim1_type = MMI_SIM_TYPE_UNKNOWN;
    }
    else if (!mmi_bootup_is_sim_valid())
    {
        sim_info_notify_ind->sim1_type = MMI_SIM_TYPE_BLOCKED_SIM;
    }
    else if (!mmi_bootup_is_nw_registration_ok())
    {
        sim_info_notify_ind->sim1_type = MMI_SIM_TYPE_INVALID_SIM;
    }
    else
    {
        sim_info_notify_ind->sim1_type = MMI_SIM_TYPE_VALID_SIM;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim2_removed())
    {
        sim_info_notify_ind->sim2_type = MMI_SIM_TYPE_UNKNOWN;
    }
    else if (!mmi_bootup_is_sim2_valid())
    {
        sim_info_notify_ind->sim2_type = MMI_SIM_TYPE_BLOCKED_SIM;
    }
    else if (!mmi_bootup_is_sim2_nw_registration_ok())
    {
        sim_info_notify_ind->sim2_type = MMI_SIM_TYPE_INVALID_SIM;
    }
    else
    {
        sim_info_notify_ind->sim2_type = MMI_SIM_TYPE_VALID_SIM;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    sim_info_notify_ind->sim2_type = MMI_SIM_TYPE_UNKNOWN;
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_MASTER__
    switch(MTPNP_AD_Get_Startup_Mode())
    {
        case MTPNP_AD_NVRAM_CARD1:
            sim_info_notify_ind->setting_mode = MMI_SIM_ID_SIM1;
        break;

        case MTPNP_AD_NVRAM_CARD2:
            sim_info_notify_ind->setting_mode = MMI_SIM_ID_SIM2;
        break;

        case MTPNP_AD_NVRAM_FLIGHT:
            sim_info_notify_ind->setting_mode = MMI_SIM_ID_FLIGHT_MODE;
        break;

        case MTPNP_AD_NVRAM_DUALCARD:
        default:
            sim_info_notify_ind->setting_mode = MMI_SIM_ID_DUAL_SIM;
        break;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    sim_info_notify_ind->setting_mode = mmi_bootup_get_active_flight_mode() ? MMI_SIM_ID_FLIGHT_MODE: MMI_SIM_ID_SIM1;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_SIM_STATUS_INFO_IND;
    Message.oslDataPtr = (oslParaType*) sim_info_notify_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_dual_sim_status_to_spa_from_sim1
 * DESCRIPTION
 *  SPA wrapper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_dual_sim_status_to_spa_from_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_notify_dual_sim_status_to_spa(MMI_SIM_ID_SIM1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_dual_sim_status_to_spa_from_sim2
 * DESCRIPTION
 *  SPA wrapper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_dual_sim_status_to_spa_from_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_notify_dual_sim_status_to_spa(MMI_SIM_ID_SIM2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_dual_sim_status_to_spa_from_switch
 * DESCRIPTION
 *  SPA wrapper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_dual_sim_status_to_spa_from_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_notify_dual_sim_status_to_spa(MMI_SIM_ID_DUAL_SIM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_notify_bootup_ready_to_wap
 * DESCRIPTION
 *  Send message to WAP for idle screen notification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_notify_bootup_ready_to_wap(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL wap_ready_sent = MMI_FALSE;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_ready_sent)
    {
        return;
    }

    wap_ready_sent = MMI_TRUE;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_MMI_READY_NOTIFY_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  CheckAndStopAudioPlayer
 * DESCRIPTION
 *  Stop audio player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
extern MMI_BOOL DirectMode;
#endif 

extern void MMI_notify_bootup_ready(void);

#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
static void CheckAndStopAudioPlayer(void)
{
#ifdef __MMI_AUDIO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_is_playing())
    {
        mmi_audply_do_stop_action(MMI_TRUE);
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        mmi_fmrdo_power_on(MMI_FALSE);
    }
    else
#endif /* __MMI_FM_RADIO__ */ 
#ifdef __A8BOX_SUPPORT__
    if (mmi_a8box_is_playing())
    {
        mmi_a8box_enter_cameraapp();
    }
#endif
    #if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    #ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose())
        mmi_sublcd_camera_entry_option_screen();
    else
        mmi_camera_lauch();
    #else
        mmi_camera_lauch();
    #endif /* __MMI_SUBLCD_CAMERA__ */
    #elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
        mmi_camco_launch();
    #endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)*/
}
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */ 


/*****************************************************************************
 * FUNCTION
 *  IdleScreenEmergencyCallCheckNKeypadLock
 * DESCRIPTION
 *  Allow dial SOS number if keypad is locked in idle screen
 * PARAMETERS
 *  eventKey        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 IdleScreenEmergencyCallCheckNKeypadLock(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_sos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag)
    {
        is_sos = EmergencyCallCheck(eventKey->nKeyCode, eventKey->nMsgType);

        if (is_sos)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  RedrawIdleScreen
 * DESCRIPTION
 *  Entry idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IdleRefreshServiceIndicationArea();

    /*
     * Some APP, e.g., UM, will use this function to show a dummy screen before
     * it gets the information to be shown. If the keypad is locked, because the 
     * user will leave the locked screen, the icon will be temporarily removed.
     * Restore the icon here; otherwise, the icon will flash.
     *
     * [MAUI_01586766]
     * For touch screen, we should always show icon for background.
     */
#ifndef __MMI_TOUCH_SCREEN__
    if (g_keylock_context.gKeyPadLockFlag)
#endif
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_KEYPAD_LOCK);
    }
        
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
     if (mmi_op11_hs32_is_enable())
     {
        mmi_op11_hs32_pre_fetch_history();
        mmi_op11_hs32_redraw_homescreen();
        return;
     }
#endif /* __MMI_OP11_HOMESCREEN_0301__ */
        
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#ifdef __MMI_OP12_TOOLBAR__
    if (mmi_tb_is_enable())
    {
        mmi_tb_pre_fetch_history();
        mmi_tb_redraw_toolbar();
        return;
    }
#endif /* __MMI_OP12_TOOLBAR__ */

    if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
    {
    #ifdef __MMI_VUI_HOMESCREEN__
        if (mmi_vhs_is_enable())
        {
        #ifdef __MMI_VUI_3D_CUBE_APP__
            mmi_cube_vapp_show_homescreen();
        #else
            mmi_vhs_show_homescreen();
        #endif
        }
        else
    #endif /* __MMI_VUI_HOMESCREEN__ */
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        if (mmi_op11_hs32_is_enable())
        {
            mmi_op11_hs32_entry_homescreen();
        }
        else
    #endif /* __MMI_OP11_HOMESCREEN_0301__ */
        {   
        #if defined(__MMI_WGUI_CSK_ENABLE__) && \
            defined(__MMI_TOUCH_SCREEN__) && \
            !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && \
            !defined(__MMI_IDLE_SCREEN_ICON_SHORTCUT__)
            EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
        #endif 

        #ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
            if (!mmi_idle_is_display_touch_shortcuts())
            {
                EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
            }
        #endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */

        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
            if (PhnsetGetCalendarIdleScreen() != 0)
            {
                idle_screen_enable_calendar_display();
            }
        #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
        
        #ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
            mmi_idle_enable_idle_icon_shortcut();
        #endif

        #ifdef __MMI_SWFLASH__
            if (dispchar_iswp_swflash() == MMI_TRUE)
            {
                ShowCategory34Screen(
                    IDLE_SCREEN_LSK_TEXT, 
                    IDLE_SCREEN_LSK_ICON, 
                    idleRskStringID, 
                    IDLE_SCREEN_RSK_ICON, 
                    PhnsetGetCurWallPaperIdx(), 
                    idle_screen_wallpaper_name, 
                    NULL);
            }
            else
        #endif /* _MMI_SWFLASH__ */
        #ifdef __MMI_AVATAR__
            if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
            {
                ShowCategory34Screen(
                    IDLE_SCREEN_LSK_TEXT, 
                    IDLE_SCREEN_LSK_ICON, 
                    idleRskStringID, 
                    IDLE_SCREEN_RSK_ICON, 
                    PhnsetGetCurWallPaperIdx(), 
                    NULL,
                    NULL);
            }
            else
        #endif /* __MMI_AVATAR__ */
            {
            #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
                ShowCategory33Screen(
                    idleRskStringID,
                    IDLE_SCREEN_RSK_ICON,
                    IDLE_SCREEN_LSK_TEXT,
                    IDLE_SCREEN_LSK_ICON,
                    NULL);
            #else 
                ShowCategory33Screen(
                    IDLE_SCREEN_LSK_TEXT,
                    IDLE_SCREEN_LSK_ICON,
                    idleRskStringID,
                    IDLE_SCREEN_RSK_ICON,
                    NULL);
            #endif
                mmi_phnset_save_wallpaper_to_speedup();
            }
        }
    }
    else
    {
    #ifdef __MMI_VUI_HOMESCREEN__
        if (mmi_vhs_is_enable())
        {
        #ifdef __MMI_VUI_3D_CUBE_APP__
            mmi_cube_vapp_show_homescreen();
        #else
            mmi_vhs_show_homescreen();
        #endif
        }
        else
    #endif /* __MMI_VUI_HOMESCREEN__ */
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        if (mmi_op11_hs32_is_enable())
        {
            mmi_op11_hs32_entry_homescreen();
        }
        else
    #endif /* __MMI_OP11_HOMESCREEN_0301__ */
        {
        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
            if (PhnsetGetCalendarIdleScreen() != 0)
            {
                idle_screen_enable_calendar_display();
            }
        #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
            
        #ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
            mmi_idle_enable_idle_icon_shortcut();
        #endif
            
        #ifdef __MMI_SWFLASH__
            if (dispchar_iswp_swflash())
            {
                ShowCategory34Screen(
                    g_keylock_context.KeyLockLSKStringID,
                    g_keylock_context.KeyLockLSKIconID,
                    g_keylock_context.KeyLockRSKStringID,
                    g_keylock_context.KeyLockRSKIconID,
                    PhnsetGetCurWallPaperIdx(), 
                    idle_screen_wallpaper_name, 
                    NULL);
            }
            else
        #endif /* _MMI_SWFLASH__ */
        #ifdef __MMI_AVATAR__
            if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
            {
                ShowCategory34Screen(
                    g_keylock_context.KeyLockLSKStringID,
                    g_keylock_context.KeyLockLSKIconID,
                    g_keylock_context.KeyLockRSKStringID,
                    g_keylock_context.KeyLockRSKIconID,
                    PhnsetGetCurWallPaperIdx(), 
                    NULL, 
                    NULL);
            }
            else
        #endif /* __MMI_AVATAR__ */
            {
                ShowCategory33Screen(
                    g_keylock_context.KeyLockLSKStringID,
                    g_keylock_context.KeyLockLSKIconID,
                    g_keylock_context.KeyLockRSKStringID,
                    g_keylock_context.KeyLockRSKIconID,
                    NULL);
                mmi_phnset_save_wallpaper_to_speedup();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_generic_keypad_lock_screen_exit_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_generic_keypad_lock_screen_exit_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_KEYPAD_LOCK_EXIT);

    if (gIsIdleScreenReentry)
    {
        return;
    }

    g_keylock_context.IsOnKeyLockCallbackScreen = 0;
    
    /* diamond, 2006/03/26 Generic exit function for keypad lock callback screens */
    mmi_frm_kbd_reg_pre_key_hdlr(NULL);

    /*
     * Even though the handset is in locked state, hide the icon if user will 
     * leave the screen with keypad unlock handler. E.g., MT call or alarm will 
     * need to hide the icon temporarily.
     */
#ifdef __MMI_TOUCH_SCREEN__
    func_ptr = GetKeyHandler(KEY_SEND, KEY_EVENT_DOWN);
#else /* __MMI_TOUCH_SCREEN__ */
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    func_ptr = get_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
#endif
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    func_ptr = get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
#endif
#endif /* __MMI_TOUCH_SCREEN__ */

/* There is no func_ptc if in the idle fancy handset lock */

    if (
	#ifndef __MMI_FANCY_SCREEN_LOCK__
		func_ptr == EntryScrAfterPessingRSK &&
	#endif
        GetActiveScreenId() != KPAD_SCR_UNLOCK_FIRST_HELP_MESSAGE &&
        GetActiveScreenId() != KPAD_SCR_UNLOCK_HELP_MESSAGE)
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_KEYPAD_LOCK);
    }

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_unblock(); /* diamond, 2006/06/06 unblock pen is generic keypad lock screen exit handler */
#endif

    if (g_keylock_context.keypad_lock_screen_exit != NULL)
    {
        (*g_keylock_context.keypad_lock_screen_exit) ();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_generic_keypad_lock_key_hdlr
 * DESCRIPTION
 *  This function is called to lock the keypad.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_generic_keypad_lock_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag)
    {
        memset(currKeyFuncPtrs, 0, sizeof(currKeyFuncPtrs));

    #ifndef __MMI_KEYPADLOCK_WITH_KEYTONE__
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    #endif 

        /* Do not set key handler on the idle notification dummy screen. */
        if (GetActiveScreenId() == SCR_ID_NMGR_DUMMY)
        {
            return;
        }
	/* disable all key handler if in the idle fancy handset lock screen, IsOnKeyLockCallbackScreen reset because unblock_pen when LCD turn on*/
	#ifndef __MMI_FANCY_SCREEN_LOCK__
        g_keylock_context.IsOnKeyLockCallbackScreen = 1;
        
    #if defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__)
        SetGroupKeyHandler(
            EntryScrKeyPadLockOnPessingAnyKey,
            (PU16) PresentAllKeys,
            (U8) TOTAL_KEYS,
            (U16) KEY_EVENT_DOWN);
    #endif /* defined(__MMI_KEYPAD_LOCK_PROMPT_TEXT__) */ 

    #ifdef __MMI_TOUCH_SCREEN__
        mmi_idle_pen_block();
        SetKeyHandler(EntryScrAfterPessingRSK, KEY_SEND, KEY_EVENT_DOWN);
    #else /* __MMI_TOUCH_SCREEN__ */ 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
        mmi_idle_set_rsk(EntryScrAfterPessingRSK, KEY_EVENT_UP);
    #endif 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
        mmi_idle_set_lsk(EntryScrAfterPessingRSK, KEY_EVENT_UP);
    #endif 
    #endif /* __MMI_TOUCH_SCREEN__ */ 

	#endif /* ifndef __MMI_FANCY_SCREEN_LOCK__ */
        g_keylock_context.keypad_lock_screen_exit = GetCurrExitFuncPtr();
        SetCurrExitFuncPtr(mmi_idle_generic_keypad_lock_screen_exit_hdlr);
        
        if (g_idle_context.IsRSKPressOnScreenSaver)
        {
        #ifndef __MMI_FANCY_SCREEN_LOCK__
            EntryScrAfterPessingRSK();
        #endif
            g_idle_context.IsRSKPressOnScreenSaver = 0;
        }
    }
}


#ifdef __OP12__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_op12_live
 * DESCRIPTION
 *  This function launches the browser to open the OP12 home page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_entry_op12_live(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)L"http://live.vodafone.com/");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_delayed_rsk_timeout
 * DESCRIPTION
 *  This function is the time-out handler of the delayed RSK function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_delayed_rsk_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset the RSK handler if it is present. */
    if (g_idle_context.delayed_rsk_hdlr)
    {
        SetRightSoftkeyFunction(g_idle_context.delayed_rsk_hdlr, KEY_EVENT_UP);
        g_idle_context.delayed_rsk_hdlr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_delayed_rsk
 * DESCRIPTION
 *  This function sets the delayed RSK handler. This is a special requirement
 *  of OP12. When going back to the home screen using the back key (e.g. right 
 *  soft key), the user shall be prevented from accidentally accessing the 
 *  service that is assigned to this key on the home screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_delayed_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr rsk_hdlr;
    U16 k_code, k_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&k_code, &k_type);
    
    if (k_code == KEY_RSK && k_type == KEY_EVENT_UP)
    {
        rsk_hdlr = get_right_softkey_function(KEY_EVENT_UP);
        
        if (rsk_hdlr)
        {
            g_idle_context.delayed_rsk_hdlr = rsk_hdlr;
            SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);

            StartTimer(
                IDLE_DELAYED_RSK_TIMER, 
                MMI_IDLE_DELAYED_RSK_TOV, 
                mmi_idle_delayed_rsk_timeout);
        }
    }
}
#endif /* __OP12__ */


/*****************************************************************************
 * FUNCTION
 *  EntryIdleScreen
 * DESCRIPTION
 *  Entry function for idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 gIsOnSearchingScreen = MMI_FALSE;
    static MMI_BOOL is_idle_init_done = MMI_FALSE;
    static MMI_BOOL is_idle_post_init_done = MMI_FALSE;
    U16 keyCode, keyType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_FEATURES__) && !defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_sim_valid() == MMI_FALSE && 
        mmi_netset_get_active_preferred_mode() == P_GSM_ONLY && 
        !mmi_bootup_get_active_bt_access_profile_mode() &&
        !mmi_bootup_is_dualsim_disconnected())
    {
        if (simErrorDisplayString == STR_SIM_BLOCK_MSG)
        {
            EntryScrnSimBlockRsp();
        }
        else
        {
            EntryScrnSimErrorScreen();
        }
        return;
    }
#endif /* defined(__MMI_WLAN_FEATURES__) && !defined(__MMI_DUAL_SIM_MASTER__) */

    GetkeyInfo(&keyCode, &keyType);
    if ((keyCode == KEY_LSK || keyCode == KEY_RSK) && (keyType == KEY_EVENT_DOWN || keyType == KEY_REPEAT)&& g_idle_context.IsOnIdleScreen == 1 && g_keylock_context.gKeyPadLockFlag == 0)
    {
        /*
         * The case is because the idle screen is re-entry between left softkey down and up event.
         * Once re-entry idle screen, the clicked state will be clean and then the up event will be ignore.
         */
        return;
    }

#ifdef __MMI_VUI_3D_CUBE_APP__
    mmi_cube_vapp_prefetch_image_and_save();
#endif

    /* Avoid to restart keypad lock and screensaver timer if EntryIdleScreen is 
       called again when active screen is still idle screen. */
    gIsIdleScreenReentry = (GetActiveScreenId() == IDLE_SCREEN_ID ? MMI_TRUE : MMI_FALSE);

    EntryNewScreen(IDLE_SCREEN_ID, ExitIdleScreen, NULL, MMI_FULL_SCREEN);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_KEYPAD_LOCK);
#endif

#ifdef __MMI_OP01_DCD__
    mmi_dcd_entry_idlescreen(mmi_bootup_is_network_searching_complete());
#endif /* __MMI_OP01_DCD__ */ 

    /* START PMT NEERAJ 20051021 */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens()) /* 010706 small screen Calvin */
    {
        RedrawIdleScreen();
        gIsIdleScreenReentry = MMI_FALSE;
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 
    /* END PMT NEERAJ 20051021 */

    g_pwr_context.PrevScreenIndicator = ENTER_IDLE_SCR;

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#ifdef __MMI_OP12_TOOLBAR__
    if (mmi_tb_is_enable())
    {
        mmi_tb_pre_fetch_history();
    }
#endif /* __MMI_OP12_TOOLBAR__ */

	DinitHistory();
    DeInitSpecialMode();    /* EngineerMode/Factory Deinit */

#if defined(JATAAYU_SUPPORT) && defined(MMS_SUPPORT)
    mmi_jmms_free_media_layer_buffer(); /* free media layer buffer */
#endif

#ifdef __CERTMAN_SUPPORT__
    mmi_certman_deinit();
#endif

#if defined (__MMI_BROWSER_2__) && defined (WAP_SUPPORT)
    mmi_brw_app_deinit();
#endif

#ifdef __MMI_DOWNLOAD_AGENT__
    mmi_da_enter_idle_screen_notify();
#endif 

#ifdef __J2ME__
    jam_enter_idle_screen_notify();
#endif 

#ifdef __MMI_SWFLASH__
    mmi_swflash_enter_idle_screen_notify();
#endif 

    mmiapi_enter_idle_screen_notify();

#ifndef __MMI_DUAL_SIM_MASTER__
#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_flight_mode_is_switching())
    {
        mmi_flight_mode_switching_in_idle();
        return;
    }
#endif    
#else
    if (DualModeIsSwitching())
    {
        EntryDualModeSwitchProgressInIdle();
        return;
    }
#endif    

#if defined(__MMI_WEBCAM__) && defined(__MMI_USB_SUPPORT__)
    /* entry webcam if it is still active */
    if (mmi_usb_webcam_is_active())
    {
        mmi_usb_webcam_entry_app_scr();
        return;
    }
#endif /* defined(__MMI_WEBCAM__) && defined(__MMI_USB_SUPPORT__) */ 

#ifdef __MMI_OP11_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MMI_SIMAP_SUPPORT__) || defined(__GSMCDMA_DUALSIM__)
    /*
     * SIM Access Profile and Dual-SIM disconnected mode share the same 
     * idle screen because they have similar MMI behavior.
     */
    if (mmi_bootup_get_active_bt_access_profile_mode() ||
        mmi_bootup_is_dualsim_disconnected())
    {
    #if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
        widget_MMI_on_enter_idle_screen();
    #endif

        if (!gIsIdleScreenReentry)
        {
            mmi_idle_start_screensaver();   /* screen saver in flight mode */
            mmi_idle_start_keypad_lock();   /* keypad lock in flight mode */
        }

        g_idle_context.IsOnIdleScreen = 1;
        g_idle_context.IsOnDialerScreen = 0;
        g_idle_context.LongPressEnable = 0;
        g_idle_context.IdleScreenDigitKeyCode = -1;

        if (0)
        {
        }
    #ifdef __DM_LAWMO_SUPPORT__
        /* Do not add idle callback before this. */
        else if (mmi_idle_lawmo_is_locked())
        {
            mmi_idle_lawmo_entry_locked_screen();
            mmi_idle_generic_keypad_lock_key_hdlr();            
        }
    #endif /* __DM_LAWMO_SUPPORT__ */
    #ifdef __MMI_FANCY_SCREEN_LOCK__ 
        else if (mmi_idle_fhl_check())
        {
            mmi_idle_fhl_entry();
            mmi_idle_generic_keypad_lock_key_hdlr();            
        }
    #endif /* __MMI_FANCY_SCREEN_LOCK__  */
    #ifdef __J2ME__
        else if (mmi_java_is_launch_from_idle())
        {
            mmi_java_entry_mid_launch_from_idle();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
        else if(mmi_java_timealarm_islock())
        {
            mmi_java_timealarm_unlock();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
        else if(mmi_java_pushinstall_islock())
        {
            mmi_java_pushinstall_unlock();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif /* __J2ME__ */ 
    #if defined(__J2ME__) && defined(__DM_SCOMO_SUPPORT__)
        else if(mmi_java_dmui_scomo_execute_cmd_check())
        {
            mmi_java_dmui_scomo_execute_cmd_cb();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
     #endif
    #ifdef __MMI_DOWNLOAD_AGENT__
        else if (mmi_da_launch_ring_buffer_check())
        {
            mmi_da_entry_new_push_ind();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif /* __MMI_DOWNLOAD_AGENT__ */ 
    #if defined (__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
        else if (mmi_fmgr_default_storage_need_confirm())
        {
            mmi_fmgr_default_storage_do_confirm();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif
    #ifdef __MMI_PHB_STARTUP_COPY_SIM__
        else if (mmi_phb_startup_copy_sim_check())
        {
            mmi_phb_startup_copy_sim_pre_entry();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (mmi_phb_startup_copy_sim2_check())
        {
            mmi_phb_startup_copy_sim2_pre_entry();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #endif /* __MMI_PHB_STARTUP_COPY_SIM__ */
        else
        {
            if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
            {
                mmi_idle_entry_bt_access_profile_idle_screen();
            }
            else
            {
                EntryFlightModeKeypadLockScreen(); /* share with flight mode keypad lock screen */
            }
        }
        
        gIsIdleScreenReentry = MMI_FALSE;
        
        return;
    }
#endif /* defined(__MMI_SIMAP_SUPPORT__) || defined(__GSMCDMA_DUALSIM__) */

#ifdef __FLIGHT_MODE_SUPPORT__
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT && MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT) /* no query mode in dual sim case so startup mode can determine flight mode */
#else
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
#endif
    {
        /* If the phone enters the flight mode, treat it as the network 
           searching is completed. */
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE;

        g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
        g_pwr_context.InvalidSimShowed = 1;
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;
        g_pwr_context_2.InvalidSimShowed = 1;
    #endif
        
        if (!is_idle_init_done) // if (mmi_bootup_is_searching_or_idle_reached() == MMI_FALSE)
        {

            TurnOffBacklight();
            StartLEDPatternBackGround();

            if (g_charbat_context.isChargerConnected)
            {
                StartTimer(BOOTUP_CHARGER_DETECT_TIMER, 3000, ChargerDetectTimeoutHdlr);
            }

            PendingAlarmReminder();

            mmi_idle_notify_bootup_ready_to_l4c(); /* to L4C */
            mmi_idle_notify_bootup_ready_to_wap(); /* to WAP */
            mmi_idle_notify_bootup_ready_to_certman(); /* to CertMan */

        #ifdef __MMI_IMPS__
/* under construction !*/
        #endif 

            mmi_sim_rearrange_menu_item();

            is_idle_init_done = MMI_TRUE;
        }

        if (!gIsIdleScreenReentry)
        {
            mmi_idle_start_screensaver();   /* screen saver in flight mode */
            mmi_idle_start_keypad_lock();   /* keypad lock in flight mode */
        }

        g_idle_context.IsOnIdleScreen = 1;
        g_idle_context.IsOnDialerScreen = 0;
        g_idle_context.LongPressEnable = 0;
        g_idle_context.IdleScreenDigitKeyCode = -1;

        if (0)
        {
        }
    #ifdef __DM_LAWMO_SUPPORT__
        /* Do not add idle callback before this. */
        else if (mmi_idle_lawmo_is_locked())
        {
            mmi_idle_lawmo_entry_locked_screen();
            mmi_idle_generic_keypad_lock_key_hdlr();            
        }
    #endif /* __DM_LAWMO_SUPPORT__ */
    #ifdef __MMI_FANCY_SCREEN_LOCK__ 
        else if (mmi_idle_fhl_check())
        {
            mmi_idle_fhl_entry();
            mmi_idle_generic_keypad_lock_key_hdlr();            
        }
	#endif /* __MMI_FANCY_SCREEN_LOCK__  */
    #ifdef __J2ME__
        else if (mmi_java_is_launch_from_idle())
        {
            mmi_java_entry_mid_launch_from_idle();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
        else if(mmi_java_timealarm_islock())
        {
            mmi_java_timealarm_unlock();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
        else if(mmi_java_pushinstall_islock())
        {
            mmi_java_pushinstall_unlock();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif /* __J2ME__ */ 
    #if defined(__J2ME__) && defined(__DM_SCOMO_SUPPORT__)
        else if(mmi_java_dmui_scomo_execute_cmd_check())
        {
            mmi_java_dmui_scomo_execute_cmd_cb();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
	#endif /* __J2ME__  &&  __DM_SCOMO_SUPPORT__*/
    #ifdef __MMI_DOWNLOAD_AGENT__
        else if (mmi_da_launch_ring_buffer_check())
        {
            mmi_da_entry_new_push_ind();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif /* __MMI_DOWNLOAD_AGENT__ */ 
    #if defined (__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
        else if (mmi_fmgr_default_storage_need_confirm())
        {
            mmi_fmgr_default_storage_do_confirm();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif
    #ifdef __MMI_PHB_STARTUP_COPY_SIM__
        else if (mmi_phb_startup_copy_sim_check())
        {
            mmi_phb_startup_copy_sim_pre_entry();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (mmi_phb_startup_copy_sim2_check())
        {
            mmi_phb_startup_copy_sim2_pre_entry();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #endif /* __MMI_PHB_STARTUP_COPY_SIM__ */
    #if defined (__MMI_BT_IN_FLIGHT_MODE__)
    #if defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
        else if (mmi_bt_recv_files_exist())
        {
            mmi_bt_entry_idle_notify_scr();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif /* defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__) */
    #if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
        else if (mmi_vobj_is_pending_object())
        {
            mmi_vobj_entry_recv_object();
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
    #endif	
    #endif /* defined (__MMI_BT_IN_FLIGHT_MODE__)*/  
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
        /* flight mode idle function */
        else if(mmi_syncml_is_sync_alarm_expired())
        {
            mmi_syncml_sync_alarm_hdlr();  
            mmi_idle_generic_keypad_lock_key_hdlr();
        }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

        else
        {
            if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
            {
                EntryFlightModeIdleScreen();
            }
            else
            {
                EntryFlightModeKeypadLockScreen();
            }
        }
        gIsIdleScreenReentry = MMI_FALSE;

    #ifdef __MMI_DUAL_SIM_MASTER__
        if (MTPNP_PFAL_Is_InCard2securityCheck())
        {
            /* need to check SIM2 PIN1 when first time enter idle screen */
            /* coding here because flight mode check is true in dual sim mode */
            MTPNP_AD_Card2_CHV_Request();
            ClearInputEventHandler(MMI_DEVICE_ALL);
        }
        else
        {
            MTPNP_PFAL_Entry_Idle_With_Personalization();
        }
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
        return;
    }
#endif /* __FLIGHT_MODE_SUPPORT__ */ 
    /* end, diamond */

    NETSETCheckAndRestoreNetwork();

#ifdef __SAT__
#ifndef __SAT_LOWCOST_UI_DISABLE__
    SATEVDLIdleScreenAvaliable();
#endif
#endif

#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
    widget_MMI_on_enter_idle_screen();
#endif 

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
    mmi_brw_unread_push_message_indication();
#endif 

#ifdef __MOD_SMSAL__
    mmi_msg_on_enter_idle_screen();
#endif /* __MOD_SMSAL__ */ 

    /* This block carries all functions to be called when user enter idle screen first time. */
    if (!is_idle_init_done) // if (mmi_bootup_is_searching_or_idle_reached() == MMI_FALSE)
    {
        TurnOffBacklight();
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_NW_SEARCHING;     /* 0x40: Network searching screen */

    #if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
        DirectMode = MMI_FALSE;
    #endif 

        PendingAlarmReminder();
        StartLEDPatternBackGround();

    #ifdef __MMI_POC__
        if (g_pwr_context.CurrentServiceType == FULL_SERVICE)
        {
            mmi_poc_poweron_reg();
        }
    #endif /* __MMI_POC__ */ 

        if (g_charbat_context.isChargerConnected)
        {
            StartTimer(BOOTUP_CHARGER_DETECT_TIMER, 3000, ChargerDetectTimeoutHdlr);
        }

    #if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
        MMIProcessActionMsg();
    #endif 

        mmi_idle_notify_bootup_ready_to_l4c(); /* to L4C */
        mmi_idle_notify_bootup_ready_to_wap(); /* to WAP */
        mmi_idle_notify_bootup_ready_to_certman(); /* to CertMan */

    #ifdef __MMI_IMPS__
/* under construction !*/
    #endif 

    #ifdef __MMI_SML_MENU__
        mmi_sml_display_auto_locked_notification();
    #endif

    #ifdef __MMI_NETSET_3G_ENHANCE__
        #ifdef __MMI_WLAN_FEATURES__
            /* GSM is turn on */
            if (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)
        #endif /* __MMI_WLAN_FEATURES__ */
            {
                /* SIM is valid */
                if (mmi_bootup_is_sim_valid())
                {
                    mmi_netset_3g_nocell_start_timer();
                }
            }
    #endif /* __MMI_NETSET_3G_ENHANCE__ */

    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
        {
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG; /* No need to show network searching screen */
            g_pwr_context.IsCampOnTonePlayed = 1; /* No need to play camp on tone */
        }
    #endif /* __MMI_WLAN_FEATURES__ */

    #ifdef __MMI_AUTO_ANSWER_MACHINE__
        mmi_autoam_init_statusicon();
    #endif
        is_idle_init_done = MMI_TRUE;
    }

    g_idle_context.IsOnIdleScreen = 1;
    g_idle_context.IsOnDialerScreen = 0;
    g_idle_context.IdleScreenDigitKeyCode = -1;

    /* This checks if network attach indication has been recieved once after bootup. */
    /* If yes, then go to idle screen otherwise show network srch animation.    */
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (mmi_bootup_is_network_searching_complete() || mmi_bootup_is_sim2_network_searching_complete())
#else
    if (mmi_bootup_is_network_searching_complete() == MMI_TRUE)
#endif
    {
        /* isIdleScreenReached=1; */
        g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* 0x80: Idle screen */
        gIsOnSearchingScreen = MMI_FALSE;

    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        if (!(mmi_bootup_is_network_searching_complete() && mmi_bootup_is_sim2_network_searching_complete()) && !IsMyTimerExist(SEARCHING_SCREEN_TIMER))
        {
            StartTimer(SEARCHING_SCREEN_TIMER, 10000, SearchingSrceenTimeOutHandler);
            gIsOnSearchingScreen = MMI_TRUE;
        }
    #endif

        if (!gIsIdleScreenReentry)
        {
            mmi_idle_start_screensaver();
            mmi_idle_start_keypad_lock();
        }
        gIsIdleScreenReentry = MMI_FALSE;

        if (g_keylock_context.gKeyPadLockFlag == 0) /* keypad is not locked */
        {
            if (mmi_idle_exe_callback() == MMI_FALSE)   /* no pending message */
            {
                /* keypad lock idle screen */
            #if defined(__MMI_OP11_HOMESCREEN_0301__1) || defined(__MMI_OP11_HOMESCREEN_0302__1)
                if (mmi_op11_hs32_is_enable())
                {
                    mmi_op11_hs32_entry_homescreen();
                }
                else
            #endif  /* __MMI_OP11_HOMESCREEN_0301__ */
            #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_OP11_HOMESCREEN__ */
            #ifdef __MMI_OP12_TOOLBAR__
                if (mmi_tb_is_enable())
                {
                    mmi_tb_entry_toolbar();
                }
                else   
            #endif /* __MMI_OP12_TOOLBAR__ */
                {
                    mmi_idle_entry_idle_screen();
                }
            
            #ifdef __OP12__
                mmi_idle_set_delayed_rsk();
            #endif /* __OP12__ */
            }
        }
        else    /*  Keyapd is locked */
        {
            /* U16 KeyLockLSKStringtID=0, KeyLockRSKStringID=0, KeyLockLSKIconID=0, KeyLockRSKIconID=0; */
            mmi_idle_set_keypad_lock_string();

            if (mmi_idle_exe_callback() == MMI_FALSE)   /* no pending message */
            {
                /* keypad lock idle screen */
            #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                if (mmi_op11_hs32_is_enable())
                {
                    mmi_op11_hs32_entry_homescreen();
                }
                else
            #endif   /* __MMI_OP11_HOMESCREEN_0301__ */
            #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_OP11_HOMESCREEN__ */
            #ifdef __MMI_OP12_TOOLBAR__
                if (mmi_tb_is_enable())
                {
                    mmi_tb_entry_toolbar();
                }
                else   
            #endif /* __MMI_OP12_TOOLBAR__ */
            #ifdef __MMI_VUI_HOMESCREEN__
                if (mmi_vhs_is_enable())
                {
                #ifdef __MMI_VUI_3D_CUBE_APP__
                    mmi_cube_vapp_show_homescreen();
                #else
                    mmi_vhs_show_homescreen();
                #endif
                }
                else
            #endif /* __MMI_VUI_HOMESCREEN__ */
                {
                    IdleRefreshServiceIndicationArea();
                    
                #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
                    if (PhnsetGetCalendarIdleScreen() != 0)
                    {
                        idle_screen_enable_calendar_display();
                    }
                #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

                #ifdef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
                    mmi_idle_enable_idle_icon_shortcut();
                #endif
                
                #ifdef __MMI_SWFLASH__
                    if (dispchar_iswp_swflash())
                    {
                        ShowCategory34Screen(
                            g_keylock_context.KeyLockLSKStringID,
                            g_keylock_context.KeyLockLSKIconID,
                            g_keylock_context.KeyLockRSKStringID,
                            g_keylock_context.KeyLockRSKIconID,
                            PhnsetGetCurWallPaperIdx(), 
                            idle_screen_wallpaper_name, 
                            NULL);
                    }
                    else
                #endif /* _MMI_SWFLASH__ */
                #ifdef __MMI_AVATAR__
                    if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
                    {
                        ShowCategory34Screen(
                            g_keylock_context.KeyLockLSKStringID,
                            g_keylock_context.KeyLockLSKIconID,
                            g_keylock_context.KeyLockRSKStringID,
                            g_keylock_context.KeyLockRSKIconID,
                            PhnsetGetCurWallPaperIdx(), 
                            NULL, 
                            NULL);
                    }
                    else
                #endif /* __MMI_AVATAR__ */
                    {
                        ShowCategory33Screen(
                            g_keylock_context.KeyLockLSKStringID,
                            g_keylock_context.KeyLockLSKIconID,
                            g_keylock_context.KeyLockRSKStringID,
                            g_keylock_context.KeyLockRSKIconID,
                            NULL);
                        mmi_phnset_save_wallpaper_to_speedup();
                    }
                }
            }

            mmi_idle_generic_keypad_lock_key_hdlr();
        }

        mmi_idle_date_time_reminder();
    }
    /*
     * Handle the case that RAC indicates invalid SIM before entering idle
     */
    else if (!mmi_bootup_is_nw_registration_ok() && !g_pwr_context.InvalidSimShowed)
    {
        g_pwr_context.InvalidSimShowed = 1;
        DisplayInvalidSimInfo();
    }
    /*  
     * Displays network seaching animation 
     */
    else    
    {
        if (g_keylock_context.gKeyPadLockFlag)
        {
            mmi_idle_set_keypad_lock_string();
        }

        if (!gIsIdleScreenReentry)
        {
            mmi_idle_start_screensaver();
            mmi_idle_start_keypad_lock();
        }
        gIsIdleScreenReentry = MMI_FALSE;

        if (mmi_idle_exe_callback() == MMI_FALSE)   /* no pending message */
        {
            if (!gIsOnSearchingScreen)
            {
                StartTimer(SEARCHING_SCREEN_TIMER, 10000, SearchingSrceenTimeOutHandler);
                gIsOnSearchingScreen = MMI_TRUE;
            }

            mmi_idle_entry_searching_screen();
        }
        
        if (g_keylock_context.gKeyPadLockFlag)
        {
            mmi_idle_generic_keypad_lock_key_hdlr();
        }

        mmi_idle_date_time_reminder();
    }

    /* 
     * This block carries all functions, which are called after the category
     * screen is shown, when the user enters the idle screen in the first time. 
     */
    if (!is_idle_post_init_done)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if ((!g_pwr_context.IsCampOnTonePlayed && 
             g_pwr_context.CurrentServiceType == FULL_SERVICE) ||
            (!g_pwr_context_2.IsCampOnTonePlayed && 
             g_pwr_context_2.CurrentServiceType == FULL_SERVICE))
        {
            g_pwr_context.IsCampOnTonePlayed = 1;
            g_pwr_context_2.IsCampOnTonePlayed = 1;
            playRequestedTone(CAMP_ON_TONE);
        }
    #else
        if (!g_pwr_context.IsCampOnTonePlayed && 
            g_pwr_context.CurrentServiceType == FULL_SERVICE)
        {
            g_pwr_context.IsCampOnTonePlayed = 1;
            playRequestedTone(CAMP_ON_TONE);
        }
    #endif

        is_idle_post_init_done = MMI_TRUE;
    }

    mmi_frm_kbd_reg_pre_key_hdlr(IdleScreenEmergencyCallCheckNKeypadLock);

#ifdef __SAT__
    if (GetPostponedSATScreen())
    {
        (*GetPostponedSATScreen())();
        ClearPostponedSATScreen();
    }
#endif /* __SAT__ */

    gIsIdleScreenReentry = MMI_FALSE;

#ifdef JATAAYU_SUPPORT
    #ifdef WAP_SUPPORT
        mmi_brw_wap_deinit(); /* browser deinit */
    #endif 
    #ifdef MMS_SUPPORT
        mmi_jmms_deinit(); /* MMS deinit */
    #endif 
    mmi_ph_deinit_profiles(); /* profile deinit */
    mmi_prov_deinit();
#endif /* JATAAYU_SUPPORT */

#ifdef __MMI_MMS_2__
    mmi_umms_app_if_deinit_viewer();
    mmi_umms_app_dtmgr_reset_data();
#ifdef __MMI_URI_AGENT__
    srv_mms_de_init_uri();
#endif
#endif /* __MMI_MMS_2__ */


#ifndef __MTK_TARGET__ /* MoDIS only */
    mmi_netset_write_auto_test_result(MMI_TRUE);
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Is_InCard2securityCheck())
    {
        /* need to check SIM2 PIN1 when first time enter idle screen */
        /* coding here because flight mode check is true in dual sim mode */
        MTPNP_AD_Card2_CHV_Request();
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }
    else
    {
        MTPNP_PFAL_Entry_Idle_With_Personalization();
    }
#endif  /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  ExitIdleScreen
 * DESCRIPTION
 *  Exit function for idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitScreen(IDLE_SCREEN_ID, EntryIdleScreen);

    g_idle_context.IsOnIdleScreen = 0;

#ifdef __MMI_OP01_DCD__
    mmi_dcd_exit_idlescreen(g_keylock_context.gKeyPadLockFlag);
#endif /* __MMI_OP01_DCD__ */ 
#if defined(__J2ME__) && defined(__DM_SCOMO_SUPPORT__)
    mmi_java_dmui_scomo_exit_idle_cb();
#endif /* __J2ME__  && __DM_SCOMO_SUPPORT__ */ 

    mmi_frm_kbd_reg_pre_key_hdlr(NULL);

    /* 
     * If the idle screen exits because of the following situations, do not stop
     * keypad lock timer:
     *
     *  1) the idle screen re-entries or
     *  2) the screen saver launches
     */
    if (!g_idle_context.ScreenSaverRunFlag && !gIsIdleScreenReentry)
    {
        MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_KEYPAD_LOCK_STOP, g_idle_context.AutoLockTimeOut);
        StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
    }

    /*
     * If the idle screen exits because of the following situations, do not stop
     * screen saver timer:
     *
     *  1) the idle screen re-entries or
     *  2) the keypad locks (will show a popup)
     */
    if (GetActiveScreenId() != KPAD_SCR_LOCK_MESSAGE && !gIsIdleScreenReentry)
    {
        StopTimer(SCREENSAVER_TIMER);
    }

    StopTimer(KEYPADUNLOCKEDMESSAGE_TIMER);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_status_icon_bar_reset_all_pen_event_handler();

    if (!g_keylock_context.gKeyPadLockFlag)
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_KEYPAD_LOCK);
    }
#endif

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __OP12__
    /* For delayed RSK handler. Please refer to mmi_idle_set_delayed_rsk. */
    StopTimer(IDLE_DELAYED_RSK_TIMER);
    g_idle_context.delayed_rsk_hdlr = NULL;
#endif /* __OP12__ */

#if defined(__MMI_WGUI_CSK_ENABLE__)
    ResetCenterSoftkey();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_remove_dialer_screen_exit_handler
 * DESCRIPTION
 *  This function removes the dialer screen from history. This function handles
 *  both the normal dialer screen and the SIM error dialer screen. The function
 *  can be called before or after the application shows their screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_remove_dialer_screen_exit_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == IDLE_SCREEN_DIGIT_HANDLER_ID)
    {
        SetCurrExitFuncPtr(NULL);
        g_idle_context.IsOnDialerScreen = 0;
        g_idle_context.IdleScreenDigitKeyCode = -1;
    }
    else if (GetActiveScreenId() == SCR_DIAL_SOS_NUM)
    {
        SetCurrExitFuncPtr(NULL);
        g_idle_context.IsOnSimErrorDialerScreen = 0;
        g_idle_context.IdleScreenDigitKeyCode = -1;
    }
    else
    {
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
        DeleteScreenIfPresent(SCR_DIAL_SOS_NUM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_check_nw_provider_name_length
 * DESCRIPTION
 *  Check if the input string length is larger than main lcd width
 * PARAMETERS
 *  unicode_string      [?]     
 *  U8*(?)
 * RETURNS
 *  pBOOL
 *****************************************************************************/
extern void UI_set_font(UI_font_type f);
pBOOL mmi_idle_check_nw_provider_name_length(U8 *unicode_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL rtn;
    S32 StringWidth, StringHeight;
    stFontAttribute prev_f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* copy the system font to backup */
    memcpy(&prev_f, UI_font, sizeof(stFontAttribute));

    /* set default font for length calculation */
    UI_set_font(&UI_DEFAULT_FONT);

    Get_StringWidthHeight(unicode_string, &StringWidth, &StringHeight);

    /* check the string length if it is larger than main lcd width */
    if ((StringWidth + 1) >= MAIN_LCD_device_width - (MMI_IDLE_STRING_MARGIN_GAP << 1))
    {
        rtn = MMI_FALSE;
    }
    else
    {
        rtn = MMI_TRUE;
    }

    /* restore the system font */
    UI_set_font(&prev_f);
    return rtn;
}


/* For the detail information, please refer to IdleAppGprot.h */
MMI_BOOL mmi_idle_is_camp_on_chinese_network(U8 *plmn)
{
    if (memcmp(plmn, "460", 3) == 0 || /* CN */
        memcmp(plmn, "466", 3) == 0 || /* TW */
        memcmp(plmn, "454", 3) == 0)   /* HK */
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IdleRefreshServiceIndicationArea
 * DESCRIPTION
 *  To refresh Service indication Area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#define SetLine1Text SetIdleScreenNetworkName
#define SetLine2Text SetIdleScreenNetworkStatus

void IdleRefreshServiceIndicationArea(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_OP01_DCD__
        if (MMI_TRUE == mmi_dcd_is_switch_on())
        {
            idleRskStringID = STR_ID_DCD;
        }
        else
    #endif /* __MMI_OP01_DCD__ */
    #ifdef __OP12__
        {
            idleRskStringID = STR_ID_IDLE_OP12_LIVE;
        }
    #else /* __OP12__ */
        {
            idleRskStringID = IDLE_SCREEN_RSK_TEXT;
        }
    #endif /* __OP12__ */

    SetLine1Text((U8*) NULL);
    SetLine2Text((U8*) NULL);

#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_imei_valid(SIM1) &&
        mmi_bootup_is_imei_valid(SIM2) &&
        mmi_bootup_is_imei_the_same())
    {
        mmi_ucs2ncpy(
            (PS8)gNWProviderName,
            GetString(STR_ID_IMEI_SAME),
            MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);

        MTPNP_PFAL_Show_Same_IMEI();

    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_bootup_get_active_flight_mode() != FLIGHTMODE_SILENT)
        {
            mmi_netset_update_preferred_mode_service_area();
        }
    #endif /* __MMI_WLAN_FEATURES__ */
        
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (!mmi_bootup_is_imei_valid(SIM1))
    {
        mmi_ucs2ncpy(
            (PS8)gNWProviderName,
            GetString(STR_ID_IMEI_INVALID),
            MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);

    #ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea();
    #endif

    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_bootup_get_active_flight_mode() != FLIGHTMODE_SILENT)
        {
            mmi_netset_update_preferred_mode_service_area();
        }
    #endif /* __MMI_WLAN_FEATURES__ */

        return;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
#ifdef __MMI_WLAN_FEATURES__
    if (!mmi_bootup_get_active_flight_mode() &&
#else
    if (!MTPNP_PFAL_Is_FlightMode() &&
#endif
        ( (MTPNP_AD_Get_Status() & MTPNP_AD_CARD1) != MTPNP_AD_CARD1 || MTPNP_PFAL_Is_Card1Absent() || MTPNP_PFAL_Is_Card1CHVBlocked() ) )
    {
        if ((MTPNP_AD_Get_Status() & MTPNP_AD_CARD1) != MTPNP_AD_CARD1)
        {
            MTPNP_PFAL_Show_Idle_Card1Closed();
            /* refresh card2 idle information */
        }
        else if (MTPNP_PFAL_Is_Card1Absent())
        {
            MTPNP_PFAL_Show_Idle_Card1Absent();
            /* refresh card2 idle information */
        }
        else if (MTPNP_PFAL_Is_Card1CHVBlocked())
        {
            MTPNP_PFAL_Show_Idle_Card1Blocked();
        }

        if (mmi_bootup_is_sim2_network_searching_complete() == MMI_FALSE)
        {
            MTPNP_PFAL_Show_Idle_NW_Register();
        }
        else
        {
            MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea();
        }
        
    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_bootup_get_active_flight_mode() != FLIGHTMODE_SILENT)
        {
            mmi_netset_update_preferred_mode_service_area();
        }
    #endif /* __MMI_WLAN_FEATURES__ */

        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (mmi_bootup_get_active_flight_mode() != FLIGHTMODE_SILENT &&
        mmi_bootup_is_sim2_network_searching_complete() == MMI_FALSE)
    {
        MTPNP_PFAL_Show_Idle_NW_Register();
    }
#endif

    /* diamond, 2005/07/22 240x320 sync searching screen style with idle screen style */
#if defined(__MMI_IDLE_NO_NW_SEARCHING_SCREEN__) || \
    defined(__MMI_DUAL_SIM_MASTER__) || \
    defined(__MMI_OP11_HOMESCREEN__) || \
    defined(__MMI_OP12_TOOLBAR__) || \
    defined(__MMI_VUI_HOMESCREEN__)
    if (mmi_bootup_is_network_searching_complete() == MMI_FALSE)
    {
        mmi_ucs2ncpy(
            (PS8) gNWProviderName,
            (PS8) GetString(STR_GLOBAL_SEARCHING),
            MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);

    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        if (mmi_bootup_is_sim2_network_searching_complete() == MMI_TRUE)
        {
            MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea();
        }
    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_bootup_get_active_flight_mode() != FLIGHTMODE_SILENT)
        {
            mmi_netset_update_preferred_mode_service_area();
        }
    #endif /* __MMI_WLAN_FEATURES__ */

        return;
    }
#endif /* __MMI_IDLE_NO_NW_SEARCHING_SCREEN__ */ 
    /* end, diamond */

    if (g_pwr_context.CurrentServiceType == FULL_SERVICE)
    {
        /* MMI_BOOL SHOW_OPN = MMI_TRUE; */
        MMI_BOOL OPN_Exist;
        MMI_BOOL Short_OPN_Exist;
        MMI_BOOL SPN_Exist;
        MMI_BOOL MSISDN_Exist = PhnsetGetShowOwnerNumStatus() && (mmi_ucs2strlen(gOwnerName) != 0);
        stFontAttribute IdleScr_Medium_font = {0, 0, 0, MEDIUM_FONT, 0, 0};
        U8 Scenario;

    #if defined(__MMI_OPERATOR_NAME_MENU__)
        /* SHOW_OPN = PhnsetGetShowOPNStatus(); */
        if (PhnsetGetShowOPNStatus() == 0)  /* diamond, 2005/10/18 Hide the service area if this setting is off */
        {
            return;
        }
    #endif /* defined(__MMI_OPERATOR_NAME_MENU__) */ 

        /* Now the line1 string is temporarily set to "Searching" so clear line2 in this case */
        if (mmi_ucs2cmp((PS8) gNWProviderName, GetString(STR_GLOBAL_SEARCHING)) == 0)
        {
            SetLine1Text(gNWProviderName);
            return;
        }

        if (IsChineseSet() && mmi_idle_is_camp_on_chinese_network(gPLMN) && !mmi_bootup_is_roaming()) /* Trad. Chinese and Simp. Chinese only */
        {
            /* Ignore OPN because OPN does not have UCS2 encoding */
            Scenario = (gSpnValid ? 2 : 0) + (mmi_idle_is_spn_b1_set() ? 1 : 0);
        }
        else
        {
            /* OPN*4 + SPN*2+ b1*1 */
            Scenario = ((gOpNameValid || gShortOpnameValid) ? 4 : 0) + (gSpnValid ? 2 : 0) + (mmi_idle_is_spn_b1_set() ? 1 : 0);
        }

        MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_DISPLAY_SCENARIO, Scenario);

        /* OPN_Exist means gOpNameValid and the string is not NULL */
        OPN_Exist = gOpNameValid && (mmi_ucs2strlen(gOperatorName) != 0) /* && SHOW_OPN */ ;
        Short_OPN_Exist = gShortOpnameValid && (mmi_ucs2strlen(gShortOperatorName) != 0) /* && SHOW_OPN */ ;
        SPN_Exist = gSpnValid && (mmi_ucs2strlen(gServProvderName) != 0);

        SetFont(IdleScr_Medium_font, (U8) gCurrLangIndex);

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
        {
            switch (Scenario)   /* OPN--SPN--b1 */
            {
                case 0:                             /* OPN=OFF, SPN=OFF, b1=0 */
                case 1:                             /* OPN=OFF, SPN=OFF, b1=1 */
                    SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                    if (MSISDN_Exist)
                    {
                        SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                    }
                    break;

                case 2: /* OPN=OFF, SPN=ON, b1=0 */
                    if (MSISDN_Exist)
                    {
                        if (mmi_bootup_is_roaming() && !mmi_idle_is_rplmn_in_spdi_list())
                        {
                            SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                            if (SPN_Exist && !mmi_idle_is_spn_b2_set() && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                            {
                                SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                            }
                            else
                            {
                                SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                            }
                        }
                        else
                        {
                            SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                            if (SPN_Exist)
                            {
                                SetLine1Text((U8*) gServProvderName); /* Line 1 = SPN */
                            }
                            else
                            {
                                SetLine1Text(gNWProviderName);  /* Line 2 = PLMN */
                            }
                        }
                    }
                    else
                    {
                        if (mmi_bootup_is_roaming() && !mmi_idle_is_rplmn_in_spdi_list())
                        {
                            SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                            if (SPN_Exist && !mmi_idle_is_spn_b2_set() && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                            {
                                SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                            }
                        }
                        else
                        {
                            if (SPN_Exist)
                            {
                                SetLine1Text((U8*) gServProvderName);  /* Line 1 = SPN */
                            }
                            else
                            {
                                SetLine1Text(gNWProviderName);  /* Line 2 = NULL */
                            }
                        }
                    }
                    break;

                case 3:                             /* OPN=OFF, SPN=ON, b1=1 */
                    SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                    if (mmi_bootup_is_roaming() && !mmi_idle_is_rplmn_in_spdi_list())
                    {
                        if (SPN_Exist && !mmi_idle_is_spn_b2_set() && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                        {
                            SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                        }
                        else if (MSISDN_Exist)
                        {
                            SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                        }
                        else
                        {
                            SetLine2Text((U8*) NULL);
                        }
                    }
                    else
                    {
                        if (SPN_Exist && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                        {
                            SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                        }
                        else if (MSISDN_Exist)
                        {
                            SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                        }
                        else
                        {
                            SetLine2Text((U8*) NULL);
                        }
                    }
                    break;

                case 4: /* OPN=ON, SPN=OFF, b1=0 */
                case 5: /* OPN=ON, SPN=OFF, b1=1 */
                    if (mmi_bootup_is_roaming() == MMI_TRUE)
                    {
                        SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                        if (OPN_Exist)
                        {
                            SetLine2Text((U8*) gOperatorName); /* Line 2 = OPN */
                        }
                        else if (Short_OPN_Exist)
                        {
                            SetLine2Text((U8*) gShortOperatorName);
                        }
                        else    /* They are both valid but NULL */
                        {
                            SetLine2Text((U8*) NULL);
                        }
                    }
                    else
                    {
                        if (OPN_Exist)
                        {
                            SetLine1Text((U8*) gOperatorName); /* Line 1 = OPN */
                        }
                        else if (Short_OPN_Exist)
                        {
                            SetLine1Text((U8*) gShortOperatorName);
                        }
                        else    /* They are both valid but NULL */
                        {
                            SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                        }
                        if (MSISDN_Exist)
                        {
                            SetLine2Text((U8*) gOwnerName); /* Line 2 = Owner Name */
                        }
                    }
                    break;

                case 6: /* OPN=ON, SPN=ON, b1=0 */
                case 7: /* OPN=ON, SPN=ON, b1=1 */
                    if (mmi_bootup_is_roaming() == MMI_TRUE && !mmi_idle_is_rplmn_in_spdi_list())
                    {
                        SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                        if (SPN_Exist && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                        {
                            SetLine2Text((U8*) gServProvderName);      /* Line 2 = SPN */
                        }
                        else if (MSISDN_Exist)
                        {
                            SetLine2Text((U8*) gOwnerName);
                        }
                        else
                        {
                            SetLine2Text((U8*) NULL);
                        }
                    }
                    else
                    {
                        if (OPN_Exist)
                        {
                            SetLine1Text((U8*) gOperatorName); /* Line 1 = OPN */
                            if (SPN_Exist && !mmi_idle_is_spn_b2_set() && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gOperatorName) != 0)
                            {
                                SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                            }
                            else if (MSISDN_Exist)
                            {
                                SetLine2Text((U8*) gOwnerName);        /* Line 2 = MSISDN */
                            }
                            else
                            {
                                SetLine2Text((U8*) NULL);
                            }
                        }
                        else if (Short_OPN_Exist)
                        {
                            SetLine1Text((U8*) gShortOperatorName);    /* Line 1 = Short OPN */
                            if (SPN_Exist && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gShortOperatorName) != 0)
                            {
                                SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                            }
                            else if (MSISDN_Exist)
                            {
                                SetLine2Text((U8*) gOwnerName);        /* Line 2 = MSISDN */
                            }
                            else
                            {
                                SetLine2Text((U8*) NULL);
                            }
                        }
                        else    /* They are both valid but NULL */
                        {
                            if (mmi_idle_is_spn_b1_set())
                            {
                                SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                                if (SPN_Exist && mmi_ucs2icmp((S8*) gServProvderName, (S8*) gNWProviderName) != 0)
                                {
                                    SetLine2Text((U8*) gServProvderName);  /* Line 2 = SPN */
                                }
                                else if (MSISDN_Exist)
                                {
                                    SetLine2Text((U8*) gOwnerName);        /* Line 2 = MSISDN */
                                }
                                else
                                {
                                    SetLine2Text((U8*) NULL);
                                }
                            }
                            else
                            {
                                if (SPN_Exist)
                                {
                                    SetLine1Text((U8*) gServProvderName);  /* Line 1: SPN */
                                }
                                else
                                {
                                    SetLine1Text(gNWProviderName);  /* Line 1 = PLMN */
                                }

                                if (MSISDN_Exist)
                                {
                                    SetLine2Text((U8*) gOwnerName); /* Line 2: Owner Name */
                                }
                            }
                        }
                    }
                    break;

                default:
                    MMI_ASSERT(0);
                    break;
            }
        }

    #ifdef __MMI_NITZ__
        mmi_idle_update_nitz_content();
        if (g_nitz_display.opname_from_nitz && mmi_idle_check_nitz_display_validation())
        {
            MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_NITZ_OPNAME);
            if (mmi_bootup_is_roaming())
            {
                /* Roaming and receive NITZ network name */
                SetLine1Text(g_nitz_display.display_name);
            }
            else if (!OPN_Exist && mmi_idle_is_spn_b1_set()) /* not roaming but no OPN */
            {
                /* Network name from NITZ takes lower priority from OPN, but not replace SPN */
                SetLine1Text(g_nitz_display.display_name);
            }
        }
    #endif /* __MMI_NITZ__ */ 

    #ifdef __HOMEZONE_SUPPORT__
        if (gHomezoneText)
        {
            SetLine2Text((U8*) gHomezoneText);
        }
    #endif /* __HOMEZONE_SUPPORT__ */ 
    }
#ifdef __MANUAL_MODE_NW_SEL__
    else if (g_pwr_context.CurrentServiceType == LIMITED_SERVICE)
    {
    #ifdef __MMI_SIMAP_SUPPORT__
        if (mmi_bootup_get_active_bt_access_profile_mode())
        {
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8)GetString(STR_SIM_ACCESS_PROFILE), MAX_LENGTH_DISPLAY_NAME - 1);
        }
        else
    #endif /* __MMI_SIMAP_SUPPORT__ */
    #ifdef __GSMCDMA_DUALSIM__
        if (mmi_bootup_is_dualsim_disconnected())
        {
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8)GetString(STR_SIM_DISCONNECTED_MSG), MAX_LENGTH_DISPLAY_NAME - 1);
        }
        else
    #endif /* __GSMCDMA_DUALSIM__ */
    #ifdef __MMI_WLAN_FEATURES__
        if (!mmi_bootup_is_sim_valid())
        {
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(simErrorDisplayString), MAX_LENGTH_DISPLAY_NAME - 1);
        }
        else
    #endif /* __MMI_WLAN_FEATURES__ */
        if (mmi_bootup_get_plmn_selection_mode() == AUTOMATIC_MODE)
        {
            if (mmi_bootup_is_nw_registration_ok() == MMI_FALSE)
            {
                mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_SIM_INVALID_SIM_TITLE), MAX_LENGTH_DISPLAY_NAME - 1); /* L1: "Invalid SIM" */
            }
            else
            {
                mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_LIMITED_SERVICE), MAX_LENGTH_DISPLAY_NAME - 1); /* L1: "Emergency" */
            }
        }
        else
        {
            /* L1: "Select Network" */
            /* diamond, 2005/12/18 Check if the input string length is larger than main lcd width */
            if (mmi_bootup_is_nw_registration_ok() == MMI_FALSE)
            {
                mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_SIM_INVALID_SIM_TITLE), MAX_LENGTH_DISPLAY_NAME - 1); /* L1: "Invalid SIM" */
            }
            else
            {
                if (mmi_idle_check_nw_provider_name_length((PU8) GetString(STR_ID_NETSET_MANUAL_MODE_TITLE)))
                {
                    mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_ID_NETSET_MANUAL_MODE_TITLE), MAX_LENGTH_DISPLAY_NAME - 1);
                }
                else
                {
                    mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_ID_NETSET_MANUAL_MODE_SHORT), MAX_LENGTH_DISPLAY_NAME - 1);
                }
            #ifndef __MMI_DUAL_SIM_MASTER__
            #ifdef __MMI_WLAN_FEATURES__
                if (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)
            #endif
                {
                    #ifdef __MMI_OP01_DCD__
                        if (MMI_TRUE == mmi_dcd_is_switch_on())
                        {
                            idleRskStringID = STR_ID_DCD;
                        }
                        else
                    #endif /* __MMI_OP01_DCD__ */
                    #ifdef __OP12__
                        {
                            idleRskStringID = STR_ID_IDLE_OP12_LIVE;
                        }
                    #else /* __OP12__ */
                        {
                            idleRskStringID = STR_GLOBAL_SELECT;
                        }
                    #endif /* __OP12__ */
                }
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }
        }
        SetLine1Text(gNWProviderName);
    }
    else if (g_pwr_context.CurrentServiceType == NO_SERVICE)
    {
        /* L1: "No Service" */
    #ifdef __FLIGHT_MODE_SUPPORT__
        if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_MENU_FLIGHT_MODE), MAX_LENGTH_DISPLAY_NAME - 1);
        else
    #endif /* __FLIGHT_MODE_SUPPORT__ */ 
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_NO_SERVICE), MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);
    }
    else    /* temporarily remove the string */
    {
        /* L1: "" */
        SetLine1Text((U8*) NULL);

    }

#else /* __MANUAL_MODE_NW_SEL__ */ 
    else if (g_pwr_context.CurrentServiceType == LIMITED_SERVICE)
    {
    #ifdef __MMI_SIMAP_SUPPORT__
        if (mmi_bootup_get_active_bt_access_profile_mode())
        {
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8)GetString(STR_SIM_ACCESS_PROFILE), MAX_LENGTH_DISPLAY_NAME - 1);
        }
        else
    #endif /* __MMI_SIMAP_SUPPORT__ */
    #ifdef __GSMCDMA_DUALSIM__
        if (mmi_bootup_is_dualsim_disconnected())
        {
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8)GetString(STR_SIM_DISCONNECTED_MSG), MAX_LENGTH_DISPLAY_NAME - 1);
        }
        else
    #endif /* __GSMCDMA_DUALSIM__ */
    
        /* L1: "Limited Service" */
    #ifdef __MMI_WLAN_FEATURES__
        if (!mmi_bootup_is_sim_valid())
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(simErrorDisplayString), MAX_LENGTH_DISPLAY_NAME - 1);
        else
    #endif /* __MMI_WLAN_FEATURES__ */
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_LIMITED_SERVICE), MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);
    }
    else    /* if ( gNoService ) */
    {
        /* L1: "No Service" */
    #ifdef __FLIGHT_MODE_SUPPORT__
        if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_MENU_FLIGHT_MODE), MAX_LENGTH_DISPLAY_NAME - 1);
        else
    #endif /* __FLIGHT_MODE_SUPPORT__ */ 
            mmi_ucs2ncpy((PS8) gNWProviderName, (PS8) GetString(STR_NO_SERVICE), MAX_LENGTH_DISPLAY_NAME - 1);
        SetLine1Text(gNWProviderName);
    }

#endif /* __MANUAL_MODE_NW_SEL__ */ 

#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim2_network_searching_complete() != MMI_FALSE)
    {
        MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea();
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_bootup_get_active_flight_mode() != FLIGHTMODE_SILENT)
    {
        mmi_netset_update_preferred_mode_service_area();
    }
#endif /* __MMI_WLAN_FEATURES__ */
}

#undef SetLine1Text
#undef SetLine2Text


/*****************************************************************************
 * FUNCTION
 *  IdleToggleProfile
 * DESCRIPTION
 *  Toggles profiles between silent mode and current activated profile on long press of # key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleToggleProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == MMI_PROFILE_SILENT)
    {
        DeactivateSilentProfile();  /* disable silent mode */
    }
    else
    {
        ActivateSilentProfile();    /* enable silent mode */

        /* If the handset enables the silent mode successfully, stop the keypad 
           tone immediately. */
        if (gactivatedprofile == MMI_PROFILE_SILENT)
        {
            StopCurrentKeyPadTone();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  IdleCallSpeedDialOnLongPress
 * DESCRIPTION
 *  Implements speed dial on idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleCallSpeedDialOnLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    S8 *tempbuffer = NULL;
    mmi_ucm_make_call_para_struct param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);

    if ((Keycode >= 1) && (Keycode <= 9))
    {
        mmi_idle_remove_dialer_screen_exit_handler();
        if (!mmi_phb_check_ready(MMI_TRUE))
        {
            return;
        }

        tempbuffer = mmi_phb_speed_dial_get_number(Keycode);
        if (tempbuffer != NULL)
        {
            mmi_ucs2cpy(g_idle_context.DialPadCallBuffer, tempbuffer);

            mmi_ucm_init_call_para(&param);
            param.dial_type     = SRV_UCM_CALL_TYPE_ALL;
            param.ucs2_num_uri  = (U16 *)g_idle_context.DialPadCallBuffer;

            mmi_ucm_call_launch(0, &param);
        }
        else
        {
            IdleShowScrNoSpeedDialNumSaved();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  IdleShowScrNoSpeedDialNumSaved
 * DESCRIPTION
 *  Displays pop up: no speed dial number saved for this digit.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleShowScrNoSpeedDialNumSaved(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(IDLE_SCREEN_ID);
    
    mmi_display_popup(
        get_string(STR_NO_SPEED_DIAL_NUM_SAVED), 
        MMI_EVENT_FAILURE);
}


/*****************************************************************************
 * FUNCTION
 *  IdleAbbrevDialling
 * DESCRIPTION
 *  Quick acces to phonebook entries.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleAbbrevDialling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tempbuffer[(MAX_LOCATION_DIGITS + 1) * ENCODING_LENGTH];
    U8 count, i = 0;
    U16 Location;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempbuffer, 0, ((MAX_LOCATION_DIGITS + 1) * ENCODING_LENGTH));

    /* Don't do anything when shifting out digits */
    if (mmi_ucs2strlen((PS8) g_idle_context.DialPadCallBuffer) >= (MAX_DIAL_PAD - 1))
    {
        return;
    }

    if ((g_idle_context.DialPadCallBuffer[0] >= '0') && (g_idle_context.DialPadCallBuffer[0] <= '9'))
    {
        /* No need to handle abbrev. dial number for (a) flight mode (2) no SIM
           inserted. */
        if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT ||
            !mmi_bootup_is_sim_valid())
        {
            return;
        }
        
        /* This loop search for '#' in DialpadCallbuffer,if # is not found before MAX_LOCATION_DIGITS then return */
        for (count = 0; (g_idle_context.DialPadCallBuffer[count] != '#'); count++)
        {
            if (count > (MAX_LOCATION_DIGITS * ENCODING_LENGTH - 1) ||
                g_idle_context.DialPadCallBuffer[count] == '*' ||
                g_idle_context.DialPadCallBuffer[count] == '+' ||
                g_idle_context.DialPadCallBuffer[count] == 'p' ||
                g_idle_context.DialPadCallBuffer[count] == 'w')
            {
                return;
            }
            tempbuffer[i] = g_idle_context.DialPadCallBuffer[count];
            i++;
        }
        if (g_idle_context.DialPadCallBuffer[count + 2] == 0)   /* no other digits after the first found # */
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            if (MTPNP_AD_Get_UsableSide() < MTPNP_AD_SIMCARD1_USABLE)
            {
                return;
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */

            Location = (U16) gui_atoi((UI_string_type) tempbuffer);
            if (mmi_phb_get_sim_entry_by_location((U16) Location) != 0)
            {
                DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
            }
        }
    }
    else if (!SSCStringParsing3())
    {
        SSCStringParsing1();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_save_number_proc
 * DESCRIPTION
 *  This function is the proc function of the phone book "Save Contact" CUI.
 * PARAMETERS
 *  evt         : [IN]      Event
 * RETURNS
 *  OK.
 *****************************************************************************/
static mmi_ret mmi_idle_save_number_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_save_contact_result_struct *event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event = (cui_phb_save_contact_result_struct *)evt;
    
    switch (event->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_OPTIONS_ID); 
            cui_phb_save_contact_close(g_idle_context.cui_save_number_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  IdleDialPadSavePhoneBook
 * DESCRIPTION
 *  Save entered number in phonebook on press of LSK on dialler screen.
 *  
 *  Temorary function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleDialPadSavePhoneBook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VOIP__
    if (IsScreenPresent(SCR_ID_VOIP_CALL_EDITOR) &&
        mmi_ucs2strlen(g_idle_context.DialPadCallBuffer) == 0)
    {        
        mmi_display_popup(
            get_string(STR_ID_VOIP_EMPTY_USERNAME), 
            MMI_EVENT_FAILURE);
    
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_OPTIONS_ID); 
    
        return;
    }
#endif /* __MMI_VOIP__ */

    mmi_frm_group_create(GRP_ID_ROOT, APP_IDLEAPP, mmi_idle_save_number_proc, NULL);
    mmi_frm_group_enter(APP_IDLEAPP, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_idle_context.cui_save_number_id = cui_phb_save_contact_create(APP_IDLEAPP);

    if (g_idle_context.cui_save_number_id == GRP_ID_INVALID)
    {
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_OPTIONS_ID); 
        return;
    }
    
#ifdef __MMI_VOIP__
    if (IsScreenPresent(SCR_ID_VOIP_CALL_EDITOR))
    {
        cui_phb_save_contact_set_voip(
            g_idle_context.cui_save_number_id,
            (U16 *)g_idle_context.DialPadCallBuffer);
    }
    else
#endif /* __MMI_VOIP__ */
    {
        cui_phb_save_contact_set_number(
            g_idle_context.cui_save_number_id,
            (U16 *)g_idle_context.DialPadCallBuffer);
    }
       
    cui_phb_save_contact_run(g_idle_context.cui_save_number_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_dialer_after_make_call_hdlr
 * DESCRIPTION
 *  TODO
 * PARAMETERS
 *  p           : [IN]          Callback parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_dialer_after_make_call_hdlr(
                mmi_ucm_after_make_call_cb_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * If the user presses "Back" on the SIM selection screen, go back to the 
     * dialer; otherwise, go back to the idle screen. 
     */
    if (p && p->result != SRV_UCM_RESULT_CANCEL)
    {
        mmi_idle_remove_dialer_screen_exit_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  DialIPNumber
 * DESCRIPTION
 *  Dial IP Number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __IP_NUMBER__
void DialIPNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
    {
        mmi_ucm_init_call_para(&param);
        param.dial_type = SRV_UCM_CALL_TYPE_ALL;
        param.ucs2_num_uri = (U16 *)g_idle_context.DialPadCallBuffer;
        param.adv_para.after_make_call_callback = mmi_idle_dialer_after_make_call_hdlr;
        param.adv_para.after_callback_user_data = NULL;
        param.adv_para.is_ip_dial = MMI_TRUE;

        mmi_ucm_call_launch(0, &param);
    }
}
#endif /* __IP_NUMBER__ */ 


#ifdef __MMI_SEARCH_WEB__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_dial_pad_clear_star_key_long_press_hdlr
 * DESCRIPTION
 *  Clear the long-press handler of star key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_dial_pad_clear_star_key_long_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR))
    {
        ClearKeyHandler(KEY_STAR, KEY_LONG_PRESS);
    }
}
#endif /* __MMI_SEARCH_WEB__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_dialer_handle_center_key
 * DESCRIPTION
 *  TODO
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_dialer_handle_center_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
    {
        mmi_ucm_init_call_para(&param);
        param.dial_type = SRV_UCM_CALL_TYPE_ALL;
        param.ucs2_num_uri = (U16 *)g_idle_context.DialPadCallBuffer;
        param.adv_para.after_make_call_callback = mmi_idle_dialer_after_make_call_hdlr;
        param.adv_para.after_callback_user_data = NULL;

        mmi_ucm_call_launch(0, &param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_dialer_handle_send_key
 * DESCRIPTION
 *  TODO
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_dialer_handle_send_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
    {
        mmi_ucm_init_call_para_for_sendkey(&param);
        param.ucs2_num_uri = (U16 *)g_idle_context.DialPadCallBuffer;
        param.adv_para.after_make_call_callback = mmi_idle_dialer_after_make_call_hdlr;
        param.adv_para.after_callback_user_data = NULL;

        mmi_ucm_call_launch(0, &param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  IdleScreenDigitHandler
 * DESCRIPTION
 *  Inputs the digits of a phone number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleScreenDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rsk_str_id;
    U8 *history_buffer;

    U16 SpeedDialKeys[MAX_SPEED_DIAL_KEYS] =
        {KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VOIP__)
    if (mmi_idle_get_dial_mode() == DIAL_MODE_WLAN)
    {
        mmi_netset_enter_wlan_dialer_screen();
        return;
    }
#endif /* defined(__MMI_VOIP__) */

    EntryNewScreen(IDLE_SCREEN_DIGIT_HANDLER_ID, ExitIdleScreenDigitHandler, NULL, NULL);

    DeInitSpecialMode();

    g_idle_context.IsOnDialerScreen = 1;
    history_buffer = GetCurrGuiBuffer(IDLE_SCREEN_DIGIT_HANDLER_ID);

#if defined(MMI_IDLE_DIAL_PAD_SUPPORT_CSK)
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
    SetDialingKeypadPhonebookHandler(mmi_phb_idle_launch);
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_idle_set_dual_sim_dialing_keypad_call_handler(
        mmi_idle_sim1_dialpad_call,
        mmi_idle_sim2_dialpad_call);
#else
    SetDialingKeypadCallHandler(mmi_idle_dialer_handle_center_key);
#endif
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */

    /* Determine the RSK string ID. */
    if (g_idle_context.IdleScreenDigitKeyCode >= 0)
    {
        rsk_str_id = STR_GLOBAL_CLEAR;
    }
    else
    {
        rsk_str_id = STR_GLOBAL_BACK;
    }

    ShowCategory16Screen(
        STR_GLOBAL_OPTIONS,
        0,
        rsk_str_id,
        0,
        (U8*) g_idle_context.DialPadCallBuffer,
        MAX_DIAL_PAD,
        history_buffer);

#if defined(MMI_IDLE_DIAL_PAD_SUPPORT_CSK)
    SetCenterSoftkeyFunction(mmi_idle_dialer_handle_center_key, KEY_EVENT_UP);
#endif

#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    /* On non-QWERTY project, the first digit should be inserted by executing
       the current key handler. */
    if (g_idle_context.IdleScreenDigitKeyCode >= 0)
    {
        ExecuteCurrKeyHandler(g_idle_context.IdleScreenDigitKeyCode, KEY_EVENT_DOWN);
    }
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

    SetLeftSoftkeyFunction(mmi_idle_entry_dial_pad_option, KEY_EVENT_UP);

    mmi_ucm_handle_sendkeys_for_call(mmi_idle_dialer_handle_send_key, KEY_EVENT_DOWN);
    
    SetKeyHandler(IdleAbbrevDialling, KEY_POUND, KEY_EVENT_UP);

    SetCategory16RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif 

    if (g_idle_context.LongPressEnable == 0)
    {
        mmi_idle_dial_pad_set_disable_long_press_handler();

    #ifdef __MMI_DUAL_SIM_MASTER__
        if(MTPNP_AD_Get_UsableSide() >= MTPNP_AD_SIMCARD1_USABLE)
    #else
        if (mmi_bootup_is_sim_valid())
    #endif
        {
            if (mmi_phb_get_speed_dial_status() == MMI_TRUE)
            {
                SetGroupKeyHandler(IdleCallSpeedDialOnLongPress, SpeedDialKeys, MAX_SPEED_DIAL_KEYS - 1, KEY_LONG_PRESS);
            }

            SetKeyHandler(DialVoiceMail, KEY_1, KEY_LONG_PRESS);
        }

        SetKeyHandler(IdleToggleProfile, KEY_POUND, KEY_LONG_PRESS);

    #ifdef __MMI_SEARCH_WEB__
        if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR))
        {
            SetKeyHandler(mmi_search_web_trigger_by_long_pressing_star, KEY_STAR, KEY_LONG_PRESS);
        }
    #endif /* __MMI_SEARCH_WEB__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitIdleScreenDigitHandler
 * DESCRIPTION
 *  Exit function for idle screen digit handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitIdleScreenDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
    {
        GenericExitScreen(IDLE_SCREEN_DIGIT_HANDLER_ID, FlightModeDigitHandler);
    }
    else
#endif /* __FLIGHT_MODE_SUPPORT__ */
#ifdef __MMI_DIALER_SEARCH__
    if (mmi_idle_ds_is_exit_from_dialer_search())
    {
        GenericExitScreen(IDLE_SCREEN_DIGIT_HANDLER_ID, mmi_idle_ds_entry_dialer_search);
    }
    else
#endif /* __MMI_DIALER_SEARCH__ */
    {
        GenericExitScreen(IDLE_SCREEN_DIGIT_HANDLER_ID, IdleScreenDigitHandler);
    }

    g_idle_context.IsOnDialerScreen = 0;
    g_idle_context.IdleScreenDigitKeyCode = -1;

    if (mmi_ucs2strlen(g_idle_context.DialPadCallBuffer))
    {
        g_idle_context.LongPressEnable = 1;
    }

#if defined(__MMI_WGUI_CSK_ENABLE__)
    ResetCenterSoftkey();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dialer
 * DESCRIPTION
 *  This function launches the dialer from the idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#ifdef __MMI_SCREEN_SWITCH_EFFECT__ 
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
#endif
#endif

#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
    {
        FlightModeDigitHandler();
    }
    else
#endif /* __FLIGHT_MODE_SUPPORT__ */ 
#ifdef __MMI_DIALER_SEARCH__
    if (mmi_idle_ds_is_dialer_search_enable())
    {
        mmi_idle_ds_entry_dialer_search();
    }
    else
#endif /* __MMI_DIALER_SEARCH__ */
    {
        IdleScreenDigitHandler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  HandleIdleScreenDigitEntry
 * DESCRIPTION
 *  This function is entered when a key is pressed at the Idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleIdleScreenDigitEntry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    memset((U8*) g_idle_context.DialPadCallBuffer, 0, sizeof((U8*) g_idle_context.DialPadCallBuffer));
    
    g_idle_context.IdleScreenDigitKeyCode = Keycode;

    mmi_idle_entry_dialer();
}


#ifdef __MMI_MULTITAP_KEY_0__
extern void wgui_cat016_multitap_0_long_press_key_handler(void);
extern void MMI_key_0_up(void);
#endif /* #ifdef __MMI_MULTITAP_KEY_0__ */
/*****************************************************************************
 * FUNCTION
 *  IdleDisableLongPress
 * DESCRIPTION
 *  Disbale some long press handlers on up event of key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleDisableLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;
    FuncPtr original_key_up_handler;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.LongPressEnable = 1;

    GetkeyInfo(&key_code, &key_type);

    /* Restore the original LONG_PRESS and UP handlers. */
    wgui_restore_key_handlers();

    /* Execute the original UP key handler. */
    original_key_up_handler = GetKeyHandler(key_code, key_type);

    if (original_key_up_handler)
    {
        original_key_up_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  IdleSetKeyPadLockFlag
 * DESCRIPTION
 *  This function is called when time out occurs on idle screen to set key pad lock flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleSetKeyPadLockFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_KEYPAD_LOCK_TIMEOUT);

    g_keylock_context.gKeyPadLockFlag = 1;

#ifdef __MMI_VUI_HOMESCREEN__
    /* If the ME is in the keypad locked state, fold the widget bar and the 
       shortcut pool. */
    if (mmi_vhs_is_enable())
    {
        mmi_vhs_fold_all();
    }
#endif /* __MMI_VUI_HOMESCREEN__ */

    if (g_idle_context.ScreenSaverRunFlag != 1)
    {
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        if (mmi_op11_hs32_is_enable())
        {
            mmi_op11_hs32_discard_history();
        }
    #endif            

    #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP11_HOMESCREEN__ */

    #ifdef __MMI_OP12_TOOLBAR__
        if (mmi_tb_is_enable())
        {
            mmi_tb_discard_history();
        }
    #endif /* __MMI_OP12_TOOLBAR__ */

        EntryScrKeyPadLockMessage();
    }
    else
    {
        /* Robin 1216, Screen saver is running, using SetKeyHandler() to prevent redrew softkey */
    #ifdef __MMI_TOUCH_SCREEN__
        SetKeyHandler(IdleRSKPressOnScreenSaver, KEY_SEND, KEY_EVENT_DOWN);
    #else /* __MMI_TOUCH_SCREEN__ */ 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__    /* Robin 1223 */
        SetKeyHandler(IdleRSKPressOnScreenSaver, KEY_RSK, KEY_EVENT_DOWN);
    #endif 

    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
        SetKeyHandler(IdleRSKPressOnScreenSaver, KEY_LSK, KEY_EVENT_DOWN);
    #endif 

    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }

    StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  IdleSetStatusIcon
 * DESCRIPTION
 *  Show Icon
 * PARAMETERS
 *  index       [IN]        
 *  U8(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IdleSetStatusIcon(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_show_icon(index);
}


/*****************************************************************************
 * FUNCTION
 *  IdleResetStatusIcon
 * DESCRIPTION
 *  Hide Icon
 * PARAMETERS
 *  index       [IN]        
 *  U8(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IdleResetStatusIcon(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_hide_icon(index);
}


/*****************************************************************************
 * FUNCTION
 *  IsChineseSet
 * DESCRIPTION
 *  This function checks whether the current language is set as Chinese or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
pBOOL IsChineseSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) == 0)
    {
        return 1;
    }

    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE) == 0)
    {
        return 1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  IsEnglishSet
 * DESCRIPTION
 *  This function checks whether the current language is set as English or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
pBOOL IsEnglishSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH) == 0)
    {
        return 1;
    }

    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_AUTO) == 0)
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  IsTrChineseSet
 * DESCRIPTION
 *  This function checks whether the current language is set as traditional
 *  Chinese or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
pBOOL IsTrChineseSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) == 0)
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  IsSmChineseSet
 * DESCRIPTION
 *  This function checks whether the current language is set as simplified
 *  Chinese or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
pBOOL IsSmChineseSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE) == 0)
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ReadValueCityNVRAM
 * DESCRIPTION
 *  Read city values from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReadValueCityNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 city_chosen1;
    U8 city_chosen2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE, &error);
    if (city_chosen1 == 0xff)
    {
        city_chosen1 = PhnsetGetHomeCity();
        city_chosen1++;
        WriteValue(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE, &error);

    }
    ReadValue(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE, &error);
    if (city_chosen2 == 0xff)
    {
        city_chosen2 = 0;
        WriteValue(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryIdleAppSubLcdWithErrorMsg
 * DESCRIPTION
 *  Show Sub LCD idle screen with error message
 * PARAMETERS
 *  message             [?]         
 *  message_icon        [IN]        
 *  history_buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void EntryIdleAppSubLcdWithErrorMsg(U8 *message, U16 message_icon, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    DinitSubLCDHistory();
    ShowCategory301Screen(message, message_icon, history_buffer);
    SetSubLCDExitHandler(ExitSubLCDIdleScr);
}


/*****************************************************************************
 * FUNCTION
 *  ShowIdleAppSubLcd
 * DESCRIPTION
 *  Show Sub LCD idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
extern U8 gMMIClamState;
#endif 

void ShowIdleAppSubLcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *CityAbbr1, *CityAbbr2;
    FLOAT time_difference;
    U8 city_chosen1;
    U8 city_chosen2;
    U8 home_city_sublcd;
    FLOAT diff1, diff2;
    S16 error = -1;
    MMI_BOOL show_category_333_screen = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_MASTER_MODE__
    if (IsSubLCDInMasterMode())
    {
        return ;
    }
    if (EntrySubLCDMasterFromIdle())
    {
        return ;
    }
#endif /* __MMI_SUBLCD_MASTER_MODE__ */   

    ExecSubLCDCurrExitHandler();
    DinitSubLCDHistory();

    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_ON_IDLE_NORMAL;
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (gMMIClamState == 1)
    {
        ShowCategory310Screen(get_string(STR_GLOBAL_LOGO));
    }
    else
    {
        ShowSubLCDAnalogClockScreen();
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 


#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        show_category_333_screen = MMI_TRUE;
    }
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        show_category_333_screen = MMI_TRUE;
    }
#endif /* __MMI_FM_RADIO__ */ 

    if (show_category_333_screen)
    {
        ShowCategory333Screen();
    }
    else
    {
        ReadValue(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE, &error);
        ReadValue(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE, &error);
        home_city_sublcd = PhnsetGetHomeCity();
        home_city_sublcd++;

        if (city_chosen1 > 57)
        {
            city_chosen1 = 1;
        }

        if (city_chosen2 > 57)
        {
            city_chosen2 = 1;
        }
        if ((TimeZoneData[city_chosen1].CityAbbr != STR_WCLOCK_CITY_ABBRE_NONE) &&
            (TimeZoneData[city_chosen2].CityAbbr != STR_WCLOCK_CITY_ABBRE_NONE))
        {

            CityAbbr1 = GetString((U16) TimeZoneData[city_chosen1].CityAbbr);
            CityAbbr2 = GetString((U16) TimeZoneData[city_chosen2].CityAbbr);
            diff1 = TimeZoneData[city_chosen1].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;
            diff2 = TimeZoneData[city_chosen2].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;

            ShowCategory303Screen((U8*) CityAbbr1, (U8*) CityAbbr2, diff1, diff2, NULL);

        }
        else if (TimeZoneData[city_chosen1].CityAbbr != STR_WCLOCK_CITY_ABBRE_NONE)
        {
            CityAbbr1 = GetString((U16) TimeZoneData[city_chosen1].CityAbbr);
            time_difference = TimeZoneData[city_chosen1].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;
            ShowCategory312Screen((U8*) CityAbbr1, time_difference, NULL);

        }
        else if (TimeZoneData[city_chosen2].CityAbbr != STR_WCLOCK_CITY_ABBRE_NONE)
        {
            CityAbbr2 = GetString((U16) TimeZoneData[city_chosen2].CityAbbr);
            time_difference = TimeZoneData[city_chosen2].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;
            ShowCategory312Screen((U8*) CityAbbr2, time_difference, NULL);

        }
        else if ((TimeZoneData[city_chosen1].CityAbbr == STR_WCLOCK_CITY_ABBRE_NONE) &&
                 (TimeZoneData[city_chosen2].CityAbbr == STR_WCLOCK_CITY_ABBRE_NONE))
        {
            city_chosen1 = home_city_sublcd;
            CityAbbr1 = GetString((U16) TimeZoneData[city_chosen1].CityAbbr);
            time_difference = TimeZoneData[city_chosen1].CityTimeZone - TimeZoneData[home_city_sublcd].CityTimeZone;
            ShowCategory312Screen((U8*) CityAbbr1, time_difference, NULL);
        }
    }
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose() && 
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
        SetKeyHandler(mmi_sublcd_camera_entry_option_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    }
#endif
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */
    SetSubLCDExitHandler(ExitSubLCDIdleScr);

#ifdef __MMI_SUBLCD_MASTER_MODE__
    UnFreezeSubLCD();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SubLCDIdleScreen
 * DESCRIPTION
 *  Displays the idle screen of sub-LCD
 * PARAMETERS
 *  funcptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDIdleScreen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_MASTER_MODE__
    if (IsSubLCDInMasterMode())
    {
        return;
    }
    if (EntrySubLCDMasterFromIdle())
    {
        return;
    }
#endif /* __MMI_SUBLCD_MASTER_MODE__ */   

    if (g_pwr_context.PrevScreenIndicator == ENTER_PIN_SCR)
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_ENTER_PIN_MSG), 0, NULL);
    }
    else if ((g_pwr_context.PrevScreenIndicator == ENTER_PUK_SCR) ||
             (g_pwr_context.PrevScreenIndicator == ENTER_CONFIRM_PIN) ||
             (g_pwr_context.PrevScreenIndicator == ENTER_NEW_PIN))
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_ENTER_PUK_MSG), 0, NULL);
    }
    else if (g_pwr_context.PrevScreenIndicator == ENTER_PHONELOCK)
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_ENTER_PHONELOCK_MSG), 0, NULL);
    }
    else if (g_pwr_context.PrevScreenIndicator == ENTER_SIM_INSERTION)
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_SIM_INSERTION_MSG), 0, NULL);
    }
    else if (g_pwr_context.PrevScreenIndicator == ENTER_SIM_BLOCK)
    {
        EntryIdleAppSubLcdWithErrorMsg((PU8) GetString(STR_SUBLCD_SIM_BLOCK_MSG), 0, NULL);
    }
    else /* if (g_pwr_context.PrevScreenIndicator == ENTER_IDLE_SCR) */
    {
        /* City names and time difference need to be added here  */
        ShowIdleAppSubLcd();
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

#ifdef __MMI_SUBLCD_MASTER_MODE__
    UnFreezeSubLCD();
#endif

#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDIdleScr
 * DESCRIPTION
 *  Exit sublcd idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDIdleScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.IsSubLcdOnIdleScreen = SUBLCD_NOT_ON_IDLE;
    SubLCDHistory.entryFuncPtr = SubLCDIdleScreen;
    AddSubLCDHistory(&SubLCDHistory);
}


/*****************************************************************************
 * FUNCTION
 *  IdleHandleKeypadLockProcess
 * DESCRIPTION
 *  This fn handle the press of star key , when LSK is pressed first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleHandleKeypadLockProcess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(KEYPAD_LOCK_TIMER);
    g_idle_context.RskPressedFromIdleApp = 0;

#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    g_idle_context.ToMainMenuScrFromIdleApp = 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  IdleHandlePoundKeyForKeypadLock
 * DESCRIPTION
 *  This fn handle the press of star key , when LSK is pressed first
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleHandlePoundKeyForKeypadLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
    if (g_idle_context.RskPressedFromIdleApp == 0)
    {
        return;
    }
    g_idle_context.RskPressedFromIdleApp = 0;
#endif /* __MMI_KEYPAD_LOCK_PATTERN_1__ */ 

#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    if (g_idle_context.ToMainMenuScrFromIdleApp == 0)
    {
        return;
    }
    g_idle_context.ToMainMenuScrFromIdleApp = 0;
#endif /* __MMI_KEYPAD_LOCK_PATTERN_2__ */ 

    StopTimer(KEYPAD_LOCK_TIMER);
    g_keylock_context.gKeyPadLockFlag = 1;

#ifdef __MMI_VUI_HOMESCREEN__
    /* If the ME is in the keypad locked state, fold the widget bar and the
       shortcut pool. */
    if (mmi_vhs_is_enable())
    {
        mmi_vhs_fold_all();
    }
#endif /* __MMI_VUI_HOMESCREEN__ */

#ifdef __MMI_OP12_TOOLBAR__
    /* On toolbar, press RSK does not open a new category screen. Thus, 
       DisplayIdleScreen will not do anything because there is nothing in the 
       history. Directly discard toolbar history and redraw the screen. */
    if (mmi_tb_is_enable())
    {
        mmi_tb_discard_history();
        EntryIdleScreen();
    }
    else
#endif /* __MMI_OP12_TOOLBAR__ */
    {
        DisplayIdleScreen();
    }
}


#if defined (__MANUAL_MODE_NW_SEL__) && !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && !defined(__MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_manual_network_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_manual_network_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_idle_context.RskPressedFromIdleApp = 1;

    mmi_display_popup_confirm(
        get_string(STR_GLOBAL_YES), 
        get_image(IMG_GLOBAL_YES), 
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        get_string(STR_ID_IDLE_NW_SEL_CONFIRM),
        MMI_EVENT_QUERY);
    
    SetLeftSoftkeyFunction(NETSETGetPLMNListCheck, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#if (defined(__MMI_KEYPAD_LOCK_PATTERN_1__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__))
    if (g_idle_context.RskPressedFromIdleApp == 1)
    {
        StartTimer(KEYPAD_LOCK_TIMER, KEYPAD_LOCK_TIMEOUT, IdleHandleKeypadLockProcess);
        SetKeyHandler(IdleHandlePoundKeyForKeypadLock, KEY_POUND, KEY_EVENT_UP);
    }
#endif /* (defined(__MMI_KEYPAD_LOCK_PATTERN_1__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__)) */ 
}
#endif /* defined (__MANUAL_MODE_NW_SEL__) && !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && !defined(__MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  IdleSetLRKey
 * DESCRIPTION
 *  Change Idlescreen's L or RSK according to network status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IdleSetLRKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr lsk_func = NULL, rsk_func = NULL;
    U16 lsk_str = 0, rsk_str = 0;
    
#if defined(__MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__)
    FuncPtr tmp_func;
    U16 tmp_str;
#endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag)
    {
    #ifdef __MMI_TOUCH_SCREEN__
    #ifdef __MMI_KEYPAD_LOCK_PROMPT_TEXT__
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_1__
        mmi_idle_set_rsk(EntryScrKeyPadLockOnPessingAnyKey, KEY_EVENT_UP);
    #endif 
    #ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
        mmi_idle_set_lsk(EntryScrKeyPadLockOnPessingAnyKey, KEY_EVENT_UP);
    #endif 
    #endif /* __MMI_KEYPAD_LOCK_PROMPT_TEXT__ */ 
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    else    /* keypad unlocked */
    {
        /*
         * In the following situation, the LSK and RSK do not change according
         * to the network status:
         * 
         *  1) SIM access profile
         *  2) OP11 home screen
         *  3) OP12 toolbar
         */
        if (mmi_bootup_get_active_bt_access_profile_mode() ||
        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
            mmi_op11_hs32_is_enable() ||
        #endif       
        #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
        #endif /* __MMI_OP11_HOMESCREEN__ */
        #ifdef __MMI_OP12_TOOLBAR__
            mmi_tb_is_enable() ||
        #endif /* __MMI_OP12_TOOLBAR__ */
            MMI_FALSE)
        {
            return;
        }

    #if defined (__MANUAL_MODE_NW_SEL__) && \
        !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && \
        !defined (__MMI_VUI_HOMESCREEN__) && \
        !defined(__MMI_DUAL_SIM_MASTER__)
        if (g_pwr_context.CurrentServiceType == LIMITED_SERVICE && 
            mmi_bootup_get_plmn_selection_mode() == MANUAL_MODE && 
        #ifdef __MMI_WLAN_FEATURES__
            mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY && 
        #endif
            mmi_bootup_is_nw_registration_ok() != MMI_FALSE)
        {
            lsk_func = EntryMainMenuFromIdleScreen;

        #ifdef __MMI_OP01_DCD__
            if (MMI_TRUE == mmi_dcd_is_switch_on())
            {
                rsk_str = STR_ID_DCD;
                rsk_func = mmi_dcd_entry_main_option;
            }
            else
        #endif /* __MMI_OP01_DCD__ */
        #ifdef __OP12__
            {
                rsk_str = STR_ID_IDLE_OP12_LIVE;
                rsk_func = mmi_idle_entry_op12_live;
            }
        #else /* __OP12__ */
            {
                rsk_str = STR_GLOBAL_SELECT;
                rsk_func = mmi_idle_entry_manual_network_selection;
            }
        #endif /* __OP12__ */
        }
        else
    #endif /* defined (__MANUAL_MODE_NW_SEL__) && !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && !defined(__MMI_DUAL_SIM_MASTER__) */ 
        {
            lsk_func = EntryMainMenuFromIdleScreen;

        #ifdef __MMI_OP01_DCD__
            if (MMI_TRUE == mmi_dcd_is_switch_on())
            {
                rsk_str = STR_ID_DCD;
                rsk_func = mmi_dcd_entry_main_option;
            }
            else
        #endif /* __MMI_OP01_DCD__ */
        #ifdef __OP12__
            {
                rsk_str = STR_ID_IDLE_OP12_LIVE;
                rsk_func = mmi_idle_entry_op12_live;
            }
        #else /* __OP12__ */
            {
                rsk_func = mmi_phb_idle_launch;
            }
        #endif /* __OP12__ */
        }

    #if defined(__MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__)
        /* Swap the LSK and RSK handler. */
        tmp_func = lsk_func;
        lsk_func = rsk_func;
        rsk_func = tmp_func;

        /* Swap the LSK and RSK string. */
        tmp_str = lsk_str;
        lsk_str = rsk_str;
        rsk_str = tmp_str;
    #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */
    
        if (lsk_str != 0)
        {
            ChangeLeftSoftkey(lsk_str, 0);
        }
        mmi_idle_set_lsk(lsk_func, KEY_EVENT_UP);

        if (rsk_str != 0)
        {
            ChangeRightSoftkey(rsk_str, 0);
        }
        mmi_idle_set_rsk(rsk_func, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_flight_mode_handler
 * DESCRIPTION
 *  This function sets the handler for the flight mode idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_flight_mode_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)
    /* Venus home screen uses END key for manual keypad lock. */
    wgui_status_icon_bar_register_pen_event_handler(
        STATUS_ICON_KEYPAD_LOCK,
        WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
        IdleSetKeyPadLockFlag);
#endif /* defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__) */ 

    /*
     * Set up LSK, RSK and CSK. If the softkey area of the idle screen already
     * has other UI component (e.g., the native idle screen with the idle 
     * shortcut or the Venus idle screen), we cannot use 
     * Set[Left|Right|Center]SoftKey handler. We should use SetKeyHandler.
     */

#ifdef __MMI_VRSI__
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_VALID) || 
        (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_VALID))
#endif
    {
        mmi_idle_set_rsk(mmi_vrsi_rcg_pre_entry, KEY_LONG_PRESS);
    }
#endif /* __MMI_VRSI__ */

#ifdef __MMI_VRSD__
#ifdef __MMI_DUAL_SIM_MASTER__
    if ((MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_VALID) || 
        (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_VALID))
#endif
    {
        mmi_idle_set_rsk(mmi_vrsd_rcg_pre_entry, KEY_LONG_PRESS);
    }
#endif

#ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
    mmi_idle_set_lsk(mmi_phb_idle_launch, KEY_EVENT_UP);
    mmi_idle_set_rsk(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
#else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */
    mmi_idle_set_lsk(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
    mmi_idle_set_rsk(mmi_phb_idle_launch, KEY_EVENT_UP);
#endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */

#if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_idle_set_csk(mmi_idle_entry_dialer, KEY_EVENT_UP);
#endif

    /*
     * Set up other key handlers.
     */

#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_vhs_is_enable())
    {
        SetKeyHandler(vadp_p2v_hs_rotate_desktop, KEY_ENTER, KEY_EVENT_DOWN);
    }

    /* Allow to keypad lock even if the Venus home screen is off. */
    SetKeyHandler(mmi_vhs_entry_lock_keypad_confirm, KEY_END, KEY_EVENT_UP);
#endif /* __MMI_VUI_HOMESCREEN__ */

#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    RegisterDedicatedKeyHandlers();
#elif !defined(__DISABLE_SHORTCUTS_MENU__)
    SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
#endif

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
    SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
#ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose())
        SetKeyHandler(mmi_sublcd_camera_entry_option_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    else
        SetKeyHandler(mmi_camera_lauch, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
#else
    SetKeyHandler(mmi_camera_lauch, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
#endif
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */    
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
    SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_camco_launch, KEY_CAMERA, KEY_EVENT_DOWN);
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */

#ifdef __MMI_MAPBAR_GIS__
    SetKeyHandler(mmi_gis_enter_app_check_conform, KEY_EXTRA_2, KEY_EVENT_UP);
#endif

    mmi_idle_set_digit_key_handler();

    /* volume key */
    SetDefaultVolumeKeyHandlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryFlightModeIdleScreen
 * DESCRIPTION
 *  Entry idle screen in flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFlightModeIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change current service type */
    g_pwr_context.CurrentServiceType = NO_SERVICE;

#ifdef __MMI_DUAL_SIM_MASTER__
    g_pwr_context_2.CurrentServiceType = NO_SERVICE;
    MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_NO_SERVICE);
    MTPNP_AD_Set_Card2ServiceType(MTPNP_AD_NO_SERVICE);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_FLIGHT_MODE);

    StopLEDPatternNoService();
    
    /* reset icons to indicate no service available */
    wgui_status_icon_bar_change_icon_level(STATUS_ICON_SIGNAL_STRENGTH, 0);
    wgui_status_icon_bar_change_icon_level(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, 0);
    IdleResetStatusIcon(STATUS_ICON_ROAMING);

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if (mmi_op11_hs32_is_enable())
    {
        mmi_op11_hs32_entry_homescreen();
    }
    else
#endif /* __MMI_OP11_HOMESCREEN_0301__ */
#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_vhs_is_enable())
    {
    #ifdef __MMI_VUI_3D_CUBE_APP__
        mmi_cube_vapp_show_homescreen();
    #else
        mmi_vhs_show_homescreen();
    #endif
    }
    else
#endif /* __MMI_VUI_HOMESCREEN__ */
    {
        IdleRefreshServiceIndicationArea();
        
    #if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__)
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    #endif 

    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
        if (PhnsetGetCalendarIdleScreen() != 0)
        {
            idle_screen_enable_calendar_display();
        }
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
        
    #ifdef __MMI_SWFLASH__
        if (dispchar_iswp_swflash() == MMI_TRUE)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT,
                IDLE_SCREEN_LSK_ICON,   /* Menu */
                IDLE_SCREEN_RSK_TEXT,
                IDLE_SCREEN_RSK_ICON,
                PhnsetGetCurWallPaperIdx(), 
                idle_screen_wallpaper_name, 
                NULL);
        }
        else
    #endif /* _MMI_SWFLASH__ */
    #ifdef __MMI_AVATAR__
        if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT,
                IDLE_SCREEN_LSK_ICON,
                IDLE_SCREEN_RSK_TEXT,
                IDLE_SCREEN_RSK_ICON,
                PhnsetGetCurWallPaperIdx(), 
                NULL, 
                NULL);
        }
        else
    #endif /* __MMI_AVATAR__ */
        {
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            ShowCategory33Screen(
                IDLE_SCREEN_RSK_TEXT, 
                IDLE_SCREEN_RSK_ICON, 
                IDLE_SCREEN_LSK_TEXT, 
                IDLE_SCREEN_LSK_ICON, 
                NULL);
        #else 
            ShowCategory33Screen(
                IDLE_SCREEN_LSK_TEXT, 
                IDLE_SCREEN_LSK_ICON, 
                IDLE_SCREEN_RSK_TEXT,
                IDLE_SCREEN_RSK_ICON, 
                NULL);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */
            mmi_phnset_save_wallpaper_to_speedup();
        }
    }

#ifdef __MMI_TOUCH_DIAL_SCREEN__
    memset((U8*) g_idle_context.DialPadCallBuffer, 0, sizeof((U8*) g_idle_context.DialPadCallBuffer));
#endif

    mmi_idle_set_flight_mode_handler();
    ClearKeyEvents();

    ForceSubLCDScreen(ShowIdleAppSubLcd);
}


/*****************************************************************************
 * FUNCTION
 *  EntryFlightModeKeypadLockScreen
 * DESCRIPTION
 *  Entry keypad lock screen in flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFlightModeKeypadLockScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_set_keypad_lock_string();

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if (mmi_op11_hs32_is_enable())
    {
        mmi_op11_hs32_entry_homescreen();
    }
    else
#endif /* __MMI_OP11_HOMESCREEN_0301__ */
#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_vhs_is_enable())
    {
    #ifdef __MMI_VUI_3D_CUBE_APP__
        mmi_cube_vapp_show_homescreen();
    #else
        mmi_vhs_show_homescreen();
    #endif
    }
    else
#endif /* __MMI_VUI_HOMESCREEN__ */
    {
        IdleRefreshServiceIndicationArea();
        
    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
        if (PhnsetGetCalendarIdleScreen() != 0)
        {
            idle_screen_enable_calendar_display();
        }
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
        
    #ifdef __MMI_SWFLASH__
        if (dispchar_iswp_swflash())
        {
            ShowCategory34Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                PhnsetGetCurWallPaperIdx(), 
                idle_screen_wallpaper_name, 
                NULL);
        }
        else
    #endif /* _MMI_SWFLASH__ */    
    #ifdef __MMI_AVATAR__
        if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
        {
            ShowCategory34Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                PhnsetGetCurWallPaperIdx(), 
                NULL, 
                NULL);
        }
        else
    #endif /* __MMI_AVATAR__ */
        {
            ShowCategory33Screen(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID,
                NULL);
            mmi_phnset_save_wallpaper_to_speedup();
        }
    }

    mmi_idle_generic_keypad_lock_key_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_flight_mode_dialpad_call
 * DESCRIPTION
 *  This function is the SEND key handler of the dial pad in the flight mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_flight_mode_dialpad_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
    {
        mmi_ucm_init_call_para(&param);
        param.dial_type = SRV_UCM_CALL_TYPE_ALL;
        param.ucs2_num_uri = (U16 *)g_idle_context.DialPadCallBuffer;
        param.adv_para.after_make_call_callback = mmi_idle_dialer_after_make_call_hdlr;
        param.adv_para.after_callback_user_data = NULL;

        mmi_ucm_call_launch(0, &param); /* just to display error popup */
    }
}


/*****************************************************************************
 * FUNCTION
 *  FlightModeDigitHandler
 * DESCRIPTION
 *  Flight mode digit handler in dial pad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FlightModeDigitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *history_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(IDLE_SCREEN_DIGIT_HANDLER_ID, ExitIdleScreenDigitHandler, NULL, NULL);

    g_idle_context.IsOnDialerScreen = 1;
    history_buffer = GetCurrGuiBuffer(IDLE_SCREEN_DIGIT_HANDLER_ID);

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
    SetDialingKeypadPhonebookHandler(mmi_phb_idle_launch);
#endif

    ShowCategory16Screen(
        STR_GLOBAL_SAVE,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) g_idle_context.DialPadCallBuffer,
        MAX_DIAL_PAD,
        history_buffer);

#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    /* On non-QWERTY project, the first digit should be inserted by executing
       the current key handler. */
    if (g_idle_context.IdleScreenDigitKeyCode >= 0)
    {
        ExecuteCurrKeyHandler(g_idle_context.IdleScreenDigitKeyCode, KEY_EVENT_DOWN);
    }
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

    SetKeyHandler(mmi_idle_flight_mode_dialpad_call, KEY_SEND, KEY_EVENT_DOWN);
    SetCategory16RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* diamond, 2005/11/14 Allow to entry phonebook in flight mode */
    SetLeftSoftkeyFunction(IdleDialPadSavePhoneBook, KEY_EVENT_UP);
    SetKeyHandler(IdleAbbrevDialling, KEY_POUND, KEY_EVENT_UP);

    if (g_idle_context.LongPressEnable == 0)
    {
        mmi_idle_dial_pad_set_disable_long_press_handler();
        SetKeyHandler(IdleToggleProfile, KEY_POUND, KEY_LONG_PRESS);
    }
}
/* end, diamond */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_star_key_disable_long_press
 * DESCRIPTION
 *  Special handler for star key pressed in touch screen dial pad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_star_key_disable_long_press(void)
{
#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


#if defined(__MMI_SIMAP_SUPPORT__) || defined(__GSMCDMA_DUALSIM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_bt_access_profile_handler
 * DESCRIPTION
 *  This function sets the handler for the SAP mode idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_bt_access_profile_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)
    /* Venus home screen uses END key for manual keypad lock. */
    wgui_status_icon_bar_register_pen_event_handler(
        STATUS_ICON_KEYPAD_LOCK,
        WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
        IdleSetKeyPadLockFlag);
#endif /* defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__) */ 
    
    /*
     * Set up LSK, RSK and CSK. If the softkey area of the idle screen already
     * has other UI component (e.g., the native idle screen with the idle 
     * shortcut or the Venus idle screen), we cannot use 
     * Set[Left|Right|Center]SoftKey handler. We should use SetKeyHandler.
     */
     
#ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
    mmi_idle_set_rsk(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
    mmi_idle_set_lsk(mmi_phb_idle_launch, KEY_EVENT_UP);
#else /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */
    mmi_idle_set_lsk(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
    mmi_idle_set_rsk(mmi_phb_idle_launch, KEY_EVENT_UP);
#endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */

#if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_idle_set_csk(mmi_idle_entry_dialer, KEY_EVENT_UP);
#endif
    
    /*
     * Set up other key handlers.
     */
     
#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_vhs_is_enable())
    {
        SetKeyHandler(vadp_p2v_hs_rotate_desktop, KEY_ENTER, KEY_EVENT_DOWN);
    }

    /* Allow to keypad lock even if the Venus home screen is off. */
    SetKeyHandler(mmi_vhs_entry_lock_keypad_confirm, KEY_END, KEY_EVENT_UP);
#endif /* __MMI_VUI_HOMESCREEN__ */

#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    RegisterDedicatedKeyHandlers();
#elif !defined(__DISABLE_SHORTCUTS_MENU__)
    SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
#endif

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
    SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
#ifdef __MMI_SUBLCD_CAMERA__
    if (IsClamClose())
        SetKeyHandler(mmi_sublcd_camera_entry_option_screen, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    else
        SetKeyHandler(mmi_camera_lauch, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
#else
    SetKeyHandler(mmi_camera_lauch, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
#endif
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
#ifdef __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__
    SetKeyHandler(CheckAndStopAudioPlayer, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_camco_launch, KEY_CAMERA, KEY_EVENT_DOWN);
#endif /* __MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__ */
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)*/

#ifdef __MMI_MAPBAR_GIS__
    SetKeyHandler(mmi_gis_enter_app_check_conform, KEY_EXTRA_2, KEY_EVENT_UP);
#endif

    mmi_idle_set_digit_key_handler();

    /* volume key */
    SetDefaultVolumeKeyHandlers();

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY || 
        mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
    {
        mmi_idle_set_dial_mode(DIAL_MODE_WLAN);
    }
    else
    {
        mmi_idle_set_dial_mode(DIAL_MODE_GSM);
    }
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_bt_access_profile_idle_screen
 * DESCRIPTION
 *  Entry idle screen in BT access profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_bt_access_profile_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_SIM_ACCESS);

    StopLEDPatternNoService();

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if (mmi_op11_hs32_is_enable())
    {
        mmi_op11_hs32_entry_homescreen();
    }
    else
#endif /* __MMI_OP11_HOMESCREEN_0301__ */
#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_vhs_is_enable())
    {
    #ifdef __MMI_VUI_3D_CUBE_APP__
        mmi_cube_vapp_show_homescreen();
    #else
        mmi_vhs_show_homescreen();
    #endif
    }
    else
#endif /* __MMI_VUI_HOMESCREEN__ */
    {
        IdleRefreshServiceIndicationArea();
        
    #if defined(__MMI_WGUI_CSK_ENABLE__) && defined(__MMI_TOUCH_SCREEN__)
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    #endif 
        
    #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
        if (PhnsetGetCalendarIdleScreen() != 0)
        {
            idle_screen_enable_calendar_display();
        }
    #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
    
    #ifdef __MMI_SWFLASH__
        if (dispchar_iswp_swflash() == MMI_TRUE)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT,
                IDLE_SCREEN_LSK_ICON,   /* Menu */
                IDLE_SCREEN_RSK_TEXT,
                IDLE_SCREEN_RSK_ICON,
                PhnsetGetCurWallPaperIdx(), 
                idle_screen_wallpaper_name, 
                NULL);
        }
        else
    #endif /* _MMI_SWFLASH__ */
    #ifdef __MMI_AVATAR__
        if (PhnsetGetDisplayType(PhnsetGetCurWallPaperIdx()) == PHNSET_TYPE_DISP_AVATAR)
        {
            ShowCategory34Screen(
                IDLE_SCREEN_LSK_TEXT,
                IDLE_SCREEN_LSK_ICON,   /* Menu */
                IDLE_SCREEN_RSK_TEXT,
                IDLE_SCREEN_RSK_ICON,
                PhnsetGetCurWallPaperIdx(), 
                NULL, 
                NULL);
        }
        else
    #endif /* __MMI_AVATAR__ */
        {
        #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
            ShowCategory33Screen(
                IDLE_SCREEN_RSK_TEXT, 
                IDLE_SCREEN_RSK_ICON, 
                IDLE_SCREEN_LSK_TEXT,
                IDLE_SCREEN_LSK_ICON, 
                NULL);
        #else 
            ShowCategory33Screen(
                IDLE_SCREEN_LSK_TEXT, 
                IDLE_SCREEN_LSK_ICON, 
                IDLE_SCREEN_RSK_TEXT,
                IDLE_SCREEN_RSK_ICON, 
                NULL);
        #endif /* __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__ */
            mmi_phnset_save_wallpaper_to_speedup();
        }
    }

#ifdef __MMI_TOUCH_DIAL_SCREEN__
    memset((U8*) g_idle_context.DialPadCallBuffer, 0, sizeof((U8*) g_idle_context.DialPadCallBuffer));
#endif 
    
    mmi_idle_set_bt_access_profile_handler();
    ClearKeyEvents();
    
    ForceSubLCDScreen(ShowIdleAppSubLcd);
}
#endif /* defined(__MMI_SIMAP_SUPPORT__) || defined(__GSMCDMA_DUALSIM__) */


/* For the detail information, please refer to IdleAppGprot.h */
MMI_BOOL mmi_idle_is_disp_available(mmi_idle_disp_item_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If the user is on the idle screen now, cannot call this function to 
       determine whether some item can be shown on the idle screen; otherwise,
       the state of idle screen might be reset. */
    MMI_ASSERT(!mmi_idle_is_on_idle_screen());
    
    switch (type)
    {
        /*
         * Owner number
         */
        case MMI_IDLE_DISP_OWNER_NUMBER:
        {
            /* If it is not possible to show the owner number, e.g., OP11 home
               screen or non-full sevice, return FALSE directly. */
            if (
            #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
            #endif
                !mmi_bootup_is_sim_valid())
            {
                break;
            }

            /* Enable calendar display to calculate how many lines can be shown
               on the idle screen (owner number is shown on line 2). */
        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
            if (PhnsetGetCalendarIdleScreen())
            {
                idle_screen_enable_calendar_display();
            }
        #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

            if (wgui_cat033_get_number_of_informaiont_line() > 1)
            {
                ret = MMI_TRUE;
            }
            
            wgui_cat033_reset_reminder_state();

            break;
        }
        default:
            MMI_ASSERT(0);
            break;
    }
    
    return ret;
}


/* For the detail information, please refer to IdleAppGprot.h */
pBOOL mmi_idle_is_allow_to_display_song_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP12_TOOLBAR__
    if (mmi_tb_is_enable() && mmi_tb_is_open())
    {
        return MMI_FALSE;
    }
#endif /* __MMI_OP12_TOOLBAR__ */

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD || MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT)
    {
        return MMI_TRUE;
    }
    else if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 && MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_VALID)
    {
        return MMI_TRUE;
    }
    else if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_VALID)
    {
        return MMI_TRUE;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_valid())
    {
    	return MMI_TRUE;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_SIMAP_SUPPORT__
    else if (mmi_bootup_get_active_bt_access_profile_mode())
    {
        return MMI_TRUE;
    }
#endif /* __MMI_SIMAP_SUPPORT__ */
#ifdef __GSMCDMA_DUALSIM__
    else if (mmi_bootup_is_dualsim_disconnected())
    {
        return MMI_TRUE;
    }
#endif /* __GSMCDMA_DUALSIM__ */
#ifdef __MMI_WLAN_FEATURES__
    else if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
    	return MMI_TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */
    else
    {
    	return MMI_FALSE;
    }
}


#ifdef __MMI_OP01_WITH_WAP_KEY__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __OP01_0202__
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
#else /* __OP01_0202__ */
/* under construction !*/
#endif /* __OP01_0202__ */
/* under construction !*/
#endif /* __MMI_OP01_WITH_WAP_KEY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_delete_dialpad_from_history
 * DESCRIPTION
 *  Delete dialpad screen after make call (only available for background sound)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_delete_dialpad_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
}


#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
/* For the detail information, please refer to IdleAppGprot.h */
MMI_BOOL mmi_idle_is_display_touch_shortcuts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dual_sim_root_screen
 * DESCRIPTION
 *  Dual SIM: Entry root screen from bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_dual_sim_root_screen(void)
{
    if (MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT)
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
        {
            // case 4, 8 ,12
            // still idle screen
            if ((MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 && MTPNP_PFAL_Is_Card1CHVBlocked()) || 
                (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && MTPNP_PFAL_Is_Card2CHVBlocked()))
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* SIM1 is ready but enter SIM blocked screen */
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                EntryScrnSimBlockRsp();
            }
            else
            {
                if (IsShowWelcomeScr1() == MMI_FALSE ||
                    GetActiveScreenId() == WELCOME_SCREEN_ID ||
                    IsScreenPresent(IDLE_SCREEN_ID) ||
                    (MTPNP_PFAL_Is_Card1CHVBlocked() && MTPNP_PFAL_Is_Card2CHVBlocked()))
                {
                    EntryIdleScreen();
                }
                else
                {
                    ShowWelcomeScr(); //EntryIdleScreen();
                }
            }
        }
        else
        {
            // case 2, 6 ,10
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2)
            {
                g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE; /* SIM1 is ready but enter SIM error screen */
                if(mmi_bootup_is_sim2_access_error())
                {
                    simErrorDisplayString = STR_SIM_ACCESS_ERROR_MSG;
                }
                else
                {
                    simErrorDisplayString = STR_SIM_INSERTION_MSG;
                }
                EntryScrnSimErrorScreen();
            }
            else
            {
                if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 && MTPNP_PFAL_Is_Card1CHVBlocked())
                {
                    simErrorDisplayString = STR_SIM_BLOCK_MSG;
                    EntryScrnSimBlockRsp();
                }
                else
                {
                    EntryIdleScreen();
                }
            }
        }
    }
    else
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
        {
            // case 3, 7 ,11
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1)
            {
                if(mmi_bootup_is_sim_access_error())
                {
                    simErrorDisplayString = STR_SIM_ACCESS_ERROR_MSG;
                }
                else
                {
                    simErrorDisplayString = STR_SIM_INSERTION_MSG;
                }
                EntryScrnSimErrorScreen();
            }
            else
            {
                if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && MTPNP_PFAL_Is_Card2CHVBlocked())
                {
                    simErrorDisplayString = STR_SIM_BLOCK_MSG;
                    EntryScrnSimBlockRsp();
                }
                else
                {
                    if (IsShowWelcomeScr1() == MMI_FALSE ||
                        GetActiveScreenId() == WELCOME_SCREEN_ID ||
                        IsScreenPresent(IDLE_SCREEN_ID) ||
                        MTPNP_PFAL_Is_Card2CHVBlocked())
                    {
                        EntryIdleScreen();
                    }
                    else
                    {
                        ShowWelcomeScr(); //EntryIdleScreen();
                    }
                }
            }
        }
        else
        {
            // case 1, 5 ,7
            // still insert sim screen
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 || MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2)
            {
                if ((MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 && mmi_bootup_is_sim_access_error() == MMI_TRUE) ||
                    (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && mmi_bootup_is_sim2_access_error() == MMI_TRUE))
                {
                    simErrorDisplayString = STR_SIM_ACCESS_ERROR_MSG;
                }
                else
                {
                    simErrorDisplayString = STR_SIM_INSERTION_MSG;
                }
                EntryScrnSimErrorScreen();
            }
            else
            {
                EntryIdleScreen();
            }
        }
    }
}


#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_sim1_dialpad_call
 * DESCRIPTION
 *  Dual SIM: dial SIM1 call via call icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_sim1_dialpad_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
    {
        mmi_ucm_init_call_para(&param);
        param.dial_type = SRV_UCM_VOICE_CALL_TYPE;
        param.ucs2_num_uri = (U16 *)g_idle_context.DialPadCallBuffer;
        param.adv_para.after_make_call_callback = mmi_idle_dialer_after_make_call_hdlr;
        param.adv_para.after_callback_user_data = NULL;

        mmi_ucm_call_launch(0, &param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_sim2_dialpad_call
 * DESCRIPTION
 *  Dual SIM: dial SIM2 call via call icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_sim2_dialpad_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SSCStringParsing2() && g_idle_context.DialPadCallBuffer[0] != '\0')
    {
        mmi_ucm_init_call_para(&param);
        param.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
        param.ucs2_num_uri = (U16 *)g_idle_context.DialPadCallBuffer;
        param.adv_para.after_make_call_callback = mmi_idle_dialer_after_make_call_hdlr;
        param.adv_para.after_callback_user_data = NULL;

        mmi_ucm_call_launch(0, &param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_dual_sim_dialing_keypad_call_handler
 * DESCRIPTION
 *  Dual SIM: Set dialing call handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_set_dual_sim_dialing_keypad_call_handler(FuncPtr sim1_func, FuncPtr sim2_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE))
    {
        SetDialingKeypadCallHandler(sim1_func);
    }

    if (srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2))
    {
        SetDialingKeypadCall2Handler(sim2_func);
    }
}
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
#endif /* __MMI_DUAL_SIM_MASTER__ */


#ifdef __TCPIP__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_csd_icon
 * DESCRIPTION
 *  This function updates the CSD icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_update_csd_icon(
                cbm_bearer_state_enum state, 
                cbm_bearer_enum bearer, 
                kal_uint32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_IDLE_CSD_ICON, state, bearer);

    if (bearer == CBM_CSD && state == CBM_ACTIVATED)
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        IdleSetStatusIcon(STATUS_ICON_CSD);
    #else
        /* Dual SIM project shall use different icons for different SIM. */
        if (cbm_get_sim_id(acct_id) == CBM_SIM_ID_SIM1)
        {
            IdleSetStatusIcon(STATUS_ICON_CSD);
        }
        else
        {
            IdleSetStatusIcon(STATUS_ICON_SLAVE_CSD);
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    else if (bearer == CBM_CSD && state == CBM_DEACTIVATED)
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        IdleResetStatusIcon(STATUS_ICON_CSD);
    #else
        /* Dual SIM project shall use different icons for different SIM. */
        if (cbm_get_sim_id(acct_id) == CBM_SIM_ID_SIM1)
        {
            IdleResetStatusIcon(STATUS_ICON_CSD);
        }
        else
        {
            IdleResetStatusIcon(STATUS_ICON_SLAVE_CSD);
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
}
#endif /* __TCPIP__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_initialization
 * DESCRIPTION
 *  This function initializes the idle screen application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_initialization(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__
    U8 app_id;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__
    /* Register bearer status notification for CSD icon. */
    app_id = cbm_register_app_id(IDLE_APP_BASE, 0);
   
    mmi_cbm_register_bearer_status_notify(
        app_id, 
        MMI_FALSE, 
        mmi_idle_update_csd_icon);
#endif /* __TCPIP__ */

#if defined(__OP12__) && defined(__NBR_CELL_INFO__)
    mmi_nw_register_cell_info_ind();
#endif /* defined(__OP12__) && defined(__NBR_CELL_INFO__) */

#ifdef __DM_LAWMO_SUPPORT__
    mmi_idle_lawmo_initialize();
#endif /* __DM_LAWMO_SUPPORT__ */

#ifdef __MMI_DIALER_SEARCH__
    mmi_idle_ds_initialize();
#endif /* __MMI_DIALER_SEARCH__ */
}


/* For the detail information, please refer to IdleAppGprot.h */
MMI_BOOL mmi_idle_is_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/* For the detail information, please refer to IdleAppGprot.h */
U16 mmi_idle_get_idle_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    
    if (scr_id == IDLE_SCREEN_ID || IsScreenPresent(IDLE_SCREEN_ID))
    {
        return IDLE_SCREEN_ID;
    }
    else if (scr_id == SCR_SIM_INSERTION || IsScreenPresent(SCR_SIM_INSERTION))
    {
        return SCR_SIM_INSERTION;
    }
    else if (scr_id == SCR_SIM_BLOCK || IsScreenPresent(SCR_SIM_BLOCK))
    {
        return SCR_SIM_BLOCK;
    }

    return 0;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_main_menu
 * DESCRIPTION
 *  This function takes the user to the main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryMainMenuFromIdleScreen();

    /* Disable the manual keypad lock mechanism. */
    IdleHandleKeypadLockProcess();
}


#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_dial_pad_qwerty_key_handler
 * DESCRIPTION
 *  This function is the translate key handler of the dial pad (QWERTY project).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_idle_dial_pad_qwerty_key_handler(
            S16 mmi_key_code, 
            S16 mmi_key_type, 
            U16 ucs2_value, 
            U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Disable long-press after the key up event of any dialer keys. */
    if ((wgui_inputs_dialer_is_dialer_keys(mmi_key_code, ucs2_value)) &&
        (mmi_key_type == KEY_EVENT_UP) &&
        (g_idle_context.LongPressEnable == 0) &&
        (mmi_ucs2strlen(g_idle_context.DialPadCallBuffer)))
    {
        IdleDisableLongPress();
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_qwerty_key_handler
 * DESCRIPTION
 *  This function takes the user to the main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_idle_qwerty_key_handler(
                S16 mmi_key_code, 
                S16 mmi_key_type, 
                U16 ucs2_value, 
                U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((wgui_inputs_dialer_is_dialer_keys(mmi_key_code, ucs2_value)) &&
        (mmi_key_type == KEY_EVENT_DOWN))
    {
        /* Show the dial pad. */
        HandleIdleScreenDigitEntry();

        /* Enable the DTMF tone because the flag is reset in EntryNewScreen. */
        mmi_frm_set_default_num_key_tone_mode(MMI_FRM_NUM_KEY_TONE_DTMF);

        /* On QWERTY project, the first digit is inserted by executing the key
           handler of the dialer. */
        wgui_inputs_dialer_qwerty_key_handler(
            mmi_key_code,
            mmi_key_type,
            ucs2_value,
            special_key_flag);

        /* Screen is changed. Return TRUE to abort the key routing. */
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_digit_key_handler
 * DESCRIPTION
 *  This function sets the digit key handler on the idle screen. It also handles
 *  the QWERTY keypad by registering the translated key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_set_digit_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_set_app_translate_key_handler(mmi_idle_qwerty_key_handler);

    /* 
     * On QWERTY phone, the DTMF tones are played when the user wants to dial
     * calls; otherwise, normal key tone is played, e.g. in the editor. Enable
     * the DTMF tone here. 
     *
     * PS. Our non-QWERTY phone will always play DTMF tone no matter in the dial
     *     pad or editor.
     */
    mmi_frm_set_default_num_key_tone_mode(MMI_FRM_NUM_KEY_TONE_DTMF);
#else
    SetGroupKeyHandler(
        HandleIdleScreenDigitEntry, 
        (PU16)PresentAllDialerKeys, 
        TOTAL_DIALER_KEYS, 
        KEY_EVENT_DOWN);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_dial_pad_set_disable_long_press_handler
 * DESCRIPTION
 *  This function sets up the handler to disable the LONG_PRESS handler after
 *  the first digit on the dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_dial_pad_set_disable_long_press_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * To disable LONG_PRESS after the first digit, set all UP key handler and
     * clear the LONG_PRESS handler in the UP key handler. Because UP key
     * handler might also be used by the category, save them here and restore
     * them later.
     */
    wgui_save_key_handlers();
    
    SetGroupKeyHandler(
        IdleDisableLongPress, 
        (PU16)PresentAllDialerKeys,
        TOTAL_DIALER_KEYS,
        KEY_EVENT_UP);

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    /* For QWERTY, to disable the LONG_PRESS after the first digit, we also
       need to call IdleDisableLongPress on special key, e.g., 'p'. */
    mmi_frm_set_app_translate_key_handler(mmi_idle_dial_pad_qwerty_key_handler);
#endif
}


/* For the detail information, please refer to IdleAppGprot.h */
MMI_BOOL mmi_idle_is_keypad_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_keylock_context.gKeyPadLockFlag? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_dial_pad_call_buffer
 * DESCRIPTION
 *  This function returns the dialing string. If the active screen isn't dialer,
 *  it return NULL.
 * PARAMETERS
 *  void
 * RETURNS
 *  Dialing string on the dialer.
 *****************************************************************************/
WCHAR *mmi_idle_get_dial_pad_call_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    
    if (scr_id != IDLE_SCREEN_DIGIT_HANDLER_ID &&
        scr_id != SCR_DIAL_SOS_NUM)
   	{
   		return NULL;
   	}
    
	return (WCHAR *)g_idle_context.DialPadCallBuffer;
}

