#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxN=100000,MAX=2e9;
struct L
{int v,t;};

//變數區 
int N,K,M,m;
vector<L> link[2][maxN];//0為站外，1為站內
int dis[2][maxN];

//輸入區 
void Input()
{
	cin>>N>>K;
	cin>>M;
	for(int i=0,a,b,c;i<M;i++)
	{
		cin>>a>>b>>c;
		link[0][a].push_back(L{b,c});
		link[0][b].push_back(L{a,c});
	}
	cin>>m;
	for(int i=0,a,b,c;i<m;i++)
	{
		cin>>a>>b>>c;
		link[1][a].push_back(L{b,c});
		link[1][b].push_back(L{a,c});
	}
}
//初始化 
void Init()
{
	for(int i=1;i<N;i++)dis[0][i]=MAX;
	for(int i=0;i<N;i++)dis[1][i]=MAX;
}

int main()
{
	Input();
	Init();
	queue<int>togo;
	togo.push(0);
	while(!togo.empty())
	{
		int cur=togo.front();
		togo.pop();
		for(int i=0;i<link[0][cur].size();i++)
		{
			int tar=link[0][cur][i].v;
			dis[0][tar]=min(dis[0][tar],dis[0][cur]+link[0][cur][i].t);
		}
		for(int i=0;i<link[1][cur].size();i++)
		{
			
		}
	}
	
	
	return 0;
}

