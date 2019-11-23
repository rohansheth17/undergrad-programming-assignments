
package Rohan;

import java.util.*;

public class first{
	public static int[] list = new int[20];
	public static StringBuilder[] sb=new StringBuilder[100];

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Scanner no = new Scanner(System.in);
		System.out.println("Enter No. of Production");
		int n = no.nextInt();
		System.out.println("Enter Grammer");
		String[] prod = new String[20];
		for (int i=0; i<n; i++ )
			prod[i] = input.nextLine();

		char[] nt = new char[20];
		char[] tterm = new char[20];

		for (int i=0; i<n; i++ ) {
			nt[i] = prod[i].charAt(0);
			tterm[i] = prod[i].charAt(3);
		}

		
		for(int i = 0; i < sb.length; i++) {
			sb[i] = new StringBuilder("");
		}

		for (int i=0; i<n; i++ ) {
			if(list[i]==0)
				returnFirst(prod,nt,n,i);
		}
                
                //System.out.println(list[2]+list[0]);
                
                for (int i=n-1; i>=0; i--)
			for (int j=n-1; j>=0; j--)
				if(tterm[i]==nt[j])
					sb[i].append(sb[j]);
         
               int j;
                
                
               for(int i=0;i<n;i++)
                {
                 
                    int p=3,f=0;
                    do{
                            for(j=0;j<n;j++)
                            {
                              if(prod[i].charAt(p)==nt[j])
                                break;
                            }  
                            for(int k=0;k<prod[j].length();k++)
                            {
                                 if(prod[j].charAt(k)=='?')
                                      {
                                          //sb[i].append(sb[j]);
                                           p++;
                                           f=1;
                                           break;
                                      }
                            }
                            if(f==1 && p!=prod[i].length()){
                                for(j=0;j<n;j++)
                                {
                                    if(prod[i].charAt(p)==nt[j])
                                        sb[i].append(sb[j]);
                                }
                                
                            }  
                              
                    }while(p<prod[i].length());
                }
                
                
                String[] fst = new String[20];

                for (int i=0; i<n; i++ )
			fst[i]=sb[i].toString();
                
                
                
               
		System.out.print("\n");					//ANSWER DISPLAY
		for (int i=0; i<n; i++ ) {
			System.out.print("First("+prod[i].charAt(0)+")= { ");
			for (j=0; j<fst[i].length();j++ )
				if(j==fst[i].length()-1)
					System.out.print(fst[i].charAt(j));
				else
					System.out.print(fst[i].charAt(j)+" , ");
			System.out.print(" }\n");
		}
	}

	public static void returnFirst(String a1[], char a2[],int n1,int pno){
		int c1=-1,i,count1=0,c2;
		for (i=0; i<n1; i++)
			if(a1[pno].charAt(3)==a2[i]){
				c1=0;
                                list[pno]=1;
				break;
			}

		if(c1==0){
			list[i]=1;
			returnFirst(a1,a2,n1,i);
                }
		else{
			sb[pno].append(a1[pno].charAt(3));
			for (int j=0; j<a1[pno].length();j++ ) {
				if(a1[pno].charAt(j)=='/'){
					for (int k=0; k<n1; k++ )
						if (a1[pno].charAt(j+1)==a2[k])
							returnFirst(a1,a2,n1,k);
					
					for (int k=0; k<n1; k++ ) 
						if (a1[pno].charAt(j+1)!=a2[k])
							count1=1;

					if (count1==1)
						sb[pno].append(a1[pno].charAt(j+1));
				}
			}
		}
	}
}
/*
OUTPUT :
Enter No. of Production
5
Enter Grammer
E->TX
X->+TX/ε
T->FY
Y->*FY/ε
F->(E)/i

First(E)= { ( , i }
First(X)= { + , ε }
First(T)= { ( , i }
First(Y)= { * , ε }
First(F)= { ( , i }

*/