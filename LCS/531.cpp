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

class lcs_bottom_up{
public:
    int bottom_up();
    vector<string>X;
    vector<string>Y;
    int lcs[102][102];
    int lenx,leny,printed;
    void find_len();
    int maxi(int, int);
    void traceback(int i, int j);
};

void lcs_bottom_up:: find_len()
{
    lenx=X.size();
    leny=Y.size();
}

int lcs_bottom_up::bottom_up()
{
    find_len();
    for(int i=0; i<=lenx; i++)
        lcs[i][0]=0;
    for(int i=0; i<=leny; i++)
        lcs[0][i]=0;
    for(int i=1; i<=lenx; i++)
        for(int j=1; j<=leny; j++)
        {
            if(X[i-1]==Y[j-1])//i is the ith character of X which means i-1 index same goes for j with Y
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=maxi(lcs[i-1][j], lcs[i][j-1]);
        }
        printed=0;
        return lcs[lenx][leny];
}

int lcs_bottom_up::maxi(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void lcs_bottom_up::traceback(int i, int j){

 if(i == 0|| j == 0)return;

 if(X[i-1] == Y[j-1]) {
     traceback(i-1, j-1);
     if(!printed)           //1st word er aage kono gap hobena
     {
         cout << X[i-1];
         printed++;
     }
     else
        cout<<' '<<X[i-1];
 }
 else if(lcs[i-1][j] > lcs[i][j-1])
     traceback(i-1, j);
 else traceback(i, j-1);
}

int main ()
{
    //vector<string>X,Y;
//            freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    string st1, st2;
    lcs_bottom_up test;

    while(cin>>st1)
    {
      // cout<<st1;
      lcs_bottom_up test;
        test.X.push_back(st1);
        while(1)
        {
            cin>>st1;
            if(st1=="#")
                break;
            test.X.push_back(st1);
        }
        //cout<<"bair hoisi"<<endl;
        while(1)
        {
            cin>>st1;
            if(st1=="#")
                break;
            test.Y.push_back(st1);
        }
//         cout<<"Abar bair hoisi"<<endl;
         test.bottom_up();
         test.traceback(test.lenx,test.leny);
         cout<<endl;
    }
    return 0;
}