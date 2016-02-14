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
#define ELE 100000+4
using namespace std;

int save[3*ELE];

void change(char x)
{
    if(x=='0') printf("1\n");
    else printf("0\n");
}

int update(int rangeStart,int rangeFin,int givenLeft,int givenRight,int node)
{

    if(rangeStart>givenRight||rangeFin<givenLeft)//if current range is fully out of update range
        return 0;

    if(rangeStart>=givenLeft && rangeFin<=givenRight)//if current range is fully in update range
        return save[node]++;

    int x,y;
    x=update(rangeStart,(rangeStart+rangeFin)/2,givenLeft,givenRight,node*2);
    y=update((rangeStart+rangeFin)/2+1,rangeFin,givenLeft,givenRight,node*2+1);
    return x+y;
}


int query(int rangeStart,int rangeFin, int index, int node)
{

    if(rangeStart>index || rangeFin<index)
        return 0;

    if(rangeStart==index && rangeFin==index)
        return save[node];

    //if the given index lies within the current range
    int x,y;
    x=query(rangeStart,(rangeFin+rangeStart)/2, index, node*2);
    y=query((rangeFin+rangeStart)/2+1, rangeFin, index, node*2+1);
    return save[node]+x+y;

}

int main()
{
    int testCase,x,y,m,n,k,q,i,j;
    char num[ELE];
    //freopen("out.txt", "w", stdout);
    scanf("%d", &testCase);
    char choice;
    for(int qq=1;qq<=testCase;qq++)
    {
        memset(save, 0, sizeof save);
        scanf("%s", num);
        n=strlen(num);
        scanf("%d", &q);
        printf("Case %d:\n", qq);
        int x,y;
        for(int i=1; i<=q; i++)
        {
            scanf("%c", &choice);

            if(choice=='I')
            {
                scanf("%d %d", &x, &y);
                update(1,n,x,y,1);
            }
            else if(choice=='Q')
            {
                scanf("%d", &x);
                int res=query(1,n,x,1);
                if(res%2)
                    change(num[x-1]);
                else
                    printf("%c\n", num[x-1]);
            }

            else //habijabi character jhamela kortes tai
                i--;
        }

    }
    return 0;
}
