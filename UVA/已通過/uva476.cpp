#include<iostream>
#include<vector>
using namespace std;
//矩形不超過10個,範圍不大算簡單圖論 

#define is_in_figure x>Figure[i].lx&&x<Figure[i].rx&&y>Figure[i].ry&&y<Figure[i].ly

struct figure
{
	float lx,ly,rx,ry;
	figure(float a,float b,float c,float d)
	{
		lx=a;
		ly=b;
		rx=c;
		ry=d;
	}
};
int main()
{
	char r;
	vector<figure> Figure;
	float x,y,Point=1,end=9999.9;
	while(cin>>r)
	{
		float lx,ly,rx,ry;
		if(r!='r')break;
		cin>>lx>>ly>>rx>>ry;
		Figure.emplace_back(lx,ly,rx,ry);
	}
	while(cin>>x>>y)
	{
		if(x==end&&y==end)break;
		bool isntcout=1;
		for(int i=0;i<Figure.size();i++)
		{
			if(is_in_figure)
			{
				cout<<"Point "<<Point<<" is contained in figure "<<i+1<<endl;
				isntcout=0;
			}
		}
		if(isntcout)
			cout<<"Point "<<Point<<" is not contained in any figure"<<endl;
		Point++;
	}
	
	return 0;
}

