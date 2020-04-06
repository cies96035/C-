#include<iostream>
using namespace std;

int main()
{
	int n,i,ans=1;
	cin>>n>>i;
	while(i--)ans*=n;
	cout<<ans<<endl;
	return 0;
}

