package com.erong.model.CommercialDraft034;
import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * 质押信息
 * @author IBM
 *
 */

public class Collztn extends  CommonTransmission034{
	/*
	 * 质押签收时间
	 */
	private Date dtTm;
	/*
	 * 出质人信息
	 */
	private User user;
	/*
	 * 出质人信息 承接行行号
	 */
	private int /*MaxMin12NumericText*/ Agcy;
	/*
	 * 质权人信息
	 */
	private User user1;

}
