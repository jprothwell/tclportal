package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;
import javax.servlet.http.HttpServletRequest;

public class mobileDao
    extends BaseDAO {
  //////����did�õ�UA
 public String didUa(int e) {
 StringBuffer sql = new StringBuffer("select ua ");
 sql.append(" from mobile ");
 sql.append(" where did=");
 sql.append(e);
 DBMap[] map =  executeQuery(sql.toString());
 if (map!=null && map.length > 0)return map[0].get("ua").toString();
 else return  "Alcatel-Tcl";
 }

 /////����UA��uamenu���ݱ����Ƿ����
 public boolean checkUamenu(String e) {
   StringBuffer sql = new StringBuffer("select * ");
 sql.append(" from uamenu ");
 sql.append(" where ua='");
 sql.append(e);
  sql.append("'");
   DBMap[] map = executeQuery(sql.toString());
   if (map!=null && map.length > 0) {
     return true;
   }
   else {
     return false;
   }
 }

 //////////����ua�õ���ҳ��ַ
 public String indexUrl(String e) {
 String urlName="/jsp/";
StringBuffer sql = new StringBuffer("select urlName,file1 ");
sql.append(" from mobile,pageresource ");
sql.append(" where mobile.ua='");
sql.append(e);
 sql.append("' and mobile.pageid=pageresource.id");
 //System.out.println("sql="+sql.toString());
DBMap[] map =  executeQuery(sql.toString());
if (map!=null && map.length > 0)urlName=urlName+ map[0].get("file1").toString();
else urlName=urlName+"homepage.jsp";
  return  urlName;
}
//////////����id�õ���Ŀ��ַ
public String menuUrl(int e) {
String urlName="/jsp/";
StringBuffer sql = new StringBuffer("select file1 ");
sql.append(" from menu,pageresource ");
sql.append(" where menu.id=");
sql.append(e);
sql.append(" and menu.pageid=pageresource.id");
DBMap[] map =  executeQuery(sql.toString());
if (map!=null && map.length > 0)urlName=urlName+ map[0].get("file1").toString();
else urlName=urlName+"images.jsp";
 return  urlName;
}


 /////����UA�����ݱ����Ƿ����
 public boolean checkUa(String e) {
   StringBuffer sql = new StringBuffer("select * ");
 sql.append(" from mobile ");
 sql.append(" where ua='");
 sql.append(e);
  sql.append("'");
   DBMap[] map = executeQuery(sql.toString());
   if (map!=null && map.length > 0) {
     return true;
   }
   else {
     return false;
   }
 }
/////////////////////
 /////����LG�����ݱ����Ƿ����
public boolean checkLg(String ua,String lg) {
  StringBuffer sql = new StringBuffer("select * ");
sql.append(" from uamenu ");
sql.append(" where lg='");
sql.append(lg);
sql.append("' and ua='");
sql.append(ua);
sql.append("'");
  DBMap[] map = executeQuery(sql.toString());
  if (map!=null && map.length > 0) {
    return true;
  }
  else {
    return false;
  }
}
/////////////////////

}
