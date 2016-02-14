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
    vector<int>dependent[100];
    int indegree [100],taken[100],elements,result[100];
    stack<int>resultStack;
    void input(int, int);
    void topologicalSort2D();
    void topSortStack(int);
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
    int index=0;
    for(int i=0;i<=elements;i++)
    {
        if(!indegree[i] && !taken[i])
        {
            taken[i]=1;
            result[index++]=i;
            for(int j=0;j<dependent[i].size(); j++)
            {
                int temp=dependent[i][j];
                indegree[temp]--;
            }
            if(index==elements)
                return;
            i=-1;
        }    
    }
}

//void topSort::topSortStack(int x)
//{
//    if(!indegree[x])
//        resultStack.push(x);
//    for(int i=0;i<dependent[x].size();i++)
//    {
//        int temp=dependent[x][i];
//        topSortStack(temp);
//    }
//}
int main ()
{
    
    return 0;
}