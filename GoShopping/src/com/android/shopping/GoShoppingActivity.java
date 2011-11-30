package com.android.shopping;


import android.app.TabActivity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.widget.TabHost;
import android.widget.TabHost.OnTabChangeListener;
/**
 * 参照已有的shoppingList的需求和代码，重新实现
 * 1. 日历参照android源代码中的构建
 * 2. 滑动效果，参照launcher构建
 * 3. 在页面切换过程中添加其他动画效果
 * 4. 用数据库保存数据
 * 5. 支持从服务器更新版本
 * 6. 国际化支持
 * @author kun.shen
 * GoShoppingActivity实现
 */
public class GoShoppingActivity extends TabActivity implements OnTabChangeListener{
	
	private final static String TAG = "GoShoppingActivity";
	
	private TabHost mTabHost;
	
	Intent calendarIntent;
	Intent listIntent;
	Intent searchIntent;
	Intent settingIntent;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.tabhost);
		mTabHost = this.getTabHost();
		
		calendarIntent = new Intent(GoShoppingActivity.this,CalendarActivity.class);
		listIntent = new Intent(GoShoppingActivity.this,ShoppingListActivity.class);
		searchIntent = new Intent(GoShoppingActivity.this,GoodsSearchActivity.class);
		settingIntent = new Intent(GoShoppingActivity.this,ShoppingListActivity.class);
		
		//以列表显示购购物单
		mTabHost.addTab(mTabHost.newTabSpec ("清单")
				.setIndicator("清单",this.getResources().getDrawable(R.drawable.temp))
				.setContent(listIntent));
		
		//按日历显示购物单
		mTabHost.addTab(mTabHost.newTabSpec ("日历")
				.setIndicator("日历",this.getResources().getDrawable(R.drawable.temp))
				.setContent(calendarIntent));
		
		
		mTabHost.addTab(mTabHost.newTabSpec ("搜索")
				.setIndicator("搜索",this.getResources().getDrawable(R.drawable.temp))
				.setContent(searchIntent));
		//软件设置
		mTabHost.addTab(mTabHost.newTabSpec ("设置")
				.setIndicator("设置",this.getResources().getDrawable(R.drawable.temp))
				.setContent(settingIntent));
	}

	@Override
	public void onTabChanged(String tabId) {
		// TODO Auto-generated method stub
		
	}
	
	
}