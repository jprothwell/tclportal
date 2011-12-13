package com.android.shopping;

import java.util.Date;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.android.shopping.bean.ShoppingList;
import com.android.shopping.util.DBAdapter;
import com.android.shopping.util.DateSet;
import com.android.shopping.util.DateUtil;
import com.android.shopping.util.ParamUtil;

public class ShoppingListAddActivity extends Activity implements DateSet.DateDialogBackInfoListener{
	
	private static final String TAG = "ShoppingListAddActivity";
	
	DBAdapter dbAdapter;
	
	private TextView shoppingName;
	private EditText nameText;
	
	private TextView shoppingTime;
	private EditText timeText;
	
	
	private Button save;
	private Button cancel;
	
	String label;//用来判断
	
	int shopping_id;
	
	ShoppingList shoppingList;
	
	Date dateValue;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.shopping_list_add);
		dbAdapter = new DBAdapter(this);
		Intent intent = getIntent();
		label = intent.getStringExtra(ParamUtil.LABEL);
		
		shoppingName = (TextView)findViewById(R.id.shopping_name);
		nameText = (EditText)findViewById(R.id.shopping_name_value);
		shoppingTime = (TextView)findViewById(R.id.shopping_time);
		timeText = (EditText)findViewById(R.id.shopping_time_value);
		//初始化时间数据为当天
		
		if("add".equals(label)){
			
			dateValue = new Date();
			
			timeText.setText(DateUtil.dateAndWeek(dateValue,this));
		}else if("edit".equals(label)){
			shopping_id = intent.getIntExtra(ParamUtil.ID, 0);
			shoppingList = dbAdapter.queryShoppingList(shopping_id);
			nameText.setText(shoppingList.getName());
			dateValue = DateUtil.stringToDate(shoppingList.getDate());
			timeText.setText(DateUtil.dateAndWeek(dateValue,this));
		}
		
		
		timeText.setFocusable(false);
		timeText.setOnClickListener(timeListenter);
		
		save = (Button)findViewById(R.id.shopping_save);
		cancel = (Button)findViewById(R.id.shopping_cancel);
		save.setOnClickListener(saveListener);
		cancel.setOnClickListener(cancelListener);
	}
	private View.OnClickListener timeListenter = new View.OnClickListener(){

		@Override
		public void onClick(View v) {
			String timeValue = timeText.getText().toString();
			Log.d(TAG, "timaValue:::"+timeValue.split(" ")[0]);
			dateValue = DateUtil.stringToDate(timeValue.split(" ")[0]);
			DateSet dateSet = new DateSet(ShoppingListAddActivity.this,ShoppingListAddActivity.this,dateValue);
			
//			DateSetDialog dateSetDialog = new DateSetDialog(ShoppingListAddActivity.this);
//			dateSetDialog.show();
		}
		
	};
	
	private Button.OnClickListener saveListener = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			//获取输入框里的值，保存数据库
			String name = nameText.getText().toString();
			String time = timeText.getText().toString().split(" ")[0];
			
			ShoppingList shoppingList = new ShoppingList();
			shoppingList.setName(name);
			shoppingList.setDate(time);
			dbAdapter.insertList(shoppingList);
			ShoppingListAddActivity.this.startActivity(saveIntent());
		}
	};
	
	private Button.OnClickListener cancelListener = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			ShoppingListAddActivity.this.startActivity(cancelIntent());
		}
	};
	
	private Intent saveIntent(){
		return new Intent(this,ShoppingListActivity.class);
	}
	private Intent cancelIntent(){
		return new Intent(this,ShoppingListActivity.class);
	}
	@Override
	public void refreshActivity(CharSequence charSequence) {
		timeText.setText(charSequence);
	}
}
