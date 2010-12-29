package htmlurl;

import java.sql.Connection;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;


public class GetIpFromDatabase {

	/**
	 * @param args
	 * @throws ClassNotFoundException 
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 */
	public static void main(String[] args) throws Exception {
		Class.forName("com.mysql.jdbc.Driver").newInstance();
		Connection con=java.sql.DriverManager.getConnection("jdbc:mysql://localhost:3306/onetouch?useUnicode=true&amp;characterEncoding=utf-8","root","admin");
		java.sql.Statement stmt = con.createStatement();
		ResultSet authrst = stmt.executeQuery("select * from location where country is null");
		List<String> list = new ArrayList<String>();
		while(authrst.next()){
			list.add(authrst.getString("ip"));
		}
		int num = list.size();
		ExecutorService executor = Executors.newFixedThreadPool(num/20);
		Future<List> ft = executor.submit(new GetIps(list));
		System.out.println(20/20);
		System.out.println(list.size());
		
//		Map<String,String> maps = new HashMap<String,String>();
//		for(String str:list){
//			str = str+".2";
//			//GetIp.getIp(str);
//			maps.put(str, GetIp.getIp(str));
//			System.out.println("");
//		}
		
//		System.out.println(maps);
	}

}
