package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;

public class userDao
    extends BaseDAO {
  ////////////////��ʾ�û��б�
  public DBMap[] userList() {
StringBuffer sql = new StringBuffer("select * ");
sql.append(" from ");
sql.append(" tb_user ");
return executeQuery(sql.toString());
}
  ////////////////��ʾ�û�������Ϣ
  public DBMap[] userInfo(int e) {
StringBuffer sql = new StringBuffer("select * ");
sql.append(" from tb_user ");
sql.append(" where user_id= ");
sql.append(e);
return executeQuery(sql.toString());
}

////////////////�����û���Ϣ
  public int insertUser(String user_name,String user_pass,String role) {
     StringBuffer sql = new StringBuffer("insert into ");
     sql.append(" tb_user ");
     sql.append(" (user_name,user_pass,role) values('"+user_name+"','"+user_pass+"','"+role+"')");
    return executeUpdate(sql.toString());
  }
////////////�޸��û���Ϣ
  public int updateUser(String role,int user_id) {
    StringBuffer sql = new StringBuffer("update tb_user set ");
    sql.append(" role='"+role);
    sql.append("' where user_id="+user_id);
   return executeUpdate(sql.toString());
 }
 ///////ɾ���û���Ϣ
 public int delUser(int user_id) {
  StringBuffer sql = new StringBuffer("delete  from tb_user ");
  sql.append(" where user_id="+user_id);
 return executeUpdate(sql.toString());
}
///����û��Ƿ����
  public boolean checkUser(String user_name) {
    String checksql = "select * from tb_user where user_name='" + user_name + "'";
    DBMap[] map = executeQuery(checksql);
    if (map!=null && map.length > 0) {
      return true;
    }
    else {
      return false;
    }
  }
  ///����û��������Ƿ����
  public String checkUserpass(String user_name,String user_pass) {
    String checksql = "select * from tb_user where user_name='" + user_name + "' and user_pass='"+user_pass+"'";
    DBMap[] map = executeQuery(checksql);
    if (map!=null && map.length > 0) {
      return map[0].get("role").toString();
    }
    else {
      return null;
    }
  }

///���

}
