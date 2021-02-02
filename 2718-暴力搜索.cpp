#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int f(int num[],int j)
{
	int de=100000;    //10000不够。。
	do
	{
		int first=0,second=0;
		if(num[0]==0||num[(j+1)/2]==0)
			continue;
		for(int i=0;i<(j+1)/2;i++)
			first=first*10+num[i];
		for(int i=(j+1)/2;i<j;i++)
			second=second*10+num[i];
		if(abs(first-second)<de)
			de=abs(first-second);
	}
	while(next_permutation(num,num+j));
	return de;
}
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		int num[10]={0};
		int j=0;
		char c;
		c=getchar();
		while(c!='\n')
		{
			if(c==' ')
			{
				c=getchar();
				continue;
			}
			num[j]=c-'0';
			j++;    //数组中的个数
			c=getchar();
		}
		if(j==2)
		{
			printf("%d\n",num[1]-num[0]);
			continue;
		}
		printf("%d\n",f(num,j));
	}
	return 0;
 } 
