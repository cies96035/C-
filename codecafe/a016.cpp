#include<iostream>
using namespace std;

typedef long long ll;

#define N 1000010
bool isntprime[N];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	isntprime[0]=isntprime[1]=1;
	for(int i=4;i<N;i+=2)
		isntprime[i]=1;
	for(ll i=2;i<N;i++)
	{
		if(!isntprime[i]) 
		{
			for(ll j=i*i,k=i+i;j<N;j+=k)
				isntprime[j]=1;
		}
	} 
	
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<(isntprime[n]?"No":"Yes")<<'\n';
	}
	return 0;
}

