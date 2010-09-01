/*
 * Created on 2006-5-30
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.action;

import java.util.*;
import javax.servlet.http.*;

import cn.funstar.wap.db.*;
import cn.funstar.wap.db.dao.*;
import cn.funstar.wap.util.*;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class indexAction {
  private String did = null;
  private String page = null;
  private String pageUrl = null;
  private String ip = null;
  private String phonenum = null;
  private static Map alias = null;
  private static Random ramdom = new Random();

  public indexAction(HttpServletRequest req) {
    initAlias();
    DBMap mobileMap = MobileParse.getMobile(req);
    if (mobileMap != null) {
      did = String.valueOf(mobileMap.get(DBInfo.MOBILE_DID));
      if (mobileMap.get(DBInfo.F_MOBILE_PAGE) != null) {
        pageUrl = mobileMap.get(DBInfo.F_MOBILE_PAGE).toString();
      }
      if (mobileMap.get(DBInfo.MOBILE_PAGE) != null) {
        page = mobileMap.get(DBInfo.MOBILE_PAGE).toString();
      }
    }

    if (pageUrl == null || pageUrl.length() == 0) {
      pageUrl = Common.MOBILE_INDEX_URL;
    }
    else {
      pageUrl = Common.MOBILE_PAGE_URL + pageUrl;
    }
    if (did == null || did.length() == 0) {
      did = "0";
    }
    pageUrl = pageUrl + "?did=" + did;
    // define for log
    ip = req.getRemoteAddr();
    phonenum = req.getHeader("x-up-calling-line-id");
  }

  private void initAlias() {
    if (alias == null) {
      alias = new HashMap();
      try {
        ResourceBundle oRsBd = ResourceBundle.getBundle("servicalias");
        Enumeration e = oRsBd.getKeys();
        String key = null;
        String value = null;
        String[] values = null;
        while (e.hasMoreElements()) {
          key = (String) e.nextElement();
          value = new String(oRsBd.getString(key).getBytes("ISO8859-1"),
                             "UTF-8");
          values = value.split(",");
          alias.put(values[0], values);
        }
      }
      catch (Exception e) {
        System.err.println("initAlias Exception");
        // e.printStackTrace();
      }
    }
  }

  public String getPageUrl() {
    return pageUrl;
  }

  public void log() {
    try {
      LogAction.indexLog(page, did, ip, phonenum);
    }
    catch (Exception e) {
      System.out.println(" at indexAction log");
      e.printStackTrace();
    }
  }

  public DBMap[] getList(String channel) {
    PageDAO dao = new PageDAO();
    DBMap map[] = dao.getListByChannel(channel, 0, 0);
    return map;
  }

  public String getAlias(String name) {
    String ret = name;
    if (this.alias != null) {
      String[] alias = (String[])this.alias.get(name);
      if (alias != null) {
        int index = (ramdom.nextInt() >>> 1) % alias.length;
        ret = alias[index];
      }
    }
    return ret;
  }
}
