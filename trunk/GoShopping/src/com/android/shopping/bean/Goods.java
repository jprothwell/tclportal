package com.android.shopping.bean;
/**
 * ��Ʒ����
 * @author kun.shen
 *
 */
public class Goods {
	
	private int id;
	//����
	private String name;
	//�۸�
	private double price;
	//��Ʒ����
	private String remark;
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
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public String getRemark() {
		return remark;
	}
	public void setRemark(String remark) {
		this.remark = remark;
	}
	
	//���м��ȡ��������
	private double  number;
	
	private int state;
	public double getNumber() {
		return number;
	}
	public void setNumber(double number) {
		this.number = number;
	}
	public int getState() {
		return state;
	}
	public void setState(int state) {
		this.state = state;
	}
}
