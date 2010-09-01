package cn.alcatel.wap.db;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.util.Enumeration;
import cn.alcatel.wap.db.dao.mobileDao;

public class Util {
  private static mobileDao dao = new mobileDao();
  //////////////�õ�Head
  public static String getHead(HttpServletRequest request) {
    Enumeration headers = request.getHeaderNames();
    String Strname = "";
    while (headers.hasMoreElements()) {
      String head = (String) headers.nextElement();
      Strname = Strname + head + ":" + request.getHeader(head);
    }
    return Strname;
  }

  //////////////�õ��ֻ�����
  public static String getPhone(HttpServletRequest request) {
    String phnum = request.getHeader("X-Up-Calling-Line-ID");
    if (phnum == null) phnum = request.getHeader("x-up-calling-line-id");
    if (phnum == null) phnum = request.getHeader("x-up-subno");
    if (phnum == null) phnum = request.getHeader("HTTP_X_NETWORK_INFO");
    if (phnum == null) phnum = "1380000000";
    return phnum;
  }

  //////////////�õ��ֻ�Ip
  public static String getIp(HttpServletRequest request) {
    String ipnum = request.getRemoteAddr();
    String ipnum1 = request.getParameter("ip");
    //////////////////////////11
    if (ipnum1 != null) {
        HttpSession k = request.getSession(true);
          k.setAttribute("ip", ipnum1);
          k.setMaxInactiveInterval(60 * 5);
    }
    if (request.getSession().getAttribute("ip") != null) {
      ipnum1 = (String) request.getSession().getAttribute("ip");
  }
    //////////////////////////00
    if (ipnum1 != null && ipnum1.length() > 0) ipnum = ipnum1;
    if (ipnum == null) {
      ipnum = "127.0.0.1";
    }
   // System.out.println("ipnum="+ipnum);
    return ipnum;
  }
////�õ����������(����ͳ��)
  public static String getAcceptLanguage(HttpServletRequest request) {
    String s = request.getHeader("Accept-Language");
    if (s != null) {
      s = s.substring(0, 2).toLowerCase();
    }
    if (s == null || s.equals("")) {
      s = "en";
    }
    return s;
  }
  //////�ж�ϵͳ����
  public static String getLanguage(HttpServletRequest request) {
  String lg = request.getParameter("lg");
  String lg1 = Util.getAcceptLanguage(request);
  String ua = Util.getBrowser(request);
  if(lg==null || lg.length()==0)lg=lg1;
  //System.out.println("lg="+lg);
  if(!dao.checkLg(ua,lg))lg="en";
  return lg;
}
  //�õ�ua
  public static String getBrowser(HttpServletRequest request) {
    String ua = Util.getUa(request);
    if(!dao.checkUa(ua))ua = "Alcatel-Tcl";
    if(!dao.checkUamenu(ua))ua = "Alcatel-Tcl";
    return ua;
  }

////////////////////////////�õ�ua(������ͳ��)
  public static String getUa(HttpServletRequest request) {
    String ua = request.getHeader("User-Agent");
    //Force User-Agent for test
    String forceua = request.getParameter("fua");
    if (forceua != null) {
      if (forceua.length() > 0) {
        ua = forceua;
      }
      else {
        //add for opera test
        HttpSession s = request.getSession(true);
        if (s != null) {
          s.setAttribute("fua", "true");
          s.setMaxInactiveInterval(60 * 5);
        }
        ua = null;
      }
    }
    //end
    if (request.getSession().getAttribute("fua") != null) {
      ua = null;
    }
    String did = request.getParameter("did");
    int kid = 0;
    if (ua != null) {
      if (ua.indexOf("/") > 0) {
        ua = ua.substring(0, ua.indexOf("/"));
      }
      if (ua.indexOf(" ") > 0) {
        ua = ua.substring(0, ua.indexOf(" "));
      }
    }
    else {
      if (did != null) {
        try {
          kid = Integer.parseInt(did);
        }
        catch (Exception ex) {
        }
        ////////////
       // mobileDao dao=new mobileDao();
       ua=dao.didUa(kid);
        ///////////
      }
      else {
        ua = "Alcatel-Tcl";
      }
    }
    return ua;
  }
///////////////////////////
}
