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
vector<int> dependent[102];
bool visited[102];

int dfs(int index)
{
    if(visited[index]) return 0;
    int counting=1;
    visited[index]=true;
    for(int i=0;i<dependent[index].size(); i++)
    {
        if(!visited[dependent[index][i]])
            counting+=dfs(dependent[index][i]);
    }
    return counting;
}
int main ()
{
    int totalItem,x,y,depend,temp,high,result;
    while(scanf("%d", &totalItem) && totalItem)
    {
        high=-1;
        for(int i=0;i<totalItem;i++)
        {
            scanf("%d", &depend);
            while(depend--)
            {
                scanf("%d", &x);
                dependent[i].push_back(x-1);//all array are 0 indexed
            }
        }
        
        for(int i=0;i<totalItem;i++)
        {
            memset(visited, false, sizeof visited);
            temp=dfs(i);
            if(temp>high)
            {
                high=temp;
                result=i;
            }
        }
        
        printf("%d\n",result+1);
        for(int i=0;i<totalItem;i++)
            dependent[i].clear();
    }
    return 0;
}