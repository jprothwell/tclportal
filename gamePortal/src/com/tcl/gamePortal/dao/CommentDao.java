package com.tcl.gamePortal.dao;

import java.util.List;
import java.util.Map;

import com.tcl.gamePortal.domain.Comment;

public class CommentDao extends BaseDao{

	public List<Comment> findCommentById(Map map) {
		return getSqlMapClientTemplate().queryForList("findCommentById", map);
	}

	public void save(Comment comment) {
		getSqlMapClientTemplate().insert("saveComment", comment);
	}

	public int findCommentCount(Map map) {
		// TODO Auto-generated method stub
		return (Integer)getSqlMapClientTemplate().queryForObject("findCommentCount", map);
	}

	public List<Comment> findComment(Map map) {
		// TODO Auto-generated method stub
		return getSqlMapClientTemplate().queryForList("findComment",map);
	}

}
