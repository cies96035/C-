#include<iostream>
using namespace std;

const int maxn=1010;
int arr[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	while(--n)
		cout<<arr[n]<<' ';
	cout<<arr[0]<<endl; 
	return 0;
}

