package servlets;
import java.io.File;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;


public class myfile {
  public myfile() {
  }
  /**
   * 删除文件
   * @param filePathAndName String 文件路径及名称 如c:/fqf.txt
   * @param fileContent String
   * @return boolean
   */
  public static int getFileSize(File file) {
  try {
  FileInputStream fis = new FileInputStream(file);
//这里可以转换下fis的大小格式，1024b = 1KB 1024KB = 1M，但是返回类型要改了，如果用int类型可能不精确
  return fis.available();
  } catch (FileNotFoundException e) {
  e.printStackTrace();
  } catch (IOException e) {
  e.printStackTrace();
  }
  return 0;
  }

public static int delFile(String filepath,String filename) {
    try{
      String filePath = filepath+filename;
      filePath = filePath.toString();
      java.io.File myDelFile = new java.io.File(filePath);
      myDelFile.delete();
      return 1;
    }
    catch (Exception e) {
      System.out.println("删除文件操作出错");
      e.printStackTrace();
      System.out.println("0000000000");
      return 0;
    }
  }
public static int existFile(String filepath,String filename){
try{
    String filePath = filepath+filename;
    filePath = filePath.toString();
    java.io.File myfileexist = new java.io.File(filePath);
     if(myfileexist.exists()){
         return 1;
     }
     else{
         return 0;
     }
  }
  catch (Exception e) {
    System.out.println("判断文件存在错误！");
    e.printStackTrace();
    return 0;
  }
}
}
