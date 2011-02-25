package cn.alcatel.wap.db.dao;
import cn.alcatel.wap.db.BaseDAO;
import cn.alcatel.wap.db.DBMap;
import cn.alcatel.wap.db.DBInfo;
import java.util.Date;

public class userDao
    extends BaseDAO {
  ////////////////显示用户列表
  public DBMap[] userList() {
StringBuffer sql = new StringBuffer("select * ");
sql.append(" from ");
sql.append(" tb_user ");
return executeQuery(sql.toString());
}
  ////////////////显示用户单个信息
  public DBMap[] userInfo(int e) {
StringBuffer sql = new StringBuffer("select * ");
sql.append(" from tb_user ");
sql.append(" where user_id= ");
sql.append(e);
return executeQuery(sql.toString());
}

////////////////插入用户信息
  public int insertUser(String user_name,String user_pass,String role) {
     StringBuffer sql = new StringBuffer("insert into ");
     sql.append(" tb_user ");
     sql.append(" (user_name,user_pass,role) values('"+user_name+"','"+user_pass+"','"+role+"')");
    return executeUpdate(sql.toString());
  }
////////////修改用户信息
  public int updateUser(String role,int user_id) {
    StringBuffer sql = new StringBuffer("update tb_user set ");
    sql.append(" role='"+role);
    sql.append("' where user_id="+user_id);
   return executeUpdate(sql.toString());
 }
 ///////删除用户信息
 public int delUser(int user_id) {
  StringBuffer sql = new StringBuffer("delete  from tb_user ");
  sql.append(" where user_id="+user_id);
 return executeUpdate(sql.toString());
}
///检查用户是否存在
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
  ///检查用户和密码是否存在
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

///输出

}
