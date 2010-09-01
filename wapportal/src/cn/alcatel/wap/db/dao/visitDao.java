package cn.alcatel.wap.db.dao;

import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;

public class visitDao
    extends BaseDAO {
//  public visitDao(String name) {
//    super(name);
//  }
/////////////显示这个月的访问数据
  public DBMap[] visitInfo(int e,int b,String a) {
    String addDb = getDBName();
    if(a!=null && a.length() > 0)addDb=a;
StringBuffer sql = new StringBuffer("select * from ");
sql.append(addDb);
sql.append(" limit ");
sql.append(e);
sql.append(" , ");
sql.append(b);
return executeQuery(sql.toString());
}

/////////////显示这个月的下载数据
  public DBMap[] downloadInfo(int e ,int b,String a) {
    String addDb = getDMName();
    if(a!=null && a.length() > 0)addDb=a;
StringBuffer sql = new StringBuffer("select * from ");
sql.append(addDb);
sql.append(" limit ");
sql.append(e);
sql.append(" , ");
sql.append(b);
return executeQuery(sql.toString());
}

////////////////插入统计记录
  public int insert(String menuname,String phonenum,String srel,String statua,String ipnum) {
     String addDb = getDBName();
     if (!checkDbVisit())createTable();
     StringBuffer sql = new StringBuffer("insert into ");
     sql.append(addDb);
     sql.append("(menuname,phonenum,srel,statua,ipnum) values('"+menuname+"','"+phonenum+"','"+srel+"','"+statua+"','"+ipnum+"')");
    return executeUpdate(sql.toString());
  }
/////////////////////////得到这个月的数据表名称
  private String getDBName() {
    Date date = new Date(System.currentTimeMillis());
    int yearnum = 1900 + date.getYear();
    int monthnum = 1 + date.getMonth();
    String addDb = null;
    if (monthnum < 10) {
      addDb = "visit" + String.valueOf(yearnum) + "0" + String.valueOf(monthnum);
    }
    else {
      addDb = "visit" + String.valueOf(yearnum) + String.valueOf(monthnum);
    }
    //System.out.println("addDb="+addDb);
    return addDb;
  }

////////////////////得到创建数据库sql语句
  private void createTable() {
    String addDb=getDBName();
    StringBuffer sql = new StringBuffer("CREATE TABLE ");
    sql.append(addDb);
    sql.append(" (id bigint(8) NOT NULL auto_increment,");
    sql.append(" menuname varchar(50) default NULL,");
    sql.append(" statua varchar(50) default NULL,");
    sql.append(" phonenum varchar(50) default NULL,");
    sql.append(" srel varchar(10) default NULL,ipnum varchar(50) default NULL,");
    sql.append(" sdate timestamp(14) NOT NULL,");
    sql.append(" PRIMARY KEY  (id)");
    sql.append(" ) TYPE=MyISAM;");
   //System.out.print(sql.toString());
   executeUpdate(sql.toString());
  }
  ////////////////////////检查数据表是否存在
  private boolean checkDbVisit() {
    String addDb = getDBName();
    String checksql = "show tables like '" + addDb + "'";
    DBMap[] map = executeQuery(checksql);
    if (map!=null && map.length > 0) {
      return true;
    }
    else {
      return false;
    }
  }
//////////////******对下载统计*****/////////////
  /////////////////////////得到这个月的下载数据表名称
private String getDMName() {
  Date date = new Date(System.currentTimeMillis());
  int yearnum = 1900 + date.getYear();
  int monthnum = 1 + date.getMonth();
  String addDb = null;
  if (monthnum < 10) {
    addDb = "download" + String.valueOf(yearnum) + "0" + String.valueOf(monthnum);
  }
  else {
    addDb = "download" + String.valueOf(yearnum) + String.valueOf(monthnum);
  }
  //System.out.println("addDb="+addDb);
  return addDb;
}
////////////////////////检查下载统计数据表是否存在
private boolean checkDMVisit() {
  String addDm = getDMName();
  String checksql = "show tables like '" + addDm + "'";
  DBMap[] map = executeQuery(checksql);
  if (map!=null && map.length > 0) {
    return true;
  }
  else {
    return false;
  }
}
////////////////////得到创建下载数据库sql语句
  private void createDMTable() {
    String addDm = getDMName();
    StringBuffer sql = new StringBuffer("CREATE TABLE ");
    sql.append(addDm);
    sql.append(" (id bigint(8) NOT NULL auto_increment,");
    sql.append(" menu1 varchar(100) default NULL,");
    sql.append(" menu2 varchar(100) default NULL,");
    sql.append(" resourcename varchar(200) default NULL,");
    sql.append(" statua varchar(100) default NULL,");
    sql.append(" phonenum varchar(50) default NULL,");
    sql.append(" srel varchar(10) default NULL,ipnum varchar(50) default NULL,");
    sql.append(" sdate timestamp(14) NOT NULL,");
    sql.append(" menuFlag bit(1) NOT NULL default '\0',");
    sql.append(" spname varchar(200) default NULL,");
    sql.append(" PRIMARY KEY  (id)");
    sql.append(" ) TYPE=MyISAM;");
   //System.out.print(sql.toString());
   executeUpdate(sql.toString());
  }
////////////////插入统计记录
  public int insertDM(String menu1,String resourcename,String phonenum,String srel,String statua,String ipnum,String spname) {
     String addDm = getDMName();
     if (!checkDMVisit())createDMTable();
    StringBuffer sql = new StringBuffer("insert into ");
     sql.append(addDm);
     sql.append("(menu1,resourcename,phonenum,srel,statua,ipnum,spname) values('"+menu1+"','"+resourcename+"','"+phonenum+"','"+srel+"','"+statua+"','"+ipnum+"','"+spname+"')");
     //System.out.print(sql.toString());
     return executeUpdate(sql.toString());
  }
////////////////插入head
//  public int insertHead(String ipname,String lgname,String headname,String version) {
//     //System.out.println("insert into "+addDm+"(menu1,menu2,resourcename,phonenum,srel,statua,ipnum,menuFlag,spname) values('"+menu1+"','"+menu2+"','"+resourcename+"','"+phonenum+"','"+srel+"','"+statua+"','"+ipnum+"',"+menuFlag+",'"+spname+"')");
//     StringBuffer sql = new StringBuffer("insert into gethead");
//     sql.append("(ipname,lgname,headname,version) values('"+ipname+"','"+lgname+"','"+headname+"','"+version+"')");
//    return executeUpdate(sql.toString());
//  }

////////////////////******对下载统计*****end/////////////////////////////////
}
