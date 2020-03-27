#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	long long a,b,t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a>b)cout<<'>'<<endl;
		else if(a<b)cout<<'<'<<endl;
		else cout<<'='<<endl;
	}
	return 0;
}

