package com.erong.model;

import com.erong.model.util.CommercialDraft;

/**
 * 自由格式报文
 * @author IBM
 *
 */

public class FreeFormatMessageReques039 extends CommercialDraft {
	/*
	 * 报文内容 广播级别
	 */
	private String brdcstLvl;
	/*
	 * 报文内容 
	 */
	private String msgCnts;
	/*
	 * 发起行行号
	 */
	private int SndrAcct;
	/*
	 * 接收行行号
	 */
	private int rcvrId;

}
