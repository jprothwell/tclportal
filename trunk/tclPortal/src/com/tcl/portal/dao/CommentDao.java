package com.tcl.portal.dao;

import java.sql.SQLException;
import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;
import org.springframework.orm.ibatis.SqlMapClientCallback;

import com.ibatis.sqlmap.client.SqlMapExecutor;
import com.tcl.portal.domain.Comment;
import com.tcl.portal.domain.Gameresouce;

public class CommentDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(CommentDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findCommentCount",map);
	}

	public List<Comment> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findCommentList",map);
	}

	public void delete(String[] ids) {
		batchDelete("commonetDelete",ids);
	}
	
 protected void batchDelete(final String delete, final String[] ids) {
		 
		 getSqlMapClientTemplate().execute(
				 new SqlMapClientCallback() {
			            public Object doInSqlMapClient(SqlMapExecutor executor) throws SQLException {    
			                executor.startBatch();
			                int batchNum = 0;
			                for (String id : ids) {   
			                	executor.delete(delete, Integer.parseInt(id));
			                    batchNum++;
			                    if(batchNum==20){
			                    	executor.executeBatch();   
			                    	batchNum=0;
			                    }
			                }  
			                return executor.executeBatch();   
			                
			            }
			        }
				 ); 
	 }

	public void update(String[] ids, String flag) {
		if("1".equals(flag)){
			batchUpdate("commonetUpdate1",ids);
		}else{
			batchUpdate("commonetUpdate0",ids);
		}
	}
	
	protected void batchUpdate(final String update, final String[] ids) {
		 
		 getSqlMapClientTemplate().execute(
				 new SqlMapClientCallback() {
			            public Object doInSqlMapClient(SqlMapExecutor executor) throws SQLException {    
			                executor.startBatch();
			                int batchNum = 0;
			                for (String id : ids) {   
			                	executor.update(update, Integer.parseInt(id));
			                    batchNum++;
			                    if(batchNum==20){
			                    	executor.executeBatch();   
			                    	batchNum=0;
			                    }
			                }  
			                return executor.executeBatch();   
			                
			            }
			        }
				 ); 
	 }
}
