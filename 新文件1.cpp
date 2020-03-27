#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define in_edge(m,n,x,y) (x>=0&&x<m&&y>=0&&y<n) 
 
vector<int> deep_sum;
struct Point
{
	int x,y;
	Point (int a,int b)
	{
		x=a;
		y=b;
	}
}me={0,0};


int main()
{
	int N,M,Q;
	cin>>N>>M>>Q>>me.x>>me.y;
	me.x--;
	me.y--;
	int Map[N][M],deep[N][M];
	memset(deep,-1,sizeof(deep));
	Point move[4]={{0,1},{1,0},{0,-1},{-1,0}};
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>Map[i][j];
			
	queue<Point> BFS;
	BFS.push(me);
	deep[me.x][me.y]=0;
	deep_sum.push_back(0);
	while(!BFS.empty())
	{
		Point togo=BFS.front();
		BFS.pop();
		for(int i=0;i<4;i++)
		{
			int X=move[i].x+togo.x,Y=move[i].y+togo.y;
			if(in_edge(M,N,X,Y)&&deep[X][Y]==-1&&Map[X][Y]!=-1)
			{
				BFS.emplace(X,Y);
				deep[X][Y]=deep[togo.x][togo.y]+1;
				if(deep_sum.size()<deep[X][Y])
					deep_sum.push_back(Map[X][Y]+deep_sum[deep_sum.size()-1]);
				else deep_sum[deep_sum.size()-1]+=Map[X][Y];
			}
		}
	}

	while(Q--)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			int i,j,k;
			cin>>i>>j>>k;
			i--;
			j--;
			if(Map[i][j]!=-1&&!(i==me.x&&j==me.y))
			{
				for(int p=deep[i][j]-1;p<deep_sum.size();p++)
					deep_sum[p]+=-Map[i][j]+k;
				Map[i][j]=k;
			}
		}
		if(t==2)
		{
			int W;
			cin>>W;
			cout<<upper_bound(deep_sum.begin(),deep_sum.end(),W)-deep_sum.begin()<<endl;
		}
		/*for(int i=0;i<deep_sum.size();i++)
		cout<<deep_sum[i]<<endl;*/
	}
	return 0;
}

