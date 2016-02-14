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
vector<int>parent;
int rooting(int a)
{
    if(parent[a]==a)
        return a;
    return (parent[a]=rooting (parent[a]));
}

bool makeUnion(int a,int b)
{
    int p,q;
    p=rooting(a);
    q=rooting(b);
    if(p==q)
        return false;
     parent[p]=parent[q];
    return true;
}

void intialize(int total)
{
    for(int i=0;i<=total;i++)
    {
        parent.push_back(i);
    }
}
int main ()
{
    int testCase,school,connection,node1,node2,cost ;
//    freopen("in.txt","r",stdin);
    cin>>testCase;
    
    while(testCase--)
    {
        cin>>school>>connection;
        int costing=0;
        int edgeUsed=0;
        vector<pair<int, pair<int,int> > > v;
        vector<int>usedEdges;
        int copyC=connection;
        intialize(school);
        while(connection--)
        {
            cin>>node1>>node2>>cost;
            v.push_back(make_pair(cost,make_pair(node1,node2)));
        }
        sort(v.begin(),v.end());//sorting according to cost is done
        
        for(int i=0;i<copyC;i++)
        {
            if(makeUnion(v[i].second.first,v[i].second.second))
            {
                usedEdges.push_back(i);
                costing+=v[i].first;
                edgeUsed++;
                if(edgeUsed>=(school-1))
                    break;
            }    
        }
        cout<<costing<<" ";//minimum spanning cost is found
        
       
        costing=edgeUsed=0;
        int lowest_costing=1<<15;//lowest_cost=2^15
        vector<int>temp,ans;
        
        for(int j=0;j<usedEdges.size();j++)
        {
            costing=edgeUsed=0;
            parent.clear(); //to start a new one
            intialize(school);
            for(int i=0;i<copyC;i++)
            {
                if(i==usedEdges[j])
                    continue;//1ta kore edge baad die dekha hobe
                if(makeUnion(v[i].second.first,v[i].second.second))
                {
                    costing+=v[i].first;
                    if(costing>lowest_costing)
                        break;
                        edgeUsed++;
                    if(edgeUsed>=(school-1))
                        break;
                }
            }
            if(costing<lowest_costing && edgeUsed==(school-1))//if edgeUsed<school-1 then the tree doesn't span all the nodes
                lowest_costing=costing;//to see if it is the second best

        }   
        cout<<lowest_costing<<endl;
        parent.clear(); 
    }
    return 0;
}