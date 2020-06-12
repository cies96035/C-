#include<iostream>
#include<iomanip>
using namespace std;

#define Maxn 1010
typedef long double ld;
ld n,cost[Maxn],avg;



ld get_all_delta()
{
	ld s=0,t=0;
	for(int i=0;i<n;i++)
	{
		if(cost[i]>avg)
			s+=cost[i]-avg;
		else 
			t+=avg-cost[i];
	}
	return min(s,t);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(2);
	
	while(cin>>n&&n)
	{
		avg=0;
		for(int i=0;i<n;i++)
		{
			cin>>cost[i];
			avg+=cost[i];
		}
		avg=int(avg*100/n+0.5)/100.0;
		cout<<'$'<<get_all_delta()<<'\n';
		
	}
	return 0;
}

