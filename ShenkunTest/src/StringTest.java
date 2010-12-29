import java.util.HashMap;
import java.util.Map;

/**
 * 根据输入的数字（字节数），输出字符串，遇到中文不能输出一半或者他
 * @author Administrator
 *
 */
public class StringTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String s = "ab中文";
		//map中存放字节和字符的键值对应
		Map map = new HashMap();
		char[] c = s.toCharArray();
		for(int i=0;i<=c.length;i++){
			int count = s.substring(0, i).getBytes().length;
			//key为字节数，value为字符数
			map.put(count,i);
		}
		//System.out.println(map);
		Integer insert = 5;
		if(!map.containsKey(insert)){
			Integer insert2 = insert-1;
			for(int i=0;i<((Integer)map.get(insert2)).intValue();i++){
				System.out.print(c[i]);
			}
		}else{
			for(int i=0;i<((Integer)map.get(insert)).intValue();i++){
				System.out.print(c[i]);
			}
		}
	}
}
