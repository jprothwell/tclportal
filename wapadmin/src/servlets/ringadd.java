package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.DBInfo;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import cn.alcatel.wap.db.dao.ringadmin;
import cn.alcatel.wap.db.dao.Configuration;

public class ringadd extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  private String ringname=null;
  private String lg=null;
  private String ringinfo=null;
  private String tempring=null;
  private String myringName=null;
  private String viewtrace=null;
  private String dirpath=null;
  private String viewpathsql=null;
  private String pathfile=Configuration.ringpath;
  private int ringkind=0;
  private int ringspid=0;
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
          dealsome(su);
          com.jspsmart.upload.File myFile = su.getFiles().getFile(0);
          if (!myFile.isMissing()) {
            myringName = new String(myFile.getFileName().getBytes(), "utf-8");
            dirpath = pathfile + tempring;
            int suc = createPath(dirpath);
            viewtrace = dirpath + Configuration.pathurl+myringName;
            viewpathsql = "sounds/"+ tempring + "/" + myringName;
            int file_status = myfile.existFile(dirpath + Configuration.pathurl, myringName);
            //System.out.println("file_status="+file_status);
            if (1 == file_status) {
              out.print(
                  "<script>alert('已存在此铃声，重新输入！');history.back();</script>");
                return;
            }
            else {
              myFile.saveAs(viewtrace, su.SAVE_PHYSICAL);
              int insert_status = ringadmin.insert(ringname, lg, ringinfo, ringkind,
                                                   viewpathsql, ringspid);
              if (insert_status == 1) {
                out.print("<script>alert('添加信息成功!');history.back();</script>");
              }
              else out.print("<script>alert('添加信息失败，请重输!');history.back();</script>");
            }
          }
  }catch(Exception  ex){
    ex.printStackTrace();
  }
}
//  获取参数
  private void dealsome(SmartUpload su){
    try {
         ringname = new String(su.getRequest().getParameter("ringname").toString().trim().getBytes(), "utf-8");
         lg = new String(su.getRequest().getParameter("lg").toString().trim().getBytes(), "utf-8");
         ringinfo = new String(su.getRequest().getParameter("ringinfo").toString().trim().getBytes(), "utf-8");
         ringkind = Integer.parseInt(su.getRequest().getParameter("typeid"));
         for(int i=0;i<DBInfo.RING_TYPEID.length;i++){
           if(i==ringkind){
             tempring=DBInfo.RING_TYPEID[i];
           }
         }
         ringspid = Integer.parseInt(su.getRequest().getParameter("ringsppro"));
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
