package com.shenkun.music;

import android.content.ContentResolver;
import android.database.Cursor;
import android.provider.MediaStore;
import android.util.Log;

public class MusicCache {
	
	private static String TAG = "MusicCache";
	
	MusicApplication musicApplication;
	
	ContentResolver contentResolver;

	public MusicCache(MusicApplication musicApplication) {
		this.musicApplication = musicApplication;
		contentResolver = musicApplication.getContentResolver();
	}
	//获取所有歌曲
	public Cursor getAllSongs(){
		if(contentResolver==null){
			Log.d(TAG,"resolver null" );
			return null;
		}
		return contentResolver.query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, null, null, null, MediaStore.Audio.Media.DEFAULT_SORT_ORDER);
	}
}
