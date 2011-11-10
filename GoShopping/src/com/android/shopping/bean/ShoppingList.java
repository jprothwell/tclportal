package com.android.shopping.bean;

import java.util.Date;
import java.util.List;


/**
 * 购物清单对象
 * @author kun.shen
 *
 */
public class ShoppingList {
	
	private int id;
	
	private String name;
	
	private Date date;
	
	private String remark;
	
	List<Goods> goodsList;
	
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Date getDate() {
		return date;
	}

	public void setDate(Date date) {
		this.date = date;
	}

	public String getRemark() {
		return remark;
	}

	public void setRemark(String remark) {
		this.remark = remark;
	}

	public List<Goods> getGoodsList() {
		return goodsList;
	}

	public void setGoodsList(List<Goods> goodsList) {
		this.goodsList = goodsList;
	}
	
	
}
