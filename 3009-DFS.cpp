#include<iostream>
#include<cstdio>
using namespace std;
struct P{int x,y,t;}; //t代表走到这里所用步数
int w,h;
int board[22][22];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int num;
P find(P from,int i)    //这个函数用来找向i方向扔时停的位置
{
	P to;
	to.x=from.x+dx[i],to.y=from.y+dy[i],to.t=from.t;
	if(to.x>h||to.y>w||to.x<1||to.y<1)
	{
		from.t=-1;
		return from;
	}
	if(board[to.x][to.y]==3)
		return to;
	if(board[to.x][to.y]==1)
	{
		board[to.x][to.y]=0;
		return from;
	}
	return find(to,i);
}
void dfs(P start)
{
	for(int i=0;i<4;i++)
	{
		if(board[start.x+dx[i]][start.y+dy[i]]==1)
			continue;
		P p=find(start,i);
		if(p.t==-1)
			continue;
		p.t++;
		if(board[p.x][p.y]==3&&p.t<num)
		{
			num=p.t;
			continue;
		}
		if(p.t<10)
			dfs(p);
		if(board[p.x][p.y]!=3)
			board[p.x+dx[i]][p.y+dy[i]]=1;  //深搜每退回一部就把撞掉的冰还原
	}
}
int main()
{	
	cin>>w>>h;
	while(w||h)
	{
		P start;
		num=11;
		for(int i=1;i<=h;i++)   //这里在board上的部分是从1到h，w，不是0到h-1，w-1，我是为了防止数组越界
			for(int j=1;j<=w;j++)
			{
				scanf("%d",&board[i][j]);
				if(board[i][j]==2)
				{
					start.x=i,start.y=j,start.t=0;
					board[i][j]=0;
				}
			}
		dfs(start);
		if(num>10)
			cout<<"-1"<<endl;
		else
			cout<<num<<endl;
		cin>>w>>h;
	}
	return 0;
}
