package com.erong.model;

import com.erong.model.user.User;
import com.erong.model.util.CommercialDraft;
/**
 * 支付信用信息查询报文
 * @author IBM
 *
 */

public class CreditInfomationQueryRequest037 extends CommercialDraft {
	
	/*
	 * 查询人
	 */
	private User qrier;
	
	/*
	 * 查询人 承接行行号
	 */
	private int /*MaxMin12NumericText*/qrierAgcy;

}
