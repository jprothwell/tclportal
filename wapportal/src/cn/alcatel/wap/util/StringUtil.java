/*
 * Created on 2009-9-20
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.alcatel.wap.util;

/**
 * @author gonglin.shi
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class StringUtil {
	public static final String shift(Object o){
		return String.valueOf(o);
	}

    public static final String gb2utf(String s) {
        try {
            return new String(s.getBytes("GB2312"), "UTF-8");
        } catch (Exception e) {
        	System.err.println(e);
            return s;
        }
    }

    public static final String utf2gb(String s) {
        try {
            return new String(s.getBytes("UTF-8"), "GB2312");
        } catch (Exception e) {
        	System.err.println(e);
            return s;
        }
    }

    public static final String gbk2utf(String s) {
        try {
            return new String(s.getBytes("GBK"), "UTF-8");
        } catch (Exception e) {
        	System.err.println(e);
            return s;
        }
    }

    public static final String utf2gbk(String s) {
        try {
            return new String(s.getBytes("UTF-8"), "GBK");
        } catch (Exception e) {
        	System.err.println(e);
            return s;
        }
    }

    public static final String iso2utf(String s) {
        try {
            return new String(s.getBytes("ISO8859_1"), "UTF-8");
        } catch (Exception e) {
        	System.err.println(e);
            return s;
        }
    }

    public static final String utf2iso(String s) {
        try {
            return new String(s.getBytes("UTF-8"), "ISO8859_1");
        } catch (Exception e) {
        	System.err.println(e);
            return s;
        }
    }

    public static final String gbk2gb(String s) {
        try {
            return new String(s.getBytes("GBK"), "GB2312");
        } catch (Exception e) {
        	System.err.println(e);
            return s;
        }
    }
}