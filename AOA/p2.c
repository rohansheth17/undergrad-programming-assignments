/*
NAME: ROHAN SHETH  BATCH: C  ROLLNO: 51
*/

#include<stdio.h>
#include<stdlib.h>
# define INF 999
int N;

typedef struct Edge
{
    int p,c;
    int w;
}Edge;


int collectEdges(int a[][N],Edge e[])
{
    int i,j,k=0;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(a[i][j]!=INF)
            {
                e[k].p=i;
                e[k].c=j;
                e[k].w=a[i][j];
                k++;
            }
        }

    }
    return k;
}

void sortEdges(Edge e[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(e[j].w>e[j+1].w)
            {
                temp=e[j].w;
                e[j].w=e[j+1].w;
                e[j+1].w=temp;

            }
        }
    }

}

void createGraph(int a[][N])
{
	int i,j,f=0;
	for(i=0;i<N;i++)
	     for(j=0;j<N;j++)
		a[i][j]=INF;
        for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			printf("\nIs the edge between %d and %d connected(y=1/n=0)?\n",i+1,j+1);
			scanf("%d",&f);
			if(f)
			{
			     printf("\nEnter that edge's cost:\n");
		             scanf("%d",&a[i][j]);
			     a[j][i]=a[i][j];
                         }
                 }
        }
}


int minNode(int dist[],int visited[])
{
	int i,min=INF,m=0;
	for(i=0;i<N;i++)
	{
		if(!visited[i]&&dist[i]<min)
		{
		    min=dist[i];
		    m=i;
		}
	}
	return m;
}

int prim(int start,int a[][N],int prev[],int visited[])
{
	int i,j,d,sum=0;
	int dist[N];
	for(i=0;i<N;i++)
	{
	    dist[i]=INF;
        }
	dist[start]=0;
	visited[start]=1;
	for(j=1;j<N;j++)
	{
		for(i=0;i<N;i++)
		{
		    d=a[start][i];
		    if(!visited[i]&&d<dist[i])
		    {
			dist[i]=d;
			prev[i]=start;
            }

        }
		start=minNode(dist,visited);
		sum+=dist[start];
		visited[start]=1;
		 printf("\n%d->%d\n",prev[start]+1,start+1);
	}
	return sum;
}

int Kruskal(int a[][N])
{
    Edge e[20];
    int n= collectEdges(a,e);
    printf("\n%d\n",n);
    sortEdges(e,n);
    int parent[N],cost=0;
    int i,j;

    for(i=0;i<N;i++)
    {
        parent[i]=-1;
    }
    for(j=0,i=0;j<N-1;i++)
    {
         int p=e[i].p;
         int c=e[i].c;
        while(parent[p]!=-1)
        {
            p=parent[p];
        }
        while(parent[c]!=-1)
        {
            c=parent[c];
        }
        if(p!=c)
        {
            parent[c]=p;
            cost+=e[i].w;
            printf("%d\t%d\n",(e[i].p)+1,(e[i].c)+1);
            j++;
        }
    }
    return cost;
}


void main()
{
	int i,j,ch,minCost;
	printf("\nEnter the no of vetices:\n");
	scanf("%d",&N);
	int a[N][N],visited[N],prev[N];
    createGraph(a);
    printf("\nThe cost matrix is:\n");
    for(i=0;i<N;i++)
    {
            for(j=0;j<N;j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
    }
    printf("\nWhich algorithm?\nEnter 1 for Prim's or enter 2 for Kruskal's:\n");
    scanf("%d",&ch);
    switch(ch)
    {
            case 1: for(i=0;i<N;i++)
                    {
                        visited[i]=0;
                        prev[i]=0;
                    }
                   printf("The selected edges are:\n");
                     minCost=prim(0,a,prev,visited);
                      printf("The minimum cost is:\n%d",minCost);
                   /* for(i=1;i<N;i++)
                        printf("\n%d->%d\n",i+1,prev[i]+1);*/
                    break;
            case 2: minCost=Kruskal(a);
                   printf("The minimum cost is:\n%d",minCost);
                    break;
            default: printf("\nInvalid choice!!\n");
                     exit(0);
    }

}


/*
OUTPUT:


Enter the no of vetices:
7

Is the edge between 1 and 2 connected(y=1/n=0)?
1

Enter that edge's cost:
30

Is the edge between 1 and 3 connected(y=1/n=0)?
0

Is the edge between 1 and 4 connected(y=1/n=0)?
0

Is the edge between 1 and 5 connected(y=1/n=0)?
0

Is the edge between 1 and 6 connected(y=1/n=0)?
1

Enter that edge's cost:
11

Is the edge between 1 and 7 connected(y=1/n=0)?
0

Is the edge between 2 and 3 connected(y=1/n=0)?
1

Enter that edge's cost:
17

Is the edge between 2 and 4 connected(y=1/n=0)?
0

Is the edge between 2 and 5 connected(y=1/n=0)?
0

Is the edge between 2 and 6 connected(y=1/n=0)?
0

Is the edge between 2 and 7 connected(y=1/n=0)?
1

Enter that edge's cost:
15

Is the edge between 3 and 4 connected(y=1/n=0)?
1

Enter that edge's cost:
13

Is the edge between 3 and 5 connected(y=1/n=0)?
0

Is the edge between 3 and 6 connected(y=1/n=0)?
0

Is the edge between 3 and 7 connected(y=1/n=0)?
0

Is the edge between 4 and 5 connected(y=1/n=0)?
1

Enter that edge's cost:
23

Is the edge between 4 and 6 connected(y=1/n=0)?
0

Is the edge between 4 and 7 connected(y=1/n=0)?
1

Enter that edge's cost:
19

Is the edge between 5 and 6 connected(y=1/n=0)?
1

Enter that edge's cost:
26

Is the edge between 5 and 7 connected(y=1/n=0)?
1

Enter that edge's cost:
25

Is the edge between 6 and 7 connected(y=1/n=0)?
0

The cost matrix is:
999     30      999     999     999     11      999
30      999     17      999     999     999     15
999     17      999     13      999     999     999
999     999     13      999     23      999     19
999     999     999     23      999     26      25
11      999     999     999     26      999     999
999     15      999     19      25      999     999

Which algorithm?
Enter 1 for Prim's or enter 2 for Kruskal's:
1
The selected edges are:

1->6

6->5

5->4

4->3

3->2

2->7
The minimum cost is:
105
Process returned 24 (0x18)   execution time : 45.052 s
Press any key to continue.
------------------------------------------------------------------------------------------------
OUTPUT 2:
students@CELAB4-10:~/Desktop$ cc p2.c
students@CELAB4-10:~/Desktop$ ./a.out

Enter the no of vetices:
4

Is the edge between 1 and 2 connected(y=1/n=0)?
1

Enter that edge's cost:
5

Is the edge between 1 and 3 connected(y=1/n=0)?
1

Enter that edge's cost:
3

Is the edge between 1 and 4 connected(y=1/n=0)?
0

Is the edge between 2 and 3 connected(y=1/n=0)?
1

Enter that edge's cost:
4

Is the edge between 2 and 4 connected(y=1/n=0)?
1

Enter that edge's cost:
9

Is the edge between 3 and 4 connected(y=1/n=0)?
0

The cost matrix is:
999	5	3	999	
5	999	4	9	
3	4	999	999	
999	9	999	999	

Which algorithm?
Enter 1 for Prim's or enter 2 for Kruskal's:
2

4
1	3
2	3
2	4
The minimum cost is:
16students@CELAB4-10:~/Desktop$ 


*/


