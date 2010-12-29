package thread;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

public class CopyOnWriteDemo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String[] strs = {"a","b","c"};
		List list1 = new CopyOnWriteArrayList(Arrays.asList(strs));
		List list2 = new ArrayList(Arrays.asList(strs));
		Iterator iter1 = list1.iterator();
		Iterator iter2 = list2.iterator();
		list1.add("test");
		list2.add("test");
		printAll(iter1);
		printAll(iter2);
	}

	private static void printAll(Iterator iter) {
		while(iter.hasNext()){
			System.out.println(iter.next());
		}
	}

}
