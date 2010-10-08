package com.tcl.android;

import android.app.ListActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;

public class AcrtivityList extends ListActivity {
    
	final String[] strs = new String[]{"China","Japan","Russian","American"};
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.main);
        setListAdapter(new ArrayAdapter<String>(this,android.R.layout.simple_list_item_1,strs));
    }
}