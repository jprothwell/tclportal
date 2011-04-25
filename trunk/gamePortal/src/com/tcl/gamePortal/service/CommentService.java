package com.tcl.gamePortal.service;

import java.util.List;
import java.util.Map;

import com.tcl.gamePortal.dao.CommentDao;
import com.tcl.gamePortal.domain.Comment;

public class CommentService {
	
	private CommentDao commentDao;
	
	public void setCommentDao(CommentDao commentDao) {
		this.commentDao = commentDao;
	}

	public List<Comment> findCommentById(Map map) {
		return commentDao.findCommentById(map);
	}

	public void save(Comment comment) {
		commentDao.save(comment);
	}

	public int findCommentCount(Map map) {
		// TODO Auto-generated method stub
		return commentDao.findCommentCount(map);
	}

	public List<Comment> findComment(Map map) {
		// TODO Auto-generated method stub
		return commentDao.findComment(map);
	}

}
