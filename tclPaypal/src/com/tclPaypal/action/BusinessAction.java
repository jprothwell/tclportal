package com.tclPaypal.action;

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
import com.tclPaypal.service.BusinessService;
import com.tclPaypal.service.CertCacheService;
import com.tclPaypal.util.Constants;


public class BusinessAction extends DispatchAction {
	
	public Logger logger = Logger.getLogger(BusinessAction.class);
	
	private CertCacheService certCacheService;
	
	private BusinessService businessService;
	
	public void setCertCacheService(CertCacheService certCacheService) {
		this.certCacheService = certCacheService;
	}

	public void setBusinessService(BusinessService businessService) {
		this.businessService = businessService;
	}

	public ActionForward payFor(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
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
		encoder.add("RETURNURL",returnURL + "?paymentAmount=" + request.getParameter("paymentAmount") + "&currencyCodeType=" + request.getParameter("currencyCodeType"));
		encoder.add("CANCELURL",cancelURL);
		
		
		encoder.add("PAYMENTACTION","Authorization");
		session.setAttribute("paymentType", "Authorization");
		encoder.add("CURRENCYCODE",request.getParameter("currencyCodeType"));	
		session.setAttribute("currencyCodeType", request.getParameter("currencyCodeType"));
		encoder.add("L_NAME0",request.getParameter("name"));
//		encoder.add("L_NUMBER0","10001");
		encoder.add("L_DESC0","shangmail");
		encoder.add("L_AMT0",request.getParameter("num"));
		encoder.add("L_QTY0",request.getParameter("price"));
//		encoder.add("L_ITEMWEIGHTVALUE1","0.1");
//		encoder.add("L_ITEMWEIGHTUNIT1","lbs");
//		encoder.add("ADDROVERRIDE","1");
		
		float ft = 1*Float.valueOf(request.getParameter("price").trim()).floatValue();
//		encoder.add("ITEMAMT",String.valueOf(ft));
//		encoder.add("TAXAMT","0.00");
		float amt = Util.round(ft,2);	
		float maxamt = Util.round(amt,2);
		encoder.add("AMT",String.valueOf(amt));
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
			session.setAttribute("TotalAmount",decoder.get("AMT"));
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
		System.out.println("PAYMENTACTION::::"+(String)session.getAttribute("paymentType"));
		encoder.add("AMT",(String) session.getAttribute("TotalAmount"));
		System.out.println("AMT::::"+(String)session.getAttribute("TotalAmount"));
		encoder.add("CURRENCYCODE",(String) session.getAttribute("currencyCodeType"));
		System.out.println("CURRENCYCODE::::"+(String)session.getAttribute("currencyCodeType"));
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

			request.setAttribute("resp",resp);
			
			//CreateRecurringPaymentsProfile
//			request.setAttribute("TOKEN",decoder.get("TOKEN"));
//			request.setAttribute("AMT",decoder.get("AMT"));
//			request.setAttribute("CURRENCYCODE",decoder.get("CURRENCYCODE"));
//			return mapping.findForward("recurringPayment");
			return mapping.findForward("confirmSuccess");
		}
		
	}
}
