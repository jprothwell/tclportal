package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.dao.pagedb;
import cn.alcatel.wap.db.dao.Configuration;

public class pageedit extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  public String pathdir=Configuration.pageaddress;
  private String mypageName=null;
  private String viewtrace=null;
  private String fileName=null;
  private String pagedescription=null;
  private String language=null;
  private String temppagekind=null;
  private String pagename=null;
  private String viewsqltrace=null;

  private int pagekind=0;
  private int pageid=0;




  //Initialize global variables
  public void init() throws ServletException {
  }

  //Process the HTTP Get request
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    response.setContentType(CONTENT_TYPE);
    PrintWriter out = response.getWriter();
    try {
      SmartUpload su = new SmartUpload();
      su.initialize(this.getServletConfig(), request, response);
      su.upload();
      //图片保存路径
      dealsome(su);
      com.jspsmart.upload.File my = su.getFiles().getFile(0);
      ////////////////////////////test
      if (!my.isMissing()) {
        //////////
        mypageName = new String(my.getFileName().getBytes(), "utf-8");
        int file_status = myfile.existFile(Configuration.pageaddress,
                                           mypageName);
        if(1 == file_status){
          if(fileName.equals(mypageName)){
          ///////就覆盖
          myfile.delFile(Configuration.pageaddress,fileName);
          viewtrace = pathdir + mypageName;
           my.saveAs(viewtrace, su.SAVE_PHYSICAL);
           int modify_page_status = pagedb.modify_page(pagename, mypageName,
                pagekind, language, pagedescription, pageid);
            if (modify_page_status == 1) {
              out.print("<script>alert('页面信息修改成功！');history.back();</script>");
            }
          //////////////
          }else{
            ////跳出循环
           out.print("<script>alert('已存在此文件！');history.back();</script>");
           return;
          }
        }else{
        ///添加新文件，添加纪录
        myfile.delFile(Configuration.pageaddress,fileName);
        viewtrace = pathdir + mypageName;
        my.saveAs(viewtrace, su.SAVE_PHYSICAL);
        int modify_page_status = pagedb.modify_page(pagename, mypageName,
             pagekind, language, pagedescription, pageid);
         if (modify_page_status == 1) {
           out.print("<script>alert('页面信息修改成功！');history.back();</script>");
         }
        }
      }
      else {
        int modify_page_status = pagedb.modify_page(pagename, fileName,
              pagekind, language, pagedescription, pageid);
          if (modify_page_status == 1) {
            out.print("<script>alert('信息修改成功！');history.back();</script>");
          }
      }
      ///////////////////////////test
    }
    catch (Exception ex) {
      ex.printStackTrace();
    }
  }

//  获取参数
  private void dealsome(SmartUpload su){
    try {
         pageid=Integer.parseInt(su.getRequest().getParameter("pageid"));
         fileName= new String(su.getRequest().getParameter("fileName").getBytes(), "utf-8");
         //viewsqltrace= new String(su.getRequest().getParameter("pageurl").getBytes(), "utf-8");
         pagedescription = new String(su.getRequest().getParameter("pagedescription").getBytes(), "utf-8");
         language = new String(su.getRequest().getParameter("language").getBytes(), "utf-8");
         temppagekind = new String(su.getRequest().getParameter("pagekind").getBytes(), "utf-8");
         pagename = new String(su.getRequest().getParameter("pagename").getBytes(), "utf-8");
         pagekind = Integer.parseInt(temppagekind);
    }
    catch (Exception e) {
      e.printStackTrace();
    }
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
