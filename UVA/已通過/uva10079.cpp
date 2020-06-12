#include<iostream>
using namespace std;

typedef long long ll;
ll n;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while((cin>>n)&&n>=0)
		cout<<(n+1)*n/2+1<<'\n';
	return 0;
}

