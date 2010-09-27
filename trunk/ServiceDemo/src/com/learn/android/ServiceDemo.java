package com.learn.android;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class ServiceDemo extends Activity implements OnClickListener{
   
	private Context mContext;
	private TextView mTextView;
	private Button startServiceButton;
	private Button stopServiceButton;
	private Button bindServiceButton;
	private Button unbindServiceButton;
	private MyService myService;
	
	private ServiceConnection mServiceConnection = new ServiceConnection(){
		public void onServiceConncted(ComponentName name,IBinder service){
			myService = ((MyService.MyBinder)service).getService();
			mTextView.setText("I an forme service:"+myService.getTime());
		}

		@Override
		public void onServiceDisconnected(ComponentName name) {
			// TODO Auto-generated method stub
			
		}
		@Override
		public void onServiceConnected(ComponentName name, IBinder service) {
			// TODO Auto-generated method stub
			
		}
	};
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        setupViews();
    }
    
    public void setupViews(){
    	mContext = ServiceDemo.this;
		mTextView = (TextView)findViewById(R.id.text);
		
		startServiceButton = (Button)findViewById(R.id.startService);
		stopServiceButton = (Button)findViewById(R.id.stopService);
		bindServiceButton = (Button)findViewById(R.id.bindService);
		unbindServiceButton = (Button)findViewById(R.id.unbindService);
		
		startServiceButton.setOnClickListener(this);
		stopServiceButton.setOnClickListener(this);
		bindServiceButton.setOnClickListener(this);
		unbindServiceButton.setOnClickListener(this);
    }
	@Override
	public void onClick(View v) {
		if(v == startServiceButton){
			Intent i = new Intent();
			i.setClass(ServiceDemo.this, MyService.class);
		}else if(v == stopServiceButton){
			Intent i = new Intent();
			i.setClass(ServiceDemo.this, MyService.class);
			mContext.startService(i);
		}else if(v == bindServiceButton){
			Intent i = new Intent();
			i.setClass(ServiceDemo.this, MyService.class);
			mContext.bindService(i, mServiceConnection, BIND_AUTO_CREATE);
		}else{
			mContext.unbindService(mServiceConnection);
		}
	}
	
}