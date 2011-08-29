#ifndef __VM_SAL_BITSTREAM__
#define __VM_SAL_BITSTREAM__

#include "vmsys.h"
#include "vmbitstream.h"

/**
 * (SAL �㺯��)
 * ��bitstream ��ʽ����Ƶ��Դ��
 *
 * @param handle			�򿪵�bitstream �����
 * @param audio_type		��Ƶ��Դ�����͡�
 * @param result_callback	��Ƶ�ص�������
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_open(
	VMINT* handle,
	vm_bitstream_audio_cfg_struct *audio_type,
	vm_bitstream_audio_result_callback callback);

/**
 * (SAL �㺯��)
 * �ر���bitstream ��ʽ�򿪵���Ƶ�ļ���
 *
 * @param handle			��vm_bitstream_audio_open �򿪵�bitstream �����
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_close(VMINT handle);

/**
 * (SAL �㺯��)
 * ����bitstream �����ȡ��Ƶ����ṹ�塣
 *
 * @param handle			�򿪵�bitstream �����
 * @param status			�õ�����Ƶ����ṹ�塣
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_get_buffer_status(
	VMINT handle, 
	vm_bitstream_audio_buffer_status *status);

/**
 * (SAL �㺯��)
 * ��ָ����С����Ƶ����д����Ƶ�������ڣ���ͨ������used_size ��֤��ʵд�����ݴ�С��
 *
 * @param handle			�򿪵�bitstream �����
 * @param buffer			��д����Ƶ���������ڴ��ַָ�롣
 * @param buffer_size		Ҫд��Ļ�����ֽ�����
 * @param used_size		ʵ��д�뻺����ֽ�����
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_put_data(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT 	buffer_size,
	VMUINT	*written);

 /**
 * (SAL �㺯��)
 * ��ָ��ʱ�����Ƶ����д����Ƶ�������ڣ�������ݴ�С����������������ʧ�ܡ�
 *
 * @param handle			�򿪵�bitstream �����
 * @param buffer			��д����Ƶ������������ָ�롣
 * @param buffer_size		Ҫд��Ļ���Ĵ�С��
 * @param used_size		Ҫд�뻺�����Ƶʱ��(��λ������)��
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_put_frame(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT	buffer_size,
	VMUINT 	timestamp);

/**
 * (SAL �㺯��)
 * ��ʼ����BitStream Audio ��Ƶ��
 *
 * @param handle			Ҫ���ŵ�bitstream �����
 * @param para			������Ƶʱ�����ṹ�塣
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_start(
	VMINT handle,
	vm_bitstream_audio_start_param *para);

/**
 * (SAL �㺯��)
 * ֹͣ����BitStream Audio ��Ƶ��
 *
 * @param handle			Ҫֹͣ���ŵ�bitstream �����
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_stop(VMINT handle);

/**
 * (SAL �㺯��)
 * ��ȡ��ǰ����ʱ�䡣
 *
 * @param handle			Ҫ��ȡ����ʱ���bitstream �����
 * @param current_time		��õĵ�ǰ����ʱ��(��λ������)
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_sal_bitstream_audio_get_play_time(
	VMINT handle,
	VMUINT* current_time);


 /**
 * ��bitstream��Ƶ��
 *
 * @param handle			�򿪵�bitstream �����
 * @param cfg				h264���ýṹ��Ϣ��
 * @param callback		�ص�������								
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT stub_bitstream_video_open(
        VMINT* handle,
        vm_bitstream_video_h264_cfg* cfg,
        vm_bitstream_video_result_callback callback);


 /**
 * �ر�bitstream��Ƶ��
 *
 * @param handle			�򿪵�bitstream �����							
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT stub_bitstream_video_close(VMINT handle);    


/**
 * �õ�������״̬��
 * @param handle			�򿪵�bitstream �����		
 * @param status			��仺������Ϣ�Ľṹ��ָ�������
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT stub_bitstream_video_get_buffer_status(VMINT handle, vm_bitstream_video_buffer_status* status);


 /**
 * ��仺������
 * @param handle			�򿪵�bitstream �����		
 * @param  buffer			��������Դ����ָ�롣		
 * @param buffer_size		����Դ�����С��
 * @param timestamp		ʱ���λ�á�
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT stub_bitstream_video_put_frame(VMINT handle, VMUSTR buffer, VMUINT buffer_size, VMUINT timestamp);


/**
 * ��ʼ����bitsteam��Ƶ��
 * @param handle			�򿪵�bitstream �����		
 * @param  para			���ò��ŵĲ����ṹ��ָ�������		
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT stub_bitstream_video_start(VMINT handle, vm_bitstream_video_start_param* para);



/**
 * ֹͣ����bitsteam��Ƶ,�����ٴβ��ţ���Ҫ�رգ������´򿪡�
 * @param handle			�򿪵�bitstream �����				
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT stub_bitstream_video_stop(VMINT handle);


/**
 * ��ѯ��Ŀǰ�Ĳ���ʱ�䡣
 * @param handle				�򿪵�bitstream �����	
 * @param ms_current_time		���ڴ�ŵõ��Ĳ���ʱ���ָ�������	
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT stub_bitstream_video_get_play_time(VMINT handle, VMUINT* ms_current_time);



 /**
 * ��ֹͣ�����״̬�¶��ݵĻ�����ͣ��������Ƶλ��/��С���л�
 * �˽ӿ�֧�ֺܶ�ʱ�����ͣ,�򾡿�ĵ���vm_bitstream_video_switchscreenstart�����ָ���
 * ����ʧ��
 * @param handle				�򿪵�bitstream �����	
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT stub_bitstream_video_switchscreenstop(VMINT handle);



 /**
 * ���ڻָ�vm_bitstream_video_switchscreenstop����Ļ�����ͣ
 * @param handle				�򿪵�bitstream �����
 * @param  para			���ò��ŵĲ����ṹ��ָ�������
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT stub_bitstream_video_switchscreenstart(VMINT handle, vm_bitstream_video_start_param* p_para);

/*
* �������ֹ���
*/
void stub_audio_suspend_background_play(void);

/*
* ��������resume
*/
void stub_audio_resume_background_play(void);


#endif /* __VM_SAL_BITSTREAM__ */
