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
#define ELE 200000
using namespace std;

int ary[ELE],save[3*ELE];



int makeTree(int leftLim,int rightLim, int node)
{
    if(leftLim==rightLim)
        return save[node]=ary[leftLim];
        
    int x,y;
    x=makeTree(leftLim,(leftLim+rightLim)/2,2*node);
    y=makeTree((leftLim+rightLim)/2+1,rightLim,2*node+1);
    return save[node]=x+y;
}


int query(int rangeStart,int rangeFin,int givenLeft,int givenRight,int node)
{
    if(rangeStart>givenRight||rangeFin<givenLeft)
        return 0;
        
    if(rangeStart>=givenLeft && rangeFin<=givenRight)
        return save[node];
    
    int x,y;
    x=query(rangeStart,(rangeStart+rangeFin)/2,givenLeft,givenRight,node*2);
    y=query((rangeStart+rangeFin)/2+1,rangeFin,givenLeft,givenRight,node*2+1);
    return x+y;
}


int updateTree(int leftLim,int rightLim, int node, int x,int value)
{
    if(leftLim==rightLim && leftLim==x)
        return save[node]=value;
    
    if(leftLim>x || rightLim<x)
        return save[node];
    
    int a,b;
    a=updateTree(leftLim,(leftLim+rightLim)/2, 2*node,x,value);
    b=updateTree((leftLim+rightLim)/2+1, rightLim, 2*node+1, x, value);
    
    return save[node]=a+b;

    
}

int main()
{
    int x,y,n,val,serial=0;
    char str[5];
    freopen("out.txt", "w", stdout);
    while(scanf("%d", &n))
    {
        if(!n)
            break;
        for(int i=1;i<=n;i++)
            scanf("%d", &ary[i]);
            
            if(!serial)
                serial++;
            else
                printf("\n");
        printf("Case %d:\n", serial++);
        makeTree(1,n,1);
        while(scanf("%s", str))
        {
            if(str[0]=='E')
                break;

            scanf("%d %d", &x,&y);
            if(str[0]=='M')
                printf("%d\n", query(1,n,x,y,1));
            else
                updateTree(1,n,1,x,y);
        }
    }
}