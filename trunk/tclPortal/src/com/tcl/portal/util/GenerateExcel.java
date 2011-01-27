package com.tcl.portal.util;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.Map;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFRichTextString;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import com.tcl.portal.domain.ExcelObject;

public class GenerateExcel {

	public static void excel(Map<String, ExcelObject> maps, String filepath) throws Exception {
		HSSFWorkbook wb = new HSSFWorkbook();
	    HSSFSheet sheet = wb.createSheet("访问统计数据");
	    FileOutputStream fileOut = new FileOutputStream(filepath);
	    
	    HSSFRow row = sheet.createRow(0);
	    //设置样式
	    HSSFFont font = wb.createFont();
	    font.setFontHeightInPoints((short)16);
	    font.setFontName("utf-8");
	    HSSFCellStyle style = wb.createCellStyle();
	    style.setFont(font);
	    
	    HSSFFont f = wb.createFont();
	    font.setFontName("utf-8");
	    HSSFCellStyle s = wb.createCellStyle();
	    s.setFont(f);
	    
	    HSSFCell cell = row.createCell(0);
	    HSSFRichTextString text = new HSSFRichTextString("					访问数据统计");
	    cell.setCellValue(text);
	    cell.setCellStyle(style);
	   
	    setCellValue(sheet,1,0,new HSSFRichTextString("机型"));
	    setCellValue(sheet,1,1,new HSSFRichTextString("游戏"));
	    setCellValue(sheet,1,2,new HSSFRichTextString("SP"));
	    setCellValue(sheet,1,3,new HSSFRichTextString("访问量"));
	    int i = 0;
	    for(String key:maps.keySet()){
	    		ExcelObject reportModel = (ExcelObject)maps.get(key);
//				System.out.println(reportModel.getAuthid()+" imsi:"+reportModel.getImsi()+" num:"+reportModel.getNum()+" effectNum:"+reportModel.getEffectNum());
		    	setCellValue(sheet,i+2,0,new HSSFRichTextString(reportModel.getPhoneType()));
		    	setCellValue(sheet,i+2,1,new HSSFRichTextString(reportModel.getGameName()));
		    	setCellValue(sheet,i+2,2,new HSSFRichTextString(reportModel.getSpName()));
		    	setCellValue(sheet,i+2,3,new HSSFRichTextString(String.valueOf(reportModel.getCount())));
		    	i++;
	    }
	    wb.write(fileOut);
	    fileOut.close(); 
	}
	
	private static void setCellValue(HSSFSheet sheet, int i, int j, int d) {
		if(sheet.getRow(i)!=null){
			sheet.getRow(i).createCell(j).setCellValue(d);
		}else{
			sheet.createRow(i).createCell(j).setCellValue(d);
		}
	}
	private static void setCellValue(HSSFSheet sheet, int i, int j,
			HSSFRichTextString text) {
		if(sheet.getRow(i)!=null){
			sheet.getRow(i).createCell(j).setCellValue(text);
		}else{
			sheet.createRow(i).createCell(j).setCellValue(text);
		}
	}
}
