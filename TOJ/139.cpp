#include<iostream>
#include<map>
using namespace std;

typedef long double ld;
struct Point
{
	ld x,y;
	bool operator <(const Point& a)const//stl::map需要用<來排列，需要自訂<來使用map 
	{
		return (a.x==x)?(a.y<y):(a.x<x);
	}
};


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	for(int kase=0;kase<T;)
	{
		int N,ans=0,lamb=0;
		cin>>N;
		Point point[N];
		map<Point,bool> Record;
		bool record[N]={0};
		for(int i=0;i<N;i++)
		{
			cin>>point[i].x>>point[i].y;
			if(Record.find(point[i])==Record.end())
			{
				record[i]=1;
				Record[point[i]]=1;	
				lamb++;
			}
		}
		for(int i=0;i<N;i++)
		{
			map<ld,int> num;
			int sp=0;
			for(int j=0;j<N;j++)
			{
				if(i!=j&&record[j]&&record[i])
				{
					ld Y=(point[i].y-point[j].y),
					X=(point[i].x-point[j].x);
					if(X)
						num[Y/X]++;
					else
						sp++;
				}
			} 
			int max=0;
			for(map<ld,int>::iterator iter=num.begin();iter!=num.end();iter++)
				if(iter->second>max)max=iter->second;
			if(ans<max)ans=max;
			if(ans<sp)ans=sp;
		}
		if(lamb==1)
			cout<<"Data set #"<<++kase<<" contains a single gnu.\n";
		else
			cout<<"Data set #"<<++kase<<" contains "<<lamb<<" gnus, out of which a maximum of "<<ans+1<<" are aligned.\n";
	}
	return 0;
}
