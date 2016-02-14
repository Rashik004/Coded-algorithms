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
int main ()
{
    int side,square[26][26],serial=1;
    bool visited[26][26];
    char line[26];
    
    while(scanf("%d", &side)!=EOF)
    {
        int eagle=0;
        memset(visited,false,sizeof visited);
        for(int i=0;i<side;i++)
        {
            scanf("%s", line);
            for(int j=0;j<side;j++)
                square[i][j]=line[j]-48;
        }
        for(int tempR=0;tempR<side;tempR++)
        {
            for(int tempC=0;tempC<side;tempC++)
            {
                if(square[tempR][tempC]==0 || visited[tempR][tempC])
                    continue;
                eagle++;
                queue<pair<int,int> >q;
                q.push(make_pair(tempR,tempC));
                visited[tempR][tempC]=true;
                while(!q.empty())
                {
                    int i,j;
                    i=q.front().first;
                    j=q.front().second;
                    q.pop();
                    if(j>0 && square[i][j-1]==1 && !visited[i][j-1])
                    {
                        visited[i][j-1]=true;
                        q.push(make_pair(i,j-1));
                    }
                    
                    if(j<side-1 && square[i][j+1]==1 && !visited[i][j+1])
                    {
                        visited[i][j+1]=true;
                        q.push(make_pair(i,j+1));
                    }
                    
                    if(i>0 && square[i-1][j]==1 && !visited[i-1][j])
                    {
                        visited[i-1][j]=true;
                        q.push(make_pair(i-1,j));
                    }
                    
                    if(i<side-1 && square[i+1][j]==1 && !visited[i+1][j])
                    {
                        visited[i+1][j]=true;
                        q.push(make_pair(i+1,j));
                    }
                    
                    if(i>0 && j>0 && square[i-1][j-1]==1 && !visited[i-1][j-1])
                    {
                        visited[i-1][j-1]=true;
                        q.push(make_pair(i-1,j-1));
                    }
                    
                    if(i>0 && j<side-1 && square[i-1][j+1]==1 && !visited[i-1][j+1])
                    {
                        visited[i-1][j+1]=true;
                        q.push(make_pair(i-1,j+1));
                    }
                    
                    
                    if(i<side-1 && j>0 && square[i+1][j-1]==1 && !visited[i+1][j-1])
                    {
                        visited[i+1][j-1]=true;
                        q.push(make_pair(i+1,j-1));
                    }
                    
                    
                    if(i<side-1 && j<side-1 && square[i+1][j+1]==1 && !visited[i+1][j+1])
                    {
                        visited[i+1][j+1]=true;
                        q.push(make_pair(i+1,j+1));
                    }
                }

            }
        }
        
            
            printf("Image number %d contains %d war eagles.\n", serial++,eagle);
    }
    return 0;
}





