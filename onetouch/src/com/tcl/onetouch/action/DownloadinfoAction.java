package com.tcl.onetouch.action;

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
import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.onetouch.domain.Downloadinfo;
import com.tcl.onetouch.domain.ExcelObject;
import com.tcl.onetouch.domain.Gameinfo;
import com.tcl.onetouch.domain.Gameresouce;
import com.tcl.onetouch.domain.Mobileinfo;
import com.tcl.onetouch.service.DownloadinfoService;
import com.tcl.onetouch.service.GameinfoService;
import com.tcl.onetouch.service.GameresouceService;
import com.tcl.onetouch.service.MobileinfoService;
import com.tcl.onetouch.service.SpinfoService;
import com.tcl.onetouch.util.DateUtil;
import com.tcl.onetouch.util.GenerateExcel;
import com.tcl.onetouch.util.Pager;
import com.tcl.onetouch.util.PagerBuilder;
import com.tcl.onetouch.util.Util;

public class DownloadinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(DownloadinfoAction.class);
	
	private DownloadinfoService downloadinfoService;
	
	private MobileinfoService mobileinfoService;
	
	private GameinfoService gameinfoService;
	
	private SpinfoService spinfoService;
	
	private GameresouceService gameresouceService;
	
	public void setSpinfoService(SpinfoService spinfoService) {
		this.spinfoService = spinfoService;
	}
	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}
	
	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}


	public void setDownloadinfoService(DownloadinfoService downloadinfoService) {
		this.downloadinfoService = downloadinfoService;
	}
	
	public void setGameresouceService(GameresouceService gameresouceService) {
		this.gameresouceService = gameresouceService;
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
		pager.setEntryCount(downloadinfoService.findCount(map));
		pager.addParam("startDate", startDate);
		pager.addParam("endDate", endDate);
		List<Downloadinfo> list = downloadinfoService.findList(map);
		for(Downloadinfo downloadinfo:list){
			Mobileinfo mobileinfo = mobileinfoService.queryMobileinfo(downloadinfo.getDid());
			if(mobileinfo!=null){
				downloadinfo.setDidName(mobileinfo.getPhonetype());
			}
			Gameinfo gameinfo = gameinfoService.queryGameinfo(downloadinfo.getGameid());
			if(gameinfo!=null){
				downloadinfo.setGameName(gameinfo.getGamename());
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
		List<Downloadinfo> list = downloadinfoService.findListForExcel(map);
//		List<ExcelObject> excelList = new ArrayList<ExcelObject>();
		Map<String,ExcelObject> maps = new LinkedHashMap<String,ExcelObject>();
		for(Downloadinfo downloadinfo:list){
			
			//以访问的did和游戏id作为唯一值，来统计下载的个数
			Mobileinfo mobileinfo = mobileinfoService.queryMobileinfo(downloadinfo.getDid());
			if(mobileinfo!=null){
				downloadinfo.setDidName(mobileinfo.getPhonetype());
			}
			Gameinfo gameinfo = gameinfoService.queryGameinfo(downloadinfo.getGameid());
			if(gameinfo!=null){
				downloadinfo.setGameName(gameinfo.getGamename());
				downloadinfo.setSpName(spinfoService.querySpinfo(gameinfo.getSpid()).getName());
			}
		}
		HttpSession session = request.getSession();
		String filepath = session.getServletContext().getRealPath("downloadinfo")+startDate+"to"+endDate+".xls";
		//产生excel文件
		GenerateExcel.excelDownload(list,filepath);
		String fileName = "d"+startDate+"to"+endDate+".xls";
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
	//wap页面调用
	public ActionForward download(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 String pagename="javaUrl";
		 String did = request.getParameter("did");
		 int pageid = Integer.parseInt(request.getParameter("pageid"));
		 int proviceid = Integer.parseInt(request.getParameter("proviceid"));
		String gameId = request.getParameter("gameId");
		String location = request.getParameter("location");
		int locationid=0;
		if(location!=null&&!"".equals(location)&&!"null".equals(location))locationid=Integer.parseInt(location);
		HttpSession session = request.getSession();
//		Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
		
		
		
		//获取游戏资源信息，取得下载信息
		Map map = new HashMap();
		map.put("gameId", gameId);
		map.put("proviceid", proviceid);
		map.put("did", did);
		Gameresouce gameresouce = gameresouceService.queryGameresouce(map);
		Gameinfo gameinfo = gameinfoService.queryGameinfo(gameresouce.getGameid());
		///////////////////下载统计
		//保存下载信息
		Downloadinfo downloadinfo = new Downloadinfo();
//		if(customer!=null){
//			downloadinfo.setCustomerid(customer.getId());
//		}
		downloadinfo.setDid(did);
		downloadinfo.setDtime(new Date());
		downloadinfo.setGameid(Integer.parseInt(gameId));
		String ip=Util.getIp(request);
		String phnum =Util.getPhone(request);
		downloadinfo.setIp(ip);
		downloadinfo.setLocation(locationid);
		downloadinfo.setTitleid(gameinfo.getKindid());
		downloadinfo.setTelephone(phnum);
		downloadinfoService.save(downloadinfo);
		//////////////////下载统计结束
		//下载
		//获取文件路径和文件名
		String filePath = "game/"+gameId+"/"+did+"/"+gameresouce.getProvinceid()+"/";
		//下载文件
		String fileName = gameresouce.getJarfile();
		String fileName1 = gameresouce.getJadfile();
		//if(fileName1!=null&&!"".equals(fileName1)&&!"null".equals(fileName1))fileName=fileName1;
		////////////////////////////////
		fileName = URLDecoder.decode(fileName,"UTF-8");
		fileName = URLEncoder.encode(fileName, "UTF-8");
		fileName = filePath+fileName;
//		response.setContentType("application/txt"); 
//		response.addHeader("Content-Disposition", "attachment; filename=" + fileName);
//		//获取文件输入流和输出流
//		InputStream is = new BufferedInputStream(new FileInputStream(filePath+"\\"+fileName));
//		OutputStream os = new BufferedOutputStream(response.getOutputStream());
//		int bufferSize = 1024*8;
//		byte[] buffer = new byte[bufferSize];
//		int len = 0;
//		while((len = is.read(buffer, 0, bufferSize))!=-1){
//			os.write(buffer, 0, len);
//		}
//		is.close();
//		os.close();	
		//System.out.println("javaPath="+fileName);
		request.setAttribute("javaPath",fileName);
		return mapping.findForward(pagename);
	}
}
