#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;
const pii Move[4]={{0,1},{1,0},{0,-1},{-1,0}};
const int maxy=100;
int x,y,ans=0;

void Find(int X,int Y,bool r,bool g,bool b,bool ye,char Map[][maxy],int len)
{
	int visited[x][y];
	memset(visited,0,sizeof(visited));
	queue<pii> tobfs;
	tobfs.push(pii(X,Y));
	visited[X][Y]=len;
	while(!tobfs.empty())
	{
		pii now=tobfs.front();
		tobfs.pop();
		for(int i=0;i<4;i++)
		{
			int bx=now.first+Move[i].first,by=now.second+Move[i].second;
			if(bx>=0&&by>=0&&bx<x&&by<y&&Map[bx][by]!='#'&&!visited[bx][by])
			{
				if(!r&&Map[bx][by]=='r')//§ä¨ì¬õÆ_°Í 
				{
					Map[bx][by]='.';
					Find(bx,by,1,g,b,ye,Map,visited[now.first][now.second]+1);
				}
				else if(!g&&Map[bx][by]=='g')//§ä¨ìºñÆ_°Í 
				{
					Map[bx][by]='.';
					Find(bx,by,r,1,b,ye,Map,visited[now.first][now.second]+1);
				}
				else if(!b&&Map[bx][by]=='b')//§ä¨ìÂÅÆ_°Í 
				{
					Map[bx][by]='.';
					Find(bx,by,r,g,1,ye,Map,visited[now.first][now.second]+1);
				}
				else if(!ye&&Map[bx][by]=='y')//§ä¨ì¶ÀÆ_°Í 
				{
					Map[bx][by]='.';
					Find(bx,by,r,g,b,1,Map,visited[now.first][now.second]+1);
				}
				else if(
				(Map[bx][by]=='R'&&r==0)||//§ä¨ìªù¡A¨SÆ_°Í->¸õ¹L 
				(Map[bx][by]=='G'&&g==0)||
				(Map[bx][by]=='B'&&b==0)||
				(Map[bx][by]=='Y'&&ye==0))
				continue;
				
				else if(Map[bx][by]=='X')//§ä¨ì²×ÂI 
				{ 
					ans=visited[now.first][now.second];
					return;
				}
				tobfs.push(pii(bx,by));
				visited[bx][by]=visited[now.first][now.second]+1;
			}
		}
	}
}

int main()
{
	cin.tie();
	ios_base::sync_with_stdio(0);
	
	pii start;
	cin>>y>>x;
	char Map[x][maxy];
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
		{
			cin>>Map[j][i];
			if(Map[j][i]=='*')start=pii(j,i);
		}
	Find(start.first,start.second,0,0,0,0,Map,1);
	if(ans>0)
		cout<<"Escape possible in "<<ans<<" steps.\n";
	else
		cout<<"The poor student is trapped!\n";
	
	return 0;
}

