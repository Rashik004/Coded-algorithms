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

//ACed
using namespace std;
class Shortest{
public:
    vector<int>relation[32];
    int shortest_path(int source, int ttl);
    int element;
};


int Shortest::shortest_path(int source, int ttl)
{
      vector<int> taken(1000,0);//the array 'parent' is used to store the parent node of a derived node
    vector<int> v1,v2;
    int visited=1;
    taken[source]=1;//source has been visited once
    v1.push_back(source);
     for(int loop=1; loop<=ttl; loop++)
    {
        for(int i=0; i<v1.size(); i++)
        {
            int u= v1[i];
            for(int j=0; j<relation[u].size(); j++)
            {
                int v=relation[u][j];
                if(!taken[v])
                {
                    taken[v]=1;//here v is firstly derived from u
                    visited++;
                    v2.push_back(v);
                }

            }
        }
        if(v2.empty())
            return 0;
        else
        {
            v1.clear();
            v1=v2;
            v2.clear();
        }
    }
    return (element-visited);
}

int main()
{
//    freopen("bfs.txt","r",stdin);
//    freopen("nfsout.txt","w",stdout);
    int caseCounter=1;
    while(2)
    {
        int test,i=0;
        cin>>test;
        if(!test)
            return 0;
        map<int,int>my;
        Shortest ob;
        ob.element=test;
        int x,y;
        while(test--)
        {
            
            cin>>x>>y;
            if(my.find(x)==my.end())
                my[x]=i++;
            if(my.find(y)==my.end())//if there is no such element with this key find() will return my::end iterator more at http://www.cplusplus.com/reference/map/map/find/
            if(my.find(y)==my.end())//if there is no such element with this key find() will return my::end iterator more at http://www.cplusplus.com/reference/map/map/find/
                my[y]=i++; 
                
            ob.relation[my[x]].push_back(my[y]);
            ob.relation[my[y]].push_back(my[x]);
        }
        while(2)
        {
            cin>>x>>y;
            if(x==0 && y==0)
                break;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",caseCounter++,ob.shortest_path(my[x],y),x,y);
        }
    }
    return 0;
}