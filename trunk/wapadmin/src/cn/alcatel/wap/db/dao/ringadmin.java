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


public class ringadmin  extends BaseDAO {

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

  public ringadmin() {
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
  public static int  insert(String ringname,String lg,String ringinfo,int tempring,
                            String viewpathsql,
                            int ringspid) {
     StringBuffer sql = new StringBuffer("insert into ");
    sql.append("ringresource(name,");
    sql.append("file1,");
    sql.append("typeid,");
    sql.append("lg,");
    sql.append("spid,");
    sql.append("info)");
    sql.append(" values('"+ringname+"','"+viewpathsql+"',"+tempring +",'"
                 +lg+"',"
                 +ringspid+",'"
                 +ringinfo+"')");
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
  public static DBMap[] all_ring_cnt(int typeid){
     String sql = new String("select count(*)as cnt from ringresource where typeid="+typeid+"");
    return executeQuery(sql);
}
// 显示的总条数
  public static int all_ring_count(int typeid){
    cn.alcatel.wap.db.DBMap[] cnt=all_ring_cnt(typeid);
    return tempcnt=Integer.parseInt(cnt[0].get("cnt").toString());
}

// 显示的总页数
  public static int get_pagecnt(int typeid){
     int temp=all_ring_count(typeid);
     if((temp%pagecnt)==0){
        return temp/pagecnt;
     }
     else{
        return temp/pagecnt+1;
     }
}
   ///////////显示单个数据
   public static DBMap[] listring(int e){
      String sql = new String("select * from ringresource where id="+e);
     return executeQuery(sql);
 }

// 查询某页显示的数据
public static DBMap[] get_page_info(int pagestart,int typeid){
     StringBuffer sql = new StringBuffer(" select id as id,");
          sql.append(" name as na, ");
          sql.append(" file1 as fileaddr, ");
          sql.append(" typeid as typeid, ");
          sql.append(" lg as lg, ");
          sql.append(" info as info, ");
          sql.append(" sdate as sdate ");
          sql.append(" from ringresource  ");
           sql.append(" where typeid="+typeid+" ");
          sql.append(" order by id desc");
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
  public static int  delete_ring(int id) {
     StringBuffer sql = new StringBuffer("delete from ringresource where id="+id+" ");
     return executeUpdate(sql.toString());
  }
// 查询需要修改的数据
public static DBMap[] get_modify_info(int tempid){
     StringBuffer sql = new StringBuffer(" select name as na,");
          sql.append("id as id,");
          sql.append("file1 as filepath,");
          sql.append("typeid as typeid,");
          sql.append("lg as lan,");
          sql.append("sdate as sdate,");
          sql.append("rel as rel,");
          sql.append("kindid as kindid,");
          sql.append("spid as spid,");
          sql.append("info as info ");
          sql.append(" from ringresource  ");
          sql.append(" where id="+tempid+"   ");
     return executeQuery(sql.toString());
}
// 处理查询后需要修改的数据

 //修改数据
 public static int  modify_ring(String ringname,String lg,String ringinfo,
                                           int  ringkind,String viewpathsql,
                                           int ringspid,int ringid){
    StringBuffer sql = new StringBuffer(" update ringresource ");
   sql.append(" set name='"+ringname+"', ");
   sql.append(" lg='"+lg+"',");
   sql.append(" file1='"+viewpathsql+"',");
   sql.append(" typeid="+ringkind+" ,");
   sql.append(" info='"+ringinfo+"',");
   sql.append(" spid="+ringspid+"");
   sql.append(" where id="+ringid+" ");
   //System.out.print("sqo="+sql.toString());
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
// 判断是否有重名的mp3
public static DBMap[] same_ring_quer(String ringname,int si){
     String sql = new String("select * from ringresource where name='"+ringname+"' and typeid="+si+"");
     return executeQuery(sql);
}
public static int same_ring(String  ringname,int size){
 cn.alcatel.wap.db.DBMap[] cnt=same_ring_quer(ringname,size);
 if(null==cnt){
     return 0;
 }
 else{
     return 1;
 }
}
  }
