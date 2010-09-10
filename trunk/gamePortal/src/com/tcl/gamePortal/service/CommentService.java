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

	public List<Comment> findCommentById(int id) {
		return commentDao.findCommentById(id);
	}

	public void save(Comment comment) {
		commentDao.save(comment);
	}

	public int findCommentCount(int gameid) {
		// TODO Auto-generated method stub
		return commentDao.findCommentCount(gameid);
	}

	public List<Comment> findComment(Map map) {
		// TODO Auto-generated method stub
		return commentDao.findComment(map);
	}

}
