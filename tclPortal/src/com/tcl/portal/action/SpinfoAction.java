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

import com.tcl.portal.domain.City;
import com.tcl.portal.domain.Spinfo;
import com.tcl.portal.form.CityForm;
import com.tcl.portal.form.SpinfoForm;
import com.tcl.portal.service.SpinfoService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;
/**
 * sp基本信息
 * @author kun.shen
 *
 */
public class SpinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(SpinfoAction.class);
	
	private SpinfoService spinfoService;
	
	public void setSpinfoService(SpinfoService spinfoService) {
		this.spinfoService = spinfoService;
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
	
		pager.setEntryCount(spinfoService.findCount(map));
		List<Spinfo> list = spinfoService.findList(map);
		
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
		
		SpinfoForm spinfoForm = (SpinfoForm)form;
		Spinfo spinfo = new Spinfo();
		BeanUtils.copyProperties(spinfo,spinfoForm);
		spinfoService.save(spinfo);
		logger.info("spinfo save");
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		SpinfoForm spinfoForm = (SpinfoForm)form;
		Spinfo spinfo = new Spinfo();
		BeanUtils.copyProperties(spinfo,spinfoForm);
		spinfoService.update(spinfo);
		logger.info("spinfo update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Spinfo spinfo = spinfoService.querySpinfo(Integer.parseInt(id));
		SpinfoForm spinfoForm = new SpinfoForm();
		BeanUtils.copyProperties(spinfoForm,spinfo);
		request.setAttribute("obj",spinfoForm );
		return mapping.findForward("edit");
	}
}
