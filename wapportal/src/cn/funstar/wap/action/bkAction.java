/*
 * Created on 2006-5-30
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.action;

import javax.servlet.http.*;

import cn.funstar.wap.db.*;
import cn.funstar.wap.db.dao.*;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class bkAction {
  String service = null;
  // String mobile = null;
  String did = null;
  String url = null;
  String spurl = null;

  public bkAction(HttpServletRequest req) {
    String sid = req.getParameter("id");
    DBMap mobileMap = (DBMap) req.getSession().getAttribute("mobile");
    if (mobileMap == null) {
      mobileMap = cn.funstar.wap.util.MobileParse.getMobile(req);
    }
    if (mobileMap != null) {
      //   mobile = String.valueOf(mobileMap.get(DBInfo.COMMON_ID));
      did = String.valueOf(mobileMap.get(DBInfo.MOBILE_DID));
    }
    if (did == null || did.equals("")) {
      did = "0";
    }

    DBMap serviceMap = new PageDAO().getServiceBySid(sid);
    if (serviceMap != null && !serviceMap.isEmpty()) {
      service = String.valueOf(serviceMap.get(DBInfo.COMMON_ID));
      url = String.valueOf(serviceMap.get(DBInfo.SERVICE_URL));
      spurl = url;
    }

    if ("28".equals(sid)) {
      return;
    }

    if (url != null && !url.equals("")) {
      // if (url.startsWith("http://")) {
      if (url.indexOf("?") > 0) {
        //url = url.replaceAll("&", "&amp;") + "&amp;did=" + did;
        url = url + "&did=" + did;
      }
      else {
        url = url + "?did=" + did;
      }
      //   }
      //language
//      String lg = req.getParameter("lg");
//      if (lg != null && lg.length() > 0) {
//        url = url + "&lg=" + lg;
//      }
    }
  }

  public String getDid() {
    return did;
  }

  public String getUrl() {
    return url;
  }

  public void log() {
    try {
      LogAction.serviceLog(service, did, spurl);
    }
    catch (Exception e) {
      System.out.println(" at bkAction log");
      e.printStackTrace();
    }
  }
}
