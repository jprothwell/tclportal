package com.android.shopping;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;

import com.android.shopping.ShoppingListActivity.ShoppingAdapter;
import com.android.shopping.bean.Goods;
import com.android.shopping.bean.ShoppingList;
import com.android.shopping.util.DBAdapter;
import com.android.shopping.util.ParamUtil;
/**
 * 根据shoppingList的id获取其中的商品列表
 * @author kun.shen
 *
 */
public class ShoppingListContentActivity extends ListActivity{
	
	private String TAG = "ShoppingListContent";
	
	List<Goods> list;
	
	DBAdapter dbAdapter;
	
	int id;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.shopping_list_goods);
		dbAdapter = new DBAdapter(this);
		Intent intent = getIntent();
		id = intent.getIntExtra(ParamUtil.ID, 1);
	}
	
	
	@Override
	protected void onListItemClick(ListView l, View v, int position, long id) {
		super.onListItemClick(l, v, position, id);
		CheckBox ib = (CheckBox) v.findViewById(R.id.goods_checkbox);
		Goods goods =  list.get(position); 
		if(ib.isChecked()){
			ib.setChecked(false);
			goods.setState(0);
		}else{
			ib.setChecked(true);
			goods.setState(1);
		}
	}


	@Override
	protected void onResume() {
		super.onResume();
		list = dbAdapter.findGoodsInShoppingList(id);
		ListAdapter adapter = new GoodsAdapter(this,R.layout.shopping_list_goods_item,list);
		this.setListAdapter(adapter);
	}
	
	//list的数据适配
	class GoodsAdapter extends ArrayAdapter<Goods>{
		
		private int view;
		
		public GoodsAdapter(Context context, int textViewResourceId,
				List<Goods> list) {
			super(context, textViewResourceId, list);
			this.view = textViewResourceId;
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			Goods goods =  getItem(position); 
			LayoutInflater inflater = (LayoutInflater)getContext().getSystemService(LAYOUT_INFLATER_SERVICE);
			View layout = inflater.inflate(view,null);
//			TextView idText = (TextView)layout.findViewById(R.id.goods_id);
//			idText.setText(String.valueOf(goods.getId()));
	        TextView name = (TextView)layout.findViewById(R.id.goods_name);  
	        name.setText(goods.getName());
	        CheckBox checkBox = (CheckBox) layout.findViewById(R.id.goods_checkbox);
	        if(goods.getState()==0){
		        checkBox.setChecked(false);
	        }else{
		        checkBox.setChecked(true);
	        }
	        return layout;  
		}
	}	
}
