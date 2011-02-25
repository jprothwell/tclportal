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


public class videoadmin  extends BaseDAO {

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
// 机型总数
public static int gamecount=0;

public static int ringformat[]=null;
public static String tempring=null;
public static String[] tempringformat=null;
public static String tempvideo=null;
public static String[] tempvideoformat=null;
public static String videoformat=null;
public static int javasupport=0;

  public videoadmin() {
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
  }
//插入终端的相关数据
  public static int  insert(String videoname,String lg,
                            int temp,
                            String model,String videoinfo,
                            int videosppro,int videosize,
                            String viewpathsql,String videopathsql) {
     StringBuffer sql = new StringBuffer("insert into ");
    sql.append("videosresource(name,");
    sql.append("images,");
    sql.append("file1,");
    sql.append("typeid,");
    sql.append("lg,");
    sql.append("spid,");
    sql.append("info,");
    sql.append("ua,");
    sql.append("sizeid)");
    sql.append(" values('"+videoname+"','"+viewpathsql+"','"+videopathsql+"',"
                 +temp+",'"
                 +lg+"',"
                 +videosppro+",'"
                 +videoinfo+"','"
                 +model+"',"
                 +videosize+")");
     return executeUpdate(sql.toString());
  }
  //////////
  public static DBMap[] listvideos(int dd){
   String sql = new String("select * from videosresource where id="+dd);
  return executeQuery(sql);
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
  public static DBMap[] all_video_cnt(int typeid){
     String sql = new String("select count(*)as cnt from videosresource where typeid="+typeid+"");
    return executeQuery(sql);
}
// 显示的总条数
  public static int all_video_count(int typeid){
    cn.alcatel.wap.db.DBMap[] cnt=all_video_cnt(typeid);
    if(null==cnt){
        return tempcnt=0;
    }
    else{
      return tempcnt = Integer.parseInt(cnt[0].get("cnt").toString());
    }
}

// 显示的总页数
  public static int get_pagecnt(int typeid){
     int temp=all_video_count(typeid);
     if((temp%pagecnt)==0){
        return temp/pagecnt;
     }
     else{
        return temp/pagecnt+1;
     }
}

// 查询某页显示的数据
public static DBMap[] get_page_info(int pagestart,int typeid){
     StringBuffer sql = new StringBuffer(" select id as id,");
          sql.append(" name as na, ");
          sql.append(" file1 as fileaddr, ");
          sql.append(" typeid as typeid, ");
          sql.append(" lg as lg, ");
          sql.append(" images as picdir, ");
          sql.append(" sizeid as sizeid, ");
          sql.append(" sdate as sdate ");
          sql.append(" from videosresource  ");
           sql.append(" where typeid="+typeid+" ");
          sql.append(" order by sizeid,id desc");
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
// 查询sp
    public static DBMap[] get_sp_info(){
      StringBuffer sql = new StringBuffer(" select id as id,");
           sql.append(" sp_name as spname ");
           sql.append(" from spinfo  ");
           sql.append(" order by id asc ");
      return executeQuery(sql.toString());
 }

//删除数据
  public static int  delete_video(int id) {
     StringBuffer sql = new StringBuffer("delete from videosresource where id="+id+" ");
     return executeUpdate(sql.toString());
  }
// 查询需要修改的数据
public static DBMap[] get_modify_info(int tempid){
     StringBuffer sql = new StringBuffer(" select name as na,");
          sql.append(" name as na, ");
          sql.append(" file1 as fileaddr, ");
          sql.append(" typeid as typeid, ");
          sql.append(" lg as lg, ");
          sql.append(" images as picdir, ");
          sql.append(" sdate as sdate ");
          sql.append(" from videosresource  ");
          sql.append(" where id="+tempid+"   ");
     return executeQuery(sql.toString());
}
// 处理查询后需要修改的数据

 //修改数据
 public static int  modify_video(String videoname,String lg,
                            String model,String videoinfo,
                            int videosppro,int videosize,
                            String viewpathsql,String videopathsql,int gameid){
    StringBuffer sql = new StringBuffer(" update videosresource ");
   sql.append(" set name='"+videoname+"', ");
   sql.append(" lg='"+lg+"',");
   sql.append(" images='"+viewpathsql+"',");
   sql.append(" file1='"+videopathsql+"' ,");
   sql.append(" ua='"+model+"',");
   sql.append(" sizeid="+videosize+",");
   sql.append(" info='"+videoinfo+"',");
   sql.append(" spid='"+videosppro+"' ");
   sql.append(" where id="+gameid+" ");
    return executeUpdate(sql.toString());
 }
// 机型总数总数
 public static DBMap[] all_model_cnt(String ua){
   String sql = new String("select count(*)as modelcnt from mobile where ua='"+ua+"'");
  return executeQuery(sql);
}
// 显示的总条数
 public static void all_model_count(String ua){
     cn.alcatel.wap.db.DBMap[] cntmodel=all_model_cnt(ua);
     gamecount=Integer.parseInt(cntmodel[0].get("modelcnt").toString());
}
  }
