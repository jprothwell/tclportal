#ifdef __VRE__
/*******************mtk head file ******************/
#include "mmi_include.h"
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mdi_audio.h"
#include "gpioInc.h"
#include "gdi_include.h"
#include "DevConfigGprot.h"
/*************************************************/

/****************** VRE HEAD *********************/
#include "vmopt.h"
#include "vmsys.h"
#include "vmgraph.h"
#include "vmcamera.h"
#include "vmlog.h"
#include "vmio.h"
#include "vmchset.h"

#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmem.h"
#include "vmmod.h"
/*************************************************/


/*******************************************************************************************************************/
#if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
#define __VM_CAMERA_FEATURE_XENON_FLASH__
#define __VM_CAMERA_FEATURE_FLASH__
#define __VM_CAMERA_FEATURE_FLASH_AUTO__
  #if defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
        #define __VM_CAMERA_FEATURE_FLASH_REDEYE__
  #endif
#elif defined(LED_FLASHLIGHT_SUPPORT)
  #define __VM_CAMERA_FEATURE_FLASH__
  #define __VM_CAMERA_FEATURE_FLASH_AUTO__
#elif defined(LED_ONOFF_SUPPORT)
#define __VM_CAMERA_FEATURE_LED_HIGHLIGHT__
#define  __VM_CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
//#define __VM_CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
#endif

typedef enum
{
    VM_CAMERA_SETTING_LED_HIGHLIGHT_OFF,
#ifdef __VM_CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
    VM_CAMERA_SETTING_LED_HIGHLIGHT_ON,
#endif 

#ifdef __VM_CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
    VM_CAMERA_SETTING_LED_HIGHLIGHT_WHITE,
    VM_CAMERA_SETTING_LED_HIGHLIGHT_RED,
    VM_CAMERA_SETTING_LED_HIGHLIGHT_GREEN,
    VM_CAMERA_SETTING_LED_HIGHLIGHT_BLUE,
    VM_CAMERA_SETTING_LED_HIGHLIGHT_YELLOW,
    VM_CAMERA_SETTING_LED_HIGHLIGHT_PURPLE,
    VM_CAMERA_SETTING_LED_HIGHLIGHT_CYAN,
#endif
    VM_CAMERA_SETTING_LED_HIGHLIGHT_COUNT
} vm_camera_setting_led_highlight_enum;

#define __VM_CAMERA_FEATURE_EFFECT_NORMAL__
#define __VM_CAMERA_DSC_MODE_AUTO__
#define VM_CAMERA_DEFAULT_CAPTURE_LED_VALUE					(90)
#define VM_CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT 				VM_CAMERA_SETTING_LED_HIGHLIGHT_OFF
#ifdef ISO_PRIORITY_SUPPORT
#define __VM_CAEMRA_FEATURE_ISO_AUTO__
#endif
#ifdef AF_SUPPORT
#define __VM_CAMERA_AUTOFOCUS__
#define __VM_CAMERA_AUTOFOCUS_MODE_AUTO__
#define __VM_CAMERA_FEATURE_AE_METER_AUTO__
#define __VM_CAMERA_AUTOFOCUS_1_ZONE__
/*
#define __VM_CAMERA_AUTOFOCUS_3_ZONE__
#define __VM_CAMERA_AUTOFOCUS_5_ZONE__
*/

#define VM_CAMERA_AF_POSITION_1_X								(LCD_WIDTH/2)
#define VM_CAMERA_AF_POSITION_1_Y								(LCD_HEIGHT/2)
#define VM_CAMERA_AF_POSITION_2_X								(VM_CAMERA_AF_POSITION_1_X + 40)
#define VM_CAMERA_AF_POSITION_2_Y								(VM_CAMERA_AF_POSITION_1_Y)
#define VM_CAMERA_AF_POSITION_3_X								(VM_CAMERA_AF_POSITION_1_X - 40)
#define VM_CAMERA_AF_POSITION_3_Y								(VM_CAMERA_AF_POSITION_1_Y)
#define VM_CAMERA_AF_POSITION_4_X								(VM_CAMERA_AF_POSITION_1_X)
#define VM_CAMERA_AF_POSITION_4_Y								(VM_CAMERA_AF_POSITION_1_Y	+ 40)
#define VM_CAMERA_AF_POSITION_5_X								(VM_CAMERA_AF_POSITION_1_X)
#define VM_CAMERA_AF_POSITION_5_Y								(VM_CAMERA_AF_POSITION_1_Y - 40)
#endif

/*
#define __VM_CAMERA_AUTOFOCUS_MODE_MACRO__
#define __VM_CAMERA_AUTOFOCUS_MODE_INFINITE__
#define __VM_CAMERA_AUTOFOCUS_MODE_MANUAL__
*/

#if defined(SENSOR_ROTATE_0)
  #define VM_CAMERA_PREVIEW_MAINLCD_ROTATE           			MDI_CAMERA_PREVIEW_ROTATE_0
#elif defined(SENSOR_ROTATE_90)
  #define VM_CAMERA_PREVIEW_MAINLCD_ROTATE           			MDI_CAMERA_PREVIEW_ROTATE_90
#elif defined(SENSOR_ROTATE_180)
  #define VM_CAMERA_PREVIEW_MAINLCD_ROTATE           			MDI_CAMERA_PREVIEW_ROTATE_180
#else
  #define VM_CAMERA_PREVIEW_MAINLCD_ROTATE           			MDI_CAMERA_PREVIEW_ROTATE_0
#endif

#ifdef HORIZONTAL_CAMERA
#define __VM_CAMERA_OSD_HORIZONTAL__
#endif

#ifdef __VM_CAMERA_OSD_HORIZONTAL__
    #define VM_CAMERA_LCM_MAINLCD_ROTATE           					MDI_CAMERA_LCM_ROTATE_270
#else
    #define VM_CAMERA_LCM_MAINLCD_ROTATE       	    					MDI_CAMERA_LCM_ROTATE_0
#endif
/*******************************************************************************************************************/
extern VMINT vm_graphic_get_current_layer_count(void);
extern U16 GetCurKeypadTone(void);
extern void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state);
#ifdef MMI_ON_HARDWARE_P
extern void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty);
extern void custom_stop_flashlight(void);
#else
static void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty)
{
    // do noting, need hardware support flash.
}
static void custom_stop_flashlight(void)
{
    // do noting, need hardware support flash.
}
#endif

/* ����ı���� */
#define DUMMY_COMMAND                  							(0)

/* ����ͷ������preview ʱ�Ŀ�͸�*/
#ifdef MT6228_05_VERSION
#define CAM_MOTION_SENSOR_DEFAULT_WIDTH  				(128)
#define CAM_MOTION_SENSOR_DEFAULT_HEIGHT				(168)
#else
#define CAM_MOTION_SENSOR_DEFAULT_WIDTH  				(60)
#define CAM_MOTION_SENSOR_DEFAULT_HEIGHT				(80)
#endif

#define CAM_CAPTURE_MAX_WIDTH							(480)
#define CAM_CAPTURE_MAX_HEIGHT							(640)
#define CAM_PREVIEW_MAX_FPS								(30)

void vm_camera_get_support_sensor_size(VMUINT* width, VMUINT* height);

/* ͨ�������Ӧ����ɴ���3, ���С��2 ����صĺ���������������. */
#define SUPPORT_PREVIEW_SIZE_NUM 							(4)

#define NOTIFY_CAM_CALLBACK(notify_callback, notify_data, user_data, process_handle)	\
	if (notify_callback != NULL) {\
		if(vm_pmng_set_ctx(process_handle) == VM_PMNG_OP_OK)  {\
			notify_callback(notify_data, user_data);\
			vm_pmng_reset_ctx();\
		}\
	}

typedef struct vm_cam_internal_t
{
	VM_CAMERA_ID camera_id;					/* ����ͷID��,��ǰʵ��ֻ����һ������ͷID����
											    	     һ������ͷʵ��. 												*/
	int timer_id;									/* ����ͷ���ڲ�ʹ�õĶ�ʱ��ID	.							*/
	gdi_handle preview_layer;						/* Ԥ��ͼ��ľ��. 												*/
	void* preview_layer_buffer;					/* Ԥ��ͼ��Ļ���. 												*/
	unsigned int preview_width;					/* Ԥ��ͼ��Ŀ��.												*/
	unsigned int preview_height;					/* Ԥ��ͼ��ĸ߶�. 												*/
	unsigned int preview_fps;						/* Ԥ����֡��. 														*/

	gdi_handle osd_layer;							/* ��ʾ��ͼ�㣬�ò���˫����ģ����е�һ��
											   	    ������MAIN��Ļ���.											*/
	void* osd_layer_buffer_2;					/* osd layer���һ��ȫ��Ļ����. 									*/
	
	void* preview_data;							/* frame data��ͷָ��. 												*/
#if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
	void* frame_buffer;							/* preview �Ļ���,Ӧ����start preview��ʱ������ڴ�,
												     stop preview��ʱ���ͷ��ڴ�. 									*/
#endif	
	void* capture_data;							/* ��Ƭ����. 														*/
	unsigned int capture_data_size;				/* ��Ƭ���ݵĳߴ�. 												*/
	unsigned int capture_width;					/* ��Ƭ�Ŀ�. 														*/
	unsigned int capture_height;					/* ��Ƭ�ĸ�. 														*/

	int before_capature_repreview_success;			/* ����Ԥ���Ƿ�ɹ�. FALSE Ϊ���ɹ�,TRUEΪ�ɹ�.			*/
	unsigned int before_capture_width;				/* ������Ԥ��ǰ����Ƭ�Ŀ��. 								*/
	unsigned int before_capture_height;			/* ������Ԥ��ǰ����Ƭ�ĸ߶�. 								*/
	
	VM_CAMERA_STATUS_NOTIFY cam_callback;		/* Ӧ�ó���ע�������Ļ������. 							*/
	vm_cam_notify_data_t user_notify_data; 		/* �ͻ�����ص����ݽṹ. 										*/
	void* user_data;								/* Ӧ�ó��������. 												*/
	VM_P_HANDLE pHandle;
}vm_cam_internal_t;

/**
 * ֧�ֵ�Ԥ��֡�ĳߴ�.
 */
static vm_cam_size_t PREV_DEF_SIZE_LIS[SUPPORT_PREVIEW_SIZE_NUM];

/**
 * ����ͷ�ĺ������ݽṹ.
 */
static vm_cam_internal_t* mainCamCorePtr = NULL;

/**
 * ��ʼ��Ԥ���ߴ�, �±�Ϊ0�ߴ�Ϊ��camera sensorʹ�õ�.
 *
 * @return ����֧�ֵĳߴ����.
 */
static VMUINT vm_init_preview_size_list(void);

/**
 * ����ͷģ����ڴ洦����.
 * 
 * @param 		tid ��ʱ��ID.
 */
static void cam_internal_timer_proc(int tid);

/**
 * ��������ͷ��Ԥ��ģʽ.
 *
 * @return 		TRUE ��ʾ�����ɹ�,FALSE ��ʾʧ��.
 */
static VMINT cam_really_start_preview(void);

/**
 * ����preview ��Դ.
 *
 *
 * @return 		TRUE ��ʾ����preview ��Դ�ɹ�, FALSE ��Ϊʧ��.
 */
static VMINT cam_create_preview_resource(void);

/**
 * �ͷ�preview ��Դ, ��������ε��ö�û�и�����.
 */
static void cam_free_preview_resource(void);

/**
 * �����յ������.
 */
static void vm_cam_turn_on_capture_flash(void);

/**
 * ֹͣ����ͷԤ��ģʽ��
 */
static void cam_really_stop_preview(void);

/**
 * �ر����յ������.
 */
static void vm_cam_turn_off_capture_flash(void);

static void vm_cam_process_notify_state(VM_P_HANDLE process_handle, 
	VMINT sys_state)
{
	if (mainCamCorePtr)
	{
		if (sys_state == VM_PMNG_BACKGROUND || sys_state == VM_PMNG_UNLOAD)
		{
			if (mainCamCorePtr->pHandle == process_handle)
			{
				/* �ͷŵĴ��� */
				if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_STARTING_PREVIEW_STATUS
					|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS
					|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS)
				{
					/* ����Ѿ���Ԥ��״̬����Ҫֹͣ����ͷ��Ԥ��ģʽ. */
					if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS
						|| (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS
							&& mainCamCorePtr->before_capature_repreview_success))	
						cam_really_stop_preview();

					cam_free_preview_resource();
				}
				
				vm_delete_timer((VMSHORT)mainCamCorePtr->timer_id);
				_vm_kernel_free(mainCamCorePtr);
				mainCamCorePtr = NULL;

				TurnOffBacklight();
				mdi_audio_resume_background_play();								// resume background audio
				mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);	
			}
		}
	}
}

static VMINT vm_initialize_camera_module(void)
{
	if (vm_res_type_set_notify_callback(VM_RES_TYPE_CAMERA, 
		(vm_res_release_callback_t)vm_cam_process_notify_state) == 0)
	{
		return 0;
	}

	return -1;
}

static void vm_finialize_camera_module(void)
{
	vm_res_type_set_notify_callback(VM_RES_TYPE_CAMERA, NULL);

	if (mainCamCorePtr)
	{
		/* �ͷŵĴ��� */
		if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_STARTING_PREVIEW_STATUS
			|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS
			|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS)
		{
			/* ����Ѿ���Ԥ��״̬����Ҫֹͣ����ͷ��Ԥ��ģʽ. */
			if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS
				|| (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS
					&& mainCamCorePtr->before_capature_repreview_success))	
				cam_really_stop_preview();

			cam_free_preview_resource();
		}

		vm_delete_timer((VMSHORT)mainCamCorePtr->timer_id);
		_vm_kernel_free(mainCamCorePtr);
		mainCamCorePtr = NULL;

		TurnOffBacklight();
		mdi_audio_resume_background_play();								// resume background audio
		mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);	
	}
}

static VMINT vm_cam_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			if (vm_initialize_camera_module() != 0)
				return -1;
			break;
 		case EVT_MOD_RELEASE:
			vm_finialize_camera_module();
			break;
	}
	return 0;
}

VMINT _vm_reg_cam_module(void)
{
	int res_code = REG_VRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("CAMERA MODULE", 
		(MOD_EVT_PROCESS)vm_cam_mod_evt_proc)) != REG_VRE_MODULE_SUCCESS)
	{
		vm_log_error("[CAMERA MODULE]Failed to regisiter camera module. Error Code : %d", res_code);
	}

	return res_code;
}

static void vm_cam_turn_on_capture_flash(void)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	VMUINT8 duty = VM_CAMERA_DEFAULT_CAPTURE_LED_VALUE;

    	if (duty == 0)
    	{
       	custom_stop_flashlight();
        	return;
    	}

#ifdef __VM_CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
	switch (VM_CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT)
    	{
       case VM_CAMERA_SETTING_LED_HIGHLIGHT_WHITE:
		custom_start_flashlight(1, 1, 1, duty);
            	break;

       case VM_CAMERA_SETTING_LED_HIGHLIGHT_RED:
            	custom_start_flashlight(1, 0, 0, duty);
            	break;

       case VM_CAMERA_SETTING_LED_HIGHLIGHT_GREEN:
            	custom_start_flashlight(0, 1, 0, duty);
            	break;

       case VM_CAMERA_SETTING_LED_HIGHLIGHT_BLUE:
            	custom_start_flashlight(0, 0, 1, duty);
            	break;

       case VM_CAMERA_SETTING_LED_HIGHLIGHT_YELLOW:
            	custom_start_flashlight(1, 1, 0, duty);
            	break;

       case VM_CAMERA_SETTING_LED_HIGHLIGHT_PURPLE:
            	custom_start_flashlight(1, 0, 1, duty);
            	break;

       case VM_CAMERA_SETTING_LED_HIGHLIGHT_CYAN:
            	custom_start_flashlight(0, 1, 1, duty);
            	break;

       case VM_CAMERA_SETTING_LED_HIGHLIGHT_OFF:
            	custom_stop_flashlight();
           	break;
    }
#endif

#ifdef __VM_CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
    switch (VM_CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT)
    {
        case VM_CAMERA_SETTING_LED_HIGHLIGHT_ON:
            custom_start_flashlight(1, 1, 1, duty);
            break;

        case VM_CAMERA_SETTING_LED_HIGHLIGHT_OFF:
            custom_stop_flashlight();
            break;
    }
#endif
#endif
}

static void vm_cam_turn_off_capture_flash(void)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	custom_stop_flashlight();
#endif
}

static VMUINT vm_init_preview_size_list(void)
{
	VMINT i = 0;
	vm_cam_size_t* sizePtr = NULL;

	if (SUPPORT_PREVIEW_SIZE_NUM <= 0)
		return 0;
	else
	{	
		/*
		  * ��ʼ��camera sensor ֧�ֵ�preview ���ڳߴ�.
		  */
		vm_camera_get_support_sensor_size(&(PREV_DEF_SIZE_LIS[0].width), 
			&(PREV_DEF_SIZE_LIS[0].height));

		/*
		  * ��ʼ��ͨ��preview ���ڳߴ�.
		  */
		for (i = 1, sizePtr = PREV_DEF_SIZE_LIS + 1; i < SUPPORT_PREVIEW_SIZE_NUM; i++, sizePtr++)
		{
			/* ��֤�߶Ȳ�С��MAIN LCD ��һ��߶ȡ� */
			if ((LCD_HEIGHT - (i - 1) * 40) < (LCD_HEIGHT >> 1))
				break;
		
			sizePtr->width = LCD_WIDTH;
			sizePtr->height = LCD_HEIGHT - (i - 1) * 40;
		}

		return i;
	}
}

static VMINT cam_create_preview_resource(void)
{
	VMINT osdLayerBufferSize = (LCD_WIDTH * LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
	VMINT previewBufferSize =(mainCamCorePtr->preview_width * mainCamCorePtr->preview_height 
		* GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
	U8* mainBufferPtr = NULL;

	gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
	gdi_layer_get_buffer_ptr(&mainBufferPtr);
	gdi_layer_pop_and_restore_active();

	/* 150K QVGA , 75K QCIF, 187.5K WQVGA */
	if ((mainCamCorePtr->osd_layer_buffer_2 = vm_malloc(osdLayerBufferSize)) == NULL)
		return FALSE;
	
	if ((mainCamCorePtr->preview_layer_buffer = vm_malloc(previewBufferSize)) == NULL)
	{
		vm_free(mainCamCorePtr->osd_layer_buffer_2);
		mainCamCorePtr->osd_layer_buffer_2 = NULL;
		return FALSE;
	}

#if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
	if ((mainCamCorePtr->frame_buffer = vm_malloc(previewBufferSize)) == NULL)
	{
		vm_free(mainCamCorePtr->preview_layer_buffer);
		mainCamCorePtr->preview_layer_buffer = NULL;
		vm_free(mainCamCorePtr->osd_layer_buffer_2);
		mainCamCorePtr->osd_layer_buffer_2 = NULL;
		
		return FALSE;
	}
#endif

	/* ����preview ��. */
	if (GDI_SUCCEED != gdi_layer_create_cf_using_outside_memory(GDI_LCD->cf, 0, 0, 
#if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
		mainCamCorePtr->preview_height, mainCamCorePtr->preview_width,
#else
		mainCamCorePtr->preview_width, mainCamCorePtr->preview_height,
#endif
		&mainCamCorePtr->preview_layer, (U8*)mainCamCorePtr->preview_layer_buffer, 
		previewBufferSize))
	{
		vm_free(mainCamCorePtr->preview_layer_buffer);
		mainCamCorePtr->preview_layer_buffer = NULL;
		vm_free(mainCamCorePtr->osd_layer_buffer_2);
		mainCamCorePtr->osd_layer_buffer_2 = NULL;

#if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
		vm_free(mainCamCorePtr->frame_buffer);
		mainCamCorePtr->frame_buffer = NULL;
#endif
		return FALSE;
	}
	gdi_layer_push_and_set_active(mainCamCorePtr->preview_layer);

	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_pop_and_restore_active();

	/* ����osd ��. 	*/
	if (GDI_SUCCEED != gdi_layer_create_cf_double_using_outside_memory(
		GDI_LCD->cf, 0, 0, LCD_WIDTH, LCD_HEIGHT, 
		&mainCamCorePtr->osd_layer, (U8*)mainCamCorePtr->osd_layer_buffer_2, osdLayerBufferSize, 
		(U8*)mainBufferPtr, osdLayerBufferSize))
	{
		gdi_layer_free(mainCamCorePtr->preview_layer);
		mainCamCorePtr->preview_layer = GDI_LAYER_EMPTY_HANDLE;

		vm_free(mainCamCorePtr->preview_layer_buffer);
		mainCamCorePtr->preview_layer_buffer = NULL;
		vm_free(mainCamCorePtr->osd_layer_buffer_2);
		mainCamCorePtr->osd_layer_buffer_2 = NULL;

#if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
		vm_free(mainCamCorePtr->frame_buffer);
		mainCamCorePtr->frame_buffer = NULL;
#endif

		return FALSE;
	}
	gdi_layer_push_and_set_active(mainCamCorePtr->osd_layer);
	memcpy(mainCamCorePtr->osd_layer_buffer_2, mainBufferPtr, osdLayerBufferSize);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_pop_and_restore_active();

	return TRUE;
	
}

static void cam_free_preview_resource(void)
{
	/* �ͷŵ�osd ����Դ. */
	if (mainCamCorePtr->osd_layer_buffer_2 != NULL)
	{
		vm_free(mainCamCorePtr->osd_layer_buffer_2);
		//mmi_frm_scrmem_free(mainCamCorePtr->osd_layer_buffer_2);
		mainCamCorePtr->osd_layer_buffer_2 = NULL;
	}
	if (mainCamCorePtr->osd_layer != GDI_LAYER_EMPTY_HANDLE)
	{
		gdi_layer_free(mainCamCorePtr->osd_layer);
		mainCamCorePtr->osd_layer = GDI_LAYER_EMPTY_HANDLE;
	}

	/* �ͷŵ�preview ����Դ. */
	if (mainCamCorePtr->preview_layer_buffer != NULL)
	{
		vm_free(mainCamCorePtr->preview_layer_buffer);
		mainCamCorePtr->preview_layer_buffer = NULL;
	}
	if (mainCamCorePtr->preview_layer != GDI_LAYER_EMPTY_HANDLE)
	{
		gdi_layer_free(mainCamCorePtr->preview_layer);
		mainCamCorePtr->preview_layer = GDI_LAYER_EMPTY_HANDLE;
	}

#if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
		vm_free(mainCamCorePtr->frame_buffer);
		mainCamCorePtr->frame_buffer = NULL;
#endif

}

static VMINT cam_really_start_preview(void)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	mdi_camera_setting_struct camera_setting_data = {0};
#if (defined(MT6225_06_VERSION) || defined(MT6226_06_VERSION) || defined(MT6228_05_VERSION))
	GDI_HANDLE preview_layer_handle = 0;
	U32 preview_layer_flag = 0;
	U32 blt_layer_flag = 0;
	S32 preview_wnd_offset_x = 0;
	S32 preview_wnd_offset_y = 0;
	U16 preview_wnd_width = 0;
	U16 preview_wnd_height 	= 0;
#else
	mdi_camera_preview_struct	preview_setting_data = {0};
#endif

	/* ������ͷ��Դ. 				 		*/
	if (mdi_camera_power_on() != MDI_RES_CAMERA_SUCCEED)
		return FALSE;
	
	/* ��ʼ������ͷ����Ԥ���Ĺ���. 	*/
	mdi_camera_load_default_setting(&camera_setting_data);
/***************************** VRE control camera setting data setup  **************************************/	
	/* preview parameters */
#ifdef __VM_CAMERA_OSD_HORIZONTAL__
	camera_setting_data.preview_width 				=  mainCamCorePtr->preview_height;
	camera_setting_data.preview_height 				=  mainCamCorePtr->preview_width;
#else
	camera_setting_data.preview_width 				=  mainCamCorePtr->preview_width;
	camera_setting_data.preview_height 				=  mainCamCorePtr->preview_height;
#endif
	camera_setting_data.continue_capture 			=  TRUE;
	
	/* capture parameters */
	camera_setting_data.image_width				= mainCamCorePtr->capture_width;
	camera_setting_data.image_height				= mainCamCorePtr->capture_height;	
/****************************************************************************************************/
	camera_setting_data.lcm 						= MDI_CAMERA_PREVIEW_LCM_MAINLCD;
	camera_setting_data.preview_rotate 				= VM_CAMERA_PREVIEW_MAINLCD_ROTATE;
	camera_setting_data.lcm_rotate 					= VM_CAMERA_LCM_MAINLCD_ROTATE;

#ifdef __VM_CAMERA_AUTOFOCUS__
  #ifdef __VM_CAMERA_OSD_HORIZONTAL__
		{
			S32 tmp;

			#define TRANSLATE_COORDINATE_TO_270(X,Y,TMP)\
				TMP=X;\
				X=Y;\
				Y=(LCD_WIDTH-1)-TMP;
			
			camera_setting_data.af_zone0_x = VM_CAMERA_AF_POSITION_1_X;
			camera_setting_data.af_zone0_y = VM_CAMERA_AF_POSITION_1_Y;
			camera_setting_data.af_zone1_x = VM_CAMERA_AF_POSITION_2_X;
			camera_setting_data.af_zone1_y = VM_CAMERA_AF_POSITION_2_Y;
			camera_setting_data.af_zone2_x = VM_CAMERA_AF_POSITION_3_X;
			camera_setting_data.af_zone2_y = VM_CAMERA_AF_POSITION_3_Y;
			camera_setting_data.af_zone3_x = VM_CAMERA_AF_POSITION_4_X;
			camera_setting_data.af_zone3_y = VM_CAMERA_AF_POSITION_4_Y;
			camera_setting_data.af_zone4_x = VM_CAMERA_AF_POSITION_5_X;
			camera_setting_data.af_zone4_y = VM_CAMERA_AF_POSITION_5_Y;
		
			TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone0_x,camera_setting_data.af_zone0_y,tmp);
			TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone1_x,camera_setting_data.af_zone1_y,tmp);
			TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone2_x,camera_setting_data.af_zone2_y,tmp);
			TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone3_x,camera_setting_data.af_zone3_y,tmp);
			TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone4_x,camera_setting_data.af_zone4_y,tmp);
		}
  #else
		camera_setting_data.af_zone0_x = VM_CAMERA_AF_POSITION_1_X;
		camera_setting_data.af_zone0_y = VM_CAMERA_AF_POSITION_1_Y;
		camera_setting_data.af_zone1_x = VM_CAMERA_AF_POSITION_2_X;
		camera_setting_data.af_zone1_y = VM_CAMERA_AF_POSITION_2_Y;
		camera_setting_data.af_zone2_x = VM_CAMERA_AF_POSITION_3_X;
		camera_setting_data.af_zone2_y = VM_CAMERA_AF_POSITION_3_Y;
		camera_setting_data.af_zone3_x = VM_CAMERA_AF_POSITION_4_X;
		camera_setting_data.af_zone3_y = VM_CAMERA_AF_POSITION_4_Y;
		camera_setting_data.af_zone4_x = VM_CAMERA_AF_POSITION_5_X;
		camera_setting_data.af_zone4_y = VM_CAMERA_AF_POSITION_5_Y;
  #endif // HORIZONTAL_CAMERA
#endif // __CAMERA_AUTOFOCUS__
	
	gdi_layer_set_blt_layer(mainCamCorePtr->preview_layer, mainCamCorePtr->osd_layer, 0, 0);

#if defined(__VM_CAMERA_OSD_HORIZONTAL__) && defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__)
	mdi_camera_set_hw_rotator(MDI_CAMERA_PREVIEW_ROTATE_90);
#endif

#if (defined(MT6225_06_VERSION) || defined(MT6226_06_VERSION) || defined(MT6228_05_VERSION))
	preview_layer_handle		= mainCamCorePtr->preview_layer;
	preview_wnd_offset_x	 	= 0;
	preview_wnd_offset_y	 	= 0;
#ifdef __VM_CAMERA_OSD_HORIZONTAL__
	preview_wnd_width        	= mainCamCorePtr->preview_height;
	preview_wnd_height	 	= mainCamCorePtr->preview_width;
#else
	preview_wnd_width        	= mainCamCorePtr->preview_width;
	preview_wnd_height	 	= mainCamCorePtr->preview_height;
#endif
	blt_layer_flag 				= GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
	preview_layer_flag			= GDI_LAYER_ENABLE_LAYER_0;

	if (MDI_RES_CAMERA_SUCCEED != mdi_camera_preview_start(
		preview_layer_handle,
		preview_wnd_offset_x, 
		preview_wnd_offset_y,
		preview_wnd_width, 
		preview_wnd_height,
		blt_layer_flag, 
		preview_layer_flag, 
  #ifdef MT6225_06_VERSION
		TRUE, 
  #endif
		GDI_COLOR_TRANSPARENT, 
		TRUE, 
		&camera_setting_data))
	{
		mdi_camera_power_off();
		gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
		return FALSE;
	}
#else
	preview_setting_data.preview_layer_handle = mainCamCorePtr->preview_layer;
	preview_setting_data.preview_wnd_offset_x = 0;
	preview_setting_data.preview_wnd_offset_y = 0;
#ifdef __VM_CAMERA_OSD_HORIZONTAL__
	preview_setting_data.preview_wnd_width = mainCamCorePtr->preview_height;
	preview_setting_data.preview_wnd_height = mainCamCorePtr->preview_width;
#else
	preview_setting_data.preview_wnd_width = mainCamCorePtr->preview_width;
	preview_setting_data.preview_wnd_height = mainCamCorePtr->preview_height;
#endif
	preview_setting_data.is_lcd_update = TRUE;
	preview_setting_data.src_key_color = GDI_COLOR_TRANSPARENT;
	preview_setting_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
	preview_setting_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
	preview_setting_data.is_tvout = FALSE;
	
	if (MDI_RES_CAMERA_SUCCEED != mdi_camera_preview_start(
		&preview_setting_data, &camera_setting_data))
	{
		mdi_camera_power_off();
		gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
		return FALSE;
	}
	
#endif

	return TRUE;
#else

	return FALSE;
#endif
}

static void cam_really_stop_preview(void)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	mdi_camera_preview_stop();
	mdi_camera_power_off();
	gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
#endif
}

static void cam_internal_timer_proc(int tid)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	static VMINT fps_expired_ms;
	static VMINT fps_current_ms;
	vm_cam_notify_data_t notify_data;
	

	if (mainCamCorePtr != NULL)
	{
		switch (mainCamCorePtr->user_notify_data.cam_status)
		{
		case VM_CAM_PREVIEW_STATUS:
			if (mainCamCorePtr->preview_layer != GDI_LAYER_EMPTY_HANDLE
				&& mainCamCorePtr->preview_layer_buffer != NULL)
			{
				fps_current_ms -= 10;

				if (fps_current_ms <= 0)
				{
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_FRAME_RECEIVED;
					memcpy(&notify_data, &mainCamCorePtr->user_notify_data, sizeof(vm_cam_notify_data_t));
					NOTIFY_CAM_CALLBACK(mainCamCorePtr->cam_callback, &notify_data,  
						mainCamCorePtr->user_data, mainCamCorePtr->pHandle);

					fps_current_ms = fps_expired_ms;
				}
			}
			break;
		case VM_CAM_STARTING_PREVIEW_STATUS:
			if (vm_graphic_get_current_layer_count() > 1)
			{
				mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
				mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_START_ABORT;
			}
			else
			{
				mainCamCorePtr->before_capture_width = mainCamCorePtr->capture_width;
				mainCamCorePtr->before_capture_height = mainCamCorePtr->capture_height;
				
				if (cam_really_start_preview())
				{
					VMINT mod = 0;
				
					/* �����ɹ�,����ͷ����Ԥ��״̬ */
					mainCamCorePtr->user_notify_data.cam_status = VM_CAM_PREVIEW_STATUS;
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_START_DONE;

					/* FPS �Ĺ���ʱ��. 						*/
					fps_expired_ms = 1000 / mainCamCorePtr->preview_fps;
					if ((mod = (fps_expired_ms % 10)) > 4)
						fps_expired_ms += (10 - mod);
					else
						fps_expired_ms -= mod;
					fps_current_ms = fps_expired_ms;
				}
				else
				{
					/* ����ʧ��,����ͷ�������״̬ */
					mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_START_ABORT;
					
					cam_free_preview_resource();
				}	
			}
			
			memcpy(&notify_data, &mainCamCorePtr->user_notify_data, sizeof(vm_cam_notify_data_t));
			NOTIFY_CAM_CALLBACK(mainCamCorePtr->cam_callback, &notify_data,  
				mainCamCorePtr->user_data, mainCamCorePtr->pHandle);
			break;
		case VM_CAM_STOPPING_PREVIEW_STATUS:
			mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_STOP_DONE;
			mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
			memcpy(&notify_data, &mainCamCorePtr->user_notify_data, sizeof(vm_cam_notify_data_t));
			
			NOTIFY_CAM_CALLBACK(mainCamCorePtr->cam_callback, &notify_data,  
				mainCamCorePtr->user_data, mainCamCorePtr->pHandle);
			break;
		case VM_CAM_CAPTURING_STATUS:
			/* �ٴ�����preview �Ƿ�ɹ� */
			if (mainCamCorePtr->before_capature_repreview_success)
			{
				VMCHAR capture_tmp_filename[12];
				VMWCHAR wide_capture_tmp_filename[12];
				
				sprintf(capture_tmp_filename, "%c:\\tmp.dat", (VMCHAR)vm_get_system_driver());
				vm_ascii_to_ucs2(wide_capture_tmp_filename, 
					sizeof(wide_capture_tmp_filename), capture_tmp_filename);
				//vm_gb2312_to_ucs2(wide_capture_tmp_filename, 
				//	sizeof(wide_capture_tmp_filename), capture_tmp_filename);
				vm_file_delete(wide_capture_tmp_filename);
				
				vm_cam_turn_on_capture_flash();
				
				if (mdi_camera_capture_to_memory((U8**)&(mainCamCorePtr->capture_data), 
					&mainCamCorePtr->capture_data_size
					,(S8*)wide_capture_tmp_filename
					) == MDI_RES_CAMERA_SUCCEED 
					&& mdi_camera_save_captured_image() == MDI_RES_CAMERA_SUCCEED
				)
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_CAPTURE_DONE;
				else
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_CAPTURE_ABORT;
				
				vm_cam_turn_off_capture_flash();
				mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
			}
			else
			{
				mainCamCorePtr->before_capature_repreview_success = TRUE;

				mainCamCorePtr->user_notify_data.cam_message = VM_CAM_CAPTURE_ABORT;
				mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
			}

			/* �ͷ���preview  ʱ�����Դ.						*/
			cam_free_preview_resource();

			/* �ص��ͻ�����. 									*/
			memcpy(&notify_data, &mainCamCorePtr->user_notify_data, sizeof(vm_cam_notify_data_t));
			NOTIFY_CAM_CALLBACK(mainCamCorePtr->cam_callback, &notify_data,  
				mainCamCorePtr->user_data, mainCamCorePtr->pHandle);

			/* ��capture ��������������ȥ��.				*/
			mainCamCorePtr->capture_data = NULL;
			mainCamCorePtr->capture_data_size = 0;

			/* �ر�����ͷ, ������ͷ���Ƭ���ڴ�.		*/
			mdi_camera_power_off();
			gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
            		
			break;
		}
	}
#endif
}

VMINT vm_create_camera_instance(VM_CAMERA_ID camera_id, 
	VM_CAMERA_HANDLE* handle_ptr)
{  
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	VM_P_HANDLE proHandle = vm_pmng_get_current_handle();

	if (vm_pmng_state(proHandle) != VM_PMNG_FOREGROUND)
	{
		return VM_CAM_OPERATION_IN_PROCESS_STATUS;
	}
	
	if (camera_id != VM_CAMERA_MAIN_ID)
	 	return VM_CAM_ERR_INVALID_CAM_ID;

	if (handle_ptr == NULL)
	 	return VM_CAM_ERR_BAD_PARAM;

	if (mainCamCorePtr != NULL)
	 	return VM_CAM_ERR_CAM_INSTANCE_CREATED;

	/* ��ʼ����Ԥ���ĳߴ�����. */
	if (vm_init_preview_size_list() <= 1)
		return VM_CAM_ERR_CAM_INTERNAL_ERROR;
	
	if ((mainCamCorePtr = _vm_kernel_malloc(sizeof(vm_cam_internal_t))) == NULL)
	 	return VM_CAM_ERR_NOMEMORY;

	memset(mainCamCorePtr, 0x00, sizeof(vm_cam_internal_t));
	mainCamCorePtr->pHandle = proHandle;
	mainCamCorePtr->camera_id = VM_CAMERA_MAIN_ID;
	mainCamCorePtr->user_notify_data.handle = VM_CAMERA_MAIN_ID;
	mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
	mainCamCorePtr->preview_width = LCD_WIDTH;
	mainCamCorePtr->preview_height = LCD_HEIGHT;
	mainCamCorePtr->preview_fps = CAM_PREVIEW_MAX_FPS;

	mainCamCorePtr->capture_width = LCD_WIDTH;
	mainCamCorePtr->capture_height = LCD_HEIGHT;

	mainCamCorePtr->before_capture_width = LCD_WIDTH;
	mainCamCorePtr->before_capture_height = LCD_HEIGHT;

	mainCamCorePtr->osd_layer = GDI_LAYER_EMPTY_HANDLE;
	mainCamCorePtr->preview_layer = GDI_LAYER_EMPTY_HANDLE;

	mainCamCorePtr->capture_data = NULL;
	mainCamCorePtr->capture_data_size = 0;
	mainCamCorePtr->preview_data = NULL;

#if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
	 mainCamCorePtr->frame_buffer = NULL;
#endif

	mainCamCorePtr->preview_layer_buffer = NULL;
	mainCamCorePtr->before_capature_repreview_success =TRUE;


	/* ��������ͷģ��Ĵ���ʱ�� */
	if ((mainCamCorePtr->timer_id = vm_create_timer(10, (VM_TIMERPROC_T)cam_internal_timer_proc)) < 0)
	{
		_vm_kernel_free(mainCamCorePtr);
		mainCamCorePtr = NULL;
		return VM_CAM_ERR_NOMEMORY;
	}

	/* ִ�� ��������ͷģʽǰ�Ĳ��� */
	mdi_audio_suspend_background_play();						// �����audio ���ڲ���,����ͣ. 
	TurnOnBacklight(0);										// ��ֹMMI��������ģʽ. 		 
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
	
	*handle_ptr = mainCamCorePtr->user_notify_data.handle;
	 return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_register_notify(VM_CAMERA_HANDLE handle, VM_CAMERA_STATUS_NOTIFY notify_callback, 
	void* user_data)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (notify_callback == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	mainCamCorePtr->user_data = user_data;
	mainCamCorePtr->cam_callback = notify_callback;

	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_get_support_preview_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t** cam_size_list, 
	VMUINT* list_size)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	VMUINT size = 0;

	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (cam_size_list == NULL || list_size == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	if ((size = vm_init_preview_size_list()) <= 1)
		return VM_CAM_ERR_CAM_INTERNAL_ERROR;
	else
	{	
		*cam_size_list = PREV_DEF_SIZE_LIS + 1; 		// 0 �±���motion sensor �Ŀ�Ⱥ͸߶ȡ�
		*list_size = size - 1;					     	// �۳�motion sensor �Ŀ�Ⱥ͸߶�.
	}
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_set_preview_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t* preview_size)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	VMUINT size = 0, i = 0;
	vm_cam_size_t* sizePtr = NULL;

	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (preview_size == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	if (mainCamCorePtr->user_notify_data.cam_status != VM_CAM_READY_STATUS)
		return VM_CAM_ERR_OPERATE_BAD_STATUS;

	if ((size = vm_init_preview_size_list()) <= 1)
		return VM_CAM_ERR_CAM_INTERNAL_ERROR;
	else
	{	
		for (i = 0, sizePtr = PREV_DEF_SIZE_LIS; i < size; i++)
		{
			if ((sizePtr + i)->width == preview_size->width && (sizePtr + i)->height == preview_size->height)
			{
				mainCamCorePtr->preview_width = preview_size->width;
				mainCamCorePtr->preview_height = preview_size->height;

				return VM_CAM_SUCCESS;
			}
		}
	}

	return VM_CAM_ERR_BAD_PARAM;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif	
}

VMINT vm_get_camera_status(VM_CAMERA_HANDLE handle, VM_CAMERA_STATUS* cam_status)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (cam_status == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	*cam_status = mainCamCorePtr->user_notify_data.cam_status;
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_set_preview_fps(VM_CAMERA_HANDLE handle, VMUINT fps)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE

	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (fps == 0)
		return VM_CAM_ERR_BAD_PARAM;

	if (mainCamCorePtr->user_notify_data.cam_status != VM_CAM_READY_STATUS)
		return VM_CAM_ERR_OPERATE_BAD_STATUS;

	mainCamCorePtr->preview_fps = (fps >= CAM_PREVIEW_MAX_FPS ? CAM_PREVIEW_MAX_FPS : fps);

	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_preview_start(VM_CAMERA_HANDLE handle)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();

	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	/* ����̵��ж� */
	if (process_handle != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;
	if (mainCamCorePtr->pHandle != 0 
		&& vm_pmng_state(process_handle) != VM_PMNG_FOREGROUND)
		return VM_CAM_OPERATION_IN_PROCESS_STATUS;

	if (mainCamCorePtr->user_notify_data.cam_status != VM_CAM_READY_STATUS)
		return VM_CAM_ERR_OPERATE_BAD_STATUS;

	if (mainCamCorePtr->cam_callback == NULL)
		return VM_CAM_ERR_NOT_REGISTER_NOTIFY;

	if (vm_graphic_get_current_layer_count() > 1)
		return VM_CAM_ERR_NOMEMORY;

	if (!cam_create_preview_resource())
		return VM_CAM_ERR_NOMEMORY;
	
	/* ���ڴ���Ӧ�ó���preveiw frame �Ļ�����ʱ�Ȳ�����. */

	/* 
	  * �Ѿ��������Ҫ���ڴ�, ��״̬���ó������ɻص�����
	  * ����������ͷ����
	  */
	mainCamCorePtr->user_notify_data.cam_status = VM_CAM_STARTING_PREVIEW_STATUS;
		
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_preview_stop(VM_CAMERA_HANDLE handle)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (mainCamCorePtr->user_notify_data.cam_status != VM_CAM_STARTING_PREVIEW_STATUS
		&& mainCamCorePtr->user_notify_data.cam_status != VM_CAM_PREVIEW_STATUS)
		return VM_CAM_ERR_OPERATE_BAD_STATUS;

	if (mainCamCorePtr->cam_callback == NULL)
		return VM_CAM_ERR_NOT_REGISTER_NOTIFY;

	/* ����Ѿ���Ԥ��״̬����Ҫֹͣ����ͷ��Ԥ��ģʽ. */
	if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS)	
		cam_really_stop_preview();

	cam_free_preview_resource();

	mainCamCorePtr->user_notify_data.cam_status = VM_CAM_STOPPING_PREVIEW_STATUS;
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_get_frame(VM_CAMERA_HANDLE handle, vm_cam_frame_data_t* frame_data)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE

  #if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
	VMUINT i = 0, j = 0;
	VMBYTE* source_buffer = NULL;
	VMUINT16* pixtel_16 = 0;
	VMUINT* pixtel_32 = 0;
  #endif
  
	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;
	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (frame_data == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	if (VM_CAM_PREVIEW_STATUS != mainCamCorePtr->user_notify_data.cam_status
		|| mainCamCorePtr->preview_layer == GDI_LAYER_EMPTY_HANDLE
		|| mainCamCorePtr->preview_layer_buffer == NULL
  #if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
		|| mainCamCorePtr->frame_buffer == NULL
  #endif
  		)
  	{
		return VM_CAM_ERR_OPERATE_BAD_STATUS;
  	}

	gdi_layer_push_and_set_active(mainCamCorePtr->preview_layer);
	switch (gdi_layer_get_bit_per_pixel())
	{
	case 16:
		frame_data->pixtel_format = PIXTEL_BGR565;

  #if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
		pixtel_16 = mainCamCorePtr->frame_buffer;
  		source_buffer = (VMBYTE*)mainCamCorePtr->preview_layer_buffer;
		GDI_LOCK; 
		{
			for (i = 0; i < mainCamCorePtr->preview_height; i++)
			{
				for (j = 0; j < mainCamCorePtr->preview_width; j++)
				{
					pixtel_16[i * LCD_WIDTH + j] = *(source_buffer + ((mainCamCorePtr->preview_width - j - 1)* mainCamCorePtr->preview_height + i) * 2) 
						+ (*(source_buffer + ((mainCamCorePtr->preview_width - j - 1)* mainCamCorePtr->preview_height + i ) * 2 + 1) << 8);	
				}
			}
		}  
		GDI_UNLOCK;
		frame_data->pixtel_data = mainCamCorePtr->frame_buffer;
  #else
		frame_data->pixtel_data = mainCamCorePtr->preview_layer_buffer;
  #endif
		
		break;
	case 24:
		frame_data->pixtel_format = PIXTEL_BGR888;

  #if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
		pixtel_32 = mainCamCorePtr->frame_buffer;
  		source_buffer = (VMBYTE*)mainCamCorePtr->preview_layer_buffer;

		GDI_LOCK;
		{
			for (i = 0; i < mainCamCorePtr->preview_height; i++)
			{
				for (j = 0; j < mainCamCorePtr->preview_width; j++)
				{
					pixtel_32[i * LCD_WIDTH + j] = *(source_buffer + ((mainCamCorePtr->preview_width - j - 1)* mainCamCorePtr->preview_height + i) * 2) 
						+ (*(source_buffer + ((mainCamCorePtr->preview_width - j - 1)* mainCamCorePtr->preview_height + i ) * 2 + 1) << 8);	
				}
			}
		}
		GDI_UNLOCK;
		frame_data->pixtel_data = mainCamCorePtr->frame_buffer;
  #else
		frame_data->pixtel_data = mainCamCorePtr->preview_layer_buffer;
  #endif
		
		break;
	case 32:
		frame_data->pixtel_format = PIXTEL_ABGR8888;

  #if (defined(__VM_CAMERA_OSD_HORIZONTAL__) && !defined(__MDI_CAMERA_HW_ROTATOR_BY_IDP__))
		pixtel_32 = mainCamCorePtr->frame_buffer;
  		source_buffer = (VMBYTE*)mainCamCorePtr->preview_layer_buffer;

		GDI_LOCK;
		{
			for (i = 0; i < mainCamCorePtr->preview_height; i++)
			{
				for (j = 0; j < mainCamCorePtr->preview_width; j++)
				{
					pixtel_32[i * LCD_WIDTH + j] = *(source_buffer + ((mainCamCorePtr->preview_width - j - 1)* mainCamCorePtr->preview_height + i) * 2) 
						+ (*(source_buffer + ((mainCamCorePtr->preview_width - j - 1)* mainCamCorePtr->preview_height + i ) * 2 + 1) << 8);	
				}
			}
		}
		GDI_UNLOCK;
		frame_data->pixtel_data = mainCamCorePtr->frame_buffer;
#else
		frame_data->pixtel_data = mainCamCorePtr->preview_layer_buffer;
#endif
		
		break;
	default:
		return VM_CAM_ERR_CAM_INTERNAL_ERROR;
	}
	gdi_layer_pop_and_restore_active();
	frame_data->col_pixel = mainCamCorePtr->preview_height;
	frame_data->row_pixel = mainCamCorePtr->preview_width;

	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_get_max_capture_size(VM_CAMERA_HANDLE handle, 
	vm_cam_size_t* size)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE

	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;
	
	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (size == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	size->width = CAM_CAPTURE_MAX_WIDTH;
	size->height = CAM_CAPTURE_MAX_HEIGHT;
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif	
}

VMINT vm_camera_set_capture_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t* size)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE

	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (size == NULL || size->width == 0 || size->height == 0 || 
		size->width > CAM_CAPTURE_MAX_WIDTH || size->height > CAM_CAPTURE_MAX_HEIGHT)
		return VM_CAM_ERR_BAD_PARAM;

	if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS)
		return VM_CAM_ERR_OPERATE_BAD_STATUS;

	mainCamCorePtr->capture_width = size->width;
	mainCamCorePtr->capture_height = size->height;
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

extern mmi_devconfig_system_config_struct sysconf;
VMINT vm_camera_capture(VM_CAMERA_HANDLE handle)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
  	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
  	{
		if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
			return VM_CAM_ERR_INVALID_CAM_HANDLE;

		if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle
			|| (mainCamCorePtr->pHandle != 0 
				&& vm_pmng_state(mainCamCorePtr->pHandle) != VM_PMNG_FOREGROUND))
			return VM_CAM_ERR_INVALID_CAM_HANDLE;

		if (mainCamCorePtr->cam_callback == NULL)
			return VM_CAM_ERR_NOT_REGISTER_NOTIFY;

		if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_STARTING_PREVIEW_STATUS 
			|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_STOPPING_PREVIEW_STATUS
			|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS)
			return VM_CAM_ERR_OPERATE_BAD_STATUS;

		if (mainCamCorePtr->user_notify_data.cam_status  == VM_CAM_READY_STATUS)
		{
			if (vm_graphic_get_current_layer_count() > 1)
			{
				vm_log_error("{CAM MODULE}VRE System don't support to preview in mulit GDI layer.");
				return VM_CAM_ERR_NOMEMORY;
			}
			
			if (!cam_create_preview_resource())
			{
				vm_log_error("{CAM MODULE}Failed to create preview resource.");
				return VM_CAM_ERR_NOMEMORY;
			}
			
			if (!cam_really_start_preview())
			{
				vm_log_error("{CAM MODULE}Failed to start to preview.");
				cam_free_preview_resource();
				return VM_CAM_ERR_NOMEMORY;
			}

			/* ��¼����Ԥ��ǰ����Ƭ�ֱ��� */
			mainCamCorePtr->before_capture_width = mainCamCorePtr->capture_width;
			mainCamCorePtr->before_capture_height = mainCamCorePtr->capture_height;
		}
		else
		{
			if (mainCamCorePtr->before_capture_width != mainCamCorePtr->capture_width
				|| mainCamCorePtr->before_capture_height != mainCamCorePtr->capture_height)
			{
				cam_really_stop_preview();

				/* ��¼����Ԥ��ǰ����Ƭ�ֱ��� */
				mainCamCorePtr->before_capture_width = mainCamCorePtr->capture_width;
				mainCamCorePtr->before_capture_height = mainCamCorePtr->capture_height;

				if (!cam_really_start_preview())
				{
					/* ����preview ʧ��. */
					cam_free_preview_resource();
					mainCamCorePtr->before_capature_repreview_success = FALSE;
				}
			}
		}

		mainCamCorePtr->user_notify_data.cam_status = VM_CAM_CAPTURING_STATUS;

		return VM_CAM_SUCCESS;
	}
	else
	{
		return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
	}
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_get_capture_data(VM_CAMERA_HANDLE handle, vm_cam_capture_data_t* capture_data)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE

	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	/* 
	 * ��֤ǰ̨��Ӧ�ó�����Ի��capture data�����ݣ�
	 * ���ұ�֤��������ͷ��Ӧ�ó�������ñ�
	 * ������Ӧ�ó�����ͬһ����
	 */
	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle
		|| (mainCamCorePtr->pHandle != 0 
			&& vm_pmng_state(mainCamCorePtr->pHandle) != VM_PMNG_FOREGROUND))
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (capture_data == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	if (mainCamCorePtr->capture_data == NULL)
		return VM_CAM_ERR_OPERATE_BAD_STATUS;
	
	capture_data->data = mainCamCorePtr->capture_data;
	capture_data->data_size = mainCamCorePtr->capture_data_size;
	strcpy(capture_data->mime_type, "JPEG");

	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_release_camera_instance(VM_CAMERA_HANDLE handle)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	
	if (mainCamCorePtr == NULL || handle != VM_CAMERA_MAIN_ID)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS)
		return VM_CAM_ERR_OPERATE_BAD_STATUS;

	vm_delete_timer((VMSHORT)mainCamCorePtr->timer_id);
	_vm_kernel_free(mainCamCorePtr);
	mainCamCorePtr = NULL;

       //UI_enable_alignment_timers();									// resume alignment timer
	TurnOffBacklight();
	mdi_audio_resume_background_play();								// resume background audio
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);				// re-enable keypad tone 
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

/**
 * �Ƿ��������ͷˢ��ģʽ.
 * 
 * @return 				�Ƿ��������ͷˢ��ģʽ.
 * @retval				TRUE ��������ͷˢ��ģʽ.
 * @retval				FALSE û�д�����ͷˢ��ģʽ.
 */
VMINT vm_is_open_camera_flush_screen_patten(void)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	if (mainCamCorePtr && (mainCamCorePtr->user_notify_data.cam_status 
		== VM_CAM_PREVIEW_STATUS || (mainCamCorePtr->user_notify_data.cam_status 
		== VM_CAM_CAPTURING_STATUS && mainCamCorePtr->preview_layer != GDI_LAYER_EMPTY_HANDLE 
		&& mainCamCorePtr->preview_layer_buffer != NULL))  )
		return TRUE;
	else
		return FALSE;
#else
	return FALSE;
#endif
}

/**
 * ������ͷģ����ˢ��.
 */
VMINT  vm_camera_patten_flush_screen_buffer(void)
{
#ifdef VRE_SUPPORT_CAMERA_FEATURE
	U8* mainBufferPtr = NULL;
	int bufferSize = (LCD_WIDTH * LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL)>>3;

	if (mainCamCorePtr && (mainCamCorePtr->user_notify_data.cam_status 
		== VM_CAM_PREVIEW_STATUS || (mainCamCorePtr->user_notify_data.cam_status 
		== VM_CAM_CAPTURING_STATUS && mainCamCorePtr->preview_layer != GDI_LAYER_EMPTY_HANDLE 
		&& mainCamCorePtr->preview_layer_buffer != NULL))  )
	{
		gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
		if (gdi_layer_get_buffer_ptr(&mainBufferPtr) == GDI_SUCCEED && mainCamCorePtr->osd_layer_buffer_2)
		{
			gdi_layer_push_and_set_active(mainCamCorePtr->osd_layer);
			gdi_layer_toggle_double();
			GDI_LOCK; {
				memcpy(mainCamCorePtr->osd_layer_buffer_2, mainBufferPtr, bufferSize);
			} GDI_UNLOCK;
			gdi_layer_toggle_double();
			gdi_layer_pop_and_restore_active();
		}
		gdi_layer_pop_and_restore_active();

		if (gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1) == GDI_SUCCEED)
			return 0;
		else
			return -1;
	}
	else
		return -1;
#else
	return -1;
#endif
}

/**
 * �õ�֧��camera sensor ��Ԥ���ߴ�.
 *
 * @param[out]			width �õ�camera sensor֧�ֵ�Ԥ�����.
 * @param[out]			height �õ�camera sensor֧�ֵ�Ԥ���߶�.
 */
void vm_camera_get_support_sensor_size(VMUINT* width, VMUINT* height)
{
	if (CAM_MOTION_SENSOR_DEFAULT_WIDTH > LCD_WIDTH 
		|| CAM_MOTION_SENSOR_DEFAULT_HEIGHT > LCD_HEIGHT)
	{
		*width = LCD_WIDTH;
		*height = LCD_HEIGHT;
	}
	else
	{
		*width = CAM_MOTION_SENSOR_DEFAULT_WIDTH;
		*height = CAM_MOTION_SENSOR_DEFAULT_HEIGHT;
	}
}

#endif



