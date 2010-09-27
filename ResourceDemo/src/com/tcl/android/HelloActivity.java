package com.tcl.android;

import android.app.Activity;
import android.os.Bundle;
/**
 * 涉及横屏和竖屏以及国际化
 * @author kun.shen
 *
 */
public class HelloActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
    }
}