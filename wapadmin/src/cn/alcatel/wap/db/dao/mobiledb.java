package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.COMMON;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import cn.alcatel.wap.db.dao.Configuration;
/*********************
 * @author:abel
 * @author:09-08-11
 */


public class mobiledb  extends BaseDAO {

// 每页显示20条
public static int pagecnt=Configuration.mobilepage;
// 显示的总条数
public static int tempcnt=0;

// id
public static int tempid=0;

// 需要修改的字段
public static String name=null;
public static String ua=null;
public static String did=null;
public static int wapinfo=0;
public static int netinfo=0;
public static int screen=0;
public static int ringformat[]=null;
public static String tempring=null;
public static String[] tempringformat=null;
public static String tempvideo=null;
public static String[] tempvideoformat=null;
public static String videoformat=null;
public static int javasupport=0;
public static int pageid=0;

  public mobiledb() {
  }
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
    if(null==tmpdb[0].get("pageid")){
       pageid=0;
    }
    else{
       pageid=Integer.parseInt(tmpdb[0].get("pageid").toString());
    }
  }
//插入终端的相关数据
  public static int  insert(String mobilename,String mobileua,
                            int mobiledid,int mobileversion,int mobilenet,
                            String ringformat,String videoformat,
                            int javasupport, int screensize,int pageclass) {
     StringBuffer sql = new StringBuffer("insert into ");
    sql.append("mobile(name,");
    sql.append("ua,");
    sql.append("did,");
    sql.append("wapinfo,");
    sql.append("netinfo,");
    sql.append("ring_format,");
    sql.append("video_format,");
    sql.append("game_rel,");
    sql.append("image_size,");
    sql.append("pageid)");
    sql.append(" values('"+mobilename+"','"
               +mobileua+"','"
               +mobiledid+"','"
               +mobileversion+"','"
               +mobilenet+"','"
               +ringformat+"','"
               +videoformat+"',"+javasupport+","+screensize+","+pageclass+")" );
  //  System.out.print(sql.toString());
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
  public static DBMap[] all_mobile_cnt(){
     String sql = new String("select count(*)as cnt from mobile");
    return executeQuery(sql);
}
// 显示的总条数
  public static int all_mobile_count(){
    cn.alcatel.wap.db.DBMap[] cnt=all_mobile_cnt();
    if(null==cnt){
        return tempcnt=0;
     }
     else{
        return tempcnt=Integer.parseInt(cnt[0].get("cnt").toString());
     }
}

// 显示的总页数
  public static int get_pagecnt(){
     int temp=all_mobile_count();
     if((temp%pagecnt)==0){
        return temp/pagecnt;
     }
     else{
        return temp/pagecnt+1;
     }
}
   /////查询结果
   public static DBMap[] getList(String ua, String java,String ring,String video){
       StringBuffer sql = new StringBuffer(" select id as id,name as na,");
            sql.append("ua as ua,");
            sql.append("did as did,");
            sql.append("wapinfo as wapinfo,");
            sql.append("netinfo as netinfo,");
            sql.append("image_size as screen,");
            sql.append("ring_format as ringformat,");
            sql.append("video_format as videoformat,");
            sql.append("game_rel as javasupport");
            sql.append(" from mobile where ");
            sql.append(" ua like '%"+ua+"%' ");
     if(java.length()>0){
       int int_java=Integer.parseInt(java);
       sql.append(" and game_rel="+int_java);
     }
     if(ring.length()>0){
       int int_ring=Integer.parseInt(ring);
       sql.append(" and image_size="+int_ring);
     }
     if(video.length()>0)sql.append(" and video_format like '%"+video+"%' ");
     return executeQuery(sql.toString());
   }

// 查询某页显示的数据
public static DBMap[] get_page_info(int pagestart){
     StringBuffer sql = new StringBuffer(" select id as id,name as na,");
          sql.append("ua as ua,");
          sql.append("did as did,");
          sql.append("wapinfo as wapinfo,");
          sql.append("netinfo as netinfo,");
          sql.append("image_size as screen,");
          sql.append("ring_format as ringformat,");
          sql.append("video_format as videoformat,");
          sql.append("game_rel as javasupport,");
          sql.append("pageid as pageid");
          sql.append(" from mobile  ");
          sql.append(" order by id desc    ");
          sql.append("  limit "+pagestart+","+pagecnt+" ");
     return executeQuery(sql.toString());
}
//删除数据
  public static int  delete_mobile(int id) {
     StringBuffer sql = new StringBuffer("delete from mobile where id="+id+" ");
     return executeUpdate(sql.toString());
  }
// 查询需要修改的数据
public static DBMap[] get_modify_info(int tempid){
     StringBuffer sql = new StringBuffer(" select name as na,");
          sql.append("ua as ua,");
          sql.append("did as did,");
          sql.append("wapinfo as wapinfo,");
          sql.append("netinfo as netinfo,");
          sql.append("image_size as screen,");
          sql.append("ring_format as ringformat,");
          sql.append("video_format as videoformat,");
          sql.append("game_rel as javasupport,");
          sql.append("pageid as pageid");
          sql.append(" from mobile  ");
          sql.append(" where id="+tempid+"   ");
     return executeQuery(sql.toString());
}
// 处理查询后需要修改的数据

 //修改数据
 public static int  modify_mobile(int id,String mobilename,String mobileua,
                           int mobiledid,int mobileversion,int mobilenet,
                           String ringformat,String videoformat,
                           int javasupport, int screensize,int pageid) {
    StringBuffer sql = new StringBuffer(" update mobile ");
   sql.append(" set name='"+mobilename+"', ");
   sql.append(" ua='"+mobileua+"',");
   sql.append(" did="+mobiledid+",");
   sql.append(" wapinfo="+mobileversion+" ,");
   sql.append(" netinfo="+mobilenet+",");
   sql.append(" ring_format='"+ringformat+"',");
   sql.append(" video_format='"+videoformat+"',");
   sql.append(" game_rel="+javasupport+",");
   sql.append(" image_size="+screensize+", ");
   sql.append(" pageid="+pageid+" ");
   sql.append(" where id="+id+" ");
    return executeUpdate(sql.toString());
 }
 //ua唯一性
 //显示总条数
  public static DBMap[] all_mobile_unique(String ua){
     String sql = new String("select *  from mobile where ua='"+ua+"'");
    return executeQuery(sql);
}
// 确定此UA是否存在
  public static int mobile_unique(String ua){
    cn.alcatel.wap.db.DBMap[] cnt=all_mobile_unique(ua);
    if(null==cnt){
        return tempcnt=0;
     }
     else{
        return tempcnt=1;
     }
}
// 获取页面的信息
   public static DBMap[] all_mobile_page(){
      String sql = new String("select id as id,name as na  from pageresource where kindid=0");
     return executeQuery(sql);
 }
  }
