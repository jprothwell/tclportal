package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.util.CommercialDraft;

/**
 * ֽƱ��ʧֹ������ʾ�߸�ǼǱ���
 * @author SHENKUN
 *
 */
public class SuspendingPaymentRegister110 extends CommercialDraft{
	/*
	 * ֹ���Ǽ���Ϣ  ֹ������
	 */
	private String sspdgPmtTp;
	/*
	 * ֹ���Ǽ���Ϣ ����ֹ������
	 */
	private Date dt;
	/*
	 * �ж�����Ϣ
	 */
	private Accptr accptr;
	/*
	 * ����ֹ������Ϣ
	 */
	private String propsrNm;
	/*
	 * �����ʧֹ������Ϣ
	 */
	private String oprtrNm;
	/*
	 * ��ע
	 */
	private String rmrk;
}
