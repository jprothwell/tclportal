package com.erong.model;
//明细申请报文
import java.util.Date;
import java.util.List;

import com.erong.model.util.CommercialDraft;
import com.erong.model.util.ForRcvdMsgs;
import com.erong.model.util.ForSntMsgs;



public class MoreDetailsRequest074 extends CommercialDraft {

//	行号
	private String AcctSvcr;
//	申请发送明细
	private List<ForSntMsgs> forSntMsgss;
//	申请接受明细
	private List<ForRcvdMsgs> forRcvdMsgss;
	

}
