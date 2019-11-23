/*NAME: ROHAN SHETH  ROLLNO: 51  BATCH: C
*/

#include<stdio.h>

void print(int n,int a[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}


void addsub(int n,int arr[n][n],int brr[n][n],int rrr[n][n],int f)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(f==0)
              rrr[i][j]=arr[i][j]+brr[i][j];
            else
                rrr[i][j]=arr[i][j]-brr[i][j];
        }
    }
}

void strasmult(int n,int a[n][n],int b[n][n],int c[n][n])
{
    int i,j;
    if(n==2)
    {

        int p1 = (a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
        int p2 = (a[1][0]+a[1][1])*b[0][0];
        int p3 = a[0][0]*(b[0][1]-b[1][1]);
        int p4 = a[1][1]*(b[1][0]-b[0][0]);
        int p5 = (a[0][0]+a[0][1])*b[1][1];
        int p6 = (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
        int p7 = (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

        int c11 = p1 + p4 - p5 + p7;
        int c12 = p3 + p5;
        int c21 = p2 + p4;
        int c22 = p1 + p3 - p2 + p6;
         c[0][0]=c11;
         c[0][1]=c12;
         c[1][0]=c21;
         c[1][1]=c22;


    }
    else
    {
        int a11[n/2][n/2],a12[n/2][n/2],a21[n/2][n/2],a22[n/2][n/2];
        int b11[n/2][n/2],b12[n/2][n/2],b21[n/2][n/2],b22[n/2][n/2];
        int r1[n/2][n/2],r2[n/2][n/2],r3[n/2][n/2],r4[n/2][n/2],r5[n/2][n/2];
        int r6[n/2][n/2],r7[n/2][n/2],r8[n/2][n/2],r9[n/2][n/2],r10[n/2][n/2];
        int r11[n/2][n/2],r12[n/2][n/2],r13[n/2][n/2],r14[n/2][n/2],r15[n/2][n/2];
        int r16[n/2][n/2],r17[n/2][n/2],r18[n/2][n/2];
        int p1[n/2][n/2],p2[n/2][n/2],p3[n/2][n/2],p4[n/2][n/2],p5[n/2][n/2],p6[n/2][n/2],p7[n/2][n/2];
        int c11[n/2][n/2],c12[n/2][n/2],c21[n/2][n/2],c22[n/2][n/2];
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                a11[i][j]=a[i][j];
            }


        }
        for(i=0;i<n/2;i++)
        {
            for(j=n/2;j<n;j++)
            {
                a12[i][j-(n/2)]=a[i][j];
            }

        }
        for(i=n/2;i<n;i++)
        {
            for(j=0;j<n/2;j++)
            {
                a21[i-(n/2)][j]=a[i][j];
            }

        }
        for(i=n/2;i<n;i++)
        {
            for(j=n/2;j<n;j++)
            {
                a22[i-(n/2)][j-(n/2)]=a[i][j];
            }

        }
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                b11[i][j]=b[i][j];
            }

        }
        for(i=0;i<n/2;i++)
        {
            for(j=n/2;j<n;j++)
            {
                b12[i][j-(n/2)]=b[i][j];
            }

        }
        for(i=n/2;i<n;i++)
        {
            for(j=0;j<n/2;j++)
            {
                b21[i-(n/2)][j]=b[i][j];
            }

        }
        for(i=n/2;i<n;i++)
        {
            for(j=n/2;j<n;j++)
            {
                b22[i-(n/2)][j-(n/2)]=b[i][j];
            }

        }
         addsub(n/2,a11,a22,r1,0);
         addsub(n/2,b11,b22,r2,0);
         strasmult(n/2,r1,r2,p1);
         addsub(n/2,a21,a22,r3,0);
         strasmult(n/2,r3,b11,p2);
         addsub(n/2,b12,b22,r4,1);
         strasmult(n/2,a11,r4,p3);
         addsub(n/2,b21,b11,r5,1);
         strasmult(n/2,a22,r5,p4);
         addsub(n/2,a11,a12,r6,0);
         strasmult(n/2,r6,b22,p5);
         addsub(n/2,a21,a11,r7,1);
         addsub(n/2,b11,b12,r8,0);
         strasmult(n/2,r7,r8,p6);
         addsub(n/2,a12,a22,r9,1);
         addsub(n/2,b21,b22,r10,0);
         strasmult(n/2,r9,r10,p7);
         addsub(n/2,p1,p4,r11,0);
         addsub(n/2,r11,p5,r12,1);
         addsub(n/2,r12,p7,c11,0);
         addsub(n/2,p3,p5,c12,0);
         addsub(n/2,p2,p4,c21,0);
         addsub(n/2,p1,p3,r13,0);
         addsub(n/2,r13,p2,r14,1);
         addsub(n/2,r14,p6,c22,0);
         printf("\n----------c11----------\n");
         print(n/2,c11);
          printf("\n----------c12-----------");
          print(n/2,c12);
          printf("\n----------c21-----------");
           print(n/2,c21);
          printf("\n----------c22-----------");
           print(n/2,c22);
          for(i=0;i<n/2;i++)
          {
            for(j=0;j<n/2;j++)
            {
                c[i][j]=c11[i][j];
            }

         }
          for(i=0;i<n/2;i++)
        {
            for(j=n/2;j<n;j++)
            {
                c[i][j]=c12[i][j-n/2];
            }

        }
         for(i=n/2;i<n;i++)
        {
            for(j=0;j<n/2;j++)
            {
                c[i][j]=c21[i-n/2][j];
            }

        }
         for(i=n/2;i<n;i++)
        {
            for(j=n/2;j<n;j++)
            {
                c[i][j]=c22[i-n/2][j-n/2];
            }

        }
    }
}

void main()
{
    int n,i,j;
    printf("Enter the order of the matrices(as a power of 2):\n");
    scanf("%d",&n);
    if(n%2!=0)
    {
        printf("\nEnter again!!\n");
        scanf("%d",&n);
    }
    int a[n][n],b[n][n],c[n][n];
    printf("\nEnter the elements of the first matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nYour first matrix is: \n");
    print(n,a);
    printf("\nEnter the elements of the second matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
     printf("\nYour second matrix is: \n");
    print(n,b);
    strasmult(n,a,b,c);
    printf("\nThe matrix after applying strassen multiplication is:\n");
    print(n,c);
    /* if(n<=2)
    {


        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(i<n/2)
            {
                for(j=0;j<n/2;j++)
                {
                    printf("%d\t",c11[i][j]);
                }
                for(k=n/2;k<n;k++)
                {
                    printf("%d\t",c12[i][k]);
                }
            }
            else
            {
                 for(j=0;j<n/2;j++)
                {
                    printf("%d\t",c21[i][j]);
                }
                for(k=n/2;k<n;k++)
                {
                    printf("%d\t",c22[i][k]);
                }
            }
            printf("\n");

    }
*/
}
 /*
 Output:

 Enter the order of the matrices(as a power of 2):
4

Enter the elements of the first matrix:
1
2
3
4
5
6
7
8
9
1
2
3
4
5
6
7

Your first matrix is:
1       2       3       4
5       6       7       8
9       1       2       3
4       5       6       7

Enter the elements of the second matrix:
1
2
3
4
5
6
7
8
9
1
2
3
4
5
6
7

Your second matrix is:
1       2       3       4
5       6       7       8
9       1       2       3
4       5       6       7

----------c11----------
54      37
130     93

----------c12-----------47      57
119     145

----------c21-----------44      41
111     79

----------c22-----------56      71
101     123

The matrix after applying strassen multiplication is:
54      37      47      57
130     93      119     145
44      41      56      71
111     79      101     123

*/




