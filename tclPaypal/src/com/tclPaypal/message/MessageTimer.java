package com.tclPaypal.message;

import java.util.TimerTask;
/**
 * spring定时器
 * @author kun.shen
 *
 */
public class MessageTimer extends  TimerTask{

	@Override
	public void run() {
		System.out.println("==============================="+System.currentTimeMillis());
	}

}
