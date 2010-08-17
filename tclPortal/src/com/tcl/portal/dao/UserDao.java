package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import com.tcl.portal.domain.User;

public class UserDao extends  BaseDao{

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findUserCount",map);
	}

	public List findList(Map map) {
		return getSqlMapClientTemplate().queryForList("findUserList",map);
	}

	public void save(User user) {
		getSqlMapClientTemplate().insert("saveUser", user);
	}

	public void update(User user) {
		getSqlMapClientTemplate().update("updateUser", user);
	}

	public User queryUser(String id) {
		return (User)getSqlMapClientTemplate().queryForObject("queryUser", Integer.parseInt(id));
	}

	public User getUserByName(String username) {
		return (User)getSqlMapClientTemplate().queryForObject("queryUserByName", username);
	}

	public List<User> findAll() {
		return getSqlMapClientTemplate().queryForList("findUserAll");
	}

}
