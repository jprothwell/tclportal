package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * 质押解除信息
 * @author IBM
 *
 */

public class RpdCollztn extends  CommonTransmission034{
	/*
	 * 质押解除签收时间
	 */
	private Date /*ISODateTime*/ dtTm;
	/*
	 * 质押解除申请人信息（质权人)
	 */
	private User collztnBk;
	/*
	 * 质押解除签收人信息（出质人）
	 */
	private User orgnlCollztnProPsr;
	/*
	 * 承接行行号
	 */
	private int/*MaxMin12NumericText*/ agcy;

}
