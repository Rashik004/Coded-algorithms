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
#define INFINITY 1<<30
using namespace std;
int costing[25][25],d[25][25];
//floyd warshall apsp
void apsp(int n)
{
    int temp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(j==i)// this is an important line of this apsp!!!
                d[i][j]=0;
            else if(costing[i][j]==-1)
                d[i][j]=INFINITY;
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

int main ()
{
    int member,road,x,y,k,temp,lowest,lowestIndex,serial=1;
    char names[25][12];
    
    while(scanf("%d %d", &member, &road) && member)
    {
        memset(costing,-1,sizeof costing);
        for(int i=1;i<=member;i++)
            scanf("%s", names[i]);
        for(int i=1;i<=road;i++)
        {
            scanf("%d %d %d", &x, &y, &k);
            costing[x][y]=k;
            costing[y][x]=k;
        }
        
        apsp(member);
        lowest=INFINITY;
        for(int i=1;i<=member;i++)
        {
            temp=0;
            for(int j=1;j<=member;j++)
            {
                if(j==i)
                    continue;
                temp+=d[i][j];
            }
            if(temp<lowest)
            {
                lowest=temp;
                lowestIndex=i;
            }
            
        }
        printf("Case #%d : %s\n", serial++, names[lowestIndex]);
    }
    return 0;
}