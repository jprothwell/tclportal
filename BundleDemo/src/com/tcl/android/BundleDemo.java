package com.tcl.android;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
/**
 * 2个页面的关联
 * @author kun.shen
 *
 */
public class BundleDemo extends Activity {
    
	public TextView questionText;
	
	public RadioGroup radioGroup;
	
	public RadioButton boyButton,girlButton;
	
	public Button button;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        questionText = (TextView)findViewById(R.id.Button);
        radioGroup = (RadioGroup)findViewById(R.id.radioGroup);
        boyButton = (RadioButton)findViewById(R.id.optionBoy);
        girlButton = (RadioButton)findViewById(R.id.optionGirl);
        button = (Button)findViewById(R.id.Button);
        
        button.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				String name = (String)questionText.getText();
				String sex = "";
				if(boyButton.isChecked()){
					sex = "man";
				}else{
					sex = "women";
				}
				Intent intent = new Intent();
				intent.setClass(BundleDemo.this, Result.class);
				Bundle bundle = new Bundle();
				bundle.putString("name", name);
				bundle.putString("sex", sex);
				intent.putExtras(bundle);
				startActivity(intent);
			}
        	
        });
    }
}