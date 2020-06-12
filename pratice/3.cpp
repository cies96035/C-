#include<iostream>
using namespace std;
int N,a,b;
int Gcd(int a,int b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>N;
	while(N--)
	{
		cin>>a>>b;
		cout<<Gcd(a,b)<<'\n';
	}
	return 0;
}

