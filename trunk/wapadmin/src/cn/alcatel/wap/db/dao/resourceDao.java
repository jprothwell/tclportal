package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;

public class resourceDao
    extends BaseDAO {
////////////////////
  ////////////修改栏目信息
  public int editResource(int id,String contentid) {
     StringBuffer sql = new StringBuffer("update menu set ");
     sql.append(" contentid='");
     sql.append(contentid);
     sql.append("' where id="+id);
     //System.out.println("sql="+sql.toString());
    return executeUpdate(sql.toString());
  }
/*-----图片begin------*/
//////显示图片列表
 public DBMap[] reimageList(String contentid) {
 StringBuffer sql = new StringBuffer("select * from imageresource where id in (");
 sql.append(contentid);
 sql.append(") order by orderid,id");
 return executeQuery(sql.toString());
 }
//////分页显示图片列表
 public DBMap[] imageList(int startpage,int num1,int sizeid,int kindid) {
 StringBuffer sql = new StringBuffer("select * from imageresource where sizeid= ");
 sql.append(sizeid);
 sql.append(" and kindid=");
 sql.append(kindid);
 sql.append(" order by sizeid,id limit ");
 sql.append(startpage);
 sql.append(" , ");
 sql.append(num1);
 //System.out.print("sql="+sql.toString());
 return executeQuery(sql.toString());
 }
  ////数量
 public int imageTotalnum(int sizeid,int kindid) {
    int count = 0;
   StringBuffer sql = new StringBuffer("select count(*)as count from imageresource where sizeid=");
   sql.append(sizeid);
   sql.append(" and kindid=");
   sql.append(kindid);
   DBMap[] map = executeQuery(sql.toString());
                  if (map != null) {
                          count = Integer.parseInt(String.valueOf(map[0].get("count")));
                  }
                  return count;
   }

   public int resourceOrder(String db,int id,int num1) {
    StringBuffer sql = new StringBuffer("update ");
    sql.append(db);
    sql.append(" set orderid=");
    sql.append(num1);
    sql.append("  where id="+id);
   return executeUpdate(sql.toString());
 }

   /*-----铃声begin------*/
//////显示铃声列表
 public DBMap[] ringList(String contentid) {
 StringBuffer sql = new StringBuffer("select * from ringresource where id in (");
 sql.append(contentid);
 sql.append(") order by orderid,id");
 return executeQuery(sql.toString());
 }
//////分页显示铃声列表
 public DBMap[] ringList(int startpage,int num1) {
 StringBuffer sql = new StringBuffer("select * from ringresource order by typeid,id limit ");
 sql.append(startpage);
 sql.append(" , ");
 sql.append(num1);
 return executeQuery(sql.toString());
 }
  ////铃声数量
 public int ringTotalnum() {
    int count = 0;
   StringBuffer sql = new StringBuffer("select count(*)as count ");
   sql.append(" from ");
   sql.append(" ringresource");
   DBMap[] map = executeQuery(sql.toString());
                  if (map != null) {
                          count = Integer.parseInt(String.valueOf(map[0].get("count")));
                  }
                  return count;
   }

   /*-----视频begin------*/
//////显示视频列表
  public DBMap[] videoList(String contentid) {
  StringBuffer sql = new StringBuffer("select * from videosresource where id in (");
  sql.append(contentid);
  sql.append(") order by orderid,id");
  return executeQuery(sql.toString());
  }
//////分页显示视频列表
  public DBMap[] videoList(int startpage,int num1) {
  StringBuffer sql = new StringBuffer("select * from videosresource order by sizeid,id limit ");
  sql.append(startpage);
  sql.append(" , ");
  sql.append(num1);
  return executeQuery(sql.toString());
  }
   ////视频数量
  public int videoTotalnum() {
     int count = 0;
    StringBuffer sql = new StringBuffer("select count(*)as count ");
    sql.append(" from ");
    sql.append(" videosresource");
    DBMap[] map = executeQuery(sql.toString());
                   if (map != null) {
                           count = Integer.parseInt(String.valueOf(map[0].get("count")));
                   }
                   return count;
    }
    /*-----信息begin------*/
//////显示信息列表
     public DBMap[] newsList(String contentid) {
     StringBuffer sql = new StringBuffer("select * from  newsresource where id in (");
     sql.append(contentid);
     sql.append(") order by orderid,id");
     return executeQuery(sql.toString());
     }
//////分页显示信息列表
     public DBMap[] newsList(String lg,int startpage,int num1) {
     StringBuffer sql = new StringBuffer("select * from newsresource where lg='");
     sql.append(lg);
     sql.append("' limit ");
     sql.append(startpage);
     sql.append(" , ");
     sql.append(num1);
     return executeQuery(sql.toString());
     }
      ////信息数量
     public int newsTotalnum(String lg) {
        int count = 0;
       StringBuffer sql = new StringBuffer("select count(*)as count ");
       sql.append(" from newsresource where lg='");
       sql.append(lg);
       sql.append("'");
       DBMap[] map = executeQuery(sql.toString());
                      if (map != null) {
                              count = Integer.parseInt(String.valueOf(map[0].get("count")));
                      }
                      return count;
       }
//////////////
       /*-----java begin------*/
//////分页显示java列表
   public DBMap[] gameList(String lg,int startpage,int num1) {
   StringBuffer sql = new StringBuffer("select * from gameresource where lg='");
   sql.append(lg);
   sql.append("' order by orderid limit ");
   sql.append(startpage);
   sql.append(" , ");
   sql.append(num1);
   //System.out.print("sql="+sql.toString());
   return executeQuery(sql.toString());
   }
    ////java数量
   public int gameTotalnum(String lg,String ua) {
      int count = 0;
     StringBuffer sql = new StringBuffer("select count(*)as count ");
     sql.append(" from gameresource where lg='");
     sql.append(lg);
     sql.append("' and ua='");
     sql.append(ua);
     sql.append("'");
     DBMap[] map = executeQuery(sql.toString());
                    if (map != null) {
                            count = Integer.parseInt(String.valueOf(map[0].get("count")));
                    }
                    return count;
     }
//////////////

}
