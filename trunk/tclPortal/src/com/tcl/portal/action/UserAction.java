package com.tcl.portal.action;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.portal.domain.User;
import com.tcl.portal.form.UserForm;
import com.tcl.portal.service.RoleService;
import com.tcl.portal.service.UserService;
import com.tcl.portal.util.MD5;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;



public class UserAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(UserAction.class);
	
	private UserService userService;
	
	private RoleService  roleService;
	
	public void setRoleService(RoleService roleService) {
		this.roleService = roleService;
	}

	public void setUserService(UserService userService) {
		this.userService = userService;
	}


	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String name = request.getParameter("name");
		String roleId = request.getParameter("roleId");
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("name", name);
		map.put("roleId", roleId);
		pager.setEntryCount(userService.findCount(map));
		pager.addParam("name", name);
		pager.addParam("roleId", roleId);
		List<User> list = userService.findList(map);
		for(User user:list){
			user.setRoleName(roleService.queryRoleNameById(user.getRoleId()));
		}
		request.setAttribute("list", list);
		//获取角色
		List listRole = roleService.findRoleAll();
		request.setAttribute("listRole", listRole);
		return mapping.findForward("list");
	}
	
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		List listRole = roleService.findRoleAll();
		request.setAttribute("listRole", listRole);
		return mapping.findForward("add");
	}
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		UserForm userForm = (UserForm)form;
		User user = new User();
		BeanUtils.copyProperties(user,userForm);
		String password = MD5.getMd5Value(user.getPassword());
		user.setPassword(password);
		userService.save(user);
		logger.info("user save");
		return mapping.findForward("save");
	}
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		UserForm userForm = (UserForm)form;
		String id = request.getParameter("id");
		User user = userService.queryUser(id);
		user.setName(userForm.getName());
		user.setRoleId(userForm.getRoleId());
		user.setDisabled(userForm.getDisabled());
		userService.update(user);
		logger.info("user update");
		return mapping.findForward("update");
	}
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		User user = userService.queryUser(id);
		UserForm userForm = new UserForm();
		BeanUtils.copyProperties(userForm,user);
		request.setAttribute("obj",userForm );
		List listRole = roleService.findRoleAll();
		request.setAttribute("listRole", listRole);
		return mapping.findForward("edit");
	}
	
	public ActionForward view(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		User user = userService.queryUser(id);
		UserForm userForm = new UserForm();
		BeanUtils.copyProperties(userForm,user);
		request.setAttribute("obj",userForm );
		return mapping.findForward("view");
	}
	public ActionForward editPassword(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		User user = userService.queryUser(id);
		UserForm userForm = new UserForm();
		BeanUtils.copyProperties(userForm,user);
		request.setAttribute("obj",userForm );
		List listRole = roleService.findRoleAll();
		request.setAttribute("listRole", listRole);
		return mapping.findForward("editPassword");
	}

	
}
