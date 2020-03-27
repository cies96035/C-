#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	string str;
	cin>>T;
	cin.ignore();
	while(T--)
	{
		getline(cin,str); 
		for(int i=0;i<str.size();i++)
			cout<<str.substr(i,str.size()-i)<<'\n';
	}
	return 0;
}

