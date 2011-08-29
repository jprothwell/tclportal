#ifndef VMSALGPS_H_
#define VMSALGPS_H_

#include "vmgps.h"

typedef enum{
	VM_SAL_GPS_NO_GPS = -3,
	VM_SAL_GPS_UART_HANDLE_WRONG = -2,
	VM_SAL_GPS_MALLOC_FAILED = -1,
	VM_SAL_GPS_OPEN_SUCCESS = 0				
} vm_sal_gps_open_state_enum;



/**
 * ��UART�����ҷ����ڴ档
 *
 * @param port	UART PORT��
 * @return	����VM_SAL_GPS_MALLOC_FAILED��ʾ�����ڴ�ʧ�ܣ�����VM_SAL_GPS_UART_HANDLE_WRONG
 *			��ʾ��UARTʧ�ܣ�����VM_SAL_GPS_OPEN_SUCCESS��ʾ�ɹ���
 */
VMINT vm_sal_gps_uart_open(VMUINT16 port);

/**
 * �ر�UART�ӿڣ��ͷ��ڴ档
 *
 * @param port	UART PORT��
 */
void vm_sal_gps_uart_close(VMUINT16 port);

/**
 * ��ȡNMEA��GGA��Ϣ��
 *
 * @return ���s_vm_sal_gps_infoΪ�գ��򷵻�NULL�����򷵻�ָ��GGA��Ϣ�Ľṹ��ָ�롣
 */
vm_gps_gga_data_struct* vm_sal_gps_get_gga_data(void);

/**
 * ��ȡNMEA��RMC��Ϣ��
 *
 * @return ���s_vm_sal_gps_infoΪ�գ��򷵻�NULL�����򷵻�ָ��RMC��Ϣ�Ľṹ��ָ�롣
 */
vm_gps_rmc_data_struct* vm_sal_gps_get_rmc_data(void);

/**
 * ��ȡNMEA��GLL��Ϣ��
 *
 * @return ���s_vm_sal_gps_infoΪ�գ��򷵻�NULL�����򷵻�ָ��GLL��Ϣ�Ľṹ��ָ�롣
 */
vm_gps_gll_data_struct* vm_sal_gps_get_gll_data(void);

/**
 * ��ȡNMEA��GSV��Ϣ��
 *
 * @return ���s_vm_sal_gps_infoΪ�գ��򷵻�NULL�����򷵻�ָ��GSV��Ϣ�Ľṹ��ָ�롣
 */
vm_gps_gsv_data_struct* vm_sal_gps_get_gsv_data(void);

/**
 * ��ȡNMEA��GSA��Ϣ��
 *
 * @return ���s_vm_sal_gps_infoΪ�գ��򷵻�NULL�����򷵻�ָ��GSA��Ϣ�Ľṹ��ָ�롣
 */
vm_gps_gsa_data_struct* vm_sal_gps_get_gsa_data(void);

/**
 * ��ȡNMEA��VTG��Ϣ��
 *
 * @return ���s_vm_sal_gps_infoΪ�գ��򷵻�NULL�����򷵻�ָ��VTG��Ϣ�Ľṹ��ָ�롣
 */
vm_gps_vtg_data_struct* vm_sal_gps_get_vtg_data(void);



#ifdef __cplusplus
}
#endif 
#endif