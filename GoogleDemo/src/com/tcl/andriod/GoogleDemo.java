package com.tcl.andriod;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;

public class GoogleDemo extends Activity {
	 private AutoCompleteTextView autoCompleteTextView;
	 private static final String[] strs = new String[]{"a","ab","abc","bc","bcd"};
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
       
       
        autoCompleteTextView = (AutoCompleteTextView)findViewById(R.id.autoComplete);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,android.R.layout.simple_dropdown_item_1line,strs);
        autoCompleteTextView.setAdapter(adapter);
    }
}