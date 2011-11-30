package com.android.shopping;


import android.app.TabActivity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.widget.TabHost;
import android.widget.TabHost.OnTabChangeListener;
/**
 * �������е�shoppingList������ʹ��룬����ʵ��
 * 1. ��������androidԴ�����еĹ���
 * 2. ����Ч��������launcher����
 * 3. ��ҳ���л������������������Ч��
 * 4. �����ݿⱣ������
 * 5. ֧�ִӷ��������°汾
 * 6. ���ʻ�֧��
 * @author kun.shen
 * GoShoppingActivityʵ��
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
		
		//���б���ʾ�����ﵥ
		mTabHost.addTab(mTabHost.newTabSpec ("�嵥")
				.setIndicator("�嵥",this.getResources().getDrawable(R.drawable.temp))
				.setContent(listIntent));
		
		//��������ʾ���ﵥ
		mTabHost.addTab(mTabHost.newTabSpec ("����")
				.setIndicator("����",this.getResources().getDrawable(R.drawable.temp))
				.setContent(calendarIntent));
		
		
		mTabHost.addTab(mTabHost.newTabSpec ("����")
				.setIndicator("����",this.getResources().getDrawable(R.drawable.temp))
				.setContent(searchIntent));
		//�������
		mTabHost.addTab(mTabHost.newTabSpec ("����")
				.setIndicator("����",this.getResources().getDrawable(R.drawable.temp))
				.setContent(settingIntent));
	}

	@Override
	public void onTabChanged(String tabId) {
		// TODO Auto-generated method stub
		
	}
	
	
}