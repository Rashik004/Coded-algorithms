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
//ACed
class MST{
public:
    vector<int>parent,usedEdges;
    int elements,costing,second_best,totalEdge;
    vector<pair<int,pair<int,int> > > v;
    void input(int cost,int node1, int node2);
    int rooting(int a);
    bool makeUnion(int a,int b);
    void initialize(int total);
    int findFirstMst();
    int findSecondMst();
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
            usedEdges.push_back(i);
            costing+=v[i].first;
            edgeUsed++;
            if(edgeUsed==(elements-1))
                return costing;                
        }
    }
}

int MST::findSecondMst()
{
    int edgeUsed=0,fin;
    second_best=1<<15;
    
    
    for(int j=0;j<elements-1;j++)
    {
        int costNow=0;
        edgeUsed=0;
        parent.clear();
        initialize(elements);
        
        for(int i=0;i<totalEdge;i++)
        {
            if(i==usedEdges[j])
                continue;
            if(makeUnion(v[i].second.first,v[i].second.second))
            {
                costNow+=v[i].first;
                edgeUsed++;
                if(edgeUsed==elements || costNow>=second_best)
                    break;
            }
            
            
        }
        if(costNow<second_best && edgeUsed==(elements-1))
        {
            second_best=costNow;
//            if(second_best==costing)
//                return second_best;
        }
    }        
    return second_best;
}

int main ()
{
    int testCase,school,connection,node1,node2,cost ;
//    freopen("in.txt","r",stdin);
    cin>>testCase;
    
    while(testCase--)
    {
        cin>>school>>connection;
        MST obj;
        obj.elements=school;
        while(connection--)
        {
            cin>>node1>>node2>>cost;
            obj.input(cost,node1,node2);
        }
        
        cout<<obj.findFirstMst()<<" ";
        cout<<obj.findSecondMst()<<endl;
        
         
    }
    return 0;
}