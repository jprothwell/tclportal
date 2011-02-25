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


public class questionDao  extends BaseDAO {

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
  public questionDao() {
  }

//显示总条数
  public static DBMap[] all_page_cnt(){
     String sql = new String("select count(*)as cnt from question");
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
        StringBuffer sql = new StringBuffer(" select question.id,");
             sql.append(" y_content, ");
             sql.append(" y_contact, ");
             sql.append(" did, ");
             sql.append(" phonenum, ");
             sql.append(" country, ");
             sql.append(" rel, ");
             sql.append(" sdate ");
             sql.append(" from question left join location on ip=substring_index(ipnum,'.',3)  ");
             sql.append(" limit "+pagestart+","+pagecnt+" ");
      //     System.out.println(sql);
        return executeQuery(sql.toString());
   }
   //
   public static int  updateQ(int id,String info) {
     StringBuffer sql = new StringBuffer(" update question ");
     sql.append(" set rel='1',");
     sql.append(" info='"+info+"' ");
     sql.append(" where id="+id+" ");
      return executeUpdate(sql.toString());
   }
   //显示某一个数据
    public static DBMap[] get_modify_info(int id){
      StringBuffer sql = new StringBuffer(" select * ");
           sql.append(" from question where id="+id+"");
        //   System.out.print(sql.toString());
      return executeQuery(sql.toString());
  }
  }
