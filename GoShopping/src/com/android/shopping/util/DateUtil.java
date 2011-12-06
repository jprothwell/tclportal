package com.android.shopping.util;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import com.android.shopping.R;

import android.content.Context;
import android.util.Log;
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
			SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
			return format.format(date);
		}
	}
	
	public static String timeToString(Date date){
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

	public static String dateAndWeek(Date date, Context context) {
		Calendar calendar = Calendar.getInstance();
		calendar.setTime(date); 
		int week = calendar.get(calendar.DAY_OF_WEEK);
		String day = dateToString(date);
		String day_of_week = "";
		Log.d("DateUtil", "week::"+week);
			switch(week){
				case 2:
					day_of_week = context.getString(R.string.one_day_of_week);
					break;
				case 3:
					day_of_week = context.getString(R.string.two_day_of_week);
					break;
				case 4:
					day_of_week = context.getString(R.string.three_day_of_week);
					break;
				case 5:
					day_of_week = context.getString(R.string.four_day_of_week);
					break;
				case 6:
					day_of_week = context.getString(R.string.five_day_of_week);
					break;
				case 7:
					day_of_week = context.getString(R.string.six_day_of_week);
					break;
				case 1:
					day_of_week = context.getString(R.string.seven_day_of_week);
					break;
			}
	 return day + "  " + day_of_week;
	}

	public static CharSequence dateAndWeek(Date date, String[] weekDays) {
		Calendar calendar = Calendar.getInstance();
		calendar.setTime(date); 
		int week = calendar.get(calendar.DAY_OF_WEEK);
		String day = dateToString(date);
		String day_of_week = "";
		Log.d("DateUtil", "week::"+week);
			switch(week){
				case 2:
					day_of_week = weekDays[0];
					break;
				case 3:
					day_of_week = weekDays[1];
					break;
				case 4:
					day_of_week = weekDays[2];
					break;
				case 5:
					day_of_week = weekDays[3];
					break;
				case 6:
					day_of_week = weekDays[4];
					break;
				case 7:
					day_of_week = weekDays[5];
					break;
				case 1:
					day_of_week = weekDays[6];
					break;
			}
	 return day + "  " + day_of_week;
	}

}
