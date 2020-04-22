#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 1000100
#define maxid 10000100
int num[maxid],E[maxid],n,k;

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
		num[i]=2;
	for(long long i=3;i<maxid;i++)
	{
		if(!num[i])
		{
			num[i]=i;
			for(long long j=i*i;j<maxid;j+=i)
				num[j]=i;
		}
	}
}

int getvalue(int id)
{
	int ans=1,tmp,ID=id;
	while(num[id]>1)
	{
		tmp=num[id];
		if(E[id])return E[ID]=ans*E[id];
		ans*=tmp-1;
		id/=tmp;
		while(id%tmp==0)
		{
			id/=tmp;
			ans*=tmp;
		}
	}
	return E[ID]=ans;
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

