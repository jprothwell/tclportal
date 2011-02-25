package cn.alcatel.wap.db.dao;

import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.COMMON;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;
import cn.alcatel.wap.db.dao.Configuration;
/*********************
 * @author:abel
 * @author:09-08-11
 */

public class mobilelist extends BaseDAO {
  public mobilelist(){
  }

// soho每页显示20条
public static int listpagecnt=Configuration.mobilepage;
// soho的总条数
public static int soho_tempcnt=0;
private static  String MOBILE_NAME=null;
private static int JAVA_SUPPORT=0;
private static  int RING_FORMAT=0;
private static int VIDEO_FORMAT=0;

  public mobilelist(String na,int java,int ring,int video) {
     MOBILE_NAME=na;
     JAVA_SUPPORT=java;
     RING_FORMAT=ring;
     VIDEO_FORMAT=video;
}
   //soho的总条数
 public static DBMap[] soho_all_mobile_cnt(){
   StringBuffer sql = new StringBuffer("select count(id) from ");
   sql.append(" mobile ");
   sql.append(" where ");
   sql.append(" ua like '%"+MOBILE_NAME+"%' ");
   sql.append(" and game_rel="+JAVA_SUPPORT+" ");
   sql.append(" and ring_format like '%"+RING_FORMAT+"%' ");
   sql.append(" and video_format like '%"+VIDEO_FORMAT+"%' ");
 return executeQuery(sql.toString());
}
  //soho计算总页数的总条数
public static DBMap[] page_soho_all_mobile_cnt(){
StringBuffer sql = new StringBuffer("select count(id)as paid from   ");
sql.append(" mobile ");
sql.append(" where ");
sql.append(" ua like '%"+MOBILE_NAME+"%' ");
sql.append(" and game_rel="+JAVA_SUPPORT+" ");
sql.append(" and ring_format like '%"+RING_FORMAT+"%' ");
sql.append(" and video_format like '%"+VIDEO_FORMAT+"%' ");
return executeQuery(sql.toString());
}

// soho的总条数
public static int soho_all_mobile_count(){
   cn.alcatel.wap.db.DBMap[] soho_cnt=soho_all_mobile_cnt();
  if(soho_cnt[0].get("cnt")==null){
      return 0;
  }
  else{
     return soho_tempcnt = Integer.parseInt(soho_cnt[0].get("cnt").toString());
  }
}
// soho,page的总条数
public static int page_soho_all_mobile_count(){
   cn.alcatel.wap.db.DBMap[] soho_cnt=page_soho_all_mobile_cnt();
  if(soho_cnt[0].get("paid")==null){
      return 0;
  }
  else{
     return soho_tempcnt = Integer.parseInt(soho_cnt[0].get("paid").toString());
  }
}

// soho的总页数
public static int soho_get_pagecnt(){
      int temp = page_soho_all_mobile_count();
      if ( (temp % listpagecnt) == 0) {
        return temp / listpagecnt;
      }
      else{
        return temp / listpagecnt + 1;
    }
}

// 查询符合条件的所有数据数据
public static DBMap[] get_page_info(){
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
         sql.append(" ua like '%"+MOBILE_NAME+"%' ");
         sql.append(" and game_rel="+JAVA_SUPPORT+" ");
         sql.append(" and ring_format like '%"+RING_FORMAT+"%' ");
         sql.append(" and video_format like '%"+VIDEO_FORMAT+"%' ");
         sql.append(" order by id asc    ");
    return executeQuery(sql.toString());
}
  /////////
  // 查询符合条件的所有数据数据
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
  if(ring.length()>0)   sql.append(" and ring_format like '%"+ring+"%' ");
  if(video.length()>0)  sql.append(" and video_format like '%"+video+"%' ");
  return executeQuery(sql.toString());
}
}
