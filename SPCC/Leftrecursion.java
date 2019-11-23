package Rohan;

import java.util.*;

public class Leftrecursion{


	public static void main(String[] args) {
		System.out.println("Enter no of productions in the grammar");
                Scanner no = new Scanner(System.in);
		int n = no.nextInt();
                String[] gram = new String[20];
		Scanner p = new Scanner(System.in);
		System.out.println("Enter the grammar");
		for (int i=0; i<n ;i++) {
			gram[i]=p.nextLine();
		}
                System.out.println("Eliminating recursion...");
		Indirect idr =new Indirect();
		idr.Indirect(gram,n);
	}
}

class Direct{
	String grammer1;
	void Direct(String gram1){
		grammer1 = gram1;
		int c=0,c1=0;
		int pos1[]= new int[50];
		for (int i=0;i<grammer1.length() ;i++ ) {
			if(grammer1.charAt(i)=='/'){
				c++;
				pos1[c1++]=i;
			}
		}
		System.out.print(grammer1.charAt(0)+"->");
		// for (int i; i<c; i++) {

			// System.out.println("test"+grammer1.charAt(pos1[1]+1));

		// }
		for (int i=0; i<c; i++) {
			if(grammer1.charAt(pos1[i]+1)!=grammer1.charAt(0)){
				// int t1=indexOf(charAt(pos1[i]+1)),t2=indexOf(charAt(pos1[i+1]-1));
				int t1=pos1[i]+1,t2=pos1[i+1];
				if (i==(c-1))
					t2=grammer1.length();
							// System.out.println(t1+" "+t2);
				System.out.print(""+grammer1.substring(t1,t2)+grammer1.charAt(0)+"'");
				if(i!=((c-1)))
					System.out.print("/");
			}
			
		}
		System.out.println("");



		System.out.print(grammer1.charAt(0)+"'->");
		int t1=4,t2=pos1[0];
		System.out.print(""+grammer1.substring(t1,t2)+grammer1.charAt(0)+"'/");


		for (int i=0; i<c; i++) {
			if(grammer1.charAt(pos1[i]+1)==grammer1.charAt(0)){
				t1=pos1[i]+2;
				t2=pos1[i+1];
				System.out.print(""+grammer1.substring(t1,t2)+grammer1.charAt(0)+"'/");
			}
			
		}
		System.out.print("є");
		System.out.println("");


	}


}

class Indirect{
	void Indirect(String[] gram2,int n){		
		String[] prod = new String[20];
		prod = gram2;
		System.out.println("Answer:");
                System.out.println(prod[0]);

     
		for (int i=1; i<n; i++ ) {
                    
			char temp = prod[i-1].charAt(0);
			int pos2[]= new int[50];
			int ct1=0,ct2=0;
			for (int j=0;j<prod[i-1].length() ;j++ ) {
				if(prod[i-1].charAt(j)=='/'){
					ct1++;			
					pos2[ct2++]=j;		
				}
			}
			String[] tempprod = new String[20];
			int t1=3,t2=pos2[0],k=0,m=0,l=0;
			for (int j=0;j<=ct1 ;j++ ) {
				if (j!=0) {
					t1=pos2[j-1]+1;
					if (j==ct1)
                                            t2=prod[i-1].length();
					else
                                            t2=pos2[j];
					
				}
				tempprod[j]=prod[i-1].substring(t1,t2);
                                k++;
                            // System.out.println("temp "+tempprod[j]);

			}

			int t;
                         t = prod[i].indexOf(temp);
                if(t!=-1){         
                       String tempc;
                    //   System.out.println(prod[i].charAt(t));
                    tempc = Character.toString(prod[i].charAt(t));
                 //   System.out.println(tempc);
                  //  System.out.println(prod[i].length());
                      for(m=t;m<prod[i].length();m++){
                          if(prod[i].charAt(m)=='/') 
                             break; 
                        }
                       // System.out.println(t);
                        //System.out.println(m);
                        String abc = prod[i].substring(t,m);
                      //  System.out.println(abc);
                        prod[i]=prod[i].replace(abc+"/","");
                       // System.out.println(prod[i]);
                        String[] bcd=  new String[20];
                        
                       for(l=0;l<k;l++)
                        {
                            bcd[l]= abc.replace(tempc,tempprod[l]);
                        }
                      // System.out.println(bcd[1]);
                       l=0;
                        while(l<k)
                        {
                            prod[i]=prod[i].concat("/").concat(bcd[l++]);
                        }
                }        
                 if(prod[i].charAt(0)==prod[i].charAt(3)){
				Direct dirr = new Direct();
				dirr.Direct(prod[i]);
                                
			}
		if(prod[i].charAt(0)!=prod[i].charAt(3))
				System.out.println(prod[i]);
		
	}
}

}
/*
Output:
Enter no of productions in the grammar
4
Enter the grammar
S->Aab/a
A->Ab/Sa/b
B->Bb/ab
C->ba
Eliminating recursion...
Answer:
S->Aab/a
A->bA'/aaA'
A'->bA'/abaA'/є
B->abB'
B'->bB'/є
C->ba
BUILD SUCCESSFUL (total time: 31 seconds)
*/
