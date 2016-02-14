#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<utility>
#include<complex>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<deque>
#include<list>
#include<stdexcept>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<ctime>
#define ELE 109
#define MAX 1<<10
using namespace std;
//apsp Floyd warshall
int d[ELE][ELE], costing[ELE][ELE];

void apsp(int n)
{
    int temp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(costing[i][j]==-1)
                d[i][j]=MAX;
            else
                d[i][j]=costing[i][j];
        }
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                
                temp=d[i][k]+d[k][j];
                if(temp<d[i][j])
                {
                    d[i][j]=temp;
                }
            }
}
int main()
{
    int x,y,index,total,serial=1;
    float avg;
    while(scanf("%d %d", &x , &y) &&x &&y)
    {
        map<int, int> mymap;
        index=3;
        mymap[x]=1;
        mymap[y]=2;
        memset(costing, -1, sizeof costing);
        costing[1][2]=1;
        while(scanf("%d %d", &x, &y) &&x &&y)
        {
            if(mymap.find(x)==mymap.end())
                mymap[x]=index++;
            if(mymap.find(y)==mymap.end())
                mymap[y]=index++;
            costing[mymap[x]][mymap[y]]=1;
        }
        apsp(index-1);
        total=0;
        int pairs=0;
        for(int i=1;i<index;i++)
            for(int j=1;j<index;j++)
            {
                if(i==j)
                    continue;
                pairs++;
                total+=d[i][j];
            }
        avg=total*1.0/pairs;
        printf("Case %d: average length between pages = %.3f clicks\n",serial++, avg);
        
    }
    return 0;
}