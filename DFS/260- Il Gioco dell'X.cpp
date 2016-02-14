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
char box[205][205],pawn;
int side;
int dirR[]={-1,-1,0,0,1,1};
int dirC[]={-1,0,-1,1,0,1};
bool dfs(int row,int col)
{
    if(row>=0 && row<side && col>=0 && col<side)
    {
        if(box[row][col]!=pawn) return false;
        else if (pawn=='b' && row==side-1)
            return true;
        else if (pawn=='w' && col==side-1)
            return true;
        else
            box[row][col]='n';
        
        for(int i=0;i<6;i++)
            if(dfs(row+dirR[i],col+dirC[i]))
                return true;
        return false;
    }
    else return false;
}


int main ()
{
    int serial=1;
    while(scanf("%d", &side) && side)
    {
        for(int i=0;i<side;i++)
            scanf("%s", box[i]);
        for(int i=0;i<side;i++)
        {
            pawn='b';
            if(dfs(0,i))
            {
                printf("%d B\n", serial++);
                break;
            }
            pawn='w';
            if(dfs(i,0))
            {
                printf("%d W\n", serial++);
                break;
            }
        }
    }
    return 0;
}