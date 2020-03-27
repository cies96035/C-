#include<iostream>
using namespace std;

typedef long long ll;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		ll A,B,C;
		cin>>A>>B>>C;
		if(A>C)swap(A,C);
		if(B>C)swap(B,C);
		cout<<(A+B>C?"Yes\n":"No\n");
	}
	return 0;
}

