#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int k,R,ans=0;
	cin>>k>>R;
	bool K[k];
	int link[k][k];
	memset(K,0,sizeof(K));
	memset(link,0,sizeof(link));
	
	K[0]=1;
	
	for(int i=0;i<R;i++)
	{
		int a,b,W;
		cin>>a>>b>>W;
		if(link[a][b]==0||link[a][b]>W)link[a][b]=W;
	}
	for(int ii=1;ii<k;ii++)//執行k-1次(第一次以執行完 
	{
		int min=2e9,minid=-1,toid=-1;
		for(int i=0;i<k;i++)
		{
			if(K[i])
			{
				for(int j=0;j<k;j++)
				{
					if(link[i][j]&&link[i][j]<min&&!K[j])
					{
						min=link[i][j];
						minid=j;
						toid=i;
					}
				}
			}
			
		}
		K[minid]=1;
		ans+=link[toid][minid];
	}
	cout<<ans<<endl;
	return 0;
}

