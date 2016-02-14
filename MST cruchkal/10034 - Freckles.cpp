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
//Minimum spanning tree
using namespace std;

class MST{
public:
    vector<int>parent;
    int elements,totalEdge;
    vector<pair<float ,pair<int,int> > > v;
    void input(float cost,int node1, int node2);
    int rooting(int a);
    bool makeUnion(int a,int b);
    void initialize(int total);
    float findFirstMst();
};

void MST::input(float cost,int node1, int node2)
{
    v.push_back(make_pair(cost,make_pair(node1,node2)));
}
int MST::rooting(int a)
{
    if(parent[a]==a)
        return a;
    return (parent[a]=rooting (parent[a]));
}


bool MST::makeUnion(int a,int b)
{
    int p,q;
    p=rooting(a);
    q=rooting(b);
    if(p==q)
        return false;
     parent[p]=parent[q];
    return true;
}


void MST::initialize(int total)
{
    for(int i=0;i<=total;i++)
    {
        parent.push_back(i);
    }
}


float MST::findFirstMst()
{
    sort(v.begin(),v.end());
    totalEdge=v.size();
    float costing=0;
    int edgeUsed=0;
    initialize(elements);

    for(int i=0;i<totalEdge;i++)
    {
        if(makeUnion(v[i].second.first,v[i].second.second))
        {
            costing+=v[i].first;
            edgeUsed++;
            if(edgeUsed==(elements-1))
                return costing;
        }
    }
}

float distance(float p1x, float p1y, float p2x, float p2y)
{
    float ret=sqrt(pow(p1x-p2x, 2)+pow(p1y-p2y, 2));
    return ret;
}
int main ()
{
    int testCase,pairs,cost,cities,counter=0,z;
    int x,y;
//    freopen("in.txt","r",stdin);
    cin>>testCase;
    for(int qq=1;qq<=testCase;qq++)
    {
        MST obj;
        cin>>x;
        obj.elements=x;
        float coX[x+2],coY[x+2];
        for(int i=1;i<=x;i++)
            cin>>coX[i]>>coY[i];

        for(int i=1;i<x;i++)
            for(int j=i+1; j<=x; j++)
            {
                float cost=distance(coX[i], coY[i], coX[j], coY[j]);
                obj.input(cost, i,j);
            }
        float cost=obj.findFirstMst();
        if(qq!=1)
            printf("\n");
        printf("%.2f\n", cost);

    }
    return 0;
}
