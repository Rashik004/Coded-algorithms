//      ***RASHIK HASNAT***     KUET_DOUR.01
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<ctime>
using namespace std;
void bfs(int n, int source);
vector <int> relation[1000];
vector<int> cost[1000];
int main ()
{
    int x,y;
    while(cin>>x>>y)// taking relation & considering them as bidirectional
    {
        if(x==0 && y==0)// when graph is taken then input 0 0 for terminating input
        break;
        relation[x].push_back(y);
        relation[y].push_back(x);
    }
    while(2)
    {
        printf("ENTER SOURCE\n");
        cin>>x;
        if(x<0)
        break;
        bfs(1, x);
    }
	return 0;
}
void bfs(int n, int source)
{
    vector<int> v1,v2;
    int taken[1000];
    memset(taken,0,sizeof taken);//first no nodes are visited
    taken[source]=1;//source is visited once
    v1.push_back(source);//source is taken to the first vector
    printf("Level 0= %d\n", source);
    for(int loop=1; loop<n; loop++)// you dont have to circle the loops more than n-1 times
    {
        printf("level %d= ", loop);
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
                    printf("%d ", v);
                }
            }
        }
        if(v2.empty())//when v2 is empty that means all the nodes has been visited :D
        {
            printf("EMPTY\n");
            break;
        }
        else
        {
            printf("\n");
            v1.clear();
            v1=v2;
            v2.clear();//making v1=v2 & clearing v2
        }
    }
}
// Reference: গ্রাফ থিওরিতে হাতেখড়ি-৩,৫ ()শাফায়াতের বাংলা ব্লগ
