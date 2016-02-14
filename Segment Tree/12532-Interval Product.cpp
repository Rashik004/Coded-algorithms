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
#define ELE 100005
using namespace std;

int ary[ELE],save[2*ELE],maxM,high=0;



int makeTree(int leftLim,int rightLim, int node)
{
    if(high<node)
        high=node;
    if(leftLim==rightLim)
    {
        if(!ary[leftLim])
            save[node]=maxM;
        else if(ary[leftLim]<0)
            save[node]=1;
        else
            save[node]=0;
        
        return save[node];
    }
        
    int x,y;
    x=makeTree(leftLim,(leftLim+rightLim)/2,2*node);
    y=makeTree((leftLim+rightLim)/2+1,rightLim,2*node+1);
    
    if(x==maxM || y==maxM)
        return save[node]=maxM;
    
    else if((x+y)==1)
        return save[node]=1;
    
    else
        return save[node]=0;
    
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
    
    if(x==maxM || y==maxM)
        return maxM;
    
    else if((x+y)==1)
        return 1;
    
    else
        return 0;
}


int updateTree(int leftLim,int rightLim, int node, int x,int value)
{
    if(leftLim==rightLim && leftLim==x)
    {
        if(!value)
            save[node]=maxM;
        else if(value<0)
            save[node]=1;
        else
            save[node]=0;
        
        return save[node];
    }
    
    if(leftLim>x || rightLim<x)
        return save[node];
    
    int a,b;
    a=updateTree(leftLim,(leftLim+rightLim)/2, 2*node,x,value);
    b=updateTree((leftLim+rightLim)/2+1, rightLim, 2*node+1, x, value);
    
    if(a==maxM || b==maxM)
        return save[node]=maxM;
    
    else if((a+b)==1)
        return save[node]=1;
    
    else
        return save[node]=0;
}

int main()
{
    maxM=1<<18;
    int k,n,x;
//    freopen("out.txt", "w", stdout);
    while(scanf("%d %d", &n,&k)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d", &ary[i]);
        makeTree(1,n,1);
        
//        for(int i=1;i<=high;i++)
//            printf("%d ", save[i]);

        
        int l,v,result;
        
        while(k--)
        {
            char choice;
            getchar();
            scanf("%c %d %d", &choice, &l,&v);
            if(choice=='C')
                updateTree(1,n,1,l,v);
            else
            {
                result=query(1,n,l,v,1);
                if(result==maxM)
                    printf("0");
            
                else if(result==1)
                    printf("-");
            
                else
                    printf("+");
                    
//                printf("\n");
            }
        }
        printf("\n");
    }
}