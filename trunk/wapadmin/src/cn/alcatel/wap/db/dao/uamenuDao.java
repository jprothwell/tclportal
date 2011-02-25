package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;

public class uamenuDao
    extends BaseDAO {
  ////////////////�����¼
public int insertUamenu(String ua,String lg,int menuid) {
  StringBuffer sql = new StringBuffer("insert into ");
   sql.append(" uamenu ");
   sql.append(" (ua,lg,menuid) values('"+ua+"','"+lg+"','"+menuid+"')");
   //System.out.println("sql="+sql.toString());
   return executeUpdate(sql.toString());
}
///////ɾ����¼
 public int delUamenu(int id) {
  StringBuffer sql = new StringBuffer("delete  from uamenu ");
  sql.append(" where id="+id);
  //System.out.println(sql.toString());
 return executeUpdate(sql.toString());
}
  ///////�����ȵ��޸�
 public int updateUamenu(int id,int rel) {
   StringBuffer sql = new StringBuffer("update uamenu set new_r=");
    sql.append(rel);
    sql.append("  where id="+id);

  //System.out.println(sql.toString());
 return executeUpdate(sql.toString());
}

  ///////����ɾ����Ŀ��¼
  public int delUamenu(String idlist) {
   StringBuffer sql = new StringBuffer("delete  from uamenu ");
   sql.append(" where id in (");
   sql.append(idlist);
   sql.append(")");
   //System.out.println(sql.toString());
  return executeUpdate(sql.toString());
 }
 ///�����Ŀ�Ƿ����
  public boolean checkUamenu(String ua,String lg,int menuid) {
    String checksql = "select * from uamenu where lg='" + lg + "' and ua='"+ua+"' and menuid="+menuid;
    //System.out.print("sql="+checksql);
    DBMap[] map = executeQuery(checksql);
    if (map!=null && map.length > 0) {
      return true;
    }
    else {
      return false;
    }
  }

//////��ʾ��Ŀ�б�
 public DBMap[] uamenuList(String lg,String ua) {
 StringBuffer sql = new StringBuffer("select uamenu.id,uamenu.menuid,uamenu.lg,uamenu.ua,name,groupid,info,contentid,rel,new_r from uamenu,menu where uamenu.menuid=menu.id and uamenu.lg='");
 sql.append(lg);
 sql.append("' and ua='");
 sql.append(ua);
 sql.append("' order by orderid,id");
 //System.out.println("sql="+sql.toString());
 return executeQuery(sql.toString());
 }
////////////�޸���Ŀ��Ϣ
  public int editOrder(int id,int num1) {
    StringBuffer sql = new StringBuffer("update uamenu set orderid=");
    sql.append(num1);
    sql.append("  where id="+id);
   return executeUpdate(sql.toString());
 }

}
