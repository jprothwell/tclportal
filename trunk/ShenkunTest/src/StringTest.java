import java.util.HashMap;
import java.util.Map;

/**
 * ������������֣��ֽ�����������ַ������������Ĳ������һ�������
 * @author Administrator
 *
 */
public class StringTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String s = "ab����";
		//map�д���ֽں��ַ��ļ�ֵ��Ӧ
		Map map = new HashMap();
		char[] c = s.toCharArray();
		for(int i=0;i<=c.length;i++){
			int count = s.substring(0, i).getBytes().length;
			//keyΪ�ֽ�����valueΪ�ַ���
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
