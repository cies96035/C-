#include<iostream>
using namespace std;
//字元往後移位... 
int main()
{
	char word;
	while(cin.get(word))
	{
		if(word=='\n')
			cout<<endl;
		else
			cout<<(char)(word-'1'+'*');
	}
	return 0;
}

