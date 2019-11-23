package Rohan;
import java.util.*;

public class clr1{
    
    public static void main(String[] args){
         
        Scanner in = new Scanner(System.in);
        
        String[][] abc= new String[20][20];
        System.out.println("Enter the number of states:");
        int n= in.nextInt();
        
        Scanner out = new Scanner(System.in);
        System.out.println("Enter the terminals first including '$' and then the nonterminals");
        
        String sym= out.nextLine();
        int i,j,k=0;
        String[] acd= new String[20];
         System.out.println("Enter no of unique grammar productions:");
         int m=in.nextInt();
         System.out.println("Enter the productions in order:");
         for(i=0;i<m;i++){
            acd[i]=out.nextLine();
         }
        
        for(i=1;i<=n;i++){
            
            abc[i][0]=Integer.toString(i-1);
        } 
        abc[0][0]="I";
        for(j=1;j<=sym.length();j++)
        {
            abc[0][j]=Character.toString(sym.charAt(j-1));  
        }
        System.out.println("Enter the input table for CRL1:");
        
        for(i=1;i<=n;i++)
        {
           for(j=1;j<=sym.length();j++){
               
               abc[i][j]=out.nextLine();    
           }
        }
        
        System.out.println("Your entered input table is:('-'for Blank and A for accept)");
        
        for(i=0;i<=n;i++){
            
            for(j=0;j<=sym.length();j++){
                
                System.out.print(abc[i][j]+"  ");
                
            }
            System.out.println();
        }
        Scanner sc=new Scanner(System.in);
        char ch;
        do{
            System.out.println("Enter the input string to be parsed with $:");

            String bcd= out.nextLine();
            parseString(n,bcd,sym,acd,abc);
            System.out.println("Parse another string?(y/n)");
            ch=sc.nextLine().charAt(0);
        }while(ch=='y'||ch=='Y');
    }   
    
    
    public static void parseString(int n,String bcd,String sym,String[] acd,String[][] abc){
        Object o=new Object();
        Stack st= new Stack();
        st.push(0);
       int p,s,t;
       char q;
       int j=0;
       //int v=0;
    do{ 
        System.out.println("STACK: "+Arrays.toString(st.toArray()));
        System.out.println("INPUT: "+bcd.substring(j,bcd.length()));     
       // System.out.println(v++);
       p=(int)st.peek();
       q=bcd.charAt(j);
       
       for(s=1;s<=n;s++)
           if(((int)abc[s][0].charAt(0)-48)==p)
               break;
       for(t=1;t<=sym.length();t++)
           if(abc[0][t].charAt(0)==q)
               break;
       if(s>n||t>sym.length())
       {
           System.out.println("String cannot be parsed any further");
           return;
       }
       else
       {
           String def=abc[s][t];
           
           switch(def.charAt(0)){
               
               case 's':    System.out.println("ACTION: "+def); 
                            st.push(q);
                            st.push((int)def.charAt(1)-48);
                            j++;
                            break;
                   
               case 'r':    System.out.println("ACTION: "+def); 
                            int f=((int)def.charAt(1)-48)-1;
                            System.out.println("PRODUCTION: "+acd[f]); 
                            char g=acd[f].charAt(0);
                            int h=acd[f].length()-3;
                            h*=2;
                            do{
                                o=st.pop();
                                h--;
                            }while(h>0);
                            h=(int)st.peek();
                            st.push(g);
                            for(s=1;s<=n;s++)
                            if(((int)abc[s][0].charAt(0)-48)==h)
                                break;
                           for(t=1;t<=sym.length();t++)
                            if(abc[0][t].charAt(0)==g)
                                break;
                           st.push((int)abc[s][t].charAt(0)-48);
                           break;
                           
               case '-':   System.out.println("String cannot be parsed any further");
                            return;
                            
                   
               case 'A':   System.out.println("String is successfully parsed");                            
                            return;
                     
           }
               
       }
    }while(true);  
     
    
    
    }  
}
        
/*Output:
Enter the number of states:
10
Enter the terminals first including '$' and then the nonterminals
ab$AS
Enter no of unique grammar productions:
3
Enter the productions in order:
S->AA
A->aA
A->b
Enter the input table for CRL1:
s3
s4
-
2
1
-
-
A
-
-
s6
s7
-
5
-
s3
s4
-
8
-
r3
r3
-
-
-
-
-
r1
-
-
s6
s7
-
9
-
-
-
r3
-
-
r2
r2
-
-
-
-
-
r2
-
-
Your entered input table is:('-'for Blank and A for accept)
I  a  b  $  A  S  
0  s3  s4  -  2  1  
1  -  -  A  -  -  
2  s6  s7  -  5  -  
3  s3  s4  -  8  -  
4  r3  r3  -  -  -  
5  -  -  r1  -  -  
6  s6  s7  -  9  -  
7  -  -  r3  -  -  
8  r2  r2  -  -  -  
9  -  -  r2  -  -  
Enter the input string to be parsed with $:
aaaabab$
STACK: [0]
INPUT: aaaabab$
ACTION: s3
STACK: [0, a, 3]
INPUT: aaabab$
ACTION: s3
STACK: [0, a, 3, a, 3]
INPUT: aabab$
ACTION: s3
STACK: [0, a, 3, a, 3, a, 3]
INPUT: abab$
ACTION: s3
STACK: [0, a, 3, a, 3, a, 3, a, 3]
INPUT: bab$
ACTION: s4
STACK: [0, a, 3, a, 3, a, 3, a, 3, b, 4]
INPUT: ab$
ACTION: r3
PRODUCTION: A->b
STACK: [0, a, 3, a, 3, a, 3, a, 3, A, 8]
INPUT: ab$
ACTION: r2
PRODUCTION: A->aA
STACK: [0, a, 3, a, 3, a, 3, A, 8]
INPUT: ab$
ACTION: r2
PRODUCTION: A->aA
STACK: [0, a, 3, a, 3, A, 8]
INPUT: ab$
ACTION: r2
PRODUCTION: A->aA
STACK: [0, a, 3, A, 8]
INPUT: ab$
ACTION: r2
PRODUCTION: A->aA
STACK: [0, A, 2]
INPUT: ab$
ACTION: s6
STACK: [0, A, 2, a, 6]
INPUT: b$
ACTION: s7
STACK: [0, A, 2, a, 6, b, 7]
INPUT: $
ACTION: r3
PRODUCTION: A->b
STACK: [0, A, 2, a, 6, A, 9]
INPUT: $
ACTION: r2
PRODUCTION: A->aA
STACK: [0, A, 2, A, 5]
INPUT: $
ACTION: r1
PRODUCTION: S->AA
STACK: [0, S, 1]
INPUT: $
String is successfully parsed
Parse another string?(y/n)
y
Enter the input string to be parsed with $:
abbba$
STACK: [0]
INPUT: abbba$
ACTION: s3
STACK: [0, a, 3]
INPUT: bbba$
ACTION: s4
STACK: [0, a, 3, b, 4]
INPUT: bba$
ACTION: r3
PRODUCTION: A->b
STACK: [0, a, 3, A, 8]
INPUT: bba$
ACTION: r2
PRODUCTION: A->aA
STACK: [0, A, 2]
INPUT: bba$
ACTION: s7
STACK: [0, A, 2, b, 7]
INPUT: ba$
String cannot be parsed any further
Parse another string?(y/n)
n
BUILD SUCCESSFUL (total time: 2 minutes 0 seconds)
*/























