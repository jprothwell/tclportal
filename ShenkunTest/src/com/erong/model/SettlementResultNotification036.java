package com.erong.model;

import java.util.Date;

import com.erong.model.user.User;
import com.erong.model.util.CommercialDraft;

/**
 * ����������֪ͨ����
 * 
 * @author IBM
 * 
 */

public class SettlementResultNotification036 extends
		CommercialDraft {
	/*
	 * ԭ���뱨�ı�ʶ ���ı�ʶ��
	 */
	private String orgnlMsgId;

	/*
	 * ԭ���뱨�ı�ʶ ����ʱ��
	 */
	private Date orgncreDtTm;
	/* 
	 *��ʱת�˱�����Ϣ ��������ߺ���
	 */
	private String trfRef;
	/*
	 * ��������
	 */
	private Date tradDt;
	/*
	 * ֧���������
	 */
	private String trfId;
	/*
	 * ������
	 */
	private String prcCd;
	/*
	 * ������Ϣ
	 */
	private String prcMsg;
	/*
	 * ǩ������Ϣ
	 */
	private User sgnr;
	/*
	 * ǩ������Ϣ �н����к�
	 */
	private int SgnrId;
	/*
	 * ԭҵ����������Ϣ��Ϣ
	 */
	private User orgnlPropsr;
	/*
	 * ԭҵ����������Ϣ��Ϣ �н����к�
	 */
	private int OrgnlPropsrId;
	
}
