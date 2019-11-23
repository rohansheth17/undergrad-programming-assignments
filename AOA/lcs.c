/*
NAME: ROHAN SHETH  BATCH: C  ROLLNO: 51
*/


#include<stdio.h>
#include<string.h>
char a[100],b[100],pat[100];
int x,len,l,m;


void printpat(int i,int j,int lcs,char dir[][l], int len[][l+1])
{
    if(i==0 || j==0)
    {
        printf("\n The reqd LCS is: %s\n",strrev(pat));
        return;
    }
    if(dir[i-1][j-1]=='d')
    {
        pat[x++]=b[i-1];
        printpat(i-1,j-1,lcs,dir,len);
    }
    else if(dir[i-1][j-1]=='l')
    {
        printpat(i,j-1,lcs,dir,len);
    }
     else if(dir[i-1][j-1]=='u')
     {
        printpat(i-1,j,lcs,dir,len);
     }


}

void main()
{
    int i,j,lcs;
    printf("Enter first string:\n");
    gets(a);
    printf("\nEnter second string:\n");
    gets(b);
    l=strlen(a);
    m=strlen(b);
    int len[m+1][l+1];
    char dir[m][l];
    for(j=0;j<l+1;j++)
        len[0][j]=0;
    for(i=0;i<m+1;i++)
        len[i][0]=0;
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<l+1;j++)
        {

            if(b[i-1]==a[j-1])
            {
                len[i][j]=len[i-1][j-1]+1;
                dir[i-1][j-1]='d';
                //printf("%d%c\t",len[i][j],dir[i-1][j-1]);
            }
            else if(len[i-1][j]>=len[i][j-1])
            {
                len[i][j]=len[i-1][j];
                dir[i-1][j-1]='u';
                 //printf("%d%c\t",len[i][j],dir[i-1][j-1]);
            }
            else if(len[i-1][j]<len[i][j-1])
            {
                len[i][j]=len[i][j-1];
                dir[i-1][j-1]='l';
                 //printf("%d%c\t",len[i][j],dir[i-1][j-1]);
            }
        }
    }
       for(i=0;i<m+1;i++)
        {
            for(j=0;j<l+1;j++)
            {
                if(i==0 || j==0)
                    printf("%d \t",len[i][j]);
                else
                    printf("%d%c\t",len[i][j],dir[i-1][j-1]);
            }
             printf("\n");
        }
    lcs=len[m][l];
    printf("The length of the longest common subsequence is: %d",lcs);
    for(i=m;i>0;i--)
    {
        if(len[i][l]==lcs && dir[i-1][l-1]=='d')
        {
            x=0;
            printpat(i,l,lcs,dir,len);
        }
    }
    for(j=l;j>0;j--)
    {
        if(len[m][j]==lcs && dir[m-1][j-1]=='d')
        {
            x=0;
            printpat(m,j,lcs,dir,len);
        }
    }
}


/*
OUTPUT:


Enter first string:
abcdbacdf

Enter second string:
ccbafad
0       0       0       0       0       0       0       0       0       0

0       0u      0u      1d      1l      1l      1l      1d      1l      1l

0       0u      0u      1d      1u      1u      1u      2d      2l      2l

0       0u      1d      1u      1u      2d      2l      2u      2u      2u

0       1d      1u      1u      1u      2u      3d      3l      3l      3l

0       1u      1u      1u      1u      2u      3u      3u      3u      4d

0       1d      1u      1u      1u      2u      3d      3u      3u      4u

0       1u      1u      1u      2d      2u      3u      3u      4d      4u

The length of the longest common subsequence is: 4
 The reqd LCS is: cbaf

 The reqd LCS is: cbad

Process returned 1 (0x1)   execution time : 13.670 s
Press any key to continue.



*/
