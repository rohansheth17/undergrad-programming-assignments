//package Rohan;

import java.util.*;

public class cg{
     
    public static void main(String[] args){
        
         Scanner in = new Scanner(System.in);
         Scanner out= new Scanner(System.in);
         System.out.println("Enter the number of three address coded expressions:");
         int n=in.nextInt();
         System.out.println("Enter the three address coded expressions in their order to generate code:");
         int i;
         String[] abc= new String[n];
         for(i=0;i<n;i++)
             abc[i]=out.nextLine();
        System.out.println("Enter the number of available registers:");
        int m=in.nextInt();
        
        String[] bcd=new String[m];
        for(i=0;i<m;i++)
            bcd[i]="-";
         System.out.println("Enter the number of program variables:");
        
        int s1=in.nextInt();    
        System.out.println("Enter the total number of program as well as temporary variables:");
        
        int s=in.nextInt();
        System.out.println("Enter all the variables in order(program variables first):");
        char[] def=new char[s];
        for(i=0;i<s;i++){
            def[i]=out.next().charAt(0);
        }
        String[] efg=new String[s];
         for(i=0;i<s;i++)
            efg[i]="-";
        
        for(i=0;i<5;i++)
            generatecode(i,abc,bcd,def,efg);
           
        System.out.println(bcd[0]+bcd[1]+bcd[2]);
        
       // System.out.println(bcd[0]+bcd[1]+bcd[2]);
        for(i=0;i<bcd.length;i++)
        {
             for(int j=0;j<s1;j++)
             {
                if(bcd[i].charAt(0)==def[j]){
                    System.out.println("STORE "+def[j]+",R"+Integer.toString(i+1));
                }   
             }
        }        
        
        
    }
    
    public static void generatecode(int p,String[] abc,String[] bcd,char[] def,String[] efg){
            int i=0,f=0,j=0,l=0,k=2,t=0;
            int[] a= new int[20];
            System.out.println(bcd[0]+bcd[1]+bcd[2]);
            if(abc[p].length()==5)
            {
                while(i<bcd.length){
                    if(bcd[i].equals(Character.toString(abc[p].charAt(k)))){
                       // System.out.println(bcd[i]);
                        //System.out.println(abc[p].charAt(k));
                            k+=2;
                            l++;
                        a[l-1]=f=i;
                        i=0;
                        if(l==2)
                            break;  
                    }
                    else if("-".equals(bcd[i])){
                        
                        bcd[i]=Character.toString(abc[p].charAt(k));
                        //System.out.println("kjghlihga;wohaohyaohiyioaroe");
                        System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(k));
                        k+=2;
                        l++;
                        a[l-1]=f=i;
                        i=0;
                        if(l==2)
                            break;
                    }
                    else
                        i++;
                } 
                if(l==0)
                {
                    t=0;
                    for(i=0;i<bcd.length;i++){
                        for(j=p+1;j<abc.length;j++){
                            if(bcd[i].charAt(0)!='-')
                                t=abc[j].indexOf(bcd[i].charAt(0));
                            if(t!=-1&&t!=0)
                                 break;   
                        }
                        if(t==-1||t==0){
                            bcd[i]=Character.toString(abc[p].charAt(k));
                            //System.out.println("kjghlihga;wohaohyaohiyioaroe");
                            System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(k));
                        k+=2;
                          l++;
                          a[l-1]=f=i;
                          if(l==2)
                              break;
                        }
                    }
                }
                if(l==1){
                    k=4;
                    for(i=0;i<bcd.length&&i!=f;i++){
                        for(j=p+1;j<abc.length;j++){
                            if(bcd[i].charAt(0)!='-')
                                t=abc[j].indexOf(bcd[i].charAt(0));
                            if(t!=-1&&t!=0)
                                 break;   
                        }
                        if(t==-1||t==0){
                            bcd[i]=Character.toString(abc[p].charAt(k));
                           // System.out.println("kjghlihga;wohaohyaohiyioaroe");
                            System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(k));
                          l++;
                          a[l-1]=i;
                          if(l==2)
                              break;
                        }
                    }
                }
               k=0;l=0;t=0;
             for(i=0;i<bcd.length;i++){
                 
                        for(j=p+1;j<abc.length;j++){
                            if(bcd[i].charAt(0)!='-')        
                                t=abc[j].indexOf(bcd[i].charAt(0));
                            if(t!=-1&&t!=0)
                                 break;   
                        }
                       // System.out.println("kjghlihga;wohaohyaohiyioaroe");
                       int y,g=0;
                        if(t==-1||t==0||p+1==abc.length){
                            for(y=0;y<bcd.length;y++){
                                 if((g=bcd[y].indexOf(abc[p].charAt(k)))!=-1)
                                 {  
                                     if(g==0){
                                         //System.out.println("kjghlihga;wohaohyaohiyioaroe");
                                        bcd[y]=bcd[y].substring(g+2,bcd[y].length());
                                        // System.out.println(bcd[y]);
                                        break;}
                                     else{
                                        // System.out.println("aohiyioaroe");
                                         bcd[y]=bcd[y].substring(0,g);
                                       //  System.out.println(bcd[y]);
                                         break;}       
                                 }
                                }
                            int temp=i;
                            if(p+1==abc.length){
                       //         System.out.println(y);
                               for(g=0;g<bcd.length;g++){
                                   if(g!=y){
                                       i=g;
                                       
                                       break;
                                   }
                               }
                            }
                           // System.out.println("kjghlihga;wohaohyaohiyioaroe");
                            t=0;
                            //System.out.println(bcd[i]);
                            //System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(k));
                            //System.out.println(bcd[i]);
                            switch(abc[p].charAt(3)){
                                case '+':   System.out.println("ADD R"+Integer.toString(i+1)+",R"+(a[0]+1)+",R"+(a[1]+1));
                                            break;
                                    
                                case '-':   System.out.println("SUB R"+Integer.toString(i+1)+",R"+(a[0]+1)+",R"+(a[1]+1));
                                            break;
                                case '*':   System.out.println("MUL R"+Integer.toString(i+1)+",R"+(a[0]+1)+",R"+(a[1]+1));
                                            break;
                                    
                                case '/':   System.out.println("DIV R"+Integer.toString(i+1)+",R"+(a[0]+1)+",R"+(a[1]+1));
                                            break;
                            }
                             bcd[i]=Character.toString(abc[p].charAt(k));
                             i=temp;
                          l++;
                          if(l==1)
                              break;
                        }
                    }
                if(l==0)
                {
                    for(i=0;i<bcd.length;i++){
                        
                    if("-".equals(bcd[i])){
                        for(int y=0;y<bcd.length;y++){
                                 if(bcd[y].charAt(0)==abc[p].charAt(k))
                                 {
                                     i=y;
                                     break;
                                 }
                                }
                       
                       // System.out.println(bcd[i]);
                       // System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(k));
                        switch(abc[p].charAt(3)){
                                case '+':   System.out.println("ADD R"+Integer.toString(i+1)+",R"+(a[0]+1)+",R"+(a[1]+1));
                                            break;
                                    
                                case '-':   System.out.println("SUB R"+Integer.toString(i+1)+",R"+(a[0]+1)+",R"+(a[1]+1));
                                            break;
                                case '*':   System.out.println("MUL R"+Integer.toString(i+1)+",R"+(a[0]+1)+",R"+(a[1]+1));
                                            break;
                                    
                                case '/':   System.out.println("DIV R"+Integer.toString(i+1)+",R"+(a[0]+1)+",R"+(a[1]+1));
                                            break;
                            }
                         bcd[i]=Character.toString(abc[p].charAt(k));
                        l++;
                        if(l==1)
                            break;
                    }
                }
                    
                }
            }
            else if(abc[p].length()==3){
             /*   for(i=0;i<bcd.length;i++){
                    
                }*/
                for(i=0;i<bcd.length;i++){
                    if(bcd[i].equals(Character.toString(abc[p].charAt(0))))
                        bcd[i]="-";
                    if(bcd[i].equals(Character.toString(abc[p].charAt(k)))){
                        bcd[i]=bcd[i].concat(",").concat(Character.toString(abc[p].charAt(0)));
                          System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(0));
                            l++;
                        if(l==1)
                            break;
                    
                    }
                    else if("-".equals(bcd[i])){
                        
                        bcd[i]=Character.toString(abc[p].charAt(k)).concat(",").concat(Character.toString(abc[p].charAt(0)));
                        System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(k));
                        System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(0));
                        l++;
                        if(l==1)
                            break;
                    }
                } 
                if(l==0)
                {
                    t=0;
                    for(i=0;i<bcd.length;i++){
                        for(j=p+1;j<abc.length;j++){
                            if(bcd[i].charAt(0)!='-')
                                t=abc[j].indexOf(bcd[i].charAt(0));
                            if(t!=-1&&t!=0)
                                 break;   
                        }
                        if(t==-1||t==0){
                            bcd[i]=Character.toString(abc[p].charAt(k)).concat(",").concat(Character.toString(abc[p].charAt(0)));
                          System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(k));
                          System.out.println("LOAD R"+Integer.toString(i+1)+","+abc[p].charAt(0));
                            l++;
                          if(l==1)
                              break;
                        }
                    }
                }                
            }              
    }           
}    
   
/*
Output:
Enter the number of three address coded expressions:
5
Enter the three address coded expressions in their order to generate code:
t=a-b
u=a-c
v=u+t
a=d
d=u+v
Enter the number of available registers:
3
Enter the number of program variables:
4
Enter the total number of program as well as temporary variables:
7
Enter all the variables in order(program variables first):
a
b
c
d
t
u
v
---

LOAD R1,a
LOAD R2,b
SUB R2,R1,R2

at-

LOAD R3,c
SUB R1,R1,R3

utc

ADD R2,R1,R2

uvc

LOAD R3,d
LOAD R3,a

uvd,a

ADD R1,R1,R2

dva

STORE d,R1
STORE a,R3
students@CELAB4-17:~/Downloads$ */
       
        
        
        
        
        
        
        
        
   
    
    
    
