#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int,int> pii;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T,M,N;//測資數,y軸長度,x軸長度 
	cin>>T;
	while(T--)
	{
		cin>>M>>N;
		char input;
		int ex,ey,sx,sy,trip[M][N];
		memset(trip,0,sizeof(trip));
		//trip用來記錄從起點到達該地需要多少步數
		//0代表未走過,可以前往,-1代表不能前往,其餘數字代表曾經走過,也不能前往
		
		//根據輸入得到起點、終點、以及不能前往的位置 
		for(int i=M-1;i>=0;i--)
			for(int j=0;j<N;j++)
			{
				cin>>input;
				if(input=='A')
				{
					sx=j;
					sy=i;
				}
				else if(input=='B')
				{
					ex=j;
					ey=i;
				}
				else if(input=='Z')
				{
					if(j>1&&i>0)
						trip[i-1][j-2]=-1;
					if(j>1&&i<M-1)
						trip[i+1][j-2]=-1;
					if(j>0&&i>1)
						trip[i-2][j-1]=-1;
					if(j>0&&i<M-2)
						trip[i+2][j-1]=-1;
					if(j<N-2&&i>0)
						trip[i-1][j+2]=-1;
					if(j<N-2&&i<M-1)
						trip[i+1][j+2]=-1;
					if(j<N-1&&i>1)
						trip[i-2][j+1]=-1;
					if(j<N-1&&i<M-2)
						trip[i+2][j+1]=-1;
					trip[i][j]=-1;//注意這行
				} 
			}
		queue<pii> togo;
		togo.emplace(sy,sx);
		trip[sy][sx]=1;
		trip[ey][ex]=0;
		while(!togo.empty())
		{
			int y=togo.front().first,x=togo.front().second,goy,gox;
			//*test*/cout<<x<<y<<' '<<trip[y][x]<<endl;
			if(x==ex&&y==ey)
			{
				cout<<"Minimal possible length of a trip is "<<trip[y][x]-1<<endl;
				break;
			}
			togo.pop();
			for(int i=0;i<8;i++)
			{
				if(i==0)gox=x+1,goy=y+1;//右上 
				else if(i==1)gox=x-1,goy=y-1;//左上 
				else if(i==2)gox=x+1,goy=y-1;//右上 
				else if(i==3)gox=x-1,goy=y+1;//左下 
				else if(i==4)gox=x+1,goy=y;//右 
				else if(i==5)gox=x-1,goy=y;//左  
				else if(i==6)gox=x,goy=y+1;//下 
				else if(i==7)gox=x,goy=y-1;//上
				if((gox>=0&&gox<N)&&(goy>=0&&goy<M))//判斷無超出陣列範圍
				{
					//如果沒有被記錄過(可以走) 
					if(!trip[goy][gox]) 
					{
						//*test*/cout<<' '<<gox<<goy<<' '<<trip[goy][gox]<<endl;
						togo.emplace(goy,gox);
						trip[goy][gox]=trip[y][x]+1;
					} 
				} 
			}
		}
		if(togo.empty())
			cout<<"King Peter, you can't go now!"<<endl;
	}
	return 0;
}

