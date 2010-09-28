package com.tcl.paypal.action;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URLDecoder;
import java.net.URLEncoder;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.paypal.domain.Gameresource;
import com.tcl.paypal.domain.Goods;
import com.tcl.paypal.service.GameresourceService;
import com.tcl.paypal.util.Constants;

public class GameresourceAction extends DispatchAction {
	
	public Logger logger = Logger.getLogger(GameresourceAction.class);
	
	private GameresourceService gameresourceService;
	
	public void setGameresourceService(GameresourceService gameresourceService) {
		this.gameresourceService = gameresourceService;
	}

	public ActionForward view(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id =  request.getParameter("id");
		String groupid = request.getParameter("groupid");
		String did = request.getParameter("did");
		Gameresource gameresource = gameresourceService.queryGameresource(Integer.parseInt(id));
		request.setAttribute("obj", gameresource);
		request.setAttribute("groupid", groupid);
		request.setAttribute("did", did);
		return mapping.findForward("view");
	}
	
	public ActionForward download(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 HttpSession session = request.getSession();
		//下载
		String filePath = Constants.DOWNLOAD_PATH;
		//下载文件
		Gameresource gameresource = gameresourceService.queryGameresource(Integer.parseInt((String)session.getAttribute(Constants.GOODS_ID)));
		String fileName = gameresource.getFile1();
		fileName = URLDecoder.decode(fileName,"UTF-8");
		fileName = URLEncoder.encode(fileName, "UTF-8");
		response.setContentType("application/txt"); 
		response.addHeader("Content-Disposition", "attachment; filename=" + fileName);
		//获取文件输入流和输出流
		InputStream is = new BufferedInputStream(new FileInputStream(filePath+gameresource.getLg()+"\\"+fileName));
		OutputStream os = new BufferedOutputStream(response.getOutputStream());
		int bufferSize = 1024*8;
		byte[] buffer = new byte[bufferSize];
		int len = 0;
		while((len = is.read(buffer, 0, bufferSize))!=-1){
			os.write(buffer, 0, len);
		}
		is.close();
		os.close();
		return mapping.findForward("");
	}
	
}