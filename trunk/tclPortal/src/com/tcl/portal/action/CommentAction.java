package com.tcl.portal.action;

import java.io.PrintWriter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
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

import com.tcl.portal.domain.Comment;
import com.tcl.portal.domain.Gameinfo;
import com.tcl.portal.service.CommentService;
import com.tcl.portal.service.GameinfoService;
import com.tcl.portal.util.DateUtil;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class CommentAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(CommentAction.class);
	
	private CommentService  commentService;
	
	private GameinfoService gameinfoService;
	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}
	public void setCommentService(CommentService commentService) {
		this.commentService = commentService;
	}


	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String startDate=request.getParameter("startDate");
		String endDate=request.getParameter("endDate");
		String gameid = request.getParameter("gameid");
		String gameName = request.getParameter("gameName");
		if(gameid==null){
			gameid = "";
		}
		if(gameName==null){
			gameName = "";
		}
		System.out.println(gameid+"??>>>>"+gameName);
		if (("").equals(startDate)||startDate==null)
		{
			startDate = DateUtil.getTheMonthFirstDay();
		}
		if (("").equals(endDate)||endDate==null)
		{
			endDate = DateUtil.getCurrentDate();
		}
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("gameid", gameid);
		map.put("gameName", gameName);
		Date startD = null;
		Date endD = null;
		try {
			if (!("").equals(startDate)&&startDate!=null)
			{
			startD =  new SimpleDateFormat("yyyy-MM-dd").parse(startDate);
			}
			
		} catch (ParseException e) {
			e.printStackTrace();
		}
		if(!"".equals(startDate)&&startDate!=null){
			map.put("startDate",startD);
		}
		if(!"".equals(endDate)&&endDate!=null){
			map.put("endDate",endD);
		}
		pager.setEntryCount(commentService.findCount(map));
		pager.addParam("startDate", startDate);
		pager.addParam("endDate", endDate);
		pager.addParam("gameid", gameid);
		pager.addParam("gameName", gameName);
		List<Comment> list = commentService.findList(map);
		for(Comment comment:list){
			Gameinfo gameinfo = gameinfoService.queryGameinfo(comment.getGameid());
			if(gameinfo!=null){
				comment.setGameName(gameinfo.getGamename());
			}
		}
		request.setAttribute("list", list);
		request.setAttribute("startDate", startDate);
		request.setAttribute("endDate", endDate);
		request.setAttribute("gameid", gameid);
		request.setAttribute("gameName", gameName);
		return mapping.findForward("list");
	}
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String nid = request.getParameter("nid");
		String[] ids = nid.split(",");
		commentService.delete(ids);
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		out.write("1");
		out.flush();
		return null;
	}
	
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String flag = request.getParameter("flag");
		String nid = request.getParameter("nid");
		String[] ids = nid.split(",");
		commentService.update(ids,flag);
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		out.write("1");
		out.flush();
		return null;
	}
	
}
