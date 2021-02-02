#include<iostream>
using namespace std;
char cow[2001];
bool s(int x,int y)
{
	if(x>y)
		return true;
	if(cow[x]<cow[y])
		return true;
	if(cow[x]==cow[y])
		return s(x+1,y-1);
	return false;
}
int num=0;
void t(int cowf,int cowb)
{
	if(cowf==cowb)
	{
		cout<<cow[cowf];
		return ;
	}
	if(num==80)
	{
		cout<<endl;
		num=0;
	}
	num++;
	if(s(cowf,cowb))
	{
		cout<<cow[cowf];
		cowf++;
	}
	else
	{
		cout<<cow[cowb];
		cowb--;
	}

	t(cowf,cowb);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>cow[i];
	t(0,n-1);
	return 0;
} 
