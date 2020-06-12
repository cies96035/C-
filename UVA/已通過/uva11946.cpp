#include<iostream>
using namespace std;

int main()
{
	int T;
	char alpha[10]={'O','I','Z','E','A','S','G','T','B','P'};
	bool end=0;
	cin>>T;
	char k;
	cin.get();
	while(T)
	{
		cin.get(k);
		if(k>='0'&&k<='9')
			cout<<alpha[k-'0'];
		else
		{
			if(!(k=='\n'&&T==1&&end))
				cout<<k;
			if(k=='\n')
			{
				if(!end)
					end=1;
				else
					T--;
			}
			else if(end)
				end=0;
		}
	}
	return 0;
}

