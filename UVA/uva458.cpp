#include<iostream>
using namespace std;
//�r�����Ჾ��... 
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

