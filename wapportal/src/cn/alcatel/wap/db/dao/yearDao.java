package cn.alcatel.wap.db.dao;

import java.util.List;
import java.util.ArrayList;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.text.*;

public class yearDao {
  public yearDao() {
  }

  /////////////////////////得到这个月的数据表名称
  public String getymName() {
    Date date = new Date(System.currentTimeMillis());
    int yearnum = 1900 + date.getYear();
    int monthnum = 1 + date.getMonth();
    String addDb = null;
    if (monthnum < 10) {
      addDb = String.valueOf(yearnum) + "-" + "0" + String.valueOf(monthnum);
    }
    else {
      addDb = String.valueOf(yearnum) + "-" + String.valueOf(monthnum);
    }
    return addDb;
  }
  /////////////////////////得到上个月数据表名称
 public String getlymName() {
   Date date = new Date(System.currentTimeMillis());
   return getYearMonth(date);
 }

  public static String getYearMonth(Date date) {
    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM");
    return sdf.format(date);
  }

  public static String getPreMonth(String yearmonth) {
    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM");
    Date date = null;
    try {
      date = (Date) sdf.parse(yearmonth);
    }
    catch (ParseException ex) {
    }
    long cur = date.getTime();
    cur= cur-1;
    date = new Date(cur);
    return getYearMonth(date);
  }
}
