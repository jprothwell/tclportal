import java.util.ArrayList;
import java.util.List;


public class SublistTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		List list = new ArrayList();
		for(int i=0;i<100;i++){
			list.add(i);
		}
		List<Integer> addList = new ArrayList<Integer>();
		for(int i=0;i<list.size()/10;i++){
			List subList = list.subList(i*10, (i+1)*10);
			System.out.println(subList.size());
			addList.addAll(subList);
		}
		for(int i :addList){
			System.out.println(">>>>>>");
			System.out.println(i);
		}

	}

}
