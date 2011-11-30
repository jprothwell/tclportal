package com.android.shopping.util;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
/**
 * 日期字符串转化处理类
 * @author kun.shen
 *
 */
public class DateUtil {
	
	//日期转换字符串
	public static String dateToString(Date date){
		if(date==null){
			return "";
		}else{
			SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm");
			return format.format(date);
		}
		
	}
	//str为空的时候，返回的是null,调用的时候，要判断是否为空
	public static Date stringToDate(String str){
		if("".equals(str)||str==null){
			return null;
		}else{
			SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm");
			Date date = null;
			try {
				System.out.println("ERROR-----------"+str);
				 date = format.parse(str);
			} catch (ParseException e) {
				e.printStackTrace();
				return date;
			}
			return date;
		}
	}
}
