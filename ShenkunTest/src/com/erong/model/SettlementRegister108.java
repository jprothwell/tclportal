package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.Pyee;
import com.erong.model.util.CommercialDraft;
/**
 * ֽƱ����ǼǱ���
 * @author SHENKUN
 *
 */
public class SettlementRegister108 extends CommercialDraft{

	/*
	 * ��������
	 */
	private Date payDt;
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
