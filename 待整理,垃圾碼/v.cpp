//#include "player.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	pair<int,vector<int> > tmp;
	tmp.first = 15;
	
	bool take[1001];
	memset(take,0,sizeof(take));
	for(int i=0;i<tmp.second.size();i++)
		take[tmp.second[i]]=1;
	int rock=tmp.first;
	
//	while(rock!=0)
//	{
		int c=rock,t=0;
		bool b2[15];
		for(int i=0;i<15;i++)
		{
			b2[i]=c%2;
			c/=2;
			if(b2[i]==1)t+=pow(2,i);
		}
		cout<<t<<endl;
//	}
	
	return 0;
}
