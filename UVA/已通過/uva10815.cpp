#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

char c;
string s;
vector<string> str;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin.get(c))
	{
		if('A'<=c&&c<='Z')
			s+=c-'A'+'a';
		else if('a'<=c&&c<='z')
			s+=c;
		else if(s.size()!=0)
		{
			str.emplace_back(s);
			s.clear();
		}
	}
	
	if(s.size()!=0)
	{
		str.emplace_back(s);
		s.clear();
	}
		
	sort(str.begin(),str.end());
	
	cout<<str[0]<<'\n';
	for(int i=1;i<str.size();i++)
		if(str[i-1]!=str[i])
			cout<<str[i]<<'\n';
	return 0;
}
