#include<iostream>
using namespace std;

int n,m;

//(m-1)+m*(n-1)==m*n-1
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>n>>m)
		cout<<n*m-1<<'\n';
	return 0;
}

