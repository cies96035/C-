#include<iostream>
using namespace std;

const int maxA=10000001,smaxA=3163;
int prime[maxA];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	prime[1]=2;
	for(int i=2;i<maxA;i++)
	{
		if(i%2)
		{
			if(!prime[i])
			{
				if(i<smaxA)
					for(int j=i,k=i+i;j<maxA;j+=k)
					{
						if(!prime[j])
							prime[j]=i;
					}
				else
					prime[i]=i;
			}
		}
		else
			prime[i]=2;
	}
	
	int N,A,first,second,Prime;	
	cin>>N;
	while(N--)
	{
		cin>>A;
		first=1,second=1;
		while(A!=1)
		{
			Prime=prime[A];
			if(Prime>second)second=Prime;
			if(second>first)swap(first,second);
			while(!(A%Prime))A/=Prime;
		}
		cout<<second<<' '<<first<<'\n';
	}
	return 0;
}

