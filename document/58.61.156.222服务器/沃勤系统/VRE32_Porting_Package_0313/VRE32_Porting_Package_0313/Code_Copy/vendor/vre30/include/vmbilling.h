/**********************************************************************************
 * �Ʒ���غ�����ͷ�ļ����Ʒ�������ֻ֧��CMCC(�й��ƶ�)��UNICOM(�й���ͨ)��G���Ʒѣ�
 * �����ṩ���棬�۳�����ѯ�ѼƷ���Ϣ�Ĺ��ܡ�
 * 
 * 
 * @author jie.chen@vogins.com
 * @version 1.3.0
 **********************************************************************************/
#ifndef __BILLING_H__
#define __BILLING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 * Ӧ�ó���Ԥװ���ֻ��
 */
#define PAYMENT_APP_SOURCE_FROM_PREINSTALL		(1)

/**
 * Ӧ�ó���ͨ�����صõ���
 */
#define PAYMENT_APP_SOURCE_FROM_DOWNLOAD		(2)

/**
 * �첽�ƷѺ������ص�״̬������
 */
typedef VMINT CALLBACK_PAYMENT_STATE;

/**
 * @name vm_quick_charge���첽�ص������Ĳ�����
 * @{
 */
/**
 * �Ʒѳɹ���
 */
#define PAYMENT_STATE_SUCCESS				(0)
/**
 * �Ʒ�ʧ�ܡ� 
 */
#define PAYMENT_STATE_FAILED				(-1)

/**
 * �Ʒѱ�ȡ����
 */
#define PAYMENT_STATE_CANCEL				(-2)
/** @} */

/**
 * @name �Ʒ�ģʽ��
 * @{
 */
/**
 * �����շѵ�ģʽ��
 */
#define PAYMENT_MODE_BY_TIME				(1)
/**
 * �����շѵ�ģʽ��
 */
#define PAYMENT_MODE_BY_DATE				(2)
/**
 * ��ϵ�ģʽ��
 */
#define PAYMENT_MODE_BY_FOREVER				(3)
/** @} */

/**
 * @name �Ʒ�������صķ�����
 */
#define PAYMENT_RET_SUCCESS					(0)
#define PAYMENT_RET_IN_DURABILITY			(1)
#define PAYMENT_RET_NEED_PAYMENT			(2)
#define PAYMENT_ERR_NO_SIM_CARD				(-1)
#define PAYMENT_ERR_LACK_FS_SPACE			(-2)
#define PAYMENT_ERR_WRONG_PARAM				(-3)
#define PAYMENT_ERR_NO_MEM					(-4)
#define PAYMENT_ERR_CURRENT_DATE			(-5)
#define PAYMENT_ERR_NOT_EXISTS_PAYMENT_ID	(-6)
#define PAYMENT_ERR_IO						(-7)
#define PAYMENT_ERR_INTERNAL_ERROR			(-8)
/** @} */

/**
 * @name vm_quick_charge���������롣
 * @{
 */
/**
 * ������ѵļƷѵ㽫���ᴥ���Ʒ����̣�����ֱ�ӱ��������ʹ�����
 * ���ڷ���ѵķ��ظ�ֵ���ᴥ���Ʒ����̣��ڼƷѳɹ���Żᱣ�档
 * ����������ʹ�����
 */ 
#define CHARGE_RET_ACCEPT_CHARGE			PAYMENT_RET_SUCCESS
/**
 * ��û�в�SIM����δ֪����Ӫ�̸ô���Ҳ�ᱻ���ء�
 */
#define ERROR_CHARGE_RET_NO_SIM_CARD		PAYMENT_ERR_NO_SIM_CARD
/**
 * ����ļ�ϵͳ��û���㹻�Ŀռ䣬��ô��󽫻ᱻ���ء�
 */
#define ERROR_CHARGE_RET_LACK_FS_SPACE		PAYMENT_ERR_LACK_FS_SPACE
/**
 * �������������ô�ô����뽫�ᱻ���ء�
 */
#define ERROR_CHARGE_RET_WRONG_PARAM		PAYMENT_ERR_WRONG_PARAM
/**
 * �ڴ治����Ʒ�������������ȡ�
 */
#define ERROR_CHARGE_RET_LACK_RESOURCE		PAYMENT_ERR_NO_MEM
/**
 * �ֻ���ǰ���ڴ������ֻ�ϵͳ��������2009/1/1�򱾴����뽫�ᱻ���ء�
 */
#define ERROR_CHARGE_RET_CURRENT_DATE_ERROR	PAYMENT_ERR_CURRENT_DATE
/**
 * ����һЩϵͳ�Դ����µļƷ������ڲ�����
 */
#define ERROR_CHARGE_RET_INT_ERROR			PAYMENT_ERR_INTERNAL_ERROR
/**
 * ��������ֻ������ģ�����ϳ��֡�
 */
#define ERROR_CHARGE_RET_VXP_FILE_ERROR		(PAYMENT_ERR_INTERNAL_ERROR - 1)
/**
 * ����״̬����
 */
#define ERROR_CHARGE_RET_APP_STATE			(PAYMENT_ERR_INTERNAL_ERROR - 2)
/** @} */

/**
 * ���������ڼƷѣ��Ʒ��Ƿ�ɹ������û�����ע�������Ļص��������ݸ�Ӧ�ó���ġ�������ֻ����ǰ̨���á�
 * ���ñ�������������ԼƷ���Ӧ�û��յ���������л�����̨����Ϣ����ʱӦ�ó����ͷ����е�ͼ����Դ����
 * �Ʒ�����ӹܽ�����������롣�ڼƷ��н��ʱ���Ʒ��������Ȼ�ص��Ʒѽ��������Ӧ�û����յ��Ʒѽ����
 * �յ���������л���ǰ̨����Ϣ��
 * @code
 * void myCallBack(VMINT local_payment_id, CALLBACK_PAYMENT_STATE state)
 * {
 *    vm_release_charge_resource();
 *    if (state == PAYMENT_STATE_SUCCESS)
 *    {
 *        vm_save_charge_info("killer", 1, PAYMENT_MODE_BY_TIME, 10);
 *	      game_run();
 *    }
 *    else
 *    {
 *	      // ʧ�ܵĴ����߼���
 *	  }
 * }
 * 
 * VMINT ret = 0;
 * if ((ret = vm_query_charge_info("killer", 1, NULL, NULL, NULL) == QUERY_CHARGE_RET_NEED_PAYMENT))
 * {
 *     VMINT errorCode = 0;
 *     if (errorCode = vm_quick_charge("killer", 1, 100, myCallBack, NULL) == CHARGE_RET_ACCEPT_CHARGE)
 *     {
 *         // ˢӦ�ó�����棬�ȴ��ص��ú�����
 *     }
 *     else
 *     {
 *         // ʧ�ܣ����ݷ��صĴ�������ʾ��
 *     }    
 * }
 * else if (ret == QUERY_CHARGE_RET_IN_DURABILITY)
 * {
 *    vm_deduct_charged_value("killer", 1);
 *    game_run();
 * }
 * else
 * {
 *    // ��ʾʧ��
 * }
 * @endcode
 * @param[in] good_name						��Ҫ�������Ʒ���ƣ����Ϊ12���ַ���
 * @param[in] local_payment_id 				Ӧ�ó����ڲ��Ʒѵ�ID,��Ҫ��ͬһ��Ӧ�ó����ﱣ��Ψһ����ֵӦ�ô�1��ʼ��ţ����������10000��
 * @param[in] price							����������ȡ���õļ۸񣬵�λΪ�֡��������0���ʾ��ѡ����������С��
 *											0,�򽫷���ERROR_CHARGE_RET_WRONG_PARAM�Ĵ���.										
 * @param[in] payment_callback				�û�ע�������Ļص������������NULL��
 * @param[in] extra_content					���ж��ŵĸ�����Ϣ�����Ϊ10���ַ������ܰ����ո�
 * @param[in] charge_flag					TRUE ��ʾӦ�ó�����ļƷѳ������FALSE���ʾӦ�ó��򲻹��ļƷ��Ƿ���ĳɹ���������ó�FALSE��
 *											���ܼӿ�Ʒѻص����ٶȡ�
 * @return									�Ƿ���ܼƷ�����ı�־��
 * @retval									CHARGE_RET_ACCEPT_CHARGE �Ʒ���������˼Ʒ�����
 * @retval									ERROR_CHARGE_RET_NO_SIM_CARD  û��SIM�������ƶ�����ͨ����Ӫ���򱾴����뽫�ᱻ���ء�
 * @retval									ERROR_CHARGE_RET_LACK_FS_SPACE �ļ�ϵͳȱ�ٿռ䡣
 * @retval									ERROR_CHARGE_RET_WRONG_PARAM ���������
 * @retval									ERROR_CHARGE_RET_LACK_RESOURCE ����ڴ治����ƷѶ�����������ô�������뽫�ᱻ���ء�
 * @retval									ERROR_CHARGE_RET_CURRENT_DATE_ERROR �ֻ�ϵͳʱ�����
 * @retval									ERROR_CHARGE_RET_INT_ERROR �Ʒ������ڲ�����
 * @retval									ERROR_CHARGE_RET_VXP_FILE_ERROR app_name����ΪNULL���������ᱻ���أ�
 *											������ֻ����VREģ��������֣����ֻ��ϸò������ᱻ���ԡ�	
 * @retval									ERROR_CHARGE_RET_APP_STATE ���Ӧ�ó�����ǰ̨���ñ���������յ��������롣
 */
VMINT vm_quick_charge(VMWSTR good_name, VMINT local_payment_id, VMINT price, 
	void (*payment_callback)(VMINT local_payment_id, CALLBACK_PAYMENT_STATE state), VMSTR extra_content, VMINT charge_flag);

/**
 * ȡ���Ʒѣ������ͷ�vm_quick_charge����������ļƷ��������в�������Դ������û�����û��ע���
 * ��������ص�������û�е��ñ���������ô�Ʒѹ����е���Դ��һֱ���ڡ�Ӧ�ó���Ӧ�����˳�ǰ���ñ�
 * �������ڼƷѹ����в�Ӧ�õ��ñ�������������������ȡ��һ���ֵĽ����û��޷�ʹ�üƷ��ú��
 * ���ݡ�
 */
void vm_release_charge_resource(void);

/**
 * @name vm_save_charge_info�����ķ����롣
 * @{
 */
/**
 * ����ɹ���
 */
#define SAVE_RET_SUCCESS					PAYMENT_RET_SUCCESS
/**
 * û�в�SIM����δ֪����Ӫ�̡�
 */
#define ERROR_SAVE_RET_NO_SIM_CARD			PAYMENT_ERR_NO_SIM_CARD
/**
 * �ļ�ϵͳȱ�ٿռ䡣
 */
#define ERROR_SAVE_RET_LACK_FS_SPACE		PAYMENT_ERR_LACK_FS_SPACE
/**
 * ����Ĳ�����
 */
#define ERROR_SAVE_RET_WRONG_PARAM			PAYMENT_ERR_WRONG_PARAM
/**
 * �ڴ治�㡣
 */
#define ERROR_SAVE_RET_LACK_RESOURCE		PAYMENT_ERR_NO_MEM
/**
 * ��������ڣ�����ֻ�ϵͳʱ��С��2009/1/1��ô�����󽫻ᱻ���ء�
 */
#define ERROR_SAVE_RET_CURRENT_DATE_ERROR	PAYMENT_ERR_CURRENT_DATE
/**
 * �Ʒ������ڲ�����
 */
#define ERROR_SAVE_RET_INT_ERROR			PAYMENT_ERR_INTERNAL_ERROR
/**
 * ��������ֻ������ģ�����ϳ��֡�
 */
#define ERROR_SAVE_RET_VXP_FILE_ERROR		(PAYMENT_ERR_INTERNAL_ERROR - 1)
/**
 * �޷��õ�IMSI�ţ���ǰ�汾�����뽫���ᱻ���ء�
 */
#define ERROR_SAVE_RET_NOT_GET_IMSI			(PAYMENT_ERR_INTERNAL_ERROR - 2)
/** @} */
/**
 * ����ƷѺ�ļƷ���Ϣ.
 * 
 * @param[in] 				app_name Ӧ�ó������ƣ�����"killer"����Ӧ��ΪNULL������Ҫ����ֵ0��β���ò���ֻ��ģ��������Ч��
 * @param[in]				local_payment_id Ӧ�ó����ڲ��Ʒѵ�ID,��Ҫ��ͬһ��Ӧ�ó����ﱣ��Ψһ����ֵӦ�ô�1��ʼ��ţ����������10000��
 * @param[in]				payment_mode �����ѼƷ���Ϣ�ļƷ�ģʽ��<br/>
 *							<li>PAYMENT_MODE_BY_TIME ��ʾ���Ρ�		</li>
 *							<li>PAYMENT_MODE_BY_DATE ��ʾ���졣		</li>
 *							<li>PAYMENT_MODE_BY_FOREVER ��ʾ��ϡ�	</li>
 * @param[in]				payment_value </br>
 *							<li>���payment_mode����ΪPAYMENT_MODE_BY_TIME�򱾲�����ʾ���ѳɹ����ʹ�ô�����	</li>
 *							<li>���payment_mode����ΪPAYMENT_MODE_BY_DATE�򱾲�����ʾ���ѳɹ����ʹ��������	</li>
 *							<li>���payment_mode����ΪPAYMENT_MODE_BY_FOREVER�򱾲������ᱻ���ԡ�				</li>
 *                          <li>���������Ϊ0���ʾ��ϵ�ģʽ�����Ե�payment_mode������							</li>
 * @return					�Ƿ�ɹ�����Ʒ���Ϣ�ı�־��
 * @retval					SAVE_RET_SUCCESS ����ɹ���
 * @retval					ERROR_SAVE_RET_LACK_FS_SPACE �ļ�ϵͳ�ռ䲻�㣬����ʧ�ܡ�
 * @retval					ERROR_SAVE_RET_WRONG_PARAM ����Ĳ���������ʧ�ܡ�
 * @retval					ERROR_SAVE_RET_LACK_RESOURCE �ڴ治�㣬����ʧ�ܡ�
 * @retval					ERROR_SAVE_RET_CURRENT_DATE_ERROR ����ֻ�ϵͳʱ��С��2009/1/1���򲻴��󽫻ᱻ���أ�����ʧ�ܡ�
 * @retval					ERROR_SAVE_RET_INT_ERROR �Ʒ������ڲ����󣬱���ʧ�ܡ�
 * @retval					ERROR_SAVE_RET_VXP_FILE_ERROR app_name����ΪNULL���������ᱻ���أ�������ֻ����VREģ������
 *							���֣����ֻ��ϸò������ᱻ���ԡ�	
 */
VMINT vm_save_charge_info(VMSTR app_name, VMINT local_payment_id, VMINT payment_mode, VMUINT payment_value);

/**
 * @name vm_deduct_charged_value�����ķ���ֵ
 * @{
 */
/**
 * �۳����������������ɹ�.
 */
#define DEDUCT_CHARGED_RET_SUCCESS								PAYMENT_RET_SUCCESS
/**
 * ָ���ļƷѵ�ID������.
 */
#define ERROR_DEDUCT_CHARGED_RECORD_NOT_FOUND					PAYMENT_ERR_NOT_EXISTS_PAYMENT_ID
/**
 * ��������
 */
#define ERROR_DEDUCT_CHARGED_RET_WRONG_PARAM					PAYMENT_ERR_WRONG_PARAM
/**
 * ����շѹ����е�ȱ����Դ����ô�ô����뽫�ᱻ���ء�
 */
#define ERROR_DEDUCT_CHARGED_RET_LACK_RESOURCE					PAYMENT_ERR_NO_MEM
/**
 * ����ֻ���ϵͳʱ��С��2009��1��1�գ���ô�����ر������롣
 */
#define ERROR_DEDUCT_CHARGED_RET_CURRENT_DATE_ERROR				PAYMENT_ERR_CURRENT_DATE
/**
 * ��SIM����δ֪����Ӫ�̡�
 */
#define ERROR_DEDUCT_CHARGED_RET_NO_SIM_CARD					PAYMENT_ERR_NO_SIM_CARD
/**
 * �Ʒ������ڲ�����
 */
#define ERROR_DEDUCT_CHARGED_RET_INT_ERROR						PAYMENT_ERR_INTERNAL_ERROR
/**
 * �õ�IMSI��ʧ�ܡ�
 */
#define ERROR_DEDUCT_CHARGED_RET_NOT_GET_IMSI					(PAYMENT_ERR_INTERNAL_ERROR - 1)
/**
 * ��������ֻ������ģ�����ϳ��֡�
 */
#define ERROR_DEDUCT_CHARGED_RET_EXEC_FILE_PREFIX_ERROR			(PAYMENT_ERR_INTERNAL_ERROR - 2)
/** @} */
/**
 * ���������۳��û��������������������������ϵļƷѵ����
 * ��������û���κ����ã���������Ѿ����ڵļƷѵ���ñ�����Ҳ
 * û���κ����á�
 *
 * @param[in]	app_name Ӧ�ó������ƣ�����"killer"����Ӧ��ΪNULL������Ҫ����ֵ0��β���ò���ֻ��ģ��������Ч��
 * @param[in]	local_payment_id Ӧ�ó����ڲ��Ʒѵ�ID,��Ҫ��ͬһ��Ӧ�ó����ﱣ��Ψһ����ֵӦ�ô�1��ʼ��ţ����������10000��
 * @return		
 * @retval		DEDUCT_CHARGED_RET_SUCCESS �۳��ɹ���
 * @retval		ERROR_DEDUCT_CHARGED_RECORD_NOT_FOUND û�з���ָ���Ʒѵ�ID���Ѵ�ƷѼ�¼���۳�ʧ�ܡ�
 * @retval		ERROR_DEDUCT_CHARGED_RET_WRONG_PARAM ����Ĳ������۳�ʧ�ܡ�
 * @retval		ERROR_DEDUCT_CHARGED_RET_LACK_RESOURCE �ڴ治�㣬����ʧ�ܡ�
 * @retval		ERROR_DEDUCT_CHARGED_RET_CURRENT_DATE_ERROR ��ǰ���ڴ��������ǰ�ֻ�����С��2009/1/1��
 *				��ô�������뽫�ᱻ���ء�
 * @retval		ERROR_DEDUCT_CHARGED_RET_INT_ERROR �Ʒ������ڲ������¿۳�ʧ�ܡ�
 * @retval		ERROR_DEDUCT_CHARGED_RET_EXEC_FILE_PREFIX_ERROR app_name����ΪNULL���������ᱻ���أ�������ֻ����VREģ������
 *				���֣����ֻ��ϸò������ᱻ���ԡ�
 */
VMINT vm_deduct_charged_value(VMSTR app_name, VMINT local_payment_id);

/**
 * @name vm_query_charge_info�����ķ�����
 * @{
 */
/**
 * ��ʾ���ڼƷѵ���Ч���ڡ�
 */
#define QUERY_CHARGE_RET_IN_DURABILITY			PAYMENT_RET_IN_DURABILITY
/**
 * ��ʾ��Ҫ�Ʒѡ�
 */
#define QUERY_CHARGE_RET_NEED_PAYMENT			PAYMENT_RET_NEED_PAYMENT
/**
 * ��������
 */
#define QUERY_CHARGE_RET_PARAM_ERROR			PAYMENT_ERR_WRONG_PARAM
/**
 * �ڴ治�㡣
 */
#define QUERY_CHARGE_RET_LACK_RESOURCE			PAYMENT_ERR_NO_MEM
/**
 * ����ֻ���ϵͳʱ��С��2000��1��1�գ���ô�����ظô���
 */
#define QUERY_CHARGE_RET_CURRENT_DATE_ERROR		PAYMENT_ERR_CURRENT_DATE
/**
 * û��SIM����δ֪��Ӫ�̡�
 */
#define QUERY_CHARGE_RET_NO_SIM_CARD			PAYMENT_ERR_NO_SIM_CARD
/**
 * �Ʒ������ڲ�����
 */
#define QUERY_CHARGE_RET_INT_ERROR				PAYMENT_ERR_INTERNAL_ERROR
/**
 * �޷��õ�IMSI�š�
 */
#define QUERY_CHARGE_RET_NOT_GET_IMSI			(PAYMENT_ERR_INTERNAL_ERROR - 1)
/**
 * ��������ֻ������ģ�����ϳ��֡� 
 */
#define QUERY_CHARGE_RET_EXEC_FILE_PREFIX_ERROR (PAYMENT_ERR_INTERNAL_ERROR - 2)
/** @} */

/**
 * ��ѯָ���ļ�ǰ׺��ָ��Ӧ�ñ��ؼƷѵ�ID�ļƷ���Ϣ.
 * 
 * @param[in] 	app_name Ӧ�ó������ƣ�����"killer"����Ӧ��ΪNULL������Ҫ����ֵ0��β���ò���ֻ��ģ��������Ч��
 * @param[in]	local_payment_id Ӧ�ó����ڲ��Ʒѵ�ID,��Ҫ��ͬһ��Ӧ�ó����ﱣ��Ψһ����ֵӦ�ô�1��ʼ��ţ����������10000��
 * @param[out]	payment_mode ϣ���õ��ļƷ�����ָ��,�������QUERY_CHARGE_RET_IN_DURABILITY,��ô���򱾲������ڴ��ַ
 *				д��Ʒѷ�ʽ.д�����ֵΪPAYMENT_MODE_BY_TIME��ʾ����,PAYMENT_MODE_BY_DATE��ʾ��
 *				��,�������������QUERY_CHARGE_RET_NEED_PAYMENT�򲻻�д��.
 * @param[out]	payment_surplus_value ϣ���õ���ʣ��Ĵ�����������ָ������,�������������QUERY_CHARGE_RET_IN_DURABILITY,��ô
 *				���򱾲���ָ����ָ�ĵ�ַд��ʣ��Ĵ���������.��������ģʽ��д��0.�����������
 *				��QUERY_CHARGE_RET_NEED_PAYMENT�򲻻�д��.
 * @param[out]	is_saved ����û�ϣ�����յ�QUERY_CHARGE_RET_NEED_PAYMENT��ʱ��ͬʱ��Ҫ֪���Ƿ��û��ԸüƷ�
 *				�㱣���.��ô��Ӧ���ṩ��ָ��.��ô�������ڷ���QUERY_CHARGE_RET_NEED_PAYMENT��ʱ��
 *				�ὫTRUE��FALSEд���ָ��ָ����ڴ��ַ.FALSE��ʾû�б����.TRUE��ʾ�Ѿ������.
 *				ֻ���ڱ���������QUERY_CHARGE_RET_NEED_PAYMENT��ʱ��Ż�д��.
 *				
 * @return		��ʾ��ѯ�Ƿ�ɹ����Ƿ��ڼƷ����ڡ�		
 * @retval		QUERY_CHARGE_RET_IN_DURABILITY �ڼƷ�ʹ�����ڡ�
 * @retval		QUERY_CHARGE_RET_NEED_PAYMENT ���ڼƷ�ʹ�����ڣ���Ҫ�Ʒѡ�
 * @retval		QUERY_CHARGE_RET_PARAM_ERROR �������󣬲�ѯʧ�ܡ�
 * @retval		QUERY_CHARGE_RET_LACK_RESOURCE �ڲ���������ѯʧ�ܡ�
 * @retval		QUERY_CHARGE_RET_CURRENT_DATE_ERROR ��ǰ���ڴ��������ǰ�ֻ�����С��2009/1/1��
 *				��ô�������뽫�ᱻ���ء�
 * @retval		QUERY_CHARGE_RET_INT_ERROR �Ʒ������ڲ�����
 * @retval		QUERY_CHARGE_RET_EXEC_FILE_PREFIX_ERROR app_name����ΪNULL���������ᱻ���أ�������ֻ����VREģ������
 *				���֣����ֻ��ϸò������ᱻ���ԡ�
 */
VMINT vm_query_charge_info(VMSTR app_name, VMINT local_payment_id, 
	VMINT* payment_mode, VMINT* payment_surplus_value, VMINT* is_saved);

/**
 * @name vm_get_charge_notification�ķ���ֵ��
 */
/**
* Ѱ�۳ɹ���
*/
#define NOTIFICATION_RET_SUCCESS											(0)
/**
* ����Ĳ�����
*/
#define ERROR_NOTIFICATION_RET_WRONG_PARAM									(-1)
/**
* �ڴ治����
*/
#define ERROR_NOTIFICATION_RET_ERROR_MEM									(-2)
/**
* �����VXP�ļ���
*/
#define ERROR_NOTIFICATION_RET_VXP_FILE_ERROR								(-3)
/**
* �۸��޷�ƥ�䡣
*/
#define ERROR_NOTIFICATION_RET_DISMATCH_PRICE								(-4)
/**
 * Ӧ�ò���Ҫ��ʾ��
 */
#define ERROR_NOTIFICATION_NO_NOTIFICATION									(-5)

/**
* �õ��Ʒ�ǰ����ʾ������ʵ�ʵĽ��׼۸�
* 
* @code
* VMINT ret = 0, transaction_price = 0;
* if ((ret = vm_query_charge_info("ball", 1, NULL, NULL, NULL) == QUERY_CHARGE_RET_NEED_PAYMENT))
* {
*     VMINT errorCode = 0;
*     VMWSTR notification = NULL;
*	 
*	 if (vm_get_charge_notification(200, 1, &transaction_price, &notification) == 0)
*	 {
*	     draw_notification(notification); // ��ʾ��ʾ���棬�û�ȷ�Ϻ����vm_quick_charge��ʼ�Ʒѡ�
*       vm_free(notification);
*     }
* }
* @endcode
* @param[in]								fix_price ��Ϸ�ԸüƷѵ�Ķ��ۣ���λΪ�֡�
* @param[in]								local_payment_id Ӧ�ó����ڲ��Ʒѵ�ID��
* @param[out]								transaction_price �Ʒ�����֧�ֵļƷѼ۸񣬵�λΪ�֡�����۸�Ҳ�ǵ���vm_quick_charge������ļ۸�
* @param[out]								notification ��ʾ���û�����ʾ���֣���ʹ�����������vm_free������notification�ͷŵ���
* @return									�Ƿ�Ѱ�۳ɹ��ı�־��
* @retval									NOTIFICATION_RET_SUCCESS Ѱ�۳ɹ���
* @retval									ERROR_NOTIFICATION_RET_WRONG_PARAM ����Ĳ�����
* @retval									ERROR_NOTIFICATION_RET_ERROR_MEM �ڴ治����
* @retval									ERROR_NOTIFICATION_RET_VXP_FILE_ERROR �����VXP�ļ���
* @retval									ERROR_NOTIFICATION_RET_DISMATCH_PRICE �۸��ܲ�ƥ�䡣
* @retval									ERROR_NOTIFICATION_NO_NOTIFICATION Ӧ�ò���Ҫ��ʾ���ɼƷ����渺����ʾ��
*/
VMINT vm_get_charge_notification(VMUINT fix_price, VMINT local_payment_id, VMUINT* transaction_price, VMWSTR* notification);

#ifdef __cplusplus
}
#endif

#endif



