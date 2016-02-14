#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
vector<int>dependent[102];
int ending,maxM,d[102];
void dfs(int index,int time)
{
    d[index]=time++;
    int s=dependent[index].size(),temp;
    if(!s)
    {
        if(d[index]>maxM)
        {
            maxM=d[index];
            ending=index;
        }
        else if(d[index]==maxM && index<ending)
            ending=index;
        return;
    }
    
    for(int i=0;i<s;i++)
    {
        temp=dependent[index][i];
        if(d[temp]<time)//if current time is less than the previous yime saved in d[temo] then we don't need to visit there
            dfs(temp,time);
    }
}


int main ()
{
    int nodes,x,y,start,caseNo=1;
    while(scanf("%d", &nodes) && nodes)
    {
        scanf("%d", &start);
        maxM=0;
        ending=1000;
        while(scanf("%d %d", &x, &y) && x && y)
            dependent[x].push_back(y);
        memset(d,-1,sizeof d);
        dfs(start,0);
//        if(caseNo!=1)
//            printf("\n");
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", caseNo++, start,maxM, ending);
        
        for(int i=1;i<=nodes;i++)
            dependent[i].clear();
    }
    return 0;
}