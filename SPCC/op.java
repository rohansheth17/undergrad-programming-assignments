
package Rohan;

import java.util.*;


public class op
{

	public static void main(String[] args){

		Scanner input = new Scanner(System.in);
		Scanner no = new Scanner(System.in);
		/*System.out.println("Enter No. of Production");
		int n = no.nextInt();
		System.out.println("Enter Grammer");
		String[] prod = new String[20];
		for (int i=0; i<n; i++ )
			prod[i] = input.nextLine();*/
		char[] abc= new char[20];
		int i,j=0;
		System.out.println("Enter the number of operators:");
		int n= input.nextInt();
		System.out.println("Enter the operators:");
		for(i=0;i<n;i++)
			abc[i]=no.next().charAt(0);
		abc[n]='i';
		abc[n+1]='$';
		char[][] opTable= new char[n+3][n+3];
		opTable[0][0]='X';
		
		for(i=1;i<=n+2;i++)
		{
			opTable[0][i]=abc[j];
			opTable[i][0]=abc[j++];
		}
		System.out.println("Enter the grammar precedence using(>,<,-,A)");

		for(i=1;i<=n+2;i++)
		{
			for(j=1;j<=n+2;j++)
			{
				opTable[i][j]= no.next().charAt(0);
			}
		}

		for(i=0;i<=(n+2);i++)
		{
			for(j=0;j<=(n+2);j++)
			{
				System.out.print(opTable[i][j]+" ");
			}
			System.out.println();
                }
                
                System.out.println("Enter the input string to be parsed replacing every identifier as i(including $):");
                Scanner on= new Scanner(System.in);
                String bcd = on.nextLine();
                Stack st= new Stack();
                st.push('$');
               
               int ptr = 0;char c,ch,op,bc;
        do{       
                c= bcd.charAt(ptr);
                 ch= (char) st.peek();
                 
                 for(j=1;j<=(n+2);j++)
                     if(opTable[0][j]==c)
                         break;
                 for(i=1;i<=(n+2);i++)
                     if(opTable[i][0]==ch)
                         break;
                  if(j==(n+3)||i==(n+3))
                  {
                      System.out.println("String cannot be parsed");
                      System.exit(0);
                  }
                
                 op= opTable[i][j];
                 switch(op){
                     case '<':  System.out.println("jhhgfkwaugqufuqlgilug");
                                st.push(bcd.charAt(ptr));
                                if((ptr+1)!=bcd.length())
                                    ptr++;
                                break;
                     
                     case '>':  bc = (char)st.pop();
                                break;
                     
                     case '-': System.out.println("String cannot be parsed");
                                System.exit(0);
                     
                     case 'A': System.out.println("The string is successfully parsed.");
                                System.exit(0);
                                          
                                
                 } 
             
           }while(ptr<bcd.length());
                     
                   

}
        
}

/*
Output:

*/
