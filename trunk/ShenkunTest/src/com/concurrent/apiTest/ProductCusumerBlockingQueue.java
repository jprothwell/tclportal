package com.concurrent.apiTest;

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class ProductCusumerBlockingQueue {

	public static void main(String[] args) {
		BlockingQueue<String> blockingQueue = new ArrayBlockingQueue(1, true);
		Product product = new Product(blockingQueue);
		Cusumer cusumer = new Cusumer(blockingQueue);
		new Thread(product).start();
		new Thread(cusumer).start();
	}
}

class Product implements Runnable{
	
	private BlockingQueue<String> blockingQueue;
	
	private List<String> list = Arrays.asList("one","two","three","four");
	
	public Product(BlockingQueue<String> bq){
		this.blockingQueue = bq;
	}
	public void run() {
		try {
			for(String str:list){
				this.blockingQueue.put(str);
			} 
			blockingQueue.put("None");
		}catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

class Cusumer implements Runnable{
	
	private BlockingQueue<String> blockingQueue;
	
	public Cusumer(BlockingQueue<String> bq){
		this.blockingQueue = bq;
	}
	public void run() {
		
		try {
			String msg = "";
			while(!(msg=this.blockingQueue.take()).equals("None")){
				System.out.println(msg);
			}
			
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
}