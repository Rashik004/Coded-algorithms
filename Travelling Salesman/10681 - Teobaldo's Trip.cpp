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
#define CITY_NO 101
#define DAY 201
using namespace std;
int endCity,dp[CITY_NO][DAY];
vector<int>link[CITY_NO];
//before calling the function for the first time make sure to do memset(dp,-1)
int salesman(int city,int daysLeft)
{
    if(dp[city][daysLeft]!=-1)
        return dp[city][daysLeft];
    
    if(daysLeft==0)
        {
            if(city!=endCity)
                return dp[city][0]=0;
            else
                return dp[city][0]=1;
        }
    if(daysLeft==1)
    {
        for(int i=0;i<link[city].size();i++)
            if(link[city][i]==endCity)
                return dp[city][1]=1;
        return dp[city][daysLeft]=0;
    }
    
    for(int i=0;i<link[city].size();i++)
        if(salesman(link[city][i],daysLeft-1)==1)//if optimal solution is achievable from any of these citites connected to current city then optimal soluttion can also be obtained from current city
            return dp[city][daysLeft]=1;
    return dp[city][daysLeft]=0;
}


int main ()
{
    int totalCity, connections,starter,highDay,x,y;
    while(scanf("%d %d", &totalCity, &connections)!=EOF)
    {
        if(!totalCity && !connections)
            break;
            
        
        memset(dp,-1,sizeof dp);

        for(int i=0;i<CITY_NO;i++)
            link[i].clear();

        
        while(connections--)
        {
            scanf("%d %d", &x,&y);
            link[x].push_back(y);
            link[y].push_back(x);
        }
        
        scanf("%d %d %d",&starter, &endCity, &highDay );
        if(salesman(starter,highDay))
            printf("Yes, Teobaldo can travel.\n");
        else
            printf("No, Teobaldo can not travel.\n");
    }
    return 0;
}