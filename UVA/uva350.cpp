#include<iostream>
using namespace std;

int used[10000];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int Z,I,M,L,Case=1;
	while(cin>>Z>>I>>M>>L)
	{
		if(Z+I+M+L==0)return 0;
		int cycle_length=0,sp_stats=L;
		while(used[L]!=Case)
		{
			used[L]=Case;
			L=(Z*L+I)%M;
			cycle_length++;
		}
		sp_stats-=L;
		cout<<"Case "<<Case++<<": "<<cycle_length-(sp_stats?1:0)<<'\n';
	}
	return 0;
}

