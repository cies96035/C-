//應該可以 
#include<iostream>
#include<algorithm> 
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	//5 2 3 7 8 12
	int n;
	cin>>n;
	int bar[n];
	for(int i=0;i<n;i++)cin>>bar[i];
	sort(bar,bar+n);
	for(int i=2;i<n;i++)
	{
		if(bar[i]<bar[i-1]+bar[i-2])
		{
			cout<<bar[i]+bar[i-1]+*upper_bound(bar,bar+n,bar[i]-bar[i-1])<<'\n';
			return 0;
		}
	}
}

