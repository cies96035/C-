//好像不能線性... 
#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		int n,ans=0;
		cin>>n;
		int s[n];
		for(int i=0;i<n;i++)
			cin>>s[i];
		for(int i=0;i<n;i++)
		{
			int Min=s[i],Max=s[i];
			for(int j=i+1;j<n;j++)
			{
				if(s[j]>Max)Max=s[j];
				if(s[j]<Min)Min=s[j];
				if(abs(s[j]-s[i])==j-i&&Max==max(s[j],s[i])&&Min==min(s[j],s[i]))
					ans++;
			}
		}
		cout<<ans<<'\n';
		
	}
	return 0;
}

