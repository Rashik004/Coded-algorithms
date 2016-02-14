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
#define MAXx 30

map<string,int>name;
string manush[MAXx];
bool visited[MAXx],first;
vi relation[MAXx],opposite[MAXx];
stack<int>finishTime;


void dfs(int now)
{
    visited[now]=true;
    for(int i=0;i<relation[now].size();i++)
    {
        int temp=relation[now][i];
        if(!visited[temp])
            dfs(temp);
    }
    finishTime.push(now);
}

void oppositeDfs(int now)
{
    visited[now]=true;
    if(first)
        cout<<manush[now];
    else
        cout<<", "<<manush[now];
    first=false;
    for(int i=0;i<opposite[now].size();i++)
    {
        int temp=opposite[now][i];
        if(!visited[temp])
            oppositeDfs(temp);
    }

}

void findScc(int people)
{
    memset(visited,false,sizeof visited);
    while(!finishTime.empty())
        finishTime.pop();

    for(int i=1;i<=people;i++)
        if(!visited[i])
            dfs(i);

    memset(visited,false,sizeof visited);

    while(!finishTime.empty())
    {
        int temp=finishTime.top();
        first=true;
        if(!visited[temp])
        {
            oppositeDfs(temp);
            cout<<endl;
        }
        finishTime.pop();
    }

    for(int i=0;i<=people;i++)
    {
        relation[i].clear();
        opposite[i].clear();
    }

    name.clear();

}
int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,people, query,serial=1;
    while(cin>>people>>query && people && query)
    {


        string x,y;
        int index=0;
        while(query--)
        {
            cin>>x>>y;
            if(name.find(x)==name.end())
            {
                name[x]=++index;
                manush[index]=x;
            }
            if(name.find(y)==name.end())
            {
                name[y]=++index;
                manush[index]=y;
            }
            relation[name[x]].pb(name[y]);
            opposite[name[y]].pb(name[x]);
        }
        if(serial!=1)
            cout<<endl;
        printf("Calling circles for data set %d:\n", serial++);
        findScc(people);

    }

    return 0;
}




