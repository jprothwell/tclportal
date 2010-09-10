package com.tcl.gamePortal.action;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
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
import com.tcl.gamePortal.domain.Gameresouce;
import com.tcl.gamePortal.service.DownloadinfoService;
import com.tcl.gamePortal.service.GameresouceService;
import com.tcl.gamePortal.util.Constants;


public class DownloadinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(DownloadinfoAction.class);
	
	private DownloadinfoService  downloadinfoService;
	
	private GameresouceService gameresouceService;
	
	public void setGameresouceService(GameresouceService gameresouceService) {
		this.gameresouceService = gameresouceService;
	}


	public void setDownloadinfoService(DownloadinfoService downloadinfoService) {
		this.downloadinfoService = downloadinfoService;
	}


	public ActionForward download(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String gameId = request.getParameter("gameId");
		HttpSession session = request.getSession();
		int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
		String did = (String) session.getAttribute(Constants.DID_VALUE);
		int proviceid =  (Integer) session.getAttribute(Constants.PROVICEID_VALUE);
		Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
		
		
		
		//获取游戏资源信息，取得下载信息
		Map map = new HashMap();
		map.put("gameId", gameId);
		map.put("proviceid", proviceid);
		map.put("did", did);
		Gameresouce gameresouce = gameresouceService.queryGameresouce(map);
		//下载
		//获取文件路径和文件名
		String filePath = "D:\\tomcat6\\webapps\\"+request.getContextPath()+ "/game"+File.separatorChar+gameId+File.separatorChar+did;
		//下载文件
		String fileName = gameresouce.getJarfile();
		fileName = URLDecoder.decode(fileName,"UTF-8");
		fileName = URLEncoder.encode(fileName, "UTF-8");
		response.setContentType("application/txt"); 
		response.addHeader("Content-Disposition", "attachment; filename=" + fileName);
		//获取文件输入流和输出流
		InputStream is = new BufferedInputStream(new FileInputStream(filePath+"\\"+fileName));
		OutputStream os = new BufferedOutputStream(response.getOutputStream());
		int bufferSize = 1024*8;
		byte[] buffer = new byte[bufferSize];
		int len = 0;
		while((len = is.read(buffer, 0, bufferSize))!=-1){
			os.write(buffer, 0, len);
		}
		is.close();
		os.close();
		//保存下载信息
		Downloadinfo downloadinfo = new Downloadinfo();
		if(customer!=null){
			downloadinfo.setCustomerid(customer.getId());
		}
		downloadinfo.setDid(did);
		downloadinfo.setDtime(new Date());
		downloadinfo.setGameid(Integer.parseInt(gameId));
		downloadinfo.setIpid(proviceid);
		downloadinfo.setLocation(0);
		downloadinfo.setTitleid(0);
		downloadinfoService.save(downloadinfo);
		
		return mapping.findForward("");
	}
}
