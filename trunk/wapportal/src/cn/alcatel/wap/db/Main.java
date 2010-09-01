package cn.alcatel.wap.db;

import cn.alcatel.wap.db.dao.ipgoDao;
import cn.alcatel.wap.db.dao.mobileDao;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ResourceBundle;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Main extends HttpServlet
{
  private static boolean DEBUG = false;
  private static String JspURL;
  private static String binaryURL;
  private Messages messages;
  private static String previewURL;

  public Main()
  {
    this.messages = null;
  }

  public Messages LoadMessages(String language)
  {
    Messages messages = null;
    if (DEBUG)
      System.out.println("Message language loaded : " + language);
    try
    {
      ResourceBundle res = ResourceBundle.getBundle("cn.alcatel.wap.db.Messages_" + language);

      messages = new Messages(res);
      if (DEBUG)
        System.out.println("Message getBack : " + messages.getBack());
    }
    catch (Exception e)
    {
      if (DEBUG) {
        e.printStackTrace();
      }
      messages = null;
    }
    return messages;
  }

  public void destroy()
  {
  }

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException
  {
    String ua = Util.getBrowser(request);
    String id = request.getParameter("id");
    String language = Util.getLanguage(request);
    String groupid = request.getParameter("groupid");
    String group = request.getParameter("group");
    String action = request.getParameter("action");
    String did = request.getParameter("did");
    String number = request.getParameter("number");
    mobileDao mdao = new mobileDao();
    JspURL = mdao.indexUrl(ua);
    Messages messages = LoadMessages(language);
    if (messages == null) {
      messages = LoadMessages("en");
    }
    if (number == null) {
      number = "0";
    }
    if (group != null) {
      if (group.equals("images")) groupid = "0";
      if (group.equals("sounds")) groupid = "1";
      if (group.equals("videos")) groupid = "2";
      if (group.equals("java")) groupid = "3";
    }

    ipgoDao ipdao = new ipgoDao();

    if (ipdao.judgeCountry(request)) {
      Stat.statIndex(request, "cnwap");
      response.sendRedirect("http://wap.vcoon.cn/?did=" + did);
      return;
    }

    if (action == null) {
      request.setAttribute(Messages.Id, messages);
      request.setAttribute("groupid", groupid);
      request.setAttribute("lg", language);
      request.setAttribute("ua", ua);
      request.setAttribute("did", did);

      Stat.statIndex(request, "index");
      System.out.println("JspURL:::"+JspURL);
     // request.getRequestDispatcher("/jsp/homepage.jsp").forward(request, response);
      
     response.sendRedirect("jsp/homepage.jsp");
//      RequestDispatcher requestDispatcher = request.getRequestDispatcher(JspURL);
//      requestDispatcher.forward(request, response);
      
//      response.setContentType("text/html; charset=gb2312");
//
//      ServletContext sc = getServletContext();
//
//      RequestDispatcher rd = null;
//
//      rd = sc.getRequestDispatcher(JspURL); //定向的页面
//
//      rd.forward(request, response);
    }
    else
    {
      int id1;
      if (action.compareTo("menu") == 0) {
        id1 = 0;
        int group_id = Integer.parseInt(groupid);
        id1 = Integer.parseInt(id);
        JspURL = mdao.menuUrl(id1);

        request.setAttribute(Messages.Id, messages);
        request.setAttribute("groupid", groupid);
        request.setAttribute("lg", language);
        request.setAttribute("ua", ua);
        request.setAttribute("did", did);
        request.setAttribute("id", id);
        request.setAttribute("number", number);

        String menuName = DBInfo.MENU_INFO[group_id];
        Stat.statIndex(request, menuName);

        getServletConfig().getServletContext().getRequestDispatcher(JspURL).forward(request, response);
      }
      else if (action.compareTo("download") == 0) {
        JspURL = request.getParameter("urlname");

        Stat.statDownload(request);
        response.sendRedirect(JspURL);
      }
      else if (action.compareTo("yewu") == 0) {
        id1 = 0;
        String fid = request.getParameter("fid");
        int group_id = Integer.parseInt(groupid);
        id1 = Integer.parseInt(id);
        JspURL = mdao.menuUrl(id1);

        request.setAttribute(Messages.Id, messages);
        request.setAttribute("groupid", groupid);
        request.setAttribute("lg", language);
        request.setAttribute("did", did);
        request.setAttribute("id", id);
        request.setAttribute("fid", fid);
        request.setAttribute("number", number);
        getServletConfig().getServletContext().getRequestDispatcher(JspURL).forward(request, response);
      }
    }
  }

  public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException
  {
    doGet(request, response);
  }

  public void init(ServletConfig config)
    throws ServletException
  {
    super.init(config);

    load();
  }

  public void load()
  {
    JspURL = (getInitParameter("JspURL") == null) ? "/jsp/" : getInitParameter("JspURL");

    binaryURL = (getInitParameter("binaryURL") == null) ? "http://localhost:8080/images/" : getInitParameter("binaryURL");

    previewURL = (getInitParameter("previewURL") == null) ? "http://localhost:8080/images/" : getInitParameter("previewURL");
  }
}