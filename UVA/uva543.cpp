#include<iostream>
using namespace std;
#define maxN 1000100
typedef long long ll;
bool isnt_prime[maxN];
int prime[maxN],index=0,N;

void Init()
{
	for(ll i=2;i<maxN;i++)
	{
		if(!isnt_prime[i])
		{
			for(ll j=i*i;j<maxN;j+=i)
				isnt_prime[j]=1;
			prime[index++]=i;
		}
	}
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Init();
	
	while(cin>>N&&N)
	{
		int i=1;
		for(;i<index;i++)
			if(isnt_prime[N-prime[i]]==0)
			{
				cout<<N<<" = "<<prime[i]<<" + "<<N-prime[i]<<'\n';
				break;
			}
		if(i==index)
			cout<<"Goldbach's conjecture is wrong.\n";
	}
	return 0;
}

