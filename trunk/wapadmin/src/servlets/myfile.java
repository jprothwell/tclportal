package servlets;
import java.io.File;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;


public class myfile {
  public myfile() {
  }
  /**
   * ɾ���ļ�
   * @param filePathAndName String �ļ�·�������� ��c:/fqf.txt
   * @param fileContent String
   * @return boolean
   */
  public static int getFileSize(File file) {
  try {
  FileInputStream fis = new FileInputStream(file);
//�������ת����fis�Ĵ�С��ʽ��1024b = 1KB 1024KB = 1M�����Ƿ�������Ҫ���ˣ������int���Ϳ��ܲ���ȷ
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
      System.out.println("ɾ���ļ���������");
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
    System.out.println("�ж��ļ����ڴ���");
    e.printStackTrace();
    return 0;
  }
}
}
