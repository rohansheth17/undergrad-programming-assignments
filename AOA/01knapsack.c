
    #include <stdio.h>
int max(int a, int b) { return (a > b)? a : b; }
    int knapsack(int W, int wt[], int val[], int n)

    {

       int i, j,w;

       int K[n+1][W+1];
       for (i = 0; i <= n; i++)

       {

           for (w = 0; w <= W; w++)

           {

               if (i==0 || w==0)

                   K[i][w] = 0;

               else if (wt[i-1] <= w)

                     K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);

               else

                     K[i][w] = K[i-1][w];

           }

       }
       
     for(i=0;i<n+1;i++)
     {
       for(j=0;j<W+1;j++)
        printf("%d\t",K[i][j]);
       printf("\n");
     }
      i=n;
      j=W;
      while(i>0 && j>0)
      {
        if(K[i][j] != K[i-1][j])
        {
          printf("\nItem %d is added in knapsack\n",i);
          i=i-1;
          j=j-wt[i];
        }
        else
        {
         i=i-1;
        }
      }
       return K[n][W];

    }
    int main()

    {

        int W,i,n;
        printf("Enter the no of items and knapsack caapcity: ");
	scanf("%d %d",&n,&W);
	int val[n],wt[n];
	for(i=0;i<n;i++){
	  printf("\nEnter weight and benifit of item no %d ",i+1);
          scanf("%d %d",&wt[i],&val[i]);
        }
        printf("\nValue = %d", knapsack(W, wt, val, n));

        return 0;

    }
