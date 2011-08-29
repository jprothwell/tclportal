#ifndef VMCAMERA_H_
#define VMCAMERA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 *  ����ͷ�ľ������.
 */
typedef VMINT VM_CAMERA_HANDLE;

/**
 * �ֻ�������ͷ��ID��.
 */
typedef enum 
{
	VM_CAMERA_MAIN_ID = 1,		/**<�ֻ��ϵ�������ͷID. 					*/
	VM_CAMERA_SUB_ID				/**<�ֻ��ϵĸ�����ͷID,һ����������. */
}VM_CAMERA_ID;

/**
 * ����ͷ�ڲ�ͬ�����µ��첽��Ϣ,������ͷ�ĸ���״̬����
 * ����Ĳ���Ҳ�ǲ�ͬ��.
 */
typedef enum
{
	VM_CAM_PREVIEW_START_DONE = 1,		/**<����ͷ��ʼpreview �ɹ�.							*/
	VM_CAM_PREVIEW_START_ABORT,			/**<����ͷ��ʼpreview ʧ��.							*/
	VM_CAM_PREVIEW_STOP_DONE,			/**<����ͷֹͣpreview �ɹ�.							*/
	VM_CAM_PREVIEW_STOP_ABORT,			/**<����ͷֹͣpreview ʧ��.							*/
	VM_CAM_PREVIEW_FRAME_RECEIVED,		/**<����ͷ��preview״̬�������֡ͼ��
												���������Ϣ���ᱻ�͵��ͻ�����. 		*/
	VM_CAM_CAPTURE_DONE,					/**<����ͷ���ճɹ�.									*/
	VM_CAM_CAPTURE_ABORT				/**<����ͷ����ʧ��.									*/
}VM_CAMERA_MESSAGE;

/**
 * ����ͷ��״̬,���VM_CAMERA_MESSAGE����������״̬ͼ����.
 * @code
 * VM_CAM_READY_STATUS      VM_CAM_STARTING_PREVIEW_STATUS      VM_CAM_PREVIEW_STATUS      VM_CAM_STOPPING_PREVIEW_STATUS      VM_CAM_CAPTURING_STATUS
 *			| vm_camera_preview_start		                                                                                     			
 *			------------------------------->								
 *											|VM_CAM_PREVIEW_START_DONE																				 
 *											-------------------------------->																
 *											|								|																
 *				VM_CAM_PREVIEW_START_ABORT	|								|																
 *			<--------------------------------								|vm_camera_preview_stop													 							 
 *			|																------------------------------->													 
 *			|																|	VM_CAM_PREVIEW_STOP_ABORT	|														 
 *			|																<-------------------------------													 
 *			|	 																							|								
 *			|																	VM_CAM_PREVIEW_STOP_DONE	|				 				
 *			<------------------------------------------------------------------------------------------------												 
 *			|								 								|								 			 					
 *			|																|vm_camera_capture											
 *			|								 								--------------------------------------------------------------->
 *			|																			 VM_CAM_CAPTURE_DONE/VM_CAM_CAPTURE_ABORT			|
 *			<-------------------------------------------------------------------------------------------------------------------------------
 *			|vm_camera_capture																												|
 *			------------------------------------------------------------------------------------------------------------------------------->
 *			|																			VM_CAM_CAPTURE_DONE/VM_CAM_CAPTURE_ABORT			|
 *			<-------------------------------------------------------------------------------------------------------------------------------
 * @endcode
 */
typedef enum
{
	VM_CAM_READY_STATUS = 1,				/**<�ɹ���������ͷʵ�����״̬. 	*/
	VM_CAM_STARTING_PREVIEW_STATUS,	/**<������������ͷԤ����״̬. 		*/
	VM_CAM_STOPPING_PREVIEW_STATUS,	/**<����ֹͣ����ͷԤ����״̬. 		*/
	VM_CAM_PREVIEW_STATUS,				/**<����Ԥ����״̬. 						*/
	VM_CAM_CAPTURING_STATUS				/**<��������״̬. 						*/
}VM_CAMERA_STATUS;


/**
 * @name ����ͷ���������ķ���ֵ
 * @{
 */
/**
  * �����ɹ�.
  */
#define VM_CAM_SUCCESS								(0)
/**
  * û���㹻���ڴ�.
  */
#define VM_CAM_ERR_NOMEMORY						(-1)
/**
  * ����ͷ�ڸ�״̬�²�����������.
  */
#define VM_CAM_ERR_OPERATE_BAD_STATUS			(-2)
/**
  * ����Ĳ���ֵ.
  */
#define VM_CAM_ERR_BAD_PARAM						(-3)
/**
  * �Ƿ�������ͷ���.
  */
#define VM_CAM_ERR_INVALID_CAM_HANDLE			(-4)
/**
  * ��VRE�İ汾����֧�ָò���.
  */
#define VM_CAM_ERR_UNSUPPORT_OPERATION			(-5)
/**
  * �ظ���������ͷʵ��.
  */
#define VM_CAM_ERR_CAM_INSTANCE_CREATED			(-6)
/**
  * ������ͷʵ����û��ע��ص�.
  */
#define VM_CAM_ERR_NOT_REGISTER_NOTIFY			(-7)
/**
 * ���������ͷID��.
 */
#define VM_CAM_ERR_INVALID_CAM_ID				(-8)
/**
  * ����ͷ���ڲ�����.
  */
#define VM_CAM_ERR_CAM_INTERNAL_ERROR			(-9)
/**
 * ��ǰƽ̨��֧������ͷ����.
 */
#define VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE	(-10)
/**
 * �����VRE (3.0)���Ժ�汾�����Ӧ�ó����ڷ�
 * ǰ̨����״̬�µ���������ͷ��ĳЩ������
 * ��ô�������뽫�ᱻ���ء�
 */
#define VM_CAM_OPERATION_IN_PROCESS_STATUS		(-11)
/** @} */

/**
 * ��������ͷʵ��,�õ�����ͷ�ľ��.�þ������
 * ������ͷ�ĸ��ֲ���.�������������
 * #VM_CAM_SUCCESS���ʾ����ͷ����Ѿ���д
 * �����handle_ptr��ָ����ڴ��ַ��,����ͷҲ�Ѿ���
 * �ھ���״̬. ��������#vm_release_camera_instance��Ӧ,�ڵ���
 * ����������������˳�����Ҫ��������ͷ��Ӧ��
 * ����#vm_release_camera_instance����.
 *
 * @param[in] 			camera_id ����ͷID.
 * @param[out] 			handle_ptr ָ������ͷ�����ָ��.			
 * @return				�Ƿ񴴽�����ͷ�ɹ����ķ���ֵ.
 * @retval				VM_CAM_SUCCESS �ɹ�.
 * @retval				VM_CAM_ERR_NOMEMORY �ڴ治��.
 * @retval				VM_CAM_ERR_INVALID_CAM_ID ���������ͷID.
 * @retval				VM_CAM_ERR_CAM_INSTANCE_CREATED ������ͷID����������ͷʵ���Ѿ�������.
 * @retval				VM_CAM_ERR_BAD_PARAM ����Ĳ���,handle_ptr����ΪNULL.
 * @retval				VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *						���������ᱻ����.
 * @retval				VM_CAM_OPERATION_IN_PROCESS_STATUS ���VRE 3.0���Ժ�汾���ͻ�������BackGround״̬�µ���
 *						��������ô���������ᱻ���ء�
 * @see					vm_release_camera_instance
 */
VMINT vm_create_camera_instance(VM_CAMERA_ID camera_id, 
	VM_CAMERA_HANDLE* handle_ptr);

/**
 * �ͷ�����ͷʵ��.
 * 
 * @param[in]				handle ����ͷ���,�þ������
 *						#vm_create_camera_instance����������.
 * @return				�����Ƿ�ɹ��ͷ�����ͷ��������.
 * @retval				VM_CAM_SUCCESS ��ʾ�ͷųɹ�.
 * @retval				VM_CAM_ERR_OPERATE_BAD_STATUS ��ʾ��ǰ������ͷ
 *						��״̬�������ͷ�.
 * @retval				VM_CAM_ERR_INVALID_CAM_HANDLE �Ƿ�������ͷ���.
 * @retval				VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *						���������ᱻ����. 
 *						�Ż᷵�ظ�Ӧ�ó���
 * @note					������#vm_create_camera_instance����������ͷʵ����
 *						,���˳�����ǰ������ñ������ͷŵ�����ͷ
 *						ʵ��.
 * @see					vm_create_camera_instance
 */
VMINT vm_release_camera_instance(VM_CAMERA_HANDLE handle);

/**
 * �õ�����ͷ��ǰ��״̬,���κ�״̬�¶����Ե��ñ�����.
 * 
 * @param[in]				handle ����ͷ���.
 * @param[out]			cam_status ����ͷ��״ָ̬��.
 * @return				�õ�����ͷ״̬�Ƿ�ɹ�.
 * @retval				VM_CAM_SUCCESS �ɹ�.
 * @retval				VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval				VM_CAM_ERR_BAD_PARAM ����Ĳ���.
 * @retval				VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *						���������ᱻ����.
 * @retval				VM_CAM_OPERATION_IN_PROCESS_STATUS �������Ӧ�ó��򴴽�������ͷ�����
 *						��ô�����󽫻ᱻ���ء�
 *						
 */
VMINT vm_get_camera_status(VM_CAMERA_HANDLE handle, VM_CAMERA_STATUS* cam_status);

/**
 * ֡ͼ����һ�����صĸ�ʽ.
 */
typedef enum
{
	PIXTEL_RGB565 = 1,					/**<PIXTEL_RGB565��ʽ,��λΪ��ɫ(RED),��λΪ��ɫ(BLUE), һ������ռ2�ֽ�. 		*/
	PIXTEL_BGR565,						/**<PIXTEL_BGR565��ʽ,��λΪ��ɫ(BLUE),��λΪ��ɫ(RED), һ������ռ2�ֽ�. 		*/
	PIXTEL_RGB888,						/**<PIXTEL_RGB888��ʽ,��λΪ��ɫ(RED),��λΪ��ɫ(BLUE), һ������ռ3�ֽ�. 		*/
	PIXTEL_BGR888,						/**<PIXTEL_BGR565��ʽ,��λΪ��ɫ(BLUE),��λΪ��ɫ(RED), һ������ռ3�ֽ�. 		*/
	PIXTEL_ARGB8888,					/**<PIXTEL_ARGB8888��ʽ,��λalpha(alpahͨ��),��λΪ��ɫ(BLUE), һ������ռ4�ֽ�. 	*/
	PIXTEL_ABGR8888					/**<PIXTEL_ABGR8888��ʽ,��λalpha(alpahͨ��),��λΪ��ɫ(RED), һ������ռ4�ֽ�. 		*/
}PIXTEL_FORMAT_T;

/**
  * @struct ����ͷԤ��������֡
  * @brief ����ͷ��Ԥ��ʱ���֡ͼ��,�����#vm_camera_preview_start �����Ĳ���is_direct_display_on_screen����ΪTRUE,��ô��������֡����Ϣ�ص�.
  */
typedef struct vm_cam_frame_data_t
{
	VMUINT 				row_pixel;				/**<ÿ�е����ظ���. 								*/
	VMUINT 				col_pixel;				/**<ÿ�е����ظ���. 								*/ 
	PIXTEL_FORMAT_T 	pixtel_format;			/**<���ظ�ʽ,��alpha��rgb�ĸߵ�λ˳��, Ҳ
													��	���еõ�ÿ��������ռ���ֽ���.	*/
	void* 				pixtel_data;				/**<��������. 										*/
	VMINT				reserved;				/**<�����ֶ�. 										*/
}vm_cam_frame_data_t;

/**
 * @struct ����ͷ��������������
 * @brief ����ͷ����������,�����ݿ������յ�VM_CAM_CAPTURE_DONE�����#vm_camera_get_capture_data�����õ�.
 */
typedef struct vm_cam_capture_data_t
{
	VMCHAR 				mime_type[32];			/**<���ݵ�media������. 		*/
	VMUINT8*			data;					/**<����. 							*/
	VMUINT				data_size;				/**<���ݵ��ֽڳ���. 			*/
	VMINT				reserved;				/**<�����ֶ�. 					*/
}vm_cam_capture_data_t;

/**
 * @struct vm_cam_notify_data_t
 * @brief 
 * �ͻ�����ע�������Ļص�����������ܵĲ�����ָ������ݽṹ.
 * �����ݽṹ������������ͷ	��״̬����������ص�����. �ͻ�����
 * ���ڸ����ݽṹ��Ӧ����ֻ����.
 */
typedef struct vm_cam_notify_data_t
{
	VM_CAMERA_HANDLE 		handle;					/**<����ͷʵ�����.  							*/
	VM_CAMERA_MESSAGE 	cam_message;			/**<����ͷ��Ϣ.									*/
	VM_CAMERA_STATUS 		cam_status;				/**<����ͷ��ǰ����״̬. 						*/
}vm_cam_notify_data_t;

/**
 * ����ͷ�û�ע�������Ļص�����.
 */
typedef void (*VM_CAMERA_STATUS_NOTIFY)(const vm_cam_notify_data_t* notify_data, void* user_data);

/**
 * ע��ص�����,�ú�������VM_CAMERA_MESSAGE��Ϣʱ����ϵͳ�ص�.
 * 
 * @param[in]					handle ����ͷ���.
 * @param[in]					notify_callback �ص�����.
 * @param[in]					user_data �û�����,��ÿ��ϵͳ�ص�ʱ��Ϊ��������,ϵͳ�����޸ĸ����ݡ��������Ҫ����ò�������ΪNULL��
 * @return 					�Ƿ�ע��ɹ��������.
 * @retval 					VM_CAM_SUCCESS ע��ɹ�.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval					VM_CAM_ERR_BAD_PARAM ����Ĳ���,�������notify_callbackΪNULL,
 *							��ô�ô��󽫻ᱻ����.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *							���������ᱻ����.
 * @note						��������ͷ����Ϣ��ȫ���첽��,�����ڵ�����������ͷ���
 *							�ĺ���ǰ��Ӧ����ע��ص�����,������ܷ���VM_CAM_ERR_NOT_REGISTER_NOTIFY
 *							����.
 */
VMINT vm_camera_register_notify(VM_CAMERA_HANDLE handle, VM_CAMERA_STATUS_NOTIFY notify_callback, void* user_data);

/**
  * @struct vm_cam_size
  * @brief ����ͷ�ߴ�����ݽṹ.
  */
typedef struct vm_cam_size_t
{
	VMUINT width;				/**<��� */
	VMUINT height;				/**<�߶� */
}vm_cam_size_t;

/**
 * �õ�ϵͳ֧�ֵ�����ͷԤ���ĸ�����ϵĿ�͸�.
 *
 * @code
 * void app_set_preview_size(void)
 * {
 *	vm_cam_size_t* ptr = NULL;
 *	VMUINT size = 0, i = 0;
 * 	if (vm_camera_get_support_preview_size(camera_handle, &ptr, &size) == VM_CAM_SUCCESS)
 *	{
 *		vm_cam_size_t my_cam_size;
 *
 *		// ��������֧�ֵĳߴ磬�����������һ��֧�ֵĳߴ硣
 *		for (i = 0; i < size; i++)
 *		{
 *			my_cam_size.width  = (ptr + i)->width;
 *			my_cam_size.height =(ptr + i) ->height;
 *		}
 *		vm_camera_set_preview_size(camera_handle, &my_cam_size);
 *	}
 * }
 * @endcode
 * @param[in]						handle ����ͷ���.
 * @param[out]					cam_size_list �ߴ������ͷָ�룬���������Ҫ����vm_camera_set_preview_size
 *								���������óߴ磬��ô��Ҫ�ѱ��������ĳ��Ԫ�ؿ�����Ӧ�ó����
 *								���ڴ�ռ��С�
 * @param[out]					list_size �ߴ������Ԫ�ظ���.
 * @return						�Ƿ�ɹ�ִ���˱�����.
 * @retval						VM_CAM_SUCCESS �ɹ�ִ�в���.
 * @retval						VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ�����
 * @retval						VM_CAM_ERR_BAD_PARAM ��������.
 * @retval						VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *								���������ᱻ����.
 * @see							vm_camera_set_preview_size
 */ 
VMINT vm_camera_get_support_preview_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t** cam_size_list, VMUINT* list_size);

/**
 * ��������ͷԤ���ĳߴ�,��λΪ����.ֻ����VM_CAM_READY_STATUS״̬�²��ܵ���
 * ������. ���������Ԥ���ĳߴ���Ĭ��ΪMAIN LCD ͬ���Ŀ�Ⱥ͸߶ȡ�
 * 
 * @param[in] 					handle ����ͷ���.
 * @param[in]					preview_size ����ͷԤ���ĳߴ硣
 * @return						�Ƿ�ɹ�����Ԥ��֡�ߴ�ķ���ֵ.
 * @retval						VM_CAM_SUCCESS ���óɹ�.
 * @retval						VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval						VM_CAM_ERR_BAD_PARAM ����Ĳ���,�����������
 *								preview_size ΪNULL��preview_size�����õĿ�͸ߵ���ϲ�֧��,
 *								��ô����뽫�ᱻ����.
 * @retval						VM_CAM_ERR_OPERATE_BAD_STATUS �ڴ���״̬�µ����˱�����.
 * @retval						VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *								���������ᱻ����.
 * @note							���õ�Ԥ���ߴ�Ӧ���ǵ���vm_camera_get_support_preview_size���ص�ĳ
 *								���ߴ�.
 * @see							vm_camera_get_support_preview_size
 */
VMINT vm_camera_set_preview_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t* preview_size);

/**
 * ������Ԥ��ʱ���֡��,��Ԥ��ʱ���֧��ÿ�� 30֡.
 * �����ܱȽϲ�������ֻ�ƽ̨�Ͽ���С��ÿ��30֡.
 * ������ֻ����VM_CAM_READY_STATUS ״̬������. ���û������
 * ����ͷԤ��ʱ���֡����ô������ƽ̨���֧�ֵ�
 * ֡��������Ԥ��.
 * 
 * @param[in]					handle ����ͷ���.
 * @param[in]					fps ÿ��֡��,�������30,��VREϵͳ����
 * 								ǿ�ư�֡������Ϊ30.
 * @return						
 * @retval						VM_CAM_SUCCESS ���óɹ�.
 * @retval						VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval						VM_CAM_ERR_BAD_PARAM ���fps Ϊ0��ô�������뽫��
 *								������.
 * @retval						VM_CAM_ERR_OPERATE_BAD_STATUS ����ڷ�VM_CAM_READY_STATUS����
 *								����������õ���������.
 * @see							vm_camera_preview_start
 */
VMINT vm_camera_set_preview_fps(VM_CAMERA_HANDLE handle, VMUINT fps);

/**
 * ����Ԥ��,ֻ����VM_CAM_READY_STATUS�µ��øú���.�����Ҫ��������ͷ��Ԥ
 * ��,��ô������Ӧ�ó����йرն��,������������ͷԤ����������ʧ��.
 * 
 * @param[in]					handle ����ͷ���.
 * @return					�Ƿ�ɹ�����Ԥ���ķ���ֵ.
 * @retval					VM_CAM_SUCCESS ���ܿ�ʼ�����Ĳ���,������������ͷ,����ͷ����
 *							VM_CAM_STARTING_PREVIEW_STATUS״̬.
 * @retval					VM_CAM_ERR_NOMEMORY û���㹻���ڴ�ռ�����Ԥ��.
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS �ڴ����״̬����������ͷԤ��.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷԤ�����.
 * @retval					VM_CAM_ERR_NOT_REGISTER_NOTIFY �����û��ע��ص������͵��ñ�����,
 *							��ô�ô��󽫻ᱻ����.
 * @retval					VM_CAM_OPERATION_IN_PROCESS_STATUS
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *							���������ᱻ����.
 * @see						vm_camera_preview_stop
 * @see						vm_camera_set_preview_size
 * @see						vm_camera_set_preview_fps
 */
VMINT vm_camera_preview_start(VM_CAMERA_HANDLE handle);
 
/**
 * ֹͣ����ͷ��Ԥ��, ֻ����VM_CAM_PREVIEW_STATUS״̬��VM_CAM_STARTING_PREVIEW_STATUS
 * ״̬�µ��ñ�����.
 * 
 * @param[in]					handle ����ͷ���.
 * @return					�Ƿ�ʼֹͣ����ͷԤ���ķ���ֵ.
 * @retval 					VM_CAM_SUCCESS ����ֹͣ����ͷԤ���Ĳ���,����ͷ����VM_CAM_STOPPING_PREVIEW_STATUS
 *							״̬.
 * @retval 					VM_CAM_ERR_OPERATE_BAD_STATUS �ڴ����״̬�µ����˱�����.
 * @retval 					VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval					VM_CAM_ERR_NOT_REGISTER_NOTIFY �����û��ע��ص������͵��ñ�����,
 *							��ô�ô��󽫻ᱻ����.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *							���������ᱻ����.
 * @see						vm_camera_preview_start
 */
VMINT vm_camera_preview_stop(VM_CAMERA_HANDLE handle);

/**
 * �õ�����ͷ��Ԥ������,ֻ���յ�VM_CAM_PREVIEW_FRAME_RECEIVED
 * ��Ϣ��ʱ����ñ��������ܵõ�Ԥ������֡. ������ʾ������.
 * @code
 * void cam_message_callback(vm_cam_notify_data_t* notify_data, void* user_data)
 * {
 * 	if (notify_data != NULL)
 *    {
 *		vm_cam_frame_data_t frame;
 *		
 *		switch (notify_data->cam_message)
 *		{
 *		case VM_CAM_PREVIEW_SOPT_DONE:
 *			// Ԥ���Ѿ�ֹͣ���߼�.
 *			break;
 *		case VM_CAM_PREVIEW_FRAME_RECEIVED:
 *			if (vm_camera_get_frame(cam_handle, &frame) == VM_CAM_SUCCESS)
 *			{
 *				// �õ�Ԥ����֡ͼ����߼�,���Ӧ�ó���
 *				// ��Ҫ�ڳ��˻ص����������õ���֡����.
 *				// ��ô��Ҫ������Ӧ�ó�����ڴ���ȥ,����
 *				// ���˱������ķ�Χ,frame.pixtel_data���ڴ����ݽ�
 *				// �ᱻ�ͷŵ�.���µ�������ʾ�˿����Ķ���.
 *				VMUINT app_frame_data_size = 0;
 *				VMUINT8* app_frame_data = NULL;
 *				
 *				if (frame.pixtel_format == PIXTEL_RGB565 || frame.pixtel_format == PIXTEL_BGR565)
 *					app_frame_data_size = row_pixel * col_pixel * 2;
 *				else if (frame.pixtel_format == PIXTEL_RGB888 || frame.pixtel_format == PIXTEL_BGR888)
 *					app_frame_data_size = row_pixel * col_pixel * 3;
 *				else
 *					app_frame_data_size = row_pixel * col_pixel * 4;
 *
 *				if ((app_frame_data = vm_malloc(app_frame_data_size)) != NULL)
 *				{
 *					memcpy(app_frame_data, frame.pixtel_data, app_frame_data_size);
 *				}
 *				else
 *				{
 *					// �ڴ治��, ������������ֻ��Ҫ��preview������
 *					// ͼ��ˢ����Ļ��,����԰����µ�α�������.
 *					// if (frame.rgbformat == ��Ļ�������ĸ�ʽ)
 *					// {
 *					//     copy frame.pixtel_data to screen buffer;
 *					//     flush screen buffer;
 *					//  }
 *				}
 *				
 *			}
 *			break;
 *		case ......
 *    		}
 *	}
 * }
 * @endcode
 * @param[in]					handle ����ͷ���.
 * @param[out]				frame_data ����֡,ֻ���ڷ���VM_CAM_SUCCESS�²ŵõ���
 *							Ԥ������֡.
 * @return 					�Ƿ�ɹ��õ�Ԥ��֡�ķ���ֵ.
 * @retval					VM_CAM_SUCCESS ����ͷ���. 
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS �ڴ����״̬�µ����˱�����.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval					VM_CAM_ERR_BAD_PARAM �ڲ���frame_dataΪNULL��ʱ�򱾴����뽫�ᱻ����.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *							���������ᱻ����.
 * @see						vm_camera_preview_start
 * @see						vm_camera_preview_stop
 */
VMINT vm_camera_get_frame(VM_CAMERA_HANDLE handle, vm_cam_frame_data_t* frame_data);

/**
 * �õ�VRE֧�������Ƭ�ֱ���,��������������ͷ���κ�״̬�±�����.
 *
 * @param[in]				handle ����ͷ���.
 * @param[out]			size ��Ƭ�ֱ��ʵ�ָ��.
 * @return				�õ�VRE֧�ֵ������Ƭ�ֱ����Ƿ�ɹ�.
 * @retval				VM_CAM_SUCCESS �õ�VRE ֧�ֵ������Ƭ�ֱ��ʳɹ�.
 * @retval				VM_CAM_ERR_BAD_PARAM ����Ĳ���.
 * @retval				VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval				VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *						���������ᱻ����.
 * @see					vm_camera_set_capture_size
 * 
 */
VMINT vm_camera_get_max_capture_size(VM_CAMERA_HANDLE handle, vm_cam_size_t* size);

/**
 * ��������ͷ��Ƭ�ķֱַ���,�����������ڷ�VM_CAM_CAPTURING_STATUS
 * ���κ�״̬��ִ��.
 * 
 * @param[in]					handle ����ͷ���.
 * @param[in]					size	��Ƭ�ֱ���.
 * @return					�Ƿ����óɹ�.
 * @retval					VM_CAM_SUCCESS ��������ߴ�ɹ�.
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS �����VM_CAM_CAPTURING_STATUS�µ��ñ�
 *							�����������뽫�ᱻ����.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval					VM_CAM_ERR_BAD_PARAM ���size����ΪNULL,����Ƭ�Ŀ�͸ߵķֱ���
 *							���Ϸ�,�������뽫�ᱻ����.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *							���������ᱻ����.
 * @see						vm_camera_get_max_capture_size
 */
VMINT vm_camera_set_capture_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t* size);

/**
 * ������ͷ����.
 * 
 * @param[in]					handle ����ͷ���.
 * @return					ϵͳ�Ƿ���ܸñ�����.
 * @retval					VM_CAM_SUCCESS ���ܱ�����,����ͷ����VM_CAM_CAPTURING_STATUS״̬.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS �ڱ�״̬�²��������ղ���.
 * @retval					VM_CAM_ERR_NOT_REGISTER_NOTIFY �����û��ע��ص������͵��ñ�����,
 *							��ô�ô��󽫻ᱻ����.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *							���������ᱻ����.
 * @see						vm_camera_set_capture_size
 * 
 */
VMINT vm_camera_capture(VM_CAMERA_HANDLE handle);


/**
 * �õ�����ͷ�ĵ���Ƭ���ݼ���������Ϣ,������ֻ�����յ�
 * VM_CAM_CAPTURE_DONE��Ϣʱ����.
 * 
 * @param[in]					handle ����ͷ���.						
 * @param[out]				capture_data	ϵͳ������������ݺ�����д��ýṹ���
 *							��Ա������.
 * @return					�Ƿ�õ��������ݳɹ�.						
 * @retval					VM_CAM_SUCCESS �ɹ��õ���������.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE ���������ͷ���.
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS �ڴ����˵�״̬��ִ�б�����.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE ���VRE��֧������ͷ�Ĺ�����ô
 *							���������ᱻ����.
 * @see						vm_camera_capture
 */
VMINT vm_camera_get_capture_data(VM_CAMERA_HANDLE handle, vm_cam_capture_data_t* capture_data);

#ifdef __cplusplus
}
#endif

#endif

