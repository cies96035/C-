#include<iostream>
#include<vector>
using namespace std;

struct Point
{
	int x,y;
	Point(int a,int b)
	{
		x=a;
		y=b;
	}
};

string tolowerstring(string x)
{
	for(unsigned int i=0;i<x.size();i++)
		x[i]=x[i]<'a'?(char)(x[i]-'A'):(char)(x[i]-'a');
	return x;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		int M,N,K;
		string tosearch;
		cin>>M>>N;
		char k[M][N];
		vector<Point> alpha[26];
		
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				cin>>k[i][j];
				k[i][j]=k[i][j]<'a'?(char)(k[i][j]-'A'):(char)(k[i][j]-'a');
				alpha[(int)k[i][j]].emplace_back(i,j);
			}
		
		cin>>K;
		while(K--)
		{
			cin>>tosearch;
			tosearch=tolowerstring(tosearch);
			bool flag=1;
			int index=-1,head=tosearch[0],x,y;
			Point move[8]=
			{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
			while(flag)
			{
				index++;
				for(unsigned int i=0,j=1;i<8;i++,j=1)
				{
					x=alpha[head][index].x,y=alpha[head][index].y;
					do
					{
						x+=move[i].x;
						y+=move[i].y;
						if(k[x][y]!=tosearch[j])
							break;
						j++;
					}while(!(x==M||y==N||x<0||y<0)&&j<tosearch.size());
					if(j==tosearch.size())
					{
						flag=0;
						break;
					}
				}
			}
			cout<<(int)alpha[head][index].x+1<<' '<<(int)alpha[head][index].y+1<<'\n';
		}
		if(t)cout<<'\n';
	}
	return 0;
}

