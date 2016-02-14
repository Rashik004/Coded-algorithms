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
bool mati[1002][1002];
map<pair<pair<int,int>,char>,bool>mapping;
map<pair<pair<int,int>,char>,pair<pair<int,int>,char>  >parent;
int totR,totC;
int bfs(int r0,int c0,int finR,int finC,int iniD)
{
    mapping[make_pair(make_pair(r0,c0), iniD)]=true;
    vector<pair<pair<int,int>, char > > v1,v2;
    v1.push_back(make_pair(make_pair(r0,c0), iniD));
    int dist=0;
    while(2)
    {
        for(int i=0;i<v1.size();i++)
        {
            int tempR,tempC;
            char nowD;
            tempR=v1[i].first.first;
            tempC=v1[i].first.second;
            nowD=v1[i].second;
            
            if(nowD=='s')
            {
                if(tempR<totR-1 && mapping[make_pair(make_pair(tempR+1,tempC), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR+1,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR+1==finR && tempC==finC)
                        return dist+1;
                        
                    mapping[make_pair(make_pair(tempR+1,tempC), nowD)]==true;
                    parent[make_pair(make_pair(tempR+1,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    v2.push_back(make_pair(make_pair(tempR+1,tempC), nowD));
                }
                

                if(tempR<totR-2 && mapping[make_pair(make_pair(tempR+2,tempC), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR+2,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR+2==finR && tempC==finC)
                        return dist+1;
//                    parent[make_pair(make_pair(tempR+2,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);    
                    mapping[make_pair(make_pair(tempR+2,tempC), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR+2,tempC), nowD));
                }


                if(tempR<totR-3 && mapping[make_pair(make_pair(tempR+3,tempC), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR+3,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR+3==finR && tempC==finC)
                        return dist+1;
//                    parent[make_pair(make_pair(tempR+3,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    mapping[make_pair(make_pair(tempR+3,tempC), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR+3,tempC), nowD));
                }

                
                if(mapping[make_pair(make_pair(tempR,tempC), 'e')]==false)
                {
                    parent[make_pair(make_pair(tempR,tempC), 'e')]=make_pair(make_pair(tempR,tempC), nowD);
                    mapping[make_pair(make_pair(tempR,tempC), 'e')]==true;
                    v2.push_back(make_pair(make_pair(tempR,tempC), 'e'));                    
                }
                if(mapping[make_pair(make_pair(tempR,tempC), 'w')]==false)
                {
                    parent[make_pair(make_pair(tempR,tempC), 'w')]=make_pair(make_pair(tempR,tempC), nowD);
                    mapping[make_pair(make_pair(tempR,tempC), 'w')]==true;
                    v2.push_back(make_pair(make_pair(tempR,tempC), 'w'));                    
                }
            }
            
            
            if(nowD=='n')
            {
                if(tempR>1 && mapping[make_pair(make_pair(tempR-1,tempC), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR-1,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR-1==finR && tempC==finC)
                        return dist+1;
//                    parent[make_pair(make_pair(tempR-1,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    mapping[make_pair(make_pair(tempR-1,tempC), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR-1,tempC), nowD));
                }


                if(tempR>2 && mapping[make_pair(make_pair(tempR-2,tempC), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR-2,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR-2==finR && tempC==finC)
                        return dist+1;
//                    parent[make_pair(make_pair(tempR-2,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    mapping[make_pair(make_pair(tempR-2,tempC), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR-2,tempC), nowD));
                }
                
                
                if(tempR>3 && mapping[make_pair(make_pair(tempR-3,tempC), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR-3,tempC), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR-3==finR && tempC==finC)
                        return dist+1;
                    
                        
                    mapping[make_pair(make_pair(tempR-3,tempC), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR-3,tempC), nowD));
                }
                
                if(mapping[make_pair(make_pair(tempR,tempC), 'e')]==false)
                {
                    mapping[make_pair(make_pair(tempR,tempC), 'e')]==true;
                    parent[make_pair(make_pair(tempR,tempC), 'e')]=make_pair(make_pair(tempR,tempC), nowD);
                    v2.push_back(make_pair(make_pair(tempR,tempC), 'e'));                    
                }
                if(mapping[make_pair(make_pair(tempR,tempC), 'w')]==false)
                {
                    mapping[make_pair(make_pair(tempR,tempC), 'w')]==true;
                    parent[make_pair(make_pair(tempR,tempC), 'w')]=make_pair(make_pair(tempR,tempC), nowD);
                    v2.push_back(make_pair(make_pair(tempR,tempC), 'w'));                    
                }
            }
            
            
            if(nowD=='w')
            {
                if(tempC>1 && mapping[make_pair(make_pair(tempR,tempC-1), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR,tempC-1), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR==finR && tempC-1==finC)
                        return dist+1;
                    
                    mapping[make_pair(make_pair(tempR,tempC-1), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR,tempC-1), nowD));
                }


                if(tempC>2 && mapping[make_pair(make_pair(tempR,tempC-2), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR,tempC-2), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR==finR && tempC-2==finC)
                        return dist+1;
                        
                    
                    mapping[make_pair(make_pair(tempR,tempC-2), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR,tempC-2), nowD));
                }
                


                if(tempC>3 && mapping[make_pair(make_pair(tempR,tempC-3), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR,tempC-3), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR==finR && tempC-3==finC)
                        return dist+1;
                        
                    
                    mapping[make_pair(make_pair(tempR,tempC-3), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR,tempC-3), nowD));
                }
                
                
                if(mapping[make_pair(make_pair(tempR,tempC), 's')]==false)
                {
                    parent[make_pair(make_pair(tempR,tempC), 's')]=make_pair(make_pair(tempR,tempC), nowD);
                    mapping[make_pair(make_pair(tempR,tempC), 's')]==true;
                    v2.push_back(make_pair(make_pair(tempR,tempC), 's'));                    
                }
                if(mapping[make_pair(make_pair(tempR,tempC), 'n')]==false)
                {
                    mapping[make_pair(make_pair(tempR,tempC), 'n')]==true;
                    parent[make_pair(make_pair(tempR,tempC), 'n')]=make_pair(make_pair(tempR,tempC), nowD);
                    v2.push_back(make_pair(make_pair(tempR,tempC), 'n'));                    
                }
            }



            if(nowD=='e')
            {
                if(tempC<totC-1 && mapping[make_pair(make_pair(tempR,tempC+1), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR,tempC+1), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR==finR && tempC+1==finC)
                        return dist+1;
                    
                    mapping[make_pair(make_pair(tempR,tempC+1), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR,tempC+1), nowD));
                }


                if(tempC<totC-2 && mapping[make_pair(make_pair(tempR,tempC+2), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR,tempC+2), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR==finR && tempC+2==finC)
                        return dist+1;
                        
                    
                    mapping[make_pair(make_pair(tempR,tempC+2), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR,tempC+2), nowD));
                }

                if(tempC<totC-3 && mapping[make_pair(make_pair(tempR,tempC+3), nowD)]==false)
                {
                    parent[make_pair(make_pair(tempR,tempC+3), nowD)]=make_pair(make_pair(tempR,tempC), nowD);
                    if(tempR==finR && tempC+3==finC)
                        return dist+1;
                    
                    
                    mapping[make_pair(make_pair(tempR,tempC+3), nowD)]==true;
                    v2.push_back(make_pair(make_pair(tempR,tempC+3), nowD));
                }
                
                
                if(mapping[make_pair(make_pair(tempR,tempC), 's')]==false)
                {
                    mapping[make_pair(make_pair(tempR,tempC), 's')]==true;
                    parent[make_pair(make_pair(tempR,tempC), 's')]=make_pair(make_pair(tempR,tempC), nowD);
                    v2.push_back(make_pair(make_pair(tempR,tempC), 's'));                    
                }
                if(mapping[make_pair(make_pair(tempR,tempC), 'n')]==false)
                {
                    mapping[make_pair(make_pair(tempR,tempC), 'n')]==true;
                    parent[make_pair(make_pair(tempR,tempC), 'n')]=make_pair(make_pair(tempR,tempC), nowD);
                    v2.push_back(make_pair(make_pair(tempR,tempC), 'n'));                    
                }
            }
        }
        if(v2.empty())
            return dist+1;
        v1=v2;
        v2.clear();
        dist++;
    }
}
int main ()
{
    int temp,inR,inC,tarR,tarC;
    while(scanf("%d %d", &totR, &totC))
    {
        if(totC==0 && totR==0)
            break;
        
        for(int i=1;i<=totR;i++)
        {
            for(int j=1;j<=totC;j++)
            {
                scanf("%d", &temp);
                if(!temp)
                {
                    mapping[make_pair(make_pair(i,j),'s')]=false;
                    mapping[make_pair(make_pair(i,j),'n')]=false;
                    mapping[make_pair(make_pair(i,j),'w')]=false;
                    mapping[make_pair(make_pair(i,j),'e')]=false;
                }
                else
                {
                    mapping[make_pair(make_pair(i,j),'s')]=true;
                    mapping[make_pair(make_pair(i-1,j),'s')]=true;
                    mapping[make_pair(make_pair(i,j),'s')]=true;
                    mapping[make_pair(make_pair(i,j-1),'s')]=true;
                    
                    mapping[make_pair(make_pair(i,j),'n')]=true;
                    mapping[make_pair(make_pair(i-1,j),'n')]=true;
                    mapping[make_pair(make_pair(i,j),'n')]=true;
                    mapping[make_pair(make_pair(i,j-1),'n')]=true;

                    mapping[make_pair(make_pair(i,j),'e')]=true;
                    mapping[make_pair(make_pair(i-1,j),'e')]=true;
                    mapping[make_pair(make_pair(i,j),'e')]=true;
                    mapping[make_pair(make_pair(i,j-1),'e')]=true;

                    mapping[make_pair(make_pair(i,j),'w')]=true;
                    mapping[make_pair(make_pair(i-1,j),'w')]=true;
                    mapping[make_pair(make_pair(i,j),'w')]=true;
                    mapping[make_pair(make_pair(i,j-1),'w')]=true;
                    
                }
            }
        }
        char di[6];
        scanf("%d %d %d %d %s",&inR,&inC,&tarR,&tarC,di );
        printf("%d\n",bfs(inR,inC,tarR,tarC,di[0]));
        char d[5]="sewn";
        int nowR,nowC;
        char nowD;
        cout<<endl<<endl<<endl;
        for(int i=0;i<4;i++)
        {
            if(parent.find(make_pair(make_pair(tarR,tarC), d[i]))!=parent.end())
            {
                while(2)
                {
                    nowR=parent[make_pair(make_pair(tarR,tarC),d[i])].first.first;
                    nowC=parent[make_pair(make_pair(tarR,tarC),d[i])].first.second;
                    nowD=parent[make_pair(make_pair(tarR,tarC),d[i])].second;
                    cout<<nowR<<" "<<nowC<<" "<<nowD<<endl;
                    if(nowR==inR && nowC==inC && nowD==di[0])
                        break;
                    tarR=nowR;
                    tarC=nowC;
                    d[i]=nowD;
                }
                break;
            }
        }
    }
    return 0;
}




