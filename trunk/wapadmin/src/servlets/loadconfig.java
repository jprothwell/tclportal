package servlets;

import javax.servlet.*;
import javax.servlet.http.*;
import cn.alcatel.wap.db.dao.Configuration;

public class loadconfig extends HttpServlet {
//Initialize global variables
  public void init() throws ServletException {
    Configuration.getValue();
  }
//Clean up resources
  public void destroy() {
  }
}
