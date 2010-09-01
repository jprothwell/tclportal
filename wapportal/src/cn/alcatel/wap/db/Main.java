package cn.alcatel.wap.db;

import java.io.IOException;
import java.util.ResourceBundle;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import cn.alcatel.wap.db.dao.ipgoDao;
import cn.alcatel.wap.db.dao.mobileDao;

/**
 * <p>Title: Easy Picture Download Service</p>
 * <p>Description: Service to download picures and sounds by WAP</p>
 * <p>Copyright: Copyright (c) tcl 2005</p>
 * <p>Company: tcl&Alcatel</p>
 * @author linfirst
 * @version 1.0
 */


 public class Main
    extends HttpServlet {

  private static String JspURL;
  private static String previewURL;
  private static String binaryURL;
  private static boolean DEBUG = false;
  private Messages messages = null;

  //private String did = null;

  public void init(ServletConfig config) throws ServletException {
    super.init(config);
    // create some properties and get the default Session
    this.load();
  }

//Process the HTTP Post request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws
      ServletException, IOException {
    this.doGet(request, response);
  }

  //Process the HTTP Get request
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws
      ServletException, IOException {
    //PrintWriter out = response.getWriter();
    String ua = Util.getBrowser(request);
    String id = request.getParameter("id");
    String language =Util.getLanguage(request);
    String groupid = request.getParameter("groupid");
    String group = request.getParameter("group");
    String action = request.getParameter("action");
    String did = request.getParameter("did");
    String number = request.getParameter("number");
    mobileDao mdao= new mobileDao();
    JspURL=mdao.indexUrl(ua);
    Messages messages = LoadMessages(language);
    if (messages == null) {
      messages = this.LoadMessages("en");
    }
    if (number == null) {
      number = "0";
    }
if(group!=null){
if(group.equals("images"))groupid="0";
if(group.equals("sounds"))groupid="1";
if(group.equals("videos"))groupid="2";
if(group.equals("java"))groupid="3";
}
//////////////
    ipgoDao ipdao = new ipgoDao();
/////////////印度尼西亚地区跳转
//    if(ipdao.judgeIndonesia(request)){
//          Stat.statIndex(request, "indonesia");
//          response.sendRedirect("http://wap.my-onetouch.com/venera.jsp");
//          return;
//    }
 ////////////////设置中国地区跳转
if(ipdao.judgeCountry(request)){
      Stat.statIndex(request, "cnwap");
      response.sendRedirect("http://cnwap.my-onetouch.com/?did="+did);
      return;
}else {

/////////////enter index
if (action == null) {
      request.setAttribute(Messages.Id, messages);
      request.setAttribute("groupid", groupid);
      request.setAttribute("lg", language);
      request.setAttribute("ua", ua);
      request.setAttribute("did", did);
      ////////首页统计
      Stat.statIndex(request, "index");
      //System.out.println("JspURL="+JspURL);
      this.getServletConfig().getServletContext().getRequestDispatcher(this.
          JspURL).forward(request, response);
    }
    else
    ///////////// enter menu
  if (action.compareTo("menu") == 0) {
      int id1 = 0;
      int group_id=Integer.parseInt(groupid);
      id1 = Integer.parseInt(id);
      JspURL=mdao.menuUrl(id1);
      ///////////////////////////////////
      request.setAttribute(Messages.Id, messages);
      request.setAttribute("groupid", groupid);
      request.setAttribute("lg", language);
      request.setAttribute("ua", ua);
      request.setAttribute("did", did);
      request.setAttribute("id", id);
      request.setAttribute("number", number);
     //////栏目统计
     String menuName=DBInfo.MENU_INFO[group_id];
     Stat.statIndex(request,menuName);
     //System.out.println("JspURL="+JspURL);
     this.getServletConfig().getServletContext().getRequestDispatcher(this.
          JspURL).forward(request, response);
    }
    else
    ///////////// enter download
   ///url {action groupid spname resourcename urlname}
  if (action.compareTo("download") == 0) {
     JspURL=request.getParameter("urlname");
     ////下载统计
     Stat.statDownload(request);
     response.sendRedirect(this.JspURL);
    }
    else
 ///////////// enter yewu
///url {action groupid spname resourcename urlname}
if (action.compareTo("yewu") == 0) {
        String fid = request.getParameter("fid");
        int group_id=Integer.parseInt(groupid);
        if(group_id==3)JspURL="/jsp/gameinfo.jsp";
        else JspURL="/jsp/newsinfo.jsp";
        ///////////////////////////////////
        request.setAttribute(Messages.Id, messages);
        request.setAttribute("groupid", groupid);
        request.setAttribute("lg", language);
        request.setAttribute("did", did);
        request.setAttribute("id", id);
        request.setAttribute("fid", fid);
        request.setAttribute("number", number);
        this.getServletConfig().getServletContext().getRequestDispatcher(this.
          JspURL).forward(request, response);

 }
}
      }
  public void load() {
    String DEBUG_TMP;
    //the parameters
    JspURL = getInitParameter("JspURL") == null ? "/jsp/" :
        getInitParameter("JspURL");
    binaryURL = getInitParameter("binaryURL") == null ?
        "http://localhost:8080/images/" :
        getInitParameter("binaryURL");
    previewURL = getInitParameter("previewURL") == null ?
        "http://localhost:8080/images/" :
        getInitParameter("previewURL");
  }

  public Messages LoadMessages(String language) {
    Messages messages = null;
    if (DEBUG) {
      System.out.println("Message language loaded : " + language);
    }
    try {
      ResourceBundle res = ResourceBundle.getBundle(
          "cn.alcatel.wap.db.Messages_" + language);
      messages = new Messages(res);
      if (DEBUG) {
        System.out.println("Message getBack : " + messages.getBack());
      }
    }
    catch (Exception e) {
     if (DEBUG) {
        e.printStackTrace();
      }
      messages = null;
    }
    return messages;
  }
  //Clean up resources
  public void destroy() {
  }
}
