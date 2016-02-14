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
int totR,totC;
char world[25][25],land;
int dirR[]={-1,+0,+1,+0}, dirC[]={+0,+1,0,-1};

int dfs(int row,int col)
{
    if(row>=0 && row<totR && col>=0 && col<totC)
    {
        if(world[row][col]!=land) return 0;
        int counting=1;
        world[row][col]='f';
        
        if(col==0)
            counting+=dfs(row,totC-1);
        else if(col==totC-1)
            counting+=dfs(row,0);
        
        for(int i=0;i<4;i++)
            counting+=dfs(row+dirR[i],col+dirC[i]);
        
        return counting;
        
    }
    
    return 0;
}
int main ()
{
    int kingR,kingC,high,temp;
    while(scanf("%d %d", &totR, &totC)!=EOF)
    {
        for(int i=0;i<totR;i++) scanf("%s", world[i]);

        high=0;
        scanf("%d %d", &kingR, &kingC);
        land=world[kingR][kingC];
        dfs(kingR,kingC);
        for(int i=0;i<totR;i++)
            for(int j=0;j<totC;j++)
            {
                if(world[i][j]==land)
                {
                    temp=dfs(i,j);
                    if(temp>high)
                        high=temp;
                }
            }
            
        printf("%d\n", high);
    }
    return 0;
}