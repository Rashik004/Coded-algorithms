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
vector<int>dependent[102];
int indegree[102];
bool taken[102];
vector<int>result;
void ini()
{
    memset(indegree,0,sizeof indegree);
    memset(taken,false,sizeof taken);
    for(int i=0;i<102;i++)
        dependent[i].clear();
    result.clear();
}


void input(int a,int b)
{
    dependent[a].push_back(b);
    indegree[b]++;
}


void topSort(int elements)
{
    int pushed=0;
    for(int i=0;i<elements;i++)
    {
        if(!indegree[i] && !taken[i])
        {
            taken[i]=true;
            result.push_back(i);
            pushed++;
            if(pushed==elements)
                break;
            for(int j=0;j<dependent[i].size();j++)
            {
                int temp=dependent[i][j];
                indegree[temp]--;
            }
            i=-1;
        }
    }
}
int main ()
{
    int elements,relation,serial=1;
    string bevarage1,bevarage2;
//    freopen("out.txt","w",stdout);
    while(cin>>elements)
    {
        map<string,int>indexMap;
        vector<string>nameTrack;
        int index=0;
        
        for(int z=0;z<elements;z++)
        {
            cin>>bevarage1;
            indexMap[bevarage1]=index++;//index==work_serial in topSort
            nameTrack.push_back(bevarage1);//to track the names of topSort
        }
        
        ini();
        
        cin>>relation;
        
        while(relation--)
        {
            cin>>bevarage1>>bevarage2;
            input(indexMap[bevarage1],indexMap[bevarage2]);
        }
        
        topSort(elements);
        
        printf("Case #%d: Dilbert should drink beverages in this order:",serial++);
        for(int s=0;s<result.size();s++)
        {
            cout<<" "<<nameTrack[result[s]];
        }
        cout<<"."<<endl<<endl;
    }
    
    return 0;
}







