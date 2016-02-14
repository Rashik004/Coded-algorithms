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
#define ELE 1025000
using namespace std;
//not tested yet
int ary[ELE],save[3*ELE],prop[3*ELE];
//memset(prop,0,sizeof prop);


int makeTree(int node,int leftLim,int rightLim)
{
    if(leftLim==rightLim)
        return save[node]=ary[leftLim];
        
    int x,y;
    x=makeTree(2*node,leftLim,(leftLim+rightLim)/2);
    y=makeTree(2*node+1,(leftLim+rightLim)/2+1,rightLim);
    return save[node]=x+y;
}




void updateTree(int node,int leftLim,int rightLim, int givenLeft, int givenRight,int value)
{    
    if(leftLim>givenRight || rightLim<givenLeft)return;
    
    if(leftLim>=givenLeft && rightLim<=givenRight)
    {
        save[node]+=(rightLim-leftLim+1)*value;
        prop[node]+=value;
        return;
    }
    
    int left,right,mid;
    left=node*2;
    right=node+1;
    mid=(leftLim+rightLim)/2;
    
    updateTree(2*node, leftLim,mid,givenLeft,givenRight,value);
    updateTree(2*node+1,mid+1,rightLim,givenLeft,givenRight,value);
    
    save[node]=save[2*node]+save[2*node+1]+(rightLim-leftLim+1)*prop[node];//if this save [node] was previously upgraded then prop[node] will be non-zero
    
}

int query(int node, int leftLim, int rightLim, int givenLeft,int givenRight, int carry)
{
    if(leftLim>givenRight || rightLim<givenLeft) return 0;
    
    if(leftLim>=givenLeft && rightLim<=givenRight)
        return save[node]+(rightLim-leftLim+1)*carry;
        
    int p,q,mid;
    mid=(leftLim+rightLim)/2;
    p=query(2*node,leftLim,mid,givenLeft,givenRight,carry+prop[node]);
    q=query(2*node+1,mid+1,rightLim,givenLeft,givenRight,carry+prop[node]);
    
    return p+q;
}