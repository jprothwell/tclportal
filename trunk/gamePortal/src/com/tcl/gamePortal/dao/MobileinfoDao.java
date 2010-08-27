package com.tcl.gamePortal.dao;

import java.util.List;
import java.util.Map;

import com.tcl.gamePortal.domain.Gameinfo;
import com.tcl.gamePortal.domain.Mobileinfo;

public class MobileinfoDao extends BaseDao{
  public String getMobileUa(int did){
	  return (String)getSqlMapClientTemplate().queryForObject("getMobileUa", did);
  }

public List<Mobileinfo> findMobile() {
	return getSqlMapClientTemplate().queryForList("findMobileAll");
}
}
