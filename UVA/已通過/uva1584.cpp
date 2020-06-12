#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		int s;
		string str,minstr;
		cin>>str;
		minstr=str;
		s=str.size();
		str.append(str);	
		for(int i=1;i<s;i++)
			if(str.substr(i,s)<minstr)
				minstr=str.substr(i,s);
		cout<<minstr<<'\n';
	}
	return 0;
}

