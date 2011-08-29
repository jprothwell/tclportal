#ifndef VMMM_H_
#define VMMM_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif


/* 盘符名长度 */
#define DRV_NAME_LEN	(4)

/* 录音名长度 */
#define REC_NAME_LEN	(50)

/* 目录长度 */
#define DIR_NAME_LEN	(200)

/* 文件名长度 */
#define MAX_NAME_LEN	(260)

/* 宽文件名长度 */
#define MAX_WNAME_LEN		(260 * sizeof(VMWCHAR))

/* 默认音量 */
#define DEFAULT_VOLUME			3

/**
 *	音乐播放路径
 */
#define VM_DEVICE_SPEAKER 			0 		/* 听筒*/
#define VM_DEVICE_MICROPHONE	 	1 		/* 麦克*/
#define VM_DEVICE_SPEAKER2 		4 		/* 有耳机时从耳机，没有耳机时从loudspeaker播放*/
#define VM_DEVICE_LOUDSPEAKER 	5		/* 从后面的大喇叭播放*/
#define VM_DEVICE_SPEAKER_BOTH 	6		/* 从耳机和喇叭同时播放*/
#define VM_DEVICE_BT_HEADSET 		8		/* 从蓝牙设置播放，如蓝牙耳机*/

/**
 *	音乐类型
 */
typedef enum
{
	VM_FORMAT_NONE = -1,  
    	VM_FORMAT_AMR = 3,
    	VM_FORMAT_MP3 = 5,
    	VM_FORMAT_AAC = 6,
   	VM_FORMAT_WAV = 13,
   	VM_FORMAT_MIDI = 17,
   	VM_FORMAT_OTHER = 100,
	VM_FORMAT_MAX
}vm_format_enum;

/* ======================= record ====================== */

/**
 * 录音 操作为独占资源，如同一APP 中要打开第二个录音将返回错误。
 * 
 * 与其它占用音频资源的功能关系：
 * 视频功能使用时将不能使用本功能。
 * bitstream 功能使用时将不能使用本功能。
 * midi 功能 在使用时，本功能将停止midi，抢占音频资源。
 * audio 功能在使用时，本功能将停止audio，抢占音频资源。
 * 
 * 多实例情况下：
 * 如所在APP 被切换到后台或者有外部事件打断时 将被VRE 系统强制中
 * 止并将已录内容保存至申请录音时指定文件中。
 *
 * 后台时：
 * 本功能将不能使用。
 */

/**
 * 录音操作成功。
 */
#define VM_RECORD_SUCCEED		(1)

/**
 * 录音操作失败。
 */
#define VM_RECORD_FAILED		(0)

/**
 * 录音回调函数类型说明。
 */
typedef void(*vm_recorder_callback)(VMINT result);

/**
 *	开始录音,用户需要输入驱动器名，路经，录音名，格式，
 *	系统开始录音并返回一个完整路径的录音文件名(UCS2编码)。
 *	@param drv_name				录音目标磁盘，只用使用英文单字符(ASCII编码)。
 *    @param dir_name				录音目标目录，目录名要小于DIR_NAME_LEN 个字符(ASCII编码)。
 *    @param rec_name				录音目标名称，文件名要在1 至REC_NAME_LEN 个字符之间，不要指定后缀名(ASCII编码)。
 *	@param format				录音格式(现支持AMR(VM_FORMAT_AMR) 与WAV(VM_FORMAT_WAV) 两种格式)。
 *	@param full_rec_file_wname		返回录音文件的全名，必须记录，可能与之前指定目录不同(ucs2格式)。
 *    @param vm_record_cb			录音回调函数。
 *
 *	@return 						返回VM_RECORD_SUCCEED 为操作成功，  VM_RECORD_FAILED 为操作失败.
 */
VMINT vm_record_start(VMSTR drv_name, VMSTR dir_name, VMSTR rec_name, VMUINT8 format, VMWSTR full_rec_file_wname, vm_recorder_callback vm_record_cb);

/**
 *	暂停录音。
 *	如果录音状态为空闲或者暂停时，返回操作失败。
 *
 *	@return 					返回VM_RECORD_SUCCEED 为操作成功，  VM_RECORD_FAILED 为操作失败.
 */
VMINT vm_record_pause(void);

/**
 *	恢复录音。
 *	如果录音状态为空闲或者录音时，返回操作失败。
 *
 *	@return 					返回VM_RECORD_SUCCEED 为操作成功，  VM_RECORD_FAILED 为操作失败.
 */
VMINT vm_record_resume(void);

/**
 *	结束录音。
 *
 *	@return 					返回VM_RECORD_SUCCEED 为操作成功，  VM_RECORD_FAILED 为操作失败.
 */
VMINT vm_record_stop(void);


/* ===================== audio ========================== */

/**
 * 音频播放功能在同个APP 中遵循后者为大的原则，即停止原有播放，
 * 开始播放后打开的音频。
 *
 * 与其它占用音频资源的功能关系：
 * 视频功能使用时将不能使用本功能。
 * bitstream 功能使用时将不能使用本功能。
 * 录音功能在使用时将不能使用本功能。
 * midi 功能在使用时，本功能将停止midi，抢占音频资源。
 * 
 * 多实例情况下：
 * 如所在APP 被切换到后台时将给APP CallBack 消息，是否要停止操作由APP
 * 决定。如在后台播放时有其它音频功能 使用，本功能将被停止。
 * APP 被切回前台时也将给APP CallBack 消息(带有被停止的时间)，是否要断
 * 点重播将由APP 决定。
 *
 * 后台时：
 * 如果音频资源未被占用，本功能可使用。
 */

/**
 * 音频操作成功。
 */
#define VM_AUDIO_SUCCEED 	(0)

/**
 * 音频操作失败。
 */
#define VM_AUDIO_FAILED	(-1)

/**
 * 音频播放停止(用户主动停止)。
 */
#define VM_AUDIO_RESULT_STOP			1

/**
 * 音频播放暂停。
 */
#define VM_AUDIO_RESULT_PAUSE			2

/**
 * 音频播放恢复。
 */
#define VM_AUDIO_RESULT_RESUME			3

/*
* 音频播放 正常结束(音乐文件播放完成)。
*/  
#define	VM_AUDIO_RESULT_END_OF_FILE		5

/*
* 音频DEMO 播放时间 结束。
*/  
#define	VM_AUDIO_RESULT_DEMO_END		6

/**
 * 音频遇外部事件中断。
 */
#define	VM_AUDIO_RESULT_INTERRUPT		7

/**
 * 音频外部事件中断结束。
 */
#define	VM_AUDIO_RESULT_INTERRUPT_RESUME		8


/**
 * 播放音频文件，能够支持的音频编码格式视手机硬件能力而定，一般CBR的MP3和
 * AAC都能支持。系统的音频播放能力是单工的，即任一时刻只能播放一个音频文件。
 *
 * @param filename				音频文件路径(注意：请使用不超过200个宽字符的文件路径)。
 * @param f						回调函数。
 *
 * @return						返回VM_AUDIO_SUCCEED 表示成功，VM_AUDIO_FAILED 表示失败。
 */
VMINT vm_audio_play_file(VMWSTR filename, void (*f)(VMINT result));

/**
 * 播放音频文件，能够支持的音频编码格式视手机硬件能力而定，一般CBR的MP3和
 * AAC都能支持。系统的音频播放能力是单工的，即任一时刻只能播放一个音频文件。
 *
 * @param filename				音频文件路径(注意：请使用不超过200个宽字符的文件路径)。
 * @param start_time				开始播放的时间(单位：毫秒)，为0 时从头开始播放(如开始播放时间大于总时间将失败)。
 * @param path					音乐播放路径。
 * @param f						回调函数。
 *
 * @return						返回VM_AUDIO_SUCCEED 表示成功，VM_AUDIO_FAILED 表示失败。
 */
VMINT vm_audio_play_file_ex(VMWSTR filename, VMUINT start_time, VMUINT path, void (*f)(VMINT result));

/**
 *  根据字节流播放音频，使用本方法播放音频时是单工的，即任一时刻只能播放一个音频文件。
 *
 * @param audio_data				字节流的起始地址。		
 * @param len						音频字节流的长度(如传入长度小于音频长度，只播放传入长度)。
 * @param format					音频类型(现支持VM_FORMAT_MP3 与VM_FORMAT_AAC两种格式)。
 * @param start_time				开始播放的时间(单位：毫秒)，为0 时从头开始播放(如开始播放时间大于总时间将失败)。
 * @param path					音乐播放路径。
 * @param f						回调函数。
 *
 * @return						返回VM_AUDIO_SUCCEED 表示成功，VM_AUDIO_FAILED 表示失败。
 */
VMINT vm_audio_play_bytes(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path, void (*f)(VMINT result));

/**
 * 暂停播放音频。
 *
 * @param f						回调函数。
 *
 * @return						返回VM_AUDIO_SUCCEED 表示成功，VM_AUDIO_FAILED 表示失败。
 */
VMINT vm_audio_pause(void (*f)(VMINT result));

/**
 * 恢复播放音频。
 *
 * @param f						回调函数。
 *
 * @return						返回VM_AUDIO_SUCCEED 表示成功，VM_AUDIO_FAILED 表示失败。
 */
VMINT vm_audio_resume(void (*f)(VMINT result));

/**
 * 停止播放音频。vm_audio_play_file()与vm_audio_play_bytes()播放的音频均由本函数关闭。
 *
 * @param f						回调函数。
 *
 * @return						返回VM_AUDIO_SUCCEED 表示成功，VM_AUDIO_FAILED 表示失败。
 */
VMINT vm_audio_stop(void (*f)(VMINT result));

/*
 * 获得音频文件的播放时长，支持MP3/AAC的CBR格式。
 *
 * @param filename				音频文件完整路径。
 *
 * @return						返回非负数播放时长，以秒为单位，返回VM_AUDIO_FAILED 表示无法获取时间。
 */
VMINT vm_audio_duration(VMWSTR filename);

/*
 * 获得音频字节流的播放时长，现支持MP3/MIDI的两种格式。
 *
 * @param audio_data				字节流的起始地址。	
 * @param len						音频字节流的长度。
 * @param format					音频字节流的格式。(现支持VM_FORMAT_MP3与VM_FORMAT_AAC两种格式)
 *
 * @return						返回非负数播放时长，以秒为单位，返回VM_AUDIO_FAILED 表示无法获取时间。
 */
VMINT vm_audio_bytes_duration(void *audio_data, VMUINT len, VMUINT8 format);


/*
 * 获得音频文件的当前播放时间(无法得到由函数vm_audio_play_bytes 播放的歌曲时间)。
 *
 * @return						返回非负数播放时长，以毫秒为单位，返回VM_AUDIO_FAILED 表示无法获取时间。
 */
VMINT vm_audio_get_time(void);

/**
 * 设置音量大小。
 *
 * @param volume				音量，从0~6分别表示静音到最大音量，设置 为0 时表示静音。
 */
void vm_set_volume(VMINT volume);


/* ========================== midi ============================ */

/**
 * MIDI 播放功能支持多路混音，将最多同时可以支持四路混音。
 * 如要打开第五个handle，将返回失败。
 *
 * 与其它占用音频资源的功能关系：
 * 视频功能使用时将不能使用本功能。
 * bitstream 功能使用时将不能使用本功能。
 * 录音功能在使用时将不能使用本功能。
 * audio 功能在使用时，本功能将停止audio，抢占音频资源。
 * 
 * 多实例情况下：
 * 如所在APP 被切换到后台时将给APP CallBack 消息，是否要停止操作由APP
 * 决定。APP 被切回前台时也将给APP CallBack 消息(带有被停止的时间)，是
 * 否要断点重播将由APP 决定。
 *
 * 后台时：
 * 本功能不能使用。
 */

/**
 * MIDI 操作成功。
 */
#define VM_MIDI_SUCCEED 	(0)

/**
 * MIDI 操作失败。
 */
#define VM_MIDI_FAILED		(-1)

/**
 * MIDI 同时可播放数。
 */
#define VM_MIDI_PLAY_MAX	4

/**
 * MIDI开始播放。
 */
#define VM_STATE_MIDI_START		1

/**
 * MIDI播放结束。
 */
#define VM_STATE_MIDI_STOP			2

/**
 * 播放MIDI。
 * 
 * @param resid					VRE使用资源编号来唯一标记一个MIDI资源，由于
 *								手机开发环境的特殊性，一般MIDI文件都是以字节
 *								数组的形式与执行代码存放在一起，这与WINDOWS
 *								系统用磁盘文件或者资源形式存放MIDI文件是完全
 *								不同的。为了保持MIDI播放的平台无关性，VRE使用
 *								资源编号来标识MIDI资源。资源编号与资源之间的映射
 *								关系通过vm_midi_get_resource()函数实现。
 * @param repeat					重复播放次数，设为0表示重复播放。
 * @param f						回调函数。
 *
 * @return						返回大于等于0 的句柄表示播放成功，返回VM_MIDI_FAILED表示失败。
 */
VMINT vm_midi_play(VMINT resid, VMINT repeat, void (*f)(VMINT handle, VMINT event));

/**
 * 指定启始时间播放MIDI。
 * 
 * @param resid					VRE使用资源编号来唯一标记一个MIDI资源。
 * @param start_time				开始播放的时间，为0 时从头开始播放。(单位：毫秒)
 * @param repeat					重复播放次数，设为0表示重复播放。
 * @param path					音乐播放路径。
 * @param f						回调函数。
 *
 * @return						返回非负值的句柄表示播放成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_midi_play_ex(VMINT resid, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event));

/**
 * 根据字节流播放MIDI。
 * 
 * @param midibuf					字节流的起始地址
 * @param len						midi字节流的长度
 * @param repeat					重复播放次数，设为0表示重复播放。
 * @param f						回调函数。
 *
 * @return						返回非负值的句柄表示播放成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_midi_play_by_bytes( VMUINT8 * midibuf, VMINT len, VMINT repeat, void (*f)(VMINT handle, VMINT event) );

/**
 * 根据字节流播放MIDI，并可指定播放启始时间。
 * 
 * @param midibuf					字节流的起始地址
 * @param len						midi字节流的长度
 * @param start_time				开始播放的时间，为0 时从头开始播放。(单位：毫秒)
 * @param repeat					重复播放次数，设为0表示重复播放。
 * @param path					音乐播放路径。
 * @param f						回调函数。
 *
 * @return						返回非负值的句柄表示播放成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_midi_play_by_bytes_ex( VMUINT8 * midibuf, VMINT len, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event) );

/**
 * MIDI资源映射函数，这个函数必须由应用程序实现。一般来说，WINDOWS应用程序通常把
 * MIDI文件存放在磁盘上，然后通过播放MIDI文件来实现播放功能。而手机应用程序则把
 * MIDI文件以以字节数组的形式和代码存放在一起，手机上播放MIDI通常也是以传递内存
 * 指针方式实现。vm_midi_get_resource()函数的目的是实现这两者的映射关系，在WINDOWS
 * 实现中，应用程序应根据资源编号返回对应的MIDI文件路径。在手机实现中，应用程序
 * 应根据资源编号返回包含MIDI文件内容的内存指针。
 *
 * @param resid				资源编号，编号由应用程序决定。
 * @param len					在WINDOWS实现中，这个参数被忽略。在手机实现中，为包含
 *							MIDI内容的内存块长度，以字节为单位。
 *
 * @return					返回存放MIDI原始数据的内存指针，返回NULL表示映射失败。
 */
//VMUINT8* vm_midi_get_resource(VMINT resid,VMINT *len);

/**
 * 暂停播放MIDI 音频。
 *
 * @param handle					要暂停的MIDI 音频handle。
 *
 * @return						返回VM_MIDI_SUCCEED 表示成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_midi_pause(VMINT handle);

/**
 * 恢复播放MIDI 音频。
 *
 * @param f						要恢复的MIDI 音频handle。
 *
 * @return						返回VM_MIDI_SUCCEED 表示成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_midi_resume(VMINT handle);

/**
 * 获得当前MIDI 文件的已播放时间。
 *
 * @param handle				MIDI句柄，由vm_midi_play()函数返回。
 * @param current_time			MIDI 文件的已播放时间(单位：毫秒)。
 *
 * @return					返回VM_MIDI_SUCCEED 表示成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_midi_get_time(VMINT handle, VMUINT *current_time);

/**
 * 停止播放MIDI。
 *
 * @param handle				MIDI句柄，由vm_midi_play()函数返回。
 */
void vm_midi_stop(VMINT handle);

/**
  *	停止所有正在播放的MIDI 音乐。
  */
void vm_midi_stop_all(void);

/* ============================== other ========================== */

/**
 * 震动一次，每次一秒。后台支持。
 */
void vm_vibrator_once(void);

/**
 *	设置按键声打开，后台时忽略。
 */
void vm_set_key_tone_on(void);

/**
 *	设置按键声关闭，后台时忽略。
 */
void vm_set_key_tone_off(void);

/*
 *	按键音状态枚举类型
 */
typedef enum
{
	VM_KEY_TONE_ENABLED = 0,		 /* Not Disable all key tone */
    	VM_KEY_VOL_TONE_DISABLED,		/* Disable VOL_UP VOL_DOWN key tone */
    	VM_KEY_VOL_UP_DOWN_TONE_DISABLED,		/* Disable VOL_UP, VOL_DOWN, UP_ARROW, DOWN_ARROW key tone */
    	VM_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED,	/* Disable LEFT ARROW, RIGHT ARROW */
    	VM_KEY_TONE_DISABLED,		/* Disable all key tone */
    	VM_KEY_TONE_INVALID
} vm_kbd_tone_state_enum;

/**
 * 得到当前按键声的状态，后台时正常使用。
 *
 * @return 当前按键声的状态值。
 */
vm_kbd_tone_state_enum vm_get_key_tone_state(void);

/**
 * 设置当前按键声的状态，后台设置 时失败。
 *
 * @param key_tone_state 按键声的状态。
 *
 * @return TRUE=设置成功，FALSE=设置失败。
 */
VMINT vm_set_key_tone_state(vm_kbd_tone_state_enum key_tone_state);



/* ================= Kuro api ====================== */

/**
 * KURO 操作成功。
 */
#define VM_KURO_SUCCEED 	(0)

/**
 * KURO 操作失败。
 */
#define VM_KURO_FAILED		(-1)


/**
 * 去人声功能开启。
 *
 * @return				返回VM_KURO_SUCCEED 表示成功，VM_KURO_FAILED 为失败。
 */
VMINT vm_audio_vocal_removal_turn_on(void);

/**
 * 去人声功能关闭。
 *
 * @return				返回VM_KURO_SUCCEED 表示成功，VM_KURO_FAILED 为失败。?
 */
VMINT vm_audio_vocal_removal_turn_off(void);

/**
 * 升降调功能开启，并将升降调的级别设为零。
 *
 * @return				返回VM_KURO_SUCCEED 表示成功，VM_KURO_FAILED 为失败。
 */
VMINT vm_audio_pitch_shifting_turn_on(void);

/**
 * 升降调功能关闭。
 *
 * @return				返回VM_KURO_SUCCEED 表示成功，VM_KURO_FAILED 为失败。
 */
VMINT vm_audio_pitch_shifting_turn_off(void);

/**
 * 设置升降调的级别。
 *
 * @param level			设置变调的级别(范围在-4 ~ 4 之间)，如设置级别超过范围将自动调整至范围边界。
 *
 * @return				返回VM_KURO_SUCCEED 表示成功，VM_KURO_FAILED 为失败。
 */
VMINT vm_audio_pitch_shifting_set_level(VMINT16 level);

/**
 * 设置来电铃声，铃声格式可以是MP3/AAC/MIDI，必须是目标平台支持的格式。
 *
 * @param filepath                        铃声文件的完整路径。
 *
 * @return                                      返回非负值表示设置成功，VM_KURO_FAILED 为失败。
 */
VMINT vm_set_ringtone(VMWSTR filepath);



#ifdef __cplusplus
}
#endif

#endif /* VMMM_H_ */
