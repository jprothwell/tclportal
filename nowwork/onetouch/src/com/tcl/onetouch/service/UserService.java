package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.onetouch.dao.UserDao;
import com.tcl.onetouch.domain.User;



public class UserService {
	
	private UserDao  userDao;
	
	private Cache cache = null;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}

	public void setUserDao(UserDao userDao) {
		this.userDao = userDao;
	}

	public int findCount(Map map) {
		return userDao.findCount(map);
	}

	public List findList(Map map) {
		return userDao.findList(map);
	}

	public void save(User user) {
		userDao.save(user);
		this.updateCache();
	}

	public void update(User user) {
		userDao.update(user);
		this.updateCache();
	}

	public User queryUser(String id) {
		return userDao.queryUser(id);
	}

	public User getUserByName(String username) {
		List<User> users = this.findAll();
		for(User user:users){
			if(user.getName().equals(username)){
				return user;
			}
		}
		return null;
	}
	
	public List findAll(){
		List<User> users = null;
		Element element = this.cache.get(User.CACHE_USER);
		if (null != element) {
			users = (List<User>)element.getValue();
      } else {
    	  users = this.userDao.findAll();
          element = new Element(User.CACHE_USER, users);
          this.cache.put(element);
      }
      return users;
	}
	private void updateCache(){
        if(null != this.cache)
               this.cache.remove(User.CACHE_USER);
	}
}
