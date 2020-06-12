#include<iostream>
using namespace std;

int T;
string S;
bool per(string s)
{
	for(int i=0;i<S.size();i+=s.size())
		if(S.substr(i,s.size())!=s)
			return false;
	return true;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>T;
	while(T--)
	{
		cin>>S;
		for(int i=1;i<=S.size();i++)
		{
			if(!(S.size()%i))
			{
				if(per(S.substr(0,i)))
				{
					cout<<i<<'\n';
					break;
				}
					
			}
		}
		if(T)
			cout<<'\n';
	}
	return 0;
}

