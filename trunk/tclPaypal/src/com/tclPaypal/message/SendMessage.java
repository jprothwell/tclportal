package com.tclPaypal.message;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * 发送确认消息
 * @author kun.shen
 *
 */
public class SendMessage {
	
	static ExecutorService execut =  Executors.newFixedThreadPool(10);
	
	public static void send(){
//		execut.execute();
	}
}
