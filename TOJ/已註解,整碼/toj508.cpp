#include<iostream>
#include<stack>
using namespace std;

typedef pair<int,int> pii;

const int maxNM=1050;
const int m[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

char table[maxNM][maxNM]; 
pii CF[maxNM][maxNM];//comefrom[i][j]，紀錄點(i)(j)來自哪裡 
int N,M,cnt,DP[maxNM][maxNM];

stack<pii> nine;//紀錄9的位置 

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>table[i][j];
			if(table[i][j]=='9')
				nine.push(pii(i,j));
		}
	}
	
	pii tg,nxg,Ori;//togo,nextgo,origin
	char tgv;//togovalue
	int add;
	
	while(!nine.empty())
	{
		tg=nine.top();
		nine.pop();
		tgv=table[tg.first][tg.second];
		if(tgv=='0')
			DP[tg.first][tg.second]=1;
		if(DP[tg.first][tg.second])
		{
			Ori=CF[tg.first][tg.second];//父點 
			while(tgv!='9')
			{
				DP[Ori.first][Ori.second]+=DP[tg.first][tg.second];
				Ori=CF[Ori.first][Ori.second];//父點 
				tgv+=1;//更新到9為止 
			}
			
			//紀錄所有由9出發的結果 
			cnt+=DP[tg.first][tg.second];
			continue;
		}
		
		for(int i=0;i<4;i++)//DFS
		{
			nxg=pii(tg.first+m[i][0],tg.second+m[i][1]);
			if(0<=nxg.first&&nxg.first<N&&0<=nxg.second&&nxg.second<M)//如果在邊界內 
				if(table[nxg.first][nxg.second]==tgv-1)//找尋下游 
				{ 
					CF[nxg.first][nxg.second]=pii(tg.first,tg.second);//紀錄comefrom 
					nine.push(nxg);
				}
		}
	}
	
	cout<<cnt<<'\n';
	return 0;
}
