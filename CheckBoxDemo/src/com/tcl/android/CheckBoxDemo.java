package com.tcl.android;

import android.app.Activity;
import android.os.Bundle;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.CompoundButton.OnCheckedChangeListener;
import android.widget.TextView;
/**
 * checkBox
 * @author kun.shen
 *
 */
public class CheckBoxDemo extends Activity {
    
	private TextView textView;
	
	private CheckBox histortyCheckBox;
	
	private CheckBox psychologyCheckBox;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        textView = (TextView)findViewById(R.id.fond);
        histortyCheckBox = (CheckBox)findViewById(R.id.histortyCheck);
        psychologyCheckBox = (CheckBox)findViewById(R.id.psychologyCheck);
        
        histortyCheckBox.setOnCheckedChangeListener(occl);
        psychologyCheckBox.setOnCheckedChangeListener(occl);
       
    }
    private OnCheckedChangeListener occl = new OnCheckedChangeListener(){

		@Override
		public void onCheckedChanged(CompoundButton buttonView,
				boolean isChecked) {
			
			String text = getString(R.string.fond);
			String historty = getString(R.string.history);
			String psychology = getString(R.string.psychology);
			if(histortyCheckBox.isChecked()==true&&psychologyCheckBox.isChecked()==true){
				textView.setText(text+":"+historty+","+psychology);
			}else if(histortyCheckBox.isChecked()==true&&psychologyCheckBox.isChecked()==false){
				textView.setText(text+":"+historty);
			}else if(histortyCheckBox.isChecked()==false&&psychologyCheckBox.isChecked()==true){
				textView.setText(text+":"+psychology);
			}else{
				textView.setText(text);
			}
		}
    };
    
}