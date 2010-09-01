package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;

public class resourceDao
    extends BaseDAO {
////////////////////
/*-----图片begin------*/
//////分页显示图片列表
 public DBMap[] imageList(String contentid,int startpage,int num1) {
 StringBuffer sql = new StringBuffer("select * from imageresource where id in (");
 sql.append(contentid);
 sql.append(") order by orderid limit ");
 sql.append(startpage);
 sql.append(" , ");
 sql.append(num1);
 return executeQuery(sql.toString());
 }
   /*-----铃声begin------*/
//////分页显示铃声列表
 public DBMap[] ringList(String contentid,int startpage,int num1) {
 StringBuffer sql = new StringBuffer("select * from ringresource where id in (");
 sql.append(contentid);
 sql.append(") order by orderid limit ");
 sql.append(startpage);
 sql.append(" , ");
 sql.append(num1);
 return executeQuery(sql.toString());
 }
    /*-----视频begin------*/
//////分页显示视频列表
  public DBMap[] videoList(String contentid,int startpage,int num1) {
  StringBuffer sql = new StringBuffer("select * from videosresource where id in (");
  sql.append(contentid);
  sql.append(") order by orderid limit ");
  sql.append(startpage);
  sql.append(" , ");
  sql.append(num1);
  return executeQuery(sql.toString());
  }
   /*-----信息begin------*/
//////分页显示信息列表
     public DBMap[] newsList(String contentid,int startpage,int num1) {
     StringBuffer sql = new StringBuffer("select * from newsresource where id in (");
     sql.append(contentid);
     sql.append(") order by orderid limit ");
     sql.append(startpage);
     sql.append(" , ");
     sql.append(num1);
     return executeQuery(sql.toString());
     }
    ////////显示单个信息
     public DBMap[] newsInfo(int e) {
    StringBuffer sql = new StringBuffer("select * from newsresource where id=");
    sql.append(e);
    return executeQuery(sql.toString());
    }
   /////////////
   public String display_convert(String Str){
     Str=Str.replaceAll("&","&amp;");
     Str=Str.replaceAll("   ","&nbsp;")   ;
     Str=Str.replaceAll(">","&gt;");
     Str=Str.replaceAll("<","&lt;");
     Str=Str.replaceAll("\n","<br/>");
     Str=Str.replaceAll("\"","&quot;");
 return   Str;
   }
       /*-----java begin------*/
       public DBMap[] uagameList(String ua,String lg,int startpage,int num1) {
      StringBuffer sql = new StringBuffer("select uagame.id as id,");
      sql.append(" uagame.ua as ua,");
      sql.append(" uagame.gameid as fid,");
      sql.append(" name,file1,file2,gameresource.lg as lg");
      sql.append(" FROM uagame,gameresource where uagame.gameid=gameresource.id and uagame.ua='");
      sql.append(ua);
      sql.append("' and gameresource.lg='");
      sql.append(lg);
      sql.append("' order by uagame.orderid limit ");
      sql.append(startpage);
      sql.append(" , ");
      sql.append(num1);
//System.out.print("sql="+sql.toString());
     return executeQuery(sql.toString());
     }

     public int uagameTotalnum(String lg,String ua) {
          int count = 0;
         StringBuffer sql = new StringBuffer("select count(*)as count ");
         sql.append(" from uagame,gameresource  where uagame.gameid=gameresource.id and uagame.ua='");
         sql.append(ua);
         sql.append("' and gameresource.lg='");
         sql.append(lg);
         sql.append("'");
 //System.out.print("sql="+sql.toString());
         DBMap[] map = executeQuery(sql.toString());
                        if (map != null) {
                                count = Integer.parseInt(String.valueOf(map[0].get("count")));
                        }
                        return count;
         }


//////分页显示java列表
   public DBMap[] gameList(String ua,String lg,int startpage,int num1) {
   StringBuffer sql = new StringBuffer("select * from gameresource where ua='");
   sql.append(ua);
   sql.append("' and lg='");
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
     ////////显示单个信息
     public DBMap[] gameInfo(int e) {
    StringBuffer sql = new StringBuffer("select * from gameresource,spinfo where gameresource.spid=spinfo.id and gameresource.id=");
    sql.append(e);
    return executeQuery(sql.toString());
    }

//////////////
}
