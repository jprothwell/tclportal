package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.RdscntWthCntrlBkSys;
import com.erong.model.user.RqstngBkOfRdscntWthCntrlBk;
import com.erong.model.util.CommercialDraft;

/**
 * ֽƱ�����ֵǼǱ���
 * @author SHENKUN
 *
 */
public class RediscountWithCentralBankRegister104 extends CommercialDraft{
	
	/*
	 * ����������
	 */
	private Date dt;
	/*
	 * �ж�����Ϣ
	 */
	private Accptr accptr;
	/*
	 * ��������Ϣ
	 */
	private RqstngBkOfRdscntWthCntrlBk rqstngBkOfRdscntWthCntrlBk;
	/*
	 * ��������Ϣ
	 */
	private RdscntWthCntrlBkSys rdscntWthCntrlBkSys;
	/*
	 * ��ע
	 */
	private String rmrk;
}
