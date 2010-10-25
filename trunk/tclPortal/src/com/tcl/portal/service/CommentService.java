package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.CommentDao;
import com.tcl.portal.domain.Comment;

public class CommentService {
	
	private CommentDao commentDao;
	
	public void setCommentDao(CommentDao commentDao) {
		this.commentDao = commentDao;
	}

	public int findCount(Map map) {
		return commentDao.findCount(map);
	}

	public List<Comment> findList(Map map) {
		return commentDao.findList(map);
	}

	public void delete(String[] ids) {
		commentDao.delete(ids);
	}

	public void update(String[] ids, String flag) {
		commentDao.update(ids,flag);
	}

}
