#ifndef	_VM_PRO_MNG_
#define _VM_PRO_MNG_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmmem.h"

typedef VMINT VM_P_HANDLE;

//process procedure related interfaces

#define	VM_PMNG_OP_OK					(0)
#define   VM_PMNG_PROCESS_NO_EXISTS		(-1)
#define	VM_PMNG_NO_OP_IN_STATUS			(-2)
#define 	VM_PMNG_ERROR_PARAM				(-3)
#define 	VM_PMNG_NO_MEM					(-4)
#define 	VM_PMNG_ERROR_IO					(-5)
#define	VM_PMNG_NO_SCHEDULE				(-6)
#define	VM_PMNG_EXIT						(-7)
#define	VM_PMNG_CERT_FAIL                            (-8)
#define	VM_PMNG_ERROR_FUNLST                     (-9)

#define 	VM_PMNG_SEC_TAG_PLATFORM_PARAM_DISMATCH		(-10)
#define	VM_PMNG_SEC_APP_TIMESTAMP_ERROR				(-11)
#define	VM_PMNG_SEC_IMSI_DISMATCH						(-12)
#define	VM_PMNG_SEC_BAN_LIST_APP						(-13)
#define 	VM_PMNG_SEC_INVALIDATE_APP						(-14)
#define 	VM_PMNG_SEC_CERT_OVREDUE						(-15)
#define 	VM_PMNG_SEC_CERT_SMALL_SYS_MEM					(-16)

#define	VM_PMNG_EXCEED_MAX_PROCESS_NUM				(-17)

#define	VM_PMNG_CUR_HANDLE				(0x0f)

#define VM_PMNG_KERNEL_HANDLE			(0)


typedef enum 
{
	VM_PMNG_UNLOAD = 0,			/**<�����Ѿ���ж�ص�״̬��												*/
	VM_PMNG_FOREGROUND, 			/**<������ǰ̨����״̬��													*/
	VM_PMNG_BACKGROUND,			/**<�����ں�̨����״̬��													*/ 
	VM_PMNG_MAX_NUM
}VM_PROCESS_STATUS;


/**
 * ��ʼ�����̹�������������ֻ��Ҫ��VRE������ʱ�򱻵��á�
 *
 * @return ��ʼ���ɹ����� VM_PMNG_OP_OK, ���򷵻ظ����Ĵ����롣
*/
VMINT vm_pmng_init(void);

/**
 * ֹͣ���̹���������������Ҫ������ģ�鱻�ͷ�ֻ��ű�
 * ���á�������ֻ�����˳�VRE��ʱ�򱻵��á�
*/
void vm_pmng_finialize(void);

/**
 * �������̵��ȵ�ǰ̨���У�����ý����Ѿ���������ᱻ
 * ���ȵ�ǰ̨���С�����ý�������ĳЩԭ���ܱ����ȵ�
 * ǰ̨�����򱾺������᷵��ʧ�ܡ����ڷ�VRE Kernel(VAM)����ֻ��
 * ��Foreground ״̬�²��ܵ��ñ����������ҵ��ñ������Ľ���
 * ���յ�HIDE��Ϣ�������ȵ�Background ״̬��
 *  
 * @param[in] 	file_name װ�ص�Ӧ�õ��ļ�����
 * @param[in]		app_name��Ӧ�ó������ơ�
 * @return		�����ɹ�ʱ���ؽ���id, ���򷵻ظ����Ĵ�����
 * @retval		����0������ʾ���̵�ID��
 * @retval		VM_PMNG_NO_OP_IN_STATUS ��ǰ���еĽ��̲���Foreground״̬��
 *				���ܵ��ñ�������
 * @retval		VM_PMNG_ERROR_PARAM ���file_nameΪNULL�򱾴����뽫�᷵�ء�
 * @retval		VM_PMNG_ERROR_IO �����IO��ʱ��ʧ���򷵻ر������룬����
 *				�Ѿ����صĽ��̱������벻�᷵�ء�
 * @retval		VM_PMNG_NO_MEM û���ڴ���ظ�Ӧ�ã������Ѿ����صĽ��̱������벻�᷵�ء�
 * @retval		VM_PMNG_NO_SCHEDULE �Ѿ������صĽ��̲��ܱ����ȵ�ǰ̨���С�
 * @retval		VM_PMNG_SEC_TAG_PLATFORM_PARAM_DISMATCH ƽ̨������Ӧ��TAG��ƥ�䣬��������ʧ�ܡ�
 * @retval		VM_PMNG_SEC_APP_TIMESTAMP_ERROR Ӧ�ó�������Ч�ڣ���������ʧ�ܡ�
 * @retval		VM_PMNG_SEC_IMSI_DISMATCH	IMSI����Ӧ�ó���ƥ�䣬��������ʧ�ܡ�
 * @retval		VM_PMNG_SEC_BAN_LIST_APP Ӧ�ó���Ϊ������Ӧ�ã���������ʧ�ܡ�
 * @retval		VM_PMNG_SEC_INVALIDATE_APP Ӧ�õ�֤����֤ʧ�ܣ���������ʧ�ܡ�
 * @retval		VM_PMNG_SEC_CERT_OVREDUE ֤����ڡ�
*/
VM_P_HANDLE vm_pmng_create_process(VMWSTR file_name, vm_multi_lang_app_name_t* app_name, void (*mem_retry_callback)(void));

/**
 * ɾ�����̣�������ֻ����VAM��ָ��p_handle�ĸ����̵��á���û�н�������ʱ��
 * ����VAM�˳�������£����VRE�Ļ���ֹͣ��
 *  
 * @param[in] 	p_handle	����ID��
 *
 * @return		���������
 * @retval		VM_PMNG_OP_OK ɾ���ɹ���
 * @retval		VM_PMNG_PROCESS_NO_EXISTS ָ���Ľ��̲����ڡ�
 */
VMINT vm_pmng_delete_process(VM_P_HANDLE p_handle);

/*
 * ���̰��Լ����óɺ�̨���У��������������VM_PMNG_OP_OK��
 * ��ô���̲�Ӧ���ٶ�UI���̲������ڵ��ñ�����ǰ��Ӧ��
 * �ر�UI��Դ��������Ӧ���ڽ�����Foreground״̬�²�������á�
 *  
 * @return	���������
 * @retval	VM_PMNG_OP_OK �����ɹ���
 * @retval	VM_PMNG_NO_OP_IN_STATUS ��ǰ״̬�²�������á�
*/
VMINT vm_pmng_set_bg(void);

/*
 * ���ϵͳ��װ�ؽ��̵���������
 *  
 * @return 	�����еĽ��̵ĸ���������ϵͳ���ö����������ش���0����������
*/
VMINT vm_pmng_max_counter(void);

/*
 * ��õ�ǰϵͳ�Ѽ��صĽ��̵ĸ�����
 *  
 * @return		�Ѿ����صĽ��̸��������ش��ڵ���0����������
 */
VMINT vm_pmng_current_counter(void);

/*
 * ���ǰ̨���еĽ��̵�ID��
 *  
 * @return		��ǰ���еĽ���ID��
 * @retval		����0������ʾ��ǰ�������н��̵�ID��
 * @retval		����0��ʾ��ǰû�н�����ǰ̨���С�
*/
VM_P_HANDLE vm_pmng_fg_process(void);

/*
 * ��ý��̵�״̬
 *  
 * @param[in] 	p_handle	��ʾ��Ҫ��ѯ״̬����ID�������Ҫ��ѯ
 *			       ���ñ��������̵�״̬�򱾲���Ӧ����
 *				VM_PMNG_CUR_HANDLE ��
 *
 * @return		���̵�״̬��
 * @retval		VM_PMNG_FOREGROUND ǰ̨����״̬��
 * @retval		VM_PMNG_BACKGROUND ��̨����״̬��
 * @retval		VM_PMNG_PAUSED ֹͣ״̬��
 * @retval		VM_PMNG_UNLOAD δ����״̬��
*/
VM_PROCESS_STATUS vm_pmng_state(VM_P_HANDLE p_handle);

/*
 * �ж�ָ�������Ƿ���ǰ̨���С�
 *  
 * @param[in] 	p_handle	����ID��VM_PMNG_CUR_HANDLE ��ʾ��ǰ����ID��
 * @return		ָ�������Ƿ�ǰ̨���С�
 * @retval		TRUE ��ʾ��ǰ̨���С�
 * @retval		FALSE ��ʾ����ǰ̨���С�
*/
VMINT vm_pmng_is_fg(VM_P_HANDLE p_handle);

/*
 * ��ָ���Ľ��̷�����Ϣ��
 *  
 * @param[in] 	p_handle	��Ҫ���͵��Ľ���ID��
 * @param[in]		user_message	 �û���Ϣ�����Ǵ��ڵ���5000��
 * @param[in]		memsage_param ��Ϣ������
 *
 * @return		�ɹ�ʱ����VM_PMNG_OP_OK, ���򷵻ظ����Ĵ����롣
 * @retval		VM_PMNG_OP_OK ��ʾ���ͳɹ���
 * @retval		VM_PMNG_PROCESS_NO_EXISTS ����ID ָ���Ľ��̲����ڡ�
 * @retval		VM_PMNG_ERROR_PARAM ���user_message������5000�򱾺����᷵�ظñ���ֵ��
*/
VMINT vm_pmng_send_sys_msg(VM_P_HANDLE p_handle, VMINT user_message, VMINT memsage_param);

/**
 * ������������ý������л���callback��ָ�����
 * ���л����ĺꡣʹ�÷�ʽ����:
 * 
 * PMNG_WRAP_CALLBACK(p_handle, app_callback(param));
 */
#define	PMNG_WRAP_CALLBACK(PHANDLE, APP_CALLBACK_CALLER) \
	if (vm_pmng_set_ctx(PHANDLE) == VM_PMNG_OP_OK){\
		APP_CALLBACK_CALLER;\
		vm_pmng_reset_ctx();\
	}

/*
 * ����ָ�����̵����л�������callback�����̿ռ�����ǰ
 * ������ñ���������callback����ִ����ϣ��������
 * vm_pmng_reset_ctx�ͷŸ����л�����
 * 
 * @code
 * if (vm_pmng_set_ctx(handle) == VM_PMNG_OP_OK)
 * {
 *     app_callback(event);
 *     vm_pmng_reset_ctx();
 * }
 * @endcode
 * @param[in] 	p_handle	����ID��
 * @return		�����Ƿ�ɹ���
 * @retval		VM_PMNG_OP_OK ���óɹ���
 * @retval		VM_PMNG_PROCESS_NO_EXISTS ָ���Ľ��̲����ڡ�
 * @retval		VM_PMNG_NO_OP_IN_STATUS ���������vm_pmng_reset_ctx�ڶ���
 * 				���ñ�������ʱ��ͻ᷵�ر�����ֵ��
 * @note			vm_pmng_reset_ctx
*/
VMINT vm_pmng_set_ctx(VM_P_HANDLE p_handle);

/*
 * �ָ���ǰ�������ã��ú����ָ�vm_pmng_set_ctx����ǰ
 * �Ľ������û�����
 *  
 * @return		�ָ������Ƿ�ɹ���
 * @retval		VM_PMNG_OP_OK �ɹ���
 * @retval		VM_PMNG_NO_OP_IN_STATUS ���û�е���vm_pmng_set_ctx
 * 				�͵��ñ���������ô�������뽫�ᱻ���ء�
*/
VMINT vm_pmng_reset_ctx(void);

/*
 * ��ȡָ������ID��Ӧ�ó����ļ�����
 *  
 * @param[in] 	p_handle	����ID��VM_PMNG_CUR_HANDLE ��ʾ��ǰ����ID��
 * @param[out] 	filename_buf	�����ļ����Ļ��档
 * @param[in]		filename_len filename_buf��ָ�����ܹ��Ŷ��ٸ��ַ���
 * 
 * @return		�õ������ļ������Ƿ�ɹ���
 * @retval		VM_PMNG_OP_OK �����ɹ���
 * @retval		VM_PMNG_ERROR_PARAM ���filename ΪNULL�򱾺������ᱻ���ء�
 * @retval		VM_PMNG_PROCESS_NO_EXISTS ָ���Ľ���ID�Ľ��̻�û�б����ء�
*/
VMINT vm_pmng_file_name(VM_P_HANDLE p_handle, VMWCHAR* filename_buf, VMINT filename_len);

/**
 * ��ֹ���ں�̨���е�Ӧ�ó�����VAM���ã������������˳�VRE������
 * 
 * @param[in]		filename Ӧ�ó������ƣ��������·����
 * @return		�Ƿ���ֹӦ�ó���ķ���ֵ��
 * @retval		VM_PMNG_PROCESS_NO_EXISTS ָ�����ļ�����Ӧ�ó������û�б����ع���
 * @retval		VM_PMNG_NO_OP_IN_STATUS ������ǰ̨�����޷���ֹ��
 * @retval		VM_PMNG_OP_OK ��ֹ���̳ɹ���
 */
VMINT vm_pmng_destroy_bg_process(VMWSTR filename);

/**
 * �õ�ָ��״̬�Ľ����б��ڲ�ʹ��pHandleʱ���������_vm_kernel_free�ͷ�֮��
 * 
 * @param[in]			status ��Ҫ�õ�����������״̬��
 * @param[out]		pHandle ���̱���б�
 * @param[out]		process_num ���̸�����
 * @return			�Ƿ�ɹ��õ�ָ��״̬�Ľ����б�
 * @retval			VM_PMNG_OP_OK �ɹ���
 * @retval			VM_PMNG_ERROR_PARAM ����Ĳ�����
 * @retval			VM_PMNG_NO_MEM �ڴ治����
 */
VMINT vm_pmng_get_process_lst(VM_PROCESS_STATUS status, VM_P_HANDLE** pHandle, 
	VMUINT* process_num);

/*
 * ��ȡָ�����̵�Ӧ��ID��
 *  
 * @param 	p_handle	����ID��VM_PMNG_CUR_HANDLE ��ʾ��ǰ����ID��
 *
 * @return	�ɹ�ʱ����Ӧ��ID, ���򷵻�0��
*/
VMINT vm_pmng_app_id(VM_P_HANDLE p_handle);

/*
 * ��ȡ��ǰ���������е�APP ��SM ����ID��
 *  
 * @return	�ɹ�ʱ���ؽ���ID, ���򷵻ظ����Ĵ����롣
 * @retval	����0����������ʾ����ID��
 * @retval	0 ��ʾû�н����������С�
 *			
*/
VM_P_HANDLE vm_pmng_get_current_handle(void);

/*
 * ��ȡ��ǰ���������е�APP ����ID��
 *  
 * @return	�ɹ�ʱ���ؽ���ID, ���򷵻ظ����Ĵ����롣
 * @retval	����0����������ʾ����ID��
 * @retval	0 ��ʾû�н����������С�
 *			
*/
VMINT vm_pmng_get_app_handle(void);

/**
 * ��̨Ӧ����ʾ�û��л���ǰ̨���е�֪ͨ��ʽ��
 */
typedef enum 
{
	VM_NOTIFY_TYPE_SILENCE,			/**<����ģʽ��ʾ*/
	VM_NOTIFY_TYPE_SOUND = 1,			/**<���������ķ�ʽ��ʾ��		*/
	VM_NOTIFY_TYPE_VIBRATILITY = 2	/**<ʹ�ֻ��𶯵ķ�ʽ��ʾ�� 	*/
} VM_FG_NOTIFY_TYPE;

/**
 * Ӧ�����뵽ǰ̨���У����ñ�����VRE����Ӧ��ָ���ķ�ʽ��
 * ֪ͨ�û�����̨Ӧ����Ҫ�л���ǰ̨���С�������ֻ����
 * Ӧ�û��ں�̨ʱ���á��������������롣
 * 
 * @code
 * vm_pmng_apply_to_run_in_fg(VM_NOTIFY_TYPE_SILENCE); 	// �԰�����ʽ������ʾ�û���
 * @endcode
 * @code
 * vm_pmng_apply_to_run_in_fg(VM_NOTIFY_TYPE_SOUND); 	// ֻ�������ķ�ʽ��ʾ�û���
 * @endcode
 * @code
 * vm_pmng_apply_to_run_in_fg(VM_NOTIFY_TYPE_VIBRATILITY); // ֻ���𶯵ķ�ʽ��ʾ�û���
 * @endcode
 * @code
 * vm_pmng_apply_to_run_in_fg(VM_NOTIFY_TYPE_SOUND | VM_NOTIFY_TYPE_VIBRATILITY); // ���������𶯵ķ�ʽ��ʾ�û���
 * @endcode
 * @param[in]				notify_type ֪ͨ�ķ�ʽ��
 */
VMINT vm_pmng_apply_to_run_in_fg(VMINT notify_type);

/**
 * ָ���Ľ��̾���Ľ����Ƿ�֧�ֺ�̨���С�
 *
 *
 * @param[in]					p_handle ΪVM_PMNG_CUR_HANDLE��ʾ��ѯ��ǰ�����Ƿ�֧��BG,����Ϊ���̺š�
 * @return					TRUE��ʾ֧��,FALSE���ʾ��֧�֡�
 *
 */
VMINT vm_pmng_is_support_bg(VM_P_HANDLE p_handle);

/*
 *	��ѯapp�Ƿ���FG����
 *  
 *  @param 	appid		Ӧ�ñ�š�
 *
 *	@return	���app��FG���з���1, ���򷵻�0��
*/
//VMINT vm_pmng_is_fg_by_appid( VMINT appid );

/*
 *	��ѯapp�Ƿ���BG����
 *  
 *  @param 	appid		Ӧ�ñ�š�
 *
 *	@return	���app��BG���з���1, ���򷵻�0��
*/
//VMINT vm_pmng_is_bg_by_appid( VMINT appid );


/*
 * ��ѯappstore�Ƿ�������,���ҷ���ǰ̨/��̨��״̬
 *  
 * @param 	running_state		����ǰ̨/��̨״̬�����ݵ�ָ��
 * @return	���appstore�����з���1, ���򷵻�0��
 *					����ֵ��1������£�����appstroe��ǰ̨���У�running_stateָ�������ΪVM_PMNG_FG_RUNNING�� 
 *					����ֵ��1������£�����appstroe�ں�̨���У�running_stateָ�������ΪVM_PMNG_BG_RUNNING��  
*/
//VMINT vm_pmng_as_running( VMINT * running_state );


/*
��ʱ�ӿ� MP����Ҫɾ��,
Ϊ��ģ��VRE �� VM_MSG_SCREEN_ROTATE ��Ϣ  ,����Ϊ ģ��VRE ����Ӧ�÷�ת�ĽǶ�
���Դ���Ĳ�������Ϊ��������֮һ
VM_GRAPHIC_SCREEN_ROTATE_0
VM_GRAPHIC_SCREEN_ROTATE_90
VM_GRAPHIC_SCREEN_ROTATE_180
VM_GRAPHIC_SCREEN_ROTATE_270
����
Ҳ�� VM_MSG_ROTATE	��Ϣ,���� ����ķ�ת�Ƕ� Ϊ 
VM_GRAPHIC_SCREEN_ROTATE_0
*/
void vm_graphic_rotate_temp(VMINT _rotate_value);



/*
VRE �������� design house ����������Ļ��ת���ٶ�
*/
void vm_sensors_rotate(VMINT _rotate_value);



#ifdef __cplusplus
}
#endif 
#endif