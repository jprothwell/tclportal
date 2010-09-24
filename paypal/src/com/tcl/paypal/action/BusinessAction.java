package com.tcl.paypal.action;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URLDecoder;
import java.net.URLEncoder;
import java.util.HashMap;
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
import com.tcl.paypal.domain.Business;
import com.tcl.paypal.domain.Gameresource;
import com.tcl.paypal.domain.Goods;
import com.tcl.paypal.service.BusinessService;
import com.tcl.paypal.service.CertCacheService;
import com.tcl.paypal.service.GameresourceService;
import com.tcl.paypal.service.GoodsService;
import com.tcl.paypal.util.Constants;

public class BusinessAction extends DispatchAction {
	
	public Logger logger = Logger.getLogger(BusinessAction.class);
	
	private CertCacheService certCacheService;
	
	private BusinessService businessService;
	
	private GoodsService goodsService;
	
	private GameresourceService gameresourceService;
	
	public void setGameresourceService(GameresourceService gameresourceService) {
		this.gameresourceService = gameresourceService;
	}
	
	public void setGoodsService(GoodsService goodsService) {
		this.goodsService = goodsService;
	}
	
	public void setCertCacheService(CertCacheService certCacheService) {
		this.certCacheService = certCacheService;
	}
	
	public void setBusinessService(BusinessService businessService) {
		this.businessService = businessService;
	}

	//手机支付
	public ActionForward mobliePay(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String chargeEmail = request.getParameter("chargeEmail");
		String id = request.getParameter("id");
		int size = 0;
		if(!("").equals(chargeEmail)){
			//根据goods id和chargeEmail查找是否支付
			Map map = new HashMap();
			map.put("buyname", chargeEmail);
			map.put("goodid", id);
			size = businessService.findBusiness(map);
		}
		if(size==0){
			 HttpSession session = request.getSession();
			 //将货物id保存在session里面
			 session.setAttribute(Constants.GOODS_ID,request.getParameter("id"));
			 NVPCallerServices caller =  certCacheService.getCertCathe(session);
			//路径
				StringBuffer url = new StringBuffer();
				url.append("http://");
				url.append(request.getServerName());
				url.append(":");
				url.append(request.getServerPort());
				url.append(request.getContextPath());
			//返回路径
			String returnURL = url.toString()+"/page/common/redirect.jsp";
			//取消路径
			String cancelURL = url.toString()+"/page/common/error.jsp";
			
			NVPEncoder encoder = new NVPEncoder();
			encoder.add("METHOD","SetMobileCheckout");
			float ft = Float.valueOf(request.getParameter("num").trim()).floatValue()*Float.valueOf(request.getParameter("price").trim()).floatValue();
			encoder.add("ITEMAMT",String.valueOf(ft));
			encoder.add("TAXAMT","0.00");
			//amount = itemamount+ shippingamt+shippingdisc+taxamt+insuranceamount;
			float amt = Util.round(ft,2);	
			encoder.add("AMT",String.valueOf(amt));
			System.out.println("currencyCodeType::"+request.getParameter("currencyCodeType"));
			encoder.add("CURRENCYCODE",request.getParameter("currencyCodeType"));	//mobile
			encoder.add("DESC",request.getParameter("name"));
			encoder.add("RETURNURL",returnURL + "?paymentAmount=" + request.getParameter("paymentAmount") + "&currencyCodeType=" + request.getParameter("currencyCodeType"));
			encoder.add("CANCELURL",cancelURL);
//			encoder.add("ADDRESSDISPLAY","0");
			encoder.add("VERSION","60.0");
		
			//发送信息，并且获取返回信息。
			String ppresponse = (String) caller.call(encoder.encode());
			NVPDecoder resultValues = new NVPDecoder();
			resultValues.decode(ppresponse);
			String strAck = resultValues.get("ACK");
			System.out.println("strAck::"+strAck);
			if(strAck !=null && !(strAck.equals("Success") || strAck.equals("SuccessWithWarning")))
			{	
				logger.debug("fail"+ ppresponse);
				return mapping.findForward("error");
			}else {
				response.sendRedirect("https://www.sandbox.paypal.com/wc?t="+resultValues.get("TOKEN"));
//				response.sendRedirect("https://www.paypal.com/wc?t="+resultValues.get("TOKEN"));
			}
			return mapping.findForward("");
		}else{
			//直接下载
			//下载
			 HttpSession session = request.getSession();
			 String filePath = Constants.DOWNLOAD_PATH;
			//下载文件
//			Goods goods = goodsService.queryGoods(Integer.parseInt(id));
//			String fileName = goods.getJarname();
			Gameresource gameresource = gameresourceService.queryGameresource(Integer.parseInt((String)session.getAttribute(Constants.GOODS_ID)));
			String fileName = gameresource.getFile1();
			fileName = URLDecoder.decode(fileName,"UTF-8");
			fileName = URLEncoder.encode(fileName, "UTF-8");
			response.setContentType("application/txt"); 
			response.addHeader("Content-Disposition", "attachment; filename=" + fileName);
			//获取文件输入流和输出流
			InputStream is = new BufferedInputStream(new FileInputStream(filePath+"\\"+fileName));
			OutputStream os = new BufferedOutputStream(response.getOutputStream());
			int bufferSize = 1024*8;
			byte[] buffer = new byte[bufferSize];
			int len = 0;
			while((len = is.read(buffer, 0, bufferSize))!=-1){
				os.write(buffer, 0, len);
			}
			is.close();
			os.close();
			return mapping.findForward("");
		}
		
		
	}
	
	//手机成功确认
	public ActionForward moblieConfirm(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 HttpSession session = request.getSession();
		 NVPCallerServices caller =  certCacheService.getCertCathe(session);
		 NVPEncoder encoder = new NVPEncoder();
		 encoder.add("METHOD","DoMobileCheckoutPayment");
		 encoder.add("TOKEN",request.getParameter("token"));
		 encoder.add("VERSION","60.0");
		 String strNVPString = encoder.encode();
		 //发送请求数据获取返回数据
		 String strNVPResponse = (String) caller.call(strNVPString);
		 NVPDecoder decoder = new NVPDecoder();
		 decoder.decode(strNVPResponse);
		 ResponseBuilder rb=new ResponseBuilder();
		 String header1="Order complete";
		 String header2="you order has been complete and will delivered shotly ";
		 String resp=rb.BuildResponse(decoder,header1,header2);
		   	
		String strAck = decoder.get("ACK"); 
		if(strAck !=null && !(strAck.equals("Success") || strAck.equals("SuccessWithWarning")))
		{	
			logger.debug("fail info: "+decoder);
			request.setAttribute("response",decoder);
			return mapping.findForward("error");
		}else{
			request.setAttribute("resp",resp);
			request.setAttribute("token",decoder.get("TOKEN"));
			//request.setAttribute("PayerID",decoder.get("PAYERID"));
			session.setAttribute("TotalAmount",decoder.get("AMT"));
//			System.out.println(">>"+decoder.get("EMAIL"));
			//下载
//			String filePath = session.getServletContext().getRealPath("game");
//			System.out.println("filePath::"+filePath);
//			//下载文件
//			String fileName = "RussGame.jar";
//			fileName = URLDecoder.decode(fileName,"UTF-8");
//			fileName = URLEncoder.encode(fileName, "UTF-8");
//			response.setContentType("application/txt"); 
//			response.addHeader("Content-Disposition", "attachment; filename=" + fileName);
//			//获取文件输入流和输出流
//			InputStream is = new BufferedInputStream(new FileInputStream(filePath+"\\"+fileName));
//			OutputStream os = new BufferedOutputStream(response.getOutputStream());
//			int bufferSize = 1024*8;
//			byte[] buffer = new byte[bufferSize];
//			int len = 0;
//			while((len = is.read(buffer, 0, bufferSize))!=-1){
//				os.write(buffer, 0, len);
//			}
//			is.close();
//			os.close();
			//支付成功，记录支付信息
			Business business = new Business();
			business.setBuyname(decoder.get("EMAIL"));
			business.setGoodid(Integer.parseInt((String)session.getAttribute(Constants.GOODS_ID)));
			businessService.save(business);
			return mapping.findForward("confirmSuccess");
		}
	}
	
	public ActionForward payFor(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 HttpSession session = request.getSession();
		 NVPCallerServices caller =  certCacheService.getCertCathe(session);
		//路径
			StringBuffer url = new StringBuffer();
			url.append("http://");
			url.append(request.getServerName());
			url.append(":");
			url.append(request.getServerPort());
			url.append(request.getContextPath());
		//返回路径
		String returnURL = url.toString()+"/page/common/redirect.jsp";
		//取消路径
		String cancelURL = url.toString()+"/page/common/error.jsp";
		
		NVPEncoder encoder = new NVPEncoder();
		encoder.add("METHOD","SetExpressCheckout");
		encoder.add("RETURNURL",returnURL + "?paymentAmount=" + request.getParameter("paymentAmount") + "&currencyCodeType=" + request.getParameter("currencyCodeType"));
		encoder.add("CANCELURL",cancelURL);
		
		
		encoder.add("PAYMENTACTION","Authorization");
		session.setAttribute("paymentType", "Authorization");
		encoder.add("CURRENCYCODE",request.getParameter("currencyCodeType"));	
		session.setAttribute("currencyCodeType", request.getParameter("currencyCodeType"));
		encoder.add("L_NAME0",request.getParameter("L_NAME0"));
		encoder.add("L_NUMBER0","10001");
		encoder.add("L_DESC0","game");
		encoder.add("L_AMT0",request.getParameter("L_AMT0"));
		encoder.add("L_QTY0",request.getParameter("L_QTY0"));
		encoder.add("L_ITEMWEIGHTVALUE1","0.1");
		encoder.add("L_ITEMWEIGHTUNIT1","lbs");
		encoder.add("ADDROVERRIDE","1");
		
		float ft = Float.valueOf(request.getParameter("L_QTY0").trim()).floatValue()*Float.valueOf(request.getParameter("L_AMT0").trim()).floatValue();
		encoder.add("ITEMAMT",String.valueOf(ft));
		encoder.add("TAXAMT","0.00");
		float amt = Util.round(ft,2);	
		float maxamt = Util.round(amt,2);
		encoder.add("AMT",String.valueOf(amt));
		encoder.add("MAXAMT",String.valueOf(maxamt));
		
		//encoder.add("AMT",request.getParameter("paymentAmount"));
//		encoder.add("SHIPTONAME",request.getParameter("NAME"));
//		encoder.add("SHIPTOSTREET",request.getParameter("SHIPTOSTREET"));
//		encoder.add("SHIPTOCITY",request.getParameter("SHIPTOCITY"));
//		encoder.add("SHIPTOSTATE",request.getParameter("SHIPTOSTATE"));
//		encoder.add("SHIPTOCOUNTRY",request.getParameter("SHIPTOCOUNTRYCODE"));
//		encoder.add("SHIPTOZIP",request.getParameter("SHIPTOZIP"));
		//amount = itemamount+ shippingamt+shippingdisc+taxamt+insuranceamount;
//		encoder.add("CALLBACK","https://www.ppcallback.com/callback.pl");
		
//		encoder.add("SHIPDISCAMT","0.00");
//		encoder.add("SHIPPINGAMT","0.00");
//		encoder.add("INSURANCEOPTIONOFFERED","false");
//		encoder.add("INSURANCEAMT","0.00");
//		encoder.add("L_SHIPPINGOPTIONISDEFAULT0","false");
//		encoder.add("L_SHIPPINGOPTIONNAME0","Ground");
//		encoder.add("L_SHIPPINGOPTIONLABEL0","UPS Ground 7 Days");
//		encoder.add("L_SHIPPINGOPTIONAMOUNT0","0.00");
//		encoder.add("L_SHIPPINGOPTIONISDEFAULT1","true");
//		encoder.add("L_SHIPPINGOPTIONNAME1","Ground");
//		encoder.add("L_SHIPPINGOPTIONlABEL1","UPS Ground 7 Days");
//		encoder.add("L_SHIPPINGOPTIONAMOUNT1","0.00");
//		encoder.add("CALLBACKTIMEOUT","4");
		
		//发送信息，并且获取返回信息。
		String ppresponse = (String) caller.call(encoder.encode());
		NVPDecoder resultValues = new NVPDecoder();
		resultValues.decode(ppresponse);
		String strAck = resultValues.get("ACK");
		System.out.println("strAck::"+strAck);
		if(strAck !=null && !(strAck.equals("Success") || strAck.equals("SuccessWithWarning")))
		{
			return mapping.findForward("error.jsp");
		}else {
			//response.sendRedirect("https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&token="+resultValues.get("TOKEN"));
			System.out.println("Token::"+resultValues.get("TOKEN"));
			response.sendRedirect("https://www.paypal.com/cgi-bin/webscr?cmd=_express-checkout&token="+resultValues.get("TOKEN"));
		}
		return mapping.findForward("");
	}
	
	//成功确认
	public ActionForward confirm(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 HttpSession session = request.getSession();
		 NVPCallerServices caller =  certCacheService.getCertCathe(session);
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
		if(strAck !=null && !(strAck.equals("Success") || strAck.equals("SuccessWithWarning")))
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
		 NVPCallerServices caller =  certCacheService.getCertCathe(session);
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
		if(strAck !=null && !(strAck.equals("Success") || strAck.equals("SuccessWithWarning"))){
			logger.debug("fail info: "+decoder);
			request.setAttribute("response",decoder);
			return mapping.findForward("error");
		}else{
			request.setAttribute("resp",resp);
			//下载
			String filePath = session.getServletContext().getRealPath("game");
			System.out.println("filePath::"+filePath);
			//下载文件
			String fileName = "RussGame.jar";
			fileName = URLDecoder.decode(fileName,"UTF-8");
			fileName = URLEncoder.encode(fileName, "UTF-8");
			response.setContentType("application/txt"); 
			response.addHeader("Content-Disposition", "attachment; filename=" + fileName);
			//获取文件输入流和输出流
			InputStream is = new BufferedInputStream(new FileInputStream(filePath+"\\"+fileName));
			OutputStream os = new BufferedOutputStream(response.getOutputStream());
			int bufferSize = 1024*8;
			byte[] buffer = new byte[bufferSize];
			int len = 0;
			while((len = is.read(buffer, 0, bufferSize))!=-1){
				os.write(buffer, 0, len);
			}
			is.close();
			os.close();
			
			return mapping.findForward("confirmSuccess");
//			return mapping.findForward("confirmSuccess");
		}
		
	}
	
//	public ActionForward mobilePayFor(ActionMapping mapping, ActionForm form,
//			HttpServletRequest request, HttpServletResponse response)
//			throws Exception {
//		 HttpSession session = request.getSession();
//		 NVPCallerServices caller =  certCacheService.getCertCathe(session);
//		//路径
//			StringBuffer url = new StringBuffer();
//			url.append("http://");
//			url.append(request.getServerName());
//			url.append(":");
//			url.append(request.getServerPort());
//			url.append(request.getContextPath());
//		//返回路径
//		String returnURL = url.toString()+"/page/common/redirect.jsp";
//		//取消路径
//		String cancelURL = url.toString()+"/page/common/error.jsp";
//		
//		NVPEncoder encoder = new NVPEncoder();
//		encoder.add("METHOD","SetExpressCheckout");
//		//mobile require
//		encoder.add("RETURNURL",returnURL + "?paymentAmount=" + request.getParameter("paymentAmount") + "&currencyCodeType=" + request.getParameter("currencyCodeType"));
//		encoder.add("CANCELURL",cancelURL);
//		
//		//encoder.add("AMT",request.getParameter("paymentAmount"));
//		encoder.add("PAYMENTACTION","Authorization");
//		session.setAttribute("paymentType", "Authorization");
//		encoder.add("CURRENCYCODE",request.getParameter("currencyCodeType"));	
//		session.setAttribute("currencyCodeType", request.getParameter("currencyCodeType"));
//		
//		encoder.add("SHIPTONAME",request.getParameter("NAME"));
//		encoder.add("SHIPTOSTREET",request.getParameter("SHIPTOSTREET"));//mobile
//		encoder.add("SHIPTOCITY",request.getParameter("SHIPTOCITY"));//mobile
//		encoder.add("SHIPTOSTATE",request.getParameter("SHIPTOSTATE"));
//		encoder.add("SHIPTOCOUNTRY",request.getParameter("SHIPTOCOUNTRYCODE"));//mobile
//		encoder.add("SHIPTOZIP",request.getParameter("SHIPTOZIP"));
//		
//		encoder.add("L_NAME1",request.getParameter("L_NAME1"));
//		encoder.add("L_NUMBER1","10001");
//		encoder.add("DESC","24-piece boxes");
//		encoder.add("L_AMT1",request.getParameter("L_AMT1"));
//		encoder.add("L_QTY1",request.getParameter("L_QTY1"));
//		encoder.add("L_ITEMWEIGHTVALUE1","0.5");
//		encoder.add("L_ITEMWEIGHTUNIT1","lbs");
//		encoder.add("ADDROVERRIDE","1");
//		
//		float ft = Float.valueOf(request.getParameter("L_QTY1").trim()).floatValue()*Float.valueOf(request.getParameter("L_AMT1").trim()).floatValue();
//		encoder.add("ITEMAMT",String.valueOf(ft));
//		encoder.add("TAXAMT","2.00");
//		//amount = itemamount+ shippingamt+shippingdisc+taxamt+insuranceamount;
//		float amt = Util.round(ft + 5.00f+ 2.00f+1.00f,2);	
//		float maxamt = Util.round(amt+25.00f,2);
//		encoder.add("SHIPDISCAMT","-3.00");
//		encoder.add("AMT",String.valueOf(amt));
//		encoder.add("SHIPPINGAMT","8.00");
//		encoder.add("MAXAMT",String.valueOf(maxamt));
//		encoder.add("CALLBACK","https://www.ppcallback.com/callback.pl");
//		encoder.add("INSURANCEOPTIONOFFERED","true");
//		encoder.add("INSURANCEAMT","1.00");
//		encoder.add("L_SHIPPINGOPTIONISDEFAULT0","false");
//		encoder.add("L_SHIPPINGOPTIONNAME0","Ground");
//		encoder.add("L_SHIPPINGOPTIONLABEL0","UPS Ground 7 Days");
//		encoder.add("L_SHIPPINGOPTIONAMOUNT0","3.00");
//		encoder.add("L_SHIPPINGOPTIONISDEFAULT1","true");
//		encoder.add("L_SHIPPINGOPTIONNAME1","UPS Air");
//		encoder.add("L_SHIPPINGOPTIONlABEL1","UPS Next Day Air");
//		encoder.add("L_SHIPPINGOPTIONAMOUNT1","8.00");
//		encoder.add("CALLBACKTIMEOUT","4");
//		
//		//发送信息，并且获取返回信息。
//		String ppresponse = (String) caller.call(encoder.encode());
//		NVPDecoder resultValues = new NVPDecoder();
//		resultValues.decode(ppresponse);
//		String strAck = resultValues.get("ACK");
//		
//		if(strAck !=null && !(strAck.equals("Success") || strAck.equals("SuccessWithWarning")))
//		{
//			return mapping.findForward("error.jsp");
//		}else {
//			response.sendRedirect("https://mobile.paypal.com/wc?t="+resultValues.get("TOKEN"));	
//		}
//		return mapping.findForward("");
//	}
}
