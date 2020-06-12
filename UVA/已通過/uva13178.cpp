#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		if(num%3==1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}

