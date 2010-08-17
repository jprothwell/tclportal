package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Comment;

public class CommentDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(CommentDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findCommentCount",map);
	}

	public List<Comment> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findCommentList",map);
	}

}
