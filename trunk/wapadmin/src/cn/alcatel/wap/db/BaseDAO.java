/*
 * Created on 2009-7-16
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.alcatel.wap.db;
import cn.alcatel.wap.db.DBPool;

import java.sql.*;
import java.util.ArrayList;

/**
 * @author gonglin.shi
 *
 * TODO To change the template for this generated type comment go to Window -
 * Preferences - Java - Code Style - Code Templates
 */
public class BaseDAO {
  private String _table = null;

  public BaseDAO() {
  }

  public BaseDAO(String table) {
    this._table = table;
  }

  protected String getTable() {
    return this._table;
  }

  public DBMap[] getAll() {
    StringBuffer sql = new StringBuffer("select * from ");
    sql.append(this._table);
    return executeQuery(sql.toString());
  }

//  public DBMap[] getAll(int start, int count) {
 //   System.out.println("BaseDAO The value of start is:" + start);
//    System.out.println("BaseDAO The value of count is:" + count);
//    StringBuffer sql = new StringBuffer("select top ");
//    sql.append(count);
//    sql.append(" * from ");
//    sql.append(this._table);
//    sql.append(" where ");
//    sql.append(DBInfo.COMMON_ID);
//    sql.append(" not in (select top ");
//    sql.append(start);
//    sql.append(" ");
//    sql.append(DBInfo.COMMON_ID);
//    sql.append(" from ");
//    sql.append(this._table);
//    sql.append(") ");
//    return executeQuery(sql.toString());
//  }

  public int getAllCount() {
    int count = 0;
    StringBuffer sql = new StringBuffer("select count(*) as count from ");
    sql.append(this._table);
    DBMap[] map = executeQuery(sql.toString());
    if (map != null) {
      count = Integer.parseInt(String.valueOf(map[0].get("count")));
    }
    return count;
  }

//  public DBMap getByKey(String key) {
//    StringBuffer sql = new StringBuffer("select * from ");
//    sql.append(getTable());
//    sql.append(" where ");
//    sql.append(DBInfo.COMMON_ID);
//    sql.append("=");
//    sql.append(key);
//    DBMap[] map = executeQuery(sql.toString());
//    if (map != null && map.length == 1) {
//      return map[0];
//    }
//    else {
//      return null;
//    }
//  }
//
//  public int delByKey(String key) {
//    StringBuffer sql = new StringBuffer("delete from ");
//    sql.append(getTable());
//    sql.append(" where ");
//    sql.append(DBInfo.COMMON_ID);
//    sql.append("=");
//    sql.append(key);
//    return executeUpdate(sql.toString());
//  }

  public int insert(DBMap map) {
    return 0;
  }

  public int update(DBMap map) {
    return 0;
  }

  protected static DBMap[] executeQuery(String sql) {
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
      System.err.println(e);
      return null;
    }
  }

  protected  static int executeUpdate(String sql) {
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
      System.err.println(e);
      return -1;
    }
  }

  protected Connection getConnection() {
    try {
      return DBPool.getConnection();
    }
    catch (Exception e) {
      System.err.println(e);
      return null;
    }
  }

  protected void release(Connection conn) {
    DBRelease.release(conn);
  }

  protected void release(PreparedStatement pstmt) {
    DBRelease.release(pstmt);
  }

  protected void debug(String message) {
   // System.out.println("message =" + message);
  }
}
