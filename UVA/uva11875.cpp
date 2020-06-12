#include<iostream>
#include<algorithm> 
using namespace std;

int t,n;
int arr[11];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	for(int Case=1;Case<=t;Case++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		cout<<"Case "<<Case<<": "<<arr[n/2]<<'\n';
	}
	return 0;
}
