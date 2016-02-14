#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
//ACed
using namespace std;
int process[100007],coinNum,lim[54],coins[54];
int processCount(int amount)
{
    for(int i=1;i<=amount;i++)
        process[i]=0;
    process[0]=1;
    int cur;

    for(int i=1;i<=lim[0];i++)
    {
        cur=coins[0]*i;
        if(cur>amount)
            break;
        process[cur]=1;
    }
    for(int i=1;i<coinNum;i++)
    {
        for(int j=amount;j>=0;j--)
            for(int k=1;k<=lim[i];k++)
            {
                cur=coins[i]*k;
                if(j-cur<0)
                    break;
                process[j]=(process[j]+process[j-cur])%100000007;
            }
    }
    return process[amount];
}


int main ()
{
    int testCase, n,k;
    scanf("%d", &testCase);
    for(int a=1;a<=testCase;a++)
    {
        scanf("%d %d", &n,&k);
        for(int i=0;i<n;i++)
            scanf("%d", &coins[i]);
        for(int i=0;i<n;i++)
            scanf("%d", &lim[i]);
        coinNum=n;
        printf("Case %d: ", a);
        printf("%d\n",processCount(k));
    }
    return 0;
}
