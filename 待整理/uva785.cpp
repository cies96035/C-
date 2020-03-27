#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
 
typedef pair<int,int> pii;
vector<string> grid;
queue<pii> tobfs;
 
void BFS()
{
	pii move[4]={{0,1},{1,0},{0,-1},{-1,0}};
	while(!tobfs.empty())
	{
		char word=grid[tobfs.front().first][tobfs.front().second];
		queue<pii> bfs;
		bfs.push(tobfs.front());
		tobfs.pop();
		while(!bfs.empty())
		{
			pii k=bfs.front();
			bfs.pop();
			//system("pause");
			for(int i=0;i<4;i++)
			{
				int y=(k.first+move[i].first),x=(k.second+move[i].second);
				if(x>=0&&y>=0&&grid[y][x]==' ')
				{
					grid[y][x]=word;
					bfs.push(pii(y,x));
				}
			}
		}
	}
	for(int i=0;i<grid.size();i++)
		cout<<grid[i]<<'\n';
 
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string input;
	char inputchar;
	bool endline=1;
	int x=0,y=0;
	while(cin.get(inputchar))
	{
		if(inputchar!='\n')
		{
			if(inputchar!='_')
			{ 
				endline=0;
				if(inputchar!=' '&&inputchar!='X')
					tobfs.push(pii(y,x));
			}
			input.append(1,inputchar);
		x++;
		}
		else
		{
			if(endline&&!input.empty())
			{
				//for(int i=0;i<grid.size();i++)
				//	grid[i].append(input.size()-grid[i].size(),' ');
				BFS();
				cout<<input<<'\n'<<flush;
				y=-1;
				grid.clear();
			}
			else grid.push_back(input);
			y++;
			x=0;
			endline=1;
			input.clear();
		}
	}
	return 0;
}
