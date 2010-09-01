package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import cn.alcatel.wap.db.Util;
import java.util.Date;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

public class ipgoDao
    extends BaseDAO {
  /////�ж�ip�Ƿ���ת�������ת������ת��ַ�����򷵻ؿ�
public String getipUrl(HttpServletRequest request){
     String ipnum = Util.getIp(request);
     String uaname=Util.getUa(request);
     int e=ipnum.lastIndexOf(".");
     ipnum=ipnum.substring(0,e);
    //System.out.println("ipnum="+ipnum);
    String sql = "select urlname from location,indexmenu where location.country=indexmenu.country and ip='"+ipnum+"' and uaname='"+uaname+"'";
    DBMap[] map = executeQuery(sql);
    if (map!=null && map.length > 0) {
      return map[0].get("urlname").toString();
      //return "index.jsp";
    }
    else {
      return null;
    }
 }
 /////�ж�ip�Ƿ���ת�������ת������ת��ַ�����򷵻ؿ�
public boolean judgeCountry(HttpServletRequest request){
   String ipnum = Util.getIp(request);
   String lgnum = Util.getAcceptLanguage(request);
   //System.out.println("ipnum="+ipnum);
   int e=ipnum.lastIndexOf(".");
   ipnum=ipnum.substring(0,e);
  String sql = "select country from location where country='China' and  ip='"+ipnum+"'";
  DBMap[] map = executeQuery(sql);
  if (map!=null && map.length > 0) {
    return true;
  }
  else {
    return false;
  }
}
/////�ж�ip�Ƿ�ӡ�������ǵģ������ת������ת��ַ�����򷵻ؿ�
public boolean judgeIndonesia(HttpServletRequest request){
   String ipnum = Util.getIp(request);
   String lgnum = Util.getAcceptLanguage(request);
   //System.out.println("ipnum="+ipnum);
   int e=ipnum.lastIndexOf(".");
   ipnum=ipnum.substring(0,e);
  String sql = "select country from location where country='Indonesia' and  ip='"+ipnum+"'";
  DBMap[] map = executeQuery(sql);
  if (map!=null && map.length > 0) {
    return true;
  }
  else {
    return false;
  }
}


 ////����ip�õ���������
// public static String getCountry(HttpServletRequest request){
// String ipnum = Util.getIp(request);
// DBManager manager = new DBManager();
//     String sqlStr="select * from ipdata where ipnum="+ipnum+" and dirname=1";
//     DBRowSet ret = manager.search(sqlStr, null);
//     if (ret==null  || ret.getRowCount()==0) {
//          return null;
//        }
//        else {
//          return ret.getString(0,"country");
//        }
//}
 ///////������ת��¼

}
