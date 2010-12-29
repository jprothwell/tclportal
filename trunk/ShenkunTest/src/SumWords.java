import java.util.HashMap;
import java.util.Map;


public class SumWords {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String s = "aassddad";
		char[] bytes = s.toCharArray();
		Map map = new HashMap();
		for(int i=0;i<bytes.length;i++){
			if(map.containsKey(bytes[i])){
				int count = (Integer)map.get(bytes[i])+1;
				map.put(bytes[i], count);
			}else{
				map.put(bytes[i], 1);
			}
		}
		System.out.println(map);
	}

}
