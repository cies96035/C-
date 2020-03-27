#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n,m,Field=1;
	pair<int,int> move[8]={{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}}; 
	char mine;
	while(cin>>n>>m)
	{
		if(n==0)return 0;
		int sweeper[n][m];
		memset(sweeper,0,sizeof(sweeper));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>mine;
				if(mine=='*')
				{
					for(int k=0;k<8;k++)
					{
						int X=move[k].first+i,Y=move[k].second+j;
						if(X>=0&&X<n&&Y>=0&&Y<m&&sweeper[X][Y]!=9)
							sweeper[X][Y]++;
					}
					sweeper[i][j]=9;
				}
			}
		if(Field>1)cout<<'\n';
		cout<<"Field #"<<Field++<<":\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				sweeper[i][j]!=9 ? cout<<sweeper[i][j] : cout<<'*';
			cout<<'\n';
		}
	}
	
		
	return 0;
}

