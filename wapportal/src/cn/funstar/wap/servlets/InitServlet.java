/*
 * Created on 2006-5-16
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.servlets;

import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;

import cn.funstar.wap.util.*;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class InitServlet
    extends HttpServlet {
  public void init() throws ServletException {
    try {
      super.init();

      /*��ʼ�����ݿ����ӳ�*/
      try {
        System.out.println(cn.funstar.wap.db.DBPool.init());
      }
      catch (Exception e) {
        System.err.println(e);
        throw e;
      }

      /*��ȡ�����ļ���Ϣ*/
      try {
        ResourceBundle oRsBd = ResourceBundle.getBundle("config");
//		      Common.MOBILE_RS_URL = oRsBd.getString(Common.MOBILE_RS_URL);
//		      Common.MOBILE_RS_PATH = oRsBd.getString(Common.MOBILE_RS_PATH).replace(File.separator.charAt(0), '/');
        Common.MOBILE_PAGE_URL = oRsBd.getString(Common.MOBILE_PAGE_URL);
//		      Common.MOBILE_PAGE_PATH = oRsBd.getString(Common.MOBILE_PAGE_PATH).replace(File.separator.charAt(0), '/');
        Common.MOBILE_INDEX_URL = oRsBd.getString(Common.MOBILE_INDEX_URL);
      }
      catch (Exception e) {
        System.err.println(e);
      }

    }
    catch (Exception e) {
      throw new ServletException(e);
    }
  }

  public void destroy() {
    /*�رջỰ*/
    // do something
  }
}
