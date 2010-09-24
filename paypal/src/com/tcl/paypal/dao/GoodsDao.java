package com.tcl.paypal.dao;

import java.util.List;
import java.util.Map;

import com.tcl.paypal.domain.Goods;


public class GoodsDao extends BaseDao{

	public List<Goods> findGoods(Map map) {
		return getSqlMapClientTemplate().queryForList("findGoodsList", map);
	}

	public Goods queryGoods(int id) {
		return (Goods)getSqlMapClientTemplate().queryForObject("queryGoods", id);
	}
}
