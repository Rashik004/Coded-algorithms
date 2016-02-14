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
using namespace std;

class MST{
public:
    vector<int>parent;
    int elements,costing,totalEdge;
    vector<pair<int,pair<int,int> > > v;
    void input(int cost,int node1, int node2);
    int rooting(int a);
    bool makeUnion(int a,int b);
    void initialize(int total);
    int findFirstMst();
    int findMaxSt();
};

void MST::input(int cost,int node1, int node2)
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


int MST::findFirstMst()
{
    sort(v.begin(),v.end());
    totalEdge=v.size();
    costing=0;
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

int MST::findMaxSt()
{
    totalEdge=v.size();
    parent.clear();
    costing=0;
    int edgeUsed=0;
    initialize(elements);

    for(int i=totalEdge-1;i>=0;i--)
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
        obj.elements=x+1;
        while(cin>>x>>y>>z)
        {
            if(!x && !y && !z)
                break;
            obj.input(z,x,y);
        }
        int cost=obj.findFirstMst();
        cost+=obj.findMaxSt();
        printf("Case %d: ", qq);
        if(cost%2)
            printf("%d/2\n", cost);
        else
            printf("%d\n", cost/2);

    }
    return 0;
}
