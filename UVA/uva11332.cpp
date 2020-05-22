#include<iostream>
using namespace std;

int N;

int f(int num)
{
	int s=0;
	while(num)
	{
		s+=num%10;
		num/=10;
	}
	if(s>9)
		return f(s);
	return s;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>N&&N)
		cout<<f(N)<<'\n';
	return 0;
}

