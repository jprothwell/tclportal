package com.erong.model;

import java.util.Date;

import com.erong.model.user.Rcrsr;
import com.erong.model.user.RcvgPrsnOfRcrs;
import com.erong.model.util.CommercialDraft;

/**
 * ׷��֪ͨ����
 * @author SHENKUN
 *
 */
public class RecourseNotification022 extends CommercialDraft{
//	/*
//	 * ���ı�ʶ
//	 */
//	private MsgId msgId;
//	/*
//	 * Ʊ����Ϣ
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * ׷������
	 */
	private String tp;
	/*
	 * ׷��֪ͨ����
	 */
	private Date applDt;
	/*
	 * ׷�����
	 */
	private String reqAmt;
	/*
	 * ׷������Ϣ
	 */
	private Rcrsr rcrsr;
	/*
	 * ��׷����Ϣ
	 */
	private RcvgPrsnOfRcrs rcvgPrsnOfRcrs;
}
