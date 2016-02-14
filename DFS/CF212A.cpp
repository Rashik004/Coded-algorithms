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
#define pb push_back
#define max(a,b)a>b?a:b
#define min(a,b)a<b?a:b
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
char board[9][9];
bool visited [9][9];
int dirC[]={+2,+2,-2,-2};
int dirR[]={+2,-2,+2,-2};

bool check(int row,int col)
{
    if(row<1 || row>8 ||col<1 || col>8 || visited[row][col])
        return false;
    return true;
}
bool dfs (int row,int col,int time)
{
    if(!check(row,col))
        return false;
        
    if(board[row][col]=='K')
    {
        if(time%2)
            return false;
        else
            return true;
            
    }
    
    visited[row][col]=true;
    
    for(int i=0;i<=3;i++)
        if(dfs(row+dirR[i],col+dirC[i],time+1))
            return true;
    return false;
    
}
int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,x,y,d;
    cin>>testCase;
    
    
    while(testCase--)
    {
        
        int k1Row,k1Col;
        memset(visited,false,sizeof visited);
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
            {
                cin>>board[i][j];
                if(board[i][j]=='K')
                {
                    
                        k1Row=i;
                        k1Col=j;
                }
                
            }
            
        bool flag=false;
        board[k1Row][k1Col]='.';
        if(dfs(k1Row,k1Col,0))
            flag=true;
        
        
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
            
    }
    return 0;
}