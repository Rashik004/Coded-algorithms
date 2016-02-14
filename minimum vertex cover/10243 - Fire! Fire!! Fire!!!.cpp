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
#define MAX 1010
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
int dp[MAX][3];
int parent[MAX];
vi edge[MAX];
bool visited[MAX];
int minimumVertex(int node, int guarded)
{
    if(edge[node].size()==0) return 1;// wpuld be 0
    if(dp[node][guarded]!=-1) return dp[node][guarded];
    visited[node]=true;
    int guardsNeeded=0;
    for(int i=0;i<edge[node].size();i++)
    {
        int temp=edge[node][i];
        if(parent[node]!=temp && temp!=node)
        {
            parent[temp]=node;
            if(!guarded)
                guardsNeeded+=minimumVertex(temp,1);
            else
                guardsNeeded+=min(minimumVertex(temp,1),minimumVertex(temp,0));
            
        }
    }
    
    return dp[node][guarded]=guardsNeeded+guarded;
}

int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,x,y,nodes,adj;
    while(cin>>nodes && nodes)
    {
        memset(dp,-1,sizeof dp);
        memset(visited,false,sizeof visited);
        parent[1]=0;
        for(int i=1;i<=nodes;i++)
        {
            cin>>adj;
            while(adj--)
            {
                cin>>x;
                edge[i].pb(x);
            }
        }
        
        int res=0;
        for(int i=1;i<=nodes;i++)
            if(!visited[i])
                res+=min(minimumVertex(i,0),minimumVertex(i,1));
        
        for(int i=1;i<=nodes;i++)
            edge[i].clear();
        cout<<res<<endl;
    }
    
    return 0;
}