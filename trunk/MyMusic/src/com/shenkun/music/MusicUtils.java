package com.shenkun.music;


import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.net.Uri;
import android.provider.MediaStore;
import android.provider.Settings;
import android.util.Log;
import android.widget.Toast;

public class MusicUtils {
	
	private static String TAG = "MusicUtils";
	
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
		
		Toast.makeText(context, "set sucess", Toast.LENGTH_SHORT).show();
//		String[] cols = new String[] { MediaStore.Audio.Media._ID,
//				MediaStore.Audio.Media.DATA, MediaStore.Audio.Media.TITLE };
//
//		String where = MediaStore.Audio.Media._ID + "=" + id;
//		Cursor cursor = query(context,
//				MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, cols, where, null,null);
//		try{
//			String message = context.getString(R.string.set_ring,cursor.getString(2));
//			Toast.makeText(context, message, Toast.LENGTH_SHORT).show();
//		}finally {
//			if (cursor != null) {
//				cursor.close();
//			}
//		}
		
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
