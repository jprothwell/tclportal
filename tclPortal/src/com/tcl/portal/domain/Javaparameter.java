package com.tcl.portal.domain;

import java.io.Serializable;

public class Javaparameter {
    public static final Serializable CACHE_JAVAPARAMETER = "cacheJavaParameter";

	/**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column javaparameter.id
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    private Integer id;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column javaparameter.name
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    private String name;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column javaparameter.value
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    private String value;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column javaparameter.remarker
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    private String remarker;

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column javaparameter.id
     *
     * @return the value of javaparameter.id
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    public Integer getId() {
        return id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column javaparameter.id
     *
     * @param id the value for javaparameter.id
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    public void setId(Integer id) {
        this.id = id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column javaparameter.name
     *
     * @return the value of javaparameter.name
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    public String getName() {
        return name;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column javaparameter.name
     *
     * @param name the value for javaparameter.name
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column javaparameter.value
     *
     * @return the value of javaparameter.value
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    public String getValue() {
        return value;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column javaparameter.value
     *
     * @param value the value for javaparameter.value
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    public void setValue(String value) {
        this.value = value;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column javaparameter.remarker
     *
     * @return the value of javaparameter.remarker
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    public String getRemarker() {
        return remarker;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column javaparameter.remarker
     *
     * @param remarker the value for javaparameter.remarker
     *
     * @abatorgenerated Wed Jul 28 14:13:03 CST 2010
     */
    public void setRemarker(String remarker) {
        this.remarker = remarker;
    }
}