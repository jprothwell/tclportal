package com.android.shopping.util;


import java.util.Calendar;
import java.util.Date;

import kankan.wheel.widget.NumericWheelAdapter;
import kankan.wheel.widget.OnWheelChangedListener;
import kankan.wheel.widget.OnWheelScrollListener;
import kankan.wheel.widget.WheelView;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;

import com.android.shopping.R;

public class DateSet{
	 
	private static final String TAG = "DateSet";
	
	public interface DateDialogBackInfoListener {
		
		public void refreshActivity(CharSequence charSequence);
	}
	
	View layout_view;
	
	public DateDialogBackInfoListener backInfoListener;
	
	TextView tv;
	
	Context mContext;
	
	Calendar calendar;
	
	//年月日 枚举类型
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
	
	private Date dateValue;
	
	public DateSet(Context context,final DateDialogBackInfoListener backInfoListener, Date dateValue){
		this.mContext = context;
		this.backInfoListener = backInfoListener;
		this.dateValue = dateValue;
		
		//自定义布局
		LayoutInflater factory = LayoutInflater.from(mContext);
		// 得到自定义对话框
		layout_view = factory.inflate(R.layout.date_set_layout, null);
		tv = (TextView)layout_view.findViewById(R.id.time_title);
		String date = DateUtil.dateAndWeek(dateValue,mContext);
		
		
		calendar = Calendar.getInstance();
		calendar.setTime(dateValue); 
		int year =  calendar.get(Calendar.YEAR);
		int month = calendar.get(Calendar.MONTH)+1;
		int day = calendar.get(Calendar.DAY_OF_MONTH);
		currentYear = year;
		currenMonth = month;
		currentDay = day;
		
		tv.setText(date);//设置选中日期，初始化为当前日期
		
		minYear = year-5;
		maxYear = year+5;
		maxDay = calendar.getActualMaximum(Calendar.DATE);
		
		initWheelView(R.id.year,minYear,maxYear,Tag.YEAR,year);
		initWheelView(R.id.month,minMonth,maxMonth,Tag.MONTH,month);
		initWheelView(R.id.day,minDay, maxDay,Tag.DAY,day);
		
	
		AlertDialog dialog = new AlertDialog.Builder(mContext)
		.setCancelable(false).setView(layout_view)// 设置自定义对话框
		.setPositiveButton("确定", 
				new DialogInterface.OnClickListener() // 设置事件监听
				{
					public void onClick(DialogInterface dialog,
							int whichButton) {
						
						backInfoListener.refreshActivity(tv.getText());
					}
				})
		.setNegativeButton("取消",
				new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog,
							int whichButton) {
						dialog.cancel();
					}
				}).create();
		dialog.show();// 显示
	}


	/**
	 * 
	 * @param view 布局文件 the layout of the view
	 * @param min 最小值  the value of min
	 * @param max 最大值 the value of max
	 * @param tag 栏目  the label of the view will show
	 * @param value 当前值 the value of choice
	 */
	private void initWheelView(int view, int min, int max, Tag tag,
			int value) {
		WheelView wheelView = (WheelView) layout_view.findViewById(view);
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
	//监听滑动效果
	OnWheelScrollListener scrollListener = new OnWheelScrollListener() {
		public void onScrollingStarted(WheelView wheel) {
			Log.d(TAG, "scrolling start");
		}
		public void onScrollingFinished(WheelView wheel) {
			Tag tag = (Tag)wheel.getTag();
			
			switch(tag){
				case YEAR:
					currentYear = minYear+wheel.getCurrentItem();
					//按年月改变每个月日期的滑动选项
					//按照月份，改变该月的天数
					calendar.set(Calendar.YEAR,currentYear); 
					calendar.set(Calendar.MONTH,currenMonth);//Java月份才0开始算，正好和数组吻合
					maxDay = calendar.getActualMaximum(Calendar.DATE);
					initWheelView(R.id.day,minDay, maxDay,Tag.DAY,currentDay);
					//设置时间
					calendar.set(Calendar.DATE,currentDay);
					tv.setText(DateUtil.dateAndWeek(calendar.getTime(),mContext));
					break;
				case MONTH:
					currenMonth = wheel.getCurrentItem();//按照数组，从0开始算
					//按照月份，改变该月的天数
					calendar.set(Calendar.YEAR,currentYear); 
					calendar.set(Calendar.MONTH,currenMonth);//Java月份才0开始算，正好和数组吻合
					maxDay = calendar.getActualMaximum(Calendar.DATE);
					initWheelView(R.id.day,minDay, maxDay,Tag.DAY,currentDay);
					//设置时间
					calendar.set(Calendar.DATE,currentDay);
					tv.setText(DateUtil.dateAndWeek(calendar.getTime(),mContext));
					break;
				case DAY:
					currentDay = 1+wheel.getCurrentItem();
					//设置时间
					calendar.set(Calendar.YEAR,currentYear); 
					calendar.set(Calendar.MONTH,currenMonth);//Java月份才0开始算，正好和数组吻合
					calendar.set(Calendar.DATE,currentDay);
					Date date = new Date();
					tv.setText(DateUtil.dateAndWeek(calendar.getTime(),mContext));
					break;
			}
			
			
		}
	};
	
	public OnWheelChangedListener changedListener = new OnWheelChangedListener() {
		public void onChanged(WheelView wheel, int oldValue, int newValue) {
			
		}
	};
//	public static String getDateSet(Context context){
//		
//		return null;
//	}

}
