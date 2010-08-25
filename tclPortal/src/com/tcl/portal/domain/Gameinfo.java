package com.tcl.portal.domain;

import java.io.Serializable;
import java.util.Date;

public class Gameinfo {
    public static final Serializable CACHE_GAMEINFO = "gameinfoCache";

	/**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.id
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private Integer id;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.gameName
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private String gamename;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.detailInfo
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private String detailinfo;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.type
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private Integer kindid;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.addTime
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private Date addtime;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.spid
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private Integer spid;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.imageName
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private String imagename;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.language
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private String language;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.style
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private String style;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.disable
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private Integer disable;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.brief
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private String brief;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.icon
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private String icon;

    /**
     * This field was generated by Abator for iBATIS.
     * This field corresponds to the database column gameinfo.level
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    private Integer lev;

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.id
     *
     * @return the value of gameinfo.id
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public Integer getId() {
        return id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.id
     *
     * @param id the value for gameinfo.id
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setId(Integer id) {
        this.id = id;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.gameName
     *
     * @return the value of gameinfo.gameName
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public String getGamename() {
        return gamename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.gameName
     *
     * @param gamename the value for gameinfo.gameName
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setGamename(String gamename) {
        this.gamename = gamename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.detailInfo
     *
     * @return the value of gameinfo.detailInfo
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public String getDetailinfo() {
        return detailinfo;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.detailInfo
     *
     * @param detailinfo the value for gameinfo.detailInfo
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setDetailinfo(String detailinfo) {
        this.detailinfo = detailinfo;
    }

  

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.addTime
     *
     * @return the value of gameinfo.addTime
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public Date getAddtime() {
        return addtime;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.addTime
     *
     * @param addtime the value for gameinfo.addTime
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setAddtime(Date addtime) {
        this.addtime = addtime;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.spid
     *
     * @return the value of gameinfo.spid
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public Integer getSpid() {
        return spid;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.spid
     *
     * @param spid the value for gameinfo.spid
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setSpid(Integer spid) {
        this.spid = spid;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.imageName
     *
     * @return the value of gameinfo.imageName
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public String getImagename() {
        return imagename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.imageName
     *
     * @param imagename the value for gameinfo.imageName
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setImagename(String imagename) {
        this.imagename = imagename;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.language
     *
     * @return the value of gameinfo.language
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public String getLanguage() {
        return language;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.language
     *
     * @param language the value for gameinfo.language
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setLanguage(String language) {
        this.language = language;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.style
     *
     * @return the value of gameinfo.style
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public String getStyle() {
        return style;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.style
     *
     * @param style the value for gameinfo.style
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setStyle(String style) {
        this.style = style;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.disable
     *
     * @return the value of gameinfo.disable
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public Integer getDisable() {
        return disable;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.disable
     *
     * @param disable the value for gameinfo.disable
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setDisable(Integer disable) {
        this.disable = disable;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.brief
     *
     * @return the value of gameinfo.brief
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public String getBrief() {
        return brief;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.brief
     *
     * @param brief the value for gameinfo.brief
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setBrief(String brief) {
        this.brief = brief;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method returns the value of the database column gameinfo.icon
     *
     * @return the value of gameinfo.icon
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public String getIcon() {
        return icon;
    }

    /**
     * This method was generated by Abator for iBATIS.
     * This method sets the value of the database column gameinfo.icon
     *
     * @param icon the value for gameinfo.icon
     *
     * @abatorgenerated Wed Jul 28 14:13:02 CST 2010
     */
    public void setIcon(String icon) {
        this.icon = icon;
    }
    
    private String spName;

	public String getSpName() {
		return spName;
	}

	public void setSpName(String spName) {
		this.spName = spName;
	}
    
    private String languageName;

	public String getLanguageName() {
		return languageName;
	}

	public void setLanguageName(String languageName) {
		this.languageName = languageName;
	}

	public Integer getKindid() {
		return kindid;
	}

	public void setKindid(Integer kindid) {
		this.kindid = kindid;
	}

	public Integer getLev() {
		return lev;
	}

	public void setLev(Integer lev) {
		this.lev = lev;
	}
    
    
}