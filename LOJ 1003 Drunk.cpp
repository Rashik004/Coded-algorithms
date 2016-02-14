 #include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define vi vector<int>
#define MAX 10000+8
using namespace std;
bool visited[MAX], once[MAX];
bool cycle;
vi relation[MAX];

void dfs(int now)
{
    if(cycle || visited[now])
    {
        cycle=true;
        return;
    }
    visited[now]=true;
    once[now]=true;
    for(int i=0;i<relation[now].size(); i++)
        dfs(relation[now][i]);
}
int main()
{
    int testCase,x,y,m,n,k;
    cin>>testCase;
    for(int qq=1;qq<=testCase;qq++)
    {
        cin>>m;
        memset(visited, false, sizeof visited);
        memset(once, false, sizeof once);
        cycle=false;

        string a,b;
        map <string, int> mymap;
        int index=0;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            if(mymap.find(a)==mymap.end())
                mymap[a]=index++;
            if(mymap.find(b)==mymap.end())
                mymap[b]=index++;
            x=mymap[a];
            y=mymap[b];
            relation[x].pb(y);
//            relation[y].pb(x);
        }
        for(int i=0;i<index; i++)
            if(!once[i])
            {
                memset(visited, false, sizeof visited);
                dfs(i);
            }
        for(int i=0;i<index; i++)
            relation[i].clear();
        printf("Case %d: ", qq);
        if(cycle)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
