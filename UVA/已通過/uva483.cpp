#include<iostream>
using namespace std;

string S;
char c;
void rstring(string s)
{
	for(int i=s.size()-1;i>=0;i--)
		cout<<s[i];
}
int main()
{
	while(cin.get(c))
	{
		if(c=='\n'||c==' ')
		{
			rstring(S);
			cout<<c;
			S.clear();
		}
		else
			S+=c;
	}
	return 0;
}

