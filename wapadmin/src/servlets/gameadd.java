package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.dao.gameadmin;
import cn.alcatel.wap.db.dao.Configuration;

public class gameadd extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  private String commonpath=Configuration.gamespath;
  private String gamename=null;
  private String price=null;
  private String myviewName=null;
  private String myjarName=null;
  private String myjadName=null;
  private String dirpath=null;
  private String viewtrace=null;
  private String pictrace=null;
  private String viewpathsql=null;
  private String picjarpathsql=null;
  private String picjadpathsql=null;
  private String lg=null;
  String model=null;
  String gameinfo=null;
  private int gameapp=0;
  private int screen=0;
  private int sppro=0;

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
        su.upload();
        dealsome(su);
    //////////file images
     com.jspsmart.upload.File myFile = su.getFiles().getFile(0);
      if (!myFile.isMissing()) {
        myviewName = new String(myFile.getFileName().getBytes(), "utf-8");
        viewpathsql = myviewName;
      }
/////////////jar jad file
           com.jspsmart.upload.File myFile1 = su.getFiles().getFile(1);
           com.jspsmart.upload.File myFile2 = su.getFiles().getFile(2);
           myjarName = new String(myFile1.getFileName().getBytes(), "utf-8");
           myjadName = new String(myFile2.getFileName().getBytes(), "utf-8");
           dirpath = commonpath + lg + Configuration.pathurl;
           int picsuc = createPath(dirpath);
           picjarpathsql = myjarName;
           picjadpathsql = myjadName;
           String filetrace1=dirpath+myjarName;
           String filetrace2=dirpath+myjadName;
           int file_status = myfile.existFile(dirpath,myjarName);
           int file_stat   = myfile.existFile(dirpath,myjadName);
   if (1== file_status) {
                out.print("<script>alert('此jar文件存在,请修改文件名称，重新输入！');history.back();</script>");
                return;
               }
   if (1== file_stat) {
                  out.print("<script>alert('此jad文件存在,请修改文件名称，重新输入！');history.back();</script>");
                  return;
                 }
  ///////////file end

        int insert_status=gameadmin.insert(gamename,gameinfo,lg,viewpathsql,picjarpathsql,picjadpathsql,gameapp,screen,sppro,price);
 if (insert_status == 1){
   if (!myFile.isMissing()) {
    myviewName = new String(myFile.getFileName().getBytes(), "utf-8");
    dirpath = commonpath + lg + Configuration.pathurl + "view" +
        Configuration.pathurl;
     createPath(dirpath);
    viewtrace=dirpath+myviewName;
    myFile.saveAs(viewtrace, su.SAVE_PHYSICAL);
  }

    myFile1.saveAs(filetrace1, su.SAVE_PHYSICAL);
   myFile2.saveAs(filetrace2, su.SAVE_PHYSICAL);
   out.print("<script>alert('添加信息成功!');location.href='pro/gamepro/gameindex.jsp?ua="+model+"';</script>");
 }
 else out.print("<script>alert('添加请与管理员联系!');history.back();</script>");
  }catch(Exception  ex){
    ex.printStackTrace();
  }
  }

private void dealsome(SmartUpload su){
  try{
       gamename=new String(su.getRequest().getParameter("gamename").toString().trim().getBytes(),"utf-8");
       price=new String(su.getRequest().getParameter("price").toString().trim().getBytes(),"utf-8");
       gameinfo=new String(su.getRequest().getParameter("gameinfo").toString().trim().getBytes(),"utf-8");
       lg=new String(su.getRequest().getParameter("lg").toString().trim().getBytes(),"utf-8");
       gameapp=Integer.parseInt(su.getRequest().getParameter("gameapp"));
       screen=Integer.parseInt(su.getRequest().getParameter("screen"));
       sppro=Integer.parseInt(su.getRequest().getParameter("sppro"));
  }catch(Exception e){
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
