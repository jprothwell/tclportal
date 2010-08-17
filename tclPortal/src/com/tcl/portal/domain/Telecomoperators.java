package com.tcl.portal.domain;

import java.io.Serializable;

public class Telecomoperators {
    public static final Serializable CACHE_TELECOMOPERATORS = "telecomCache";

	/**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column telecomoperators.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Integer id;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column telecomoperators.name
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String name;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column telecomoperators.countryId
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Integer countryid;

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column telecomoperators.id
     *
     * @return the value of telecomoperators.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Integer getId() {
        return id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column telecomoperators.id
     *
     * @param id the value for telecomoperators.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setId(Integer id) {
        this.id = id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column telecomoperators.name
     *
     * @return the value of telecomoperators.name
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getName() {
        return name;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column telecomoperators.name
     *
     * @param name the value for telecomoperators.name
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column telecomoperators.countryId
     *
     * @return the value of telecomoperators.countryId
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Integer getCountryid() {
        return countryid;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column telecomoperators.countryId
     *
     * @param countryid the value for telecomoperators.countryId
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