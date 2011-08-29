#ifndef VMGPS_H_
#define VMGPS_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VM_GPS_NMEA_MAX_SVVIEW             20
#define VM_GPS_GSA_SATE_MAX			12

/*ʱ�䡣*/
typedef struct{
	VMINT8 hour;
	VMINT8 minute;
	VMINT8 second;
	VMINT8 millisecond;
} vm_gps_nmea_utc_time_struct;

/*���ڡ�*/
typedef struct{
	VMINT8 year;
	VMINT8 month;
	VMINT8 day;
} vm_gps_nmea_utc_date_struct;

/*NMEA��GGA�����ݡ�*/
typedef struct{
	double gga_latitude;                                      /*γ��ddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩��*/
    	double gga_longitude;                                   /*����dddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩��*/
    	float gga_h_precision;                                   /*HDOPˮƽ�������ӣ�0.0~99.9����*/
    	double gga_altitude;                                      /*���θ߶ȣ�-9999.9~99999.9����*/
    	float gga_unit_of_altitude;                            /*���θ߶ȵĵ�λ��M��ʾ�ס�*/
    	float gga_geoidal ;                                         /*������������Դ��ˮ׼��ĸ߶ȡ�*/
    	float gga_unit_of_geoidal;                            /*������������Դ��ˮ׼��ĸ߶ȵ�λ��M��ʾ�ס�*/
    	float gga_gps_age;                                        /*���ʱ�䣨�����һ�ν��յ�����źſ�ʼ��������������ǲ�ֶ�λ��Ϊ�գ���*/
    	VMUINT16 gga_station_id;                             /*���վID�ţ�0000~1023����ǰ���0Ҳ�������䣬������ǲ�ֶ�λ��Ϊ�գ���*/
    	VMUINT8 gga_sat_in_view;                            /*����ʹ�õ�����������00~12��ǰ���0Ҳ�������䣩��*/
    	vm_gps_nmea_utc_time_struct gga_utc_time; /*UTCʱ��hhmmss.sss��ʱ���룩��ʽ��*/
    	VMINT8 gga_north_south;			              /*γ�Ȱ���N����γ����S����γ����*/
    	VMINT8 gga_east_west;			              /*���Ȱ���E����������W����������*/
    	VMINT8 gga_quality;                                      /*GPS״̬��0=δ��λ��1=�ǲ�ֶ�λ��2=��ֶ�λ��*/
}vm_gps_gga_data_struct;

/*NMEA��RMC�����ݡ�*/
typedef struct{
	double rmc_latitude;                                       /*γ��ddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩��*/
    	double rmc_longitude;                                    /*����dddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩��*/
    	float rmc_ground_speed;                               /*�ٶȣ��ڣ�Knots��*/
    	float rmc_trace_degree;                                /*���溽��000.0~359.9�ȣ����汱Ϊ�ο���׼��ǰ���0Ҳ�������䣩��*/
    	float rmc_magnetic;                                       /*��ƫ�ǣ�000~180���ȣ�ǰ���0Ҳ�������䣩��*/
    	vm_gps_nmea_utc_time_struct rmc_utc_time; /*UTCʱ�䣬hhmmss.sss��ʽ��*/
    	vm_gps_nmea_utc_date_struct rmc_utc_date; /*UTC���ڣ�DDMMYY��ʽ��*/
    	VMINT8 rmc_status;                                       /*״̬��A=��λ��V=δ��λ��*/
    	VMINT8 rmc_north_south;                             /*γ�Ȱ���N����γ����S����γ����*/
    	VMINT8 rmc_east_west;                                /*���Ȱ���E����������W����������*/
    	VMINT8 rmc_magnetic_e_w;                         /*��ƫ�Ƿ���E=����W=����*/
    	VMINT8 rmc_cmode;					       /*ģʽָʾ����NMEA0183 3.00�汾�����A=������λ��D=��֣�E=���㣬N=������Ч��*/
}vm_gps_rmc_data_struct;

/*NMEA��GLL�����ݡ�*/
typedef struct{
	double gll_latitude;                                      /*γ��ddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩��*/
    	double gll_longitude;                                   /*����dddmm.mmmm���ȷ֣���ʽ��ǰ���0Ҳ�������䣩��*/
    	vm_gps_nmea_utc_time_struct gll_utc_time; /*UTCʱ�䣬hhmmss.sss��ʽ*/
    	VMINT8 gll_north_south;                             /*γ�Ȱ���N����γ����S����γ����*/
    	VMINT8 gll_east_west;                                /*���Ȱ���E����������W����������*/
    	VMINT8 gll_status;                                       /*״̬��A=��λ��V=δ��λ*/
    	VMINT8 gll_mode;
}vm_gps_gll_data_struct;

/*NMEA��GSV�����ݡ�*/
typedef struct{
	VMINT16 gsv_msg_sum;         	 /*����GSV��������Ŀ��1~3����*/
    	VMINT16 gsv_msg_index;      	 /*����GSV����Ǳ���GSV���ĵڼ�����1~3����*/
    	VMINT16 gsv_sates_in_view;	 /*��ǰ�ɼ�����������00~12����ǰ���0Ҳ�������䣩��*/
    	VMINT16 gsv_max_snr;		 /*�������ȡ�*/
    	VMINT16 gsv_min_snr;		 /*��С����ȡ�*/
    	VMINT16 gsv_num_sv_trk;	 /*������Ϣ������*/
    	struct
    	{
       	VMUINT8 sate_id;			 /*PRN�루α��������룩��01~12��ǰ���0Ҳ�������䣩��*/
        	VMUINT8 elevation;		 /*�������ǣ�00~90�ȣ�ǰ���0Ҳ�������䣩��*/
        	VMINT16 azimuth;		 /*���Ƿ�λ�ǣ�000~359�ȣ�ǰ���0Ҳ�������䣩��*/
        	VMUINT8 snr;				 /*����ȣ�00~99dB��û�и��ٵ�����ʱΪ�գ�ǰ���0Ҳ�������䣩��*/
    	}gsv_rsv[VM_GPS_NMEA_MAX_SVVIEW];
}vm_gps_gsv_data_struct;

/*NMEA��GSA�����ݡ�*/
typedef struct{
	float gsa_pdop;                   /*PDOP�ۺ�λ�þ������ӣ�0.5~99.9����*/
    	float gsa_hdop;                   /*HDOPˮƽ�������ӣ�0.5~99.9����*/
    	float gsa_vdop;                   /*VDOP��ֱ�������ӣ�0.5~99.9����*/
    	VMUINT16 gsa_sate_id[VM_GPS_GSA_SATE_MAX];/*PRN ���֣�01��32�����ʹ���е����Ǳ�ţ����ɽ���12��������Ϣ��*/
    	VMINT8 gsa_op_mode;       /*��λģʽ��A=�Զ��ֶ�2D/3D��M=�ֶ�2D/3D��*/
    	VMINT8 gsa_fix_mode;       /*��λ���ͣ�1=δ��λ��2=2D��λ��3=3D��λ��*/
}vm_gps_gsa_data_struct;

/*NMEA��VTG�����ݡ�*/
typedef struct{
	float vtg_hspeed_knot; /*���浼�����ʣ���λ�ڡ�*/
	float vtg_hspeed_km;   /*���浼�����ʣ���λ����/Сʱ��*/
	float vtg_true_heading;/*���汱Ϊ�ο���׼�ĵ��溽��*/
	float vtg_mag_heading;/*�Դű�Ϊ�ο���׼�ĵ��溽��*/
	VMINT8 vtg_mode;   	   /*ģʽָʾ����NMEA0183 3.00�汾�����A=������λ��D=��֣�E=���㣬N=������Ч����*/
}vm_gps_vtg_data_struct;

/*NMEA��NMEA�����ݡ�*/
typedef struct{
	vm_gps_rmc_data_struct rmc_data;
	vm_gps_vtg_data_struct vtg_data;
	vm_gps_gll_data_struct gll_data;
	vm_gps_gga_data_struct gga_data;
	vm_gps_gsa_data_struct gsa_data;
	vm_gps_gsv_data_struct gsv_data;
}vm_gps_info_struct;

/*GPS��״̬��*/
typedef enum{
	VM_GPS_OPEN_RES_LESS = -3	,				/*ȱ����Դ*/
	VM_GPS_OPEN_PORT_HANDLE_WRONG = -2,	/*OPEN UART�������*/
	VM_GPS_OPEN_PORT_NUMBER_WRONG = -1,	/*PORT NUMBER����*/
	VM_GPS_OPEN_SUCCESS = 0,					/*�򿪳ɹ���*/
	VM_GPS_OPEN_ALREADY_OPEN = 1			/*�Ѿ��򿪡�*/
} vm_gps_open_state_enum;

/*GPS�ر�״̬��*/
typedef enum{
	VM_GPS_CLOSE_FAILED = -1,					/*�ر�ʧ�ܡ�*/
	VM_GPS_CLOSE_SUCCESS = 0,					/*�رճɹ���*/
	VM_GPS_CLOSE_STILL_APP_USE_DATA = 1		/*��Ȼ��Ӧ����ʹ��GPS��Ϣ*/
} vm_gps_close_state_enum;


/**
 * ��GPS�������л��UART�ӿڡ�
 *
 * @return		����VM_GPS_OPEN_SUCCESS��ʾ�򿪳ɹ�������VM_GPS_OPEN_ALREADY_OPEN
 *				��ʾ�Ѿ��򿪣�����VM_GPS_OPEN_PORT_NUMBER_WRONG��ʾ��ȡUART PORT
 *				ʧ�ܣ�����VM_GPS_OPEN_PORT_HANDLE_WRONG��ʾ��UARTʧ�ܡ�
 */
VMINT vm_gps_open(void);

/**
 * �ر�GPS������Ƿ������һ��GPS APP������ǣ���ر�UART�����򲻹رա�
 *
 * @return	����VM_GPS_CLOSE_SUCCESS��ʾ�رճɹ�������VM_GPS_CLOSE_STILL_APP_USE_DATA��ʾ��
 *			��Ӧ����ʹ��GPS��Ϣ������VM_GPS_CLOSE_FAILED��ʾ�ر�ʧ�ܡ�
 */
VMINT vm_gps_close(void);


/**
 * ��ȡGGA��Ϣ���ڵ��ô˺�����ȡ��Ϣ֮ǰ����ȷ���Ѿ����ù�GPS����
 * ����vm_gps_open�������ȡ�����ǿ�ָ��NULL��
 *
 * @return	��������·���ָ��GGA�ṹ���ָ�룬�ýṹ�屣����GGA����
 *			Ϣ�����δ����vm_gps_open���򷵻ؿ�ָ��NULL��
 */
 vm_gps_gga_data_struct*  vm_gps_get_gga_data( void );

/**
 * ��ȡRMC��Ϣ���ڵ��ô˺�����ȡ��Ϣ֮ǰ����ȷ���Ѿ����ù�GPS����
 * ����vm_gps_open�������ȡ�����ǿ�ָ��NULL��
 *
 * @return	��������·���ָ��RMC�ṹ���ָ�룬�ýṹ�屣����RMC����
 *			Ϣ�����δ����vm_gps_open���򷵻ؿ�ָ��NULL��
 */
 vm_gps_rmc_data_struct* vm_gps_get_rmc_data( void );

/**
 * ��ȡGLL��Ϣ���ڵ��ô˺�����ȡ��Ϣ֮ǰ����ȷ���Ѿ����ù�GPS����
 * ����vm_gps_open�������ȡ�����ǿ�ָ��NULL��
 *
 * @return	��������·���ָ��GLL�ṹ���ָ�룬�ýṹ�屣����GLL����
 *			Ϣ�����δ����vm_gps_open���򷵻ؿ�ָ��NULL��
 */
 vm_gps_gll_data_struct* vm_gps_get_gll_data( void );

/**
 * ��ȡGSV��Ϣ���ڵ��ô˺�����ȡ��Ϣ֮ǰ����ȷ���Ѿ����ù�GPS����
 * ����vm_gps_open�������ȡ�����ǿ�ָ��NULL��
 *
 * @return	��������·���ָ��GSV�ṹ���ָ�룬�ýṹ�屣����GSV����
 *			Ϣ�����δ����vm_gps_open���򷵻ؿ�ָ��NULL��
 */
 vm_gps_gsv_data_struct* vm_gps_get_gsv_data( void );

/**
 * ��ȡGSA��Ϣ���ڵ��ô˺�����ȡ��Ϣ֮ǰ����ȷ���Ѿ����ù�GPS����
 * ����vm_gps_open�������ȡ�����ǿ�ָ��NULL��
 *
 * @return	��������·���ָ��GSA�ṹ���ָ�룬�ýṹ�屣����GSA����
 *			Ϣ�����δ����vm_gps_open���򷵻ؿ�ָ��NULL��
 */
vm_gps_gsa_data_struct* vm_gps_get_gsa_data(  void );

/**
 * ��ȡVTG��Ϣ���ڵ��ô˺�����ȡ��Ϣ֮ǰ����ȷ���Ѿ����ù�GPS����
 * ����vm_gps_open�������ȡ�����ǿ�ָ��NULL��
 *
 * @return	��������·���ָ��VTG�ṹ���ָ�룬�ýṹ�屣����VTG����
 *			Ϣ�����δ����vm_gps_open���򷵻ؿ�ָ��NULL��
 */
vm_gps_vtg_data_struct* vm_gps_get_vtg_data( void );

#ifdef __cplusplus
}
#endif 
#endif

