#include<iostream>
using namespace std;

int t,n,sum=0;
string s;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s=="donate")
		{
			cin>>n;
			sum+=n;
		}
		else
			cout<<sum<<'\n';
	}
	
	return 0;
}

