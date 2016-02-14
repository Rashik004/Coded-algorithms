 #include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define vi vector<int>
#define MAX 55
using namespace std;
vector<pair <int, pair<int, int> > > v;
int parent[MAX];

int root(int node)
{
    if(parent[node]==node)
        return node;

    return parent[node]=root(parent[node]);
}

bool makeUnion(int a, int b)
{
    int p,q;
    p=root(a);
    q=root(b);
    if(p==q)
        return false;
    parent[p]=parent[q];
    return true;
}


int findFirstMST(int totalNode)
{
    if(totalNode==1)
        return 0;
    for(int i=0;i<=totalNode; i++)
        parent[i]=i;
    sort(v.begin(), v.end());
    int tEdge=v.size();
    int cost=0,used=0;
    for(int i=0;i<tEdge; i++)
    {
        if(makeUnion(v[i].second.first, v[i].second.second))
        {
            cost+=v[i].first;
            used++;
            if(used==totalNode-1)
            {
                v.clear();
                return cost;
            }
        }
    }
    v.clear();
    return -1;
}

int main()
{
    int testCase,x,y,m,n,k;
    cin>>testCase;
    for(int qq=1;qq<=testCase;qq++)
    {
        cin>>n;
        int totCable=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                cin>>x;
                totCable+=x;
                if(x)
                    v.pb(mp(x, mp(i,j)));
            }

        int res=findFirstMST(n);
        printf("Case %d: ", qq);
        if(res==-1)
            cout<<res<<endl;
        else
            cout<<totCable-res<<endl;

    }
    return 0;
}
