#include<iostream>
using namespace std;
char water[101][101];
int num;
int m,n;
void dfs(int x,int y)
{
	if(water[x][y]=='.')
		return;
	water[x][y]='.';
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
		{
			int nx=x+i,ny=y+j;
			if(nx<0||ny<0||nx>=n||ny>=m)
				continue;
			dfs(nx,ny);
		}
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>water[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(water[i][j]=='W')
			{
				num++;
				dfs(i,j);
			}
		}
	cout<<num<<endl;
	return 0;
}
