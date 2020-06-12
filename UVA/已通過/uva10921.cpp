#include<iostream>
using namespace std;

char c;
string value=
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
 "22233344455566677778889999";
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin.get(c))
	{
		if('A'<=c&&c<='Z')
			cout<<value[c-'A'];
		else
			cout<<c;
	}
	return 0;
}

