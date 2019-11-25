#include<stdio.h>
void main()
{
	int i,j,n,w;
	int tol_prof=0;
	printf("Enter the no of items:");
	scanf("%d",&n);
	printf("Enter the Weight of Knapsack:");
	scanf("%d",&w);
	int mat[n+1][w+1];
	int prof[n],wt[n];
	for(i=1;i<=n;i++)
	{
		printf("Enter weight of %d:",i);
		scanf("%d",&wt[i]);
		printf("Enter its corresponding profit:");
		scanf("%d",&prof[i]);	
	}
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<w+1;j++)
		{
			mat[i][j]=0;
		}
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<w+1;j++)
		{
			if(wt[i]>j)
			{
				mat[i][j]=mat[i-1][j];
			}
			else
			{
				if(prof[i]+mat[i-1][j-wt[i]]>mat[i-1][j])
				{
					mat[i][j]=prof[i]+mat[i-1][j-wt[i]];
				}
				else
				{
					mat[i][j]=mat[i-1][j];
				}
			}
		}
	}
	printf("Matrix:\n");
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<w+1;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	i=n;
	j=w;
	tol_prof=mat[i][j];
	while(i!=0 || j!=0)
	{
		if(mat[i][j]>mat[i-1][j])
		{
			printf("%d is added to knapsack with value %d\n",i,prof[i]);
			j=j-wt[i];
			i=i-1;
		}
		else
		{
			i=i-1;
		}
	}
	printf("Total Profit:%d",tol_prof);
}
