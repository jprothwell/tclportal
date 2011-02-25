/*
 * Created on 2009-5-15
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.alcatel.wap.util;

/**
 * @author gonglin.shi
 *
 * TODO To change the template for this generated type comment go to Window -
 * Preferences - Java - Code Style - Code Templates
 */
public class Common {
	/* 页面序号 */
	public static final String PARA_PAGE = "p";

	/* 页面显示记录条数 */
	public static final String PARA_PAGE_ROWS = "pr";

	/* 记录总条数 */
	public static final String PARA_RECORD_TOTAL = "rt";

	/* ID参数 */
	public static final String PARA_ID = "id";

	/* 排序提交参数 */
	public static final String PARA_ORDERLIST = "orderlist";

	public static final String PARA_MOBILE_PAGE1 = "mp1";
	public static final String PARA_MOBILE_PAGE2 = "mp2";

	/* 删除提交参数 */
	public static final String PARA_IDLIST = "idlist";

	/* 上传文件参数 */
	public static final String PARA_FILE = "file";

	/*上传文件名参数*/
	public static final String PARA_FILE_NAME = "fname";

	/*手机默认页上传参数*/
	public static final String PARA_INDEX = "index";

	/*查询开始日期*/
	public static final String PARA_BEGIN_DATE = "bdate";

	/*查询结束日期*/
	public static final String PARA_END_DATE = "edate";

	/* 列表属性 */
	public static final String ATTR_LIST = "list";

	/* 单条记录属性 */
	public static final String ATTR_DATA = "data";

	/* 分隔符 */
	public static final String STR_SPLIT = "#";

	/* 错误页面 */
	public static final String PAGE_MSG = "/message.jsp";

	/* 默认每页显示记录数 */
	public static final int NUM_PAGEROWS = 500;

	/* 手机页面存放目录 */
	public static String MOBILE_PAGE_PATH = "MOBILE_PAGE_PATH";

	/* 手机页面资源存放目录 */
	public static String MOBILE_RS_PATH = "MOBILE_RS_PATH";

	/* 访问手机页面的基本路径 */
	public static String MOBILE_PAGE_URL = "MOBILE_PAGE_URL";

	/* 访问手机页面资源的基本路径 */
	public static String MOBILE_RS_URL = "MOBILE_RS_URL";

	/* 访问手机默认页面的路径 */
	public static String MOBILE_INDEX_URL = "MOBILE_INDEX_URL";

	/*手机默认页面文件名*/
	public static String MOBILE_INDEX_NAME = "MOBILE_INDEX_NAME";

	/*备份文件模板*/
	public static String BACKUP_TEMPLATE = "BACKUP_TEMPLATE";

	/*备份文件*/
	public static String BACKUP_FILE = "BACKUP_FILE";

	/*后台管理员*/
	public static String USER_NAME = "USER_NAME";

	/*后台密码*/
	public static String PASSWORD = "PASSWORD";

	/* 参数method */
	public static class PARA_METHOD {
		/* 参数名 */
		public static final String NAME = "method";

		/* 添加操作 */
		public static final String ADD = "1";

		/* 更新操作 */
		public static final String UPDATE = "2";

		/* 删除操作 */
		public static final String DEL = "3";

		/* 显示操作 */
		public static final String SHOW = "4";

		/* 隐藏操作 */
		public static final String HIDE = "5";

		/* 排序操作 */
		public static final String ORDER = "6";

		/* 保存排序操作 */
		public static final String ORDER_SAVE = "7";

		/* 开始滚动操作 */
		public static final String ROLL_START = "8";

		/* 停止滚动操作 */
		public static final String ROLL_STOP = "9";

		/*指定手机特定栏目操作*/
		public static final String MOBILE_SET = "10";

		/*初始化显示序号操作*/
		public static final String INIT_ORDER = "11";

		/*文件删除操作*/
		public static final String DEL_FILE = "12";

		/*查询*/
		public static final String QUERY = "13";

		/*页面访问统计*/
		public static final String STAT_PAGE = "14";

		/*业务跳转统计*/
		public static final String STAT_SERVICE = "15";
	}

	/* 属性errinfo */
	public static class ATTR_PAGE_MSG {
		/* 属性名 */
		public static final String NAME = "page_info";

		public static final String SAME_PARENT_SELF = "1";

		public static final String SAME_CID = "2";

		public static final String SAME_SID = "3";

		public static final String DIR_NOT_EXIST = "4";

		public static final String UPLOAD_SUCCESS = "5";

		public static final String FILE_NOT_EXIST = "6";
	}
}
