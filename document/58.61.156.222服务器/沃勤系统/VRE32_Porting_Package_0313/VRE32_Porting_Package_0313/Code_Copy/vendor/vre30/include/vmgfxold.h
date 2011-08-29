#ifndef VMCPT_H_
#define VMCPT_H_

/************************************************************************
 * VRE1.2.5之后版本图形库接口上作了较大的调整, 原来基于老版本接口
 * 开发的程序若要在新版本平台上运行，需包含本文件重新编译。
 * 新开发的程序请使用vmgraph.h文件中的图形接口。
 *
 * Vogins Network Technology (China).
 * 2008.12.30
 ************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
#include "vmsys.h"
#include "vmgraph.h"
#include "vmlog.h"


/* vmgraph.h*/
void vm_graphic_lock(void);
void vm_graphic_unlock(void);
VMUINT8 * vm_graphic_get_buffer(void);
void vm_graphic_flush_buffer(void);
void vm_initialize_screen_buffer(void);
void vm_finalize_screen_buffer(void);
VMINT vm_graphic_draw_gif(VMUINT8* gif, VMINT gif_len, VMINT x, VMINT y, VMINT width, VMINT height, VMINT frame_index);
VMINT vm_graphic_bitblt(VMINT resid, int x, int y);
void vm_graphic_drawtext(VMINT x, VMINT y, VMWSTR s, VMINT32 length, VMINT color);
void vm_graphic_setpixel(VMINT x, VMINT y, VMINT color);
void vm_graphic_drawline(VMINT x0, VMINT y0, VMINT x1, VMINT y1, VMINT color);
void vm_graphic_drawrect(VMINT x, VMINT y, VMINT width, VMINT height, VMINT color);
void vm_graphic_fillrect(VMINT x, VMINT y, int width, int height, int color);
#define vm_graphic_set_text_clip 			vm_graphic_set_clip
#define vm_graphic_reset_text_clip 		vm_graphic_reset_clip

/* vmddraw.h*/
void vm_dd_initialize_clip_rect(void);
void vm_dd_set_clip(VMINT x, VMINT y, VMINT width, VMINT height);
void vm_dd_reset_clip(void);
void vm_dd_blt_all_cutting_frames(VMBYTE *buf, VMBYTE *source_surface, VMINT x_num, VMINT y_num, VMINT width, VMINT height);
void vm_dd_img_flood(VMBYTE *buf, VMINT x_dst, VMINT y_dst,VMBYTE *source_surface,  VMINT width, VMINT height, VMINT frame_index);
void vm_dd_copy(VMBYTE *buf, VMINT x_dest, VMINT y_dest, VMBYTE *source_surface,  VMINT x_src, VMINT y_src, VMINT width, VMINT height, VMINT frame_index, VMINT direction);
void vm_dd_flood_4_regional(VMBYTE *buf, VMINT x_dst, VMINT y_dst,VMBYTE *source_surface, VMINT width, VMINT height, VMINT frame_index);
VMUINT8* vm_dd_load_image(VMUINT8 *img, VMINT img_len);
struct frame_prop * vm_dd_get_img_property(VMUINT8 *img,  VMUINT8 frame_index);
VMINT vm_dd_get_frame_number(VMUINT8 *img);
void vm_dd_clean(VMUINT8* buf, VMUINT16 color16);
void vm_dd_active_layer(VMINT handle);
#define vm_dd_clean_ex 					vm_dd_clean
#define vm_dd_copy_ex 					vm_dd_copy
#define vm_dd_setpixel_ex 				vm_graphic_set_pixel	
#define vm_dd_setpixel 					vm_graphic_set_pixel
#define vm_dd_getpixel_ex 				vm_graphic_get_pixel	
#define vm_dd_getpixel 					vm_graphic_get_pixel
#define vm_dd_line_ex 					vm_graphic_line	
#define vm_dd_line 						vm_graphic_line
#define vm_dd_rect_ex 					vm_graphic_rect	
#define vm_dd_rect 						vm_graphic_rect
#define vm_dd_fillrect_ex 				vm_graphic_fill_rect	
#define vm_dd_fillrect 					vm_graphic_fill_rect
#define vm_dd_blt_ex 					vm_graphic_blt	
#define vm_dd_blt 						vm_graphic_blt
#define vm_dd_rotate_ex 				vm_graphic_rotate	
#define vm_dd_rotate 					vm_graphic_rotate
#define vm_dd_mirror_ex 				vm_graphic_mirror	
#define vm_dd_mirror 					vm_graphic_mirror
#define vm_dd_blt_with_opacity 			vm_graphic_blt_ex



/* vmdraw.h*/
#define vm_graph_initialize						vm_initialize_screen_buffer	
#define vm_graph_finalize						vm_finalize_screen_buffer
#define vm_graph_get_buffer						vm_graphic_get_buffer
#define vm_graph_flush_buffer					vm_graphic_flush_buffer
#define vm_graph_initialize_clip_rect				vm_dd_initialize_clip_rect
#define vm_graph_blt_all_cutting_frames			vm_dd_blt_all_cutting_frames
#define vm_graph_img_flood						vm_dd_img_flood
#define vm_graph_copy							vm_dd_copy
#define vm_graph_load_image					vm_dd_load_image
#define vm_graph_get_img_property 				vm_dd_get_img_property
#define vm_graph_get_frame_number				vm_dd_get_frame_number
#define vm_graph_clean							vm_dd_clean

#define vm_graph_get_bits_per_pixel				vm_graphic_get_bits_per_pixel
#define vm_graph_set_clip						vm_graphic_reset_clip
#define vm_graph_reset_clip						vm_graphic_reset_clip
#define vm_graph_get_screen_width				vm_graphic_get_screen_width
#define vm_graph_get_screen_height				vm_graphic_get_screen_height
#define vm_graph_get_character_height			vm_graphic_get_character_height
#define vm_graph_get_character_width 			vm_graphic_get_character_width
#define vm_graph_measure_character				vm_graphic_measure_character
#define vm_graph_get_string_width				vm_graphic_get_string_width
#define vm_graph_set_font						vm_graphic_set_font
#define vm_graph_setpixel						vm_graphic_set_pixel
#define vm_graph_getpixel						vm_graphic_get_pixel
#define vm_graph_line							vm_graphic_line
#define vm_graph_rect							vm_graphic_rect
#define vm_graph_fillrect							vm_graphic_fill_rect	
#define vm_graph_blt								vm_graphic_blt
#define vm_graph_rotate							vm_graphic_rotate
#define vm_graph_mirror							vm_graphic_mirror
#define vm_graph_draw_gif						vm_graphic_draw_gif
void vm_graph_drawtext(VMINT x, VMINT y, VMWSTR s, VMINT32 length, VMUINT16 color);
void vm_graph_release_surface(VMUINT8 * off_surface);
VMUINT8 * vm_graph_create_custom_buf(VMINT width, VMINT height);
void vm_graph_delete_custom_buf(VMUINT8 * custom_buf);
void vm_graph_move(VMBYTE *screen_buf, VMINT x_dest, VMINT y_dest, VMBYTE *custom_buf, VMINT x_src, VMINT y_src, VMINT width, VMINT height);

#ifdef __cplusplus
}
#endif

#endif
