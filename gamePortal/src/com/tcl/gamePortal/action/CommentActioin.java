package com.tcl.gamePortal.action;

import java.util.Date;
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

import com.tcl.gamePortal.domain.Comment;
import com.tcl.gamePortal.domain.Customer;
import com.tcl.gamePortal.domain.Gameinfo;
import com.tcl.gamePortal.service.CommentService;
import com.tcl.gamePortal.service.GameinfoService;
import com.tcl.gamePortal.util.Constants;

public class CommentActioin  extends DispatchAction{
	
	public Logger logger = Logger.getLogger(CommentActioin.class);
	
	private CommentService  commentService;

	private GameinfoService gameinfoService;
	
	public void setCommentService(CommentService commentService) {
		this.commentService = commentService;
	}
	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}

	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String gameId = request.getParameter("gameId");
		String content = request.getParameter("content");
		String location=request.getParameter("location");
		HttpSession session = request.getSession();
		Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
		Comment comment = new Comment();
		comment.setGameid(Integer.parseInt(gameId));
		comment.setContent(content);
		if(customer!=null){
			comment.setMobileuserid(customer.getId());
		}
		comment.setDisable(1);//默认不显示
		commentService.save(comment);
		request.setAttribute("location",location);
		request.setAttribute("gameId",gameId);
		return mapping.findForward("save");
	}
	public ActionForward list(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String gameId = request.getParameter("gameId");
		String pagn=request.getParameter("pagenum");
	    HttpSession   session=request.getSession(false); 
	    int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
	    int checkNextPage=0;
		//获取游戏简介
		Gameinfo gameInfo = gameinfoService.queryGameinfo(Integer.parseInt(gameId));
		Map map = new HashMap(5);
        int pagenum=1;//TODO
        if(pagn!=null&&!"".equals(pagn)&&!"null".equals(pagn))pagenum=Integer.parseInt(pagn);
		int start = (pagenum-1) * Constants.PAGESIZE;
		int end = Constants.PAGESIZE;
		map.put("start",start);
		map.put("end", end);
		map.put("gameId", gameId);
		int numCount = commentService.findCommentCount(Integer.parseInt(gameId));
	    if(pagenum*Constants.PAGESIZE<numCount)checkNextPage=1;
		List<Comment> list = commentService.findComment(map);
		request.setAttribute("gameId", gameId);
		request.setAttribute("pagenum", pagenum); 
		request.setAttribute("numCount", numCount);
		request.setAttribute("checkNextPage",checkNextPage);
		request.setAttribute("obj", gameInfo);
		request.setAttribute("list",list);
		if(pageid==2){
			return mapping.findForward("listCom2");
		}else if(pageid==3){
			return mapping.findForward("listCom3");
		}else{
			return mapping.findForward("listCom1");
		}
	}
}
