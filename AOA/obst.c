/*
NAME: ROHAN SHETH  BATCH: C  ROLLNO: 51
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define N 99


typedef struct node
{
    int data;
    struct node *left,*right;
}node;

node* create()
{
    node *rooot;
    rooot=NULL;
    return rooot;
}



node *insert(node *T,int x)
{
    node *p,*q,*r;
    r=(node*)malloc(sizeof(node));
    r->data=x;
    r->left=NULL;
    r->right=NULL;
    if(T==NULL)
            return r;
    p=T;
    while(p!=NULL)
    {
        q=p;
        if(x>p->data)
            p=p->right;
        else
            p=p->left;
    }
    if(x>q->data)
        q->right=r;
    else
        q->left=r;
    return T;

}

node * root(int i,int j,node* rooot,int n,int r[][n+1])
{
    if(i!=j)
    {
            int rut=r[i][j];
           // printf(" \n- - - - - - - - - - - - %d\n",rut);
            rooot=insert(rooot,rut);
            root(i,rut-1,rooot,n,r);
            root(rut,j,rooot,n,r);
    }
    return rooot;
}


void postorder(node *T)
{
    if(T!=NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%5d",T->data);
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
	node *rooot;
	rooot=create();
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
    printf("\n------------------------------------\n");
    i=0;
    j=n;
    rooot=root(i,j,rooot,n,r);
     printf("The root node is :%d\n",r[i][j]);
	printf("The cost is :%d\n",c[i][j]);
    printf("Postorder traversal of obst is as follows:\n");
    postorder(rooot);


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

Postorder traversal of obst is as follows:
    1    4    3    2
Process returned 5 (0x5)   execution time : 4.636 s
Press any key to continue.


*/












