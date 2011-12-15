package com.android.shopping;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.android.shopping.bean.Goods;
import com.android.shopping.util.DBAdapter;
import com.android.shopping.util.ParamUtil;

public class GoodsAddActivity extends Activity{
	
	private static final String TAG = "GoodsAddActivity";
	
	DBAdapter dbAdapter;
	
	
	private TextView goodsName;
	
	private EditText nameText;
	
	private Button save;
	
	private Button cancel;
	
	String label;
	
	int id;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.goods_add);
		dbAdapter = new DBAdapter(this);
		Intent intent = getIntent();
		label = intent.getStringExtra(ParamUtil.LABEL);
		if("edit".equals(label)){
			id = intent.getIntExtra(ParamUtil.ID, 1);
		}
		
		goodsName = (TextView)findViewById(R.id.goods_name);
		nameText = (EditText)findViewById(R.id.goods_name_value);
		
		save = (Button)findViewById(R.id.goods_save);
		save.setOnClickListener(saveListener);
	}
	
	private Button.OnClickListener saveListener = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			//获取输入框里的值，保存数据库
			String name = nameText.getText().toString();
			
			Goods goods = new Goods();
			if("add".equals(label)){
				goods.setName(name);
				dbAdapter.insertGoods(goods);
			}else{
				goods = dbAdapter.queryGoods(id);
				goods.setName(name);
				dbAdapter.updateGoos(goods);
			}
		}
	};
	
}
