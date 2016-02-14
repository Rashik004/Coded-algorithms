#include <bits/stdc++.h>
#define MAX_NODE 505
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define max(a,b)a>b?a:b
#define min(a,b)a<b?a:b
using namespace std;

struct edge{
    int weight;
    int node1;
    int node2;
};

class compareEdge{
public:
    bool operator()(edge e1, edge e2)
    {
        if(e1.weight<e2.weight) return false;
        else return true;
    }
};
//above code was for priority queue opertor overloading reference:http://comsci.liu.edu/~jrodriguez/cs631sp08/c++priorityqueue.html

int main()
{
    int testCase,x,y,totalNode, totalEdge, z,source, maxCost=-1;
    scanf("%d", &testCase);

    for(int qq=1;qq<=testCase;qq++)
    {
        scanf("%d %d", &totalNode, &totalEdge);
        maxCost=-1;
        vector<int > edgeDetail[totalNode+2];
        int weightDetail[MAX_NODE][MAX_NODE];
        bool visited[MAX_NODE];
        int costing[MAX_NODE];

        memset(visited,false,sizeof visited);
        memset(weightDetail, -1, sizeof weightDetail);
        memset(costing, -1, sizeof costing);

        for(int i=1;i<=totalEdge;i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            if(weightDetail[x][y]==-1)//if there is already a path between x& y no need to push them again
            {
                edgeDetail[x].pb(y);
                edgeDetail[y].pb(x);
            }
            else
                z=min(z,weightDetail[x][y]);//only the minimum weight of existing edges will be counted
            weightDetail[x][y]=z;
            weightDetail[y][x]=z;
        }

        scanf("%d", &source);
        visited[source]=true;
        costing[source]=0;

        priority_queue<edge, vector<edge>, compareEdge> pq;
        int reached=1;
        bool change;
        do
        {
            for(int i=0;i<edgeDetail[source].size();i++)
            {
                int adj=edgeDetail[source][i];
                if(visited[adj])
                    continue;
                edge temp;
                temp.node1=source;
                temp.node2=adj;
                temp.weight=weightDetail[source][adj];
                pq.push(temp);
            }

            change=false;
            while(!pq.empty())
            {
                edge temp=pq.top();
                source=temp.node2;
                pq.pop();
                if(!visited[source])
                {
                    reached++;
                    visited[source]=true;
                    change=true;
                    maxCost=max(maxCost, temp.weight);
                    costing[source]=maxCost;
                    break;
                }
            }

        }while(reached!=totalNode && change);

        printf("Case %d:\n", qq);
        for(int i=0;i<totalNode;i++)
            if(costing[i]==-1)
                printf("Impossible\n");
            else
                printf("%d\n", costing[i]);
    }

}
