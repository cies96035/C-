#include<iostream>
using namespace std;

struct Point
{
	int x,y;
};
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Point center;
	int T;
	while(cin>>T&&T!=0)
	{
		cin>>center.x>>center.y;
		while(T--)
		{
			Point point;
			cin>>point.x>>point.y;
			if(point.x==center.x||point.y==center.y)
				cout<<"divisa\n";
			else if(point.x>center.x)
			{
				if(point.y>center.y)
					cout<<"NE\n";
				else
					cout<<"SE\n";
			}
			else
			{
				if(point.y>center.y)
					cout<<"NO\n";
				else
					cout<<"SO\n";
			}
		}
	}
	return 0;
}

