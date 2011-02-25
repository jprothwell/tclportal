package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.COMMON;
import cn.alcatel.wap.db.DBInfo;
import cn.alcatel.wap.db.dao.picres;
import cn.alcatel.wap.db.dao.Configuration;


public class picadd extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  private String mypicName=null;
  private String myviewName=null;
  private String viewpath=null;
  private String picpath=null;
  private String viewpathsql=null;
  private String picpathsql=null;
  private String commonpath=Configuration.picpath;
  private  String viewtrace=null;
  private String pictrace=null;
  private int sizeid=0;
  private int kindid=0;
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
       COMMON.PICNAME=su.getRequest().getParameter("picname");
       COMMON.SCREENSIZE=Integer.parseInt(su.getRequest().getParameter("screensize"));
       dealpath(su);
       //////////
       com.jspsmart.upload.File file = su.getFiles().getFile(0);
       myviewName = new String(file.getFileName().getBytes(), "utf-8");
       int picsuc = createPath(viewpath);
       viewtrace = viewpath + myviewName;
       viewpathsql = viewpathsql + myviewName;
       int file_status = myfile.existFile(viewpath,myviewName);
    //////////
      com.jspsmart.upload.File file1 = su.getFiles().getFile(1);
      mypicName = new String(file1.getFileName().getBytes(), "utf-8");
      int filesuc = createPath(picpath);
      pictrace = picpath + mypicName;
      picpathsql = picpathsql + mypicName;
      int file_stat = myfile.existFile(pictrace,mypicName);
  ///////////
     if (1== file_status) {
      out.print("<script>alert('此小图片存在,请修改文件名称，重新输入！');history.back();</script>");
      return;
     }
    if (1== file_stat) {
        out.print("<script>alert('此大图片存在,请修改文件名称，重新输入！');history.back();</script>");
        return;
       }
         //插入数据
         int insert_status = picres.insert(COMMON.PICNAME, viewpathsql,
                                           picpathsql, COMMON.SCREENSIZE,kindid,
                                           COMMON.LG, COMMON.TEXTFILE,
                                           COMMON.SPNAME);
 //if (insert_status == 1)out.print("<script>alert('添加信息成功!');location.href='pro/imagepro/index.jsp?sizeid="+COMMON.SCREENSIZE+"';</script>");
 if (insert_status == 1){
   file.saveAs(viewtrace, su.SAVE_PHYSICAL);
   file1.saveAs(pictrace, su.SAVE_PHYSICAL);
   out.print("<script>alert('添加信息成功!');history.back();</script>");
 }
 else out.print("<script>alert('添加请与管理员联系!');history.back();</script>");

 }catch(Exception  ex){
   ex.printStackTrace();
 }
 }

// Process the HTTP Post request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    doGet(request, response);
  }

// Clean up resources
  public void destroy() {
  }
 // 创建路径
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

  public void dealpath(SmartUpload su){
// 获取参
         COMMON.LG=su.getRequest().getParameter("lg");
         COMMON.SPNAME=Integer.parseInt(su.getRequest().getParameter("spname"));
         COMMON.TEXTFILE=su.getRequest().getParameter("picdesc");
         kindid=Integer.parseInt(su.getRequest().getParameter("kindid"));
///////////////
  viewpath=commonpath+DBInfo.FILE_SIZE[COMMON.SCREENSIZE]+Configuration.pathurl;
  viewpath=viewpath+DBInfo.IMAGE_KINDID[kindid]+Configuration.pathurl;
  viewpath=viewpath+"view"+Configuration.pathurl;
  picpath=commonpath+DBInfo.FILE_SIZE[COMMON.SCREENSIZE]+Configuration.pathurl;
  picpath=picpath+DBInfo.IMAGE_KINDID[kindid]+Configuration.pathurl;
  viewpathsql="images/"+DBInfo.FILE_SIZE[COMMON.SCREENSIZE]+"/"+DBInfo.IMAGE_KINDID[kindid]+"/view/";
  picpathsql="images/"+DBInfo.FILE_SIZE[COMMON.SCREENSIZE]+"/"+DBInfo.IMAGE_KINDID[kindid]+"/";
  ///////////////
  }
}
