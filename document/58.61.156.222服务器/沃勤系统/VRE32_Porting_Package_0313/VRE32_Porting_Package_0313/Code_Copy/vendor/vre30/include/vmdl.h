#ifndef VMDL_H_
#define VMDL_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Ӧ�ó�������Ƶ������ı�ʾ�ĸ�ʽΪ:
 * "�̷�:\\·��\Ӧ�ó�������"[?"�̷�:\\·��\Ӧ�ó�������"]
 * ����[]�е�����Ϊ��ѡ�ģ���������ʾ��Ҫͨ��'?'ǰ��Ӧ�ó���������'?'���Ӧ�ó���
 * 
 * Ӧ�ó������Ƶĸ�ʽ��ͨ��Ӧ�ó������Ƶĺ�׺�����֡�
 * (1) rom��ʾROM��ʽ��
 * (2) vxp��ʾVXP��ʽ��
 * (3) axf��ʾAXF��ʽ��
 */
 
/**
 * ֧�ֵ�Ӧ�ó��������������ʾ������ַ�������
 * VRE��֧�ֵ�ȫ·�����ļ����Ƶ�������Ϊ260���ַ�
 */
#define MAX_APP_NAME_LEN					(260)

/**
 * Ӧ�ó����������ض���ķָ����š�
 */
#define REDIRECT_APPNAME_SEPARATOR		L'?'

/**
 * symbol�����͡�
 */
typedef VMINT (*vm_get_sym_entry_t)(char* sym);

/**
 * ��ִ�е�Ӧ�ó������Ƶĸ�ʽ��
 */
typedef enum
{
	VM_EXEC_VXP,		/**<VXP��ʽ����ʾӦ�ó������ļ�����ʽ���ڣ��洢���ļ�ϵͳ�С� 		*/
	VM_EXEC_AXF,		/**<AXF��ʽ����ʾӦ�ó������ļ�����ʽ���ڣ��洢���ļ�ϵͳ�С� 		*/
	VM_EXEC_ROM,		/**<ROM��ʽ����ʾӦ�ó������ֽ��������ʽ���ڣ��洢��ROM DATA�С� 	*/
	VM_EXEC_NO_FORMAT	/**<δ֪�ĸ�ʽ�� 													*/
} vm_exec_format_enum;

/**
 * ��Ӧ�ó����ļ������еõ�Ӧ�ó����ļ���ROM DATA��ĳ���ӳ���ͷָ�롣����
 * Ӧ�ó�����ļ����Ʊ�����VM_EXEC_ROM�ĸ�ʽ��
 * 
 * @param[in]		wfilename Ӧ�ó����ļ����ƣ���Ӧ�ð�����REDIRECT_APPNAME_SEPARATOR�ģ�
 *				���һ�Ӧ��ֻ����VM_EXEC_ROM��ʽ�ı�ʾ��ʽ��Ч�����򷵻�NULL��
 * @return		����ɹ��򷵻��ڴ�ӳ���ͷָ�룬���򷵻�NULL��
 */
VMUINT8* vm_get_execrom_ptr(VMWSTR wfilename);

/**
 * ����ROM DATA��õ�����ӳ��ĵĴ�С����ROM�еĸ�ʽ���¡�
 * @code
 *					|-------------------|
 * rom_ptr--> 		| app image size 	|
 *            		|-------------------|
 *			  		|  app    image  	|
 *            		|-------------------|
 * @endcode
 * @param[in]		rom_ptr ��ROM DATA���ͷָ�롣
 * @return		����ɹ��򷵻س����ڴ�ӳ��Ĵ�С�����򷵻�0��
 */
VMINT vm_get_execrom_size(VMUINT8* rom_ptr);

/**
 * ��������Ӧ�ó����ļ������еõ���ִ�е�Ӧ�ó������Ƶĸ�ʽ��
 * 
 * @param[in]		wfilename Ӧ�ó����ļ����ƣ���Ӧ�ð�����REDIRECT_APPNAME_SEPARATOR�ģ����򷵻�VM_EXEC_NO_FORMAT��
 * @return		����ɹ��򷵻��ڴ�ӳ���ͷָ�룬���򷵻�VM_EXEC_NO_FORMAT��
 */
vm_exec_format_enum vm_parse_exec_format(VMWSTR wfilename);

/**
 * ���ļ�������ȡָ������ŵĴ�·�����ļ����ơ�
 * ����"c:\\vre\game.vxp?c:\\vre\game2.vxp"���������ȡ?ǰһ��������file_index����Ӧ��Ϊ0����һ����Ϊ1�����û��'?'��
 * file_index����Ϊ0��
 * 
 * @param[in]		wfilename Ӧ�ó�������Ƶ������ı�ʾ��
 * @param[in]		file_index ��š�
 * @param[out]	wexec_filename �ڵõ�ָ����ŵĳ������ƶκ�ϣ������д����ڴ�ռ�ͷָ�룬��Ӧ��ΪNULL��
 * @param[in]		wexec_filename_len wexec_filename��ָ��Ŀռ��С����λΪ�ֽڣ��ó��ȱ������MAX_APP_NAME_LEN��
 * @return		����ɹ��򷵻�TRUE�����򷵻�FALSE��
 */
VMINT vm_get_segment_from_filename(VMWSTR wfilename, VMINT file_index, VMWSTR wexec_filename, 
	VMINT wexec_filename_len);

/**
 * ָ����Ӧ�ó����������Ƿ����REDIRECT_APPNAME_SEPARATOR��
 * 
 * @param[in]		������Ӧ�ó������ơ�
 * @return		TRUE ��ʾexec_filename�����REDIRECT_APPNAME_SEPARATOR
 *				��FALSE ���ʾ������REDIRECT_APPNAME_SEPARATOR��
 */
VMINT vm_is_redirection_filename(VMWSTR exec_filename);

#define EXEC_SUCCESS								(0)
#define EXEC_INTERNAL_ERROR						(-1)
#define EXEC_ERROR_FORMAT							(-2)
#define EXEC_PARAM_ERROR							(-3)

#define EXEC_TAG_PLATFORM_PARAM_DISMATCH		(-4)
#define EXEC_APP_TIMESTAMP_ERROR					(-5)
#define EXEC_BAN_LIST_APP							(-6)
#define EXEC_INVALIDATE_APP						(-7)
#define EXEC_IMSI_DISMATCH							(-8)
#define EXEC_CERT_OVREDUE							(-9)

#define EXEC_NOT_EXEC_IN_STATUS					(-10)
#define EXEC_NO_MEM								(-11)

/**
 * װ��һ������VRE��Ӧ�ó��򣬲��Ұѳ������Ȩת�����������ĳ���
 *
 * @param filename		����·����
 *
 * @return				����0��ʾִ�гɹ�����ʱVRE������ִ��Ȩ����
 *						Ӧ�ó��򡣷��ظ�����ʾʧ�ܡ�
 */
VMINT vm_exec(VMWSTR filename);

/**
 * �����Ѿ�װ�ص��ڴ�ĳ����ڴ�ӳ������ݱ�����ļ�һ�¡�
 *
 * @param ptr			�����ڴ�ӳ����ڴ�ָ�롣
 *
 * @return				����0��ʾ�����ɹ���
 */
VMINT vm_exec_from_mem(VMUINT8 *ptr);

/**
 * �ͷŶ�̬װ���VREӦ�ó�����ռ�õ��ڴ棬�������ֻ��VRE�ڲ�ʹ�ã�
 * Ӧ�ó���Ӧ���ô˺�������������𲻿�Ԥ��Ľ����
 */ 
void vm_free_vreapp(void);

/**
 * Ӧ�ó����������͡�
 */
typedef enum {
	ASYN_EXECUTE_SHORTCUT_APP_TYPE = 1,		/**<�ض�������Ӧ�ó��򣬶�����ʾAPP STORE�� */
	ASYN_EXECUTE_APP_STORE_TYPE				/**<��APP STORE������Ӧ�ó��� 			*/			
} ASYN_EXECUTE_TYPE;

/**
 * ��vm_asyn_execute_context_t.pre_app_execute_ret���Եõ�
 * ����Ӧ��ʱ��״̬��
 * @{
 */
/**
 *  �����ɹ��������˳���
 */
#define APP_ASYN_EXECUTE_SUCCESS							(0)

/**
 * Ӧ�ó�������е�ƽ̨����ʵ���е�ƽ̨��ƥ�䡣
 */
#define APP_ASYN_EXECUTE_PLATFORM_PARAM_DISMATCH		(-1)

/**
 * Ӧ�ó������е�ʱ�䲻������Ч���ڡ�
 */
#define APP_ASYN_EXECUTE_TIMESTAMP_ERROR				(-2)

/**
 * Ӧ�ó����ں������
 */
#define APP_ASYN_EXECUTE_BANNED_APP						(-3)

/**
 * Ӧ�ó���Ƿ���û�о���Ȩ��
 */
#define APP_ASYN_EXECUTE_INVALIDATE_APP					(-4)

/**
 * IMSI�Ų����ڡ�
 */
#define APP_ASYN_EXECUTE_IMSI_DISMATCH					(-5)

/**
 * APP��ʹ�õ�֤���Ѿ����ڡ�
 */
#define APP_USE_CERT_OVERDUE								(-6)

/**
 * VREϵͳ�ڲ�����
 */
#define APP_ASYN_EXECUTE_INTERNAL_ERROR					(-7)
/** @} */

/**
 * �û����浽�����������ݵ����ߴ磬��λΪ�ֽڡ�
 */
#define ASYN_MAX_MEM_SIZE									(20)

/**
 * ����Ӧ�ó���ʱ�����������Ͷ��塣
 */
typedef struct 
{
	VMWCHAR app_name[MAX_APP_NAME_LEN + 1];						/**<��ǰ�����ӳ���ĸ�Ӧ�ó�������ơ�					*/
	VMINT pre_app_execute_ret;										/**<��ǰһ��������Ӧ���Ƿ�ɹ��ķ���ֵ������롣	*/
	ASYN_EXECUTE_TYPE pre_app_execute_type;						/**<��ǰһ��������Ӧ�õ�������ʽ��							*/
	VMUCHAR pre_app_execute_user_data[ASYN_MAX_MEM_SIZE];		/**<������Ӧ�ó���ǰ��������ݡ� 							*/
	VMUINT user_data_size;											/**<������Ӧ�ó���ǰ��������ݵĳ��ȡ� 					*/
	VMFILE pre_app_file_handle;										/**<��ǰ�����ӳ���ĸ�Ӧ�ó�����ļ������ 			*/
} vm_asyn_execute_context_t;

/**
 * ��Ӧ�ó���ϣ����������ݱ��浽�������У�
 * ʵ�ִ��ӳ����ﷵ�ظ��������Եõ������
 * ���ݡ�������Ӧ���ڵ���vm_executeǰ���á�
 * 
 * @param[in]		data ϣ������ĵ����������ĵ����ݡ�
 * @param[in]		data_size ���ݵĴ�С����λΪ�ֽڡ�������
 *					Ӧ��С�ڻ��ߵ���ASYN_MAX_MEM_SIZE��
 * @return			�Ƿ�ɹ��������ݡ�
 * @retval			TRUE ����ɹ���
 * @retval			FALSE ����ʧ�ܡ�
 */
VMINT vm_save_execute_context(VMUCHAR* data, VMUINT data_size);

/**
 * ȡ����ǰһ�������ӳ���������ġ�
 * 
 * @param[out]		context �����ģ����ȡ�������ʳɹ��Ὣ�����ĵ�����
 *					д��context��ָ��Ľṹ�С�
 * @return			�Ƿ�ȡ��Ӧ�ó��������ĳɹ���
 * @retval			TRUE ��ȡ�����ĳɹ���
 * @retval			FALSE ��ȡ������ʧ�ܡ�
 */
VMINT vm_load_execute_context(vm_asyn_execute_context_t* context);

#ifdef __cplusplus
}
#endif

#endif