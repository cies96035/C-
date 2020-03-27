#include<iostream>
using namespace std;

#define n 9999999999999

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int M,N,P;
	unsigned long long ans=1;
	cin>>N>>M>>P;
	while(N)
	{
		ans*=N;
		ans%=P;
		N--;
	}
	ans+=(M%P)*(n%P);
	cout<<ans%P<<endl;
	return 0;
}

