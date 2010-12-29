
public class IntTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Integer a = 1;
		Integer b = new Integer(1);
		Integer e = new Integer(1);
		int c = 1;
		int d = new Integer(1);
		System.out.println(a==b); //t
		System.out.println(a==c); //f
		System.out.println(a==d); //f
		System.out.println(b==c); //f
		System.out.println(b==d); //f
		System.out.println(c==d); //t
		System.out.println(b.equals(e));
	}
}
