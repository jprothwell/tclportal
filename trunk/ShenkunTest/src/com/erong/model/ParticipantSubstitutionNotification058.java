package com.erong.model;
//�����߳нӹ�ϵ֪ͨ����
import java.util.Date;
import java.util.List;

import com.erong.model.util.CommercialDraft;
import com.erong.model.util.CurPtcpt;
import com.erong.model.util.OrgnlPtcpt;

public class ParticipantSubstitutionNotification058 extends CommercialDraft {
//      ʧЧʱ��
      private Date FctvDt;
//      ԭ��������Ϣ�����н��У�
      private String OrgnlPtcpt;
//      �²�������Ϣ���н��У�
      private String CurPtcpt;
//      ԭ��������Ϣ�����н��У�
      private List<OrgnlPtcpt> orgnlPtcpts;
//      �²�������Ϣ���н��У�
      private List<CurPtcpt> curPtcpts;
}
