package com.tcl.onetouch.util;

import java.io.FileOutputStream;
import java.util.List;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFRichTextString;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import com.tcl.onetouch.domain.Downloadinfo;
import com.tcl.onetouch.domain.Visiteinfo;

public class GenerateExcel {

	public static void excel(List<Visiteinfo> list, String filepath) throws Exception {
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
	    for(Visiteinfo visiteinfo:list){
	    		//ExcelObject reportModel = (ExcelObject)list.get(key);
//				System.out.println(reportModel.getAuthid()+" imsi:"+reportModel.getImsi()+" num:"+reportModel.getNum()+" effectNum:"+reportModel.getEffectNum());
		    	setCellValue(sheet,i+2,0,new HSSFRichTextString(visiteinfo.getDidName()));
		    	setCellValue(sheet,i+2,1,new HSSFRichTextString(visiteinfo.getGameName()));
		    	setCellValue(sheet,i+2,2,new HSSFRichTextString(visiteinfo.getSpName()));
		    	setCellValue(sheet,i+2,3,visiteinfo.getNum());
		    	i++;
	    }
	    wb.write(fileOut);
	    fileOut.close(); 
	}
	
	public static void excelDownload(List<Downloadinfo> list, String filepath) throws Exception {
		HSSFWorkbook wb = new HSSFWorkbook();
	    HSSFSheet sheet = wb.createSheet("下载统计数据");
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
	    HSSFRichTextString text = new HSSFRichTextString("					下载数据统计");
	    cell.setCellValue(text);
	    cell.setCellStyle(style);
	   
	    setCellValue(sheet,1,0,new HSSFRichTextString("机型"));
	    setCellValue(sheet,1,1,new HSSFRichTextString("游戏"));
	    setCellValue(sheet,1,2,new HSSFRichTextString("SP"));
	    setCellValue(sheet,1,3,new HSSFRichTextString("下载量"));
	    int i = 0;
	    for(Downloadinfo downloadinfo:list){
	    		//ExcelObject reportModel = (ExcelObject)list.get(key);
//				System.out.println(reportModel.getAuthid()+" imsi:"+reportModel.getImsi()+" num:"+reportModel.getNum()+" effectNum:"+reportModel.getEffectNum());
		    	setCellValue(sheet,i+2,0,new HSSFRichTextString(downloadinfo.getDidName()));
		    	setCellValue(sheet,i+2,1,new HSSFRichTextString(downloadinfo.getGameName()));
		    	setCellValue(sheet,i+2,2,new HSSFRichTextString(downloadinfo.getSpName()));
		    	setCellValue(sheet,i+2,3,downloadinfo.getNum());
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
