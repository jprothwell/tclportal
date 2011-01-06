package com.tclPaypal.util;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class DateUtil {
	
	//当天
	 public static String getCurrentDate(){
	        return new SimpleDateFormat("yyyy-MM-dd").format(new Date());
	    }
	 //本月第一天
	 public static String getTheMonthFirstDay(){
		 Calendar cal = Calendar.getInstance();  
		 cal.set(Calendar.DATE,1); 
		 Date  d = cal.getTime();
		 return new SimpleDateFormat("yyyy-MM-dd").format(d);
	 }
	 public static Date getTomorrow(String endDate) throws ParseException{
			Calendar   cal   =   Calendar.getInstance();
			cal.setTime(new SimpleDateFormat("yyyy-MM-dd").parse(endDate));
			cal.add(Calendar.DAY_OF_YEAR,+1);
			return cal.getTime();
	 }
}
