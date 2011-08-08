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
       

    //��serviceͨѶ
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
	     //bindService��Context�ķ���
		 Log.d(TAG, "bindService......");
		 getApplicationContext().bindService(musicServiceIntent(), serviceConnection, Context.BIND_AUTO_CREATE);
	}
	
	private Intent musicServiceIntent(){
		return new Intent(this,MyMusicService.class);
	}
	
	private Intent aboutActivityIntent(){
		return new Intent(this,AboutActivity.class);
	}
	
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