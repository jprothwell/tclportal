package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import com.jspsmart.upload.SmartUpload;
import cn.alcatel.wap.db.DBInfo;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import cn.alcatel.wap.db.dao.newadmin;
import cn.alcatel.wap.db.dao.Configuration;

public class viewedit extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  private String newname=null;
  private String lg=null;
  private String newinfo=null;
  private String tempring=null;
  private String mypicName=null;
  private String viewtrace=null;
  private String dirpath=null;
  private String viewpathsql=null;
  private String pathfile=Configuration.newspath;
  private int ringkind=0;
  private int ringspid=0;
  private int newid=0;

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
  // 保存修改前的信息
        newid=Integer.parseInt(su.getRequest().getParameter("newid"));
        savenewbefore(newid);
        dealsome(su);
          com.jspsmart.upload.File myFile = su.getFiles().getFile(0);
          if (!myFile.isMissing()) {
                myfile.delFile(Configuration.newspath,viewpathsql);
                mypicName = new String(myFile.getFileName().getBytes(), "utf-8");
                dirpath = pathfile;
                int suc = createPath(dirpath);
                viewtrace = dirpath + "\\\\" + mypicName;
                viewpathsql =  "/" +mypicName;
                myFile.saveAs(viewtrace, su.SAVE_PHYSICAL);
          }
        Date dt=new Date();
// 设置显示格式
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
// 用DateFormat的format()方法在dt中获取并以yyyy/MM/dd HH:mm:ss格式显示
        String nowTime= df.format(dt);

        int modify_status=newadmin.new_modify(newname,lg,newinfo,viewpathsql,nowTime,newid);
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
// 保存参数
private void savenewbefore(int newid){
  cn.alcatel.wap.db.DBMap[] newbefore=newadmin.get_modify_info(newid);
      newname=newbefore[0].get("na").toString();
      lg=newbefore[0].get("lg").toString();
      System.out.print(lg);
      newinfo=newbefore[0].get("info").toString();
      viewpathsql=newbefore[0].get("picdir").toString();
}
//  获取参数
  private void dealsome(SmartUpload su){
    try {

         newname = new String(su.getRequest().getParameter("viewname").toString().trim().getBytes(), "utf-8");
         lg = new String(su.getRequest().getParameter("lg").toString().trim().getBytes(), "utf-8");
         newinfo = new String(su.getRequest().getParameter("newinfo").toString().trim().getBytes(),"utf-8");
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
