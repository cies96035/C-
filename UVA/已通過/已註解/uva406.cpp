#include<iostream>
#include<algorithm>
using namespace std;

#define MaxN 1100
bool isnt_prime[MaxN];
int Prime[MaxN],Primesize=0;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//getPrime
	Prime[Primesize++]=1;
	for(int i=2;i<MaxN;i++)
		if(!isnt_prime[i])
		{
			for(int j=i*i;j<MaxN;j+=i)
				isnt_prime[j]=1;
			Prime[Primesize++]=i;
		}
		
	int N,C,S;
	while(cin>>N>>C)
	{
		cout<<N<<' '<<C<<':';
		
		//S=list size
		S=upper_bound(Prime,Prime+Primesize,N)-Prime;
		
		//if S is odd like 7
		//print 3-C+1 ~ 3+C-1
		//else if S is even like 6
		//print 2-C+1 ~ 3+C-1
		int i,j;
		if(C>S/2)
			i=0,j=S;
		else
			i=(S-1)/2-C+1,j=S/2+C;
			
		while(i<j)
			cout<<' '<<Prime[i++];
		cout<<"\n\n"; 
	}
	return 0;
}

