/*
 * Created on 2006-5-16
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.db;

import java.sql.Connection;

import javax.sql.DataSource;
import javax.naming.Context;
import javax.naming.InitialContext;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class DBPool{
	  private static boolean isInit_ = false;
	  private static Context oContext_ = null;
	  private static DataSource oDataSource_ = null;

	  public static String init() throws Exception{
	    if(!isInit_){
	      try{
	        oContext_ = new InitialContext();
	        oDataSource_ = (DataSource)oContext_.lookup(
	            "java:comp/env/jdbc/wapportal");
	        isInit_ = true;
	        return new String("database pool:successful!");
	      } catch(Exception e){
	        throw e;
	      }
	    }
	    return new String("database pool:failed!");
	  }

	  protected static Connection getConnection() throws Exception{
//	    Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
//	    String connectionUrl = "jdbc:sqlserver://localhost;database=wapportal;user=sa;password=0000";
//	    Connection con = DriverManager.getConnection(connectionUrl);
//	    return con;
	    Connection oConn = null;
	    try{
	      oConn = oDataSource_.getConnection();
	      if(oConn != null && oConn.isClosed()){
	        oConn = DBPool.getConnection();
	      }
	    } catch(Exception e){
	      throw e;
	    }
	    return oConn;
	  }
	}
