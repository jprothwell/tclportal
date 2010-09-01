/*
 * Created on 2006-5-16
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.funstar.wap.db;

import java.sql.*;

/**
 * @author feel
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class DBRelease {
	protected static ResultSet release(ResultSet rs) {
		if (rs != null) {
			try {
				rs.close();
			} catch (Exception e) {
			}
			rs = null;
		}
		return rs;
	}

	protected static PreparedStatement release(PreparedStatement pstmt) {
		if (pstmt != null) {
			try {
				pstmt.close();
			} catch (Exception e) {
			}
			pstmt = null;
		}
		return pstmt;
	}

	protected static Statement release(Statement stmt) {
		if (stmt != null) {
			try {
				stmt.close();
			} catch (Exception e) {
			}
			stmt = null;
		}
		return stmt;
	}

	protected static Connection release(Connection conn) {
		if (conn != null) {
			try {
				conn.close();
			} catch (Exception e) {
			}
			conn = null;
		}
		return conn;
	}
}