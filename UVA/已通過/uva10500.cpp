#include<iostream>
#include<cstring>
using namespace std;

inline void coutline(int n)
{
	cout<<"\n|";
	while(n--)
		cout<<"---|";
	cout<<'\n';
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int M,N,x,y;
	while(cin>>M>>N)
	{
		if(M==0&&N==0)break;
		cin>>x>>y;
		
		//0無法到達1可以到達2未到過3已到達過
		int go=0,robot[M][N],real[M][N],num=0; 
		char k,output[4]={'X','0','?','0'};
		
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				cin>>k;
				real[i][j]=(k=='0'?1:0);
				robot[i][j]=2;
			}
		robot[--x][--y]=3;
		while(true)
		{
			if(y>0)
			{
				if(robot[x][y-1]==2)
					robot[x][y-1]=real[x][y-1];
				if(robot[x][y-1]==1)
					go=4;
			}
			if(x<M-1)
			{
				if(robot[x+1][y]==2)
					robot[x+1][y]=real[x+1][y];
				if(robot[x+1][y]==1)
					go=3;
			}
			if(y<N-1)
			{
				if(robot[x][y+1]==2)
					robot[x][y+1]=real[x][y+1];
				if(robot[x][y+1]==1)
					go=2;
			}
			if(x>0)
			{
				if(robot[x-1][y]==2)
					robot[x-1][y]=real[x-1][y];
				if(robot[x-1][y]==1)
					go=1;
			}
			if(go)
			{
				if(go==1)
					robot[--x][y]=3;
				if(go==2)
					robot[x][++y]=3;
				if(go==3)
					robot[++x][y]=3;
				if(go==4)
					robot[x][--y]=3;
				go=0;
				num++;
			}
			else break;
		}
		
		coutline(N);
		for(int i=0;i<M;i++)
		{
			cout<<'|';
			for(int j=0;j<N;j++)
				cout<<' '<<output[robot[i][j]]<<" |";
			coutline(N);
		}
		cout<<"\nNUMBER OF MOVEMENTS: "<<num<<'\n';
	}
	return 0;
}

