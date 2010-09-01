package cn.alcatel.wap.db;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;
import cn.alcatel.wap.db.dao.ipgoDao;
import cn.alcatel.wap.db.Util;
import cn.alcatel.wap.db.*;

/**
 * <p>Title: Easy Picture Download Service</p>
 * <p>Description: Service to download picures and sounds by WAP</p>
 * <p>Copyright: Copyright (c) tcl 2005</p>
 * <p>Company: tcl&Alcatel</p>
 * @author linfirst
 * @version 1.0
 */

/*public class Main
    extends HttpServlet {

  private static String JspURL;
  private static String previewURL;
  private static String binaryURL;
  private static boolean DEBUG = false;

//  private Configuration configuration = null;
//  private Messages messages = null;
//  private Categories categories = null;
//  private DwObjects dwObjects = null;
  private String allowedBrowser = null;

  //private String did = null;

  public void init(ServletConfig config) throws ServletException {
    super.init(config);
    // create some properties and get the default Session
    this.load();
  }

//Process the HTTP Post request
//  public void doPost(HttpServletRequest request, HttpServletResponse response) throws
//      ServletException, IOException {
//    this.doGet(request, response);
//  }

  //Process the HTTP Get request
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws
      ServletException, IOException {
    //PrintWriter out = response.getWriter();
    String ua = Util.getBrowser(request);
    String did = request.getParameter("did");

    if (DEBUG) {
      System.out.println("Browser : " + ua);
      System.out.println("Browser language : " + this.getLanguage(request, null));
      System.out.println("Force language : " + request.getParameter("lg"));
      System.out.println("Action : " + request.getParameter("action"));
      System.out.println("Result language : " +
                         this.getLanguage(request, request.getParameter("lg")));
    }
ipgoDao ipdao = new ipgoDao();
 ////////////////设置中国地区跳转
if(ipdao.judgeCountry(request)){
      Stat.statIndex(request, "cnwap");
      response.sendRedirect("http://cnwap.my-onetouch.com/?did="+did);
      return;
}else {
///////////设置中国地区跳转结束
///////////判断是否是c7系列
if(Util.judgeUA(request)){
      String ipUrl = ipdao.getipUrl(request);
      if (ipUrl != null && ipUrl.length() > 0) {
        Stat.statIndex(request, ipUrl);
        response.sendRedirect("newportal/" + ipUrl + "?did=" + did);
        return;
      }else {
       Stat.statIndex(request,"en/index.jsp");
       response.sendRedirect("newportal/en/?did=" + did);
       return;
      }
    }
    //////开始计数
    Stat.statIndex(request, "index");
    // filter browser
    if (this.filterBrowser(ua) == false) {
      //开始计数
      Stat.statIndex(request, "en/index.jsp");
      response.sendRedirect("newportal/en/index1.jsp");
      return;
    }

    String action = request.getParameter("action");
    String language = request.getParameter("lg");

    // Starting point
    language = this.getLanguage(request, language);

    Configuration configuration = LoadConfiguration(ua);
    if (configuration == null) {
      ua = "Alcatel-OT-C551";
      configuration = LoadConfiguration(ua);
    }

    Categories categories = LoadCategories(language, ua);
    if (categories == null) {
      categories = LoadCategories("en", ua);
    }

    Messages messages = LoadMessages(language);
    if (messages == null) {
      messages = this.LoadMessages("en");
    }
    //System.out.println("messages="+messages);
    if (action == null) {
      String group = request.getParameter("group");
      if (DEBUG) {
        System.out.println("group : " + group);
        System.out.println("Go to: " + configuration.getHomePageJSP());
      }
      request.setAttribute(Messages.Id, messages);
      request.setAttribute(Categories.Id, categories);
      request.setAttribute("group", group);
      request.setAttribute("error", null);
      //request.setAttribute("did", did);
      request.setAttribute("lg", language);
      request.setAttribute("browserlg", this.getLanguage(request, null));
      //如果是中文，进入登录页面
      if (language.compareTo("zh") == 0) {
        request.setAttribute("previewURL", this.previewURL);
        this.getServletConfig().getServletContext().getRequestDispatcher(this.
              + configuration.getLogoPageJSP()).forward(request, response);
      }
      else {
        this.getServletConfig().getServletContext().getRequestDispatcher(this.
            JspURL + configuration.getHomePageJSP()).forward(request, response);
      }
    }
    else

    // Category selection into group or not
    if (action.compareTo("categories") == 0) {
      String group = request.getParameter("group");
      if (DEBUG) {
        System.out.println("group : " + group);
        System.out.println("Number of categories: " + categories.length());
        System.out.println("Go to: " + configuration.getListCategoriesJSP());
      }
      request.setAttribute(Messages.Id, messages);
      request.setAttribute(Categories.Id, categories);
      request.setAttribute("group", group);
      request.setAttribute("lg", language);
      request.setAttribute("browserlg", this.getLanguage(request, null));
      this.getServletConfig().getServletContext().getRequestDispatcher(this.
          JspURL + configuration.getListCategoriesJSP()).forward(request,
          response);

    }
    else

    // Browsing image into category
    if (action.compareTo("browse") == 0) {
      String category = request.getParameter("category");
      String number = request.getParameter("number");
      String group = request.getParameter("group");
      if (DEBUG) {
        System.out.println("category : " + category);
        System.out.println("Go to: " + configuration.getListDwObjectsJSP());
      }

      DwObjects dwObjects = LoadObjects(language, ua, category);
      if (dwObjects == null) {
        dwObjects = LoadObjects("en", ua, category);
      }

      if (DEBUG) {
        if (dwObjects != null) {
          System.out.println("Number of objects: " + dwObjects.length());
        }
        else {
          System.out.println("Number of objects: null");
        }
        System.out.println("Go to: " + configuration.getListDwObjectsJSP());
      }
      request.setAttribute(Configuration.Id, configuration);
      request.setAttribute(Messages.Id, messages);
      request.setAttribute(Categories.Id, categories);
      request.setAttribute(DwObjects.Id, dwObjects);
      request.setAttribute("previewURL", this.previewURL);
      request.setAttribute("binaryURL", this.binaryURL);
      request.setAttribute("number", number);
      request.setAttribute("category", category);
      request.setAttribute("group", group);
      request.setAttribute("lg", language);
      request.setAttribute("browserlg", this.getLanguage(request, null));
      this.getServletConfig().getServletContext().getRequestDispatcher(this.
          JspURL + configuration.getListDwObjectsJSP()).forward(request,
          response);

    }
    else

    // Download when we have the exact reference
    if (action.compareTo("download") == 0) {
      String code = null;
      String group = null;
      try {
        code = request.getParameter("code");
        group = request.getParameter("group");
      }
      catch (Exception e) {}
      if (DEBUG) {
        System.out.println("code : " + code);
      }
      if (code != null) {
        DwObjects dwObjects = null;
        int number = Download(ua, categories, dwObjects, code, language);
        request.setAttribute(Configuration.Id, configuration);
        request.setAttribute(Messages.Id, messages);
        request.setAttribute(Categories.Id, categories);
        request.setAttribute(DwObjects.Id, dwObjects);
        request.setAttribute("previewURL", this.previewURL);
        request.setAttribute("binaryURL", this.binaryURL);
        request.setAttribute("number", new Integer(number));
        request.setAttribute("group", group);
        request.setAttribute("lg", language);
        request.setAttribute("browserlg", this.getLanguage(request, null));
        this.getServletConfig().getServletContext().getRequestDispatcher(this.
            JspURL + configuration.getDownloadJSP()).forward(request, response);
      }
      else
      // The code doesn't exist in the URL.
      {
        request.setAttribute(Messages.Id, messages);
        request.setAttribute(Categories.Id, categories);
        request.setAttribute("group", group);
        request.setAttribute("error", messages.getEPicNotFound());
        request.setAttribute("lg", language);
        request.setAttribute("browserlg", this.getLanguage(request, null));
        this.getServletConfig().getServletContext().getRequestDispatcher(this.
            JspURL + configuration.getHomePageJSP()).forward(request, response);
      }
    }
    else

    // Logo
    if (action.compareTo("logo") == 0) {
      String group = request.getParameter("group");
      if (DEBUG) {
        System.out.println("group : " + group);
        System.out.println("Number of categories: " + categories.length());
        System.out.println("Go to: " + configuration.getLogoPageJSP());
      }
      request.setAttribute(Messages.Id, messages);
      request.setAttribute(Categories.Id, categories);
      request.setAttribute("group", group);
      request.setAttribute("previewURL", this.previewURL);
      request.setAttribute("lg", language);
      request.setAttribute("browserlg", this.getLanguage(request, null));
      this.getServletConfig().getServletContext().getRequestDispatcher(this.
          JspURL + configuration.getLogoPageJSP()).forward(request, response);
    }
  }
      }
  public int Download(String ua, Categories categories, DwObjects dwObjects,
                      String code,
                      String language) {
    if (categories != null) {
      //DwObjects dwObjects = null;
      for (int i = 0; i < categories.length(); i++) {
        dwObjects = LoadObjects(language, ua, categories.getKey(i));
        if (dwObjects == null) {
          dwObjects = LoadObjects("en", ua, categories.getKey(i));
        }
        if (dwObjects != null) {
          for (int j = 0; j < dwObjects.length(); j++) {
            if (code.compareTo(dwObjects.getKey(j)) == 0) {
              return j;
            }
          }
        }
      }
    }
    return -1;
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
    allowedBrowser = getInitParameter("allowedBrowser") == null ?
        "Alcatel-BF4, Alcatel-BF5" :
        getInitParameter("allowedBrowser");
    DEBUG_TMP = getInitParameter("DEBUG") == null ? "false" :
        getInitParameter("DEBUG");
    if (DEBUG_TMP != null) {
      DEBUG = new Boolean(DEBUG_TMP).booleanValue();
    }
    else {
      DEBUG = false;
    }
  }

  public String getLanguage(HttpServletRequest request, String language) {
    if (language == null || language.length() == 0) {
      return Util.getAcceptLanguage(request);
    }
    else {
      return language;
    }
  }

  public boolean filterBrowser(String browser) {
    StringTokenizer lineToken = new StringTokenizer(
        allowedBrowser, ",");
    while (lineToken.hasMoreElements()) {
      if (browser.compareTo(lineToken.nextElement()) == 0) {
        return true;
      }
    }
    return false;
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

  public Configuration LoadConfiguration(String browser) {
    Configuration configuration = null;
    try {
      ResourceBundle res = ResourceBundle.getBundle(
          "com.alcatel.hq.easymobiledownloadservice.Configuration_" + browser);
      configuration = new Configuration(res);
    }
    catch (Exception e) {
      if (DEBUG) {
        e.printStackTrace();
      }
      configuration = null;
    }
    return configuration;
  }

  public Categories LoadCategories(String language, String browser) {
    Categories categories = null;
    try {
      ResourceBundle res = ResourceBundle.getBundle(
          "com.alcatel.hq.easymobiledownloadservice.Categories_" + language +
          "_" + browser);
      categories = new Categories(res);
    }
    catch (Exception e) {
      if (DEBUG) {
        e.printStackTrace();
      }
      categories = null;
    }
    return categories;
  }

  public Categories LoadCategories(String language, String browser,
                                   String group) {
    Categories categories = null;
    try {
      ResourceBundle res = ResourceBundle.getBundle(
          "com.alcatel.hq.easymobiledownloadservice.Categories_" + language +
          "_" + browser);
      categories = new Categories(res);
    }
    catch (Exception e) {
      if (DEBUG) {
        e.printStackTrace();
      }
      categories = null;
    }
    return categories;
  }

  public DwObjects LoadObjects(String language, String browser, String category) {
    DwObjects dwObjects = null;
    ResourceBundle res;
    if (category != null) {
      try {
        res = ResourceBundle.getBundle(
            "com.alcatel.hq.easymobiledownloadservice.Objects_" + language +
            "_" + browser + "_" + category);
        dwObjects = new DwObjects(res);
      }
      catch (Exception e) {
        if (DEBUG) {
          e.printStackTrace();
        }
        dwObjects = null;
      }
    }
    return dwObjects;
  }
  //Clean up resources
  public void destroy() {
  }
}
*/
