package com.tcl.gamePortal.dao;

import java.util.List;

import com.tcl.gamePortal.domain.Comment;

public class CommentDao extends BaseDao{

	public List<Comment> findCommentById(int id) {
		return getSqlMapClientTemplate().queryForList("findCommentById", id);
	}

	public void save(Comment comment) {
		getSqlMapClientTemplate().insert("saveComment", comment);
	}

}
