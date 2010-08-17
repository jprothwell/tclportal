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

import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.Province;
import com.tcl.portal.domain.Spinfo;
import com.tcl.portal.domain.Telecomoperators;
import com.tcl.portal.form.ProvinceForm;
import com.tcl.portal.service.CountryService;
import com.tcl.portal.service.ProvinceService;
import com.tcl.portal.service.TelecomoperatorsService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;
/**
 * 省份信息
 * @author kun.shen
 *
 */
public class ProvinceAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(ProvinceAction.class);
	
	private ProvinceService provinceService;
	
	private CountryService countryService;
	
	private TelecomoperatorsService telecomoperatorsService;

	public void setTelecomoperatorsService(
			TelecomoperatorsService telecomoperatorsService) {
		this.telecomoperatorsService = telecomoperatorsService;
	}

	public void setProvinceService(ProvinceService provinceService) {
		this.provinceService = provinceService;
	}
	
	//列表，查找
	public void setCountryService(CountryService countryService) {
		this.countryService = countryService;
	}

	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String provincename = request.getParameter("provincename");
		String countryid = request.getParameter("countryid");
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("provincename", provincename);
		map.put("countryid", countryid);
		pager.setEntryCount(provinceService.findCount(map));
		pager.addParam("provincename", provincename);
		pager.addParam("countryid", countryid);
		List<Province> list = provinceService.findList(map);
		for(Province province:list){
			Country country = countryService.queryCountry(province.getCountryid());
			StringBuilder countryName = new StringBuilder();
			if(country!=null){
				countryName.append(country.getName());
				countryName.append("(");
				countryName.append(country.getShorterform());
				countryName.append(")");
			}
			province.setCountryName(countryName.toString());
		}
		request.setAttribute("list", list);
		List<Country> listCountry = countryService.findAll();
		request.setAttribute("listCountry", listCountry);
		request.setAttribute("countryidSelect", countryid);
		return mapping.findForward("list");
	}
	//增加页面以及初始化数据
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		List<Country> list = countryService.findAll();
		request.setAttribute("listCountry", list);
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		ProvinceForm provinceForm = (ProvinceForm)form;
		Province province = new Province();
		BeanUtils.copyProperties(province,provinceForm);
		provinceService.save(province);
		logger.info("province save");
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		ProvinceForm provinceForm = (ProvinceForm)form;
		Province province = new Province();
		BeanUtils.copyProperties(province,provinceForm);
		provinceService.update(province);
		logger.info("province update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Province province = provinceService.queryProvince(Integer.parseInt(id));
		ProvinceForm provinceForm = new ProvinceForm();
		BeanUtils.copyProperties(provinceForm,province);
		List<Country> list = countryService.findAll();
		request.setAttribute("listCountry", list);
		request.setAttribute("obj",provinceForm );
		return mapping.findForward("edit");
	}
	public ActionForward findProvinceByCountry(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String countryid = request.getParameter("countryid");
		List<Province> list = provinceService.findAll();
		StringBuilder sb = new StringBuilder("<option value=>选择省州</option>");
		for(Province province:list){
			if(String.valueOf(province.getCountryid()).equals(countryid)){
				sb.append("<option value=");
				sb.append(province.getId());
				sb.append(">");
				sb.append(province.getProvincename());
				sb.append("</option>");
			}
		}
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		out.write(sb.toString());
		out.flush();
		return null;
	}
	public ActionForward findProvAndTelecomByCountry(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String countryid = request.getParameter("countryid");
		List<Province> list = provinceService.findAll();
		StringBuilder sb = new StringBuilder("<option value=>选择省州</option>");
		for(Province province:list){
			if(String.valueOf(province.getCountryid()).equals(countryid)){
				sb.append("<option value=");
				sb.append(province.getId());
				sb.append(">");
				sb.append(province.getProvincename());
				sb.append("</option>");
			}
		}
		sb.append(";");
		List<Telecomoperators> listTelecomoperators = telecomoperatorsService.findAll();
		sb.append("<option value=>选择运营商</option>");
		for(Telecomoperators telecomo:listTelecomoperators){
			if(String.valueOf(telecomo.getCountryid()).equals(countryid)){
				sb.append("<option value=");
				sb.append(telecomo.getId());
				sb.append(">");
				sb.append(telecomo.getName());
				sb.append("</option>");
			}
		}
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		out.write(sb.toString());
		out.flush();
		return null;
	}
	
}
