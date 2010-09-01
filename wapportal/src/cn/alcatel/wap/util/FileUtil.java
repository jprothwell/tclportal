/*
 * Created on 2009-5-25
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.alcatel.wap.util;

import java.io.*;

/**
 * @author gonglin.shi
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class FileUtil {
	private static String fileSuffix = "png,gif,jpg,bmp";

	public static String[] getFileNames(String dir) throws Exception {
		File ftmp = new File(dir);
		if (!ftmp.exists()) {
			throw new Exception(Common.ATTR_PAGE_MSG.DIR_NOT_EXIST);
		}
		File[] files = ftmp.listFiles();
		if (files != null && files.length > 0) {
			String[] filenames = new String[files.length];
			for (int i = 0; i < files.length; i++) {
				filenames[i] = files[i].getName();
			}
			return filenames;
		}
		return null;
	}

	public static boolean isImg(String filename) {
		if (fileSuffix.indexOf(filename.substring(filename.indexOf(".") + 1)) >= 0) {
			return true;
		} else {
			return false;
		}
	}

	public static boolean delFile(String fullfile){
		File file = new File(fullfile);
		try{
			file.delete();
			return true;
		}catch(Exception e){
			System.err.println(e);
			return false;
		}
	}
}
