#include<iostream>
using namespace std;
int t,N,a[25];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		cin>>N;
		for(int i=0;i<=N;i++)
			cin>>a[i];
		for(int i=0;i<=N;i++)
			for(int j=N;j>i;j--)
				a[j]-=a[j-1];
		cout<<a[N]<<'\n';
	}
	return 0;
}

