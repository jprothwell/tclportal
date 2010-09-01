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
  /*手机信息*/
  public final static String TABLE_MOBILE = "mobile";

  public final static String MOBILE_NAME = "name";
  public final static String MOBILE_UA = "useragent";
  public final static String MOBILE_DID = "did";
  public final static String MOBILE_WAPINFO = "wapinfo"; //wap浏览器版本(1.2.1、2.0)
  public final static String MOBILE_NETINFO = "netinfo"; //手机网络信息(G网、C网)
  public final static String MOBILE_ROWS = "rows"; //每页显示行数
  public final static String MOBILE_PAGE = "page"; //默认页面
  public final static String F_MOBILE_PAGE = "pname"; //页面名称，表中不存在此字段

  /*栏目信息*/
  public final static String TABLE_CHANNEL = "channel";

  public final static String CHANNEL_CID = "id"; //栏目ID
  public final static String CHANNEL_NAME = "name";
  public final static String CHANNEL_ORDER_BASE = "order_base"; //基准排序
  public final static String CHANNEL_ORDER_SHOW = "order_show"; //显示排序
  public final static String CHANNEL_PARENT = "parent"; //上级栏目，外键
  public final static String CHANNEL_ISROLL = "isroll"; //是否滚动
  public final static String CHANNEL_FREQUENCY = "frequency"; //滚动频率
  public final static String CHANNEL_STATUS = "status"; //状态，是否隐藏
  public final static String CHANNEL_ISCOMMON = "iscommon"; //是否为通用栏目
  public final static String CHANNEL_MEMO = "memo"; //备注
  public final static String CHANNEL_REDIRECT = "redirect"; //定向到其他栏目
  public final static String CHANNEL_ICON = "icon"; //栏目图标

  /*业务信息*/
  public final static String TABLE_SERVICE = "service";

  public final static String SERVICE_SID = "id"; //ServiceID
  public final static String SERVICE_NAME = "name";
  public final static String SERVICE_ORDER_BASE = "order_base"; //基准排序
  public final static String SERVICE_ORDER_SHOW = "order_show"; //显示排序
  public final static String SERVICE_URL = "url"; //正式地址
  public final static String SERVICE_CHANNEL = "channel"; //所属栏目
  public final static String SERVICE_SP = "sp"; //所属SP
  public final static String SERVICE_ISROLL = "isroll"; //是否滚动
  public final static String SERVICE_STATUS = "status"; //状态，是否隐藏
  public final static String SERVICE_ISCOMMON = "iscommon"; //是否为通用业务
  public final static String SERVICE_MEMO = "memo"; //备注
  public final static String SERVICE_ICON = "icon"; //业务图标

  /*手机页面信息*/
  public final static String TABLE_PAGEINFO = "pageinfo";

  public final static String PAGEINFO_NAME = "name"; //页面名称
  public final static String PAGEINFO_FILENAME = "filename"; //执行文件名
  public final static String PAGEINFO_ISDEFAULT = "isdefault"; //是否为默认页面
  public final static String PAGEINFO_MEMO = "memo"; //备注
  public final static String PAGEINFO_LANGUAGE = "lg"; //语言

  //机型页面信息
  public final static String TABLE_DIDPAGE = "did_page";

  public final static String DIDPAGE_PAGE = "page";
  public final static String DIDPAGE_DID = "did";

  /*特定手机业务设置信息*/
  public final static String TABLE_MSINFO = "msinfo";

  public final static String MSINFO_MOBILE = "mobile";
  public final static String MSINFO_SERVICE = "service";

  /*首页访问日志*/
  public final static String TABLE_ACCESS_LOG = "access_log";

  public final static String ACCESS_LOG_PAGE = "page";
  public final static String ACCESS_LOG_MOBILE = "mobile";
  public final static String ACCESS_LOG_ACCESS_DATE = "access_date";
  public final static String ACCESS_LOG_IP = "ip";
  public final static String ACCESS_LOG_LANGUAGE = "lg";

  /*栏目访问日志*/
  public final static String TABLE_CHANNEL_LOG = "channel_log";

  public final static String CHANNEL_LOG_CHANNEL = "channel";
  public final static String CHANNEL_LOG_MOBILE = "mobile";
  public final static String CHANNEL_LOG_ACCESS_DATE = "access_date";

  /*业务访问日志*/
  public final static String TABLE_SERVICE_LOG = "service_log";

  public final static String SERVICE_LOG_SERVICE = "service";
  public final static String SERVICE_LOG_MOBILE = "mobile";
  public final static String SERVICE_LOG_ACCESS_DATE = "access_date";

  /*共同字段*/
  public static String COMMON_ID = "id"; //序号
  public static String COMMON_IS_SERVICE = "is_service"; //是否为业务，排序功能中使用
}
