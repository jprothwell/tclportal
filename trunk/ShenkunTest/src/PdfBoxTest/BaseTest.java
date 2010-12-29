package PdfBoxTest;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.Writer;

import org.pdfbox.cos.COSDocument;
import org.pdfbox.pdfparser.PDFParser;
import org.pdfbox.pdmodel.PDDocument;
import org.pdfbox.util.PDFTextStripper;

/*
 * 简单测试  读取pdf文档中的数据
 */
public class BaseTest {

	public static void main(String[] args) throws Exception {
		InputStream in = new FileInputStream("E:\\TestDocument\\test.pdf");
		PDFParser p = new PDFParser(in);
		p.parse();
		COSDocument pdfDocument = p.getDocument();
		PDFTextStripper stripper = new PDFTextStripper();
		String s = stripper.getText(new PDDocument(pdfDocument)); 
		pdfDocument.close();
		
		File file = new File("e:\\TestDocument\\test中文.doc");
		Writer output = new FileWriter(file);
		output.write(s);
		output.flush();
        System.out.println(s);
	}
}

	