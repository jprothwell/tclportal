package com.shenkun.music;

import android.app.ListActivity;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
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
import android.widget.Button;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.TextView;
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
	
//	private Button playAndPause;//播放和暂停
//	
//	private Button beforeMusic;//前一首
//	
//	private Button nextMusic; //后一首
	
//	private Button stop;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        MusicApplication  musicApplication = ((MusicApplication)getApplication());
        musicCache = musicApplication.musicCache;
        title = (TextView)findViewById(R.id.title);
//        playAndPause = (Button)findViewById(R.id.play_pause_button);
//        beforeMusic = (Button)findViewById(R.id.before_music);
//        nextMusic = (Button)findViewById(R.id.next_music);
       // stop = (Button)findViewById(R.id.stop_button);
        
        Log.d(TAG,"init view ");
        Intent intent = new Intent(this,MyMusicService.class);
        this.startService(intent);
        //bindService是Context的方法
        bindService(intent, serviceConnection, Context.BIND_AUTO_CREATE);
        
//        playAndPause.setOnClickListener(new Button.OnClickListener(){
//
//			@Override
//			public void onClick(View view) {
//				if(musicService!=null&&musicService.isPlaying()){
//					//有音乐正在播放
//					playAndPause.setText(R.string.play);
//					musicService.pause();
//				}else if(musicService!=null){
//					//没有音乐在播放
//					playAndPause.setText(R.string.pause);
//					musicService.start();
//				}
//			}
//        	
//        });
//        
//        beforeMusic.setOnClickListener(new Button.OnClickListener(){
//
//			@Override
//			public void onClick(View v) {
//				if(musicService!=null&&musicService.isPlaying()){
//					mCursor.moveToPrevious();
//					playMusic();
//				}
//			}
//        	
//        });
        
//        nextMusic.setOnClickListener(new Button.OnClickListener(){
//
//			@Override
//			public void onClick(View v) {
//				playNextMusic();
//			}
//        });
//        stop.setOnClickListener(new Button.OnClickListener(){
//
//			@Override
//			public void onClick(View view) {
//				Log.d(TAG, "stop.setOnClickListener..");
//				if(musicService!=null){
//					title.setVisibility(View.INVISIBLE);
//					stop.setVisibility(View.INVISIBLE);
//					musicService.stop();
//				}
//			} 	
//        });
        
//        IntentFilter filter = new IntentFilter();
//        filter.addAction(MyMusicService.COMPLETE);
//        filter.addAction(MyMusicService.PREPARE);
//        registerReceiver(broadcastReciver, filter);
    }
   
//    private BroadcastReceiver broadcastReciver = new BroadcastReceiver(){
//
//		@Override
//		public void onReceive(Context context, Intent intent) {
//			String action = intent.getAction();
//			if((MyMusicService.COMPLETE).equals(action)){
//				//播放完毕
//				playAndPause.setText(R.string.pause);
////				playNextMusic();
//			}else if((MyMusicService.PREPARE).equals(action)){
////				playingView();
//				playAndPause.setText(R.string.pause);
//			}
//			
//		}
//    	
//    };
    //和service通讯
    private ServiceConnection serviceConnection = new ServiceConnection() {
        public void onServiceConnected(ComponentName classname, IBinder binder) {
        	Log.d(TAG, "ServiceConnection onServiceConnected..");
//            // we need to be able to bind again, so unbind
//            try {
//                unbindService(this);
//            } catch (IllegalArgumentException e) {
//            	Log.e(TAG, "unbindService error");
//            }
            //获取service
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
		startActivity(intent);
	}


	@Override
	protected void onResume() {
		Log.d(TAG, "onResume..");
		super.onResume();
		mCursor = musicCache.getAllSongs();
//		mCursor = musicService.getCursor();
		ListAdapter adapter = new MusicListAdapter(this,android.R.layout.simple_expandable_list_item_2,mCursor,new String[]{}, new int[]{});
		setListAdapter(adapter);
	}

	@Override
	protected void onDestroy() {
//		this.unbindService(serviceConnection);
		super.onDestroy();
	}
	

//	//播放音乐
//	protected void playMusic(){
//		String path = mCursor.getString(mCursor.getColumnIndexOrThrow(MediaStore.Audio.Media.DATA));
//		musicService.setDateSource(path);
//		musicService.start();
//	}
//	
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
				Intent intent = new Intent();
				intent.setClass(MyMusicPlayer.this, AboutActivity.class);
				MyMusicPlayer.this.startActivity(intent);
				break;
			case R.id.exit:
				musicService.stop();
				this.finish();
				break;
		}
		return super.onOptionsItemSelected(item);
	}


//	//播放下一首，在自动播放，和按下一首中会用到
//	protected void playNextMusic(){
//		//下一首
//		if(mCursor.moveToNext()){
//			playMusic();
//		}else{
//			//最后一首
//			mCursor.moveToFirst();
//			playMusic();
//		}
//	}
//	//有音乐播放显示的页面
//	protected void playingView(){
//		playAndPause.setVisibility(View.VISIBLE);
//		beforeMusic.setVisibility(View.VISIBLE);
//		nextMusic.setVisibility(View.VISIBLE);
//	}
}