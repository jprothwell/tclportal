package com.tcl.android;

import android.app.Activity;
import android.os.Bundle;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RadioGroup.OnCheckedChangeListener;
import android.widget.TextView;
/**
 * radio°´Å¥
 * @author kun.shen
 *
 */
public class RadioGroupDemo extends Activity {
   
	public TextView questionText;
	
	public RadioGroup radioGroup;
	
	public RadioButton boyButton,girlButtion;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        questionText = (TextView)findViewById(R.id.radioTextView);
        radioGroup = (RadioGroup)findViewById(R.id.radioGroup);
        boyButton = (RadioButton)findViewById(R.id.optionBoy);
        girlButtion = (RadioButton)findViewById(R.id.optionGirl);
        radioGroup.setOnCheckedChangeListener(radioChange);
    }
    
    private OnCheckedChangeListener radioChange = new OnCheckedChangeListener(){

		@Override
		public void onCheckedChanged(RadioGroup group, int checkedId) {
			if(checkedId==boyButton.getId()){
				questionText.setText(boyButton.getText());
			}else if(checkedId==girlButtion.getId()){
				questionText.setText(girlButtion.getText());
			}
		}
    	
    };
}