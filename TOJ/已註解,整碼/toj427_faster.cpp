#include<iostream>
using namespace std;
typedef long long ll;

#define maxN 1000100

bool isntprime[maxN];//record isnt prime or is
ll sum[maxN]={0,1};//sigma(E[i])*2+1
int prime[maxN],Pindex=0,//record every prime
E[maxN],//sigma(i and n coprime ? 1 : 0)
N;//the quest

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//Init
	for(int i=2;i<maxN;i++)
	{
		if(isntprime[i]==0)
		{
			prime[Pindex++]=i;//put new primenumber to prime[]
			E[i]=i-1; //if(i is prime) E[i]=i-1
		}
		for(int j=0,k=i*prime[j];k<maxN;j++,k=i*prime[j])
		{
			//a = prime * b 
			//if b has the prime factor E[a] = E[b] * prime
			//if b doesnt have the prime factor then E[a] = E[b] * (prime-1)
			isntprime[k]=1;
			if(!(i%prime[j]))
			{
				E[k]=E[i]*prime[j];
				break;
			}
			else
				E[k]=E[i]*E[prime[j]];
		}
		
        sum[i]+=sum[i-1]+E[i];//also get the ans
        sum[i-1]=(sum[i-1]<<1)+1;
	}
	
	while(cin>>N)
		cout<<sum[N]<<'\n'; 
	return 0;
}

