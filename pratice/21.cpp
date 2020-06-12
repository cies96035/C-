#include<iostream>
#include<algorithm>
using namespace std;
//應該要保存方向... 
struct B
{
	int x,w;
};
int Abs(int a)
{
	return (a>0?a:-a);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		int N,asum=0,bsum=0,r;
		cin>>N;
		B board[N];
		int c[N],d[N];
		for(int i=0;i<N;i++)
			cin>>board[i].x>>board[i].w;
		c[0]=d[0]=0;
		r=board[0].x+board[0].w;
		for(int i=1;i<N;i++)
		{
			int h=r-board[i].x;
			if(h>0)asum+=h;
			else bsum+=h;
			r+=board[i].w;
		}
		int Min=Abs(asum)+Abs(bsum);
		sort(d,d+N);
		for(int i=0;i<N;i++)
		{
			int u=upper_bound(d,d+N,c[i])-d,l=lower_bound(d,d+N,c[i])-d,k=u-l;
			u=N-u; 
			if(c[i]<0)c[i]*=-1;
			Min=min(Min,Abs(sum+(u-l-k)*c[i]));
		}
		cout<<Min<<'\n';
	}
	return 0;
	
}

