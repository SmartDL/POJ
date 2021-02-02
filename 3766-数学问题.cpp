#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI 3.14159265358979323846
int main()
{
	int n,m,k;
	long double r;
	cin>>n>>m>>k>>r;
	int t=1;
	while(n&&m&&k)
	{
		long double ans[3];
		int num=0;
		long double s;
		ans[2]=(m-1)*(2*n-3)*(sqrt(3.0)+PI/2)*pow(r,2);
		if(m%2==0)
		{
			num=m*(2*n-1)/2;
			ans[0]=num*(2*sqrt(3.0)*pow(r,2)-6*r+1.5*sqrt(3.0))+(4*m+4*n-4)*(r-2*pow(r,2)/sqrt(3.0))+(2*m+2*n+1)*pow(r,2)/sqrt(3.0)-(2*m+2*n-5)*PI*pow(r,2)/6;
			/*      Ð¡Áù±ßÐÎ                                  ±ß                                 ½Ç                           ÉÈ*/
		}
		else
		{
			if(m!=1)
				num=(m-1)*(2*n-1)/2+k;
			else
				num=n;
			ans[0]=num*(2*sqrt(3.0)*pow(r,2)-6*r+1.5*sqrt(3.0))+(4*m+4*k-2)*(r-2*pow(r,2)/sqrt(3.0))+(2*m+2*k+2)*pow(r,2)/sqrt(3.0)-(2*m+2*k-4)*PI*pow(r,2)/6;
			/*      Ð¡Áù±ßÐÎ                                  ±ß                                 ½Ç                           ÉÈ*/
		}
		s=num*1.5*sqrt(3.0);
		ans[2]=ans[2]/s*100;
		ans[0]=ans[0]/s*100;
		ans[1]=100-ans[0]-ans[2];
		printf("Case %d:\n",t);
		printf("Probability of covering 1 hexagon   = %.3llf percent.\n",abs(ans[0]));
		printf("Probability of covering 2 hexagons  = %.3llf percent.\n",abs(ans[1]));
		printf("Probability of covering 3 hexagons  = %.3llf percent.\n",abs(ans[2]));
		printf("\n");
		t++;
		cin>>n>>m>>k>>r;
	}
	return 0;
}
