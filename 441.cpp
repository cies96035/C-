#include<iostream>
using namespace std;

int main()
{
	int N,M;
	long long ans=1,err=0,k;
	cin>>N>>M;
	for(int i=1;i<=M;i++)
	{
		ans*=(i+N);
		ans/=i;
	}
		cout<<ans<<endl;
	for(int m=1;m<=M;m++)
	{
		k=1;
		for(int j=1;j<=M-m;j++)
		{
			k*=(N-m+j);
			k/=j;
		}
		cout<<k<<endl;
		k*=m;
		cout<<k<<endl;
		err+=k;
	}
	cout<<ans-err<<endl;
	return 0;
}

