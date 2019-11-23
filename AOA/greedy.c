/*
NAME:ROHAN SHETH  BATCH:C  ROLLNO: 51
*/


#include<stdio.h>

typedef struct knapSack
{
	int p,w;
}kSack;


void init(kSack a[],int n)
{
	int i;
	printf("\nEnter the weights and profits of all the objects:\n");
	for(i=0;i<n;i++)
		scanf("%d\n%d\n",&a[i].w,&a[i].p);
	printf("\ninit done\n");
}


void sort(kSack a[],int n)
{
	int i,j;
	int temp1,temp2;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((a[j].p/a[j].w)<(a[j+1].p/a[j+1].w))
			{
				temp1=a[j].p;
				temp2=a[j].w;
				a[j].p=a[j+1].p;
				a[j].w=a[j+1].w;
				a[j+1].p=temp1;
				a[j+1].w=temp2;
			}
		}
	}
	printf("Sorted weights:\n");
	for(i=0;i<n;i++)
		printf("%d\t%d\t%d\n",a[i].w,a[i].p,a[i].p/a[i].w);
}


int findProfit(kSack a[],int n,int cap)
{
	int m,profit=0;
	int i,c=0;
	for(i=0;i<n;i++)
	{
		int w=a[i].w;
		if(c+w<=cap)
		{
			profit+=a[i].p;
			c+=w;
			printf("\nprofit:%d\tweight:%d\n",a[i].p,a[i].w);
		}
		else if(c<cap)
		{
			m=(a[i].p/a[i].w)*(cap-c);
			profit+=m;
			printf("\n------------------------\n");
			printf("\nprofit:%d\tweight:%d\n",m,cap-c);
			break;
			
		}
	}
	return profit;
}	



void main()
{
	int profit;
	kSack a[20];
	int n,c;
	printf("\nEnter the no.of objects:\n");
	scanf("%d",&n);
	printf("\nEnter the capacity of the knapsack:\n");
	scanf("%d",&c);
	init(a,n);
	sort(a,n);
	profit=findProfit(a,n,c);
	printf("\n--------------------\n");
	printf("\nProfit:%d\n",profit);
}


/*
OUTPUT:
Enter the no.of objects:
5

Enter the capacity of the knapsack:
10

Enter the weights and profits of all the objects:
4
12
8
32
2
40
6
30
1
50
w

init done
Sorted weights:
1	50	50
2	40	20
6	30	5
8	32	4
4	12	3

profit:50	weight:1

profit:40	weight:2

profit:30	weight:6

------------------------

profit:4	weight:1

--------------------

Profit:124
compdept@CELAB4-13:~/Desktop$ 


*/
	
