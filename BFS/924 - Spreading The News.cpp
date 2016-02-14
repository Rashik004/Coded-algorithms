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
vi relation[2600];
void bfs(int source)
{
    vector<int> v1,v2;
    int taken[2600];
    memset(taken,0,sizeof taken);//first no nodes are visited
    taken[source]=1;//source is visited once
    v1.push_back(source);
    int day=0;
    int high=0,highDay;
    while(2)
    {
        day++;
        for(int i=0; i<v1.size(); i++)
        {
            int u=v1[i];
            for(int j=0; j<relation[u].size(); j++)
            {
                int v=relation[u][j];//nodes those has realtion with node u
                if(!taken[v])//to aviod once visited nodes
                {
                    v2.push_back(v);
                    taken[v]=1;
                }
            }
        }
        if(v2.empty())//when v2 is empty that means all the nodes has been visited :D
        {
            if(high==0)
                printf("0\n");
            else
                printf("%d %d\n", high,highDay);
            return;
        }
        else
        {
            int temp=v2.size();
            if(temp>high)
            {
                high=temp;
                highDay=day;
            }
            v1.clear();
            v1=v2;
            v2.clear();//making v1=v2 & clearing v2
        }
    }
}

int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,x,y;
    int emp,n;
    cin>>emp;
    for(int i=0;i<emp;i++)
    {
        cin>>n;
        while(n--)
        {
            cin>>x;
            relation[i].pb(x);
        }
    }
    cin>>testCase;
    while(testCase--)
    {
        cin>>x;
        bfs(x);
    }
    return 0;
}




