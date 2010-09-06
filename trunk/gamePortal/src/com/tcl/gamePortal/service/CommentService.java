package com.tcl.gamePortal.service;

import java.util.List;

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

}
