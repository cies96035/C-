#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

struct Window
{
	int lx,ly,rx,ry;
	Window(int a,int b,int c,int d)
	{
		lx=a;
		ly=b;
		rx=c;
		ry=d;
	}
};

struct Point
{
	int x,y;
	Point(int a,int b)
	{
		x=a;
		y=b;
	}
};

bool is_point_in_window(Point p,Window w)
{
	return (w.lx<=p.x)&&(p.x<=w.rx)&&(w.ly<=p.y)&&(p.y<=w.ry);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	char k;
	vector<Window> window;
	vector<Point> icon;
	while(cin>>k)
	{
		int a,b,c,d;
		if(k=='I')
		{
			cin>>a>>b;
			icon.emplace_back(a,b);
		}
		else if(k=='R')
		{
			cin>>a>>b>>c>>d;
			window.emplace_back(a,b,c,d);
		}
		else if(k=='M')
		{
			Point point={0,0};
			bool complete=0;
			cin>>point.x>>point.y;
			
			//第一優先,搜尋新到舊視窗 
			for(int i=window.size()-1;i>=0;i--)
			{
				if(is_point_in_window(point,window[i]))
				{
					cout<<(char)('A'+i)<<endl;
					complete=1;
					break;
				}
			}
			
			//如果未點擊到視窗，繼續第二優先搜尋icon 
			if(!complete)
			{
				//紀錄每個最短距離icon的id 
				vector <int> minid;
				long long min=2e9,distance;
				for(int i=0;i<icon.size();i++)
				{
					distance=pow((icon[i].x-point.x),2)+pow((icon[i].y-point.y),2);
					//如果icon被視窗擋住,將距離設為很大 
					for(int j=window.size()-1;j>=0;j--)
					{
						if(is_point_in_window(icon[i],window[j]))
						{
							distance=2e9;
							break;
						}
					}
					//得到所有最小距離 
					if(distance==min)
						minid.push_back(i);
					else if(distance<min)
					{
						minid.clear();
						min=distance;
						minid.push_back(i);
					}
				}
				//輸出所有最小距離 
				for(int i=0;i<minid.size();i++)
					cout<<setw(3)<<minid[i]+1;
				cout<<endl;
			}
		}
		else if(k=='#')break;
	}
	return 0;
}

