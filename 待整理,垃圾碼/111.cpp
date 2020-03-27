#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string a[2],b;
	int n,m;
	cin>>a[0]>>a[1];
	cin>>n>>m;
	
	b=a[1];
	for(int i=2;i<n;i++)
	{
		a[(i+1)%2]=b;
		b+=a[(i)%2];
	cout<<b<<endl;
	}
	
	if(b[m-1]>='a'&&b[m-1]<='z')
		cout<<b[m-1]<<endl;
	else
		cout<<'X'<<endl;
	return 0;
}

