#include<iostream>
#include<cstring> 
using namespace std;

string pw,pkg;
int n;

inline bool ch(string a,string b)
{
	if(a.size()!=b.size())return 0;
	for(int i=0;i<a.size();i++)
	{
		if(abs(a[i]-b[i])!='a'-'A'&&a[i]!=b[i])
			return 0;
	}
	return 1;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	getline(cin,pw);
	cin>>n;
	cin.ignore();
	for(int i=1;i<=n;i++)
	{
		getline(cin,pkg);
		if(ch(pw,pkg))cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}

