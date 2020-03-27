#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<i<<'*'<<j<<'='<<i*j<<' '; 
		}
		cout<<'\n';
	}
	return 0;
}

