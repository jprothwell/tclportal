/*
 * Created on 2006-5-16
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.db;

import java.sql.*;
import java.util.ArrayList;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to Window -
 * Preferences - Java - Code Style - Code Templates
 */
public class BaseDAO {
  protected DBMap[] executeQuery(String sql) {
    try {
      Connection conn = DBPool.getConnection();
      Statement stmt = null;
      ResultSet rs = null;
      try {
        stmt = conn.createStatement();
        rs = stmt.executeQuery(sql);

        ResultSetMetaData rsmd = rs.getMetaData();
        int columCount = rsmd.getColumnCount();

        ArrayList list = new ArrayList();
        while (rs.next()) {
          DBMap tmpMap = new DBMap();
          for (int i = 1; i <= columCount; i++) {
            if (rsmd.getColumnTypeName(i).equalsIgnoreCase(
                "datetime")) {
              /* 日期字段特殊处理 */
              String tmpStr = String.valueOf(rs.getObject(i));
              try {
                tmpMap.put(rsmd.getColumnName(i), tmpStr
                           .substring(0, 19));
              }
              catch (Exception e) {
              }
            }
            else {
              tmpMap.put(rsmd.getColumnName(i), rs
                         .getObject(i));
            }
          }
          list.add(tmpMap);
        }
        DBMap[] map = null;
        if (list.size() > 0) {
          map = new DBMap[list.size()];
          map = (DBMap[]) list.toArray(map);
        }
        return map;
      }
      catch (Exception e) {
        throw e;
      }
      finally {
        DBRelease.release(rs);
        DBRelease.release(stmt);
        DBRelease.release(conn);
      }
    }
    catch (Exception e) {
      e.printStackTrace();
      return null;
    }
  }


  protected int executeUpdate(String sql) {
    try {
      Connection conn = DBPool.getConnection();
      Statement stmt = null;
      try {
        stmt = conn.createStatement();
        return stmt.executeUpdate(sql);
      }
      catch (Exception e) {
        throw e;
      }
      finally {
        DBRelease.release(stmt);
        DBRelease.release(conn);
      }
    }
    catch (Exception e) {
      e.printStackTrace();
      return -1;
    }
  }
}
