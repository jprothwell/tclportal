#ifndef __VM_PAYMENT_REGISTER_IO
#define __VM_PAYMENT_REGISTER_IO

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmbilling.h"

/**
 * �Ʒ�ע���ļ��Ŀ�ʼ���֡�
 */
#define PAYMENT_REG_FILENAME_START_PARTY		"PRF_"

/**
 * �Ʒ�ע���ļ��ĺ�׺��
 */
#define PAYMENT_REG_FILENAME_SUFFIX				".REG"

/**
 * �Ʒ�ע���ļ��İ汾�š�
 */
#define PAYMENT_REG_FILE_VERSION_NUM			(1)

/**
 * @name �Ʒ�ע���ļ�������ģʽ��
 * @{
 */
/**
 * ������ѡ�
 */
#define TRAIL_MODE_TIME						(1)
/**
 * ������ѡ�
 */
#define TRAIL_MODE_DATE						(2)
/**
 * �������Ϣ��
 */
#define TRAIL_MODE_NONE						(3)
/** @} */

/**
 * @name �Ʒ�ģʽ��
 * @{
 */
/**
 * ����Ʒ�ģʽ��
 */
#define PAYMENT_MODE_DATE		PAYMENT_MODE_BY_DATE
/**
 * ���μƷ�ģʽ��
 */
#define PAYMENT_MODE_TIME		PAYMENT_MODE_BY_TIME
/**
 * ���ģʽ��
 */
#define PAYMENT_MODE_FOREVER	PAYMENT_MODE_BY_FOREVER
/** @} */

/**
 * @name �Ʒ�ע���ļ������ķ���ֵ��
 * @{
 */
#define PAY_REG_PROCESS_SUCCESS					(0)
#define PAY_REG_ERR_IO									(-1)
#define PAY_REG_ERR_PARAM								(-2)
#define PAY_REG_ERR_FILE_VERSION				(-3)
#define PAY_REG_ERR_INTERNAL_ERROR				(-4)
#define PAY_REG_ERR_FILE_INVALIDATE				(-5)
#define PAY_REG_ERR_FILE_NOT_EXIST				(-6)
#define PAY_REG_ERR_FILE_SYSTEM_NO_SPACE		(-7)
#define PAY_REG_ERR_NO_MEMORY					(-8)
#define PAY_REG_ERR_PAYMENT_RECORD_NOT_EXITS	(-9)
/** @} */

/**
 * @struct vm_payment_record_t
 * @brief 
 */
typedef struct 
{
	VMINT app_payment_id;		/**<Ӧ�ó����ڲ�ID��				*/
	VMUINT payment_mode;		/**<�Ʒ�ģʽ��						*/
	VMUINT payment_value;		/**<ʣ��Ĵ������ֹ���ڡ�			*/
} vm_payment_record_t;

/**
 * ָ���ļƷ��ļ����ļ����Ƿ���ڡ�
 * 
 * @param[in]			filename ��·���ļƷ�ע���ļ����ơ�
 * @param[out]			is_exists ָ�����ļ��Ƿ���ڡ�
 * @return				�ɹ����
 * @retval				PAY_REG_PROCESS_SUCCESS �ɹ���
 * @retval				PAY_REG_ERR_PARAM ����Ĳ�����
 */
VMINT vm_payment_reg_file_is_exist(VMWCHAR* filename, VMINT* is_exists);

/**
 * ָ�����ƼƷ�ע���ļ��Ƿ�Ϸ��� 
 *
 * @param[in]			filename ��·���ļƷ�ע���ļ����ơ�
 * @param[out]			is_validate �Ƿ�Ϸ���
 * @param[in]			random ������֤�Ʒ��ļ��Ƿ�Ϸ���PADDING����
 * @return				��֤�Ƿ�ɹ�������Ϊ��Ӧ�Ĵ����롣
 * @retval				PAY_REG_PROCESS_SUCCESS �ɹ���
 * @retval				PAY_REG_ERR_PARAM ����Ĳ�����
 * @retval				PAY_REG_ERR_FILE_NOT_EXIST ָ�����ƵļƷ�ע���ļ������ڡ�
 * @retval				PAY_REG_ERR_IO �ļ�IO����
 * @retval				PAY_REG_ERR_NO_MEMORY �ڲ�������ʧ�ܡ�
 */
VMINT vm_payment_reg_file_is_validate(VMWCHAR* filename, VMINT* is_validate, VMUINT8 random[8]);

/**
 * ����ƷѼ�¼������Ʒ�ע���ļ��������򴴽�֮���ڱ���ָ���ļƷѼ�¼ǰ��Ҫ��֤��
 * �ļƷѼ�¼�ļ��Ƿ�Ϸ���������Ϸ��򷵻�PAY_REG_ERR_FILE_INVALIDATE������Ʒ�
 * ע���ļ��Ѿ����ڣ���old_random������Ӧ��ΪNULL������᷵��PAY_REG_ERR_PARAM��
 * 
 * @param[in]			filename ��·���ļƷ�ע���ļ����ơ�
 * @param[in]			record �ƷѼ�¼��
 * @param[in]			old_random ������֤�ɵļƷ�ע���ļ��Ƿ�Ϸ���PADDING����
 * @param[in]			new_random �����µ���֤��Ϣ��PADDING����
 * @return				����ƷѼ�¼�Ƿ�ɹ���
 * @retval				PAY_REG_PROCESS_SUCCESS �ɹ���
 * @retval				PAY_REG_ERR_PARAM ����Ĳ�����
 * @retval				PAY_REG_ERR_FILE_SYSTEM_NO_SPACE �ļ�ϵͳû�пռ䡣
 * @retval				PAY_REG_ERR_FILE_INVALIDATE �Ƿ��ļƷ�ע���ļ���
 * @retval				PAY_REG_ERR_IO �ļ�IO����
 * @retval				PAY_REG_ERR_INTERNAL_ERROR �ڲ�����
 * @retval				PAY_REG_ERR_NO_MEMORY �ڴ治����
 */
VMINT vm_save_payment_information(VMWCHAR* filename, vm_payment_record_t* record, 
	VMUINT8 old_random[8], VMUINT8 new_random[8]);

/**
 * ����ָ�����ļ�����Ӧ�ó����ڲ��Ʒѵ��ţ�װ�ؼƷѼ�¼��
 * 
 * @param[in]			filename ��·���ļƷ�ע���ļ����ơ�
 * @param[in]			app_payment_id Ӧ�ó����ڲ��Ʒѵ�ID��
 * @param[out]			record �ƷѼ�¼��
 * @param[in]			random ������֤�ɵļƷ�ע���ļ��Ƿ�Ϸ���PADDING����
 * @return				װ��ָ���ƷѼ�¼
 * @retval				PAY_REG_PROCESS_SUCCESS �ɹ����
 * @retval				PAY_REG_ERR_PAYMENT_RECORD_NOT_EXITS ָ��app_payment_id�ļƷѼ�¼
 *						�����ڡ�
 * @retval				PAY_REG_ERR_PARAM ����Ĳ�����
 * @retval				PAY_REG_ERR_FILE_NOT_EXIST �ļ������ڡ�
 * @retval				PAY_REG_ERR_FILE_INVALIDATE �Ƿ��ļƷ�ע���ļ���
 * @retval				PAY_REG_ERR_IO �ļ�IO����ʧ�ܡ�
 * @retval				PAY_REG_ERR_NO_MEMORY �ڴ治����
 * @retval				PAY_REG_ERR_PAYMENT_RECORD_NOT_EXITS ָ����Ӧ�ó����ڲ��Ʒѵ�IDû����
 *						����Ӧ�ƷѼ�¼��
 */
VMINT vm_load_payment_information(VMWCHAR* filename, VMINT app_payment_id, 
	vm_payment_record_t* record, VMUINT8 random[8]);

/**
 * װ��ʹ�������Ϣ��
 * 
 * @param[in]			filename ��·���ļƷ�ע���ļ����ơ�
 * @param[out]			trail_mode ����ģʽ��
 *						TRAIL_MODE_NONEû�������Ϣ��TRAIL_MODE_TIME���Σ�TRAIL_MODE_DATE���졣
 * @param[out]			trail_value ���õ�ֵ��
 * @param[in]			random ������֤�ɵļƷ�ע���ļ��Ƿ�Ϸ���PADDING����
 * @return				װ�������Ϣ�ɹ����
 * @retval				PAY_REG_PROCESS_SUCCESS �����ɹ���
 * @retval				PAY_REG_ERR_PARAM ����Ĳ�����
 * @retval				PAY_REG_ERR_FILE_NOT_EXIST ָ�����ƵļƷ���ע���ļ������ڡ�
 * @retval				PAY_REG_ERR_IO �ļ�IO����ʧ�ܡ�
 * @retval				PAY_REG_ERR_FILE_INVALIDATE	�Ʒ�ע���ļ��Ƿ���
 * @retval				PAY_REG_ERR_NO_MEMORY �ڴ治�㣬�޷�ִ�С�
 */
VMINT vm_load_trail_information(VMWCHAR* filename, VMUSHORT* trail_mode, 
	VMUINT* trail_value, VMUINT8 random[8]);

/**
 * ����ʹ�������Ϣ������Ʒ�ע���ļ��������򴴽�֮���ڱ���ָ���������Ϣǰ��Ҫ��֤��
 * �ļƷѼ�¼�ļ��Ƿ�Ϸ���������Ϸ��򷵻�PAY_REG_ERR_FILE_INVALIDATE������Ʒ�
 * ע���ļ��Ѿ����ڣ���old_des_key������Ӧ��ΪNULL������᷵��PAY_REG_ERR_PARAM�� 
 * 
 * @param[in]			filename ��·���ļƷ�ע���ļ����ơ�
 * @param[in]			trail_mode ����ģʽ��
 *						TRAIL_MODE_NONEû�������Ϣ��TRAIL_MODE_TIME���Σ�TRAIL_MODE_DATE���졣
 * @param[in]			trail_value ������ģʽ��ص����õ�ֵ��
 * @param[in]			old_random ������֤�ɵļƷ�ע���ļ��Ƿ�Ϸ���PADDING����
 * @param[in]			new_random �����µ���֤��Ϣ��PADDING����
 * @return				���������Ϣ�ɹ����ı�־��
 * @retval				PAY_REG_PROCESS_SUCCESS �����ɹ���
 * @retval				PAY_REG_ERR_PARAM ����Ĳ�����
 * @retval				PAY_REG_ERR_IO �ļ�IO����ʧ�ܡ�
 * @retval				PAY_REG_ERR_FILE_SYSTEM_NO_SPACE û���㹻�Ŀռ䴴���Ʒ�ע���ļ���
 * @retval				PAY_REG_ERR_FILE_INVALIDATE	�Ʒ�ע���ļ��Ƿ���
 * @retval				PAY_REG_ERR_NO_MEMORY û���㹻�ڴ档
 * @retval				PAY_REG_ERR_INTERNAL_ERROR �ڲ�����
 */
VMINT vm_save_trail_information(VMWCHAR* filename, VMUSHORT trail_mode, VMUINT trail_value, 
	VMUINT8 old_random[8], VMUINT8 new_random[8]);

/**
 * ɾ���Ʒ�ע���ļ���
 * 
 * @param[in]			filename ��·���ļƷ�ע���ļ����ơ�
 * @return				ɾ���Ʒ�ע���ļ��Ƿ�ɹ���
 * @retval				PAY_REG_PROCESS_SUCCESS �ɹ�ɾ����
 * @retval				PAY_REG_ERR_PARAM ����Ĳ�����
 * @retval				PAY_REG_ERR_FILE_NOT_EXIST ָ�����ƵļƷ�ע���ļ������ڡ�
 * @retval				PAY_REG_ERR_IO �ļ�IO����ʧ�ܡ�
 */
VMINT vm_delete_payment_reg_file(VMWCHAR* filename);

#ifdef __cplusplus
}
#endif


#endif