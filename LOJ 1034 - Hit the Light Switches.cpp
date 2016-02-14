 #include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define vi vector<int>
#define MAX 100005
using namespace std;
bool visited[MAX],r1;
stack<int> st;

vi relation[MAX];

void dfs(int now)
{
    visited[now]=true;
    for(int i=0;i<relation[now].size(); i++)
        if(!visited[relation[now][i]])
            dfs(relation[now][i]);
    if(r1)
        st.push(now);
}


int main()
{
    int testCase,x,y,m,n,k;
    cin>>testCase;
    for(int qq=1;qq<=testCase;qq++)
    {
        cin>>n>>m;
        for(int i=1;i<=m; i++)
        {
            cin>>x>>y;
            relation[x].pb(y);
        }
        memset(visited, false, sizeof visited);
        r1=true;
        for(int i=1; i<=n; i++)
            if(!visited[i])
                dfs(i);
        r1=false;
        memset(visited, false, sizeof visited);
        int on=0;
        while(!st.empty())
        {
            int temp=st.top();
            st.pop();
            if(!visited[temp])
            {
                on++;
                dfs(temp);
            }
        }
        for(int i=0;i<=n; i++)
            relation[i].clear();
        printf("Case %d: %d\n", qq, on);

    }
    return 0;
}
