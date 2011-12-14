package com.android.shopping;

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
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.AdapterView.OnItemLongClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;

import com.android.shopping.bean.ShoppingList;
import com.android.shopping.util.DBAdapter;
import com.android.shopping.util.ParamUtil;


/**
 * 从数据库中获取shoppingList
 * @author kun.shen
 *
 */
public class ShoppingListActivity extends ListActivity{
	
	private String TAG = "ShoppingListActivity";

	List<ShoppingList> list;
	
	DBAdapter dbAdapter;
	
	Button button;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.shopping_list);
		dbAdapter = new DBAdapter(this);
		button = (Button)findViewById(R.id.add_shopping_item);
		button.setOnClickListener(addShoppingListener);
		//list长事件
		this.getListView().setOnItemLongClickListener(longClickListener);		
		//this.getListView().setOnItemClickListener(clickListener);
	}
	
	private AdapterView.OnItemClickListener clickListener = new OnItemClickListener(){

		@Override
		public void onItemClick(AdapterView<?> adapter, View view, int i,
				long l) {
			// TODO Auto-generated method stub
			
		}
		
		
	};
	
	private AdapterView.OnItemLongClickListener longClickListener = new OnItemLongClickListener(){
		
		public boolean onItemLongClick(AdapterView parent, View view, int position, long id) {
			ShoppingList shoppingList = list.get(position);
			Intent intent = new Intent();
			intent.putExtra(ParamUtil.LABEL, "edit");
			intent.putExtra("id", shoppingList.getId());
			Log.d(TAG,"label::edit");
			ShoppingListActivity.this.startActivity(editActivityIntent());
		    return true;
		}
	};
	
	private Button.OnClickListener addShoppingListener = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			ShoppingListActivity.this.startActivity(addActivityIntent());
		}
	};
	

	@Override
	protected void onResume() {
		super.onResume();
		list = dbAdapter.findShoppingList();
		ListAdapter adapter = new ShoppingAdapter(this,R.layout.shopping_list_item,list);
		this.setListAdapter(adapter);
	}
	
	@Override
	protected void onListItemClick(ListView l, View v, int position, long id) {
		super.onListItemClick(l, v, position, id);
		ShoppingList shoppingList = list.get(position);
		Log.d(TAG, "shoppingList:"+shoppingList.getId());
		//传入shoppingList的id，进入shoppingList的商品列表
		Intent intent = new Intent(this,ShoppingListContentActivity.class);
		intent.putExtra(ParamUtil.ID, shoppingList.getId());
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
		Intent intent = new Intent(this,ShoppingListAddActivity.class);
		intent.putExtra(ParamUtil.LABEL, "add");
		Log.d(TAG,"label::add");
		return intent;
	}
	
	private Intent editActivityIntent() {
		Intent intent = new Intent(this,ShoppingListAddActivity.class);
		intent.putExtra(ParamUtil.LABEL, "edit");
		Log.d(TAG,"label::edit");
		return intent;
	}
	
	private Intent listActivityIntent() {
		return new Intent(this,ShoppingListSearchActivity.class);
	}

	//list的数据适配
	class ShoppingAdapter extends ArrayAdapter<ShoppingList>{
		
		boolean check = false;
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
	        date.setText(shoppingList.getDate());
	        
//	        CheckBox checkBox = (CheckBox)layout.findViewById(R.id.list_checkbox);
//	        checkBox.setOnCheckedChangeListener(new OnCheckedChangeListener() {
//                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
//                	check = isChecked;
//                }
//            });
	        
	        return layout;  
		}
	}	
//	@Override  
//	public boolean onKeyDown(int keyCode, KeyEvent event)  {
//	    //按下的如果是BACK，同时没有重复  直接退出程序
//	    if (keyCode == KeyEvent.KEYCODE_BACK && event.getRepeatCount() == 0) {   
//	    	Intent home = new Intent(Intent.ACTION_MAIN);   
//	    	home.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);   
//	    	home.addCategory(Intent.CATEGORY_HOME);   
//	    	startActivity(home);
//	    }  
//	    return true;
//	}
}
