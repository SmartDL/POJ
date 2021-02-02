#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int num[10][10]={0};  //下面每行是计算一次的结果
int n=0;
int find()
{
	int sum=0;
	int t=n;
	for(int i=0;i<t-1;i++)
		for(int j=0;j<t-i;j++)
		{
			num[i+1][j]=num[i][j]+num[i][j+1];
		}
	return num[t-1][0];
}
int main()
{
	int sum=0;
	scanf("%d%d",&n,&sum);
	for(int i=0;i<n;i++)
		num[0][i]=i+1;	//初始是从小到大 
	while(find()!=sum)
		next_permutation(num[0],num[0]+n);	//每次不对换一种排序 
	for(int i=0;i<n;i++)
		printf("%d ",num[0][i]);
	return 0;
} 
