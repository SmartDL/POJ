//反向走与擦肩而过相同
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t,l,n;
	scanf("%d",&t);
	while(t--)
	{
		int tmax=0,tmin=0;
		int x;
		scanf("%d%d",&l,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			tmin=max(tmin,min(x,l-x));
			tmax=max(tmax,max(x,l-x));
		}
		printf("%d %d\n",tmin,tmax);
	}
	return 0;
 } 
