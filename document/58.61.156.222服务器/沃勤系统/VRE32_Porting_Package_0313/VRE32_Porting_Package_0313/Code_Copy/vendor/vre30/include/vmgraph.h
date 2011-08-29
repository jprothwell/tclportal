#ifndef VMGRAPHIC_H_
#define VMGRAPHIC_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/* GDI return code */
typedef enum
{
	VM_GDI_ERR_BASE_LAYER_EXIST = -17,//基层还存在
    VM_GDI_FONTSIZE_NOT_SUPPORT = -16,
    VM_GDI_ERR_NOT_SUPPORT_ROTATE = -15,
    VM_GDI_MIBR_ERR = -14,
	VM_GDI_MIBR_RES_ERR,
	VM_GDI_MIBR_NOT_FORE,
	VM_GDI_MIBR_NO_RES,
	VM_GDI_ERR_PLATFORM_DECODE_FAILED,
	VM_GDI_ERR_BASE_LAYER_NOT_EXIST,
	VM_GDI_ERR_UNSUPPORT_IMAGE_TYPE,
	VM_GDI_ERR_MALLOC_FAILED,
	VM_GDI_ERR_LAYER_BIND,
	VM_GDI_ERR_FREE_RES,
	VM_GDI_ERR_CREATE_LAYER_FAILED,
	VM_GDI_ERR_CREATE_CANVAS_FAILED,
	VM_GDI_ERR_WRONG_PARAM,
	VM_GDI_FAILED,
	VM_GDI_SUCCEED
}vm_graphic_result;




/*GDI rotate type*/
typedef enum
{
      VM_GDI_ROTATE_NORMAL = 0,
      VM_GDI_ROTATE_90 = 0x01,
      VM_GDI_ROTATE_180 = 0x02,
      VM_GDI_ROTATE_270 = 0x03,
      VM_GDI_MIRROR = 0x80,
      VM_GDI_MIRROR_ROTATE_90 = 0x81,
      VM_GDI_MIRROR_ROTATE_180 = 0x82,
      VM_GDI_MIRROR_ROTATE_270 = 0x83
}vm_graphic_rotate_value;


/*GDI gradient paint style*/
typedef enum
{
    VM_GDI_GP_HOR = 0,  //水平
    VM_GDI_GP_VER,      //垂直
    VM_GDI_GP_DIA,      //斜45度
    VM_GDI_GP_DIA_INV,  //反向斜45度
    VM_GDI_GP_FLIP      //中间往2边 
}vm_graphic_gp_style;

typedef enum
{
    VM_GRAPHIC_SCREEN_ROTATE_0=0,
    VM_GRAPHIC_SCREEN_ROTATE_90,//1
    VM_GRAPHIC_SCREEN_ROTATE_180,//2
    VM_GRAPHIC_SCREEN_ROTATE_270,//3
    VM_GRAPHIC_SCREEN_ROTATE_MIRROR_0,//4
    VM_GRAPHIC_SCREEN_ROTATE_MIRROR_90,//5
    VM_GRAPHIC_SCREEN_ROTATE_MIRROR_180,//6
    VM_GRAPHIC_SCREEN_ROTATE_MIRROR_270,//7
    VM_GRAPHIC_SCREEN_ROTATE_MAX_TYPE//8
} vm_graphic_screen_rotate_value;


#define VM_GDI_RESULT VMINT
#define VM_GDI_HANDLE VMINT

#define MAX_LAYER_WIDTH 				(65535)
#define MAX_LAYER_HEIGHT 				(65535)
#define MAX_LAYER						(16)
#define MAX_BLT_LAYER					(4)//useless now
#define MAX_FLATTEN_LAYER				(4)
#define MAX_PIXEL_ENLARGE				(512)
#define CANVAS_BUF_OFFSET 				(VM_CANVAS_SIGNATURE_SIZE + VM_CANVAS_FRAME_PROPERTY_SIZE)
#define VM_NO_TRANS_COLOR				(-1)


/**
 * RGB565常用颜色值
 */
#define VM_COLOR_WHITE				    (0XFFFF)			//白
#define VM_COLOR_BLACK					(0X0000)			//黑
#define VM_COLOR_RED					(0XF800)			//红
#define VM_COLOR_GREEN					(0X07E0)			//绿
#define VM_COLOR_BLUE					(0X001F)			//蓝

/**
 * 常用辅助宏
 */
#define VM_RGB(r, g, b)					((b << 16) + (g << 8) + r)
#define VM_COLOR_INT_TO_565(i)			((i & 0xf8) << 8) + ((i & 0xfc00) >> 5) + ((i & 0xf80000) >> 19)
#define VM_COLOR_888_TO_565(r, g, b)	(((r & 0xf8) + ((g & 0xe0) >> 5)) << 8) + ((g & 0x1c) << 3) + (b >> 3)
#define VM_COLOR_565_TO_888(color16)	((color16 & 0x001F) << 19) + ((color16 & 0x07E0) << 5) + ((color16 & 0xF800) >> 8)
#define VM_COLOR_GET_RED(color16)		((color16 & 0xF800) >> 8)
#define VM_COLOR_GET_GREEN(color16)	    ((color16 & 0x07E0) >> 3)
#define VM_COLOR_GET_BLUE(color16)		((color16 & 0x001F) << 3)


	
typedef struct clip_rect{
	VMINT16 left;			/* 裁剪区左边界坐标（裁剪区包含坐标所在列） */	
	VMINT16 top;			/* 裁剪区上边界坐标（裁剪区包含坐标所在行） */	
	VMINT16 right;			/* 裁剪区右边界坐标（裁剪区包含坐标所在列） */	
	VMINT16 bottom;			/* 裁剪区下边界坐标（裁剪区包含坐标所在行） */	
	VMBYTE	flag;			/* 0该裁剪区无效，1该裁剪区有效 */
}clip_rect;

/**
 * IMG 单帧结构体
 */
struct frame_prop 
{
	VMUINT8  flag;			/* 图片标志位 */
	VMUINT16 left;			/* 图片左上角与图片逻辑框架左侧偏移量 */
	VMUINT16 top;			/* 图片左上角与图片逻辑框架上侧偏移量 */
	VMUINT16 width;			/* 图片宽 */
	VMUINT16 height;			/* 图片高 */
	VMUINT16 delay_time;	/* 延迟，在绘制完当前图像后的等待时间*/	
	VMUINT8  trans_color_index;	/* 保留字段*/	
	VMUINT16 trans_color;		/* 透明色*/	
	VMUINT32 offset;				/* 图像数据块大小*/	
};

typedef struct _vm_graphic_imgprop
{
	VMINT width;//图片宽
	VMINT height;//图片高
}vm_graphic_imgprop;


typedef struct _vm_graphic_char_info
{
    VMINT dwidth;   //字符adv_x
    VMINT width;    //字符glyph_width
	VMINT height;   //字符glyph_height
	VMINT ascent;   //字符ascent
	VMINT descent;  //字符descent
}vm_graphic_char_info;

/**
 * font size
 */
typedef enum {
	VM_SMALL_FONT, 
	VM_MEDIUM_FONT, 
	VM_LARGE_FONT
} font_size_t;

/**
 * create mode of layer
 */
typedef enum{
	VM_BASE_LAYER = 1,          //创建基层
	VM_FAST_LAYER ,             //创建快速层
	VM_BUF,                     //使用内存创建层
	VM_CREATE_CANVAS            //创建画布同时创建层
}vm_layer_mode;

/**
 * property of canvas
 */
typedef enum{
	VM_CANVAS_LEFT = 1,
	VM_CANVAS_TOP,
	VM_CANVAS_WIDTH,
	VM_CANVAS_HEIGHT
}vm_canvas_prop;


typedef struct _vm_graphic_point{
	VMINT16 x;
	VMINT16 y;
}vm_graphic_point;

typedef struct _vm_graphic_color{
	VMUINT vm_color_565;//565格式的颜色
	VMUINT vm_color_888;//888格式的颜色
}vm_graphic_color;



/*
example:
VMBYTE bitvalues[] = {1,1,1,0,0};
vm_graphic_pen pen;
pen.cycle = sizeof(bitvalues);
pen.bitvalues = bitvalues;
*/	
typedef struct _vm_graphic_pen{
	VMBYTE cycle;//虚线线段的长度
	VMBYTE *bitvalues;//象素点样式，指向一个用户自定义的数组.
}vm_graphic_pen;






/**
 * 获得屏幕的宽度。
 */
VMINT vm_graphic_get_screen_width(void);

/**
 * 获得屏幕的高度。
 */
VMINT vm_graphic_get_screen_height(void);

/**
 * 创建层。
 * 层是对屏幕的模拟，VRE支持两个层。
 * VRE两层系统可以根据用户设定融合两层。
 * 第一层（基层）与硬件屏幕完全重合，位置大小都一致。
 * 第二层用户可以设置透明度等操作，两层以指定透明度融合。
 * 创建基层的参数需做限定。
 * 具体限定为:
 * 1)左上角坐标为(0,0),即x=0;y=0;
 * 2)层宽高为屏幕的宽高。
 * 参考代码:
 * VMINT layer_hdl[2] = {0};			
 * layer_hdl[0] = vm_graphic_create_layer(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height(), VM_NO_TRANS_COLOR);	
 *
 * @param x				层在屏幕上的左上角X坐标。
 * @param y				层在屏幕上的左上角Y坐标。
 * @param width			层的宽度，像素单位。
 * @param height 			层的高度，像素单位。
 * @param trans_color		层的背景穿透色，-1表示无穿透色，否则层在输出到屏幕时
 *						会忽略背景穿透色以产生穿透效果。
 *
 * @return				成功返回创建的层句柄，否则返回错误码。
 */
VMINT vm_graphic_create_layer(VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color);

/**
 * 删除层并释放层所创建的屏幕缓冲区，应用程序创建层之后必须要把层释放，释放层的
 * 时机可以是应用程序退出之前。
 *
 * @param handle		层句柄，由vm_graphic_create_layer返回。
 *
 * @return				返回VM_GDI_SUCCEED表示层删除成功，否则为失败。
 */
VMINT vm_graphic_delete_layer(VMINT handle);

/**
 * 激活层。当程序试图激活不存在的层时，系统不会任何操作，当前激活层不会被改变。
 * 激活层成功后，全局裁剪区将会变为当前层的裁剪区
 *
 * @param handle		由vm_graphic_create_layer()返回的层句柄。
 *
 * @return				返回VM_GDI_SUCCEED表示激活层成功，否则为失败。
 */	
VMINT vm_graphic_active_layer(VMINT handle);

/**
 * 返回层的显示缓冲区。
 *
 * @param handle		层句柄。
 *
 * @return				返回NULL表示取显示缓冲区失败，否则返回显示缓冲区指针。
 */	
VMUINT8* vm_graphic_get_layer_buffer (VMINT handle);

/**
 * 使用背景色清除层的内容。
 *
 * @param handle		层句柄，背景色由vm_graphic_create_layer()函数 的trans_color参数传入。当
 * 					 trans_color	不等于-1 时，层中所有等于背景色的部分都当作穿透背景使用。
 *
 * @return				返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */	
VMINT vm_graphic_clear_layer_bg (VMINT handle);

/**
 * 把各个层合并为一个层并刷新到屏幕上，应用程序必须调用这个函数才能实现屏幕的
 * 绘制更新。
 *
 * @param layer_handles		层数组指针。
 * @param count				层数组的下标个数。每次合并绘制的最大支持层数通过vm_graphic_get_blt_layer_count获得
							若下标超出最大支持层数，则只刷最大层数。
 *
 * @return					返回VM_GDI_SUCCEED表示绘制成功，否则为失败。
 */
VMINT vm_graphic_flush_layer(VMINT* layer_handles, VMINT count);

/**
 * 获得目标平台支持的最大层数。层是为了方便图形绘制而设计的硬件，应用程序可以在不同
 * 的层上绘制图形，然后让系统把层迭加在一起组成完整的图像。比如手机的待机桌面
 * 背景可以是一个层，顶部的信号区和底部的软功能键栏分别为两个层，待机桌面上的
 * 图标可以是第四个层，当信号状态改变时应用程序只需要重绘一个层，使用硬件层可
 * 以加快复杂用户界面的绘制速度。
 *
 * @return				返回目标平台层的数量。
 */
VMINT vm_graphic_get_layer_count(void);

/**
 * 获得层的位置。
 *
 * @param handle		层句柄。
 * @param x				层左上角X坐标。
 * @param y				层左上角Y坐标。
 * @param width			层的宽度。
 * @param height		层的高度。
 *
 * @return				返回VM_GDI_SUCCEED表示取层配置成功，否则为失败。
 */
VMINT vm_graphic_get_layer_position(VMINT handle, VMINT *x, VMINT *y, VMINT *width, VMINT *height);

/**
 * 设置层的透明度。
 *
 * @param handle			层句柄。
 * @param percent			透明度，从0到100，数字越大表示透明度越低。
 *
 * @return					返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
VMINT vm_graphic_set_layer_opacity(VMINT handle, VMINT percent);

/**
 * 获得目标平台屏幕缓冲区表示一个像素所用的字节数。
 *
 * @return				屏幕缓冲区表示一个像素所用的字节数。
 */
VMINT vm_graphic_get_bits_per_pixel(void);

/**
 * 获得缓冲区(显缓或画布)给指定点的颜色。
 *
 * @param buf		源缓冲
 * @param x			点的X坐标。
 * @param y			点的Y坐标。
 *
 * @return			点的颜色。
 */
VMUINT16 vm_graphic_get_pixel(VMUINT8 *buf, VMINT x, VMINT y);

/**
 * 在目标缓冲区(显缓或画布)上画点。
 *
 * @param buf	源缓冲。
 * @param x		点的X坐标。
 * @param y		点的Y坐标。
 * @param color	点的颜色。
 */
void vm_graphic_set_pixel(VMUINT8 *buf, VMINT x,VMINT y, VMUINT16 color);

/**
 * 在目标缓冲区(显缓或画布)上画线。
 *
 * @param buf	目标缓冲
 * @param x0	线起点的X坐标。
 * @param y0	线起点的Y坐标。
 * @param x1	线终点的X坐标。
 * @param y1	线终点的Y坐标。
 * @param color	线的颜色。
 */
void vm_graphic_line(VMUINT8 *buf, VMINT x0, VMINT y0, VMINT x1, VMINT y1, VMUINT16 color);

/**
 * 在目标缓冲区上(显缓或画布)画矩形。
 *
 * @param buf		目标缓冲
 * @param x			矩形左上角X坐标。
 * @param y			矩形左上角Y坐标。
 * @param width		矩形宽度。
 * @param height	矩形高度。
 * @param color		矩形边框颜色。
 */
void vm_graphic_rect(VMUINT8 *buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color);

/**
 * 在目标缓冲区上(显缓或画布)填充矩形区域。
 * 
 * @param buf		 目标缓冲
 * @param x			 矩形左上角X坐标。
 * @param y			 矩形左上角Y坐标。
 * @param width		 矩形的宽度。
 * @param height	 矩形的高度。
 * @param line_color 边框颜色。
 * @param back_color 填充颜色。
 */
void vm_graphic_fill_rect(VMUINT8 *buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 line_color, VMUINT16 back_color);

/**
 * 向显示缓冲区绘制空心圆角矩形，给定的坐标相对于显示缓冲区的左上角，和物理屏幕无关。
 * 
 * @param buf			目标缓冲
 * @param x				矩形左上角X坐标。
 * @param y				矩形左上角Y坐标。
 * @param width			矩形宽度。
 * @param height		矩形高度。
 * @param corner_width	圆角半径，圆角半径不得超过矩形宽度的一半，如果超出则绘制失败。
 * @param color			边框颜色，使用565格式。
 */
void vm_graphic_roundrect (VMUINT8 * buf, VMINT x, VMINT y, VMINT width, VMINT height, VMINT corner_width, VMUINT16 color);

/**
 * 向显示缓冲区绘制实心圆角矩形，给定的坐标相对于显示缓冲区的左上角，和物理屏幕无关。
 * 
 * @param buf			目标缓冲
 * @param x				矩形左上角X坐标。
 * @param y				矩形左上角Y坐标。
 * @param width			矩形宽度。
 * @param height		矩形高度。
 * @param corner_width	圆角半径，圆角半径不得超过矩形宽度的一半，如果超出则绘制失败。
 * @param color			填充颜色，使用565格式。
 */
void vm_graphic_fill_roundrect (VMUINT8 * buf, VMINT x,	VMINT y, VMINT width, VMINT height, VMINT corner_width, VMUINT16 color);

/**
 * 向显示缓冲区绘制空心椭圆，给定的坐标相对于显示缓冲区的左上角，和物理屏幕无关。
 * 
 * @param buf			目标缓冲
 * @param x				椭圆左上角X坐标。
 * @param y				椭圆左上角Y坐标。
 * @param width			椭圆宽度。
 * @param height		椭圆高度。
 * @param color			椭圆边框颜色，使用565格式。
 */
void vm_graphic_ellipse (VMUINT8 * buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color);

/**
 * 向显示缓冲区绘制实心椭圆，给定的坐标相对于显示缓冲区的左上角，和物理屏幕无关。
 * 
 * @param buf			目标缓冲
 * @param x				椭圆左上角X坐标。
 * @param y				椭圆左上角Y坐标。
 * @param width			椭圆宽度。
 * @param height		椭圆高度。
 * @param color			椭圆填充颜色，使用565格式。
 */
void vm_graphic_fill_ellipse (VMUINT8 * buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color);

/**
 * 创建指定大小的画布。
 * 
 * @param width			画布宽。
 * @param height		画布高。
 *
 * @return				成功返回新建画布句柄，否则返回错误码。
 */
VMINT vm_graphic_create_canvas(VMINT width, VMINT height);

/**
 * 释放由vm_graphic_create_canvas或vm_graphic_load_image创建的画布资源。
 * 
 * @param hcanvas	画布句柄。
 */
void vm_graphic_release_canvas(VMINT hcanvas);

/**
 * 获得画布的显示缓冲区指针。
 * 
 * @param hcanvas		画布句柄。
 *
 * @return				返回画布的显示缓冲区指针。
 */							  
VMUINT8* vm_graphic_get_canvas_buffer(VMINT hcanvas);

/**
 * 对图像进行解码，解码后的图像被绘制到新建的画布上。
 * 
 * @param img			指向图象数据的内存指针，存放图象数据的内存块格式与图象文件格式完全一致。
 * @param img_len		图象内存块的长度。
 *
 * @return				成功返回新建画布句柄，否则返回错误码。
 */
VMINT vm_graphic_load_image(VMUINT8 *img, VMINT img_len);

/**
 * 获取图像单帧属性。
 *
 * @param hcanvas		指向由vm_graphic_load_image()得到的画布句柄。
 * @param frame_index	图象帧号,帧号从1开始,第一帧帧号为1。
 *
 * @return				图象属性结构体指针。
 */
struct frame_prop * vm_graphic_get_img_property(VMINT hcanvas, VMUINT8 frame_index);

/**
 * 获取图像的帧数目。
 *
 * @param hcanvas		指向由vm_graphic_load_image()得到的图象画布。
 *
 * @return				图像的帧数目。
 */
VMINT vm_graphic_get_frame_number(VMINT hcanvas);

/**
 * 把源显示缓冲区的内容拷贝到目标显示缓冲区上，拷贝使用逐位复制，不对像素做
 * 融合运算。参与操作的显示缓冲区可以是屏幕的显示缓冲区，也可以是画布的显示
 * 缓冲区。
 *
 * @param dst_disp_buf		目标显示缓冲区指针。
 * @param x_dest			目标绘图区域的左上点X坐标
 * @param y_dest			目标绘图区域的左上点Y坐标
 * @param src_disp_buf		源显示缓冲区指针。
 * @param x_src				源绘图区域的左上点X坐标
 * @param y_src				源绘图区域的左上点Y坐标
 * @param width				目标绘图区域的宽
 * @param height			目标绘图区域的高
 * @param frame_index		图象帧的帧号，帧号从1开始编号。
 */
void vm_graphic_blt(VMBYTE * dst_disp_buf, VMINT x_dest, VMINT y_dest, VMBYTE * src_disp_buf, 
					 VMINT x_src, VMINT y_src, VMINT width, VMINT height, VMINT frame_index);

/**
 * 把源显示缓冲区的内容拷贝到目标显示缓冲区上，拷贝使用逐位复制，以指定alpha
 * 值对像素做融合运算。参与操作的显示缓冲区可以是屏幕的显示缓冲区，也可以是
 * 画布的显示缓冲区。
 *
 * @param dst_disp_buf		目标显示缓冲区指针。
 * @param x_dest			目标绘图区域的左上点X坐标
 * @param y_dest			目标绘图区域的左上点Y坐标
 * @param src_disp_buf		源显示缓冲区指针。
 * @param x_src				源绘图区域的左上点X坐标
 * @param y_src				源绘图区域的左上点Y坐标
 * @param width				目标绘图区域的宽
 * @param height			目标绘图区域的高
 * @param frame_index		图象帧的帧号，帧号从1开始编号。
 * @param alpha				透明度，从0到255，数字越大表示透明度越低。
 */
void vm_graphic_blt_ex(VMBYTE * dst_disp_buf, VMINT x_dest, VMINT y_dest, VMBYTE * src_disp_buf, 
						VMINT x_src, VMINT y_src, VMINT width, VMINT height, VMINT frame_index, VMINT alpha);
					 
/**
 * 得到当前点阵字库的字高度。
 *
 * @return		字的高度，以象素为单位。
 */
VMINT vm_graphic_get_character_height(void);

/**
 * 得到字符宽度。
 *
 * @param c		UCS2格式编码的字符。
 * 
 * @return		字符宽度，以象素为单位。
 */
VMINT vm_graphic_get_character_width(VMWCHAR c);

/**
 * 获得给定字串长度，以象素为单位。
 *
 * @param str		UCS2编码格式的字符串。
 *
 * @return			成功返回字符串宽度，以象素为单位。否则返回错误码
 */
VMINT vm_graphic_get_string_width(VMWSTR str);


/**
 * 获得给定字串高度，以象素为单位。
 *
 * @param str		UCS2编码格式的字符串。
 *
 * @return			成功返回字符串高度，以象素为单位。否则返回错误码
 */
VMINT vm_graphic_get_string_height(VMWSTR str);



/**
 * 获得给定字符的高度和宽度，以象素为单位。
 *
 * @param c			UCS2编码格式的字符。
 * @param width		字符宽度，以象素为单位。
 * @param height	字符高度，以象素为单位。
 *
 * @return			返回VM_GDI_SUCCEED表示成功，否则为失败。
 */
VMINT vm_graphic_measure_character(VMWCHAR c, VMINT *width, VMINT *height);



/**
 * 获得给定字符的信息。
 *
 * @param c			UCS2编码格式的字符。
 * @param char_info		字符信息。
 *
 * @return			返回VM_GDI_SUCCEED表示成功，否则为失败。
 */
VMINT vm_graphic_get_character_info(VMWCHAR c, vm_graphic_char_info *char_info);

/**
 * 设置字体，手机上使用的都是点阵字库，因此只能设置其字体大小而无法设置字
 * 型。当目标机只有一个字体字库时，本函数调用无效。
 *
 * @param size		字体尺寸。
 */
void vm_graphic_set_font(font_size_t size);

/**
* 向显示缓冲区绘制文字，文字的尺寸由vm_graphic_set_font()决定，默认是中号字体。
 *
 * @param disp_buf		显示缓冲区指针。
 * @param x				被绘制文字的左上角横坐标。
 * @param y				被绘制文字的左上角纵坐标。
 * @param s				被绘制的字符串。
 * @param length		被绘制的字符串长度。
 * @param color			文字颜色，使用565格式。
 */
void vm_graphic_textout (VMUINT8* disp_buf, VMINT x, VMINT y, VMWSTR s, VMINT length, VMUINT16 color);

/**
 * 设置矩形的裁剪区域，绘图时落在裁剪区域以外的图像都会被裁剪。
 * VRE的剪裁区为一个全局剪裁区。当目标操作对象更换时需要重新设置剪裁区。
 * 例如，程序创建了一个层(屏幕大小)和一个画布(200*200).
 * 原先绘制目标区域为第一层，设置了屏幕大小的剪裁区.
 * 此时更换绘制的目标区域，想往画布上绘制。这时需重新针对画布设置剪裁区。
 * 
 *
 * @param x1				x1 裁剪区域的左上角横坐标，采用屏幕左上角为原点的直角坐标系。
 * @param y1				y1 裁剪区域的左上角纵坐标。
 * @param x2				x2 裁剪区域的右下角横坐标。
 * @param y2				y2 裁剪区域的右下角纵坐标。
 */
void vm_graphic_set_clip(VMINT x1, VMINT y1, VMINT x2, VMINT y2);

/**
 * 释放裁剪区域,屏幕可绘区域恢复成全屏大小。
 */
void vm_graphic_reset_clip(void);

/**
 * 触发重绘屏幕系统消息。这个函数调用后，系统会向通过vm_reg_sysevt_callback()
 * 注册的系统事件监听函数发出VM_PAINT消息，应用程序可以通过这个函数触发系
 * 统重绘消息。
 */
void vm_graphic_flush_screen(void);

/**
 * 旋转角度
 */
#define VM_ROTATE_DEGREE_90				    (90)
#define VM_ROTATE_DEGREE_180				(180)
#define VM_ROTATE_DEGREE_270				(270)
/**
 * 从画布中获取整帧图象的像素信息后，按指定的旋转角度绘制到目标区域(显缓或画布)
 *
 * @param buf				目标缓冲
 * @param x_des             目标左上点X坐标
 * @param y_des             目标左上点Y坐标
 * @param src_buf			源缓冲
 * @param frame_index 		帧号
 * @param degrees			顺时针旋转角度，
 *                                              暂只支持VM_ROTATE_DEGREE_90、VM_ROTATE_DEGREE_180、VM_ROTATE_DEGREE_270度三个角度。
 *                                              输入其他值将不做绘制操作。
 */
void vm_graphic_rotate(VMBYTE *buf, VMINT x_des, VMINT y_des, 
						VMBYTE *src_buf, VMINT frame_index, VMINT degrees);


/*
临时接口 ,为了模拟VRE 发 VM_MSG_ROTATE 消息  ,参数为 模拟VRE 建议应用翻转的角度
可以传入的参数建议为以下四种之一
VM_GRAPHIC_SCREEN_ROTATE_0
VM_GRAPHIC_SCREEN_ROTATE_90
VM_GRAPHIC_SCREEN_ROTATE_180
VM_GRAPHIC_SCREEN_ROTATE_270
否则
也发 VM_MSG_ROTATE	消息,不过 建议的翻转角度 为 
VM_GRAPHIC_SCREEN_ROTATE_0

void vm_graphic_rotate_temp(VMINT _rotate_value);
*/


/**
 * 镜像方向
 */
#define VM_MIRROR_X							(0)
#define VM_MIRROR_Y							(1)
/**
 * 从画布中获取整帧图象的像素信息后，按指定的镜像方向绘制图片
 *
 * @param buf               目标缓冲(显缓或画布)
 * @param x_des				目标绘图区域的左上点X坐标
 * @param y_des				目标绘图区域的左上点Y坐标
 * @param src_buf			源缓冲
 * @param frame_index		图象帧的帧号，帧号从1开始编码
 * @param direction         镜像方向支持垂直、水平两个方向，VM_MIRROR_X表示沿x方向,VM_MIRROR_Y沿y方向，
 *                                  输入其他值将不做绘制操作。
 */
void vm_graphic_mirror(VMBYTE *buf, VMINT x_des, VMINT y_des, VMBYTE *src_buf, VMINT frame_index, VMINT direction);

/**
 * vm_reg_res_provider()函数用于注册应用程序的资源映射函数。
 * 当资源以数组形式保存在程序中时，数组可以通过资源映射函数把数组与一个整数型ID对应。
 * 程序中可以通过ID来操作资源。
 *
 * @param fp		应用程序提供的资源映射函数指针。
 */
void vm_reg_res_provider(VMUINT8* (*fp)(VMINT resid, VMINT* len));

/*
 *	多种模式创建层
 *	在创建其他层前，必须先创建基层。

 *
 *	@param x				层在屏幕上的左上角X坐标。
 *	@param y				层在屏幕上的左上角Y坐标。
 *	@param width				层的宽度，像素单位。
 *	@param height 			层的高度，像素单位。
 *	@param trans_color		层的背景穿透色，-1表示无穿透色，否则层在输出到屏幕时
 *							会忽略背景穿透色以产生穿透效果。
 *	@param mode				创建模式
 *							VM_BASE_LAYER:
 *							创建基层信息。当已经创建，带入的参数将覆盖前一次的参数。
 *							VM_FAST_LAYER:
 *							创建一个快速层，绘制速度更快，但是全局只能创建一个。
 *							如果已经创建，则返回该层handle，同时覆盖原有参数。
 *							VM_BUF:
 *							使用Canvas的buf创建新层，此时形参buf有效，该buf必须是由vm_create_canvas创建的画布缓存。
 *							创建之后该画布和新层将做映射。
 *							再次用同一块buf创建层将返回错误。
 *							VM_CREATE_CANVAS:
 *							创建一块画布，同时使用新画布缓存创建新层。
 *							创建之后画布和层将做映射。
 *	@param buf				当使用VM_BUF模式创建层时,新建层所需要的画布缓存头指针。
 * @return				成功返回创建的层句柄，否则返回错误码。
 */
VM_GDI_HANDLE vm_graphic_create_layer_ex(VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color,VMINT mode,VMUINT8 * buf);


/**
 * 释放一块画布,当画布和某一个层对应，即使用该画布缓存创建了层，那么将同时删除该层。
 *
 * @param hcanvas			画布句柄。

 *
 * @return					返回VM_GDI_SUCCEED表示删除成功，否则为失败。
 */
VM_GDI_RESULT  vm_graphic_release_canvas_ex(VMINT hcanvas);


/**
 * 将几块画布缓存合并绘制到当前层上，同时释放这几块画布和映射的层。
 * 如果映射层为当前层，则不释放该画布和映射层。
 * 画布缓存必须和某一层做过映射，否则该画布不做合并。
 * 每次合并绘制的最多支持层数为4
 *
 *
 * @param hcanvas			画布句柄数组指针。
 * @param count				合并画布数。
 *
 * @return					返回VM_GDI_SUCCEED表示合并成功，否则为失败。
 */
VM_GDI_RESULT  vm_graphic_flatten_canvas(VMINT *hcanvas,VMINT count);


/**
 * 将几个层合并绘制到当前层上，同时释放这几个层。当前层不会释放。
 * 每次合并绘制的最多支持层数为4
 *
 *
 * @param hhandle			层句柄数组指针。
 * @param count				合并层数。
 *
 * @return					返回VM_GDI_SUCCEED表示合并成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_flatten_layer(VMINT *hhandle,VMINT count);

/**
 * 重设层的大小。重设之后，需要重绘其中的数据。
 * 新的宽高不能大于原有的宽高。
 *
 * @param width			新的宽度。
 * @param height		新的高度。
 *
 * @return				返回VM_GDI_SUCCEED表示resize成功，否则为失败。
 */
VM_GDI_RESULT  vm_graphic_resize_layer(VMINT handle,VMINT width,VMINT height);

/**
 * 设置画笔。
 *
 * @param pen		颜色指针。
 *
 * @return				返回VM_GDI_SUCCEED表示设置成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_setpen(vm_graphic_pen *pen);

/**
 * 获取画笔。
 *
 *
 * @return				返回画笔。
 */
vm_graphic_pen  vm_graphic_getpen(void);


/**
 * 设置全局颜色。
 *
 * @param color		颜色指针。
 *
 * @return				返回VM_GDI_SUCCEED表示设置成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_setcolor(vm_graphic_color* color);


/**
 * 获取全局颜色。
 *
 *
 * @return				返回颜色。
 */
vm_graphic_color vm_graphic_getcolor(void);

/**
 * 在层上画点
 *
 * @param handle		层句柄。
 * @param x1			点的X坐标。
 * @param y1			点的Y坐标。
 */
void vm_graphic_set_pixel_ex(VMINT handle,VMINT x1,VMINT y1);


/**
 * 在层上画实线。不使用画笔。
 *
 * @param handle		层句柄。
 * @param x1			线起点的X坐标。
 * @param y1			线起点的Y坐标。
 * @param x2			线终点的X坐标。
 * @param y2			线终点的Y坐标。
 */
void vm_graphic_line_ex(VMINT handle,VMINT x1,VMINT y1,VMINT x2,VMINT y2);


/**
 * 使用画笔在层上画线。通过vm_graphic_set_pen设置画笔风格，之后调用该函数。
 * 如果从未调用vm_graphic_set_pen设置画笔，则不会绘制。
 * 
 * @param handle		层句柄。
 * @param x1			线起点的X坐标。
 * @param y1			线起点的Y坐标。
 * @param x2			线终点的X坐标。
 * @param y2			线终点的Y坐标。
 */
void vm_graphic_line_style(VMINT handle,VMINT x1,VMINT y1,VMINT x2,VMINT y2);

/**
 * 向层上绘制空心圆角矩形，给定的坐标相对于显示缓冲区的左上角，和物理屏幕无关。
 * 
 * @param handle			层句柄。
 * @param x				矩形左上角X坐标。
 * @param y				矩形左上角Y坐标。
 * @param width			矩形宽度。
 * @param height			矩形高度。
 * @param frame_width		圆角半径，圆角半径不得超过矩形宽度的一半，如果超出则绘制失败。
 */
void vm_graphic_roundrect_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height, VMINT frame_width);

/**
 * 在层上画矩形。
 *
 * @param handle		层句柄。
 * @param x			矩形左上角X坐标。
 * @param y			矩形左上角Y坐标。
 * @param width		矩形宽度。
 * @param height		矩形高度。
 */
void vm_graphic_rect_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height);

/**
 * 在层上绘制空心椭圆，给定的坐标相对于层的左上角。
 * 
 * @param handle			层句柄。
 * @param x				椭圆左上角X坐标。
 * @param y				椭圆左上角Y坐标。
 * @param width			椭圆宽度。
 * @param height			椭圆高度。
 */
void vm_graphic_ellipse_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height);


/**
 * 在层上绘制空心多边形
 * 
 * @param handle			层句柄。
 * @param point			点坐标数组。
 * @param npoint		点的数量。
 */
void vm_graphic_polygon(VMINT handle, vm_graphic_point *point,VMINT npoint);

/**
 * 向层上绘制实心圆角矩形，给定的坐标相对于显示缓冲区的左上角，和物理屏幕无关。
 * 
 * @param handle			层句柄。
 * @param x				矩形左上角X坐标。
 * @param y				矩形左上角Y坐标。
 * @param width			矩形宽度。
 * @param height			矩形高度。
 * @param frame_width		圆角半径，圆角半径不得超过矩形宽度的一半，如果超出则绘制失败。
 */
void vm_graphic_fill_roundrect_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height, VMINT  frame_width);

/**
 * 在层上画实心矩形。
 *
 * @param handle		层句柄。
 * @param x			矩形左上角X坐标。
 * @param y			矩形左上角Y坐标。
 * @param width		矩形宽度。
 * @param height		矩形高度。
 */
void vm_graphic_fill_rect_ex(VMINT handle, VMINT  x, VMINT  y, VMINT  width, VMINT  height);


/**
 * 向显示缓冲区绘制实心椭圆，给定的坐标相对于层的左上角。
 * 
 * @param handle			层句柄。
 * @param x				椭圆左上角X坐标。
 * @param y				椭圆左上角Y坐标。
 * @param width			椭圆宽度。
 * @param height			椭圆高度。
 */
void vm_graphic_fill_ellipse_ex(VMINT handle, VMINT  x, VMINT  y, VMINT  width, VMINT  height);


/**
 * 在层上绘制实心多边形
 * 
 * @param handle			层句柄。
 * @param point			点坐标数组。
 * @param npoints				点的数量。
 */
void vm_graphic_fill_polygon(VMINT handle, vm_graphic_point *point,VMINT npoints);





/**
 *渐变色绘制一块矩形区域。
 *
 * @param handle 		层句柄。
 * @param x1 		矩形区域左上角的x坐标。
 * @param y1 		矩形区域左上角的y坐标。
 * @param x2 		矩形区域右下角的x坐标。
 * @param y2 		矩形区域右下角的y坐标。
 * @param color_start		渐变色的起始颜色。
 * @param color_end		渐变色的结束颜色。
 * @param style			绘制风格。
 *
 */
void vm_graphic_gradient_paint_rect(VMINT handle, VMINT x1, VMINT y1, VMINT x2, VMINT y2, vm_graphic_color color_start, vm_graphic_color color_end,vm_graphic_gp_style style);



/**
 * 获取层的裁剪区。
 *
 * @param handle 		    要获取的层句柄。
 * @param curcliprect 		获取的裁剪区。
 *
 * @return				返回VM_GDI_SUCCEED表示获取成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_get_layer_clip(VMINT handle,clip_rect * curcliprect);


/**
 *设置层的裁剪区。当handle为当前层时，调用该接口，会影响全局裁剪区。
 *
 * @param handle 	要设置的层句柄。
 * @param x1 		裁剪区左上角的x坐标。
 * @param y1 		裁剪区左上角的y坐标。
 * @param x2 		裁剪区右下角的x坐标。
 * @param y2 		裁剪区右下角的y坐标。
 *
 * @return				返回VM_GDI_SUCCEED表示设置成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_set_layer_clip(VMINT handle,VMINT16 x1,VMINT16 y1,VMINT16 x2,VMINT16 y2);

/**
 * 平移一个层。
 *
 * @param handle			平移的层句柄。
 * @param tx				新层左上角的x坐标，相对于(0,0)。
 * @param ty				新层左上角的y坐标，相对于(0,0)。
 *
 * @return				返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_translate_layer(VMINT handle , VMINT tx, VMINT ty);


/**
 * 旋转一个层。
 *
 * @param handle			旋转的层句柄。
 * @param rotatevalue		旋转的角度。目前只支持0,90,180,270度。如：当旋转了90度，需要再旋转90度，rotatevalue = VM_GDI_ROTATE_180.
 *
 * @return				返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_rotate_layer(VMINT handle, vm_graphic_rotate_value rotatevalue);


/**
 * 缩放一张图片至指定大小。
 *
 * @param img_data		图片数据指针。
 * @param img_len			图片数据大小。
 * @param width			图片的新宽度。
 * @param height			图片的新高度。
 *
 * @return				成功返回新建画布句柄，否则返回错误码。
 */
VMINT vm_graphic_load_image_resized(VMUINT8 *img_data, VMINT img_len,VMINT width,VMINT height);

/**
 * 倍数放大GIF图片。只能放大，且类型只支持GIF文件。
 *
 * @param img_data		图片数据指针。
 * @param img_len			图片数据大小。
 * @param percent		放大倍数。
 *
 * @return				成功返回新建画布句柄，否则返回错误码。
 */
VMINT vm_graphic_load_gif_resized_by_percent(VMUINT8 *img_data, VMINT img_len,VMINT percent);

/**
 * 获取图片属性。可在后台使用。
 *
 * @param img_data		图片数据指针。
 * @param img_len			图片数据大小。
 * @param img_prop		属性结构体指针。	
 *
 * @return				返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
//VM_GDI_RESULT vm_graphic_get_img_property_ex(VMUINT8 *img_data, VMINT img_len,vm_graphic_imgprop * img_prop);


/**
 * 获取绘制的最大层数。与最大支持层数不同。
 * 最大支持层数指总共能够创建的层数，通过 vm_graphic_get_layer_count()获取。
 *
 * @return			绘制的最大层数。
 *
 */
VMINT vm_graphic_get_blt_layer_count(void);


/**
 * 设置字体大小。
 * 推荐使用font_size_t定义的大中小字体。
 * 如果直接使用数字，当在未使用矢量字体和使用矢量字体的机器之间移植时，可能会界面显示不一致。
 * @param size		字体大小。
 *
 * @return				返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
VM_GDI_RESULT vm_font_set_font_size(VMINT size);

/**
 *设置字体风格，只对矢量字体有效。
 * @param bold			是否加粗，TRUE表示加粗，FALSE不加粗。
 * @param italic			是否倾斜，TRUE表示倾斜，FALSE不倾斜。
 * @param underline		是否有下划线，TRUE表示有下划线，FALSE无下划线。
 * 
 * @return				返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
VM_GDI_RESULT vm_font_set_font_style(VMINT bold,VMINT italic,VMINT underline);



/*
 *在层上绘制文字。
 * @param handle			层句柄。
 * @param x				绘制文字的左上角横坐标。
 * @param y				绘制文字的左上角纵坐标。
 * @param s				绘制的字符串。
 * @param length			绘制的字符串长度。
 * 
 * @return				返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_textout_to_layer (VMINT handle, VMINT x, VMINT y, VMWSTR s, VMINT length);

/*
 *设置画布的穿透色。(使用vm_graphic_blt_ex()时该穿透色有效)
 *当画布与一个层相映射时，则会同样修改层的穿透色设置。
 * @param hcanvas			VRE画布句柄。
 * @param trans_color			穿透色,-1表示无穿透色。
 * 
 * @return					返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_canvas_set_trans_color(VMINT hcanvas, VMINT trans_color);


/*
 *设置层的穿透色。
 * @param hhandle			层句柄。
 * @param trans_color			穿透色,-1表示无穿透色。
 * 
 * @return					返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
VM_GDI_RESULT vm_graphic_layer_set_trans_color(VMINT hhandle, VMINT trans_color);

/*
 * 当前平台是否支持矢量字体。
 * 
 * @return					返回TRUE表示支持，否则为不支持。
 */
VMINT vm_graphic_is_use_vector_font(void);


/*
 *根据点阵数组绘制点阵字符。
 * @param handle		层句柄
 * @param x				绘制文字的左上角横坐标。
 * @param y				绘制文字的左上角纵坐标。
 * @param color			文字颜色
 * @param font_data		点阵数组
 * @param font_width		字符宽度
 * @param font_height		字符高度 
 * 
 * @return				返回VM_GDI_SUCCEED表示操作成功，否则为失败。
 */
VMINT vm_graphic_draw_abm_text(VMINT handle, VMINT x, VMINT y, VMINT color,VMUINT8* font_data,VMINT font_width,VMINT font_height);



//========================================================================
void vm_graphic_show_theme_background(void);

void vm_graphic_show_status_icon_bar(void);

void vm_graphic_show_left_softkey(void);

void vm_graphic_show_right_softkey(void);

void vm_graphic_reset_status_icon_bar(void);
//========================================================================

//=====================================================================
// rotate screen
/**
 * 翻转屏幕至指定的角度。
 *
 * @param  rotate	vm_graphic_screen_rotate_value枚举中的一个值现在的取值*@范围可以查看vm_graphic_screen_rotate_value定义。
*
 * @return		返回翻转屏幕的操作结果 ：
* @如果手机支持屏幕翻转 成功返回 VM_GDI_SUCCEED，
* @失败返回：VM_GDI_ERR_WRONG_PARAM
* @如果手机不支持屏幕翻转就会返回：VM_GDI_ERR_NOT_SUPPORT_ROTATE
 */ 
VMINT vm_graphic_screen_rotate(vm_graphic_screen_rotate_value rotate);

/**
 * 重置翻转后的屏幕，让屏幕以原来的模式显示。2010-7-14 王传祥删除这个函数
 *
 * @param 为NULL*
 * @return		返回重置翻转屏幕的操作结果 ：
* @如果手机支持屏幕翻转 成功返回 VM_GDI_SUCCEED，
* @如果手机不支持屏幕翻转就会返回：VM_GDI_ERR_NOT_SUPPORT_ROTATE
 

VMINT vm_graphic_reset_screen_rotate(void);*/ 

/**
 * 获得屏幕翻转后的度数。
 *
 * @param 为NULL*
 * @return		获得屏幕翻转后的度数的操作结果 ：
* @如果手机支持屏幕翻转返回vm_graphic_screen_rotate_value中的一个值。
* @如果手机不支持屏幕翻转就会返回：VM_GRAPHIC_SCREEN_ROTATE_0
 */
vm_graphic_screen_rotate_value vm_graphic_get_current_rotate(void);


/**
 * 依赖sensor翻转屏幕，VRE接收到屏幕翻转消息会向应用回调函数发出屏幕已经可以进* 行翻转的消息，应用接收到这个回调函数。可以翻转手机屏幕到指定的角度也可以不翻  * 转屏幕。
 *
 * @param 为void(*f)( VMINT    message ,VMINT   rotate_value)，应用注册的回调函数，* @如果屏幕可以翻转就会通知应用可以翻转多少度，message是通知应用是否可以翻转，
* @rotate_value是可以翻转的角度。可以翻转的角度由手机本身决定。
 * @return 是否通知应用已经进行可以进行翻转的消息 ：
* @TRUE 已经通知到应用。
* @FALSE 没有通知到应用。
 
VMINT vm_graphic_reg_rotate_callback(void(*f)(VMINT   message ,VMINT   rotate_value));
*/

/*
临时接口 MP后需要删除,
为了模拟VRE 发 VM_MSG_SCREEN_ROTATE 消息  ,参数为 模拟VRE 建议应用翻转的角度
可以传入的参数建议为以下四种之一
VM_GRAPHIC_SCREEN_ROTATE_0
VM_GRAPHIC_SCREEN_ROTATE_90
VM_GRAPHIC_SCREEN_ROTATE_180
VM_GRAPHIC_SCREEN_ROTATE_270
否则
也发 VM_MSG_ROTATE	消息,不过 建议的翻转角度 为 
VM_GRAPHIC_SCREEN_ROTATE_0
*/
void vm_graphic_rotate_temp_ex(VMINT _rotate_value);




//===================================================================

#ifdef __cplusplus
}
#endif

#endif
