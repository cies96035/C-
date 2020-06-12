#include<iostream>
using namespace std;

string s;
int sum=0;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>s&&s!="0")
	{
		for(int i=0;i<s.size();i++)
		{
			if(i&1)
				sum+=s[i]-'0';
			else
				sum-=s[i]-'0';
		}
		if(sum%11)
			cout<<s<<" is not a multiple of 11.\n";
		else
			cout<<s<<" is a multiple of 11.\n";
		sum=0;
	}
	return 0;
}

