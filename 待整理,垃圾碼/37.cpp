#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	char k;
	int ans=0;
	bool f=0;
	while(cin.get(k))
	{
		if(k==' ')
		{
			if(f)
				ans++,f=0;
		}
		else if(k=='\n')
		{
			if(f)
				ans++,f=0;
			cout<<ans<<'\n';
			ans=0;
		}
		else
		{
			f=1;
		}
	}
	return 0;
}

