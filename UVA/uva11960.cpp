#include<iostream>
using namespace std;

const int maxX=1000001;

int prime[maxX]={0,0};
int divisors[maxX]={0,1};
int smaller_most_divisor[maxX]={0,1};

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(int i=2;i<maxX;i++)
		divisors[i]=1;
	
	//½è¼Æªí
	int most_divisor=0;
	for(int i=2;i<maxX;i++)
	{
		if(!prime[i])
			for(int j=i;j<maxX;j+=i)
			{
				prime[j]=i;
				int k=j,tomul=1;
				do
				{		
					tomul++;
					k/=i;
				}while(!(k%i));
				divisors[j]*=tomul;
			}
		if(divisors[i]>=most_divisor)
		{
			smaller_most_divisor[i]=i;
			if(divisors[i]>most_divisor)most_divisor=divisors[i];
		}
		else smaller_most_divisor[i]=smaller_most_divisor[i-1];
	}
				
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		cout<<smaller_most_divisor[N]<<'\n';
	}
	return 0;
}

