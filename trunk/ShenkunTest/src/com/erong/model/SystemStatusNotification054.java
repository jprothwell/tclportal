package com.erong.model;
//系统状态变更通知报文
import java.util.Date;

import com.erong.model.util.CommercialDraft;

public class SystemStatusNotification054 extends CommercialDraft {
//	   原系统日期
	private Date orgnlSysDt;
//	   原系统状态
	private String orgnlSysSts;
//	  当前系统时间
	private Date sysDt;
//	  当前系统状态
	private String sysSts;
//	  下一个系统工作日期
	private Date nxtSysDt;
//	营业参考时间
	private Date bizRefTm;
//	附言
	private String rmrk;
}
