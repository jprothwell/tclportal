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
import servlets.myfile;

public class ringedit extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  private String ringname=null;
  private String filepath=null;
  private String fileName=null;
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
  private int ringid=0;
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
//获得保存前的参数
        dealsome(su);
          com.jspsmart.upload.File myFile = su.getFiles().getFile(0);
          if (!myFile.isMissing()) {
            try {
     //////////////////
     fileName=fileName.substring(fileName.lastIndexOf("/")+1);
     myfile.delFile(Configuration.ringpath+tempring+Configuration.pathurl, fileName);
   }
   catch (Exception ex1) {
   }
                myringName = new String(myFile.getFileName().getBytes(), "utf-8");
                dirpath = pathfile  + tempring ;
                int suc = createPath(dirpath);
                viewtrace = dirpath + Configuration.pathurl + myringName;
                viewpathsql = "sounds/"+ tempring + "/" + myringName;
                //System.out.println("viewtrace="+viewtrace);
                //System.out.println("viewpathsql="+viewpathsql);
                myFile.saveAs(viewtrace, su.SAVE_PHYSICAL);
          }
          else{
            viewpathsql=fileName;
          }
        int modify_status=ringadmin.modify_ring(ringname,lg,ringinfo,ringkind,viewpathsql,ringspid,ringid);
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
//  获取参数
  private void dealsome(SmartUpload su){
    try {
         ringid = Integer.parseInt(su.getRequest().getParameter("ringid"));
         ringname = new String(su.getRequest().getParameter("ringname").toString().trim().getBytes(), "utf-8");
         lg = new String(su.getRequest().getParameter("lg").toString().trim().getBytes(), "utf-8");
         fileName = new String(su.getRequest().getParameter("fileName").toString().trim().getBytes(), "utf-8");
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
// 获取保存前的参数
 public void saveringbefore(int indexid){
       cn.alcatel.wap.db.DBMap[] ringbefore=ringadmin.get_modify_info(indexid);
       ringname=ringbefore[0].get("na").toString();

       lg=ringbefore[0].get("lan").toString();
       ringinfo=ringbefore[0].get("info").toString();
       ringkind = Integer.parseInt(ringbefore[0].get("kindid").toString());
       ringspid=Integer.parseInt(ringbefore[0].get("spid").toString());
       viewpathsql=ringbefore[0].get("filepath").toString();
 }
  //Process the HTTP Post request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    doGet(request, response);
  }

  //Clean up resources
  public void destroy() {
  }
}
