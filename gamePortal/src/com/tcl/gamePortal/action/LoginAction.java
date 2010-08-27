package com.tcl.gamePortal.action;

import java.util.HashMap;
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

import com.tcl.gamePortal.domain.Customer;
import com.tcl.gamePortal.domain.Gameinfo;
import com.tcl.gamePortal.domain.Ipinfo;
import com.tcl.gamePortal.domain.Mobileinfo;
import com.tcl.gamePortal.domain.Visiteinfo;
import com.tcl.gamePortal.service.GameinfoService;
import com.tcl.gamePortal.service.GameresouceService;
import com.tcl.gamePortal.service.IpinfoService;
import com.tcl.gamePortal.service.MobileinfoService;
import com.tcl.gamePortal.service.PageinfoService;
import com.tcl.gamePortal.service.TypesService;
import com.tcl.gamePortal.service.VisiteinfoService;
import com.tcl.gamePortal.util.Constants;
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
	
	private TypesService typesService;
	
	private MobileinfoService mobileinfoService;
	
	
	public void setTypesService(TypesService typesService) {
		this.typesService = typesService;
	}

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
	
	public void setPageinfoService(PageinfoService pageinfoService) {
		this.pageinfoService = pageinfoService;
	}
	

	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}
	
	//手机用户进入主页 
	public ActionForward visitHomePage(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		HttpSession session = request.getSession();
		
        String did=request.getParameter("did");
        session.setAttribute(Constants.DID_VALUE, did);
        String ip=Util.getIp(request);
        String phnum =Util.getPhone(request);
        String pagename=null;
        if(did!=null){
	         //*************获取显示页面************/
	    		pagename = pageinfoService.queryPageName(did);
	    		System.out.println("pagename="+pagename);
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
			for(Gameinfo gameinfo:list){
				gameinfo.setKindName(typesService.queryType(gameinfo.getKindid()));
			}
			
			if(list.size()==0){
				map.put("provinceid", 0);	
				list = gameinfoService.findGame(map);	
			}
			request.setAttribute("list", list);
			//*********访问统计***********************/
			
			Visiteinfo visiteinfo = new Visiteinfo();
			visiteinfo.setDid(did);	
			visiteinfo.setGameid(0);
			visiteinfo.setIp(ip);
			visiteinfo.setLocation(0);
			visiteinfo.setTelephone(phnum);
			visiteinfo.setTitleid(0);
			visiteinfoService.save(visiteinfo);
			//*********访问统计end***********************/
				Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
				if(customer!=null){
					request.setAttribute("username", customer.getUsername());
				}else{
					request.setAttribute("username","");
				}
			return mapping.findForward("indexWap1");
		}else{
			//如果did不存在，根据did得到手机列表
			List<Mobileinfo> list = mobileinfoService.findMobile();	
			request.setAttribute("list",list);
			return mapping.findForward("indexMeno");
		}
	}

}
