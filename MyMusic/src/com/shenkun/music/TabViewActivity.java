package com.shenkun.music;

import android.app.ActivityGroup;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.ViewGroup.LayoutParams;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.AdapterView.OnItemClickListener;

public class TabViewActivity extends ActivityGroup{
	
	private GridView topViewBar;
	
	public LinearLayout container;
	
	ImageAdapter imageAdapter;
	
	 /** 顶部按钮图片 **/  
    int[] topbar_image_array = { R.drawable.icon, R.drawable.icon};  
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.tabview);
		
		topViewBar = (GridView)this.findViewById(R.id.gvTopBar);
		topViewBar.setNumColumns(2);
		topViewBar.setSelector(new ColorDrawable(Color.TRANSPARENT));// 选中的时候为透明色  
		topViewBar.setGravity(Gravity.CENTER);// 位置居中  
		topViewBar.setVerticalSpacing(0);// 垂直间隔  
		
		 int width = this.getWindowManager().getDefaultDisplay().getWidth()  
         / topbar_image_array.length;  
		 imageAdapter = new ImageAdapter(this, topbar_image_array, width, 48,  
         R.drawable.album_playback);  
		 topViewBar.setAdapter(imageAdapter);// 设置菜单Adapter  
		 topViewBar.setOnItemClickListener(new ClickEvent());// 项目点击事件  
		 container = (LinearLayout) findViewById(R.id.Container);  
		// SwitchActivity(0);//默认打开第0页  
	}
	
	  class ClickEvent implements OnItemClickListener {  
		  
	        public void onItemClick(AdapterView<?> adapterView, View view, int id,  
	                long l) {  
	            SwitchActivity(id);  
	        }  
	    }  
	  
	  /** 
	     * 根据ID打开指定的Activity 
	     * @param id GridView选中项的序号 
	     */  
	    void SwitchActivity(int id)  
	    {  
	    	imageAdapter.SetFocus(id);//选中项获得高亮  
	        container.removeAllViews();//必须先清除容器中所有的View  
	        Intent intent =null;  
	        if (id == 0 || id == 2) {  
	            intent = new Intent(TabViewActivity.this, MyMusicPlayer.class);  
	        } else if (id == 1 || id == 3) {  
	            intent = new Intent(TabViewActivity.this, AboutActivity.class);  
	        }   
	        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);  
	        //Activity 转为 View  
	        Window subActivity = getLocalActivityManager().startActivity("subActivity", intent);  
	        //容器添加View  
	        container.addView(subActivity.getDecorView(),  
	                LayoutParams.FILL_PARENT, LayoutParams.FILL_PARENT);  
	    }  
	    
	class ImageAdapter extends BaseAdapter {  
	    private Context mContext;   
	    private ImageView[] imgItems;  
	    private int selResId;  
	    public ImageAdapter(Context c,int[] picIds,int width,int height,int selResId) {   
	        mContext = c;   
	        this.selResId=selResId;  
	        imgItems=new ImageView[picIds.length];  
	        for(int i=0;i<picIds.length;i++)  
	        {  
	            imgItems[i] = new ImageView(mContext);   
	            imgItems[i].setLayoutParams(new GridView.LayoutParams(width, height));//设置ImageView宽高   
	            imgItems[i].setAdjustViewBounds(false);   
	            //imgItems[i].setScaleType(ImageView.ScaleType.CENTER_CROP);   
	            imgItems[i].setPadding(2, 2, 2, 2);   
	            imgItems[i].setImageResource(picIds[i]);   
	        }  
	    }   
	   
	    public int getCount() {   
	        return imgItems.length;   
	    }   
	   
	    public Object getItem(int position) {   
	        return position;   
	    }   
	   
	    public long getItemId(int position) {   
	        return position;   
	    }   
	   
	    /**  
	     * 设置选中的效果  
	     */    
	    public void SetFocus(int index)    
	    {    
	        for(int i=0;i<imgItems.length;i++)    
	        {    
	            if(i!=index)    
	            {    
	                imgItems[i].setBackgroundResource(0);//恢复未选中的样式  
	            }    
	        }    
	        imgItems[index].setBackgroundResource(selResId);//设置选中的样式  
	    }    
	      
	    public View getView(int position, View convertView, ViewGroup parent) {   
	        ImageView imageView;   
	        if (convertView == null) {   
	            imageView=imgItems[position];  
	        } else {   
	            imageView = (ImageView) convertView;   
	        }   
	        return imageView;   
	    }   
	}   
}
