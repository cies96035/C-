//¦³ªÅ­«¼g 

#include<iostream>
#include<vector>
using namespace std;

const int maxN=110;
typedef pair<int,int> pii;
int N,M;
vector<pii> link[maxN];

int di(int a)
{
	int num[N];
	for(int i=0;i<N;i++)num[i]=100000;
	num[a]=0;
	for(int i=0;i<N;i++)
	{
		int min;
		for(int j=0;j<link[a].size();j++)
		{
			int k=link[a][j].first;
			if(link[a][j].second+num[a]<num[k])
				num[k]=link[a][j].second+num[a];
			if(num[min]>num[k])min=k;
		}
		a=min;
		cout<<a<<endl;
	}
}
int main()
{
	cin>>N>>M;
	for(int i=0,tmp1,tmp2,tmp3;i<M;i++)
	{
		cin>>tmp1>>tmp2>>tmp3;
		
		if(tmp1==tmp2)continue;
		link[tmp1].push_back(pii(tmp2,tmp3));
		link[tmp2].push_back(pii(tmp1,tmp3));
	}
	di(0);
	for(int i=0;i<N;i++)
	{
		
	}
	return 0;
}

