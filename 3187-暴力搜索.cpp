#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int num[10][10]={0};  //����ÿ���Ǽ���һ�εĽ��
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
		num[0][i]=i+1;	//��ʼ�Ǵ�С���� 
	while(find()!=sum)
		next_permutation(num[0],num[0]+n);	//ÿ�β��Ի�һ������ 
	for(int i=0;i<n;i++)
		printf("%d ",num[0][i]);
	return 0;
} 
