package lucene;

import java.io.IOException;
import java.io.Reader;
import java.io.StringReader;

import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.Token;
import org.apache.lucene.analysis.TokenStream;
import org.mira.lucene.analysis.MIK_CAnalyzer;
public class Lucene {

	public static void main(String[] args) throws IOException {
		String s = "�л����񹲺͹���1949�꽨�����Ӵ˿�ʼ�����й���ΰ��ƪ��."; 
//		Analyzer analyzer = new ChineseAnalyzer();
//		Reader r = new StringReader(s);
//		TokenFilter tf = (TokenFilter) analyzer.tokenStream("", r);
//		System.out.println("=====chinese analyzer====");
//		System.out.println("��������:������ͬStandardAnalyzer��һԪ�ִʣ�");
//		Token t;
//		while ((t = tf.next()) != null) {
//		System.out.println(t.termText());
//		} 
		
		Analyzer analyzer = new MIK_CAnalyzer();
		Reader r = new StringReader(s);
		TokenStream ts = (TokenStream)analyzer.tokenStream("", r);
		System.out.println("=====MIK_CAnalyzer====");
		Token t;
		while ((t = ts.next()) != null) {
		System.out.println(t.termText()); 
		}
	}
}
