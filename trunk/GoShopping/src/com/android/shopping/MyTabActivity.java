package com.android.shopping;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

public class MyTabActivity extends Activity{
	
	private final static String TAG = "MyTabActivity";

	private RelativeLayout list,calendar,favorite,setting;
	
	
	private TextView listText,calendarText,favoriteText,settingText;
	
	private ImageView list_image,calendar_image,favorite_image,setting_image;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.myhost);
		list = (RelativeLayout)findViewById(R.id.list);
		calendar = (RelativeLayout)findViewById(R.id.calendar);
		favorite = (RelativeLayout)findViewById(R.id.favorite);
		setting = (RelativeLayout)findViewById(R.id.setting);
		
		listText = (TextView)findViewById(R.id.list_text);
		calendarText = (TextView)findViewById(R.id.calendar_text);
		favoriteText = (TextView)findViewById(R.id.favorite_text);
		settingText = (TextView)findViewById(R.id.setting_text);
		
		list.setOnClickListener(new TabListener(list));
		calendar.setOnClickListener(new TabListener(calendar));
		favorite.setOnClickListener(new TabListener(favorite));
		setting.setOnClickListener(new TabListener(setting));
		
//		list_image = (ImageView)findViewById(R.id.list_image);
//		calendar_image = (ImageView)findViewById(R.id.calendar_image);
	}

	class TabListener implements OnClickListener{
		
		RelativeLayout layout;
		
		public TabListener(RelativeLayout layout) {
			this.layout = layout;
		}

		@Override
		public void onClick(View view) {
//			switch(view.getId()){
//				case R.id.list:
//					
//					list_image.setBackgroundResource(R.drawable.tab_address_pressed);
//					calendar_image.setBackgroundResource(R.drawable.tab_find_frd_normal);
//					Log.d(TAG, "listView");
//				case R.id.calendar:
//					
//					calendar_image.setBackgroundResource(R.drawable.tab_find_frd_pressed);
//					list_image.setBackgroundResource(R.drawable.tab_address_normal);
//					Log.d(TAG, "calendarView");
//			}
			if(list == (RelativeLayout)view){
				list_image = (ImageView)findViewById(R.id.list_image);
				list_image.setBackgroundResource(R.drawable.tab_address_pressed);
				Log.d(TAG, "listView");
			}else if(calendar == (RelativeLayout)view){
				calendar_image = (ImageView)findViewById(R.id.calendar_image);
				calendar_image.setBackgroundResource(R.drawable.tab_find_frd_pressed);
				Log.d(TAG, "calendarView");
			}else if(favorite == (RelativeLayout)view){
				favorite_image = (ImageView)findViewById(R.id.favorite_image);
				favorite_image.setBackgroundResource(R.drawable.tab_settings_pressed);
				Log.d(TAG, "favorite");
			}else if(setting == (RelativeLayout)view){
				setting_image = (ImageView)findViewById(R.id.setting_image);
				setting_image.setBackgroundResource(R.drawable.tab_weixin_normal);
				Log.d(TAG, "setting");
			}
		}
		
	}
}

