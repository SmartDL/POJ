#include<iostream>
using namespace std;
int cow[350][350];
bool co[350][350];
int dp(int i,int j)	//�ӵ�(i,j)�㵽�ױ����� 
{
	if(co[i][j])	//�õ㵽�ױߵ������Ѿ��ҵ� 
		return cow[i][j];
	else
	{
		cow[i][j]+=max(dp(i+1,j),dp(i+1,j+1));	//�ҵ���(i,j)�㵽�ױߵ����ͣ����cow���� 
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
	for(int i=0;i<n;i++)	//������һ�е��ױߵ������������� 
		co[n-1][i]=true;
	int num=dp(0,0);
	cout<<num;
	return 0;
}
