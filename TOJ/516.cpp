#include<iostream>
using namespace std;

#define maxN 1<<18
typedef long long ll;

bool isntprime[maxN];
int index=1,prime[maxN],N;

void Init()
{
	for(ll i=2;i<maxN;i++)
		if(!isntprime[i])
		{
			prime[index++]=i;
			for(ll j=i*i;j<maxN;j+=i)
				isntprime[j]=1;
		}
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Init();
	//cout<<index<<endl;
	cin>>N;
	cout<<prime[N+1]-1<<'\n';
	return 0;
}

