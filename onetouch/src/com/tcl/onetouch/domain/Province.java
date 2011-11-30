package com.tcl.onetouch.domain;

import java.io.Serializable;

public class Province {
    public static final Serializable CACHE_PROVINCE = "provinceCache";

	/**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column province.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Integer id;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column province.provinceName
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String provincename;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column province.countryId
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Integer countryid;

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column province.id
     *
     * @return the value of province.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Integer getId() {
        return id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column province.id
     *
     * @param id the value for province.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setId(Integer id) {
        this.id = id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column province.provinceName
     *
     * @return the value of province.provinceName
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getProvincename() {
        return provincename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column province.provinceName
     *
     * @param provincename the value for province.provinceName
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setProvincename(String provincename) {
        this.provincename = provincename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column province.countryId
     *
     * @return the value of province.countryId
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Integer getCountryid() {
        return countryid;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column province.countryId
     *
     * @param countryid the value for province.countryId
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setCountryid(Integer countryid) {
        this.countryid = countryid;
    }
    
    private String countryName;

	public String getCountryName() {
		return countryName;
	}

	public void setCountryName(String countryName) {
		this.countryName = countryName;
	}
    
}