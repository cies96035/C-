#include<iostream>
using namespace std;

bool d[1000001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int k,sum;
	for(int i=1;i<999955;i++)
	{
		k=i,sum=i;
		while(k)
		{
			sum+=k%10;
			k/=10;
		}
		if(!d[sum])d[sum]=1;
	}
	for(int i=1;i<=1000000;i++)
		if(!d[i])cout<<i<<'\n';
	return 0;
}

