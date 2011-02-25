package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.COMMON;
import cn.alcatel.wap.db.DBInfo;
import cn.alcatel.wap.db.dao.picres;
import cn.alcatel.wap.db.dao.Configuration;
import servlets.myfile;


public class editpic extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  // edit
  private String picname=null;
  private String pathview=null;
  private String picdesc=null;
  private int spname=0;
  private String language=null;
  private int sizeid=0;
  private int kindid=0;
  private int indexid=0;

  private String mypicName=null;
  private String myviewName=null;
  private String viewpath=null;
  private String picpath=null;
  private String picName=null;
  private String viewName=null;
  private String pathpic=null;
  private String viewpathsql=null;
  private String picpathsql=null;
  private String commonpath=Configuration.picpath;
  private  String viewtrace=null;
  private String pictrace=null;


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
       dealpath(su);
       dealpath(sizeid,kindid);
       ///////////小图片处理
    com.jspsmart.upload.File myFile = su.getFiles().getFile(0);
    com.jspsmart.upload.File myFile1 = su.getFiles().getFile(1);
   if (!myFile.isMissing()) {
    try {
      //////////////////
      viewName=viewName.substring(viewName.lastIndexOf("/")+1);
      myfile.delFile(viewpath, viewName);
    }
    catch (Exception ex1) {
    }
     myviewName = new String(myFile.getFileName().getBytes(), "utf-8");
     int picsuc = createPath(viewpath);
     viewtrace = viewpath + myviewName;
     viewpathsql = viewpathsql + myviewName;
     myFile.saveAs(viewtrace, su.SAVE_PHYSICAL);
 }else
 {
 viewpathsql=viewName;
 }
 ///////////////大图片处理
 if (!myFile1.isMissing()) {
  try {
    picName=picName.substring(picName.lastIndexOf("/")+1);
    myfile.delFile(picpath, picName);
  }
  catch (Exception ex1) {
  }
   mypicName = new String(myFile1.getFileName().getBytes(), "utf-8");
   int picsuc = createPath(picpath);
   pictrace = picpath + mypicName;
   picpathsql = picpathsql + mypicName;
   myFile1.saveAs(pictrace, su.SAVE_PHYSICAL);
}else
{
picpathsql=picName;
}
/////////////插入数据
int modify_status=picres.modify_pic(indexid,picname,viewpathsql,picpathsql,sizeid,kindid,language,picdesc,spname);
       if(modify_status==1){
         out.print("<script>alert('修改信息成功!');history.back();</script>");
       }
       else{
          out.print("<script>alert('修改信息失败!');history.back();</script>");
       }
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
// 获取保存前的参数
 public void savebefore(int indexid){
       cn.alcatel.wap.db.DBMap[] picbefore=picres.get_modify_info(indexid);
       picname=picbefore[0].get("na").toString();
       viewpathsql=picbefore[0].get("pathview").toString();
       picpathsql=picbefore[0].get("picpath").toString();
       language=picbefore[0].get("lg").toString();
       sizeid=Integer.parseInt(picbefore[0].get("size").toString());
       spname=Integer.parseInt(picbefore[0].get("spid").toString());
       picdesc=picbefore[0].get("info").toString();
 }
  public void dealpath(SmartUpload su){
// 获取参数
         indexid=Integer.parseInt(su.getRequest().getParameter("editid"));
// 获取修改前的参数
         savebefore(indexid);
// 获取新的参数
         picName=su.getRequest().getParameter("picName");
         viewName=su.getRequest().getParameter("viewName");
         picname=su.getRequest().getParameter("picname");
         language=su.getRequest().getParameter("lg");
         sizeid=Integer.parseInt(su.getRequest().getParameter("sizeid"));
         kindid=Integer.parseInt(su.getRequest().getParameter("kindid"));
         spname=Integer.parseInt(su.getRequest().getParameter("spname"));
         picdesc=su.getRequest().getParameter("picdesc");
         pathpic=su.getRequest().getParameter("pathpic");
         pathview=su.getRequest().getParameter("pathview");
//      System.out.println("abelyangxin"+COMMON.TEXTFILE);

  }
  public void dealpath(int sizeid,int kindid){
viewpath=commonpath+DBInfo.FILE_SIZE[COMMON.SCREENSIZE]+Configuration.pathurl;
viewpath=viewpath+DBInfo.IMAGE_KINDID[kindid]+Configuration.pathurl;
viewpath=viewpath+"view"+Configuration.pathurl;
picpath=commonpath+DBInfo.FILE_SIZE[COMMON.SCREENSIZE]+Configuration.pathurl;
picpath=picpath+DBInfo.IMAGE_KINDID[kindid]+Configuration.pathurl;
viewpathsql="images/"+DBInfo.FILE_SIZE[COMMON.SCREENSIZE]+"/"+DBInfo.IMAGE_KINDID[kindid]+"/view/";
picpathsql="images/"+DBInfo.FILE_SIZE[COMMON.SCREENSIZE]+"/"+DBInfo.IMAGE_KINDID[kindid]+"/";
  }
}
