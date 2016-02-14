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
using namespace std;
//still wa
int process[100007],coinNum,lim[5],coins[5];
int processCount(int amount)
{
    coinNum=4;
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
                process[j]+=process[j-cur];
            }
    }
    
    return process[amount];
}
int main ()
{
    int test,q,c1,c2,c3,v;
    cin>>test;
    while(test--)
    {
        for(int i=0;i<4;i++)
            cin>>coins[i];
        cin>>q;
        while(q--)
        {
            for(int i=0;i<4;i++)
            cin>>lim[i];
            cin>>v;
            printf("%d\n",processCount(v));
        }
        
    }

}