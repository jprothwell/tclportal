package com.tclPaypal.message;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

import com.tclPaypal.util.Constants;


public class IoMessage {
	//socket发送信息，并获取返回信息
	public int sendAndGetMessage(byte[] buffer, int len,byte[] outBuffer){
		Socket socket;
		try {
			socket = new Socket(Constants.SOCKET_IP, Constants.SOCKET_PORT);
			socket.setSoTimeout(Constants.SOCKET_TIME);
			// 发送关闭命令
			OutputStream socketOut = new BufferedOutputStream(socket.getOutputStream());
			socketOut.write(buffer, 0, len);
			  
			for(int i=0;i<len;i++){
				 System.out.print(buffer[i]);   
			 }
			socketOut.flush();
			  
			 // 接收服务器的反馈
			InputStream br = new BufferedInputStream(socket.getInputStream());
			 int length = br.read(outBuffer);
			 br.close();
			 socket.close();
			 return length;
		} catch (UnknownHostException e) {
			e.printStackTrace();
			return 0;
		} catch (IOException e) {
			e.printStackTrace();
			return 0;
		}
	}
	
}
