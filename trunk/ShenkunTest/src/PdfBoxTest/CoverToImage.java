package PdfBoxTest;
import java.awt.image.BufferedImage;
import java.io.IOException;

import org.pdfbox.pdmodel.PDDocument;
import org.pdfbox.pdmodel.PDPage;
public class CoverToImage {
	
	public static void main(String[] args) throws IOException {
		String pdfUrl = "E:\\TestDocument\\test����.pdf";//����Ϊ����pdf�����쳣
		PDDocument doc = PDDocument.load(pdfUrl);
		PDPage page = (PDPage) doc.getDocumentCatalog().getAllPages().get(0);
		BufferedImage image = page.convertToImage();
	}

}
