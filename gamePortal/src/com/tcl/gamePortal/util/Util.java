package com.tcl.gamePortal.util;


import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.util.Enumeration;

public class Util {
  //////////////得到手机号码
  public static String getPhone(HttpServletRequest request) {
    String phnum = request.getHeader("X-Up-Calling-Line-ID");
    if (phnum == null) phnum = request.getHeader("x-up-calling-line-id");
    if (phnum == null) phnum = request.getHeader("x-up-subno");
    if (phnum == null) phnum = request.getHeader("HTTP_X_NETWORK_INFO");
    if (phnum == null) phnum = "1380000000";
    return phnum;
  }

  //////////////得到手机Ip
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
////得到浏览器语言(用于统计)
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
///////////////////////////
}
