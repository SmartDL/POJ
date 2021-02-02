#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int r,n;
	cin>>r>>n;
	while(r!=-1)
	{
		int troop[1001];
		int num=0; 
		for(int i=0;i<n;i++)
			cin>>troop[i];
		sort(troop,troop+n);	//algorithm库中的排序 
		for(int i=0;i<n;i++)
		{
			num++;
			int j=i;
			while(j+1<n)	//因为是从小到大排序，所以把palantir尽量往后面放,放在j处 
				if(troop[j+1]-troop[i]<=r)
					j++;
				else
					break;
			int k=j;
			while(k+1<n)	//k是最后一个被覆盖的点 
				if(troop[k+1]-troop[j]<=r)
					k++;
				else
					break;
			i=k;
		}
		cout<<num<<endl;
		cin>>r>>n;
	}
	return 0;
 } 
