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
//This MST class was verified in 10600
//Aced
using namespace std;
class MST{
public:
    vector<int>parent;
    int elements,totalEdge;
    int costing;
    vector<pair<int,pair<int,int> > > v;//for saving the edgeLIst
    void setElemntNumber(int x){elements=x;}
    int rooting(int a);
    bool makeUnion(int a,int b);
    void initialize(int total);
    int findFirstMst();

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
}


int MST::findFirstMst()
{
    sort(v.begin(),v.end());//sorting the edges according to cost
    totalEdge=v.size();
    costing=0;
    int edgeUsed=0;
    initialize(elements);//initializin parents
    
    for(int i=0;i<totalEdge;i++)
    {
        if(makeUnion(v[i].second.first,v[i].second.second))
        {
//            usedEdges.push_back(i);
            costing+=v[i].first;
            edgeUsed++;
            if(edgeUsed==elements-1)
                return costing;               //all the nodes have been spanned 
        }
    }
    return costing;//no solution
}



int main ()
{
    int nodes,cost1,cost2,x,y,newEdge,oldEdge,serial=1;
    while(scanf("%d", &nodes)!=EOF)
    {
        cost1=0;
        if(serial==1)
            serial++;
        else
            printf("\n");
        for(int i=1;i<nodes;i++)
        {
            scanf("%*d %*d %d", &cost2);
            cost1+=cost2;
        }
        printf("%d\n", cost1);
        MST obj;
        obj.elements=nodes;
        scanf("%d", &newEdge);
        while(newEdge--)
        {
            scanf("%d %d %d", &x,&y,&cost2);
            obj.v.pb(mp(cost2, mp(x,y)));
        }
        scanf("%d", &oldEdge);
        while(oldEdge--)
        {
            scanf("%d %d %d", &x,&y,&cost2);
            obj.v.pb(mp(cost2, mp(x,y)));           
        }
        printf("%d\n", obj.findFirstMst());
        
    }
    return 0;
}



