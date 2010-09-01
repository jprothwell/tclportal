package cn.alcatel.wap.db;

import java.io.DataInputStream;
import java.net.*;
import java.io.OutputStreamWriter;
import java.io.*;
import javax.servlet.http.HttpServletRequest;
import cn.alcatel.wap.db.dao.visitDao;

public class Stat {
  private static visitDao dao = new visitDao();
  ////////计数
  public static void statIndex(HttpServletRequest request, String testname) {
    try {
      String ua = Util.getUa(request);
      String phonenum = Util.getPhone(request);
      String ipnum = Util.getIp(request);
      String srel = Util.getAcceptLanguage(request);
      String menuname = request.getParameter("category");
      if (menuname == null) {
        menuname = testname;
      }
      if (srel == null || srel.length() == 0) {
        srel = Util.getAcceptLanguage(request);
      }
      //System.out.print("11111111");
      dao.insert(URLEncoder.encode(menuname),phonenum,srel,ua,ipnum);
    }
    catch (Exception ex) {
    }
  }
  ////////
  ////////下载计数
  public static void statDownload(HttpServletRequest request) {
      try {
        String ua = Util.getUa(request);
        String phonenum = Util.getPhone(request);
        String ipnum = Util.getIp(request);
        String srel = Util.getAcceptLanguage(request);
        /////////////////
        String resourcename = request.getParameter("resourcename");
        String spname = request.getParameter("spname");
        String groupid= request.getParameter("groupid");
        ////////////////////////////////////////
        int group_id=Integer.parseInt(groupid);
        String menu1 = DBInfo.MENU_INFO[group_id];
        ///////////////////////////////
        if (srel == null || srel.length() == 0) {
          srel = Util.getAcceptLanguage(request);
        }
        dao.insertDM(menu1,URLEncoder.encode(resourcename),phonenum,srel,ua,ipnum,spname);
      }
      catch (Exception ex) {
      }
    }
////////////////////////////////

}
