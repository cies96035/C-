#include<iostream>
using namespace std;

long long Abs(long long x)
{
	return (x>0?x:-x);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	long long a,b;
	while(cin>>a>>b)
	{
		cout<<Abs(a-b)<<endl;
	}
	return 0;
}
