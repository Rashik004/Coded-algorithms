//Rashik Hasnat KUET_DOUR rashikhasnat@ymail.com
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

class lcs_bottom_up{
public:
    int bottom_up();
    string X,Y;
    int lcs[102][102];
    int lenx,leny;
    void find_len();
    int maxi(int, int);
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
        return lcs[lenx][leny];
}

int lcs_bottom_up::maxi(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main ()
{
    lcs_bottom_up test;
    int tcase=0;
    while(getline(cin, test.X))
    {
        if(test.X[0]=='#')
        break;
        tcase++;
        getline(cin, test.Y);
        int city=test.bottom_up();
        printf("Case #%d: you can visit at most %d cities.\n", tcase, city);
    }
    return 0;
}