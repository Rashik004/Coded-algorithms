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

//Ali Vai & programming interview Sum of Subsets tutorial
using namespace std;

class non_Sos{
public:
    int high,totalItem,maxM;
    vector<int> item,temp,ans;
    void backtrack(int nowSum,int index);
    void printAns();
     non_Sos();
};

 non_Sos:: non_Sos()
 {
     high=-100;
 }

void non_Sos::backtrack(int nowSum,int index)
{
    if(nowSum>maxM)//as the sum never can be greater than the maxM value
        return;
    
    if(nowSum>high)//this is the optimal solution till now
    {
        //changing the value of integer high & answer vector
        high=nowSum;
        ans=temp;
    }
    
    if(index==totalItem)
        return;
    
    temp.push_back(item[index]);
    backtrack(nowSum+item[index],index+1);// Incluing x indexed data
    temp.pop_back();
    backtrack(nowSum,index+1);// Excluing x indexed data
}

void non_Sos::printAns()
{
    int totalSolution=ans.size();
    for(int i=0;i<totalSolution;i++)
      printf("%d ",ans[i]);
    printf("sum:%d\n",high);
}

int main ()
{
    string input;
    while(getline(cin,input))
    {
        stringstream sin(input);
        non_Sos test;
        sin>>test.maxM>>test.totalItem;
        int x;
        for(int i=0;i<test.totalItem;i++)
        {
            sin>>x;
            test.item.push_back(x);
        }
        
        test.backtrack(0,0);
        test.printAns();
    }
    return 0;
}