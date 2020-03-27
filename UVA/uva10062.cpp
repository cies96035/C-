#include<iostream>
#include<cstring>
using namespace std;

int ASCII[256];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	char k,f=0;
	int l=0,Min=2e9,Max=0;
	while(cin.get(k))
	{
		if(k=='\n')
		{
			if(f)cout<<endl;
			for(int i=1;i<=l;i++)
			{
				for(int j=Max;j>=Min;j--)
				{
					if(ASCII[j]==i)
					cout<<j<<' '<<i<<endl;
				}
			}
			l=Max=0;
			Min=2e9;
			f=1;
		memset(ASCII,0,sizeof(ASCII));
		}
		else
		{
			ASCII[(int)k]++;
			l++;
			Min=min((int)k,Min);
			Max=max((int)k,Max);
		}
	}
	return 0;
}

