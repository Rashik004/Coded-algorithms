//maximum spanning tree, mst, uva 544, ACed 15/7/2014
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
using namespace std;
int parent[300];
int rooting(int a)
{
    if(parent[a]==a)
        return a;
    return (parent[a]=rooting (parent[a]));
}


void intialize(int total)
{
    for(int i=0;i<=total;i++)
        parent[i]=i;
}
int main()
{
    int city,road,x,city1,city2,cost,y,serial=1;

    string cityName,s,d;

    while(cin>>city>>road && serial)
    {
        if(!city && !road)
            return 0;
        priority_queue<pair<int, pair<int,int> > > edge;
        map<string,int>mymap;
        x=0;
        intialize(city+3);
        while(road--)
        {
            cin>>cityName;
            if(mymap.find(cityName)==mymap.end())
                mymap[cityName]=x++;

            city1=mymap[cityName];

            cin>>cityName;
            if(mymap.find(cityName)==mymap.end())
                mymap[cityName]=x++;

            city2=mymap[cityName];
            cin>>cost;
            edge.push(mp(cost,mp(city1,city2)));
        }
        cin>>s>>d;
        int source,destination;
        source=mymap[s];
        destination=mymap[d];
        int minCap=1<<22,now=1<<22;


        while(2)
        {
            if(rooting(source)==rooting(destination))
                break;
            now=edge.top().first;
            city1=edge.top().second.first;
            city2=edge.top().second.second;
            edge.pop();

            x=rooting(city1);
            y=rooting(city2);
            if(x==y)
                continue;
            parent[x]=parent[y];
            minCap=min(now,minCap);
        }

        printf("Scenario #%d\n%d tons\n\n",serial++,minCap);
    }
    return 0;
}
