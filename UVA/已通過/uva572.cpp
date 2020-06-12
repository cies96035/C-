#include<iostream>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
#define maxNM 110
#define in_bound(x,y) (x>=0&&y>=0&&x<n&&y<m) //is point(x,y)in bound

//if the point is 0,0 ,the connect points
int Move[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int n,m,cnt;
bool oil[maxNM][maxNM];
char c;
queue<pii> check;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>n>>m&&n!=0)
	{
		cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>c;
				if(c=='@')//if its a oilfield
				{
					oil[i][j]=1;
					check.push(pii(i,j));
				}
				else
					oil[i][j]=0;
			}
			
			
		while(!check.empty())
		{
			int i=check.front().first,j=check.front().second;
			check.pop();
			if(oil[i][j])//BFS
			{
				cnt++;
				queue<pii> nx_point;
				nx_point.push(pii(i,j));
				while(!nx_point.empty())
				{
					int t[2]={nx_point.front().first,nx_point.front().second};
					nx_point.pop();
					oil[t[0]][t[1]]=0;//the oilfield is visited
					for(int i=0;i<8;i++)
					{
						int x=t[0]+Move[i][0],y=t[1]+Move[i][1];
						if(in_bound(x,y)&&oil[x][y]==1)
							nx_point.push(pii(x,y));
					}
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
