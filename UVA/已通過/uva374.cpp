#include<iostream>
using namespace std;

typedef long long ll;
ll B,P,M,b;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>B>>P>>M)
	{
		b=1;
		while(P)
		{
			if(P%2)
			{
				b*=B;
				b%=M;
			}
			P/=2;
			B*=B;
			B%=M;
		}
		cout<<b<<'\n';
	}
	return 0;
}

