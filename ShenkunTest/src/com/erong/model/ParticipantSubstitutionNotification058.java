package com.erong.model;
//参与者承接关系通知报文
import java.util.Date;
import java.util.List;

import com.erong.model.util.CommercialDraft;
import com.erong.model.util.CurPtcpt;
import com.erong.model.util.OrgnlPtcpt;

public class ParticipantSubstitutionNotification058 extends CommercialDraft {
//      失效时间
      private Date FctvDt;
//      原参与者信息（被承接行）
      private String OrgnlPtcpt;
//      新参与者信息（承接行）
      private String CurPtcpt;
//      原参与者信息（被承接行）
      private List<OrgnlPtcpt> orgnlPtcpts;
//      新参与者信息（承接行）
      private List<CurPtcpt> curPtcpts;
}
