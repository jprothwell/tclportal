package com.erong.model;
//NPC和CCPC状态变更报文
import java.util.Date;

import com.erong.model.util.CommercialDraft;

public class ParticipantStatusNotification064 extends CommercialDraft{
//	类别
	private String Tp;
//	节点号
	private String Nb;
//	 系统状态
	private String Sts;
//	附言
	private String Rmrk;
}
