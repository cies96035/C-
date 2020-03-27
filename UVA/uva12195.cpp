#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	char k;
	int ans=0;
	long double beat=0;
	while(cin.get(k))
	{
		//cout<<beat<<endl;
		if(k=='/')
		{
			if(beat==1)ans++;
			beat=0;
		}
		else if(k=='W')beat+=1;
		else if(k=='H')beat+=0.5;
		else if(k=='Q')beat+=0.25;
		else if(k=='E')beat+=0.125;
		else if(k=='S')beat+=0.0625;
		else if(k=='T')beat+=0.03125;
		else if(k=='X')beat+=0.015625;
		else if(k=='\n')
		{
			cout<<ans<<endl;
			ans=0;
		}
		else if(k=='*')
			break;
	}
	return 0;
}

