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
#define CITY_NO 111
#define TURNS 1005
using namespace std;
int costing[CITY_NO][CITY_NO],ending[CITY_NO],totalCity,dp[CITY_NO][TURNS],E;
int salesman(int city,int turnsLeft)
{
    if(dp[city][turnsLeft])
        return dp[city][turnsLeft];
    if(turnsLeft==0)
        return dp[city][0]=0;
    int high=-1<<31,temp;
    if(turnsLeft==1)
    {
        for(int i=1;i<=E;i++)
        {
            temp=costing[city][ending[i]];
            high=max(temp,high);
        } 
        return dp[city][1]=high;
    }
    
    for(int i=1;i<=totalCity;i++)
    {
        temp=costing[city][i]+salesman(i,turnsLeft-1);
        high=max(high,temp);
    }
    return dp[city][turnsLeft]=high;
        
}

int main ()
{
    int starter,totalTurns;
    while(scanf("%d %d %d %d", &totalCity, &starter, &E, &totalTurns))
    {
        if(!totalCity && !starter && !E && !totalTurns)
            break;
        memset(dp,0,sizeof dp);
        for(int i=1;i<=totalCity;i++)
            for(int j=1;j<=totalCity;j++)
                scanf("%d", &costing[i][j]);
        for(int i=1;i<=E;i++)
            scanf("%d", &ending[i]);
        printf("%d\n", salesman(starter,totalTurns));
    }
    return 0;
}




