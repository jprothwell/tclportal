package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
public class gameDao    extends BaseDAO {
  ////////////修改栏目信息
  public int editOrder(int id,int num1) {
    StringBuffer sql = new StringBuffer("update uagame set orderid=");
    sql.append(num1);
    sql.append("  where id="+id);
   return executeUpdate(sql.toString());
 }

  ////////////////
  public DBMap[] uagameList(String ua) {
StringBuffer sql = new StringBuffer("select uagame.id as id,");
sql.append(" uagame.ua as ua,");
sql.append(" uagame.gameid as fid,");
sql.append(" name,file1,file2,gameresource.lg as lg");
sql.append(" FROM uagame,gameresource where uagame.gameid=gameresource.id order by uagame.orderid");
//System.out.print("sql="+sql.toString());
return executeQuery(sql.toString());
}

  ////////////////插入游戏
public int insertGame(String ua,int gameid) {
 StringBuffer sql = new StringBuffer("insert into ");
  sql.append(" uagame ");
  sql.append(" (ua,gameid) values('"+ua+"','"+gameid+"')");
  //System.out.println("sql="+sql.toString());
  return executeUpdate(sql.toString());
}

  //////显示栏目列表
 public DBMap[] gameList(String ua,int startpage,int num1) {
   StringBuffer sql = new StringBuffer("select * from gameresource where not exists(select * FROM uagame where ua='");
 sql.append(ua);
 sql.append("' and gameresource.id=uagame.gameid)");
 sql.append(" limit ");
 sql.append(startpage);
 sql.append(" , ");
 sql.append(num1);
 return executeQuery(sql.toString());
 }
////数量
 public int gameTotalnum(String ua) {
   int count = 0;
  StringBuffer sql = new StringBuffer("select count(*)as count ");
  sql.append(" from gameresource where not exists(select * FROM uagame where ua='");
  sql.append(ua);
  sql.append("' and gameresource.id=uagame.gameid)");
  DBMap[] map = executeQuery(sql.toString());
                 if (map != null) {
                         count = Integer.parseInt(String.valueOf(map[0].get("count")));
                 }
                 return count;
  }
  ///////批量删除栏目纪录
  public int delallGame(String idlist) {
   StringBuffer sql = new StringBuffer("delete  from uagame ");
   sql.append(" where id in (");
   sql.append(idlist);
   sql.append(")");
  return executeUpdate(sql.toString());
 }

}
