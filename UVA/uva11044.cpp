#include<iostream>
using namespace std;

int t,m,n;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		cout<<(m/3)*(n/3)<<'\n';
	}
	return 0;
}

