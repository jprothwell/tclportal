#ifndef VMGPS_H_
#define VMGPS_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VM_GPS_NMEA_MAX_SVVIEW             20
#define VM_GPS_GSA_SATE_MAX			12

/*时间。*/
typedef struct{
	VMINT8 hour;
	VMINT8 minute;
	VMINT8 second;
	VMINT8 millisecond;
} vm_gps_nmea_utc_time_struct;

/*日期。*/
typedef struct{
	VMINT8 year;
	VMINT8 month;
	VMINT8 day;
} vm_gps_nmea_utc_date_struct;

/*NMEA中GGA的数据。*/
typedef struct{
	double gga_latitude;                                      /*纬度ddmm.mmmm（度分）格式（前面的0也将被传输）。*/
    	double gga_longitude;                                   /*经度dddmm.mmmm（度分）格式（前面的0也将被传输）。*/
    	float gga_h_precision;                                   /*HDOP水平精度因子（0.0~99.9）。*/
    	double gga_altitude;                                      /*海拔高度（-9999.9~99999.9）。*/
    	float gga_unit_of_altitude;                            /*海拔高度的单位：M表示米。*/
    	float gga_geoidal ;                                         /*地球椭球面相对大地水准面的高度。*/
    	float gga_unit_of_geoidal;                            /*地球椭球面相对大地水准面的高度单位：M表示米。*/
    	float gga_gps_age;                                        /*差分时间（从最近一次接收到差分信号开始的秒数，如果不是差分定位则为空）。*/
    	VMUINT16 gga_station_id;                             /*差分站ID号（0000~1023）（前面的0也将被传输，如果不是差分定位将为空）。*/
    	VMUINT8 gga_sat_in_view;                            /*正在使用的卫星数量（00~12，前面的0也将被传输）。*/
    	vm_gps_nmea_utc_time_struct gga_utc_time; /*UTC时间hhmmss.sss（时分秒）格式。*/
    	VMINT8 gga_north_south;			              /*纬度半球N（北纬）或S（南纬）。*/
    	VMINT8 gga_east_west;			              /*经度半球E（东经）或W（西经）。*/
    	VMINT8 gga_quality;                                      /*GPS状态：0=未定位，1=非差分定位，2=差分定位。*/
}vm_gps_gga_data_struct;

/*NMEA中RMC的数据。*/
typedef struct{
	double rmc_latitude;                                       /*纬度ddmm.mmmm（度分）格式（前面的0也将被传输）。*/
    	double rmc_longitude;                                    /*经度dddmm.mmmm（度分）格式（前面的0也将被传输）。*/
    	float rmc_ground_speed;                               /*速度，节，Knots。*/
    	float rmc_trace_degree;                                /*地面航向（000.0~359.9度，以真北为参考基准，前面的0也将被传输）。*/
    	float rmc_magnetic;                                       /*磁偏角（000~180）度（前面的0也将被传输）。*/
    	vm_gps_nmea_utc_time_struct rmc_utc_time; /*UTC时间，hhmmss.sss格式。*/
    	vm_gps_nmea_utc_date_struct rmc_utc_date; /*UTC日期，DDMMYY格式。*/
    	VMINT8 rmc_status;                                       /*状态，A=定位，V=未定位。*/
    	VMINT8 rmc_north_south;                             /*纬度半球N（北纬）或S（南纬）。*/
    	VMINT8 rmc_east_west;                                /*经度半球E（东经）或W（西经）。*/
    	VMINT8 rmc_magnetic_e_w;                         /*磁偏角方向，E=东，W=西。*/
    	VMINT8 rmc_cmode;					       /*模式指示（仅NMEA0183 3.00版本输出，A=自主定位，D=差分，E=估算，N=数据无效）*/
}vm_gps_rmc_data_struct;

/*NMEA中GLL的数据。*/
typedef struct{
	double gll_latitude;                                      /*纬度ddmm.mmmm（度分）格式（前面的0也将被传输）。*/
    	double gll_longitude;                                   /*经度dddmm.mmmm（度分）格式（前面的0也将被传输）。*/
    	vm_gps_nmea_utc_time_struct gll_utc_time; /*UTC时间，hhmmss.sss格式*/
    	VMINT8 gll_north_south;                             /*纬度半球N（北纬）或S（南纬）。*/
    	VMINT8 gll_east_west;                                /*经度半球E（东经）或W（西经）。*/
    	VMINT8 gll_status;                                       /*状态，A=定位，V=未定位*/
    	VMINT8 gll_mode;
}vm_gps_gll_data_struct;

/*NMEA中GSV的数据。*/
typedef struct{
	VMINT16 gsv_msg_sum;         	 /*本次GSV语句的总数目（1~3）。*/
    	VMINT16 gsv_msg_index;      	 /*本条GSV语句是本次GSV语句的第几条（1~3）。*/
    	VMINT16 gsv_sates_in_view;	 /*当前可见卫星总数（00~12）（前面的0也将被传输）。*/
    	VMINT16 gsv_max_snr;		 /*最大信噪比。*/
    	VMINT16 gsv_min_snr;		 /*最小信噪比。*/
    	VMINT16 gsv_num_sv_trk;	 /*卫星信息数量。*/
    	struct
    	{
       	VMUINT8 sate_id;			 /*PRN码（伪随机噪声码）（01~12，前面的0也将被传输）。*/
        	VMUINT8 elevation;		 /*卫星仰角（00~90度，前面的0也将被传输）。*/
        	VMINT16 azimuth;		 /*卫星方位角（000~359度，前面的0也将被传输）。*/
        	VMUINT8 snr;				 /*信噪比（00~99dB，没有跟踪到卫星时为空，前面的0也将被传输）。*/
    	}gsv_rsv[VM_GPS_NMEA_MAX_SVVIEW];
}vm_gps_gsv_data_struct;

/*NMEA中GSA的数据。*/
typedef struct{
	float gsa_pdop;                   /*PDOP综合位置精度因子（0.5~99.9）。*/
    	float gsa_hdop;                   /*HDOP水平精度因子（0.5~99.9）。*/
    	float gsa_vdop;                   /*VDOP垂直精度因子（0.5~99.9）。*/
    	VMUINT16 gsa_sate_id[VM_GPS_GSA_SATE_MAX];/*PRN 数字：01至32表天空使用中的卫星编号，最多可接收12颗卫星信息。*/
    	VMINT8 gsa_op_mode;       /*定位模式，A=自动手动2D/3D，M=手动2D/3D。*/
    	VMINT8 gsa_fix_mode;       /*定位类型，1=未定位，2=2D定位，3=3D定位。*/
}vm_gps_gsa_data_struct;

/*NMEA中VTG的数据。*/
typedef struct{
	float vtg_hspeed_knot; /*地面导航速率，单位节。*/
	float vtg_hspeed_km;   /*地面导航速率，单位公里/小时。*/
	float vtg_true_heading;/*以真北为参考基准的地面航向。*/
	float vtg_mag_heading;/*以磁北为参考基准的地面航向。*/
	VMINT8 vtg_mode;   	   /*模式指示（仅NMEA0183 3.00版本输出，A=自主定位，D=差分，E=估算，N=数据无效）。*/
}vm_gps_vtg_data_struct;

/*NMEA中NMEA的数据。*/
typedef struct{
	vm_gps_rmc_data_struct rmc_data;
	vm_gps_vtg_data_struct vtg_data;
	vm_gps_gll_data_struct gll_data;
	vm_gps_gga_data_struct gga_data;
	vm_gps_gsa_data_struct gsa_data;
	vm_gps_gsv_data_struct gsv_data;
}vm_gps_info_struct;

/*GPS打开状态。*/
typedef enum{
	VM_GPS_OPEN_RES_LESS = -3	,				/*缺少资源*/
	VM_GPS_OPEN_PORT_HANDLE_WRONG = -2,	/*OPEN UART句柄错误。*/
	VM_GPS_OPEN_PORT_NUMBER_WRONG = -1,	/*PORT NUMBER错误。*/
	VM_GPS_OPEN_SUCCESS = 0,					/*打开成功。*/
	VM_GPS_OPEN_ALREADY_OPEN = 1			/*已经打开。*/
} vm_gps_open_state_enum;

/*GPS关闭状态。*/
typedef enum{
	VM_GPS_CLOSE_FAILED = -1,					/*关闭失败。*/
	VM_GPS_CLOSE_SUCCESS = 0,					/*关闭成功。*/
	VM_GPS_CLOSE_STILL_APP_USE_DATA = 1		/*仍然有应用在使用GPS信息*/
} vm_gps_close_state_enum;


/**
 * 打开GPS。函数中会打开UART接口。
 *
 * @return		返回VM_GPS_OPEN_SUCCESS表示打开成功，返回VM_GPS_OPEN_ALREADY_OPEN
 *				表示已经打开，返回VM_GPS_OPEN_PORT_NUMBER_WRONG表示获取UART PORT
 *				失败，返回VM_GPS_OPEN_PORT_HANDLE_WRONG表示打开UART失败。
 */
VMINT vm_gps_open(void);

/**
 * 关闭GPS。检查是否是最后一个GPS APP，如果是，则关闭UART，否则不关闭。
 *
 * @return	返回VM_GPS_CLOSE_SUCCESS表示关闭成功，返回VM_GPS_CLOSE_STILL_APP_USE_DATA表示还
 *			有应用在使用GPS信息，返回VM_GPS_CLOSE_FAILED表示关闭失败。
 */
VMINT vm_gps_close(void);


/**
 * 获取GGA信息。在调用此函数获取信息之前必须确保已经调用过GPS开启
 * 函数vm_gps_open。否则获取到的是空指针NULL。
 *
 * @return	正常情况下返回指向GGA结构体的指针，该结构体保存了GGA的信
 *			息。如果未调用vm_gps_open，则返回空指针NULL。
 */
 vm_gps_gga_data_struct*  vm_gps_get_gga_data( void );

/**
 * 获取RMC信息。在调用此函数获取信息之前必须确保已经调用过GPS开启
 * 函数vm_gps_open。否则获取到的是空指针NULL。
 *
 * @return	正常情况下返回指向RMC结构体的指针，该结构体保存了RMC的信
 *			息。如果未调用vm_gps_open，则返回空指针NULL。
 */
 vm_gps_rmc_data_struct* vm_gps_get_rmc_data( void );

/**
 * 获取GLL信息。在调用此函数获取信息之前必须确保已经调用过GPS开启
 * 函数vm_gps_open。否则获取到的是空指针NULL。
 *
 * @return	正常情况下返回指向GLL结构体的指针，该结构体保存了GLL的信
 *			息。如果未调用vm_gps_open，则返回空指针NULL。
 */
 vm_gps_gll_data_struct* vm_gps_get_gll_data( void );

/**
 * 获取GSV信息。在调用此函数获取信息之前必须确保已经调用过GPS开启
 * 函数vm_gps_open。否则获取到的是空指针NULL。
 *
 * @return	正常情况下返回指向GSV结构体的指针，该结构体保存了GSV的信
 *			息。如果未调用vm_gps_open，则返回空指针NULL。
 */
 vm_gps_gsv_data_struct* vm_gps_get_gsv_data( void );

/**
 * 获取GSA信息。在调用此函数获取信息之前必须确保已经调用过GPS开启
 * 函数vm_gps_open。否则获取到的是空指针NULL。
 *
 * @return	正常情况下返回指向GSA结构体的指针，该结构体保存了GSA的信
 *			息。如果未调用vm_gps_open，则返回空指针NULL。
 */
vm_gps_gsa_data_struct* vm_gps_get_gsa_data(  void );

/**
 * 获取VTG信息。在调用此函数获取信息之前必须确保已经调用过GPS开启
 * 函数vm_gps_open。否则获取到的是空指针NULL。
 *
 * @return	正常情况下返回指向VTG结构体的指针，该结构体保存了VTG的信
 *			息。如果未调用vm_gps_open，则返回空指针NULL。
 */
vm_gps_vtg_data_struct* vm_gps_get_vtg_data( void );

#ifdef __cplusplus
}
#endif 
#endif

