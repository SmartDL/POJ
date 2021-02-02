#include<iostream>
using namespace std;
int cow[350][350];
bool co[350][350];
int dp(int i,int j)	//从第(i,j)点到底边最大和 
{
	if(co[i][j])	//该点到底边的最大和已经找到 
		return cow[i][j];
	else
	{
		cow[i][j]+=max(dp(i+1,j),dp(i+1,j+1));	//找到从(i,j)点到底边的最大和，存回cow数组 
		co[i][j]=true;
		return cow[i][j];
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			cin>>cow[i][j];
	for(int i=0;i<n;i++)	//最下面一行到底边的最大和是他本身 
		co[n-1][i]=true;
	int num=dp(0,0);
	cout<<num;
	return 0;
}
