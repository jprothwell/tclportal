package com.android.shopping.util;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
/**
 * �����ַ���ת��������
 * @author kun.shen
 *
 */
public class DateUtil {
	
	//����ת���ַ���
	public static String dateToString(Date date){
		if(date==null){
			return "";
		}else{
			SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm");
			return format.format(date);
		}
		
	}
	//strΪ�յ�ʱ�򣬷��ص���null,���õ�ʱ��Ҫ�ж��Ƿ�Ϊ��
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
