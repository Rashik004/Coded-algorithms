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
vector<int>parent,counting;
int high;
int rooting(int a)
{
    if(parent[a]==a)
        return a;
    return (parent[a]=rooting (parent[a]));
}
void initialize(int x)
{
    parent.clear();
    counting.clear();
    for(int i=0; i<=x;i++)
    {
        parent.push_back(i);
        counting.push_back(1);
    }
}
void makeUnion(int a,int b)
{
    int p,q;
    p=rooting(a);
    q=rooting(b);
    if(p==q)
    {
        //cout<<"they are same"<<endl;
        return;
    }
     counting[parent[q]]+=counting[parent[p]];
     if(high<counting[parent[q]])
        high=counting[parent[q]];
     parent[p]=parent[q];
   
}
int main ()
{
    int testCase,citizen,pairs,x,y;
//    freopen("in.txt","r",stdin);
    cin>>testCase;
    while(testCase--)
    {
        cin>>citizen>>pairs;
        high=-12;
        initialize(citizen);
        while(pairs--)
        {
            cin>>x>>y;
            makeUnion(x,y);
        }
        cout<<high<<endl;
    }
    return 0;
}