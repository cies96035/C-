#include<iostream>
#include<queue>
using namespace std;

//�P�_x,y���S���W�L�j�pm,n���}�C 
#define isnt_out_of_range(x,y,m,n) (0<x&&x<=m&&0<y&&y<=n)

//�x�s��m��struct 
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
	
	//�������Ǯ�l����e�� # 1~N,1~M 
	bool cant_go[N+1][M+1]={0};
	
	//�����ۤ��I�A�ХܸӮ椣�ਫ
	while(F--)
	{
		cin>>X>>Y;
		cant_go[X][Y]=1;
	}
	
	//�W�k�U�� 
	Point move[4]={{0,1},{1,0},{0,-1},{-1,0}};
	queue<Point> BFS;
	BFS.push(me);//�e���_�I 
	cant_go[me.x][me.y]=1;//�_�I�Хܨ��L�A�O�A���^���קK�L���j��
	
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
			//�p�G�e���d��S���W�X��ɡA�Bcantgo�S���аO 
			if(isnt_out_of_range(X,Y,N,M)&&!cant_go[X][Y])
			{
				BFS.emplace(X,Y);
				cant_go[X][Y]=1;//�аO���L�A�קK�L���j�� 
			}
		}
	}
	if(BFS.empty())
		cout<<"Harakiri!\n";
		
	return 0;
}

