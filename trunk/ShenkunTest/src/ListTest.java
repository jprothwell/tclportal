import java.util.ArrayList;
import java.util.List;


public class ListTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		List list = new ArrayList();
		list.add("1");
		changelist(list);
		System.out.println(list.size());
	}

	private static void changelist(List list) {
		list = null;
	}

	

}
