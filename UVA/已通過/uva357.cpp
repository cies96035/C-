#include<iostream>
using namespace std;

#define MaxN 30100
#define Cent_amount 5

int cent[Cent_amount]={1,5,10,25,50};
long long way[MaxN];
int N;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	way[0]=1;
	for(int i=0;i<Cent_amount;i++)
		for(int j=cent[i];j<MaxN;j++)
			way[j]+=way[j-cent[i]];
			
	while(cin>>N)
		if(way[N]>1)
			cout<<"There are "<<way[N]<<" ways to produce "<<N<<" cents change.\n";
		else
			cout<<"There is only 1 way to produce "<<N<<" cents change.\n";
	return 0;
}

