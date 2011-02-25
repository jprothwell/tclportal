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


public class location  extends BaseDAO {

// ÿҳ��ʾ20��
public static int pagecnt=Configuration.newpage;
// ��ʾ��������
public static int tempcnt=0;

// id
public static int tempid=0;

// ��Ҫ�޸ĵ��ֶ�
public static String name=null;
public static String ua=null;
public static String did=null;
public static int wapinfo=0;
public static int netinfo=0;
public static int screen=0;
// ��������
public static int gamecount=0;

public static int ringformat[]=null;
public static String tempring=null;
public static String[] tempringformat=null;
public static String tempvideo=null;
public static String[] tempvideoformat=null;
public static String videoformat=null;
public static int javasupport=0;

  public location() {
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
//�����ն˵��������
  public static int  insert(String newname,String lg,String newinfo,
                            String viewpathsql,String nowtime) {
     StringBuffer sql = new StringBuffer("insert into ");
    sql.append("newsresource(name,");
    sql.append("info,");
    sql.append("images,");
    sql.append("lg,");
    sql.append("sdate)");
    sql.append(" values('"+newname+"','"+newinfo+"','"+viewpathsql +"','"
                 +lg+"','"
                 +nowtime+"')");
     return executeUpdate(sql.toString());
  }
  //������е�����
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
//��ʾ������
  public static DBMap[] all_new_cnt(){
     String sql = new String("select count(*)as cnt from location ");
    return executeQuery(sql);
}
// ��ʾ��������
  public static int all_new_count(){
    cn.alcatel.wap.db.DBMap[] cnt=all_new_cnt();
    if(null==cnt){
      return 0;
    }
    else{
       return tempcnt=Integer.parseInt(cnt[0].get("cnt").toString());
    }
}

// ��ʾ����ҳ��
  public static int get_pagecnt(){
     int temp=all_new_count();
     if((temp%pagecnt)==0){
        return temp/pagecnt;
     }
     else{
        return temp/pagecnt+1;
     }
}

// ��ѯĳҳ��ʾ������
public static DBMap[] get_page_info(int pagestart){
     StringBuffer sql = new StringBuffer(" select id as id,");
          sql.append(" ip as ip, ");
          sql.append(" country as country, ");
          sql.append(" city as city, ");
          sql.append(" operator as operator, ");
          sql.append(" description as description ");
          sql.append(" from location  ");
          sql.append(" order by id asc ");
          sql.append(" limit "+pagestart+","+pagecnt+" ");
     return executeQuery(sql.toString());
}
// ��ѯ���еĻ���
   public static DBMap[] get_model_info(){
     StringBuffer sql = new StringBuffer(" select id as id,");
          sql.append(" ua as ua ");
          sql.append(" from mobile  ");
          sql.append(" order by id asc ");
     return executeQuery(sql.toString());
}
// ��ѯsp
    public static DBMap[] get_sp_info(){
      StringBuffer sql = new StringBuffer(" select id as id,");
           sql.append(" sp_name as spname ");
           sql.append(" from spinfo  ");
           sql.append(" order by id asc ");
      return executeQuery(sql.toString());
 }

//ɾ������
  public static int  delete_location(int id) {
     StringBuffer sql = new StringBuffer("delete from location where id="+id+" ");
     return executeUpdate(sql.toString());
  }
// ��ѯ��Ҫ�޸ĵ�����
public static DBMap[] get_modify_info(int tempid){
     StringBuffer sql = new StringBuffer(" select id as id,");
     sql.append(" name as na, ");
     sql.append(" info as info, ");
     sql.append(" images as picdir, ");
     sql.append(" lg as lg, ");
     sql.append(" rel as status, ");
     sql.append(" sdate as sdate ");
     sql.append(" from newsresource  ");
     sql.append(" where id="+tempid+"   ");
     System.out.print(sql.toString());
     return executeQuery(sql.toString());
}
// �����ѯ����Ҫ�޸ĵ�����

 //�޸�����
 public static int  new_modify(String newname,String lg,
                               String newinfo,String viewpathsql,
                               String nowTime,int newid){
    StringBuffer sql = new StringBuffer(" update newsresource ");
   sql.append(" set name='"+newname+"', ");
   sql.append(" info='"+newinfo+"',");
   sql.append(" lg='"+lg+"',");
   sql.append(" sdate='"+nowTime+"' ,");
   sql.append(" images='"+viewpathsql+"'");
   sql.append(" where id="+newid+" ");
    return executeUpdate(sql.toString());
 }
// ������������
 public static DBMap[] all_model_cnt(String ua){
   String sql = new String("select count(*)as modelcnt from mobile where ua='"+ua+"'");
  return executeQuery(sql);
}
// ��ʾ��������
 public static void all_model_count(String ua){
     cn.alcatel.wap.db.DBMap[] cntmodel=all_model_cnt(ua);
     gamecount=Integer.parseInt(cntmodel[0].get("modelcnt").toString());
}
  }
