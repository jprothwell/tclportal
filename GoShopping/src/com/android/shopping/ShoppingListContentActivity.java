package com.android.shopping;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import android.app.ListActivity;
import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.TextView;

import com.android.shopping.ShoppingListActivity.ShoppingAdapter;
import com.android.shopping.bean.Goods;
import com.android.shopping.bean.ShoppingList;
/**
 * 根据shoppingList的id获取其中的商品列表
 * @author kun.shen
 *
 */
public class ShoppingListContentActivity extends ListActivity{
	
	private String TAG = "ShoppingListContent";
	
	List<Goods> list;
	DBAdapter dbAdapter;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.shopping_list_goods);
		dbAdapter = new DBAdapter(this);
	}
	
	@Override
	protected void onResume() {
		super.onResume();
		//list = dbAdapter.findShoppingList();
		list = new ArrayList<Goods>();
		Goods goods1 = new Goods();
		goods1.setId(5);
		goods1.setName("goods1");
		Goods goods2 = new Goods();
		goods2.setId(6);
		goods2.setName("goods2");
		
		list.add(goods1);
        list.add(goods2);
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
	        return layout;  
		}
	}	
}
