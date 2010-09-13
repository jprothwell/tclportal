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
	public ActionForward index(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		HttpSession session = request.getSession();
		String sessiondid = (String) session.getAttribute(Constants.DID_VALUE);	
        String did=request.getParameter("did");
        if(sessiondid!=null&&!"".equals(sessiondid)&&!"null".equals(sessiondid))did=sessiondid;
        String ip=Util.getIp(request);
        String phnum =Util.getPhone(request);
        int pageid=1;
        String pagename="indexWap1";
        if(did!=null&&!"".equals(did)&&!"null".equals(did)){
	         //*************获取显示页面************/
	    	pageid = pageinfoService.queryPageName(did);
	        session.setAttribute(Constants.DID_VALUE, did);
	    	session.setAttribute(Constants.PAGEID_VALUE, pageid);
			//根据ip查找到省份       
			Ipinfo ipinfo = ipinfoService.queryIpinfo(ip);	
			Map map = new HashMap(2);
			map.put("did", did);
			if(ipinfo!=null){
				session.setAttribute(Constants.PROVICEID_VALUE,ipinfo.getProviceid());
				map.put("provinceid", ipinfo.getProviceid());
			}else{
				map.put("provinceid", 0);
				session.setAttribute(Constants.PROVICEID_VALUE,0);
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
				Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
				if(customer!=null){
					request.setAttribute("username", customer.getUsername());
				}else{
					request.setAttribute("username","");
				}
		  switch(pageid){
		    case 2:pagename="indexWap2";
		       break;
		    case 3:pagename="indexWap3";
		       break;
		    default:pagename="indexWap1";
		      break;		  
		  }
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
			return mapping.findForward(pagename);
		}else{
			//如果did不存在，根据did得到手机列表
			List<Mobileinfo> list = mobileinfoService.findMobile();	
			request.setAttribute("list",list);
			return mapping.findForward("indexMeno");
		}
	}
	//手机用户进入游戏列表
	public ActionForward menulist(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
	    String kindid=request.getParameter("kindid");
	    //通过session得到did,pageid	
	    HttpSession   session=request.getSession(false); 
	    String did = (String) session.getAttribute(Constants.DID_VALUE);
	    int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
	    String pagn=request.getParameter("pagenum");
	    Integer proviceid =  (Integer) session.getAttribute(Constants.PROVICEID_VALUE);
        String ip=Util.getIp(request);
        String phnum =Util.getPhone(request);
        String pagename="listWap1";
        String kindName=typesService.queryType(Integer.parseInt(kindid));;
        int checkNextPage=0;
        
        Map map = new HashMap(5);
        int pagenum=1;//TODO
        if(pagn!=null&&!"".equals(pagn)&&!"null".equals(pagn))pagenum=Integer.parseInt(pagn);
		int start = (pagenum-1) * Constants.PAGESIZE;
		int end = Constants.PAGESIZE;
		map.put("start",start);
		map.put("end", end);
		map.put("did", did);
		map.put("kindid",kindid);
		map.put("provinceid",proviceid);
		int numCount = gameinfoService.findGameMenoCount(map);//总数
	    if((pagenum+1)*Constants.PAGESIZE<numCount)checkNextPage=1;
		List<Gameinfo> list = gameinfoService.findGameMeno(map);
		request.setAttribute("list",list);
		request.setAttribute("kindid",kindid);
		request.setAttribute("pagenum", pagenum);
		request.setAttribute("checkNextPage",checkNextPage);
		request.setAttribute("gamenum",Constants.PAGESIZE);
		request.setAttribute("kindName",kindName);
		request.setAttribute("numCount",numCount);
		switch(pageid){
			  case 2:pagename="listWap2";
			       break;
			  case 3:pagename="listWap3";
			       break;
			  default:pagename="listWap1";
			      break;		  
			 }
			  
			//*********访问统计***********************//		
				Visiteinfo visiteinfo = new Visiteinfo();
				visiteinfo.setDid(did);	
				visiteinfo.setGameid(0);
				visiteinfo.setIp(ip);
				visiteinfo.setLocation(0);
				visiteinfo.setTelephone(phnum);
				visiteinfo.setTitleid(Integer.parseInt(kindid));
				visiteinfoService.save(visiteinfo);
				//*********访问统计end***********************/
			return mapping.findForward(pagename);
	}
}
