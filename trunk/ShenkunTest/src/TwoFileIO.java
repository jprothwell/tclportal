import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class TwoFileIO {

	public static void main(String[] args) {
		String file1 = "E:/TestDocument/testIOSteam.txt";
		String file2 = "E:/TestDocument/testIOSteamCopy.txt";
		FileReader input = null;
		FileWriter output = null;
		try {
			input = new FileReader(file1);
			output = new FileWriter(file2);
			char[] c = new char[1024];
			while(input.read(c, 0, 1024)>=0)
			{
				output.write(c);
			}
			output.flush();
			input.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} 
	}

}
