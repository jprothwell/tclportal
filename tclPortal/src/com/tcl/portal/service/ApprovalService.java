package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.ApprovalDao;
import com.tcl.portal.domain.Approval;

public class ApprovalService {
	
	private ApprovalDao  approvalDao;
	
	public void setApprovalDao(ApprovalDao approvalDao) {
		this.approvalDao = approvalDao;
	}

	public int findCount(Map map) {
		return approvalDao.findCount(map);
	}

	public List<Approval> findList(Map map) {
		return approvalDao.findList(map);
	}

	public void save(Approval approval) {
		approvalDao.save(approval);
	}

	public void update(Approval approval) {
		approvalDao.update(approval);
	}

	public Approval queryApproval(int parseInt) {
		return approvalDao.queryApprovel(parseInt);
	}

}
