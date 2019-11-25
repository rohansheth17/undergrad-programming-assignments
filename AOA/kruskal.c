#include<stdio.h>
#define INF 999
typedef struct edge{
int p,c;
int w;
}edge;
void creategraph(int a[50][50],int m){
	int i,j,x,y=1;
	for(i=0;i<m;i++){
		for(j=0;j<m;j++)
		a[i][j]=INF;
	}
		for(i=0;i<m;i++)
		{
			for(j=y;j<m;j++)
			{
				printf("Does edge between %c and %c exist\n1 yes\n2.no\n",i+65,j+65);
				scanf("%d",&x);
				if(x==1){
					printf("Enter its cost\n");
					scanf("%d",&a[i][j]);
					a[j][i]=a[i][j];
				}
				else 
				  continue;
		}
		y++;
	}
}
int collectedge(int a[50][50],edge e[],int m){
	int k=0,i,j;
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			if(a[i][j]!=INF){
				e[k].p=i;
				e[k].c=j;
				e[k].w=a[i][j];
				k++;
			}
		}
	}
	return k;
}
int kruskal(int a[50][50],int m){
	edge e[50],temp;
	int parent[50];
	int n,i,j,cost=0,c,p,q;
	n=collectedge(a,e,m);
	for(i=0;i<n-1;i++){
		for(j=0;j<n;j++){
			if(e[j].w>e[j+1].w){
				temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
			}
		}
	}
	for(i=0;i<m;i++)
	parent[i]=-1;
		for(c=0,i=0;c<m-1;i++){
			p=e[i].p;
			q=e[i].c;
			while(parent[p]!=-1)
				p=parent[p];
			while(parent[q]!=-1)
			    q=parent[q];
			    if(p!=q){
			    	parent[q]=p;
			    	cost+=e[i].w;
			    	printf("Selected edge\n");
			    	printf("%c\t%c\n",e[i].p+65,e[i].c+65);
			    	c++;
				}
		   }
		   return cost;
	}
void main(){
	int a[50][50];
	int m,cost;
	printf("Enter the no. of nodes\n");
	scanf("%d",&m);
	creategraph(a,m);
	cost=kruskal(a,m);
	printf("Total cost=%d\n",cost);
}

