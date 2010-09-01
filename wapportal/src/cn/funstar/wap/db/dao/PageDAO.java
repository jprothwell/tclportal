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
public class PageDAO
    extends BaseDAO {
  public DBMap getMobileByDid(String did) {
    StringBuffer sql = new StringBuffer("select a.*, b.");
    sql.append(DBInfo.PAGEINFO_FILENAME);
    sql.append(" as ");
    sql.append(DBInfo.F_MOBILE_PAGE);
    sql.append(" from ");
    sql.append(DBInfo.TABLE_MOBILE);
    sql.append(" a left join ");
    sql.append(DBInfo.TABLE_PAGEINFO);
    sql.append(" b on a.");
    sql.append(DBInfo.MOBILE_PAGE);
    sql.append("=b.");
    sql.append(DBInfo.COMMON_ID);
    sql.append(" where a.");
    sql.append(DBInfo.MOBILE_DID);
    sql.append("='");
    sql.append(did);
    sql.append("'");
    DBMap[] tmpMap = executeQuery(sql.toString());
    if (tmpMap != null && tmpMap.length > 0) {
      return tmpMap[0];
    }
    return null;
  }

  public DBMap getMobileByUA(String ua) {
    StringBuffer sql = new StringBuffer("select a.*, b.");
    sql.append(DBInfo.PAGEINFO_FILENAME);
    sql.append(" as ");
    sql.append(DBInfo.F_MOBILE_PAGE);
    sql.append(" from ");
    sql.append(DBInfo.TABLE_MOBILE);
    sql.append(" a left join ");
    sql.append(DBInfo.TABLE_PAGEINFO);
    sql.append(" b on a.");
    sql.append(DBInfo.MOBILE_PAGE);
    sql.append("=b.");
    sql.append(DBInfo.COMMON_ID);
    sql.append(" where a.");
    sql.append(DBInfo.MOBILE_UA);
    sql.append(" like '");
    sql.append(ua);
    sql.append("%'");
    DBMap[] tmpMap = executeQuery(sql.toString());
    if (tmpMap != null && tmpMap.length > 0) {
      return tmpMap[0];
    }
    return null;
  }

  public DBMap getPageByDidLanguage(String did, String language) {
    StringBuffer sql = new StringBuffer("select b.*, a.");
    sql.append(DBInfo.DIDPAGE_DID);
    sql.append(" from ");
    sql.append(DBInfo.TABLE_DIDPAGE);
    sql.append(" a left join ");
    sql.append(DBInfo.TABLE_PAGEINFO);
    sql.append(" b on a.");
    sql.append(DBInfo.DIDPAGE_PAGE);
    sql.append("=b.");
    sql.append(DBInfo.COMMON_ID);
    sql.append(" where a.");
    sql.append(DBInfo.MOBILE_DID);
    sql.append("='");
    sql.append(did);
    sql.append("' and b.");
    sql.append(DBInfo.PAGEINFO_LANGUAGE);
    sql.append("='");
    sql.append(language);
    sql.append("'");
    DBMap[] tmpMap = executeQuery(sql.toString());
    if (tmpMap != null && tmpMap.length > 0) {
      return tmpMap[0];
    }
    return null;
  }

//  public DBMap[] getListByChannel(String channel, int start, int count) {
//    int total = getListCountByChannel(channel);
//    if (total < (start + count)) {
//      count = total - start;
//    }
//    StringBuffer sql = new StringBuffer("select a.* from (select top ");
//    sql.append(count);
//    sql.append(" b.* from (select top ");
//    sql.append(start + count);
//    sql.append(" c.* from (select ");
//    sql.append(DBInfo.CHANNEL_CID).append(" as ").append(DBInfo.COMMON_ID);
//    sql.append(",");
//    sql.append(DBInfo.CHANNEL_NAME);
//    sql.append(",");
//    sql.append(DBInfo.CHANNEL_ORDER_SHOW);
//    sql.append(",'0' as ");
//    sql.append(DBInfo.COMMON_IS_SERVICE);
//    sql.append(" from ");
//    sql.append(DBInfo.TABLE_CHANNEL);
//    sql.append(" where ");
//    sql.append(DBInfo.CHANNEL_PARENT);
//    sql.append("=");
//    sql.append(channel);
//    sql.append(" and ");
//    sql.append(DBInfo.CHANNEL_ISCOMMON);
//    sql.append("='1' union select ");
//    sql.append(DBInfo.SERVICE_SID).append(" as ").append(DBInfo.COMMON_ID);
//    sql.append(",");
//    sql.append(DBInfo.SERVICE_NAME).append(" as ").append(DBInfo.CHANNEL_NAME);
//    sql.append(",");
//    sql.append(DBInfo.SERVICE_ORDER_SHOW).append(" as ").append(DBInfo.
//        CHANNEL_ORDER_SHOW);
//    sql.append(",'1' as ");
//    sql.append(DBInfo.COMMON_IS_SERVICE);
//    sql.append(" from ");
//    sql.append(DBInfo.TABLE_SERVICE);
//    sql.append(" where ");
//    sql.append(DBInfo.SERVICE_CHANNEL);
//    sql.append("=");
//    sql.append(channel);
//    sql.append(" and ");
//    sql.append(DBInfo.SERVICE_ISCOMMON);
//    sql.append("='1') c order by c.");
//    sql.append(DBInfo.CHANNEL_ORDER_SHOW);
//    sql.append(") b order by b.");
//    sql.append(DBInfo.CHANNEL_ORDER_SHOW);
//    sql.append(" desc) a order by a.");
//    sql.append(DBInfo.CHANNEL_ORDER_SHOW);
//    System.out.println(sql.toString());
//    return executeQuery(sql.toString());
//  }
  public DBMap[] getListByChannel(String channel, int page, int numperpage) {
//     int total = getListCountByChannel(channel);
//     if (total < (start + count)) {
//       count = total - start;
//     }
   StringBuffer sql = new StringBuffer("select ");
//     sql.append(count);
//     sql.append(" b.* from (select top ");
//     sql.append(start + count);
   sql.append(" c.* from (select ");
   sql.append(DBInfo.CHANNEL_CID).append(" as ").append(DBInfo.COMMON_ID);
   sql.append(",");
   sql.append(DBInfo.CHANNEL_NAME);
   sql.append(",");
   sql.append(DBInfo.CHANNEL_ICON);
   sql.append(",");
   sql.append(DBInfo.CHANNEL_ORDER_SHOW);
   sql.append(",");
   sql.append(DBInfo.CHANNEL_ORDER_BASE);
   sql.append(",'0' as ");
   sql.append(DBInfo.COMMON_IS_SERVICE);
   sql.append(",'null' as url ");
   sql.append(",'null' as ");
   sql.append(DBInfo.SERVICE_MEMO);
   sql.append(" from ");
   sql.append(DBInfo.TABLE_CHANNEL);
   sql.append(" where ");
   sql.append(DBInfo.CHANNEL_PARENT);
   sql.append("=");
   sql.append(channel);
   sql.append(" and ");
   sql.append(DBInfo.CHANNEL_ISCOMMON);
   sql.append("='1' union select ");
   sql.append(DBInfo.SERVICE_SID).append(" as ").append(DBInfo.COMMON_ID);
   sql.append(",");
   sql.append(DBInfo.SERVICE_NAME).append(" as ").append(DBInfo.CHANNEL_NAME);
   sql.append(",");
   sql.append(DBInfo.SERVICE_ICON).append(" as ").append(DBInfo.CHANNEL_ICON);
   sql.append(",");
   sql.append(DBInfo.SERVICE_ORDER_SHOW).append(" as ").append(DBInfo.
       CHANNEL_ORDER_SHOW);
   sql.append(",");
   sql.append(DBInfo.SERVICE_ORDER_BASE).append(" as ").append(DBInfo.
       CHANNEL_ORDER_BASE);
   sql.append(",'1' as ");
   sql.append(DBInfo.COMMON_IS_SERVICE);
   sql.append(",");
   sql.append(DBInfo.SERVICE_URL);
   sql.append(" as url,");
   sql.append(DBInfo.SERVICE_MEMO);
   sql.append(" from ");
   sql.append(DBInfo.TABLE_SERVICE);
   sql.append(" where ");
   sql.append(DBInfo.SERVICE_CHANNEL);
   sql.append("=");
   sql.append(channel);
   sql.append(" and ");
   sql.append(DBInfo.SERVICE_ISCOMMON);
   sql.append("='1') c order by c.");
   sql.append(DBInfo.CHANNEL_ORDER_BASE);
//     sql.append(") b order by b.");
//     sql.append(DBInfo.CHANNEL_ORDER_SHOW);
//     sql.append(" desc) a order by a.");
//     sql.append(DBInfo.CHANNEL_ORDER_SHOW);
//     System.out.println(sql.toString());
   return executeQuery(sql.toString());
 }


  private int getListCountByChannel(String channel) {
    StringBuffer sql = new StringBuffer(
        "select count(*) as count from (select ");
    sql.append(DBInfo.COMMON_ID);
    sql.append(" from ");
    sql.append(DBInfo.TABLE_CHANNEL);
    sql.append(" where ");
    sql.append(DBInfo.CHANNEL_PARENT);
    sql.append("=");
    sql.append(channel);
    sql.append(" and ");
    sql.append(DBInfo.CHANNEL_ISCOMMON);
    sql.append("='1' union select ");
    sql.append(DBInfo.COMMON_ID);
    sql.append(" from ");
    sql.append(DBInfo.TABLE_SERVICE);
    sql.append(" where ");
    sql.append(DBInfo.SERVICE_CHANNEL);
    sql.append("=");
    sql.append(channel);
    sql.append(" and ");
    sql.append(DBInfo.SERVICE_ISCOMMON);
    sql.append("='1') a");
    //System.out.println(sql.toString());
    DBMap[] tmp = executeQuery(sql.toString());
    if (tmp != null && tmp.length > 0) {
      try {
        return Integer.parseInt(String.valueOf(tmp[0].get("count")));
      }
      catch (Exception e) {
        e.printStackTrace();
      }
    }
    return 0;
  }

  public DBMap getServiceBySid(String sid) {
    StringBuffer sql = new StringBuffer("select * from ");
    sql.append(DBInfo.TABLE_SERVICE);
    sql.append(" where ");
    sql.append(DBInfo.SERVICE_SID);
    sql.append("=");
    sql.append(sid);
    DBMap[] tmpMap = executeQuery(sql.toString());
    if (tmpMap != null && tmpMap.length > 0) {
      return tmpMap[0];
    }
    return null;
  }

  public String getDefaultIndex() {
    StringBuffer sql = new StringBuffer("select top 1");
    sql.append(DBInfo.COMMON_ID);
    sql.append(" from ");
    sql.append(DBInfo.TABLE_PAGEINFO);
    sql.append(" where ");
    sql.append(DBInfo.PAGEINFO_ISDEFAULT);
    sql.append("='1'");
    DBMap[] tmpMap = executeQuery(sql.toString());
    if (tmpMap != null && tmpMap.length > 0) {
      return String.valueOf(tmpMap[0].get(DBInfo.COMMON_ID));
    }
    return null;
  }

  public DBMap getDefaultPage(String language) {
    StringBuffer sql = new StringBuffer("select top 1 * from ");
    sql.append(DBInfo.TABLE_PAGEINFO);
    sql.append(" where ");
    sql.append(DBInfo.PAGEINFO_ISDEFAULT);
    sql.append("='1' and ");
    sql.append(DBInfo.PAGEINFO_LANGUAGE);
    sql.append("='");
    sql.append(language);
    sql.append("'");
    DBMap[] tmpMap = executeQuery(sql.toString());
    if (tmpMap != null && tmpMap.length > 0) {
      return tmpMap[0];
    }
    return null;
  }

  public DBMap getChannel(String key) {
    StringBuffer sql = new StringBuffer("select * from ");
    sql.append(DBInfo.TABLE_CHANNEL);
    sql.append(" where ");
    sql.append(DBInfo.COMMON_ID);
    sql.append("=");
    sql.append(key);
    DBMap[] map = executeQuery(sql.toString());
    if (map != null && map.length == 1) {
      return map[0];
    }
    else {
      return null;
    }
  }

}
