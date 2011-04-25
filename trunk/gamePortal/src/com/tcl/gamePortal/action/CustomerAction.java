package com.tcl.gamePortal.action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.gamePortal.domain.Customer;
import com.tcl.gamePortal.form.CustomerForm;
import com.tcl.gamePortal.service.CustomerService;
import com.tcl.gamePortal.util.Constants;
import com.tcl.gamePortal.util.MD5;

/**
 * 手机用户
 * @author kun.shen
 *
 */
public class CustomerAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(CustomerAction.class);
	
	private CustomerService  customerService;
	
	public void setCustomerService(CustomerService customerService) {
		this.customerService = customerService;
	}

	//手机用户选择注册页面
	public ActionForward selectReg(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 String did = request.getParameter("did");
		 int pageid = Integer.parseInt(request.getParameter("pageid"));
		 int proviceid = Integer.parseInt(request.getParameter("proviceid"));
		String pagename="listreg2";
		switch(pageid){
		  case 2:pagename="listreg2";
		       break;
		  case 3:pagename="listreg3";
		       break;
		  default:pagename="listreg1";
		      break;		  
		 }
		request.setAttribute("did",did);
		request.setAttribute("pageid",pageid);
		request.setAttribute("proviceid",proviceid);
		return mapping.findForward(pagename);
	}
	//手机用户选择登陆页面
	public ActionForward selectLogin(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 String did = request.getParameter("did");
		 int pageid = Integer.parseInt(request.getParameter("pageid"));
		 int proviceid = Integer.parseInt(request.getParameter("proviceid"));
		String pagename="listlog2";
		switch(pageid){
		  case 2:pagename="listlog2";
		       break;
		  case 3:pagename="listlog3";
		       break;
		  default:pagename="listlog1";
		      break;		  
		 }
		request.setAttribute("did",did);
		request.setAttribute("pageid",pageid);
		request.setAttribute("proviceid",proviceid);
		return mapping.findForward(pagename);
	}
	//手机用户注册
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 String did = request.getParameter("did");
		 int pageid = Integer.parseInt(request.getParameter("pageid"));
		 int proviceid = Integer.parseInt(request.getParameter("proviceid"));
		String password1=request.getParameter("password1");
		String password=request.getParameter("password");	
		CustomerForm customerForm = (CustomerForm)form;
		Customer customer = new Customer();
		BeanUtils.copyProperties(customer,customerForm);
		Customer customer1 = customerService.queryCustomerByName(customer.getUsername());
		request.setAttribute("did",did);
		request.setAttribute("pageid",pageid);
		request.setAttribute("proviceid",proviceid);
		//判断用户名不能为空		
		if(customer.getUsername()==null||"".equals(customer.getUsername())){
		request.setAttribute("result","用户名不能为空，请重输");			
		return this.selectReg(mapping, form, request, response);
		}
		//判断用户名是否存在
		if(customer1!=null){
			request.setAttribute("result","用户名已经存在!，请重输");
			return this.selectReg(mapping, form, request, response);
		}
		//判断两者密码是否相同
		if(!password1.equals(password)|| customer.getPassword()==null||"".equals(customer.getPassword())){
		request.setAttribute("result","两者密码不等或者密码为空，请重输");
		return this.selectReg(mapping, form, request, response);	
		}
		///end
		HttpSession session = request.getSession();
		session.setAttribute(Constants.SESSION_CUSTOMER,customer);
		String passwordToMd5 = MD5.getMd5Value(customer.getPassword());
		customer.setPassword(passwordToMd5);
		customerService.save(customer);
		return mapping.findForward("save");
	}
	//手机用户登陆
	public ActionForward login(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String userName = request.getParameter("user");
		String password = request.getParameter("pwd");
		String did = request.getParameter("did");
		int pageid = Integer.parseInt(request.getParameter("pageid"));
		int proviceid = Integer.parseInt(request.getParameter("proviceid"));
		request.setAttribute("did",did);
		request.setAttribute("pageid",pageid);
		request.setAttribute("proviceid",proviceid);
		Customer customer = customerService.queryCustomerByName(userName);
		if(customer==null){
			request.setAttribute("result","该用户不存在!，请重输");
			return this.selectLogin(mapping, form, request, response);
		}else{
				//有效用户
				if(customer.getPassword().equals(MD5.getMd5Value(password))){
					//密码正确	
				HttpSession session = request.getSession();            				
				session.setAttribute(Constants.SESSION_CUSTOMER,customer);
					return mapping.findForward("save");
				}else{
					request.setAttribute("result","输入密码不正确!，请重输");
					return this.selectLogin(mapping, form, request, response);
				}
			}
	}
	//修改密码
}
