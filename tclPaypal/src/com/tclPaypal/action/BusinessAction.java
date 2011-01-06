package com.tclPaypal.action;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.paypal.sdk.core.nvp.NVPDecoder;
import com.paypal.sdk.core.nvp.NVPEncoder;
import com.paypal.sdk.services.NVPCallerServices;
import com.paypal.sdk.util.ResponseBuilder;
import com.paypal.sdk.util.Util;
import com.tclPaypal.domain.Business;
import com.tclPaypal.message.GetResponse;
import com.tclPaypal.service.BusinessService;
import com.tclPaypal.service.CertCacheService;
import com.tclPaypal.service.MessageStatuService;
import com.tclPaypal.util.Constants;
import com.tclPaypal.util.DateUtil;
import com.tclPaypal.util.Pager;
import com.tclPaypal.util.PagerBuilder;


public class BusinessAction extends DispatchAction {
	
	public Logger logger = Logger.getLogger(BusinessAction.class);
	
	private CertCacheService certCacheService;
	
	private BusinessService businessService;
	
	private MessageStatuService messageStatuService;
	
	
	public void setMessageStatuService(MessageStatuService messageStatuService) {
		this.messageStatuService = messageStatuService;
	}

	public void setCertCacheService(CertCacheService certCacheService) {
		this.certCacheService = certCacheService;
	}

	public void setBusinessService(BusinessService businessService) {
		this.businessService = businessService;
	}

	public ActionForward payFor(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 String tradeId = request.getParameter("tradeId");
		 String price = request.getParameter("price");
		 String currency = request.getParameter("currency");
		 String goodsName = request.getParameter("goodsName");
		 
		 HttpSession session = request.getSession();
		 NVPCallerServices caller =  certCacheService.getCertCathe(session.getServletContext().getRealPath(Constants.CERT_PATH_NAME));
		//路径
			StringBuffer url = new StringBuffer();
			url.append("http://");
			url.append(request.getServerName());
			url.append(":");
			url.append(request.getServerPort());
			url.append(request.getContextPath());
		//返回路径
		String returnURL = url.toString()+"/page/redirect.jsp";
		//取消路径
		String cancelURL = url.toString()+"/page/error.jsp";
		
		NVPEncoder encoder = new NVPEncoder();
		encoder.add("METHOD","SetExpressCheckout");
		encoder.add("RETURNURL",returnURL);
		encoder.add("CANCELURL",cancelURL);
		
		
		encoder.add("PAYMENTACTION","Authorization");
		session.setAttribute("paymentType", "Authorization");
		encoder.add("CURRENCYCODE",currency);	
		//session.setAttribute("currencyCodeType", currency);
		encoder.add("L_NAME0",tradeId);
//		encoder.add("L_NUMBER0","10001");
		encoder.add("L_DESC0",goodsName);
		encoder.add("L_AMT0",price);
		encoder.add("L_QTY0","1");
//		encoder.add("L_ITEMWEIGHTVALUE1","0.1");
//		encoder.add("L_ITEMWEIGHTUNIT1","lbs");
//		encoder.add("ADDROVERRIDE","1");
		
		float ft = 1*Float.valueOf(price.trim()).floatValue();
//		encoder.add("ITEMAMT",String.valueOf(ft));
//		encoder.add("TAXAMT","0.00");
		float amt = Util.round(ft,2);	
		float maxamt = Util.round(amt,2);
		encoder.add("AMT",price);
		System.out.println("AMT:::"+String.valueOf(amt));
		System.out.println("amt:::"+amt);
//		encoder.add("MAXAMT",String.valueOf(maxamt));
		
		//RecurringPayments交易
//		encoder.add("L_BILLINGTYPE0","RecurringPayments");
//		encoder.add("L_BILLINGAGREEMENTDESCRIPTION0","Daily Subscription");
		
		//发送信息，并且获取返回信息。
		String ppresponse = (String) caller.call(encoder.encode());
		NVPDecoder resultValues = new NVPDecoder();
		resultValues.decode(ppresponse);
		String strAck = resultValues.get("ACK");
		System.out.println("strAck::"+strAck);
		if(!("Success").equals(strAck) &&!("SuccessWithWarning").equals(strAck))
		{
			return mapping.findForward("error.jsp");
		}else {
			response.sendRedirect("https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&token="+resultValues.get("TOKEN"));
			System.out.println("Token::"+resultValues.get("TOKEN"));
			//response.sendRedirect("https://www.paypal.com/cgi-bin/webscr?cmd=_express-checkout&token="+resultValues.get("TOKEN"));
		}
		return mapping.findForward("");
	}
	
	//成功确认
	public ActionForward confirm(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 HttpSession session = request.getSession();
		 NVPCallerServices caller =  certCacheService.getCertCathe(session.getServletContext().getRealPath(Constants.CERT_PATH_NAME));
		 NVPEncoder encoder = new NVPEncoder();
		 encoder.add("METHOD","GetExpressCheckoutDetails");
		 encoder.add("TOKEN",request.getParameter("token"));
		 String strNVPString = encoder.encode();
		 //发送请求数据获取返回数据
		 String strNVPResponse = (String) caller.call(strNVPString);
		 NVPDecoder decoder = new NVPDecoder();
		 decoder.decode(strNVPResponse);
		 ResponseBuilder rb=new ResponseBuilder();
		 String header1="Review Order";
		 String header2="Step 3: DoExpressCheckoutPayment, Order Review Page";
		 String resp=rb.BuildResponse(decoder,header1,header2);
		   	
		String strAck = decoder.get("ACK"); 
		if(!("Success").equals(strAck) &&!("SuccessWithWarning").equals(strAck))
		{	
			logger.debug("fail info: "+decoder);
			request.setAttribute("response",decoder);
			return mapping.findForward("fail");
		}else{
			request.setAttribute("resp",resp);
			request.setAttribute("token",decoder.get("TOKEN"));
			request.setAttribute("PayerID",decoder.get("PAYERID"));
			request.setAttribute("TotalAmount",decoder.get("AMT"));
			request.setAttribute("CURRENCYCODE",decoder.get("CURRENCYCODE"));
			request.setAttribute("orderNum", decoder.get("L_NAME0"));
			request.setAttribute("customerEmail", decoder.get("EMAIL"));
			return mapping.findForward("buyConfirm");
		}
	}
	//确认返回
	public ActionForward doExpressCheckoutPayment(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 HttpSession session = request.getSession();
		 NVPCallerServices caller =  certCacheService.getCertCathe(session.getServletContext().getRealPath(Constants.CERT_PATH_NAME));
		 NVPEncoder encoder = new NVPEncoder();
		 
		encoder.add("METHOD","DoExpressCheckoutPayment");
		encoder.add("TOKEN",request.getParameter("token"));
		encoder.add("PAYERID",request.getParameter("PayerID"));
		encoder.add("PAYMENTACTION",(String) session.getAttribute("paymentType"));	
//		System.out.println("PAYMENTACTION::::"+(String)session.getAttribute("paymentType"));
		encoder.add("AMT",(String) request.getParameter("TotalAmount"));
		encoder.add("CURRENCYCODE",(String) request.getParameter("CURRENCYCODE"));
		
	    String strNVPString = encoder.encode();
		String strNVPResponse = (String) caller.call( strNVPString);		
		NVPDecoder decoder = new NVPDecoder();	
		decoder.decode(strNVPResponse);
			
		ResponseBuilder rb=new ResponseBuilder();
		String header1="DoExpressCheckoutPayment";
		String header2="Thank you for your payment!";
		String resp=rb.BuildResponse(decoder,header1,header2);
		   		
		String strAck = decoder.get("ACK"); 
		if(!("Success").equals(strAck) &&!("SuccessWithWarning").equals(strAck)){
			logger.debug("fail info: "+decoder);
			request.setAttribute("response",decoder);
			return mapping.findForward("error");
		}else{
			//保存交易成功信息
			Business business = new Business();
			business.setOrdernum(request.getParameter("orderNum"));
			business.setToken(decoder.get("TOKEN"));
			business.setSavetime(new Date());
			business.setStatute(0);//paypal支付成功
			business.setCustomerpaypalnum(request.getParameter("customerEmail"));
			businessService.save(business);
			//发送信息,获取返回状态
			String statue = GetResponse.getShangmailResponse(business.getOrdernum());
			//收到回复后更改数据库状态，没收到回复，放入容器中，不断重发。
			if("ok".equals(statue)){
				business.setStatute(1);//paypal支付成功，shangmail反馈成功
				businessService.update(business);
			}else{
				business.setStatute(20);//paypal支付成功，尚邮反馈不成功
				businessService.update(business);
				//保存在内存中
				messageStatuService.add(business);
			}
			
			request.setAttribute("resp",resp);
			
			//CreateRecurringPaymentsProfile
//			request.setAttribute("TOKEN",decoder.get("TOKEN"));
//			request.setAttribute("AMT",decoder.get("AMT"));
//			request.setAttribute("CURRENCYCODE",decoder.get("CURRENCYCODE"));
//			return mapping.findForward("recurringPayment");
			return mapping.findForward("confirmSuccess");
		}
		
	}
	
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		Map map = new HashMap();
		String tradeId = request.getParameter("tradeId");
		String customerPaypal = request.getParameter("customerPaypal");
		map.put("tradeId", tradeId);
		map.put("customerPaypal", customerPaypal);
		String startDate=request.getParameter("startDate");
		String endDate=request.getParameter("endDate");
		if (("").equals(startDate)||startDate==null)
		{
			startDate = DateUtil.getTheMonthFirstDay();
		}
		if (("").equals(endDate)||endDate==null)
		{
			endDate = DateUtil.getCurrentDate();
		}
		
		Pager pager = PagerBuilder.build(request);
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		Date startD = null;
		Date endD = null;
		try {
			startD =  new SimpleDateFormat("yyyy-MM-dd").parse(startDate);
			endD = DateUtil.getTomorrow(endDate);
			
		} catch (ParseException e) {
			e.printStackTrace();
		}
		if(!"".equals(startDate)&&startDate!=null){
			map.put("startDate",startD);
		}
		if(!"".equals(endDate)&&endDate!=null){
			map.put("endDate",endD);
		}
		
		pager.setEntryCount(businessService.findBusinessCount(map));
		List<Business> list = businessService.findBusiness(map);
		request.setAttribute("startDate", startDate);
		request.setAttribute("endDate", endDate);
		request.setAttribute("list",list);
		return mapping.findForward("findList");
	}
}