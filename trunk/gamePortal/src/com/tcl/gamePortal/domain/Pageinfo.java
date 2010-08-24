package com.tcl.gamePortal.domain;
/**
 * 页面信息
 * @author kun.shen
 *
 */
public class Pageinfo {
    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column pageinfo.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Integer id;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column pageinfo.pagename
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String pagename;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column pageinfo.filename
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String filename;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column pageinfo.isdefault
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Integer isdefault;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column pageinfo.remark
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private String remark;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column pageinfo.languageId
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    private Integer languageid;
    
    private Integer pagetype;
    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column pageinfo.id
     *
     * @return the value of pageinfo.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Integer getId() {
        return id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column pageinfo.id
     *
     * @param id the value for pageinfo.id
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setId(Integer id) {
        this.id = id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column pageinfo.pagename
     *
     * @return the value of pageinfo.pagename
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getPagename() {
        return pagename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column pageinfo.pagename
     *
     * @param pagename the value for pageinfo.pagename
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setPagename(String pagename) {
        this.pagename = pagename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column pageinfo.filename
     *
     * @return the value of pageinfo.filename
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getFilename() {
        return filename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column pageinfo.filename
     *
     * @param filename the value for pageinfo.filename
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setFilename(String filename) {
        this.filename = filename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column pageinfo.isdefault
     *
     * @return the value of pageinfo.isdefault
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Integer getIsdefault() {
        return isdefault;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column pageinfo.isdefault
     *
     * @param isdefault the value for pageinfo.isdefault
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setIsdefault(Integer isdefault) {
        this.isdefault = isdefault;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column pageinfo.remark
     *
     * @return the value of pageinfo.remark
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public String getRemark() {
        return remark;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column pageinfo.remark
     *
     * @param remark the value for pageinfo.remark
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setRemark(String remark) {
        this.remark = remark;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column pageinfo.languageId
     *
     * @return the value of pageinfo.languageId
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public Integer getLanguageid() {
        return languageid;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column pageinfo.languageId
     *
     * @param languageid the value for pageinfo.languageId
     *
     * @abatorgenerated Wed Jul 28 14:13:04 CST 2010
     */
    public void setLanguageid(Integer languageid) {
        this.languageid = languageid;
    }

	public Integer getPagetype() {
		return pagetype;
	}

	public void setPagetype(Integer pagetype) {
		this.pagetype = pagetype;
	}
    
    
}