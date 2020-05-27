#include<iostream>
using namespace std;

int n,k,ans;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin>>n>>k)
	{
		ans=0;
		while(n>=k)
		{
			ans+=n/k*k;
			n=n%k+n/k;
		}
		cout<<ans+n<<'\n';
	}
	return 0;
}

