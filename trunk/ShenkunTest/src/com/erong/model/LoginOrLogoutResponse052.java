package com.erong.model;
//登录/退出应答报文
import java.util.Date;

import com.erong.model.util.CommercialDraft;

public class LoginOrLogoutResponse052 extends CommercialDraft{

	
	
//	原登录/退出报文标识   
//	报文标识号
	private String OrgnlMsgId;
//	
	private Date OrgnlMsgCreDtTm;
//	操作类型
	private String TpMk;
//	系统状态
	private String Sts;
//	系统当前时间
	private Date VldtyDt;
//	处理结果码
	private String PrcCd;
//	结果处理说明
	private String PrcMsg;
}
