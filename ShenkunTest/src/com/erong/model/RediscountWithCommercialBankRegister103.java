package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.RcvgBkOfRdscntWthComrclBk;
import com.erong.model.user.RqstngBkOfRdscntWthComrclBk;
import com.erong.model.util.CommercialDraft;

/**
 * ֽƱת���ֵǼǱ���
 * @author SHENKUN
 *
 */
public class RediscountWithCommercialBankRegister103 extends CommercialDraft{

	/*
	 * ת��������
	 */
	private Date dt;
	/*
	 * �ж�����Ϣ
	 */
	private Accptr accptr;
	/*
	 * ��������Ϣ
	 */
	private RqstngBkOfRdscntWthComrclBk rqstngBkOfRdscntWthComrclBk;
	/*
	 * ��������Ϣ
	 */
	private RcvgBkOfRdscntWthComrclBk rcvgBkOfRdscntWthComrclBk;
	/*
	 * ��ע
	 */
	private String rmrk;
}
