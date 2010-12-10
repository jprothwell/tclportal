package com.tcl.wapStatistic.dao;

import java.sql.SQLException;
import java.util.List;

import org.springframework.orm.ibatis.SqlMapClientCallback;

import com.ibatis.sqlmap.client.SqlMapExecutor;
import com.tcl.wapStatistic.domain.Location;

public class LocationDAO extends BaseDao{

	public List<Location> findLocationCountryIsNull() {
		return getSqlMapClientTemplate().queryForList("findLocationCountryIsNull");
	}

	public void updateLocation(List<Location> listLocation) {
		batchCreate(listLocation, "updateLocation");
	}
   
 protected void batchCreate(final List<Location> locations, final String statement) {
		 
		 getSqlMapClientTemplate().execute(
				 new SqlMapClientCallback() {
			            public Object doInSqlMapClient(SqlMapExecutor executor) throws SQLException {    
			                executor.startBatch();
			                int batchNum = 0;
			                for (Location location : locations) { 
			                    executor.update(statement, location); // statement在*MapSql.xml一条语句的id   
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

public void updateLocationSingle(Location location) {
	getSqlMapClientTemplate().update("updateLocation", location);
}
}