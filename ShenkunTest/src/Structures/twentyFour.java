package Structures;

 import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
   
 public class twentyFour {  
       
     static List lists = new ArrayList();  
     @SuppressWarnings("unused")  
     public static void main(String[] args){  
           
         int a=0,b=0,c=0,d=0;  
         //将a,b,c,d取由1到13的数字  
         for(int i=1;i<=13;i++){  
                 a = i;  
             for(int j=1;j<=13;j++){  
                     b = j;  
                 for(int k=1;k<=13;k++){  
                         c = k;  
                     for(int l=1;l<=13;l++){  
                             d = l;  
                              outs(a,b,c,d);  
                     }  
                 }     
             }  
        }  
     }  
       
     //将四个数带入计算,判断是否可以组成24,可以则输出  
     @SuppressWarnings("unused")  
     public static void outs(int a,int b,int c,int d){  
         int count = 0;  
         //两个数计算的结果是ab，三个数计算的结果是abc，最终结果是abcd  
         double ab=0, abc=0, abcd=0;  
         boolean todo = false;  
         String[] s = new String[]{"+","-","*","/"};  
         int[] content;  
         for(int i=0;i<s.length;i++){  
             ab = account(a,b,s[i]);  
             for(int j=0;j<s.length;j++){  
                 abc = account(ab,c,s[j]);  
                 for(int k=0;k<s.length;k++){  
                     abcd = account(abc,d,s[k]);  
                     if(abcd == 24){  
                         content = new int[]{a,b,c,d};  
                         //排序，这样利于比较  
                         Arrays.sort(content);  
                         count++;  
                         Iterator iter = lists.iterator();  
                         while(iter.hasNext()){  
                             int[] list = (int[])iter.next();  
                             if(list[0]==content[0]&list[1]==content[1]&list[2]==content[2]&list[3]==content[3]){  
                                 todo = true;  
                             }  
                         }  
                         if(!todo){  
                             lists.add(content);  
                             System.out.println(lists.size());  
                             System.out.println(a + " "+ b +" " + c + " " + d + "经过四则混合运算可以组成24");  
                         }  
                     }  
                 }         
             }  
         }     
     }  
       
     //具体的计算  
     public static double account(double i, double j, String d){  
         double k = 0;  
         if(d.compareTo("+")==0){  
             k = i + j;  
         }else if(d.compareTo("-")==0){  
             k = Math.abs(i - j);  
         }else if(d.compareTo("*")==0){  
             k = i * j;  
         }else if(d.compareTo("/")==0){  
            k = i / j;  
         }  
         return k;  
     }  
 }  