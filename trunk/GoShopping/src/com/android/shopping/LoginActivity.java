package com.android.shopping;


import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.Animation.AnimationListener;
import android.widget.ImageView;

/**
 * µÇÂ¼½çÃæ
 * @author kun.shen
 *
 */
public class LoginActivity extends Activity{

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.login);
		ImageView imageView=(ImageView)this.findViewById(R.id.login);
		imageView.setImageResource(R.drawable.login);
		AlphaAnimation aa=new AlphaAnimation(0.1f,1.0f);
		aa.setDuration(5000);
		imageView.startAnimation(aa);
		aa.setAnimationListener(new AnimationListener(){

			@Override
			public void onAnimationEnd(Animation arg0) {
				Intent intent = new Intent(LoginActivity.this,GoShoppingActivity.class);
				startActivity(intent);
			}

			@Override
			public void onAnimationRepeat(Animation arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void onAnimationStart(Animation arg0) {
				// TODO Auto-generated method stub
				
			}
			
		});
	}
	
}
