package com.erong.model;
//汇总详细回复报文
import java.util.Date;
import java.util.List;

import com.erong.model.util.CommercialDraft;
import com.erong.model.util.RcvdMsgs;
import com.erong.model.util.SntMsgs;

public class DetailsInformation073 extends CommercialDraft{


//   行号
   private String AcctSvcr ;
//   发送明细  
   
   private List<SntMsgs> sntMsgss;

//   接收明细
   private List<RcvdMsgs>  rcvdMsgss;

}
