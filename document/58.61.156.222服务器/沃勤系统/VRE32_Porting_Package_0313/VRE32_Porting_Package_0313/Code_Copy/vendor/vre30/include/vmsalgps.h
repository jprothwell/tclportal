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
 * 打开UART，并且分配内存。
 *
 * @param port	UART PORT。
 * @return	返回VM_SAL_GPS_MALLOC_FAILED表示分配内存失败，返回VM_SAL_GPS_UART_HANDLE_WRONG
 *			表示打开UART失败，返回VM_SAL_GPS_OPEN_SUCCESS表示成功。
 */
VMINT vm_sal_gps_uart_open(VMUINT16 port);

/**
 * 关闭UART接口，释放内存。
 *
 * @param port	UART PORT。
 */
void vm_sal_gps_uart_close(VMUINT16 port);

/**
 * 获取NMEA中GGA信息。
 *
 * @return 如果s_vm_sal_gps_info为空，则返回NULL，否则返回指向GGA信息的结构体指针。
 */
vm_gps_gga_data_struct* vm_sal_gps_get_gga_data(void);

/**
 * 获取NMEA中RMC信息。
 *
 * @return 如果s_vm_sal_gps_info为空，则返回NULL，否则返回指向RMC信息的结构体指针。
 */
vm_gps_rmc_data_struct* vm_sal_gps_get_rmc_data(void);

/**
 * 获取NMEA中GLL信息。
 *
 * @return 如果s_vm_sal_gps_info为空，则返回NULL，否则返回指向GLL信息的结构体指针。
 */
vm_gps_gll_data_struct* vm_sal_gps_get_gll_data(void);

/**
 * 获取NMEA中GSV信息。
 *
 * @return 如果s_vm_sal_gps_info为空，则返回NULL，否则返回指向GSV信息的结构体指针。
 */
vm_gps_gsv_data_struct* vm_sal_gps_get_gsv_data(void);

/**
 * 获取NMEA中GSA信息。
 *
 * @return 如果s_vm_sal_gps_info为空，则返回NULL，否则返回指向GSA信息的结构体指针。
 */
vm_gps_gsa_data_struct* vm_sal_gps_get_gsa_data(void);

/**
 * 获取NMEA中VTG信息。
 *
 * @return 如果s_vm_sal_gps_info为空，则返回NULL，否则返回指向VTG信息的结构体指针。
 */
vm_gps_vtg_data_struct* vm_sal_gps_get_vtg_data(void);



#ifdef __cplusplus
}
#endif 
#endif