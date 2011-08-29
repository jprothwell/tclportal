/*****************************************************************************
 * 本地视频播放接口文件
 * 根据常见平台特性最大支持格式如下支持视频格式如下:
 *   +-----------------------------------------------------------------------------------------------------+
 *   |					   	| MT6225				|	MT6226,MT6228,MT6238		|	MT6235
 *   +-----------------------------------------------------------------------------------------------------+
 *   | 文件格式      		| AVI				|	3GP,MP4						|	3GP,MP4/AVI
 *   +-----------------------------------------------------------------------------------------------------+
 *   | 视频编码格式        |Motion JPEG			|	MP4,3GP 						|	MP4,3GP/AVI 	
 *   +-----------------------------------------------------------------------------------------------------+
 *   | 音频编码格式        |PCM				|	AMR,AAC						|	AMR,AAC
 *   +-----------------------------------------------------------------------------------------------------+
 *
 *	规则描述：
 *	1.  播放接口目前最多支持两层，使用前需创建层资源，并作为参数传入，
 *    建议第一次创建的层作为播放层，第二次创建的层作为工具层，并保持这样的顺序进行画面的flush操作。
 *	一旦应用被切到后台，请及时停止视频播放和释放层资源，
 *	并记录当前播放时间用于切到前台时恢复；如果应用不这么做，
 *	系统将强制关闭视频并释放资源而不记录任何信息。
 *	
 *	2. 视频优于音频原则：有音频在播放，打开视频时将关闭音频(bitsteam audio除外,bitsteam audio占用时，打开视频将返回错误)。
 *	3. 有视频打开/播放，再次打开/播放视频将返回错误。
 *
 *
 ****************************************************************************/
#ifndef _VM_VIDEO_H
#define _VM_VIDEO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmmm.h"




/**
 *	返回成功。
 */
#define VM_VIDEO_SUCCESS    (0)
/**
 *	返回失败。
 */
#define VM_VIDEO_FAILED    (-1)


/**
 *	数据不足
 */
#define VM_VIDEO_PROGRESSIVE_FILE_NOT_ENOUGH   	-101




/**
 *	文件打开失败。
 */
#define VM_VIDEO_ERR_OPEN_FILE_FAILED           		-103

/**
 *	文件太大。
 */
#define VM_VIDEO_ERR_FILE_TOO_LARGE             		-104

/**
 *	抓取快照失败。
 */
#define VM_VIDEO_ERR_SNAPSHOT_FAILED            		-105

/**
 *	播放失败。
 */
#define VM_VIDEO_ERR_PLAY_FAILED                		-106



/**
 *	磁盘已满，抓图失败。
 */
#define VM_VIDEO_ERR_SNAPSHOT_DISK_FULL         	-107

/**
 *	写保护，抓图失败。
 */
#define VM_VIDEO_ERR_SNAPSHOT_WRITE_PROTECTION  -108

/**
 *	分辨率不对。
 */
#define VM_VIDEO_ERR_INVALID_RESOULTION         	-109   

/**
 *	格式不支持。
 */
#define VM_VIDEO_ERR_UNSUPPORTED_FORMAT         	-110

/**
 *	内存不足。
 */
#define VM_VIDEO_ERR_MEMORY_INSUFFICIENT        	-111

/**
 *	没有版权。
 */
#define VM_VIDEO_ERR_DRM_PROHIBITED             		-112     

/**
 *	版权正被使用。
 */
#define VM_VIDEO_ERR_DRM_DURATION_USED          	-113

/**
 *	帧率太高。
 */
#define VM_VIDEO_ERR_FRAMERATE_TOO_HIGH         	-114



/**
 *	亮度比 N4 暗一级 。
 */
#define VM_VIDEO_BRIGHTNESS_N5              0	
/**
 *	亮度比 N3 暗一级 。
 */
#define VM_VIDEO_BRIGHTNESS_N4              1    
/**
 *	亮度比 N2 暗一级 。
 */
#define VM_VIDEO_BRIGHTNESS_N3              2	
/**
 *	亮度比 N1 暗一级 。
 */
#define VM_VIDEO_BRIGHTNESS_N2              3	
/**
 *	亮度比 默认亮度 暗一级。
 */
#define VM_VIDEO_BRIGHTNESS_N1              4		
/**
 *	默认亮度。
 */
#define VM_VIDEO_BRIGHTNESS_0                5  
/**
 *	亮度比 默认亮度亮一级。
 */
#define VM_VIDEO_BRIGHTNESS_P1              6	
/**
 *	亮度比 P1 亮一级。
 */
#define VM_VIDEO_BRIGHTNESS_P2              7	
/**
 *	亮度比 P2 亮一级。
 */
#define VM_VIDEO_BRIGHTNESS_P3              8	
/**
 *	亮度比 P3 亮一级。
 */
#define VM_VIDEO_BRIGHTNESS_P4              9	
/**
 *	亮度比 P4 亮一级。
 */
#define VM_VIDEO_BRIGHTNESS_P5              10	


/**
 *	对比度比N4低一级。
 */
#define VM_VIDEO_CONTRAST_N5                0	
/**
 *	对比度比N3低一级。
 */
#define VM_VIDEO_CONTRAST_N4                1	
/**
 *	对比度比N2低一级。
 */
#define VM_VIDEO_CONTRAST_N3                2	
/**
 *	对比度比N1低一级。
 */
#define VM_VIDEO_CONTRAST_N2                3	
/**
 *	对比度比默认低一级。
 */
#define VM_VIDEO_CONTRAST_N1                4	
/**
 *	默认对比度。
 */
#define VM_VIDEO_CONTRAST_0                 5	
/**
 *	对比度比默认高一级。
 */
#define VM_VIDEO_CONTRAST_P1                6	
/**
 *	对比度比P1高一级。
 */
#define VM_VIDEO_CONTRAST_P2                7	
/**
 *	对比度比P2高一级。
 */
#define VM_VIDEO_CONTRAST_P3                8	
/**
 *	对比度比P3高一级。
 */
#define VM_VIDEO_CONTRAST_P4                9	
/**
 *	对比度比P4高一级。
 */
#define VM_VIDEO_CONTRAST_P5                10	


/**
 *	旋转0度 。
 */
#define VM_VIDEO_LCD_ROTATE_0            0
/**
 *	旋转90度 。
 */
#define VM_VIDEO_LCD_ROTATE_90           1
/**
 *	旋转180度 。
 */
#define VM_VIDEO_LCD_ROTATE_180          2
/**
 *	旋转270度 。
 */
#define VM_VIDEO_LCD_ROTATE_270          3

/**
 *	视频音/视轨迹定义。
 */
typedef enum
{
    VM_VIDEO_TRACK_NONE,   
    VM_VIDEO_TRACK_AV,     /* 视频文件含视频和音频轨迹 */
    VM_VIDEO_TRACK_A_ONLY, /* 视频文件只含音频轨迹  */
    VM_VIDEO_TRACK_V_ONLY /* 视频文件只含视频轨迹 */
} vm_video_track_enum;


/**
 *	视频描述信息buffer 长度定义，UCS2计算，最长80个字符。
 */
#define VM_VIDEO_MAX_CONTENT_INFO_LEN   80


/**
 *	视频信息结构。
 */
typedef struct
{
    VMUINT16 width;                      /* 视频宽度  */
    VMUINT16 height;                     /* 视频高度  */
    VMUINT32 total_frame_count;          /* 视频的总帧数  */
    VMUINT64 total_time_duration;        /* 总播放时间  */
    vm_video_track_enum track;     
    VMINT handle;              /* 视频文件句柄 */
    VMINT is_seekable;           /* 是否可定位 */
    VMUINT8 aud_channel_no;              /* 音频通道数  */
    VMUINT16 aud_sample_rate;            /* 音频采样率  */

    VMINT is_drm_streaming;      /* 是否 数字版权保护文件  */
    VMUINT drm_handle;                 /* 数字版权保护文件句柄 */

    VMWCHAR title_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];       /* 标题信息  */
    VMWCHAR artist_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];      /* 艺术家信息  */
    VMWCHAR album_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];       /* 专辑 信息  */
    VMWCHAR author_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];      /* 作者信息  */
    VMWCHAR copyright_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];   /* 版权信息  */
    VMWCHAR date_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];        /* 日期  */
} vm_video_info_struct;





 /**
 *	使用函数vm_video_open_file打开视频文件时	。
 *	当有错误或正常返回时将调用这个类型的函数。
 *	@param ret			返回结果: >=0表示成功，<0 失败。
 *    @param video_info			视频文件的信息，成功打开时将填充这个结构体。
 *	@return 			
 */
typedef void (*vm_video_open_result_callback)(VMINT ret, vm_video_info_struct *video_info);


  /**
 *	使用函数vm_video_play打开视频文件。
 *	当有错误或正常播放完成时将调用这个类型的函数。
 *	@param ret			返回结果: >=0表示成功，<0 失败。
 *	@return 			
 */
typedef void (*vm_video_finish_callback) (VMINT ret);



 /**
 *	打开视频文件	
 *	@param filename			完整路径及文件名。
 *    @param open_result_callback	回调函数。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 打开文件成功。
 *  		VM_VIDEO_ERR_DRM_PROHIBITED : 不能打开视频文件因drm被禁止。
 *  		VM_VIDEO_ERR_MEMORY_INSUFFICIENT : 不能打开视频因内存不足。
 *  		VM_VIDEO_ERR_FILE_TOO_LARGE : 不能打开视频因文件太大。
 *  		VM_VIDEO_ERR_FRAMERATE_TOO_HIGH : 不能打开视频因帧率太高。
 *		VM_VIDEO_ERR_INVALID_RESOULTION: 不能打开视频因分辨率不对。 
 *  		VM_VIDEO_ERR_OPEN_FILE_FAILED : 其它原因不能打开视频。
 */
 VMINT vm_video_open_file(
                    const VMWSTR filename,
                    vm_video_open_result_callback open_result_callback);


 /**
 *	关闭视频文件。	
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 关闭文件成功。
 *  		VM_VIDEO_FAILED : 关闭文件失败。
 */
 VMINT vm_video_close_file(void);


 /**
 *	使用指定缓存数据打开视频。
 *    @param buffer	视频缓存数据指针。
 *    @param buffer_len	缓存长度。
 *    @param info		得到的视频信息结构。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 打开成功。
 *  		VM_VIDEO_ERR_MEMORY_INSUFFICIENT : 没有足够内存打开失败。
 *  		VM_VIDEO_ERR_FRAMERATE_TOO_HIGH : 帧率太高打开失败。
 *  		VM_VIDEO_ERR_OPEN_FILE_FAILED : 打开失败。
 */
  VMINT vm_video_open_buffer(
                    const VMUSTR buffer,
                    const VMUINT buffer_len,
                    vm_video_info_struct *info);
 
                    
 /**
 *	关闭视频缓存数据，与vm_video_open_buffer成对使用。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 关闭文件成功。
 *  		VM_VIDEO_FAILED : 关闭文件失败。
 */
 VMINT vm_video_close_buffer(void);


 /**
 *	播放视频（根据平台特性支持3gp/mp4），播放前需进行过seek操作。
 *    播放接口需要知道层的叠放顺序，因此请保证使用前已进行过vm_graphic_flush_layer操作，否则可能花屏。
 *    @param player_layer_handle		播放层的句柄（建议使用第一次创建层时返回的句柄）。
 *   @param base_layer_handle		工具层的句柄（建议使用第二次创建层时返回的句柄）。
 *    @param repeat_count			重复播放次数，0表示重复播放。
 *    @param is_play_audio			是否播放音频（TRUE/FALSE ）。
 *    @param audio_path			音频播放路径（使用vmmm.h中定义，如VM_DEVICE_SPEAKER2）。
 *    @param play_finish_callback		回调函数。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 开始播放成功。
 *  		VM_VIDEO_ERR_DRM_PROHIBITED :因数字版权不能打开视频文件。
 *  		VM_VIDEO_PROGRESSIVE_FILE_NOT_ENOUGH : 数据不足以用来播放。
 *  		VM_VIDEO_ERR_PLAY_FAILED : 播放失败。
 */
 VMINT vm_video_play(
                    VMUINT player_layer_handle,
                    VMUINT base_layer_handle,
                    VMUINT16 repeat_count, 
                    VMINT is_play_audio,
                    VMINT audio_path, 
                    vm_video_finish_callback play_finish_callback);


/**
 *	 停止播放。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 停止成功。
 *			VM_VIDEO_FAILED : 停止失败。
 */
 VMINT vm_video_stop(void);


 /**
 *	暂停播放。
 *	@return
 *  		VM_VIDEO_SUCCESS : 成功。
 *			VM_VIDEO_FAILED : 	失败。
 */
VMINT vm_video_pause(void);


 /**
 *	  继续播放
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 成功。
 *			VM_VIDEO_FAILED : 	失败。
 */
VMINT vm_video_resume(void);


 /**
 *	定位视频到指定时间点那一帧（需刷新界面才能显示）。
 *    @param time		时间 （毫秒）。
 *    @param player_layer_handle		播放层句柄。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
 VMINT vm_video_seek_and_getframe(VMUINT64 time, VMUINT player_layer_handle);


 /**
 *	抓图保存为指定的文件，文件格式JPEG(只在硬件解码的机器中有效，软解码将返回VM_VIDEO_ERR_SNAPSHOT_FAILED)。
 *    @param player_layer_handle		播放层句柄。
 *    @param file_name			保存的文件名(UCS2)。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 抓图成功。
 *  		VM_VIDEO_ERR_SNAPSHOT_DISK_FULL : 磁盘已满，抓图失败。
 *  		VM_VIDEO_ERR_SNAPSHOT_WRITE_PROTECTION : 写保护，抓图失败。
 * 		VM_VIDEO_ERR_SNAPSHOT_FAILED : 抓图失败。
 */
 VMINT vm_video_snapshot(VMUINT player_layer_handle, VMWSTR file_name);



 /**
 *	设置亮度，关闭后不保存，只能在打开状态下设置，播放过程中设置值只在下次播放时有效，
 *	只在硬件解码的机器中有效，软解码将返回VM_VIDEO_FAILED 。
 *    @param brightness			亮度值（如:VM_VIDEO_BRIGHTNESS_0 ）。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
 VMINT vm_video_set_brightness(VMUINT16 brightness);


 /**
 *	 设置对比度，关闭后不保存，只能在打开状态下设置，播放过程中设置值只在下次播放时有效，
 *	只在硬件解码的机器中有效，软解码将返回VM_VIDEO_FAILED 。
 *    @param contrast			对比度值(如:VM_VIDEO_CONTRAST_0)。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
 VMINT vm_video_set_contrast(VMUINT16 contrast);



 /**
 *	 得到目前的播放时间。
 *    @param cur_play_time			需获取的播放时间变量指针。 
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
 VMINT vm_video_get_cur_play_time(VMUINT64 *cur_play_time); 


 /**
 *	根据URL 来打开流媒体视频(将把调用的VREAPP 切到后台，新开SCREEN 调用MTK 的视频播放器)。
 *    @param url			要打开的视频URL。
 *
 *	@return
 *		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
VMINT vm_video_play_stream_from_rtsp_link(VMWSTR url);
	
/**
 *	打开sdp 格式的流媒体视频文件(将把调用的VREAPP 切到后台，新开SCREEN 调用MTK 的视频播放器)。
 *    @param filename		打开sdp 格式的文件。
 *	@param is_short		是否为8.3 格式的短文件名。TURE为是，FALSE为否。	
 *
 *	@return
 *		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
VMINT vm_video_play_stream_from_sdp_file(VMWSTR filename, VMUCHAR is_short);

#ifdef __cplusplus
}
#endif

#endif
