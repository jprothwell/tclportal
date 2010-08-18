package com.tcl.gamePortal.action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;

import com.tcl.gamePortal.domain.Ipinfo;
import com.tcl.gamePortal.service.IpinfoService;



/**
 * 用户手机登陆
 * @author kun.shen
 *
 */
public class LoginAction {
	
	public Logger logger = Logger.getLogger(LoginAction.class);
	
	private IpinfoService ipinfoService;
	
	public void setIpinfoService(IpinfoService ipinfoService) {
		this.ipinfoService = ipinfoService;
	}


	//手机用户进入主页 
	public ActionForward visit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		//根据ip 手机ua显示页面内容
		String ip = "";
		//根据ip查找到省份
		Ipinfo ipinfo = ipinfoService.queryIpinfo(ip);
		ipinfo.getProviceid();
		String ua = request.getParameter("ua");
		
		return mapping.findForward("save");
	}
}
