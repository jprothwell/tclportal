/*****************************************************************************
 * ������Ƶ���Žӿ��ļ�
 * ���ݳ���ƽ̨�������֧�ָ�ʽ����֧����Ƶ��ʽ����:
 *   +-----------------------------------------------------------------------------------------------------+
 *   |					   	| MT6225				|	MT6226,MT6228,MT6238		|	MT6235
 *   +-----------------------------------------------------------------------------------------------------+
 *   | �ļ���ʽ      		| AVI				|	3GP,MP4						|	3GP,MP4/AVI
 *   +-----------------------------------------------------------------------------------------------------+
 *   | ��Ƶ�����ʽ        |Motion JPEG			|	MP4,3GP 						|	MP4,3GP/AVI 	
 *   +-----------------------------------------------------------------------------------------------------+
 *   | ��Ƶ�����ʽ        |PCM				|	AMR,AAC						|	AMR,AAC
 *   +-----------------------------------------------------------------------------------------------------+
 *
 *	����������
 *	1.  ���Žӿ�Ŀǰ���֧�����㣬ʹ��ǰ�贴������Դ������Ϊ�������룬
 *    �����һ�δ����Ĳ���Ϊ���Ų㣬�ڶ��δ����Ĳ���Ϊ���߲㣬������������˳����л����flush������
 *	һ��Ӧ�ñ��е���̨���뼰ʱֹͣ��Ƶ���ź��ͷŲ���Դ��
 *	����¼��ǰ����ʱ�������е�ǰ̨ʱ�ָ������Ӧ�ò���ô����
 *	ϵͳ��ǿ�ƹر���Ƶ���ͷ���Դ������¼�κ���Ϣ��
 *	
 *	2. ��Ƶ������Ƶԭ������Ƶ�ڲ��ţ�����Ƶʱ���ر���Ƶ(bitsteam audio����,bitsteam audioռ��ʱ������Ƶ�����ش���)��
 *	3. ����Ƶ��/���ţ��ٴδ�/������Ƶ�����ش���
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
 *	���سɹ���
 */
#define VM_VIDEO_SUCCESS    (0)
/**
 *	����ʧ�ܡ�
 */
#define VM_VIDEO_FAILED    (-1)


/**
 *	���ݲ���
 */
#define VM_VIDEO_PROGRESSIVE_FILE_NOT_ENOUGH   	-101




/**
 *	�ļ���ʧ�ܡ�
 */
#define VM_VIDEO_ERR_OPEN_FILE_FAILED           		-103

/**
 *	�ļ�̫��
 */
#define VM_VIDEO_ERR_FILE_TOO_LARGE             		-104

/**
 *	ץȡ����ʧ�ܡ�
 */
#define VM_VIDEO_ERR_SNAPSHOT_FAILED            		-105

/**
 *	����ʧ�ܡ�
 */
#define VM_VIDEO_ERR_PLAY_FAILED                		-106



/**
 *	����������ץͼʧ�ܡ�
 */
#define VM_VIDEO_ERR_SNAPSHOT_DISK_FULL         	-107

/**
 *	д������ץͼʧ�ܡ�
 */
#define VM_VIDEO_ERR_SNAPSHOT_WRITE_PROTECTION  -108

/**
 *	�ֱ��ʲ��ԡ�
 */
#define VM_VIDEO_ERR_INVALID_RESOULTION         	-109   

/**
 *	��ʽ��֧�֡�
 */
#define VM_VIDEO_ERR_UNSUPPORTED_FORMAT         	-110

/**
 *	�ڴ治�㡣
 */
#define VM_VIDEO_ERR_MEMORY_INSUFFICIENT        	-111

/**
 *	û�а�Ȩ��
 */
#define VM_VIDEO_ERR_DRM_PROHIBITED             		-112     

/**
 *	��Ȩ����ʹ�á�
 */
#define VM_VIDEO_ERR_DRM_DURATION_USED          	-113

/**
 *	֡��̫�ߡ�
 */
#define VM_VIDEO_ERR_FRAMERATE_TOO_HIGH         	-114



/**
 *	���ȱ� N4 ��һ�� ��
 */
#define VM_VIDEO_BRIGHTNESS_N5              0	
/**
 *	���ȱ� N3 ��һ�� ��
 */
#define VM_VIDEO_BRIGHTNESS_N4              1    
/**
 *	���ȱ� N2 ��һ�� ��
 */
#define VM_VIDEO_BRIGHTNESS_N3              2	
/**
 *	���ȱ� N1 ��һ�� ��
 */
#define VM_VIDEO_BRIGHTNESS_N2              3	
/**
 *	���ȱ� Ĭ������ ��һ����
 */
#define VM_VIDEO_BRIGHTNESS_N1              4		
/**
 *	Ĭ�����ȡ�
 */
#define VM_VIDEO_BRIGHTNESS_0                5  
/**
 *	���ȱ� Ĭ��������һ����
 */
#define VM_VIDEO_BRIGHTNESS_P1              6	
/**
 *	���ȱ� P1 ��һ����
 */
#define VM_VIDEO_BRIGHTNESS_P2              7	
/**
 *	���ȱ� P2 ��һ����
 */
#define VM_VIDEO_BRIGHTNESS_P3              8	
/**
 *	���ȱ� P3 ��һ����
 */
#define VM_VIDEO_BRIGHTNESS_P4              9	
/**
 *	���ȱ� P4 ��һ����
 */
#define VM_VIDEO_BRIGHTNESS_P5              10	


/**
 *	�Աȶȱ�N4��һ����
 */
#define VM_VIDEO_CONTRAST_N5                0	
/**
 *	�Աȶȱ�N3��һ����
 */
#define VM_VIDEO_CONTRAST_N4                1	
/**
 *	�Աȶȱ�N2��һ����
 */
#define VM_VIDEO_CONTRAST_N3                2	
/**
 *	�Աȶȱ�N1��һ����
 */
#define VM_VIDEO_CONTRAST_N2                3	
/**
 *	�Աȶȱ�Ĭ�ϵ�һ����
 */
#define VM_VIDEO_CONTRAST_N1                4	
/**
 *	Ĭ�϶Աȶȡ�
 */
#define VM_VIDEO_CONTRAST_0                 5	
/**
 *	�Աȶȱ�Ĭ�ϸ�һ����
 */
#define VM_VIDEO_CONTRAST_P1                6	
/**
 *	�Աȶȱ�P1��һ����
 */
#define VM_VIDEO_CONTRAST_P2                7	
/**
 *	�Աȶȱ�P2��һ����
 */
#define VM_VIDEO_CONTRAST_P3                8	
/**
 *	�Աȶȱ�P3��һ����
 */
#define VM_VIDEO_CONTRAST_P4                9	
/**
 *	�Աȶȱ�P4��һ����
 */
#define VM_VIDEO_CONTRAST_P5                10	


/**
 *	��ת0�� ��
 */
#define VM_VIDEO_LCD_ROTATE_0            0
/**
 *	��ת90�� ��
 */
#define VM_VIDEO_LCD_ROTATE_90           1
/**
 *	��ת180�� ��
 */
#define VM_VIDEO_LCD_ROTATE_180          2
/**
 *	��ת270�� ��
 */
#define VM_VIDEO_LCD_ROTATE_270          3

/**
 *	��Ƶ��/�ӹ켣���塣
 */
typedef enum
{
    VM_VIDEO_TRACK_NONE,   
    VM_VIDEO_TRACK_AV,     /* ��Ƶ�ļ�����Ƶ����Ƶ�켣 */
    VM_VIDEO_TRACK_A_ONLY, /* ��Ƶ�ļ�ֻ����Ƶ�켣  */
    VM_VIDEO_TRACK_V_ONLY /* ��Ƶ�ļ�ֻ����Ƶ�켣 */
} vm_video_track_enum;


/**
 *	��Ƶ������Ϣbuffer ���ȶ��壬UCS2���㣬�80���ַ���
 */
#define VM_VIDEO_MAX_CONTENT_INFO_LEN   80


/**
 *	��Ƶ��Ϣ�ṹ��
 */
typedef struct
{
    VMUINT16 width;                      /* ��Ƶ���  */
    VMUINT16 height;                     /* ��Ƶ�߶�  */
    VMUINT32 total_frame_count;          /* ��Ƶ����֡��  */
    VMUINT64 total_time_duration;        /* �ܲ���ʱ��  */
    vm_video_track_enum track;     
    VMINT handle;              /* ��Ƶ�ļ���� */
    VMINT is_seekable;           /* �Ƿ�ɶ�λ */
    VMUINT8 aud_channel_no;              /* ��Ƶͨ����  */
    VMUINT16 aud_sample_rate;            /* ��Ƶ������  */

    VMINT is_drm_streaming;      /* �Ƿ� ���ְ�Ȩ�����ļ�  */
    VMUINT drm_handle;                 /* ���ְ�Ȩ�����ļ���� */

    VMWCHAR title_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];       /* ������Ϣ  */
    VMWCHAR artist_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];      /* ��������Ϣ  */
    VMWCHAR album_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];       /* ר�� ��Ϣ  */
    VMWCHAR author_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];      /* ������Ϣ  */
    VMWCHAR copyright_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];   /* ��Ȩ��Ϣ  */
    VMWCHAR date_desc[VM_VIDEO_MAX_CONTENT_INFO_LEN+1];        /* ����  */
} vm_video_info_struct;





 /**
 *	ʹ�ú���vm_video_open_file����Ƶ�ļ�ʱ	��
 *	���д������������ʱ������������͵ĺ�����
 *	@param ret			���ؽ��: >=0��ʾ�ɹ���<0 ʧ�ܡ�
 *    @param video_info			��Ƶ�ļ�����Ϣ���ɹ���ʱ���������ṹ�塣
 *	@return 			
 */
typedef void (*vm_video_open_result_callback)(VMINT ret, vm_video_info_struct *video_info);


  /**
 *	ʹ�ú���vm_video_play����Ƶ�ļ���
 *	���д���������������ʱ������������͵ĺ�����
 *	@param ret			���ؽ��: >=0��ʾ�ɹ���<0 ʧ�ܡ�
 *	@return 			
 */
typedef void (*vm_video_finish_callback) (VMINT ret);



 /**
 *	����Ƶ�ļ�	
 *	@param filename			����·�����ļ�����
 *    @param open_result_callback	�ص�������
 *	@return 			
 *  		VM_VIDEO_SUCCESS : ���ļ��ɹ���
 *  		VM_VIDEO_ERR_DRM_PROHIBITED : ���ܴ���Ƶ�ļ���drm����ֹ��
 *  		VM_VIDEO_ERR_MEMORY_INSUFFICIENT : ���ܴ���Ƶ���ڴ治�㡣
 *  		VM_VIDEO_ERR_FILE_TOO_LARGE : ���ܴ���Ƶ���ļ�̫��
 *  		VM_VIDEO_ERR_FRAMERATE_TOO_HIGH : ���ܴ���Ƶ��֡��̫�ߡ�
 *		VM_VIDEO_ERR_INVALID_RESOULTION: ���ܴ���Ƶ��ֱ��ʲ��ԡ� 
 *  		VM_VIDEO_ERR_OPEN_FILE_FAILED : ����ԭ���ܴ���Ƶ��
 */
 VMINT vm_video_open_file(
                    const VMWSTR filename,
                    vm_video_open_result_callback open_result_callback);


 /**
 *	�ر���Ƶ�ļ���	
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ر��ļ��ɹ���
 *  		VM_VIDEO_FAILED : �ر��ļ�ʧ�ܡ�
 */
 VMINT vm_video_close_file(void);


 /**
 *	ʹ��ָ���������ݴ���Ƶ��
 *    @param buffer	��Ƶ��������ָ�롣
 *    @param buffer_len	���泤�ȡ�
 *    @param info		�õ�����Ƶ��Ϣ�ṹ��
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �򿪳ɹ���
 *  		VM_VIDEO_ERR_MEMORY_INSUFFICIENT : û���㹻�ڴ��ʧ�ܡ�
 *  		VM_VIDEO_ERR_FRAMERATE_TOO_HIGH : ֡��̫�ߴ�ʧ�ܡ�
 *  		VM_VIDEO_ERR_OPEN_FILE_FAILED : ��ʧ�ܡ�
 */
  VMINT vm_video_open_buffer(
                    const VMUSTR buffer,
                    const VMUINT buffer_len,
                    vm_video_info_struct *info);
 
                    
 /**
 *	�ر���Ƶ�������ݣ���vm_video_open_buffer�ɶ�ʹ�á�
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ر��ļ��ɹ���
 *  		VM_VIDEO_FAILED : �ر��ļ�ʧ�ܡ�
 */
 VMINT vm_video_close_buffer(void);


 /**
 *	������Ƶ������ƽ̨����֧��3gp/mp4��������ǰ����й�seek������
 *    ���Žӿ���Ҫ֪����ĵ���˳������뱣֤ʹ��ǰ�ѽ��й�vm_graphic_flush_layer������������ܻ�����
 *    @param player_layer_handle		���Ų�ľ��������ʹ�õ�һ�δ�����ʱ���صľ������
 *   @param base_layer_handle		���߲�ľ��������ʹ�õڶ��δ�����ʱ���صľ������
 *    @param repeat_count			�ظ����Ŵ�����0��ʾ�ظ����š�
 *    @param is_play_audio			�Ƿ񲥷���Ƶ��TRUE/FALSE ����
 *    @param audio_path			��Ƶ����·����ʹ��vmmm.h�ж��壬��VM_DEVICE_SPEAKER2����
 *    @param play_finish_callback		�ص�������
 *	@return 			
 *  		VM_VIDEO_SUCCESS : ��ʼ���ųɹ���
 *  		VM_VIDEO_ERR_DRM_PROHIBITED :�����ְ�Ȩ���ܴ���Ƶ�ļ���
 *  		VM_VIDEO_PROGRESSIVE_FILE_NOT_ENOUGH : ���ݲ������������š�
 *  		VM_VIDEO_ERR_PLAY_FAILED : ����ʧ�ܡ�
 */
 VMINT vm_video_play(
                    VMUINT player_layer_handle,
                    VMUINT base_layer_handle,
                    VMUINT16 repeat_count, 
                    VMINT is_play_audio,
                    VMINT audio_path, 
                    vm_video_finish_callback play_finish_callback);


/**
 *	 ֹͣ���š�
 *	@return 			
 *  		VM_VIDEO_SUCCESS : ֹͣ�ɹ���
 *			VM_VIDEO_FAILED : ֹͣʧ�ܡ�
 */
 VMINT vm_video_stop(void);


 /**
 *	��ͣ���š�
 *	@return
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *			VM_VIDEO_FAILED : 	ʧ�ܡ�
 */
VMINT vm_video_pause(void);


 /**
 *	  ��������
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *			VM_VIDEO_FAILED : 	ʧ�ܡ�
 */
VMINT vm_video_resume(void);


 /**
 *	��λ��Ƶ��ָ��ʱ�����һ֡����ˢ�½��������ʾ����
 *    @param time		ʱ�� �����룩��
 *    @param player_layer_handle		���Ų�����
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
 VMINT vm_video_seek_and_getframe(VMUINT64 time, VMUINT player_layer_handle);


 /**
 *	ץͼ����Ϊָ�����ļ����ļ���ʽJPEG(ֻ��Ӳ������Ļ�������Ч������뽫����VM_VIDEO_ERR_SNAPSHOT_FAILED)��
 *    @param player_layer_handle		���Ų�����
 *    @param file_name			������ļ���(UCS2)��
 *	@return 			
 *  		VM_VIDEO_SUCCESS : ץͼ�ɹ���
 *  		VM_VIDEO_ERR_SNAPSHOT_DISK_FULL : ����������ץͼʧ�ܡ�
 *  		VM_VIDEO_ERR_SNAPSHOT_WRITE_PROTECTION : д������ץͼʧ�ܡ�
 * 		VM_VIDEO_ERR_SNAPSHOT_FAILED : ץͼʧ�ܡ�
 */
 VMINT vm_video_snapshot(VMUINT player_layer_handle, VMWSTR file_name);



 /**
 *	�������ȣ��رպ󲻱��棬ֻ���ڴ�״̬�����ã����Ź���������ֵֻ���´β���ʱ��Ч��
 *	ֻ��Ӳ������Ļ�������Ч������뽫����VM_VIDEO_FAILED ��
 *    @param brightness			����ֵ����:VM_VIDEO_BRIGHTNESS_0 ����
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
 VMINT vm_video_set_brightness(VMUINT16 brightness);


 /**
 *	 ���öԱȶȣ��رպ󲻱��棬ֻ���ڴ�״̬�����ã����Ź���������ֵֻ���´β���ʱ��Ч��
 *	ֻ��Ӳ������Ļ�������Ч������뽫����VM_VIDEO_FAILED ��
 *    @param contrast			�Աȶ�ֵ(��:VM_VIDEO_CONTRAST_0)��
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
 VMINT vm_video_set_contrast(VMUINT16 contrast);



 /**
 *	 �õ�Ŀǰ�Ĳ���ʱ�䡣
 *    @param cur_play_time			���ȡ�Ĳ���ʱ�����ָ�롣 
 *	@return 			
 *  		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
 VMINT vm_video_get_cur_play_time(VMUINT64 *cur_play_time); 


 /**
 *	����URL ������ý����Ƶ(���ѵ��õ�VREAPP �е���̨���¿�SCREEN ����MTK ����Ƶ������)��
 *    @param url			Ҫ�򿪵���ƵURL��
 *
 *	@return
 *		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
VMINT vm_video_play_stream_from_rtsp_link(VMWSTR url);
	
/**
 *	��sdp ��ʽ����ý����Ƶ�ļ�(���ѵ��õ�VREAPP �е���̨���¿�SCREEN ����MTK ����Ƶ������)��
 *    @param filename		��sdp ��ʽ���ļ���
 *	@param is_short		�Ƿ�Ϊ8.3 ��ʽ�Ķ��ļ�����TUREΪ�ǣ�FALSEΪ��	
 *
 *	@return
 *		VM_VIDEO_SUCCESS : �ɹ���
 *		VM_VIDEO_FAILED :ʧ�ܡ�
 */
VMINT vm_video_play_stream_from_sdp_file(VMWSTR filename, VMUCHAR is_short);

#ifdef __cplusplus
}
#endif

#endif
