#include<iostream>
#include<algorithm> 
using namespace std;

#define maxn 550 
int t,n,m,arr[maxn];
inline int sgma(int s,int e,bool f)
{
	int S=0;
	for(int i=s;i<=e;i++)
		S+=arr[i];
	if(f)
		S=-S;
	return S;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		n--;
		m=n/2;
		cout<<sgma(0,m,1)+sgma(m+1,n,0)+(n%2?0:arr[m])<<'\n';
	}
	return 0;
}

