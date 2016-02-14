#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int ary[100005],save[300020],maxM;

int minM(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

int makeTree(int leftLim,int rightLim, int node)
{
    if(leftLim==rightLim)
        return save[node]=ary[leftLim];
        
    int x,y;
    x=makeTree(leftLim,(leftLim+rightLim)/2,2*node);
    y=makeTree((leftLim+rightLim)/2+1,rightLim,2*node+1);
    return save[node]=minM(x,y);
}

int query(int rangeStart,int rangeFin,int givenLeft,int givenRight,int node)
{
    if(rangeStart>givenRight||rangeFin<givenLeft)
        return maxM;
        
    if(rangeStart>=givenLeft && rangeFin<=givenRight)
        return save[node];
    
    int x,y;
    x=query(rangeStart,(rangeStart+rangeFin)/2,givenLeft,givenRight,node*2);
    y=query((rangeStart+rangeFin)/2+1,rangeFin,givenLeft,givenRight,node*2+1);
    return minM(x,y);
}


int main ()
{
    maxM=1<<20;
    int testCase, q,n,x,y;
    scanf("%d", &testCase);
    for(int i=1;i<=testCase;i++)
    {
        cin>>n>>q;
        for(int j=1;j<=n;j++)
            scanf("%d", &ary[j]);
        makeTree(1,n,1);
        printf("Case %d:\n",i);
        while(q--)
        {
            scanf("%d %d", &x,&y);
            printf("%d\n",query(1,n,x,y,1));
        }
    }
    return 0;
}