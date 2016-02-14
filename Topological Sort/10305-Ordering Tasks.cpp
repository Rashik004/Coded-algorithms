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
class topSort{
public:
    vector<int>dependent[102];
    int indegree [102],taken[102],elements;
    void input(int, int);
    void topologicalSort2D();
    topSort(int);
    
};

topSort::topSort(int x)
{
    memset(indegree,0,sizeof(indegree));
    memset(taken,0,sizeof(taken));
    elements=x;
}

void topSort::input(int x,int y)
{
    dependent[x].push_back(y);
    indegree[y]++;
}

void topSort::topologicalSort2D()
{
    int print=0;
    for(int i=1;i<=elements;i++)
    {
        if(!indegree[i] && !taken[i])
        {
            taken[i]=1;
//            cout<<result[index-1]<<" "<<i<<" ";
            if(!print)
             {
                 cout<<i;
             }   
            else
                cout<<" "<<i;
            print++;
            for(int j=0;j<dependent[i].size(); j++)
            {
                int temp=dependent[i][j];
                indegree[temp]--;
            }
            if(print==elements)
                return;
            i=0;
        }    
    }
}


int main ()
{
    int m,n,i,j;
    while(cin>>n>>m)
    {
        if(!m && !n)
            return 0;
        
        topSort obj(n);
        while(m--)
        {
            cin>>i>>j;
            obj.input(i,j);
        }
        obj.topologicalSort2D();
        cout<<endl;
    }
    return 0;
}




