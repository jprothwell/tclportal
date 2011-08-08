package com.shenkun.music;

import android.app.ListActivity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.database.Cursor;
import android.os.Bundle;
import android.os.IBinder;
import android.provider.MediaStore;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.TextView;

import com.shenkun.music.MusicUtil.ServiceToken;
/**
 * 一个音乐播放器
 * 1.自动识别SD卡，手机内的音乐
 * 2.选择文件夹进行加入音乐，类似于千千静听的加入音乐分类管理
 * 3.从网络下载音乐
 * @author kun.shen
 */
/**
 * 提供music的展现，界面列表
 * 在播放完成之后，会出现接受到service的广播的状态，来更新列表显示
 * 
 * 关注Activity与Service的交互方式
 * Activity显示状态，service是控制音频，使在退出activity时音乐播放不受影响
 */
public class MyMusicPlayer extends ListActivity {
   
	private static final String TAG = "MyMusicPlayer";
	
	private MusicCache musicCache;
	
	private MyMusicService musicService = null;
	
	private Cursor mCursor = null;
	 
	private TextView title;
	
	private ServiceToken serviceToken;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        MusicApplication  musicApplication = ((MusicApplication)getApplication());
        musicCache = musicApplication.musicCache;
        title = (TextView)findViewById(R.id.title);
        Log.d(TAG,"init view ");
        //serviceToken = MusicUtil.bindToService(this, serviceConnection);
    }
       

    //和service通讯
    private ServiceConnection serviceConnection = new ServiceConnection() {
        public void onServiceConnected(ComponentName classname, IBinder binder) {
        	Log.d(TAG, "ServiceConnection onServiceConnected..");
        	musicService  = ((MyMusicService.LocalBinder)binder).getService();
        }

        public void onServiceDisconnected(ComponentName classname) {
        	musicService = null;
        }
    };
    /*
     * 根据列表的适配类型，可以分为ArrayAdapter，SimpleAdapter和SimpleCursorAdapter
     * SimpleCursorAdapter api的描述
     * An easy adapter to map columns from a cursor to TextViews or ImageViews defined in an XML file.
     * You can specify which columns you want, which views you want to display the columns, and the XML file that defines the appearance of these views.
    
     * 详细例子http://www.cnblogs.com/allin/archive/2010/05/11/1732200.html
     * android.R.layout.simple_expandable_list_item_2系统定义好的布局文件
		最后两个参数：一个包含数据库的列的String型数组，一个包含布局文件中对应组件id的int型数组。
		其作用是自动的将String型数组所表示的每一列数据映射到布局文件对应id的组件上。
     */
    class MusicListAdapter extends SimpleCursorAdapter{

		public MusicListAdapter(Context context, int layout, Cursor c,
				String[] from, int[] to) {
			super(context, layout, c, from, to);
		}

		@Override
		public void bindView(View view, Context context, Cursor cursor) {
			super.bindView(view, context, cursor);
			TextView textView1 = (TextView) view.findViewById(android.R.id.text1);
			TextView textView2 = (TextView) view.findViewById(android.R.id.text2);
			textView1.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.TITLE)));
			textView2.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.ARTIST)));
		} 
    }
    
    /**
     * 设置列表的感应事件
     */
    @Override
	protected void onListItemClick(ListView l, View v, int position, long id) {
		// TODO Auto-generated method stub
    	Log.d(TAG, "onListItemClick..");
		super.onListItemClick(l, v, position, id);
//		if(mCursor==null||mCursor.getCount()==0){
//			return;
//		}
	
		if(!musicService.moveToPosition(position)){
			return;
		}
		musicService.playMusic();
		
		//play activity
		Intent intent = new Intent();
		intent.setClass(MyMusicPlayer.this, PlayActivity.class);
		this.startActivity(intent);
	}


	@Override
	protected void onResume() {
		Log.d(TAG, "onResume..");
		super.onResume();
		mCursor = musicCache.getAllSongs();
		ListAdapter adapter = new MusicListAdapter(this,android.R.layout.simple_expandable_list_item_2,mCursor,new String[]{}, new int[]{});
		setListAdapter(adapter);
		
		bindService();
		startService();
	}

	@Override
	protected void onDestroy() {
		super.onDestroy();
	}

	private void startService(){
		 this.startService(musicServiceIntent());
	}
	private void stopService(){
		this.stopService(musicServiceIntent());
	}
	private void bindService(){
	     //bindService是Context的方法
		 Log.d(TAG, "bindService......");
		 getApplicationContext().bindService(musicServiceIntent(), serviceConnection, Context.BIND_AUTO_CREATE);
	}
	
	private Intent musicServiceIntent(){
		return new Intent(this,MyMusicService.class);
	}
	
	private Intent aboutActivityIntent(){
		return new Intent(this,AboutActivity.class);
	}
	
	//创建menu
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.menu, menu);
		return true;
	}
	
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int itemId = item.getItemId();
		switch(itemId){
			case R.id.about:
				MyMusicPlayer.this.startActivity(aboutActivityIntent());
				break;
			case R.id.exit:
				onDestroy();
				musicService.stop();
				stopService();
				this.finish();
				break;
		}
		return super.onOptionsItemSelected(item);
	}
}