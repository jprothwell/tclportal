#ifndef VMMM_H_
#define VMMM_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif


/* �̷������� */
#define DRV_NAME_LEN	(4)

/* ¼�������� */
#define REC_NAME_LEN	(50)

/* Ŀ¼���� */
#define DIR_NAME_LEN	(200)

/* �ļ������� */
#define MAX_NAME_LEN	(260)

/* ���ļ������� */
#define MAX_WNAME_LEN		(260 * sizeof(VMWCHAR))

/* Ĭ������ */
#define DEFAULT_VOLUME			3

/**
 *	���ֲ���·��
 */
#define VM_DEVICE_SPEAKER 			0 		/* ��Ͳ*/
#define VM_DEVICE_MICROPHONE	 	1 		/* ���*/
#define VM_DEVICE_SPEAKER2 		4 		/* �ж���ʱ�Ӷ�����û�ж���ʱ��loudspeaker����*/
#define VM_DEVICE_LOUDSPEAKER 	5		/* �Ӻ���Ĵ����Ȳ���*/
#define VM_DEVICE_SPEAKER_BOTH 	6		/* �Ӷ���������ͬʱ����*/
#define VM_DEVICE_BT_HEADSET 		8		/* ���������ò��ţ�����������*/

/**
 *	��������
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
 * ¼�� ����Ϊ��ռ��Դ����ͬһAPP ��Ҫ�򿪵ڶ���¼�������ش���
 * 
 * ������ռ����Ƶ��Դ�Ĺ��ܹ�ϵ��
 * ��Ƶ����ʹ��ʱ������ʹ�ñ����ܡ�
 * bitstream ����ʹ��ʱ������ʹ�ñ����ܡ�
 * midi ���� ��ʹ��ʱ�������ܽ�ֹͣmidi����ռ��Ƶ��Դ��
 * audio ������ʹ��ʱ�������ܽ�ֹͣaudio����ռ��Ƶ��Դ��
 * 
 * ��ʵ������£�
 * ������APP ���л�����̨�������ⲿ�¼����ʱ ����VRE ϵͳǿ����
 * ֹ������¼���ݱ���������¼��ʱָ���ļ��С�
 *
 * ��̨ʱ��
 * �����ܽ�����ʹ�á�
 */

/**
 * ¼�������ɹ���
 */
#define VM_RECORD_SUCCEED		(1)

/**
 * ¼������ʧ�ܡ�
 */
#define VM_RECORD_FAILED		(0)

/**
 * ¼���ص���������˵����
 */
typedef void(*vm_recorder_callback)(VMINT result);

/**
 *	��ʼ¼��,�û���Ҫ��������������·����¼��������ʽ��
 *	ϵͳ��ʼ¼��������һ������·����¼���ļ���(UCS2����)��
 *	@param drv_name				¼��Ŀ����̣�ֻ��ʹ��Ӣ�ĵ��ַ�(ASCII����)��
 *    @param dir_name				¼��Ŀ��Ŀ¼��Ŀ¼��ҪС��DIR_NAME_LEN ���ַ�(ASCII����)��
 *    @param rec_name				¼��Ŀ�����ƣ��ļ���Ҫ��1 ��REC_NAME_LEN ���ַ�֮�䣬��Ҫָ����׺��(ASCII����)��
 *	@param format				¼����ʽ(��֧��AMR(VM_FORMAT_AMR) ��WAV(VM_FORMAT_WAV) ���ָ�ʽ)��
 *	@param full_rec_file_wname		����¼���ļ���ȫ���������¼��������֮ǰָ��Ŀ¼��ͬ(ucs2��ʽ)��
 *    @param vm_record_cb			¼���ص�������
 *
 *	@return 						����VM_RECORD_SUCCEED Ϊ�����ɹ���  VM_RECORD_FAILED Ϊ����ʧ��.
 */
VMINT vm_record_start(VMSTR drv_name, VMSTR dir_name, VMSTR rec_name, VMUINT8 format, VMWSTR full_rec_file_wname, vm_recorder_callback vm_record_cb);

/**
 *	��ͣ¼����
 *	���¼��״̬Ϊ���л�����ͣʱ�����ز���ʧ�ܡ�
 *
 *	@return 					����VM_RECORD_SUCCEED Ϊ�����ɹ���  VM_RECORD_FAILED Ϊ����ʧ��.
 */
VMINT vm_record_pause(void);

/**
 *	�ָ�¼����
 *	���¼��״̬Ϊ���л���¼��ʱ�����ز���ʧ�ܡ�
 *
 *	@return 					����VM_RECORD_SUCCEED Ϊ�����ɹ���  VM_RECORD_FAILED Ϊ����ʧ��.
 */
VMINT vm_record_resume(void);

/**
 *	����¼����
 *
 *	@return 					����VM_RECORD_SUCCEED Ϊ�����ɹ���  VM_RECORD_FAILED Ϊ����ʧ��.
 */
VMINT vm_record_stop(void);


/* ===================== audio ========================== */

/**
 * ��Ƶ���Ź�����ͬ��APP ����ѭ����Ϊ���ԭ�򣬼�ֹͣԭ�в��ţ�
 * ��ʼ���ź�򿪵���Ƶ��
 *
 * ������ռ����Ƶ��Դ�Ĺ��ܹ�ϵ��
 * ��Ƶ����ʹ��ʱ������ʹ�ñ����ܡ�
 * bitstream ����ʹ��ʱ������ʹ�ñ����ܡ�
 * ¼��������ʹ��ʱ������ʹ�ñ����ܡ�
 * midi ������ʹ��ʱ�������ܽ�ֹͣmidi����ռ��Ƶ��Դ��
 * 
 * ��ʵ������£�
 * ������APP ���л�����̨ʱ����APP CallBack ��Ϣ���Ƿ�Ҫֹͣ������APP
 * ���������ں�̨����ʱ��������Ƶ���� ʹ�ã������ܽ���ֹͣ��
 * APP ���л�ǰ̨ʱҲ����APP CallBack ��Ϣ(���б�ֹͣ��ʱ��)���Ƿ�Ҫ��
 * ���ز�����APP ������
 *
 * ��̨ʱ��
 * �����Ƶ��Դδ��ռ�ã������ܿ�ʹ�á�
 */

/**
 * ��Ƶ�����ɹ���
 */
#define VM_AUDIO_SUCCEED 	(0)

/**
 * ��Ƶ����ʧ�ܡ�
 */
#define VM_AUDIO_FAILED	(-1)

/**
 * ��Ƶ����ֹͣ(�û�����ֹͣ)��
 */
#define VM_AUDIO_RESULT_STOP			1

/**
 * ��Ƶ������ͣ��
 */
#define VM_AUDIO_RESULT_PAUSE			2

/**
 * ��Ƶ���Żָ���
 */
#define VM_AUDIO_RESULT_RESUME			3

/*
* ��Ƶ���� ��������(�����ļ��������)��
*/  
#define	VM_AUDIO_RESULT_END_OF_FILE		5

/*
* ��ƵDEMO ����ʱ�� ������
*/  
#define	VM_AUDIO_RESULT_DEMO_END		6

/**
 * ��Ƶ���ⲿ�¼��жϡ�
 */
#define	VM_AUDIO_RESULT_INTERRUPT		7

/**
 * ��Ƶ�ⲿ�¼��жϽ�����
 */
#define	VM_AUDIO_RESULT_INTERRUPT_RESUME		8


/**
 * ������Ƶ�ļ����ܹ�֧�ֵ���Ƶ�����ʽ���ֻ�Ӳ������������һ��CBR��MP3��
 * AAC����֧�֡�ϵͳ����Ƶ���������ǵ����ģ�����һʱ��ֻ�ܲ���һ����Ƶ�ļ���
 *
 * @param filename				��Ƶ�ļ�·��(ע�⣺��ʹ�ò�����200�����ַ����ļ�·��)��
 * @param f						�ص�������
 *
 * @return						����VM_AUDIO_SUCCEED ��ʾ�ɹ���VM_AUDIO_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_audio_play_file(VMWSTR filename, void (*f)(VMINT result));

/**
 * ������Ƶ�ļ����ܹ�֧�ֵ���Ƶ�����ʽ���ֻ�Ӳ������������һ��CBR��MP3��
 * AAC����֧�֡�ϵͳ����Ƶ���������ǵ����ģ�����һʱ��ֻ�ܲ���һ����Ƶ�ļ���
 *
 * @param filename				��Ƶ�ļ�·��(ע�⣺��ʹ�ò�����200�����ַ����ļ�·��)��
 * @param start_time				��ʼ���ŵ�ʱ��(��λ������)��Ϊ0 ʱ��ͷ��ʼ����(�翪ʼ����ʱ�������ʱ�佫ʧ��)��
 * @param path					���ֲ���·����
 * @param f						�ص�������
 *
 * @return						����VM_AUDIO_SUCCEED ��ʾ�ɹ���VM_AUDIO_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_audio_play_file_ex(VMWSTR filename, VMUINT start_time, VMUINT path, void (*f)(VMINT result));

/**
 *  �����ֽ���������Ƶ��ʹ�ñ�����������Ƶʱ�ǵ����ģ�����һʱ��ֻ�ܲ���һ����Ƶ�ļ���
 *
 * @param audio_data				�ֽ�������ʼ��ַ��		
 * @param len						��Ƶ�ֽ����ĳ���(�紫�볤��С����Ƶ���ȣ�ֻ���Ŵ��볤��)��
 * @param format					��Ƶ����(��֧��VM_FORMAT_MP3 ��VM_FORMAT_AAC���ָ�ʽ)��
 * @param start_time				��ʼ���ŵ�ʱ��(��λ������)��Ϊ0 ʱ��ͷ��ʼ����(�翪ʼ����ʱ�������ʱ�佫ʧ��)��
 * @param path					���ֲ���·����
 * @param f						�ص�������
 *
 * @return						����VM_AUDIO_SUCCEED ��ʾ�ɹ���VM_AUDIO_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_audio_play_bytes(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path, void (*f)(VMINT result));

/**
 * ��ͣ������Ƶ��
 *
 * @param f						�ص�������
 *
 * @return						����VM_AUDIO_SUCCEED ��ʾ�ɹ���VM_AUDIO_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_audio_pause(void (*f)(VMINT result));

/**
 * �ָ�������Ƶ��
 *
 * @param f						�ص�������
 *
 * @return						����VM_AUDIO_SUCCEED ��ʾ�ɹ���VM_AUDIO_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_audio_resume(void (*f)(VMINT result));

/**
 * ֹͣ������Ƶ��vm_audio_play_file()��vm_audio_play_bytes()���ŵ���Ƶ���ɱ������رա�
 *
 * @param f						�ص�������
 *
 * @return						����VM_AUDIO_SUCCEED ��ʾ�ɹ���VM_AUDIO_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_audio_stop(void (*f)(VMINT result));

/*
 * �����Ƶ�ļ��Ĳ���ʱ����֧��MP3/AAC��CBR��ʽ��
 *
 * @param filename				��Ƶ�ļ�����·����
 *
 * @return						���طǸ�������ʱ��������Ϊ��λ������VM_AUDIO_FAILED ��ʾ�޷���ȡʱ�䡣
 */
VMINT vm_audio_duration(VMWSTR filename);

/*
 * �����Ƶ�ֽ����Ĳ���ʱ������֧��MP3/MIDI�����ָ�ʽ��
 *
 * @param audio_data				�ֽ�������ʼ��ַ��	
 * @param len						��Ƶ�ֽ����ĳ��ȡ�
 * @param format					��Ƶ�ֽ����ĸ�ʽ��(��֧��VM_FORMAT_MP3��VM_FORMAT_AAC���ָ�ʽ)
 *
 * @return						���طǸ�������ʱ��������Ϊ��λ������VM_AUDIO_FAILED ��ʾ�޷���ȡʱ�䡣
 */
VMINT vm_audio_bytes_duration(void *audio_data, VMUINT len, VMUINT8 format);


/*
 * �����Ƶ�ļ��ĵ�ǰ����ʱ��(�޷��õ��ɺ���vm_audio_play_bytes ���ŵĸ���ʱ��)��
 *
 * @return						���طǸ�������ʱ�����Ժ���Ϊ��λ������VM_AUDIO_FAILED ��ʾ�޷���ȡʱ�䡣
 */
VMINT vm_audio_get_time(void);

/**
 * ����������С��
 *
 * @param volume				��������0~6�ֱ��ʾ������������������� Ϊ0 ʱ��ʾ������
 */
void vm_set_volume(VMINT volume);


/* ========================== midi ============================ */

/**
 * MIDI ���Ź���֧�ֶ�·�����������ͬʱ����֧����·������
 * ��Ҫ�򿪵����handle��������ʧ�ܡ�
 *
 * ������ռ����Ƶ��Դ�Ĺ��ܹ�ϵ��
 * ��Ƶ����ʹ��ʱ������ʹ�ñ����ܡ�
 * bitstream ����ʹ��ʱ������ʹ�ñ����ܡ�
 * ¼��������ʹ��ʱ������ʹ�ñ����ܡ�
 * audio ������ʹ��ʱ�������ܽ�ֹͣaudio����ռ��Ƶ��Դ��
 * 
 * ��ʵ������£�
 * ������APP ���л�����̨ʱ����APP CallBack ��Ϣ���Ƿ�Ҫֹͣ������APP
 * ������APP ���л�ǰ̨ʱҲ����APP CallBack ��Ϣ(���б�ֹͣ��ʱ��)����
 * ��Ҫ�ϵ��ز�����APP ������
 *
 * ��̨ʱ��
 * �����ܲ���ʹ�á�
 */

/**
 * MIDI �����ɹ���
 */
#define VM_MIDI_SUCCEED 	(0)

/**
 * MIDI ����ʧ�ܡ�
 */
#define VM_MIDI_FAILED		(-1)

/**
 * MIDI ͬʱ�ɲ�������
 */
#define VM_MIDI_PLAY_MAX	4

/**
 * MIDI��ʼ���š�
 */
#define VM_STATE_MIDI_START		1

/**
 * MIDI���Ž�����
 */
#define VM_STATE_MIDI_STOP			2

/**
 * ����MIDI��
 * 
 * @param resid					VREʹ����Դ�����Ψһ���һ��MIDI��Դ������
 *								�ֻ����������������ԣ�һ��MIDI�ļ��������ֽ�
 *								�������ʽ��ִ�д�������һ������WINDOWS
 *								ϵͳ�ô����ļ�������Դ��ʽ���MIDI�ļ�����ȫ
 *								��ͬ�ġ�Ϊ�˱���MIDI���ŵ�ƽ̨�޹��ԣ�VREʹ��
 *								��Դ�������ʶMIDI��Դ����Դ�������Դ֮���ӳ��
 *								��ϵͨ��vm_midi_get_resource()����ʵ�֡�
 * @param repeat					�ظ����Ŵ�������Ϊ0��ʾ�ظ����š�
 * @param f						�ص�������
 *
 * @return						���ش��ڵ���0 �ľ����ʾ���ųɹ�������VM_MIDI_FAILED��ʾʧ�ܡ�
 */
VMINT vm_midi_play(VMINT resid, VMINT repeat, void (*f)(VMINT handle, VMINT event));

/**
 * ָ����ʼʱ�䲥��MIDI��
 * 
 * @param resid					VREʹ����Դ�����Ψһ���һ��MIDI��Դ��
 * @param start_time				��ʼ���ŵ�ʱ�䣬Ϊ0 ʱ��ͷ��ʼ���š�(��λ������)
 * @param repeat					�ظ����Ŵ�������Ϊ0��ʾ�ظ����š�
 * @param path					���ֲ���·����
 * @param f						�ص�������
 *
 * @return						���طǸ�ֵ�ľ����ʾ���ųɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_midi_play_ex(VMINT resid, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event));

/**
 * �����ֽ�������MIDI��
 * 
 * @param midibuf					�ֽ�������ʼ��ַ
 * @param len						midi�ֽ����ĳ���
 * @param repeat					�ظ����Ŵ�������Ϊ0��ʾ�ظ����š�
 * @param f						�ص�������
 *
 * @return						���طǸ�ֵ�ľ����ʾ���ųɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_midi_play_by_bytes( VMUINT8 * midibuf, VMINT len, VMINT repeat, void (*f)(VMINT handle, VMINT event) );

/**
 * �����ֽ�������MIDI������ָ��������ʼʱ�䡣
 * 
 * @param midibuf					�ֽ�������ʼ��ַ
 * @param len						midi�ֽ����ĳ���
 * @param start_time				��ʼ���ŵ�ʱ�䣬Ϊ0 ʱ��ͷ��ʼ���š�(��λ������)
 * @param repeat					�ظ����Ŵ�������Ϊ0��ʾ�ظ����š�
 * @param path					���ֲ���·����
 * @param f						�ص�������
 *
 * @return						���طǸ�ֵ�ľ����ʾ���ųɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_midi_play_by_bytes_ex( VMUINT8 * midibuf, VMINT len, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event) );

/**
 * MIDI��Դӳ�亯�����������������Ӧ�ó���ʵ�֡�һ����˵��WINDOWSӦ�ó���ͨ����
 * MIDI�ļ�����ڴ����ϣ�Ȼ��ͨ������MIDI�ļ���ʵ�ֲ��Ź��ܡ����ֻ�Ӧ�ó������
 * MIDI�ļ������ֽ��������ʽ�ʹ�������һ���ֻ��ϲ���MIDIͨ��Ҳ���Դ����ڴ�
 * ָ�뷽ʽʵ�֡�vm_midi_get_resource()������Ŀ����ʵ�������ߵ�ӳ���ϵ����WINDOWS
 * ʵ���У�Ӧ�ó���Ӧ������Դ��ŷ��ض�Ӧ��MIDI�ļ�·�������ֻ�ʵ���У�Ӧ�ó���
 * Ӧ������Դ��ŷ��ذ���MIDI�ļ����ݵ��ڴ�ָ�롣
 *
 * @param resid				��Դ��ţ������Ӧ�ó��������
 * @param len					��WINDOWSʵ���У�������������ԡ����ֻ�ʵ���У�Ϊ����
 *							MIDI���ݵ��ڴ�鳤�ȣ����ֽ�Ϊ��λ��
 *
 * @return					���ش��MIDIԭʼ���ݵ��ڴ�ָ�룬����NULL��ʾӳ��ʧ�ܡ�
 */
//VMUINT8* vm_midi_get_resource(VMINT resid,VMINT *len);

/**
 * ��ͣ����MIDI ��Ƶ��
 *
 * @param handle					Ҫ��ͣ��MIDI ��Ƶhandle��
 *
 * @return						����VM_MIDI_SUCCEED ��ʾ�ɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_midi_pause(VMINT handle);

/**
 * �ָ�����MIDI ��Ƶ��
 *
 * @param f						Ҫ�ָ���MIDI ��Ƶhandle��
 *
 * @return						����VM_MIDI_SUCCEED ��ʾ�ɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_midi_resume(VMINT handle);

/**
 * ��õ�ǰMIDI �ļ����Ѳ���ʱ�䡣
 *
 * @param handle				MIDI�������vm_midi_play()�������ء�
 * @param current_time			MIDI �ļ����Ѳ���ʱ��(��λ������)��
 *
 * @return					����VM_MIDI_SUCCEED ��ʾ�ɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_midi_get_time(VMINT handle, VMUINT *current_time);

/**
 * ֹͣ����MIDI��
 *
 * @param handle				MIDI�������vm_midi_play()�������ء�
 */
void vm_midi_stop(VMINT handle);

/**
  *	ֹͣ�������ڲ��ŵ�MIDI ���֡�
  */
void vm_midi_stop_all(void);

/* ============================== other ========================== */

/**
 * ��һ�Σ�ÿ��һ�롣��̨֧�֡�
 */
void vm_vibrator_once(void);

/**
 *	���ð������򿪣���̨ʱ���ԡ�
 */
void vm_set_key_tone_on(void);

/**
 *	���ð������رգ���̨ʱ���ԡ�
 */
void vm_set_key_tone_off(void);

/*
 *	������״̬ö������
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
 * �õ���ǰ��������״̬����̨ʱ����ʹ�á�
 *
 * @return ��ǰ��������״ֵ̬��
 */
vm_kbd_tone_state_enum vm_get_key_tone_state(void);

/**
 * ���õ�ǰ��������״̬����̨���� ʱʧ�ܡ�
 *
 * @param key_tone_state ��������״̬��
 *
 * @return TRUE=���óɹ���FALSE=����ʧ�ܡ�
 */
VMINT vm_set_key_tone_state(vm_kbd_tone_state_enum key_tone_state);



/* ================= Kuro api ====================== */

/**
 * KURO �����ɹ���
 */
#define VM_KURO_SUCCEED 	(0)

/**
 * KURO ����ʧ�ܡ�
 */
#define VM_KURO_FAILED		(-1)


/**
 * ȥ�������ܿ�����
 *
 * @return				����VM_KURO_SUCCEED ��ʾ�ɹ���VM_KURO_FAILED Ϊʧ�ܡ�
 */
VMINT vm_audio_vocal_removal_turn_on(void);

/**
 * ȥ�������ܹرա�
 *
 * @return				����VM_KURO_SUCCEED ��ʾ�ɹ���VM_KURO_FAILED Ϊʧ�ܡ�?
 */
VMINT vm_audio_vocal_removal_turn_off(void);

/**
 * ���������ܿ����������������ļ�����Ϊ�㡣
 *
 * @return				����VM_KURO_SUCCEED ��ʾ�ɹ���VM_KURO_FAILED Ϊʧ�ܡ�
 */
VMINT vm_audio_pitch_shifting_turn_on(void);

/**
 * ���������ܹرա�
 *
 * @return				����VM_KURO_SUCCEED ��ʾ�ɹ���VM_KURO_FAILED Ϊʧ�ܡ�
 */
VMINT vm_audio_pitch_shifting_turn_off(void);

/**
 * �����������ļ���
 *
 * @param level			���ñ���ļ���(��Χ��-4 ~ 4 ֮��)�������ü��𳬹���Χ���Զ���������Χ�߽硣
 *
 * @return				����VM_KURO_SUCCEED ��ʾ�ɹ���VM_KURO_FAILED Ϊʧ�ܡ�
 */
VMINT vm_audio_pitch_shifting_set_level(VMINT16 level);

/**
 * ��������������������ʽ������MP3/AAC/MIDI��������Ŀ��ƽ̨֧�ֵĸ�ʽ��
 *
 * @param filepath                        �����ļ�������·����
 *
 * @return                                      ���طǸ�ֵ��ʾ���óɹ���VM_KURO_FAILED Ϊʧ�ܡ�
 */
VMINT vm_set_ringtone(VMWSTR filepath);



#ifdef __cplusplus
}
#endif

#endif /* VMMM_H_ */
