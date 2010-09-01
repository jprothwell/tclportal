/*
 * Created on 2006-5-31
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.db.dao;

import cn.funstar.wap.db.*;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class LogDAO
    extends BaseDAO {
  public void insertAccessLog(String page, String mobile, String ip,
                              String language) {
    if (page == null) {
      page = "0";
    }
    if (mobile == null) {
      mobile = "0";
    }
    StringBuffer sql = new StringBuffer("insert into ");
    sql.append(DBInfo.TABLE_ACCESS_LOG);
    sql.append("(");
    sql.append(DBInfo.ACCESS_LOG_PAGE);
    sql.append(",");
    sql.append(DBInfo.ACCESS_LOG_MOBILE);
    sql.append(",");
    sql.append(DBInfo.ACCESS_LOG_IP);
    sql.append(",");
    sql.append(DBInfo.ACCESS_LOG_LANGUAGE);
    sql.append(",");
    sql.append(DBInfo.ACCESS_LOG_ACCESS_DATE);
    sql.append(") values(");
    sql.append(page);
    sql.append(",");
    sql.append(mobile);
    sql.append(",'");
    sql.append(ip);
    sql.append("','");
    sql.append(language);
    sql.append("',getdate())");
    executeUpdate(sql.toString());
  }

  public void insertChannelLog(String channel, String mobile) {
    if (mobile == null) {
      mobile = "0";
    }
    StringBuffer sql = new StringBuffer("insert into ");
    sql.append(DBInfo.TABLE_CHANNEL_LOG);
    sql.append("(");
    sql.append(DBInfo.CHANNEL_LOG_CHANNEL);
    sql.append(",");
    sql.append(DBInfo.CHANNEL_LOG_MOBILE);
    sql.append(",");
    sql.append(DBInfo.CHANNEL_LOG_ACCESS_DATE);
    sql.append(") values(");
    sql.append(channel);
    sql.append(",");
    sql.append(mobile);
    sql.append(",getdate())");
    //System.out.println("sql="+sql.toString());
    executeUpdate(sql.toString());
  }

  public void insertServiceLog(String service, String mobile,String url) {
    if (mobile == null) {
      mobile = "0";
    }
    StringBuffer sql = new StringBuffer("insert into ");
    sql.append(DBInfo.TABLE_SERVICE_LOG);
    sql.append("(");
    sql.append(DBInfo.SERVICE_LOG_SERVICE);
    sql.append(",");
    sql.append(DBInfo.SERVICE_LOG_MOBILE);
    sql.append(",");
    sql.append(DBInfo.SERVICE_URL);
    sql.append(",");
    sql.append(DBInfo.SERVICE_LOG_ACCESS_DATE);
    sql.append(") values(");
    sql.append(service);
    sql.append(",");
    sql.append(mobile);
    sql.append(",'");
    sql.append(url);
    sql.append("',getdate())");
    // System.out.println("sql="+sql.toString());
    executeUpdate(sql.toString());
  }
}
