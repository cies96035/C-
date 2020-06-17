#include<iostream>
using namespace std;

#define Max 47000

typedef long long ll;
bool x;
int g,isnt_prime[Max],Prime[Max],Primesize=0;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//pre
	for(ll i=2;i<Max;i++)
		if(!isnt_prime[i])
		{
			Prime[Primesize++]=i;
			for(ll j=i*i;j<Max;j+=i)
				if(!isnt_prime[j])
					isnt_prime[j]=1;
		}
	Prime[Primesize]=1;
	
	while(cin>>g&&g)
	{
		//Init
		x=0;
		
		//output
		cout<<g<<" = ";
		
		if(g<0)//if negative
		{
			cout<<-1<<" x ";
			g=-g;
		}
		
		//output factors
		for(int i=0,out=0;g!=1;)
		{
			while(g%Prime[i])//if not g's factor
				if(++i<Primesize);
				else//g is a prime
					out=1;
			if(out)
				break;
			while(!(g%Prime[i]))//if Prime[i] is g's factor
			{
				if(x)
					cout<<" x ";
				else
					x=1;
				cout<<Prime[i];
				g/=Prime[i];
			}
		}
		
		//if lager than Max and g is a prime
		if(!x)
			cout<<g;
		cout<<'\n';
	}
	return 0;
}

