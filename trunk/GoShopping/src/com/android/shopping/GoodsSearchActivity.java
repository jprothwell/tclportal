package com.android.shopping;


import android.app.Activity;
import android.app.SearchManager;
import android.content.Intent;
import android.os.Bundle;
import android.provider.SearchRecentSuggestions;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class GoodsSearchActivity extends Activity{
	
	private static final String TAG = "GoodsSearchActivity";
	
	private static final String JARGON = "search";
	
	private Button searchButton;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.search);
		searchButton = (Button)findViewById(R.id.search_button);
		searchButton.setOnClickListener(searchClickListen);
		Intent intent = getIntent();
		handleIntent(getIntent());
		//判断是否是搜索请求 
//		if (Intent.ACTION_SEARCH.equals(intent.getAction())) { 
//			String query = intent.getStringExtra(SearchManager.QUERY);
//			//doMySearch(query);
//		}
	}
	
	@Override  
	protected void onNewIntent(Intent intent) {  
	    setIntent(intent);  
	    handleIntent(intent);  
	}  
	   
	private void handleIntent(Intent intent) {  
	    if (Intent.ACTION_SEARCH.equals(intent.getAction())) {  
	    	//获取输入框的查询内容
	      String query = intent.getStringExtra(SearchManager.QUERY);  
	      Log.d(TAG, "search information::"+query);
	      //保存搜索记录
	      SearchRecentSuggestions suggestions=new SearchRecentSuggestions(this,
	    		  GoodSearchProvider.AUTHORITY, GoodSearchProvider.MODE);
	      suggestions.saveRecentQuery(query, null);
	    // doMySearch(query);  
	    }
	 }  
	    
	@Override
	public boolean onSearchRequested() {
		Bundle appData = new Bundle(); 
		appData.putBoolean(GoodsSearchActivity.JARGON, true); 
		startSearch(null, false, appData, false);
		return true; 
	}

	private Button.OnClickListener searchClickListen = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			onSearchRequested();
		}
		
	};
}
