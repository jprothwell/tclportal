package com.tcl.portal.action;

import java.io.File;
import java.io.InputStream;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import net.sf.jasperreports.engine.JRExporterParameter;
import net.sf.jasperreports.engine.JasperExportManager;
import net.sf.jasperreports.engine.JasperFillManager;
import net.sf.jasperreports.engine.JasperPrint;
import net.sf.jasperreports.engine.JasperRunManager;
import net.sf.jasperreports.engine.data.JRBeanCollectionDataSource;
import net.sf.jasperreports.engine.export.JRRtfExporter;
import net.sf.jasperreports.engine.export.JRXlsExporter;
import net.sf.jasperreports.engine.export.JRXlsExporterParameter;
import net.sf.jasperreports.engine.util.JRLoader;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.jasperreports.JasperReportsMultiFormatView;

import com.tcl.portal.domain.Changelog;
import com.tcl.portal.domain.Gameinfo;
import com.tcl.portal.domain.Gameresouce;
import com.tcl.portal.domain.Province;
import com.tcl.portal.service.ChangelogService;
import com.tcl.portal.service.GameinfoService;
import com.tcl.portal.service.GameresouceService;
import com.tcl.portal.service.ProvinceService;
import com.tcl.portal.util.DateUtil;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class ChangelogAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(ChangelogAction.class);
	
	private ChangelogService changelogService;
	
	private GameresouceService gameresouceService;
	
	private GameinfoService gameinfoService;
	
	private ProvinceService provinceService;
	
	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}


	public void setProvinceService(ProvinceService provinceService) {
		this.provinceService = provinceService;
	}


	public void setGameresouceService(GameresouceService gameresouceService) {
		this.gameresouceService = gameresouceService;
	}


	public void setChangelogService(ChangelogService changelogService) {
		this.changelogService = changelogService;
	}


	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String startDate=request.getParameter("startDate");
		String endDate=request.getParameter("endDate");
		if (("").equals(startDate)||startDate==null)
		{
			startDate = DateUtil.getTheMonthFirstDay();
		}
		if (("").equals(endDate)||endDate==null)
		{
			endDate = DateUtil.getCurrentDate();
		}
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		
		Date startD = null;
		Date endD = null;
		try {
			startD =  new SimpleDateFormat("yyyy-MM-dd").parse(startDate);
			endD = DateUtil.getTomorrow(endDate);
			
		} catch (ParseException e) {
			e.printStackTrace();
		}
		if(!"".equals(startDate)&&startDate!=null){
			map.put("startDate",startD);
		}
		if(!"".equals(endDate)&&endDate!=null){
			map.put("endDate",endD);
		}
		pager.setEntryCount(changelogService.findCount(map));
		pager.addParam("startDate", startDate);
		pager.addParam("endDate", endDate);
		List<Changelog> list = changelogService.findList(map);
		for(Changelog changelog:list){
			Gameresouce gameresouce = gameresouceService.queryGameresouce(changelog.getGameresourceid());
			Gameinfo gameinfo = null;
			Province province = null;
			if(gameresouce!=null){
				gameinfo = gameinfoService.queryGameinfo(gameresouce.getGameid());
				province = provinceService.queryProvince(gameresouce.getProvinceid());
				changelog.setDid(gameresouce.getDid());
			}
			if(gameinfo!=null){
				changelog.setGameName(gameinfo.getGamename());
			}
			if(province!=null){
				changelog.setProvinceName(province.getProvincename());
			}
		}
		request.setAttribute("startDate", startDate);
		request.setAttribute("endDate", endDate);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	
	//列表，查找
	public ActionForward report(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		response.setCharacterEncoding("UTF-8");
		HttpSession session = request.getSession();
//		String path = session.getServletContext().getRealPath("/report/report.jrxml");
//		JasperCompileManager.compileReportToFile(path);
		String jasper = session.getServletContext().getRealPath("/report/report.jasper");
		
		//饼状
//		String piePath = session.getServletContext().getRealPath("/report/pie.jrxml");
//		JasperCompileManager.compileReportToFile(piePath);
		String pie = session.getServletContext().getRealPath("/report/pie.jasper");
		
		List<Changelog> list = changelogService.findList();
		for(Changelog changelog:list){
			Gameresouce gameresouce = gameresouceService.queryGameresouce(changelog.getGameresourceid());
			Gameinfo gameinfo = null;
			Province province = null;
			if(gameresouce!=null){
				gameinfo = gameinfoService.queryGameinfo(gameresouce.getGameid());
				province = provinceService.queryProvince(gameresouce.getProvinceid());
				changelog.setDid(gameresouce.getDid());
			}
			if(gameinfo!=null){
				changelog.setGameName("测试");
			}
			if(province!=null){
				changelog.setProvinceName(province.getProvincename());
			}
		}
		JRBeanCollectionDataSource jrDataSource = new JRBeanCollectionDataSource(list);
		String jasperPrintPath = JasperFillManager.fillReportToFile(jasper, new HashMap(), jrDataSource);//.jrprint文件
		//生成pdf
		JasperExportManager.exportReportToPdfFile(jasperPrintPath);
		//生成pie pdf
		//String pieJasperPrint = JasperFillManager.fillReportToFile(pie, new HashMap(), jrDataSource);//.jrprint文件
		//JasperExportManager.exportReportToPdfFile(pieJasperPrint);
		//生成html
		JasperExportManager.exportReportToHtmlFile(jasperPrintPath);
		
		File sourceFile = new File(jasperPrintPath);
		JasperPrint jasperPrint = (JasperPrint)JRLoader.loadObject(sourceFile);
		//生成word
		File destFile = new File(sourceFile.getParent(), jasperPrint.getName() + ".rtf");
		JRRtfExporter exporter = new JRRtfExporter();
		exporter.setParameter(JRExporterParameter.JASPER_PRINT, jasperPrint);
		exporter.setParameter(JRExporterParameter.OUTPUT_FILE_NAME, destFile.toString());
		exporter.exportReport();
		//生成excel
		File excelFile = new File(sourceFile.getParent(), jasperPrint.getName() + ".xls");
		JRXlsExporter exporterXls = new JRXlsExporter();
		exporterXls.setParameter(JRExporterParameter.JASPER_PRINT, jasperPrint);
		exporterXls.setParameter(JRExporterParameter.OUTPUT_FILE_NAME, excelFile.toString());
		exporterXls.setParameter(JRXlsExporterParameter.IS_ONE_PAGE_PER_SHEET, Boolean.FALSE);
		exporterXls.exportReport();

		//输出在页面上
		ServletOutputStream  servletOutputStream = response.getOutputStream();
		InputStream reportStream = session.getServletContext().getResourceAsStream("/report/report.jasper");
		JasperRunManager.runReportToPdfStream(reportStream,servletOutputStream,new HashMap(),jrDataSource);
		response.setContentType("application/pdf");
		response.setCharacterEncoding("utf-8");
		servletOutputStream.flush();
		servletOutputStream.close();
		
		//html
//		JRHtmlExporter htmlExporter = new JRHtmlExporter();
//		PrintWriter printWriter = response.getWriter();
//		response.setContentType("text/html");
//		request.getSession().setAttribute(ImageServlet.DEFAULT_JASPER_PRINT_SESSION_ATTRIBUTE, jasperPrint);
//		htmlExporter.setParameter(JRExporterParameter.JASPER_PRINT, jasperPrint);
//		htmlExporter.setParameter(JRExporterParameter.OUTPUT_WRITER,printWriter);
//		htmlExporter.setParameter(JRHtmlExporterParameter.IMAGES_URI, "image?image=");
//		htmlExporter.exportReport();
		
		//pie pdf
//		Map map = new HashMap();
//		map.put("myData", jrDataSource);
//		map.put("format", "pdf");
//		ModelAndView model = new ModelAndView("myData",map);
//		JasperReportsMultiFormatView formatView = new JasperReportsMultiFormatView();
//		formatView.renderReport(jasperPrint,map,response);
		return null;
	}
}
