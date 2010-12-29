package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * 保证信息
 * @author IBM
 *
 */

public class Guarntee extends  CommonTransmission034{
	/*
	 * 保证签收时间
	 */
	private Date dttm;
	
	/*
	 * 被保证人信息
	 */
	
	private User  user;
	/*
	 *  被保证人信息 承接行行号
	 */
	private int /*MaxMin12NumericText*/ Agcy;
	/*
	 * 保证人信息
	 */
	
	private User user1;
}
