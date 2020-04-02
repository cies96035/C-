#include<iostream>
#include<queue>
using namespace std;

//判斷x,y有沒有超過大小m,n的陣列 
#define isnt_out_of_range(x,y,m,n) (0<x&&x<=m&&0<y&&y<=n)

//儲存位置的struct 
struct Point
{
	int x,y;
	Point(int a,int b)
	{
		x=a;
		y=b;
	}
}me={0,0},door={0,0};

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,M,F,X,Y;
	cin>>N>>M>>me.x>>me.y>>door.x>>door.y>>F;
	
	//紀錄那些格子不能前往 # 1~N,1~M 
	bool cant_go[N+1][M+1]={0};
	
	//紀錄著火點，標示該格不能走
	while(F--)
	{
		cin>>X>>Y;
		cant_go[X][Y]=1;
	}
	
	//上右下左 
	Point move[4]={{0,1},{1,0},{0,-1},{-1,0}};
	queue<Point> BFS;
	BFS.push(me);//前往起點 
	cant_go[me.x][me.y]=1;//起點標示走過，別再往回走避免無限迴圈
	
	while(!BFS.empty()) 
	{
		Point togo=BFS.front();
		if(door.x==togo.x&&door.y==togo.y)
		{
			cout<<"Cool!\n";
			return 0;
		}
		BFS.pop();
		for(int i=0;i<4;i++)
		{
			X=togo.x+move[i].x;
			Y=togo.y+move[i].y;
			//如果前往範圍沒有超出邊界，且cantgo沒有標記 
			if(isnt_out_of_range(X,Y,N,M)&&!cant_go[X][Y])
			{
				BFS.emplace(X,Y);
				cant_go[X][Y]=1;//標記走過，避免無限迴圈 
			}
		}
	}
	if(BFS.empty())
		cout<<"Harakiri!\n";
		
	return 0;
}

