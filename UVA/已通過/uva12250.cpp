#include<iostream>
#include<map>
using namespace std;

map<string,string> m;
string s;
int Case=1;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
	m["HELLO"]="ENGLISH";
	m["HOLA"]="SPANISH";
	m["HALLO"]="GERMAN";
	m["BONJOUR"]="FRENCH";
	m["CIAO"]="ITALIAN";
	m["ZDRAVSTVUJTE"]="RUSSIAN";
	
	while(cin>>s&&s!="#")
	{
		cout<<"Case "<<Case++<<": ";
		if(m.find(s)!=m.end())
			cout<<m[s]<<'\n';
		else
			cout<<"UNKNOWN\n";
	}
	return 0;
}

