package com.tcl.portal.action;

import java.io.PrintWriter;
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

import com.tcl.portal.domain.Types;
import com.tcl.portal.form.TypesForm;
import com.tcl.portal.service.TypesService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class TypesAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(TypesAction.class);
	
	private TypesService typesService;

	public void setTypesService(TypesService typesService) {
		this.typesService = typesService;
	}
	
	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		
		pager.setEntryCount(typesService.findCount(map));
	
		List<Types> list = typesService.findList(map);
	
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	//增加页面以及初始化数据
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		TypesForm typesForm = (TypesForm)form;
		Types types = new Types();
		BeanUtils.copyProperties(types,typesForm);
		typesService.save(types);
		logger.info("types save");
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		TypesForm typesForm = (TypesForm)form;
		Types types = new Types();
		BeanUtils.copyProperties(types,typesForm);
		typesService.update(types);
		logger.info("types update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Types types = typesService.queryTypes(Integer.parseInt(id));
		TypesForm typesForm = new TypesForm();
		BeanUtils.copyProperties(typesForm,types);
		request.setAttribute("obj",typesForm );
		return mapping.findForward("edit");
	}
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
	    int flag = typesService.delete(Integer.parseInt(id));
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("type delete");
			out.write("1");
		}else{
			logger.info("type delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
}
