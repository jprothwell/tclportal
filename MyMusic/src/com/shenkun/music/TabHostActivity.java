package com.shenkun.music;


import android.app.Activity;
import android.app.TabActivity;
import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.database.Cursor;
import android.os.Bundle;
import android.os.IBinder;
import android.util.Log;
import android.view.View;
import android.widget.ListView;
import android.widget.TabHost;
import android.widget.TextView;

public class TabHostActivity extends TabActivity{
	
	private final static String TAG = "TabHostActivity";
	
	private TabHost mTabHost;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.tabhost);
		
		mTabHost = this.getTabHost();
		
		Intent intent = new Intent();
		intent.setClass(TabHostActivity.this, MyMusicPlayer.class);
		
		mTabHost.addTab(mTabHost.newTabSpec("music_play")
	    		.setIndicator("",getResources().getDrawable(R.drawable.icon))
	    		.setContent(intent));
		
		Intent webIntent = new Intent(TabHostActivity.this,WebViewActivity.class);
		mTabHost.addTab(mTabHost.newTabSpec("music_download")
	    		.setIndicator("",getResources().getDrawable(R.drawable.icon))
	    		.setContent(webIntent));
	}
}
