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
class topSort{
public:
    vector<int>dependent[102];
    int taken[102],elements, time;
    priority_queue <pair<int, int> > time_node;
    void input(int, int);
    void dfs();
    void dfs_visit(int node);
    topSort(int);
};

topSort::topSort(int x)
{
    time=0;
    memset(taken,0,sizeof(taken));
    elements=x;
}



void topSort::dfs()
{
    for(int i=1;i<=elements;i++)
        if(taken[i]==0)
            dfs_visit(i);
}

void topSort::dfs_visit(int node)
{
    time++;
    taken[node]=1;
    for(int i=0;i<dependent[node].size();i++)
        if(taken[dependent[node][i]]==0)
            dfs_visit(dependent[node][i]);
    pair<int,int>p;
    p.first=time++;
    p.second=node;
    time_node.push(p);
}


int main ()
{
    int m,n,i,j;
    while(cin>>n>>m)
    {
        if(!m && !n)
            return 0;
        getchar();
        topSort obj(n);
        while(m--)
        {
            cin>>i>>j;
            obj.dependent[i].push_back(j);
        }
        obj.dfs();
        cout<<obj.time_node.top().second;
        obj.time_node.pop();
        while(!obj.time_node.empty())
        {
            cout<<' '<<obj.time_node.top().second;
            obj.time_node.pop();
        }
        cout<<endl;
    }
    return 0;
}