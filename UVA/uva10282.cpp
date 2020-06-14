#include<iostream>
#include<map>
using namespace std;

string str;
map<string,string> diction;
bool strintomap()
{
	if(str=="")
		return false;
		
	int i=0;
	string value;
	
	while(str[++i]!=' ');//until blank
	value=str.substr(0,i);//value
	
	while(str[++i]==' ');//until next words
	
	diction[str.substr(i,str.size()-i)]=value;
	return true;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(getline(cin,str))
		if(!(strintomap()))
			break;
	
		cout<<str<<endl<<endl<<endl;
	while(getline(cin,str))
	{
		if(diction.find(str)!=diction.end())
			cout<<diction[str]<<endl;
		else
			cout<<"eh\n";
	}
	return 0;
}

