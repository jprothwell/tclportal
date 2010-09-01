package cn.funstar.wap.util;

import java.util.*;

public class Message {
  private String title;
  private String home;
  private String back;
  private String next;
  private String build;
  private String prev;
  private String busy;
  public Message(String language) {
    try {
      ResourceBundle res = ResourceBundle.getBundle("cn.funstar.wap.message." +
          language);
      if (res == null) {
        res = ResourceBundle.getBundle("cn.funstar.wap.message.en");
      }
      if (res != null) {
        title = getStr(res.getString("title"), "UTF-8");
        home = getStr(res.getString("home"), "UTF-8");
        back = getStr(res.getString("back"), "UTF-8");
        prev = getStr(res.getString("prev"), "UTF-8");
        next = getStr(res.getString("next"), "UTF-8");
        build = getStr(res.getString("build"), "UTF-8");
        busy = getStr(res.getString("busy"), "UTF-8");
      }
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }

  public String home() {
    return home;
  }

  public String back() {
    return back;
  }

  public String prev() {
    return prev;
  }

  public String next() {
    return next;
  }

  public String build() {
    return build;
  }

  public String busy() {
    return busy;
  }

  public String title() {
    return title;
  }

  private static String getStr(String str, String encode) {
    try {
      String temp_p = str;
      byte[] temp_t = temp_p.getBytes("ISO8859-1");
      String temp = new String(temp_t, encode);
      return temp;
    }
    catch (Exception e) {}
    return null;
  }

}
