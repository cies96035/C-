#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int Case=1,N;//記錄第幾筆case 
	while(cin>>N)
	{
		//為零時結束程式
		if(!N)return 0; 
		
		const int end=N-1;//邊邊常數 
		int hole[N][N],x=0,y=0,num=1;//N*N個洞,(x,y)分別記錄現在挖到的地點,num紀錄該地點的數值 
		
		//製造矩陣 
		hole[x][y]=num;//左上角為第一個
		for(int step=1;num<N*N;step++)
		{
			//往右一格，往左下到底，往下一格，往右上到底
			//如果1,3步出現問題，改成往下和往右 
			switch(step%4)
			{
				case 1://第一步 
					//如果沒辦法右移一格，往下移 
					if(x==end)hole[x][++y]=++num;
					else hole[++x][y]=++num;
					break;
				case 2://左下到底
					while(x>0&&y<end)//直到碰到邊邊為止
						hole[--x][++y]=++num;
					break;
				case 3://往下，如果出問題往右 
					if(y==end)hole[++x][y]=++num;
					else hole[x][++y]=++num;
					break;
				case 0://右上到底
					while(x<end&&y>0)//直到碰到邊邊為止
						hole[++x][--y]=++num;
					break;
			}
		} 
		
		//輸出
		cout<<"Case "<<Case++<<':'<<endl; 
		for(y=0;y<N;y++)
		{
			for(x=0;x<N;x++)
			{
				cout<<setw(3)<<hole[x][y];
			}
			cout<<endl;
		}
	}
	return 0;
}

