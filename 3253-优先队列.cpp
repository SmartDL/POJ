#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > que; //��С��������ȶ��У�ע��greater<int>����һ��Ҫ��һ���ո�">>"�ᱻ��Ϊ����
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		que.push(a);
	}
	long long sum=0;
	while(que.size()>1)
	{
		int min1=que.top();
		que.pop();
		int min2=que.top();
		que.pop();
		sum=sum+min1+min2;
		que.push(min1+min2);
	}
	cout<<sum<<endl;
	return 0;
 } 
