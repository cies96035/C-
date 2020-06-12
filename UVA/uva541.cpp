#include<iostream>
#include<cstring>
using namespace std;

#define Maxn 110
int sum[2][Maxn];
int n,num,ans[2];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin>>n&&n)
	{
		ans[0]=ans[1]=-1;
		memset(sum,0,sizeof(sum));
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>num;
				sum[0][i]+=num;
				sum[1][j]+=num;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<2;j++)
				if(sum[j][i]%2)
				{
					if(ans[j]>=0)
						ans[j]=-2;
					else if(ans[j]!=-2)
						ans[j]=i;
				}
		}
		if(ans[0]==-2||ans[1]==-2)
			cout<<"Corrupt\n";
		else if(ans[0]==-1)
			cout<<"OK\n";
		else
			cout<<"Change bit ("<<ans[0]+1<<','<<ans[1]+1<<")\n";
	}
	return 0;
}

