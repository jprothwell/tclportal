package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;
import javax.servlet.http.HttpServletRequest;

public class uamenuDao
    extends BaseDAO {
//////////////////////////
  ///检查栏目是否存在
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
//////显示栏目列表
  public DBMap[] uamenuList(String lg,String ua) {
  StringBuffer sql = new StringBuffer("select uamenu.id,uamenu.menuid,uamenu.lg,uamenu.ua,name,groupid,info,contentid,rel,new_r from uamenu,menu where uamenu.menuid=menu.id and uamenu.lg='");
  sql.append(lg);
  sql.append("' and uamenu.ua='");
  sql.append(ua);
  sql.append("' order by orderid,id");
// System.out.println("sql="+sql.toString());
  return executeQuery(sql.toString());
  }
  //////显示栏目列表
 public DBMap[] uamenuList(String lg,String ua,int groupid) {
 StringBuffer sql = new StringBuffer("select uamenu.id,uamenu.menuid,uamenu.lg,uamenu.ua,name,groupid,info,contentid,rel,new_r from uamenu,menu where uamenu.menuid=menu.id and uamenu.lg='");
 sql.append(lg);
 sql.append("' and uamenu.ua='");
 sql.append(ua);
  sql.append("' and groupid=");
  sql.append(groupid);
 sql.append(" order by orderid,id");
// System.out.println("sql="+sql.toString());
 return executeQuery(sql.toString());
 }
 public DBMap[] menuList(int id) {
 StringBuffer sql = new StringBuffer("select * from menu where id=");
 sql.append(id);
// System.out.println("sql="+sql.toString());
 return executeQuery(sql.toString());
 }
//得到游戏栏目列表
 public DBMap[] uagameList(String ua,String lg) {
      StringBuffer sql = new StringBuffer("select uagame.id as id,");
      sql.append(" uagame.ua as ua,");
      sql.append(" uagame.gameid as fid,");
      sql.append(" name,file1,file2,gameresource.lg as lg");
      sql.append(" FROM uagame,gameresource where uagame.gameid=gameresource.id and uagame.ua='");
      sql.append(ua);
      sql.append("' and gameresource.lg='");
      sql.append(lg);
      sql.append("' order by uagame.orderid limit 0,3");
      //System.out.println("sql="+sql.toString());
     return executeQuery(sql.toString());
     }

//////////////////////////
}
