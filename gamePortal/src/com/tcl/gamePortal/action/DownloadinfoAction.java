package com.tcl.gamePortal.action;

import java.net.URLDecoder;
import java.net.URLEncoder;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.gamePortal.domain.Customer;
import com.tcl.gamePortal.domain.Downloadinfo;
import com.tcl.gamePortal.domain.Gameinfo;
import com.tcl.gamePortal.domain.Gameresouce;
import com.tcl.gamePortal.service.DownloadinfoService;
import com.tcl.gamePortal.service.GameinfoService;
import com.tcl.gamePortal.service.GameresouceService;
import com.tcl.gamePortal.util.Constants;
import com.tcl.gamePortal.util.Util;


public class DownloadinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(DownloadinfoAction.class);
	
	private DownloadinfoService  downloadinfoService;
	
	private GameresouceService gameresouceService;
	
	private GameinfoService gameinfoService;
	
	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}


	public void setGameresouceService(GameresouceService gameresouceService) {
		this.gameresouceService = gameresouceService;
	}


	public void setDownloadinfoService(DownloadinfoService downloadinfoService) {
		this.downloadinfoService = downloadinfoService;
	}


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
		Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
		
		
		
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
		if(customer!=null){
			downloadinfo.setCustomerid(customer.getId());
		}
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
