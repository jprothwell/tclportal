package com.shenkun.music;


import java.util.HashMap;


import android.app.Activity;
import android.content.ComponentName;
import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Context;
import android.content.ContextWrapper;
import android.content.Intent;
import android.content.ServiceConnection;
import android.database.Cursor;
import android.net.Uri;
import android.provider.MediaStore;
import android.provider.Settings;
import android.util.Log;
import android.widget.Toast;

public class MusicUtils {
	
	private static String TAG = "MusicUtils";
	
	private static MyMusicService sService = null;
	
	private static HashMap<Context, ServiceBinder> sConnectionMap = new HashMap<Context, ServiceBinder>();
	
	public static class ServiceToken {
		ContextWrapper mWrappedContext;

		ServiceToken(ContextWrapper context) {
			mWrappedContext = context;
		}
	}

	public static ServiceToken bindToService(Activity context,
			ServiceConnection callback) {
		Activity realActivity = context.getParent();
		if (realActivity == null) {
			realActivity = context;
		}
		ContextWrapper cw = new ContextWrapper(realActivity);
		cw.startService(new Intent(cw, MyMusicService.class));
		ServiceBinder sb = new ServiceBinder(callback);
		if (cw.bindService(
				(new Intent()).setClass(cw, MyMusicService.class), sb, 0)) {
			sConnectionMap.put(cw, sb);
			return new ServiceToken(cw);
		}
		Log.e("Music", "Failed to bind to service");
		return null;
	}
	
	
	private static class ServiceBinder implements ServiceConnection {
		
		ServiceConnection mCallback;

		ServiceBinder(ServiceConnection callback) {
			mCallback = callback;
		}

		public void onServiceConnected(ComponentName className,
				android.os.IBinder service) {
			sService = ((MyMusicService.LocalBinder)service).getService();
			
			if (mCallback != null) {
				mCallback.onServiceConnected(className, service);
			}
		}

		public void onServiceDisconnected(ComponentName className) {
			if (mCallback != null) {
				mCallback.onServiceDisconnected(className);
			}
			sService = null;
		}
	}
	//ÉèÖÃÁåÉù
	public static void setRingtone(Context context, long id) {
		Log.d(TAG, "setRingtone");
		
		ContentResolver resolver = context.getContentResolver();
		Uri ringUri = ContentUris.withAppendedId(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, id);
		ContentValues values = new ContentValues(2);
		values.put(MediaStore.Audio.Media.IS_RINGTONE, "1");
		values.put(MediaStore.Audio.Media.IS_ALARM, "1");
		resolver.update(ringUri, values, null, null);
		Settings.System.putString(resolver, Settings.System.RINGTONE,
				ringUri.toString());
		
		//Toast.makeText(context, "set sucess", Toast.LENGTH_SHORT).show();
		String[] cols = new String[] { MediaStore.Audio.Media._ID,
				MediaStore.Audio.Media.DATA, MediaStore.Audio.Media.TITLE };

		String where = MediaStore.Audio.Media._ID + "=" + id;
		Cursor cursor = query(context,
				MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, cols, where, null,null);
		try{
			String message = context.getString(R.string.set_ring,"");
			Toast.makeText(context, message, Toast.LENGTH_SHORT).show();
		}finally {
			if (cursor != null) {
				cursor.close();
			}
		}
		
	}
	
	public static Cursor query(Context context, Uri uri, String[] projection,
			String selection, String[] selectionArgs, String sortOrder) {
		return query(context, uri, projection, selection, selectionArgs,
				sortOrder, 0);
	}
	
	public static Cursor query(Context context, Uri uri, String[] projection,
			String selection, String[] selectionArgs, String sortOrder,
			int limit) {
		try {
			ContentResolver resolver = context.getContentResolver();
			if (resolver == null) {
				return null;
			}
			if (limit > 0) {
				uri = uri.buildUpon().appendQueryParameter("limit", "" + limit)
						.build();
			}
			return resolver.query(uri, projection, selection, selectionArgs,
					sortOrder);
		} catch (UnsupportedOperationException ex) {
			return null;
		}

	}
}
