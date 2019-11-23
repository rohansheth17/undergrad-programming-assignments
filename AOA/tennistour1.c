/*NAME: ROHAN SHETH  ROLLNO: 51  BATCH: C
*/


#include<stdio.h>
void tournament(int n,int a[100][100])
{
	int i,j,flag,x;
	if(n==2)
	{
	  a[0][0]=2;
	  a[1][0]=1;
	}

	else
	{
	  tournament(n/2,a);
	  for(i=n/2;i<n;i++)
		  for(j=0;j<n/2-1;j++)
			  a[i][j]=a[i-n/2][j]+n/2;
      x=1;
      for(i=n/2;i<n;i++)
	     {   flag=1;
	    	 for(j=n/2-1;j<n;j++)
	    	 {
	    		 if(flag)
	    		 {a[i][j]=x++;
	    		 }
	    		 else
	    			 a[i][j]=a[i-n/2][j-n/2];
	    		 flag=0;
	    	 }
	     }
	     x=n/2+1;
	     for(i=0;i<n/2;i++)
	     {int flag=1;
	    	 for(j=n/2-1;j<n;j++)
	    	 {
	    		if(flag)
	    			a[i][j]=x++;
	    		else
	    			a[i][j]=a[i+n/2][j-n/2];
	    		flag=0;

	    	 }
	    }
	}
}

void main()
{

	int n,i,j,flag,x=1;
	printf("Enter the no of players(as a power of two):");
    scanf("%d",&n);
   int a[100][100];
   int f[100][100];
    tournament(n,a);
  printf("\nSchedule of the tennis tournament:\n");
  for(i=0;i<n-1;i++)
  {
      if(i==0)
         printf("  %d\t",i+1);
      else
         printf("%d\t",i+1);
  }
   printf("\n");
  for(i=0;i<n;i++)
  {
      flag=1;
	  for(j=0;j<n-1;j++)
	  {
	      if(flag)
            printf("%d|",x++);
		  printf("%d\t",a[i][j]);
		  flag=0;
	  }
	  printf("\n");

  }

 /* for(i=0;i<n;i+=2)
  {
  	for(j=0;j<n-1;j++)
  	{
  		printf("\nPlayer %d plays with player %d on day %d\n",i+1,a[i][j],j+1);
  	}

  }*/

  for(i=0;i<n;i++){
  	for(j=0;j<n;j++)
  	f[i][j]=0;
  }
  for(i=0;i<n;i++){
  	for(j=0;j<n-1;j++){
  		if(f[a[i][j]-1][j]!=1)
  		    printf("Player %d plays with player %d on day %d",i+1,a[i][j],j+1);
  		printf("\n");
  		f[i][j]=1;
  	}
  	printf("\n");
  }


}


/*Output:

Enter the no of players(as a power of two):8

Schedule of the tennis tournament:
  1     2       3       4       5       6       7
1|2     3       4       5       6       7       8
2|1     4       3       6       5       8       7
3|4     1       2       7       8       5       6
4|3     2       1       8       7       6       5
5|6     7       8       1       2       3       4
6|5     8       7       2       1       4       3
7|8     5       6       3       4       1       2
8|7     6       5       4       3       2       1

Player 1 plays with player 2 on day 1

Player 1 plays with player 3 on day 2

Player 1 plays with player 4 on day 3

Player 1 plays with player 5 on day 4

Player 1 plays with player 6 on day 5

Player 1 plays with player 7 on day 6

Player 1 plays with player 8 on day 7

Player 3 plays with player 4 on day 1

Player 3 plays with player 1 on day 2

Player 3 plays with player 2 on day 3

Player 3 plays with player 7 on day 4

Player 3 plays with player 8 on day 5

Player 3 plays with player 5 on day 6

Player 3 plays with player 6 on day 7

Player 5 plays with player 6 on day 1

Player 5 plays with player 7 on day 2

Player 5 plays with player 8 on day 3

Player 5 plays with player 1 on day 4

Player 5 plays with player 2 on day 5

Player 5 plays with player 3 on day 6

Player 5 plays with player 4 on day 7

Player 7 plays with player 8 on day 1

Player 7 plays with player 5 on day 2

Player 7 plays with player 6 on day 3

Player 7 plays with player 3 on day 4

Player 7 plays with player 4 on day 5

Player 7 plays with player 1 on day 6

Player 7 plays with player 2 on day 7

*/

/*
Enter the no of players(as a power of two):8

Schedule of the tennis tournament:
  1     2       3       4       5       6       7
1|2     3       4       5       6       7       8
2|1     4       3       6       5       8       7
3|4     1       2       7       8       5       6
4|3     2       1       8       7       6       5
5|6     7       8       1       2       3       4
6|5     8       7       2       1       4       3
7|8     5       6       3       4       1       2
8|7     6       5       4       3       2       1
Player 1 plays with player 2 on day 1
Player 1 plays with player 3 on day 2
Player 1 plays with player 4 on day 3
Player 1 plays with player 5 on day 4
Player 1 plays with player 6 on day 5
Player 1 plays with player 7 on day 6
Player 1 plays with player 8 on day 7


Player 2 plays with player 4 on day 2
Player 2 plays with player 3 on day 3
Player 2 plays with player 6 on day 4
Player 2 plays with player 5 on day 5
Player 2 plays with player 8 on day 6
Player 2 plays with player 7 on day 7

Player 3 plays with player 4 on day 1


Player 3 plays with player 7 on day 4
Player 3 plays with player 8 on day 5
Player 3 plays with player 5 on day 6
Player 3 plays with player 6 on day 7




Player 4 plays with player 8 on day 4
Player 4 plays with player 7 on day 5
Player 4 plays with player 6 on day 6
Player 4 plays with player 5 on day 7

Player 5 plays with player 6 on day 1
Player 5 plays with player 7 on day 2
Player 5 plays with player 8 on day 3






Player 6 plays with player 8 on day 2
Player 6 plays with player 7 on day 3





Player 7 plays with player 8 on day 1
*/








