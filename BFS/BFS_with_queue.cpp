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
void bfs (int n,int src);
vector<int>G [100]; 
int main ()
{
    int i,j,x;
    while(2)
    {
        cin>>i>>j;
        if(!(i||j))
            break;
        G[i].push_back(j);
        G[j].push_back(i);  
    }

    while(2)
    {
        printf("ENTER SOURCE\n");
        cin>>x;
        if(x<0)
        break;
        bfs(1, x);
    }
    return 0;
}

void bfs (int n,int src) 
{ 
    queue<int>Q; 
    Q.push (src); 
    int taken [100]={0},distance [100]; 
    taken  [src]=1;  
        distance  [src]=0; 
    while (!Q.empty ()) 
    { 
        int u=Q.front (); 
        for (int i=0;i<G [u].size ();i++) 
        { 
            int v=G [u][i]; 
            if(!taken [v]) 
            { 
                distance [v]=distance [u]+1; 
                taken [v]=1; 
                Q.push (v); 
            } 
        } 
        Q.pop (); 
    } 
    for (int i=1;i<=n;i++) 
      printf("%d to %d distance %d\n",src,i,distance [i]); 
} 