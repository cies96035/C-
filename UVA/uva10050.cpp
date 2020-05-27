#include<iostream>
#include<cstring> 
using namespace std;

#define maxN 3800
bool arr[maxN];
int t,N,tmp,p,ans;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>N>>p;
		while(p--)
		{
			cin>>tmp;
			for(int i=tmp;i<=N;i+=tmp)
				arr[i]=1;
		}
		for(int i=1;i<=N;i++)
			if(arr[i]&&(((i+1)%7)&&(i%7)))
				ans++;
		cout<<ans<<'\n';
		memset(arr,0,sizeof(arr));
	}
	return 0;
}

