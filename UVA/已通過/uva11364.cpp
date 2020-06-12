#include<iostream>
using namespace std;

int t,n,Max,Min,input;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	while(t--)
	{
		Max=-2e9;
		Min=-Max;
		cin>>n;
		while(n--)
		{
			cin>>input;
			if(input>Max)Max=input;
			if(input<Min)Min=input;
		}
		cout<<(Max-Min)*2<<'\n';
	}
	return 0;
}

