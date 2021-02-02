#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> P;
struct cmp{
	bool operator()(P a,P b)
	{
		return a.first<b.first;
	}
};
int main()
{
	int n;
	int tank=0;
	int pos=0,num=0;
	int l,p; 
	priority_queue<P,vector<P>,cmp> sta;
	priority_queue<int> que;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		sta.push(make_pair(x,y));
	}
	cin>>l>>p;		//p�ǳ��ϵ������� 
	sta.push(make_pair(0,0));//���յ㵱�����һվ���룬�����յ㵽�յ�ľ�����0 
	for(int i=0;i<=n;i++)
	{
		pair<int,int> x=sta.top();
		sta.pop();
		int d=l-x.first-pos;//pos����ǰλ�� 
		while(p<d)//������任�ɡ��ڵ������վiʱ���ͻ����һ����֮���κ�ʱ�򶼿��Լ�Bi��λ���͵�Ȩ���� 
		{
			if(que.empty())
			{
				cout<<"-1"<<endl;
				return 0;
			}
			p+=que.top();
			que.pop();
			num++;
		}
		pos=l-x.first;
		p-=d;
		que.push(x.second); 
	}
	cout<<num<<endl;
	return 0;
}
