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

import com.tcl.portal.domain.City;
import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.Ipinfo;
import com.tcl.portal.domain.Province;
import com.tcl.portal.domain.Telecomoperators;
import com.tcl.portal.form.IpinfoForm;
import com.tcl.portal.service.CityService;
import com.tcl.portal.service.CountryService;
import com.tcl.portal.service.IpinfoService;
import com.tcl.portal.service.ProvinceService;
import com.tcl.portal.service.TelecomoperatorsService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class IpinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(IpinfoAction.class);
	
	private IpinfoService ipinfoService;
	
	private CountryService countryService;
	
	private ProvinceService provinceService;
	
	private CityService cityService;
	
	private TelecomoperatorsService telecomoperatorsService;
	
	public void setTelecomoperatorsService(
			TelecomoperatorsService telecomoperatorsService) {
		this.telecomoperatorsService = telecomoperatorsService;
	}

	public void setCityService(CityService cityService) {
		this.cityService = cityService;
	}

	public void setCountryService(CountryService countryService) {
		this.countryService = countryService;
	}
	
	public void setProvinceService(ProvinceService provinceService) {
		this.provinceService = provinceService;
	}

	public void setIpinfoService(IpinfoService ipinfoService) {
		this.ipinfoService = ipinfoService;
	}
	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String ip = request.getParameter("ip");
		if(ip==null){
			ip = "";
		}
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("ip", ip);
		
		pager.setEntryCount(ipinfoService.findCount(map));
		pager.addParam("ip", ip);
		List<Ipinfo> list = ipinfoService.findList(map);
		
		for(Ipinfo ipinfo:list){
			if(ipinfo.getCountry()!=null){
				Country country = countryService.queryCountry(ipinfo.getCountry());
				if(country!=null){
					ipinfo.setCountryName(country.getName());
				}
			}
			if(ipinfo.getProviceid()!=null){
				Province province = provinceService.queryProvince(ipinfo.getProviceid());
				if(province!=null){
					ipinfo.setProviceName(province.getProvincename());
				}
			}
			if(ipinfo.getCity()!=null){
				City city = cityService.queryCountry(ipinfo.getCity());
				if(city!=null){
					ipinfo.setCityName(city.getCityname());
				}
			}
			if(ipinfo.getTelecomoperators()!=null){
				Telecomoperators telecomoperators = telecomoperatorsService.queryTelecomoperators(ipinfo.getTelecomoperators());
				if(telecomoperators!=null){
					ipinfo.setTelecomoperName(telecomoperators.getName());
				}

			}
			
		}
		request.setAttribute("ip", ip);
		request.setAttribute("list", list);
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
		
		IpinfoForm ipinfoForm = (IpinfoForm)form;
		Ipinfo ipinfo = new Ipinfo();
		BeanUtils.copyProperties(ipinfo,ipinfoForm);
		ipinfoService.save(ipinfo);
		logger.info("ipinfo save");
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		IpinfoForm ipinfoForm = (IpinfoForm)form;
		Ipinfo ipinfo = new Ipinfo();
		BeanUtils.copyProperties(ipinfo,ipinfoForm);
		ipinfoService.update(ipinfo);
		logger.info("ipinfo update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Ipinfo ipinfo = ipinfoService.queryIpinfo(Integer.parseInt(id));
		IpinfoForm ipinfoForm = new IpinfoForm();
		BeanUtils.copyProperties(ipinfoForm,ipinfo);
		request.setAttribute("obj",ipinfoForm );
		
		List<Country> list = countryService.findAll();
		request.setAttribute("listCountry", list);
		
		if(ipinfo.getProviceid()!=null){
			Province province = provinceService.queryProvince(ipinfo.getProviceid());
			if(province!=null){
				StringBuilder sb = new StringBuilder();
				sb.append("<option value=\"");
				sb.append(province.getId());
				sb.append("\" selected");
				sb.append(">");
				sb.append(province.getProvincename());
				sb.append("</option>");
				request.setAttribute("provinceSelect", sb.toString());
			}
		}
		
	if(ipinfo.getCity()!=null){
		City city = cityService.queryCountry(ipinfo.getCity());
		if(city!=null){
			StringBuilder sb = new StringBuilder();
			sb.append("<option value=\"");
			sb.append(city.getId());
			sb.append("\" selected");
			sb.append(">");
			sb.append(city.getCityname());
			sb.append("</option>");
			request.setAttribute("citySelect", sb.toString());
		}
	}
		
	if(ipinfo.getTelecomoperators()!=null){
		Telecomoperators telecomoperators = telecomoperatorsService.queryTelecomoperators(ipinfo.getTelecomoperators());
		if(telecomoperators!=null){
			StringBuilder sb = new StringBuilder();
			sb.append("<option value=\"");
			sb.append(telecomoperators.getId());
			sb.append("\" selected");
			sb.append(">");
			sb.append(telecomoperators.getName());
			sb.append("</option>");
			request.setAttribute("telecomoperatorsSelect", sb.toString());
		}
	}
		
		return mapping.findForward("edit");
	}
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
	    int flag = ipinfoService.delete(Integer.parseInt(id));
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("ipinfo delete");
			out.write("1");
		}else{
			logger.info("ipinfo delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
	//检查ip是否存在
	
	public ActionForward checkDual(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String ip = request.getParameter("ip");
	    int num = ipinfoService.checkDual(ip);
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(num==0){
			logger.info("new Ip");
			out.write("0");
		}else{
			logger.info("ip has exist");
			out.write("1");
		}
		out.flush();
		return null;
	}
	
	//批量导入
	public ActionForward batchAdd(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		//从下载信息中导入ip
		ipinfoService.batchAddFromDownload();
		//从访问信息中导入ip
		ipinfoService.batchAddFormVisite();
		return mapping.findForward("save");
	}
}
