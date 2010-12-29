import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;


public class FileReader {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		File file = new File("f:/test.text");
		InputStream is = new FileInputStream(file);
		BufferedInputStream bis = new BufferedInputStream(is);
		StringBuilder test = new StringBuilder();
		byte[] bytes = new byte[1024];
		int len =0;
		while((len = bis.read(bytes, 0, 1024))>0){
			test.append(new String(bytes,0,len));
		}
		System.out.println(test.toString());
	}

}
