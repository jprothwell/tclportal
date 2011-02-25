package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;


import cn.alcatel.wap.db.dao.Configuration;

/*********************
 * @author:abel
 * @author:09-08-14
 */


public class picres  extends BaseDAO {

// 每页显示20条
public static int pagecnt=Configuration.picpage;
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
public static String screen=null;
public static int ringformat[]=null;
public static String tempring=null;
public static String[] tempringformat=null;
public static String videoformat=null;
public static int javasupport=0;

  public picres() {
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

  }
//插入页面相关数据
  public static String display_str(String Str){
Str=Str.replaceAll("'","’");
Str=Str.replaceAll("\"","”");
System.out.println("Str="+Str);
return   Str;
}
//插入页面相关数据
  public static int  insert(String picname,String viewpath,String picpath,
                            int screensize,int kindid,
                            String language,
                            String descrip,
                            int spname) {
    descrip =display_str(descrip);
     StringBuffer sql = new StringBuffer("insert into ");
    sql.append("imageresource(name,");
    sql.append("file1,");
    sql.append("file2,");
    sql.append("sizeid,");
    sql.append("kindid,");
    sql.append("lg,");
    sql.append("spid,");
    sql.append("info)");
    sql.append(" values('"+picname+"','"
               +viewpath+"','"
               +picpath+"','"
               +screensize+"','"
               +kindid+"','"
               +language+"','"
               +spname+"','"
               +descrip+"')");
   // System.out.println("sql="+sql.toString());
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
  public static DBMap[] all_page_cnt(int dd,int e){
     String sql = new String("select count(*)as cnt from imageresource where sizeid="+dd+" and kindid="+e);
     //System.out.println("sql="+sql);
    return executeQuery(sql);
}
  //显示总条数
  public static DBMap[] listimages(int dd){
     String sql = new String("select * from imageresource where id="+dd);
    return executeQuery(sql);
}

// 显示的总条数,即有多少张图片
  public static int all_page_count(int pagescreenid,int kindid){
    cn.alcatel.wap.db.DBMap[] cnt=all_page_cnt(pagescreenid,kindid);
    return tempcnt=Integer.parseInt(cnt[0].get("cnt").toString());
}

// 显示的总页数
  public static int get_pagecnt(int screenid,int kindid){
    //System.out.println("screenid="+screenid);
     int temp=all_page_count(screenid,kindid);
     if((temp%pagecnt)==0){
        return temp/pagecnt;
     }
     else{
        return temp/pagecnt+1;
     }
}

// 查询某页显示的数据
public static DBMap[] get_page_info(int pagestart,int sizeid,int kindid){
     StringBuffer sql = new StringBuffer(" select id as id,name as na,");
          sql.append("file1 as pathview,");
          sql.append("file2 as pathpic,");
          sql.append("lg as lan,");
          sql.append("sdate as sdate ");
          sql.append(" from imageresource  ");
          sql.append(" where sizeid="+sizeid+" and kindid="+kindid);
          sql.append(" order by id desc ");
          sql.append("  limit "+pagestart+","+pagecnt+" ");
     return executeQuery(sql.toString());
}
//删除数据
  public static int  delete_pic(int id) {
     StringBuffer sql = new StringBuffer("delete from imageresource where id="+id+" ");
     return executeUpdate(sql.toString());
  }
// 查询需要修改的数据
public static DBMap[] get_modify_info(int tempid){
     StringBuffer sql = new StringBuffer(" select name as na,");
          sql.append("file1 as pathview,");
          sql.append("file2 as picpath,");
          sql.append("sizeid as size,");
          sql.append("lg as lg,");
          sql.append("sdate as sdate,");
          sql.append("kindid as kindid,");
          sql.append("rel as rel,");
          sql.append("spid as spid,");
          sql.append("info as info");
          sql.append(" from imageresource  ");
          sql.append(" where id="+tempid+"   ");
     return executeQuery(sql.toString());
}

 // 修改数据
   public static int  modify_pic(int indexid,String picname,String viewpathsql,String picpathsql,int sizeid,int kindid,String lan,String picdesc,int spname) {
     StringBuffer sql = new StringBuffer(" update imageresource set name='"+picname+"',");
     sql.append(" file1='"+viewpathsql+"',");
     sql.append(" file2='"+picpathsql+"',");
     sql.append(" sizeid="+sizeid+",");
     sql.append(" kindid="+kindid+",");
     sql.append(" lg='"+lan+"',");
     sql.append(" spid="+spname+",");
     sql.append(" info='"+picdesc+"' ");
     sql.append(" where id="+indexid+"   ");
      return executeUpdate(sql.toString());
   }
 // 查询是否有同名的图片
public static DBMap[] same_pic_quer(String pic,int si){
      String sql = new String("select * from imageresource where name='"+pic+"' and sizeid="+si+"");
      return executeQuery(sql);
 }
 public static int same_pic(String  picname,int size){
  cn.alcatel.wap.db.DBMap[] cnt=same_pic_quer(picname,size);
  if(null==cnt){
      return 0;
  }
  else{
      return 1;
  }
}
  }
