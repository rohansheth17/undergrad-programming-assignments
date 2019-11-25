#include<stdio.h>
#include<stdbool.h>

typedef struct node
{
 int a;
 int b;
 int c;
}node;

int x=12,y=8,z=5;                            //maximum capacities of 3 jugs
node m[100];

bool findAllStates(node [],int [],int);
void main()
{
    node n[100];
                   
    int visited[100]={0};        
    n[0].a=12;
    n[0].b=0;
    n[0].c=0;
    m[0].a=n[0].a;
    m[0].b=n[0].b;
    m[0].c=n[0].c;

   // printf("Initial state:%d,%d,%d",n[0].a,n[0].b,n[0].c);
    int i=0;
    findAllStates(n,visited,i);
    
   //printf("\n%d %d %d\n",n[10].a,n[10].b,n[10].c);
    printf("\n%d %d %d\n",m[1].a,m[1].b,m[1].c);   
    
    
    
    
}

//visited=memory
//n=state
//m=ans

bool findAllStates(node n[100],int visited[100],int i)
{

    int a=n[i].a,b=n[i].b,c=n[i].c,j;

    if(a==6&&b==6)
        return true;
        
    for(j=i;j>=0;j--)
    {
            if( n[j].a==a && n[j].b==b && n[j].c==c && (visited[j]==1) )
                return false;     
    }    
    
    visited[i]=1;
    
    if(a>0)
    {
       
        if(a+b<=y)
        {
            i++;
            n[i].a=0;
            n[i].b=a+b;
            n[i].c=c;
            if(findAllStates(n,visited,i))
            {
             //printf("wfjgwalifwgifiqwgbfiwhlvgowgfiwbhkwbhvgf");
                 m[i].a=n[i].a;
                 m[i].b=n[i].b;
                 m[i].c=n[i].c;
                  //printf("\n%d %d %d\n",m[i].a,m[i].b,m[i].c);
                 return true;
            }
                
        }  
        else
        {
            i++;
            n[i].a=a-(y-b);
            n[i].b=y;
            n[i].c=c;
            if(findAllStates(n,visited,i))
            {
                 m[i].a=n[i].a;
                 m[i].b=n[i].b;
                 m[i].c=n[i].c;
                 return true;
            }
        
        
        
        }
        if(a+c<=z)
        {
            i++;
            n[i].a=0;
            n[i].b=b;
            n[i].c=a+c;
            if(findAllStates(n,visited,i))
            {
                 m[i].a=n[i].a;
                 m[i].b=n[i].b;
                 m[i].c=n[i].c;
                 return true;
            }
        
        
        }
        else
        {            
            i++;
            n[i].a=a-(z-c);
            n[i].b=b;
            n[i].c=z;
            if(findAllStates(n,visited,i))
            {
                 m[i].a=n[i].a;
                 m[i].b=n[i].b;
                 m[i].c=n[i].c;
                 return true;
            }   
        }
    }
    if(b>0)
        {
            if(a+b<=x)
            {
                i++;
                n[i].a=a+b;
                n[i].b=0;
                n[i].c=c;
                if(findAllStates(n,visited,i))
                {
                     m[i].a=n[i].a;
                     m[i].b=n[i].b;
                     m[i].c=n[i].c;
                     return true;
                }
                    
            }  
            else
            {
                i++;
                n[i].a=x;
                n[i].b=b-(x-a);
                n[i].c=c;
                if(findAllStates(n,visited,i))
                {
                     m[i].a=n[i].a;
                     m[i].b=n[i].b;
                     m[i].c=n[i].c;
                     return true;
                }       
            }
            if(b+c<=z)
            {
                i++;
                n[i].a=a;
                n[i].b=0;
                n[i].c=b+c;
                if(findAllStates(n,visited,i))
                {
                     m[i].a=n[i].a;
                     m[i].b=n[i].b;
                     m[i].c=n[i].c;
                     return true;
                }
            
            
            }
            else
            {            
                i++;
                n[i].a=a;
                n[i].b=b-(z-c);
                n[i].c=z;
                if(findAllStates(n,visited,i))
                {
                     m[i].a=n[i].a;
                     m[i].b=n[i].b;
                     m[i].c=n[i].c;
                     return true;
                }   
            }
        }
    if(c>0)
        {
            if(a+c<=x)
            {
                i++;
                n[i].a=a+c;
                n[i].b=b;
                n[i].c=0;
                if(findAllStates(n,visited,i))
                {
                     m[i].a=n[i].a;
                     m[i].b=n[i].b;
                     m[i].c=n[i].c;
                     return true;
                }
                    
            }  
            else
            {
                i++;
                n[i].a=x;
                n[i].b=b;
                n[i].c=c-(x-a);
                if(findAllStates(n,visited,i))
                {
                     m[i].a=n[i].a;
                     m[i].b=n[i].b;
                     m[i].c=n[i].c;
                     return true;
                }        
            }
            if(b+c<=y)
            {
                i++;
                n[i].a=a;
                n[i].b=b+c;
                n[i].c=0;
                if(findAllStates(n,visited,i))
                {
                     m[i].a=n[i].a;
                     m[i].b=n[i].b;
                     m[i].c=n[i].c;
                     return true;
                }       
            }
            else
            {            
                i++;
                n[i].a=a;
                n[i].b=y;
                n[i].c=c-(y-b);
                if(findAllStates(n,visited,i))
                {
                     m[i].a=n[i].a;
                     m[i].b=n[i].b;
                     m[i].c=n[i].c;
                     return true;
                }   
            }
        }
        return false;

}
