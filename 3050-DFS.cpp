#include<iostream>
#include<set>
#include<string>
using namespace std;
char axes[5][5]={0};
set<string> res;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(int x,int y,int t,string sum)
{
	if(x>4||y>4||x<0||y<0)
		return;
	sum=sum+axes[x][y];
	t++;
	if(t==6)
	{
		res.insert(sum);  //°Ñsum·ÅÈëset
		return;
	}
	for(int i=0;i<4;i++)
		dfs(x+dx[i],y+dy[i],t,sum);
	return;
}
int main()
{
	int t=0;
	string sum="";
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin>>axes[i][j];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			t=0;
			dfs(i,j,t,sum);
		}
	cout<<res.size()<<endl;
	return 0;
 } 
