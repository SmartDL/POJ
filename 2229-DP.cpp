#include<iostream>
#include<cstdio> 
using namespace std;
struct computer{float x;float y;};
computer com[1002];
int par[1002];
int rank[1002];	
int n;
float d;
void init(int i)
{
	par[i]=i;
	rank[i]=0;
}
int find(int a)
{
	if(par[a]==a)
		return a;
	else
		return par[a]=find(par[a]);
}
void unite(int b,int c)
{
	b=find(b);
	c=find(c);
	if(b==c)
		return;
	if(rank[b]<rank[c])
		par[b]=c;
	else
	{
		par[c]=b;
		if(rank[b]==rank[c])
			rank[b]++;
	}
}
void wire(int a)
{
	for(int i=0;i<n;i++)
	{
		if(par[i]==-1||i==a)
			continue;
		else
		{
			float b=(com[i].x-com[a].x)*(com[i].x-com[a].x)+(com[i].y-com[a].y)*(com[i].y-com[a].y);
			if(b<=d*d)
				unite(i,a);
		}
	}
}
int main()
{
	cin>>n>>d;
	for(int i=0;i<n;i++)
		cin>>com[i].x>>com[i].y;
	getchar();
	for(int i=0;i<n;i++)
		par[i]=-1;
	char m;
	int t=299999-n;
	while(cin>>m)
	{
		t--;
		if(m=='O')
		{
			int a;
			cin>>a;
			init(a-1);
			wire(a-1);
		}
		if(m=='S')
		{
			int a,b;
			cin>>a>>b;
			if(par[a-1]==-1||par[b-1]==-1)
				cout<<"FAIL"<<endl;
			else if(find(a-1)!=find(b-1))
				cout<<"FAIL"<<endl;
			else
				cout<<"SUCCESS"<<endl;
		}
		getchar();
		if(t==0)
			break;
	}
	return 0;
}
