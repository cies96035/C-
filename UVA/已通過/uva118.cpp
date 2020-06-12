#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int m,n,x,y,faceid;
	char face,f[4]={'N','E','S','W'};
	string todo;
	cin>>m>>n;
	bool desk[m+1][n+1],losted;
	memset(desk,0,sizeof(desk));
	while(cin>>x>>y>>face>>todo)
	{
		if(face=='N')faceid=0;
		else if(face=='E')faceid=1;
		else if(face=='S')faceid=2;
		else if(face=='W')faceid=3;
		
		losted=0;
		
		//處理字串部分 
		for(int i=0;i<todo.size();i++)
		{
			if(todo[i]=='L')faceid+=3;
			else if(todo[i]=='R')faceid++;
			else if(todo[i]=='F')
			{
				if(faceid==0)
				{
					if(y==n)
					{
						if(desk[x][y])continue;
						desk[x][y]=losted=1;
						cout<<x<<' '<<y<<" N LOST\n";
						break;
					}
					y++;
				}
				else if(faceid==1)
				{
					if(x==m)
					{
						if(desk[x][y])continue;
						desk[x][y]=losted=1;
						cout<<x<<' '<<y<<" E LOST\n";
						break;
					}
					x++;
				}
				else if(faceid==2)
				{
					if(y==0)
					{
						if(desk[x][y])continue;
						desk[x][y]=losted=1;
						cout<<x<<' '<<y<<" S LOST\n";
						break;
					}
					y--;
				}
				else if(faceid==3)
				{
					if(x==0)
					{
						if(desk[x][y])continue;
						desk[x][y]=losted=1;
						cout<<x<<' '<<y<<" W LOST\n";
						break;
					}
					x--;
				}
			}
			if(faceid>=4)faceid%=4;
		}
		if(!losted)cout<<x<<' '<<y<<' '<<f[faceid]<<endl;
	}
	return 0;
}

