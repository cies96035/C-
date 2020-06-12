#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define Max 2e9

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	for(int Case=1;Case<=T;Case++)
	{
		
		int N,M,S;
		cin>>N>>M>>S;
		
		int K[N],End=Max;
		bool road[N][N];
		memset(road,0,sizeof(road));
		for(int i=0;i<N;i++)
		{
			cin>>K[i];
			if(K[i]<End)
				End=K[i];
		}
		for(int i=0,a,b;i<M;i++)
		{
			cin>>a>>b;
			road[a][b]=road[b][a]=1;
		}
		
		
		queue<int> togo;
		int vis[N],walk=-1;
		memset(vis,-1,sizeof(vis));
		togo.push(S);
		vis[S]=0;
		while(!togo.empty())
		{
			int cur=togo.front();
			togo.pop();
			if(K[cur]==End)
			{
				walk=vis[cur];
				break;
			}
			for(int i=0;i<N;i++)
				if(road[cur][i]&&vis[i]==-1)
				{
					vis[i]=vis[cur]+1; 
					togo.push(i);
				}
		}
		
		int cur=S,car=0;
		while(K[cur]!=End)
		{
			int Low,l=Max;
			for(int i=0;i<N;i++)
			{
				if(road[cur][i]&&K[i]<l)
					{
						l=K[i];
						Low=i;
					}
			}
			
			if(l>=K[cur])
			{
				car=0;
				break;
			}
			cur=Low;
			car++;
		}
		
		cout<<"Case #"<<Case<<": ";
		if(walk!=-1)cout<<walk*6-car<<'\n';
		else cout<<"Call 119!\n";
		
	}
	return 0;
}

