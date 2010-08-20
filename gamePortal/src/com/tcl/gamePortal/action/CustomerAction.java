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


	//手机用户注册
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		CustomerForm customerForm = (CustomerForm)form;
		Customer customer = new Customer();
		BeanUtils.copyProperties(customer,customerForm);
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
	//积分修改
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
