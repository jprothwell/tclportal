package com.tcl.android;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class Result extends Activity {
	  public void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.mylayout);
	        Bundle bundle = this.getIntent().getExtras();
	        String name = bundle.getString("name");
	        String sex = bundle.getString("sex");
	        TextView textView = (TextView)findViewById(R.id.show);
	        textView.setText("name:"+name+"\n sex:"+sex);
	  }
}
