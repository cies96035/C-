#include<iostream>
#include<cstring>
using namespace std;

bool same(int a,int b,int c,int d,int e)
{
	return a!=-1&&a==b&&b==c&&c==d&&d==e;
}
int main()
{
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N;
	while(cin>>N)
	{
		int table[N][N],Steps,x,y,end=0,who=1;
		memset(table,-1,sizeof(table));
		cin>>Steps;
		while(Steps--)
		{
			cin>>x>>y;
			if(!end)
			{
				who=!who;
				if(table[x][y]!=-1)//invalid
				{
					end=3;
					continue;
				} 
				table[x][y]=who;
				for(int i=-4;i<=0;i++)
				{
					if(x+i>=0&&x+i+4<N&&y+i>=0&&y+i+4<N&&
					same(table[x+i][y+i],table[x+i+1][y+i+1],table[x+i+2][y+i+2],table[x+i+3][y+i+3],table[x+i+4][y+i+4]))
					{
						end=who+1;
						break;
					}
					if(x+i>=0&&x+i+4<N&&y-i-4>=0&&y-i<N&&
					same(table[x+i][y-i],table[x+i+1][y-i-1],table[x+i+2][y-i-2],table[x+i+3][y-i-3],table[x+i+4][y-i-4]))
					{
						end=who+1;
						break;
					}
					if(x+i>=0&&x+i+4<N&&
					same(table[x+i][y],table[x+i+1][y],table[x+i+2][y],table[x+i+3][y],table[x+i+4][y]))
					{
						end=who+1;
						break;
					}
					if(y+i>=0&&y+i+4<N&&
					same(table[x][y+i],table[x][y+i+1],table[x][y+i+2],table[x][y+i+3],table[x][y+i+4]))
					{
						end=who+1;
						break;
					}
					
				}
			}
		}/*
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)cout<<table[i][j];
			cout<<endl;
		}*/
		if(end==1)cout<<"A wins\n";
		else if(end==2)cout<<"B wins\n";
		else if(end==3)cout<<"invalid\n";
		else cout<<"not yet\n";
		
	}
	return 0;
}

