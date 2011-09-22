package com.tcl.onetouch.dao;

import java.sql.SQLException;
import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;
import org.springframework.orm.ibatis.SqlMapClientCallback;

import com.ibatis.sqlmap.client.SqlMapExecutor;
import com.tcl.onetouch.domain.Gameresouce;

public class GameresouceDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(GameresouceDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findGameresouceCount",map);
	}

	public List<Gameresouce> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findGameresouceList",map);
	}

	public void save(Gameresouce gameresouce) {
		getSqlMapClientTemplate().insert("saveGameresouce", gameresouce);
	}

	public void update(Gameresouce gameresouce) {
		getSqlMapClientTemplate().update("updateGameresouce",gameresouce);
	}

	public Gameresouce queryGameresouce(int id) {
		return (Gameresouce)getSqlMapClientTemplate().queryForObject("queryGameresouce", id);
	}

	public List<Gameresouce> findAll() {
		return  getSqlMapClientTemplate().queryForList("findGameresouceAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deleteGameresouce", id);
	}

	public List<Gameresouce> findSequenceList(Map map) {
		return getSqlMapClientTemplate().queryForList("findSequenceList",map);
	}

	public void update(Map map) {
		getSqlMapClientTemplate().update("updateGameresoucePriority", map);
	}

	public List<Gameresouce> findGameByDid(Map map) {
		return getSqlMapClientTemplate().queryForList("findGameByDid",map);
	}

	public List<Gameresouce> findGameByGameAndDid(Map map) {
		return getSqlMapClientTemplate().queryForList("findGameByGameAndDid",map);
	}

	public void batchCreate(List<Gameresouce> gameresouces) {
		batchCreate(gameresouces, "saveGameresouce");
	}
	
	 protected void batchCreate(final List<Gameresouce> gameresouces, final String statement) {
		 
		 getSqlMapClientTemplate().execute(
				 new SqlMapClientCallback() {
			            public Object doInSqlMapClient(SqlMapExecutor executor) throws SQLException {    
			                executor.startBatch();
			                int batchNum = 0;
			                for (Gameresouce gameresouce : gameresouces) {               
			                    executor.insert(statement, gameresouce); // statement在*MapSql.xml一条语句的id   
			                    batchNum++;
			                    if(batchNum==200){
			                    	executor.executeBatch();   
			                    	batchNum=0;
			                    }
			                }  
			                return executor.executeBatch();   
			                
			            }
			        }
				 ); 
	 }
	 
	 //wap调用
		public Gameresouce queryGameresouce(Map map) {
			return (Gameresouce)getSqlMapClientTemplate().queryForObject("queryGameresouceWap", map);
		}

		public List<Gameresouce> findGameByCountryAndDid(Map map) {
			return getSqlMapClientTemplate().queryForList("findGameByCountryAndDid", map);
		}
}
