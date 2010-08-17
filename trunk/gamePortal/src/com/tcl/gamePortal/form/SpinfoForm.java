package com.tcl.gamePortal.form;

import java.util.Date;

import org.apache.commons.beanutils.ConvertUtils;

import com.tcl.gamePortal.util.DateConvert;


public class SpinfoForm extends BaseForm{
	static{
		ConvertUtils.register(new DateConvert(),java.util.Date.class); 
	}
	/**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column spinfo.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Integer id;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column spinfo.name
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String name;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column spinfo.address
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String address;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column spinfo.contactPerson
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String contactperson;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column spinfo.phone
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String phone;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column spinfo.remark
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String remark;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column spinfo.begainTime
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Date begaintime;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column spinfo.endTime
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Date endtime;

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column spinfo.id
     *
     * @return the value of spinfo.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Integer getId() {
        return id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column spinfo.id
     *
     * @param id the value for spinfo.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setId(Integer id) {
        this.id = id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column spinfo.name
     *
     * @return the value of spinfo.name
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getName() {
        return name;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column spinfo.name
     *
     * @param name the value for spinfo.name
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column spinfo.address
     *
     * @return the value of spinfo.address
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getAddress() {
        return address;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column spinfo.address
     *
     * @param address the value for spinfo.address
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setAddress(String address) {
        this.address = address;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column spinfo.contactPerson
     *
     * @return the value of spinfo.contactPerson
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getContactperson() {
        return contactperson;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column spinfo.contactPerson
     *
     * @param contactperson the value for spinfo.contactPerson
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setContactperson(String contactperson) {
        this.contactperson = contactperson;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column spinfo.phone
     *
     * @return the value of spinfo.phone
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getPhone() {
        return phone;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column spinfo.phone
     *
     * @param phone the value for spinfo.phone
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setPhone(String phone) {
        this.phone = phone;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column spinfo.remark
     *
     * @return the value of spinfo.remark
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getRemark() {
        return remark;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column spinfo.remark
     *
     * @param remark the value for spinfo.remark
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setRemark(String remark) {
        this.remark = remark;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column spinfo.begainTime
     *
     * @return the value of spinfo.begainTime
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Date getBegaintime() {
        return begaintime;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column spinfo.begainTime
     *
     * @param begaintime the value for spinfo.begainTime
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setBegaintime(Date begaintime) {
        this.begaintime = begaintime;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column spinfo.endTime
     *
     * @return the value of spinfo.endTime
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Date getEndtime() {
        return endtime;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column spinfo.endTime
     *
     * @param endtime the value for spinfo.endTime
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setEndtime(Date endtime) {
        this.endtime = endtime;
    }
}
