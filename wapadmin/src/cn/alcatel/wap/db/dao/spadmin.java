package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.COMMON;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.sql.Date;
import cn.alcatel.wap.db.dao.Configuration;

/*********************
 * @author:abel
 * @author:09-08-14
 */


public class spadmin  extends BaseDAO {

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
public static String screen=null;
public static int ringformat[]=null;
public static String tempring=null;
public static String[] tempringformat=null;
public static String videoformat=null;
public static int javasupport=0;

public static String  spname=null;
public static String username=null;
public static String userphone=null;

public static String useremail=null;
public static String clientphone=null;
public static String spinfo=null;
  public spadmin() {
  }
  public static void iddb(int temp) {
    tempid=temp;
    cn.alcatel.wap.db.DBMap tmpdb[]= get_modify_info(tempid);
    spname=tmpdb[0].get("spname").toString();
    if(null==tmpdb[0].get("username")){
       username="无信息";
    }
    else{
      username=tmpdb[0].get("username").toString();
    }

    if(null==tmpdb[0].get("spinfo")){
        spinfo="无信息";
    }
    else{
        spinfo=tmpdb[0].get("spinfo").toString();
     }

     if(null==tmpdb[0].get("useremail")){
         useremail="无信息";
     }
     else{
         useremail=tmpdb[0].get("useremail").toString();
      }

      if(null==tmpdb[0].get("clientphone")){
           clientphone="无信息";
       }
       else{
           clientphone=tmpdb[0].get("clientphone").toString();
        }
        if(null==tmpdb[0].get("userphone")){
           userphone="无信息";
       }
       else{
           userphone=tmpdb[0].get("userphone").toString();
        }
  }
//插入页面相关数据
  public static int  insert(String spname,String username,String userphone,
                            String useremail,String clientphone,String spinfo) {
     StringBuffer sql = new StringBuffer("insert into ");
    sql.append("spinfo(sp_name,");
    sql.append("user_name,");
    sql.append("sp_tel,");
    sql.append("sp_email,");
    sql.append("user_tel,");
    sql.append("sp_info )");
    sql.append(" values('"+spname+"','"
               +username+"','"
               +userphone+"','"
               +useremail+"','"
               +clientphone+"','"
               +spinfo+"')");
     //System.out.print(sql);
     return executeUpdate(sql.toString());
  }
  //输出所有的数据
  public static DBMap[] get_modify_info(int tempid){
    StringBuffer sql = new StringBuffer(" select id as id,");
         sql.append(" sp_name as spname, ");
         sql.append(" user_name as username, ");
         sql.append(" sp_tel as userphone, ");
         sql.append(" sp_email as useremail, ");
         sql.append(" user_tel as clientphone, ");
         sql.append(" sp_info as spinfo ");
         sql.append(" from spinfo where id="+tempid+"");
      //   System.out.print(sql.toString());
    return executeQuery(sql.toString());
}
 // 修改的数据
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
  public static DBMap[] all_page_cnt(){
     String sql = new String("select count(*)as cnt from spinfo");
    return executeQuery(sql);
}
//
  public static int all_page_count(){
    cn.alcatel.wap.db.DBMap[] cnt=all_page_cnt();
     if(null==cnt){
       return tempcnt=0;
     }
     else{
         return tempcnt=Integer.parseInt(cnt[0].get("cnt").toString());
     }
}

// 显示的总页数
  public static int get_pagecnt(){
     int temp=all_page_count();
     if((temp%pagecnt)==0){
        return temp/pagecnt;
     }
     else{
        return temp/pagecnt+1;
     }
}

// 查询某页显示的数据
   public static DBMap[] get_page_info(int pagestart){
        StringBuffer sql = new StringBuffer(" select id as id,");
             sql.append(" sp_name as spname, ");
             sql.append(" user_name as username, ");
             sql.append(" sp_tel as userphone, ");
             sql.append(" sp_email as useremail, ");
             sql.append(" user_tel as clientphone, ");
             sql.append(" sp_info as spinfo ");
             sql.append(" from spinfo  ");
             sql.append(" order by id asc ");
             sql.append(" limit "+pagestart+","+pagecnt+" ");
      //     System.out.println(sql);
        return executeQuery(sql.toString());
   }
   //
   public static DBMap[] listSp(){
       StringBuffer sql = new StringBuffer(" select * from spinfo");
       return executeQuery(sql.toString());
  }


//删除sp数据
  public static int  delete_sp(int id) {
     StringBuffer sql = new StringBuffer("delete from spinfo where id="+id+" ");
     return executeUpdate(sql.toString());
  }
// 修改SP数据
  public static int  modify_sp(int id,String spname,String username,
                            String userphone,String useremail,String clientphone,
                            String spinfo) {
     StringBuffer sql = new StringBuffer(" update spinfo ");
    sql.append(" set sp_name='"+spname+"', ");
    sql.append(" user_name='"+username+"',");
    sql.append(" sp_tel='"+userphone+"',");
    sql.append(" sp_email='"+useremail+"' ,");
    sql.append(" user_tel='"+clientphone+"',");
    sql.append(" sp_info='"+spinfo+"' ");
    sql.append(" where id="+id+" ");
     return executeUpdate(sql.toString());
  }
// 处理查询后需要修改的数据

  }
