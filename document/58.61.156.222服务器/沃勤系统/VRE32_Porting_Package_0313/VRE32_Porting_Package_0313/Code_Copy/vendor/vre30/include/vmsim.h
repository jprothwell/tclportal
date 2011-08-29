#ifndef VMSIM_H_
#define VMSIM_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 运营商。*/
typedef enum 
{
	NO_SIM_CARD = 0,		/* 没有SIM 卡 		*/
	UNKOWN_OPERATOR,		/* 未知运营商。	*/
	CMCC, 					/* 中国移动。		*/
	UNICOM, 				/* 中国联通。		*/
	CNC,					/* 中国网通。		*/
	CNTELCOM,				/* 中国电信。		*/
	ALL						/* 所有运营商。	*/
} operator_t;


typedef enum
{
	VM_SIM_STATE_NET_REG_FAILED = -2,	/*检测到处于工作模式的SIM卡，
											但SIM卡注册网络失败*/
	VM_SIM_STATE_ERROR = -1,	/*查询状态错误*/
	VM_SIM_STATE_VACANT = 0,	/*SIM卡未插或未工作*/
	VM_SIM_STATE_WORKING = 1	/*SIM卡正常工作*/
} vm_sim_state_t;

#define VM_SIM_NO 0  /*无SIM卡*/
#define VM_SIM_SIM1 1  /*SIM1卡*/
#define VM_SIM_SIM2 2  /*SIM2卡*/

/**
 * 获得当前激活网络的运营商名称。
 *
 * @return			运营商名称。
 */
operator_t vm_get_operator(void);

/**
 * 检测SIM卡是否插入。
 *
 * @return					返回TRUE表示SIM卡已插入，否则为FALSE。
 */
VMINT vm_has_sim_card(void);

/**
 * 获得手机卡的IMEI。
 *
 * 如果支持双IMEI号的情况，只返回当前对应卡的IMEI。
 * 
 * @return 				手机卡的imei 号。如果返回的VMSTR
 *								指向一个NULL那么表示系统还正在得到IMEI，
 *								请稍候调用本函数。
 */
const VMSTR vm_get_imei(void);

/**
 * 获得手机卡的IMSI，只返回当前对应卡的IMEI。。
 * 
 * @return 				手机卡的imsi 号。
 */
const VMSTR vm_get_imsi(void);

/**
 *	检测sim卡的数量。
 *	有如下情况:单卡，双卡(只有卡1有效，只有卡2有效，双卡有效)
 *
 *	@return         当前卡的数量,0=无卡，1=有一张卡，2=有两张卡
 */
VMINT vm_sim_card_count(void);

/**
 *	设置当前sim卡
 *
 *	@param card_id sim卡的序号,有效数据VM_SIM_SIM1=卡1，VM_SIM_SIM2=卡2
 *
 *	@return		TRUE=设置成功, FALSE=设置失败
 */
VMINT vm_set_active_sim_card(VMINT card_id);

/**
 *	获取指定sim卡状态
 *
 *	@param card_id sim卡的序号,有效数据VM_SIM_SIM1=卡1，VM_SIM_SIM2=卡2
 *
 *	@return	sim卡状态，值参见vm_sim_state_t；
 */
vm_sim_state_t vm_get_sim_card_status(VMINT card_id);


#define VM_MAX_OPERATOR_CODE_SIZE			(7)

/**
 * 得到运营商编号。
 * @code
 * VMCHAR op_code[VM_MAX_OPERATOR_CODE_SIZE] = {0};
 * 
 * if (vm_query_operator_code(op_code, sizeof(op_code)) == 0)
 * {
 *     // 取得运营商编号成功。
 * }
 * @endcode
 * @param[out]			buffer 取得运营商编号后会向该指针所指位置写入运营商编号。
 * @param[in]				buffer_size buffer的大小，单位为字节。
 */
VMINT vm_query_operator_code(VMCHAR* buffer, VMUINT buffer_size);

#ifdef __cplusplus
}
#endif 
#endif

