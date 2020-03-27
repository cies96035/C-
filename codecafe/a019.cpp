#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		while(N>9)
		{
			int n=0;
			while(N)
			{
				n+=N%10;
				N/=10;
			}
			N=n;
		}
		cout<<N<<'\n';
	}
	return 0;
}

