package com.shenkun.music;

import android.app.Activity;
import android.os.Bundle;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class WebViewActivity extends Activity{
	
	private WebView webView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.download);
		webView = (WebView)findViewById(R.id.musicWebView);
		webView.getSettings().setJavaScriptEnabled(true);
		webView.loadUrl("htpp://www.top100.cn");
		webView.setWebViewClient(new WebViewClient(){
			@Override
			public boolean shouldOverrideUrlLoading(WebView view, String url) {
				webView.loadUrl(url);
				return super.shouldOverrideUrlLoading(view, url);
			}
			
		});
	}

	
}
