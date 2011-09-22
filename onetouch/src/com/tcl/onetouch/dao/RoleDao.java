package com.tcl.onetouch.dao;

import java.util.List;
import java.util.Map;

import com.tcl.onetouch.domain.Role;


public class RoleDao  extends  BaseDao{

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findRoleCount",map);
	}

	public List findList(Map map) {
		return getSqlMapClientTemplate().queryForList("findRoleList",map);
	}

	public List findAll() {
		return getSqlMapClientTemplate().queryForList("findAll");
	}

	public void save(Role role) {
		getSqlMapClientTemplate().insert("saveRole", role);
	}

	public void update(Role role) {
		getSqlMapClientTemplate().update("updateRole", role);
	}

	public Role queryRole(String id) {
		return (Role)getSqlMapClientTemplate().queryForObject("queryRole", Integer.parseInt(id));
	}

}
