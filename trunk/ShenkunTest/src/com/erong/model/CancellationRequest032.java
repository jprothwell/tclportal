package com.erong.model;

import java.util.Date;

import com.erong.model.util.CommercialDraft;

/**
 * ͨ�ó��ر���
 * @author IBM
 *
 */
public class CancellationRequest032 extends CommercialDraft {

	/*
	 * ԭ���뱨�ı�ʶ��
	 */
	private String orgnlMsgId;
	/*
	 * ԭ����ʱ��
	 */
	private Date orgnlCreDtTm;
	/*
	 * ���������˵���ǩ��
	 */
	private String elctrncSgntr;
	/*
	 * �����������˺�
	 */
	private int acctSvcr;
	/*
	 * �н����к�
	 */
	private int acctSvcrAgcy;
}
