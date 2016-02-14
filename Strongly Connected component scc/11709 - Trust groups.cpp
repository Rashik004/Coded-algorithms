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
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
#define MAX 1005 
//strongly connected component scc
vi relation[MAX],opposite[MAX];
stack<int>finish;
bool visited[MAX];

void dfs(int now)
{
    visited[now]=true;
    for(int i=0;i<relation[now].size();i++)
    {
        int temp=relation[now][i];
        if(!visited[temp])
            dfs(temp);
    }
    finish.push(now);
}

void anotherDfs(int now)
{
    visited[now]=true;
    for(int i=0;i<opposite[now].size();i++)
    {
        int temp=opposite[now][i];
        if(!visited[temp])
            anotherDfs(temp);
    }
}

int findScc(int nodes)
{
    int components=0;
    
    memset(visited,false,sizeof visited);
    for(int i=1;i<=nodes;i++)
        if(!visited[i])
            dfs(i);
            
    
    memset(visited,false,sizeof visited);
    while(!finish.empty())
    {
        if(!visited[finish.top()])
        {
            anotherDfs(finish.top());
            components++;
        }
        finish.pop();
    }
    
    for(int i=1;i<=nodes;i++)
    {
        relation[i].clear();
        opposite[i].clear();
    }
    return components;
}


int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int p,t,x,y;
    string name;
    while(cin>>p>>t)
    {
        if(!p && !t)
            break;
        getchar();
        map<string,int>manMap;
        
        for(int i=1;i<=p;i++)
        {
            getline(cin,name);
            manMap[name]=i;
        }
        
        
        for(int i=1;i<=t;i++)
        {
            int person1,person2;
            
            getline(cin,name);
            person1=manMap[name];
            
            getline(cin,name);
            person2=manMap[name];
            
            relation[person1].pb(person2);
            opposite[person2].pb(person1);
        }
        manMap.clear();
        cout<<findScc(p)<<endl;
    }
    return 0;
}




