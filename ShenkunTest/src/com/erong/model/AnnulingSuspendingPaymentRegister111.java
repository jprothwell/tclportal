package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.util.CommercialDraft;
/**
 * ֽƱֹ������ǼǱ���
 * @author SHENKUN
 *
 */
public class AnnulingSuspendingPaymentRegister111 extends CommercialDraft{
	
	/*
	 * ֹ�������Ϣ ֹ���������
	 */
	private String tp;
	/*
	 * ֹ�������Ϣ ֹ���������
	 */
	private Date dt;
	/*
	 * �ж�����Ϣ
	 */
	private Accptr accptr;
	/*
	 * ����ֹ���������Ϣ
	 */
	private String propsrNm;
	/*
	 * ֹ���������Ϣ 
	 */
	private String OprtrNm;
	/*
	 * ��ע
	 */
	private String rmrk;
}
