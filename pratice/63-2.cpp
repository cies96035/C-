#include<iostream>
using namespace std;

const int maxN=110;
#define Inf 2e9
int T,N,M,link[maxN][maxN],Max,tmp;

//給一個起始點，使用dijkstra 
void di(int a)
{
	int num[N],min,minid;
	bool vis[N]={0};
	for(int i=0;i<N;i++)
		num[i]=Inf;
	num[a]=0;
	vis[a]=1;
	for(int i=1;i<N;i++)
	{
		min=Inf;
		for(int i=0;i<N;i++)
			if((tmp=num[a]+link[a][i])<num[i])
				num[i]=tmp;
		for(int i=0;i<N;i++)
			if(num[i]<min&&!vis[i])
				minid=i,min=num[i];
		a=minid;
		vis[a]=1;
	}
	for(int i=0;i<N;i++)
		if(Max<num[i]&&vis[i])Max=num[i];
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>T;
	while(T--)
	{
		Max=0;
		cin>>N>>M;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				link[i][j]=Inf;
		for(int i=0,tmp1,tmp2,tmp3;i<M;i++)
		{
			cin>>tmp1>>tmp2>>tmp3;
			if(tmp3<link[tmp1][tmp2]&&tmp1!=tmp2)
				link[tmp1][tmp2]=link[tmp2][tmp1]=tmp3;
		}
		for(int i=0;i<N;i++)
			di(i);
		cout<<Max<<'\n';
	}
	
	return 0;
}

