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
import android.os.IBinder;
import android.provider.MediaStore;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.ProgressBar;
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
	
	private ProgressBar progressBar;//������
	
	private ImageView imageView;
	
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
		
        //������
        progressBar = (ProgressBar)findViewById(R.id.progressBar);
		
        
        playAndPause.setOnClickListener(new Button.OnClickListener(){

			@Override
			public void onClick(View view) {
				if(musicService!=null&&musicService.isPlaying()){
					//���������ڲ���
					//playAndPause.setText(R.string.play);
					musicService.pause();
				}else if(musicService!=null){
					//û�������ڲ���
					//playAndPause.setText(R.string.pause);
					musicService.start();
				}
			}
        	
        });
        
        beforeMusic.setOnClickListener(new Button.OnClickListener(){

			@Override
			public void onClick(View v) {
				if(musicService!=null&&musicService.isPlaying()){
					cursor.moveToPrevious();
					musicService.playMusic();
				}
			}
        	
        });
        
        nextMusic.setOnClickListener(new Button.OnClickListener(){

			@Override
			public void onClick(View v) {
				musicService.playNextMusic();
			}
        });
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
        
        IntentFilter filter = new IntentFilter();
        filter.addAction(MyMusicService.COMPLETE);
        filter.addAction(MyMusicService.PREPARE);
        registerReceiver(broadcastReciver, filter);
	}

	 private BroadcastReceiver broadcastReciver = new BroadcastReceiver(){

			@Override
			public void onReceive(Context context, Intent intent) {
				String action = intent.getAction();
				if((MyMusicService.COMPLETE).equals(action)){
					//�������
//					playAndPause.setText(R.string.pause);
					musicService.playNextMusic();
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
            aritstText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.ARTIST)));
    		ablumText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.ALBUM)));
    		songText.setText(cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.TITLE)));
        }

        public void onServiceDisconnected(ComponentName classname) {
        	musicService = null;
        }
    };
}
