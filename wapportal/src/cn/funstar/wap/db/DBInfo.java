/*
 * Created on 2006-5-15
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.db;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class DBInfo {
  /*�ֻ���Ϣ*/
  public final static String TABLE_MOBILE = "mobile";

  public final static String MOBILE_NAME = "name";
  public final static String MOBILE_UA = "useragent";
  public final static String MOBILE_DID = "did";
  public final static String MOBILE_WAPINFO = "wapinfo"; //wap������汾(1.2.1��2.0)
  public final static String MOBILE_NETINFO = "netinfo"; //�ֻ�������Ϣ(G����C��)
  public final static String MOBILE_ROWS = "rows"; //ÿҳ��ʾ����
  public final static String MOBILE_PAGE = "page"; //Ĭ��ҳ��
  public final static String F_MOBILE_PAGE = "pname"; //ҳ�����ƣ����в����ڴ��ֶ�

  /*��Ŀ��Ϣ*/
  public final static String TABLE_CHANNEL = "channel";

  public final static String CHANNEL_CID = "id"; //��ĿID
  public final static String CHANNEL_NAME = "name";
  public final static String CHANNEL_ORDER_BASE = "order_base"; //��׼����
  public final static String CHANNEL_ORDER_SHOW = "order_show"; //��ʾ����
  public final static String CHANNEL_PARENT = "parent"; //�ϼ���Ŀ�����
  public final static String CHANNEL_ISROLL = "isroll"; //�Ƿ����
  public final static String CHANNEL_FREQUENCY = "frequency"; //����Ƶ��
  public final static String CHANNEL_STATUS = "status"; //״̬���Ƿ�����
  public final static String CHANNEL_ISCOMMON = "iscommon"; //�Ƿ�Ϊͨ����Ŀ
  public final static String CHANNEL_MEMO = "memo"; //��ע
  public final static String CHANNEL_REDIRECT = "redirect"; //����������Ŀ
  public final static String CHANNEL_ICON = "icon"; //��Ŀͼ��

  /*ҵ����Ϣ*/
  public final static String TABLE_SERVICE = "service";

  public final static String SERVICE_SID = "id"; //ServiceID
  public final static String SERVICE_NAME = "name";
  public final static String SERVICE_ORDER_BASE = "order_base"; //��׼����
  public final static String SERVICE_ORDER_SHOW = "order_show"; //��ʾ����
  public final static String SERVICE_URL = "url"; //��ʽ��ַ
  public final static String SERVICE_CHANNEL = "channel"; //������Ŀ
  public final static String SERVICE_SP = "sp"; //����SP
  public final static String SERVICE_ISROLL = "isroll"; //�Ƿ����
  public final static String SERVICE_STATUS = "status"; //״̬���Ƿ�����
  public final static String SERVICE_ISCOMMON = "iscommon"; //�Ƿ�Ϊͨ��ҵ��
  public final static String SERVICE_MEMO = "memo"; //��ע
  public final static String SERVICE_ICON = "icon"; //ҵ��ͼ��

  /*�ֻ�ҳ����Ϣ*/
  public final static String TABLE_PAGEINFO = "pageinfo";

  public final static String PAGEINFO_NAME = "name"; //ҳ������
  public final static String PAGEINFO_FILENAME = "filename"; //ִ���ļ���
  public final static String PAGEINFO_ISDEFAULT = "isdefault"; //�Ƿ�ΪĬ��ҳ��
  public final static String PAGEINFO_MEMO = "memo"; //��ע
  public final static String PAGEINFO_LANGUAGE = "lg"; //����

  //����ҳ����Ϣ
  public final static String TABLE_DIDPAGE = "did_page";

  public final static String DIDPAGE_PAGE = "page";
  public final static String DIDPAGE_DID = "did";

  /*�ض��ֻ�ҵ��������Ϣ*/
  public final static String TABLE_MSINFO = "msinfo";

  public final static String MSINFO_MOBILE = "mobile";
  public final static String MSINFO_SERVICE = "service";

  /*��ҳ������־*/
  public final static String TABLE_ACCESS_LOG = "access_log";

  public final static String ACCESS_LOG_PAGE = "page";
  public final static String ACCESS_LOG_MOBILE = "mobile";
  public final static String ACCESS_LOG_ACCESS_DATE = "access_date";
  public final static String ACCESS_LOG_IP = "ip";
  public final static String ACCESS_LOG_LANGUAGE = "lg";

  /*��Ŀ������־*/
  public final static String TABLE_CHANNEL_LOG = "channel_log";

  public final static String CHANNEL_LOG_CHANNEL = "channel";
  public final static String CHANNEL_LOG_MOBILE = "mobile";
  public final static String CHANNEL_LOG_ACCESS_DATE = "access_date";

  /*ҵ�������־*/
  public final static String TABLE_SERVICE_LOG = "service_log";

  public final static String SERVICE_LOG_SERVICE = "service";
  public final static String SERVICE_LOG_MOBILE = "mobile";
  public final static String SERVICE_LOG_ACCESS_DATE = "access_date";

  /*��ͬ�ֶ�*/
  public static String COMMON_ID = "id"; //���
  public static String COMMON_IS_SERVICE = "is_service"; //�Ƿ�Ϊҵ����������ʹ��
}
