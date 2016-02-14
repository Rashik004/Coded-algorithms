// C++ Code for LIS - Longest increasing subsequence
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define MAXELE 10005
using namespace std;
/*
 - Find the LIS and save the LIS til index i in array increasing.
 - Find the LDS by do the LIS backward and save the LDS till index i in array decreasing.
 - For each element, consider it as the top element of the waivo.
*/
int increasing[MAXELE], decreasing[MAXELE],tailTable[MAXELE],numbers[MAXELE];

void binary_search(int start, int end, int key)
{
	int mid;
	while(start<=end)
	{
		mid=(start+end)/2;

		if(tailTable[mid] == key)
			return;
		else if(tailTable[mid] > key)
			end=mid-1;
		else
			start=mid+1;
	}
	if(tailTable[start]<key)  // no need;  just for safety!!
		start++;
	tailTable[start]=key;
}


int lis(int elements)
{
    int i,n,cur,num,set=1;
    
    cur=1;
    tailTable[0]=numbers[0];
    increasing[1]=1;
    for(int i=1;i<elements;i++)
    {
        num=numbers[i];
        if(num>tailTable[cur-1])
            tailTable[cur++]=num;
        else if(num<tailTable[cur-1])
            binary_search(0,cur-1,num);
        increasing[i]=cur;
    }
    return cur;
}

int lds(int elements)
{
    int i,n,cur,num,set=1;
    
    cur=1;
    tailTable[0]=numbers[elements-1];
    decreasing[elements-1]=1;
    for(int i=elements-2;i>=0;i--)
    {
        num=numbers[i];
        if(num>tailTable[cur-1])
            tailTable[cur++]=num;
        else if(num<tailTable[cur-1])
            binary_search(0,cur-1,num);
        decreasing[i]=cur;
    }
    return cur;
}
main()
{
    int elements,result,temp;
    while(scanf("%d", &elements)!=EOF)
    {
        for(int i=0;i<elements;i++)
            scanf("%d", &numbers[i]);
        lis(elements);
        lds(elements);
        result=1;
        for(int i=0;i<elements;i++)
        {
            
            temp=min(increasing[i],decreasing[i]);
            result=max(result,temp);
        }
        printf("%d\n", result*2-1);
        
    }
}
