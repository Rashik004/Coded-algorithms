#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<utility>
#include<complex>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<deque>
#include<list>
#include<stdexcept>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<ctime>
#define ELE 109
#define MAX 1<<10
using namespace std;
int d[ELE][ELE], costing[ELE][ELE];

void apsp(int n)
{
    int temp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(costing[i][j]==-1)
                d[i][j]=MAX;
            else
                d[i][j]=costing[i][j];
        }
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                
                temp=d[i][k]+d[k][j];
                if(temp<d[i][j])
                {
                    d[i][j]=temp;
                }
            }
}