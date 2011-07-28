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
 * һ�����ֲ�����
 * 1.�Զ�ʶ��SD�����ֻ��ڵ�����
 * 2.ѡ���ļ��н��м������֣�������ǧǧ�����ļ������ַ������
 * 3.��������������
 * @author kun.shen
 */
/**
 * �ṩmusic��չ�֣������б�
 * �ڲ������֮�󣬻���ֽ��ܵ�service�Ĺ㲥��״̬���������б���ʾ
 * 
 * ��עActivity��Service�Ľ�����ʽ
 * Activity��ʾ״̬��service�ǿ�����Ƶ��ʹ���˳�activityʱ���ֲ��Ų���Ӱ��
 */
public class MyMusicPlayer extends ListActivity {
   
	private static final String TAG = "MyMusicPlayer";
	
	private MusicCache musicCache;
	
	private MyMusicService musicService = null;
	
	private Cursor mCursor = null;
	 
	private TextView title;
	
//	private Button playAndPause;//���ź���ͣ
//	
//	private Button beforeMusic;//ǰһ��
//	
//	private Button nextMusic; //��һ��
	
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
        //bindService��Context�ķ���
        bindService(intent, serviceConnection, Context.BIND_AUTO_CREATE);
        
//        playAndPause.setOnClickListener(new Button.OnClickListener(){
//
//			@Override
//			public void onClick(View view) {
//				if(musicService!=null&&musicService.isPlaying()){
//					//���������ڲ���
//					playAndPause.setText(R.string.play);
//					musicService.pause();
//				}else if(musicService!=null){
//					//û�������ڲ���
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
//				//�������
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
        }

        public void onServiceDisconnected(ComponentName classname) {
        	musicService = null;
        }
    };
    /*
     * �����б���������ͣ����Է�ΪArrayAdapter��SimpleAdapter��SimpleCursorAdapter
     * SimpleCursorAdapter api������
     * An easy adapter to map columns from a cursor to TextViews or ImageViews defined in an XML file.
     * You can specify which columns you want, which views you want to display the columns, and the XML file that defines the appearance of these views.
    
     * ��ϸ����http://www.cnblogs.com/allin/archive/2010/05/11/1732200.html
     * android.R.layout.simple_expandable_list_item_2ϵͳ����õĲ����ļ�
		�������������һ���������ݿ���е�String�����飬һ�����������ļ��ж�Ӧ���id��int�����顣
		���������Զ��Ľ�String����������ʾ��ÿһ������ӳ�䵽�����ļ���Ӧid������ϡ�
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
     * �����б�ĸ�Ӧ�¼�
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
	

//	//��������
//	protected void playMusic(){
//		String path = mCursor.getString(mCursor.getColumnIndexOrThrow(MediaStore.Audio.Media.DATA));
//		musicService.setDateSource(path);
//		musicService.start();
//	}
//	
	//����menu
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


//	//������һ�ף����Զ����ţ��Ͱ���һ���л��õ�
//	protected void playNextMusic(){
//		//��һ��
//		if(mCursor.moveToNext()){
//			playMusic();
//		}else{
//			//���һ��
//			mCursor.moveToFirst();
//			playMusic();
//		}
//	}
//	//�����ֲ�����ʾ��ҳ��
//	protected void playingView(){
//		playAndPause.setVisibility(View.VISIBLE);
//		beforeMusic.setVisibility(View.VISIBLE);
//		nextMusic.setVisibility(View.VISIBLE);
//	}
}