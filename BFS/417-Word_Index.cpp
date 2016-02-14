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
vector<string>dp;
void bfs(int range)
{
    int index=1;
    dp.push_back(" ");
    queue<string> q;
    string temp,now;
    
    for(char i='a'; i<='z';i++)
    {
        string temp;
        temp+=i;
        q.push(temp);
        dp.push_back(temp);
        index++;
    }
    while(index<=range)
    {
        temp=q.front();
        q.pop();
        for(char i=temp[temp.size()-1]+1;i<='z';i++)//top er last char er por theke tar sathe abar poroborti char jog kor hobe
            //suppos temp="asd" then i will start from d+1=e & end in z
        {
            now=temp+i;
            dp.push_back(now);
            index++;
            q.push(now);
            if(index>range)
                return;
        }
    }
    
}

int main ()
{
    bfs(83681);
    string input;
    while(cin>>input)
    {
        int s=input.size();
        for(int i=1;i<s;i++)
            if(input[i]<=input[i-1])
            {
                    printf("0\n");
                    continue;
            }
        for(int i=1;i<=83681;i++)
            if(dp[i]==input)
                printf("%d\n", i);
    }
    return 0;
}