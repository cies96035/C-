#include<iostream>
using namespace std;

int gcd(int x,int y)
{
	while((x%=y)&&(y%=x));
	return x+y;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	unsigned long long a,b;
	int x,y,t;
	while(cin>>a>>b>>x>>y)
	{
		t=gcd(x,y);
		x/=t;
		y/=t;
		if((a/x)>(b/y))
			cout<<(b/y)*x<<' '<<(b/y)*y<<'\n';
		else
			cout<<(a/x)*x<<' '<<(a/x)*y<<'\n';
		
	}
	return 0;
}

