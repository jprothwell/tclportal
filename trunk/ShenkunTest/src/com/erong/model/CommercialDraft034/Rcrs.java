package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * ׷��
 * @author IBM
 *
 */

public class Rcrs extends  CommonTransmission034 {
	/*
	 * ׷������
	 */
	private String /*RecourseTypeCode*/tp;
	/*
	 * ׷��֪ͨ����
	 */
	private Date applDt;
	/*
	 * �峥����
	 */
	private Date dt;
	/*
	 * ׷�����
	 */
	private int /*CurrencyAndAmount*/ reqAmt;
	/*
	 * �峥���
	 */
	private int/*CurrencyAndAmount*/ amt;
	
	/*
	 * ׷������Ϣ��Ϣ
	 */
	
	private User drftHldr;
	/*
	 * ׷������Ϣ��Ϣ �н����к�
	 */
	
	private int/*MaxMin12NumericText*/ drftHldrAgcy;
	/*
	 * �峥����Ϣ
	 */
	
	private User payBk;
	
	/*
	 * �峥����Ϣ �н����к�
	 */
	private int /*MaxMin12NumericText*/ payBkAgcy;
	

}
