#ifndef __VM_SENSOR
#define __VM_SENSOR

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @VRE�Ĵ������ӿڵķ���ֵ
 * @{
 */
 /**
  * �����ɹ�.
  */
#define SENSOR_OP_SUCCESS									(0)
/**
 * ����Ϊ�첽����,��ο���صĺ���˵��.
 */
#define SENSOR_OP_ASYNCHROUS								(1)
/**
 * ����Ĳ���.
 */
#define SENSOR_ECODE_BAD_PARAM							(-1)
/**
 * ��֧�ֵĲ���.
 */
#define SENSOR_ECODE_UNSUPPORT_OPERATION				(-2)
/**
 * �ڵ�ǰ״̬�²�֧�ָò���.
 */
#define SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS   	(-3)
/**
 * ����Ĵ��������.
 */
#define SENSOR_ECODE_INVALID_HANDLE						(-4)
/**
 * ָ���Ĵ��������ƷǷ�.
 */
#define SENSOR_ECODE_INVALID_NAME						(-5)
/**
 * ������ʵ���Ѵ���.
 */
#define SENSOR_ECODE_INSTANCE_CREATED					(-6)
/**
 * ��û��ע�ᴫ�����Ļص�����.
 */
#define SENSOR_ECODE_NOT_REG_NOTIFY						(-7)
/**
 * ȱ���ڴ�.
 */
#define SENSOR_ECODE_NO_MEMORY							(-8)
/** @} */

/**
 * �������ص���Ϣ.
 */
typedef enum {
	SENSOR_START_DONE, 			/**<�������������.				*/
	SENSOR_START_ABORT, 			/**<����������ʧ��.				*/
	SENSOR_STOP_DONE,				/**<������ֹͣ�ɹ�. 				*/
	SENSOR_STOP_ABORT,			/**<������ֹͣʧ��. 				*/
	SENSOR_SET_OPTION_DONE, 		/**<���ô������������.		*/
	SENSOR_SET_OPTION_ABORT, 	/**<���ô��������Գɹ�.		*/
	SENSOER_DATA_RECEIVED		/**<���������ܵ�������.		*/
}VM_SENSOR_MESSAGE;

/**
 * @struct �������Ļص��ṹ��
 * @brief �������ӿڻص���Ӧ�ó���Ľṹ��.
 */
typedef struct vm_sensor_notify_t {
	VMINT sensor_handle;			/**<���������.						*/
	VM_SENSOR_MESSAGE message;	/**<�������ص���Ϣ.					*/
	void* sensor_data;				/**<���������յ�������.			*/
	VMUINT data_size;				/**<���������յ������ݸ���.		*/
	VMINT reserved;					/**<�����ֶ�.							*/
}vm_sensor_notify_t;

typedef void (*SENSOR_NOTIFY_FUNC)(vm_sensor_notify_t* sensor_notify, void* user_data);

/**
 * ����������ʵ��.
 *  
 * @param[in]				name ������������,��һ���豸��Ӧ�ñ���Ψһ.
 * @param[out]			sensor_handle ������ʵ���Ĵ��������,ֻ�з���
 *						#SENSOR_OP_SUCCESS��ʱ��,��������������.
 * @return				����ָ�����ƵĴ�����ʵ���Ƿ�ɹ��ķ���ֵ.
 * @retval				SENSOR_OP_SUCCESS ����������ʵ���ɹ�.
 * @retval				SENSOR_OP_ERROR_CODE_BAD_PARAM �������sensor_handleΪNULL
 *						��ô���᷵�ر�������.
 * @retval				SENSOR_ECODE_INVALID_NAME �Ƿ��Ĵ���������.
 * @retval				SENSOR_ECODE_INSTANCE_CREATED ָ�����ƵĴ�����ʵ��
 *						�Ѿ�������.
 * @retval				SENSOR_ECODE_NO_MEMORY ȱ���ڴ�.
 * @note					�ڵ��ñ�������������#vm_release_sensor_instance,�ͷ�
 *						���������Ĵ�����ʵ��.
 * @code 
 * // vm_freescale_MMA7455L.h
 * #define USE_SENSOR_NAME "sensor:quality=acceleration;device=mobile;model=TCL-E9;location=inside"
 * #define G_SELECT "G_SELECT"
 * typedef enum {2G, 4G, 8G}G_SELECT_ENUM;
 * @endcode
 * @code
 * // sensor_sample.c
 * VMINT handle;
 * if (vm_create_sensor_instance(USE_SENSOR_NAME, &handle) == SENSOR_OP_SUCCESS)
 * {
 * 	if (vm_register_sensor_notify(handle, (RECEIVE_DATA_FUNC)receive_callback, NULL) == SENSOR_OP_SUCCESS)
 *  	{
 * 		VMINT res = vm_set_sensor_numeric_option(handle, G_SELECT, 2G);
 *		if (res == SENSOR_OP_SUCCESS)
 *		{
 *			// ���ô�����ѡ��ɹ�, ������������������.
 *		}
 *    		else if (res == SENSOR_OP_ASYNCHROUS)
 *		{
 *			// ���ô�����ѡ����첽�ķ�ʽ��������.
 *		}
 *		else
 *		{
 *			// ���ô�����ѡ��Ĵ���Ĵ���.
 *		}
 *	}
 * }
 * @endcode
 */
VMINT  vm_create_sensor_instance(const VMSTR name, VMINT* sensor_handle);

/**
 * �ͷŸô�����ʵ��.
 * 
 * @param[in]				sensor_handle ���������.
 * @return 				
 * @retval				SENSOR_OP_SUCCESS �����ɹ�.
 * @retval				SENSOR_OP_ERROR_CODE_INVALID_HANDLE ����Ĵ��������.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS �ڵ�ǰ״̬��
 *						��֧�ֵ��ñ�����.
 * @see					vm_create_sensor_instance 
 */
VMINT vm_release_sensor_instance(VMINT sensor_handle);

/**
 * ע�ᴫ�����ص�����.
 * 
 * @param[in]				sensor_handle ���������.
 * @param[in]				callback �ص�����
 * @param[in]				user_data ÿ�λص����ڲ�����Ŀͻ����������.
 * @return				ע�ᴫ�����ص������ɹ����ķ���ֵ.
 * @retval				SENSOR_OP_SUCCESS �����ɹ�.
 * @retval				SENSOR_OP_ERROR_CODE_BAD_PARAM ��������ô����뽫�ᱻ����.
 * @retval				SENSOR_ECODE_INVALID_HANDLE  ����Ĵ��������.
 * 
 */
VMINT vm_register_sensor_notify(VMINT sensor_handle, SENSOR_NOTIFY_FUNC callback, void* user_data);

/**
 * ���ô�������ֵ���͵�ѡ��.
 * 
 * @param[in]				sensor_handle ���������.
 * @param[in]				control_name ������ѡ�������.
 * @param[in]				value ������ѡ���ֵ.
 * @return				����ѡ��ɹ����.
 * @retval				SENSOR_OP_SUCCESS ����ѡ��ɹ�.
 * @retval				SENSOR_OP_ASYNCHROUS  ����Ϊ�첽����, ������óɹ�
 *						����ص�SENSOR_SET_OPTION_DONE��Ϣ,�������ʧ��
 *						���ص�SENSOR_SET_OPTION_ABORT��Ϣ.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS �ڵ�ǰ״̬��
 *						��֧�����ø�ѡ��.
 * @retval				SENSOR_ECODE_INVALID_HANDLE ����Ĵ��������.
 * @retval				SENSOR_ECODE_BAD_PARAM �������control_nameΪNULL
 *						�����value ����ȷ,��ô�ô����뽫�ᱻ����.
 * @retval				SENSOR_ECODE_NOT_REG_NOTIFY �ڵ��ñ�����ǰ�������
 *						#vm_register_sensor_notify������ע��ص�����,���򽫷��ظ�
 *						������.
 * @see					vm_set_sensor_string_option
 */
VMINT vm_set_sensor_numeric_option(VMINT sensor_handle, const VMSTR control_name, 
	VMINT value);

/**
 * ���ô������ַ������͵�ѡ��.
 * 
 * @param[in]				sensor_handle ���������.
 * @param[in]				control_name ������ѡ�������.
 * @param[in]				value ������ѡ���ֵ.
 * @return				����ѡ��ɹ����.
 * @retval				SENSOR_OP_SUCCESS ����ѡ��ɹ�.
 * @retval				SENSOR_OP_ASYNCHROUS  ����Ϊ�첽����, ������óɹ�
 *						����ص�SENSOR_SET_OPTION_DONE��Ϣ,�������ʧ��
 *						���ص�SENSOR_SET_OPTION_ABORT��Ϣ.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS ��ǰ״̬��
 *						��֧�����ø�ѡ��.
 * @retval				SENSOR_ECODE_INVALID_HANDLE  ����Ĵ��������.
 * @retval				SENSOR_ECODE_BAD_PARAM �������control_nameΪNULL
 *						�����value ����ȷ,��ô�ô����뽫�ᱻ����.
 * @retval				SENSOR_ECODE_NOT_REG_NOTIFY �ڵ��ñ�����ǰ�������
 *						#vm_register_sensor_notify������ע��ص�����,���򽫷��ظ�
 *						������.
 * @see					vm_set_sensor_numeric_option
 */
VMINT vm_set_sensor_string_option(VMINT sensor_handle, const VMSTR control_name, 
	VMSTR value);

/**
 * ����������.
 * 
 * @param[in]				sensor_handle ���������.
 * @return				�����������ɹ����.
 * @retval				SENSOR_OP_SUCCESS �����������ɹ�.
 * @retval				SENSOR_OP_ASYNCHROUS ����Ϊ�첽����, ��������ɹ�
 *						����ص�SENSOR_START_DONE��Ϣ,�������ʧ��
 *						����ص�SENSOR_START_ABORT��Ϣ.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS ����������Ѿ�����
 *						��ô�ô����뽫�ᱻ����.
 * @retval				SENSOR_ECODE_INVALID_HANDLE ����Ĵ��������.
 * @retval				SENSOR_ECODE_NOT_REG_NOTIFY �ڵ��ñ�����ǰ�������
 *						#vm_register_sensor_notify������ע��ص�����,���򽫷��ظ�
 *						������.
 * @note					���ñ�����������������,�ڵ���#vm_release_sensor_instance
 *						ǰ��������#vm_stop_sensor��ֹͣ������.
 * @see 					vm_stop_sensor
 */
VMINT vm_start_sensor(VMINT sensor_handle);

/**
 * ֹͣ������.
 * 
 * @param[in]				sensor_handle ���������.
 * @return				ֹͣ�������ɹ����
 * @retval				SENSOR_OP_SUCCESS �رմ������ɹ�.
 * @retval				SENSOR_OP_ASYNCHROUS �������Ĺر�Ϊ�첽��,���ֹͣ
 *						�ɹ�,����ص�SENSOR_STOP_DONE��Ϣ,ֹͣʧ�ܽ��᷵��
 *						SENSOR_STOP_ABORT��Ϣ.
 * @retval				SENSOR_ECODE_INVALID_HANDLE ����Ĵ��������.
 * @retval				SENSOR_ECODE_NOT_REG_NOTIFY �ڵ��ñ�����ǰ�������
 *						#vm_register_sensor_notify������ע��ص�����,���򽫷��ظ�
 *						������.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS ���������û������,
 *						��ô�ô����뽫�ᱻ����.
 * @see					vm_start_sensor		
 */
VMINT vm_stop_sensor(VMINT sensor_handle);

#ifdef __cplusplus
}
#endif 

#endif
