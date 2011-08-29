#ifndef VMSALMM_H_
#define VMSALMM_H_

#include "mdi_datatype.h"

#include "vmmm.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ======================= record ====================== */
/**
 *	(SAL 层函数)
 *	开始录音。
 *	@param file_name			录音目标名称
 *	@param format			录音格式。
 *    @param cb_handler		录音回调函数。
 *
 *	@return 					返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_record_start(VMWCHAR *file_name, VMUINT8 file_format, mdi_callback cb_handler);

/**
 *	(SAL 层函数)
 *	暂停录音
 *    @param handler		回调函数。
 *
 *	@return 					返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_record_pause(mdi_callback handler);

/**
 *	(SAL 层函数)
 *	恢复录音
 *    @param handler		回调函数。
 *
 *	@return 					返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_record_resume(mdi_callback handler);

/**
 *	(SAL 层函数)
 *	结束录音
 *	@return 					返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_record_stop(void);


/* ===================== audio ========================== */

/**
 * (SAL 层函数)
 * 播放音频文件，能够支持的音频编码格式视手机硬件能力而定，一般CBR的MP3和
 * AAC都能支持。系统的音频播放能力是单工的，即任一时刻只能播放一个音频文件。
 *
 * @param filename				音频文件路径。
 * @param f						回调函数。
 *
 * @return 						返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_audio_play_file(VMWSTR filename, void (*f)(VMINT result));

/**
 * (SAL 层函数)
 * 播放音频文件，能够支持的音频编码格式视手机硬件能力而定，一般CBR的MP3和
 * AAC都能支持。系统的音频播放能力是单工的，即任一时刻只能播放一个音频文件。
 *
 * @param filename				音频文件路径。
 * @param start_time				开始播放的时间，为0 时从头开始播放。
 * @param path					音乐播放路径(VM_DEVICE_SPEAKER等)。
 * @param f						回调函数。
 *
 * @return 						返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_audio_play_file_ex(VMWSTR filename, VMUINT start_time, VMUINT path, void (*f)(VMINT result));

/**
 * (SAL 层函数)
 *  根据字节流播放音频
 *
 * @param audio_data				字节流的起始地址。		
 * @param len						音频字节流的长度。
 * @param format					音频类型。
 * @param start_time				开始播放的时间，为0 时从头开始播放。
 * @param path					音乐播放路径(VM_DEVICE_SPEAKER等)。
 * @param f						回调函数。
 *
 * @return 						返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_audio_play_bytes(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path, void (*f)(VMINT result));

/**
 * (SAL 层函数)
 * 暂停播放音频。
 *
 * @param f						回调函数。
 *
 * @return 						返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_audio_pause(void (*f)(VMINT result));

/**
 * (SAL 层函数)
 * 恢复播放音频。
 *
 * @param f						回调函数。
 *
 * @return 						返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_audio_resume(void (*f)(VMINT result));

/**
 * (SAL 层函数)
 * 停止播放音频。vm_sal_audio_play_file()与vm_sal_audio_play_bytes()播放的音频均由本函数关闭。
 *
 * @param f						回调函数。
 *
 * @return 						返回VM_AUDIO_SUCCEED 为操作成功，  其它为操作失败.
 */
VMINT vm_sal_audio_stop(void (*f)(VMINT result));

/*
 * (SAL 层函数)
 * 获得音频文件的播放时长，支持MP3/AAC的CBR格式。
 *
 * @param filename				音频文件完整路径。
 *
 * @return						返回非负数表示音乐播放时长，以秒为单位，返回VM_AUDIO_FAILED 表示无法获取时间。
 */
VMINT vm_sal_audio_duration(VMWSTR filename);

/*
 * (SAL 层函数)
 * 获得音频字节流的播放时长，支持MP3/AAC的CBR格式。
 *
 * @param audio_data				字节流的起始地址。	
 * @param len						音频字节流的长度。	
 * @param format					音频字节流的格式。
 * 								(MP3	VM_FORMAT_MP3		MDI_FORMAT_DAF		5)	
 *								(MIDI	VM_FORMAT_MIDI		MDI_FORMAT_SMF		17)
 *
 * @return						返回非负数播放时长，以秒为单位，返回VM_AUDIO_FAILED 表示无法获取时间。
 */
VMINT vm_sal_audio_bytes_duration(void *audio_data, VMUINT len, VMUINT8 format);


/*
 * (SAL 层函数)
 * 获得音频文件的当前播放时间。
 *
 * @return						返回非负数播放时长，以毫秒为单位，返回VM_AUDIO_FAILED 表示无法获取时间。
 */
VMINT vm_sal_audio_get_time(void);

/**
 * (SAL 层函数)
 * 设置音量大小。
 *
 * @param volume				音量，从0~6分别表示静音到最大音量。
 */
void vm_sal_set_volume(VMINT volume);
//wei.xia add by 0624
void vm_sal_set_current_volume(VMINT volume);
//add end

/**
 * (SAL 层函数)
 * 挂起auido 的背景播放。
 */
void vm_sal_audio_suspend_background_play(void);

/**
 * (SAL 层函数)
 * 恢复被挂起的auido 的背景播放。
 */
void vm_sal_audio_resume_background_play(void);

/* ========================== midi ============================ */


/**
 * (SAL 层函数)
 * 播放MIDI。
 * 
 * @param resid					VRE使用资源编号来唯一标记一个MIDI资源，由于
 *								手机开发环境的特殊性，一般MIDI文件都是以字节
 *								数组的形式与执行代码存放在一起，这与WINDOWS
 *								系统用磁盘文件或者资源形式存放MIDI文件是完全
 *								不同的。为了保持MIDI播放的平台无关性，VRE使用
 *								资源编号来标识MIDI资源。资源编号与资源之间的映射
 *								关系通过vm_sal_midi_get_resource()函数实现。
 * @param repeat					重复播放次数，设为0表示重复播放。
 * @param f						回调函数。
 *
 * @return						返回非负值的句柄表示播放成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_sal_midi_play(VMINT resid, VMINT repeat, void (*f)(VMINT handle, VMINT event));

/**
 * (SAL 层函数)
 * 指定启始时间播放MIDI。
 * 
 * @param resid					VRE使用资源编号来唯一标记一个MIDI资源。
 * @param start_time				开始播放的时间，为0 时从头开始播放。(单位：毫秒)
 * @param repeat					重复播放次数，设为0表示重复播放。
 * @param path					音乐播放路径(VM_DEVICE_SPEAKER等)。
 * @param f						回调函数。
 *
 * @return						返回非负值的句柄表示播放成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_sal_midi_play_ex(VMINT resid, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event));

/**
 * (SAL 层函数)
 * 根据字节流播放MIDI。
 * 
 * @param midibuf					字节流的起始地址
 * @param len						midi字节流的长度
 * @param repeat					重复播放次数，设为0表示重复播放。
 * @param f						回调函数。
 *
 * @return						返回非负值的句柄表示播放成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_sal_midi_play_by_bytes( VMUINT8 * midibuf, VMINT len, VMINT repeat, void (*f)(VMINT handle, VMINT event) );

/**
 * (SAL 层函数)
 * 根据字节流播放MIDI，并可指定播放启始时间。
 * 
 * @param midibuf					字节流的起始地址
 * @param len						midi字节流的长度
 * @param start_time				开始播放的时间，为0 时从头开始播放。(单位：毫秒)
 * @param repeat					重复播放次数，设为0表示重复播放。
 * @param path					音乐播放路径(VM_DEVICE_SPEAKER等)。
 * @param f						回调函数。
 *
 * @return						返回非负值的句柄表示播放成功，返回VM_MIDI_FAILED 表示失败。
 */
VMINT vm_sal_midi_play_by_bytes_ex( VMUINT8 * midibuf, VMINT len, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event) );

/**
 * (SAL 层函数)
 * MIDI资源映射函数，这个函数必须由应用程序实现。一般来说，WINDOWS应用程序通常把
 * MIDI文件存放在磁盘上，然后通过播放MIDI文件来实现播放功能。而手机应用程序则把
 * MIDI文件以以字节数组的形式和代码存放在一起，手机上播放MIDI通常也是以传递内存
 * 指针方式实现。vm_sal_midi_get_resource()函数的目的是实现这两者的映射关系，在WINDOWS
 * 实现中，应用程序应根据资源编号返回对应的MIDI文件路径。在手机实现中，应用程序
 * 应根据资源编号返回包含MIDI文件内容的内存指针。
 *
 * @param resid				资源编号，编号由应用程序决定。
 * @param len					在WINDOWS实现中，这个参数被忽略。在手机实现中，为包含
 *							MIDI内容的内存块长度，以字节为单位。
 *
 * @return					返回存放MIDI原始数据的内存指针，返回NULL表示映射失败。
 */
VMUINT8* vm_sal_midi_get_resource(VMINT resid,VMINT *len);

/**
 * (SAL 层函数)
 * 暂停播放MIDI 音频。
 *
 * @param handle					要暂停的MIDI 音频handle。
 *
 * @return						返回VM_MIDI_SUCCEED 表示成功，否则失败。
 */
VMINT vm_sal_midi_pause(VMINT handle);

/**
 * (SAL 层函数)
 * 恢复播放MIDI 音频。
 *
 * @param f						要恢复的MIDI 音频handle。
 *
 * @return						返回VM_MIDI_SUCCEED 表示成功，否则失败。
 */
VMINT vm_sal_midi_resume(VMINT handle);

/**
 * (SAL 层函数)
 * 获得当前MIDI 文件的已播放时间。
 *
 * @param handle				MIDI句柄，由vm_sal_midi_play()函数返回。
 * @param current_time			MIDI 文件的已播放时间(单位：毫秒)。
 *
 * @return					返回VM_MIDI_SUCCEED 表示成功，VM_MIDI_FAILED 为错误。
 */
VMINT vm_sal_midi_get_time(VMINT handle, VMUINT *current_time);

/**
 * (SAL 层函数)
 * 设置已打开MIDI 文件的当前播放时间。
 *
 * @param handle				MIDI句柄，由vm_sal_midi_play()函数返回。
 * @param current_time			MIDI 文件的已播放时间(单位：毫秒)。
 *
 * @return					返回VM_MIDI_SUCCEED 表示成功，VM_MIDI_FAILED 为错误。
 */
VMINT vm_sal_midi_set_time(VMINT handle, VMUINT current_time);

/**
 * (SAL 层函数)
 * 停止播放MIDI。
 *
 * @param handle				MIDI句柄，由vm_midi_play()函数返回。
 *
 * @return					返回VM_MIDI_SUCCEED 表示成功，VM_MIDI_FAILED 为错误。
 */
VMINT vm_sal_midi_stop(VMINT handle);

/* ============================== other ========================== */

/**
 * (SAL 层函数)
 * 震动一次， 现在的规则是在震动未完成时再次CALL 入无效。
 */
void vm_sal_vibrator_once(void);

/**
 * (SAL 层函数)
 *	设置按键声打开
 */
void vm_sal_set_key_tone_on(void);

/**
 * (SAL 层函数)
 *	设置按键声关闭
 */
void vm_sal_set_key_tone_off(void);

/**
 * (SAL 层函数)
 * 得到当前按键声的状态
 *
 * @return 当前按键声的状态值
 */
vm_kbd_tone_state_enum vm_sal_get_key_tone_state(void);

/**
 * (SAL 层函数)
 * 设置当前按键声的状态
 * @param key_tone_state 			按键声的状态
 * @return 						TRUE 设置成功，FALSE 设置失败
 */
VMINT vm_sal_set_key_tone_state(vm_kbd_tone_state_enum key_tone_state);


/**
 * (SAL 层函数)
 * 查询当前是否有电话呼入或呼出。
 * @return 						TRUE 有电话操作，FALSE 无电话操作。
 */
VMINT vm_sal_query_calling(void);

/**
 * (SAL 层函数)
 * 将音量设置回默认值。
 */
void reset_default_volume(void);

/* ================= Kuro api ====================== */

/**
 * (SAL 层函数)
 * 检测Chip ID 加密是否成功
 *
 * @return				返回1 表示成功，否则为错误。
 */
VMINT vm_sal_check_chip_ID(void);

/**
 * (SAL 层函数)
 * 去人声功能开启
 *
 * @return				返回0 表示成功，否则为错误。
 */
VMINT vm_sal_audio_vocal_removal_turn_on(void);

/**
 * (SAL 层函数)
 * 去人声功能关闭
 *
 * @return				返回0 表示成功，否则为错误。
 */
VMINT vm_sal_audio_vocal_removal_turn_off(void);

/**
 * (SAL 层函数)
 * 升降调功能开启
 *
 * @return				返回0 表示成功，否则为错误。
 */
VMINT vm_sal_audio_pitch_shifting_turn_on(void);

/**
 * (SAL 层函数)
 * 升降调功能关闭
 *
 * @return				返回0 表示成功，否则为错误。
 */
VMINT vm_sal_audio_pitch_shifting_turn_off(void);

/**
 * (SAL 层函数)
 * 设置升降调的级别
 *
 * @param level			设置变调的级别(范围在-4 ~ 4 之间)。
 *
 * @return				返回0 表示成功，否则为错误。
 */
VMINT vm_sal_audio_pitch_shifting_set_level(VMINT16 level);

/**
 * (SAL 层函数)
 * 设置来电铃声，铃声格式可以是MP3/AAC/MIDI，必须是目标平台支持的格式。
 *
 * @param filepath                        铃声文件的完整路径。
 *
 * @return                                    返回非负值表示设置成功，VM_KURO_FAILED 为失败。
 */
VMINT vm_sal_set_ringtone(VMWSTR filepath);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* VMSALMM_H_ */

