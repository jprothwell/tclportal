package com.tcl.portal.action;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URLDecoder;
import java.net.URLEncoder;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.portal.domain.ExcelObject;
import com.tcl.portal.domain.Gameinfo;
import com.tcl.portal.domain.Mobileinfo;
import com.tcl.portal.domain.Visiteinfo;
import com.tcl.portal.service.GameinfoService;
import com.tcl.portal.service.MobileinfoService;
import com.tcl.portal.service.SpinfoService;
import com.tcl.portal.service.VisiteinfoService;
import com.tcl.portal.util.DateUtil;
import com.tcl.portal.util.GenerateExcel;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;


public class VisiteinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(VisiteinfoAction.class);
	
	private VisiteinfoService  visiteinfoService;
	
	private MobileinfoService mobileinfoService;
	
	private GameinfoService gameinfoService;
	
	private SpinfoService spinfoService;
	
	public void setSpinfoService(SpinfoService spinfoService) {
		this.spinfoService = spinfoService;
	}

	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}

	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}

	public void setVisiteinfoService(VisiteinfoService visiteinfoService) {
		this.visiteinfoService = visiteinfoService;
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
		pager.setEntryCount(visiteinfoService.findCount(map));
		pager.addParam("startDate", startDate);
		pager.addParam("endDate", endDate);
		List<Visiteinfo> list = visiteinfoService.findList(map);
		for(Visiteinfo visiteinfo:list){
			Mobileinfo mobileinfo = mobileinfoService.queryMobileinfo(visiteinfo.getDid());
			if(mobileinfo!=null){
				visiteinfo.setDidName(mobileinfo.getPhonetype());
			}
			Gameinfo gameinfo = gameinfoService.queryGameinfo(visiteinfo.getGameid());
			if(gameinfo!=null){
				visiteinfo.setGameName(gameinfo.getGamename());
			}
		}
		request.setAttribute("startDate", startDate);
		request.setAttribute("endDate", endDate);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	
	//导出excel
	public ActionForward getExcel(ActionMapping mapping, ActionForm form,
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
		Map map = new HashMap();
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
		List<Visiteinfo> list = visiteinfoService.findListForExcel(map);
//		List<ExcelObject> excelList = new ArrayList<ExcelObject>();
		Map<String,ExcelObject> maps = new LinkedHashMap<String,ExcelObject>();
		for(Visiteinfo visiteinfo:list){
			
			//以访问的did和游戏id作为唯一值，来统计访问的个数
			Mobileinfo mobileinfo = mobileinfoService.queryMobileinfo(visiteinfo.getDid());
			if(mobileinfo!=null){
				visiteinfo.setDidName(mobileinfo.getPhonetype());
			}
			Gameinfo gameinfo = gameinfoService.queryGameinfo(visiteinfo.getGameid());
			if(gameinfo!=null){
				visiteinfo.setGameName(gameinfo.getGamename());
				visiteinfo.setSpName(spinfoService.querySpinfo(gameinfo.getSpid()).getName());
			}
		}
		String filepath = "d://test"+".xls";
		//产生excel文件
		GenerateExcel.excel(list,filepath);
		String fileName = startDate+"to"+endDate+".xls";
		fileName = URLDecoder.decode(fileName,"UTF-8");
		fileName = URLEncoder.encode(fileName, "UTF-8");
		response.addHeader("Content-Disposition", "attachment; filename=" + fileName);
		
		//unix path  cbsysctl.getCbsysparvalue()
		//获取文件输入流和输出流
		
		InputStream is = new BufferedInputStream(new FileInputStream(filepath));
		OutputStream os = new BufferedOutputStream(response.getOutputStream());
		int bufferSize = 1024*8;
		byte[] buffer = new byte[bufferSize];
		int len = 0;
		while((len = is.read(buffer, 0, bufferSize))!=-1){
			os.write(buffer, 0, len);
		}
		is.close();
		os.flush();
		os.close();
		File file = new File(filepath);
		file.delete();
		
//		request.setAttribute("startDate", startDate);
//		request.setAttribute("endDate", endDate);
//		request.setAttribute("excelList", list);
		return null;
		
	}
}
