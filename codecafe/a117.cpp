#include<iostream>
using namespace std;

#define strtonum(i) i-'0'

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string a;
	while(cin>>a)
	{
		int sum=0;
		for(int i=max(int(a.size()-31),0);i<a.size();i++)
		{
			sum=sum*2+strtonum(a[i]);
		}
		cout<<sum<<'\n';
	}
	return 0;
}

