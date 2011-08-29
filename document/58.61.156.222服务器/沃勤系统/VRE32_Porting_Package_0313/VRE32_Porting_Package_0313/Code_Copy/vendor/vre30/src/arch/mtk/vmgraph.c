#ifdef __VRE__
#include "mmi_include.h"
#include "vmmacrostub.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmlog.h"
#include "vmstdlib.h"
#include "vmopt.h"
#include "string.h"
#include "math.h"
#include "vmsys.h"
#include "vmio.h"
#include "vmmod.h"
#include "vmresmng.h"
#include "vmpromng.h"

#include "vmcert.h" 	//��� Ϊ�� ����Ļ��ת֧�� ����Ļ��������Ļ
/* ------------------------------------------------------------------------- */
/* Define And Typedef                                             							*/
/* ------------------------------------------------------------------------- */
//#define VM_USE_VRE_GIF_SOFT_DECODE       f           //GIF ���뷽ʽ

#ifndef VM_CANVAS_FRAME_NUM_OFFSET
#define VM_CANVAS_FRAME_NUM_OFFSET            (9)    //����֡��ƫ����
#endif

#ifndef VM_CANVAS_SIGNATURE_SIZE
#define VM_CANVAS_SIGNATURE_SIZE            (12)    //����ǩ�����С
#endif

#ifndef VM_CANVAS_FRAME_PROPERTY_SIZE
#define VM_CANVAS_FRAME_PROPERTY_SIZE       (20)    //������֡�������С
#endif

/*
 *	VRE KEY COLOR
 */
#define  VM_KEY_COLOR						(0XFFFD)

#define  VM_FONT_ATTR_BOLD					0x00000002
#define  VM_FONT_ATTR_ITALIC				0x00000004
#define  VM_FONT_ATTR_OBLIQUE				0x00000008
#define  VM_FONT_ATTR_UNDERLINE			    0x00000010

#define VM_FONT_TEST_BASELINE_STRING    "AbcdEfgHij��1234!..,;'?@"

//#define INVALID_VRE_HANDLE(handle)  (((handle) < 0) || ((handle) >= MAX_LAYER) ||( !(layer_trans_tbl[(handle)].used)))
//#define VALID_VRE_HANDLE(handle)  (((handle) >= 0) && ((handle) < MAX_LAYER) && (layer_trans_tbl[(handle)].used))
#define SAL_HANDLE(VREHANDLE)  (layer_trans_tbl[(VREHANDLE)].handle)

/*�жϲ����Ƿ����ڸý���
#define HANDLE_BELONG_TO_CUR_PROCESS(handle) (((vm_res_get_process_handle(VM_RES_TYPE_LAYER_HANDLE,layer_trans_tbl[handle].mibrhandle)) \
												==  (vm_pmng_get_current_handle()))  \
												&& (vm_pmng_get_current_handle() != 0))
*/

#define MAX_PROCESS 16
#define VRE_LIMIT_VALUE(POS, MIN_VALUE, MAX_VALUE) \
   do{                                         \
      if((POS) < (MIN_VALUE))                      \
         (POS) = (MIN_VALUE);                      \
      else if((POS) > (MAX_VALUE))                 \
         (POS) = (MAX_VALUE);                      \
   }while(0)


#define VM_GRAPHIC_LAYER_FLAG_USED                          (1<<0)
#define VM_GRAPHIC_LAYER_FLAG_USE_OUTSIDE_MEMORY            (1<<1)
#define VM_GRAPHIC_LAYER_FLAG_ALLDELETE                     (1<<2)


#define VM_GRAPHIC_LAYER_CLEAR_FLAG(HANDLE,FLAG)          (layer_trans_tbl[(HANDLE)].flag &= ~(FLAG))
#define VM_GRAPHIC_LAYER_SET_FLAG(HANDLE,FLAG)            (layer_trans_tbl[(HANDLE)].flag |= (FLAG))
#define VM_GRAPHIC_LAYER_GET_FLAG(HANDLE,FLAG)            (layer_trans_tbl[(HANDLE)].flag &(FLAG))

#define VM_GRAPHIC_CHECK_MODULE_STATE \
    do{\
        if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)\
        { \
            vm_log_error("[graphic] - : background!!");\
            return VM_GDI_MIBR_NOT_FORE;\
        }\
    }while(0)



typedef struct
{
	VM_P_HANDLE phandle;
	VMINT mibrhandle;
}vm_graphic_mibr_node;


typedef struct _vm_canvas_list {
	VMBYTE * canvasbuf; 
	struct _vm_canvas_list *next;
}vm_canvas_list;

typedef struct _layer_param_t {
	gdi_handle handle;
	VMINT   trans_color;
	VMINT   x;
	VMINT   y;
	VMINT   width;
	VMINT   height;
	VMUINT8* buffer;
	VMUINT8* canvas;
	VMINT   mibrhandle;
	VMINT   rotate;
	VMINT   used;
	VMINT   all_delete;
    VMUINT  flag;
} layer_param_t;



typedef VMUINT8* (*vm_graphic_user_get_resource_fp)(VMINT, VMINT*);

typedef struct vm_graphic_context{
	clip_rect cliprect;				//��ǰ�ü���
	vm_graphic_pen pen;			    //��ǰ����
	vm_graphic_color color;			//��ǰ��ɫ
	stFontAttribute font;			//��ǰ����
	vm_graphic_user_get_resource_fp fp;//��ǰ�û��Զ�����Դ��ȡ����(���ϰ汾����)
	VMINT save_screen_rotate; //��ǰ��Ļ�ķ�ת�Ƕ� 
	VMINT baseline;
}vm_graphic_context;
/* ------------------------------------------------------------------------- */
/* Extern Platform API                                               							*/
/* ------------------------------------------------------------------------- */
#ifndef __VRE_RB_08B__
extern GDI_RESULT gdi_image_get_frame_count_mem(U8  image_type, U8  *image_ptr, S32 image_size, S32 *frame_count);
#endif
extern GDI_RESULT gdi_image_gif_get_dimension(U8 * GIF_src, S32 * width, S32 * height);
extern GDI_RESULT gdi_image_get_dimension_mem(U8 img_type,U8 *img_ptr,S32 img_size,S32 *width, S32 *height);
extern void Get_CharInfo_ForVRE(U32 Ch, S32 *pWidth, S32 *pDwidth,S32 *pHeight, S32 *Ascent, S32 *Descent);

/* ------------------------------------------------------------------------- */
/* Extern VRE API                                                              */
/* ------------------------------------------------------------------------- */
VMINT vm_is_open_camera_flush_screen_patten(void);
VMINT vm_camera_patten_flush_screen_buffer(void);


/* ------------------------------------------------------------------------- */
/* Module Internal Function                                                     */
/* ------------------------------------------------------------------------- */
static VM_GDI_HANDLE vm_graphic_mibr_save_layer(void);
static VM_GDI_HANDLE vm_graphic_mibr_release_layer(VMINT mibrlayer);
static VM_GDI_RESULT vm_graphic_load_context(void);
static VM_GDI_RESULT vm_graphic_save_context(void);


/* ------------------------------------------------------------------------- */
/* Module External Function                                                     */
/* ------------------------------------------------------------------------- */
extern VMINT  vm_graphic_sal_flatten_layer(gdi_handle handle1,gdi_handle handle2,gdi_handle handle3,gdi_handle handle4,gdi_handle handle5,gdi_handle handle6);
//extern void dd_circle(VMUINT8 *buf, VMINT x, VMINT y, VMINT r, VMINT quadrant, VMUINT16 color);
extern VMINT vm_graphic_sal_flush_layer(gdi_handle handle1,gdi_handle handle2,gdi_handle handle3,gdi_handle handle4,gdi_handle handle5,gdi_handle handle6,VMINT w,VMINT h);
extern void vm_graphic_set_clip_internal(VMINT x1, VMINT y1, VMINT x2, VMINT y2);


/* ------------------------------------------------------------------------- */
/* Module UT Function                                                           */
/* ------------------------------------------------------------------------- */
//#define VM_GRAPHIC_UT
#ifdef VM_GRAPHIC_UT
extern gdi_layer_struct GDI_LAYERS[GDI_LAYER_TOTAL_LAYER_COUNT];
void print_gdi_layers_table(void);
#endif

VMINT _vm_show_malloc_stat(VMINT handle);

#ifdef __VRE_RB_08B__
GDI_RESULT gdi_image_get_frame_count_mem(U8  image_type, U8  *image_ptr, S32 image_size, S32 *frame_count)/*ltz*/
{
return gdi_image_codec_get_frame_count(
            GDI_IMAGE_SRC_FROM_MEMORY,
            image_ptr,
            image_type,
            image_size,
            frame_count,
            0);
}
#endif


/* ------------------------------------------------------------------------- */
/* Global Variable Declare                                                        	    */
/* ------------------------------------------------------------------------- */
/*
 * Ӧ�ó����ṩ�Ļ�ȡͼƬ��Դ����ָ�롣
 */
VMUINT8* (*user_get_resource_fp)(VMINT resid, VMINT* len) = NULL;
static VMINT vm_load_info_resolution(void);

/* ------------------------------------------------------------------------- */
/* Local Variable Declare                                              	*/
/* ------------------------------------------------------------------------- */
extern VMINT is_base_layer_created ;             //���㴴����־
extern  VMINT is_screen_buffer_initialized;      //��Ļ��ʼ����־
extern clip_rect gcliprect;

/*
 * ��Ļ�߶ȡ�
 */
static VMINT screen_width = -1;

/*
 * ��Ļ�߶ȡ�
 */
static VMINT screen_height = -1;

/*
 * MMI�����塣
 */
static stFontAttribute mmi_large_font = {0, 0, 0, LARGE_FONT, 0, 1};
/*
 * MMI�������塣
 */
static stFontAttribute mmi_medium_font = {0,0,0,MEDIUM_FONT,0,1};

/*
 * MMIС���塣
 */
static stFontAttribute mmi_small_font = {0,0,0,SMALL_FONT,0,1};

/*
 * MMIĬ�����塣
 */
static stFontAttribute mmi_def_font = {0,0,0,MEDIUM_FONT,0,1};

/*
 * ��ǰѡ�����塣
 */
static stFontAttribute *current_font = &mmi_def_font;


static VMINT current_baseline = -1;
/*
 * ��Ļ˫����������־λ��
 */
//static VMINT double_buffer_locked = FALSE;

/*
 * ���������
 */
static VMINT layer_count = 0;

/*
 * ��ǰ����Ĳ��š�  
 */
 VMINT active_layer = 0;

/*
 * ��ǰ����Handle��δ������Ϊ-1��
 */
static VMINT is_base_layer = -1;

/*
 * ��ǰ���ٲ�Handle��δ������Ϊ-1��
 */
static VMINT is_fast_layer = -1;

/*
 * ����ת����
 *///  20100706ȥ���� static
 layer_param_t layer_trans_tbl[MAX_LAYER];

/*
 * ȫ�ֻ��ʡ�
 */
static vm_graphic_pen global_pen = {0,NULL};

/*
 * ȫ����ɫ��
 *///  20100706ȥ���� static
 vm_graphic_color global_color = {0,0};

/*
 * ����̱�ÿ�����̶�Ӧһ��������handle��
 */
static vm_graphic_mibr_node mibr_table[MAX_PROCESS];


/*
*��Ļ��ת��־��   
*/
 vm_graphic_screen_rotate_value g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0 ;



//====================================Module Internal Function==========================
VMINT INVALID_VRE_HANDLE(VMINT handle)  
{
	if (((handle) < 0) || ((handle) >= MAX_LAYER) ||( !(layer_trans_tbl[(handle)].used)))
		return TRUE;
	return FALSE;

}
VMINT VALID_VRE_HANDLE(VMINT handle)  
{
	
	if (((handle) >= 0) && ((handle) < MAX_LAYER) && (layer_trans_tbl[(handle)].used))
		return TRUE;
	return FALSE;		
}


VMINT is_vre_canvas_buf(VMBYTE *buf)
{
	if (memcmp(buf, "VOGINS", 6) == 0)
		return TRUE;
	return FALSE;
}

VMINT vm_graphic_is_use_vector_font(void)
{
/*#ifdef __MMI_VECTOR_FONT_SUPPORT__
	return TRUE;
#elif
	return FALSE;
#endif
*/
    if (sysconf.font_engine.fe_vector_support == MMI_TRUE)
		return TRUE;
	return FALSE;
}

VMINT vm_graphic_is_valid_layer_handle(VMINT handle)
{
    if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
        return FALSE;
	return VALID_VRE_HANDLE(handle) ;
}


VMINT vm_graphic_get_blt_layer_count(void)
{
/*#ifdef GDI_6_LAYERS
	return 6;
#endif
#ifdef GDI_4_LAYERS
	return 4;
#endif
	return 2;
*/
	
	if(sysconf.gdi_info.gdi_6_layer == MMI_TRUE)
		return 6;
	else
		return 4;
}

VMINT get_canvas_prop(VMBYTE *buf,vm_canvas_prop  type)
{
	
	switch(type)
	{
		case VM_CANVAS_LEFT:
			return (VMINT)(buf[VM_CANVAS_SIGNATURE_SIZE+2] * 256 + buf[VM_CANVAS_SIGNATURE_SIZE+1]); 
			break;	
		case VM_CANVAS_TOP:
			return (VMINT)(buf[VM_CANVAS_SIGNATURE_SIZE+4] * 256 + buf[VM_CANVAS_SIGNATURE_SIZE+3]); 
			break;	
		case VM_CANVAS_WIDTH:
			return (VMINT)(buf[VM_CANVAS_SIGNATURE_SIZE+6] * 256 + buf[VM_CANVAS_SIGNATURE_SIZE+5]); 
			break;	
		case VM_CANVAS_HEIGHT:
			return (VMINT)(buf[VM_CANVAS_SIGNATURE_SIZE+8] * 256 + buf[VM_CANVAS_SIGNATURE_SIZE+7]);  
			break;
		default:
			return 0;
	}
}

void save_canvas_to_layer(VMINT handle,VMBYTE *canvasbuf)
{
	
	layer_trans_tbl[handle].canvas = canvasbuf;
	return;
}

void delete_canvas_from_layer(VMINT handle)
{
	
	layer_trans_tbl[handle].canvas = NULL;
	return;
}

void save_layer_to_canvas(VMINT handle,VMBYTE *canvasbuf)
{
	VMUINT16  shorthandle;
	
	shorthandle = (VMUINT16)((handle << 16) >> 16);
	canvasbuf[VM_CANVAS_FRAME_NUM_OFFSET+1] = shorthandle %256;
	canvasbuf[VM_CANVAS_FRAME_NUM_OFFSET+2] = shorthandle / 256;
	return;
}

void delete_layer_from_canvas(VMBYTE * canvasbuf)
{
	canvasbuf[VM_CANVAS_FRAME_NUM_OFFSET+1] = 0xff;
	canvasbuf[VM_CANVAS_FRAME_NUM_OFFSET+2] = 0xff;
	return;
}





/*�����Ͳ�һһ��Ӧ*/
/*�ҵ��ò����Ŀ��ڴ���*/
VMINT  find_canvas(VMINT handle)
{
	if ((handle == is_fast_layer) || (handle == is_base_layer))
		return 0;
	if (INVALID_VRE_HANDLE(handle))
		return VM_GDI_ERR_WRONG_PARAM;
	return (VMINT)(layer_trans_tbl[handle].canvas);
}

/*�ҵ��û����ڴ����ĸ�����*/
VMINT find_layer(VMBYTE * canvasbuf)
{
	
	if ((!canvasbuf) || (!is_vre_canvas_buf(canvasbuf)) )
		return VM_GDI_FAILED;

	return (VMINT)(canvasbuf[VM_CANVAS_FRAME_NUM_OFFSET+2]*256+canvasbuf[VM_CANVAS_FRAME_NUM_OFFSET+1]);
}


/*�ҵ���ת����յ�λ��*/
VM_GDI_RESULT find_empty_node_in_layer_table(void)
{
	VMINT i;
		
	for(i=0;i<MAX_LAYER;i++)
    {   
		if (layer_trans_tbl[i].used== FALSE)
			break;
	}
    vm_log_debug("[graphic] - find_empty_node_in_layer_table : %d",i);
	return ((i==MAX_LAYER) ? VM_GDI_FAILED : i);
}


/*�жϲ����Ƿ����ڸý���*/
VM_GDI_RESULT handle_belong_to_cur_process(VMINT handle) 
{
	VM_P_HANDLE phandle = vm_pmng_get_app_handle();
	VM_P_HANDLE testhandle;
		
	if (phandle <= 0)
		return VM_GDI_MIBR_ERR;
	if ((testhandle = vm_res_get_process_handle(VM_RES_TYPE_LAYER_HANDLE,layer_trans_tbl[handle].mibrhandle)) ==  phandle)
	{
		vm_log_debug("[graphic] - handle_belong_to_cur_process :SUCCEED : phandle =%d,testhandle =%d",phandle,testhandle);
		return VM_GDI_SUCCEED;
	}
	vm_log_debug("[graphic] - handle_belong_to_cur_process :FAILED : phandle =%d,testhandle =%d",phandle,testhandle);
	return VM_GDI_MIBR_RES_ERR;
}

/*
* ���ٽ����ֵ��Ϊ���׵��㷨----�����ֵ
*/
VMINT enlarge_image(VMUINT8 *in_data,VMINT swidth,VMINT sheight,VMUINT8 *out_data,VMINT dwidth,VMINT dheight)
{
	//VMUINT ptar=0,ptbr=0,ptcr=0,ptdr=0;   
    //VMUINT ptag=0,ptbg=0,ptcg=0,ptdg=0;
    //VMUINT ptab=0,ptbb=0,ptcb=0,ptdb=0;
    VMUINT pixelvalueb=0,pixelvalueg=0,pixelvaluer=0; 
    VMUINT spixelcolnum=0,spixelrownum=0,destcol=0,destrow=0;   
    VMUINT spixelcoladdr=0,spixelrowaddr=0;   
    VMUINT coldelta=0,rowdelta=0,scalev=0,scaleh=0;   
    //VMUINT *contribtem;
    VMINT  i = 0;   
	vm_log_debug("[graphic] - enlarge_image :Begin!");
	if (dwidth > MAX_PIXEL_ENLARGE)
		return VM_GDI_ERR_WRONG_PARAM;
	//if ((contribtem = vm_calloc(MAX_PIXEL_ENLARGE * 2 * sizeof(VMUINT))) ==NULL)
	//	return VM_GDI_ERR_MALLOC_FAILED;
              
      	scaleh=(swidth<<8)/dwidth;   
      	scalev=(sheight<<8)/dheight;   
	vm_log_debug("[graphic] - enlarge_image :scaleh = %d!",scaleh);
//first   line   
	for(destcol=0;destcol<(VMUINT)dwidth;destcol++)   
	{   
		spixelcoladdr=destcol*scaleh;   
		coldelta=spixelcoladdr&255;   
		spixelcolnum=(spixelcoladdr-coldelta)>>8; 



		pixelvalueb = (in_data[2*spixelrownum*swidth+2*spixelcolnum] & 0x1F) << 3;
		pixelvalueg = (((in_data[2*spixelrownum*swidth+2*spixelcolnum+1] & 0x07) << 4) +( (in_data[2*spixelrownum*swidth+2*spixelcolnum] & 0xE0) >>4)) << 1;                   
		pixelvaluer = (in_data[2*spixelrownum*swidth+2*spixelcolnum+1] & 0xF8);  
  
		/*if((spixelcolnum+1)<swidth)   
		{   
			ptbb= (in_data[2*spixelrownum*swidth+2*(spixelcolnum+1)]& 0x1F) << 3;   
			ptbg = (((in_data[2*spixelrownum*swidth+2*(spixelcolnum+1)+1] & 0x07) << 4) + ((in_data[2*spixelrownum*swidth+2*(spixelcolnum+1)] & 0xE0)>>4)) << 1;                   
			ptbr = (in_data[2*spixelrownum*swidth+2*(spixelcolnum+1)+1] & 0xF8); 


			ptcb = (in_data[2*(spixelrownum+1)*swidth+2*spixelcolnum] & 0x1F) << 3;
			ptcg = (((in_data[2*(spixelrownum+1)*swidth+2*spixelcolnum+1] & 0x07) << 4) + ((in_data[2*(spixelrownum+1)*swidth+2*spixelcolnum] & 0xE0)>>4)) << 1;                   
			ptcr = (in_data[2*(spixelrownum+1)*swidth+2*spixelcolnum+1] & 0xF8);   			

			ptdb = (in_data[2*(spixelrownum+1)*swidth+2*(spixelcolnum+1)] & 0x1F) << 3;
			ptdg = (((in_data[2*(spixelrownum+1)*swidth+2*(spixelcolnum+1)+1] & 0x07) << 4) + ((in_data[2*(spixelrownum+1)*swidth+2*(spixelcolnum+1)] & 0xE0)>>4)) << 1;                   
			ptdr = (in_data[2*(spixelrownum+1)*swidth+2*(spixelcolnum+1)+1] & 0xF8);   

		}   
		else   
		{   
			ptbb=ptcb=ptdb=ptab;   
			ptbg=ptcg=ptdg=ptag;   
			ptbr=ptcr=ptdr=ptar;   
		}   
		
		pixelvalueb=ptab;   
		pixelvalueg=ptag;  
		pixelvaluer=ptar;  */
		out_data[2*destrow*dwidth+2*destcol] = (((pixelvalueg >> 2 ) & 0x07 ) << 5) + ((pixelvalueb & 0xF8) >> 3);  
		out_data[2*destrow*dwidth+2*destcol+1]= pixelvaluer + ((pixelvalueg >> 5 ) & 0x07);   
	}   
                  
                  
	for(destrow=1;destrow<(VMUINT)dheight;destrow++)   
	{   
		i=0;                                                                             
		spixelrowaddr=destrow*scalev;   
		rowdelta=spixelrowaddr&255;   
		spixelrownum=(spixelrowaddr-rowdelta)>>8;   
		for(destcol=0;destcol<(VMUINT)dwidth;destcol++)   
		{   
			spixelcoladdr=destcol*scaleh;   
			coldelta=spixelcoladdr&255;   
			spixelcolnum=(spixelcoladdr-coldelta)>>8;   

			pixelvalueb = (in_data[2*spixelrownum*swidth+2*spixelcolnum] & 0x1F) << 3;
			pixelvalueg = (((in_data[2*spixelrownum*swidth+2*spixelcolnum+1] & 0x07) << 4) + ((in_data[2*spixelrownum*swidth+2*spixelcolnum] & 0xE0)>>4)) << 1;                   
			pixelvaluer = (in_data[2*spixelrownum*swidth+2*spixelcolnum+1] & 0xF8);   			
                
		/*	if(((spixelcolnum+1)<swidth)&&((spixelrownum+1)<sheight))   
			{   
				ptcb = ((in_data[2*(spixelrownum+1)*swidth+2*spixelcolnum] & 0x1F) << 3);
				ptcg = (((in_data[2*(spixelrownum+1)*swidth+2*spixelcolnum+1] & 0x07) << 4) + ((in_data[2*(spixelrownum+1)*swidth+2*spixelcolnum] & 0xE0)>>4)) << 1;                   
				ptcr = (in_data[2*(spixelrownum+1)*swidth+2*spixelcolnum+1] & 0xF8);   			

				ptdb = ((in_data[2*(spixelrownum+1)*swidth+2*(spixelcolnum+1)] & 0x1F) << 3);
				ptdg = (((in_data[2*(spixelrownum+1)*swidth+2*(spixelcolnum+1)+1] & 0x07) << 4) + ((in_data[2*(spixelrownum+1)*swidth+2*(spixelcolnum+1)] & 0xE0)>>4)) << 1;                   
				ptdr = (in_data[2*(spixelrownum+1)*swidth+2*(spixelcolnum+1)+1] & 0xF8);   				
			}   
			else   
			{   
				ptbb=ptcb=ptdb=ptab;   
				ptbg=ptcg=ptdg=ptag; 
				ptbr=ptcr=ptdr=ptar; 
			}   
			pixelvalueb=ptab;   
			pixelvalueg=ptag;   
 			pixelvaluer=ptar;   */
                      
			out_data[2*destrow*dwidth+2*destcol] = (((pixelvalueg >> 2 ) & 0x07 ) << 5 )+ ((pixelvalueb & 0xF8) >> 3);  
			out_data[2*destrow*dwidth+2*destcol+1]= pixelvaluer + ((pixelvalueg >> 5 ) & 0x07);   
		}   
	}
	//vm_free(contribtem);
	return VM_GDI_SUCCEED;
}


//=================================================================================





//=======================================SAL Function================================
void set_layer_table_internal(VMINT handle,VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color,VMINT alldelete)
{
	layer_trans_tbl[handle].x = x;
	layer_trans_tbl[handle].y = y;
	layer_trans_tbl[handle].width = width;
	layer_trans_tbl[handle].height = height;
	layer_trans_tbl[handle].all_delete= alldelete;
	layer_trans_tbl[handle].trans_color = trans_color;	//low 16bit is available
	gdi_layer_push_and_set_active(SAL_HANDLE(handle));
	if (layer_trans_tbl[handle].trans_color != VM_NO_TRANS_COLOR) 
		gdi_layer_set_source_key(TRUE, layer_trans_tbl[handle].trans_color);
	else
		gdi_layer_set_source_key(FALSE, 0);
	gdi_layer_pop_and_restore_active();
	layer_trans_tbl[handle].used = TRUE;
}




VM_GDI_HANDLE set_layer_table(gdi_handle hdl,VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color,VMINT alldelete)
{
	VMUINT8* buf = NULL;
	VMINT handle = 0;

	if ((handle = find_empty_node_in_layer_table())< 0)
	{
		vm_log_error("[graphic] -vm_graphic_sal_set_layer_table : empty node not found !");
		return VM_GDI_FAILED;
	}
	
	
	layer_trans_tbl[handle].handle = hdl;
	gdi_layer_push_and_set_active(hdl);
	gdi_layer_get_buffer_ptr(&buf);
	gdi_layer_pop_and_restore_active();
	layer_trans_tbl[handle].buffer = buf;

	
	if ((layer_trans_tbl[handle].mibrhandle = vm_graphic_mibr_save_layer()) < 0)
		return layer_trans_tbl[handle].mibrhandle;
			
	set_layer_table_internal(handle,x,y,width,height,trans_color,alldelete);
	layer_count++;	
	vm_log_debug("[graphic] -set_layer_table : Current Handle = %d ,Layer Count = %d !",handle,layer_count);
	vm_log_debug("[graphic] -set_layer_table : Add MTK layer = %u ,MIBR Handle= %d!",layer_trans_tbl[handle].handle,layer_trans_tbl[handle].mibrhandle);
	return handle;
}


VM_GDI_RESULT set_layer_table_existed(VMINT handle,VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color,VMINT alldelete)
{
	if (INVALID_VRE_HANDLE(handle))
		return VM_GDI_FAILED;
	
	
	set_layer_table_internal(handle,x,y,width,height,trans_color,alldelete);
	

	vm_log_debug("[graphic] -set_layer_table_existed : Current Handle = %d ,Layer Count = %d !",handle,layer_count);
	vm_log_debug("[graphic] -set_layer_table_existed : Add MTK layer = %u ,MIBR Handle= %d!",layer_trans_tbl[handle].handle,layer_trans_tbl[handle].mibrhandle);

	return VM_GDI_SUCCEED;
}


VM_GDI_HANDLE vm_graphic_sal_set_base_layer(VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color)
{
	gdi_handle hdl;
	VMINT handle;
	if (is_base_layer >= 0)
	{
		vm_log_debug("[graphic] - vm_graphic_sal_set_base_layer_existed :  is_base_layer = %d!",is_base_layer);
		set_layer_table_existed(is_base_layer,x,y,width,height,trans_color,FALSE);
		return is_base_layer;
	}
	if (gdi_layer_get_base_handle(&hdl) == GDI_SUCCEED)
	{
		if ((handle = set_layer_table(hdl,x,y,width,height,trans_color,FALSE)) >= 0)
		{
			is_base_layer = handle;
			return handle;
		}
	}
	return VM_GDI_FAILED;
}

VM_GDI_HANDLE vm_graphic_sal_set_fast_layer(VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color)
{
	gdi_handle hdl;
	VMINT handle;
	if (layer_count > MAX_LAYER -1)
		return VM_GDI_FAILED;	
	if (is_fast_layer >= 0)
	{
		vm_log_debug("[graphic] - vm_graphic_sal_set_fast_layer_existed :  is_fast_layer = %d!",is_fast_layer);
		set_layer_table_existed(is_fast_layer,x,y,width,height,trans_color,FALSE);
		return is_fast_layer;
	}		
	if (gdi_layer_create(x, y, width, height, &hdl) == GDI_SUCCEED)
	{
		if ((handle = set_layer_table(hdl,x,y,width,height,trans_color,FALSE)) >= 0)
		{
			is_fast_layer = handle;
			return handle;
		}
	}
	return VM_GDI_FAILED;
}





VM_GDI_RESULT vm_graphic_sal_release_base_layer(gdi_handle salhandle)
{
	//Clear transcolor and opacity;Coordinate on (0,0);Reset rotate value;Resize width and height.
	gdi_layer_push_and_set_active(salhandle);
	//gdi_layer_set_source_key(FALSE, 0);
	gdi_layer_set_opacity(FALSE, 0);
    gdi_layer_set_position(0, 0);
    gdi_layer_set_rotate(VM_GDI_ROTATE_NORMAL);
    gdi_layer_resize(vm_graphic_get_screen_width(), vm_graphic_get_screen_height());     
	gdi_layer_pop_and_restore_active();
	return VM_GDI_SUCCEED;
}

VM_GDI_RESULT vm_graphic_sal_release_layer(gdi_handle salhandle)
{
	gdi_handle hdl;
	gdi_layer_get_base_handle(&hdl);
	if (salhandle == hdl)
		return vm_graphic_sal_release_base_layer(salhandle);
	if (gdi_layer_free(salhandle) != GDI_SUCCEED) 
    {
        vm_log_fatal("[graphic]-vm_graphic_sal_release_layer : release failed");
        return VM_GDI_FAILED;	
    }
		
	return VM_GDI_SUCCEED;
}


VM_GDI_RESULT  vm_graphic_sal_resize_layer(gdi_handle salhandle,VMINT width,VMINT height)
{

	gdi_handle cur_active_layer;
	gdi_layer_get_active(&cur_active_layer);
	if (salhandle != cur_active_layer)
	{
		gdi_layer_push_and_set_active(salhandle);	
		gdi_layer_resize(width, height);
		gdi_layer_pop_and_restore_active();
		return VM_GDI_SUCCEED;
	}
	gdi_layer_resize(width, height);
	return VM_GDI_SUCCEED;	
}
//===============================================================================







//=========================Module Extern Function=====================================

VMINT vm_graphic_get_character_height(void) 
{
	VMINT w = 0;
	VMINT h = 0;
	//VMWCHAR wstr[20];

	/*vm_gb2312_to_ucs2(wstr, 20, "AGJPYabgjkqty1��!");
	gui_set_font(current_font);
	Get_StringWidthHeight((U8 *)wstr, (S32 *)&w, (S32 *)&h);
	return (h + VRE_CHAR_V_PADDING);*/

	gui_set_font(current_font);
	Get_StringWidthHeight((U8 *)L"AGJPYabgjkqty1��!", (S32 *)&w, (S32 *)&h);
	return (h + VRE_CHAR_V_PADDING);
}

VMINT vm_graphic_get_character_width(VMWCHAR c) 
{
	VMINT w = 0;
	VMINT h = 0;
	
	if(c == 0)
		return VM_GDI_ERR_WRONG_PARAM;
	
	gui_set_font(current_font);
	Get_CharWidthHeight((U32)c , (s32 *)(&w), (s32 *)(&h));
	return (w + VRE_CHAR_H_PADDING);
}

VMINT vm_graphic_measure_character(VMWCHAR c, VMINT *width, VMINT *height) 
{
#if !defined(__VRE_RB_08A__)
	mmi_fe_glyph_metrics_struct matrix;
#endif
    if ((width == NULL) || (height == NULL))
		return VM_GDI_ERR_WRONG_PARAM;
	if (c == 0)
	{
		*width = 0;
		*height = 0;	   
		return VM_GDI_ERR_WRONG_PARAM;
	}
	gui_set_font(current_font);
#ifdef __VRE_RB_08A__
	Get_CharWidthHeight((U32)c, (s32 *)width, (s32 *)height);
#else	
    mmi_fe_get_glyph_metrics((VMUINT16)c, &matrix);    
    if (matrix.adv_x != 0) 
    {
        *width = matrix.adv_x;
        *height= matrix.height;        
    }
    else
      Get_CharWidthHeight((U32)c, (s32 *)width, (s32 *)height);
#endif    
 	*width += VRE_CHAR_H_PADDING;
	*height += VRE_CHAR_V_PADDING;
	return VM_GDI_SUCCEED;
}





VMINT vm_graphic_get_character_info(VMWCHAR c, vm_graphic_char_info *char_info)
{
    if (char_info == NULL)
		return VM_GDI_ERR_WRONG_PARAM;

 	if (c == 0)
	{
		char_info->width = 0;
		char_info->height = 0;
        char_info->dwidth = 0;
        char_info->ascent= 0;
        char_info->descent= 0;
		return VM_GDI_ERR_WRONG_PARAM;
	}   
	gui_set_font(current_font);

    Get_CharInfo_ForVRE((VMUINT16)c, &(char_info->width), &(char_info->dwidth), &(char_info->height), &(char_info->ascent), &(char_info->descent));    
        
    char_info->dwidth += VRE_CHAR_H_PADDING;
	char_info->width  += VRE_CHAR_H_PADDING;
	char_info->height += VRE_CHAR_V_PADDING;
	return VM_GDI_SUCCEED;    

}




VMINT vm_graphic_get_string_width(VMWSTR str) 
{
	VMINT swidth = 0;
	VMINT sheight = 0;
	if(str == NULL)
		return VM_GDI_ERR_WRONG_PARAM;
		
	gui_set_font(current_font);
	gui_measure_string((UI_string_type)str, (S32 *) &swidth, (S32 *)&sheight);
	return  swidth + vm_wstrlen(str) * VRE_CHAR_H_PADDING;
}
VMINT vm_graphic_get_string_height(VMWSTR str) 
{
	VMINT swidth = 0;
	VMINT sheight = 0;
	if(str == NULL)
		return VM_GDI_ERR_WRONG_PARAM;
		
	gui_set_font(current_font);
	gui_measure_string((UI_string_type)str, (S32 *) &swidth, (S32 *)&sheight);
	return  (sheight + VRE_CHAR_V_PADDING);
}

VMINT vm_graphic_get_screen_width(void) 
{
//	if (-1 == screen_width) // 
		gdi_lcd_get_dimension(&screen_width, &screen_height);
	return screen_width;
}

VMINT vm_graphic_get_screen_height(void) 
{
//	if (-1 == screen_height) //��
		gdi_lcd_get_dimension(&screen_width, &screen_height);
	return screen_height;
}

void vm_graphic_set_font(font_size_t size) 
{
    if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
        return;

	switch (size) 
	{
	case VM_SMALL_FONT:
		current_font = &mmi_small_font;
		break;
	case VM_MEDIUM_FONT:
		current_font = &mmi_medium_font;
		break;
	case VM_LARGE_FONT:
		current_font = &mmi_large_font;
		break;
	default:
		current_font = &mmi_medium_font;
		break;
	}
	//gui_set_font(current_font);	
	
}

void vm_reg_res_provider(VMUINT8* (*fp)(VMINT resid, VMINT* len)) 
{
	//vm_log_debug("Register user_get_resource_fp: fn=%x.", fp);
	user_get_resource_fp = fp;
}

VMINT vm_graphic_get_bits_per_pixel(void) 
{
	/*����һ�����ص�ռ�ÿռ��(�ֽ���������λ��)*/
	return gdi_layer_get_bit_per_pixel();
}

VMINT vm_graphic_get_layer_count(void)
{
	return MAX_LAYER;
}


VMINT vm_graphic_get_current_layer_count(void)
{
	return layer_count;
}


VMINT vm_graphic_active_layer_internal(VMINT handle)
{
	VMINT x1,y1,x2,y2;
	if (INVALID_VRE_HANDLE(handle))
		return VM_GDI_FAILED;

	if (handle != active_layer)
	{
		active_layer = handle;
		gdi_layer_set_active(layer_trans_tbl[handle].handle);
		gdi_layer_get_clip(&x1, &y1, &x2, &y2);
		vm_graphic_set_clip(x1, y1, x2, y2);
        vm_log_debug("[graphic]-vm_graphic_active_layer_internal : active_layer = %d.",active_layer);
	}
	return VM_GDI_SUCCEED;
}



VMINT vm_graphic_active_layer(VMINT handle)
{

//    if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
//    { 
//        vm_log_error("[graphic] - vm_graphic_active_layer : background!!");
//        return VM_GDI_MIBR_NOT_FORE;
//    }
    if (handle_belong_to_cur_process(handle) == VM_GDI_SUCCEED)
        return vm_graphic_active_layer_internal(handle);
    else
    {
        vm_log_fatal("[graphic]-vm_graphic_active_layer : handle %d FAILED.",handle);
        return VM_GDI_FAILED;
    }
}


/*ͨ��canvas��buf�½�һ����*/
VM_GDI_HANDLE vm_graphic_create_layer_with_buf(VMINT x,VMINT y,VMBYTE *canvasbuf,VMINT trans_color,VMINT alldelete)
{
	gdi_handle hdl;
	VMINT handle,width,height;
	if ( (canvasbuf == NULL) ||(!is_vre_canvas_buf(canvasbuf)))
		return VM_GDI_ERR_WRONG_PARAM;
	
	if (layer_count > MAX_LAYER -1) 
		return VM_GDI_FAILED;	

	if ((handle = find_layer(canvasbuf))!= 0)
		if (VALID_VRE_HANDLE(handle))
			return VM_GDI_ERR_LAYER_BIND;
	
	width = get_canvas_prop(canvasbuf,VM_CANVAS_WIDTH);
	height = get_canvas_prop(canvasbuf,VM_CANVAS_HEIGHT);

	if (gdi_layer_create_using_outside_memory(x, y, width, height, &hdl, canvasbuf+CANVAS_BUF_OFFSET, width * height * 2+(width * height * 2) % 4)!= GDI_SUCCEED)
 	{
		vm_log_fatal("[graphic] - vm_graphic_create_layer_with_buf : using_outside_memory create fail!");
		return VM_GDI_ERR_CREATE_LAYER_FAILED;
	}       
	if (hdl == 0)
	{
		vm_log_fatal("[graphic] - vm_graphic_create_layer_with_buf : using_outside_memory create fail!");
		return VM_GDI_ERR_CREATE_LAYER_FAILED;
	}
	
	handle = set_layer_table(hdl,x,y,width,height,trans_color,alldelete);

	//�������Ͳ���໥ӳ��
	save_canvas_to_layer(handle,canvasbuf);
	save_layer_to_canvas(handle,canvasbuf);

	vm_log_debug("[graphic] - vm_graphic_create_layer_with_buf :MTKhandle = %u,return handle = %d", hdl,handle);
	return handle;	
}


/*
	����ɹ���Ӧ����һ������0��handle
	���򷵻ش����롣
*/
VM_GDI_HANDLE  vm_graphic_create_canvas_and_layer(VMINT x,VMINT y,VMINT width, VMINT height,VMINT trans_color)
{
	VMINT canvasbuf;
	if ((canvasbuf = vm_graphic_create_canvas(width, height)) <= 0)
	{
		vm_log_debug("[graphic] - vm_graphic_create_canvas_and_layer :return canvas addr = %p", canvasbuf);
		return VM_GDI_ERR_CREATE_CANVAS_FAILED;
	}
		
	return vm_graphic_create_layer_with_buf(x,y,vm_graphic_get_canvas_buffer(canvasbuf),trans_color,TRUE);
}




VM_GDI_HANDLE vm_graphic_create_layer(VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color)
{
	VMINT ret;
//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return VM_GDI_FAILED;

    if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
    { 
        vm_log_error("[graphic] - vm_graphic_create_layer : background!!");
        return VM_GDI_MIBR_NOT_FORE;
    }
    vm_log_debug("[graphic] - vm_graphic_create_layer : Begin!");
#ifdef VM_GRAPHIC_UT    
    print_gdi_layers_table();
#endif    

#ifdef VRE_SUPPORT_CAMERA_FEATURE
	if (vm_is_open_camera_flush_screen_patten())
		return VM_GDI_FAILED;
#endif
    //
    if ((is_base_layer>=0) && (is_fast_layer>=0))
    {
        vm_log_error("[graphic] - vm_graphic_create_layer : Already 2 Layers!");
        return VM_GDI_FAILED; 
    }
       

	if ((x < 0 ) || (y < 0) ||
		(x >= vm_graphic_get_screen_width() ) ||
		(y >= vm_graphic_get_screen_height()) ||
		(width <= 0) || (height <= 0) )
		return VM_GDI_ERR_WRONG_PARAM;
	if (x + width > vm_graphic_get_screen_width())
		width = vm_graphic_get_screen_width() - x;
	if (y + height > vm_graphic_get_screen_height())
		height = vm_graphic_get_screen_height() - y;
	if (layer_count < MAX_LAYER) 
	{
		if (layer_count == 0) 
		{
			//��������
			ret =  vm_graphic_sal_set_base_layer(x,y,width,height,trans_color);
			vm_log_debug("[graphic] - vm_graphic_create_layer (base_layer): create ret =%d And layer_count=%d!",ret,layer_count);
		}
 		else 
		{
			//�������ٲ�
			ret = vm_graphic_sal_set_fast_layer(x,y,width,height,trans_color);
			vm_log_debug("[graphic] - vm_graphic_create_layer (fast_layer): create ret =%d And layer_count=%d!",ret,layer_count);
		}
		vm_log_debug("[graphic] - vm_graphic_create_layer : create layer %d  DONE",ret);
        vm_log_error("[graphic] - vm_graphic_create_layer : End!");
#ifdef VM_GRAPHIC_UT    
    	print_gdi_layers_table();
#endif        
		return ret;
	}
    vm_log_error("[graphic] - vm_graphic_create_layer : layer_count > MAX_LAYER!");
    return VM_GDI_FAILED;
 }













VM_GDI_HANDLE vm_graphic_create_layer_ex(VMINT x, VMINT y, VMINT width, VMINT height, VMINT trans_color,VMINT mode,VMUINT8 * buf)
{
	VMINT ret;
    if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
    { 
        vm_log_error("[graphic] - vm_graphic_create_layer_ex : background!!");
        return VM_GDI_MIBR_NOT_FORE;
    }
	vm_log_debug("[graphic] - vm_graphic_create_layer_ex : In FOREGROUND, layercount = %d",layer_count);
#ifdef VM_GRAPHIC_UT    
    print_gdi_layers_table();
#endif 
	/*������Ǵ������㣬��������Ƿ񴴽����Լ��Ƿ�����Դ����*/
	if (mode != VM_BASE_LAYER)
	{
		if (is_base_layer < 0)
			return VM_GDI_ERR_BASE_LAYER_NOT_EXIST;	
		if (vm_res_type_avaliable_handle(VM_RES_TYPE_LAYER_HANDLE, vm_pmng_get_app_handle()) <=0)
			return VM_GDI_MIBR_NO_RES;
		vm_log_debug("[graphic] - vm_graphic_create_layer_ex : MIBR OK!");
	}


	if ((width <= 0) || (height <= 0) || (width > MAX_LAYER_WIDTH) || (height > MAX_LAYER_HEIGHT))
		return VM_GDI_ERR_WRONG_PARAM;

    if ((mode == VM_BASE_LAYER) || (mode == VM_FAST_LAYER))
        if ((width > vm_graphic_get_screen_width()) || (height > vm_graphic_get_screen_height()))
            return VM_GDI_ERR_WRONG_PARAM;

	switch(mode)
	{
		case VM_BASE_LAYER:
			ret = vm_graphic_sal_set_base_layer(x, y, width, height, trans_color);
			vm_log_debug("[graphic] - vm_graphic_create_layer_ex (base_layer): create ret =%d And layer_count=%d!",ret,layer_count);
			break;
		case VM_FAST_LAYER:
			ret = vm_graphic_sal_set_fast_layer(x,y,width,height,trans_color);
			vm_log_debug("[graphic] - vm_graphic_create_layer_ex (fast_layer): create ret =%d And layer_count=%d!",ret,layer_count);
			break;
		case VM_BUF:
			ret = vm_graphic_create_layer_with_buf(x,y,buf,trans_color,FALSE);
			break;
		case VM_CREATE_CANVAS:
			ret = vm_graphic_create_canvas_and_layer(x,y,width, height,trans_color);
			break;			
		default:
			return VM_GDI_ERR_WRONG_PARAM;
	}
#ifdef VM_GRAPHIC_UT    
    print_gdi_layers_table();
#endif 
	vm_log_debug("[graphic] -vm_graphic_create_layer_ex : create ret =%d DONE!",ret);
	return ret;
}






VM_GDI_RESULT  vm_graphic_release_canvas_ex(VMINT hcanvas)
{
	VMINT layerhandle;
	if (hcanvas<=0)
		return VM_GDI_ERR_WRONG_PARAM;

	layerhandle =  find_layer((VMUINT8*)hcanvas);
	if (layerhandle < 0)
		return VM_GDI_FAILED;
	if (vm_graphic_delete_layer(layerhandle) < 0)
		return VM_GDI_ERR_FREE_RES;
	vm_graphic_release_canvas(hcanvas);
	return VM_GDI_SUCCEED;
}




VM_GDI_RESULT  vm_graphic_delete_layer_internal(VMINT handle)
{
	VMINT result;
	VMINT canvas;
	vm_log_debug("[graphic] - vm_graphic_delete_layer_internal : handle=%d!",handle);
	if (INVALID_VRE_HANDLE(handle))
		return VM_GDI_ERR_WRONG_PARAM;	

	//��ɾ������ǰ����Ҫ��ɾ��������
	if ((handle == is_base_layer) && (layer_count > 1))
    {   
        vm_log_warn("[graphic] - vm_graphic_delete_layer_internal : Should Delete Base Layer First!");
        return VM_GDI_FAILED;
    }

	//���Ҫɾ���Ĳ��ǵ�ǰ�㣬��ô���������ߵ�һ����(һ����˵������ǵ�һ����)
	if (handle == active_layer)
	{
		vm_graphic_active_layer_internal((is_base_layer >= 0) ? is_base_layer : 0);
		vm_graphic_set_layer_clip(active_layer,0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height());
	}

	
	result =  vm_graphic_sal_release_layer(SAL_HANDLE(handle));
	//���ɾ���ɹ������ͷ�MIBR��Դ������ر���
	if (result >= 0)
	{
		if ((canvas = find_canvas(handle)) > 0)
		{
			if (layer_trans_tbl[handle].all_delete)
				vm_graphic_release_canvas(canvas);
			else
				delete_layer_from_canvas((VMUINT8 *) canvas);
		}
		layer_count--;
		vm_graphic_mibr_release_layer(layer_trans_tbl[handle].mibrhandle);
		layer_trans_tbl[handle].used = FALSE;
    	if (handle ==  is_base_layer )
		    is_base_layer = -1;
	    if (handle ==  is_fast_layer )
    		is_fast_layer = -1;			
	}
	return result;
}

/*
 *	ɾ��һ��ͼ�㡣
 *	��ɾ�����ǰ���������Ƿ��ͷţ����򷵻ش���
 *	����ͷŵ�ǰ�㣬�򼤻����
 *	
 */
VM_GDI_RESULT  vm_graphic_delete_layer(VMINT handle)
{
	if (INVALID_VRE_HANDLE(handle))
		return VM_GDI_ERR_WRONG_PARAM; // -2 //��������
	
	if (handle_belong_to_cur_process(handle) < 0)
		return VM_GDI_MIBR_RES_ERR; // -13
	
	return vm_graphic_delete_layer_internal(handle);
}






VMINT vm_graphic_flush_layer(VMINT* layer_handles, VMINT count)
{
	VMINT maxbltlayer;

	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
	{
		vm_log_error("[graphic] - vm_graphic_flush_layer : background!!");
		return VM_GDI_MIBR_NOT_FORE;	
	}


	maxbltlayer = vm_graphic_get_blt_layer_count();
	if ((layer_handles == NULL) || (count <=0) )
		return VM_GDI_ERR_WRONG_PARAM;
		
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	if (vm_is_open_camera_flush_screen_patten())
		return vm_camera_patten_flush_screen_buffer();
#endif
    //vm_log_debug("[graphic]-vm_graphic_flush_layer:first handle =%d,count =%d",layer_handles[0],count);

	if (count == 1 && layer_handles[0] == is_base_layer)			/* ֻ��ˢ����. 	*/
	{
#ifdef VM_OUTPUT_MEM_STATE
		_vm_show_malloc_stat(0);
#endif
		if (gdi_layer_blt_base_layer(0, 0, vm_graphic_get_screen_width() - 1, 
			vm_graphic_get_screen_height() - 1) == GDI_SUCCEED)
			return VM_GDI_SUCCEED;
		return VM_GDI_FAILED;
	}
	else												/* ����ˢ����.	*/
	{
		gdi_handle layers[MAX_LAYER];
		VMINT i = 0;
		memset(layers, 0x00, sizeof(layers));
			
		if (count > maxbltlayer)
			count = maxbltlayer;


		for (i = 0; i < maxbltlayer; i++) 
		{
			layers[i] = 0;
			if (i < count) 
    			if (VALID_VRE_HANDLE(layer_handles[i]))
					layers[i] = layer_trans_tbl[layer_handles[i]].handle;
		}
		vm_log_debug("[graphic] - vm_graphic_flush_layer_ex() :Blt MTK layer_handles:   %d, %d, %d, %d, %d, %d.", layers[0], layers[1],layers[2], layers[3],layers[4], layers[5]);
#ifdef VM_OUTPUT_MEM_STATE
		_vm_show_malloc_stat(1);
#endif			
			
		if (maxbltlayer == 6)
		{
			if ((layers[0] +layers[1]+layers[2]+layers[3]+layers[4]+layers[5])== 0 )
				return VM_GDI_FAILED;

            if (vm_graphic_sal_flush_layer(layers[0],layers[1],layers[2],layers[3],layers[4],layers[5],
                vm_graphic_get_screen_width()-1,
                vm_graphic_get_screen_height()-1) == GDI_SUCCEED)
				return VM_GDI_SUCCEED;
            vm_log_fatal("[graphic] - vm_graphic_flush_layer_ex : gdi_layer_blt 6 FAILED");
			return VM_GDI_FAILED;
		}
		else
		{
            if (maxbltlayer == 2)
            {
                layers[2] = 0;
                layers[3] = 0;
            }

            if ((layers[0] +layers[1]+layers[2]+layers[3])== 0 )
				return VM_GDI_FAILED;
			if (gdi_layer_blt(layers[0], layers[1], layers[2], layers[3],0,0,
				vm_graphic_get_screen_width() - 1,
				vm_graphic_get_screen_height() - 1) == GDI_SUCCEED)
				return VM_GDI_SUCCEED;
            vm_log_fatal("[graphic] - vm_graphic_flush_layer_ex : gdi_layer_blt 2 or 4 FAILED");
			return VM_GDI_FAILED;
		}
	}
}







VMUINT8* vm_graphic_get_layer_buffer(VMINT handle) {
	VMUINT8* buf = NULL;
	
	//vm_log_debug("vm_graphic_get_layer_buffer start -- handle=%d", handle);
//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return NULL;
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return NULL;

	//vm_log_debug("vm_graphic_get_layer_buffer step1-- handle=%d", handle);
	if (VALID_VRE_HANDLE(handle))
		buf = layer_trans_tbl[handle].buffer;
	//vm_log_debug("vm_graphic_get_layer_buffer return buf=0x%x", buf);
	return buf;
}



VMINT vm_graphic_clear_layer_bg(VMINT handle) {
//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return VM_GDI_FAILED;
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;	
	if (VALID_VRE_HANDLE(handle))	
	{
		if (vm_graphic_active_layer(handle) == VM_GDI_SUCCEED) {
			if (layer_trans_tbl[handle].trans_color != VM_NO_TRANS_COLOR) {
				gdi_layer_set_source_key(TRUE, 
					layer_trans_tbl[handle].trans_color);
				gdi_layer_clear(layer_trans_tbl[handle].trans_color);
				//vm_log_debug("clear layer[%d]", handle);
			}
			vm_graphic_active_layer(active_layer);
			return VM_GDI_SUCCEED;
		}
	}
	return VM_GDI_FAILED;
}

VMINT vm_graphic_set_layer_opacity(VMINT handle, VMINT percent) {
//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return VM_GDI_FAILED;
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;

	if((percent < 0) || (percent > 100))
		return VM_GDI_ERR_WRONG_PARAM;
	if (VALID_VRE_HANDLE(handle))
	{
		if (vm_graphic_active_layer(handle) == VM_GDI_SUCCEED) 
		{
			if (gdi_layer_set_opacity(TRUE, (VMUINT8)(percent * 255 / 100)) == GDI_SUCCEED) {
				vm_graphic_active_layer(active_layer);
				return VM_GDI_SUCCEED;
			}
			vm_graphic_active_layer(active_layer);
		}
	}
	
	return VM_GDI_FAILED;
}

VMINT vm_graphic_get_layer_position(VMINT handle, VMINT *x, VMINT *y, 
	VMINT *width, VMINT *height)
{
//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return VM_GDI_FAILED;
//	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
//		return VM_GDI_MIBR_NOT_FORE;
	
	if (!x || !y || !width || !height)
		return VM_GDI_ERR_WRONG_PARAM;
	if (VALID_VRE_HANDLE(handle))
	{
		*x = layer_trans_tbl[handle].x;
		*y = layer_trans_tbl[handle].y;
		*width = layer_trans_tbl[handle].width;
		*height = layer_trans_tbl[handle].height;

		return VM_GDI_SUCCEED;
	}
	
	return VM_GDI_FAILED;
}


VMINT  vm_graphic_get_layer_porp_from_buf(VMUINT8* platform_disp_buffer, VMINT*x,VMINT*y,VMINT *width, VMINT *height)
{
	VMINT i = 0;
	VMINT lx, ly, lw, lh;
	VMINT ret = -1;

//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return VM_GDI_FAILED;
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;
	
	if (!platform_disp_buffer || !width || !height|| !x || !y)
		return VM_GDI_ERR_WRONG_PARAM;

	for (i = 0;  i < MAX_LAYER; i++)
	{
        if ((layer_trans_tbl[i].buffer == platform_disp_buffer) && (layer_trans_tbl[i].used))
        {
            if (vm_graphic_get_layer_position(i, &lx, &ly, &lw, &lh) < 0)
			    return VM_GDI_FAILED;	
            *width = lw;
            *height = lh;  
            *x = lx; 
            *y = ly; 			
            
            ret = 0;
            break;
        }
	}
	if (ret == 0)
		return VM_GDI_SUCCEED;

	return VM_GDI_FAILED;
}


VMINT  vm_graphic_get_layer_porp_from_layer(VMINT handle, VMINT *x , VMINT *y,VMINT *width, VMINT *height)
{
	VMINT lx, ly,lw, lh;
//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return VM_GDI_FAILED;
//	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
//		return VM_GDI_MIBR_NOT_FORE;
	
	if ((INVALID_VRE_HANDLE(handle)) || !width || !height|| !x || !y)
		return VM_GDI_ERR_WRONG_PARAM;

	if (vm_graphic_get_layer_position(handle, &lx, &ly, &lw, &lh) < 0)
		return VM_GDI_FAILED;
	*x = lx;
	*y = ly; 	
	*width = lw;
	*height = lh;            
	return VM_GDI_SUCCEED;
}

VM_GDI_RESULT vm_graphic_layer_set_trans_color(VMINT hhandle, VMINT trans_color)
{
 	//���VRE������Ϸ��������ǿ��ٲ㲻������
	if (INVALID_VRE_HANDLE(hhandle))
	{
		vm_log_error("[graphic] - vm_graphic_layer_set_trans_color : handle ERROR");
		return VM_GDI_FAILED;
	}
		
	layer_trans_tbl[hhandle].trans_color = trans_color;
	gdi_layer_push_and_set_active(SAL_HANDLE(hhandle));
	 (layer_trans_tbl[hhandle].trans_color != VM_NO_TRANS_COLOR) ?
		gdi_layer_set_source_key(TRUE, layer_trans_tbl[hhandle].trans_color) : 
		gdi_layer_set_source_key(FALSE, 0);
	gdi_layer_pop_and_restore_active();
	vm_log_debug("[graphic] - vm_graphic_layer_set_trans_color =%d",layer_trans_tbl[hhandle].trans_color);
	return VM_GDI_SUCCEED;
}


VM_GDI_RESULT vm_graphic_canvas_set_trans_color(VMINT hcanvas, VMINT trans_color)
{
	VMUINT8 *buffer = NULL;
	VMINT handle;
	
	if ((hcanvas < 0) ||((void*)hcanvas == NULL) || ( !is_vre_canvas_buf((VMUINT8 *) hcanvas)))
	{
		vm_log_debug("[graphic] - vm_graphic_canvas_set_trans_color : VM_GDI_ERR_WRONG_PARAM");
		return VM_GDI_ERR_WRONG_PARAM;
	}
		
	buffer = (VMUINT8*)hcanvas;

	buffer[VM_CANVAS_SIGNATURE_SIZE] = 1;
	buffer[VM_CANVAS_SIGNATURE_SIZE + 12] = ((VMUINT16)trans_color) % 256;	
	buffer[VM_CANVAS_SIGNATURE_SIZE + 13] = ((VMUINT16)trans_color) >> 8;

	//������㣬��������
	if ((handle=find_layer(buffer)) == 0)
	{
		vm_log_debug("[graphic] - vm_graphic_canvas_set_trans_color : BASE_LAYER");
		return VM_GDI_SUCCEED;
	}
		
 	//���VRE������Ϸ��������ǿ��ٲ㲻������
	if ((INVALID_VRE_HANDLE(handle)) || ((is_fast_layer > 0) && (handle == is_fast_layer)))
	{
		vm_log_debug("[graphic] - vm_graphic_canvas_set_trans_color : handle %d ERROR",handle);
		return VM_GDI_SUCCEED;
	}
		
	vm_graphic_layer_set_trans_color(handle, trans_color);
	return VM_GDI_SUCCEED;
}




//=====================================================================================


//===============================Textout Function=========================================
#ifdef __VRE_RB_08A__
extern U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query);
#endif

static void _vm_textout_get_baseline(void)
{
    mmi_fe_get_string_info_param_struct query; 
    VMWCHAR test_wstring[128]; 
    memset(test_wstring , 0, sizeof(test_wstring));
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    
    vm_default_to_ucs2(test_wstring, 128 * 2, VM_FONT_TEST_BASELINE_STRING); 
    
    query.String = (U8 *)test_wstring;
    query.n = vm_wstrlen(test_wstring);
    query.enableTruncated = MMI_FALSE;
    query.w = 0;    
    mmi_fe_get_string_widthheight(&query);  
    current_baseline = query.baseline;
    return;
}   



static VMUCHAR font_size;
#ifndef __VRE_RB_08B__ 
void _vm_textout_internal(VMUINT text_x, VMUINT text_y,VMWSTR text, VMINT length, VMUINT32 text_color)
{
	VMINT nlen;
	mmi_fe_color c;
    
	
	c.a = 0;
	c.r = (VMUINT8)(text_color & 0xFF);
	c.g = (VMUINT8)((text_color & 0xFF00) >> 8);
	c.b = (VMUINT8)((text_color & 0xFF0000) >> 16);
	mmi_fe_set_text_color(c);		
	gui_set_font(current_font);
	nlen = vm_wstrlen(text);
	if (length > nlen)
		length = nlen;
    if(length>1)
    {
	mmi_fe_show_string_n(text_x, text_y, (U8 *)text, length);
	return;
    }
    if (current_baseline < 0)
    {
       _vm_textout_get_baseline();
       font_size = current_font->size;
       vm_log_warn("[graphic]-_vm_textout_internal:baseline = %d.",current_baseline);
    }
    else
    {
        if (font_size != current_font->size)
        {
            _vm_textout_get_baseline();
            font_size = current_font->size;
            vm_log_warn("[graphic]-_vm_textout_internal:font_size = %d.",current_font->size);            
        }

    }
	mmi_fe_show_string_n_baseline(text_x, text_y, (U8 *)text, length, current_baseline);
	return;
}
#else
void _vm_textout_internal(VMUINT text_x, VMUINT text_y,VMWSTR text, VMINT length, VMUINT32 text_color)
{
	VMINT nlen;

	UI_set_text_color(UI_color(text_color & 0xFF, (text_color & 0xFF00) >> 8, (text_color & 0xFF0000) >> 16));
	UI_set_font(current_font);
	nlen = vm_wstrlen(text);
	if (length > nlen)
		length = nlen;
    if(length>1)
    {
		UI_move_text_cursor(text_x, text_y);//ltz
		UI_print_text_n((UI_string_type)text, length);//ltz
		return;
    }
    if (current_baseline < 0)
    {
       _vm_textout_get_baseline();
       font_size = current_font->size;
       vm_log_warn("[graphic]-_vm_textout_internal:baseline = %d.",current_baseline);
    }
    else
    {
        if (font_size != current_font->size)
        {
            _vm_textout_get_baseline();
            font_size = current_font->size;
            vm_log_warn("[graphic]-_vm_textout_internal:font_size = %d.",current_font->size);            
        }

    }
	ShowString_n_baseline(text_x, text_y, *current_font, 0, (U8 *)text, length, current_baseline);//ltz
	return;
}
#endif







VMINT vm_graphic_internal_layer_textout(VMUINT8* platform_disp_buffer, 
											   VMUINT text_x, VMUINT text_y, 
											   VMUINT clip_x1, VMUINT clip_y1, VMUINT clip_x2, VMUINT clip_y2,
											   VMWSTR text, VMINT length, VMUINT32 text_color)
{
	U8* ptr = NULL;
	VMINT i = 0;

//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return VM_GDI_FAILED;
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;	

	if (!platform_disp_buffer || !text || (length<=0))
		return VM_GDI_ERR_WRONG_PARAM;

	gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
	gdi_layer_get_buffer_ptr(&ptr);
	if (ptr == platform_disp_buffer)
	{
		gdi_layer_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
        _vm_textout_internal(text_x, text_y,text, length, text_color);
		gdi_layer_pop_and_restore_active();
		return VM_GDI_SUCCEED;
	}
	else
	{
		gdi_layer_pop_and_restore_active();
		for (i = 0; i < MAX_LAYER; i++)
		{
			if  (layer_trans_tbl[i].used)
			{
				gdi_layer_push_and_set_active(SAL_HANDLE(i));
				gdi_layer_get_buffer_ptr(&ptr);
				if (ptr == platform_disp_buffer) 
				{
					gdi_layer_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
                    _vm_textout_internal(text_x, text_y,text, length, text_color);
					gdi_layer_pop_and_restore_active();
					return VM_GDI_SUCCEED;
				}
				gdi_layer_pop_and_restore_active();
			}
		}

		return VM_GDI_FAILED;
	}
}

VM_GDI_RESULT vm_graphic_internal_layer_textout_ex(VMINT handle, 
											   VMUINT text_x, VMUINT text_y, 
											   VMUINT clip_x1, VMUINT clip_y1, VMUINT clip_x2, VMUINT clip_y2,
											   VMWSTR text, VMINT length, VMUINT32 text_color,VMUINT flag)
{
    VMINT str_width;
    if (!text || (length<=0))
		return VM_GDI_ERR_WRONG_PARAM;
	gdi_layer_push_and_set_active(SAL_HANDLE(handle));
	gdi_layer_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    if (flag)
        if ((str_width = vm_graphic_get_string_width(text)) >= 0)
    	    gdi_draw_solid_rect(text_x, text_y, text_x + str_width, text_y + 20, 0);
    _vm_textout_internal(text_x, text_y,text, length, text_color);
	gdi_layer_pop_and_restore_active();
	return VM_GDI_SUCCEED;
}


VMINT vm_graphic_internal_canvas_textout(VMUINT8* platform_disp_buffer, 
												VMUINT width, VMUINT height, VMUINT text_x, VMUINT text_y, 
												VMUINT clip_x1, VMUINT clip_y1, VMUINT clip_x2, VMUINT clip_y2,
												VMWSTR text, VMINT length, VMUINT32 text_color)
{
	gdi_handle gdi_handle = GDI_LAYER_EMPTY_HANDLE;

	VMINT buffer_size;
	
//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return VM_GDI_FAILED;
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;

	if (!platform_disp_buffer || !text || (length<=0))
		return VM_GDI_ERR_WRONG_PARAM;

	buffer_size = width * height * 2 + (width * height * 2 ) % 4;
	if (gdi_layer_create_using_outside_memory(0, 0, width, height,  
		&gdi_handle, platform_disp_buffer, buffer_size) != GDI_SUCCEED)
		return VM_GDI_FAILED;

	gdi_layer_push_and_set_active(gdi_handle);
	gdi_layer_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    _vm_textout_internal(text_x, text_y,text, length, text_color);
	gdi_layer_pop_and_restore_active();

    
	gdi_layer_free(gdi_handle);

	return VM_GDI_SUCCEED;
}







VMINT vm_textout_in_rect(VMINT handle, VMUINT text_x, VMUINT text_y, VMWSTR text, VMINT length, VMUINT32 text_color)
{
	return vm_graphic_internal_layer_textout_ex(handle, text_x, text_y, 
			0, 0, vm_graphic_get_screen_width()-1, vm_graphic_get_screen_height()-1,
			text, length, text_color ,TRUE);	 
}





VM_GDI_RESULT vm_graphic_textout_to_layer (VMINT handle, VMINT x, VMINT y, VMWSTR s, VMINT length)
{
	clip_rect cliprect;
	
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;

	if ((INVALID_VRE_HANDLE(handle)) || (length <= 0))
		return VM_GDI_ERR_WRONG_PARAM;
	
	vm_graphic_get_layer_clip(handle, &cliprect);
	
	return vm_graphic_internal_layer_textout_ex(handle, x, y, 
			cliprect.left, cliprect.top, cliprect.right, cliprect.bottom,
			s, length, VM_COLOR_565_TO_888(vm_graphic_getcolor().vm_color_565),FALSE);		
}

#ifdef __VRE_RB_08A__
extern void gdi_draw_font_by_abm(
                S32 x, 
                S32 y, 
                gdi_color color, 
                U8 *font_data, 
                S32 char_width, 
                S32 char_height);
#endif


VMINT vm_graphic_draw_abm_text(VMINT handle, VMINT x, VMINT y, VMINT color,VMUINT8* font_data,VMINT font_width,VMINT font_height)
{
    VMINT font_byte_width;
    gdi_handle cur_active_layer;
    if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;
    
	if ((INVALID_VRE_HANDLE(handle)) || (!font_data)|| (font_width <= 0) || (font_height <= 0))
		return VM_GDI_ERR_WRONG_PARAM;  

    if (x < layer_trans_tbl[handle].x || x >= (layer_trans_tbl[handle].x + layer_trans_tbl[handle].width))
        return VM_GDI_ERR_WRONG_PARAM; 

    if (y < layer_trans_tbl[handle].y || y >= (layer_trans_tbl[handle].y + layer_trans_tbl[handle].height))
        return VM_GDI_ERR_WRONG_PARAM;     
    
    if (font_height!=12 && font_height!=14 && font_height!=16&& font_height!=18
	&& font_height!=20 && font_height!=22&& font_height!=24
	&& font_height!=26 && font_height!=28&& font_height!=30&& font_height!=32)
        return VM_GDI_FONTSIZE_NOT_SUPPORT;

    
    font_byte_width = font_width;
    if (font_width < 8)
        font_byte_width = 8;    
    else if (font_width % 8)
        font_byte_width = font_width + (8 - font_width % 8); 
    
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));
		gdi_draw_font_by_abm(x,y,color,font_data,font_byte_width,font_height);
		gdi_layer_pop_and_restore_active();
		return VM_GDI_SUCCEED;
	}
	gdi_draw_font_by_abm(x,y,color,font_data,font_byte_width,font_height);
    return VM_GDI_SUCCEED;
}




//===============================Image Function===================================
typedef struct IHDR_t 
{
	VMINT32	width;
	VMINT32	height; 
	VMBYTE	bitdepth; 
	VMBYTE	colortype; 
}IHDR_t;

VMINT vm_graphic_is_gif_file(VMUINT8 *img_data)
{
	if( img_data[0] == 'G' && img_data[1] == 'I' && img_data[2] == 'F')
		return TRUE;
	return FALSE;	
}

VMINT vm_graphic_is_bmp_file(VMUINT8 *img_data)
{
	if( img_data[0] == 'B' && img_data[1] == 'M')
		return TRUE;
	return FALSE;
}

VMINT vm_graphic_is_png_file(VMUINT8 *img_data)
{
	if( img_data[0] == 0x89 && img_data[1] == 0x50 && img_data[2] == 0x4E && img_data[3] == 0x47)
		return TRUE;
	return FALSE;
}

VMINT vm_graphic_is_jpeg_file(VMUINT8 *img_data)
{
	if( img_data[0] == 0xff && img_data[1] == 0xd8 && img_data[2] == 0xff)
		return TRUE;
	return FALSE;
}


VMINT vm_graphic_create_decode_canvas_internal(VMINT width,VMINT height,VMUINT8 **frame_buffer, VMINT * buffer_size)
{
    VMINT hcanvas;
    
    if ((hcanvas = vm_graphic_create_canvas(width, height)) < 0)
	{
		vm_log_warn("vm_graphic_create_decode_canvas_internal-->create_canvas failed!");
		return VM_GDI_ERR_CREATE_CANVAS_FAILED;
	}
	*frame_buffer = (VMUINT8*)hcanvas + VM_CANVAS_SIGNATURE_SIZE + VM_CANVAS_FRAME_PROPERTY_SIZE;
	*buffer_size = width*height*2 + (width*height*2) % 4;    // 4�ֽڶ���
	return hcanvas;
}

/*
�û������崴����ʱ�㣬���������ͼ��
buffer_data:��������
buffer_len:������������С
img_data:δ��������
img_len:δ������������С
img_width,img_height:ʵ�ʻ��ƵĿ��
*/
VMINT vm_graphic_decode_internal(VMUINT8 *buffer_data , VMINT buffer_len, VMUINT8* img_data, VMINT img_len, VMINT img_width, VMINT img_height,VMUINT8 graphic_type, IHDR_t *ihdr, VMINT resize)
{
	gdi_handle layer_handle = 0;
	gdi_handle source_layer_handle;
	GDI_RESULT gdi_hdl_result = GDI_SUCCEED;	    	
	
	if (gdi_layer_create_using_outside_memory(0, 0, img_width, img_height, 
		&layer_handle, buffer_data, buffer_len) != GDI_SUCCEED)
	{
		vm_log_error("[grapvmhic] - vm_graphic_decode_internal : Layer create FAILED!");
		return VM_GDI_ERR_CREATE_LAYER_FAILED;
	}
	if (layer_handle == 0)
	{
		vm_log_error("[graphic] - vm_graphic_decode_internal : Layer create FAILED!");
		return VM_GDI_ERR_CREATE_LAYER_FAILED;
	}
	gdi_layer_push_and_set_active(layer_handle);
	if (graphic_type == GDI_IMAGE_TYPE_PNG)
	{
		if (ihdr->colortype > 3)		//0:gray	2:true color 	3:index	4:gray with alpha	6:true color with alpha
		{
			gdi_layer_set_source_key(TRUE, VM_KEY_COLOR);
			gdi_layer_clear(VM_KEY_COLOR);
		}
		//���ô�͸�㣬���ƺ�ָ�ԭ��͸�㡣
 		gdi_image_abm_get_source_layer(&source_layer_handle);
  		gdi_image_abm_set_source_layer(layer_handle);
	}
	else
		gdi_layer_clear(gdi_act_color_from_rgb(255, 255, 254, 253));

	if (resize)
		gdi_hdl_result = gdi_image_draw_resized_mem(0, 0, img_width,img_height,img_data, graphic_type, img_len);
	else
		gdi_hdl_result = gdi_image_draw_mem(0, 0, img_data, graphic_type, img_len);
	if (gdi_hdl_result != GDI_SUCCEED)
	{
		if (graphic_type == GDI_IMAGE_TYPE_PNG)
			gdi_image_abm_set_source_layer(source_layer_handle);
		gdi_layer_pop_and_restore_active();
		gdi_layer_free(layer_handle);
		layer_handle = 0;
       	return  VM_GDI_ERR_PLATFORM_DECODE_FAILED;
	}
	if (graphic_type == GDI_IMAGE_TYPE_PNG)
		gdi_image_abm_set_source_layer(source_layer_handle);
	
	gdi_layer_pop_and_restore_active();
	gdi_layer_free(layer_handle);
	layer_handle = 0;
	return VM_GDI_SUCCEED;
}



VMINT bmp_get_imgprop(VMUINT8* img_data, VMINT img_len,vm_graphic_imgprop *img_prop)
{
	VMINT img_width, img_height;
	if (gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_BMP, img_data, img_len, &img_width, &img_height) != GDI_SUCCEED)
		return  VM_GDI_FAILED;
	
	img_prop->height = img_height;
	img_prop->width= img_width;	
	return VM_GDI_SUCCEED;
}



VMINT vm_graphic_bmp_decode(VMUINT8* img_data, VMINT img_len)
{
	VMINT img_width, img_height;
	VMINT hcanvas = 0;
	VMUINT8 *frame_buffer = NULL;
	VMINT buffer_size;
    VMINT result;
	GDI_RESULT ret_val;
	vm_log_warn("[graphic] : vm_graphic_bmp_decode B");
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_warn("vm_graphic_bmp_decode-->error img data or len!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	// ��ȡBMP���� 
	ret_val = gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_BMP, img_data, img_len, &img_width, &img_height);
	if (ret_val != GDI_SUCCEED)
	{
		return  VM_GDI_FAILED;
	}
	//��������
	if ((hcanvas = vm_graphic_create_decode_canvas_internal(img_width,img_height, &frame_buffer, &buffer_size)) <= 0)
		return VM_GDI_ERR_CREATE_CANVAS_FAILED;
    
	if ((result = vm_graphic_decode_internal(frame_buffer,buffer_size,img_data,img_len,img_width,img_height,GDI_IMAGE_TYPE_BMP,NULL,FALSE)) < 0)
	{
		vm_graphic_release_canvas(hcanvas);
		return  result;
	}
	return hcanvas;
}


VMINT vm_graphic_bmp_decode_resized(VMUINT8* img_data, VMINT img_len,VMINT width,VMINT height)
{
	VMINT img_width, img_height;
	VMINT hcanvas = 0,hcanvas_l = 0;
	VMUINT8 *frame_buffer = NULL;
	VMUINT8 *frame_buffer_l = NULL;
	VMINT buffer_size,buffer_size_l;
    VMINT result;
	GDI_RESULT ret_val;
 
	vm_log_warn("[graphic] - vm_graphic_bmp_decode_resized : B!");
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_warn("[graphic] - vm_graphic_bmp_decode_resized :Img data or len ERROR!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	// ��ȡBMP���� 
	ret_val = gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_BMP, img_data, img_len, &img_width, &img_height);
	if (ret_val != GDI_SUCCEED)
	{
		vm_log_warn("[graphic] - vm_graphic_bmp_decode_resized : Get dimension ERROR!");
		return  VM_GDI_FAILED;
	}

	//�����ߺ�ԭͼƬ��ͬ��ֱ�ӵ���ԭ����
	if ((width == img_width) && (height == img_height))
		return vm_graphic_bmp_decode(img_data, img_len);
	//����������һ����ԭ��С����ôʹ����С������
	else if ((width < img_width) || (height < img_height))
	{
		//��������
	    if ((hcanvas = vm_graphic_create_decode_canvas_internal(width,height, &frame_buffer, &buffer_size)) <= 0)
		    return VM_GDI_ERR_CREATE_CANVAS_FAILED;
		if ((result = vm_graphic_decode_internal(frame_buffer,buffer_size,img_data,img_len,width,height,GDI_IMAGE_TYPE_BMP ,NULL,TRUE)) < 0)
		{
			vm_graphic_release_canvas(hcanvas);
			return  result;
		}
		return hcanvas;
	}
	//����������һ����ԭ���󣬵��÷Ŵ�����
	else
	{
		//��������
       	if ((hcanvas = vm_graphic_create_decode_canvas_internal(img_width,img_height, &frame_buffer, &buffer_size)) <= 0)
		    return VM_GDI_ERR_CREATE_CANVAS_FAILED;

		if ((result = vm_graphic_decode_internal(frame_buffer,buffer_size,img_data,img_len,img_width,img_height,GDI_IMAGE_TYPE_BMP ,NULL,FALSE)) < 0)
		{
			vm_graphic_release_canvas(hcanvas);
			return  result;
		}

		//�����󻭲�
        if ((hcanvas_l = vm_graphic_create_decode_canvas_internal(width,height, &frame_buffer_l, &buffer_size_l)) <= 0)
        {
            vm_graphic_release_canvas(hcanvas);
            return VM_GDI_ERR_CREATE_CANVAS_FAILED;
        }
		vm_log_warn("[graphic] - vm_graphic_bmp_decode_resized : DONE!");
		enlarge_image(frame_buffer,img_width, img_height, frame_buffer_l, width, height);
		vm_graphic_release_canvas(hcanvas);
		return hcanvas_l;		
	}
}




VMINT jpeg_get_imgprop(VMUINT8* img_data, VMINT img_len,vm_graphic_imgprop *img_prop)
{
	VMINT img_width, img_height;
	if (gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_JPG, img_data, img_len, &img_width, &img_height) != GDI_SUCCEED)
		return  VM_GDI_FAILED;
	
	img_prop->height = img_height;
	img_prop->width= img_width;	
	return VM_GDI_SUCCEED;
}




VMINT vm_graphic_jpeg_decode(VMUINT8* img_data, VMINT img_len)
{
	VMINT img_width, img_height;
	VMINT hcanvas = 0;
	VMUINT8 *frame_buffer = NULL;
	VMINT buffer_size;
    VMINT result;
	GDI_RESULT  ret_val;
 
	vm_log_warn("[graphic] : vm_graphic_jpg_decode B");
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_error("[graphic] - vm_graphic_jpeg_decode : error img data or len!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	// ��ȡJPEG���� 
	ret_val = gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_JPG, img_data, img_len, &img_width, &img_height);
	if (ret_val != GDI_SUCCEED)
	{
		vm_log_error("[graphic] - vm_graphic_jpeg_decode : Get dimension ERROR!");
		return  VM_GDI_FAILED;
	}

	//��������
	if ((hcanvas = vm_graphic_create_decode_canvas_internal(img_width,img_height, &frame_buffer, &buffer_size)) <= 0)
		return VM_GDI_ERR_CREATE_CANVAS_FAILED;    

	if ((result = vm_graphic_decode_internal(frame_buffer,buffer_size,img_data,img_len,img_width,img_height,GDI_IMAGE_TYPE_JPG,NULL,FALSE)) < 0)
	{
		vm_graphic_release_canvas(hcanvas);
		return  result;
	}
	return hcanvas;
}



VMINT vm_graphic_jpeg_decode_resized(VMUINT8* img_data, VMINT img_len,VMINT width,VMINT height)
{
	VMINT img_width, img_height;
	VMINT hcanvas = 0;
	VMINT hcanvas_l = 0;	
	VMUINT8 *frame_buffer = NULL;
	VMUINT8 *frame_buffer_l = NULL;
	VMINT buffer_size;
	VMINT buffer_size_l;
    VMINT result;
	GDI_RESULT  ret_val;
 
	vm_log_warn("[graphic] - vm_graphic_jpeg_decode_resized :B");
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_warn("[graphic] - vm_graphic_jpeg_decode_resized :Img data or len ERROR!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	// ��ȡJPEG���� 
	ret_val = gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_JPG, img_data, img_len, &img_width, &img_height);
	if (ret_val != GDI_SUCCEED)
	{
		vm_log_warn("[graphic] - vm_graphic_jpeg_decode_resized : Get dimension ERROR!");
		return  VM_GDI_FAILED;
	}

		
	//�����ߺ�ԭͼƬ��ͬ��ֱ�ӵ���ԭ����
	if ((width == img_width) && (height == img_height))
		return vm_graphic_jpeg_decode(img_data, img_len);
	//����������һ����ԭ��С����ôʹ����С������
	else if ((width < img_width) || (height < img_height))
	{
	    if ((hcanvas = vm_graphic_create_decode_canvas_internal(width,height, &frame_buffer, &buffer_size)) <= 0)
		    return VM_GDI_ERR_CREATE_CANVAS_FAILED;        

		if ((result = vm_graphic_decode_internal(frame_buffer,buffer_size,img_data,img_len,width,height,GDI_IMAGE_TYPE_JPG,NULL,TRUE)) < 0)
		{
			vm_graphic_release_canvas(hcanvas);
			return  result;
		}
		return hcanvas;
	}
	else
	{
	    if ((hcanvas = vm_graphic_create_decode_canvas_internal(img_width,img_height, &frame_buffer, &buffer_size)) <= 0)
		    return VM_GDI_ERR_CREATE_CANVAS_FAILED;        
    	if ((result = vm_graphic_decode_internal(frame_buffer,buffer_size,img_data,img_len,img_width,img_height,GDI_IMAGE_TYPE_JPG,NULL,FALSE)) < 0)
		{
			vm_graphic_release_canvas(hcanvas);
			return  result;
		}

    	if ((hcanvas_l = vm_graphic_create_decode_canvas_internal(width,height, &frame_buffer_l, &buffer_size_l)) <= 0)
		{
			vm_graphic_release_canvas(hcanvas);            
	    	return VM_GDI_ERR_CREATE_CANVAS_FAILED;        
        }
		vm_log_warn("[graphic] - vm_graphic_jpeg_decode_resized : DONE!");
		enlarge_image(frame_buffer,img_width, img_height, frame_buffer_l, width, height);
		vm_graphic_release_canvas(hcanvas);
		return hcanvas_l;		
	}
}








VMINT vm_graphic_png_get_info(VMUINT8* png_data, VMINT png_len, IHDR_t *ihdr)
{
	VMUINT		cursor = 0;
	
	if ((png_data == NULL) || (png_len <= 0))
	{
		vm_log_warn("vm_graphic_png_decode-->error img data or len!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	ihdr->bitdepth = 0;
	ihdr->colortype = 0;
	ihdr->height = 0;
	ihdr->width = 0;
	
	cursor = 16;		// ��IHDR��ʼ�� 

	ihdr->width = (*(png_data + cursor) <<24) + (*(png_data + cursor + 1) <<16) + (*(png_data + cursor + 2) <<8) + (*(png_data + cursor + 3) );
	cursor += 4;
	ihdr->height = (*(png_data + cursor) <<24) + (*(png_data + cursor + 1) <<16) + (*(png_data + cursor + 2) <<8) + (*(png_data + cursor + 3) );
	cursor += 4;
	ihdr->bitdepth = *(png_data + cursor);
	cursor += 1;
	ihdr->colortype = *(png_data + cursor); 
	return VM_GDI_SUCCEED;
}


VMINT png_get_imgprop(VMUINT8* img_data, VMINT img_len,vm_graphic_imgprop *img_prop)
{
	IHDR_t ihdr;
	if (vm_graphic_png_get_info(img_data, img_len, &ihdr) != GDI_SUCCEED)
		return  VM_GDI_FAILED;

	img_prop->height = ihdr.height;
	img_prop->width= ihdr.width;	
	return VM_GDI_SUCCEED;
}


VMINT vm_graphic_png_decode(VMUINT8* img_data, VMINT img_len)
{
	VMINT hcanvas = 0;
	VMUINT8 *frame_buffer = NULL;
	IHDR_t ihdr;
	VMINT buffer_size;
	VMINT ret;
    VMINT result;

	
	vm_log_warn("[graphic] : vm_graphic_png_decode B");
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_warn("vm_graphic_png_decode-->error img data or len!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	// ��ȡPNG���� 
	ret = vm_graphic_png_get_info(img_data, img_len, &ihdr);
	if (ret != GDI_SUCCEED)
	{
		return  VM_GDI_FAILED;
	}
	   
	if ((hcanvas = vm_graphic_create_decode_canvas_internal(ihdr.width,ihdr.height, &frame_buffer, &buffer_size)) <= 0)
		return VM_GDI_ERR_CREATE_CANVAS_FAILED;    

	if ((result = vm_graphic_decode_internal(frame_buffer,buffer_size,img_data,img_len,ihdr.width,ihdr.height,GDI_IMAGE_TYPE_PNG,&ihdr,FALSE)) < 0)
	{
		vm_graphic_release_canvas(hcanvas);
		return  result;
	}

	//���û�������
	if (ihdr.colortype > 3)		//0:gray	2:true color 	3:index	4:gray with alpha	6:true color with alpha
	{
		vm_graphic_canvas_set_trans_color(hcanvas, VM_KEY_COLOR);
	}
	return hcanvas;
}


			

VMINT vm_graphic_png_decode_resized(VMUINT8* img_data, VMINT img_len,VMINT width,VMINT height)
{
	VMINT hcanvas = 0;
	VMINT hcanvas_l = 0;	
	VMUINT8 *frame_buffer = NULL;
	VMUINT8 *frame_buffer_l = NULL;	
	IHDR_t ihdr;
	VMINT buffer_size;
	VMINT buffer_size_l;	
	VMINT ret;
    VMINT result;
 
	
	vm_log_warn("[graphic] - vm_graphic_png_decode_resized : B");
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_error("[graphic] - vm_graphic_png_decode_resized : Img data or len ERROR!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	// ��ȡPNG���� 
	ret = vm_graphic_png_get_info(img_data, img_len, &ihdr);
	if (ret != GDI_SUCCEED)
	{
		vm_log_error("[graphic] - vm_graphic_png_decode_resized : Get dimension ERROR!");
		return  VM_GDI_FAILED;
	}
	//�����ߺ�ԭͼƬ��ͬ��ֱ�ӵ���ԭ����
	if ((width == ihdr.width) && (height == ihdr.height))
		return vm_graphic_png_decode(img_data, img_len);
	else if ((width <  ihdr.width) || (height < ihdr.height))
	{	
    	if ((hcanvas = vm_graphic_create_decode_canvas_internal(width,height, &frame_buffer, &buffer_size)) <= 0)
	    	return VM_GDI_ERR_CREATE_CANVAS_FAILED;        

		if ((result = vm_graphic_decode_internal(frame_buffer,buffer_size,img_data,img_len,width,height,GDI_IMAGE_TYPE_PNG,&ihdr,TRUE)) < 0)
		{
			vm_graphic_release_canvas(hcanvas);
			return  result;
		}

		//���û�������
		if (ihdr.colortype > 3)		//0:gray	2:true color 	3:index	4:gray with alpha	6:true color with alpha
		{
			vm_graphic_canvas_set_trans_color(hcanvas, VM_KEY_COLOR);
		}
		return hcanvas;
	}
	else
	{
    	if ((hcanvas = vm_graphic_create_decode_canvas_internal(ihdr.width,ihdr.height, &frame_buffer, &buffer_size)) <= 0)
	    	return VM_GDI_ERR_CREATE_CANVAS_FAILED;        

		if ((result = vm_graphic_decode_internal(frame_buffer,buffer_size,img_data,img_len,ihdr.width,ihdr.height,GDI_IMAGE_TYPE_PNG,&ihdr,FALSE)) < 0)
		{
			vm_graphic_release_canvas(hcanvas);
			return  result;
		}


    	if ((hcanvas_l = vm_graphic_create_decode_canvas_internal(width,height, &frame_buffer_l, &buffer_size_l)) <= 0)
		{
			vm_graphic_release_canvas(hcanvas);
			return  VM_GDI_ERR_CREATE_CANVAS_FAILED;
		}            
   
		vm_log_debug("[graphic] - vm_graphic_png_decode_resized : DONE!");
		enlarge_image(frame_buffer, ihdr.width,ihdr.height, frame_buffer_l, width, height);
		vm_graphic_release_canvas(hcanvas);
		return hcanvas_l;		
	}
}




typedef struct gif_info_t
{	VMINT	frames;
	VMINT16 scrWidth,scrHeight;
	VMBYTE	gFlag;
	VMINT	colorRes;
	VMBYTE	gSort;
	VMINT	gSize;								/* The last three bits of Packed Fields of Graphic Control Extension */
	VMBYTE	BKColorIdx;
	VMBYTE	pixelAspectRatio;
	VMBYTE	* gColorTable;
	VMUINT32 fsize;
}gif_info_t;

VMINT vm_graphic_gif_get_trans_color(VMUINT8* color_table, VMINT color_table_len, VMUINT16 *trans_color)
{
	//VMINT i, j;
	//VMINT change_flag;

	if (color_table == NULL || color_table_len <= 0 || trans_color == NULL)
		return VM_GDI_ERR_WRONG_PARAM;
	*trans_color = VM_KEY_COLOR;
/*	
	*trans_color = 0;
	for (i = 0; i < color_table_len/3; i++)
	{
		change_flag = 0;
		for (j = 0; j < color_table_len/3; j++)
		{
			if (*trans_color == (VMUINT16)VM_COLOR_888_TO_565(*(color_table+j*3), *(color_table+j*3+1), *(color_table+j*3+2)))
			{
				(*trans_color) += 1;
				change_flag = 1;
				break;
			}
		}
		if (change_flag == 0)
			break;
	}
*/
	//vm_log_debug("trans_color = %d", *trans_color);
	return VM_GDI_SUCCEED;
}

VMINT vm_graphic_gif_get_frames_prop(VMUINT8* gif, VMINT gif_len,VMINT *frame_count, struct frame_prop **frames_p)
{
	VMINT frame_index;
	gif_info_t image_info;
	VMINT cursor = 0;
	VMBYTE temp;

	VMINT file_end = 0;
	VMBYTE frame_info[14] = {0};	
	VMINT lFlag = 0;	
	VMINT lSize = 0;
	VMINT frame_flag;
	VMINT is_one_frame=0;
	VMUINT16 trans_color = 0xfffe;
	VMINT gcolro_table_size = 0;
    	GDI_RESULT gdi_hdl_result = GDI_SUCCEED;	    

	gdi_hdl_result = gdi_image_get_frame_count_mem(IMAGE_TYPE_GIF, gif, gif_len, frame_count);
        if (gdi_hdl_result != GDI_SUCCEED)
        {
            	return  VM_GDI_FAILED;
        }
	if (*frame_count <= 0)
		return VM_GDI_FAILED;
	if ((	*frames_p = (struct frame_prop *)vm_malloc(sizeof(struct frame_prop) * (*frame_count))) == NULL)
	{
		*frame_count = 0;
		vm_log_error("vm_graphic_gif_get_frames_prop malloc error");
		return VM_GDI_ERR_MALLOC_FAILED;
	}
	memset(*frames_p, 0, sizeof(struct frame_prop) * (*frame_count));
	
	//�Ȼ�ȡȫ����Ϣ	
	cursor += 6;		//6���ֽ�ǩ����
	memcpy(&(image_info.scrWidth),gif+cursor,2); cursor += 2;//�߼���Ļ���
	memcpy(&(image_info.scrHeight),gif+cursor,2); cursor += 2;//�߼���Ļ�߶�
	memcpy(&temp,gif+cursor,1); cursor +=1;//�����
	
	if((temp&0x80) != 0)//ȫ����ɫ���־ /*1000 0000*/ ��7λ
		image_info.gFlag = 1;//����ȫ����ɫ��
	else
		image_info.gFlag = 0;//������ȫ����ɫ��
	image_info.colorRes = ((temp&0x70)>>4)+1;//ɫ�ʷ����򣬵�6��5��4λ/*0111 0000*/ /////////////////////////////
	if(image_info.gFlag)
	{
		if((temp&0x08) != 0)//��3λȫ����ɫ������λ��1����ɫ����ճ���Ƶ�ʵĸߵͽ���������
			image_info.gSort = 1;
		else
			image_info.gSort = 0;
		image_info.gSize = temp&0x07;//ȫ����ɫ���С����2��1��0λ,/*0000 0111*/
	}
	
	memcpy(&(image_info.BKColorIdx),gif+cursor,1); cursor += 1;//����ɫ��ȫ����ɫ���е�����
	memcpy(&(image_info.pixelAspectRatio),gif+cursor,1); cursor += 1;//������Ļ��߱ȣ���������ͼ����������߱�

	if(image_info.gFlag)
	{	
		gcolro_table_size = (1<<(image_info.gSize+1))*3;
		vm_graphic_gif_get_trans_color(gif+cursor, gcolro_table_size, &trans_color);

		//�ɼ��㹫ʽ�õ���ɫ���С
		cursor += (1<<(image_info.gSize+1))*3;
	}
	else
		image_info.gColorTable = NULL;
	image_info.fsize = 0;

	//��һ֡��ʼ��ȡ֡����
	frame_index = 0;
	while(cursor<gif_len && !file_end)
	{
		memset(frame_info, 0, 14);
		memcpy(&temp, gif+cursor, 1); cursor += 1;
		switch(temp)
		{
		case 0x21://��չ�����־		
			memcpy(&temp,gif+cursor,1); cursor += 1;
			switch(temp)
			{	
			case 0xf9://ͼ�������չ�飬ͼ����Ϣ�������ͱ�־
				//vm_log_debug("ͼ�������չ��");
				while(cursor<gif_len)
				{	
					memcpy(&temp,gif+cursor,1); cursor += 1;//���С
					if(temp == 0)
						break;
					if(temp == 4)//���С�̶�Ϊ4���������������־
					{					
						memcpy(frame_info+10,gif+cursor,1); 
						(*frames_p)[frame_index].flag = (*(gif+cursor)) & 0x1;
						cursor += 1;	//�����
						
						memcpy(frame_info+8,gif+cursor,2); 
						(*frames_p)[frame_index].delay_time = (*(gif+cursor)) + ((*(gif+cursor+1)) << 8);
						cursor += 2;		//�ӳ�
						memcpy(frame_info+13,gif+cursor,1); cursor += 1;	//͸��ɫ����
					}					
					else
						cursor += temp;
				}
				break;
			case 0xfe://ע����չ��
			case 0x01://�޸�ʽ�ı���չ��
			case 0xff://Ӧ����չ���ݿ�
				while(cursor<gif_len)
				{	
					memcpy(&temp,gif+cursor,1); cursor += 1;//���С
					if(temp == 0)
						break;
					cursor += temp;
				}
				break;
			default:
				return VM_GDI_SUCCEED;
			}
			break;
		case 0x2c://ͼ��������
		{	
			//vm_log_debug("ͼ��������");
			is_one_frame = TRUE;
			memcpy(frame_info,gif+cursor,2); 
			(*frames_p)[frame_index].left = (*(gif+cursor)) + ((*(gif+cursor+1)) << 8);
			cursor += 2;		//ͼ������ʼ����

			memcpy(frame_info+2,gif+cursor,2); 
			(*frames_p)[frame_index].top = (*(gif+cursor)) + ((*(gif+cursor+1)) << 8);
			cursor += 2;	//ͼ������ʼ����

			memcpy(frame_info+4,gif+cursor,2); 
			(*frames_p)[frame_index].width = (*(gif+cursor)) +((*(gif+cursor+1))  << 8);
			cursor += 2;	//ͼ����

			memcpy(frame_info+6,gif+cursor,2); 
			(*frames_p)[frame_index].height = (*(gif+cursor)) +((*(gif+cursor+1))  << 8);
			cursor += 2;	//ͼ��߶�

			memcpy(&temp,gif+cursor,1); cursor += 1;			//�����

			if((temp&0x80) != 0)
				lFlag = 1;			
			if(lFlag)//���ھֲ���ɫ��
			{				
				lSize = temp&0x07;// ����λ��ʾ�ֲ���ɫ���С /*0000 0111*/

				if (gcolro_table_size <=  (1<<(lSize+1))*3)
					vm_graphic_gif_get_trans_color(gif+cursor, (1<<(lSize+1))*3, &trans_color);

				cursor += (1<<(lSize+1))*3;				
			}
			else	//��û�оֲ���ɫ��ȡȫ����ɫ����Ϊ�ֲ���ɫ���޸�Packed Fields��Ӧλ��
			{
				temp &=0xf8;// /*1111 1000*/
				temp |= 0x80 + image_info.gSize;// /*1000 0000*/
			}
			(*frames_p)[frame_index].trans_color	= trans_color;

			frame_info[11] = temp;
			memcpy(frame_info+12,gif+cursor,1); cursor += 1;//LZW��С���С

			while(cursor<gif_len)//��ȡͼ�����ݣ�һϵ�������ݿ����
			{	
				memcpy(&temp,gif+cursor,1); cursor += 1;
				if(temp == 0)
					break;
				cursor += temp;
				frame_flag = 1;
			}
			frame_index++;
			break;			
		}
		case 0x3b:
			file_end = 1;
			break;
		case 0x00:
			break;
		default:
			return VM_GDI_SUCCEED;
		}
		
	}
	return VM_GDI_SUCCEED;
}


VMINT vm_graphic_gif_decode_frame_internal(VMUINT8* img_data, VMINT img_len, VMINT frame_index, struct frame_prop frame_p,VMUINT8 *frame_buffer,VMINT width,VMINT height,VMINT resized)
{
	gdi_handle gif_layer_handle = 0;
	VMINT buffer_size;
	buffer_size = frame_p.width*frame_p.height*2 + (frame_p.width*frame_p.height*2) % 4;    // 4�ֽڶ���
	if (gdi_layer_create_using_outside_memory(0, 0, frame_p.width, frame_p.height, 
		&gif_layer_handle, frame_buffer, buffer_size) != GDI_SUCCEED)
	{
		vm_log_error("[graphic] - vm_graphic_gif_decode_frame_internal : layer create failed!");
		return VM_GDI_ERR_CREATE_LAYER_FAILED;
	}
	if (gif_layer_handle == 0)
	{
        vm_log_error("[graphic] - vm_graphic_gif_decode_frame_internal : layer create failed!");
		return VM_GDI_ERR_CREATE_LAYER_FAILED;
	}	
	
	gdi_layer_push_and_set_active(gif_layer_handle);
	gdi_layer_set_source_key(TRUE, frame_p.trans_color);
	gdi_layer_clear(frame_p.trans_color);
	
	if (resized)
	{
		gdi_layer_set_clip(0, 0, width, height);
		gdi_image_draw_resized_mem_frames(0-frame_p.left, 0-frame_p.top,width,height,img_data, GDI_IMAGE_TYPE_GIF, (VMUINT)img_len, (VMUINT16)frame_index);
	}
	else
	{
		gdi_layer_set_clip(0, 0, frame_p.width, frame_p.height);
		gdi_image_draw_mem_frames(0-frame_p.left, 0-frame_p.top, img_data, GDI_IMAGE_TYPE_GIF, (VMUINT)img_len, (VMUINT16)frame_index);
	}
		
	gdi_layer_reset_clip();
	gdi_layer_pop_and_restore_active();
	gdi_layer_free(gif_layer_handle);
	gif_layer_handle = 0;
	return VM_GDI_SUCCEED;
}



VMINT vm_graphic_gif_set_frame_prop_by_percent(VMUINT8* buffer, struct frame_prop *frame_p,VMINT percent)
{
	VMINT data_size;

	if((buffer == NULL) || (frame_p == NULL))
		return VM_GDI_ERR_WRONG_PARAM;
	data_size =  (frame_p->width *percent/100) * (frame_p->height *percent/100) * 2+ ((frame_p->width *percent/100) * (frame_p->height *percent/100)* 2) % 4;
	buffer[0] = frame_p->flag;
	buffer[1] = frame_p->left % 256;	buffer[2] = frame_p->left >> 8;	//left
	buffer[3] = frame_p->top % 256;	    buffer[4] = frame_p->top >> 8;	//top
	buffer[5] = ((frame_p->width)*percent /100) % 256;	buffer[6] = ((frame_p->width)*percent /100) >> 8;	//width
	buffer[7] =((frame_p->height)*percent /100) % 256;	buffer[8] = ((frame_p->height)*percent /100) >> 8;		//height
	buffer[9] = frame_p->delay_time% 256;	buffer[10] = frame_p->delay_time >> 8;//delay
	buffer[11] = 0;
	buffer[12] = frame_p->trans_color % 256;	buffer[13] = frame_p->trans_color >> 8; //trans color
	
	buffer[14] = 0;	buffer[15] = 0;
	buffer[16] = data_size & 0x000000ff; 		//data size
	buffer[17] = (data_size & 0x0000ff00) >> 8; 
	buffer[18] = (data_size & 0x00ff0000) >> 16;
	buffer[19] = (data_size & 0xff000000) >> 24;

	return VM_GDI_SUCCEED;
}



VMINT vm_graphic_gif_set_frame_prop(VMUINT8* buffer, struct frame_prop *frame_p)
{
	return vm_graphic_gif_set_frame_prop_by_percent(buffer,frame_p,100);
}


VMINT gif_get_imgprop(VMUINT8* img_data, VMINT img_len,vm_graphic_imgprop *img_prop)
{
	VMINT frame_count = 0;
	struct frame_prop *frames_p = NULL;
	VMINT i;
	VMINT img_width = 0;
	VMINT img_height = 0;

	if (vm_graphic_gif_get_frames_prop(img_data, img_len, &frame_count, &frames_p) < 0 
		|| frame_count <=0 || frames_p == NULL)
		return VM_GDI_FAILED;
	
	for ( i=0; i<frame_count; i++)
	{
	   	if (img_width < frames_p[i].width + frames_p[i].left)
			img_width = frames_p[i].width + frames_p[i].left;
	   	if (img_height < frames_p[i].height+ frames_p[i].top)
			img_height = frames_p[i].height + frames_p[i].top;
	}

	img_prop->height = img_height;
	img_prop->width= img_width;	
	return VM_GDI_SUCCEED;
}



VMINT vm_graphic_gif_decode(VMUINT8* img_data, VMINT img_len)
{
	VMINT frame_count = 0;
	VMINT i;
	struct frame_prop *frames_p = NULL;
	VMUINT8 *frame_buffer = NULL;
	VMUINT8 *frame_data_buffer = NULL;
	VMUINT8 * hcanvas = NULL;
	VMINT canvas_size = 0;
	VMINT total_canvas_size = 0;
    VMINT frame_data_size;
	VMINT ret;


	vm_log_warn("[graphic] - vm_graphic_gif_decode : B");
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_error("[graphic] - vm_graphic_gif_decode : error gif data or len!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	// ��ȡGIF���� 
	ret = vm_graphic_gif_get_frames_prop(img_data, img_len, &frame_count, &frames_p);
	if (ret < 0 || frame_count <=0 || frames_p == NULL)
	{
		vm_log_error("[graphic] - vm_graphic_gif_decode : get frames prop failed!");
		return VM_GDI_FAILED;
	}

	//����ռ�
	total_canvas_size = VM_CANVAS_SIGNATURE_SIZE;
	for ( i=0; i<frame_count; i++)
	{
	    frame_data_size = frames_p[i].width * frames_p[i].height * 2 + (frames_p[i].width * frames_p[i].height * 2) % 4;
		total_canvas_size += VM_CANVAS_FRAME_PROPERTY_SIZE + frame_data_size;
	}

	if ((hcanvas = (VMUINT8*)vm_malloc(total_canvas_size)) == NULL)
	{
		vm_log_error("vm_graphic_gif_decode malloc_hcanvas fail");
		if (frames_p != NULL)
		{
			vm_free(frames_p);
			frames_p = NULL;
		}
		return VM_GDI_ERR_MALLOC_FAILED;		
	}
	memset(hcanvas, 0x00, total_canvas_size);
	
	memcpy(hcanvas, "VOGINSIMG", 9);
	hcanvas[VM_CANVAS_FRAME_NUM_OFFSET] = 0;

	// ��֡���� 
	canvas_size = VM_CANVAS_SIGNATURE_SIZE;
	for ( i=0; i<frame_count; i++)
	{
		hcanvas[VM_CANVAS_FRAME_NUM_OFFSET] += 1;
		//���õ�ǰ֡����
		frame_buffer =  hcanvas + canvas_size;
		vm_graphic_gif_set_frame_prop(frame_buffer, &frames_p[i]);

		//���ڴ�����Ļ����׵�ַ
		frame_data_buffer =  hcanvas + canvas_size + VM_CANVAS_FRAME_PROPERTY_SIZE;
		canvas_size += VM_CANVAS_FRAME_PROPERTY_SIZE 
					+ frames_p[i].width * frames_p[i].height * 2 + (frames_p[i].width * frames_p[i].height * 2)%4;
		
		//�û������崴����ʱ�㣬���������һ֡ͼ��
		vm_graphic_gif_decode_frame_internal(img_data, img_len, i, frames_p[i], frame_data_buffer,0,0,FALSE);
	}
	if (frames_p != NULL)
	{
		vm_free(frames_p);
		frames_p = NULL;
	}
	return (VMINT)hcanvas; 
}


VMINT vm_graphic_gif_decode_resized(VMUINT8* img_data, VMINT img_len,VMINT width,VMINT height)
{
	VMINT frame_count = 0;
	VMINT i;
	struct frame_prop *frames_p = NULL;
	VMUINT8 *frame_buffer = NULL;
	VMUINT8 *frame_data_buffer = NULL;
	VMUINT8 * hcanvas = NULL;
	VMINT canvas_size = 0;
	VMINT total_canvas_size = 0;
   	VMINT frame_data_size;
	VMINT ret;


	vm_log_warn("[graphic] - vm_graphic_gif_decode_resized : B");
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_warn("[graphic] - vm_graphic_gif_decode_resized : error gif data or len!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	// ��ȡGIF���� 
	ret = vm_graphic_gif_get_frames_prop(img_data, img_len, &frame_count, &frames_p);
	if (ret < 0 || frame_count <=0 || frames_p == NULL)
	{
		vm_log_warn("[graphic] - vm_graphic_gif_decode_resized : get frames prop failed!");
		return VM_GDI_FAILED;
	}




	//����ռ�
	total_canvas_size = VM_CANVAS_SIGNATURE_SIZE;
	for ( i=0; i<frame_count; i++)
	{
	    frame_data_size = frames_p[i].width * frames_p[i].height * 2 + (frames_p[i].width * frames_p[i].height * 2) % 4;
		total_canvas_size += VM_CANVAS_FRAME_PROPERTY_SIZE + frame_data_size;
	}

	if ((hcanvas = (VMUINT8*)vm_malloc(total_canvas_size)) == NULL)
	{
		if (frames_p != NULL)
		{
			vm_free(frames_p);
			frames_p = NULL;
		}
		return VM_GDI_ERR_MALLOC_FAILED;		
	}
	memset(hcanvas, 0x00, total_canvas_size);
	
	memcpy(hcanvas, "VOGINSIMG", 9);
	hcanvas[VM_CANVAS_FRAME_NUM_OFFSET] = 0;


	// ��֡���� 
	canvas_size = VM_CANVAS_SIGNATURE_SIZE;
	for ( i=0; i<frame_count; i++)
	{
		hcanvas[VM_CANVAS_FRAME_NUM_OFFSET] += 1;
		//���õ�ǰ֡����
		frame_buffer =  hcanvas + canvas_size;
		vm_graphic_gif_set_frame_prop(frame_buffer, &frames_p[i]);

		//���ڴ�����Ļ����׵�ַ
		frame_data_buffer =  hcanvas + canvas_size + VM_CANVAS_FRAME_PROPERTY_SIZE;
		canvas_size += VM_CANVAS_FRAME_PROPERTY_SIZE 
					+ frames_p[i].width * frames_p[i].height * 2 + (frames_p[i].width * frames_p[i].height * 2)%4;
		
		//�û������崴����ʱ�㣬���������һ֡ͼ��
		vm_graphic_gif_decode_frame_internal(img_data, img_len, i, frames_p[i], frame_data_buffer,width,height,TRUE);
	}
	if (frames_p != NULL)
	{
		vm_free(frames_p);
		frames_p = NULL;
	}
	return (VMINT)hcanvas; 
}


VMINT vm_graphic_gif_decode_resized_by_percent(VMUINT8* img_data, VMINT img_len,VMINT percent)
{
	VMINT frame_count = 0;
	VMINT i;
	struct frame_prop *frames_p = NULL;
	VMUINT8 *frame_buffer = NULL;
	VMUINT8 *frame_buffer_l = NULL;
	VMUINT8 *frame_data_buffer = NULL;
	VMUINT8 *frame_data_buffer_l = NULL;
	VMUINT8 * hcanvas = NULL;
	VMUINT8 * hcanvas_l = NULL;
	VMINT canvas_size = 0;
	VMINT canvas_size_l = 0;
	VMINT total_canvas_size = 0;
	VMINT total_canvas_size_l = 0;
   	VMINT frame_data_size;
   	VMINT frame_data_size_l;
	VMINT ret;
	VMINT width_l,height_l;


	vm_log_warn("[graphic] - vm_graphic_gif_decode_resized_by_percent : B");
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_warn("[graphic] - vm_graphic_gif_decode_resized_by_percent : error gif data or len!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	// ��ȡGIF���� 
	ret = vm_graphic_gif_get_frames_prop(img_data, img_len, &frame_count, &frames_p);
	if (ret < 0 || frame_count <=0 || frames_p == NULL)
	{
		vm_log_error("[graphic] - vm_graphic_gif_decode_resized_by_percent : get frames prop failed!");
		return VM_GDI_FAILED;
	}




	//����ռ�
	total_canvas_size = VM_CANVAS_SIGNATURE_SIZE;
	for ( i=0; i<frame_count; i++)
	{
		frame_data_size = frames_p[i].width * frames_p[i].height * 2 + (frames_p[i].width * frames_p[i].height * 2) % 4;
		total_canvas_size += VM_CANVAS_FRAME_PROPERTY_SIZE + frame_data_size;
	}

	if ((hcanvas = (VMUINT8*)vm_malloc(total_canvas_size)) == NULL)
	{
		if (frames_p != NULL)
		{
			vm_free(frames_p);
			frames_p = NULL;
		}
		return VM_GDI_ERR_MALLOC_FAILED;		
	}
	memset(hcanvas, 0x00, total_canvas_size);
	memcpy(hcanvas, "VOGINSIMG", 9);
	hcanvas[VM_CANVAS_FRAME_NUM_OFFSET] = 0;




	//�����ռ�
	total_canvas_size_l = VM_CANVAS_SIGNATURE_SIZE;
	for ( i=0; i<frame_count; i++)
	{
		frame_data_size_l = (frames_p[i].width * percent /100) * (frames_p[i].height  * percent / 100) * 2 + ( (frames_p[i].width * percent /100) * (frames_p[i].height  * percent / 100)*2) % 4;
		total_canvas_size_l += VM_CANVAS_FRAME_PROPERTY_SIZE + frame_data_size_l;
	}

	if ((hcanvas_l = (VMUINT8*)vm_malloc(total_canvas_size_l)) == NULL)
	{
		if (frames_p != NULL)
		{
			vm_free(frames_p);
			frames_p = NULL;
		}
		return VM_GDI_ERR_MALLOC_FAILED;		
	}
	memset(hcanvas_l, 0x00, total_canvas_size_l);
	memcpy(hcanvas_l, "VOGINSIMG", 9);
	hcanvas_l[VM_CANVAS_FRAME_NUM_OFFSET] = 0;

	





	// ��֡���� 
	canvas_size = VM_CANVAS_SIGNATURE_SIZE;
	canvas_size_l = VM_CANVAS_SIGNATURE_SIZE;
	for ( i=0; i<frame_count; i++)
	{
		hcanvas[VM_CANVAS_FRAME_NUM_OFFSET] += 1;
		hcanvas_l[VM_CANVAS_FRAME_NUM_OFFSET] += 1;
		//���õ�ǰ֡����
		frame_buffer =  hcanvas + canvas_size;
		vm_graphic_gif_set_frame_prop(frame_buffer, &frames_p[i]);
		frame_buffer_l =  hcanvas_l + canvas_size_l;
		vm_graphic_gif_set_frame_prop_by_percent(frame_buffer_l, &frames_p[i],percent);		

		//���ڴ�����Ļ����׵�ַ
		frame_data_buffer =  hcanvas + canvas_size + VM_CANVAS_FRAME_PROPERTY_SIZE;
		canvas_size += VM_CANVAS_FRAME_PROPERTY_SIZE 
					+ frames_p[i].width * frames_p[i].height * 2 + (frames_p[i].width * frames_p[i].height * 2)%4;
		frame_data_buffer_l =  hcanvas_l + canvas_size_l + VM_CANVAS_FRAME_PROPERTY_SIZE;
		canvas_size_l += VM_CANVAS_FRAME_PROPERTY_SIZE 
					+ (frames_p[i].width * percent /100) * (frames_p[i].height  * percent / 100) * 2 + ( (frames_p[i].width * percent /100) * (frames_p[i].height  * percent / 100)*2) % 4;		
		
		//�û������崴����ʱ�㣬���������һ֡ͼ��
		vm_graphic_gif_decode_frame_internal(img_data, img_len, i, frames_p[i], frame_data_buffer,0,0,FALSE);
		width_l = frames_p[i].width * percent /100;
		height_l = frames_p[i].height* percent /100;
		enlarge_image(frame_data_buffer, frames_p[i].width,frames_p[i].height, frame_data_buffer_l,width_l, height_l);
	}
	if (frames_p != NULL)
	{
		vm_free(frames_p);
		frames_p = NULL;
	}
	vm_free(hcanvas);
	return (VMINT)hcanvas_l; 
}








extern VMUINT8* dd_load_image(VMUINT8 *img, VMINT img_len);




VMINT vm_graphic_load_image(VMUINT8 *img_data, VMINT img_len)
{
	VMINT ret;
	vm_log_warn("[graphic] : vm_graphic_load_image B");
//	if (_vm_get_status() != MOD_STATUS_RUNNING)
//		return VM_GDI_FAILED;
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;
    vm_log_warn("[graphic] : vm_graphic_load_image B1 img_data=%x",img_data);    
	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_error("vm_graphic_load_image-->error img data or len!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	
	if (vm_graphic_is_gif_file(img_data))
	{
#ifndef VM_USE_VRE_GIF_SOFT_DECODE		
		ret = vm_graphic_gif_decode( img_data, img_len);
		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_load_image:load gif failed");
			return ret;
		}
#else
		ret = (VMINT)dd_load_image( img_data, img_len);
		if (ret <= 0)
		{
			vm_log_error("[graphic]-vm_graphic_load_image:load gif failed");
			return ret;
		}
#endif
		return ret;
	}
	else if(vm_graphic_is_bmp_file(img_data))
	{
		ret = vm_graphic_bmp_decode( img_data, img_len);

		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_load_image:load bmp failed");
			return ret;
		}
		return ret;
	}
	else if(vm_graphic_is_png_file(img_data))
	{
		ret = vm_graphic_png_decode( img_data, img_len);

		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_load_image:load png failed");
			return ret;
		}
		return ret;
	}
	else if(vm_graphic_is_jpeg_file(img_data))
	{
		ret = vm_graphic_jpeg_decode( img_data, img_len);

		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_load_image:load jpeg failed");
			return ret;
		}
		return ret;
	}

	vm_log_error("[graphic]-vm_graphic_load_image:image type is not supported!");
	return VM_GDI_ERR_UNSUPPORT_IMAGE_TYPE;
}


	



VMINT vm_graphic_load_image_resized(VMUINT8 *img_data, VMINT img_len,VMINT width,VMINT height)
{
	VMINT ret;

	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;

	if ((width <= 0) || (height <=  0))
		return VM_GDI_ERR_WRONG_PARAM;

	if ((img_data == NULL) || (img_len <= 0))
	{
		vm_log_warn("vm_graphic_load_image-->error img data or len!");
		return VM_GDI_ERR_WRONG_PARAM;
	}
	
	if (vm_graphic_is_gif_file(img_data))
	{
		ret = vm_graphic_gif_decode_resized( img_data, img_len,width,height);
		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_load_image_resized:load gif failed");
			return ret;
		}
		return ret;
	}
	else if(vm_graphic_is_bmp_file(img_data))
	{
		ret = vm_graphic_bmp_decode_resized( img_data, img_len,width,height);
		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_load_image_resized:load bmp failed");
			return ret;
		}
		return ret;
	}
	else if(vm_graphic_is_png_file(img_data))
	{
		ret = vm_graphic_png_decode_resized( img_data, img_len,width,height);
		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_load_image_resized:load png failed");
			return ret;
		}
		return ret;
	}
	else if(vm_graphic_is_jpeg_file(img_data))
	{
		ret = vm_graphic_jpeg_decode_resized( img_data, img_len,width,height);
		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_load_image_resized:load jpeg failed");
			return ret;
		}
		return ret;
	}

	vm_log_error("[graphic]-vm_graphic_load_image_resized:image type is not supported!");
	return VM_GDI_ERR_UNSUPPORT_IMAGE_TYPE;
}


VMINT vm_graphic_load_gif_resized_by_percent(VMUINT8 *img_data, VMINT img_len,VMINT percent)
{
	VMINT ret;
	if((img_data  == NULL) ||( img_len <=0)||(percent <= 100))
		return VM_GDI_ERR_WRONG_PARAM;
	if(!(vm_graphic_is_gif_file(img_data)))
		return VM_GDI_ERR_UNSUPPORT_IMAGE_TYPE;
	ret = vm_graphic_gif_decode_resized_by_percent( img_data, img_len,percent);
	if (ret < 0)
	{
		vm_log_error("[graphic]-vm_graphic_load_gif_resized_by_percent:load gif failed");
		return ret;
	}
	return ret;	

}

VM_GDI_RESULT vm_graphic_get_img_property_ex(VMUINT8 *img_data, VMINT img_len,vm_graphic_imgprop * img_prop)
{
	VMINT ret;
	if ((img_data  == NULL) ||( img_len <=0)|| (img_prop == NULL))
		return VM_GDI_ERR_WRONG_PARAM;
	
	if (vm_graphic_is_gif_file(img_data))
	{
		ret = gif_get_imgprop(img_data, img_len,img_prop);
		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_get_img_property_ex:get gif prop failed");
			return VM_GDI_FAILED;
		}
		return ret;
	}
	else if(vm_graphic_is_bmp_file(img_data))
	{
		ret = bmp_get_imgprop(img_data, img_len,img_prop);
		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_get_img_property_ex:get bmp prop failed");
			return VM_GDI_FAILED;
		}
		return ret;
	}
	else if(vm_graphic_is_png_file(img_data))
	{
		ret =png_get_imgprop(img_data, img_len,img_prop);
		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_get_img_property_ex:get png prop failed");
			return VM_GDI_FAILED;
		}
		return ret;
	}
	else if(vm_graphic_is_jpeg_file(img_data))
	{
		ret = jpeg_get_imgprop(img_data, img_len,img_prop);
		if (ret < 0)
		{
			vm_log_error("[graphic]-vm_graphic_get_img_property_ex:get jpeg prop failed");
			return VM_GDI_FAILED;
		}
		return ret;
	}

	vm_log_warn("image type is not supported!");
	return VM_GDI_ERR_UNSUPPORT_IMAGE_TYPE;


}




extern VMINT vm_file_count(void);
VMINT _vm_show_malloc_stat(VMINT handle)
{

	malloc_stat_t* mem_state = NULL;
	VMCHAR str[100];
	VMWCHAR wstr[100];
	VMUINT32 color = 0xffffff;
	VMINT offset_y;

	if (handle < layer_count && handle >= 0)
	{
		mem_state = vm_get_malloc_stat();
		offset_y = vm_graphic_get_screen_width();
		sprintf(str, "��ǰ:%d", mem_state->current);
		//vm_gb2312_to_ucs2(wstr, 100, str);
		vm_default_to_ucs2(wstr, 100, str);
		vm_textout_in_rect(handle, 120, 2, wstr, vm_wstrlen(wstr), color);
	
		sprintf(str, "���:%d", mem_state->peak);
		//vm_gb2312_to_ucs2(wstr, 100, str);
		vm_default_to_ucs2(wstr, 100, str);
		vm_textout_in_rect(handle, 120, 22, wstr, vm_wstrlen(wstr), color);

		sprintf(str, "ʣ��:%d", mem_state->avail_heap_size);
		//vm_gb2312_to_ucs2(wstr, 100, str);
		vm_default_to_ucs2(wstr, 100, str);
		vm_textout_in_rect(handle, 120, 42, wstr, vm_wstrlen(wstr), color);

		sprintf(str, "�ļ�:%d", vm_file_count());
		//vm_gb2312_to_ucs2(wstr, 100, str);
		vm_default_to_ucs2(wstr, 100, str);
		vm_textout_in_rect(handle, 120, 62, wstr, vm_wstrlen(wstr), color);
		return VM_GDI_SUCCEED;
	}
	
	return VM_GDI_FAILED;
}

//=====================================NEW Layer Function===========================
VM_GDI_RESULT vm_graphic_flatten_layer(VMINT *hhandle,VMINT count)
{
	gdi_handle flatten_handles[MAX_FLATTEN_LAYER];
	VMINT err = TRUE;
	VMINT i;
	if ((count > MAX_FLATTEN_LAYER) ||(hhandle == NULL))
		return VM_GDI_ERR_WRONG_PARAM;

	//���úϲ���MTK�����������Ӧ��VRE�������ȷ������Ϊ0
	for (i = 0; i < MAX_FLATTEN_LAYER; i++) 
	{
        flatten_handles[i] = 0;
        if (i < count) 
			if (VALID_VRE_HANDLE(hhandle[i]))
				flatten_handles[i] = layer_trans_tbl[hhandle[i]].handle;
	}
	vm_log_debug("[graphic] -vm_graphic_flatten_layer : flatten_handles=%u,%u,%u,%u",flatten_handles[0],flatten_handles[1],flatten_handles[2],flatten_handles[3]);	
	//�������MTK�����Ϊ0������󷵻ء�
	for (i=0;i<MAX_FLATTEN_LAYER;i++)
	{
		if(flatten_handles[i])
		{
			err = FALSE;
			break;
		}
	}	
	if (err)
		return VM_GDI_FAILED;
	

	vm_graphic_sal_flatten_layer(
		flatten_handles[0] ,
		flatten_handles[1] ,
		flatten_handles[2] ,
		flatten_handles[3] ,
		0,
		0);


	vm_log_debug("[graphic] -vm_graphic_flatten_layer : active layer=%d",active_layer);
	for(i=0;i<count;i++)
	{
		if ((VALID_VRE_HANDLE(hhandle[i])) && (hhandle[i] != active_layer))
			if (vm_graphic_delete_layer(hhandle[i]) < 0)
				return VM_GDI_ERR_FREE_RES; 
	}
	return VM_GDI_SUCCEED;

}


VM_GDI_RESULT  vm_graphic_flatten_canvas(VMINT *hcanvas,VMINT count)
{
	VMINT handles[MAX_FLATTEN_LAYER];
	gdi_handle flatten_handles[MAX_FLATTEN_LAYER];
	VMINT err = TRUE;
	VMINT i;
	if ((count > MAX_FLATTEN_LAYER) ||(hcanvas == NULL))
		return VM_GDI_ERR_WRONG_PARAM;
	//��ʼ��ʱ��VRE����Ĵ���ֵ��Ϊ-1
	for (i=0;i<MAX_FLATTEN_LAYER;i++)
		handles[i] = -1;

	//���һ����Ķ�Ӧ�㣬���û�ҵ�����Ϊ-1
	for(i=0;i<count;i++)
	{
        if (VALID_VRE_HANDLE(handles[i]))
            if ((handles[i] = find_layer((VMUINT8 *)hcanvas[i])) <= 0)
			    handles[i] = -1;
	}
	vm_log_debug("[graphic] -vm_graphic_flatten_canvas : handles=%d,%d,%d,%d",handles[0],handles[1],handles[2],handles[3]);

	//���úϲ���MTK�����������Ӧ��VRE�������ȷ������Ϊ0
	for (i = 0; i < MAX_FLATTEN_LAYER; i++) 
	{
        flatten_handles[i] = 0;
        if (i < count) 
			if (VALID_VRE_HANDLE(handles[i]))
				flatten_handles[i] = layer_trans_tbl[handles[i]].handle;
	}
	vm_log_debug("[graphic] -vm_graphic_flatten_canvas : flatten_handles=%u,%u,%u,%u",flatten_handles[0],flatten_handles[1],flatten_handles[2],flatten_handles[3]);	
	//�������MTK�����Ϊ0������󷵻ء�
	for (i=0;i<MAX_FLATTEN_LAYER;i++)
	{
		if(flatten_handles[i])
		{
			err = FALSE;
			break;
		}
	}	
	if (err)
		return VM_GDI_FAILED;
	

	vm_graphic_sal_flatten_layer(
		flatten_handles[0] ,
		flatten_handles[1] ,
		flatten_handles[2] ,
		flatten_handles[3] ,
		0,
		0);
	vm_log_debug("[graphic] -vm_graphic_flatten_canvas : active layer=%d",active_layer);
	for(i=0;i<count;i++)
	{
		if ((VALID_VRE_HANDLE(handles[i])) && (handles[i] != active_layer))
			if (vm_graphic_release_canvas_ex(hcanvas[i]) < 0)
				return VM_GDI_ERR_FREE_RES; 
	}
	return VM_GDI_SUCCEED;	 
}


VM_GDI_RESULT  vm_graphic_resize_layer(VMINT handle,VMINT width,VMINT height)
{
	VMINT lx,ly,lw,lh;
	if ((INVALID_VRE_HANDLE(handle)) || (width <= 0) || (height <= 0))
		return VM_GDI_ERR_WRONG_PARAM;	
	if (vm_graphic_get_layer_porp_from_layer(handle, &lx, &ly,  &lw,  &lh) < 0)
		return VM_GDI_FAILED;
	if ((width > lw) || (height > lh))
		return VM_GDI_ERR_WRONG_PARAM;
	return vm_graphic_sal_resize_layer(SAL_HANDLE(handle),width,height);
}


VMUINT vm_graphic_get_trans_handle(VMINT handle)
{
	if (INVALID_VRE_HANDLE(handle))
		return 0;
	if (layer_trans_tbl[handle].used)
		return SAL_HANDLE(handle);
	else
		return 0;
}


VM_GDI_RESULT vm_graphic_get_layer_clip(VMINT handle ,clip_rect * curcliprect)
{
	gdi_handle cur_active_layer;
	VMINT x1,x2,y1,y2;
	if ((INVALID_VRE_HANDLE(handle)) || (curcliprect == NULL))
		return VM_GDI_ERR_WRONG_PARAM;	
		
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle)!= cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));	
		gdi_layer_get_clip(&x1,&y1,&x2, &y2);
		curcliprect->left = (VMINT16)x1;
		curcliprect->top = (VMINT16)y1;
		curcliprect->right = (VMINT16)x2;
		curcliprect->bottom = (VMINT16)y2;		
		curcliprect->flag = 1;
		gdi_layer_pop_and_restore_active();
		vm_log_debug("[graphic] - vm_graphic_get_layer_clip : x1=%d,y1=%d,x2=%d,y2=%d",x1,y1,x2,y2);
		return VM_GDI_SUCCEED;
	}
	gdi_layer_get_clip(&x1,&y1,&x2, &y2);
	curcliprect->left =(VMINT16) x1;
	curcliprect->top = (VMINT16)y1;
	curcliprect->right = (VMINT16)x2;
	curcliprect->bottom = (VMINT16)y2;		
	curcliprect->flag = 1;
	vm_log_debug("[graphic] - vm_graphic_get_layer_clip : x1=%d,y1=%d,x2=%d,y2=%d",x1,y1,x2,y2);
	return VM_GDI_SUCCEED;
	
}

VM_GDI_RESULT vm_graphic_set_layer_clip(VMINT handle ,VMINT16 x1,VMINT16 y1,VMINT16 x2,VMINT16 y2)
{
	VMINT width,height,tmp;
	gdi_handle cur_active_layer;
	if (INVALID_VRE_HANDLE(handle))
		return VM_GDI_ERR_WRONG_PARAM;
	width = layer_trans_tbl[handle].width -1;
	height = layer_trans_tbl[handle].height -1;
	VRE_LIMIT_VALUE(x1, 0, width);
	VRE_LIMIT_VALUE(y1, 0, height);
	VRE_LIMIT_VALUE(x2, 0, width);
	VRE_LIMIT_VALUE(y2, 0, height);
	if (x1 >x2)
	{
		tmp = x2;
		x2 = x1;
		x1 =tmp;
	}
	if (y1 >y2)
	{
		tmp = y2;
		y2 = y1;
		y1 =tmp;
	}	
	
	vm_log_debug("[graphic] - vm_graphic_set_layer_clip : x1=%d,y1=%d,x2=%d,y2=%d",x1,y1,x2,y2);	
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle)!= cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));	
		gdi_layer_set_clip((VMINT)x1, (VMINT)y1,(VMINT)x2, (VMINT)y2);
		gdi_layer_pop_and_restore_active();
		return VM_GDI_SUCCEED;
	}
	gdi_layer_set_clip((VMINT)x1, (VMINT)y1,(VMINT)x2, (VMINT)y2);
	vm_graphic_set_clip_internal(x1, y1, x2, y2); //��
	return VM_GDI_SUCCEED;
}
//��
VM_GDI_RESULT vm_graphic_set_layer_clip_internal(VMINT handle ,VMINT16 x1,VMINT16 y1,VMINT16 x2,VMINT16 y2)
{
	VMINT width,height,tmp;
	gdi_handle cur_active_layer;
	if (INVALID_VRE_HANDLE(handle))
		return VM_GDI_ERR_WRONG_PARAM;
	width = layer_trans_tbl[handle].width -1;
	height = layer_trans_tbl[handle].height -1;
	VRE_LIMIT_VALUE(x1, 0, width);
	VRE_LIMIT_VALUE(y1, 0, height);
	VRE_LIMIT_VALUE(x2, 0, width);
	VRE_LIMIT_VALUE(y2, 0, height);
	if (x1 >x2)
	{
		tmp = x2;
		x2 = x1;
		x1 =tmp;
	}
	if (y1 >y2)
	{
		tmp = y2;
		y2 = y1;
		y1 =tmp;
	}	
	
	vm_log_debug("[graphic] - vm_graphic_set_layer_clip : x1=%d,y1=%d,x2=%d,y2=%d",x1,y1,x2,y2);	
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle)!= cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));	
		gdi_layer_set_clip((VMINT)x1, (VMINT)y1,(VMINT)x2, (VMINT)y2);
		gdi_layer_pop_and_restore_active();
		return VM_GDI_SUCCEED;
	}
	gdi_layer_set_clip((VMINT)x1, (VMINT)y1,(VMINT)x2, (VMINT)y2);
	//vm_graphic_set_clip(x1, y1, x2, y2);
	return VM_GDI_SUCCEED;
}

VM_GDI_RESULT vm_graphic_translate_layer(VMINT handle , VMINT tx, VMINT ty)
{
	gdi_handle cur_active_layer;
	if (INVALID_VRE_HANDLE(handle))
		return VM_GDI_ERR_WRONG_PARAM;		
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle)!= cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));	
		gdi_layer_set_position(tx, ty);
		gdi_layer_pop_and_restore_active();
		layer_trans_tbl[handle].x = tx;
		layer_trans_tbl[handle].y = ty;
		return VM_GDI_SUCCEED;
	}
	gdi_layer_set_position(tx, ty);
	layer_trans_tbl[handle].x = tx;
	layer_trans_tbl[handle].y = ty;
	return VM_GDI_SUCCEED;
}


VM_GDI_RESULT vm_graphic_rotate_layer(VMINT handle, vm_graphic_rotate_value rotatevalue)
{
	gdi_handle cur_active_layer;
	if (INVALID_VRE_HANDLE(handle))
		return VM_GDI_ERR_WRONG_PARAM;		
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle)!= cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));	
		gdi_layer_set_rotate((VMUINT8)rotatevalue);
		layer_trans_tbl[handle].rotate = (VMINT)rotatevalue;
		gdi_layer_pop_and_restore_active();
		return VM_GDI_SUCCEED;
	}
	gdi_layer_set_rotate((VMUINT8)rotatevalue);
	layer_trans_tbl[handle].rotate = (VMINT)rotatevalue;
	return VM_GDI_SUCCEED;
}


VM_GDI_RESULT vm_graphic_setpen(vm_graphic_pen *pen)
{
	if (!pen)
		return VM_GDI_ERR_WRONG_PARAM;
	if ((pen->cycle == 0) || (pen->bitvalues == NULL))
		return VM_GDI_ERR_WRONG_PARAM;
	global_pen.cycle= pen->cycle;
	global_pen.bitvalues= pen->bitvalues;
	return VM_GDI_SUCCEED;
}

vm_graphic_pen  vm_graphic_getpen(void)
{
	return global_pen;
}

VM_GDI_RESULT vm_graphic_setcolor(vm_graphic_color* color)
{
	if (!color)
		return VM_GDI_ERR_WRONG_PARAM;
	global_color.vm_color_565= color->vm_color_565;
	global_color.vm_color_888= color->vm_color_888;
	return VM_GDI_SUCCEED;	
}

vm_graphic_color vm_graphic_getcolor(void)
{
	return global_color;
}



//====================================2D Function=========================================
void vm_graphic_line_ex(VMINT handle,VMINT x1,VMINT y1,VMINT x2,VMINT y2)
{

	gdi_handle cur_active_layer;
	if (INVALID_VRE_HANDLE(handle))
		return;
	
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));	
		gdi_draw_line(x1, y1, x2, y2, global_color.vm_color_565);
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_line(x1, y1, x2, y2, global_color.vm_color_565);
	return;	
}	


void vm_graphic_set_pixel_ex(VMINT handle,VMINT x1,VMINT y1)
{
	gdi_handle cur_active_layer;
//	vm_log_error("[vmgraphic]: vm_graphic_set_pixel_ex 111");
	if (INVALID_VRE_HANDLE(handle))
		return;
	//	vm_log_error("[vmgraphic]: vm_graphic_set_pixel_ex 222");
	gdi_layer_get_active(&cur_active_layer);
	
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
	//	vm_log_error("[vmgraphic]: vm_graphic_set_pixel_ex 333");
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));	
		gdi_draw_point(x1, y1, global_color.vm_color_565);		
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_point(x1, y1, global_color.vm_color_565);
}



void vm_graphic_line_style(VMINT handle,VMINT x1,VMINT y1,VMINT x2,VMINT y2)
{

	gdi_handle cur_active_layer;
	if (INVALID_VRE_HANDLE(handle))
		return;	
	if ((global_pen.cycle == 0) || (global_pen.bitvalues == NULL))
		return;
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));	
		gdi_draw_line_style
			(x1, y1, x2, y2, global_color.vm_color_565,global_pen.cycle, global_pen.bitvalues);
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_line_style
		(x1, y1, x2, y2, global_color.vm_color_565,global_pen.cycle, global_pen.bitvalues);
	return;
		
}	



void vm_graphic_roundrect_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height, VMINT frame_width)
{
    VMUINT8 * buf;
	
	if ((INVALID_VRE_HANDLE(handle)) || (width <=0) || (height <=0) || (frame_width < 0))
		return ;
    buf = vm_graphic_get_layer_buffer(handle);
    vm_graphic_roundrect(buf, x, y, width, height, frame_width, global_color.vm_color_565);
	return;
}


void vm_graphic_rect_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height)
{

	gdi_handle cur_active_layer;
	if ((INVALID_VRE_HANDLE(handle)) || (width <= 0) ||(height<=0))
		return;	
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));	
		gdi_draw_rect(x,y,x+width - 1,y+height -1, global_color.vm_color_565);//��
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_rect(x,y,x+width-1,y+height-1, global_color.vm_color_565);//��
	return;
}

void vm_graphic_arc(VMINT handle, VMINT x, VMINT  y, VMINT  r, VMINT  startangle, VMINT  angleextent)
{
	gdi_handle cur_active_layer;
	if (INVALID_VRE_HANDLE(handle))
		return;	
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));
		gdi_draw_arc(x,y,r, startangle, angleextent, global_color.vm_color_565);
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_arc(x,y,r, startangle, angleextent, global_color.vm_color_565);
	return;
}


void vm_graphic_ellipse_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height)
{	
    VMUINT8 * buf;

    if ((width <=0) || (height <=0) || (INVALID_VRE_HANDLE(handle)))
		return;
	buf = vm_graphic_get_layer_buffer(handle);
    vm_graphic_ellipse(buf,x,y,width,height,global_color.vm_color_565);
    return;
}

void vm_graphic_polygon(VMINT handle, vm_graphic_point * points,VMINT npoint)
{
	gdi_handle cur_active_layer;
	if ((INVALID_VRE_HANDLE(handle)) || (npoint <= 0) || (points ==  NULL))
		return;	
#ifdef __VRE_RB_08A__
	return;
#endif		
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));
		gdi_draw_polygon((gdi_point2D_struct *)points, npoint,global_color.vm_color_565);
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_polygon((gdi_point2D_struct *)points, npoint,global_color.vm_color_565);
	return;
}

void vm_graphic_fill_roundrect_ex(VMINT handle, VMINT x, VMINT y, VMINT width, VMINT height, VMINT  frame_width)
{
    VMUINT8 * buf;

	if ((frame_width<0) || (width <=0) || (height <=0) ||(INVALID_VRE_HANDLE(handle)))
		return ;
    buf = vm_graphic_get_layer_buffer(handle);
    vm_graphic_fill_roundrect(buf, x, y, width, height, frame_width, global_color.vm_color_565);
    return;
}

void vm_graphic_fill_rect_ex(VMINT handle, VMINT  x, VMINT  y, VMINT  width, VMINT  height)
{
	gdi_handle cur_active_layer;
	if ((INVALID_VRE_HANDLE(handle)) || (width <= 0) ||(height<=0))
		return;	
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));
		gdi_draw_solid_rect(x,y,x+width,y+height, global_color.vm_color_565);
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_solid_rect(x,y,x+width,y+height, global_color.vm_color_565);
	return;
}

void vm_graphic_fill_ellipse_ex(VMINT handle, VMINT  x, VMINT  y, VMINT  width, VMINT  height)
{
    VMUINT8 * buf;
    if ((width <=0) || (height <=0) ||(INVALID_VRE_HANDLE(handle)))
		return;
    buf = vm_graphic_get_layer_buffer(handle);
    vm_graphic_fill_ellipse(buf, x, y, width, height, global_color.vm_color_565);
    return;
}

void vm_graphic_fill_arc(VMINT handle, VMINT x, VMINT y, VMINT r, VMINT startAngle, VMINT angleextent)
{
	gdi_handle cur_active_layer;
	if (INVALID_VRE_HANDLE(handle))
		return;	
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));
		gdi_draw_solid_arc(x,y,r, startAngle,angleextent,global_color.vm_color_565);
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_solid_arc(x,y,r, startAngle,angleextent,global_color.vm_color_565);
	return;
}


void vm_graphic_fill_polygon(VMINT handle, vm_graphic_point * points,VMINT npoint)
{
	gdi_handle cur_active_layer;
	if ((INVALID_VRE_HANDLE(handle)) || (npoint <= 0) || (points ==  NULL))
		return;	
#ifdef __VRE_RB_08A__
	return;
#endif			
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle) != cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));
		gdi_draw_solid_polygon((gdi_point2D_struct *)points,npoint,global_color.vm_color_565);
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_solid_polygon((gdi_point2D_struct *)points,npoint,global_color.vm_color_565);
	return;
}

void vm_graphic_gradient_paint_rect(VMINT handle, VMINT x1, VMINT y1, VMINT x2, VMINT y2, vm_graphic_color color_start, vm_graphic_color color_end,vm_graphic_gp_style style)
{
	gdi_handle cur_active_layer;
	if (INVALID_VRE_HANDLE(handle))
		return;	
	gdi_layer_get_active(&cur_active_layer);
	if (SAL_HANDLE(handle)!= cur_active_layer)
	{
		gdi_layer_push_and_set_active(SAL_HANDLE(handle));
		gdi_draw_gradient_rect(x1, y1, x2, y2, color_start.vm_color_565, color_end.vm_color_565, 0, 0, style);
		gdi_layer_pop_and_restore_active();
		return;
	}
	gdi_draw_gradient_rect(x1, y1, x2, y2, color_start.vm_color_565, color_end.vm_color_565, 0, 0, style);
	return;
}

//====================================Font Function=================================
VM_GDI_RESULT vm_font_set_font_size(VMINT size)
{
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;
	if (vm_graphic_is_use_vector_font())
	{
		switch (size) 
		{
		case VM_SMALL_FONT:
			current_font->size = SMALL_FONT;
			break;
		case VM_MEDIUM_FONT:
			current_font->size = MEDIUM_FONT;
			break;
		case VM_LARGE_FONT:
			current_font->size = LARGE_FONT;
			break;
		default:
			current_font->size = size;
			break;
		}	
	}
	else
	{
		switch (size) 
		{
		case VM_SMALL_FONT:
			current_font->size = SMALL_FONT;
			break;
		case VM_MEDIUM_FONT:
			current_font->size = MEDIUM_FONT;
			break;
		case VM_LARGE_FONT:
			current_font->size = LARGE_FONT;
			break;
		default:
			current_font->size = MEDIUM_FONT;
			break;
		}	
	}
	gui_set_font(current_font);
	return VM_GDI_SUCCEED;
}


VM_GDI_RESULT vm_font_set_font_style(VMINT bold,VMINT italic,VMINT underline)
{
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
		return VM_GDI_MIBR_NOT_FORE;	
	
	if (vm_graphic_is_use_vector_font())
	{
	
		if (bold)
			current_font->bold= VM_FONT_ATTR_BOLD;
		else
			current_font->bold= 0;

		if (italic)
			current_font->italic= VM_FONT_ATTR_ITALIC;
		else
			current_font->italic= 0;

		if (underline)
			current_font->underline= VM_FONT_ATTR_UNDERLINE;
		else
			current_font->underline= 0;		

	}
	else
	{
		current_font->bold = 0;
		current_font->italic = 0;
		current_font->underline = 0;
	}
	gui_set_font(current_font);
	return VM_GDI_SUCCEED;    
}

//=================================screen_rotate=====================================
extern void vm_graphic_flush_screen_rotate(void); //��



/*
��Ļ��ת */
extern VMINT vm_graphic_save_context_nonsupport_bg(void);
VMINT vm_graphic_screen_rotate(vm_graphic_screen_rotate_value rotate)
{
#ifdef __MMI_SCREEN_ROTATE__
{
	
	VM_P_HANDLE process_handle;

	// �������ε�����ͬ�ġ���Ļ��ת�Ƕȡ��Ǿ�ֱ�ӷ���
    if (g_vre_screen_rotate == rotate)
    	{
       return VM_GDI_SUCCEED;   	
    	}
		//�������������Ͳ����д���
	if  (rotate >= VM_GRAPHIC_SCREEN_ROTATE_MAX_TYPE)
	    {
		 return VM_GDI_ERR_WRONG_PARAM;
			
		}    
	//�ȱ�������,��ȥ��ת��Ļ

	g_vre_screen_rotate = rotate;

		if( (process_handle = vm_pmng_get_app_handle()) == 0)
		{
			return VM_GDI_FAILED;
		}
		
		 if (vm_pmng_is_support_bg(process_handle)) 
			vm_graphic_save_context();
	     else
	     {
			vm_graphic_save_context_nonsupport_bg(); 
			vm_log_fatal("[graphic]-vm_graphic_screen_rotate : save context");
		}

	mmi_frm_screen_rotate(rotate);

	  vm_graphic_flush_screen_rotate();
    return VM_GDI_SUCCEED;
	}
#else
    return VM_GDI_ERR_NOT_SUPPORT_ROTATE;
#endif
}



/*2010-7-14   ɾ������ӿ�

VMINT vm_graphic_reset_screen_rotate(void)
{
#ifdef __MMI_SCREEN_ROTATE__
	{
	vm_log_fatal("vm_graphic_reset_screen_rotate __MMI_SCREEN_ROTATE__ ");

    mmi_frm_reset_screen_rotation();//  ������Ļ��ԭ����״̬
	g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;
    vm_graphic_flush_screen_rotate();	
    return VM_GDI_SUCCEED;
	}
#else
    return VM_GDI_ERR_NOT_SUPPORT_ROTATE;
#endif    
}*/






vm_graphic_screen_rotate_value vm_graphic_get_current_rotate(void)
{
#ifdef __MMI_SCREEN_ROTATE__
{
	//vm_log_fatal("vm_graphic_screen_rotate_value __MMI_SCREEN_ROTATE__ ");
	return g_vre_screen_rotate;
}
#else    
    return VM_GRAPHIC_SCREEN_ROTATE_0;
#endif    
}

/* �ýӿ��Ѿ� ��VM_MSG_SCREEN_ROTATE��Ϣ����� 
VMINT vm_graphic_reg_rotate_callback(void(*f)(VMINT   message ,VMINT   rotate_value))
{
	return 1;
}
*/


/*Ϊ�� VM_MSG_PAINT �¼����ص���Ļ �� ��
VMINT vm_pmng_get_screen_width_height(void)
{
	VMINT int_WidthHeight =0;
	VMINT int_scrren_width  = 0;
	VMINT int_scrren_height = 0;	
	gdi_lcd_get_dimension(&int_scrren_width, &int_scrren_height);
	int_WidthHeight = int_scrren_width<<16;
	int_WidthHeight += int_scrren_height;	
	//vm_graphic_get_screen_height(void)
	return int_WidthHeight;
}*/
void vm_graphic_rotate_temp_ex(VMINT _rotate_value)
{
	vm_log_debug("[vmgraph]:vm_graphic_rotate_temp_ex %d ",_rotate_value);

	vm_graphic_rotate_temp(_rotate_value);
}
//============================MIBR Function========================================

void vm_graphic_mibr_clear_layer_param(VMINT handle)
{
    memset(&layer_trans_tbl[handle],0,sizeof(layer_param_t));
    layer_trans_tbl[handle].trans_color = -1;
    layer_trans_tbl[handle].mibrhandle= -1;
}


void vm_graphic_mibr_clear_layer_table(void)
{
	VMINT i;
	for (i = 0;i < MAX_LAYER;i++)
		vm_graphic_mibr_clear_layer_param(i);
}





/*
Ϊ�˲�֧�ֺ�̨���еĳ������ӵ� API 
*/
VMINT vm_graphic_save_context_nonsupport_bg()
{
#ifdef __MMI_SCREEN_ROTATE__

	vm_graphic_context *ctx = NULL;
	VM_P_HANDLE phandle;
	VMINT ctxhandle = -1;
	VMINT i;
	VMINT bufsize =0;//chuanxiang.wang

	vm_log_debug("[graphic] :  ");
	vm_log_debug("[graphic] :  ");
	vm_log_debug("[graphic] : vm_graphic_save_context_nonsupport_bg begin");	

	//��ѯ ��ǰ�ľ���Ƿ����---�Ȳ�ѯ���
	if ((phandle = vm_pmng_get_app_handle()) == 0) //vm_pmng_get_app_handle
		return VM_GDI_MIBR_ERR;


	vm_log_debug("[graphic] : vm_graphic_save_context_nonsupport_bg phandle=%d ",phandle);
	
	//�ӱ��в�ѯ  ���̵�ID �ţ��������бȽϣ��Ƿ���һ���µľ��
	for (i = 0;i<MAX_PROCESS;i++)			
	{
		vm_log_debug("[graphic] : vm_graphic_save_context_nonsupport_bg mibr_table[%d].phandle=%d ",i,mibr_table[i].phandle);
		if (mibr_table[i].phandle == phandle)
			break;
	 }
	
//i !=max_proc
	if( i != MAX_PROCESS )//�� ���� ��ȥ��ѯ ���� --
	{
		//��������  ��ȡ����
		if (vm_res_get_data(VM_RES_TYPE_GRAPHIC_CXT, mibr_table[i].mibrhandle, (void **)(&ctx) , &bufsize) < 0)
			vm_log_debug("[graphic] : vm_graphic_save_context_nonsupport_bg vm_res_get_data ");
	}
	else //�½��� ����Ҫȥ��ѯ
	{
		NULL;
	}
	
//i == max_Process
	// ��ȡ�������Ƿ���ȷ�����½��̸�����ȥ������
	if (bufsize == 0) //��ȡ�������˾Ͳ���Ҫ������ռ���
	{
		if((ctx = (vm_graphic_context *)vm_malloc(sizeof(vm_graphic_context))) == NULL)
			return VM_GDI_FAILED;
	}

			
	//Ҫȥ��̨�����ˣ��ǾͰ��Լ��ı���������
   	if(g_vre_screen_rotate >= VM_GRAPHIC_SCREEN_ROTATE_MAX_TYPE ) // g_vre_screen_rotate ��һ����������ݣ�һ�㲻����ָ�����
	{
		ctx->save_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;
	}
	else //��� g_vre_screen_rotate �Ѿ��仯�� ��Ϊ�ղ��Ѿ�����Ļ���½����˷�ת���ǾͶ�����ֵ ���ó� 0 ����ԭ����ֵ�Ѿ�������context ����
	{
		vm_log_debug("vm_graphic_save_context_nonsupport_bg  g=%d , ctx=%d ",g_vre_screen_rotate,  ctx->save_screen_rotate);
		ctx->save_screen_rotate = g_vre_screen_rotate;
		vm_log_debug("vm_graphic_save_context_nonsupport_bg  g=%d , ctx=%d ",g_vre_screen_rotate,  ctx->save_screen_rotate);

	}


	if (i == MAX_PROCESS)// ��һ���µĽ���
	{		
		if(vm_load_info_resolution())//��Ļ�Ŀ����Ӧ��Ҫ��Ŀ�������෴
		{
			mmi_frm_screen_rotate(VM_GRAPHIC_SCREEN_ROTATE_270);	
			g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_270; //Ӧ���Ѿ���ת�� 270 ��
			ctx->save_screen_rotate = g_vre_screen_rotate;		//context��ҲҪ������Ӧ���޸�	
		}
	}
	else
	{
		if(g_vre_screen_rotate != VM_GRAPHIC_SCREEN_ROTATE_0)//������� 0 �Ȳŷ�ת�� 0 ��
		{
			mmi_frm_screen_rotate(VM_GRAPHIC_SCREEN_ROTATE_0);
			gdi_draw_solid_rect(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height(), VM_COLOR_BLACK);

		}
		
	}



	
	
if(bufsize != 0)//�������� �Ͳ���Ҫ�ٱ�����,ֱ�� set ����
{
if (vm_res_set_data(VM_RES_TYPE_GRAPHIC_CXT, ctxhandle, (void *) ctx,sizeof(vm_graphic_context)) != 0)
	{
		vm_log_debug("[vmgraph] : error vm_graphic_save_context_nonsupport_bg  vm_res_set_data ");
		vm_free(ctx);
		return VM_GDI_FAILED;
	}
}
else //û�ж������ݲ�ȥ���б���
{
	//��������
	if ((ctxhandle = vm_res_save_data(VM_RES_TYPE_GRAPHIC_CXT, (void *) ctx, sizeof(vm_graphic_context),NULL, phandle)) < 0)
	{
		vm_log_debug("[vmgraph] : error vm_graphic_save_context_nonsupport_bg  ctxhandle =%d ",ctxhandle);

		vm_free(ctx);
		return VM_GDI_FAILED;
	}
}
	
	
	
	vm_log_debug("[vmgraph] :success vm_graphic_save_context_nonsupport_bg  ctxhandle =%d ",ctxhandle);
	vm_log_debug("[vmgraph] :vm_graphic_save_context_nonsupport_bg  g=%d , ctx=%d ",g_vre_screen_rotate,  ctx->save_screen_rotate);
	
	if (i == MAX_PROCESS)						//����Դ������û�з��� ����̵߳ľ��
	{
	        for (i = 0;i<MAX_PROCESS;i++)
	    	{
	    		if (mibr_table[i].phandle == 0)// ������Դ���У��ĸ�����ǿյģ�
	    			break;
	        }

		vm_log_debug("[vmgraph] :vm_graphic_save_context_nonsupport_bg i= %d ", i);
	        if (i == MAX_PROCESS)
	        {
	            vm_free(ctx);
					vm_log_debug("[vmgraph] :vm_graphic_save_context_nonsupport_bg i= MAX_PROCESS  VM_GDI_MIBR_ERR");

		    	return VM_GDI_MIBR_ERR;
	        }       
	}	
	mibr_table[i].phandle = phandle;
	mibr_table[i].mibrhandle = ctxhandle;
	vm_log_debug(" [vmgraph] :success vm_graphic_save_context_nonsupport_bg  phandle= %d ,mibrhandle = %d  " , mibr_table[i].phandle,mibr_table[i].mibrhandle);
	return VM_GDI_SUCCEED;
#endif

}


/*
save context
*/
VMINT vm_graphic_save_context(void)
{
	vm_graphic_context *ctx = NULL;
	VM_P_HANDLE phandle;
	VMINT ctxhandle = -1;
	VMINT i;
	VMINT bufsize =0;//chuanxiang.wang

	vm_log_debug("[graphic] :vm_graphic_save_context	  Save_context_B");


	//��ѯ ��ǰ�ľ���Ƿ����---�Ȳ�ѯ���
	if ((phandle = vm_pmng_get_app_handle()) == 0) //vm_pmng_get_app_handle
		return VM_GDI_MIBR_ERR;


	vm_log_debug("[graphic] : vm_graphic_save_context_nonsupport_bg phandle=%d ",phandle);


	
	
	//�ӱ��в�ѯ  ���̵�ID �ţ��������бȽϣ��Ƿ���һ���µľ��
	for (i = 0;i<MAX_PROCESS;i++)			
	{
		vm_log_debug("[graphic] : vm_graphic_save_context_nonsupport_bg mibr_table[%d].phandle=%d ",i,mibr_table[i].phandle);

		if (mibr_table[i].phandle == phandle)
			break;
    }
	
//i !=max_proc
	if( i != MAX_PROCESS )//�� ���� ��ȥ��ѯ ���� --
	{
		//��������  ��ȡ����
	if (vm_res_get_data(VM_RES_TYPE_GRAPHIC_CXT, mibr_table[i].mibrhandle, (void **)(&ctx) , &bufsize) < 0)
		vm_log_debug("[graphic] : vm_graphic_save_context_nonsupport_bg vm_res_get_data ");
	}
	else //�½��� ����Ҫȥ��ѯ
	{
		NULL;
	}
	
//i == max_Process
	// ��ȡ�������Ƿ���ȷ�����½��̸�����ȥ������
	if (bufsize == 0) //��ȡ�������˾Ͳ���Ҫ������ռ���
	{
		if((ctx = (vm_graphic_context *)vm_malloc(sizeof(vm_graphic_context))) == NULL)
			return VM_GDI_FAILED;
	}
	
	
	memcpy((void *)(&(ctx->cliprect)), (void *)(&gcliprect), sizeof(clip_rect));
	memcpy((void *)(&(ctx->color)), (void *)(&global_color), sizeof(vm_graphic_color));
	memcpy((void *)(&(ctx->pen)), (void *)(&global_pen), sizeof(vm_graphic_pen));
	memcpy((void *)(&(ctx->font)), (void *)(current_font), sizeof(stFontAttribute));
	ctx->fp = user_get_resource_fp;
	//Ҫȥ��̨�����ˣ��ǾͰ��Լ��ı���������
	#ifdef __MMI_SCREEN_ROTATE__
	  	if(g_vre_screen_rotate >= VM_GRAPHIC_SCREEN_ROTATE_MAX_TYPE ) //
		{
			ctx->save_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;
			//vm_log_fatal("vm_graphic_save_context NULL %d ,%d ",g_vre_screen_rotate,  ctx->save_screen_rotate);
		}
		else //��� g_vre_screen_rotate �Ѿ��仯�� ��Ϊ�ղ��Ѿ�����Ļ���½����˷�ת���ǾͶ�����ֵ ���ó� 0 ����ԭ����ֵ�Ѿ�������context ����
		{
			//vm_log_fatal("vm_graphic_save_context %d ,%d ",g_vre_screen_rotate,  ctx->save_screen_rotate);
			ctx->save_screen_rotate = g_vre_screen_rotate;
		}

		vm_log_debug("vm_graphic_save_context %d ,%d ",g_vre_screen_rotate,  ctx->save_screen_rotate);
		
		if (i == MAX_PROCESS)// �� �������û���ҵ�  �������һ���µĽ����� �����Ϊ��̨����׼����
		{		
			if(vm_load_info_resolution())
			{
				mmi_frm_screen_rotate(VM_GRAPHIC_SCREEN_ROTATE_270);	
				g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_270; //Ӧ���Ѿ���ת�� 270 ��
				ctx->save_screen_rotate = g_vre_screen_rotate;			//context��ҲҪ������Ӧ���޸�	
			}
		}
		else//�Ѿ������˵Ľ���,����ִ̨��,��Ҫ����Ļ����ת�� 0��
		{
			if(g_vre_screen_rotate != VM_GRAPHIC_SCREEN_ROTATE_0)//������� 0 �Ȳŷ�ת�� 0 ��
		{
			mmi_frm_screen_rotate(VM_GRAPHIC_SCREEN_ROTATE_0);
			gdi_draw_solid_rect(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height(), VM_COLOR_BLACK);

		}
		}				
#endif


if(bufsize != 0)//�������� �Ͳ���Ҫ�ٱ�����,ֱ�� set ����
{
if (vm_res_set_data(VM_RES_TYPE_GRAPHIC_CXT, ctxhandle, (void *) ctx,sizeof(vm_graphic_context)) != 0)
	{
		vm_log_debug("[vmgraph] : error vm_graphic_save_context_nonsupport_bg  vm_res_set_data ");
		vm_free(ctx);
		return VM_GDI_FAILED;
	}
}
else //û�ж������ݲ�ȥ���б���
{
	if ((ctxhandle = vm_res_save_data(VM_RES_TYPE_GRAPHIC_CXT, (void *) ctx, sizeof(vm_graphic_context),NULL, phandle)) < 0)
	{
		vm_free(ctx);
		return VM_GDI_FAILED;
	}
}
	vm_log_debug(" [graphic] :vm_graphic_save_context save context  phandle   = %d",phandle);

	
	if (i == MAX_PROCESS)//����Դ������û�з��� ����̵߳ľ��
	{
        vm_log_debug("[graphic] : vm_graphic_save_context - mibr_table Not find  this phandle!  ressource not find");
        for (i = 0;i<MAX_PROCESS;i++)
    	{
    		if (mibr_table[i].phandle == 0)// ������Դ���У��ĸ� ����ǿյģ�
    			break;
        }

        vm_log_debug("[graphic] : vm_graphic_save_context - mibr_table Not find i= %d",i);
		
        if (i == MAX_PROCESS)
        {
            vm_log_debug("[graphic] : vm_graphic_save_context - mibr_table Not find  empty phandle!");
            vm_free(ctx);
	    	return VM_GDI_MIBR_ERR;
        }
       
	}	

	
	//�ѽ��̾������Դ���д������.
	mibr_table[i].phandle = phandle;
	mibr_table[i].mibrhandle = ctxhandle;
    vm_log_debug("[graphic] :vm_graphic_save_context - mibr_table find phandle %d in position %d!",mibr_table[i].phandle,i);
	vm_log_debug("[graphic] :vm_graphic_save_context Save_context_E");	
	vm_log_debug("[graphic] :                 ");	
	vm_log_debug("[graphic] :                 ");
	vm_log_debug("[graphic] :                 ");
	
	return VM_GDI_SUCCEED;
}





/*Ϊ ��֧�ֺ�̨���еĳ��� ���� ������Ϣ�ĺ���*/
VMINT vm_graphic_load_context_nonsupport_bg()
{
#ifdef __MMI_SCREEN_ROTATE__

	vm_graphic_context *ctx;
	VM_P_HANDLE phandle;
	VMINT bufsize = 0;
	VMINT i;
	VMINT ret;
	
	vm_log_debug("[graphic] :                 ");	
	vm_log_debug("[graphic] :                 ");
	vm_log_debug("[graphic] :                 ");
	vm_log_debug("[graphic] : vm_graphic_load_context_nonsupport_bg load_context_B");
	
	
	//��õ�ǰ ���̵ľ��
	if ((phandle = vm_pmng_get_app_handle()) == 0) //ԭ���ĺ����� vm_pmng_get_current_handle
		return VM_GDI_MIBR_ERR;    
    vm_log_debug("[graphic] : vm_graphic_load_context_nonsupport_bg  phandle = %d ",phandle);
	

	
	for (i = 0;i<MAX_PROCESS;i++)//���̱����Ƿ��иþ��
	{
		vm_log_debug("[graphic] : vm_graphic_load_context  mibr_table[%d].phandle mibr_table[%d].mibrhandle =%d=%d ",i,mibr_table[i].phandle,i,mibr_table[i].mibrhandle);

		if (mibr_table[i].phandle == phandle)//������иþ��,��ֱ��break
			break;
	}		


	if (i == MAX_PROCESS)// �� �������û���ҵ�  �������һ���µĽ�����
	{
		vm_log_debug("[graphic] : vm_graphic_load_context_nonsupport_bg It's a new process!");
		// ���½��е� ����Ļ��ת�Ƕ����Ĵ��� �����ó� 0��			
		mmi_frm_screen_rotate(VM_GRAPHIC_SCREEN_ROTATE_0);//��Ļ�ָ���ԭ����״̬
		g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;				
		vm_graphic_save_context_nonsupport_bg();
		vm_log_debug("[graphic] : vm_graphic_load_context_nonsupport_bg It's a new process! return VM_GDI_SUCCEED ");
		return VM_GDI_SUCCEED;
	}		
	
	vm_log_debug("[graphic] : vm_graphic_load_context_nonsupport_bg get phandle%d %d  mibr_table[i].mibrhandle =%d success!",i,phandle, mibr_table[i].mibrhandle);


//�����һ���Ѿ����ڵĽ���,�Ǿͽ��ж�ȡ����

	if ( ( ret = vm_res_get_data(VM_RES_TYPE_GRAPHIC_CXT, mibr_table[i].mibrhandle, (void **)(&ctx) , &bufsize)) < 0)
		{
		vm_log_debug("[graphic] : vm_graphic_load_context_nonsupport_bg vm_res_get_data error  ret=%d " ,ret);
			return VM_GDI_FAILED;
		}	
	vm_log_debug("[graphic] : vm_graphic_load_context_nonsupport_bg vm_res_get_data %x success! ret= %d ",ctx ,ret);
	vm_log_debug("vm_graphic_load_context_nonsupport_bg g= %d  , cxt = %d   ",g_vre_screen_rotate,  ctx->save_screen_rotate );


	if (bufsize != 0)//���ݶ�ȡ�ɹ�, �ָ����ݵĲ���
	{		
		{
			if(VM_GRAPHIC_SCREEN_ROTATE_MAX_TYPE <= (ctx->save_screen_rotate) ) 
			{
				g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;
				vm_log_debug("vm_graphic_load_context_nonsupport_bg %d ,%d  mibr_table[i].mibrhandle=%d  VM_GRAPHIC_SCREEN_ROTATE_MAX_TYPE ",g_vre_screen_rotate,  ctx->save_screen_rotate,mibr_table[i].mibrhandle);
			}
			else 
			{
				vm_log_debug("vm_graphic_load_context_nonsupport_bg g= %d  , cxt = %d  mibr_table[i].mibrhandle = %d ",g_vre_screen_rotate,  ctx->save_screen_rotate ,mibr_table[i].mibrhandle);
				g_vre_screen_rotate = ctx->save_screen_rotate;
				vm_log_debug("vm_graphic_load_context_nonsupport_bg g = %d , cxt = %d ",g_vre_screen_rotate,  ctx->save_screen_rotate);
			}
			mmi_frm_screen_rotate(g_vre_screen_rotate);	//����Դ ��Ļ�ָ���ԭ����״̬
		}		
	}
    vm_log_debug("[graphic] :vm_graphic_load_context_nonsupport_bg  g_vre_screen_rotate %d ",g_vre_screen_rotate);
	
	{//�ͷ���Դ
		VMINT res = 100;
		res =vm_res_release_data(VM_RES_TYPE_GRAPHIC_CXT, mibr_table[i].mibrhandle);
		
		vm_log_debug("[graphic] : vm_graphic_load_context_nonsupport_bg _VM_GDI_MIBR_ERR vm_res_release_data  res = %d, i=%d,mibr_table[i].phandle=%d ,mibr_table[i].mibrhandle =%d ",
			res,i,mibr_table[i].phandle ,mibr_table[i].mibrhandle);
		
		if  ( res< 0) 
		{
			vm_log_debug("[graphic] : vm_graphic_load_context_nonsupport_bg _VM_GDI_MIBR_ERR vm_res_release_data  not delete cxt ");
			return VM_GDI_MIBR_ERR;    
		}
    }
	vm_free(ctx); 						//�ͷ� context
	
	return VM_GDI_SUCCEED;
#endif	
}







/*
	load context ��Ӧ��̨����
*/
VMINT vm_graphic_load_context(void)
{
	vm_graphic_context *ctx;
	VM_P_HANDLE phandle;
	VMINT bufsize = 0;
	VMINT i;
	
	vm_log_debug("[graphic] :                 ");	
	vm_log_debug("[graphic] :                 ");
	vm_log_debug("[graphic] :                 ");
	vm_log_debug("[graphic] : vm_graphic_load_context load_context_B");
	
	//��õ�ǰ �̵߳ľ��
	if ((phandle = vm_pmng_get_app_handle()) == 0)
		return VM_GDI_MIBR_ERR;    
    vm_log_debug("[graphic] : vm_graphic_load_context  phandle = %d ",phandle);
	
    
	for (i = 0;i<MAX_PROCESS;i++)
	{
		if (mibr_table[i].phandle == phandle)
			break;
	}		
	
	if (i == MAX_PROCESS)// �� �������û���ҵ�  �������һ���µĽ�����
	{
		vm_log_debug("[graphic] : vm_graphic_load_context background  It's a new process!");
		current_font = &mmi_def_font;
		gui_set_font(current_font);
		gcliprect.left = 0;
		gcliprect.top = 0;			
		gcliprect.right = vm_graphic_get_screen_width();		
		gcliprect.bottom = vm_graphic_get_screen_height();		
		gcliprect.flag = 1;
		//global_color.vm_color_565 = 0;
		//global_color.vm_color_888 = 0;        
		memset(&global_color,0x00,sizeof(vm_graphic_color));
		memset(&global_pen,0x00,sizeof(vm_graphic_pen));
		user_get_resource_fp = NULL;	
		
		{ // ���½��е� ����Ļ��ת�Ƕ����Ĵ��� �����ó� 0��
#ifdef __MMI_SCREEN_ROTATE__
			{				
				mmi_frm_screen_rotate(VM_GRAPHIC_SCREEN_ROTATE_0);//��Ļ�ָ���ԭ����״̬
				g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;            		
				vm_graphic_save_context();
			}	 
#endif
		}/**/
		
		vm_log_debug("[graphic] : vm_graphic_load_context        It's a new process! return VM_GDI_SUCCEED ");
		return VM_GDI_SUCCEED;
	}
		
	
	vm_log_debug("[graphic] : vm_graphic_load_context get phandle%d %d success!",i,phandle);
	if (vm_res_get_data(VM_RES_TYPE_GRAPHIC_CXT, mibr_table[i].mibrhandle, (void **)(&ctx) , &bufsize) < 0)
		return VM_GDI_FAILED;
	
	vm_log_debug("[graphic] : vm_graphic_load_context vm_res_get_data %x success!",ctx);
	if (bufsize != 0)
	{
		memcpy((void *)(&gcliprect), (void *)(&(ctx->cliprect)), sizeof(clip_rect));
		memcpy((void *)(&global_color), (void *)(&(ctx->color)), sizeof(vm_graphic_color));
		memcpy((void *)(&global_pen), (void *)(&(ctx->pen)), sizeof(vm_graphic_pen));
		memcpy((void *)(current_font), (void *)(&(ctx->font)), sizeof(stFontAttribute));
		user_get_resource_fp = ctx->fp;
		
		
		{
#ifdef __MMI_SCREEN_ROTATE__
			if(VM_GRAPHIC_SCREEN_ROTATE_MAX_TYPE <= (ctx->save_screen_rotate) ) 
			{
				g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;
				vm_log_debug("vm_graphic_load_context %d ,%d  mibr_table[i].mibrhandle=%d  VM_GRAPHIC_SCREEN_ROTATE_MAX_TYPE ",g_vre_screen_rotate,  ctx->save_screen_rotate,mibr_table[i].mibrhandle);
			}
			else 
			{
				vm_log_debug("vm_graphic_load_context %d ,%d  mibr_table[i].mibrhandle = %d ",g_vre_screen_rotate,  ctx->save_screen_rotate ,mibr_table[i].mibrhandle);
				g_vre_screen_rotate = ctx->save_screen_rotate;
				vm_log_debug("vm_graphic_load_contextt %d ,%d ",g_vre_screen_rotate,  ctx->save_screen_rotate);
			}
			mmi_frm_screen_rotate(g_vre_screen_rotate);				//��Ļ�ָ���ԭ����״̬
#endif
		}
		
	}
    gui_set_font(current_font);    
	vm_log_debug("[graphic] :vm_graphic_load_context  gcliprect %d,%d,%d,%d!",gcliprect.top,gcliprect.left,gcliprect.right,gcliprect.bottom);
	vm_log_debug("[graphic] :vm_graphic_load_context  global_color %d,%d!",global_color.vm_color_565,global_color.vm_color_888);
	vm_log_debug("[graphic] :vm_graphic_load_context  global_pen %d,%d!",global_pen.bitvalues,global_pen.cycle);
    vm_log_debug("[graphic] :vm_graphic_load_context  g_vre_screen_rotate %d ",g_vre_screen_rotate);
	
	{
		VMINT res = 100;
		res =vm_res_release_data(VM_RES_TYPE_GRAPHIC_CXT, mibr_table[i].mibrhandle);
		
		vm_log_debug("[graphic] : vm_graphic_load_context_VM_GDI_MIBR_ERR vm_res_release_data  res = %d, i=%d,mibr_table[i].phandle=%d ,mibr_table[i].mibrhandle =%d ",
			res,i,mibr_table[i].phandle ,mibr_table[i].mibrhandle);
		
		if  ( res< 0) 
		{
			vm_log_debug("[graphic] : vm_graphic_load_context_VM_GDI_MIBR_ERR vm_res_release_data  not delete cxt ");
			return VM_GDI_MIBR_ERR;    
		}
    }
	vm_free(ctx); 						//�ͷ� context
	
	/*  mibr_table[i].phandle = 0; 			//Ӧ�þ�� ��Ϊ 0
	 mibr_table[i].mibrhandle = 0;	 	//��Դ ���Ҳ��Ϊ 0
										
	vm_graphic_mibr_clear_layer_table();*/
	
	/**/
	
	vm_log_debug("[graphic] :vm_graphic_load_context  E");
	vm_log_debug("[graphic] :                 ");	
	vm_log_debug("[graphic] :                 ");
	vm_log_debug("[graphic] :                 ");
	return VM_GDI_SUCCEED;
}
VMINT vm_load_info_resolution()
{
	VMWCHAR str_vxp_filename[200]={0};
	VMINT int_w_h=0;
	VMINT int_tag_w=0;
	VMINT int_tag_h=0;
	VMINT int_size = 4;
	VMINT int_screen_w =0;
	VMINT int_screen_h =0;
	VMINT re=0;		

	vm_get_exec_filename(str_vxp_filename);				
	re = vm_get_vm_tag(str_vxp_filename ,VM_CE_INFO_RESOLUTION_REQ , &int_w_h , &int_size);
		
	vm_log_error(" vm_load_info_resolution re=%d int_w_h = %d int_size =%d filename =%s ",re,int_w_h,int_size,vm_gb2312_string(str_vxp_filename));

	if(!int_w_h)
	{
		vm_log_debug("vm_load_info_resolution:  return autio screen ");
		 return FALSE;
	}
		int_tag_h = int_w_h&65535; // 240
	int_tag_w = int_w_h>>16; // 
	vm_log_error("vm_load_info_resolution: w=%d h=%d",int_tag_w,int_tag_h);

/*����ʱʹ��
	int_tag_h = 240;
	int_tag_w = 400;
	vm_log_error("vm_load_info_resolution: w=%d h=%d",int_tag_w,int_tag_h);
*/

	int_screen_w = vm_graphic_get_screen_width();
	int_screen_h = vm_graphic_get_screen_height();
	vm_log_error("vm_load_info_resolution: w=%d h=%d",int_screen_w,int_screen_h );

	if(int_screen_w == int_tag_h && int_screen_h == int_tag_w) 
	{
		return	TRUE;
	}
	else
	{	 
		return 	FALSE;
	}
	 
}




VM_GDI_HANDLE vm_graphic_mibr_save_layer(void)
{
	VMINT reshandle;
	if  ((reshandle = vm_res_save_data(VM_RES_TYPE_LAYER_HANDLE, NULL,0, NULL, vm_pmng_get_app_handle())) < 0)
		return VM_GDI_MIBR_ERR;
	return reshandle;
}

VM_GDI_HANDLE vm_graphic_mibr_release_layer(VMINT mibrlayer)
{
	if  (vm_res_release_data(VM_RES_TYPE_LAYER_HANDLE, mibrlayer) < 0)
		return VM_GDI_MIBR_ERR;
	return VM_GDI_SUCCEED;
}


void vm_graphic_mibr_clear_mibr_table(void)
{
	VMINT i;
	for(i = 0; i < MAX_PROCESS; i++)
	{
		mibr_table[i].mibrhandle = 0;
		mibr_table[i].phandle = 0;
	}
}

void vm_graphic_mibr_reset_global_env(void)
{
    is_base_layer_created = FALSE;
    is_screen_buffer_initialized = FALSE;
    layer_count = 0;
    active_layer = 0;
	is_base_layer = -1;
	is_fast_layer = -1;
	user_get_resource_fp = NULL;
	current_baseline = -1;
	g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;
	global_color	.vm_color_565 = VM_COLOR_BLACK;
	global_color.vm_color_888 = VM_COLOR_565_TO_888(VM_COLOR_BLACK);  
			     

}



void vm_graphic_mibr_layer_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
 	VMINT i,curp = -1;// curp �߼�����
	vm_log_debug("[graphic]-vm_graphic_mibr_layer_notify_callback : process_handle=%d,sys_state=%d",process_handle,sys_state); 		
	for (i = 0;i<MAX_PROCESS;i++)
	{
		if (mibr_table[i].phandle == process_handle)
			break;
	}
	if (i != MAX_PROCESS)
		curp = i;
	vm_log_debug("[graphic]-vm_graphic_mibr_layer_notify_callback : curp=%d",curp); 	

	//if(curp<0) return;// curp �߼�����ı���
		
 	switch(sys_state)
 	{
 		case VM_PMNG_BACKGROUND:
            //If App is not support BG running,Not clear global variables.
            if (vm_pmng_is_support_bg(process_handle))
            {
         		for (i = MAX_LAYER - 1; i>=0; i--)
         			vm_graphic_delete_layer(i);

                vm_log_debug("[graphic] - B:vm_graphic_mibr_layer_notify_callback : vm_graphic_delete_layer_internal Done"); 		
         		vm_graphic_mibr_reset_global_env();
                vm_graphic_mibr_clear_layer_table();
            }  
            else
                vm_log_debug("[graphic]-vm_graphic_mibr_layer_notify_callback : Not Support BG!! "); 		                
     		break; 		
			
 		case VM_PMNG_UNLOAD:
       if (vm_pmng_get_app_handle() == process_handle)
         {			
     		for (i = MAX_LAYER - 1; i>=0; i--)
     			vm_graphic_delete_layer(i);

            		vm_log_debug("[graphic] - U:vm_graphic_mibr_layer_notify_callback : vm_graphic_delete_layer_internal Done"); 
     		       vm_graphic_mibr_reset_global_env();
           		vm_graphic_mibr_clear_layer_table();
	        
    	         current_font = &mmi_def_font;
	        gui_set_font(current_font);	 
			if (curp>=0)
			{
				vm_res_release_data(VM_RES_TYPE_GRAPHIC_CXT, mibr_table[curp].mibrhandle);
				mibr_table[curp].phandle = 0;
	        		mibr_table[curp].mibrhandle =0;
			}
		
#ifdef __MMI_SCREEN_ROTATE__
	if(VM_GRAPHIC_SCREEN_ROTATE_0 == g_vre_screen_rotate) 
		//Ӧ���Ѿ�ж���ˣ���� ȫ����ת��ֵΪ VM_GRAPHIC_SCREEN_ROTATE_MAX_TYPE �Ͳ���Ҫ�ָ���Ļ
		{
			vm_log_fatal("[graphic]-vm_graphic_mibr_layer_notify_callback  VM_GRAPHIC_SCREEN_ROTATE_0 == g_vre_screen_rotate NULL");
			NULL;
		}
	else
		{	
			vm_log_fatal("[graphic]-vm_graphic_mibr_layer_notify_callback  mmi_frm_reset_screen_rotation");
			mmi_frm_reset_screen_rotation();
			g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;
		}
#endif	
	}/*201072 ͼ��ģ�� ʹ����ɺ�Ҫ���� ��Ļ��ԭ����*/
     		break;
		default:
			return;
 
	}
}
void vm_graphic_mibr_context_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
    vm_log_debug("[graphic]-vm_graphic_mibr_context_notify_callback : process_handle=%d,sys_state=%d",process_handle,sys_state); 		    
    switch(sys_state)
 	{
        //If App is not support BG running,Not do context things.
        case VM_PMNG_BACKGROUND:
            if (vm_pmng_is_support_bg(process_handle)) //
			    vm_graphic_save_context();
            else
            	{
            		vm_graphic_save_context_nonsupport_bg();
            		vm_log_fatal("[graphic]-vm_graphic_mibr_context_notify_callback : VM_PMNG_BACKGROUND "); 		    
            	}
 		break;
		case VM_PMNG_FOREGROUND:
            if (vm_pmng_is_support_bg(process_handle)) //
			    vm_graphic_load_context();
            else
            {
					vm_graphic_load_context_nonsupport_bg(); //
					vm_log_error("[graphic]-vm_graphic_mibr_context_notify_callback : VM_PMNG_FOREGROUND");
			}
                 		                
		break;
		default:
			return;
 	}
	return;
}


static void vm_graphic_initial(void)
{
    vm_log_debug("[graphic] - vm_graphic_initialize!");
    vm_res_type_set_notify_callback(VM_RES_TYPE_LAYER_HANDLE, vm_graphic_mibr_layer_notify_callback);
	vm_res_type_set_notify_callback(VM_RES_TYPE_GRAPHIC_CXT, vm_graphic_mibr_context_notify_callback);
}

static void vm_graphic_finialize(void)
{
	VMINT i;

    vm_log_debug("[graphic] - vm_graphic_finialize!");
	/*�ر�ϵͳ֪ͨ�ص�*/
 	for (i = MAX_LAYER -1 ;  i >=0 ; i--)
		vm_graphic_delete_layer_internal(i);

    
    vm_graphic_mibr_reset_global_env();
	vm_graphic_mibr_clear_layer_table();
	vm_graphic_mibr_clear_mibr_table();
	vm_res_type_set_notify_callback(VM_RES_TYPE_LAYER_HANDLE, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_GRAPHIC_CXT, NULL);
//��
#ifdef __MMI_SCREEN_ROTATE__
	if(VM_GRAPHIC_SCREEN_ROTATE_0 == g_vre_screen_rotate)
		{
			vm_log_fatal("[graphic]-vm_graphic_finialize  VM_GRAPHIC_SCREEN_ROTATE_0 == g_vre_screen_rotate NULL");
			NULL;
		}
	else
		{	
			vm_log_fatal("[graphic]-vm_graphic_finialize  mmi_frm_reset_screen_rotation");
			mmi_frm_reset_screen_rotation();
			g_vre_screen_rotate = VM_GRAPHIC_SCREEN_ROTATE_0;
		}
#endif	/*201072 ͼ��ģ�� ʹ����ɺ�Ҫ���� ��Ļ��ԭ����*/
}

static VMINT vm_graphic_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_graphic_initial();
			break;
 		case EVT_MOD_RELEASE:
			vm_graphic_finialize();
			break;
	}
	return 0;
}

VMINT _vm_reg_graphic_modual(void)
{
	VMINT res = 0;

	if ((res = _vm_reg_module("GRAPHIC MODULE", (MOD_EVT_PROCESS)vm_graphic_mod_evt_proc)) 
		!= REG_VRE_MODULE_SUCCESS)
	{
		vm_log_fatal("_vm_reg_graphic_modual : failed to register io module. errorcode=%d", res);
	}
	return res;
}



//============================FUNC FOR UT====================================
#ifdef VM_GRAPHIC_UT
void print_gdi_layers_table(void)
{

    VMINT i;
    for(i=0;i<GDI_LAYER_TOTAL_LAYER_COUNT;i++)
        vm_log_debug("gdi_layer id=%d,flag=%d",GDI_LAYERS[i].id,GDI_LAYERS[i].flag);
}
#endif

//==========================FUNC FOR MTK==================================
#if ((!defined(__VRE_RB_09A__)) && (!defined(__VRE_RB_08A__)))
#define VRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B
#endif

#define VM_GRAPHIC_CHECK_MODULE_STATE_MTK \
    do{\
        if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)\
        { \
            return;\
        }\
    }while(0)
    

void vm_graphic_status_icon_bar_hide_callback(void)
{
    S32     x1, y1, x2, y2;
    BOOL    source_key_enable;
    gdi_color   source_key_value;

//    VM_GRAPHIC_CHECK_MODULE_STATE_MTK;
    
    /* set clip region */
    gdi_layer_push_clip();

    /* get teh clip values of bar_id */
#ifndef  VRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B
#ifdef __VRE_RB_08A__
    get_status_icon_bar_clip(0, &x1, &y1, &x2, &y2);//ltz
#else
    wgui_status_icon_get_status_icon_bar_clip(0, &x1, &y1, &x2, &y2);
#endif

#else
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &x1, &y1, &x2, &y2);
#endif
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_layer_get_source_key(&source_key_enable, &source_key_value);
    gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
    gdi_layer_pop_clip();
    
    vm_log_debug("vm_graphic_status_icon_bar_hide_callback() tranc color = 0x%0004X", source_key_value);
}

void vm_graphic_show_status_icon_bar(void)
{
    gdi_handle  cur_active_layer = 0;
    
    VM_GRAPHIC_CHECK_MODULE_STATE_MTK;
    
	gdi_layer_get_active(&cur_active_layer);
#ifndef VRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B
#ifdef __VRE_RB_08A__	
    set_status_icon_bar_layer(0, cur_active_layer);//ltz
    register_hide_status_icon_bar(0, vm_graphic_status_icon_bar_hide_callback);//ltz
    show_status_icon_bar(0);//ltz
    UpdateStatusIcons();//ltz
#else    
    wgui_status_icon_set_status_icon_bar_layer(0, cur_active_layer);
    wgui_status_icon_register_hide_status_icon_bar(0, vm_graphic_status_icon_bar_hide_callback);
    wgui_status_icon_show_status_icon_bar(0);
    wgui_status_icon_update_status_icons();
#endif    
#else
    wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_H_BAR, (gdi_handle)cur_active_layer);
	wgui_status_icon_bar_register_hide_callback(WGUI_STATUS_ICON_BAR_H_BAR, vm_graphic_status_icon_bar_hide_callback);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_update();
#endif

    vm_log_debug("vm_graphic_show_status_icon_bar() function");
}

/* This api is not in the sandbox, so it will be called by other api */
void vm_graphic_reset_status_icon_bar(void)
{
//    VM_GRAPHIC_CHECK_MODULE_STATE_MTK;
    VM_PROCESS_STATUS   state = vm_pmng_state(VM_PMNG_CUR_HANDLE);
    vm_log_debug("vm_graphic_reset_status_icon_bar() current handle state = %d", state);

#ifndef VRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B
#ifdef __VRE_RB_08B__
    set_status_icon_bar_layer(0, GDI_NULL_HANDLE);//ltz
    wgui_status_icon_reset_display_layer();//ltz
#else    
    wgui_status_icon_reset_status_icon_bar_layer(0);
    wgui_status_icon_reset_all_status_icon_bar_layer();
#endif    
#else
    wgui_status_icon_bar_reset_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_reset();
#endif
    vm_log_debug("vm_graphic_reset_status_icon_bar() function");
}

/* show theme background */
void vm_graphic_show_theme_background(void)
{
    VM_GRAPHIC_CHECK_MODULE_STATE_MTK;
    
	gdi_layer_push_clip();
	gdi_layer_set_clip(0, 0, UI_DEVICE_WIDTH - 1, UI_DEVICE_HEIGHT - 1);
	//gui_draw_filled_area(0, 0, UI_DEVICE_WIDTH - 1, UI_DEVICE_HEIGHT - 1, (current_MMI_theme->sub_menu_bkg_filler));
	gdi_layer_pop_clip();
    
	vm_log_debug("vm_graphic_show_theme_background() function");
}

/* show left softkey, now it is used to reset status icon bar */
void vm_graphic_show_left_softkey(void)
{
    vm_graphic_reset_status_icon_bar();
}

void vm_graphic_show_right_softkey(void)
{return;}




#endif
