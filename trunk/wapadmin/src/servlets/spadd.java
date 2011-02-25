package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import cn.alcatel.wap.db.dao.spadmin;

public class spadd extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";
  private String spname=null;
  private String username=null;
  private String userphone=null;
  private String useremail=null;
  private String clientphone=null;
  private String spinfo=null;
  //Initialize global variables
  public void init() throws ServletException {
  }

  //Process the HTTP Get request
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    response.setContentType(CONTENT_TYPE);
    PrintWriter out = response.getWriter();
     spname=request.getParameter("spname");
     username=request.getParameter("username");
     userphone=request.getParameter("userphone");
     useremail=request.getParameter("useremail");
     clientphone=request.getParameter("clientphone");
     spinfo=request.getParameter("spinfo");
     if(0==spname.trim().length()){
       out.print("<script>alert('用户名不能为空！');history.back();</script>");
     }
    int sp_add=spadmin.insert(spname,username,userphone,useremail,clientphone,spinfo);
    if(1==sp_add){
       out.print("<script>alert('添加信息成功！');history.back();</script>");
    }

//    out.println("<html>");
//    out.println("<head><title>spadd</title></head>");
//    out.println("<body bgcolor=\"#ffffff\">");
//    out.println("<p>The servlet has received a " + request.getMethod() + ". This is the reply.</p>");
//    out.println("</body></html>");
  }

  //Process the HTTP Post request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    doGet(request, response);
  }

  //Clean up resources
  public void destroy() {
  }
}
