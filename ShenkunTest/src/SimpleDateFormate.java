import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;


public class SimpleDateFormate {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Date date = new Date();
		SimpleDateFormat dateFormate = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss");
		String s1 = dateFormate.format(date);
		//System.out.println(s1);
		
		//Ω‚Œˆªÿ¿¥
		String s2 = "2001-12-17T09:30:47";
		String s3 = s2.replaceAll("T", " ");
		System.out.println(s3);
		SimpleDateFormat d = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss");
		try {
			Date dates = d.parse(s2);
			//System.out.println(dates);
		} catch (ParseException e) {
			e.printStackTrace();
		}
	}

}
