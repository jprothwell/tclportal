package com.tcl.gamePortal.util;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * ��ȡ��ʷ����
 * @author shenkun
 *
 */
public class TableNameUtil {
	
	public static String getTableName(String startDate, String tablename, String htablename){
		long start1 = Long.parseLong(startDate.replaceAll("-", ""));
		long start = Long.parseLong(startDate.replaceAll("-", "").substring(0, 6));
		Date date = new Date();
		SimpleDateFormat  sf = new SimpleDateFormat("yyyyMM");
		long now = Long.parseLong(sf.format(date));
		SimpleDateFormat  sf1 = new SimpleDateFormat("yyyyMMdd");
		long today = Long.parseLong(sf1.format(date));
		if(start1==today){
			return tablename;
		}else{
			return htablename+start;
		}
	}

	public static Object getTableName(String startDate, String tablename) {
		long start = Long.parseLong(startDate.replaceAll("-", "").substring(0, 6));
		return tablename+start;
	}
}
