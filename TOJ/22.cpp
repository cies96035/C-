#include<iostream>
#include<algorithm>
using namespace std;

struct Babysitter
{
	int start,end;
};
bool cmp(Babysitter x,Babysitter y)
{
	if(x.start!=y.start)return x.start<y.start;
	return x.end>y.end;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N,s=1e9,e=0,ans=1;
	cin>>N;
	Babysitter Time[N];
	for(int i=0;i<N;i++)
	{
		cin>>Time[i].start>>Time[i].end;
		if(s>Time[i].start)s=Time[i].start;
		if(e<Time[i].end)e=Time[i].end;
	}
	sort(Time,Time+N,cmp);
	int index=0;
	while(Time[index].end!=e)
	{
		Babysitter t={Time[index].end+1,0};
		int max=0,maxid;
		for(int i=0,end=upper_bound(Time,Time+N,t,cmp)-Time;i<end;i++)
		{
			if(Time[i].end>max)
			{
				max=Time[i].end;
				maxid=i;
			}
		}
		if(max==Time[index].end)
		{
			cout<<"No\n";
			return 0;
		}
		index=maxid;
		ans++;
	}
	cout<<ans<<'\n';
	return 0;
}

