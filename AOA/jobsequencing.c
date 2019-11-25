#include <stdio.h>
#include <stdlib.h>

struct job{
	float p;
	int d;
};

void main() {

	struct job jb[10];
	int i,j,n,m,r;
	float sum=0;
	struct job temp;

	printf("Enter the no. of jobs\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter profit and deadline for %d job\n",i+1);
		scanf("%f%d",&jb[i].p,&jb[i].d);
	}

	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++)
		{
			if(jb[j].p<jb[j+1].p)
			{
				temp=jb[j];
				jb[j]=jb[j+1];
				jb[j+1]=temp;
			}
		}
	}

	m=0;
	for(i=0;i<n;i++)
	{
		if(m<jb[i].d)
			m=jb[i].d;
	}

	int *d=(int*)malloc( m *sizeof(int));
	
	for(i=0;i<m;i++)
	d[i]=0;


	for(i=0;i<n;i++){
		r=jb[i].d;

		while((r-1)>=0&&d[r-1]!=0)
			r--;

		if((r-1)>=0)
		{
			d[r-1]=jb[i].d;
			sum+=jb[i].p;
			printf("Selected job:\n");
			printf("profit:%f\tdeadline:%d\n",jb[i].p,jb[i].d);
		}
	}
	printf("table of deadline is\n");

	for(i=0;i<=m;i++)
		printf("%d\t\t",i);
	    printf("\n");
	for(i=0;i<m;i++)
		printf("\t%d\t",d[i]);
	    printf("\n");

	printf("total profit=%f",sum);
}


