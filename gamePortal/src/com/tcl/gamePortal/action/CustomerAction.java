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
		HttpSession   session=request.getSession(false); 
		int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
		String pagename="listreg2";
		switch(pageid){
		  case 2:pagename="listreg2";
		       break;
		  case 3:pagename="listreg3";
		       break;
		  default:pagename="listreg1";
		      break;		  
		 }
		return mapping.findForward(pagename);
	}
	//手机用户选择登陆页面
	public ActionForward selectLogin(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		HttpSession   session=request.getSession(false); 
		int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
		String pagename="listlog2";
		switch(pageid){
		  case 2:pagename="listlog2";
		       break;
		  case 3:pagename="listlog3";
		       break;
		  default:pagename="listlog1";
		      break;		  
		 }
		return mapping.findForward(pagename);
	}
	//手机用户注册
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		HttpSession   session=request.getSession(false); 
		int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
		String password1=request.getParameter("password1");
		String password=request.getParameter("password");
		String pagename="listreg2";
		String result="";
		switch(pageid){
		  case 2:pagename="listreg2";
		       break;
		  case 3:pagename="listre3";
		       break;
		  default:pagename="listreg1";
		      break;		  
		 }
		CustomerForm customerForm = (CustomerForm)form;
		Customer customer = new Customer();
		Customer customer1 = customerService.queryCustomerByName(customer.getUsername());
		BeanUtils.copyProperties(customer,customerForm);
		//判断用户名不能为空		
		if(customer.getUsername()==null||"".equals(customer.getUsername())){
		request.setAttribute("result","用户名不能为空，请重输");	
		return mapping.findForward(pagename);	
		}
		//判断用户名是否存在
		System.out.println("customer1="+customer1);
		System.out.println("customer2="+customer.getUsername());
		if(customer1!=null){
			request.setAttribute("result","用户名已经存在!，请重输");	
			return mapping.findForward(pagename);	
		}
		//判断两者密码是否相同
		if(!password1.equals(password)|| customer.getPassword()==null||"".equals(customer.getPassword())){
		request.setAttribute("result","两者密码不等或者密码为空，请重输");	
		return mapping.findForward(pagename);	
		}
		///end
		String passwordToMd5 = MD5.getMd5Value(customer.getPassword());
		customer.setPassword(passwordToMd5);
		customerService.save(customer);
		logger.info("customer save");
		return mapping.findForward("save");
	}
	//用户修改信息
	public ActionForward eidt(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Customer customer = customerService.queryCustomer(Integer.parseInt(id));
		CustomerForm customerForm = new CustomerForm();
		BeanUtils.copyProperties(customerForm,customer);
		request.setAttribute("obj", customerForm);
		logger.info("customer eidt");
		return mapping.findForward("edit");
	}
	//update信息
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		CustomerForm customerForm = (CustomerForm)form;
		Customer customer = new Customer();
		BeanUtils.copyProperties(customer,customerForm);
		String passwordToMd5 = MD5.getMd5Value(customer.getPassword());
		customer.setPassword(passwordToMd5);
		customerService.update(customer);
		logger.info("customer update");
		return mapping.findForward("update");
	}
	//手机用户登陆
	public ActionForward login(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String userName = request.getParameter("user");
		String password = request.getParameter("pwd");
		Customer customer = customerService.queryCustomerByName(userName);
		if(customer==null){
			request.setAttribute("errorMessage", new String("该用户不存在!"));
			return mapping.findForward("fail");
		}else{
				//有效用户
				if(customer.getPassword().equals(MD5.getMd5Value(password))){
					//密码正确
					HttpSession session = request.getSession();//用户信息放到session里面
					logger.info("customer:"+userName+"(longin success)");
					session.setAttribute(Constants.SESSION_CUSTOMER,customer);
					
					return mapping.findForward("login");
				}else{
					logger.info("customer:"+userName+"(longin fail,password error)");
					request.setAttribute("errorMessage", new String("输入密码不正确!"));
					return mapping.findForward("fail");
				}
			}
	}
	//修改密码
	
	//积分修改,注：该出不需要另外调用，将代码嵌入其他action之中
	public ActionForward updatePoint(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String point = request.getParameter("point");
		HttpSession session = request.getSession();
		Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
		
		int newPoint = customer.getPoint()+Integer.parseInt(point);
		customer.setPoint(newPoint);
		customerService.update(customer);
		logger.info("customer point update");
		return mapping.findForward("update");
	}
}
