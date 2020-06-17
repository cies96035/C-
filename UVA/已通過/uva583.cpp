#include<iostream>
#include<vector> 
using namespace std;

#define Max 50000

typedef long long ll;
ll g;
bool x;
int isnt_prime[Max],Prime[Max],Primesize=0;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(ll i=2;i<Max;i++)
	{
		if(!isnt_prime[i])
		{
			Prime[Primesize++]=i;
			for(ll j=i*i;j<Max;j+=i)
				isnt_prime[j]=1;
		}
	}
	
	while(cin>>g&&g)
	{
		x=0;
		cout<<g<<" = ";
		if(g<0)
		{
			cout<<-1<<" x ";
			g=-g;
		}
		
		for(int i=0;i<Primesize&&g!=1;)
		{
			if(g%Prime[i])
				i++;
			else
			{
				if(x)
					cout<<" x ";
				else
					x=1;
				cout<<Prime[i];
				g/=Prime[i];
			}
		}
		
		if(!x)
			cout<<g;
		cout<<'\n';
	}
	return 0;
}

