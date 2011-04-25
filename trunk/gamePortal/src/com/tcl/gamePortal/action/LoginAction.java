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
        String did=request.getParameter("did");
        String ip=Util.getIp(request);
        String phnum =Util.getPhone(request);
        int pageid=1;
        int proviceid=0;
        String pagename="indexWap1";
        if(did!=null&&!"".equals(did)&&!"null".equals(did)){
	         //*************获取显示页面************/
	    	pageid = pageinfoService.queryPageName(did);

			//根据ip查找到省份       
			Ipinfo ipinfo = ipinfoService.queryIpinfo(ip);	
			Map map = new HashMap(2);
			map.put("did", did);
			if(ipinfo!=null)proviceid=ipinfo.getProviceid();
            map.put("proviceid",proviceid);
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
			request.setAttribute("did",did);
			request.setAttribute("pageid",pageid);
			request.setAttribute("proviceid",proviceid);
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
	    String content = request.getParameter("searchName");
	    String did = request.getParameter("did");
	    int pageid = Integer.parseInt(request.getParameter("pageid"));
	    int proviceid = Integer.parseInt(request.getParameter("proviceid"));
	    int numCount=0;
	    //通过session得到did,pageid	
	    String pagn=request.getParameter("pagenum");
        String ip=Util.getIp(request);
        String phnum =Util.getPhone(request);
        String pagename="listWap1";
        String kindName="";
       if(kindid!=null&&!"".equals(kindid)&&!"null".equals(kindid)&&!"0".equals(kindid)){
        kindName=typesService.queryType(Integer.parseInt(kindid));
}else kindid="0";
        
        int checkNextPage=0;
        
        Map map = new HashMap(6);
        int pagenum=1;//TODO
        if(pagn!=null&&!"".equals(pagn)&&!"null".equals(pagn))pagenum=Integer.parseInt(pagn);
		int start = (pagenum-1) * Constants.PAGESIZE;
		int end = Constants.PAGESIZE;
		map.put("start",start);
		map.put("end", end);
		map.put("did", did);
		map.put("kindid",kindid);
		map.put("content",content);
		map.put("provinceid",proviceid);
		List<Gameinfo> list =null;
		/////////////////////
		if(!"0".equals(kindid)){
			numCount = gameinfoService.findGameMenoCount(map);//总数
			list = gameinfoService.findGameMeno(map);
		}
		else if(content!=null&&!"".equals(content)&&!"null".equals(content)){
			numCount = gameinfoService.findGMCount(map);//总数
			list = gameinfoService.findGM(map);
			kindName="游戏搜索";
		}else {
			 numCount = gameinfoService.newGMCount(map);
			 list = gameinfoService.newGM(map);
			 kindName="最新上线游戏";
		}
		////////////////////////////////////////////////////////////
		
	    if(pagenum*Constants.PAGESIZE<numCount)checkNextPage=1;
		request.setAttribute("list",list);
		request.setAttribute("kindid",kindid);
		request.setAttribute("pagenum", pagenum);
		request.setAttribute("checkNextPage",checkNextPage);
		request.setAttribute("gamenum",Constants.PAGESIZE);
		request.setAttribute("kindName",kindName);
		request.setAttribute("numCount",numCount);
		request.setAttribute("did",did);
		request.setAttribute("pageid",pageid);
		request.setAttribute("proviceid",proviceid);
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
