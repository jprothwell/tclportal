package PdfBoxTest;

import org.pdfbox.PDFToImage;


public class PDFToImageTest2 {

	public static void main(String[] args) throws Exception {
		String pdfUrl = "E:\\TestDocument\\test.pdf";
		String[] s = {"-imageType","jpg",pdfUrl};
		PDFToImage.main(s);
	}

}
