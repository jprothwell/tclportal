package com.erong.model;

import java.util.List;

import com.erong.model.util.ChrgObj;
import com.erong.model.util.CommercialDraft;
import com.erong.model.util.MsgDtl;
import com.erong.model.util.MsgId;

/**
 * �۷�֪ͨ����
 * @author SHENKUN
 *
 */
public class ChargeNotification081 extends CommercialDraft{
//	/*
//	 * ���ı�ʶ
//	 */
//	private MsgId msgId;

	 //�ƷѶ���
	/*
	 * ����
	 */
	private String nm;
	/*
	 * �кţ����ֱ�Σ�
	 */
	private String acctSvcr;
	// �۷Ѵ�����Ϣ
	 /*
	  * ������
	  */
	private String prcCd;
	/*
	 * ������Ϣ
	 */
	private String prcMsg;
	//������Ϣ
	/*
	 * ����
	 */
	private String mnth;
	/*
	 * �ܽ��
	 */
	private String amt;
	
	//��ϸһ�Զ��ϵ
	/*
	 * �շѶ�������ϸ
	 */
	private List<ChrgObj> chrgObjs;
	/*
	 * ������Ϣ
	 */
	private List<MsgDtl> msgDtls;
}
