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
vi relation[210];
int bfs(int source,int target)
{
    vector<int> v1,v2;
    if(source==target)
        return 0;
    int taken[1000];
    memset(taken,0,sizeof taken);
    taken[source]=1;
    v1.push_back(source);
    int loop=0;
    while(2)
    {
        loop++;
        for(int i=0; i<v1.size(); i++)
        {
            int u=v1[i];
            for(int j=0; j<relation[u].size(); j++)
            {
                int v=relation[u][j];//nodes those has realtion with node u
                if(v==target)
                    return loop;
                if(!taken[v])//to aviod once visited nodes
                {
                    v2.push_back(v);
                    taken[v]=1;
                }
            }
        }
        
        
            v1.clear();
            v1=v2;
            v2.clear();//making v1=v2 & clearing v2
        
    }
}
bool trans(string a,string b)
{
    bool change=false;
    if(a==b)
        return false;
    if (a.size()==b.size())
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i] && !change)
                change=true;
            else if(a[i]!=b[i] && change)
                return false;
        }
        return true;
    }
    return false;
}


int main ()
{
//    freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,x,y;
    string abc,source,target;
    char dhoor[1000];
    cin>>testCase;
    for(int qq=1;qq<=testCase;qq++)
    {
        if(qq!=1)
            cout<<endl;
        vector<string>dicktion;
        map<string,int> indexing;
        
        int index=0;
        while(cin>>abc)
        {
            if(abc=="*")
                break;
            dicktion.pb(abc);
            indexing[abc]=index++;
        }
        getchar();
        for(int i=0;i<index;i++)
        {
            for(int j=0;j<index;j++)
            {
                if(i==j)
                    continue;
                if(trans(dicktion[i],dicktion[j]))//trans function detects if two words are transformable from each other
                    relation[i].pb(j);//if two words are transformable from each other then y will be adjacent
            }
        }
        
        while(getline(cin,abc))
        {
            if(!abc.size())//for detecting blank line
                break;
            stringstream s;
            s<<abc;
            s>>source>>target;
            cout<<source<<' '<<target<<' '<<bfs(indexing[source],indexing[target])<<endl;//the map indexing is used to find out the index number of source and target
        }
        
        for(int i=0;i<=index;i++)
            relation[i].clear();
            
    }
    return 0;
}




