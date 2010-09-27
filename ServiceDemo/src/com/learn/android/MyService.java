package com.learn.android;

import android.app.Service;
import android.content.Intent;
import android.os.Binder;
import android.os.IBinder;
import android.text.format.Time;
import android.util.Log;

public class MyService extends Service{
	
	private static final String TAG = "MyService";
	private MyBinder mBinder = new MyBinder();
	@Override
	public IBinder onBind(Intent arg0) {
		Log.e(TAG,"start binder....");
		return mBinder;
	}
	
	
	@Override
	public void onCreate() {
		Log.e(TAG,"start onStart....");
		super.onCreate();
	}


	@Override
	public void onDestroy() {
		Log.e(TAG,"start onDestroy....");
		super.onDestroy();
	}


	@Override
	public void onRebind(Intent intent) {
		Log.e(TAG,"start onRebind....");
		super.onRebind(intent);
	}


	@Override
	public void onStart(Intent intent, int startId) {
		Log.e(TAG,"start onStart....");
		super.onStart(intent, startId);
	}


	@Override
	public boolean onUnbind(Intent intent) {
		Log.e(TAG,"start onUnbind....");
		return super.onUnbind(intent);
	}

	//getTime
	public String getTime(){
		Time t = new Time();
		t.setToNow();
		return t.toString();
	}
	class MyBinder extends Binder{
		MyService getService(){
			return MyService.this;
		}
}

 
}