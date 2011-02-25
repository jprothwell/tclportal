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

public class gameedit extends HttpServlet {
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
  private String gameinfo=null;
   private String imageName=null;
   private String file1Name=null;
   private String file2Name=null;
  private int gameapp=0;
  private int screen=0;
  private int sppro=0;
  private int gameid=0;

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
// 保存修改前的参数
       // System.out.print("test:"+su.getRequest().getParameter("gameid").toString());
        gameid=Integer.parseInt(su.getRequest().getParameter("gameid").toString());
        savegamebefore(gameid);
        dealsome(su);
  //////////////////////////////
  com.jspsmart.upload.File myFile  = su.getFiles().getFile(0);
  com.jspsmart.upload.File myFile1 = su.getFiles().getFile(1);
  com.jspsmart.upload.File myFile2 = su.getFiles().getFile(2);
  //////////处理小图片
  if (!myFile.isMissing()) {
    try {
      //////////////////
      dirpath = commonpath + lg + Configuration.pathurl + "view" +
            Configuration.pathurl;
      myfile.delFile(dirpath, imageName);
    }
    catch (Exception ex1) {
    }
     myviewName = new String(myFile.getFileName().getBytes(), "utf-8");
     ///////
  viewtrace=dirpath+myviewName;
  viewpathsql = myviewName;
  myFile.saveAs(viewtrace, su.SAVE_PHYSICAL);
 }else
 {
 viewpathsql=imageName;
 }
////////处理jar jad 文件
 if (!myFile1.isMissing()) {
   dirpath = commonpath + lg + Configuration.pathurl;
   myjarName = new String(myFile1.getFileName().getBytes(), "utf-8");
   try {
    myfile.delFile(dirpath, file1Name);
  }
  catch (Exception ex1) {
  }
   pictrace=pictrace+myjarName;
   picjarpathsql = myjarName;
   myFile1.saveAs(pictrace, su.SAVE_PHYSICAL);
 }else {
 picjarpathsql=file1Name;
 }
 /////////
 if (!myFile2.isMissing()) {
 dirpath = commonpath + lg + Configuration.pathurl;
 myjadName = new String(myFile2.getFileName().getBytes(), "utf-8");
   try {
 myfile.delFile(dirpath, file2Name);
}
catch (Exception ex1) {
}
        pictrace=pictrace+myjadName;
        picjadpathsql = myjadName;
        myFile2.saveAs(pictrace, su.SAVE_PHYSICAL);
}else {
picjadpathsql=file2Name;
}
//////////////////
int modify_status=gameadmin.modify_game(gamename,price,gameinfo,lg,viewpathsql,picjarpathsql,picjadpathsql,screen,sppro,gameid);
        if(modify_status==1){
    out.print("<script>alert('修改成功!');location.href='pro/gamepro/gameindex.jsp';</script>");
        }
        else{
          out.print("<script>alert('修改信息失败!');history.back();</script>");
        }
  }catch(Exception  ex){
    ex.printStackTrace();
  }
  }
private void savegamebefore(int gameid){
     cn.alcatel.wap.db.DBMap[] gamesavebefore=gameadmin.get_modify_info(gameid);
     gamename=gamesavebefore[0].get("na").toString();
     price=gamesavebefore[0].get("price").toString();
     viewpathsql=gamesavebefore[0].get("images").toString();
     gameinfo=gamesavebefore[0].get("info").toString();

     picjarpathsql=gamesavebefore[0].get("jar").toString();
     picjadpathsql=gamesavebefore[0].get("jad").toString();
     sppro=Integer.parseInt(gamesavebefore[0].get("spid").toString());
     lg=gamesavebefore[0].get("lg").toString();

}
private void dealsome(SmartUpload su){
  try{
       gamename=new String(su.getRequest().getParameter("gamename").toString().trim().getBytes(),"utf-8");
       price=new String(su.getRequest().getParameter("price").toString().trim().getBytes(),"utf-8");
       gameinfo=new String(su.getRequest().getParameter("gameinfo").toString().trim().getBytes(),"utf-8");
       lg=new String(su.getRequest().getParameter("lg").toString().trim().getBytes(),"utf-8");
       gameapp=Integer.parseInt(su.getRequest().getParameter("gameapp"));
       imageName=new String(su.getRequest().getParameter("imageName").toString().trim().getBytes(),"utf-8");
       file1Name=new String(su.getRequest().getParameter("file1Name").toString().trim().getBytes(),"utf-8");
       file2Name=new String(su.getRequest().getParameter("file2Name").toString().trim().getBytes(),"utf-8");
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
