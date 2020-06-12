#include<iostream>
#include<algorithm>
using namespace std;

#define maxN 2000100

int n;
int arr[maxN];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		for(int i=0;i<n-1;i++)
			cout<<arr[i]<<' ';
		cout<<arr[n-1]<<'\n';
	}
	return 0;
}

