package com.shenkun.music;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class AboutActivity extends Activity{
	
	TextView textView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.about);
		textView = (TextView)findViewById(R.id.aboutContent);
	}

	
}
