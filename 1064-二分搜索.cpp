#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
float cable[10001];
int n,k;
bool C(float x)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=(int)(cable[i]/x);
	return sum>=k;
}
int main()
{
	scanf("%d%d",&n,&k);
	float cmax=0.0,cmin=0.0,mid;
	for(int i=0;i<n;i++)
	{
		scanf("%f",&cable[i]);
		if(cable[i]>cmax)
			cmax=cable[i];
	} 
	for(int i=0;i<100;i++)
	{
		mid=(cmax+cmin)/2;
		if(C(mid))
			cmin=mid;
		else
			cmax=mid;
	}
	printf("%.2f\n",floor(mid*100)/100);
	return 0;
 } 
