#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	ll N,K,n=-2e9,sum=0;
	cin>>N;
	while(N--)
	{
		cin>>K;
		if(K>0)sum+=K;
		if(K>n)n=K;
	}
	cout<<(sum==0?n:sum)<<'\n';
	return 0;
}

