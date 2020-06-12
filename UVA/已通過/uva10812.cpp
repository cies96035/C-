#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	long double t,s,d;
	long long a,b;
	cin>>t;
	while(t--)
	{
		cin>>s>>d;
		a=s/2+d/2;
		b=s/2-d/2;
		if(a+b==s&&b>=0)
			cout<<a<<' '<<b<<endl;
		else
			cout<<"impossible"<<endl;
	}
	return 0;
}

