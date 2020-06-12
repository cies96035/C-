#include<iostream>
using namespace std;

char c;
int t,ans,cnt;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	cin.ignore();
	while(t--)
	{
		cnt=ans=0;
		while(cin.get(c))
		{
			if(c=='O')
				ans+=(++cnt);
			else if(c=='X')
				cnt=0;
			else if(c=='\n')
				break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

