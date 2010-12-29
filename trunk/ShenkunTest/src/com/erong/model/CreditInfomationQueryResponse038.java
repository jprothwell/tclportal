package com.erong.model;

import com.erong.model.util.CommercialDraft;

/**
 * 支付信用信息查复报
 * @author IBM
 *
 */

public class CreditInfomationQueryResponse038 extends CommercialDraft {
	/*
	 * 被查询人  名称 组织机构代码
	 */
	
	
	/*
	 * 查询结果信息  承兑总笔数
	 */
	
	private int accptdQty;
	
	/*
	 * 承兑总金额
	 */
	private int accptdAmt;
	/*
	 * 已结清总笔数
	 */
	private int pydQty;
	/*
	 * 已结清总金额
	 */
	private int pydAmt;
	/*
	 * 未结清总笔数
	 */
	private int pdgQty;
	/*
	 * 未结清款总金额
	 */
	private int pdgAmt;
	/*
	 * 拒付总笔数
	 */
	private int dshnrQty;
	/*
	 * 拒付总金额
	 */
	private int dshnrAmt;
	/*
	 * 今年以来拒付总笔数
	 */
	private int dshnrQtySncThsYr;
	/*
	 * 今年以来拒付总金额
	 */
	private int dshnrAmtSncThsYr;
	/*
	 * 去年以来拒付总笔数
	 */
	private int dshnrQtySncLastYr;
	/*
	 * 去年以来拒付总金额
	 */
	private int dshnrAmtSncLastYr;

}
