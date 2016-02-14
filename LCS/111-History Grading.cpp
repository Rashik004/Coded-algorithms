#include<iostream>
#include<cstdio>
#include<cstring>
#define max(a,b) a>b?a:b
using namespace std;
//ACed 
int main ()
{
    int arLength,a,b,index,profit[22][22],x[22],y[22];
    scanf("%d", &arLength);
    for(int i=0;i<=arLength;i++)
    {
        profit[i][0]=0;
        profit[0][i]=0;
    }
    for(int i=1;i<=arLength;i++)
    {
        scanf("%d", &a);
        x[a]=i;
    }
    while(scanf("%d", &a)!=EOF)
    {
        y[a]=1;
        for(int i=2;i<=arLength;i++)
        {
            scanf("%d", &a);
            y[a]=i;
        }
        
        for(int i=1;i<=arLength;i++)
            for(int j=1;j<=arLength;j++)
            {
                if(x[i]==y[j])
                    profit[i][j]=1+profit[i-1][j-1];
                else
                    profit[i][j]=max(profit[i-1][j],profit[i][j-1]);
            }
        
        printf("%d\n", profit[arLength][arLength]);
    }
    return 0;
}