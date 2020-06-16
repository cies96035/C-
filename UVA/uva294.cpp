#include<iostream>
#include<vector>
using namespace std;

#define MaxP 35000
bool isnt_prime[MaxP];
int Prime[MaxP],Primesize=0;

//get k's factors_amount
int get_factors_amount(int k)
{
	int amount=1;
	for(int i=0;i<Primesize&&k>1;i++)
	{
		int cnt=1;
		while(k%Prime[i]==0)
		{
			k/=Prime[i];
			cnt++;
		}
		//k have factor : Prime[i]^0 ... Prime[i]^(cnt-1)
		if(cnt>1)
			amount*=cnt;
	}
	if(k!=1)//if k has a factor bigger than sqrt(10^9)
		amount*=2;
	return amount;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//Init
	for(int i=2;i<MaxP;i++) 
	{
		if(!isnt_prime[i])
		{
			for(int j=i*i;j<MaxP;j+=i)
				isnt_prime[j]=1;
			Prime[Primesize++]=i;
		}
	}
	
	int t,L,U,tmp;
	int Max,Max_id;
	
	cin>>t;
	while(t--)
	{
		Max=0;
		cin>>L>>U;
		for(int i=L;i<=U;i++)
		{
			if(Max<(tmp=get_factors_amount(i)))
			{
				Max=tmp;
				Max_id=i;
			}
		}
		cout<<"Between "<<L<<" and "<<U<<", "
		<<Max_id<<" has a maximum of "<<Max<<" divisors.\n";
	} 
	return 0;
}

