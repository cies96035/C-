#include<iostream>
using namespace std;

typedef pair<int,int> pii;
#define maxn 1010
#define tonum(x,y) x*m+y
#define inbound(x,y) x>=0&&x<n&&y>=0&&y<m

int set[maxn*maxn];
int table[maxn][maxn];
bool isfind[maxn*maxn];
int n,m,ans=0;
int m1[4][2]={{0,-1},{-1,0},{1,0},{0,1}};
int m2[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};

void Init()
{
	for(int i=0;i<n*m;i++)
		set[i]=i;
	return;
}

int find(int a)
{
	return set[a]=(a==set[a]?a:find(set[a]));
}

void Union(int a,int b)
{
	set[find(b)]=find(a);
	return;
}
void te()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<find(tonum(i,j))<<' ';
		cout<<endl;
	}
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	Init();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>table[i][j];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x,y;
			for(int k=0;k<4;k++)
			{
				if(table[i][j]==1||table[i][j]==3)
				{
					x=i+m1[k][0],y=j+m1[k][1];
					if(inbound(x,y)&&table[x][y])
						Union(tonum(i,j),tonum(x,y));
				}
					
				if(table[i][j]==2||table[i][j]==3)
				{
					x=i+m2[k][0],y=j+m2[k][1];
					if(inbound(x,y)&&table[x][y])
						Union(tonum(i,j),tonum(x,y));
				}
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!isfind[find(tonum(i,j))]&&table[i][j]!=0)
			{
				isfind[find(tonum(i,j))]=1;
				ans++;
			}
	cout<<ans<<'\n';
	return 0;
}

