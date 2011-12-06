package com.android.shopping;

import java.util.Calendar;
import java.util.Date;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.android.shopping.bean.ShoppingList;
import com.android.shopping.util.DBAdapter;
import com.android.shopping.util.DateSet;
import com.android.shopping.util.DateUtil;
import com.android.shopping.util.DialogBackInfoListener;

public class ShoppingListAddActivity extends Activity{
	
	private static final String TAG = "ShoppingListAddActivity";
	
	DBAdapter dbAdapter;
	
	private TextView shoppingName;
	private EditText nameText;
	
	private TextView shoppingTime;
	private EditText timeText;
	
	
	private Button reset;
	private Button save;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.shopping_list_add);
		dbAdapter = new DBAdapter(this);
		
		shoppingName = (TextView)findViewById(R.id.shopping_name);
		nameText = (EditText)findViewById(R.id.shopping_name_value);
		shoppingTime = (TextView)findViewById(R.id.shopping_time);
		timeText = (EditText)findViewById(R.id.shopping_time_value);
		//初始化时间数据为当天
		timeText.setText(DateUtil.dateAndWeek(new Date(),this));
		timeText.setFocusable(false);
		timeText.setOnClickListener(timeListenter);
		
		reset = (Button)findViewById(R.id.shopping_reset);
		save = (Button)findViewById(R.id.shopping_save);
	}
	private View.OnClickListener timeListenter = new View.OnClickListener(){

		@Override
		public void onClick(View v) {
			DialogBackInfoListener backInfo = new DialogBackInfoListener(){

				@Override
				public void refreshActivity(CharSequence charSequence) {
					timeText.setText(charSequence);
				}
				
			};
			DateSet dateSet = new DateSet(ShoppingListAddActivity.this,backInfo);

		}
		
	};
	
	private Button.OnClickListener saveListener = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			//获取输入框里的值，保存数据库
			String name = nameText.getText().toString();
			ShoppingList shoppingList = new ShoppingList();
			shoppingList.setName(name);
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
}
