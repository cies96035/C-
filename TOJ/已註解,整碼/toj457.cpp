#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 1000010
#define maxid 10000010
typedef long long ll;
int prime[maxid]//record i's prime factor
,E[maxid]//cache
,n,k;

struct Star
{
	int id,value;
}star[maxn];

bool cmp(Star a,Star b)
{
	if(a.value!=b.value)return a.value>b.value;
	return a.id<b.id;
}

//get every num's prime factor
void Init()
{
	for(ll i=2;i<maxid;i++)
	{
		if(!prime[i])
		{
			prime[i]=i;
			for(ll j=i*i;j<maxid;j+=i)
				prime[j]=i;
		}
	}
	return;
}

int getvalue(int id)
{
	int ans=1,id_primefactor,origin=id;
	while(id!=1)//因式分解直到1
	{
		id_primefactor=prime[id];
		if(E[id])//如果E[id]找過了，可以用E[id]求出E[origin]，E[origin/id]=ans
			return E[origin]=ans*E[id];
		else
		{
			id/=id_primefactor;
			ans*=id_primefactor-1;
			while(id%id_primefactor==0)
			{
				id/=id_primefactor;
				ans*=id_primefactor;
			}
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

