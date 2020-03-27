#include<iostream>
using namespace std;

int main()
{
	int T;
	char word;
	cin>>T;
	while(T--)
	{
		cin>>word;
		if(word<='Z')cout<<(char)(word-'A'+'a');
		else cout<<(char)(word-'a'+'A');
	}
	cout<<endl;
	return 0;
}

