#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 1000010
#define maxid 10000010
typedef long long ll;
int prime[maxid]//record i's prime factor
,E[maxid],n,k;

struct Star
{
	int id,value;
}star[maxn];

bool cmp(Star a,Star b)
{
	if(a.value!=b.value)return a.value>b.value;
	return a.id<b.id;
}

void Init()
{
    for(int i=2;i<maxid;i+=2)
		prime[i]=2;
	for(ll i=3;i<maxid;i++)
	{
		if(!prime[i])
		{
			prime[i]=i;
			for(long long j=i*i;j<maxid;j+=i)
				prime[j]=i;
		}
	}
}

int getvalue(int id)
{
	int ans=1,tmp,origin=id;
	while(prime[id]>1)//until pr
	{
		tmp=prime[id];
		if(E[id])return E[origin]=ans*E[id];
		ans*=tmp-1;
		id/=tmp;
		while(id%tmp==0)
		{
			id/=tmp;
			ans*=tmp;
		}
	}
	return E[origin]=ans;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Init();
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>star[i].id;
		star[i].value=getvalue(star[i].id);
	} 
	sort(star,star+n,cmp);//sort highvalue to lowvalue , lowid to highid
	cout<<star[k-1].id<<'\n';
	return 0;
}

