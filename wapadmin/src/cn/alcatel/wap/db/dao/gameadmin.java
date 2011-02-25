package cn.alcatel.wap.db.dao;

import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.COMMON;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.sql.Date;
import cn.alcatel.wap.db.dao.Configuration;
/*********************
 * @author:abel
 * @author:09-08-11
 */


public class gameadmin  extends BaseDAO {

// 每页显示20条
public static int pagecnt=Configuration.gamepage;
// 显示的总条数
public static int tempcnt=0;
public static int singletempcnt=0;
// id
public static int tempid=0;

// 需要修改的字段
public static String name=null;
public static String ua=null;
public static String did=null;
public static int wapinfo=0;
public static int netinfo=0;
public static int screen=0;
// 机型总数
public static int gamecount=0;

public static int ringformat[]=null;
public static String tempring=null;
public static String[] tempringformat=null;
public static String tempvideo=null;
public static String[] tempvideoformat=null;
public static String videoformat=null;
public static int javasupport=0;

  public gameadmin() {
  }
  ////////////////
  public DBMap[] uagameList(String ua) {
 StringBuffer sql = new StringBuffer("select uagame.id as id,");
 sql.append(" uagame.ua as ua,");
 sql.append(" uagame.gameid as fid,");
 sql.append(" name,file1,file2,gameresource.lg as lg");
 sql.append(" FROM uagame,gameresource where uagame.gameid=gameresource.id and uagame.ua='");
 sql.append(ua);
 sql.append("' order by uagame.orderid");
//System.out.print("sql="+sql.toString());
return executeQuery(sql.toString());
}
  public DBMap[] uagameList(String ua,String lg) {
StringBuffer sql = new StringBuffer("select uagame.id as id,");
sql.append(" uagame.ua as ua,");
sql.append(" uagame.gameid as fid,");
sql.append(" name,file1,file2,gameresource.lg as lg");
sql.append(" FROM uagame,gameresource where uagame.gameid=gameresource.id and uagame.ua='");
sql.append(ua);
sql.append("' and gameresource.lg='");
sql.append(lg);
sql.append("' order by uagame.orderid");
//System.out.print("sql="+sql.toString());
return executeQuery(sql.toString());
}


  //////分页显示java列表
   public DBMap[] gameList(int startpage,int num1) {
   StringBuffer sql = new StringBuffer("select * from gameresource order by orderid limit ");
   sql.append(startpage);
   sql.append(" , ");
   sql.append(num1);
   //System.out.print("sql="+sql.toString());
   return executeQuery(sql.toString());
   }
    ////java数量
   public int gameTotalnum() {
      int count = 0;
     StringBuffer sql = new StringBuffer("select count(*)as count ");
     sql.append(" from gameresource ");
     DBMap[] map = executeQuery(sql.toString());
                    if (map != null) {
                            count = Integer.parseInt(String.valueOf(map[0].get("count")));
                    }
                    return count;
     }
//////////////
  ////////////////
  public static void iddb(int temp) {
    tempid=temp;
    cn.alcatel.wap.db.DBMap tmpdb[]= get_modify_info(tempid);
    name=tmpdb[0].get("na").toString();
    ua=tmpdb[0].get("ua").toString();
    did=tmpdb[0].get("did").toString();
    wapinfo=Integer.parseInt(tmpdb[0].get("wapinfo").toString());
    netinfo=Integer.parseInt(tmpdb[0].get("netinfo").toString());
    javasupport=Integer.parseInt(tmpdb[0].get("javasupport").toString());
    tempring=tmpdb[0].get("ringformat").toString();
    tempringformat=tempring.split(",");
    tempvideo=tmpdb[0].get("videoformat").toString();
    tempvideoformat=tempvideo.split(",");
    screen=Integer.parseInt(tmpdb[0].get("screen").toString());
  }
//插入页面相关数据
  public static String display_str(String Str){
Str=Str.replaceAll("'","’");
Str=Str.replaceAll("\"","”");
System.out.println("Str="+Str);
return   Str;
}

//插入终端的相关数据
  public static int  insert(String gamename,String gameinfo,String lg,
                            String viewpathsql,String picjarpathsql,String picjadpathsql,
                            int gameapp,int screen,int sppro,String price) {
    gameinfo =display_str(gameinfo);
     StringBuffer sql = new StringBuffer("insert into ");
    sql.append("gameresource(name,");
    sql.append("images,");
    sql.append("info,");
    sql.append("file1,");
    sql.append("file2,");
    sql.append("spid,");
    sql.append("lg,");
    sql.append("typeid,");
    sql.append("sizeid,");
    sql.append("price)");
    sql.append(" values('"+gamename+"','"+viewpathsql+"','"+gameinfo+"','"
                 +picjarpathsql+"','"
                 +picjadpathsql+"','"
                 +sppro+"','"
                 +lg+"','"
                +gameapp+"','"
                +screen+"','"
                +price+"')");
     return executeUpdate(sql.toString());
  }
  //输出所有的数据
  public static DBMap[] all_mobile_info(){
      StringBuffer sql = new StringBuffer(" select name as na,");
         sql.append("ua as ua,");
         sql.append("did as did,");
         sql.append("wapinfo as wapinfo,");
         sql.append("netinfo as netinfo,");
         sql.append("image_size as screen,");
         sql.append("ring_format as ringformat,");
         sql.append("video_format as videoformat,");
         sql.append("game_rel as javasupport");
         sql.append(" from mobile  ");
    return executeQuery(sql.toString());
}
//显示总条数
  public static DBMap[] all_game_cnt(){
     String sql = new String("select count(*)as cnt from mobile where game_rel='1'");
    return executeQuery(sql);
}
// 显示的总条数
  public static int all_game_count(){
    cn.alcatel.wap.db.DBMap[] cnt=all_game_cnt();
    if(null==cnt){
       return tempcnt=0;
    }
    else{
       return tempcnt=Integer.parseInt(cnt[0].get("cnt").toString());
    }
}

// 显示的总页数
  public static int get_pagecnt(){
     int temp=all_game_count();
     if((temp%pagecnt)==0){
        return temp/pagecnt;
     }
     else{
        return temp/pagecnt+1;
     }
}
// 单个机型显示时的总页数
public static int get_singlepagecnt(){
   int temp=all_singlegame_count();
   if((temp%pagecnt)==0){
      return temp/pagecnt;
   }
   else{
      return temp/pagecnt+1;
   }
}
public static int all_singlegame_count(){
   cn.alcatel.wap.db.DBMap[] cnt=all_singlegame_cnt();
   if(null==cnt){
       return 0;
   }
   else{
     return singletempcnt = Integer.parseInt(cnt[0].get("singlecnt").toString());
   }
}
public static DBMap[] all_singlegame_cnt(){
   String sql = new String("select count(*)as singlecnt from gameresource ");
  return executeQuery(sql);
}

// 查询某页显示的数据
public static DBMap[] get_page_info(int pagestart){
     StringBuffer sql = new StringBuffer(" select id as id,");
          sql.append(" ua as ua ");
          sql.append(" from mobile  ");
          sql.append(" where game_rel=1  ");
          sql.append(" order by id desc ");
          sql.append(" limit "+pagestart+","+pagecnt+" ");
     return executeQuery(sql.toString());
}
   // 查询所有的机型
    public static DBMap[] gamelist(int e){
      StringBuffer sql = new StringBuffer("select * from gameresource where id =");
           sql.append(e);
      return executeQuery(sql.toString());
 }

// 查询某页单个游戏显示的数据
public static DBMap[] get_singlepage_info(int pagestart){
     StringBuffer sql = new StringBuffer(" select id as id,");
          sql.append(" name as name, ");
          sql.append(" images as images, ");
          sql.append(" file1 as jar, ");
          sql.append(" file2 as jad, ");
          sql.append(" orderid as sort, ");
          sql.append(" lg as lg ");
          sql.append(" from gameresource  ");
          sql.append(" order by lg,orderid desc ");
          sql.append(" limit "+pagestart+","+pagecnt+" ");
     return executeQuery(sql.toString());
}

// 查询所有的机型
   public static DBMap[] get_model_info(){
     StringBuffer sql = new StringBuffer(" select id as id,");
          sql.append(" ua as ua ");
          sql.append(" from mobile  ");
          sql.append(" order by id asc ");
     return executeQuery(sql.toString());
}
// 查询所有的机型
    public static DBMap[] get_sp_info(){
      StringBuffer sql = new StringBuffer(" select id as id,");
           sql.append(" sp_name as spname ");
           sql.append(" from spinfo  ");
           sql.append(" order by id asc ");
      return executeQuery(sql.toString());
 }


//删除数据
  public static int  delete_game(int id) {
     StringBuffer sql = new StringBuffer("delete from gameresource where id="+id+" ");
     return executeUpdate(sql.toString());
  }
// 查询需要修改的数据
public static DBMap[] get_modify_info(int tempid){
     StringBuffer sql = new StringBuffer(" select name as na,");
      sql.append(" images as images, ");
      sql.append(" info as info, ");
      sql.append(" file1 as jar, ");
      sql.append(" file2 as jad, ");
      sql.append(" ua as ua, ");
      sql.append(" spid as spid, ");
      sql.append(" sdate as sdate, ");
      sql.append(" lg as lg, ");
      sql.append(" kindid as kindid, ");
      sql.append(" typeid as typeid, ");
      sql.append(" rel as rel, ");
      sql.append(" orderid as sort, ");
      sql.append(" sizeid as sizeid ");
      sql.append(" from gameresource  ");
      sql.append(" where id="+tempid+"   ");

     return executeQuery(sql.toString());
}
// 处理查询后需要修改的数据

 //修改数据
 public static int  modify_game(String gamename,String price,String gameinfo,String lg,
                            String viewpathsql,String picjarpathsql,String picjadpathsql,
                            int screen,int sppro,int gameid) {
  gameinfo =display_str(gameinfo);
   StringBuffer sql = new StringBuffer(" update gameresource ");
   sql.append(" set name='"+gamename+"', ");
   sql.append(" price='"+price+"',");
   sql.append(" images='"+viewpathsql+"',");
   sql.append(" info='"+gameinfo+"',");
   sql.append(" file1='"+picjarpathsql+"' ,");
   sql.append(" file2='"+picjadpathsql+"',");
   sql.append(" spid="+sppro+",");
   sql.append(" lg='"+lg+"',");
   sql.append(" sizeid="+screen);
   sql.append(" where id="+gameid+" ");
    return executeUpdate(sql.toString());
 }
// 机型总数总数
 public static DBMap[] all_model_cnt(String ua){
   String sql = new String("select count(*)as modelcnt from uagame where ua='"+ua+"'");
  return executeQuery(sql);
}
// 显示的总条数
 public static void all_model_count(String ua){
     cn.alcatel.wap.db.DBMap[] cntmodel=all_model_cnt(ua);
     gamecount=Integer.parseInt(cntmodel[0].get("modelcnt").toString());
}
  }
