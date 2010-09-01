/*
 * Created on 2006-5-30
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.action;

import javax.servlet.http.*;

import cn.funstar.wap.db.*;
import cn.funstar.wap.db.dao.*;
import cn.funstar.wap.util.*;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class listAction {
  private String did = null;
  private String channel = null;

  private DBMap[] list = null;
  private int page = 1;
  private int rows = Common.NUM_PAGEROWS;
  private boolean isFirst = false;
  private String prevUrl = null;
  private String nextUrl = null;
  private String backUrl = null;
  private String prefixUrl = null;
  private String channelName = null;
  private String icon = null;
  private int totalpage = 1;

  public listAction(HttpServletRequest req) {
    channel = req.getParameter("id");
    String pageStr = req.getParameter("p");
    if (pageStr == null) {
      isFirst = true;
    }
    else {
      try {
        page = Integer.parseInt(pageStr);
      }
      catch (Exception e) {
        page = 1;
      }
    }
    DBMap mobileMap = (DBMap) req.getSession().getAttribute("mobile");
    if (mobileMap == null) {
      mobileMap = cn.funstar.wap.util.MobileParse.getMobile(req);
    }
    //机型的状态 0研发状态 1上市 2下市
    String state = "0";
    if (mobileMap != null) {
      did = String.valueOf(mobileMap.get(DBInfo.MOBILE_DID));
      state = String.valueOf(mobileMap.get("state"));
      try {
        rows = Integer.parseInt(String.valueOf(mobileMap.get(DBInfo.MOBILE_ROWS)));
      }
      catch (Exception e) {
      }
    }
    if (did == null || did.equals("")) {
      did = "0";
    }
    String prefix = "?did=" + did;
    PageDAO dao = new PageDAO();
    DBMap map = dao.getChannel(channel);
    if (map != null) {
      channelName = map.get(DBInfo.CHANNEL_NAME).toString();
      icon = map.get(DBInfo.CHANNEL_ICON) != null ?
          map.get(DBInfo.CHANNEL_ICON).toString() : null;

      //栏目重定向
      String redirect = null;
      Object object = map.get(DBInfo.CHANNEL_REDIRECT);
      if (object != null) {
        redirect = object.toString();
      }
      //

      //未上市机型,应对QA测试
      if ("0".equals(state)) {
        if ("55".equals(channel)) {
          //彩图动画
          redirect = "80";
        }
        else if ("63".equals(channel)) {
          //图片下载
          redirect = "81";
        }
        else if ("65".equals(channel)||"68".equals(channel)) {
          //视频下载 视频社区
          redirect = "82";
        }
      }
      //



      if (redirect != null && !"0".equals(redirect)) {
        list = dao.getListByChannel(redirect, page, rows);
      }
      else {
        list = dao.getListByChannel(channel, page, rows);
      }
    }
    if (list != null) {
      totalpage = list.length % rows != 0 ? list.length / rows + 1 :
          list.length / rows;
      int currows = rows;
      if (page >= totalpage) {
        page = totalpage;
        currows = list.length - (page - 1) * rows;
      }
      else if (page < 1) {
        page = 1;
      }
      DBMap[] temp = new DBMap[currows];
      System.arraycopy(list, (page - 1) * rows, temp, 0, temp.length);
      list = temp;
      if (page > 1) {
        prevUrl = req.getRequestURI() + prefix + "&amp;id=" + channel +
            "&amp;p=" +
            (page - 1);
      }
      if (page < totalpage) {
        nextUrl = req.getRequestURI() + prefix + "&amp;id=" + channel +
            "&amp;p=" +
            (page + 1);
      }
      prefixUrl = req.getRequestURI() + prefix + "&amp;id=" + channel +
          "&amp;p=";
    }
  }

  public void log() {
    try {
      if (isFirst()) {
        LogAction.channelLog(channel, did);
      }
    }
    catch (Exception e) {
      System.out.println(" at channel Action log");
      e.printStackTrace();
    }
  }

  public String getDid() {
    return did;
  }

  public int getPage() {
    return page;
  }

  public int getRows() {
    return rows;
  }

  public boolean isFirst() {
    return isFirst;
  }

  public String getPrevUrl() {
    return prevUrl;
  }

  public String getNextUrl() {
    return nextUrl;
  }

  public String getPrefixUrl() {
    return prefixUrl;
  }

  public String getBackUrl() {
    return backUrl;
  }

  public DBMap[] getList() {
    return list;
  }

  public String getChannelName() {
    return channelName;
  }

  public String getIcon() {
    return icon;
  }

  public int getTotalpage() {
    return totalpage;
  }

  public String getChannel() {
    return channel;
  }
}
