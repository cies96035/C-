#include<iostream>
using namespace std;

//�P�_�C�Ӧr��,���޸����ܦA���D�N��X�Y�i 
int main()
{
	string qutoes;
	char k;
	bool flag=1;
	while(cin.get(k))
	{
		if(k=='\"')
		{
			if(flag)
				cout<<"``";
			else
				cout<<"''";
			flag=!flag;
		}
		else
			cout<<k;
	}
	return 0;
}

