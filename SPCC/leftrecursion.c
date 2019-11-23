#include<stdio.h>
#include<string.h>



void main()
{

    printf(".......Program to remove direct left recursion.............\n");
    char prod[10][10],c;
    int i=0,j,k=0,n,position[10][10]=0;
    printf("Enter the no of productions:\n");
    scanf("%d",&n);
    printf("Enter the productions:\n");
	for(j=0;j<n;j++)
    {
      k=0;
      while((c=getchar())!='Z')
          {
              prod[j][k]=c;
              	k++;
              //printf("%c\n",c);
          }
          //printf("%d\n",j);
		prod[j][k]='\0';
    }            

    for(j=0;j<n;j++)
    {
    
        printf("%s\n",prod[j]);
        //printf("%c\n",prod[j][0]);
    }
    
    for(j=0;j<n;j++)
    {
    	  for(i=0;i<strlen(prod[j]);i++)
    	  {
    	  		if(prod[j][i]=='|')
					{	
						position[j][k]=i;
						k++;	
					}
			}	   
    }  

	/*for(j=0;j<n;j++)
	{
		//printf("%c\n%c\n",prod[j][0],prod[j][3]);
		if(prod[j][1]==prod[j][4])
		{
			printf("Production %d is left recursive\n",j+1);
				k=0;
				for(i=1;i<strlen(prod[j]);i++)
				{
					if(prod[j][i]=='|')
					{	
						position[k]=i;
						k++;	
					}
				}
				//k--;

				printf("%c->",prod[j][1]);

				for(i=position+1;i<strlen(prod[j]);i++)
				{
	
					printf("%c",prod[j][i]);
	
				}
				printf("X%d\n",j+1);
				printf("X%d->",j+1);
		
				for(i=5;i<position;i++)
				{
		
					printf("%c",prod[j][i]);
				}	
				printf("X%d|epsilon\n",j+1);
		}
		else	
			printf("Production %d is not left recursive\n",j+1);	
		
		
	}		*/


}

