#include<iostream>
#include<cstring>
using namespace std;

#define mod 10009

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,S,E,K;
	while(cin>>N>>S>>E>>K)
	{
		long long a[N][N],ans[N][N],temp[N][N];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<N;i++)
		{
			ans[i][i]=1;//ans���K��l�Ƭ��򥻤��� 
			for(int j=0;j<N;j++)
				cin>>a[i][j];
		}
		
		//�x�}�ֳt�� 
		while(K)
		{
			if(K%2)
			{
				//��l�� 
				memset(temp,0,sizeof(temp));
				
				//�x�}�ۭ��A�ۭ����G���temp 
				for(int i=0;i<N;i++)
					for(int j=0;j<N;j++)
						for(int k=0;k<N;k++)
							temp[i][j]+=a[i][k]*ans[k][j];
							
				//��temp���ans�A�p�G���W�Lmod�ȴN�� 
				for(int i=0;i<N;i++)
					for(int j=0;j<N;j++)
						ans[i][j]=(temp[i][j]>=mod?temp[i][j]%mod:temp[i][j]);
			}
			
			memset(temp,0,sizeof(temp));
			
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					for(int k=0;k<N;k++)
						temp[i][j]+=a[i][k]*a[k][j];
						
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					a[i][j]=(temp[i][j]>=mod?temp[i][j]%mod:temp[i][j]);
			
			K/=2;
		}
		
		cout<<ans[S][E]<<'\n';
	}
	return 0;
}


