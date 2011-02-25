package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;

public class menuDao
    extends BaseDAO {
  ////////////////������Ŀ��¼
public int insertMenu(String name,int fid,String images,String lg,int groupid,String info,int pageid,int rel) {
  StringBuffer sql = new StringBuffer("insert into ");
   sql.append(" menu ");
   sql.append(" (name,fid,images,lg,groupid,info,pageid,rel) values('"+name+"','"+fid+"','"+images+"','"+lg+"','"+groupid+"','"+info+"','"+pageid+"','"+rel+"')");
   //System.out.println("sql="+sql.toString());
   return executeUpdate(sql.toString());
}
////////////�޸���Ŀ��Ϣ
  public int editMenu(int id,String name,String  images,String lg,int groupid, String info,int pageid,int rel) {
    StringBuffer sql = new StringBuffer("update menu set ");
    sql.append(" name='");
    sql.append(name);
    sql.append("', images='");
    sql.append(images);
    sql.append("', lg='");
    sql.append(lg);
    sql.append("', info='");
    sql.append(info);
    sql.append("', groupid=");
    sql.append(groupid);
    sql.append(", pageid=");
    sql.append(pageid);
    sql.append(", rel=");
    sql.append(rel);
    sql.append("  where id="+id);
    //System.out.println("sql="+sql.toString());
   return executeUpdate(sql.toString());
 }

///////ɾ����Ŀ��¼
 public int delMenu(int id) {
  StringBuffer sql = new StringBuffer("delete  from menu ");
  sql.append(" where id="+id);
 return executeUpdate(sql.toString());
}
  ///////����ɾ����Ŀ��¼
 public int delallMenu(String idlist) {
  StringBuffer sql = new StringBuffer("delete  from menu ");
  sql.append(" where id in (");
  sql.append(idlist);
  sql.append(")");
  //System.out.println(sql.toString());
 return executeUpdate(sql.toString());
}

  //////��ʾ��Ŀ�б�
 public DBMap[] menuList(String lg,int groupid,int startpage,int num1) {
 StringBuffer sql = new StringBuffer("select * from menu where lg='");
 sql.append(lg);
 sql.append("' and groupid=");
 sql.append(groupid);
 sql.append(" limit ");
 sql.append(startpage);
 sql.append(" , ");
 sql.append(num1);
 return executeQuery(sql.toString());
 }
 public DBMap[] menuList(String lg,int groupid) {
  StringBuffer sql = new StringBuffer("select * from menu where lg='");
  sql.append(lg);
  sql.append("' and groupid=");
  sql.append(groupid);
  return executeQuery(sql.toString());
  }

 ////����
 public int menuTotalnum(String lg,int groupid) {
   int count = 0;
  StringBuffer sql = new StringBuffer("select count(*)as count ");
  sql.append(" from ");
  sql.append(" menu  where lg='");
  sql.append(lg);
  sql.append("' and groupid=");
  sql.append(groupid);
  DBMap[] map = executeQuery(sql.toString());
                 if (map != null) {
                         count = Integer.parseInt(String.valueOf(map[0].get("count")));
                 }
                 return count;
  }
  ////////////////��ʾ������Ϣ
  public DBMap[] menuInfo(int e) {
StringBuffer sql = new StringBuffer("select * ");
sql.append(" from menu ");
sql.append(" where id= ");
sql.append(e);
return executeQuery(sql.toString());
}

///////////
}
