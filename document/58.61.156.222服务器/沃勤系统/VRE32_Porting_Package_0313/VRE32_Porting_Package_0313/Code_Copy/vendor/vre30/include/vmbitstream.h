#ifndef _VM_BITSTREAM_H
#define _VM_BITSTREAM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmmm.h"

/**
 * BitStream 操作成功。
 */
#define VM_BITSTREAM_SUCCEED                   			(0)

/**
 * BitStream 操作失败。
 */
#define VM_BITSTREAM_FAILED                   				(-1)


/**
* 缓冲区已满
*/
#define VM_BITSTREAM_BUFFER_OVERFLOW         1  		
/**
* 缓冲区已空
*/
#define VM_BITSTREAM_BUFFER_UNDERFLOW         2 		
/**
* 微控制器太忙无法解视频
*/
#define VM_BITSTREAM_RECOVER                   	3		
/**
* 分辨率不对
*/
#define VM_BITSTREAM_ERR_INVALID_RESOULTION  -2  		
/**
* 不正确的比特流
*/
#define VM_BITSTREAM_ERR_INVALID_BITSTREAM     	-3	
/**
* 内存不足
*/
#define VM_BITSTREAM_ERR_MEMORY_INSUFFICIENT   	-4	


/**
 *	bitstream 编码类型
 */
typedef enum
{
    VM_BITSTREAM_CODEC_TYPE_NONE,  
    VM_BITSTREAM_CODEC_TYPE_SILENT, 
    VM_BITSTREAM_CODEC_TYPE_AMR,   
    VM_BITSTREAM_CODEC_TYPE_AMRWB, 
    VM_BITSTREAM_CODEC_TYPE_AAC,   
    VM_BITSTREAM_CODEC_TYPE_DAF,   
    VM_BITSTREAM_CODEC_TYPE_MP4A,  
    VM_BITSTREAM_CODEC_TYPE_MP4AG,
    VM_BITSTREAM_CODEC_TYPE_H264
} vm_bitstream_codec_type_enum;


/**
 *	H.264配置参数
 */
typedef struct
{
    VMUINT  timescale;	               			/*视频帧时间戳缩放的因数*/
    VMINT is_ps_oob;                 			/*	
    										参数集FALSE (in-band) 或TRUE (out-of-band)
		                                        			如果 is_ps_oob == TRUE 下面参数需要配置
		                                        			packetization_mode,
		                                        			profile_idc,
		                                        			level_idc,
		                                        			p_AVC_config_record
		                                        		*/
    VMUINT8   packetization_mode;	      /*  
    										H.264 打包方式, 如果这个参数不存在默认为0
                                        					0: 单个NAL方式.
                                        					1: 非交叉方式.
                                        					2: 交叉方式. 
                                        				*/
    VMUINT8   profile_idc;               		/* 编码模式*/
    VMUINT8   level_idc;                 		/*  编码等级  */
    VMUSTR  p_AVC_config_record;       /*指向AVC配置记录的指针*/
    VMUINT  AVC_config_record_size;    /*AVC配置记录的尺寸*/
    vm_bitstream_codec_type_enum audio_type;   /*bitstream 声音编码类型，目前只支持AMR*/
    VMUINT sampling_rate;                          /*音频采样率*/
    
} vm_bitstream_video_h264_cfg;

/* Video buffer status query struct */
typedef struct
{
    VMUINT buffer_duration;            /*当前缓存中有尚未播放的毫秒数 */
    VMUINT percentage_used;            /*缓存使用的百分比*/
    VMUINT free_space;                 /*缓存中未使用的字节数*/
    VMUINT current_frame_count;        /*当前缓存中有尚未播放的帧数*/
    VMUINT required_frame_count;       /*开始播放视频所需的帧数的最小值   */ 
} vm_bitstream_video_buffer_status;


typedef struct
{
    VMUINT ms_start_time;                /*开始播放的时间戳*/
    VMUINT h_layer;                 		/*播放视频的层句柄，目前VRE只支持2层，建议使用第一次创建层返回的值*/
    VMUINT base_layer;                 	/*工具层句柄,目前VRE只支持2层，建议使用第二次创建层返回的值*/
    VMUINT16 rotate;                         /*显示屏的旋转角度*/
} vm_bitstream_video_start_param;


/**
 * 调用vm_bitstream_video_open_handle函数的回调函数定义
 *
 * @param handle			打开的bitstream 句柄。
 * @param result			返回结果
 * 		VM_BITSTREAM_BUFFER_OVERFLOW           		缓冲区已满
 * 		VM_BITSTREAM_BUFFER_UNDERFLOW          		缓冲区已空
 *		VM_BITSTREAM_RECOVER                   			微控制器太忙无法解视频
 *		VM_BITSTREAM_FAILED                			错误
 *		VM_BITSTREAM_ERR_INVALID_RESOULTION    		分辨率不对
 *		VM_BITSTREAM_ERR_INVALID_BITSTREAM     		不正确的比特流
 *		VM_BITSTREAM_ERR_MEMORY_INSUFFICIENT   		内存不足
 *
 * @return	
 */
typedef void (*vm_bitstream_video_result_callback)(VMINT handle, VMINT result);


/**
 *	音频配置结构体
 */
typedef struct
{ 
    vm_bitstream_codec_type_enum vm_codec_type;                                 
} vm_bitstream_audio_cfg_struct;

/**
 *	音频缓冲结构体
 */
typedef struct
{
    VMUINT total_buf_size; 		/* 音频缓冲区大小 (ring buffer)*/
    VMUINT free_buf_size;  	/* 当前音频空闲缓冲大小 */
} vm_bitstream_audio_buffer_status;

typedef struct
{	
    VMUINT 	start_time; 			/* 设置起始时间 */
    VMUINT8 	volume;      			/* 设置音量 */
    VMUINT8 	audio_path;  		/* 设置声音播放路径 */
} vm_bitstream_audio_start_param;

/**
 * 调用vm_bitstream_audio_open_handle函数的回调函数定义
 *
 * @param handle			打开的bitstream 句柄。
 * @param result			返回结果
 *
 * @return	返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
typedef void (*vm_bitstream_audio_result_callback)(VMINT handle, VMINT result);


/* ======================== BitStream Audio ============================= */

/**
 * BitStream Audio 操作为独占资源，如同一APP 中要打开第二个BitStream Audio 将返回失败。
 * 
 * 与其它占用音频资源的功能关系：
 * 视频功能使用时将不能使用本功能。
 * 录音功能使用时，本功能 将停止录音，抢占音频资源。
 * midi 功能 在使用时，本功能将停止midi，抢占音频资源。
 * audio 功能在使用时，本功能将停止audio，抢占音频资源。
 * 
 * 多实例情况下：
 * 如所在APP 被切换到后台或者有外部事件打断时 将发送被切换到后台的CallBack 
 * 消息后被VRE 系统强制中止。在切回前台时将发送CallBack 消息(带有强制中止时
 * 的中止时间)，如何恢复将由APP 决定。
 *
 * 后台时：
 * 本功能将不能使用。
 */

/**
 * 以bitstream 方式打开音频资源。
 *
 * @param handle			打开的bitstream 句柄。
 * @param audio_type		音频资源的类型(可用音乐格式为AMR、AAC、MP3，共三种)。
 * @param result_callback	音频回调函数。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_bitstream_audio_open(
	VMINT* handle,
	vm_bitstream_audio_cfg_struct *audio_type,
	vm_bitstream_audio_result_callback callback);

/**
 * 关闭以bitstream 方式打开的音频文件。
 *
 * @param handle			由vm_bitstream_audio_open 打开的bitstream 句柄。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_bitstream_audio_close(VMINT handle);

/**
 * 根据bitstream 句柄获取音频缓冲结构体。
 *
 * @param handle			打开的bitstream 句柄。
 * @param status			得到的音频缓冲结构体。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_bitstream_audio_get_buffer_status(
	VMINT handle, 
	vm_bitstream_audio_buffer_status *status);

/**
 * 将指定大小的音频数据写入音频缓冲区内，并通过参数used_size 验证真实写入数据大小。
 *
 * @param handle			打开的bitstream 句柄。
 * @param buffer			待写入音频缓冲区的内存地址指针。
 * @param buffer_size		要写入的缓冲的字节数。
 * @param used_size		实际写入缓冲的字节数。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_bitstream_audio_put_data(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT 	buffer_size,
	VMUINT 	*written);

/**
 * 将指定时间的音频数据写入音频缓冲区内，如果数据大小超过缓冲区将导致失败。
 *
 * @param handle			打开的bitstream 句柄。
 * @param buffer			待写入音频缓冲区的数据指针。
 * @param buffer_size		要写入的缓冲的大小。
 * @param used_size		要写入缓冲的音频时间(单位：毫秒)。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
 VMINT vm_bitstream_audio_put_frame(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT	buffer_size,
	VMUINT 	timestamp);

/**
 * 开始播放BitStream Audio 音频。
 *
 * @param handle			要播放的bitstream 句柄。
 * @param para			播放音频时参数结构体。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_bitstream_audio_start(
	VMINT handle,
	vm_bitstream_audio_start_param *para);

/**
 * 停止播放BitStream Audio 音频。
 *
 * @param handle			要停止播放的bitstream 句柄。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_bitstream_audio_stop(VMINT handle);

/**
 * 获取当前播放时间。
 *
 * @param handle			要获取播放时间的bitstream 句柄。
 * @param current_time		获得的当前播放时间(单位：毫秒)
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_bitstream_audio_get_play_time(
	VMINT handle,
	VMUINT* current_time);


/**
 * BitStream H.264 video 操作为独占资源，一旦打开BitStream video，除非被关闭，否则不允许再次打开 。
 * 
 * Bitstream video接口只能播放视频，无法使用这部分接口播放音频，如需播放音频，
 * 可结合Bitstream audio接口一起使用
 * 
 * 与音频资源的功能关系：
 * 有midi,mp3等音频资源打开时，打开BitStream video，将关闭音频资源(录音除外)
 * 
 *
 * 多实例情况下：
 * 同时只允许一个实例打开BitStream video ，第二个实例调用打开接口会返回错误。
 *
 * 切到后台时：
 * 请应用停止播放，释放相关资源，并记录当前状态用于切到前台时恢复，恢复时需重新申请资源；
 * 如果切到后台不停止和释放资源，系统将强制关闭和释放资源但不记录状态信息。
 */


 /**
 * 打开bitstream视频。
 *
 * @param handle			打开的bitstream 句柄变量指针。
 * @param cfg				h264配置结构信息。
 * @param callback		回调函数。								
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
VMINT vm_bitstream_video_open(
        VMINT* handle,
        vm_bitstream_video_h264_cfg* cfg,
        vm_bitstream_video_result_callback callback);


 /**
 * 关闭bitstream视频。
 *
 * @param handle			需关闭的bitstream 句柄。							
 * @return						返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
VMINT vm_bitstream_video_close(VMINT handle);    


/**
 * 得到缓冲区状态。
 * @param handle			打开的bitstream 句柄。		
 * @param status			填充缓存区信息的结构体变量指针。
 * @return						返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
VMINT vm_bitstream_video_get_buffer_status(VMINT handle, vm_bitstream_video_buffer_status* status);


 /**
 * 填充缓冲区。
 * @param handle				打开的bitstream 句柄。		
 * @param  buffer				填充的数据源缓冲指针。		
 * @param buffer_size		数据源缓冲大小。
 * @param timestamp			时间戳位置。
 * @return							返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
VMINT vm_bitstream_video_put_frame(VMINT handle, VMUSTR buffer, VMUINT buffer_size, VMUINT timestamp);


/**
 * 开始播放bitsteam视频。
 * @param handle			打开的bitstream 句柄。		
 * @param  para			播放的参数结构体变量指针，因接口需要知道层的叠放顺序，
 *						因此请保证使用前已进行过vm_graphic_flush_layer操作，否则可能花屏。		
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
VMINT vm_bitstream_video_start(VMINT handle, vm_bitstream_video_start_param* para);



/**
 * 停止播放bitsteam视频,不能再次播放，需要关闭，再重新打开。
 * @param handle			打开的bitstream 句柄。				
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
VMINT vm_bitstream_video_stop(VMINT handle);


/**
 * 查询到目前的播放时间。
 * @param handle				打开的bitstream 句柄。	
 * @param ms_current_time		用于存放得到的播放时间的变量指针。	
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
VMINT vm_bitstream_video_get_play_time(VMINT handle, VMUINT* ms_current_time);



 /**
 * 不停止解码的状态下短暂的画面暂停，用于视频位置/大小的切换
 * 此接口支持很短时间的暂停,因尽快的调用vm_bitstream_video_switchscreenstart函数恢复，
 * 否则将失败
 * @param handle				打开的bitstream 句柄。	
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
VMINT vm_bitstream_video_switchscreenstop(VMINT handle);



 /**
 * 用于恢复vm_bitstream_video_switchscreenstop引起的画面暂停
 * @param handle				打开的bitstream 句柄。
 * @param  para			配置播放的参数结构体变量指针。
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED错误。
 */
VMINT vm_bitstream_video_switchscreenstart(VMINT handle, vm_bitstream_video_start_param* p_para);



#ifdef __cplusplus
}
#endif

#endif
