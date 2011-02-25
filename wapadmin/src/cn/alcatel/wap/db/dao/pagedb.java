package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.COMMON;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import cn.alcatel.wap.db.dao.Configuration;

/*********************
 * @author:abel
 * @author:09-08-14
 */


public class pagedb  extends BaseDAO {

// ÿҳ��ʾ20��
public static int pagecnt=Configuration.gamepage;
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
public static String screen=null;
public static int ringformat[]=null;
public static String tempring=null;
public static String[] tempringformat=null;
public static String videoformat=null;
public static int javasupport=0;

  public pagedb() {
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
//����ҳ���������
  public static int  insert(String pagename,String filename,int pagekind,
                            String language,String descrip,
                            String filepath) {
     StringBuffer sql = new StringBuffer("insert into ");
    sql.append("pageresource(name,");
    sql.append("file1,");
    sql.append("lg,");
    sql.append("kindid,");
    sql.append("info,");
    sql.append("urlName)");
    sql.append(" values('"+pagename+"','"
               +filename+"','"
               +language+"','"
               +pagekind+"','"
               +descrip+"','"
               +filepath+"')");
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
  public static DBMap[] all_page_cnt(){
     String sql = new String("select count(*)as cnt from pageresource");
    return executeQuery(sql);
}
// ��ʾ��������
  public static int all_page_count(){
    cn.alcatel.wap.db.DBMap[] cnt=all_page_cnt();
    if(null==cnt){
       return tempcnt=0;
    }
    else{
      return tempcnt=Integer.parseInt(cnt[0].get("cnt").toString());
    }
}

// ��ʾ����ҳ��
  public static int get_pagecnt(){
     int temp=all_page_count();
     if((temp%pagecnt)==0){
        return temp/pagecnt;
     }
     else{
        return temp/pagecnt+1;
     }
}

// ��ѯĳҳ��ʾ������
public static DBMap[] get_page_info(int pagestart){
     StringBuffer sql = new StringBuffer(" select id as id,name as na,");
          sql.append("file1 as fname,");
          sql.append("lg as lg,");
          sql.append("kindid as pagekind,");
          sql.append("info as descrip,");
          sql.append("urlName as url ");
          sql.append(" from pageresource  ");
          sql.append(" order by id asc    ");
          sql.append("  limit "+pagestart+","+pagecnt+" ");
     return executeQuery(sql.toString());
}
//ɾ������
  public static int  delete_page(int id) {
     StringBuffer sql = new StringBuffer("delete from pageresource where id="+id+" ");
     return executeUpdate(sql.toString());
  }
// ��ѯ��Ҫ�޸ĵ�����
public static DBMap[] get_modify_info(int tempid){
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
          sql.append(" where id="+tempid);
     return executeQuery(sql.toString());
}
   public static DBMap[] listpage(int tempid){
     StringBuffer sql = new StringBuffer(" select * from pageresource ");
          sql.append(" where id="+tempid);
     return executeQuery(sql.toString());
}

// �����ѯ����Ҫ�޸ĵ�����
   //�޸�����
public static int  modify_page(String pagename,String mypageName,
                                            int  pagekind, String language,
                                            String pagedescription,
                                             int pageid){
   StringBuffer sql = new StringBuffer(" update pageresource ");
  sql.append(" set name='"+pagename+"', ");
  sql.append(" file1='"+mypageName+"',");
  sql.append(" lg='"+language+"',");
  sql.append(" kindid="+pagekind+" ,");
  sql.append(" info='"+pagedescription+"'");
  sql.append(" where id="+pageid+" ");
  //System.out.println(sql.toString());
   return executeUpdate(sql.toString());
}
}
