package com.shenkun.music;

import android.app.Application;
import android.content.ContentResolver;
import android.database.Cursor;
import android.provider.MediaStore;
import android.util.Log;

public class MusicApplication extends Application{
	
	private static final String TAG = "MusicApplication";
	
	public MusicCache musicCache;
	@Override
	public void onCreate() {
		super.onCreate();
		musicCache = new MusicCache(this);
	}
	
}
