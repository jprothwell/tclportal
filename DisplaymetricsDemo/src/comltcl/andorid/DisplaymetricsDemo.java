package comltcl.andorid;

import android.app.Activity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;
/**
 * 点击获取屏幕分辨率
 * @author kun.shen
 *
 */
public class DisplaymetricsDemo extends Activity {
	
	private TextView textView;
	
	private Button button;
	
	private DisplayMetrics displayMetric;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        textView = (TextView)findViewById(R.id.resolutionValue);
        button = (Button)findViewById(R.id.button);
        button.setOnClickListener(new OnClickListener(){
			@Override
			public void onClick(View v) {
				displayMetric = new DisplayMetrics();
				getWindowManager().getDefaultDisplay().getMetrics(displayMetric);
				String str = "分辨率:"+displayMetric.widthPixels+"*"+displayMetric.heightPixels;
				textView.setText(str);
			}
        	
        });
    }
}