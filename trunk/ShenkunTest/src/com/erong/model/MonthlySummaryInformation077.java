package com.erong.model;
//ÿ��Ʊ����Ϣ���ܻظ�����
import java.util.Date;
import java.util.List;

import com.erong.model.util.Accptd;
import com.erong.model.util.CommercialDraft;
import com.erong.model.util.Hldg;

public class MonthlySummaryInformation077 extends CommercialDraft {
//	�к�
	private String AcctSvcr;
//	��Ϊ�ж��˵Ĵ���Ʊ����ϸ
	private List<Accptd> accptds;
//	��Ϊ��Ʊ�˵Ĵ���Ʊ����ϸ
	private List<Hldg> hldgs;
}
