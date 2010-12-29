package bankXml;

import	java.util.*;
import	java.io.*;
import	java.text.SimpleDateFormat;


/**
 * base class of log
 *
 * @author	wenxm@erongsoft.com
 * @version     %I%, %G%
 */
public	class Syslog {

	// 调试信息级别
	public	static	final	int	LV_NONE = 0;
	public	static	final	int	LV_FATAL = 1;
	public	static	final	int	LV_ERROR = 2;
	public	static	final	int	LV_FAIL = 3;
	public	static	final	int	LV_WARNING = 4;
	public	static	final	int	LV_NORMAL = 5;
	public	static	final	int	LV_INFO = 6;
	public	static	final	int	LV_DEBUG = 9;

	//log控制标志
	public	static	final	int	LF_NONE = 0;
	public	static	final	int	LF_TIME = 1; //是否加时间，缺省为显示
	public	static	final	int	LF_LABEL = 4; //是否加程序名称
	public	static	final	int	LF_PID = 8; //是否加进程号
	public	static	final	int	LF_TID = 0x10; //是否加加线程号
	public	static	final	int	LF_TTY = 0x20; //是否同时显示在屏幕上，缺省为显示
	public	static	final	int	LF_ALL = 0xffff;

	public	Syslog(String lbl) {
		setLabel(lbl);
	}

	/**
	 * set log file prefix
	 * @param file  file name (prefix)
	 */
	public	static	int	setFile(String file) {
		fname = file;
		return	0;
	}
	
	/**
	 * delete log files days ago
	 * @param days  days before today
	 */
	public	static	int	delOldFiles(int days) {
		return	0;
	}

	/**
	 * set log level
	 * @param lvl  new log level
	 * @return current log level
	 */
	public	static	int	setLevel(int lvl) {
		int	tmp = level;
		level = lvl;
		return	tmp;
	}
	
	public	static	void	setFlag(int f) {
		flag |= f;
	}

	public	static	void	clrFlag(int f) {
		flag &= ~f;
	}

	public	static	int	setLabel(String lbl) {
		label = lbl;
		int	l = flag&LF_LABEL;
		if ((label==null)||(label.length()==0))
			clrFlag(LF_LABEL);
		else
			setFlag(LF_LABEL);
	
		return	l;
	}

	//
	public	static	int	newline(int n) {
		out("");
		return	n;
	}
	
	public	static	int	show(int lvl, String s) {
		return	vdiag(lvl, s);
	}

	public	static	int	showError(String s) {
		return	vdiag(LV_ERROR, s);
	}
	public	static	int	showWarning(String s) {
		return	vdiag(LV_WARNING, s);
	}
	public	static	int	show(String s) {
		return	vdiag(LV_NORMAL, s);
	}
	public	static	int	showInfo(String s) {
		return	vdiag(LV_INFO, s);
	}
	public	static	int	showDebug(String s) {
		return	vdiag(LV_DEBUG, s);
	}

	/**
	 * print the Exception's stack trace
	 * @param e  exception
	 */
	public	static	void	printStackTrace(Exception e) {
		showError(e.toString());
		e.printStackTrace();
/*
		StackTraceElement bt[] = e.getStackTrace();
		int i = bt.length-1;
		for (; i>=0; i--) {
			if (bt[i].getClassName().startsWith("java"))
				break;
		}
		
		for (; i<bt.length; i++)
			out(bt[i].toString());
*/
	}

	/**
	 * dump the byte array in hex format
	 * @param b   array to be dumped
	 */
	public	static	void	hexDump(byte[] b) {
		if (level<LV_DEBUG) {
			return;
		}

		hexDump(b, 0, b.length);
	}

	/**
	 * dump the byte array in hex format(max 1024bytes)
	 * @param b     array to be dumped
	 * @param off   start position
	 * @param len   bytes to be dumped,
	 */
	public	static	void	hexDump(byte[] b, int off, int len) {
		if (level<LV_DEBUG) {
			return;
		}
		if (len>1024)
			len = 1024;
		for (int cnt=0; len>0; cnt++) {
			int	last;
			if (len > 16)
				last = 16;
			else
				last = len;

			String	line = dumpLine(b, off, last);
			out(line);

			int	dup = 0;
			for ( ; len>32; ) {
				if (!isSame(b, off, b, off+16, 16))
					break;
				dup++;
				off+=16; len-=16;
			}
			if (dup>0)
				out("    ***");

			off += last;
			len -= last;
		}
	}


	private	static	String	fname;
	private	static	String	label;	//程序名
	private	static	int	level = LV_NORMAL;	//
	private	static	int	flag = LF_TIME | LF_TTY;

	//
	private	static	int	vdiag(int lvl, String s) {
		//
		if (level<lvl)
			return	0;
		//
		if (((flag&LF_TTY)==0) && ((fname == null)||(fname.length()==0)))
			return	0;

		//
		int	off = 0;
		for ( ; ; off++) {
			char	c = s.charAt(off);
			if ((c=='\n')||(c=='\r'))
				continue;
			if ((c=='\t')||(c==' '))
				continue;
			break;
		}

		//debug mode or just blanks, no labels
		if ((lvl>=LV_DEBUG) || (s.length()<=off)) {
			return	out(s);
		}

		//
		String	prefix="";
		if ((flag&LF_TIME)!=0) {
			Date	d = new Date();
			prefix += formatDate(d, "HH:mm:ss "); 
		}
		if (((flag&LF_LABEL)!=0)&&
		    (label!=null)&&(label.length()>0)) {
			prefix += label + " ";
		}
		String	l = getDiagLabel(lvl);
		if ((l != null) && (l.length()>0))
			prefix += l +": ";

		if (off<=0)
			return	out(prefix+s);

		return	out(s.substring(0, off)+prefix+s.substring(off));
	}

	//
	private	static	int	out(String s) {
		return	out(null, s);
	}
	//
	private	static	int	out(Date d, String s) {
		if ((flag&LF_TTY)!=0) {
			if (s.endsWith("\n"))
				System.out.print(s);
			else
				System.out.println(s);
		}
		if ((fname != null)&&(fname.length()>0)){
			FileOutputStream  fos = null;
			PrintStream  ps = null;
			try {
				fos = new FileOutputStream(getLogFile(d));
				ps = new PrintStream(fos);
				if (s.endsWith("\n"))
					ps.print(s);
				else
					ps.println(s);
			} catch (Exception e) {
			}
			if (ps!=null) 
				ps.close();
			try {if(fos!=null) fos.close();} 
			catch (Exception ex){}
		}
		
		return	0;
	}

	//
	private	static	String	getDiagLabel(int lvl) {
		switch(lvl) {
		default:
			return	"";
		case	LV_FATAL:
			return	"Fatal";
		case	LV_ERROR:
			return	"Error";
		case	LV_FAIL:
			return	"Fail";
		case	LV_WARNING:
			return	"Warning";
		case	LV_NORMAL:
		case	LV_INFO:
			return	"Info";
		case	LV_DEBUG:
			return	"Debug";
		}
	}

	private	static	String	getLogFile(Date d) {
		return	fname+"."+formatDate(d, "MMdd");
	}

	private	static	String	formatDate(Date d, String fmt) {
		if (d==null)
			d = new Date();
			
		SimpleDateFormat sdf = new SimpleDateFormat(fmt);
		return	sdf.format(d);
	}


	private	static	boolean	isSame(byte[] s, int soff, byte[] d, int doff, int len) {
		for (int i=0; i<len; i++) {
			if (s[soff++]!=d[doff++])
				return	false;
		}

		return	true;
	}

	private	final	static	byte[]	hex = "0123456789ABCDEF".getBytes();

	/**
	 * convert byte to 2 byte hex string
	 * @param b      byte to be converted
	 * @param buff   output buffer
	 * @param off    start position
	 */
	public	static	void	byteToHex(byte b, byte[] buff, int off) {
		buff[off++] = hex[(b>>4)&0x0f];
		buff[off++] = hex[b&0x0f];
		return;
	}


	private	static	void	intToHex(int i, byte[] buff, int off) {
		if ((i&0xff0000)!=0) {
			buff[off++] = hex[(i>>20)&0x0f];
			buff[off++] = hex[(i>>16)&0x0f];
		} else {
			buff[off++] = buff[off++] = ' ';
		}
		buff[off++] = hex[(i>>12)&0x0f];
		buff[off++] = hex[(i>>8)&0x0f];
		buff[off++] = hex[(i>>4)&0x0f];
		buff[off++] = hex[i&0x0f];
		return;
	}

	private	static	String	dumpLine(byte[] buf, int off, int len) {
		byte[]	line = new byte[80];
		Arrays.fill(line, (byte)' ');
		int	loff = 2;
		intToHex(off, line, loff);

		loff = 11;
		for (int i=0; i<len; i++, loff+=2) {
			if (i == 8) {
				line[loff++]=line[loff++] = '-';
				byteToHex(buf[off+i], line, loff);
			} else {
				byteToHex(buf[off+i], line, ++loff);
			}
		}

		if (len <= 8)
			loff++;

		for (int i=len; i<=16; i++)
			loff += 3;
		for (int i=0; i<len; i++)
			if ((buf[off+i]>=0x20)&&(buf[off+i]<0x7f))
				line[loff++] = buf[off+i];
			else
				line[loff++] = '.';

		return	new String(line, 0, loff);
	}

	public	static	void	main(String[] args) {
		byte[]	b = "1234567890121374136571".getBytes();
		hexDump(b, 3, 16);
	}
};

