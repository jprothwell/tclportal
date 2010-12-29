package PdfBoxTest;

import java.awt.image.BufferedImage;
import java.io.File;
import java.util.Iterator;
import java.util.List;

import javax.imageio.IIOException;
import javax.imageio.IIOImage;
import javax.imageio.ImageIO;
import javax.imageio.ImageWriteParam;
import javax.imageio.ImageWriter;
import javax.imageio.stream.ImageOutputStream;

import org.pdfbox.pdmodel.PDDocument;
import org.pdfbox.pdmodel.PDPage;

public class PDFToImageTest {

	public static void main(String[] args) throws Exception {
		  PDDocument doc = PDDocument.load("E:\\TestDocument\\spring-reference.pdf");
		  List pages = doc.getDocumentCatalog().getAllPages();
		  Iterator iter = pages.iterator();
		  while (iter.hasNext()) {
		    PDPage page = (PDPage)iter.next();
		    BufferedImage image = page.convertToImage();
		    File file = File.createTempFile("test_", ".jpg");
		    System.out.println(file);
		    ImageOutputStream output = ImageIO.createImageOutputStream(file);
		    try {
		      boolean foundWriter = false;
		      Iterator writerIter = ImageIO.getImageWritersByFormatName("jpg");
		      while (writerIter.hasNext() && !foundWriter) {

		        try {
		          ImageWriter imageWriter = (ImageWriter) writerIter.next();
		          try {
		            ImageWriteParam writerParams = imageWriter.getDefaultWriteParam();
		            if (writerParams.canWriteCompressed()) {
		              writerParams.setCompressionMode(ImageWriteParam.MODE_EXPLICIT);
		              writerParams.setCompressionQuality(1.0f);
		            }
		            imageWriter.setOutput(output);
		            imageWriter.write(null, new IIOImage(image, null, null), writerParams);
		            foundWriter = true;
		          } finally {
		            imageWriter.dispose();
		          }
		        } catch (IIOException io) {
		          io.printStackTrace();
		        }
		      }
		    } finally {
		      output.close();
		    }
		  } 
		}

}
