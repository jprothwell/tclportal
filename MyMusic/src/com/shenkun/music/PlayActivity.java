package com.shenkun.music;


import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.database.Cursor;
import android.os.Bundle;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.provider.MediaStore;
import android.util.Log;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.TextView;
/**
 * 播放的歌曲控制
 * @author kun.shen
 *
 */
public class PlayActivity extends Activity{
	
	private final static String TAG = "PlayActivity";
	
	private MyMusicService musicService = null;
	
	private Cursor cursor;
	
	private ImageButton playList;
	
	private ImageButton shuffle;
	
	private ImageButton repeat;
	
	private TextView aritstText;
	
	private TextView ablumText;
	
	private TextView songText;
	
	private ImageButton playAndPause;//播放和暂停
	
	private ImageButton beforeMusic;//前一首
	
	private ImageButton nextMusic; //后一首
	
	private SeekBar seekBar;//进度条
	
	private ImageView imageView;
	
	private int position;//进度条位置
	
	 static boolean prgress = true; 
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.play);
		imageView = (ImageView)findViewById(R.id.play_image);
		//图片右边三个按钮
		playList = (ImageButton)findViewById(R.id.play_list);
		shuffle = (ImageButton)findViewById(R.id.pay_shuffle);
		repeat = (ImageButton)findViewById(R.id.pay_repeat);
		//中间三个图标文本信息
		aritstText = (TextView)findViewById(R.id.play_text_artist);
		ablumText = (TextView)findViewById(R.id.play_text_album);
		songText = (TextView)findViewById(R.id.play_text_song);
		
		//播放，前一首，后一首
		playAndPause = (ImageButton)findViewById(R.id.play_pause);
		beforeMusic = (ImageButton)findViewById(R.id.play_before);
		nextMusic = (ImageButton)findViewById(R.id.play_next);
		
		Intent intent = new Intent(this,MyMusicService.class);
        this.startService(intent);
        //bindService是Context的方法
        bindService(intent, serviceConnection, Context.BIND_AUTO_CREATE);
		
     
        playAndPause.setOnClickListener(playAndPauseClickListen);
        beforeMusic.setOnClickListener(beforeClickListen);
        nextMusic.setOnClickListener(nextClickListen);
        
        //进度条
        seekBar = (SeekBar)findViewById(R.id.progressBar);
        seekBar.setOnSeekBarChangeListener(seekBarChangeListener);
    	
        new ProgressThread().start();
        IntentFilter filter = new IntentFilter();
        filter.addAction(MyMusicService.COMPLETE);
        filter.addAction(MyMusicService.PREPARE);
        registerReceiver(broadcastReciver, filter);
	}
	//播放暂停
	private Button.OnClickListener playAndPauseClickListen = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			if(musicService!=null&&musicService.isPlaying()){
				//有音乐正在播放
				//playAndPause.setText(R.string.play);
				musicService.pause();
				setSeeBarStop();
			}else if(musicService!=null){
				//没有音乐在播放
				//playAndPause.setText(R.string.pause);
				musicService.start();
				setSeeBarMove();
			}
		}
		
	};
	//前一首
	private Button.OnClickListener beforeClickListen = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			if(musicService!=null&&musicService.isPlaying()){
				cursor.moveToPrevious();
				musicService.playMusic();
				setSongTextValue();
				setMusicTime();
				position = 0;
				seekBar.setProgress(position);
				setSeeBarMove();
			}
		}
		
	};
	//后一首
	private Button.OnClickListener nextClickListen = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			musicService.playNextMusic();
			setSongTextValue();
			setMusicTime();
			position = 0;
			seekBar.setProgress(position);
			setSeeBarMove();
		}
		
	};
	//进度条
	SeekBar.OnSeekBarChangeListener seekBarChangeListener = new SeekBar.OnSeekBarChangeListener(){
		@Override
		public void onProgressChanged(SeekBar seekBar, int progress,
				boolean fromUser) {
			if (!fromUser) {
				return;
			}
			Log.d(TAG, "OnSeekBarChangeListener.onProgressChanged"+progress);
			position = progress;
			musicService.seekTo(position);
		}
		//开始拖动
		@Override
		public void onStartTrackingTouch(SeekBar seekBar) {
			
			//musicService.pause();
		}
		//拖动完毕
		@Override
		public void onStopTrackingTouch(SeekBar seekBar) {
//			musicService.seekTo(seekBar.getProgress());
//			if(musicService.isPlaying()){
//				musicService.start();
//			}else{
//				musicService.pause();
//			}
		}
	};
	
	 private BroadcastReceiver broadcastReciver = new BroadcastReceiver(){

			@Override
			public void onReceive(Context context, Intent intent) {
				String action = intent.getAction();
				if((MyMusicService.COMPLETE).equals(action)){
					//播放完毕
//					playAndPause.setText(R.string.pause);
					musicService.playNextMusic();
					setSongTextValue();
					setMusicTime();
					position = 0;
					seekBar.setProgress(position);
				}
				
			}
	    	
	    };
	    
	    
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
        	cursor = musicService.getCursor();
        	setSongTextValue();
        	setMusicTime();
        }

        public void onServiceDisconnected(ComponentName classname) {
        	musicService = null;
        }
    };
    
    //设置下一首歌曲相关内容
    private void setSongTextValue(){
    	aritstText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.ARTIST)));
		ablumText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.ALBUM)));
		songText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.TITLE)));
    }
    
    //音频时间/1000(精确到秒)，同时也作为seeBar的长度。
    //每隔一秒，移动条移动一次，所处的位置也是音频播放的位置。
    Handler handlers = new Handler(){

		@Override
		public void handleMessage(Message msg) {
			super.handleMessage(msg);
			seekBar.setProgress(msg.what);
			//musicService.seekTo(msg.what);
		}
    	
    };
    
    
    //控制进度条
    class ProgressThread extends Thread{

		@Override
		public void run() {
			while(!Thread.currentThread().isInterrupted()){
				if(prgress){
					//int postion = seekBar.getProgress(); 如果将postion设为局部变量，会出现2个线程，代码会执行2遍，为什么？
					Log.d(TAG, "position:"+position+",max:"+seekBar.getMax());
					try {
						Thread.sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					if(position<seekBar.getMax()){
						position = position + 1;
					}else{
						position = 0;
					}
					
					Message message = new Message();
					message.what = position;
					handlers.sendMessage(message);
				}
			}
		}
    	
    }
    
    //获取音乐长度，根据这个长度设置seekbar长度
    private  void setMusicTime(){
    	seekBar.setMax((int)musicService.getMediaLength());
    };
    //进度条移动
    private void setSeeBarMove(){
    	prgress = true;
    }
    //进度条停止
    private void setSeeBarStop(){
    	prgress = false;
    }
	@Override
	protected void onDestroy() {
		super.onDestroy();
	}
	@Override
	public boolean onMenuItemSelected(int featureId, MenuItem item) {
		
		int itemId = item.getItemId();
		switch(itemId){
			case R.id.ring:
				if(musicService!=null){
					Log.d(TAG, "onMenuItemSelected R.id.ring");
					MusicUtils.setRingtone(this, getAudioId());
					return true;
				}
		}
		return super.onOptionsItemSelected(item);
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		//menu.add("play");
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.play_menu, menu);
		return true;
	}
	
	public long getAudioId() {
		Log.d(TAG, "getAudioId...");
		return musicService.getSessionID();
	}
}


