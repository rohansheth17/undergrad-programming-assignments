/*NAME: ROHAN SHETH BATCH: C  ROLLNO: 51
*/


#include<stdio.h>
#include<string.h>
# define q 19

int hashval(char subs[],int m)
{
    int i,sum=0;
    for(i=0;i<m;i++)
    {
        if(isdigit(subs[i]))
           sum+=(subs[i]-48);
        else
            sum+=(subs[i]-97);
    }
    printf("Hashvalue is:%d\n",sum%q);
    return (sum%q);
}


void main()
{
    int i,j,k,n,m,x,hashpat;
    char str[50],subs[10]={0},pat[10];
    printf("\nEnter the string:\n");
    gets(str);
    printf("\nEnter the pattern you want to find in the above string:\n");
    gets(pat);
    n=strlen(str);
    m=strlen(pat);
    hashpat=hashval(pat,m);
    for(i=0;i<n-m+1;i++)
    {
        k=0;x=0;
        for(j=i;j<i+m;j++)
        {
            subs[k++]=str[j];
        }
        printf("\nSubstring is:%s\n",subs);
        if(hashval(subs,m)==hashpat)
        {
            for(k=0;k<m;k++)
            {
                if(subs[k]==pat[k])
                    x++;
            }
            if(x==m)
                printf("Pattern is found in the given string at positon %d\n",i+1);
        }

    }

}


/*
OUTPUT:


Enter the string:
sjg346f3h4h3

Enter the pattern you want to find in the above string:
f3h
Hashvalue is:15

Substring is:sjg
Hashvalue is:14

Substring is:jg3
Hashvalue is:18

Substring is:g34
Hashvalue is:13

Substring is:346
Hashvalue is:13

Substring is:46f
Hashvalue is:15

Substring is:6f3
Hashvalue is:14

Substring is:f3h
Hashvalue is:15
Pattern is found in the given string at positon 7

Substring is:3h4
Hashvalue is:14

Substring is:h4h
Hashvalue is:18

Substring is:4h3
Hashvalue is:14
Process returned 10 (0xA)   execution time : 14.681 s
Press any key to continue.



*/
