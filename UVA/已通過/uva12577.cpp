#include<iostream>
using namespace std;

string input; 
int Case=1;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>input&&input!="*")
	{
		if(input=="Hajj")
			cout<<"Case "<<Case++<<": Hajj-e-Akbar\n";
		if(input=="Umrah")
			cout<<"Case "<<Case++<<": Hajj-e-Asghar\n";
	}
	return 0;
}

