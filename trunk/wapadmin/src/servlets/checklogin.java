package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import cn.alcatel.wap.db.dao.*;
import java.util.*;

public class checklogin extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";

  //Initialize global variables
  public void init() throws ServletException {
  }

  //Process the HTTP Get request
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    response.setContentType(CONTENT_TYPE);
    PrintWriter out = response.getWriter();
    String user=new String(request.getParameter("username").getBytes("ISO8859-1"),"utf-8");
    String pwd=new String(request.getParameter("password").getBytes("ISO8859-1"),"utf-8");
    String check=new String(request.getParameter("check"));
    HttpSession usersession=request.getSession(true);
    MD5Util md5dao= new MD5Util();
    String temp_pass=md5dao.MD5(pwd);
  ////////shigonglin
 if(!check.equals(usersession.getAttribute("rand"))){
   out.print("<script>alert('验证码不正确，请重输！');location.href='login.jsp';</script>");
   return;
 }
 userDao dao = new userDao();
 String tempResult=dao.checkUserpass(user,temp_pass);
 if(tempResult!=null){
    usersession.setAttribute("sessionUsername",user);
    usersession.setAttribute("sessionRole",tempResult);
    response.sendRedirect("index.jsp");
}else{
  out.print("<script>alert('用户名或者密码不正确，请重输！');location.href='login.jsp';</script>");
}
//////////////////
  }
  //Process the HTTP Post request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    doGet(request, response);
  }

  //Clean up resources
  public void destroy() {
  }
}
