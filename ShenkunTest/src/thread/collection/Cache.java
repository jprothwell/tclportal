package thread.collection;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;
import java.util.concurrent.DelayQueue;
import java.util.concurrent.TimeUnit;

import org.apache.log4j.Logger;

public class Cache<K,V> {
	
	private static final Logger LOG = Logger.getLogger(Cache.class);
	
	private ConcurrentMap<K,V> cacheObjMap = new ConcurrentHashMap<K,V>();
	
	private DelayQueue<DelayItem<Pair<K,V>>> q = new DelayQueue<DelayItem<Pair<K,V>>>();
	
	private Thread daemonThread;
	
	public Cache(){
		Runnable daemonTask = new Runnable(){
			public void run(){
				daemonCheck();
			}
		};
		daemonThread = new Thread(daemonTask);
		daemonThread.setDaemon(true);
		daemonThread.setName("Cache Daemo");
		daemonThread.start();
	}
	private void daemonCheck() {
		for(;;){
			try {
				DelayItem<Pair<K,V>> delayItem = q.take();
				if(delayItem!=null){
					Pair<K,V> pair = delayItem.getItem();
					cacheObjMap.remove(pair.first,pair.second);
				}
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
		}
	}
	
	public void put(K key,V value,long time,TimeUnit unit){
		V oldValue = cacheObjMap.put(key, value);
		if(oldValue!=null) q.remove(key);
		long nanoTime = TimeUnit.NANOSECONDS.convert(time, unit);
		q.put(new DelayItem<Pair<K,V>>(new Pair<K,V>(key,value),nanoTime));
	}
	
	public V get(K key){
		return cacheObjMap.get(key);
	}
	
	public static void main(String[] args) throws Exception{
		Cache<Integer,String> cache = new Cache<Integer,String>();
		cache.put(1, "aaa", 3,TimeUnit.SECONDS);
		Thread.sleep(1000*2);
		String str1 = cache.get(1);
		System.out.println(str1);
		Thread.sleep(1000*2);
		String str2 = cache.get(1);
		System.out.print(str2);
	}
}
