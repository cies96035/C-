#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const int Max=1<<15;
bool isntprime[Max];
vector<int> prime;
int n,amount;

void Init_Prime()
{
	for(ll i=2;i<Max;i++)
		if(!isntprime[i]) 
		{
			prime.emplace_back(i);
			for(ll j=i*i;j<Max;j+=i)
				isntprime[j]=1;
		}
	return;
		
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	Init_Prime();
	while(cin>>n&&n)
	{
		amount=0;
		for(int i=0,j=n/2;prime[i]<=j;i++)
			if(!isntprime[n-prime[i]])
				amount++;
				
		cout<<amount<<'\n';
		 
	}
	return 0;
}

