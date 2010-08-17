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

import com.tcl.portal.domain.Resource;
import com.tcl.portal.form.ResourceForm;
import com.tcl.portal.service.ResourceService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;


public class ResourceAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(ResourceAction.class);
	
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
	
		pager.setEntryCount(resourceService.findCount(map));
	
		List<Resource> list = resourceService.findList(map);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		return mapping.findForward("add");
	}
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		ResourceForm resourceForm = (ResourceForm)form;
		Resource resource = new Resource();
		BeanUtils.copyProperties(resource,resourceForm);
		resourceService.save(resource);
		logger.info("resource save");
		return mapping.findForward("save");
	}
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		ResourceForm resourceForm = (ResourceForm)form;
		Resource resource = new Resource();
		BeanUtils.copyProperties(resource,resourceForm);
		resourceService.update(resource);
		logger.info("resource update");
		return mapping.findForward("update");
	}
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Resource resource = resourceService.queryResource(id);
		ResourceForm resourceForm = new ResourceForm();
		BeanUtils.copyProperties(resourceForm,resource);
		request.setAttribute("obj",resourceForm );
		return mapping.findForward("edit");
	}
	
	public ActionForward view(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Resource resource = resourceService.queryResource(id);
		ResourceForm resourceForm = new ResourceForm();
		BeanUtils.copyProperties(resourceForm,resource);
		request.setAttribute("obj",resourceForm );
		return mapping.findForward("view");
	}
}
