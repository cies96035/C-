#include<iostream>
using namespace std;

typedef long long ll;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n;
	while(n--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		cout<<(c+1)/2*a-c/2*b<<'\n';
	}
	return 0;
}

