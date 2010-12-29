import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class DT {
	
	public static void main(String[] args) throws IOException{
		
		String order = "cmd.exe /c wmic process get name,executablepath";
		Runtime r = Runtime.getRuntime();
		Process p = r.exec(order);
		BufferedReader buff = new BufferedReader(new InputStreamReader(p.getInputStream()));
		p.getOutputStream().flush();
		p.getOutputStream().close();
		StringBuilder sb = new StringBuilder();
		String inline;
		while(null!=(inline=buff.readLine())){
			sb.append(inline);
			sb.append("\n");
		}
	
		System.out.println(sb.toString());
	}
}
