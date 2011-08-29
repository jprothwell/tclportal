#ifndef VMGRAPHIC_H_
#define VMGRAPHIC_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/* GDI return code */
typedef enum
{
	VM_GDI_ERR_BASE_LAYER_EXIST = -17,//���㻹����
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
    VM_GDI_GP_HOR = 0,  //ˮƽ
    VM_GDI_GP_VER,      //��ֱ
    VM_GDI_GP_DIA,      //б45��
    VM_GDI_GP_DIA_INV,  //����б45��
    VM_GDI_GP_FLIP      //�м���2�� 
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
 * RGB565������ɫֵ
 */
#define VM_COLOR_WHITE				    (0XFFFF)			//��
#define VM_COLOR_BLACK					(0X0000)			//��
#define VM_COLOR_RED					(0XF800)			//��
#define VM_COLOR_GREEN					(0X07E0)			//��
#define VM_COLOR_BLUE					(0X001F)			//��

/**
 * ���ø�����
 */
#define VM_RGB(r, g, b)					((b << 16) + (g << 8) + r)
#define VM_COLOR_INT_TO_565(i)			((i & 0xf8) << 8) + ((i & 0xfc00) >> 5) + ((i & 0xf80000) >> 19)
#define VM_COLOR_888_TO_565(r, g, b)	(((r & 0xf8) + ((g & 0xe0) >> 5)) << 8) + ((g & 0x1c) << 3) + (b >> 3)
#define VM_COLOR_565_TO_888(color16)	((color16 & 0x001F) << 19) + ((color16 & 0x07E0) << 5) + ((color16 & 0xF800) >> 8)
#define VM_COLOR_GET_RED(color16)		((color16 & 0xF800) >> 8)
#define VM_COLOR_GET_GREEN(color16)	    ((color16 & 0x07E0) >> 3)
#define VM_COLOR_GET_BLUE(color16)		((color16 & 0x001F) << 3)


	
typedef struct clip_rect{
	VMINT16 left;			/* �ü�����߽����꣨�ü����������������У� */	
	VMINT16 top;			/* �ü����ϱ߽����꣨�ü����������������У� */	
	VMINT16 right;			/* �ü����ұ߽����꣨�ü����������������У� */	
	VMINT16 bottom;			/* �ü����±߽����꣨�ü����������������У� */	
	VMBYTE	flag;			/* 0�òü�����Ч��1�òü�����Ч */
}clip_rect;

/**
 * IMG ��֡�ṹ��
 */
struct frame_prop 
{
	VMUINT8  flag;			/* ͼƬ��־λ */
	VMUINT16 left;			/* ͼƬ���Ͻ���ͼƬ�߼�������ƫ���� */
	VMUINT16 top;			/* ͼƬ���Ͻ���ͼƬ�߼�����ϲ�ƫ���� */
	VMUINT16 width;			/* ͼƬ�� */
	VMUINT16 height;			/* ͼƬ�� */
	VMUINT16 delay_time;	/* �ӳ٣��ڻ����굱ǰͼ���ĵȴ�ʱ��*/	
	VMUINT8  trans_color_index;	/* �����ֶ�*/	
	VMUINT16 trans_color;		/* ͸��ɫ*/	
	VMUINT32 offset;				/* ͼ�����ݿ��С*/	
};

typedef struct _vm_graphic_imgprop
{
	VMINT width;//ͼƬ��
	VMINT height;//ͼƬ��
}vm_graphic_imgprop;


typedef struct _vm_graphic_char_info
{
    VMINT dwidth;   //�ַ�adv_x
    VMINT width;    //�ַ�glyph_width
	VMINT height;   //�ַ�glyph_height
	VMINT ascent;   //�ַ�ascent
	VMINT descent;  //�ַ�descent
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
	VM_BASE_LAYER = 1,          //��������
	VM_FAST_LAYER ,             //�������ٲ�
	VM_BUF,                     //ʹ���ڴ洴����
	VM_CREATE_CANVAS            //��������ͬʱ������
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
	VMUINT vm_color_565;//565��ʽ����ɫ
	VMUINT vm_color_888;//888��ʽ����ɫ
}vm_graphic_color;



/*
example:
VMBYTE bitvalues[] = {1,1,1,0,0};
vm_graphic_pen pen;
pen.cycle = sizeof(bitvalues);
pen.bitvalues = bitvalues;
*/	
typedef struct _vm_graphic_pen{
	VMBYTE cycle;//�����߶εĳ���
	VMBYTE *bitvalues;//���ص���ʽ��ָ��һ���û��Զ��������.
}vm_graphic_pen;






/**
 * �����Ļ�Ŀ�ȡ�
 */
VMINT vm_graphic_get_screen_width(void);

/**
 * �����Ļ�ĸ߶ȡ�
 */
VMINT vm_graphic_get_screen_height(void);

/**
 * �����㡣
 * ���Ƕ���Ļ��ģ�⣬VRE֧�������㡣
 * VRE����ϵͳ���Ը����û��趨�ں����㡣
 * ��һ�㣨���㣩��Ӳ����Ļ��ȫ�غϣ�λ�ô�С��һ�¡�
 * �ڶ����û���������͸���ȵȲ�����������ָ��͸�����ںϡ�
 * ��������Ĳ��������޶���
 * �����޶�Ϊ:
 * 1)���Ͻ�����Ϊ(0,0),��x=0;y=0;
 * 2)����Ϊ��Ļ�Ŀ�ߡ�
 * �ο�����:
 * VMINT layer_hdl[2] = {0};			
 * layer_hdl[0] = vm_graphic_create_layer(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height(), VM_NO_TRANS_COLOR);	
 *
 * @param x				������Ļ�ϵ����Ͻ�X���ꡣ
 * @param y				������Ļ�ϵ����Ͻ�Y���ꡣ
 * @param width			��Ŀ�ȣ����ص�λ��
 * @param height 			��ĸ߶ȣ����ص�λ��
 * @param trans_color		��ı�����͸ɫ��-1��ʾ�޴�͸ɫ����������������Ļʱ
 *						����Ա�����͸ɫ�Բ�����͸Ч����
 *
 * @return				�ɹ����ش����Ĳ��������򷵻ش����롣
 */
VMINT vm_graphic_create_layer(VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color);

/**
 * ɾ���㲢�ͷŲ�����������Ļ��������Ӧ�ó��򴴽���֮�����Ҫ�Ѳ��ͷţ��ͷŲ��
 * ʱ��������Ӧ�ó����˳�֮ǰ��
 *
 * @param handle		��������vm_graphic_create_layer���ء�
 *
 * @return				����VM_GDI_SUCCEED��ʾ��ɾ���ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_graphic_delete_layer(VMINT handle);

/**
 * ����㡣��������ͼ������ڵĲ�ʱ��ϵͳ�����κβ�������ǰ����㲻�ᱻ�ı䡣
 * �����ɹ���ȫ�ֲü��������Ϊ��ǰ��Ĳü���
 *
 * @param handle		��vm_graphic_create_layer()���صĲ�����
 *
 * @return				����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */	
VMINT vm_graphic_active_layer(VMINT handle);

/**
 * ���ز����ʾ��������
 *
 * @param handle		������
 *
 * @return				����NULL��ʾȡ��ʾ������ʧ�ܣ����򷵻���ʾ������ָ�롣
 */	
VMUINT8* vm_graphic_get_layer_buffer (VMINT handle);

/**
 * ʹ�ñ���ɫ���������ݡ�
 *
 * @param handle		����������ɫ��vm_graphic_create_layer()���� ��trans_color�������롣��
 * 					 trans_color	������-1 ʱ���������е��ڱ���ɫ�Ĳ��ֶ�������͸����ʹ�á�
 *
 * @return				����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */	
VMINT vm_graphic_clear_layer_bg (VMINT handle);

/**
 * �Ѹ�����ϲ�Ϊһ���㲢ˢ�µ���Ļ�ϣ�Ӧ�ó��������������������ʵ����Ļ��
 * ���Ƹ��¡�
 *
 * @param layer_handles		������ָ�롣
 * @param count				��������±������ÿ�κϲ����Ƶ����֧�ֲ���ͨ��vm_graphic_get_blt_layer_count���
							���±곬�����֧�ֲ�������ֻˢ��������
 *
 * @return					����VM_GDI_SUCCEED��ʾ���Ƴɹ�������Ϊʧ�ܡ�
 */
VMINT vm_graphic_flush_layer(VMINT* layer_handles, VMINT count);

/**
 * ���Ŀ��ƽ̨֧�ֵ�������������Ϊ�˷���ͼ�λ��ƶ���Ƶ�Ӳ����Ӧ�ó�������ڲ�ͬ
 * �Ĳ��ϻ���ͼ�Σ�Ȼ����ϵͳ�Ѳ������һ�����������ͼ�񡣱����ֻ��Ĵ�������
 * ����������һ���㣬�������ź����͵ײ������ܼ����ֱ�Ϊ�����㣬���������ϵ�
 * ͼ������ǵ��ĸ��㣬���ź�״̬�ı�ʱӦ�ó���ֻ��Ҫ�ػ�һ���㣬ʹ��Ӳ�����
 * �Լӿ츴���û�����Ļ����ٶȡ�
 *
 * @return				����Ŀ��ƽ̨���������
 */
VMINT vm_graphic_get_layer_count(void);

/**
 * ��ò��λ�á�
 *
 * @param handle		������
 * @param x				�����Ͻ�X���ꡣ
 * @param y				�����Ͻ�Y���ꡣ
 * @param width			��Ŀ�ȡ�
 * @param height		��ĸ߶ȡ�
 *
 * @return				����VM_GDI_SUCCEED��ʾȡ�����óɹ�������Ϊʧ�ܡ�
 */
VMINT vm_graphic_get_layer_position(VMINT handle, VMINT *x, VMINT *y, VMINT *width, VMINT *height);

/**
 * ���ò��͸���ȡ�
 *
 * @param handle			������
 * @param percent			͸���ȣ���0��100������Խ���ʾ͸����Խ�͡�
 *
 * @return					����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_graphic_set_layer_opacity(VMINT handle, VMINT percent);

/**
 * ���Ŀ��ƽ̨��Ļ��������ʾһ���������õ��ֽ�����
 *
 * @return				��Ļ��������ʾһ���������õ��ֽ�����
 */
VMINT vm_graphic_get_bits_per_pixel(void);

/**
 * ��û�����(�Ի��򻭲�)��ָ�������ɫ��
 *
 * @param buf		Դ����
 * @param x			���X���ꡣ
 * @param y			���Y���ꡣ
 *
 * @return			�����ɫ��
 */
VMUINT16 vm_graphic_get_pixel(VMUINT8 *buf, VMINT x, VMINT y);

/**
 * ��Ŀ�껺����(�Ի��򻭲�)�ϻ��㡣
 *
 * @param buf	Դ���塣
 * @param x		���X���ꡣ
 * @param y		���Y���ꡣ
 * @param color	�����ɫ��
 */
void vm_graphic_set_pixel(VMUINT8 *buf, VMINT x,VMINT y, VMUINT16 color);

/**
 * ��Ŀ�껺����(�Ի��򻭲�)�ϻ��ߡ�
 *
 * @param buf	Ŀ�껺��
 * @param x0	������X���ꡣ
 * @param y0	������Y���ꡣ
 * @param x1	���յ��X���ꡣ
 * @param y1	���յ��Y���ꡣ
 * @param color	�ߵ���ɫ��
 */
void vm_graphic_line(VMUINT8 *buf, VMINT x0, VMINT y0, VMINT x1, VMINT y1, VMUINT16 color);

/**
 * ��Ŀ�껺������(�Ի��򻭲�)�����Ρ�
 *
 * @param buf		Ŀ�껺��
 * @param x			�������Ͻ�X���ꡣ
 * @param y			�������Ͻ�Y���ꡣ
 * @param width		���ο�ȡ�
 * @param height	���θ߶ȡ�
 * @param color		���α߿���ɫ��
 */
void vm_graphic_rect(VMUINT8 *buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color);

/**
 * ��Ŀ�껺������(�Ի��򻭲�)����������
 * 
 * @param buf		 Ŀ�껺��
 * @param x			 �������Ͻ�X���ꡣ
 * @param y			 �������Ͻ�Y���ꡣ
 * @param width		 ���εĿ�ȡ�
 * @param height	 ���εĸ߶ȡ�
 * @param line_color �߿���ɫ��
 * @param back_color �����ɫ��
 */
void vm_graphic_fill_rect(VMUINT8 *buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 line_color, VMUINT16 back_color);

/**
 * ����ʾ���������ƿ���Բ�Ǿ��Σ������������������ʾ�����������Ͻǣ���������Ļ�޹ء�
 * 
 * @param buf			Ŀ�껺��
 * @param x				�������Ͻ�X���ꡣ
 * @param y				�������Ͻ�Y���ꡣ
 * @param width			���ο�ȡ�
 * @param height		���θ߶ȡ�
 * @param corner_width	Բ�ǰ뾶��Բ�ǰ뾶���ó������ο�ȵ�һ�룬������������ʧ�ܡ�
 * @param color			�߿���ɫ��ʹ��565��ʽ��
 */
void vm_graphic_roundrect (VMUINT8 * buf, VMINT x, VMINT y, VMINT width, VMINT height, VMINT corner_width, VMUINT16 color);

/**
 * ����ʾ����������ʵ��Բ�Ǿ��Σ������������������ʾ�����������Ͻǣ���������Ļ�޹ء�
 * 
 * @param buf			Ŀ�껺��
 * @param x				�������Ͻ�X���ꡣ
 * @param y				�������Ͻ�Y���ꡣ
 * @param width			���ο�ȡ�
 * @param height		���θ߶ȡ�
 * @param corner_width	Բ�ǰ뾶��Բ�ǰ뾶���ó������ο�ȵ�һ�룬������������ʧ�ܡ�
 * @param color			�����ɫ��ʹ��565��ʽ��
 */
void vm_graphic_fill_roundrect (VMUINT8 * buf, VMINT x,	VMINT y, VMINT width, VMINT height, VMINT corner_width, VMUINT16 color);

/**
 * ����ʾ���������ƿ�����Բ�������������������ʾ�����������Ͻǣ���������Ļ�޹ء�
 * 
 * @param buf			Ŀ�껺��
 * @param x				��Բ���Ͻ�X���ꡣ
 * @param y				��Բ���Ͻ�Y���ꡣ
 * @param width			��Բ��ȡ�
 * @param height		��Բ�߶ȡ�
 * @param color			��Բ�߿���ɫ��ʹ��565��ʽ��
 */
void vm_graphic_ellipse (VMUINT8 * buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color);

/**
 * ����ʾ����������ʵ����Բ�������������������ʾ�����������Ͻǣ���������Ļ�޹ء�
 * 
 * @param buf			Ŀ�껺��
 * @param x				��Բ���Ͻ�X���ꡣ
 * @param y				��Բ���Ͻ�Y���ꡣ
 * @param width			��Բ��ȡ�
 * @param height		��Բ�߶ȡ�
 * @param color			��Բ�����ɫ��ʹ��565��ʽ��
 */
void vm_graphic_fill_ellipse (VMUINT8 * buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color);

/**
 * ����ָ����С�Ļ�����
 * 
 * @param width			������
 * @param height		�����ߡ�
 *
 * @return				�ɹ������½�������������򷵻ش����롣
 */
VMINT vm_graphic_create_canvas(VMINT width, VMINT height);

/**
 * �ͷ���vm_graphic_create_canvas��vm_graphic_load_image�����Ļ�����Դ��
 * 
 * @param hcanvas	���������
 */
void vm_graphic_release_canvas(VMINT hcanvas);

/**
 * ��û�������ʾ������ָ�롣
 * 
 * @param hcanvas		���������
 *
 * @return				���ػ�������ʾ������ָ�롣
 */							  
VMUINT8* vm_graphic_get_canvas_buffer(VMINT hcanvas);

/**
 * ��ͼ����н��룬������ͼ�񱻻��Ƶ��½��Ļ����ϡ�
 * 
 * @param img			ָ��ͼ�����ݵ��ڴ�ָ�룬���ͼ�����ݵ��ڴ���ʽ��ͼ���ļ���ʽ��ȫһ�¡�
 * @param img_len		ͼ���ڴ��ĳ��ȡ�
 *
 * @return				�ɹ������½�������������򷵻ش����롣
 */
VMINT vm_graphic_load_image(VMUINT8 *img, VMINT img_len);

/**
 * ��ȡͼ��֡���ԡ�
 *
 * @param hcanvas		ָ����vm_graphic_load_image()�õ��Ļ��������
 * @param frame_index	ͼ��֡��,֡�Ŵ�1��ʼ,��һ֡֡��Ϊ1��
 *
 * @return				ͼ�����Խṹ��ָ�롣
 */
struct frame_prop * vm_graphic_get_img_property(VMINT hcanvas, VMUINT8 frame_index);

/**
 * ��ȡͼ���֡��Ŀ��
 *
 * @param hcanvas		ָ����vm_graphic_load_image()�õ���ͼ�󻭲���
 *
 * @return				ͼ���֡��Ŀ��
 */
VMINT vm_graphic_get_frame_number(VMINT hcanvas);

/**
 * ��Դ��ʾ�����������ݿ�����Ŀ����ʾ�������ϣ�����ʹ����λ���ƣ�����������
 * �ں����㡣�����������ʾ��������������Ļ����ʾ��������Ҳ�����ǻ�������ʾ
 * ��������
 *
 * @param dst_disp_buf		Ŀ����ʾ������ָ�롣
 * @param x_dest			Ŀ���ͼ��������ϵ�X����
 * @param y_dest			Ŀ���ͼ��������ϵ�Y����
 * @param src_disp_buf		Դ��ʾ������ָ�롣
 * @param x_src				Դ��ͼ��������ϵ�X����
 * @param y_src				Դ��ͼ��������ϵ�Y����
 * @param width				Ŀ���ͼ����Ŀ�
 * @param height			Ŀ���ͼ����ĸ�
 * @param frame_index		ͼ��֡��֡�ţ�֡�Ŵ�1��ʼ��š�
 */
void vm_graphic_blt(VMBYTE * dst_disp_buf, VMINT x_dest, VMINT y_dest, VMBYTE * src_disp_buf, 
					 VMINT x_src, VMINT y_src, VMINT width, VMINT height, VMINT frame_index);

/**
 * ��Դ��ʾ�����������ݿ�����Ŀ����ʾ�������ϣ�����ʹ����λ���ƣ���ָ��alpha
 * ֵ���������ں����㡣�����������ʾ��������������Ļ����ʾ��������Ҳ������
 * ��������ʾ��������
 *
 * @param dst_disp_buf		Ŀ����ʾ������ָ�롣
 * @param x_dest			Ŀ���ͼ��������ϵ�X����
 * @param y_dest			Ŀ���ͼ��������ϵ�Y����
 * @param src_disp_buf		Դ��ʾ������ָ�롣
 * @param x_src				Դ��ͼ��������ϵ�X����
 * @param y_src				Դ��ͼ��������ϵ�Y����
 * @param width				Ŀ���ͼ����Ŀ�
 * @param height			Ŀ���ͼ����ĸ�
 * @param frame_index		ͼ��֡��֡�ţ�֡�Ŵ�1��ʼ��š�
 * @param alpha				͸���ȣ���0��255������Խ���ʾ͸����Խ�͡�
 */
void vm_graphic_blt_ex(VMBYTE * dst_disp_buf, VMINT x_dest, VMINT y_dest, VMBYTE * src_disp_buf, 
						VMINT x_src, VMINT y_src, VMINT width, VMINT height, VMINT frame_index, VMINT alpha);
					 
/**
 * �õ���ǰ�����ֿ���ָ߶ȡ�
 *
 * @return		�ֵĸ߶ȣ�������Ϊ��λ��
 */
VMINT vm_graphic_get_character_height(void);

/**
 * �õ��ַ���ȡ�
 *
 * @param c		UCS2��ʽ������ַ���
 * 
 * @return		�ַ���ȣ�������Ϊ��λ��
 */
VMINT vm_graphic_get_character_width(VMWCHAR c);

/**
 * ��ø����ִ����ȣ�������Ϊ��λ��
 *
 * @param str		UCS2�����ʽ���ַ�����
 *
 * @return			�ɹ������ַ�����ȣ�������Ϊ��λ�����򷵻ش�����
 */
VMINT vm_graphic_get_string_width(VMWSTR str);


/**
 * ��ø����ִ��߶ȣ�������Ϊ��λ��
 *
 * @param str		UCS2�����ʽ���ַ�����
 *
 * @return			�ɹ������ַ����߶ȣ�������Ϊ��λ�����򷵻ش�����
 */
VMINT vm_graphic_get_string_height(VMWSTR str);



/**
 * ��ø����ַ��ĸ߶ȺͿ�ȣ�������Ϊ��λ��
 *
 * @param c			UCS2�����ʽ���ַ���
 * @param width		�ַ���ȣ�������Ϊ��λ��
 * @param height	�ַ��߶ȣ�������Ϊ��λ��
 *
 * @return			����VM_GDI_SUCCEED��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_graphic_measure_character(VMWCHAR c, VMINT *width, VMINT *height);



/**
 * ��ø����ַ�����Ϣ��
 *
 * @param c			UCS2�����ʽ���ַ���
 * @param char_info		�ַ���Ϣ��
 *
 * @return			����VM_GDI_SUCCEED��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_graphic_get_character_info(VMWCHAR c, vm_graphic_char_info *char_info);

/**
 * �������壬�ֻ���ʹ�õĶ��ǵ����ֿ⣬���ֻ�������������С���޷�������
 * �͡���Ŀ���ֻ��һ�������ֿ�ʱ��������������Ч��
 *
 * @param size		����ߴ硣
 */
void vm_graphic_set_font(font_size_t size);

/**
* ����ʾ�������������֣����ֵĳߴ���vm_graphic_set_font()������Ĭ�����к����塣
 *
 * @param disp_buf		��ʾ������ָ�롣
 * @param x				���������ֵ����ϽǺ����ꡣ
 * @param y				���������ֵ����Ͻ������ꡣ
 * @param s				�����Ƶ��ַ�����
 * @param length		�����Ƶ��ַ������ȡ�
 * @param color			������ɫ��ʹ��565��ʽ��
 */
void vm_graphic_textout (VMUINT8* disp_buf, VMINT x, VMINT y, VMWSTR s, VMINT length, VMUINT16 color);

/**
 * ���þ��εĲü����򣬻�ͼʱ���ڲü����������ͼ�񶼻ᱻ�ü���
 * VRE�ļ�����Ϊһ��ȫ�ּ���������Ŀ������������ʱ��Ҫ�������ü�������
 * ���磬���򴴽���һ����(��Ļ��С)��һ������(200*200).
 * ԭ�Ȼ���Ŀ������Ϊ��һ�㣬��������Ļ��С�ļ�����.
 * ��ʱ�������Ƶ�Ŀ���������������ϻ��ơ���ʱ��������Ի������ü�������
 * 
 *
 * @param x1				x1 �ü���������ϽǺ����꣬������Ļ���Ͻ�Ϊԭ���ֱ������ϵ��
 * @param y1				y1 �ü���������Ͻ������ꡣ
 * @param x2				x2 �ü���������½Ǻ����ꡣ
 * @param y2				y2 �ü���������½������ꡣ
 */
void vm_graphic_set_clip(VMINT x1, VMINT y1, VMINT x2, VMINT y2);

/**
 * �ͷŲü�����,��Ļ�ɻ�����ָ���ȫ����С��
 */
void vm_graphic_reset_clip(void);

/**
 * �����ػ���Ļϵͳ��Ϣ������������ú�ϵͳ����ͨ��vm_reg_sysevt_callback()
 * ע���ϵͳ�¼�������������VM_PAINT��Ϣ��Ӧ�ó������ͨ�������������ϵ
 * ͳ�ػ���Ϣ��
 */
void vm_graphic_flush_screen(void);

/**
 * ��ת�Ƕ�
 */
#define VM_ROTATE_DEGREE_90				    (90)
#define VM_ROTATE_DEGREE_180				(180)
#define VM_ROTATE_DEGREE_270				(270)
/**
 * �ӻ����л�ȡ��֡ͼ���������Ϣ�󣬰�ָ������ת�ǶȻ��Ƶ�Ŀ������(�Ի��򻭲�)
 *
 * @param buf				Ŀ�껺��
 * @param x_des             Ŀ�����ϵ�X����
 * @param y_des             Ŀ�����ϵ�Y����
 * @param src_buf			Դ����
 * @param frame_index 		֡��
 * @param degrees			˳ʱ����ת�Ƕȣ�
 *                                              ��ֻ֧��VM_ROTATE_DEGREE_90��VM_ROTATE_DEGREE_180��VM_ROTATE_DEGREE_270�������Ƕȡ�
 *                                              ��������ֵ���������Ʋ�����
 */
void vm_graphic_rotate(VMBYTE *buf, VMINT x_des, VMINT y_des, 
						VMBYTE *src_buf, VMINT frame_index, VMINT degrees);


/*
��ʱ�ӿ� ,Ϊ��ģ��VRE �� VM_MSG_ROTATE ��Ϣ  ,����Ϊ ģ��VRE ����Ӧ�÷�ת�ĽǶ�
���Դ���Ĳ�������Ϊ��������֮һ
VM_GRAPHIC_SCREEN_ROTATE_0
VM_GRAPHIC_SCREEN_ROTATE_90
VM_GRAPHIC_SCREEN_ROTATE_180
VM_GRAPHIC_SCREEN_ROTATE_270
����
Ҳ�� VM_MSG_ROTATE	��Ϣ,���� ����ķ�ת�Ƕ� Ϊ 
VM_GRAPHIC_SCREEN_ROTATE_0

void vm_graphic_rotate_temp(VMINT _rotate_value);
*/


/**
 * ������
 */
#define VM_MIRROR_X							(0)
#define VM_MIRROR_Y							(1)
/**
 * �ӻ����л�ȡ��֡ͼ���������Ϣ�󣬰�ָ���ľ��������ͼƬ
 *
 * @param buf               Ŀ�껺��(�Ի��򻭲�)
 * @param x_des				Ŀ���ͼ��������ϵ�X����
 * @param y_des				Ŀ���ͼ��������ϵ�Y����
 * @param src_buf			Դ����
 * @param frame_index		ͼ��֡��֡�ţ�֡�Ŵ�1��ʼ����
 * @param direction         ������֧�ִ�ֱ��ˮƽ��������VM_MIRROR_X��ʾ��x����,VM_MIRROR_Y��y����
 *                                  ��������ֵ���������Ʋ�����
 */
void vm_graphic_mirror(VMBYTE *buf, VMINT x_des, VMINT y_des, VMBYTE *src_buf, VMINT frame_index, VMINT direction);

/**
 * vm_reg_res_provider()��������ע��Ӧ�ó������Դӳ�亯����
 * ����Դ��������ʽ�����ڳ�����ʱ���������ͨ����Դӳ�亯����������һ��������ID��Ӧ��
 * �����п���ͨ��ID��������Դ��
 *
 * @param fp		Ӧ�ó����ṩ����Դӳ�亯��ָ�롣
 */
void vm_reg_res_provider(VMUINT8* (*fp)(VMINT resid, VMINT* len));

/*
 *	����ģʽ������
 *	�ڴ���������ǰ�������ȴ������㡣

 *
 *	@param x				������Ļ�ϵ����Ͻ�X���ꡣ
 *	@param y				������Ļ�ϵ����Ͻ�Y���ꡣ
 *	@param width				��Ŀ�ȣ����ص�λ��
 *	@param height 			��ĸ߶ȣ����ص�λ��
 *	@param trans_color		��ı�����͸ɫ��-1��ʾ�޴�͸ɫ����������������Ļʱ
 *							����Ա�����͸ɫ�Բ�����͸Ч����
 *	@param mode				����ģʽ
 *							VM_BASE_LAYER:
 *							����������Ϣ�����Ѿ�����������Ĳ���������ǰһ�εĲ�����
 *							VM_FAST_LAYER:
 *							����һ�����ٲ㣬�����ٶȸ��죬����ȫ��ֻ�ܴ���һ����
 *							����Ѿ��������򷵻ظò�handle��ͬʱ����ԭ�в�����
 *							VM_BUF:
 *							ʹ��Canvas��buf�����²㣬��ʱ�β�buf��Ч����buf��������vm_create_canvas�����Ļ������档
 *							����֮��û������²㽫��ӳ�䡣
 *							�ٴ���ͬһ��buf�����㽫���ش���
 *							VM_CREATE_CANVAS:
 *							����һ�黭����ͬʱʹ���»������洴���²㡣
 *							����֮�󻭲��Ͳ㽫��ӳ�䡣
 *	@param buf				��ʹ��VM_BUFģʽ������ʱ,�½�������Ҫ�Ļ�������ͷָ�롣
 * @return				�ɹ����ش����Ĳ��������򷵻ش����롣
 */
VM_GDI_HANDLE vm_graphic_create_layer_ex(VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color,VMINT mode,VMUINT8 * buf);


/**
 * �ͷ�һ�黭��,��������ĳһ�����Ӧ����ʹ�øû������洴���˲㣬��ô��ͬʱɾ���ò㡣
 *
 * @param hcanvas			���������

 *
 * @return					����VM_GDI_SUCCEED��ʾɾ���ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT  vm_graphic_release_canvas_ex(VMINT hcanvas);


/**
 * �����黭������ϲ����Ƶ���ǰ���ϣ�ͬʱ�ͷ��⼸�黭����ӳ��Ĳ㡣
 * ���ӳ���Ϊ��ǰ�㣬���ͷŸû�����ӳ��㡣
 * ������������ĳһ������ӳ�䣬����û��������ϲ���
 * ÿ�κϲ����Ƶ����֧�ֲ���Ϊ4
 *
 *
 * @param hcanvas			�����������ָ�롣
 * @param count				�ϲ���������
 *
 * @return					����VM_GDI_SUCCEED��ʾ�ϲ��ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT  vm_graphic_flatten_canvas(VMINT *hcanvas,VMINT count);


/**
 * ��������ϲ����Ƶ���ǰ���ϣ�ͬʱ�ͷ��⼸���㡣��ǰ�㲻���ͷš�
 * ÿ�κϲ����Ƶ����֧�ֲ���Ϊ4
 *
 *
 * @param hhandle			��������ָ�롣
 * @param count				�ϲ�������
 *
 * @return					����VM_GDI_SUCCEED��ʾ�ϲ��ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_flatten_layer(VMINT *hhandle,VMINT count);

/**
 * �����Ĵ�С������֮����Ҫ�ػ����е����ݡ�
 * �µĿ�߲��ܴ���ԭ�еĿ�ߡ�
 *
 * @param width			�µĿ�ȡ�
 * @param height		�µĸ߶ȡ�
 *
 * @return				����VM_GDI_SUCCEED��ʾresize�ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT  vm_graphic_resize_layer(VMINT handle,VMINT width,VMINT height);

/**
 * ���û��ʡ�
 *
 * @param pen		��ɫָ�롣
 *
 * @return				����VM_GDI_SUCCEED��ʾ���óɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_setpen(vm_graphic_pen *pen);

/**
 * ��ȡ���ʡ�
 *
 *
 * @return				���ػ��ʡ�
 */
vm_graphic_pen  vm_graphic_getpen(void);


/**
 * ����ȫ����ɫ��
 *
 * @param color		��ɫָ�롣
 *
 * @return				����VM_GDI_SUCCEED��ʾ���óɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_setcolor(vm_graphic_color* color);


/**
 * ��ȡȫ����ɫ��
 *
 *
 * @return				������ɫ��
 */
vm_graphic_color vm_graphic_getcolor(void);

/**
 * �ڲ��ϻ���
 *
 * @param handle		������
 * @param x1			���X���ꡣ
 * @param y1			���Y���ꡣ
 */
void vm_graphic_set_pixel_ex(VMINT handle,VMINT x1,VMINT y1);


/**
 * �ڲ��ϻ�ʵ�ߡ���ʹ�û��ʡ�
 *
 * @param handle		������
 * @param x1			������X���ꡣ
 * @param y1			������Y���ꡣ
 * @param x2			���յ��X���ꡣ
 * @param y2			���յ��Y���ꡣ
 */
void vm_graphic_line_ex(VMINT handle,VMINT x1,VMINT y1,VMINT x2,VMINT y2);


/**
 * ʹ�û����ڲ��ϻ��ߡ�ͨ��vm_graphic_set_pen���û��ʷ��֮����øú�����
 * �����δ����vm_graphic_set_pen���û��ʣ��򲻻���ơ�
 * 
 * @param handle		������
 * @param x1			������X���ꡣ
 * @param y1			������Y���ꡣ
 * @param x2			���յ��X���ꡣ
 * @param y2			���յ��Y���ꡣ
 */
void vm_graphic_line_style(VMINT handle,VMINT x1,VMINT y1,VMINT x2,VMINT y2);

/**
 * ����ϻ��ƿ���Բ�Ǿ��Σ������������������ʾ�����������Ͻǣ���������Ļ�޹ء�
 * 
 * @param handle			������
 * @param x				�������Ͻ�X���ꡣ
 * @param y				�������Ͻ�Y���ꡣ
 * @param width			���ο�ȡ�
 * @param height			���θ߶ȡ�
 * @param frame_width		Բ�ǰ뾶��Բ�ǰ뾶���ó������ο�ȵ�һ�룬������������ʧ�ܡ�
 */
void vm_graphic_roundrect_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height, VMINT frame_width);

/**
 * �ڲ��ϻ����Ρ�
 *
 * @param handle		������
 * @param x			�������Ͻ�X���ꡣ
 * @param y			�������Ͻ�Y���ꡣ
 * @param width		���ο�ȡ�
 * @param height		���θ߶ȡ�
 */
void vm_graphic_rect_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height);

/**
 * �ڲ��ϻ��ƿ�����Բ����������������ڲ�����Ͻǡ�
 * 
 * @param handle			������
 * @param x				��Բ���Ͻ�X���ꡣ
 * @param y				��Բ���Ͻ�Y���ꡣ
 * @param width			��Բ��ȡ�
 * @param height			��Բ�߶ȡ�
 */
void vm_graphic_ellipse_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height);


/**
 * �ڲ��ϻ��ƿ��Ķ����
 * 
 * @param handle			������
 * @param point			���������顣
 * @param npoint		���������
 */
void vm_graphic_polygon(VMINT handle, vm_graphic_point *point,VMINT npoint);

/**
 * ����ϻ���ʵ��Բ�Ǿ��Σ������������������ʾ�����������Ͻǣ���������Ļ�޹ء�
 * 
 * @param handle			������
 * @param x				�������Ͻ�X���ꡣ
 * @param y				�������Ͻ�Y���ꡣ
 * @param width			���ο�ȡ�
 * @param height			���θ߶ȡ�
 * @param frame_width		Բ�ǰ뾶��Բ�ǰ뾶���ó������ο�ȵ�һ�룬������������ʧ�ܡ�
 */
void vm_graphic_fill_roundrect_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height, VMINT  frame_width);

/**
 * �ڲ��ϻ�ʵ�ľ��Ρ�
 *
 * @param handle		������
 * @param x			�������Ͻ�X���ꡣ
 * @param y			�������Ͻ�Y���ꡣ
 * @param width		���ο�ȡ�
 * @param height		���θ߶ȡ�
 */
void vm_graphic_fill_rect_ex(VMINT handle, VMINT  x, VMINT  y, VMINT  width, VMINT  height);


/**
 * ����ʾ����������ʵ����Բ����������������ڲ�����Ͻǡ�
 * 
 * @param handle			������
 * @param x				��Բ���Ͻ�X���ꡣ
 * @param y				��Բ���Ͻ�Y���ꡣ
 * @param width			��Բ��ȡ�
 * @param height			��Բ�߶ȡ�
 */
void vm_graphic_fill_ellipse_ex(VMINT handle, VMINT  x, VMINT  y, VMINT  width, VMINT  height);


/**
 * �ڲ��ϻ���ʵ�Ķ����
 * 
 * @param handle			������
 * @param point			���������顣
 * @param npoints				���������
 */
void vm_graphic_fill_polygon(VMINT handle, vm_graphic_point *point,VMINT npoints);





/**
 *����ɫ����һ���������
 *
 * @param handle 		������
 * @param x1 		�����������Ͻǵ�x���ꡣ
 * @param y1 		�����������Ͻǵ�y���ꡣ
 * @param x2 		�����������½ǵ�x���ꡣ
 * @param y2 		�����������½ǵ�y���ꡣ
 * @param color_start		����ɫ����ʼ��ɫ��
 * @param color_end		����ɫ�Ľ�����ɫ��
 * @param style			���Ʒ��
 *
 */
void vm_graphic_gradient_paint_rect(VMINT handle, VMINT x1, VMINT y1, VMINT x2, VMINT y2, vm_graphic_color color_start, vm_graphic_color color_end,vm_graphic_gp_style style);



/**
 * ��ȡ��Ĳü�����
 *
 * @param handle 		    Ҫ��ȡ�Ĳ�����
 * @param curcliprect 		��ȡ�Ĳü�����
 *
 * @return				����VM_GDI_SUCCEED��ʾ��ȡ�ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_get_layer_clip(VMINT handle,clip_rect * curcliprect);


/**
 *���ò�Ĳü�������handleΪ��ǰ��ʱ�����øýӿڣ���Ӱ��ȫ�ֲü�����
 *
 * @param handle 	Ҫ���õĲ�����
 * @param x1 		�ü������Ͻǵ�x���ꡣ
 * @param y1 		�ü������Ͻǵ�y���ꡣ
 * @param x2 		�ü������½ǵ�x���ꡣ
 * @param y2 		�ü������½ǵ�y���ꡣ
 *
 * @return				����VM_GDI_SUCCEED��ʾ���óɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_set_layer_clip(VMINT handle,VMINT16 x1,VMINT16 y1,VMINT16 x2,VMINT16 y2);

/**
 * ƽ��һ���㡣
 *
 * @param handle			ƽ�ƵĲ�����
 * @param tx				�²����Ͻǵ�x���꣬�����(0,0)��
 * @param ty				�²����Ͻǵ�y���꣬�����(0,0)��
 *
 * @return				����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_translate_layer(VMINT handle , VMINT tx, VMINT ty);


/**
 * ��תһ���㡣
 *
 * @param handle			��ת�Ĳ�����
 * @param rotatevalue		��ת�ĽǶȡ�Ŀǰֻ֧��0,90,180,270�ȡ��磺����ת��90�ȣ���Ҫ����ת90�ȣ�rotatevalue = VM_GDI_ROTATE_180.
 *
 * @return				����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_rotate_layer(VMINT handle, vm_graphic_rotate_value rotatevalue);


/**
 * ����һ��ͼƬ��ָ����С��
 *
 * @param img_data		ͼƬ����ָ�롣
 * @param img_len			ͼƬ���ݴ�С��
 * @param width			ͼƬ���¿�ȡ�
 * @param height			ͼƬ���¸߶ȡ�
 *
 * @return				�ɹ������½�������������򷵻ش����롣
 */
VMINT vm_graphic_load_image_resized(VMUINT8 *img_data, VMINT img_len,VMINT width,VMINT height);

/**
 * �����Ŵ�GIFͼƬ��ֻ�ܷŴ�������ֻ֧��GIF�ļ���
 *
 * @param img_data		ͼƬ����ָ�롣
 * @param img_len			ͼƬ���ݴ�С��
 * @param percent		�Ŵ�����
 *
 * @return				�ɹ������½�������������򷵻ش����롣
 */
VMINT vm_graphic_load_gif_resized_by_percent(VMUINT8 *img_data, VMINT img_len,VMINT percent);

/**
 * ��ȡͼƬ���ԡ����ں�̨ʹ�á�
 *
 * @param img_data		ͼƬ����ָ�롣
 * @param img_len			ͼƬ���ݴ�С��
 * @param img_prop		���Խṹ��ָ�롣	
 *
 * @return				����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */
//VM_GDI_RESULT vm_graphic_get_img_property_ex(VMUINT8 *img_data, VMINT img_len,vm_graphic_imgprop * img_prop);


/**
 * ��ȡ���Ƶ��������������֧�ֲ�����ͬ��
 * ���֧�ֲ���ָ�ܹ��ܹ������Ĳ�����ͨ�� vm_graphic_get_layer_count()��ȡ��
 *
 * @return			���Ƶ���������
 *
 */
VMINT vm_graphic_get_blt_layer_count(void);


/**
 * ���������С��
 * �Ƽ�ʹ��font_size_t����Ĵ���С���塣
 * ���ֱ��ʹ�����֣�����δʹ��ʸ�������ʹ��ʸ������Ļ���֮����ֲʱ�����ܻ������ʾ��һ�¡�
 * @param size		�����С��
 *
 * @return				����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_font_set_font_size(VMINT size);

/**
 *����������ֻ��ʸ��������Ч��
 * @param bold			�Ƿ�Ӵ֣�TRUE��ʾ�Ӵ֣�FALSE���Ӵ֡�
 * @param italic			�Ƿ���б��TRUE��ʾ��б��FALSE����б��
 * @param underline		�Ƿ����»��ߣ�TRUE��ʾ���»��ߣ�FALSE���»��ߡ�
 * 
 * @return				����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_font_set_font_style(VMINT bold,VMINT italic,VMINT underline);



/*
 *�ڲ��ϻ������֡�
 * @param handle			������
 * @param x				�������ֵ����ϽǺ����ꡣ
 * @param y				�������ֵ����Ͻ������ꡣ
 * @param s				���Ƶ��ַ�����
 * @param length			���Ƶ��ַ������ȡ�
 * 
 * @return				����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_textout_to_layer (VMINT handle, VMINT x, VMINT y, VMWSTR s, VMINT length);

/*
 *���û����Ĵ�͸ɫ��(ʹ��vm_graphic_blt_ex()ʱ�ô�͸ɫ��Ч)
 *��������һ������ӳ��ʱ�����ͬ���޸Ĳ�Ĵ�͸ɫ���á�
 * @param hcanvas			VRE���������
 * @param trans_color			��͸ɫ,-1��ʾ�޴�͸ɫ��
 * 
 * @return					����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_canvas_set_trans_color(VMINT hcanvas, VMINT trans_color);


/*
 *���ò�Ĵ�͸ɫ��
 * @param hhandle			������
 * @param trans_color			��͸ɫ,-1��ʾ�޴�͸ɫ��
 * 
 * @return					����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
 */
VM_GDI_RESULT vm_graphic_layer_set_trans_color(VMINT hhandle, VMINT trans_color);

/*
 * ��ǰƽ̨�Ƿ�֧��ʸ�����塣
 * 
 * @return					����TRUE��ʾ֧�֣�����Ϊ��֧�֡�
 */
VMINT vm_graphic_is_use_vector_font(void);


/*
 *���ݵ���������Ƶ����ַ���
 * @param handle		����
 * @param x				�������ֵ����ϽǺ����ꡣ
 * @param y				�������ֵ����Ͻ������ꡣ
 * @param color			������ɫ
 * @param font_data		��������
 * @param font_width		�ַ����
 * @param font_height		�ַ��߶� 
 * 
 * @return				����VM_GDI_SUCCEED��ʾ�����ɹ�������Ϊʧ�ܡ�
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
 * ��ת��Ļ��ָ���ĽǶȡ�
 *
 * @param  rotate	vm_graphic_screen_rotate_valueö���е�һ��ֵ���ڵ�ȡֵ*@��Χ���Բ鿴vm_graphic_screen_rotate_value���塣
*
 * @return		���ط�ת��Ļ�Ĳ������ ��
* @����ֻ�֧����Ļ��ת �ɹ����� VM_GDI_SUCCEED��
* @ʧ�ܷ��أ�VM_GDI_ERR_WRONG_PARAM
* @����ֻ���֧����Ļ��ת�ͻ᷵�أ�VM_GDI_ERR_NOT_SUPPORT_ROTATE
 */ 
VMINT vm_graphic_screen_rotate(vm_graphic_screen_rotate_value rotate);

/**
 * ���÷�ת�����Ļ������Ļ��ԭ����ģʽ��ʾ��2010-7-14 ������ɾ���������
 *
 * @param ΪNULL*
 * @return		�������÷�ת��Ļ�Ĳ������ ��
* @����ֻ�֧����Ļ��ת �ɹ����� VM_GDI_SUCCEED��
* @����ֻ���֧����Ļ��ת�ͻ᷵�أ�VM_GDI_ERR_NOT_SUPPORT_ROTATE
 

VMINT vm_graphic_reset_screen_rotate(void);*/ 

/**
 * �����Ļ��ת��Ķ�����
 *
 * @param ΪNULL*
 * @return		�����Ļ��ת��Ķ����Ĳ������ ��
* @����ֻ�֧����Ļ��ת����vm_graphic_screen_rotate_value�е�һ��ֵ��
* @����ֻ���֧����Ļ��ת�ͻ᷵�أ�VM_GRAPHIC_SCREEN_ROTATE_0
 */
vm_graphic_screen_rotate_value vm_graphic_get_current_rotate(void);


/**
 * ����sensor��ת��Ļ��VRE���յ���Ļ��ת��Ϣ����Ӧ�ûص�����������Ļ�Ѿ����Խ�* �з�ת����Ϣ��Ӧ�ý��յ�����ص����������Է�ת�ֻ���Ļ��ָ���ĽǶ�Ҳ���Բ���  * ת��Ļ��
 *
 * @param Ϊvoid(*f)( VMINT    message ,VMINT   rotate_value)��Ӧ��ע��Ļص�������* @�����Ļ���Է�ת�ͻ�֪ͨӦ�ÿ��Է�ת���ٶȣ�message��֪ͨӦ���Ƿ���Է�ת��
* @rotate_value�ǿ��Է�ת�ĽǶȡ����Է�ת�ĽǶ����ֻ����������
 * @return �Ƿ�֪ͨӦ���Ѿ����п��Խ��з�ת����Ϣ ��
* @TRUE �Ѿ�֪ͨ��Ӧ�á�
* @FALSE û��֪ͨ��Ӧ�á�
 
VMINT vm_graphic_reg_rotate_callback(void(*f)(VMINT   message ,VMINT   rotate_value));
*/

/*
��ʱ�ӿ� MP����Ҫɾ��,
Ϊ��ģ��VRE �� VM_MSG_SCREEN_ROTATE ��Ϣ  ,����Ϊ ģ��VRE ����Ӧ�÷�ת�ĽǶ�
���Դ���Ĳ�������Ϊ��������֮һ
VM_GRAPHIC_SCREEN_ROTATE_0
VM_GRAPHIC_SCREEN_ROTATE_90
VM_GRAPHIC_SCREEN_ROTATE_180
VM_GRAPHIC_SCREEN_ROTATE_270
����
Ҳ�� VM_MSG_ROTATE	��Ϣ,���� ����ķ�ת�Ƕ� Ϊ 
VM_GRAPHIC_SCREEN_ROTATE_0
*/
void vm_graphic_rotate_temp_ex(VMINT _rotate_value);




//===================================================================

#ifdef __cplusplus
}
#endif

#endif
