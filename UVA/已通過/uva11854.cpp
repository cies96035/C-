#include<iostream>
using namespace std;

int a,b,c;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin>>a>>b>>c&&a&&b&&c)
	{
		if(a>c)
			swap(a,c);
		if(b>c)
			swap(b,c);
		if(a*a+b*b-c*c)
			cout<<"wrong\n";
		else
			cout<<"right\n";
	}
	return 0;
}

