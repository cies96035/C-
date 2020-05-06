#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
#define maxN 100010

int N;
ll M;
struct Lolipop{
	ll buy;
	ll sell;
	inline ll earn()
	{
		return sell-buy;
	}
}lolipop[maxN];

//sort by buy
//earn the lowest buy lolipoop
//until you cannot buy any lolipop
bool cmp(Lolipop a,Lolipop b)
{
	return a.buy<b.buy;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N>>M;
	
	for(int i=0;i<N;i++)
		cin>>lolipop[i].buy>>lolipop[i].sell;
	
	sort(lolipop,lolipop+N,cmp);
	
	for(int i=0;i<N;i++)
	{
		if(M>=lolipop[i].buy)
			M+=lolipop[i].earn();
		else//doesnt have more lolipop i can buy, dont need to continue check
			break;
	}
	cout<<M<<'\n';
	return 0;
}

