#include<iostream>
using namespace std;

//判斷每個字元,雙引號的話再依題意輸出即可 
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

