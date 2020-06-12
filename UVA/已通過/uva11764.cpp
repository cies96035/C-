#include<iostream>
using namespace std;

int t,n,a[2],u,d;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	for(int Case=1;Case<=t;Case++)
	{
		u=d=0;
		cin>>n>>a[0];
		for(int i=1;i<n;i++)
		{
			cin>>a[i%2];
			if(a[i%2]>a[(i-1)%2])
				u++;
			else if(a[i%2]<a[(i-1)%2])
				d++;
		}
		cout<<"Case "<<Case<<": "<<u<<' '<<d<<'\n';
	}
	return 0;
}

