#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


//沒辦法了，剩下暴力解 
//建Vector圖紀錄各點已融合的id 
//建id圖，紀錄id 
//如果0->直接丟
//如果非零
//->判斷是否vector圖的id裡面有，沒有->
//->判斷是否同深度 
//丟進去，判斷id
//如果兩個id的child圖是0，新增id
 

const int mxmn=100;

typedef pair <int,int> pii;
vector<int> map[mxmn][mxmn];
int deep[mxmn][mxmn];

int N,M,P,id[mxmn];

int m[4][2]={{1,0},{0,1},{0,-1},{-1,0}};

queue<pii> togo; 

inline void Co(int ax,int ay,int bx,int by)
{
	for(int i=0;i<map[ax][ay].size();i++)
		map[bx][by].emplace_back(map[ax][ay][i]);
	sort(map[bx][by].begin(),map[bx][by].end());
	map[bx][by].erase(unique(map[bx][by].begin(),map[bx][by].end()),map[bx][by].end());
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N>>M>>P;
	for(int tmpx,tmpy,i=1;i<=P;i++)
	{ 
		cin>>tmpx>>tmpy;
		tmpx--;
		tmpy--;
		togo.push(pii(tmpx,tmpy));
		map[tmpx][tmpy].emplace_back(i);
		deep[tmpx][tmpy]=1;
	}
	
	
	while(!togo.empty())
	{
		int tg[2]={togo.front().first,togo.front().second};
		togo.pop();
		for(int i=0;i<4;i++)
		{
			pii nxg=pii(tg[0]+m[i][0],tg[1]+m[i][1]);
			if(nxg.first<0||nxg.first==N||nxg.second<0||nxg.second==M)//界限判斷 
				continue;
			if(deep[nxg.first][nxg.second]==0)
			{
				Co(tg[0],tg[1],nxg.first,nxg.second);
				deep[nxg.first][nxg.second]=deep[tg[0]][tg[1]]+1;
				togo.push(nxg);
			} 
			else if(deep[tg[0]][tg[1]]+1==deep[nxg.first][nxg.second])//融合 
				Co(tg[0],tg[1],nxg.first,nxg.second);
		}
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			for(int k=0;k<map[i][j].size();k++)
				id[map[i][j][k]]++;
	for(int i=1;i<=P;i++)
	cout<<id[i]<<'\n';
	return 0;
}

