package com.android.shopping;

import android.app.Activity;
import android.os.Bundle;
import android.widget.EditText;
import android.widget.TextView;

public class ShoppingListAddActivity extends Activity{
	
	private static final String TAG = "ShoppingListAddActivity";
	
	private TextView shoppingName;
	private EditText nameText;
	
	private TextView shoppingTime;
	private EditText timeText;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.shopping_list_add);
		shoppingName = (TextView)findViewById(R.id.shopping_name);
		nameText = (EditText)findViewById(R.id.shopping_name_value);
		shoppingTime = (TextView)findViewById(R.id.shopping_time);
		timeText = (EditText)findViewById(R.id.shopping_time_value);
	}
	
	
}
