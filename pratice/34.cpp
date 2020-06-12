#include<iostream>
#include<cstring>
#include<map>
using namespace std;

typedef long double ld;
struct Flower
{
	ld R,C;
};
int main()
{
	map<pair<ld,ld>,int>num;
	int N,Max=0,sp=0;
	cin>>N>>N>>N;
	Flower f[N];
	for(int i=0;i<N;i++)
		cin>>f[i].R>>f[i].C;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(!(f[i].C-f[j].C))
			{
				sp++;
				continue;
			}
			ld m=(f[i].R-f[j].R)/(f[i].C-f[j].C);
			Max=max(Max,++num[pair<ld,ld>(m,f[i].R-m*f[i].C)]);
		}
	}
	cout<<Max<<endl;
	return 0;
}

