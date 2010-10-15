package com.tcl.android;

import android.app.Activity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.widget.TextView;

public class TouchPaint extends Activity {
   
	private TextView textView;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        textView = (TextView)findViewById(R.id.textView);
    }

	@Override
	public boolean onTouchEvent(MotionEvent event) {
		float x = event.getX();
		float y = event.getY();
		switch(event.getAction()){
		case MotionEvent.ACTION_DOWN:textView.setText("down(x:"+x+",+y:"+y+")");
		case MotionEvent.ACTION_MOVE:textView.setText("down(x:"+x+",+y:"+y+")");
		case MotionEvent.ACTION_UP:textView.setText("down(x:"+x+",+y:"+y+")");
		}
		return super.onTouchEvent(event);
	}
    
    
}