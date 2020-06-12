#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		int f,sum=0,area,animal,environment;
		cin>>f;
		while(f--)
		{
			cin>>area>>animal>>environment;
			sum+=area*environment;
		}
		cout<<sum<<'\n';
	}
	return 0;
}

