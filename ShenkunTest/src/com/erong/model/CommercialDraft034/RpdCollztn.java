package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * ��Ѻ�����Ϣ
 * @author IBM
 *
 */

public class RpdCollztn extends  CommonTransmission034{
	/*
	 * ��Ѻ���ǩ��ʱ��
	 */
	private Date /*ISODateTime*/ dtTm;
	/*
	 * ��Ѻ�����������Ϣ����Ȩ��)
	 */
	private User collztnBk;
	/*
	 * ��Ѻ���ǩ������Ϣ�������ˣ�
	 */
	private User orgnlCollztnProPsr;
	/*
	 * �н����к�
	 */
	private int/*MaxMin12NumericText*/ agcy;

}
