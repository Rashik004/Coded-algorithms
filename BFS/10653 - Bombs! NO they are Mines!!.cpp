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
bool mati[1002][1002];
int totR,totC;
int bfs(int r0,int c0,int finR,int finC)
{
    mati[r0][c0]=true;
    vector<pair<int, int> > v1,v2;
    v1.push_back(make_pair(r0,c0));
    int dist=0;
    while(2)
    {
        for(int i=0;i<v1.size();i++)
        {
            int tempR,tempC;
            tempR=v1[i].first;
            tempC=v1[i].second;
            if(tempR>0 && !mati[tempR-1][tempC])
            {
                if(tempR-1==finR && tempC ==finC)
                    return dist+1;
                mati[tempR-1][tempC]=true;
                v2.push_back(make_pair(tempR-1,tempC));
            }
                
            if(tempR<totR && !mati[tempR+1][tempC])
            {
                if(tempR+1==finR && tempC==finC)
                    return dist+1;
                mati[tempR+1][tempC]=true;
                v2.push_back(make_pair(tempR+1,tempC));
            }
                
                
            if(tempC>0 && !mati[tempR][tempC-1])
            {
                if(tempR==finR && tempC-1==finC)
                    return dist+1;
                mati[tempR][tempC-1]=true;
                v2.push_back(make_pair(tempR,tempC-1));
            }
            
            if(tempC<totC && !mati[tempR][tempC+1])
            {
                if(tempR==finR &&tempC+1==finC)
                    return dist+1;
                mati[tempR][tempC+1]=true;
                v2.push_back(make_pair(tempR,tempC+1));
            }
            
        }
        v1=v2;
        v2.clear();
        dist++;
    }
}
int main ()
{
    int num,row,r,c,startRow,startCol,targetRow,targetCol;
    while(scanf("%d %d", &totR, &totC))
    {
        if(totC==0 && totR==0)
            break;
        memset(mati,false,sizeof mati);
        scanf("%d", &row);
        while(row--)
        {
            scanf("%d %d", &r, &num);
            while(num--)
            {
                scanf("%d", &c);
                mati[r][c]=true;
            }
        }
        
        scanf("%d %d", &startRow,&startCol);
        scanf("%d %d", &targetRow, &targetCol);
        
        printf("%d\n", bfs(startRow,startCol,targetRow,targetCol));
    }
    return 0;
}