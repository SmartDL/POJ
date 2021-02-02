//难得poj上一道中文题目
#include<iostream>
#include<cstdio>
using namespace std;
int animal[150000];
int rank [150000];
void init(int n)
{
	for(int i=0;i<n+3;i++)
		animal[i]=i;
}
int find(int x)
{
	if(animal[x]==x)
		return x;
	else
		return animal[x]=find(animal[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	if(rank[x]<rank[y])
		animal[x]=y;
	else
	{
		animal[y]=x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
	return;
}
bool same(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return true;
	return false;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int fa=0;//假话总数
	init(3*n);
	for(int i=0;i<k;i++)
	{
		int d,x,y;
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n||x<1||y<1)
		{
			fa++;
			continue;
		}
		x--,y--; 
		if(d==1)
		{
			if(same(x,y+n)||same(y,x+n))//x吃y或者y吃x 
			{
				fa++;
				continue;
			}
			unite(x,y);
			unite(x+n,y+n);
			unite(x+2*n,y+2*n);
		}
		else
		{
			if(x==y||same(x,y)||same(y,x+n))//x=y或者x与y同类或者y吃x 
			{
				fa++;
				continue;
			}
			unite(x,y+n);
			unite(x+n,y+2*n);
			unite(x+2*n,y);
		}
	}
	cout<<fa<<endl;
	return 0;
}
