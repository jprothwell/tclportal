package com.erong.model;

import java.util.Date;

import com.erong.model.util.CommercialDraft;
/**
 * ���ʧ�ܻظ�����
 * @author IBM
 *
 */

public class ExceptionNotification035 extends CommercialDraft {
	
	/*
	 * ԭ���뱨�ı�ʶ ���ı�ʶ��
	 */
	private String orgnlMsgId;
	
	/*
	 * ԭ���뱨�ı�ʶ ����ʱ��
	 */
	private Date orgncreDtTm;
	/*
	 * �쳣��Ϣ �쳣������
	 */
	private String /*ExceptionCode*/ xcptnCd;
	/*
	 * �쳣��Ϣ
	 */
	private String /*Max60Text*/ xcptnMsg;

}
