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
import android.widget.CheckBox;
import android.widget.ListAdapter;
import android.widget.ListView;
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
		//list = dbAdapter.findShoppingList();
		list = new ArrayList<Goods>();
		Goods goods1 = new Goods();
		goods1.setId(1);
		goods1.setName("goods1");
		goods1.setState(1);
		
		Goods goods2 = new Goods();
		goods2.setId(2);
		goods2.setName("goods2");
		goods2.setState(0);
		
		Goods goods3 = new Goods();
		goods3.setId(3);
		goods3.setName("goods3");
		goods3.setState(0);
		
		Goods goods4 = new Goods();
		goods4.setId(4);
		goods4.setName("goods4");
		goods4.setState(0);
		
		Goods goods5 = new Goods();
		goods5.setId(5);
		goods5.setName("goods5");
		goods5.setState(0);
		
		Goods goods6 = new Goods();
		goods6.setId(6);
		goods6.setName("goods6");
		goods6.setState(0);
		
		Goods goods7 = new Goods();
		goods7.setId(7);
		goods7.setName("goods7");
		goods7.setState(0);
		
		Goods goods8 = new Goods();
		goods8.setId(8);
		goods8.setName("goods8");
		goods8.setState(0);
		
		Goods goods9 = new Goods();
		goods9.setId(9);
		goods9.setName("goods9");
		goods9.setState(0);
		
		Goods goods10 = new Goods();
		goods10.setId(10);
		goods10.setName("goods10");
		goods10.setState(0);
		
		list.add(goods1);
        list.add(goods2);
        list.add(goods3);
        list.add(goods4);
        list.add(goods5);
        list.add(goods6);
        list.add(goods7);
        list.add(goods8);
        list.add(goods9);
        list.add(goods10);
       
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
