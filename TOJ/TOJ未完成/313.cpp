#include<iostream>
using namespace std;

#define err 1000000000

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		int R,L,X,M;
		cin>>R>>L>>X>>M;
		int map[2][R],r=R-1;
		bool turn=0;
		for(int i=0;i<R;i++)
			map[0][i]=1;
		for(int i=1;i<L;i++)
		{
			turn=!turn;
			if(!turn)
			{
				for(int j=0;j<R;j++)
				{
					map[turn][j]=map[!turn][j];
					if(j>0)
						map[turn][j]+=map[turn][j-1];
					if(map[turn][j]>err)map[turn][j]%=M;
				}
			}
			else
			{
				for(int j=r;j>=0;j--)
				{
					map[turn][j]=map[!turn][j];
					if(j<r)
						map[turn][j]+=map[turn][j+1];
					if(map[turn][j]>err)map[turn][j]%=M;
				}
			}
		}
		cout<<map[turn][X-1]%M<<'\n';
	}
	return 0;
}

