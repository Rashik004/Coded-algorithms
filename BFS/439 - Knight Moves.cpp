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
#define mp make_pair
using namespace std;
bool mati[9][9];
int totR=8,totC=8;
int bfs(int r0,int c0,int finR,int finC)
{
    if(r0==finR && c0==finC)
        return 0;
    mati[r0][c0]=true;
    vector<pair<int, int> > v1,v2;
    v1.push_back(make_pair(r0,c0));
    int dist=1;
    while(2)
    {
        for(int i=0;i<v1.size();i++)
        {
            int tempR,tempC;
            tempR=v1[i].first;
            tempC=v1[i].second;
            if(tempR<8)
            {
                if(tempC>=3 && !mati[tempR+1][tempC-2])
                {
                    mati[tempR+1][tempC-2]=true;
                    v2.push_back(mp(tempR+1,tempC-2));
                    if(tempR+1==finR && tempC-2==finC)
                        return dist;
                }

                if(tempC<7 && !mati[tempR+1][tempC+2])
                {
                    mati[tempR+1][tempC+2]=true;
                    v2.push_back(mp(tempR+1,tempC+2));
                    if(tempR+1==finR && tempC+2==finC)
                        return dist;
                }                
                
            }
            
            if(tempR>1)
            {
                if(tempC>=3 && !mati[tempR-1][tempC-2])
                {
                    mati[tempR-1][tempC-2]=true;
                    v2.push_back(mp(tempR-1,tempC-2));
                    if(tempR-1==finR && tempC-2==finC)
                        return dist;
                }

                if(tempC<7 && !mati[tempR-1][tempC+2])
                {
                    mati[tempR-1][tempC+2]=true;
                    v2.push_back(mp(tempR-1,tempC+2));
                    if(tempR-1==finR && tempC+2==finC)
                        return dist;
                }                
            }
            
            if(tempR>2)
            {
                if(tempC>1 && !mati[tempR-2][tempC-1])
                {
                    mati[tempR-2][tempC-1]=true;
                    v2.push_back(mp(tempR-2, tempC-1));
                    if(tempR-2==finR && tempC-1==finC)
                        return dist;
                }
                
                if(tempC<8 && !mati[tempR-2][tempC+1])
                {
                    mati[tempR-2][tempC+1]=true;
                    v2.push_back(mp(tempR-2, tempC+1));
                    if(tempR-2==finR && tempC+1==finC)
                        return dist;
                }                
            }
            
            if(tempR<7)
            {
                if(tempC>1 && !mati[tempR+2][tempC-1])
                {
                    mati[tempR+2][tempC-1]=true;
                    v2.push_back(mp(tempR+2, tempC-1));
                    if(tempR+2==finR && tempC-1==finC)
                        return dist;
                }
                
                if(tempC<8 && !mati[tempR+2][tempC+1])
                {
                    mati[tempR+2][tempC+1]=true;
                    v2.push_back(mp(tempR+2, tempC+1));
                    if(tempR+2==finR && tempC+1==finC)
                        return dist;
                }                
            }                
            
        }
        v1=v2;
        v2.clear();
        dist++;
    }
//    printf("Error\n");
}
int main ()
{
    int num,row,r,c,startRow,startCol,targetRow,targetCol;
    char iniPos[5],finPos[5];
    while(scanf("%s %s", iniPos,finPos)!=EOF)
    {
        
        memset(mati,false,sizeof mati);
        startCol=iniPos[0]-96;
        targetCol=finPos[0]-96;
        startRow=iniPos[1]-48;
        targetRow=finPos[1]-48;
        
        printf("To get from %s to %s takes %d knight moves.\n", iniPos, finPos,bfs(startRow,startCol,targetRow,targetCol));
    }
    return 0;
}