#include<iostream>
using namespace std;

bool isword(char x)
{
	return ((x>='A'&&x<='Z')||(x>='a'&&x<='z'));
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	char k;
	bool word=1;
	int sum=0;
	while(cin.get(k))
	{
		if(word&&isword(k))
		{
			word=0;
			sum++;
		}
		else if(k=='\n')
		{
			cout<<sum<<endl;
			word=1;
			sum=0;
		}
		else if(!word&&!isword(k))
		{
			word=1;
		}
	}
	return 0;
}

