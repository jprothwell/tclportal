package com.tcl.gamePortal.action;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;

import com.tcl.gamePortal.domain.Gameinfo;
import com.tcl.gamePortal.domain.Ipinfo;
import com.tcl.gamePortal.service.GameinfoService;
import com.tcl.gamePortal.service.GameresouceService;
import com.tcl.gamePortal.service.IpinfoService;



/**
 * 用户手机登陆
 * @author kun.shen
 *
 */
public class LoginAction {
	
	public Logger logger = Logger.getLogger(LoginAction.class);
	
	private IpinfoService ipinfoService;
	
	private GameresouceService gameresouceService;
	
	private GameinfoService gameinfoService;
	
	public void setIpinfoService(IpinfoService ipinfoService) {
		this.ipinfoService = ipinfoService;
	}
	
	public void setGameresouceService(GameresouceService gameresouceService) {
		this.gameresouceService = gameresouceService;
	}

	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}
	//手机用户进入主页 
	public ActionForward visitHomePage(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		//根据ip 手机ua显示页面内容
		String ip = request.getParameter("ip");
		//根据ip查找到省份
		Ipinfo ipinfo = ipinfoService.queryIpinfo(ip);
		String did = request.getParameter("did");
		//根据省份，did找到游戏资源，再从游戏资源获取游戏基本信息，显示在前端
		Map map = new HashMap(2);
		if(ipinfo!=null){
			map.put("provinceid", ipinfo.getProviceid());
		}else{
			map.put("provinceid", 0);
		}
		map.put("did", did);
		List<Gameinfo> list = gameinfoService.findGame(map);
		request.setAttribute("list", list);
		
		return mapping.findForward("visitHomePage");
	}
}
