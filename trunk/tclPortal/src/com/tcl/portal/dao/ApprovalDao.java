package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Approval;

public class ApprovalDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(ApprovalDao.class);

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findApprovalCount",map);
	}

	public List<Approval> findList(Map map) {
		return getSqlMapClientTemplate().queryForList("findApprovalList",map);
	}

	public void save(Approval approval) {
		getSqlMapClientTemplate().insert("saveApproval", approval);
	}

	public void update(Approval approval) {
		getSqlMapClientTemplate().update("updateApproval", approval);
	}

	public Approval queryApprovel(int id) {
		return (Approval)getSqlMapClientTemplate().queryForObject("queryApprovel",id);
	}
	

}
