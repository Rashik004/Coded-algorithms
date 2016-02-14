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
  //  freopen("Input.txt","r",stdin);
//freopen("Output.txt","w",stdout);
    string a,b;
    while(cin>>a>>b)
    {
       // queue<int> q;
        int asize,bsize;
        asize=a.size();
        bsize=b.size();
        int j=0;
        bool encode=false;
        for(int i=0; i<bsize; i++)
        {
            if(b[i]==a[j])
            {
                j++;
                if(j==asize)
                {
                    encode =true;
                    break;
                }
            }
        }
        if(encode)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
    return 0;
}