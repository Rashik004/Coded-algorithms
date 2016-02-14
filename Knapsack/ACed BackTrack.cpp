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
#define max(a,b) (a>b)?a:b
using namespace std;
int profit[32][1005],w[32],price[32],mark[32],counting;
//only profit is a 1 indexed array, all other arrays are 0 indexed
int knapsack(int totalItem,int totalWeight)
{
    int with,without;
    for(int i=0;i<=totalItem;i++)
        profit[i][0]=0;
    for(int j=0;j<=totalWeight;j++)
        profit[0][j]=0;
    for(int i=1;i<=totalItem;i++)
        for(int j=1;j<=totalWeight;j++)
        {
            if(w[i-1]<=j)
                with=profit[i-1][j-w[i-1]]+price[i-1];
            else
                with=0;
            without=profit[i-1][j];
            profit[i][j]=max(with,without);
        }

    return profit[totalItem][totalWeight];
}

void backTrack(int item,int weight)
{
    if(!item || !weight)
        return;
    if((profit[item][weight]-price[item-1])==profit[item-1][weight-w[item-1]])
    {
        mark[item-1]=1;
        counting++;
        backTrack(item-1, weight-w[item-1]);
    }
    else if(profit[item-1][weight]>profit[item][weight-1])
        backTrack(item-1,weight);
    else
        backTrack(item,weight-1);
}

int main()
{

    int item, lim;
    cout<<"enter the number of total item: ";
    cin>>item;
    for(int i=0;i<item; i++)
    {
        cin>>w[i]>>price[i];
    }
    cout<<"Enter the limit: ";
    cin>>lim;
    int res=knapsack(item, lim);
    cout<<res;
    return 0;
}
