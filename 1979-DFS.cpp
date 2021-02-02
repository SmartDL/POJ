#include<iostream>
using namespace std;
char a[20][21];
int w,h;
void dfs(int x,int y)
{
	int dx[4]={1,0,-1,0};
	int dy[4]={0,1,0,-1};
	for(int i=0;i<4;i++)
	{
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(nx>=0&&nx<h&&ny>=0&&ny<w&&a[nx][ny]=='.')	
		{
			a[nx][ny]='@';
			dfs(nx,ny);
		}
	}
	return;
}
int main()
{
	cin>>w>>h;
	while(w!=0)
	{
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin>>a[i][j];
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(a[i][j]=='@')
				{
					dfs(i,j);
					break;
				}
		int point=0;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(a[i][j]=='@')
					point++;
		cout<<point<<endl;
		cin>>w>>h;
	}
	return 0;
}
