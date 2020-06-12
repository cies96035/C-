#include<iostream>
using namespace std;

#define in_bound(a) (a.x>=0&&a.x<5&&a.y>=0&&a.y<5)

int Case=0;
string s;
char table[5][5];

struct Point
{
	int x,y;
	Point()
	{
		x=0;
		y=0;
	}
	Point(int a,int b)
	{
		x=a;
		y=b;
	}
};
Point point,nx;

Point operator + (Point a,Point b)
{
	Point c;
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	return c;
}

void print()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
			cout<<table[i][j]<<' ';
		cout<<table[i][4]<<'\n';
	}
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int f=0;
	bool flag=0,zero=0;
	while(getline(cin,s))
	{
		if(!f)
		{
			if(s=="Z")
				break;
			if(Case)
				cout<<'\n';
			cout<<"Puzzle #"<<++Case<<":\n";
		}
		if(f<5)
		{
			if(s.size()==4)
				s+=' ';
			for(int i=0;i<5;i++) 
			{
				table[f][i]=s[i];
				if(s[i]==' ')
					point=Point(f,i);
			}
			
			f++;
		}
		else
		{
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='A')
					nx=point+Point(-1,0);
				else if(s[i]=='B')
					nx=point+Point(1,0);
				else if(s[i]=='L')
					nx=point+Point(0,-1);
				else if(s[i]=='R')
					nx=point+Point(0,1);
				else if(s[i]=='0')
				{
					if(flag)
						cout<<"This puzzle has no final configuration.\n";	
					else
						print();
					zero=1;
				}
				else
					flag=1;
				if(!flag&&in_bound(nx))
					swap(table[point.x][point.y],table[nx.x][nx.y]);
				else
					flag=1;
				point=nx;
			}
			if(zero)
				zero=flag=f=0;
		}
	}
	return 0;
}

