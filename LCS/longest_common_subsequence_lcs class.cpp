#include<iostream>
#include<cstring>
using namespace std;
class finding_lcs{
public:
    int lcs(char, char);
    char X[100],Y[100];//change the strlen if your string is bigger
    int maxi(int,int);
    int LCS[100][100];
    finding_lcs();
};


int main ()
{
    while(2)
    {finding_lcs test;
    cin>>test.X>>test.Y;
    int res=test.lcs(strlen(test.X), strlen(test.Y));
    cout<<res<<endl;}
    return 0;
}

int finding_lcs::lcs(char stpos1,char stpos2)
{
    if(LCS[stpos1][stpos2]!=-1)
        return LCS[stpos1][stpos2];
    int i=stpos1-1, j=stpos2-1;
    
    if(X[i]==Y[j])
        LCS[stpos1][stpos2]=1+lcs(stpos1-1, stpos2-1);       
    else
        LCS[stpos1][stpos2]= maxi(lcs(stpos1, stpos2-1), lcs(stpos1-1, stpos2));
    return LCS[stpos1][stpos2];
}
int finding_lcs::maxi(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

finding_lcs:: finding_lcs()
{
    for(int i=0; i<100; i++)
        LCS[i][0]=0;
    for(int i=0; i<100; i++)
        LCS[0][i]=0;
    for(int i=1; i<100; i++)
        for(int j=1; j<100;j++)
        LCS[i][j]=-1;
}
