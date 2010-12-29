package bankXml;


public	class	Util {
	/**
	 * @param n space count
	 */
	public	static	String	Space(int n) {
		byte[]	b = new byte[n];
//		Arrays.fill(b, ' ');
		for (int i=0; i<n; i++)
			b[i] = ' ';
		return	new String(b);
	}

	/**
	 *
	 */
	public	static	boolean	isEmpty(String s) {
		return	(s==null)||(s.length()==0);
	}

	/**
	 *
	 */
	public	static	boolean	isEmpty(byte []b) {
		return	(b==null)||(b.length==0);
	}

	/**
	 *
	 */
	public	static	String	formatDate(String fmt) {
		return	formatDate(null, fmt);
	}

	/**
	 *
	 */
	public	static	String	formatDate(java.util.Date d, String fmt) {
		if (d==null)
			d = new java.util.Date();
			
		java.text.SimpleDateFormat sdf = 
			new java.text.SimpleDateFormat(fmt);
		return	sdf.format(d);
	}

	/**
	 *
	 */
	public	static	boolean	isSame(byte[] s, byte[] d, int len) {
		return	isSame(s, 0, d, 0, len);
	}

	/**
	 *
	 */
	public	static	boolean	isSame(byte[] s, int soff, byte[] d, int doff, int len) {
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

	// convert integer to fixed, 0-lead byte array
	public	static	void	intToBytes(int length, byte[] b, int off, int len)
		throws	Exception {
		//len -> %0*d
		byte[]	bt = String.valueOf(length).getBytes();
		if (len<bt.length)
			throw new Exception("Buffer Overflow");
		for (int i=0;i<len-bt.length; i++)
			b[off+i] = '0';
		System.arraycopy(bt, 0, b, off+len-bt.length, bt.length);
		return;
	}

	// len -> %0*d
	public	static	String	toFixString(int length, int len)
		throws	Exception {
		
		byte[]	bt = new byte[len];

		intToBytes(length, bt, 0, len);

		return new String(bt);
	}

	// convert byte array to integer
	public	static	int	bytesToInt(byte[] b, int off, int len) {
		return	Integer.parseInt(new String(b, off, len));
	}

	// Mapping table from 6-bit nibbles to Base64 characters.
	private static char[]    map1 = new char[64];
   	static {
      		int i=0;
      		for (char c='A'; c<='Z'; c++) map1[i++] = c;
      		for (char c='a'; c<='z'; c++) map1[i++] = c;
      		for (char c='0'; c<='9'; c++) map1[i++] = c;
      		map1[i++] = '+'; map1[i++] = '/'; 
      	}

	/**
	* Encodes a string into Base64 format.
	* Line breaks are inserted.
	* @param s  a String to be encoded.
	* @return   A String with the Base64 encoded data.
	*/
	public static String b64Encode (String s) {
   		return new String(b64Encode(s.getBytes())); }

	/**
	* Encodes a byte array into Base64 format.
	* Line breaks are inserted.
	* @param in  an array containing the data bytes to be encoded.
	* @return    A character array with the Base64 encoded data.
	*/
	public static char[] b64Encode (byte[] in) {
	   	int 	iLen = in.length;
	   	int 	oDataLen = (iLen*4+2)/3 + (iLen-1)/48;  
	   		// output length without padding
	   	int 	oLen = ((iLen+2)/3)*4 + (iLen-1)/48;    
	   		// output length including padding
	   	char[] 	out = new char[oLen];
	   	int 	ip = 0;
	   	int 	op = 0;
	   	int	i=0;
	   	while (ip < iLen) {
	   		if (++i == 17) {
	   			out[op++] = '\n';
	   			i=1;
	   		}
	      		int i0 = in[ip++] & 0xff;
	      		int i1 = ip < iLen ? in[ip++] & 0xff : 0;
	      		int i2 = ip < iLen ? in[ip++] & 0xff : 0;
	      		int o0 = i0 >>> 2;
	      		int o1 = ((i0 &   3) << 4) | (i1 >>> 4);
	      		int o2 = ((i1 & 0xf) << 2) | (i2 >>> 6);
	      		int o3 = i2 & 0x3F;
	      		out[op++] = map1[o0];
	      		out[op++] = map1[o1];
	      		out[op] = op < oDataLen ? map1[o2] : '='; op++;
	      		out[op] = op < oDataLen ? map1[o3] : '='; op++; 
	   	}

	   	return 	out; 
	}
	
	//
	public	static	byte[]	MD5(byte[] b, int off, int len) {
		try {
	        	java.security.MessageDigest md5 = 
	        		java.security.MessageDigest.getInstance("MD5");
	        	md5.update(b, off, len);
	        	return	md5.digest(); //getBytes("utf-8")
        	} catch (java.security.NoSuchAlgorithmException ex) {
        		return	null;
        	}
        }
	//
	public	static	byte[]	MD5(byte[] b) {
		try {
	        	java.security.MessageDigest md5 = 
	        		java.security.MessageDigest.getInstance("MD5");
	        	return	md5.digest(b); //getBytes("utf-8")
        	} catch (java.security.NoSuchAlgorithmException ex) {
        		return	null;
        	}
        }

	//
	public	static	String	toHexString(byte[] b)  {
		byte[]	hexb = new byte[b.length*2];
		for (int i=0; i<b.length; i++) {
			byteToHex(b[i], hexb, i*2);
		}
		return	new	String(hexb);
	}

	public	static	void	sleep(int t)  {
  		try {
  			Thread.sleep(t*1000); 
  		} catch (Exception e) {}
	}
	
//	Class.forName("org.jdom.Document");
//	Class.forName("org.snmp4j.Snmp");
//	org.jdom.Document.class.getResource("/");
//	org.snmp4j.Snmp.class.getResource("/");
	
}

