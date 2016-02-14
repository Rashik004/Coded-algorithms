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
#define MAX 35
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
char dungon[MAX][MAX][MAX];
int rowMove[]={-1,0,+1,0,0,0};
int colMove[]={0,+1,0,-1,0,0};
int levelMove[]={0,0,0,0,-1,+1};
int l,r,c;
// here i did a simple 3d graph traversal using bfs
bool check(int level,int row,int col)
{
    if(level<l && level>=0 && row<r && row>=0 && col>=0 && col<c && dungon[level][row][col]!='#')
        return true;
    return false;
    
}

int bfs(int level,int row,int col)
{
    vi levelv1,rowv1,colv1,levelv2,rowv2,colv2;
    int tempLevel,tempRow,tempCol,nowLevel,nowCol,nowRow;
    
    levelv1.pb(level);
    rowv1.pb(row);
    colv1.pb(col);
    int timing=0;
    
    while(2)
    {
        for(int i=0;i<levelv1.size();i++)
        {
            nowLevel=levelv1[i];
            nowCol=colv1[i];
            nowRow=rowv1[i];
            
            for(int j=0;j<6;j++)
            {
                tempLevel=nowLevel+levelMove[j];
                tempRow=nowRow+rowMove[j];
                tempCol=nowCol+colMove[j];
                
                if(check(tempLevel,tempRow,tempCol))
                {
                    if(dungon[tempLevel][tempRow][tempCol]=='E')
                    {
                        printf("Escaped in %d minute", timing+1);
                        if(timing)
                            printf("(s).\n");
                        else
                            printf(".\n");
                        return 1;
                    }
                    dungon[tempLevel][tempRow][tempCol]='#';
                    levelv2.pb(tempLevel);
                    rowv2.pb(tempRow);
                    colv2.pb(tempCol);
                    
                    
                }
            }
        }
        
        timing++;
        if(levelv2.empty())
        {
            cout<<"Trapped!"<<endl;
            return 0;
        }
        levelv1=levelv2;
        rowv1=rowv2;
        colv1=colv2;
        
        levelv2.clear();
        rowv2.clear();
        colv2.clear();
    }
        
}


int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,x,y;
    
    while(cin>>l>>r>>c && l && r && c)
    {
        for(int i=0;i<l;i++)
            for(int j=0;j<r;j++)
                cin>>dungon[i][j];
                
        for(int i=0;i<l;i++)
            for(int j=0;j<r;j++)
                for(int k=0;k<c;k++)
                    if(dungon[i][j][k]=='S')
                        bfs(i,j,k);
    }
    
    
    return 0;
}




