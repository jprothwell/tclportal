package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.CollztnBk;
import com.erong.model.user.CollztnPropsr;
import com.erong.model.util.CommercialDraft;

/**
 * ֽƱ��Ѻ�ǼǱ���
 * @author SHENKUN
 *
 */
public class CollateralizationRegister105 extends CommercialDraft{
	
	/*
	 * ��Ѻ��Ϣ
	 */
	private Date dt; 
	/*
	 * �ж�����Ϣ
	 */
	private Accptr accptr;
	/*
	 * ��������Ϣ
	 */
	private CollztnPropsr collztnPropsr;
	/*
	 * ��Ȩ����Ϣ
	 */
	private CollztnBk collztnBk;
	/*
	 * ��ע
	 */
	private String addtlInf;
}
