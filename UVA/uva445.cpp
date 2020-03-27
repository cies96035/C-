#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	char k;
	int sum=0;
	while(cin.get(k))
	{
		if(k>='0'&&k<='9')
			sum+=k-'0';
		else if(k=='!'||k=='\n')cout<<'\n';
		else
		{
			if(k=='b')k=' ';
			while(sum--)
				cout<<k;
			sum=0;
		}
	}
	return 0;
}
