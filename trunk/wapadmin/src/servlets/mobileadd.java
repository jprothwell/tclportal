package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.dao.mobiledb;

public class mobileadd extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";

  //Initialize global variables
  public void init() throws ServletException {
  }

  //Process the HTTP Get request
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    response.setContentType(CONTENT_TYPE);
    PrintWriter out = response.getWriter();
    String  TEMP_RING_FORMAT_1=null;
    String  TEMP_VIDEO_FORMAT_1=null;
    int pageid=0;
    try {
      SmartUpload   su   =   new   SmartUpload();
      su.initialize(this.getServletConfig(), request,response);
      // su.setAllowedFilesList("doc,txt");
      su.upload();

// ua的唯一性
        String modify_ua=new String(su.getRequest().getParameter("uaname").trim().getBytes(),"utf-8");
//        String uaname1=new String(su.getRequest().getParameter("uaname1").trim().getBytes(),"utf-8");
//        int ua_unique=mobiledb.mobile_unique(modify_ua);
//        if(!uaname1.equals(modify_ua) && 1==ua_unique){
//         out.print("<script>alert('已经存在相同的UA!');history.back();</script>");
//      }
//      else{
//图片保存路径
        // su.save("E:/upload/");
        int id = Integer.parseInt(su.getRequest().getParameter("tempid"));
        String modify_name = new String(su.getRequest().getParameter(
            "mobilename").trim().getBytes(), "utf-8");

        int modify_did = Integer.parseInt(su.getRequest().getParameter(
            "mobiledid"));
        int modify_wapinfo = Integer.parseInt(su.getRequest().getParameter(
            "wapinfo"));
        int modify_netinfo = Integer.parseInt(su.getRequest().getParameter(
            "net"));
        if (null == su.getRequest().getParameter("pageclass")) {
          pageid = 0;
        }
        else {
          pageid = Integer.parseInt(su.getRequest().getParameter("pageclass"));
        }
//ring格式处理
        if (null == su.getRequest().getParameterValues("ring_format")) {
          out.print("<script>alert('请选择铃声格式！');history.back();</script>");
        }
        else {
          String[] RING_FORMAT = su.getRequest().getParameterValues(
              "ring_format");
          String TEMP_RING_FORMAT_0 = null;
          TEMP_RING_FORMAT_1 = RING_FORMAT[0];
          int ring_cnt = 1;
          while (ring_cnt < RING_FORMAT.length) {
            TEMP_RING_FORMAT_0 = RING_FORMAT[ring_cnt];
            TEMP_RING_FORMAT_1 = TEMP_RING_FORMAT_1 + "," + TEMP_RING_FORMAT_0;
            ring_cnt++;
          }
          ring_cnt = 1;

//video格式处理
          if (null == su.getRequest().getParameterValues("video_format")) {
            TEMP_VIDEO_FORMAT_1 = "888";
            //  out.print("<script>alert('请选择视频格式！');location.href='/sys/mobile/add.jsp';</script>");
          }
          else {
            String[] VIDEO_FORMAT = su.getRequest().getParameterValues(
                "video_format");
            int video_cnt = 1;
            String TEMP_VIDEO_FORMAT_0 = null;
            TEMP_VIDEO_FORMAT_1 = VIDEO_FORMAT[0];
            while (video_cnt < VIDEO_FORMAT.length) {
              TEMP_VIDEO_FORMAT_0 = VIDEO_FORMAT[video_cnt];
              TEMP_VIDEO_FORMAT_1 = TEMP_VIDEO_FORMAT_1 + "," +
                  TEMP_VIDEO_FORMAT_0;
              video_cnt++;
            }
            video_cnt = 1;
          }
//
          int modify_java_support = Integer.parseInt(su.getRequest().
              getParameter("game_rel"));
          int modify_screen = Integer.parseInt(su.getRequest().getParameter(
              "screen"));
          int modify_mobile_status = mobiledb.modify_mobile(id, modify_name,
              modify_ua, modify_did, modify_wapinfo, modify_netinfo,
              TEMP_RING_FORMAT_1, TEMP_VIDEO_FORMAT_1, modify_java_support,
              modify_screen, pageid);
          if (modify_mobile_status == 1) {
            out.print("<script>alert('信息修改成功！');history.back();</script>");
          }
        }
   //   }
}catch(Exception  ex){
  ex.printStackTrace();
}
//    out.println("<html>");
//    out.println("<head><title>mobileadd</title></head>");
//    out.println("<body bgcolor=\"#ffffff\">");
//    out.println("<p>The servlet has received a " + request.getMethod() + ". This is the reply.</p>");
//    out.println("</body></html>");
  }

  //Process the HTTP Post request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    doGet(request, response);
  }

  //Clean up resources
  public void destroy() {
  }
}
