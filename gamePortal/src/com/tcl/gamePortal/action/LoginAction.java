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
import org.apache.struts.actions.DispatchAction;

import com.tcl.gamePortal.domain.Gameinfo;
import com.tcl.gamePortal.domain.Ipinfo;
import com.tcl.gamePortal.service.GameinfoService;
import com.tcl.gamePortal.service.GameresouceService;
import com.tcl.gamePortal.service.IpinfoService;
import com.tcl.gamePortal.service.PageinfoService;
import com.tcl.gamePortal.service.VisiteinfoService;
import com.tcl.gamePortal.util.Util;



/**
 * 用户手机登陆
 * @author kun.shen
 *
 */
public class LoginAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(LoginAction.class);
	
	private IpinfoService ipinfoService;
	
	private GameresouceService gameresouceService;
	
	private GameinfoService gameinfoService;
	
	private VisiteinfoService visiteinfoService;
	
	private PageinfoService pageinfoService;

	public void setVisiteinfoService(VisiteinfoService visiteinfoService) {
		this.visiteinfoService = visiteinfoService;
	}

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
        String did=request.getParameter("did");
        String ip=Util.getIp(request);
        String phnum =Util.getPhone(request);
        String pagename=null;
        if(did!=null){
		//根据ip查找到省份       
		Ipinfo ipinfo = ipinfoService.queryIpinfo(ip);		
		Map map = new HashMap(2);
		map.put("did", did);
		if(ipinfo!=null){
			map.put("provinceid", ipinfo.getProviceid());
		}else{
			map.put("provinceid", 0);
		}		
		List<Gameinfo> list = gameinfoService.findGame(map);
		if(list.size()==0){
			map.put("provinceid", 0);	
			list = gameinfoService.findGame(map);	
		}
		request.setAttribute("list", list);
		//获取显示页面
		pagename = pageinfoService.queryPageName(did);
//		Visiteinfo visiteinfo = new Visiteinfo();
//		visiteinfo.setDid(did);		
//		visiteinfoService.save(visiteinfo);
		return mapping.findForward("visitHomePage");
	}else{//如果did不存在，根据did得到手机列表
		return mapping.findForward("visitHomePage");
	}
	}
}
