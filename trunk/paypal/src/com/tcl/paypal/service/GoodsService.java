package com.tcl.paypal.service;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import net.sf.ehcache.Cache;

import com.tcl.paypal.dao.GoodsDao;
import com.tcl.paypal.domain.Goods;

public class GoodsService {
	
	public Logger logger = Logger.getLogger(GoodsService.class);
	
	private GoodsDao  goodsDao;

	public void setGoodsDao(GoodsDao goodsDao) {
		this.goodsDao = goodsDao;
	}

	public List<Goods> findGoods(Map map) {
		return goodsDao.findGoods(map);
	}

	public Goods queryGoods(int id) {
		return goodsDao.queryGoods(id);
	}
	
	
}
