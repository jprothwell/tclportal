package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.dao.videoadmin;
import cn.alcatel.wap.db.DBInfo;
import cn.alcatel.wap.db.dao.Configuration;


public class videoadd extends HttpServlet {
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

  private String myvideoName=null;
  private String videotrace=null;
  private String videopathsql=null;


  private int videosize=0;
  private int videosppro=0;
  private int temp=0;

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
         //////////////////////////
        com.jspsmart.upload.File file = su.getFiles().getFile(0);
        myviewName = new String(file.getFileName().getBytes(), "utf-8");
        dirpath = commonpath + typeid + Configuration.pathurl + "view" + Configuration.pathurl;
        int suc = createPath(dirpath);
        viewtrace = dirpath + myviewName;
        viewpathsql ="videos/" + typeid +"/view/"+ myviewName;
        int file_status = myfile.existFile(dirpath,myviewName);
     //////////
       com.jspsmart.upload.File file1 = su.getFiles().getFile(1);
       myvideoName = new String(file1.getFileName().getBytes(), "utf-8");
       dirpath = commonpath + typeid + Configuration.pathurl;
       int filesuc = createPath(dirpath);
       videotrace = dirpath + myvideoName;
       videopathsql = "videos/" + typeid +"/"+ myvideoName;
       int file_stat = myfile.existFile(videotrace,myvideoName);
       ///////////
         if (1== file_status) {
          out.print("<script>alert('此小图片存在,请修改文件名称，重新输入！');history.back();</script>");
          return;
         }
         if (1== file_stat) {
            out.print("<script>alert('此大图片存在,请修改文件名称，重新输入！');history.back();</script>");
            return;
           }
         ///////////////////////
  int insert_status=videoadmin.insert(videoname,lg,temp,model,videoinfo,videosppro,videosize,viewpathsql,videopathsql);
  if (insert_status == 1){
    file.saveAs(viewtrace, su.SAVE_PHYSICAL);
    file1.saveAs(videotrace, su.SAVE_PHYSICAL);
    out.print("<script>alert('添加信息成功!');history.back();</script>");
    //out.print("<script>alert('添加信息成功!');location.href='pro/videopro/index.jsp?typeid="+temp+"';</script>");
  }
  else out.print("<script>alert('添加请与管理员联系!');history.back();</script>");
   }catch(Exception  ex){
     ex.printStackTrace();
   }
   }

 private void dealsome(SmartUpload su){
   try{
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
