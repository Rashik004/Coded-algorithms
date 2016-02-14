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
     high=-1<<15;
 }

void non_Sos::backtrack(int nowSum,int index)
{
    if(nowSum>maxM)//as the sum never can be greater than the maxM value
        return;
    
    if(nowSum>high)//this is the optimal solution till now
    {
        //changing the value of high & answer vector
        high=nowSum;
        ans=temp;
    }
    
    if(index==item.size())
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

    return 0;
}