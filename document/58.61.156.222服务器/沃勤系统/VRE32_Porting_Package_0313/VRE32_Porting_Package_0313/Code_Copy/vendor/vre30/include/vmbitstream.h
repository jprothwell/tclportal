#ifndef _VM_BITSTREAM_H
#define _VM_BITSTREAM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmmm.h"

/**
 * BitStream �����ɹ���
 */
#define VM_BITSTREAM_SUCCEED                   			(0)

/**
 * BitStream ����ʧ�ܡ�
 */
#define VM_BITSTREAM_FAILED                   				(-1)


/**
* ����������
*/
#define VM_BITSTREAM_BUFFER_OVERFLOW         1  		
/**
* �������ѿ�
*/
#define VM_BITSTREAM_BUFFER_UNDERFLOW         2 		
/**
* ΢������̫æ�޷�����Ƶ
*/
#define VM_BITSTREAM_RECOVER                   	3		
/**
* �ֱ��ʲ���
*/
#define VM_BITSTREAM_ERR_INVALID_RESOULTION  -2  		
/**
* ����ȷ�ı�����
*/
#define VM_BITSTREAM_ERR_INVALID_BITSTREAM     	-3	
/**
* �ڴ治��
*/
#define VM_BITSTREAM_ERR_MEMORY_INSUFFICIENT   	-4	


/**
 *	bitstream ��������
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
 *	H.264���ò���
 */
typedef struct
{
    VMUINT  timescale;	               			/*��Ƶ֡ʱ������ŵ�����*/
    VMINT is_ps_oob;                 			/*	
    										������FALSE (in-band) ��TRUE (out-of-band)
		                                        			��� is_ps_oob == TRUE ���������Ҫ����
		                                        			packetization_mode,
		                                        			profile_idc,
		                                        			level_idc,
		                                        			p_AVC_config_record
		                                        		*/
    VMUINT8   packetization_mode;	      /*  
    										H.264 �����ʽ, ����������������Ĭ��Ϊ0
                                        					0: ����NAL��ʽ.
                                        					1: �ǽ��淽ʽ.
                                        					2: ���淽ʽ. 
                                        				*/
    VMUINT8   profile_idc;               		/* ����ģʽ*/
    VMUINT8   level_idc;                 		/*  ����ȼ�  */
    VMUSTR  p_AVC_config_record;       /*ָ��AVC���ü�¼��ָ��*/
    VMUINT  AVC_config_record_size;    /*AVC���ü�¼�ĳߴ�*/
    vm_bitstream_codec_type_enum audio_type;   /*bitstream �����������ͣ�Ŀǰֻ֧��AMR*/
    VMUINT sampling_rate;                          /*��Ƶ������*/
    
} vm_bitstream_video_h264_cfg;

/* Video buffer status query struct */
typedef struct
{
    VMUINT buffer_duration;            /*��ǰ����������δ���ŵĺ����� */
    VMUINT percentage_used;            /*����ʹ�õİٷֱ�*/
    VMUINT free_space;                 /*������δʹ�õ��ֽ���*/
    VMUINT current_frame_count;        /*��ǰ����������δ���ŵ�֡��*/
    VMUINT required_frame_count;       /*��ʼ������Ƶ�����֡������Сֵ   */ 
} vm_bitstream_video_buffer_status;


typedef struct
{
    VMUINT ms_start_time;                /*��ʼ���ŵ�ʱ���*/
    VMUINT h_layer;                 		/*������Ƶ�Ĳ�����ĿǰVREֻ֧��2�㣬����ʹ�õ�һ�δ����㷵�ص�ֵ*/
    VMUINT base_layer;                 	/*���߲���,ĿǰVREֻ֧��2�㣬����ʹ�õڶ��δ����㷵�ص�ֵ*/
    VMUINT16 rotate;                         /*��ʾ������ת�Ƕ�*/
} vm_bitstream_video_start_param;


/**
 * ����vm_bitstream_video_open_handle�����Ļص���������
 *
 * @param handle			�򿪵�bitstream �����
 * @param result			���ؽ��
 * 		VM_BITSTREAM_BUFFER_OVERFLOW           		����������
 * 		VM_BITSTREAM_BUFFER_UNDERFLOW          		�������ѿ�
 *		VM_BITSTREAM_RECOVER                   			΢������̫æ�޷�����Ƶ
 *		VM_BITSTREAM_FAILED                			����
 *		VM_BITSTREAM_ERR_INVALID_RESOULTION    		�ֱ��ʲ���
 *		VM_BITSTREAM_ERR_INVALID_BITSTREAM     		����ȷ�ı�����
 *		VM_BITSTREAM_ERR_MEMORY_INSUFFICIENT   		�ڴ治��
 *
 * @return	
 */
typedef void (*vm_bitstream_video_result_callback)(VMINT handle, VMINT result);


/**
 *	��Ƶ���ýṹ��
 */
typedef struct
{ 
    vm_bitstream_codec_type_enum vm_codec_type;                                 
} vm_bitstream_audio_cfg_struct;

/**
 *	��Ƶ����ṹ��
 */
typedef struct
{
    VMUINT total_buf_size; 		/* ��Ƶ��������С (ring buffer)*/
    VMUINT free_buf_size;  	/* ��ǰ��Ƶ���л����С */
} vm_bitstream_audio_buffer_status;

typedef struct
{	
    VMUINT 	start_time; 			/* ������ʼʱ�� */
    VMUINT8 	volume;      			/* �������� */
    VMUINT8 	audio_path;  		/* ������������·�� */
} vm_bitstream_audio_start_param;

/**
 * ����vm_bitstream_audio_open_handle�����Ļص���������
 *
 * @param handle			�򿪵�bitstream �����
 * @param result			���ؽ��
 *
 * @return	����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
typedef void (*vm_bitstream_audio_result_callback)(VMINT handle, VMINT result);


/* ======================== BitStream Audio ============================= */

/**
 * BitStream Audio ����Ϊ��ռ��Դ����ͬһAPP ��Ҫ�򿪵ڶ���BitStream Audio ������ʧ�ܡ�
 * 
 * ������ռ����Ƶ��Դ�Ĺ��ܹ�ϵ��
 * ��Ƶ����ʹ��ʱ������ʹ�ñ����ܡ�
 * ¼������ʹ��ʱ�������� ��ֹͣ¼������ռ��Ƶ��Դ��
 * midi ���� ��ʹ��ʱ�������ܽ�ֹͣmidi����ռ��Ƶ��Դ��
 * audio ������ʹ��ʱ�������ܽ�ֹͣaudio����ռ��Ƶ��Դ��
 * 
 * ��ʵ������£�
 * ������APP ���л�����̨�������ⲿ�¼����ʱ �����ͱ��л�����̨��CallBack 
 * ��Ϣ��VRE ϵͳǿ����ֹ�����л�ǰ̨ʱ������CallBack ��Ϣ(����ǿ����ֹʱ
 * ����ֹʱ��)����λָ�����APP ������
 *
 * ��̨ʱ��
 * �����ܽ�����ʹ�á�
 */

/**
 * ��bitstream ��ʽ����Ƶ��Դ��
 *
 * @param handle			�򿪵�bitstream �����
 * @param audio_type		��Ƶ��Դ������(�������ָ�ʽΪAMR��AAC��MP3��������)��
 * @param result_callback	��Ƶ�ص�������
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_bitstream_audio_open(
	VMINT* handle,
	vm_bitstream_audio_cfg_struct *audio_type,
	vm_bitstream_audio_result_callback callback);

/**
 * �ر���bitstream ��ʽ�򿪵���Ƶ�ļ���
 *
 * @param handle			��vm_bitstream_audio_open �򿪵�bitstream �����
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_bitstream_audio_close(VMINT handle);

/**
 * ����bitstream �����ȡ��Ƶ����ṹ�塣
 *
 * @param handle			�򿪵�bitstream �����
 * @param status			�õ�����Ƶ����ṹ�塣
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_bitstream_audio_get_buffer_status(
	VMINT handle, 
	vm_bitstream_audio_buffer_status *status);

/**
 * ��ָ����С����Ƶ����д����Ƶ�������ڣ���ͨ������used_size ��֤��ʵд�����ݴ�С��
 *
 * @param handle			�򿪵�bitstream �����
 * @param buffer			��д����Ƶ���������ڴ��ַָ�롣
 * @param buffer_size		Ҫд��Ļ�����ֽ�����
 * @param used_size		ʵ��д�뻺����ֽ�����
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_bitstream_audio_put_data(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT 	buffer_size,
	VMUINT 	*written);

/**
 * ��ָ��ʱ�����Ƶ����д����Ƶ�������ڣ�������ݴ�С����������������ʧ�ܡ�
 *
 * @param handle			�򿪵�bitstream �����
 * @param buffer			��д����Ƶ������������ָ�롣
 * @param buffer_size		Ҫд��Ļ���Ĵ�С��
 * @param used_size		Ҫд�뻺�����Ƶʱ��(��λ������)��
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
 VMINT vm_bitstream_audio_put_frame(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT	buffer_size,
	VMUINT 	timestamp);

/**
 * ��ʼ����BitStream Audio ��Ƶ��
 *
 * @param handle			Ҫ���ŵ�bitstream �����
 * @param para			������Ƶʱ�����ṹ�塣
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_bitstream_audio_start(
	VMINT handle,
	vm_bitstream_audio_start_param *para);

/**
 * ֹͣ����BitStream Audio ��Ƶ��
 *
 * @param handle			Ҫֹͣ���ŵ�bitstream �����
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_bitstream_audio_stop(VMINT handle);

/**
 * ��ȡ��ǰ����ʱ�䡣
 *
 * @param handle			Ҫ��ȡ����ʱ���bitstream �����
 * @param current_time		��õĵ�ǰ����ʱ��(��λ������)
 *
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED Ϊʧ�ܡ�
 */
VMINT vm_bitstream_audio_get_play_time(
	VMINT handle,
	VMUINT* current_time);


/**
 * BitStream H.264 video ����Ϊ��ռ��Դ��һ����BitStream video�����Ǳ��رգ����������ٴδ� ��
 * 
 * Bitstream video�ӿ�ֻ�ܲ�����Ƶ���޷�ʹ���ⲿ�ֽӿڲ�����Ƶ�����貥����Ƶ��
 * �ɽ��Bitstream audio�ӿ�һ��ʹ��
 * 
 * ����Ƶ��Դ�Ĺ��ܹ�ϵ��
 * ��midi,mp3����Ƶ��Դ��ʱ����BitStream video�����ر���Ƶ��Դ(¼������)
 * 
 *
 * ��ʵ������£�
 * ͬʱֻ����һ��ʵ����BitStream video ���ڶ���ʵ�����ô򿪽ӿڻ᷵�ش���
 *
 * �е���̨ʱ��
 * ��Ӧ��ֹͣ���ţ��ͷ������Դ������¼��ǰ״̬�����е�ǰ̨ʱ�ָ����ָ�ʱ������������Դ��
 * ����е���̨��ֹͣ���ͷ���Դ��ϵͳ��ǿ�ƹرպ��ͷ���Դ������¼״̬��Ϣ��
 */


 /**
 * ��bitstream��Ƶ��
 *
 * @param handle			�򿪵�bitstream �������ָ�롣
 * @param cfg				h264���ýṹ��Ϣ��
 * @param callback		�ص�������								
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT vm_bitstream_video_open(
        VMINT* handle,
        vm_bitstream_video_h264_cfg* cfg,
        vm_bitstream_video_result_callback callback);


 /**
 * �ر�bitstream��Ƶ��
 *
 * @param handle			��رյ�bitstream �����							
 * @return						����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT vm_bitstream_video_close(VMINT handle);    


/**
 * �õ�������״̬��
 * @param handle			�򿪵�bitstream �����		
 * @param status			��仺������Ϣ�Ľṹ�����ָ�롣
 * @return						����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT vm_bitstream_video_get_buffer_status(VMINT handle, vm_bitstream_video_buffer_status* status);


 /**
 * ��仺������
 * @param handle				�򿪵�bitstream �����		
 * @param  buffer				��������Դ����ָ�롣		
 * @param buffer_size		����Դ�����С��
 * @param timestamp			ʱ���λ�á�
 * @return							����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT vm_bitstream_video_put_frame(VMINT handle, VMUSTR buffer, VMUINT buffer_size, VMUINT timestamp);


/**
 * ��ʼ����bitsteam��Ƶ��
 * @param handle			�򿪵�bitstream �����		
 * @param  para			���ŵĲ����ṹ�����ָ�룬��ӿ���Ҫ֪����ĵ���˳��
 *						����뱣֤ʹ��ǰ�ѽ��й�vm_graphic_flush_layer������������ܻ�����		
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT vm_bitstream_video_start(VMINT handle, vm_bitstream_video_start_param* para);



/**
 * ֹͣ����bitsteam��Ƶ,�����ٴβ��ţ���Ҫ�رգ������´򿪡�
 * @param handle			�򿪵�bitstream �����				
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT vm_bitstream_video_stop(VMINT handle);


/**
 * ��ѯ��Ŀǰ�Ĳ���ʱ�䡣
 * @param handle				�򿪵�bitstream �����	
 * @param ms_current_time		���ڴ�ŵõ��Ĳ���ʱ��ı���ָ�롣	
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT vm_bitstream_video_get_play_time(VMINT handle, VMUINT* ms_current_time);



 /**
 * ��ֹͣ�����״̬�¶��ݵĻ�����ͣ��������Ƶλ��/��С���л�
 * �˽ӿ�֧�ֺܶ�ʱ�����ͣ,�򾡿�ĵ���vm_bitstream_video_switchscreenstart�����ָ���
 * ����ʧ��
 * @param handle				�򿪵�bitstream �����	
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT vm_bitstream_video_switchscreenstop(VMINT handle);



 /**
 * ���ڻָ�vm_bitstream_video_switchscreenstop����Ļ�����ͣ
 * @param handle				�򿪵�bitstream �����
 * @param  para			���ò��ŵĲ����ṹ�����ָ�롣
 * @return				����VM_BITSTREAM_SUCCEED ��ʾ�ɹ���VM_BITSTREAM_FAILED����
 */
VMINT vm_bitstream_video_switchscreenstart(VMINT handle, vm_bitstream_video_start_param* p_para);



#ifdef __cplusplus
}
#endif

#endif
