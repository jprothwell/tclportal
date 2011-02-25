package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.dao.videoadmin;
import cn.alcatel.wap.db.DBInfo;
import cn.alcatel.wap.db.dao.Configuration;


public class videoedit extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  private String videoname=null;
  private String lg=null;
  private String typeid=null;
  private String model=null;
  private String videoinfo=null;
  private String myviewName=null;
  private String commonpath=Configuration.videopath;
  private String dirpath=null;
  private String viewtrace=null;
  private String viewpathsql=null;
  private String fileName=null;
  private String viewName=null;

  private String myvideoName=null;
  private String videotrace=null;
  private String videopathsql=null;


  private int videosize=0;
  private int videosppro=0;
  private int temp=0;
  private int videoid=0;

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
  // 保存修改前的数据
         temp=Integer.parseInt(su.getRequest().getParameter("typeid"));
         videoid=Integer.parseInt(su.getRequest().getParameter("videoid"));
         savevideobefore(videoid);
         dealsome(su);
         //////////////////
         ///////////小图片处理
 com.jspsmart.upload.File myFile = su.getFiles().getFile(0);
 com.jspsmart.upload.File myFile1 = su.getFiles().getFile(1);
if (!myFile.isMissing()) {
 try {

   viewName=viewName.substring(viewName.lastIndexOf("/")+1);
   dirpath=commonpath+typeid+Configuration.pathurl+"view"+Configuration.pathurl;
   myfile.delFile(dirpath, viewName);
 }
 catch (Exception ex1) {
 }
  myviewName = new String(myFile.getFileName().getBytes(), "utf-8");
  viewtrace = dirpath + myviewName;
  viewpathsql ="videos/"+typeid+"/view/"+myviewName;
  System.out.println("viewtrace="+viewtrace);
  myFile.saveAs(viewtrace, su.SAVE_PHYSICAL);
}else
{
viewpathsql=viewName;
}
//////////////////////update videos file
if (!myFile1.isMissing()) {
 try {
   fileName=fileName.substring(fileName.lastIndexOf("/")+1);
   dirpath=commonpath+typeid+Configuration.pathurl;
   myfile.delFile(dirpath, fileName);
 }
 catch (Exception ex1) {
 }
  myviewName = new String(myFile1.getFileName().getBytes(), "utf-8");
  viewtrace = dirpath + myviewName;
  videopathsql ="videos/"+typeid+"/"+myviewName;
  System.out.println("222222222="+viewtrace);
  myFile1.saveAs(viewtrace, su.SAVE_PHYSICAL);
}else
{
videopathsql=fileName;
}

//////////////////////

/////////插入数据
         int modify_status=videoadmin.modify_video(videoname,lg,model,videoinfo,videosppro,videosize,viewpathsql,videopathsql,videoid);
         if(modify_status==1){
           out.print("<script>alert('修改成功！');history.back();</script>");
         }
         else{
           out.print("<script>alert('修改不成功！');history.back();</script>");
         }
   }catch(Exception  ex){
     ex.printStackTrace();
   }
   }

private void savevideobefore(int videoid){
         cn.alcatel.wap.db.DBMap[] videobefore=videoadmin.get_modify_info(videoid);
         videoname=videobefore[0].get("na").toString();
         lg=videobefore[0].get("lg").toString();
         viewpathsql=videobefore[0].get("picdir").toString();
         videopathsql=videobefore[0].get("fileaddr").toString();
}
 private void dealsome(SmartUpload su){
   try{
         fileName=new String(su.getRequest().getParameter("fileName").toString().trim().getBytes(),"utf-8");
         viewName=new String(su.getRequest().getParameter("viewName").toString().trim().getBytes(),"utf-8");
        videoname=new String(su.getRequest().getParameter("videoname").toString().trim().getBytes(),"utf-8");
        lg=new String(su.getRequest().getParameter("lg").toString().trim().getBytes(),"utf-8");
        temp=Integer.parseInt(su.getRequest().getParameter("typeid"));
        for(int i=0;i<DBInfo.VIDEO_TYPEID.length;i++){
            if(i==temp){
              typeid=new String(DBInfo.VIDEO_TYPEID[i]);
            }
        }
        model=new String(su.getRequest().getParameter("model").toString().trim().getBytes(),"utf-8");
        videoinfo=new String(su.getRequest().getParameter("videoinfo").toString().trim().getBytes(),"utf-8");
        videosppro=Integer.parseInt(su.getRequest().getParameter("videosppro"));
        videosize=Integer.parseInt(su.getRequest().getParameter("videosize"));
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
