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
 * ���ŵĸ�������
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
	
	private ImageButton playAndPause;//���ź���ͣ
	
	private ImageButton beforeMusic;//ǰһ��
	
	private ImageButton nextMusic; //��һ��
	
	private SeekBar seekBar;//������
	
	private ImageView imageView;
	
	private int position;//������λ��
	
	 static boolean prgress = true; 
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.play);
		imageView = (ImageView)findViewById(R.id.play_image);
		//ͼƬ�ұ�������ť
		playList = (ImageButton)findViewById(R.id.play_list);
		shuffle = (ImageButton)findViewById(R.id.pay_shuffle);
		repeat = (ImageButton)findViewById(R.id.pay_repeat);
		//�м�����ͼ���ı���Ϣ
		aritstText = (TextView)findViewById(R.id.play_text_artist);
		ablumText = (TextView)findViewById(R.id.play_text_album);
		songText = (TextView)findViewById(R.id.play_text_song);
		
		//���ţ�ǰһ�ף���һ��
		playAndPause = (ImageButton)findViewById(R.id.play_pause);
		beforeMusic = (ImageButton)findViewById(R.id.play_before);
		nextMusic = (ImageButton)findViewById(R.id.play_next);
		
		Intent intent = new Intent(this,MyMusicService.class);
        this.startService(intent);
        //bindService��Context�ķ���
        bindService(intent, serviceConnection, Context.BIND_AUTO_CREATE);
		
     
        playAndPause.setOnClickListener(playAndPauseClickListen);
        beforeMusic.setOnClickListener(beforeClickListen);
        nextMusic.setOnClickListener(nextClickListen);
        
        //������
        seekBar = (SeekBar)findViewById(R.id.progressBar);
        seekBar.setOnSeekBarChangeListener(seekBarChangeListener);
    	
        new ProgressThread().start();
        IntentFilter filter = new IntentFilter();
        filter.addAction(MyMusicService.COMPLETE);
        filter.addAction(MyMusicService.PREPARE);
        registerReceiver(broadcastReciver, filter);
	}
	//������ͣ
	private Button.OnClickListener playAndPauseClickListen = new Button.OnClickListener(){

		@Override
		public void onClick(View v) {
			if(musicService!=null&&musicService.isPlaying()){
				//���������ڲ���
				//playAndPause.setText(R.string.play);
				musicService.pause();
				setSeeBarStop();
			}else if(musicService!=null){
				//û�������ڲ���
				//playAndPause.setText(R.string.pause);
				musicService.start();
				setSeeBarMove();
			}
		}
		
	};
	//ǰһ��
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
	//��һ��
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
	//������
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
		//��ʼ�϶�
		@Override
		public void onStartTrackingTouch(SeekBar seekBar) {
			
			//musicService.pause();
		}
		//�϶����
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
					//�������
//					playAndPause.setText(R.string.pause);
					musicService.playNextMusic();
					setSongTextValue();
					setMusicTime();
					position = 0;
					seekBar.setProgress(position);
				}
				
			}
	    	
	    };
	    
	    
	 //��serviceͨѶ
    private ServiceConnection serviceConnection = new ServiceConnection() {
        public void onServiceConnected(ComponentName classname, IBinder binder) {
        	Log.d(TAG, "ServiceConnection onServiceConnected..");
//            // we need to be able to bind again, so unbind
//            try {
//                unbindService(this);
//            } catch (IllegalArgumentException e) {
//            	Log.e(TAG, "unbindService error");
//            }
            //��ȡservice
        	musicService  = ((MyMusicService.LocalBinder)binder).getService();
        	cursor = musicService.getCursor();
        	setSongTextValue();
        	setMusicTime();
        }

        public void onServiceDisconnected(ComponentName classname) {
        	musicService = null;
        }
    };
    
    //������һ�׸����������
    private void setSongTextValue(){
    	aritstText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.ARTIST)));
		ablumText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.ALBUM)));
		songText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.TITLE)));
    }
    
    //��Ƶʱ��/1000(��ȷ����)��ͬʱҲ��ΪseeBar�ĳ��ȡ�
    //ÿ��һ�룬�ƶ����ƶ�һ�Σ�������λ��Ҳ����Ƶ���ŵ�λ�á�
    Handler handlers = new Handler(){

		@Override
		public void handleMessage(Message msg) {
			super.handleMessage(msg);
			seekBar.setProgress(msg.what);
			//musicService.seekTo(msg.what);
		}
    	
    };
    
    
    //���ƽ�����
    class ProgressThread extends Thread{

		@Override
		public void run() {
			while(!Thread.currentThread().isInterrupted()){
				if(prgress){
					//int postion = seekBar.getProgress(); �����postion��Ϊ�ֲ������������2���̣߳������ִ��2�飬Ϊʲô��
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
    
    //��ȡ���ֳ��ȣ����������������seekbar����
    private  void setMusicTime(){
    	seekBar.setMax((int)musicService.getMediaLength());
    };
    //�������ƶ�
    private void setSeeBarMove(){
    	prgress = true;
    }
    //������ֹͣ
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


