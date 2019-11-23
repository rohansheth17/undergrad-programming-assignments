package Rohan;

import java.util.*;

public class co{
     
    public static void main(String[] args){
        
         Scanner in = new Scanner(System.in);
         Scanner out= new Scanner(System.in);
         System.out.println("Enter the number of expressions in your code:");
         int n=in.nextInt();
         System.out.println("Enter your code one expression at a time to optimize it:");
         int i;
         String[] abc= new String[n];
         for(i=0;i<n;i++)
             abc[i]=out.nextLine();
         
         for(i=0;i<n;i++){ 
             if(("-").equals(abc[i]))
                 continue;
             else
                optcode(i,abc);
         }
        for(i=0;i<n;i++){ 
             if(("-").equals(abc[i]))
                 continue;
             else
                opticode(i,abc);
         }
         System.out.println("The optimized code is as follows:");
         for(i=0;i<n;i++){ 
             if(("-").equals(abc[i]))
                 continue;
             else
                 System.out.println(abc[i]);
         }
    }
    
    public static void optcode(int p,String[] abc){
        
        int i,j,k,f=p,t1,t2,t3=0;
    
        for(i=p+1;i<abc.length;i++){
             
            if((abc[i].indexOf(abc[p].substring(2,abc[p].length())))!=-1){
              //  System.out.println("qwerty"+i);
              //  System.out.println("F isssssss"+f);
                if(i-f==1){
                    char ch=abc[i].charAt(0);
                   //  System.out.println(ch);
                    abc[i]="-"; 
                    for(k=i+1;k<abc.length;k++){
                     if(abc[k].indexOf(ch)==0){
                         break;
                     }
                     else if(abc[k].indexOf(ch)>0){
                         abc[k]=abc[k].replace(ch,abc[f].charAt(0));    
                     } 
                     }
                    }        
                
                else{ 
                for(j=i-1;j>f;j--){
                   // System.out.println(f);
                if(abc[p].length()==6){    
                    t1=99;t2=99;
                    
                 if(Character.isLetter(abc[p].charAt(2))) {
                     
                     t1=abc[j].indexOf(abc[p].charAt(2));
                     //System.out.println(t1);
                    } 
                 if(Character.isLetter(abc[p].charAt(4))){
                     t2=abc[j].indexOf(abc[p].charAt(4));
                   //  System.out.println("tdytkdktdku"+abc[j]);
                    //  System.out.println(t2);
                 }
                if(t1==0||t2==0){
                   t3=1;
                        break;
                }
                else if(t1!=0&&t2!=0&&j!=f+1){
                        continue;
                }
                 else if(t1!=0&&t2!=0&&j==f+1){
                  //   System.out.println(t1+""+t2);
                    char ch=abc[i].charAt(0);
                  //   System.out.println(ch);
                    abc[i]="-"; 
                    //f=i;
                    for(k=i+1;k<abc.length;k++){
                     if(abc[k].indexOf(ch)>0){
                         abc[k]=abc[k].replace(ch,abc[p].charAt(0));    
                     }
                     else if(abc[k].indexOf(ch)==0){
                         break;
                     }
                    }
                 }     
                }  
                else if(abc[p].length()==5){
                     
                      return;  
                }
                else if(abc[p].length()==4){
                    
                t1=99;
                 if(Character.isLetter(abc[p].charAt(2))) {
                     
                     t1=abc[j].indexOf(abc[p].charAt(2));
                    // System.out.println(t1);
                    } 
                 if(t1==0){
                      t3=1;
                   break;
                }
                else if(t1!=0&&j!=f+1){
                        continue;
                }
                else if(t1!=0&&j==f+1){
                    char ch=abc[i].charAt(0);
                     //System.out.println(ch);
                   // f=i;
                    abc[i]="-"; 
                    for(k=i+1;k<abc.length;k++){
                     if(abc[k].indexOf(ch)>0){
                         abc[k]=abc[k].replace(ch,abc[p].charAt(0));    
                     } 
                      else if(abc[k].indexOf(ch)==0){
                         break;
                     }
                    }
                 }
                }  
            }
                }
             if(t3==1){
                    t3=0;
                     break;   
                }
                else   
                   f=i;          
        }
         
 }
    }

    
public static void opticode(int p,String[] abc){ 

 int i,t1; 
        for(i=p+1;i<abc.length;i++){
            if((t1=abc[i].indexOf(abc[p].charAt(0)))>1&&t1<5)
                  break;
            if(abc[i].indexOf(abc[p].charAt(0))==-1){
                continue;     
            }
            if(abc[i].indexOf(abc[p].charAt(0))==0){
                abc[p]="-";
                break;
            }
    
        }    
}
}

/*
Output:
Enter the number of expressions in your code:
6
Enter your code one expression at a time to optimize it:
p=a+b;
a=c+b;
q=c+d;
r=a+b;
s=a+b;
t=r+s;
The optimized code is as follows:
p=a+b;
a=c+b;
q=c+d;
r=a+b;
t=r+r;
*/