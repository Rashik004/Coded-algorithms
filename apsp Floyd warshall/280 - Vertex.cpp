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

vi relation [110];
bool reach[110];

int bfs(int node)
{
    queue<int>q;
    q.push(node);
    int visited=0;
    while(q.empty()==false)
    {
        int temp1=q.front(),temp2;
        q.pop();
        for(int i=0;i<relation[temp1].size();i++)
        {
            temp2=relation[temp1][i];
            if(!reach[temp2])
            {
                reach[temp2]=true;
                visited++;
                q.push(temp2);
            }
        }
    }
    return visited;
}

#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<utility>
#include<complex>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<deque>
#include<list>
#include<stdexcept>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<ctime>
#define ELE 109
using namespace std;
bool d[ELE][ELE];
//apsp floyd warshall
void apsp(int n)
{
    int temp;
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                
                if(d[i][j])
                    continue;
                if(d[i][k] && d[k][j])
                {
                    d[i][j]=true;
                }
            }
}

int main ()
{
    int x,y,inAcc;
    int nodes,i,j;
    bool start=true;
    while(cin>>nodes && nodes)
    {
        memset(d,false,sizeof d);
        while(cin>>x)
        {
            if(start && !x)
                break;
            else if(!start && !x)
            {
                start=true;
                continue;
            }
            else if(start && x)
            {
                i=x;
                start=false;
            }
            else if (!start && x)
            {
                d[i][x]=true;
            }
        }
        
        apsp(nodes);
        int q;
        cin>>q;
        while(q--)
        {
            cin>>y;
            inAcc=0;
            for(int i=1;i<=nodes;i++)
            {
                if(!d[y][i])
                    inAcc++;
            }
            cout<<inAcc;
            for(int i=1;i<=nodes;i++)
                if(!d[y][i])
                    cout<<' '<<i;
            cout<<endl;
        }
        
    }
    return 0;
}