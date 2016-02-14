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
#define MAX 10000+10
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
vi relation[MAX];
bool visited[MAX];
int fallen;
void dfs(int node)
{
    fallen++;
    visited[node]=true;
    int temp;
    for(int i=0;i<relation[node].size();i++)
    {
        temp=relation[node][i];
        if(!visited[temp])
            dfs(temp);
    }
}
int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,x,y,n,m,l;
    cin>>testCase;
    while(testCase--)
    {
        cin>>n>>m>>l;
        while(m--)
        {
            cin>>x>>y;
            relation[x].pb(y);
        }
        memset(visited,false,sizeof visited);
        fallen=0;
        while(l--)
        {
            cin>>x;
            if(!visited[x])
                dfs(x);
        }
        for(int i=0;i<=n;i++)
            relation[i].clear();
        cout<<fallen<<endl;
            
    }
    return 0;
}



