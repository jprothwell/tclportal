/*
 * Created on 2009-7-15
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package cn.alcatel.wap.db;

/**
 * @author gonglin.shi
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class DBInfo {
  /**/
  public final static String[] LG_INFO={"en","fr"};//语言版本
  public final static String[] WAP_INFO={"1.2","2.0","3G"};//Wap版本
  public final static String[] NET_INFO={"C网","G网"};//网络信息版本
  public final static String[] MENU_GROUP={"images","sounds","videos","java","news","spinfo"};//栏目组
  public final static int PAGE_PER_NUM=1;//网络信息版本
  public final static String[] PAGE_KIND={"首页","图片","铃声","视频","游戏","游戏说明","资讯","资讯说明","sp业务"};//网络信息版本
  public final static String[] IMAGE_SIZE={"128*128","128*160","176*220","220*176","240*320","320*240"};//屏幕尺寸
  /*图片基本信息*/
  public final static String[] FILE_SIZE={"128128","128160","176220","220176","240320","320240"};//用于建立目录和屏幕尺寸相对应
  public final static String[] IMAGE_KINDID={"images","frames","animations"};//图片类别
  /*铃声基本信息*/
  public final static String[] RING_TYPEID={"mp3","mid","wav","mmf","amr"};//铃声类型
  public final static String[] RING_KINDID={};//铃声类别
  /*视频基本信息*/
  public final static String[] VIDEO_TYPEID={"3gp","mp4"};
  public final static String[] VIDEO_KINDID={};//视频类别
  /*游戏基本信息*/
  public final static String[] GAME_TYPEID={"game","Aplication"};
  public final static String[] GAME_KINDID={};
    /*新闻基本信息*/
  public final static String[] NEWS_KINDID={};//视频类别
  //Url 地址
  public final static String URL_NAME="../../wapportal/objectsdw/";
}
