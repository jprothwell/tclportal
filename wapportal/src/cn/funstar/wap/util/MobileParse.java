/*
 * Created on 2006-5-29
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.util;

import javax.servlet.http.HttpServletRequest;
import cn.funstar.wap.db.DBMap;
import cn.funstar.wap.db.dao.PageDAO;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class MobileParse {
  public static String getUA(HttpServletRequest req) {
    try {
      String agent = req.getHeader("User-Agent");
      int tmp1 = agent.indexOf("/");
      if (tmp1 == -1) {
        tmp1 = agent.indexOf("*");
      }
      int tmp2 = agent.indexOf(" ");
      if (tmp2 != -1 && tmp2 < tmp1) {
        tmp1 = tmp2;
      }
      if (tmp1 < 1) {
        return agent;
      }
      return agent.substring(0, tmp1);
    }
    catch (Exception e) {
      System.err.println(e);
      return null;
    }
  }

  public static String getAcceptLanguage(HttpServletRequest req) {
    String s = req.getHeader("Accept-Language");
    if (s != null) {
      s = s.substring(0, 2).toLowerCase();
    }
    else {
      s = "en";
    }
//    if (s == null || s.length() == 0) {
//      s = "unknow";
//    }
    return s;
  }

  public static DBMap getMobile(HttpServletRequest req) {
    PageDAO dao = new PageDAO();
    String did = req.getParameter("did");
    DBMap mobileMap = null;
    if (did == null || did.equals("")) {
      String ua = getUA(req);
      if (ua != null && !ua.equals("")) {
        mobileMap = dao.getMobileByUA(ua);
      }
      else {
        mobileMap = dao.getMobileByDid("0");
      }
    }
    else {
      //内置书签错误补救处理
      if (did.startsWith("=")) {
        did = did.substring(1);
        //System.out.println("In this case did is " + did);
      }
      try {
        Integer.parseInt(did);
        mobileMap = dao.getMobileByDid(did);
      }
      catch (NumberFormatException ex) {
        String temp = java.net.URLDecoder.decode(did);
//        System.out.println("enconde ="+java.net.URLEncoder.encode("TCL-M780"));
        mobileMap= dao.getMobileByUA(temp);
        System.out.println("In MobileParse did =" + did);
//        did = "0";
      }
    }
    return mobileMap;
  }

  public static boolean isUnicom(HttpServletRequest req) {
   boolean ret = false;
   String num = req.getHeader("x-up-calling-line-id");
   if (num != null) {
     if (num.startsWith("86")) {
       num = num.substring(2);
     }
     int prefix = Integer.parseInt(num.substring(0, 3), 10);
     switch (prefix) {
       case 130:
       case 131:
       case 132:
       case 133:
       case 153:
       case 156:
         ret = true;
         break;
     }
   }
   //inum is not unicom
   if (!ret) {
     String ip = req.getRemoteAddr();
     ret = new cn.funstar.wap.db.dao.IPDA0().isUnicom(ip);
   }
   return ret;
 }
}

