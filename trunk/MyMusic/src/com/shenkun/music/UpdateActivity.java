package com.shenkun.music;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.params.HttpParams;
import org.json.JSONArray;
import org.json.JSONObject;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager.NameNotFoundException;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;

/**
 * 页面进入，检查服务器更新状况
 * 有新程序包，负责更新
 * 连接网路显示进度条
 * @author kun.shen
 *
 */
public class UpdateActivity extends Activity{
	
	private static String TAG = "UpdateActivity";
	private static String VERSION_URL = "http://192.168.1.104:8080/download/version.json";
	
	private static String DOWNLOAD_URL = "http://192.168.1.104:8080/download/MyMusic.apk";
	
	private String apkName;
	
	private int apkCode;
	
	private String serverName;
	
	private int serverCode;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setContentView(R.layout.update);
		
		getVersion(this);
		getServerVersion();
		Log.d(TAG, "apkName:"+apkName+",serverName:"+serverName+",apkCode:"+apkCode+",serverCode:"+serverCode);
		//比较版本号
		if(apkName.equals(serverName)){
			if(apkCode==serverCode){
				Log.d(TAG, "apkCode==serverCode");
				goNext();
			}else{
				Log.d(TAG, "apkCode!=serverCode");
				if(download()){
					update();
				};//下载
			}
		}else{
			goNext();
		}
	
	}
	private void goNext() {
		Intent intent = new Intent();
		intent.setClass(UpdateActivity.this, TabHostActivity.class);
		this.startActivity(intent);
		
	}
	private boolean download() {
		HttpClient client = new DefaultHttpClient();
        HttpGet get = new HttpGet(DOWNLOAD_URL);
        HttpResponse response;
        try {
                response = client.execute(get);
                HttpEntity entity = response.getEntity();
                long length = entity.getContentLength();
                InputStream is = entity.getContent();
                FileOutputStream fos = null;
                if (is != null) {
                        File file = new File( Environment.getExternalStorageDirectory(),"MyMusic.apk");
                        fos = new FileOutputStream(file);

                        byte[] buf = new byte[1024];
                        int len = 0;
                        while ((len = is.read(buf,0,1024))>=0) {
                                fos.write(buf, 0, len);
                        }

                }
                fos.flush();
                if (fos != null) {
                        fos.close();
                }
        }catch (IOException e) {
            e.printStackTrace();
        }
        return true;
	}

	/*
	 * 获取服务器上版本信息
	 */
	private void getServerVersion(){
		 
		 HttpClient client = new DefaultHttpClient();
         HttpParams httpParams = client.getParams();
         //设置网络超时参数
         HttpConnectionParams.setConnectionTimeout(httpParams, 3000);
         HttpConnectionParams.setSoTimeout(httpParams, 5000);
        
         StringBuilder sb = new StringBuilder();
		try {
			 HttpResponse response = client.execute(new HttpGet(VERSION_URL));
			 Log.d(TAG,"statu:"+response.getStatusLine().getStatusCode());
			HttpEntity entity = response.getEntity();
			if (entity != null) {
	             BufferedReader reader = new BufferedReader(new InputStreamReader(entity.getContent(), "UTF-8"), 1024);
	             String line = null;
	             while ((line = reader.readLine())!= null){
	                 sb.append(line + "\n");
	             }
	             reader.close();
	         }
			 Log.d(TAG,"json:"+sb.toString());
			 JSONArray array = new JSONArray(sb.toString());  
			 if (array.length() > 0) {
                 JSONObject obj = array.getJSONObject(0);
                 serverName = obj.getString("verName");
                 serverCode = Integer.parseInt(obj.getString("verCode"));
         }

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void getVersion(Context context) {
		try {
			apkName = context.getPackageManager().getPackageInfo("com.shenkun.music", 0).versionName;
			apkCode = context.getPackageManager().getPackageInfo("com.shenkun.music", 0).versionCode;
		} catch (NameNotFoundException e) {
			e.printStackTrace();
		}
		
	}

	 void update() {
//		    Uri uri = Uri.fromParts("package", "MyMusic.apk", null);   
//		    Intent it = new Intent(Intent.ACTION_DELETE, uri);   
//		    startActivity(it);

		 Log.d(TAG, "update..........");
         Intent intent = new Intent(Intent.ACTION_VIEW);
         intent.setDataAndType(Uri.fromFile(new File(Environment
                         .getExternalStorageDirectory(), "MyMusic.apk")),
                         "application/vnd.android.package-archive");
         startActivity(intent);
 }

}
