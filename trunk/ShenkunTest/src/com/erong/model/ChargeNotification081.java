package com.erong.model;

import java.util.List;

import com.erong.model.util.ChrgObj;
import com.erong.model.util.CommercialDraft;
import com.erong.model.util.MsgDtl;
import com.erong.model.util.MsgId;

/**
 * 扣费通知报文
 * @author SHENKUN
 *
 */
public class ChargeNotification081 extends CommercialDraft{
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;

	 //计费对象
	/*
	 * 名称
	 */
	private String nm;
	/*
	 * 行号（大额直参）
	 */
	private String acctSvcr;
	// 扣费处理信息
	 /*
	  * 处理码
	  */
	private String prcCd;
	/*
	 * 处理信息
	 */
	private String prcMsg;
	//费用信息
	/*
	 * 年月
	 */
	private String mnth;
	/*
	 * 总金额
	 */
	private String amt;
	
	//明细一对多关系
	/*
	 * 收费对象行明细
	 */
	private List<ChrgObj> chrgObjs;
	/*
	 * 报文信息
	 */
	private List<MsgDtl> msgDtls;
}
