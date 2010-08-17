package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.portal.dao.RoleDao;
import com.tcl.portal.domain.Role;


public class RoleService {

	private RoleDao roleDao;
	
	
	private Cache cache = null;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}

	public void setRoleDao(RoleDao roleDao) {
		this.roleDao = roleDao;
	}

	public int findCount(Map map) {
		return roleDao.findCount(map);
	}

	public List findList(Map map) {
		return roleDao.findList(map);
	}
	
	public List findAll() {
		return roleDao.findAll();
	}

	public void save(Role role) {
		roleDao.save(role);
		this.updateCache();
	}

	public void update(Role role) {
		roleDao.update(role);
		this.updateCache();
	}
	public String queryRoleNameById(Integer id){
		List<Role> roles = this.findRoleAll();
		for(Role role:roles){
			if(role.getId().equals(id)){
				return role.getName();
			}
		}
		return "";
	}
	public Role queryRole(String id) {
		List<Role> roles = this.findRoleAll();
		for(Role role:roles){
			if(role.getId().equals(Integer.parseInt(id))){
				return role;
			}
		}
		return null;
	}
	
	public List<Role> findRoleAll(){
		List<Role> roles = null;
		Element element = this.cache.get(Role.CACHE_ROLE);
		if (null != element) {
			roles = (List<Role>)element.getValue();
      } else {
    	  roles = this.roleDao.findAll();
          element = new Element(Role.CACHE_ROLE, roles);
          this.cache.put(element);
      }
      return roles;
	}
	
	private void updateCache(){
        if(null != this.cache)
               this.cache.remove(Role.CACHE_ROLE);
	}
}
