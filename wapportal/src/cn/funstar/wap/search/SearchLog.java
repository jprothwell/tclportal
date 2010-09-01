package cn.funstar.wap.search;

import cn.funstar.wap.db.BaseDAO;

public class SearchLog
    extends BaseDAO {
  public SearchLog() {
  }

  public void log(String key, String type, String did, String url) {
    StringBuffer sql = new StringBuffer(
        "insert into searchlog (skey,type,did,url) values('");
    sql.append(key);
    sql.append("','");
    sql.append(type);
    sql.append("','");
    sql.append(did);
    sql.append("','");
    sql.append(url);
    sql.append("')");
    executeUpdate(sql.toString());
  }
}
