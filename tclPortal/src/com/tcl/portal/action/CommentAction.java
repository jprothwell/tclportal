package com.tcl.portal.action;

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
import com.tcl.portal.service.CommentService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class CommentAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(CommentAction.class);
	
	private CommentService  commentService;
	
	public void setCommentService(CommentService commentService) {
		this.commentService = commentService;
	}


	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String name = request.getParameter("name");
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("name", name);
		pager.setEntryCount(commentService.findCount(map));
		pager.addParam("name", name);
		List<Comment> list = commentService.findList(map);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
}