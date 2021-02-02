#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct poi{int x,y,t;};
int point[303][303];	//点被流星破坏的时间 
bool po[303][303];	//用于判断点是否已经遍历过 
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int a,b,c,m;
int bfs(int xi,int yi)
{
	queue<poi> que;
	poi P1,P2;
	P1.x=xi,P1.y=yi,P1.t=0;
	if(point[P1.x][P1.y]>P1.t)	//如果所在点在逃离时没有被破坏 
	{
		que.push(P1);
		po[P1.x][P1.y]=true;
	}
	while(!que.empty())
	{
		P1=que.front();
		que.pop();
		if(point[P1.x][P1.y]==1001)
			return P1.t;
		for(int i=0;i<4;i++)
		{
			P2.x=P1.x+dx[i];
			P2.y=P1.y+dy[i];
			P2.t=P1.t+1;
			if(P2.x>=0&&P2.y>=0)
				if(!po[P2.x][P2.y]&&point[P2.x][P2.y]>P2.t)
				{
					que.push(P2);
					po[P2.x][P2.y]=true;
				}
		}
	}
	return -1;
}
int main()
{
	scanf("%d",&m);
	for(int i=0;i<303;i++)
		for(int j=0;j<303;j++)
			point[i][j]=1001;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(point[a][b]>c)
			point[a][b]=c;
		for(int k=0;k<4;k++)
			if(a+dx[k]>=0&&b+dy[k]>=0&&point[a+dx[k]][b+dy[k]]>c)
				point[a+dx[k]][b+dy[k]]=c;
	}
	printf("%d\n",bfs(0,0));
	return 0;
}
