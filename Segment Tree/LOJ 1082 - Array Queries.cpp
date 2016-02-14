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
#define ELE 100009
#define maxM 1<<30
using namespace std;
int ary[ELE],save[3*ELE];

int makeTree(int leftLim,int rightLim, int node)
{
    if(leftLim==rightLim)
        return save[node]=ary[leftLim];

    int x,y;
    x=makeTree(leftLim,(leftLim+rightLim)/2,2*node);
    y=makeTree((leftLim+rightLim)/2+1,rightLim,2*node+1);
    return save[node]=min(x,y);
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
    return min(x,y);
}

int main ()
{
//    freopen("out.txt","w",stdout);
    int testCase,element,q,x,y;
    scanf("%d", &testCase);
    for(int qq=1;qq<=testCase; qq++)
    {
        scanf("%d %d", &element, &q);
        for(int i=1;i<=element;i++)
            scanf("%d", &ary[i]);

        makeTree(1,element,1);
        printf("Case %d:\n", qq);
        while(q--)
        {
            scanf("%d %d", &x, &y);
            printf("%d\n", query(1,element,x,y,1));

        }
    }
    return 0;
}
