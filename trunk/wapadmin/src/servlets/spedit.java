package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import cn.alcatel.wap.db.dao.spadmin;

public class spedit extends HttpServlet {
  private static final String CONTENT_TYPE = "text/html; charset=utf-8";

  //Initialize global variables
  public void init() throws ServletException {
  }

  //Process the HTTP Get request
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    response.setContentType(CONTENT_TYPE);
    PrintWriter out = response.getWriter();
    int id=Integer.parseInt(request.getParameter("spid"));
    String spname=request.getParameter("spname");
    String username=request.getParameter("username");
    String userphone=request.getParameter("userphone");
    String useremail=request.getParameter("useremail");
    String clientphone=request.getParameter("clientphone");
    String spinfo=request.getParameter("spinfo");
    int modify_status=spadmin.modify_sp(id,spname,username,userphone,useremail,clientphone,spinfo);
    if(1==modify_status){
      out.print("<script>alert('ÐÞ¸Ä³É¹¦£¡');history.back();</script>");
    }
//    out.println("<html>");
//    out.println("<head><title>spedit</title></head>");
//    out.println("<body bgcolor=\"#ffffff\">");
//    out.println("<p>The servlet has received a GET. This is the reply.</p>");
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
