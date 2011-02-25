package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;

public class pageDao
    extends BaseDAO {
  //////显示页面列表
  public DBMap[] pageList(String idlist) {
  StringBuffer sql = new StringBuffer("select * from pageresource ");
  sql.append(" where kindid in (");
  sql.append(idlist);
  sql.append(")");
  return executeQuery(sql.toString());
  }
}
