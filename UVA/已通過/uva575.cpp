#include<iostream>
using namespace std;

typedef long long ll;
#define n 32

string s;
ll skew[n];
void Init()
{
	ll two=1;
	for(int i=0;i<n;i++)
	{
		two*=2;
		skew[i]=two-1;
	}
	return;
}
ll str_to_num()
{
	ll num=0;
	for(int i=0,j=s.size()-1;i<s.size();i++,j--)
		num+=skew[i]*(s[j]-'0');
	return num;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Init();
	while(cin>>s&&s!="0")
		cout<<str_to_num()<<'\n';
		
	return 0;
}

