package com.tclPaypal.timer;

import java.util.TimerTask;

public class MessageTimer extends  TimerTask{

	@Override
	public void run() {
		System.out.println("==============================="+System.currentTimeMillis());
	}

}
