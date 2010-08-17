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

import com.tcl.portal.domain.Role;
import com.tcl.portal.form.RoleForm;
import com.tcl.portal.service.ResourceService;
import com.tcl.portal.service.RoleService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;



public class RoleAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(RoleAction.class);
	
	private RoleService  roleService;
	
	public void setRoleService(RoleService roleService) {
		this.roleService = roleService;
	}
	
	private ResourceService resourceService;
	
	public void setResourceService(ResourceService resourceService) {
		this.resourceService = resourceService;
	}
	
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		
		pager.setEntryCount(roleService.findCount(map));
		List list = roleService.findList(map);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		List listResource = resourceService.findAll();
		request.setAttribute("listResource",listResource);
		return mapping.findForward("add");
	}
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		RoleForm roleForm = (RoleForm)form;
		Role role = new Role();
		BeanUtils.copyProperties(role,roleForm);
		roleService.save(role);
		logger.info("Role save");
		return mapping.findForward("save");
	}
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		RoleForm roleForm = (RoleForm)form;
		Role role = new Role();
		BeanUtils.copyProperties(role,roleForm);
		roleService.update(role);
		logger.info("Role update");
		return mapping.findForward("update");
	}
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Role role = roleService.queryRole(id);
		RoleForm roleForm = new RoleForm();
		BeanUtils.copyProperties(roleForm,role);
		request.setAttribute("obj",roleForm);
		
		List listResource = resourceService.findAll();
		request.setAttribute("listResource",listResource);
		return mapping.findForward("edit");
	}
}
