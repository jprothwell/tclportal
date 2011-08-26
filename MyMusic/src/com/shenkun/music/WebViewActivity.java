package com.shenkun.music;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.KeyEvent;
import android.webkit.WebChromeClient;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class WebViewActivity extends Activity{
	
	private WebView webView;
	
	Activity activity;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.download);
		webView = (WebView)findViewById(R.id.musicWebView);
		WebSettings webSettings = webView.getSettings();
		webSettings.setJavaScriptEnabled(true);
		webSettings.setLightTouchEnabled(true);
		webView.loadUrl("http://www.qq.com");
		activity = this;
		webView.setWebViewClient(new MusicWebViewClient(this));
		webView.setWebChromeClient(new MusciWebChromeClient());
		
	}

	class MusciWebChromeClient extends WebChromeClient{
			@Override
			public void onProgressChanged(WebView view, int newProgress) {
				// TODO Auto-generated method stub
				activity.setProgress(newProgress*1000);
				//super.onProgressChanged(view, newProgress);
			}
			
		}
	
	class MusicWebViewClient extends WebViewClient{
		
		  private Context context;
		  
		  public MusicWebViewClient(Context context){
		         this .context = context;
		     }
		@Override
		public boolean shouldOverrideUrlLoading(WebView view, String url) {
//				webView.loadUrl(url);
			
				return super.shouldOverrideUrlLoading(view, url);
			}
		}
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		if(keyCode==KeyEvent.KEYCODE_BACK&&webView.canGoBack()){
			webView.goBack();
			return true;
		}
		return super.onKeyDown(keyCode, event);
	}

	
}
