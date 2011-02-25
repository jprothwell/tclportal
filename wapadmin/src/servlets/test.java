package servlets;
/*
  *********************
   @author:abel
   @date:2009-08-09
*/

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.dao.mobiledb;
import cn.alcatel.wap.db.dao.Configuration;

public class test extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  private String MOBILE_NAME=null;
  private String MOBILE_UA=null;
  private String viewtrace=null;
  private String mobilepicName=null;
  private int MOBILE_DID=0;
  private String mobilepicpath=Configuration.mobilepicpath;
  private int MOBILE_VERSION=0;

  private int MOBILE_NET=0;
  private int JAVA_SUPPORT=0;
  private int SCREEN_SIZE=0;

  private String[] RING_FORMAT=null;
  private String[] VIDEO_FORMAT=null;
  private int ring_cnt=1;
  private int video_cnt=1;
  private String TEMP_RING_FORMAT_0=null;
  private String TEMP_RING_FORMAT_1=null;

  private String TEMP_VIDEO_FORMAT_0=null;
  private String TEMP_VIDEO_FORMAT_1=null;

  private int pageclass=0;


  private String FILE_DIR=null;

  private int insert_mobile_status=0;


  //Initialize global variables
  public void init() throws ServletException {
  }

  //Process the HTTP Get request
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    response.setContentType(CONTENT_TYPE);
    PrintWriter out = response.getWriter();
 try {
       SmartUpload   su   =   new   SmartUpload();
       su.initialize(this.getServletConfig(), request,response);
       // su.setAllowedFilesList("doc,txt");
       su.upload();
  // 处理ua的唯一性
        String test=new String(su.getRequest().getParameter("mobilename").getBytes(),"utf-8");
        MOBILE_NAME=test;
        MOBILE_UA=su.getRequest().getParameter("uaname").trim();
        if(null!=su.getRequest().getParameter("pageclass")){
          pageclass = Integer.parseInt(su.getRequest().getParameter("pageclass"));
        }
        else{
             pageclass=0;
        }
        int ua_unique=mobiledb.mobile_unique(MOBILE_UA);
        if(1==ua_unique){
           out.print("<script>alert('已经存在相同的UA!');history.back();</script>");
        }
 //图片保存路径
       else{
         int filedir = createPath(mobilepicpath);
         com.jspsmart.upload.File myFile = su.getFiles().getFile(0);
         if (!myFile.isMissing()) {
           mobilepicName = new String(myFile.getFileName().getBytes(), "utf-8");
           int suc = createPath(mobilepicpath);
           viewtrace = mobilepicpath + "\\\\" + mobilepicName;
           myFile.saveAs(viewtrace, su.SAVE_PHYSICAL);
         }

         MOBILE_NAME = su.getRequest().getParameter("mobilename").trim();
         String mobile_temp = new String(su.getRequest().getParameter(
             "mobilename").trim().getBytes("ISO8859-1"), "utf-8");
         MOBILE_UA = su.getRequest().getParameter("uaname").trim();

         MOBILE_DID = Integer.parseInt(su.getRequest().getParameter("mobiledid"));
         MOBILE_VERSION = Integer.parseInt(su.getRequest().getParameter(
             "wapinfo"));
         MOBILE_NET = Integer.parseInt(su.getRequest().getParameter("net"));
 //ring格式处理
         if (null == su.getRequest().getParameterValues("ring_format")) {
           out.print("<script>alert('请选择铃声格式！');history.back();</script>");
         }
         else {
           RING_FORMAT = su.getRequest().getParameterValues("ring_format");
           TEMP_RING_FORMAT_1 = RING_FORMAT[0];
           while (ring_cnt < RING_FORMAT.length) {
             TEMP_RING_FORMAT_0 = RING_FORMAT[ring_cnt];
             TEMP_RING_FORMAT_1 = TEMP_RING_FORMAT_1 + "," + TEMP_RING_FORMAT_0;
             ring_cnt++;
           }
           ring_cnt = 1;

 //video格式处理
           if (null == su.getRequest().getParameterValues("video_format")) {
             TEMP_VIDEO_FORMAT_1 = "888";
             // out.print("<script>alert('请选择视频格式！');location.href='/sys/mobile/add.jsp';</script>");
           }
           else {
             VIDEO_FORMAT = su.getRequest().getParameterValues("video_format");
             TEMP_VIDEO_FORMAT_1 = VIDEO_FORMAT[0];
             while (video_cnt < VIDEO_FORMAT.length) {
               TEMP_VIDEO_FORMAT_0 = VIDEO_FORMAT[video_cnt];
               TEMP_VIDEO_FORMAT_1 = TEMP_VIDEO_FORMAT_1 + "," +
                   TEMP_VIDEO_FORMAT_0;
               video_cnt++;
             }
             video_cnt = 1;
           }

           JAVA_SUPPORT = Integer.parseInt(su.getRequest().getParameter(
               "game_rel"));
           SCREEN_SIZE = Integer.parseInt(su.getRequest().getParameter("kindid"));
           // System.out.print("yangxin="+mobile_temp);
           insert_mobile_status = mobiledb.insert(MOBILE_NAME, MOBILE_UA,
                                                  MOBILE_DID, MOBILE_VERSION,
                                                  MOBILE_NET, TEMP_RING_FORMAT_1,
                                                  TEMP_VIDEO_FORMAT_1,
                                                  JAVA_SUPPORT, SCREEN_SIZE,pageclass);
           if (insert_mobile_status == 1) {
             out.print("<script>alert('终端信息添加成功！');history.back();</script>");
           }
         }
       }
 }catch(Exception  ex){
   ex.printStackTrace();
 }
//    out.println("<html>");
//    out.println("<head><title>test</title></head>");
//    out.println("<body bgcolor=\"#ffffff\">");
//    out.println("<p>The servlet has received a " + request.getMethod() + ". This is mobile reply.</p>");
//    out.println("</body></html>");
  }
  // 创建文件夹
 private int createPath(String path){
   File filedir=new File(path);
   if(filedir.exists()){
      return 0;
   }
   else{
       filedir.mkdirs();
       return 1;
   }
 }

  //Process the HTTP Post request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
  doGet(request, response);
  }

  //Clean up resources
  public void destroy() {
  }
}
