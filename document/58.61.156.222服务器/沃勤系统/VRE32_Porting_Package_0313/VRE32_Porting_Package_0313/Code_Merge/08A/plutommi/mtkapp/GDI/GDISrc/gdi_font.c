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
 *  gdi_font.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI low-level font library
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "gdi_internal.h"
#include "gd_primitive.h"

#include "fontres.h"

const U32 gdi_tilt_table[61] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2,
    2, 2, 2, 2, 3, 3, 3, 3, 4, 4,
    4, 4, 5, 5, 5, 5, 5, 6, 6, 6,
    6, 7, 7, 7, 7, 8, 8, 8, 8, 8,
    9, 9, 9, 9, 10, 10, 10, 10, 11, 11,
    11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13
};

#define MAX_TILT  13

static S32 text_clip_x1;    /* Left edge of text clip rectangle */
static S32 text_clip_y1;    /* Top edge of text clip rectangle  */
static S32 text_clip_x2;    /* Right edge of text clip rectangle   */
static S32 text_clip_y2;    /* Bottom edge of text clip rectangle  */

static gd_put_pixel_func put_pixel;

#define put_pixel_with_clip(x,y,c)                    \
   {                                                  \
      if((x >= text_clip_x1) && (x <= text_clip_x2)   \
      &&(y >= text_clip_y1) && (y <= text_clip_y2))   \
         put_pixel(x,y,c);                            \
   }                                                  \

/* W05.50 Skip unnecessary action when the character is out of clip */
#define GDI_CHECK_CHAR_CLIP(x,y,char_width,char_height,NULL_ACTION)                 \
   {                                                                                \
      if((x -1 > text_clip_x2   )    || (x+char_width  +MAX_TILT +1 < text_clip_x1) \
      ||(y -1 > text_clip_y2) || (y+char_height +1 < text_clip_y1))                 \
         NULL_ACTION;                                                               \
   }                                                                                \

#define __GDI_SHOW_CHAR__  gdi_show_char_no_clip
#define __GDI_SET_PIXEL__  put_pixel
#include "gdi_font_show_char.h"
#undef __GDI_SHOW_CHAR__
#undef __GDI_SET_PIXEL__

#define __GDI_SHOW_CHAR__  gdi_show_char_with_clip
#define __GDI_SET_PIXEL__  put_pixel_with_clip
#include "gdi_font_show_char.h"
#undef __GDI_SHOW_CHAR__
#undef __GDI_SET_PIXEL__


/* 
 * ABM font engine 
 */
 /*
 * bitstream reader
 */
#define BIT_INIT(mem_ptr)               \
    {                                   \
        U32 BR_bits_buf;                \
        U16 *BR_bits_mem_ptr;           \
        U32 BR_bits_left;               \
                                        \
        BR_bits_mem_ptr = (U16*)(mem_ptr);              \
        BR_bits_buf = 0;                \
        BR_bits_left = 0;                               \
                                                        \
        /* take care of unalignment */                  \
        if ((U32)BR_bits_mem_ptr & 1)                   \
        {                                               \
            U8 *BR_mem_8 = (U8*)BR_bits_mem_ptr;        \
                                                        \
            BR_bits_buf = *BR_mem_8++;                  \
            BR_bits_mem_ptr = (U16*)BR_mem_8;           \
            BR_bits_left = 8;                           \
        }
  
#define BIT_END() }

#define BIT_READ(cb, data_mask, bit_data)  BR_bit_reader((cb), (data_mask), BR_bits_buf, BR_bits_left, BR_bits_mem_ptr, bit_data)
#define BIT_SEEK(s)                        BR_bit_seek((s), BR_bits_buf, BR_bits_left, BR_bits_mem_ptr)

/* bitstream read, output bit_data */
#define BR_bit_reader(cb, data_bit_mask, bits_buf, bits_left, bits_mem_ptr, bit_data) \
    do                                                                              \
    {                                                                               \
        /* bits in the buffer are not enough, append the buffer with 16 bits  */    \
        if (bits_left < cb)                                                         \
        {                                                                           \
            bits_buf += (*bits_mem_ptr++) << bits_left;                             \
            bits_left += 16;                                                        \
        }                                                                           \
                                                                                    \
        /* consume bits */                                                          \
        bit_data = bits_buf & (data_bit_mask);                                      \
        bits_buf >>= cb;                                                            \
        bits_left -= cb;                                                            \
    } while (0)


/* bitstream seek */
#define BR_bit_seek(seek_bits, bits_buf, bits_left, bits_mem_ptr)  \
    do                                                              \
    {                                                               \
        if (bits_left > seek_bits)                                  \
        {                                                           \
            bits_left -= seek_bits;                                 \
            bits_buf >>= seek_bits;                                 \
        }                                                           \
        else                                                        \
        {                                                           \
            U32 sb = seek_bits;                                     \
                                                                    \
            sb -= bits_left;                                        \
            bits_mem_ptr += sb / 16;                                \
            bits_buf = *bits_mem_ptr++;                             \
            sb &= 0xF;                                              \
            /* consume skipped bits */                              \
            bits_buf >>= sb;                                        \
            bits_left = 16 - sb;                                    \
        }                                                           \
    } while (0)
#define max(a,b)        (((a) > (b)) ? (a) : (b))
#define min(a,b)        (((a) < (b)) ? (a) : (b))

#define PUT_PIXEL_16(bpp, mem, p)    *((U16*)(mem)) = (U16)p;
#define PUT_PIXEL_dst_bpp(bpp, mem, p)          \
    do                                  \
    {                                   \
        if (bpp == 24){                 \
            /*U8 *mem = (mem);*/       \
            ((U8*)mem)[0] = p;                 \
            ((U8*)mem)[1] = p >> 8;            \
            ((U8*)mem)[2] = p >> 16;           \
        }else if (bpp == 8){            \
            *((U8*)(mem)) = (U8)p;      \
        }else if (bpp == 16){           \
            *((U16*)(mem)) = (U16)p;    \
        }else{                          \
            *((U32*)(mem)) = (U32)p;    \
        }                               \
    } while (0)    
              
#define PUT_PIXEL(bpp, mem, p)  PUT_PIXEL_##bpp##(bpp, mem,p);

#define OUTPUT_BORDER(border_buf, output_border_start, output_border_end, dst_bpp, not_draw_left_border)   \
    do                                                              \
    {                                                               \
        U32 tmp_line_buf2;                                          \
        S32 i;                                                      \
        tmp_line_buf2 = border_buf >> not_draw_left_border;         \
        for (i = output_border_start; i >= output_border_end; i--)  \
        {                                                           \
            if (tmp_line_buf2 & 1){                                 \
                PUT_PIXEL(dst_bpp, out_mem_ptr, border_color);      \
            }                                                       \
            out_mem_ptr += dst_byte_per_pixel;                      \
            tmp_line_buf2 = tmp_line_buf2 >> 1;                     \
        }                                                           \
    }while(0)

#if defined(GDI_USING_2D_ENGINE_V2) || defined(GDI_USING_2D_ENGINE_V3)    
/*****************************************************************************
 * FUNCTION
 *  gdi_font_use_2d_acceleration
 * DESCRIPTION
 *  Check whether to use hardware 2D engine to accelerate 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL gdi_font_use_2d_acceleration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_COLOR_FORMAT_16 <= gdi_act_layer->cf && gdi_act_layer->cf <= GDI_COLOR_FORMAT_32)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* defined(GDI_USING_2D_ENGINE_V2) || defined(GDI_USING_2D_ENGINE_V3) */

    
/*****************************************************************************
 * FUNCTION
 *  gdi_font_show_border_of_char
 * DESCRIPTION
 *  draw the border of a char with border_color (Optimized software version)
 * PARAMETERS
 *  x                    [IN]   character x
 *  y                    [IN]   character y
 *  border_color         [IN]   border color
 *  font_data            [IN]   font data
 *  font_data_size       [IN]   font data size
 *  char_width           [IN]   character width
 *  char_height          [IN]   character height
 *  font_attr            [IN]   font atrribute
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_font_show_border_of_char(
                S32 x,
                S32 y,
                gdi_color border_color,
                U8 *font_data,
                U32 font_data_size,
                U16 char_width,
                U16 char_height,
                U8 font_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 16-byte ABM header for font information */
    U32 font_buf;                                   //buffer to store data in font data
    S32 clip_width, clip_height;                    //char width and height after clipping
    U32 abm_start_bit_offset;                       //bit offset of first pixel to draw in font data
    U32 dst_line_jump_bytes, abm_line_jump_bits;    //offset to jump to first pixel to draw in the next line
    U32 bpp, dst_bpp, dst_byte_per_pixel;           //bits per pixel in source, destination
    U8  *out_mem_ptr = 0;                             //points to current output memory
    U8  not_draw_up_border, not_draw_down_border, not_draw_left_border, not_draw_right_border;  //decide to draw the border or not after cliping
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    //pre process, the section is a simplify version of gdi_image_abm_pre_process()
    {
        U32     abm_start_pixel_offset;
        U32     img_w, img_h, normal_color_num;
        S32     x1, x2, y1, y2;
        U32     line_jump_pixel_num;
        S32     layer_width;
        S32     clip_rect_x1, clip_rect_y1, clip_rect_x2, clip_rect_y2;
        S32     border_clip_rect_x1, border_clip_rect_y1, border_clip_rect_x2, border_clip_rect_y2;
        gdi_handle dst_layer;
        gdi_layer_struct *dst_layer_struct;
        
        img_w = (U32)char_width;
        img_h = (U32)char_height;    
        x1 = x;
        y1 = y;
        x2 = x1 + img_w - 1;
        y2 = y1 + img_h - 1;
        gdi_layer_get_active(&dst_layer);
        dst_layer_struct = (gdi_layer_struct*)dst_layer;
        /* check if the draw rect is out of the clip */
        if ((x1 > dst_layer_struct->clipx2) || (y1 > dst_layer_struct->clipy2) || (x2 < dst_layer_struct->clipx1) || (y2 < dst_layer_struct->clipy1))
        {
            return ;
        }

        /* calculate the overlapped rect */
        clip_rect_y1 = max(y1, dst_layer_struct->clipy1);
        clip_rect_y2 = min(y2, dst_layer_struct->clipy2);
        clip_rect_x1 = max(x1, dst_layer_struct->clipx1);
        clip_rect_x2 = min(x2, dst_layer_struct->clipx2);

        /* calculate the draw rect of border */
        border_clip_rect_y1 = max(y1-1, dst_layer_struct->clipy1);
        border_clip_rect_y2 = min(y2+1, dst_layer_struct->clipy2);
        border_clip_rect_x1 = max(x1-1, dst_layer_struct->clipx1);
        border_clip_rect_x2 = min(x2+1, dst_layer_struct->clipx2);

        //decide to draw border or not
        not_draw_up_border = (clip_rect_y1 == border_clip_rect_y1)? 1:0;
        not_draw_down_border = (clip_rect_y2 == border_clip_rect_y2)? 1:0;
        not_draw_left_border = (clip_rect_x1 == border_clip_rect_x1)? 1:0;
        not_draw_right_border = (clip_rect_x2 == border_clip_rect_x2)? 1:0;
        
        normal_color_num = 2;
        bpp = 1;    
        abm_start_pixel_offset = clip_rect_x1 - x1 + (clip_rect_y1 - y1) * img_w;
        abm_start_bit_offset = abm_start_pixel_offset * bpp;

        layer_width = GDI_LAYER.width;
        clip_width = clip_rect_x2 - clip_rect_x1 + 1;
        clip_height = clip_rect_y2 - clip_rect_y1 + 1;
        line_jump_pixel_num = layer_width - clip_width;

        dst_bpp = gdi_layer_get_bit_per_pixel();
        dst_byte_per_pixel = dst_bpp / 8;
        dst_line_jump_bytes = line_jump_pixel_num * dst_byte_per_pixel;

        // bits to skipped for a line jump of the source ABM 
        abm_line_jump_bits = (img_w - clip_width) * bpp;

        // set memory pointers to the start pixel 
        out_mem_ptr = (U8*)GDI_LAYER.buf_ptr;
        out_mem_ptr += (clip_rect_y1 * layer_width + clip_rect_x1) * dst_byte_per_pixel;
    }
    {
        BIT_INIT(font_data);
        BIT_SEEK(abm_start_bit_offset);

        {
            S32 y = clip_height;
            U32 border_buf0, border_buf1, border_buf2, readpixelnum;
            S32 output_border_start, output_border_end;

            border_buf0 = 0;    //border_buf0,1,2 is bit mask used to store the border
            border_buf1 = 0;
            border_buf2 = 0;
            
            readpixelnum = 16;  // the max number that the Bit reader can read
            
            if ((dst_bpp == 16) && (clip_width < readpixelnum))
            {
                // if dsp_bpp is 16 and clip_width<readpixelnum, we use the faster algorithm
                U32 mask, border_buf_len;
                readpixelnum = clip_width;
                border_buf_len = readpixelnum + 2;
                mask = (1 << readpixelnum) - 1;

                output_border_start = (border_buf_len - 1) - not_draw_left_border;
                output_border_end = not_draw_right_border;
                while (y > 0)                                                                  
                {
                    U32 tmp_line_buf;                       
                    U8 *ori_output_mem;
                    
                    border_buf2 = 0;
                    // read the pixel from bitstream 
                    BIT_READ(readpixelnum, mask, font_buf); 

                    //find the border, store in border_buf0,1,2
                    border_buf0 |= (font_buf);              
                    border_buf1 |= (font_buf);              
                    border_buf2 |= (font_buf);              
                    tmp_line_buf = font_buf << 1;           
                    border_buf0 |= tmp_line_buf;            
                    border_buf2 |= tmp_line_buf;            
                    tmp_line_buf = font_buf << 2;           
                    border_buf0 |= tmp_line_buf;            
                    border_buf1 |= tmp_line_buf;            
                    border_buf2 |= tmp_line_buf;  

                    //out put the border to dest layer
                    ori_output_mem = out_mem_ptr;   /* store current output mem position */ 
                    do
                    {
                        if (y == clip_height && not_draw_up_border) //the first line and not to draw up border
                        {
                            out_mem_ptr = ori_output_mem + readpixelnum * dst_byte_per_pixel;
                            break;
                        }
                        
                        /* move pos to previous pixel of previous line */ 
                        out_mem_ptr = ori_output_mem - ((GDI_LAYER.width + ((not_draw_left_border - 1) * (-1))) * dst_byte_per_pixel);
                        /* read border_buf to draw border */
                        OUTPUT_BORDER(border_buf0, output_border_start, output_border_end, 16, not_draw_left_border);
                                                                                     
                        if (y == 1) // if it's the final line
                        {                                                               
                            out_mem_ptr = ori_output_mem - ((not_draw_left_border - 1) * (-1)) * dst_byte_per_pixel; 
                            OUTPUT_BORDER(border_buf1, output_border_start, output_border_end, 16, not_draw_left_border);

                            if (not_draw_down_border)   // not draw the down border
                            {
                                out_mem_ptr = ori_output_mem + readpixelnum * dst_byte_per_pixel;     
                                break;
                            }
                            out_mem_ptr = ori_output_mem + ((GDI_LAYER.width - ((not_draw_left_border - 1) * (-1))) * dst_byte_per_pixel);    
                            OUTPUT_BORDER(border_buf2, output_border_start, output_border_end, 16, not_draw_left_border);
                        }                                          
                        out_mem_ptr = ori_output_mem + readpixelnum * dst_byte_per_pixel;               
                    }while(0);
                    
                    BIT_SEEK(abm_line_jump_bits);   // jump to the start pixel in the next line of the ABM image 
                    out_mem_ptr += dst_line_jump_bytes; // jump to the start pixel in the next line of the target layer 
                    y--;
                    
                    tmp_line_buf = border_buf0;     //shift the three border_buf
                    border_buf0 = border_buf1;
                    border_buf1 = border_buf2;
                    border_buf2 = tmp_line_buf;
                }
            }
            else
            {   //dst_bpp != 16 || clip_width > readpixelnum, we use the generic version
                while (y > 0)                                                                  
                {
                    //output a line 
                    for (x = (clip_width - 1); x >= 0; x -= readpixelnum)
                    {   
                        U32 mask, border_buf_len;
                        U32 tmp_line_buf;                       
                        U8 *ori_output_mem;     
                        U8 tmp_not_draw_left_border,tmp_not_draw_right_border;

                        tmp_not_draw_left_border = (x == (clip_width - 1))? not_draw_left_border : 0;
                        tmp_not_draw_right_border = (x <= 16)? not_draw_right_border : 0;
                        
                        border_buf0 = 0;
                        border_buf1 = 0;
                        border_buf2 = 0;
                        // read the pixel from bitstream 
                        readpixelnum = 16;
                        if (readpixelnum > x+1)
                        {
                            readpixelnum = x+1;
                        }
                        border_buf_len = readpixelnum + 2;
                        mask = (1 << readpixelnum) - 1;
                                
                        BIT_READ(readpixelnum, mask, font_buf); 
                                                                
                        border_buf0 |= (font_buf);              
                        border_buf1 |= (font_buf);              
                        border_buf2 |= (font_buf);              
                        tmp_line_buf = font_buf << 1;           
                        border_buf0 |= tmp_line_buf;            
                        border_buf2 |= tmp_line_buf;            
                        tmp_line_buf = font_buf << 2;           
                        border_buf0 |= tmp_line_buf;            
                        border_buf1 |= tmp_line_buf;            
                        border_buf2 |= tmp_line_buf;            

                        output_border_start = (border_buf_len - 1) - tmp_not_draw_left_border;
                        output_border_end = tmp_not_draw_right_border;

                        ori_output_mem = out_mem_ptr;   /* store current output mem position */ 

                        if (!(y == clip_height && not_draw_up_border))
                        {
                            /* move pos to previous pixel of previous line */
                            out_mem_ptr = ori_output_mem - ((GDI_LAYER.width + ((tmp_not_draw_left_border - 1) * (-1))) * dst_byte_per_pixel);     
                            /* read border_buf to draw border */    
                            OUTPUT_BORDER(border_buf0, output_border_start, output_border_end, dst_bpp, tmp_not_draw_left_border);
                        }
                        out_mem_ptr = ori_output_mem - ((tmp_not_draw_left_border - 1) * (-1)) * dst_byte_per_pixel; 
                        OUTPUT_BORDER(border_buf1, output_border_start, output_border_end, dst_bpp, tmp_not_draw_left_border);
                         
                        if (!(y == 1 && not_draw_down_border)){
                            out_mem_ptr = ori_output_mem + ((GDI_LAYER.width - ((tmp_not_draw_left_border - 1) * (-1))) * dst_byte_per_pixel);    
                            OUTPUT_BORDER(border_buf2, output_border_start, output_border_end, dst_bpp, tmp_not_draw_left_border);
                        }                                         
                        out_mem_ptr = ori_output_mem + readpixelnum * dst_byte_per_pixel;

                    }
                    BIT_SEEK(abm_line_jump_bits);   // jump to the start pixel in the next line of the ABM image 
                    out_mem_ptr += dst_line_jump_bytes; // jump to the start pixel in the next line of the target layer 
                    y--;
                }
            }
        }
        /* close bitstream reader */
        BIT_END();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_draw_font_by_abm
 * DESCRIPTION
 *  Wrapper for drawing a 1-bit bitmap font by the ABM decoder (accelerated)
 * PARAMETERS
 *  x                    [IN]   character x
 *  y                    [IN]   character y
 *  color                [IN]   text color
 *  font_data            [IN]   font data
 *  char_width           [IN]   character width
 *  char_height          [IN]   character height
 * RETURNS
 *  void
 *****************************************************************************/
/* Vogins Start */
#ifdef __VRE_V30__
void gdi_draw_font_by_abm(
#else
static void gdi_draw_font_by_abm(
#endif
/* Vogins End */
                S32 x, 
                S32 y, 
                gdi_color color, 
                U8 *font_data, 
                S32 char_width, 
                S32 char_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 16-byte ABM header for font information */
    U32 abm_font_header[4];
    U16* abm = (U16*)abm_font_header;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    abm[0] = (U16)char_width;
    abm[1] = (U16)char_height;

#if (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL > 16)
    /* use 24-bit palette if the active layer bpp is 24 or 32 */
    if (gdi_act_layer->bits_per_pixel > 16)
    {
        abm[1] |= 0x8000;
    }    
#endif /* (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL > 16) */

    /* 1-bit color font: 1 for transparent color, 1 for the character color. */
    abm[2] = 2;

    abm[3] = 0;
    abm[4] = 0;
    abm[5] = 0;

    *((U32*)&abm[6]) = (U32)color;
    
    gdi_image_abm_draw_font(x, y, (U8*)abm, font_data);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_show_char
 * DESCRIPTION
 *  Low-level font drawing
 * PARAMETERS
 *  x                   [IN]        X
 *  y                   [IN]        Y
 *  color               [IN]        Font color
 *  font_data           [IN]        Raw font data
 *  font_data_size      [IN]        Font data size in bytes
 *  char_width          [IN]        Character width
 *  char_height         [IN]        Character height
 *  font_attr           [IN]        Font attributes
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_show_char(
        S32 x,
        S32 y,
        gdi_color color,
        U8 *font_data,
        U32 font_data_size,
        U16 char_width,
        U16 char_height,
        U8 font_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip unnecessary action when the character is out of clip */
    GDI_CHECK_CHAR_CLIP(x, y, char_width, char_height, return);

    /* hardware font engine */
#if defined(GDI_USING_2D_ENGINE_V2)
    if (gdi_font_use_2d_acceleration() && !(font_attr & FONTATTRIB_UNDERLINE))
    {
        /* W06.04 Temp Solution for Italic Font */
        if (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE))
        {
            gdi_2d_set_tilt_table(gdi_tilt_table, char_height);
        }
        gdi_2d_draw_font(x, y, font_data, 0, char_width, char_height);
        return;
    }
#elif defined(GDI_USING_2D_ENGINE_V3)
    if (gdi_font_use_2d_acceleration() && !(font_attr & FONTATTRIB_UNDERLINE))
    {
        gdi_2d_draw_font_v3(
            MMI_FALSE,  /* Not bordered font */
            MMI_FALSE,  /* Don't use bg_color */
            color,
            0,
            (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE)) ? MMI_TRUE : MMI_FALSE,
            (const S32 *) gdi_tilt_table, 
            char_height,
            font_data, 
            font_data_size,
            0, 
            x, 
            y, 
            char_width, 
            char_height);
        return;
    }
#endif

    /* software font engine */
    if (font_attr == 0 && gdi_act_layer->bits_per_pixel >= 16)
    {   /* draw normal font by ABM decoder (ABM decoder only supports 16, 24, and 32 bpp.) */
        gdi_draw_font_by_abm(x, y, color, font_data, char_width, char_height);
    }
    else if ((x - 1 < text_clip_x1) || (x + char_width + MAX_TILT + 1 > text_clip_x2) ||
             (y - 1 < text_clip_y1) || (y + char_height + 1 > text_clip_y2))
    {
        gdi_show_char_with_clip(x, y, color, font_data, font_data_size, char_width, char_height, font_attr);
    }
    else
    {
        gdi_show_char_no_clip(x, y, color, font_data, font_data_size, char_width, char_height, font_attr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_show_char_bordered
 * DESCRIPTION
 *  Low-level drawing routine for a borered character
 * PARAMETERS
 *  x                   [IN]        X
 *  y                   [IN]        Y
 *  color               [IN]        Font color   
 *  border_color        [IN]        Font border color
 *  font_data           [IN]        Raw font data
 *  font_data_size      [IN]        Font data size in bytes
 *  char_width          [IN]        Character width
 *  char_height         [IN]        Character height
 *  font_attr           [IN]        Font attributes
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_show_char_bordered(
        S32 x,
        S32 y,
        gdi_color text_color,
        gdi_color border_color,
        U8 *font_data,
        U32 font_data_size,
        U16 char_width,
        U16 char_height,
        U8 font_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Ignore underline attribute */
    font_attr &= ~(FONTATTRIB_UNDERLINE | FONTATTRIB_BOLD);
    
    /* hardware font engine */
#if defined(GDI_USING_2D_ENGINE_V2)
    if (gdi_font_use_2d_acceleration())
    {
        gdi_2d_set_font_attr(
            font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE),      /* is_tilt */
            FALSE,
            TRUE,   /* is_border */
            FALSE,  /* don't enable bg_color, */
            text_color,
            border_color);
        /* W06.04 Temp Solution for Italic Font */
        if (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE))
        {
            gdi_2d_set_tilt_table(gdi_tilt_table, char_height);
        }
        gdi_2d_draw_font(x, y, font_data, 0, char_width, char_height);
        return;
    }
#elif defined(GDI_USING_2D_ENGINE_V3)
    if (gdi_font_use_2d_acceleration())
    {
        gdi_2d_draw_font_v3(
            MMI_TRUE,   /* Bordered font */
            MMI_FALSE,  /* Don't use bg_color */
            text_color,
            border_color,
            (font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE)) ? MMI_TRUE : MMI_FALSE,
            (const S32 *) gdi_tilt_table, 
            char_height,
            font_data, 
            font_data_size,
            0, 
            x, 
            y, 
            char_width, 
            char_height);
        return;
    }
#endif

    /* Optimized software version for bordered font drawing */
    if (font_attr == 0 && GDI_COLOR_FORMAT_16 <= gdi_act_layer->cf) 
    {
        gdi_font_show_border_of_char(x, y, border_color, font_data, font_data_size, char_width, char_height, font_attr);
        gdi_show_char(x, y, text_color, font_data, font_data_size, char_width, char_height, font_attr);
    }
    else /* Original version (slower) */
    {
        gdi_show_char(x - 1, y - 1, border_color, font_data, font_data_size, char_width, char_height, font_attr);
        gdi_show_char(x - 1, y + 1, border_color, font_data, font_data_size, char_width, char_height, font_attr);
        gdi_show_char(x + 1, y - 1, border_color, font_data, font_data_size, char_width, char_height, font_attr);
        gdi_show_char(x + 1, y + 1, border_color, font_data, font_data_size, char_width, char_height, font_attr);
        gdi_show_char(x + 0, y - 1, border_color, font_data, font_data_size, char_width, char_height, font_attr);
        gdi_show_char(x + 0, y + 1, border_color, font_data, font_data_size, char_width, char_height, font_attr);
        gdi_show_char(x - 1, y + 0, border_color, font_data, font_data_size, char_width, char_height, font_attr);
        gdi_show_char(x + 1, y + 0, border_color, font_data, font_data_size, char_width, char_height, font_attr);

        gdi_show_char(x, y, text_color, font_data, font_data_size, char_width, char_height, font_attr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_font_begin
 * DESCRIPTION
 *  Invoke this function before gdi_show_char() and gdi_show_char_bordered
 * PARAMETERS
 *  fg_color        [IN]        Font color
 *  font_attr       [IN]        Font attributes
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_font_begin(gdi_color fg_color, U8 font_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;

#if defined(GDI_USING_2D_ENGINE_V2)
    if (gdi_font_use_2d_acceleration())
    {
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer((gdi_handle) gdi_act_layer);
        gdi_2d_set_font_attr(
            font_attr & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE),  /* is_tilt */
            FALSE,  // TODO: is_bold always be FALSE, it should make some change to pixcomfontengine.c, and turn on this HW feature
            FALSE,  /* is_border */
            FALSE,  /* don't enable bg_color, */
            fg_color,
            0);
    }
#elif defined(GDI_USING_2D_ENGINE_V3)
    (void) fg_color;
    (void) font_attr;
    if (gdi_font_use_2d_acceleration())
    {
        gdi_2d_begin();
    }
#endif

    put_pixel = gd_put_pixel[gdi_act_layer->cf];

    text_clip_x1 = GDI_LAYER.clipx1;
    text_clip_y1 = GDI_LAYER.clipy1;
    text_clip_x2 = GDI_LAYER.clipx2;
    text_clip_y2 = GDI_LAYER.clipy2;

}


/*****************************************************************************
 * FUNCTION
 *  gdi_font_end
 * DESCRIPTION
 *  Invoke this function after gdi_show_char() and gdi_show_char_bordered
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_font_end(void)
{
#if defined(GDI_USING_2D_ENGINE_V2) || defined(GDI_USING_2D_ENGINE_V3)
    if (gdi_font_use_2d_acceleration())
    {
        gdi_2d_end();
    }
#endif /* defined(GDI_USING_2D_ENGINE_V2) || defined(GDI_USING_2D_ENGINE_V3) */

    GDI_UNLOCK;
}

