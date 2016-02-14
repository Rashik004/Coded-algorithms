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
#define mp make_pair
#define pb push_back
#define max(a,b)a>b?a:b
#define min(a,b)a<b?a:b
//topological sort with dfs
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
vi relation[100000+10];
stack<int> finTime;
bool visited[100000+10];
int turn;
int dfs(int node)
{
    visited[node]=true;
    for(int i=0;i<relation[node].size();i++)
    {
        int temp=relation[node][i];
        if(!visited[temp])
            dfs(temp);
    }
    
    if(turn==1)
        finTime.push(node);
}


int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,x,y;
    cin>>testCase;
   
    
    while(testCase--)
    {
         memset(visited,false,sizeof visited);
//         timing=0;
         int nodes,lines;
         cin>>nodes>>lines;
         while(lines--)
         {
             cin>>x>>y;
             relation[x].pb(y);
         }
         int temp;
         turn=1;
         for(int i=1;i<=nodes;i++)
        {
              if(!visited[i])
                dfs(i);
        }
        memset(visited,false,sizeof visited);
        int knock=0;
        turn++;
        for(int i=1;i<=nodes;i++)
        {
            temp=finTime.top();
            finTime.pop();
            if(!visited[temp])
            {
                knock++;
                dfs(temp);
            }
        }
        for(int i=0;i<=nodes;i++)
            relation[i].clear();
        while(!finTime.empty())
            finTime.pop();
        cout<<knock<<endl;
    }
    
    return 0;
}

