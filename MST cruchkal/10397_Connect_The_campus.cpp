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
// MST class was verified in 10600
//ACed
using namespace std;

class MST{
public:
    vector<int>parent;
    int elements,totalEdge,edgeUsed;
    vector<pair<double,pair<int,int> > > v;//for saving the edgeLIst
    void setElemntNumber(int x){elements=x;}
    int rooting(int a);
    bool makeUnion(int a,int b);
    void initialize(int total);
    double findFirstMst();
};


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
        return false;//no new bond is formed
     parent[p]=parent[q];
    return true;//new bond is formed
}


void MST::initialize(int total)
{
    for(int i=0;i<=total;i++)
    {
        parent.push_back(i);
    }
    edgeUsed=0;
}


double MST::findFirstMst()
{
    sort(v.begin(),v.end());//sorting the edges according to cost
    totalEdge=v.size();
    double costing=0;
    
    for(int i=0;i<totalEdge;i++)
    {
        if(makeUnion(v[i].second.first,v[i].second.second))
        {
            costing+=v[i].first;
            edgeUsed++;
            if(edgeUsed==elements-1)
                return costing;               //all the nodes have been spanned 
        }
    }
    return costing;//no m
}



int main ()
{
    int nodes,x,y;
    double cost;
    while(scanf("%d", &nodes)!=EOF)
    {
        vector<pair<int,int> > points;
        for(int i=0;i<nodes;i++)
        {
            scanf("%d %d", &x,&y);
            points.push_back(mp(x,y));
        }
        
        MST obj;
        obj.elements=nodes;
        obj.totalEdge=0;
        obj.initialize(nodes);
        int used;
        scanf("%d", &used);
        obj.edgeUsed=0;
        while(used--)
        {
            scanf("%d %d", &x, &y);
            if(obj.makeUnion(x,y))
                obj.edgeUsed++;
        }
        for(int i=0;i<nodes;i++)
            for(int j=i+1;j<nodes;j++)
            {
                x=points[i].first-points[j].first;
                y=points[i].second-points[j].second;
                cost=sqrt(x*x+y*y);
                obj.v.pb(mp(cost,mp(i+1,j+1)));
                obj.totalEdge++;
            }
//        printf("%lf\n", obj.findFirstMst());
        cout<<obj.findFirstMst()<<endl;
    }
    return 0;
}