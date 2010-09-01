package cn.alcatel.wap.db;

import java.io.*;
import java.util.*;

/**
 * <p>Title: Easy Picture Download Service</p>
 * <p>Description: Service to download pictures by WAP</p>
 * <p>Copyright: Copyright (c) Alcatel 2003</p>
 * <p>Company: Alcatel</p>
 * @author Cédric Pulrulczyk
 * @version 1.0
 */

public class Messages
    implements Serializable {

  public static String Id = "Messages";
  private String enterCode;
  private String title;
  private String back;
  private String download;
  private String next;
  private String EPicNotFound;
  private String ok;
  private String badBrowser;
  private String visitAlcatelSite;
  private String NoObjectExist;
  private String ImagesDisplayedinBandW;
  private String webBox;
  private String javaDisclaimer;
//  private String helpgameother;
//  private String helpother;
  private String videosEurosport;

  public Messages() {

  }

  public Messages(ResourceBundle res) {
    this();
    badBrowser=res.getString("badBrowser");
    enterCode = res.getString("enterCode");
    title = res.getString("title");
    back = res.getString("back");
    download = res.getString("download");
    next = res.getString("next");
    EPicNotFound = res.getString("EPicNotFound");
    NoObjectExist = res.getString("NoObjectExist");
    visitAlcatelSite= res.getString("visitAlcatelSite");
    ok=res.getString("Ok");
    ImagesDisplayedinBandW=res.getString("ImagesDisplayedinBandW");
    webBox=res.getString("WebBox");
    javaDisclaimer=res.getString("JavaDisclaimer");
//    helpother=res.getString("helpother");
//    helpgameother=res.getString("helpgameother");
    videosEurosport=res.getString("VideosEurosport");
  }

  private void writeObject(ObjectOutputStream oos) throws IOException {
    oos.defaultWriteObject();
  }

  private void readObject(ObjectInputStream ois) throws ClassNotFoundException,
      IOException {
    ois.defaultReadObject();
  }



  public String getEnterCode() {
    return enterCode;
  }

  public void setEnterCode(String enterCode) {
    this.enterCode = enterCode;
  }





  public String getTitle() {
    return title;
  }

  public void setTitle(String title) {
    this.title = title;
  }

  public String getBack() {
    return back;
  }

  public void setBack(String back) {
    this.back = back;
  }

  public String getDownload() {
    return download;
  }

  public void setDownload(String download) {
    this.download = download;
  }



  public String getNext() {
    return next;
  }

  public void setNext(String next) {
    this.next = next;
  }

  public String getEPicNotFound() {
    return EPicNotFound;
  }

  public void setEPicNotFound(String EPicNotFound) {
    this.EPicNotFound = EPicNotFound;
  }
  public String getOk() {
    return ok;
  }
  public void setOk(String ok) {
    this.ok = ok;
  }
  public String getBadBrowser() {
    return badBrowser;
  }
  public void setBadBrowser(String badBrowser) {
    this.badBrowser = badBrowser;
  }
  public String getVisitAlcatelSite() {
    return visitAlcatelSite;
  }
  public void setVisitAlcatelSite(String visitAlcatelSite) {
    this.visitAlcatelSite = visitAlcatelSite;
  }
  public String getNoObjectExist() {
    return NoObjectExist;
  }
  public void setNoObjectExist(String noObjectExist) {
    this.NoObjectExist = noObjectExist;
  }
  public String getImagesDisplayedinBandW() {
    return ImagesDisplayedinBandW;
  }
  public void setImagesDisplayedinBandW(String imagesDisplayedinBandW) {
    this.ImagesDisplayedinBandW = imagesDisplayedinBandW;
  }
  public String getWebBox() {
    return webBox;
  }
  public void setWebBox(String webBox) {
    this.webBox = webBox;
  }
  public String getJavaDisclaimer() {
    return javaDisclaimer;
  }
//  public String getHelpgameother() {
//   return helpgameother;
// }
// public String getHelpother() {
//    return helpother;
//  }
  public void setJavaDisclaimer(String javaDisclaimer) {
    this.javaDisclaimer = javaDisclaimer;
  }
  public String getVideosEurosport() {
    return videosEurosport;
  }
  public void setVideosEurosport(String videosEurosport) {
    this.videosEurosport = videosEurosport;
  }

}
