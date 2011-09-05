package com.shenkun.music;


import android.app.AlertDialog;
import android.app.TabActivity;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.widget.RelativeLayout;
import android.widget.TabHost;
import android.widget.TabWidget;
import android.widget.TextView;
/**
 * To create a tabbed UI, you need to use a TabHost and a TabWidget. 
 * The TabHost must be the root node for the layout, 
 * which contains both the TabWidget for displaying the tabs and a FrameLayout for displaying the tab content.
 * @author kun.shen
 *
 */
public class TabHostActivity extends TabActivity{
	
	private final static String TAG = "TabHostActivity";
	
	private TabHost mTabHost;

	private TextView musicTabView;
	
	private TextView webTabView;
	
//	private TabWidget tabWidget;
	
	Intent musicIntent;
	Intent webIntent;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.tabhost);
		mTabHost = this.getTabHost();
		
		musicIntent = new Intent(TabHostActivity.this,MyMusicPlayer.class);
		webIntent = new Intent(TabHostActivity.this,WebViewActivity.class);
		mTabHost.addTab(mTabHost.newTabSpec ("music")
				.setIndicator("",this.getResources().getDrawable(R.drawable.tab_songs))
				.setContent(musicIntent));
		mTabHost.addTab(mTabHost.newTabSpec ("web")
				.setIndicator("",this.getResources().getDrawable(R.drawable.tab_songs))
				.setContent(webIntent));
//		initTextView();
//		initTabHost();
	}
	
	

	/**
	 * 
	 */
	private void initTabHost() { 
		TabWidget tw = mTabHost.getTabWidget();  
//		musicTabView = (TextView)findViewById(R.id.musicTab);
		RelativeLayout  musicLayout  = (RelativeLayout ) LayoutInflater.from(this).inflate(R.layout.tabhost_widget, tw, false);  
		musicTabView = (TextView)musicLayout.getChildAt(0);
	
		
		TabHost.TabSpec musicSpec = mTabHost.newTabSpec ("music_play");
		musicSpec.setIndicator(musicLayout);//.setIndicator("",this.getResources().getDrawable(R.drawable.tab_songs))
		musicSpec.setContent(musicIntent);
		mTabHost.addTab(musicSpec);
		
		RelativeLayout  webLayout  = (RelativeLayout ) LayoutInflater.from(this).inflate(R.layout.tabhost_widget, tw, false);  
		webTabView = (TextView)webLayout.getChildAt(1);
		
		TabHost.TabSpec spec = mTabHost.newTabSpec ("web");
		spec.setIndicator(webLayout);//.setIndicator("",this.getResources().getDrawable(R.drawable.tab_songs))
		spec.setContent(webIntent);
		mTabHost.addTab(spec);
		
		Log.d(TAG, "tabWidget num:"+tw.getChildCount());
//		 for (int i =0; i <tw.getChildCount(); i++) {
//			 final TextView tv = (TextView) tw.getChildAt(i).findViewById(android.R.id.title);
//		 }
	}

	private void initTextView() {
//		((RadioButton) findViewById(R.id.music_tab)).setOnCheckedChangeListener(this);
//		((RadioButton) findViewById(R.id.web_tab)).setOnCheckedChangeListener(this);
//		musicTabView = (TextView)findViewById(R.id.music_tab);
//		webTabView = (TextView)findViewById(R.id.web_tab);
		
	}
}
