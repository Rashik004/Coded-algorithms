#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
//ACed
using namespace std;
vector<int>parent,counting;

int rooting(int a)
{
    if(parent[a]==a)
        return a;
    return (parent[a]=rooting (parent[a]));
}

void makeUnion(int a,int b)
{
    int p,q;
    p=rooting(a);
    q=rooting(b);
    if(p==q)
    {
        cout<<counting[parent[q]]<<endl;
        return;
    }
     counting[parent[q]]+=counting[parent[p]];
        cout<<counting[parent[q]]<<endl;
     parent[p]=parent[q];
   
}
int main ()
{
    int testCase,citizen,pairs;
    string x,y;
//    freopen("in.txt","r",stdin);
    cin>>testCase;
    while(testCase--)
    {
        cin>>pairs;
        int i=0;
        map<string,int>mymap;
        while(pairs--)
        {
            cin>>x>>y;
            if(mymap.find(x)==mymap.end())
            {
                counting.push_back(1);
                parent.push_back(i);
                mymap[x]=i++;
            }    
            if(mymap.find(y)==mymap.end())
            {
                counting.push_back(1);
                parent.push_back(i);
                mymap[y]=i++;
            }
            makeUnion(mymap[x],mymap[y]);
        }
        counting.clear();
        parent.clear();
    }
    return 0;
}