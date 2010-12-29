///**
// * File: Incoming.java
// *
// *     �ӿ�ͨ�ŷ���ģ��: ����ҵ����ģ��
// *
// * History:
// *    20090427   wenxm  first version
// *
// */
//
//
////package	commif;
//
//import	java.io.*;
//
//import java.sql.Connection;
//import java.sql.*;
//
//import	org.jdom.Element;
//
///**
// * base class of incoming service
// *
// * @author	wenxm@erongsoft.com
// * @version     %I%, %G%
// */
//public	class	Incoming extends Module {
//
//	/** default contructor */
//	public	Incoming() {
//		
//	}
//
//	/** load config from file
//	 * @param file config file name
//	 * @return if OK return true, else return false
//	 */
//	public	boolean	init(String cfgfile) {
//		Syslog.setLevel(Syslog.LV_DEBUG);
//
//		if (cfgfile==null)
//			cfgfile = "Incoming.xml";
//
//		return	super.init(cfgfile);
//		//ȡ�������ò���
//	}
//
//	/** exit
//	 * @return if OK return true, else return false
//	 */
//	public	boolean	exit() {
//
//		return	super.exit();
//	}
//
//	/**
//	 * main loop
//	 *
//	 */
//	public	void	run() {
//
//		for ( ; bExit != true; ) {
//			//ȡMQ����
//			MqComm  mqconn = mqManager.getConnection();
//			if (mqconn == null) {
//				return;
//			}
//			mqconn.setAutoCommit(false);
//			try {
//				// ȡ����
//				byte[]	request = mqconn.get();
//				if ((request==null)||(request.length==0)) {
//					mqManager.checkConnection(true);
//					continue;
//				}
//				//XXX: ����ͨ���ض���Ϣ(��EXIT)���˳�����
//				
//
//				// ��������ʽ
//				Request req = verifyReq(request);
//				if (req==null) {
//
//					mqconn.commit();
//					mqManager.checkKeepAlive();
//					continue;
//
//					//����ʱ����
////					mqconn.rollback();
////					return;
//				}
//				
//				// ��������
//				if (forwardReq(req)) {
//					mqconn.commit();
//					mqManager.checkKeepAlive();
//					continue;
//				}
//
//			} catch (Exception e) {
//				Syslog.printStackTrace(e);
//			}
//
//			mqconn.rollback();
//			
//			//����ʱ����
//			return;
//		}
//		
//		return;
//	}
//
//
//	private	boolean	bExit = false;	// �Ƿ��˳���ѭ����־
//	private	int	errcnt = 0;	// �����������
//	private	String	xsdPath = null; // Schemas�ļ�����·��
//
//	/**
//	 * ������Ϣ
//	 */
//	class	Request	{
//		String	msgHeader;
//		String	msgType;
//		int	bodyLen;
//		InputStream	msgText;
//		String	ptcptSgntr;
//		String	msgID;
//		String	sendMsgID; 	/* OrigMsgID or reply MsgID */
//		String	bizType; 	// if OrigMsgID=null, BizType=1
//		String	errCode; 	//
//		String	errDesc;	//
//	};
//
//	/**
//	 * ����������Ϣ
//	 *
//	 */
//	private	Request	verifyReq(byte[] req) {
//		try {
//			//verify MsgHeader
//			Request	request = new Request();
//			request.msgHeader = new String(req, 0, MsgHeader.size);
//			MsgHeader msghdr = new MsgHeader(req, 0, MsgHeader.size);
//
//			request.errCode = "000";
//			request.errDesc = "No Error";
//			
//			//
//			request.msgType = msghdr.getValue("MesgType").trim();
//			if (Util.isEmpty(request.msgType)) {
//				request.msgType = "000";
//
//				request.errCode = "001";
//				request.errDesc = "Empty MesgType";
//			}
//			Syslog.showDebug("verifyReq: msgType="+request.msgType);
//			
//			int	bodyLength = msghdr.getBodyLength();
////			if (bodyLength<0)
////				bodyLength = req.length - MsgHeader.size;
//				
//			String	bodyChksum = msghdr.getValue("BodyChksum");
//
//			Syslog.showDebug("verifyReq: request="+req.length+"B, bodyLength="+bodyLength+"B");
//
//			if (req.length<(bodyLength+MsgHeader.size)) {
//				request.errCode = "LEN";
//				request.errDesc = "req.length(" + req.length + 
//					") < bodyLength("+bodyLength+") + "+MsgHeader.size;
//				Syslog.showError(request.errDesc);
////				return	null;
//			}
//
//			request.bodyLen = bodyLength;
//			request.msgText = new ByteArrayInputStream(req, MsgHeader.size, bodyLength);
//
//			String	md5 = Util.toHexString(Util.MD5(req, MsgHeader.size, bodyLength));
//			if (!md5.equals(bodyChksum)) {
//				request.errCode = "MD5";
//				request.errDesc = "chksum("+bodyChksum+") error, !=("+md5+")";
//				Syslog.showError(request.errDesc);
//				
////				return	null;
//			}
//
//			//verify Schemas according to mesgType
//
//			//skip lead content (space)
//			int	off = MsgHeader.size;
//			int	len = bodyLength;
//			while ((len>0) && (req[off]!='<')) {
//				off++;
//				len--;
//			}
//			//skip trailing content
//			while ((len>0) && (req[off+len-1]!='>')) {
//				len--;
//			}
//			
//			ByteArrayInputStream bi = new ByteArrayInputStream(req, off, len);
//
//			Element	root = XmlUtil.verifySchemas(bi, request.msgType+".xsd");
//			if (root == null) {
//				request.errCode = "XML";
//				request.errDesc = "Schemas unmatched";
//				Syslog.showError(request.errDesc);
//				return	null;
//			}
//
//			//verify signature
//			request.ptcptSgntr = XmlUtil.getValue(root, "Document/PtcptSgntr");
//
//
//			request.msgID = XmlUtil.getValue(root, "Document/[0]/MsgId/Id");
//			request.sendMsgID = XmlUtil.getValue(root, "Document/[0]/OrgnlMsgId/Id");
//			
//			request.bizType = (request.sendMsgID==null)?"1":"2";
//
//			Syslog.show("verifyReq: OK, MsgType="+request.msgType
//					 +", MsgID="+request.msgID);
//			
//			return	request;
//		} catch (Exception e) {
//			Syslog.printStackTrace(e);
//		}
//
//		return	null;
//	}
//	
//	/**
//	 * ����������Ϣ�����ݿ��(EcdsRecvList)
//	 *
//	 */
//	private	boolean	forwardReq(Request req) {
//		//ȡ���ݿ�����
//		Connection dbconn = dbManager.getConnection();
//		if (dbconn == null) {
//			//setError(response, "�޷��������ݿ�");
//			return	false;
//		}
//
//		/* */
//		String	sql = "INSERT INTO EcdsRecvList(MsgID, MsgType, BizType, MsgHeader"
//			     +", MsgText, PtcptSgntr, SendMsgID, ErrCode, ErrDesc)"
//			     +"VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)";
//		try {
//			dbconn.setAutoCommit(false);
//
//			PreparedStatement insert = dbconn.prepareStatement(sql);
//
//			insert.setString(1, req.msgID); 	//
//			insert.setString(2, req.msgType); 	//
//			insert.setString(3, req.bizType); 	//
//			insert.setString(4, req.msgHeader); 	//
//			insert.setBinaryStream(5, req.msgText, req.bodyLen); //
////			oracle.sql.BLOB newBlob = oracle.sql.BLOB.createTemporary(dbconn, false, oracle.sql.BLOB.DURATION_SESSION);
////			newBlob.setBytes(pos, b, offset, len) 
//
//			insert.setString(6, req.ptcptSgntr); 	//
//			insert.setString(7, req.sendMsgID); 	//
//			insert.setString(8, req.errCode); 	//
//			insert.setString(9, req.errDesc); 	//
//	
//			insert.executeUpdate();
//
//			dbconn.commit();
//			Syslog.show("forwardReq: OK, MsgType="+req.msgType
//				         +", MsgID="+req.msgID);
//			dbManager.checkKeepAlive();
//			return	true;			
//		} catch (SQLException e) {
//			//DUP KEYҪ���⴦��
//			Syslog.showError("SQLException: ErrorCode="+e.getErrorCode()
//					 +", SQL=["+sql+"]");
//			if (e.getErrorCode() == 1){
//				return	true;
//			}
//			
//			Syslog.printStackTrace(e);
//			dbManager.checkConnection(true);
//		} catch (Exception e) {
//			Syslog.printStackTrace(e);
//		}
//
//
//		dbManager.rollback();//dbconn may be closed
//		
//		return	false;
//	}
//
//	//
//	private	void	unimplement(String s) {
//		Syslog.showError("Method<"+s+"> Unimplemented!");
//	}
//	
//	//for test
//	public	static	void	main(String args[])
//		throws	Exception {
//
//		Incoming m = new Incoming();
//
//		m.init(args[0]);
//
//		m.run();
//
//		m.exit();
//
//		return;
//	}
//}
//
