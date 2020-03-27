//窮舉啦毛線個DP 

#include<iostream>
#include<cstring>
using namespace std;
int Ans=1e9,X,Y,Map[21][21],time=0,directMap[4][21][21];
#define down 0
#define right 1 
#define up 2
#define left 3
void Find(int direct,int x,int y,int ans,int u,int d,int l,int r)
{
	time++;
	if(y==l||x==u||y==r||x==d)return;//出界
	ans+=Map[x][y];
	if(directMap[direct][x][y]<ans)return;
    directMap[direct][x][y]=ans;
	if(x==X&&y==Y)
	{
		if(Ans>ans)Ans=ans;
		return;
	}
	if(direct==down)
	{
		if(y<=Y)
			Find(down,x+1,y,ans,u,d,l,r);//往下
		if(x>=X)
			Find(right,x,y+1,ans,u,d,y,r);//左轉往右 
	}
	else if(direct==right)
	{
		if(x>=X)
			Find(right,x,y+1,ans,u,d,l,r);//往右 
		if(y>=Y)
			Find(up,x-1,y,ans,u,x,l,r);//左轉往上 
	}
	else if(direct==up)
	{
		if(y>=Y)
			Find(up,x-1,y,ans,u,d,l,r);//往上 
		if(x<=X)
			Find(left,x,y-1,ans,u,d,l,y);//左轉往左 
	}
	else if(direct==left)
	{
		if(x<=X)
			Find(left,x,y-1,ans,u,d,l,r);//往左 
		if(y<=Y)
			Find(down,x+1,y,ans,x,d,l,r);//左轉往下 
	}
} 
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int H,W;
	cin>>H>>W>>X>>Y;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
        {
            for(int k=0;k<4;k++)
                directMap[k][i][j]=1e9;
            cin>>Map[i][j];
        }
		
	Find(down,1,1,0,0,H+1,0,W+1);
	cout<<time<<'n'<<Ans<<'\n';
	return 0;
}
/*
14 14 10 10

98 10 10 23 10 38 29 -1239 -19 10 10 10 10 -1239 -19
1 10 10 -1239 -19 123 10 10 3 -19 2 10 10 10 10 10 10 10 10 10
231 10 10 30 10 180 410 10 10 -21 10 10 38 29 50 10 10 10 10
1 10 10 10 10 1 10 10 10 10 10 10 1 -1239 -19 1210 10 10 10 10 1 10 3 -19 2 10 10 10 10 10
1 10 10 10 1098 10 10 23 10 38 29 -1239 -19 10 10 10 10 -1239 -19 123 10
1 10 10 10 10 10 50 10 10 10 1 1 -1230 10 3 812 1 323 29 10 10 10 10 1 10 10 10 10 10 10 10 10 10
1 10 10 10 130 10 180 410 10 10 -21 10 10 38 29 50 10 10 10 10
1 10 10 10 10 1076 10 10 103 10 13 10 10 10 10 10 10 10 10 10
1 10 10 10 38 299 50 10 10 1210 1123 10 10 38 29 -1239 -19 123 10 10
1 10 10 10 10 10 10 10 10 10 1 103 10 10 10 10 10 10 10 10
1 10 10 10 10 10 10 10 10 10 38 29 50 10 10 10 10 10 10 10
1 10 10 10 10 10 10 10 10 10 1 10 10 10 11 -120 10 10 10 10 10
1 10 10 10 10 10 10 10 10 10 1 10 10 -1239 -19 123 10 10 10 10
1 10 10 10 10 10 10 10 10 10 1 10 10 10 10 3 10 10 10 10 10 10
1 10 10 -1239 -19 123 10 10 10 10 1 10 10 1010 10 10 10 10
1 10 -1239 -19 123 10 10 10 10 10 1 10 10 10 10 10 10 10 10 10
1 10 10 10 10 10 10 10 10 10 1 -1239 -19 123 10 10 10 10 10 10
1 10 10 -1239 -19 123 10 10 10 10 1 10 10 10 10 10 10 10 10 10
1 10 10 10 10 10 38 29 50 10 1 10 10 10 10 10 10 10 10 10
1 10 10 10 10 10 10 10 10 10 1 10 10 10 10 10 10 10 10 10
1 10 10 10 10 10 10 10 10 10 1 10 10 10 10 10 10 10 10 10
*/


