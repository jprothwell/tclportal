package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;

public class mobileDao
    extends BaseDAO {
  //////��ʾ��Ŀ�б�
  public DBMap[] mobileList() {
  StringBuffer sql = new StringBuffer("select * from mobile order by id desc");
  return executeQuery(sql.toString());
  }
public DBMap[] mobileList(int e) {
StringBuffer sql = new StringBuffer("select * from mobile where image_size=");
sql.append(e);
sql.append(" order by id desc");
return executeQuery(sql.toString());
}
  ////////////////��ʾ������Ϣ
   public DBMap[] menuInfo(int e) {
 StringBuffer sql = new StringBuffer("select * ");
 sql.append(" from mobile ");
 sql.append(" where id= ");
 sql.append(e);
 return executeQuery(sql.toString());
 }

}
