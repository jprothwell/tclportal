package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.Pyee;
import com.erong.model.util.CommercialDraft;
/**
 * ֽƱ�ܸ��ǼǱ���
 * @author SHENKUN
 *
 */
public class PaymentRefusedRegister109 extends CommercialDraft{
	
	/*
	 * �ܸ�����
	 */
	private Date dt;
	/*
	 * �ܸ�����
	 */
	private String dshnrCd;
	/*
	 * �ܸ���ע��Ϣ
	 */
	private String dshnrRsn;
	/*
	 * �ж�����Ϣ
	 */
	private Accptr accptr;
	/*
	 * ���һ�ֳ�Ʊ����Ϣ
	 */
	private Pyee pyee;
	/*
	 * ��ע
	 */
	private String rmrk;
}
