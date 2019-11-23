#include<stdio.h>
#define o 50
int w[o],p[o],m,n,sum=0,knap[o][o],x[10];
void display()
{
int i,j;
for(i=0;i<=n;i++)
{
printf("\n");
for(j=0;j<=m;j++)
printf("%d\t",knap[i][j]);
}
}
void knapsack() 
{
int i,j;
for(i=0;i<=m;i++)
knap[0][i]=0;
for(i=1;i<=n;i++) 
{
for(j=0;j<=m;j++) 
{
if(j>=w[i])
knap[i][j]=knap[i-1][j]>knap[i-1][j-w[i]]+p[i]?knap[i-1][j]:knap[i-1][j-w[i]]+p[i];
else
knap[i][j]=knap[i-1][j]; 
}
}
for(i=1;i<=n;i++)
x[i]=0;
i=n;
j=m;
while(i>0 && j>0) 
{
if(knap[i][j]!=knap[i-1][j]) 
{
x[i]=1;
j=j-w[i]; 
}
i--; 
}
display();
printf("\nThe Final weights are:\n");
for(i=1;i<=n;i++) 
{
if(x[i]==1) 
{
printf("X%d=1\t",i);
sum=sum+p[i];
}
else
printf("X%d=0\t",i);
}
}
void main()
{
int i;
printf("Enter the number of items: ");
scanf("%d",&n);
printf("Enter the profit and weight of %d items: ",n);
for(i=1;i<=n;i++)
scanf("%d %d",&p[i],&w[i]);
printf("Enter the weight limit of knapsack: ");
scanf("%d",&m);
knapsack(m,n,w,p);
printf("\nTotal profit = %d",sum);
}
