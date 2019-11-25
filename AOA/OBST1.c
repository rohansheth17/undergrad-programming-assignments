/*
NAME: ROHAN SHETH  BATCH: C  ROLLNO: 51
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define N 99


void output(int n,int r[][n+1],int i,int j)
{

    if(i==j)
        return;
    else
    {
        printf("\nRoot=%d\n",r[i][j]);
        printf("Left child of %d:\n",r[i][j]);
        int k=r[i][j];
        output(n,r,i,k-1);
         printf("Right child of %d:\n",r[i][j]);
         output(n,r,k,j);

    }
}


int findMin(int n,int c[][n+1],int i,int j,int *l)
{
    int k;
    int min=999;
    for(k=i+1;k<=j;k++)
    {
        if(min>(c[i][k-1]+c[k][j]))
        {
            min=c[i][k-1]+c[k][j];
            *l=k;
        }
    }
    return min;


}


void main()
{
	int n,i,j,k,l;
	static int x=1;
	printf("\nEnter the no. of identifiers:\n");
	scanf("%d",&n);
	int p[n+1],q[n+1];
	printf("\nEnter the successes of finding respective nodes:\n");
	for(i=1;i<n+1;i++)
	{
		printf("p%d:\t",i);
		scanf("%d",&p[i]);
	}
	printf("\nEnter the successes of finding failure nodes:\n");
	for(i=0;i<n+1;i++)
	{
		printf("q%d:\t",i);
		scanf("%d",&q[i]);
	}
	int w[n+1][n+1],c[n+1][n+1],r[n+1][n+1];
	for(i=0;i<n+1;i++)
	{
		w[i][i]=q[i];
		r[i][i]=0;
		c[i][i]=0;
	}
	for(j=0;j<n+1;j++)
	{
		for(i=0;i<j;i++)
		{
			w[i][j]=p[j]+q[j]+w[i][j-1];
		}
	}
	printf("\nThe weight matrix is as follows:\n");
	for(j=0;j<n+1;j++)
	{
		for(i=0;i<=j;i++)
		{
			printf("%d\t",w[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------------------");
	do
    {
        for(j=0;j<n+1;j++)
        {
            for(i=0;i<j;i++)
            {
                if(j-i==x)
                {
                    c[i][j]=findMin(n,c,i,j,&l)+w[i][j];
                    r[i][j]=l;
                }

            }
        }
        x++;
    }while(x<=n);
    printf("\nThe cost matrix is as follows:\n");
    for(j=0;j<n+1;j++)
	{
		for(i=0;i<=j;i++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------------------");
	printf("\nThe root matrix is as follows:\n");
    for(j=0;j<n+1;j++)
	{
		for(i=0;i<=j;i++)
		{
			printf("%d\t",r[i][j]);
		}
		printf("\n");
	}
	i=0;
	j=n;
    printf("\n------------------------------------\n");
    printf("The root node is :%d\n",r[i][j]);
	printf("The cost is :%d\n",c[i][j]);
	//display(0,n);
	output(n,r,i,j);
}

/*
OUTPUT:


Enter the no. of identifiers:
4

Enter the successes of finding respective nodes:
p1:     3
p2:     3
p3:     1
p4:     1

Enter the successes of finding failure nodes:
q0:     2
q1:     3
q2:     1
q3:     1
q4:     1

The weight matrix is as follows:
2
8       3
12      7       1
14      9       3       1
16      11      5       3       1
------------------------------------------
The cost matrix is as follows:
0
8       0
19      7       0
25      12      3       0
32      19      8       3       0
------------------------------------------
The root matrix is as follows:
0
1       0
1       2       0
2       2       3       0
2       2       3       4       0

------------------------------------
The root node is :2
The cost is :32

Root=2
Left child of 2:
Root=1

Left child of 1:
Right child of 1:
Right child of 2:
Root=3

Left child of 3:
Right child of 3:
Root=4

Left child of 4:
Right child of 4:

Process returned 4 (0x4)   execution time : 8.740 s
Press any key to continue.


*/










