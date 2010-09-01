package cn.alcatel.wap.db.dao;

import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.List;
import java.util.ArrayList;
import java.util.Date;
//import cn.alcatel.wap.db.bean.MenuBean;

public class menuDao
    extends BaseDAO {
  public menuDao() {
  }
  /////////////////栏目统计
    public DBMap[] statMenu(String a) {
  StringBuffer sql = new StringBuffer("select menuname, ");
  sql.append(" count(*) as menunum ");
  sql.append(" from ");
  sql.append(a);
  sql.append(" group by menuname ");
  sql.append(" order by menunum desc");
  return executeQuery(sql.toString());
 }
 /////////////////UA统计
  public  DBMap[] statUa(String a) {
    StringBuffer sql = new StringBuffer("select statua, ");
  sql.append(" count(*) as uanum ");
  sql.append(" from ");
  sql.append(a);
  sql.append(" group by statua ");
  sql.append(" order by uanum desc");
  return executeQuery(sql.toString());
  }
  /////////////////机型明细统计
 public  DBMap[] uaMenu(String a) {
   StringBuffer sql = new StringBuffer("select statua,menuname, ");
 sql.append(" count(*) as uanum ");
 sql.append(" from ");
 sql.append(a);
 sql.append(" group by statua ");
 sql.append(" order by uanum desc");
 return executeQuery(sql.toString());
 }
///////////////////////

}
