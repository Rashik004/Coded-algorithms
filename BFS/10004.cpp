#include<sstream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int change_color(int x);

int main()
{
    int test, node, edge,node_no,x,y;

    while(2)
    {
        cin>>node;
        if(!node)
        break;
        cin>>edge;
        if(!node)
        break;
        vector<int>relations[node];
       // vector<bool>visited(node,false);
        while(edge--)
        {
            cin>>x>>y;
            relations[x].push_back(y);
            relations[y].push_back(x);
        }
        vector<int>color(node,0),v1,v2;
        v1.push_back(0);
        color[0]=1;
       // visited[0]=false;
        int now_color, prev_color,no=0;
        now_color=2;
        for(int count=1; count<=node; count++)
        {
            for(int i=0; i<v1.size();i++)
            {
                int v=v1[i];

                for(int j=0; j<relations[v].size(); j++)
                {
                    int u=relations[v][j];
                    if(!color[u])
                    {
                        color[u]=now_color;
                        v2.push_back(u);
                    }
                    else if(color[u]!=now_color)
                    {
                        no=1;
                        break;
                    }

                }
            }


            now_color=change_color(now_color);
            if(no)
            break;
            if(v2.empty())
            {
                cout<<"BICOLORABLE."<<endl;
                break;
            }
            else
            {
                v1.clear();
                v1=v2;
                v2.clear();
            }

        }

        if(no)
        {
            cout<<"NOT BICOLORABLE."<<endl;
            continue;
        }


    }
    return 0;
}


int change_color(int x)
{
    if(x==1)
    return 2;
    else
    return 1;
}
