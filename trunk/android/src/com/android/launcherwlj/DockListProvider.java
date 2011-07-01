/**
 * @（#）:MemoListProvider.java
 * @description:数据库操作封装类
 * @author: wanglijuan 2011.1.17
 * @version: Version No.1.0
 * @modify:
 * @Copyright:wisky
 */
package com.android.launcherwlj;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;


public class DockListProvider {
    //数据库关键字id
	public static final String KEY_ROWID = "_id";
	//保存标题字段
	public static final String KEY_TITLE = "title";
	//保存intent内容字段
	public static final String KEY_INTENT = "intent";
	//保存DockBar中的位置
	public static final String KEY_POSITION = "position";
	//数据库文件名
	private static final String DATABASE_NAME = "Dock";
	//表名
	private static final String DATABASE_TABLE = "titles";
	//版本号
	private static final int DATABASE_VERSION = 8;
	//创建数据库表
	private static final String DATABASE_CREATE = "create table titles (_id integer primary key autoincrement, "
			+ "title text not null, intent text not null, "
			+ "position integer);";
	private final Context context;
	private DatabaseHelper DBHelper;
	private SQLiteDatabase db;

	public DockListProvider(Context ctx) {
		this.context = ctx;
		DBHelper = new DatabaseHelper(context);
	}

	private static class DatabaseHelper extends SQLiteOpenHelper {
		DatabaseHelper(Context context) {
			super(context, DATABASE_NAME, null, DATABASE_VERSION);
		}

		@Override
		public void onCreate(SQLiteDatabase db) {
			db.execSQL(DATABASE_CREATE);
		}

		@Override
		public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
			db.execSQL("DROP TABLE IF EXISTS titles");
			onCreate(db);
		}
	}
	
	// ---打开数据库---
	    public DockListProvider open() throws SQLException{   
	    	db = DBHelper.getWritableDatabase();
	        return this;
	       }
	    
	    
	    //---关闭数据库---
	    public void close(){
	    	DBHelper.close();
	    }
	    
	    
	    //---向数据库中插入一个标题---
    	public long insertTitle(String title, String intent, int position){
    		ContentValues initialValues = new ContentValues();
    		initialValues.put(KEY_TITLE,title);
    		initialValues.put(KEY_INTENT,intent);
    		initialValues.put(KEY_POSITION, position);
    		return db.insert(DATABASE_TABLE, null,initialValues);
    		}
    	
    	
    	
    	//---删除所有标题---
    	 public boolean deleteAll(){
    		 return db.delete(DATABASE_TABLE,null, null) > 0;
    		 }
    	 
    	 
	    //---删除一个指定标题---
    	 public boolean deleteTitle(long rowId){
    		 return db.delete(DATABASE_TABLE, KEY_ROWID +"=" + rowId, null) > 0;
    		 }
    	 
    	 
    	 //---检索所有标题---
    	 public Cursor getAllTitles(){
    		 return db.query(DATABASE_TABLE, new String[]{
    				 KEY_ROWID,KEY_TITLE,KEY_INTENT,KEY_POSITION},null,null,null,null,null);
    		 }
    	 //---按标题和内容检索一个指定标题---
    	 public Cursor getItemByTitle(int position) throws SQLException{
    		 Cursor mCursor =db.query(true, DATABASE_TABLE, new String[]
          {KEY_ROWID,KEY_TITLE,KEY_INTENT,KEY_POSITION},KEY_POSITION + "=" +
          position,null,null,null,null,null);
    	  if (mCursor != null)
            {mCursor.moveToFirst();
            }return mCursor;
            }
    	 //---更新一个标题---
    	 public boolean updateTitle(String title,String intent, int position){
    		 ContentValues args = new ContentValues();
    		 args.put(KEY_TITLE, title);
    		 args.put(KEY_INTENT,intent);
    		 args.put(KEY_POSITION, position);
    		 return db.update(DATABASE_TABLE, args,KEY_INTENT + "=" + intent, null) > 0;
    		 }
}
