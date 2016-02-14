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
#define NEG -100000
#define max(a,b) (a>b)?a:b
using namespace std;
int profit[102][10005],w[102],price[102],mark[102],counting;
int knapsack(int totalItem,int totalWeight)//by this function only the amount used will be +ve others will be NEG+price
{
    int with,without;
    for(int i=0;i<=totalItem;i++)
        for(int j=0;j<=totalWeight;j++)
            profit[i][j]=NEG;
    profit[0][0]=0;
    for(int i=1;i<=totalItem;i++)
        for(int j=0;j<=totalWeight;j++)
        {
            without=profit[i-1][j];
            if(w[i-1]<=j)
                profit[i][j]=max(profit[i-1][j-w[i-1]]+price[i-1],without);
            else
            
            profit[i][j]=without;
        }
            
    return profit[totalItem][totalWeight];
}

int main()
{
    int budget,tottalItem;
    while(scanf("%d %d", &budget, &tottalItem)!=EOF)
    {
        int result=0;
        for(int i=0;i<tottalItem;i++)
            scanf("%d %d", &w[i], &price[i]);
        knapsack(tottalItem, budget+200);
        for(int i=0;i<=budget;i++)
            result=max(result, profit[tottalItem][i]);
        for(int i=2001;i<=budget+200;i++)
            result=max(result, profit[tottalItem][i]);
        printf("%d\n", result);
    }
}
/* a Critical input:
    1900 3
    2000 5
    101 1
    1950 1
*/