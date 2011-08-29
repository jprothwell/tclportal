#ifdef __VRE__

#include <stdlib.h>
#include <string.h> 

#include "MMI_include.h"
#include "gdi_datatype.h"
#include "mdi_datatype.h"
#if !defined(__VRE_RB_08A__) || !defined(__VRE_RB_08B__)
#include "mdi_bitstream.h"
#endif
#include "mdi_audio.h"

#include "vmopt.h"
#include "vmsys.h"
#include "vmmod.h"
#include "vmlog.h"
#include "vmmacrostub.h"

extern VMINT vre_running;
/*************************************************************************************/
/*						BitStream “Ù∆µ≤ø∑÷										*/
/**************************************************************************************/

vm_bitstream_audio_result_callback sal_bitstream_cb = NULL;

VMINT vm_get_audio_bitstream_feature(void)
{
	if (sysconf.multimedia.audio_bitstring_support == MMI_TRUE)
		return TRUE;
	else 
		return FALSE;
/*#if defined(__BITSTREAM_API_SUPPORT__)
	return TRUE;
#else
	return FALSE;
#endif*/
}

void vm_sal_bitstream_audio_callback(VMINT handle, VMINT result) 
{
      	if (vre_running == FALSE)return;
	if (vm_get_audio_bitstream_feature())
	{
		vm_log_debug("entry vm_sal_bitstream_audio_callback, and handle = %d, result = %d", handle, result);
		if (sal_bitstream_cb != NULL)
		{
			sal_bitstream_cb(handle, result);
		}
	}
}

VMINT vm_sal_bitstream_audio_open(
	VMINT* handle,
	vm_bitstream_audio_cfg_struct *audio_type,
	vm_bitstream_audio_result_callback callback)
{
	VMINT result = VM_BITSTREAM_FAILED;
	if (vm_get_audio_bitstream_feature())
	{
		 sal_bitstream_cb = callback;
		 vm_log_debug("sal_bitstream_cb = %d", sal_bitstream_cb);
		 result = stub_bitstream_audio_open(handle, audio_type, vm_sal_bitstream_audio_callback);
	}
	return result;
}


VMINT vm_sal_bitstream_audio_close(VMINT handle)
{
	VMINT result = VM_BITSTREAM_FAILED;
	if (vm_get_audio_bitstream_feature())
	{
		result = stub_bitstream_audio_close(handle);
		if (result == VM_BITSTREAM_SUCCEED)
			sal_bitstream_cb = NULL;
	}
	return result;
}

VMINT vm_sal_bitstream_audio_get_buffer_status(
	VMINT handle, 
	vm_bitstream_audio_buffer_status *status)	
{
	VMINT result = VM_BITSTREAM_FAILED;
	if (vm_get_audio_bitstream_feature())
	{
		//result =  stub_bitstream_audio_get_buffer_status(handle, (mdi_bitstream_audio_buffer_status*)status);
		result =  stub_bitstream_audio_get_buffer_status(handle, status);
	}
	return result;
}

VMINT vm_sal_bitstream_audio_put_data(
	VMINT 		handle,
	VMUINT8*	buffer,
	VMUINT 		buffer_size,
	VMUINT* 	written)
{
	VMINT result = VM_BITSTREAM_FAILED;
	if (vm_get_audio_bitstream_feature())
	{
		result =  stub_bitstream_audio_put_data(handle, buffer, buffer_size, written);
	}
	return result;
}

VMINT vm_sal_bitstream_audio_put_frame(
	VMINT 		handle,
	VMUINT8*	buffer,
	VMUINT		buffer_size,
	VMUINT 		timestamp)
{
	VMINT result = VM_BITSTREAM_FAILED;
	if (vm_get_audio_bitstream_feature())
	{
		result =  stub_bitstream_audio_put_frame(handle, buffer, buffer_size, timestamp);
	}
	return result;
}

VMINT vm_sal_bitstream_audio_start(
	VMINT 	handle,
	vm_bitstream_audio_start_param  *para)
{
	VMINT result = VM_BITSTREAM_FAILED;
	if (vm_get_audio_bitstream_feature())
	{
		//result =  stub_bitstream_audio_start(handle, (mdi_bitstream_audio_start_param*)para);
		result =  stub_bitstream_audio_start(handle, para);
	}
	return result;
}

VMINT vm_sal_bitstream_audio_stop(VMINT handle)
{
	VMINT result = VM_BITSTREAM_FAILED;
	if (vm_get_audio_bitstream_feature())
	{
		result =  stub_bitstream_audio_stop(handle);
	}
	return result;
}

VMINT vm_sal_bitstream_audio_get_play_time(
	VMINT handle,
	VMUINT* current_time)
{
	VMINT result = VM_BITSTREAM_FAILED;
	if (vm_get_audio_bitstream_feature())
	{
		result =  stub_bitstream_audio_get_play_time(handle, current_time);
	}
	return result;
}


#endif /* __VRE__ */
