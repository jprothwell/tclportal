package thread;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.Exchanger;

public class ExchangerDemo {

	private static Exchanger ex = new Exchanger();
	
	public static void main(String[] args) {
		ExchangerDemo ed = new ExchangerDemo();
		new Thread(ed.new DataProductor()).start();
		new Thread(ed.new DataConsumer()).start();
	}
	
	class DataProductor implements Runnable{
		
		private List list = new ArrayList();
		public void run() {
			for(int i=0;i<5;i++){
				list.add("dataProductor.....");
			}
			try {
				list = (List)ex.exchange(list);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
			for(Iterator iter = list.iterator();iter.hasNext();){
				System.out.println("DataProductor Class>>"+iter.next());
			}
		}
		
	}

	class DataConsumer implements Runnable{
		private List list = new ArrayList();
		public void run() {
			for(int i=0;i<5;i++){
				list.add("dataConsumer.....");
			}
			try {
				list = (List)ex.exchange(list);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
			for(Iterator iter = list.iterator();iter.hasNext();){
				System.out.println("DataConsumer Class>>"+iter.next());
			}
		}
		
	}
}
