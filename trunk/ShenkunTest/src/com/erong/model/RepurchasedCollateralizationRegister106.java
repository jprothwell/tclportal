package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.OrginCollztnBk;
import com.erong.model.user.OrginCollztnPrpsr;
import com.erong.model.util.CommercialDraft;

/**
 * ֽƱ��Ѻ����ǼǱ���
 * @author SHENKUN
 *
 */
public class RepurchasedCollateralizationRegister106 extends CommercialDraft{
	
	/*
	 * ��Ѻ�������
	 */
	private Date dt;
	/*
	 * �ж�����Ϣ
	 */
	private Accptr accptr;
	/*
	 * ԭ��Ȩ����Ϣ
	 */
	private OrginCollztnBk orginCollztnBk;
	/*
	 * ԭ��������Ϣ
	 */
	private OrginCollztnPrpsr orginCollztnPrpsr;
	/*
	 * ��ע
	 */
	private String rmrk;
}
