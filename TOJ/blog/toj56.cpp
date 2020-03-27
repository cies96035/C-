#include<iostream>
using namespace std;

long long gcd(long long a,long long b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}

int main()
{
	long long a,b;
	while(cin>>a>>b)
		cout<<gcd(a,b)<<endl;
	return 0;
}

