package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.dao.pagedb;
import cn.alcatel.wap.db.dao.Configuration;
import servlets.myfile;

public class pageadd extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  public String pathdir=Configuration.pageaddress;
  private String mypageName=null;
  private String viewtrace=null;
  private String pagedescription=null;
  private String language=null;
  private String temppagekind=null;
  private String pagename=null;
  private String viewsqltrace=null;
  private String urlName=null;

  private int pagekind=0;
  private String languagekind="en";




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
      com.jspsmart.upload.File file = su.getFiles().getFile(0);
      if (!file.isMissing()) {
        mypageName = new String(file.getFileName().getBytes(), "utf-8");
        int suc = createPath(pathdir);
        viewtrace = pathdir + mypageName;
        viewsqltrace = mypageName;
        int file_status = myfile.existFile(Configuration.pageaddress,
                                           mypageName);
        if (1 == file_status) {
          out.print("<script>alert('已存在此文件,请修改文件名称，重新输入！');history.back();</script>");
        }
        else {
          file.saveAs(viewtrace, su.SAVE_PHYSICAL);
          //ring格式处理
          int insert_mobile_status = pagedb.insert(pagename, mypageName,
              pagekind, languagekind, pagedescription, urlName);
          if (insert_mobile_status == 1) {
            out.print("<script>alert('页面信息添加成功！');history.back();</script>");
          }
        }
      }
      else {
        out.print("<script>alert('请添加页面！');history.back();</script>");
      }

    }
    catch (Exception ex) {
      ex.printStackTrace();
    }
  }

//  获取参数
  private void dealsome(SmartUpload su){
    try {
         pagedescription = new String(su.getRequest().getParameter("pagedescription").getBytes(), "utf-8");
         language = new String(su.getRequest().getParameter("language").getBytes(), "utf-8");
         temppagekind = new String(su.getRequest().getParameter("pagekind").getBytes(), "utf-8");
         pagename = new String(su.getRequest().getParameter("pagename").getBytes(), "utf-8");
         pagekind = Integer.parseInt(temppagekind);
         languagekind = new String(su.getRequest().getParameter("language").getBytes(), "utf-8");
         urlName=new String(su.getRequest().getParameter("urlName").getBytes(), "utf-8");
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }
// 创建文件夹
 private int createPath(String path){
   File filedir=new File(path);
 //  System.out.print(path);
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
