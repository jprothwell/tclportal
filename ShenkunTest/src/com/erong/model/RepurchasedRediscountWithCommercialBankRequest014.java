package com.erong.model;

import java.util.Date;

import com.erong.model.user.OrgnlRcvgBkOfRdscntWthComrclBk;
import com.erong.model.util.CommercialDraft;

/**
 * �ع�ʽת����������뱨��
 * @author SHENKUN
 *
 */
public class RepurchasedRediscountWithCommercialBankRequest014 extends CommercialDraft{

//	/*
//	 * ���ı�ʶ
//	 */
//	private MsgId msgId;
//	/*
//	 * Ʊ����Ϣ
//	 */
//	private ComrclDrft comrclDrft;
	
	//ת���������ϢRpdRdscntWthComrclBk
	/*
	 * ת���������������
	 */
	private Date dt;

	/*
	 * ת�����������
	 */
	private String rate;
	/*
	 * ת�������ʵ�����
	 */
	private String amt;
	/*
	 * ����ת�ñ��
	 */
	private String BanEndrsmtMk;
	
	/*
	 * ԭ��������Ϣ
	 */
	 private OrgnlRcvgBkOfRdscntWthComrclBk orgnlRcvgBkOfRdscntWthComrclBk;
}
