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
		sort(troop,troop+n);	//algorithm���е����� 
		for(int i=0;i<n;i++)
		{
			num++;
			int j=i;
			while(j+1<n)	//��Ϊ�Ǵ�С�����������԰�palantir�����������,����j�� 
				if(troop[j+1]-troop[i]<=r)
					j++;
				else
					break;
			int k=j;
			while(k+1<n)	//k�����һ�������ǵĵ� 
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
