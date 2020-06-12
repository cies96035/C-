#include<iostream>
#include<algorithm>
using namespace std;

#define area 6 

struct HeightWidth
{
	bool operator != (const HeightWidth &x)
	{
		return (x.h!=this->h)||(x.w!=this->w);
	}
	int h,w;
}hw[area];

bool cmp(HeightWidth x,HeightWidth y)
{
	if(x.h!=y.h)
		return 	x.h<y.h;
	return x.w<y.w;
}

bool isbox()
{
	
	for(int i=0;i<6;i+=2)
		if(hw[i]!=hw[i+1])
			return false;
			
	//eight possible
	if(hw[0].h==hw[2].h)
	{
		if((hw[0].w==hw[4].h&&hw[2].w==hw[4].w)||
		(hw[0].w==hw[4].w&&hw[2].w==hw[4].h))
			return true;
	}
	else if(hw[0].h==hw[2].w)
	{
		if((hw[0].w==hw[4].h&&hw[2].h==hw[4].w)||
		(hw[0].w==hw[4].h&&hw[2].h==hw[4].w))
			return true;
	}
	else if(hw[0].h==hw[4].h)
	{
		if((hw[0].w==hw[2].w&&hw[2].h==hw[4].w)||
		(hw[0].w==hw[2].h&&hw[2].w==hw[4].w))
			return true;
	}
	else if(hw[0].h==hw[4].w)
	{
		if((hw[0].w==hw[2].w&&hw[2].h==hw[4].h)||
		(hw[0].w==hw[2].h&&hw[2].w==hw[4].h))
			return true;
	}
	return false;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>hw[0].h>>hw[0].w)
	{
		for(int i=0;i<area;i++)
		{
			if(i)
				cin>>hw[i].h>>hw[i].w;
			if(hw[i].h>hw[i].w)
				swap(hw[i].h,hw[i].w);
		}
		
		sort(hw,hw+area,cmp);
		
		if(isbox())
			cout<<"POSSIBLE\n";
		else
			cout<<"IMPOSSIBLE\n";
	}
	return 0;
}

