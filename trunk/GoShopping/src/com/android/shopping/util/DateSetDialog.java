package com.android.shopping.util;

import java.util.Calendar;
import java.util.Date;

import kankan.wheel.widget.NumericWheelAdapter;
import kankan.wheel.widget.OnWheelChangedListener;
import kankan.wheel.widget.OnWheelScrollListener;
import kankan.wheel.widget.WheelView;
import android.app.AlertDialog;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.android.shopping.R;

public class DateSetDialog extends AlertDialog{
	
	private static final String TAG = "DateSetDialog";
	
	TextView tv;
	
	Calendar calendar;
	
	//������ ö������
	final String YEAR = "year";
	final String MONTH = "month";
	final String DAY = "day";
	enum Tag{
		YEAR,MONTH,DAY
	}
	private int minYear;
	private int maxYear;
	private int minMonth = 1;
	private int maxMonth = 12;
	private int minDay = 1;
	private int maxDay;
	
	private int currentYear;
	
	private int currenMonth;
	
	private int currentDay;
	
	String[] weekDays = new String[7];
	public DateSetDialog(Context context) {
		super(context);
		weekDays[0] = context.getString(R.string.one_day_of_week);
		weekDays[1] = context.getString(R.string.two_day_of_week);
		weekDays[2] = context.getString(R.string.three_day_of_week);
		weekDays[3] = context.getString(R.string.four_day_of_week);
		weekDays[4] = context.getString(R.string.five_day_of_week);
		weekDays[5] = context.getString(R.string.six_day_of_week);
		weekDays[6] = context.getString(R.string.seven_day_of_week);
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		 setContentView(R.layout.date_set_layout);
		 tv = (TextView)findViewById(R.id.time_title);
		 CharSequence date = DateUtil.dateAndWeek(new Date(),weekDays);
		
			calendar = Calendar.getInstance();
			calendar.setTime(new Date()); 
			int year =  calendar.get(Calendar.YEAR);
			int month = calendar.get(Calendar.MONTH)+1;
			int day = calendar.get(Calendar.DAY_OF_MONTH);
			
			
			tv.setText(date);//����ѡ�����ڣ���ʼ��Ϊ��ǰ����
			
			minYear = year-5;
			maxYear = year+5;
			maxDay = calendar.getActualMaximum(Calendar.DATE);
			
			initWheelView(R.id.year,minYear,maxYear,Tag.YEAR,year);
			initWheelView(R.id.month,minMonth,maxMonth,Tag.MONTH,month);
			initWheelView(R.id.day,minDay, maxDay,Tag.DAY,day);
	}

	
	/**
	 * 
	 * @param view �����ļ� the layout of the view
	 * @param min ��Сֵ  the value of min
	 * @param max ���ֵ the value of max
	 * @param tag ��Ŀ  the label of the view will show
	 * @param value ��ǰֵ the value of choice
	 */
	private void initWheelView(int view, int min, int max, Tag tag,
			int value) {
		WheelView wheelView = (WheelView)findViewById(view);
		wheelView.setTag(tag);
		wheelView.setAdapter(new NumericWheelAdapter(min, max));
		wheelView.addChangingListener(changedListener);
		wheelView.addScrollingListener(scrollListener);
		wheelView.setCurrentItem(value-min);
		wheelView.setCyclic(true);
		
		
	}
	private void addChangingListener(final WheelView wheel) {
		wheel.addChangingListener(new OnWheelChangedListener() {
			public void onChanged(WheelView wheel, int oldValue, int newValue) {
				
			}
		});
	}
	//��������Ч��
	OnWheelScrollListener scrollListener = new OnWheelScrollListener() {
		public void onScrollingStarted(WheelView wheel) {
			Log.d(TAG, "scrolling start");
		}
		public void onScrollingFinished(WheelView wheel) {
//			Tag tag = (Tag)wheel.getTag();
//			switch(tag){
//				case YEAR:
//					Log.d(TAG,"current year:"+wheel.getCurrentItem());
//				case MONTH:
//					Log.d(TAG,"current month:"+wheel.getCurrentItem());
//				case DAY:
//					Log.d(TAG,"current day:"+wheel.getCurrentItem());
//			}
			
		}
	};
	
	public OnWheelChangedListener changedListener = new OnWheelChangedListener() {
		public void onChanged(WheelView wheel, int oldValue, int newValue) {
			Tag tag = (Tag)wheel.getTag();
		
			switch(tag){
				case YEAR:
					currentYear = minYear+wheel.getCurrentItem();
					//�����¸ı�ÿ�������ڵĻ���ѡ��
					//�����·ݣ��ı���µ�����
					calendar.set(Calendar.YEAR,currentYear); 
					calendar.set(Calendar.MONTH,currenMonth);//Java�·ݲ�0��ʼ�㣬���ú������Ǻ�
					maxDay = calendar.getActualMaximum(Calendar.DATE);
					initWheelView(R.id.day,minDay, maxDay,Tag.DAY,currentDay);
					//����ʱ��
					calendar.set(Calendar.DATE,currentDay);
					tv.setText(DateUtil.dateAndWeek(calendar.getTime(),weekDays));
					break;
				case MONTH:
					currenMonth = wheel.getCurrentItem();//�������飬��0��ʼ��
					//�����·ݣ��ı���µ�����
					calendar.set(Calendar.YEAR,currentYear); 
					calendar.set(Calendar.MONTH,currenMonth);//Java�·ݲ�0��ʼ�㣬���ú������Ǻ�
					maxDay = calendar.getActualMaximum(Calendar.DATE);
					initWheelView(R.id.day,minDay, maxDay,Tag.DAY,currentDay);
					//����ʱ��
					calendar.set(Calendar.DATE,currentDay);
					tv.setText(DateUtil.dateAndWeek(calendar.getTime(),weekDays));
					break;
				case DAY:
					currentDay = 1+wheel.getCurrentItem();
					//����ʱ��
					calendar.set(Calendar.YEAR,currentYear); 
					calendar.set(Calendar.MONTH,currenMonth);//Java�·ݲ�0��ʼ�㣬���ú������Ǻ�
					calendar.set(Calendar.DATE,currentDay);
					Date date = new Date();
					tv.setText(DateUtil.dateAndWeek(calendar.getTime(),weekDays));
					break;
			}
			
		}
	};
}
