#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxN=100010;
int N,K,sig[maxN],w[maxN],n,r,sum=0;
vector<int> addsum;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	sig[0]=0;//Init
	for(int i=1;i<maxN;i++)
		sig[i]=sig[i-1]+i;
		
	cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>w[i];
		
	r=K-*(lower_bound(sig,sig+maxN,K)-1);//第r大的 
	n=N-(lower_bound(sig,sig+maxN,K)-sig)+1;//掃n格
	
	for(int i=0;i<n;i++)
		sum+=w[i];
	addsum.emplace_back(sum);
	for(int i=n;i<N;i++)
	{
		sum+=w[i]-w[i-n];
		addsum.emplace_back(sum);
	}
	sort(addsum.begin(),addsum.end());
	cout<<addsum[addsum.size()-r]<<'\n';
	return 0;
}/*184 16 13 12
6 7
8 7 1 2 2 8


8 7 1 2 2 8 .1 28
8 7 1 2 2 .2 20
8 7 1 2 .4 18
8 7 1 .5 16
8 7 .6 15
8 .13 8
7 1 2 2 8 .3 20
7 1 2 2 .8 12
7 1 2 .10 10
7 1 .12 8
7 .15 7
1 2 2 8 .7 13
1 2 2 .16 5
1 2 .18 3
1 .21 1
2 2 8 .9 12
2 2 .17 4
2 .19 2
2 8 .11 10
2 .20 2
8 .14 8



*/


