package javanio;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;


public class CopyFileNio {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		String file1 = "f:/shenkun/数据库.txt";
		String file2 = "f:/数据库.txt";
		FileInputStream fin = new FileInputStream(file1);
		FileOutputStream fout = new FileOutputStream(file2);
		FileChannel fci = fin.getChannel();
		FileChannel fcout = fout.getChannel();
		ByteBuffer buffer = ByteBuffer.allocate(1024);
		while(true){
			buffer.clear();
			int r = fci.read(buffer);
			if(r == -1){
				break;
			}
			buffer.flip();
			fcout.write(buffer);
		}
	}

}
