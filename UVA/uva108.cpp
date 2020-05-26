#include<iostream>
using namespace std;


//the maxN is too small so it can just force

#define maxN 110
int N;
int sum[maxN][maxN],Max;

inline int getsum(int u,int l,int d,int r)
{
	return sum[d][r]-sum[u-1][r]-sum[d][l-1]+sum[u-1][l-1];
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin>>N)
	{
		Max=-2e9;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				cin>>sum[i][j];
				sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			}
		}
		for(int u=1;u<=N;u++)
			for(int l=1;l<=N;l++)
			{
				for(int d=u;d<=N;d++)
					for(int r=l;r<=N;r++)
					{
						if(getsum(u,l,d,r)>Max)Max=getsum(u,l,d,r);
					}
			}
		cout<<Max<<'\n';
	}
	return 0;
}

