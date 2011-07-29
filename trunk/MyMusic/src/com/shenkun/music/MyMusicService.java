package com.shenkun.music;

import java.io.IOException;

import android.app.Service;
import android.content.Intent;
import android.database.Cursor;
import android.media.MediaPlayer;
import android.os.Binder;
import android.os.IBinder;
import android.os.Parcel;
import android.os.RemoteException;
import android.provider.MediaStore;
import android.util.Log;
/**
 * ʵ�ֲ�����ͣ�ȹ��ܣ���service�У�����Ӧ�ã�����Ӱ�쵽�����Ĳ���
 * @author kun.shen
 *
 */
public class MyMusicService extends Service{
	
	private static final String TAG = "MyMusicService";
	
	private MediaPlayer mediaPlayer = null;
	
	private LocalBinder localBinder = null;
	
	private MusicCache musicCache;
	
	public Cursor cursor;
	
	public static final String COMPLETE = "com.shenkun.play.complete";
	
	public static final String PREPARE = "com.shenkun.play.prepare";
	
	@Override
	public void onCreate() {
		super.onCreate();
		 MusicApplication  musicApplication = ((MusicApplication)getApplication());
	     musicCache = musicApplication.musicCache;
	     cursor = musicCache.getAllSongs();
	     
		mediaPlayer = new MediaPlayer();
		localBinder = new LocalBinder();
		mediaPlayer.setOnPreparedListener(preparedListener);
		mediaPlayer.setOnCompletionListener(completionListener);
	}
	//�����������
	MediaPlayer.OnCompletionListener completionListener = new MediaPlayer.OnCompletionListener(){

		@Override
		public void onCompletion(MediaPlayer mp) {
			Intent intent = new Intent(COMPLETE);
			sendBroadcast(intent);
		}
		
	};
	//����׼������
	MediaPlayer.OnPreparedListener preparedListener = new MediaPlayer.OnPreparedListener(){

		@Override
		public void onPrepared(MediaPlayer mp) {
			Intent intent = new Intent(PREPARE);
			sendBroadcast(intent);
		}
	};
	
	
	@Override
	public IBinder onBind(Intent intent) {
		return localBinder;
	}
	
	
	class LocalBinder extends Binder{
		
		public  MyMusicService getService(){
			return MyMusicService.this;
		}

		@Override
		protected boolean onTransact(int code, Parcel data, Parcel reply,
				int flags) throws RemoteException {
			return super.onTransact(code, data, reply, flags);
		}
		
	}
	
	public void setDateSource(String path){
		mediaPlayer.reset();
		try {
			mediaPlayer.setDataSource(path);
			mediaPlayer.prepare();
		} catch (IOException e) {
			e.printStackTrace();
			Log.e(TAG, "setDateSource error");
		}
	}
	public void start(){
		mediaPlayer.start();
	}
	public void stop(){
		mediaPlayer.stop();
	}
	public void pause(){
		mediaPlayer.pause();
	}
	public boolean isPlaying(){
		return mediaPlayer.isPlaying();
	}
	public int getPositon(){
		return mediaPlayer.getCurrentPosition();
	}
	
	
	//��������
	protected void playMusic(){
		String path = cursor.getString(cursor.getColumnIndexOrThrow(MediaStore.Audio.Media.DATA));
		setDateSource(path);
		start();
	}
	
	//������һ�ף����Զ����ţ��Ͱ���һ���л��õ�
	protected void playNextMusic(){
		//��һ��
		if(cursor.moveToNext()){
			playMusic();
		}else{
			//���һ��
			cursor.moveToFirst();
			playMusic();
		}
	}
	
	protected Cursor getCursor(){
		return cursor;
	}
	
	protected boolean moveToPosition(int position){
		return cursor.moveToPosition(position);
	}
}
