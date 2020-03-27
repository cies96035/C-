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
			
			//�Ĥ@�u��,�j�M�s���µ��� 
			for(int i=window.size()-1;i>=0;i--)
			{
				if(is_point_in_window(point,window[i]))
				{
					cout<<(char)('A'+i)<<endl;
					complete=1;
					break;
				}
			}
			
			//�p�G���I��������A�~��ĤG�u���j�Micon 
			if(!complete)
			{
				//�����C�ӳ̵u�Z��icon��id 
				vector <int> minid;
				long long min=2e9,distance;
				for(int i=0;i<icon.size();i++)
				{
					distance=pow((icon[i].x-point.x),2)+pow((icon[i].y-point.y),2);
					//�p�Gicon�Q�����צ�,�N�Z���]���ܤj 
					for(int j=window.size()-1;j>=0;j--)
					{
						if(is_point_in_window(icon[i],window[j]))
						{
							distance=2e9;
							break;
						}
					}
					//�o��Ҧ��̤p�Z�� 
					if(distance==min)
						minid.push_back(i);
					else if(distance<min)
					{
						minid.clear();
						min=distance;
						minid.push_back(i);
					}
				}
				//��X�Ҧ��̤p�Z�� 
				for(int i=0;i<minid.size();i++)
					cout<<setw(3)<<minid[i]+1;
				cout<<endl;
			}
		}
		else if(k=='#')break;
	}
	return 0;
}

