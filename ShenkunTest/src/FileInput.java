import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 文件的读写操作
 * @author Administrator
 *
 */
public class FileInput {

	public static void main(String[] args){
		
		FileOutputStream output = null;
		File file = new File("D:/pathTest/22.txt");
		file.delete();
//		try {
//			 output = new FileOutputStream(file);
//			 byte[] b = getString().getBytes();
//			 output.write(b);
//			 output.flush();
//			 output.close();
//		} catch (FileNotFoundException e) {
//			e.printStackTrace();
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
	}

	private static String getString() {
		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader buffer = new BufferedReader(in);
		String s = null;
		try {
			s = buffer.readLine();
			buffer.close();
			in.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return s;
	}

}
