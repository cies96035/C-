#include<iostream>
using namespace std;

#define maxK 1000010
bool num[maxK];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,K,sum=0;
	cin>>N;
	while(N--)
	{
		cin>>K;
		if(!num[K])
			sum+=++num[K];
	}
	cout<<sum<<'\n';
	return 0;
}

