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
#define ELE 3000
using namespace std;
class SegmentTree{
public:
    int ary[ELE],save[3*ELE],maxM;
    SegmentTree();
    int makeTree(int leftLim,int rightLim, int node);
    int query(int rangeStart,int rangeFin,int givenLeft,int givenRight,int node);
    int updateTree(int leftLim,int rightLim, int node, int x, int value);
    void print(int );
};

SegmentTree::SegmentTree()
{
    maxM=1<<30;
}

int SegmentTree::makeTree(int leftLim,int rightLim, int node)
{
    if(leftLim==rightLim)
        return save[node]=ary[leftLim];

    int x,y;
    x=makeTree(leftLim,(leftLim+rightLim)/2,2*node);
    y=makeTree((leftLim+rightLim)/2+1,rightLim,2*node+1);
    return save[node]=min(x,y);
}

int SegmentTree::query(int rangeStart,int rangeFin,int givenLeft,int givenRight,int node)
{
    if(rangeStart>givenRight||rangeFin<givenLeft)
        return maxM;

    if(rangeStart>=givenLeft && rangeFin<=givenRight)
        return save[node];

    int x,y;
    x=query(rangeStart,(rangeStart+rangeFin)/2,givenLeft,givenRight,node*2);
    y=query((rangeStart+rangeFin)/2+1,rangeFin,givenLeft,givenRight,node*2+1);
    return min(x,y);
}

int SegmentTree::updateTree(int leftLim,int rightLim, int node, int x,int value)
{
    if(leftLim==rightLim && leftLim==x)
        return save[node]=value;

    if(leftLim>x || rightLim<x)
        return save[node];

    int a,b;
    a=updateTree(leftLim,(leftLim+rightLim)/2, 2*node,x,value);
    b=updateTree((leftLim+rightLim)/2+1, rightLim, 2*node+1, x, value);

    return save[node]=min(a,b);

}


void SegmentTree:: print(int n)
{
    for(int i=1;i<=n;i++)
        cout<<ary[i]<<" ";
    cout<<endl;
}
int main ()
{
    SegmentTree obj;
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>obj.ary[i];
    obj.print(n);

    obj.makeTree(1,n,1);
    int a,b;
    while(cin>>a>>b)
    {
        cout<<"The lowest number between "<<a<<"to "<<b<<"is "<<obj.query(1,n,a,b,1);
    }
    return 0;
}
