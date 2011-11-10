package com.android.shopping;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;

import com.android.shopping.bean.ShoppingList;

/**
 * 从数据库中获取shoppingList
 * @author kun.shen
 *
 */
public class ShoppingListActivity extends ListActivity{
	
	private String TAG = "ShoppingListActivity";
	
	List<ShoppingList> list;
	DBAdapter dbAdapter;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.shopping_list);
		dbAdapter = new DBAdapter(this);
		
		//this.setContentView(listView);
	}
	
	@Override
	protected void onResume() {
		super.onResume();
		//list = dbAdapter.findShoppingList();
		list = new ArrayList<ShoppingList>();
		ShoppingList shop1 = new ShoppingList();
		shop1.setId(5);
		shop1.setName("name1");
		shop1.setDate(new Date());
		ShoppingList shop2 = new ShoppingList();
		shop2.setId(6);
		shop2.setName("name2");
		shop2.setDate(new Date());
		
		list.add(shop1);
        list.add(shop2);
		ListAdapter adapter = new ShoppingAdapter(this,R.layout.shopping_list_item,list);
		this.setListAdapter(adapter);
	}
	
	
	@Override
	protected void onListItemClick(ListView l, View v, int position, long id) {
		super.onListItemClick(l, v, position, id);
		ShoppingList shoppingList = list.get(position);
		Log.d(TAG, "shoppingList:"+shoppingList.getId());
		//传入shoppingList的id，进入shoppingList的商品列表
		Intent intent = new Intent();
		intent.setClass(ShoppingListActivity.this, ShoppingListContentActivity.class);
		intent.putExtra("id", shoppingList.getId());
		this.startActivity(intent);
		
		//overridePendingTransition(R.anim.zoom_in,R.anim.zoom_out);
	}

	//创建menu
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.shopping_list_menu, menu);
		return true;
	}
	//menu的选择事件
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int itemId = item.getItemId();
		switch(itemId){
			case R.id.search_shopping_list:
				ShoppingListActivity.this.startActivity(listActivityIntent());
				break;
			case R.id.add_shopping_add:
				ShoppingListActivity.this.startActivity(addActivityIntent());
				break;
		}
		return super.onOptionsItemSelected(item);
	}
	
	private Intent addActivityIntent() {
		return new Intent(this,ShoppingListAddActivity.class);
	}

	private Intent listActivityIntent() {
		return new Intent(this,ShoppingListSearchActivity.class);
	}

	//list的数据适配
	class ShoppingAdapter extends ArrayAdapter<ShoppingList>{
		
		private int view;
		
		public ShoppingAdapter(Context context, int textViewResourceId,
				List<ShoppingList> list) {
			super(context, textViewResourceId, list);
			this.view = textViewResourceId;
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			ShoppingList shoppingList =  getItem(position); 
			LayoutInflater inflater = (LayoutInflater)getContext().getSystemService(LAYOUT_INFLATER_SERVICE);
			View layout = inflater.inflate(view,null);
//			TextView idText = (TextView)layout.findViewById(R.id.shopping_id);
//			idText.setText(String.valueOf(shoppingList.getId()));
	        TextView name = (TextView)layout.findViewById(R.id.name);  
	        name.setText(shoppingList.getName());
	        TextView date = (TextView)layout.findViewById(R.id.shopping_date);
	        date.setText(DateUtil.dateToString(shoppingList.getDate()));
	        return layout;  
		}
	}	
}
