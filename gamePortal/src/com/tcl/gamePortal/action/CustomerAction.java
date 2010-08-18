package com.tcl.gamePortal.action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.gamePortal.domain.Customer;
import com.tcl.gamePortal.form.CustomerForm;
import com.tcl.gamePortal.service.CustomerService;
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
}
