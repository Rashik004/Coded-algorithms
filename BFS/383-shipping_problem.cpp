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
    int shortest_path(int element,int source, int target);

};


int Shortest::shortest_path(int element,int source, int target)
{
      vector<int> taken(1000,0);//the array 'parent' is used to store the parent node of a derived node
    vector<int> v1,v2;
    taken[source]=1;//source has been visited once
    v1.push_back(source);
     for(int loop=1; loop<element; loop++)
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
                    if(v==target)
                       return loop;
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
    return 0;
}

int main ()
{
    int test;
    cin>>test;
    
    for(int i=1;i<=test;i++)
    {
        if(i==1)
            cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
        printf("DATA SET  %d\n\n",i);
        int m,n,p;
        cin>>m>>n>>p;
        
        Shortest ob;
        string x,y;
        int a=0;
        map<string,char> trace;
        
        for(int q=0;q<m;q++)
        {
            cin>>x;
            trace[x]=a++;
        }
        
        while(n--)
        {
            cin>>x>>y;
            ob.relation[trace[x]].push_back(trace[y]);
            ob.relation[trace[y]].push_back(trace[x]);
        }
        
        int weight,costing;
        while(p--)
        {
            cin>>weight>>x>>y;
            costing=ob.shortest_path(m,trace[x],trace[y]);
            if(costing)
                printf("$%d\n", costing*100*weight);
            else
                printf("NO SHIPMENT POSSIBLE\n");
        }
        
        cout<<endl;
        
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}