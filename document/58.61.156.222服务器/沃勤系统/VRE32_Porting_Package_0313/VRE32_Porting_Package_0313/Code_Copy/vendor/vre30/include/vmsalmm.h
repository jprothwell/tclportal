#ifndef VMSALMM_H_
#define VMSALMM_H_

#include "mdi_datatype.h"

#include "vmmm.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ======================= record ====================== */
/**
 *	(SAL �㺯��)
 *	��ʼ¼����
 *	@param file_name			¼��Ŀ������
 *	@param format			¼����ʽ��
 *    @param cb_handler		¼���ص�������
 *
 *	@return 					����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_record_start(VMWCHAR *file_name, VMUINT8 file_format, mdi_callback cb_handler);

/**
 *	(SAL �㺯��)
 *	��ͣ¼��
 *    @param handler		�ص�������
 *
 *	@return 					����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_record_pause(mdi_callback handler);

/**
 *	(SAL �㺯��)
 *	�ָ�¼��
 *    @param handler		�ص�������
 *
 *	@return 					����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_record_resume(mdi_callback handler);

/**
 *	(SAL �㺯��)
 *	����¼��
 *	@return 					����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_record_stop(void);


/* ===================== audio ========================== */

/**
 * (SAL �㺯��)
 * ������Ƶ�ļ����ܹ�֧�ֵ���Ƶ�����ʽ���ֻ�Ӳ������������һ��CBR��MP3��
 * AAC����֧�֡�ϵͳ����Ƶ���������ǵ����ģ�����һʱ��ֻ�ܲ���һ����Ƶ�ļ���
 *
 * @param filename				��Ƶ�ļ�·����
 * @param f						�ص�������
 *
 * @return 						����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_audio_play_file(VMWSTR filename, void (*f)(VMINT result));

/**
 * (SAL �㺯��)
 * ������Ƶ�ļ����ܹ�֧�ֵ���Ƶ�����ʽ���ֻ�Ӳ������������һ��CBR��MP3��
 * AAC����֧�֡�ϵͳ����Ƶ���������ǵ����ģ�����һʱ��ֻ�ܲ���һ����Ƶ�ļ���
 *
 * @param filename				��Ƶ�ļ�·����
 * @param start_time				��ʼ���ŵ�ʱ�䣬Ϊ0 ʱ��ͷ��ʼ���š�
 * @param path					���ֲ���·��(VM_DEVICE_SPEAKER��)��
 * @param f						�ص�������
 *
 * @return 						����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_audio_play_file_ex(VMWSTR filename, VMUINT start_time, VMUINT path, void (*f)(VMINT result));

/**
 * (SAL �㺯��)
 *  �����ֽ���������Ƶ
 *
 * @param audio_data				�ֽ�������ʼ��ַ��		
 * @param len						��Ƶ�ֽ����ĳ��ȡ�
 * @param format					��Ƶ���͡�
 * @param start_time				��ʼ���ŵ�ʱ�䣬Ϊ0 ʱ��ͷ��ʼ���š�
 * @param path					���ֲ���·��(VM_DEVICE_SPEAKER��)��
 * @param f						�ص�������
 *
 * @return 						����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_audio_play_bytes(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path, void (*f)(VMINT result));

/**
 * (SAL �㺯��)
 * ��ͣ������Ƶ��
 *
 * @param f						�ص�������
 *
 * @return 						����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_audio_pause(void (*f)(VMINT result));

/**
 * (SAL �㺯��)
 * �ָ�������Ƶ��
 *
 * @param f						�ص�������
 *
 * @return 						����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_audio_resume(void (*f)(VMINT result));

/**
 * (SAL �㺯��)
 * ֹͣ������Ƶ��vm_sal_audio_play_file()��vm_sal_audio_play_bytes()���ŵ���Ƶ���ɱ������رա�
 *
 * @param f						�ص�������
 *
 * @return 						����VM_AUDIO_SUCCEED Ϊ�����ɹ���  ����Ϊ����ʧ��.
 */
VMINT vm_sal_audio_stop(void (*f)(VMINT result));

/*
 * (SAL �㺯��)
 * �����Ƶ�ļ��Ĳ���ʱ����֧��MP3/AAC��CBR��ʽ��
 *
 * @param filename				��Ƶ�ļ�����·����
 *
 * @return						���طǸ�����ʾ���ֲ���ʱ��������Ϊ��λ������VM_AUDIO_FAILED ��ʾ�޷���ȡʱ�䡣
 */
VMINT vm_sal_audio_duration(VMWSTR filename);

/*
 * (SAL �㺯��)
 * �����Ƶ�ֽ����Ĳ���ʱ����֧��MP3/AAC��CBR��ʽ��
 *
 * @param audio_data				�ֽ�������ʼ��ַ��	
 * @param len						��Ƶ�ֽ����ĳ��ȡ�	
 * @param format					��Ƶ�ֽ����ĸ�ʽ��
 * 								(MP3	VM_FORMAT_MP3		MDI_FORMAT_DAF		5)	
 *								(MIDI	VM_FORMAT_MIDI		MDI_FORMAT_SMF		17)
 *
 * @return						���طǸ�������ʱ��������Ϊ��λ������VM_AUDIO_FAILED ��ʾ�޷���ȡʱ�䡣
 */
VMINT vm_sal_audio_bytes_duration(void *audio_data, VMUINT len, VMUINT8 format);


/*
 * (SAL �㺯��)
 * �����Ƶ�ļ��ĵ�ǰ����ʱ�䡣
 *
 * @return						���طǸ�������ʱ�����Ժ���Ϊ��λ������VM_AUDIO_FAILED ��ʾ�޷���ȡʱ�䡣
 */
VMINT vm_sal_audio_get_time(void);

/**
 * (SAL �㺯��)
 * ����������С��
 *
 * @param volume				��������0~6�ֱ��ʾ���������������
 */
void vm_sal_set_volume(VMINT volume);
//wei.xia add by 0624
void vm_sal_set_current_volume(VMINT volume);
//add end

/**
 * (SAL �㺯��)
 * ����auido �ı������š�
 */
void vm_sal_audio_suspend_background_play(void);

/**
 * (SAL �㺯��)
 * �ָ��������auido �ı������š�
 */
void vm_sal_audio_resume_background_play(void);

/* ========================== midi ============================ */


/**
 * (SAL �㺯��)
 * ����MIDI��
 * 
 * @param resid					VREʹ����Դ�����Ψһ���һ��MIDI��Դ������
 *								�ֻ����������������ԣ�һ��MIDI�ļ��������ֽ�
 *								�������ʽ��ִ�д�������һ������WINDOWS
 *								ϵͳ�ô����ļ�������Դ��ʽ���MIDI�ļ�����ȫ
 *								��ͬ�ġ�Ϊ�˱���MIDI���ŵ�ƽ̨�޹��ԣ�VREʹ��
 *								��Դ�������ʶMIDI��Դ����Դ�������Դ֮���ӳ��
 *								��ϵͨ��vm_sal_midi_get_resource()����ʵ�֡�
 * @param repeat					�ظ����Ŵ�������Ϊ0��ʾ�ظ����š�
 * @param f						�ص�������
 *
 * @return						���طǸ�ֵ�ľ����ʾ���ųɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_sal_midi_play(VMINT resid, VMINT repeat, void (*f)(VMINT handle, VMINT event));

/**
 * (SAL �㺯��)
 * ָ����ʼʱ�䲥��MIDI��
 * 
 * @param resid					VREʹ����Դ�����Ψһ���һ��MIDI��Դ��
 * @param start_time				��ʼ���ŵ�ʱ�䣬Ϊ0 ʱ��ͷ��ʼ���š�(��λ������)
 * @param repeat					�ظ����Ŵ�������Ϊ0��ʾ�ظ����š�
 * @param path					���ֲ���·��(VM_DEVICE_SPEAKER��)��
 * @param f						�ص�������
 *
 * @return						���طǸ�ֵ�ľ����ʾ���ųɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_sal_midi_play_ex(VMINT resid, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event));

/**
 * (SAL �㺯��)
 * �����ֽ�������MIDI��
 * 
 * @param midibuf					�ֽ�������ʼ��ַ
 * @param len						midi�ֽ����ĳ���
 * @param repeat					�ظ����Ŵ�������Ϊ0��ʾ�ظ����š�
 * @param f						�ص�������
 *
 * @return						���طǸ�ֵ�ľ����ʾ���ųɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_sal_midi_play_by_bytes( VMUINT8 * midibuf, VMINT len, VMINT repeat, void (*f)(VMINT handle, VMINT event) );

/**
 * (SAL �㺯��)
 * �����ֽ�������MIDI������ָ��������ʼʱ�䡣
 * 
 * @param midibuf					�ֽ�������ʼ��ַ
 * @param len						midi�ֽ����ĳ���
 * @param start_time				��ʼ���ŵ�ʱ�䣬Ϊ0 ʱ��ͷ��ʼ���š�(��λ������)
 * @param repeat					�ظ����Ŵ�������Ϊ0��ʾ�ظ����š�
 * @param path					���ֲ���·��(VM_DEVICE_SPEAKER��)��
 * @param f						�ص�������
 *
 * @return						���طǸ�ֵ�ľ����ʾ���ųɹ�������VM_MIDI_FAILED ��ʾʧ�ܡ�
 */
VMINT vm_sal_midi_play_by_bytes_ex( VMUINT8 * midibuf, VMINT len, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event) );

/**
 * (SAL �㺯��)
 * MIDI��Դӳ�亯�����������������Ӧ�ó���ʵ�֡�һ����˵��WINDOWSӦ�ó���ͨ����
 * MIDI�ļ�����ڴ����ϣ�Ȼ��ͨ������MIDI�ļ���ʵ�ֲ��Ź��ܡ����ֻ�Ӧ�ó������
 * MIDI�ļ������ֽ��������ʽ�ʹ�������һ���ֻ��ϲ���MIDIͨ��Ҳ���Դ����ڴ�
 * ָ�뷽ʽʵ�֡�vm_sal_midi_get_resource()������Ŀ����ʵ�������ߵ�ӳ���ϵ����WINDOWS
 * ʵ���У�Ӧ�ó���Ӧ������Դ��ŷ��ض�Ӧ��MIDI�ļ�·�������ֻ�ʵ���У�Ӧ�ó���
 * Ӧ������Դ��ŷ��ذ���MIDI�ļ����ݵ��ڴ�ָ�롣
 *
 * @param resid				��Դ��ţ������Ӧ�ó��������
 * @param len					��WINDOWSʵ���У�������������ԡ����ֻ�ʵ���У�Ϊ����
 *							MIDI���ݵ��ڴ�鳤�ȣ����ֽ�Ϊ��λ��
 *
 * @return					���ش��MIDIԭʼ���ݵ��ڴ�ָ�룬����NULL��ʾӳ��ʧ�ܡ�
 */
VMUINT8* vm_sal_midi_get_resource(VMINT resid,VMINT *len);

/**
 * (SAL �㺯��)
 * ��ͣ����MIDI ��Ƶ��
 *
 * @param handle					Ҫ��ͣ��MIDI ��Ƶhandle��
 *
 * @return						����VM_MIDI_SUCCEED ��ʾ�ɹ�������ʧ�ܡ�
 */
VMINT vm_sal_midi_pause(VMINT handle);

/**
 * (SAL �㺯��)
 * �ָ�����MIDI ��Ƶ��
 *
 * @param f						Ҫ�ָ���MIDI ��Ƶhandle��
 *
 * @return						����VM_MIDI_SUCCEED ��ʾ�ɹ�������ʧ�ܡ�
 */
VMINT vm_sal_midi_resume(VMINT handle);

/**
 * (SAL �㺯��)
 * ��õ�ǰMIDI �ļ����Ѳ���ʱ�䡣
 *
 * @param handle				MIDI�������vm_sal_midi_play()�������ء�
 * @param current_time			MIDI �ļ����Ѳ���ʱ��(��λ������)��
 *
 * @return					����VM_MIDI_SUCCEED ��ʾ�ɹ���VM_MIDI_FAILED Ϊ����
 */
VMINT vm_sal_midi_get_time(VMINT handle, VMUINT *current_time);

/**
 * (SAL �㺯��)
 * �����Ѵ�MIDI �ļ��ĵ�ǰ����ʱ�䡣
 *
 * @param handle				MIDI�������vm_sal_midi_play()�������ء�
 * @param current_time			MIDI �ļ����Ѳ���ʱ��(��λ������)��
 *
 * @return					����VM_MIDI_SUCCEED ��ʾ�ɹ���VM_MIDI_FAILED Ϊ����
 */
VMINT vm_sal_midi_set_time(VMINT handle, VMUINT current_time);

/**
 * (SAL �㺯��)
 * ֹͣ����MIDI��
 *
 * @param handle				MIDI�������vm_midi_play()�������ء�
 *
 * @return					����VM_MIDI_SUCCEED ��ʾ�ɹ���VM_MIDI_FAILED Ϊ����
 */
VMINT vm_sal_midi_stop(VMINT handle);

/* ============================== other ========================== */

/**
 * (SAL �㺯��)
 * ��һ�Σ� ���ڵĹ���������δ���ʱ�ٴ�CALL ����Ч��
 */
void vm_sal_vibrator_once(void);

/**
 * (SAL �㺯��)
 *	���ð�������
 */
void vm_sal_set_key_tone_on(void);

/**
 * (SAL �㺯��)
 *	���ð������ر�
 */
void vm_sal_set_key_tone_off(void);

/**
 * (SAL �㺯��)
 * �õ���ǰ��������״̬
 *
 * @return ��ǰ��������״ֵ̬
 */
vm_kbd_tone_state_enum vm_sal_get_key_tone_state(void);

/**
 * (SAL �㺯��)
 * ���õ�ǰ��������״̬
 * @param key_tone_state 			��������״̬
 * @return 						TRUE ���óɹ���FALSE ����ʧ��
 */
VMINT vm_sal_set_key_tone_state(vm_kbd_tone_state_enum key_tone_state);


/**
 * (SAL �㺯��)
 * ��ѯ��ǰ�Ƿ��е绰����������
 * @return 						TRUE �е绰������FALSE �޵绰������
 */
VMINT vm_sal_query_calling(void);

/**
 * (SAL �㺯��)
 * ���������û�Ĭ��ֵ��
 */
void reset_default_volume(void);

/* ================= Kuro api ====================== */

/**
 * (SAL �㺯��)
 * ���Chip ID �����Ƿ�ɹ�
 *
 * @return				����1 ��ʾ�ɹ�������Ϊ����
 */
VMINT vm_sal_check_chip_ID(void);

/**
 * (SAL �㺯��)
 * ȥ�������ܿ���
 *
 * @return				����0 ��ʾ�ɹ�������Ϊ����
 */
VMINT vm_sal_audio_vocal_removal_turn_on(void);

/**
 * (SAL �㺯��)
 * ȥ�������ܹر�
 *
 * @return				����0 ��ʾ�ɹ�������Ϊ����
 */
VMINT vm_sal_audio_vocal_removal_turn_off(void);

/**
 * (SAL �㺯��)
 * ���������ܿ���
 *
 * @return				����0 ��ʾ�ɹ�������Ϊ����
 */
VMINT vm_sal_audio_pitch_shifting_turn_on(void);

/**
 * (SAL �㺯��)
 * ���������ܹر�
 *
 * @return				����0 ��ʾ�ɹ�������Ϊ����
 */
VMINT vm_sal_audio_pitch_shifting_turn_off(void);

/**
 * (SAL �㺯��)
 * �����������ļ���
 *
 * @param level			���ñ���ļ���(��Χ��-4 ~ 4 ֮��)��
 *
 * @return				����0 ��ʾ�ɹ�������Ϊ����
 */
VMINT vm_sal_audio_pitch_shifting_set_level(VMINT16 level);

/**
 * (SAL �㺯��)
 * ��������������������ʽ������MP3/AAC/MIDI��������Ŀ��ƽ̨֧�ֵĸ�ʽ��
 *
 * @param filepath                        �����ļ�������·����
 *
 * @return                                    ���طǸ�ֵ��ʾ���óɹ���VM_KURO_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_set_ringtone(VMWSTR filepath);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* VMSALMM_H_ */

