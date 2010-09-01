package cn.funstar.wap.db.dao;

import cn.funstar.wap.db.BaseDAO;
import cn.funstar.wap.db.DBMap;

public class IPDA0
    extends BaseDAO {
  public IPDA0() {
  }

  public boolean isUnicom(String ip) {
   StringBuffer sql = new StringBuffer("select * from unicomip where '");
   sql.append(ip);
   sql.append("' like ip");
   DBMap[] tmpMap = executeQuery(sql.toString());
   if (tmpMap != null && tmpMap.length > 0) {
     return true;
   }
   return false;
 }

}
