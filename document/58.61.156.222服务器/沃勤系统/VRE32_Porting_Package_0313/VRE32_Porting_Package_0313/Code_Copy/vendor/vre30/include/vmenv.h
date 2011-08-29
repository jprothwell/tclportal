#ifndef __VM_ENV__
#define __VM_ENV__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmdl.h"
#include "vmpromng.h"
#include "vmnvram.h"


typedef enum {
	VRE_EVT_START_SUCCESS = 0,			/**<ASM�ڴ����ɹ���VRE�����ɹ��� 								*/
	VRE_EVT_START_INTERNEL_ERROR,		/**<ϵͳ�������������ڲ�ʧ�ܡ�									*/
	VRE_EVT_QUIT							/**<VRE �����˳�����Ϣ�� 												*/
} VAM_START_VRE_EVT;

typedef void (*vm_vre_evt_cb_t)(VAM_START_VRE_EVT evt);

#define VM_VLC_START_SUCCESS					(0)
#define VM_VLC_ASYN_ALLOC_ASM					(1)
#define VM_VLC_ASYN_DATAACCOUNT_CHECK			(2)
#define VM_VLC_MASS_STORAGE					(-1)
#define VM_VLC_MEDIA_BUFFER_ALLOC_ERROR		(-2)
#define VM_VLC_INTERNEL_ERROR					(-3)

/**
 * ����VRE ���������ǲ���ע��Pen, Keyboard����Ϣ����Ҳ����
 * ����VRE ��SCREEN��������SCREEN��һ�����⣬��VREʹ��ASM
 * �ڴ沢���ڴ�û�з��䵽��ʱ��ASM Framework���ܻ����Լ�
 * ��Popup Screen�����VRE�����Ѿ���������ñ������������κ�
 * �Ĵ������ҷ��������ɹ���
 * 
 * @param[in]					state ��ǰû���õ���Ĭ��Ϊ0��
 * @return					����VRE�Ƿ�ɹ��ķ���ֵ��
 * @retval					VM_VLC_START_SUCCESS �����ɹ���
 * @retval					VM_VLC_ASYN_ALLOC_ASM ASMû�з��䵽
 *							ϵͳ���첽�ͷŵ�����ռ��ASM��Ӧ�á�
 * @retval					VM_VLC_MASS_STOREAGE �ֻ����ڴ洢ģʽ��VRE����ʧ�ܡ�
 * @retval					VM_VLC_MEDIA_BUFFER_ALLOC_ERROR VRE����media bufferʧ�ܡ�
 * @retval					VM_VLC_INTERNEL_ERROR VRE�ڲ�����
 */
VMINT vm_vam_load_core(vm_vre_evt_cb_t vam_cb);

/*
 * Ӧ�ó������
 */
typedef void (*vm_vre_app_evt_cb_t)(VMUWSTR fileName, VAM_START_VRE_EVT evt);

/**
 * @name vm_execute�����ķ���ֵ
 * @{
 */
/**
 * �ɹ�������ָ��Ӧ�á�
 */
#define VM_EXECUTE_APP_SUCCESS					(0)

/**
 * ָ��Ӧ��Ϊ�Ƿ���Ӧ�ó���
 */
#define VM_EXECUTE_APP_ILLEGAL					(-1)

/**
 * û���㹻���ڴ�����Ӧ�ã�
 * ���ظô�����ǰVRE����ʾ��ǰ�Ѿ�����Ӧ�õ��б�
 */
#define VM_EXECUTE_APP_NOT_ENOUGH_MEMORY		(-2)

/**
 * ����ջ������
 */
#define VM_EXECUTE_APP_CALL_STACK_FULL			(-3)

/**
 * �����ں��ڲ����󣬰���IO��ȡ����ȡ�
 */
#define VM_EXECUTE_INTERNAL_ERROR				(-4)

/**
 * Ӧ�ó������в�����ƽ̨������ƥ�䡣
 */
#define VM_EXECUTE_PLATFORM_PARAM_DISMATCH		(-5)

/**
 * Ӧ�ó��򳬹���Ч�ڡ�
 */
#define VM_EXECUTE_TIMESTAMP_ERROR				(-6)

/**
 * �Ǻ�������Ӧ�ò���������
 */
#define VM_EXECUTE_BANNED_APP					(-7)

/**
 * Ӧ�ó����IMSI����ƽ̨��IMSI��ƥ�䣬����ʧ�ܡ�
 */
#define VM_EXECUTE_IMSI_DISMATCH					(-8)

/**
 * Ӧ�ó���ʹ�õ�֤����ڡ�
 */
#define VM_EXECUTE_CERT_OVERDUE					(-9)

/**
 * ��VREĿ¼���ļ�����5000���򷵻ظô����롣
 */
#define VM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY (-10)

/**
 * ϵͳû���㹻���ڴ�������Ӧ�á�����˳����е�Ӧ��Ҳ����������
 * Ӧ���򱾷�����ֵ�ᱻ���ء�
 */
#define VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY		(-11)

/**
 * ����VRE����ͬʱ�������е���������
 */
#define VM_EXECUTE_EXCEED_MAX_APP_NUM			(-12)
/**@} */

/**
 * ����Ӧ�ó������Ӧ�������ɹ���VRE �ᴴ��VRE ��SCREEN��
 * ʧ���򲻻ᴴ����������ļ��Ѿ�����������VRE��ֱ�Ӱ�
 * ��Ӧ�õ��ȵ�ǰ̨��
 * 
 * @param[in]				filename ��Ҫ�������ļ����ƣ���Ҫ������·����
 * @param[in]				retry_callback ��������
 * @return				�Ƿ�ɹ�������Ӧ�ó���ķ���ֵ��
 * @retval				VM_EXECUTE_APP_SUCCESS ����Ӧ�ó���ɹ���
 * @retval				VM_EXECUTE_APP_ILLEGAL �Ƿ���Ӧ�ó���
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY û���㹻���ڴ�����Ӧ�ó���
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL ���ö�ջ������
 * @retval				VM_EXECUTE_INTERNAL_ERROR �����ں��ڲ�����
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH ƽ̨������ƥ�䡣
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR Ӧ�ó��򳬹���Ч�ڡ�
 * @retval				VM_EXECUTE_BANNED_APP �Ǻ�������Ӧ�ò���������
 * @retval				VM_EXECUTE_IMSI_DISMATCH Ӧ�ó����IMSI����ƽ̨��IMSI��ƥ�䣬����ʧ�ܡ�
 * @retval				VM_EXECUTE_CERT_OVERDUE Ӧ�ó���ʹ�õ�֤����ڡ�
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY VREĿ¼���ļ�����5000�����ظô����롣
 * @retval				VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY Ӧ������Ҫ�ڴ����ϵͳ�޷���������
 */
VMINT vm_execute(VMWSTR filename, void (*retry_callback)(void));

/**
 * ����������Ӧ�ó���paramΪ�����VMWSTR����ָ�룬����μ�vm_execute()˵����
 * 
 * @param[in]			filename ��Ҫ�������ļ����ƣ���Ҫ������·����
 * @param[in]			param �����VMWSTR���Ͳ���ָ�롣
 * @return				�μ�vm_execute()˵����
 */
VMINT vm_execute_ex(VMWSTR filename, VMWSTR param);

/**
 * �Ѿ����е�Ӧ�ó�����Ϣ��
 */
typedef struct vm_running_app_info_t
{
	VMWCHAR app_filename[MAX_APP_NAME_LEN + 1];		/**< ��ǰ�Ѿ����е�Ӧ�ó�������ơ�*/
	VMINT app_id;										/**< Ӧ�ó����š�							*/
	VMUINT alloc_mem;									/**< �ڴ�ռ��������λΪKB�� 				*/
}vm_running_app_info_t;

/**
 * ����Ӧ�ó����������VM_EXECUTE_APP_NOT_ENOUGH_MEMORY�������bg_app_infos��
 * app_info_numָ���λ��д�뵱ǰ���ں�̨���еĽ����б�������
 * �ڲ�ʹ��bg_app_infos��ָ���ڴ�ʱ���������vm_release_app_running_infos�ͷ�
 * exist_app_infos��ָ��Ķ���
 *
 * @code 
 * VMINT ret = VM_EXECUTE_APP_SUCCESS;
 * VMUINT infos_num = 0;
 * vm_running_app_info_t* infos = NULL;
 * 
 * ret = vm_execute_app((VMWSTR)L"c:\\vre\\game.vxp", &infos, &infos_num);
 * switch (ret)
 * {
 * case VM_EXECUTE_APP_NOT_ENOUGH_MEMORY:
 *     // ��ʾ�û��˳�Ӧ�ÿ���������Ӧ�á�
 *     if (infos != NULL)
 *     {
 *         vm_release_app_running_infos(infos);
 *     }
 *     break;
 * case VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY:
 *     // ��ʾӦ���޷����У��ڴ��������
 *     break;
 * case VM_EXECUTE_TIMESTAMP_ERROR:
 *     ......
 * }
 * @endcode
 * 
 * @param[in]				filename ��Ҫ�������ļ����ơ�
 * @param[out]			bg_app_infos ���ں�̨���е�Ӧ�ó������Ϣ��
 * @param[out]			app_info_num ���ں�̨���е�Ӧ�ó�����Ϣ������
 * @param[in]				filename ��Ҫ�������ļ����ƣ���Ҫ������·����
 * 
 * @return				�Ƿ�ɹ�������Ӧ�ó���ķ���ֵ��
 * @retval				VM_EXECUTE_APP_SUCCESS ����Ӧ�ó���ɹ���
 * @retval				VM_EXECUTE_APP_ILLEGAL �Ƿ���Ӧ�ó���
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY û���㹻���ڴ�����Ӧ�ó���
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL ���ö�ջ������
 * @retval				VM_EXECUTE_INTERNAL_ERROR �����ں��ڲ�����
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH ƽ̨������ƥ�䡣
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR Ӧ�ó��򳬹���Ч�ڡ�
 * @retval				VM_EXECUTE_BANNED_APP �Ǻ�������Ӧ�ò���������
 * @retval				VM_EXECUTE_IMSI_DISMATCH Ӧ�ó����IMSI����ƽ̨��IMSI��ƥ�䣬����ʧ�ܡ�
 * @retval				VM_EXECUTE_CERT_OVERDUE Ӧ�ó���ʹ�õ�֤����ڡ�
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY VREĿ¼���ļ�����5000�����ظô����롣
 * @retval				VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY Ӧ������Ҫ�ڴ����ϵͳ�޷���������
 * 
 * @see					vm_release_app_running_infos
 */
//VMINT vm_execute_app(VMWSTR filename, vm_running_app_info_t** bg_app_infos, VMUINT* app_info_num);

/**
 * ����������Ӧ�ó���paramΪ�����VMWSTR����ָ�룬����μ�vm_execute_app()˵����
 *
 * @param[in]			filename ��Ҫ�������ļ����ƣ���Ҫ������·����
 * @param[in]			param �����VMWSTR���Ͳ���ָ�롣
 * @param[in]			retry_callback �ڷ���VM_EXECUTE_APP_NOT_ENOUGH_MEMORY��ʱ���������Ӧ���ͷ����ڴ���ú����ᱻ�ص���
 *								������Ӧ���ٵ��ñ�����������Ӧ�á�
 * 
 * @return				�μ�vm_execute_app()˵����
 */
VMINT vm_execute_app_ex(VMWSTR filename, VMWSTR param, void (*retry_callback)(void));

/**
 * �õ���̨Ӧ�ó������Ϣ����� �õ�����Ҫ ���� vm_release_app_running_infos�ͷ�
 * ��̨Ӧ�ó���� ��Ϣ ��
 * 
 * @return					��̨���е�Ӧ�ó���ĸ�����
 * @param[out]				bg_app_infos ���ں�̨���е�Ӧ�ó������Ϣ��
 */
VMINT vm_get_bg_app_infos(vm_running_app_info_t** bg_app_infos);

/**
 * �ͷ��ɵ���vm_execute_ext�����������������е�Ӧ�ó�����Ϣ��
 *
 * @param[in]				app_infos Ӧ�ó�����Ϣ��
 * @see					vm_execute_ext
 */
void vm_release_app_running_infos(vm_running_app_info_t* app_infos);

/**
 * ��ֹӦ�ó���ɹ���
 */
#define VM_TERMINATE_SUCCESS					(0)

/**
 * ��������
 */
#define VM_TERMINATE_ERROR_PARAM				(-1)

/**
 * ��Ҫ��ֹ��Ӧ�ó��򲻴��ڡ�
 */
#define VM_TERMINATE_NOT_EXISTS				(-2)

/**
 * ֹͣ��ǰ̨���еĽ��̡�
 */
#define VM_TERMINATE_ERROR_STATUS			(-3)

/**
 * ��ֹ��̨���е�Ӧ�ó���
 * 
 * @code
 * vm_terminate_bg_app((VMWSTR)L"c:\\vre\\game.vxp");
 * @endocde
 * @param[in]					filename ��Ҫ��ֹ��Ӧ�ó�������ƣ��Ǿ���·����
 * @return					�Ƿ�ɹ���ֹӦ�ó���ı�־��
 * @retval					VM_TERMINATE_SUCCESS �ɹ���ֹӦ�ó���
 * @retval					VM_TERMINATE_ERROR_PARAM ��������
 * @retval					VM_TERMINATE_NOT_EXISTS ָ����Ӧ�ó��򲻴��ڡ�
 * @retval					VM_TERMINATE_ERROR_STATUS ֹͣ��Ӧ�ó�������ǰ̨���У���ֹӦ��
 *							����ʧ�ܡ�
 */
VMINT vm_terminate_bg_app(VMWSTR filename);

/**
 * ���VRE����Ӧ���������У����ñ�������û������;
 * ���VREû�����е��ñ�����Ҳû���κ�����;
 * ���VREû��Ӧ������������VRE���������ɹ���
 * ���ñ������ὫVRE�����˳���
 */
void vm_vam_unload_core(void);

#define		VAM_IN_USE					1
#define		VAM_OUT_OF_USE			0

/*
 * ֪ͨ�ں�VAM��״̬
 *  
 * @param[in] 			VAM_IN_USE ��ʾVAM�������У�VAM_OUT_OF_USE ��ʾVAM�Ѿ��˳���
*/
void vm_vam_set_vam_state(VMINT state);

/**
 * VAM ��VRE�����ڴ档
 * 
 * @param[in]				size ��Ҫ������ڴ�����
 * @return				NULL ����ʧ�ܣ�����Ϊ�ڴ���׵�ַ��
 */
void* vm_vam_malloc(VMINT size);

/**
 * VAM �ͷ��ڴ�ʱ���á�
 * 
 * @param[in]				p ��Ҫ�ͷŵ��ڴ��׵�ַ��  
 */
void vm_vam_free(void* p);

/**
 * ���·���VAM�ڴ棬����������ڴ泤��С��ԭ���ڴ泤�ȣ�ϵͳ�����κ�
 * ������������ڴ����󵽸������ȣ��ڴ��е����ݼ�������������ط���ɹ���
 * ������Ҫ����vm_vam_free�ͷ�pָ�롣ʾ������:
 * 
 * @code
 * char* ptr = vm_vam_malloc(1024), *tmp = NULL;
 * 
 * if (ptr != NULL)
 * {
 * 	memset(ptr, 0x00, 1024);
 * 	ptr[0] = 'C';
 *	if ((tmp = vm_vam_realloc(ptr, 2048)) != NULL)
 *    {
 *    		tmp[2047] = 'J';
 * 		vm_vam_free(tmp);
 *	}
 *	else
 *	{
 *		vm_vam_free(ptr);
 *	}
 * }
 * @endcode
 * @param[in] 			p Ҫ���·�����ڴ�ָ�롣
 * @param[in] 			size	�µĳ��ȡ�
 *
 * @return				����NULL��ʾ���·���ʧ�ܣ��������ڴ�ָ��
 *						ָ����ڴ治�ͷţ����򷵻���չ����ڴ�
 *						ָ�롣
 */
void* vm_vam_realloc(void* p, VMINT size);

/*
 * �ж�Ӧ�ó����Ƿ������С�
 *
 * @param[in]				vxp_filename	Ӧ�õ��ļ�����������ȫ·����
 * @return				���Ӧ�ó����������У�����1�����򷵻�0��
 */
VMINT vm_vam_app_is_running(VMWSTR vxp_filename);

#define		LOAD_VAM_RES_PARAM_ERROR				(-1)
#define		LOAD_VAM_RES_FAIL							(-2)
#define		LOAD_VAM_RES_INSUFFICIENT_BUF			(-3)

/*
 * ���ļ���װ��ָ������Դ
 *  
 * @param[in]					filename �ļ������ơ�
 * @param[in] 				res_name ��Դ���ơ�
 * @param[out]				res_size ������Դ���ȵ�ָ�롣
 * @param[in]					cache_buf �ⲿ���� ��
 * @param[in] 				cache_size �ⲿ����ĳ��ȡ�
 * @return					������Դ�ɹ�����0, ���򷵻ظ����Ĵ����롣
*/
int vm_vam_load_resource_from_file( short * filename, char * res_name, int * res_size, char * cache_buf, int cache_size );

/**
 * �������͡�
 */
typedef enum LANGUAGE_TYPE{
	ENG = 0,		/**<Ӣ�			*/
	CHS,		/**<�������ġ� 	*/
	CHT			/**<�������ġ� 	*/
}LANGUAGE_TYPE;

/**
* �������ļ��л�ȡGIF�������ڴ档���unpackGIFZM.h��unpackGIFZM3.c
* 
* @param[in] 					gifzm ����Դ��
* @param[out] 				data_buf �������ݵĻ��档
* @param[out] 				data_len ����GIF���ݳ��ȡ�
* @return					�ɹ�ʱ����0�����򷵻ظ����Ĵ����롣
*							��data_bufΪ��ʱ���ýӿڲ�ѯ����Ҫ��ȡ�����ݵĴ�С����data_len���ء�
*							��data_buf��Ϊ��ʱ��data_len�ĳ�ʼֵΪdata_buf�Ĵ�С, 
*							�ӿ�ִ���꣬data_len�������ݵ�ʵ�ʴ�С��
*/
VMINT vm_vam_get_gif_data(VMUINT8 *gifzm, VMUINT8 ** data_buf, VMINT *data_len);

/**
* �������ļ��л�ȡ�ַ����������ڴ档���unpackGIFZM.h��unpackGIFZM3.c
* 
* @param[in]					gifzm ����Դ��
* @param[out]				data_buf �������ݵĻ��档
* @param[in]					lan �������͡�
* @param[out]				data_len ����string���ݳ��ȡ�
* @param[out]				font �����ַ��������С��
* @param[out]               data_size ��ģsize
* @return					�ɹ�ʱ����0�����򷵻ظ����Ĵ����롣
*							��data_bufΪ��ʱ���ýӿڲ�ѯ����Ҫ��ȡ�����ݵĴ�С����data_len���ء�
*							��data_buf��Ϊ��ʱ��data_len�ĳ�ʼֵΪdata_buf�Ĵ�С, 
*							�ӿ�ִ���꣬data_len�������ݵ�ʵ�ʴ�С��
*/
VMINT vm_vam_get_string_data(VMUINT8* gifzm, VMUINT8** data_buf, LANGUAGE_TYPE lan, VMINT* data_len, VMINT* font, VMINT *data_size);


/**
 * ��ȡ���ؿ��
 * @param[in] zimo_buf ָ����ģ���ݵ�ָ�� 
 * @param[in] str_len �ַ����� 
 *
 * @return  ��ģ�����ؿ�� 
 */
VMINT vm_vam_measure_zimo_string(VMUINT8 *zimo_buf, VMINT str_len);

/**
* ���ַ��������ȡ���ݻ��Ƶ�Ŀ�껺���С�
* 
* @param[out]				dst_buf Ŀ�껺��
* @param[in] 					x �ַ��������ϽǺ�����
* @param[in]					y �ַ��������Ͻ�������
* @param[in]					start_idx ��ʼλ��Index��Index��0��ʼ
* @param[in]					out_str_len ����ַ������ȣ�����С��ʵ���ַ�������
* @param[in]					src_buf �ַ�������
* @param[in]					str_len �ַ���ʵ�ʳ���
* @param[in]					font �ַ��������С
* @param[in]					color �ַ���ǰ����ɫ���ַ����հ�������͸����ʽ����
*/ 
void vm_vam_draw_text(VMUINT8 *dst_buf, VMINT x, VMINT y, VMINT start_idx, VMINT out_str_len, VMUINT8 *src_buf, VMINT str_len, VMINT font, VMUINT16 color);

/**
 * �����ʱ�ļ��Ƿ�Ϸ������ؽ��ȡ�
 * 
 * @param[in]					filename ��ʱ�ļ������ơ�
 * @param[out]				progress	���ܽ������ݵ�ָ�롣 
 * @return					�����ʱ�ļ��Ϸ�����0, ���򷵻ظ����Ĵ����롣
 *							����0ʱ, progressָ������ݴ�����ȣ�0 - 100����
*/
VMINT vm_vam_check_tempfile(VMSHORT * filename, VMINT* progress);

/**
 * ȡ�����ء�
 */
void vm_vam_cancel_download(void);

/**
 * ����SIM����
 *
 * @param[in]					choose_index ѡ�е�SIM����ţ�1ΪSIM��һ��2ΪSIM������
 * @return                                	���óɹ�����0�����򷵻�-1
 */
VMINT vm_vam_set_sim_card(VMINT choose_index);

/**
 * �����������͡�
 *
 * @param[in]					net_type �������ͣ�1ΪGPRS��2ΪWIFI��
 * @return                             	���óɹ�����0�����򷵻�-1
 */
VMINT vm_vam_set_net_type(VMINT net_type);

/**
 * �õ���ǰ�Ѿ����õĿ���������
 * 
 * @param[out]				�õ���������ָ�롣
 * @return					�Ƿ�ɹ��õ�SIM�������ı�־��
 * @retval					TRUE(1) �ɹ��õ�SIM��������
 * @retval					FALSE(0) ʧ�ܣ�û�еõ�SIM��������
 */
VMINT vm_vam_get_sim_card(VMINT* sim_index);

/**
 * �õ���ǰ�������͡�
 * 
 * @param[out]				�õ��������͵�ָ�롣
 * @return					�Ƿ�ɹ��õ��������͵ı�־��
 * @retval					TRUE(1) �ɹ��õ��������͡�
 * @retval					FALSE(0) ʧ�ܣ�û�еõ��������͡�
 */
VMINT vm_vam_get_net_type(VMINT* net_type);

/**
 * �����������ӵ㡣
 * 
 * @param[in] 				point_type ���ӵ����ͣ�1ΪCMWAP��2ΪCMNET��
 * @return                             	���óɹ�����0�����򷵻�-1
 */
//VMINT vm_vam_set_connection_point(VMINT point_type);

/**
 * ��֤Ӧ�ó����Ƿ���Ч
 * 
 * @param[in]					vxp_filename VXP�ļ����ļ�������ȫ·��
 * @return					Ӧ�ó�����֤ͨ��,����0, ���򷵻ظ����Ĵ����롣�ο�vmcerter.h
 */
VMINT vm_vam_app_is_valid(VMWSTR vxp_filename);

#define  VAM_DL_DONE             	1  //����VXP�������
#define  VAM_DL_OK               		0  //�ɹ�
#define  VAM_DL_ERR              		-1 //ʧ��
#define  VAM_DL_NET_ERR         	-2 //�������         
#define  VAM_DL_SAVE_ERR         	-3 //�������
#define  VAM_DL_APP_NOT_EXIST  -4 //Ӧ�ò�����
#define  VAM_DL_SPACE_FULL       	-5 //�ռ䲻��
#define  VAM_DL_OTHER_ERR        	-6 //��������
#define  VAM_DL_FILE_NOT_EXIST -7 //�ļ�������
#define  VAM_DL_IO_ERROR        -8 //I/O ��������

#define VAM_DL_1302_ERR -9
#define VAM_DL_1401_ERR -10
#define VAM_DL_1402_ERR -11
#define VAM_DL_1403_ERR -12
#define VAM_DL_1404_ERR -13
#define VAM_DL_1405_ERR -14
#define VAM_DL_1406_ERR -15
#define VAM_DL_1407_ERR -16

//rencai.xiao 2010/04/28 
//download payment notification and rate.
#define AM_DOWNLOAD_PAYMENT_NOTIFICATION

//added by rencai.xiao 2010/05/28 ���Ӵ��󷵻�����
#define  VAM_DL_1302_ERR       -9 //����������Ĳ����д���ʱ������û�д�AppId��
#define  VAM_DL_1401_ERR      -10//�����صĲ�Ʒ������ʱ��һ���ǿͻ��˵�AppId������߲�Ʒû������û��͵İ汾��
#define  VAM_DL_1402_ERR      -11//������͵Ĳ�Ʒ�汾��û���ϴ���Ӧ���ļ���һ�㲻�ᷢ������Ϊ��̨��Ӱ汾ʱǿ�Ʊ����ϴ��ļ���
#define  VAM_DL_1403_ERR      -12//����汾���ļ������ڣ�һ�㲻�ᷢ����Ӧ����һЩ�����������ļ���ʧ��
#define  VAM_DL_1404_ERR      -13//�ļ�MD5У�������һ�㷢�����������ص��ļ����ʱ��Ŀǰû�з��ظô����룬����ֱ�ӷ������ļ���MD5У���룬�ͻ���ֱ�����������ļ���
#define  VAM_DL_1405_ERR      -14//�ļ�������������ݶγ�����ʵ���ļ��ķ�Χ������������ᷢ����
#define  VAM_DL_1406_ERR      -15//��Ʒ�������������
#define  VAM_DL_1407_ERR      -16//��1401����������ֿ���1401��ʾAppId�����ڣ�1407��ʾ������汾��

//added by rencai.xiao 2010/06/03 twice confirm
#define AM_SUPPORT_TWICE_CONFIRM

//added by rencai.xiao 2010/06/19 extend pag config, add mcc to vm_charge_detail_record_t and add pre_string and suff_string to vm_pay_config_t
#define AM_SUPPORT_EXTEND_PAY_CONFIG

/**
 * ����Ӧ������* @param download_app_cb     ����Ӧ�ûص�
 *                             @param nResult  ���ؽ��:VAM_DL_OK = �ɹ�����������߳ɹ�������һ��
 *                                                      VAM_DL_DONE = ȫ���������
 *                                                      VAM_DL_ERR�ȴ�����
                                                        VAM_DL_IO_ERROR �ļ���������
														VAM_DL_SPACE_FULL �ռ䲻��
 *                             @param nPercent nResult��ΪVAM_DL_DONEʱ��ʾ���ؽ���,�����ʾ�洢�̷�
 *
 * @param[in] 			    download_app_cb     ����Ӧ�ûص���
 * @param[out] 				nResult  ���ؽ��:VAM_DL_OK = �ɹ�����������߳ɹ�������һ��
 *                                            VAM_DL_DONE = ȫ���������
 *                                            VAM_DL_ERR�ȴ�����
 * @paramp[out] 			nPercent nResult��ΪVAM_DL_DONEʱ��ʾ���ؽ���,�����ʾ�洢�̷�
 * @param[in] 				pszVersionID Ӧ�ð汾��ID��
 * @param[in]				pszFileName �ļ�����
 * @param[in] 				nBlockSize ���ؿ��С��
 * @return                  �ɹ������������󷵻�VAM_DL_OK, ���򷵻ش�����(VAM_DL_ERR, VAM_DL_IO_ERROR, VAM_DL_SPACE_FULL)��
 */
VMINT vm_vam_download_app(void(*download_app_cb)(VMINT nResult, VMINT nPercent), 
	VMUINT32 nAppID/*VMWSTR pszVersionID*/, VMWSTR pszFileName, VMINT nBlockSize);


#define			VMM_RET_NO_SYSC_CDR								(0)
#define			VAM_RET_NVRAM_NEED_FOR_SYNC_CDR				(1)
#define			VAM_RET_TIME_NEED_FOR_SYNC_CDR					(2)

/**
 * �Ƿ���Ҫͬ���Ʒѡ�
 * 
 * @return					�Ƿ���Ҫ���µı�־��
 * @retval					VMM_RET_NO_SYSC_CDR ��ʾ����Ҫ���¡�
 * @retval					VAM_RET_NVRAM_NEED_FOR_SYNC_CDR NVRAM����Ҫ���¡�
 * @retval					VAM_RET_TIME_NEED_FOR_SYNC_CDR ʱ�䵽��Ҫ���¡�
 */
VMINT vm_vam_is_sync_cdr(void);

/**
 * �������ͬ���Ʒ�����
 * 
 * @param[in/out]				sync_cb �ɹ���ʧ�ܵĻص�������nResultΪ0��ʾ�ɹ�����Ϊʧ�ܡ�
 * @return					�ɹ�����ͬ������VAM_DL_OK, ���򷵻ش�����(VAM_DL_ERR, VAM_DL_IO_ERROR)��
 */
VMINT vm_vam_sync_cdr(void (*sync_cb)(VMINT nResult));

/**
 * �õ��û�����
 * 
 * @param[out]				user_balance �û���
 * @return					0 ��ʾ�Ѿ��õ�������Ϊʧ�ܡ�
 */
VMINT vm_vam_get_user_balance(VMUINT* user_balance);

/**
  * ȡ���ƷѸ���
  */
void vm_vam_cancel_sync_cdr(void);
/**
 * ע�������ͷſռ亯��
 *
 * @param mem_calloc_cb   ����ռ�ӿ�
 * @param mem_free_cb     �ͷſռ�ӿ�
 */
void vm_am_pre_download_app(void *(* mem_calloc_cb)(int size), void (* mem_free_cb)(void *ptr));


/**
 * ��ȡӦ�ð汾��
 *
 * @param[in] �ļ���
 * @param[out] �õ��İ汾��
 *
 * @return ��ȡ�ɹ�����VAM_DL_OK�����򷵻�VAM_DL_ERR
 */
VMINT vm_get_app_version(VMWSTR filename, VMINT * version);

/*
 * ������޸��µ�����
 *
 * @return  �����Ӧ�ó���ĸ������󣬷��ظ��������version id,���򷵻�null��
 */
VMWSTR vm_vam_need_update(void);

/*
 * ������£���vam��ȡ���������version id��Ӧ��֪ͨvre������µ�version id��
 */
void vm_vam_clean_update(void);

/**
 * �˳����н��̣��˳�VRE���������VREû����������ñ�����
 * ���������κ����á�
 */
void vm_exit(void);

/**
 * ��ȡ��������Ӧ�õ��ܴ�С�������ش�С
 *
 * @param nTotalSize                      Ӧ���ܴ�С
 * @param nDownloadedSize            �����ش�С
 *
 * @return       ��ȡ�ɹ�����VAM_DL_OK�����򷵻�VAM_DL_ERR
 */
 VMINT vm_get_total_and_downloaded_size(VMUINT * nTotalSize, VMUINT * nDownloadedSize);

/**
 * ASM �����ڴ�Ĳ�����callback������
 */
void vm_exit_by_asm(void);

/**
 * ������ó����׵�ַ�б�
 * 
 * @param[out]			app_array_ptr ���ó����׵�ַ�б��ָ�롣
 * @param[out]			app_array_len_ptr ���ó��������
 */
void vm_get_buildin_app_array(VMINT** app_array_ptr, VMINT* app_array_len_ptr);

/**
 * ���VRE�Ƿ���ʹ��media memory.
 * 
 * @return ����ʹ�÷���1�����򷵻�0

 */
VMINT mmi_vre_is_using_media_memory(void);


VMINT vm_get_current_apn_info(vm_apn_info_ext *current_apn_info);

/************************************************************************
* �ڴ�����¼���ĺ�����
************************************************************************/

#include "che_api.h"

/*
 * ��ʼ��md5��״̬���ڵ���vm_vam_md5_append֮ǰ������ñ�������
 *
 * @code 
 * md5_context md5_context;
 * vm_vam_md5_init(&md5_context);
 * vm_vam_md5_append(&md5_context, data, data_len);
 * vm_vam_md5_append(&md5_context, data2, data2_len);
 * ......
 * vm_vam_md5_finish(&md5_context, digest);
 * @endcode
 * @param[in]				md5_context  ����ժҪʱ�������ġ�
 */
void vm_vam_md5_init(STCHE* md5_context);

/**
 * ����Ҫ�õ�ժҪ�����ݽ�����ӡ�
 * 
 * 
 * @param[in]				md5_context ����ժҪʱ�������ġ�
 * @param[in]				data ��Ҫ�õ�ժҪ�����ݡ�
 * @param[in]				nbytes data��ָ����ֽڸ�����
 */
void vm_vam_md5_append(STCHE* md5_context, const VMUINT8* data, VMUINT nbytes);

/**
 * �õ�ժҪ���ݡ�
 * 
 * @param[in]				md5_context ����ժҪʱ�������ġ�
 * @param[out]			md5_digest ժҪ��Ϣ��
 * 
 */
void vm_vam_md5_finish(STCHE* md5_context, VMUINT8 md5_digest[16]);

/**
 * ����DES��Կ��
 * 
 * @code
 * vm_vam_des_set_key(&ctx, des_key);
 * @endcode
 * @param[in]				des_context DES���ܻ����ʱ�������ġ�
 * @param[in]				key8�ֽڵ���Կ��
 * @return				0  ��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_vam_des_set_key(STCHE* des_context, VMUINT8 key[8]);

/**
 * ��DES�㷨�������ݡ�
 * 
 * @param[in]				des_context DES���ܻ����ʱ�������ġ�
 * @param[in]				input �׵�ַ������8�ֽڶ�����ڴ��ַ��input & 7 ����Ϊ0��
 * @param[in]				input_len ��Ҫ�������ݵĳ��ȡ�
 * @param[out]			output �׵�ַ������8�ֽڶ�����ڴ��ַ��output & 7 ����Ϊ0��
 * 						��ָ��ĳ���Ϊ(input_len / 8 + 1) * 8
 * @return				0 ��ʾ���ܳɹ������򷵻ش����롣
 */
VMINT vm_vam_des_encrypt(STCHE* des_context, 
	VMUINT8* input, VMUINT input_len, VMUINT8* output);

/**
 * ��DES�㷨�������ݡ�
 * 
 * @param[in]				des_context DES���ܻ����ʱ�������ġ�
 * @param[in]				input �׵�ַ������8�ֽڶ�����ڴ��ַ��input & 0x7 ����Ϊ0��
 * @param[in]				input_len ��Ҫ�������ݵĳ��ȡ�
 * @param[in]				output �׵�ַ������8�ֽڶ�����ڴ��ַ��output & 7 ����Ϊ0��
 * 						��ָ��ĳ���Ϊ(input_len  / 8 + 1) * 8
 * @param[out]			output_len ���ܳ��������ĵ��ֽ�����
 * @return				0 ��ʾ���ܳɹ������򷵻ش����롣
 */
VMINT vm_vam_des_decrypt(STCHE* des_context, 
	VMUINT8 * input, VMUINT input_len, VMUINT8* output, VMUINT* output_len);

/**
 * ����DES״̬���ڼ��ܻ������󶼱�����ñ�������
 * 
 * @param[in]				des_context ���ܻ����ʱ�������ġ�
 */
void vm_vam_des_reset_key(STCHE* des_context);

/**
 * װ����Դ�����resΪNULL������ñ������õ���Ϊres_size�Ĵ�С��
 *
 * @code
 * VMUINT res_size = 0;
 * char* res_buffer = NULL;
 * vm_vam_load_resource((VMSHORT*)L"d:\\vre\\cc.vxp", "icon.gif", NULL, &res_size); 		//�õ�Resource�Ĵ�С��
 * res_buffer = adm_malloc(res_size);
 * vm_vam_load_resource((VMSHORT*)L"d:\\vre\\cc.vxp", "icon.gif", res_buffer, &res_size);	//�õ�Resource.
 * @endcode
 * @param[in]	 			filename �ļ����ơ�
 * @param[in]				res_name ��Դ���ơ�
 * @param[out]			res ��Ҫ������Դ�����ݵ�ͷָ�롣
 * @param[out]			res_size res��ָ���ڴ�Ĵ�С��
 * @return				0 ��ʾȡ����Դ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_vam_load_resource(VMSHORT * filename, VMCHAR* res_name, 
	VMCHAR* res, VMUINT* res_size);

/*
 * ��ñ���ļ���ָ���ı�����ݡ����buff����ΪNULL ����ֻȡ�ø�TAG�Ĵ�С��
 * 
 * 
 * @param[in] 			filename �ļ����ơ�
 * @param[in]				tag_id  ��Ҫ��ȡTAG��ID��
 * @param[out]			buf ��õı������
 * @param[in/out]			buf_size	������ݵĳ���
 *	
 * @return				0 ��ʾ�õ�TAG�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_vam_get_tag(VMWCHAR* filename, VMINT tag_id, void* buf , int* buf_size);

typedef enum
{
	VM_VAM_LANG_ENG = 1,
	VM_VAM_LANG_CHS,
	VM_VAM_LANG_CHT
}VM_VAM_LANG_ID;

/*
 * �����������ͣ���ñ���ļ���ָ���ı�����ݡ�
 * ���buff����ΪNULL ����ֻȡ�ø�TAG�Ĵ�С��
 *  
 * @param[in] 			filename �ļ����ơ�
 * @param[in] 			tag_num  ��Ҫ��ȡ�ı����š�
 * @param[out] 			buf ��õı�����ݡ�
 * @param[in/out] 			buf_size ������ݵĳ��ȡ�
 * @param[in]		 		lang_id �������ͣ�ΪVM_VAM_LANG_ID ���͡�
 *	
 * @return				0 ��ʾ�ɹ��õ���ǣ�����Ϊʧ�ܡ�
*/
VMINT vm_vam_get_tag_by_lang_id(VMWCHAR* filename, VMINT tag_num, 
	void* buf, VMINT* buf_size, VMINT lang_id);


//added by rencai.xiao 2010/07/22 ����˺��ʾ֧��gzipѹ��
#define   AM_SUPPORT_GZIP

/**
 * �ͻ�ע���������������size�Ļص�
 *
 * @param nResult           �������������ʧ�ܸ�ֵΪVAM_DL_ERR�������ɹ���ֵΪVAM_DL_OK
 * @param pData             ��������,��ʽ��VIPЭ��
 * @param nDataLen          pData���ݳ���
 */
typedef void(*check_filesize_cb)(VMINT nResult, VMUINT8* pData, VMINT nDataLen);


/**
 * �������size
 *
 * @check_cb           �����ص�
 * @pCheckList         Ҫ��������ID�б���ʽ:��ID֮����","�������磺appstore,sm_charge,172111,....
 *
 * @return             �ɹ�����VAM_DL_OK, ���򷵻�VAM_DL_ERR
 */
VMINT vm_vam_check_filesize(check_filesize_cb check_cb, VMUINT8 * pCheckList);


/**
 *�ͻ�ע�������ģ���⶯̬��汾�Ļص�
 *
 * @param nResult     �������������ʧ�ܸ�ֵΪVAM_DL_ERR, �����ɹ���ֵΪVAM_DL_OK
 * @param pData       �������ݣ���ʽ��VIPЭ��
 * @param nDataLen    pData���ݳ���
 */
typedef void(*check_dll_version_cb)(VMINT nResult, VMUINT8 * pData, VMINT nDataLen);


/**
 * ��⶯̬��汾
 *
 * @param check_dll_cb        �����ص�
 * @param pCheckList          Ҫ���İ汾�б���ʽΪSMID:Version, ���ʱ�м���","�ָ�����:sm_charge:3.0.0,....
 *
 * @return                    �ɹ�����VAM_DL_OK,���򷵻�VAM_DL_ERR
 */
VMINT vm_vam_check_dll_version(check_dll_version_cb check_dll_cb, VMUINT8 * pCheckList);


/**
 *  ȡ��check������check filesize ����dll vresionʱ���жϻ���ȡ�����Ե��ô˽ӿ�
 */
void vm_vam_cancel_check(void);
#ifdef __cplusplus
}
#endif
#endif
