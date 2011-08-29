#ifdef __VRE__

#include "mmi_include.h"
#include "Fat_fs.h"
#include "SettingDefs.h"
#include "CommonScreens.h"
#include "lcd_sw_rnd.h"
#include "lcd_if.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "kal_release.h"
#if (!defined(__VRE_RB_08A__))
#include "SettingProfileEnum.h"
#endif
#include "gpioInc.h"
#include "EngineerModeResDef.h"
#if (!defined(__VRE_RB_08A__)&&!defined(__VRE_RB_08B__))
#include "EngineerModeAppResDef.h"
#include "EngineerModeMotion.h"
#endif
#include "mdi_motion.h"
#include "math.h"

#include "mdi_motion.h"
#include "vmopt.h"
#include "vmextsensor.h"

#include "vmlog.h"
#include "vm_freescale_MMA7455L.h"


#ifdef __MMI_MOTION_APP__
static VMINT start_ext_sensor(void);
static VMINT stop_ext_sensor(void);
static VMINT set_numeric_option_ext_sensor(const VMSTR control_name, 
	VMINT opt_value);

static g_sensor_data_t gData = {0, 0, 0};
static mdi_handle g_s_handle = -1;
static VMINT freeScaleHandle = 0;
static VM_MOTION_SENSITIVE_ENUM motion_sensitive = MOTION_SENSITIVE_HIGH;
#endif


VMINT vm_reg_all_ext_sensors(void)
{
#ifdef __MMI_MOTION_APP__
	vm_core_scb_t scb = 
		{
			USE_SENSOR_NAME, start_ext_sensor, stop_ext_sensor, 
			set_numeric_option_ext_sensor, NULL
		};
	
	if (vm_register_ext_sensor(&freeScaleHandle, &scb) 
		!= VM_EXT_SENSOR_SUCCESS)
	{
		vm_log_error("Failed to reg \"%s\" sensor.", USE_SENSOR_NAME);
		return -1;
	}

	g_s_handle = -1;
	motion_sensitive = MOTION_SENSITIVE_HIGH;
#endif

	return 0;
}

#ifdef __MMI_MOTION_APP__
#define MTK_ONE_G_VALUE			(1000)
  #if (defined(__VRE_RB_08A__))
void vm_motion_tilt_detail_callback(S32 x, S32 y, S32 z)
{
	gData.x = -((x * ONE_G_VALUE)  / MTK_ONE_G_VALUE);
	gData.y = ((y * ONE_G_VALUE)  / MTK_ONE_G_VALUE);
	gData.z = -((z * ONE_G_VALUE)  / MTK_ONE_G_VALUE);

	vm_notify_data_by_ext_sensor(freeScaleHandle, 
		&gData, sizeof(g_sensor_data_t));
}
  #else
void vm_motion_tilt_detail_callback(mdi_motion_angle_enum direct, mdi_motion_action_enum action, 
	mdi_motion_tilt_detail_struct *detail, void *user_data)
{
	gData.x = -((detail->acc_x * ONE_G_VALUE)  / MTK_ONE_G_VALUE);
	gData.y = ((detail->acc_y * ONE_G_VALUE)  / MTK_ONE_G_VALUE);
	gData.z = -((detail->acc_z * ONE_G_VALUE)  / MTK_ONE_G_VALUE);

	vm_notify_data_by_ext_sensor(freeScaleHandle, 
		&gData, sizeof(g_sensor_data_t));
}
  #endif

                                                                              
static VMINT start_ext_sensor(void)
{
	VMINT mtk_gsensor_sensitive = MDI_MOTION_SENSITIVE_HIGH;

	switch (motion_sensitive)
	{
	case MOTION_SENSITIVE_LOW:
		mtk_gsensor_sensitive = MDI_MOTION_SENSITIVE_LOW;
		break;
	case MOTION_SENSITIVE_NORMAL:
		mtk_gsensor_sensitive = MDI_MOTION_SENSITIVE_NORMAL;
		break;
	default:
		mtk_gsensor_sensitive = MDI_MOTION_SENSITIVE_HIGH;
		break;
	}

	if (g_s_handle < 0)
	{
#if (defined(__VRE_RB_08A__))
		if ((g_s_handle = mdi_motion_start_listen_tile((mdi_motion_sensitive_enum)mtk_gsensor_sensitive, 
			100, 200, vm_motion_tilt_detail_callback)) >= 0)		
#else
		if ((g_s_handle = mdi_motion_start_listen_tilt((mdi_motion_sensitive_enum)mtk_gsensor_sensitive, 
			MDI_MOTION_TILT_EVENT_ALL, vm_motion_tilt_detail_callback, NULL)) >= 0)
#endif
		{
			return 0;
		}
	}
	return -1;
}

static VMINT stop_ext_sensor(void)
{
	if (g_s_handle >= 0)
	{
#if (defined(__VRE_RB_08A__))
		mdi_motion_stop_listen();
#else
		mdi_motion_stop_listen_tilt(g_s_handle);
#endif
		g_s_handle = -1;

		return 0;
	}

	return -1;
}

static VMINT set_numeric_option_ext_sensor(const VMSTR control_name, 
	VMINT opt_value)
{
	if (control_name == NULL || strlen(control_name) == 0 
		|| strcmp(control_name, MOTION_SENSITIVE) != 0 
		||  opt_value < MOTION_SENSITIVE_LOW 
		|| opt_value > MOTION_SENSITIVE_HIGH)
	{
		return -1;
	}
	
	motion_sensitive = opt_value;
	return 0;
}
#endif
#endif
