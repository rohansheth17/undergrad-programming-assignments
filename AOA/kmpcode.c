

#include<stdio.h>
void prefix(int p[],int f[],int m)
{
	int i=1,j=0;
	f[0]=0;	
	while(i<m)
	{
		if(p[j]==p[i])
		{
			f[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
			j=f[j-1];
		else
		{
		f[i]=0;
		i++;
		}
	}
}

void main()
{
	int m,n,i,j;
	printf("Enter the length of String to be matched");
	scanf("%d",&n);
	int str[n];
	printf("Enter the string");
	for(i=0;i<n;i++)
		scanf("%d",&str[i]);
	printf("Enter the length of pattern");
	scanf("%d",&m);
	int p[m];
	int f[m];
	printf("Enter the pattern");
	for(j=0;j<m;j++)
		scanf("%d",&p[j]);
	prefix(p,f,m);
	for(i=0;i<m;i++)
		printf("f(%d)=%d\n",i,f[i]);
	int v=0,k=0;
	while(k<n)
	{	
		if(str[k]==p[v])
		{
		k++;
		v++;
		}
		if(str[k]!=p[v]&&v<m)
		{
		v=f[v-1];
		if(v==0)
			k++;
		}
		if(v==(m-1))
		{
		printf("Found pattern at %d\n",k-m+1);
		v=f[v-1];
		}
		else
		printf("String not found");
	}
}	

/*OUTPUT:

Enter the length of String to be matched
12
Enter the string
1
1
2
1
1
4 
4
1
1
2
1
1
Enter the length of pattern
5
Enter the pattern
1
1
2
1
1
f(0)=0
f(1)=1
f(2)=0
f(3)=1
f(4)=2
Found pattern at 0
Found pattern at 7
*/	
		
