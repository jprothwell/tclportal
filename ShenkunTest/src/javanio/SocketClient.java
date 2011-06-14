package javanio;

import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class SocketClient {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws UnknownHostException 
	 */
	public static void main(String[] args) throws UnknownHostException, IOException {
		Socket socket = new Socket("localhost",1234);
		 // ∑¢ÀÕπÿ±’√¸¡Ó
	       OutputStream socketOut = new BufferedOutputStream(socket.getOutputStream());
	       socketOut.write("client".getBytes());
	       socketOut.flush();

	}

}
